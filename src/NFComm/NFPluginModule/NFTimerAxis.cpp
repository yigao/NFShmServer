// -------------------------------------------------------------------------
//    @FileName         :    NFTimerAxis.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#include "NFTimerAxis.h"
#include "NFComm/NFCore/NFPlatform.h"

NFTimerAxis::NFTimerAxis()
{
	m_TimerAxis.resize((TIME_AXIS_LENGTH + TIME_GRID - 1) / TIME_GRID);

	m_nInitTick = GetTick();
	m_nLastTick = m_nInitTick;
	for (uint32_t i = 0; i < m_TimerAxis.size(); ++i)
	{
		m_TimerAxis[i] = new TIMER_LIST();
	}

	m_TimerAxisSec.resize(TIME_AXIS_SECLENGTH);
	m_nInitSec = GetTick()/1000;
	m_nLastSec = m_nInitSec;
	for (uint32_t i = 0; i < m_TimerAxisSec.size(); ++i)
	{
		m_TimerAxisSec[i] = new TIMER_LIST();
	}
}

NFTimerAxis::~NFTimerAxis()
{
	for (size_t i = 0; i < m_TimerAxis.size(); ++i)
	{
		TIMER_LIST* pTimerList = m_TimerAxis[i];
		TIMER_LIST::iterator iter = pTimerList->begin();
		for (; iter != pTimerList->end(); ++iter)
		{
			Timer* pTimer = (*iter);
			NF_SAFE_DELETE(pTimer);
		}
		pTimerList->clear();
		NF_SAFE_DELETE(pTimerList);
	}
	m_TimerAxis.clear();

	for (size_t j = 0; j < m_TimerAxisSec.size(); ++j)
	{
		TIMER_LIST* pTimerList = m_TimerAxisSec[j];
		TIMER_LIST::iterator iter = pTimerList->begin();
		for (; iter != pTimerList->end(); ++iter)
		{
			Timer* pTimer = (*iter);
			NF_SAFE_DELETE(pTimer);
		}
		pTimerList->clear();
		NF_SAFE_DELETE(pTimerList);
	}
	m_TimerAxisSec.clear();
}

bool NFTimerAxis::Init()
{
	return true;
}

bool NFTimerAxis::UnInit()
{
	return true;
}

//设置秒定时器
bool NFTimerAxis::SetTimerSec(uint32_t nTimerID, uint64_t nInterVal, NFTimerObj* handler, uint32_t nCallCount/* = INFINITY_CALL*/)
{
	if (nullptr == handler)
	{
		return false;
	}
	if (nCallCount == 0)
	{
		return false;
	}
	if (nInterVal < 1)
	{
		nInterVal = 1;
	}

	bool bNeedFind = true;
	void** ppTimerInfo = handler->GetTimerInfoPtr();
	TIMER_LIST* pTimerList = *(TIMER_LIST**)ppTimerInfo;
	if (nullptr == pTimerList)
	{
		pTimerList = new TIMER_LIST();
		*ppTimerInfo = pTimerList;
		bNeedFind = false;
	}

	Timer* pTimer = nullptr;
	if (bNeedFind)
	{
		TIMER_LIST::iterator iter = pTimerList->begin();
		for (; iter != pTimerList->end(); ++iter)
		{
			pTimer = (*iter);
			if (pTimer->nTimerID == nTimerID)
			{
				//定时器ID 已存在
				return false;
			}
		}
	}

	pTimer = new Timer();
	pTimer->byType = 1;
	pTimer->nTimerID = nTimerID;
	pTimer->nCallCount = nCallCount;
	pTimer->nInterVal = nInterVal;
	pTimer->pHandler = handler;
	pTimer->nLastTick = m_nLastSec;
	uint32_t nTemp = (uint32_t)(pTimer->nLastTick - m_nInitSec + pTimer->nInterVal);
	pTimer->nGridIndex = nTemp % m_TimerAxisSec.size();

	pTimerList->push_back(pTimer);

	m_TimerAxisSec[pTimer->nGridIndex]->push_back(pTimer);
	pTimer->pos = --m_TimerAxisSec[pTimer->nGridIndex]->end();

	return true;
}

bool NFTimerAxis::SetTimer(uint32_t nTimerID, uint64_t nInterVal, NFTimerObj* handler, uint32_t nCallCount /*= INFINITY_CALL*/)
{
	if (nullptr == handler)
	{
		//错误，回调指针为空，需要打印日志
		return false;
	}
	if (nCallCount == 0)
	{
		//错误，调用次数为0，需要打印日志
		nCallCount = INFINITY_CALL;
	}
	if (nInterVal < TIMER_AXIS_CHECK_FREQUENCE)
	{
		nInterVal = TIMER_AXIS_CHECK_FREQUENCE;
	}
	if (nInterVal >= 2000)
	{
		//间隔大于两秒的当做秒刻度时间轴
		return SetTimerSec(nTimerID, nInterVal / 1000, handler, nCallCount);
	}

	bool bNeedFind = true;
	void** ppTimerInfo = handler->GetTimerInfoPtr();
	TIMER_LIST* pTimerList = *(TIMER_LIST**)ppTimerInfo;
	if (nullptr == pTimerList)
	{
		pTimerList = new TIMER_LIST();
		*ppTimerInfo = pTimerList;
		bNeedFind = false;
	}

	Timer* pTimer = nullptr;
	if (bNeedFind)
	{
		TIMER_LIST::iterator iter = pTimerList->begin();
		for (; iter != pTimerList->end(); ++iter)
		{
			pTimer = (*iter);
			if (pTimer->nTimerID == nTimerID)
			{
				//定时器ID 已存在
				return false;
			}
		}
	}

	CheckTick();
	pTimer = new Timer();
	pTimer->nTimerID = nTimerID;
	pTimer->nInterVal = nInterVal;
	pTimer->pHandler = handler;
	pTimer->nCallCount = nCallCount;
	pTimer->nLastTick = m_nLastTick;
	pTimer->byType = 0;
	uint64_t nTemp = pTimer->nLastTick - m_nInitTick + pTimer->nInterVal;
	pTimer->nGridIndex = (nTemp / TIME_GRID) % m_TimerAxis.size();

	pTimerList->push_back(pTimer);

	m_TimerAxis[pTimer->nGridIndex]->push_back(pTimer);
	pTimer->pos = --m_TimerAxis[pTimer->nGridIndex]->end();

	return true;
}

//关闭定时器
bool NFTimerAxis::KillTimer(uint32_t nTimerID, NFTimerObj* handler)
{
	if (nullptr == handler)
	{
		return false;
	}

	void** ppTimerInfo = handler->GetTimerInfoPtr();
	TIMER_LIST* pTimerList = *(TIMER_LIST**)ppTimerInfo;
	if (nullptr == pTimerList)
	{
		return false;
	}

	TIMER_LIST::iterator iter = pTimerList->begin();
	for (; iter != pTimerList->end(); ++iter)
	{
		Timer* pTimer = (*iter);
		if (pTimer && pTimer->nTimerID == nTimerID)
		{
			pTimerList->erase(iter);
			pTimer->nCallCount = 0;
			pTimer->pHandler = nullptr;

			//重置定时器在时间轴上的位置
			ResetTimerPos(pTimer);

			NF_SAFE_DELETE(pTimer);

			if (pTimerList->empty())
			{
				NF_SAFE_DELETE(pTimerList);
				*ppTimerInfo = nullptr;
			}

			return true;
		}
	}

	return false;
}

//关闭所有定时器
bool NFTimerAxis::KillAllTimer(NFTimerObj* handler)
{
	if (nullptr == handler)
	{
		return false;
	}

	void** ppTimerInfo = handler->GetTimerInfoPtr();
	TIMER_LIST* pTimerList = *(TIMER_LIST**)ppTimerInfo;
	if (nullptr == pTimerList)
	{
		return false;
	}

	TIMER_LIST::iterator iter = pTimerList->begin();
	for (; iter != pTimerList->end(); ++iter)
	{
		Timer* pTimer = (*iter);
		if (nullptr != pTimer)
		{
			pTimer->nCallCount = 0;
			pTimer->pHandler = nullptr;

			//重置定时器在时间轴上的位置
			ResetTimerPos(pTimer);
			NF_SAFE_DELETE(pTimer);
		}
	}
	pTimerList->clear();
	NF_SAFE_DELETE(pTimerList);
	*ppTimerInfo = nullptr;

	return false;
}

//检查tick
void NFTimerAxis::CheckTick()
{
	uint64_t nowTick = GetTick();
	if (nowTick < m_nLastTick || nowTick < m_nInitTick || m_nLastTick < m_nInitTick)
	{
		m_nInitTick = nowTick;
		m_nLastTick = nowTick;
	}
}

bool NFTimerAxis::SetCalender(uint32_t nTimerID, const std::string& timeStr, NFTimerObj* handler, uint32_t nCallCount /* = INFINITY_CALL*/)
{
	return true;
}

//设置固定时间的定时器
bool NFTimerAxis::SetClocker(uint32_t nTimerID, uint64_t nStartTime, uint32_t nInterSec, NFTimerObj* handler, uint32_t nCallCount /*= INFINITY_CALL*/)
{
	if (nullptr == handler)
	{
		return false;
	}
	if (nCallCount == 0)
	{
		return false;
	}
	if (nInterSec < 1)
	{
		nInterSec = 1;
	}

	bool bNeedFind = true;
	void** ppTimerInfo = handler->GetTimerInfoPtr();
	TIMER_LIST* pTimerList = *(TIMER_LIST**)ppTimerInfo;
	if (nullptr == pTimerList)
	{
		pTimerList = new TIMER_LIST();
		*ppTimerInfo = pTimerList;
		bNeedFind = false;
	}

	Timer* pTimer = nullptr;
	if (bNeedFind)
	{
		TIMER_LIST::iterator iter = pTimerList->begin();
		for (; iter != pTimerList->end(); ++iter)
		{
			pTimer = (*iter);
			if (pTimer->nTimerID == nTimerID)
			{
				//定时器ID 已存在
				return false;
			}
		}
	}

	pTimer = new Timer();
	pTimer->byType = 1;
	pTimer->nTimerID = nTimerID;
	pTimer->nCallCount = nCallCount;
	pTimer->nInterVal = nInterSec;
	pTimer->pHandler = handler;
	pTimer->nLastTick = m_nLastSec;

	uint64_t nowTime = GetUnixSec();
	uint64_t nowDaySecs = nowTime % nInterSec;

	if (nInterSec >= 8 * 60 * 60)
	{
		//转换格林威治时间
		nStartTime += nInterSec - 8 * 60 * 60;
		nStartTime %= nInterSec;

		//为了在接下来的固定时间点立刻生效，构造pTimer 最近一次回调时间
		if (nStartTime < nowDaySecs)
		{
			//当前已经过了固定开始时间
			pTimer->nLastTick = (nowTime / nInterSec) * nInterSec + nStartTime;
		}
		else
		{
			//
			pTimer->nLastTick = (nowTime / nInterSec) * nInterSec - nInterSec + nStartTime;
		}
	}
	else
	{
		pTimer->nLastTick = (nowTime / nInterSec) * nInterSec + nStartTime - (8 * 60 * 60 - nInterSec) % nInterSec;
	}

	uint32_t nTemp = (uint32_t)(pTimer->nLastTick - m_nInitSec + pTimer->nInterVal);
	pTimer->nGridIndex = nTemp % m_TimerAxisSec.size();

	pTimerList->push_back(pTimer);

	m_TimerAxisSec[pTimer->nGridIndex]->push_back(pTimer);
	pTimer->pos = --m_TimerAxisSec[pTimer->nGridIndex]->end();

	return true;
}

void NFTimerAxis::Update()
{
	CheckTick();

	uint64_t now = GetTick();

	if ((now - m_nLastTick) < TIMER_AXIS_CHECK_FREQUENCE)
	{
		return;
	}

	uint32_t start_grid = (static_cast<uint32_t>(m_nLastTick - m_nInitTick) / TIME_GRID) % m_TimerAxis.size();
	uint32_t cur_grid = (static_cast<uint32_t>(now - m_nInitTick) / TIME_GRID) % m_TimerAxis.size();

	m_nLastTick = now;

	uint32_t i = start_grid;

	int iCount = 0;
	bool bFlag = true;
	// 遍历时间刻度
	do
	{
		iCount++;
		if (iCount == 1000)
		{
			//某一个刻度定时器过多，这里打印一下日志
		}
		// 遍历当前时间刻度中的所有待触发定时器
		TIMER_LIST* TimerList = m_TimerAxis[i];
		TIMER_LIST::iterator it = TimerList->begin();
		for (; it != TimerList->end();)
		{
			Timer* pTimer = *it;
			if (nullptr == pTimer || nullptr == pTimer->pHandler)
			{
				it = TimerList->erase(it);
				continue;
			}
			if (pTimer->nCallCount == 0)
			{
				it = TimerList->erase(it);
				NF_SAFE_DELETE(pTimer);
				continue;
			}

			// 触发定时器
			if (now < pTimer->nLastTick)
			{
				pTimer->nLastTick = now;
			}
			if (static_cast<uint32_t>(now - pTimer->nLastTick) >= pTimer->nInterVal)
			{
				pTimer->pHandler->OnTimer(pTimer->nTimerID);

				pTimer = *it;
				if (nullptr == pTimer || nullptr == pTimer->pHandler)
				{
					it = TimerList->erase(it);
					continue;
				}

				pTimer->nLastTick = pTimer->nLastTick + ((now - pTimer->nLastTick) / pTimer->nInterVal) * pTimer->nInterVal;
				//pTimer->nLastTick = now; //会不断积累误差
				if (pTimer->nCallCount > 0)
				{
					pTimer->nCallCount -= 1;
				}

				if (pTimer->nCallCount == 0)
				{
					// 调用次数已经够了
					KillTimer(pTimer->nTimerID, pTimer->pHandler);
					it = TimerList->erase(it);
					continue;
				}
				else
				{
					// 搬迁到下一次触发的位置
					it = TimerList->erase(it);
					if (pTimer->nLastTick < m_nInitTick)
					{
						pTimer->nLastTick = m_nLastTick;
					}
					uint32_t nTemp = static_cast<uint32_t>((pTimer->nLastTick - m_nInitTick) + pTimer->nInterVal);
					pTimer->nGridIndex = (nTemp / TIME_GRID) % m_TimerAxis.size();
					m_TimerAxis[pTimer->nGridIndex]->push_back(pTimer);
					pTimer->pos = --m_TimerAxis[pTimer->nGridIndex]->end();
				}

				continue;
			} // end of if ((uint32_t)(now - pTimer->nLastTick) >= pTimer->nInterVal)

			++it;
		}

		// 递进到下一个刻度
		if (i == cur_grid)
		{
			bFlag = false;
		}
		else
		{
			i = (i + 1) % m_TimerAxis.size();
		}
	}
	while (bFlag);

	//更新秒定时器
	UpdateSec();
}

void NFTimerAxis::UpdateSec()
{
	uint64_t now = GetUnixSec();

	if (now - m_nLastSec < 1)
	{
		return;
	}

	uint32_t start_grid = static_cast<uint32_t>(m_nLastSec - m_nInitSec) % m_TimerAxisSec.size();
	uint32_t cur_grid = static_cast<uint32_t>(now - m_nInitSec) % m_TimerAxisSec.size();

	m_nLastSec = now;

	uint32_t i = start_grid;

	int iCount = 0;
	bool bFlag = true;
	// 遍历时间刻度
	do
	{
		iCount++;
		if (iCount == 60)
		{
		}
		// 遍历当前时间刻度中的所有待触发定时器
		TIMER_LIST* TimerList = m_TimerAxisSec[i];
		TIMER_LIST::iterator it = TimerList->begin();
		for (; it != TimerList->end();)
		{
			Timer* pTimer = *it;
			if (nullptr == pTimer || nullptr == pTimer->pHandler)
			{
				it = TimerList->erase(it);
				continue;
			}

			if (pTimer->nCallCount == 0)
			{
				it = TimerList->erase(it);
				NF_SAFE_DELETE(pTimer);
				continue;
			}

			// 触发定时器
			if (now < pTimer->nLastTick)
			{
				pTimer->nLastTick = now;
			}
			if ((now - pTimer->nLastTick) >= pTimer->nInterVal)
			{
				pTimer->pHandler->OnTimer(pTimer->nTimerID);
				//这里需要重新赋值下，避免在回调中把
				pTimer = *it;
				if (nullptr == pTimer || nullptr == pTimer->pHandler)
				{
					it = TimerList->erase(it);
					continue;
				}

				pTimer->nLastTick = pTimer->nLastTick + ((now - pTimer->nLastTick) / pTimer->nInterVal) * pTimer->nInterVal;
				//pTimer->nLastTick = now;
				if (pTimer->nCallCount > 0)
				{
					pTimer->nCallCount -= 1;
				}

				if (pTimer->nCallCount == 0)
				{
					// 调用次数已经够了
					KillTimer(pTimer->nTimerID, pTimer->pHandler);
					it = TimerList->erase(it);

					continue;
				}
				else
				{
					// 搬迁到下一次触发的位置
					it = TimerList->erase(it);
					if (pTimer->nLastTick < m_nInitSec)
					{
						pTimer->nLastTick = m_nLastSec;
					}
					uint64_t nTemp = (pTimer->nLastTick - m_nInitSec) + pTimer->nInterVal;
					pTimer->nGridIndex = nTemp % m_TimerAxisSec.size();
					m_TimerAxisSec[pTimer->nGridIndex]->push_back(pTimer);
					pTimer->pos = --m_TimerAxisSec[pTimer->nGridIndex]->end();
				}

				continue;
			}

			++it;
		}

		// 递进到下一个刻度
		if (i == cur_grid)
		{
			bFlag = false;
		}
		else
		{
			i = (i + 1) % m_TimerAxisSec.size();
		}
	}
	while (bFlag);
}

//重置定时器在时间轴上的位置
bool NFTimerAxis::ResetTimerPos(Timer* pTimer)
{
	if (nullptr == pTimer)
	{
		return false;
	}
	(*pTimer->pos) = nullptr;

	return true;
}

