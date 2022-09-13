// -------------------------------------------------------------------------
//    @FileName         :    NFShmQueue.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include <stddef.h>
#include <string.h>
#include "NFComm/NFPluginModule/NFPair.h"
#include "NFShmMgr.h"
#include "NFComm/NFCore/NFRandom.hpp"

template<typename DataType, int MAX_ELEMENT_NUM>
class NFShmQueue
{
public:
	enum
	{
		REAL_ELEMENT_NUM = MAX_ELEMENT_NUM + 1,
	};

	NFShmQueue()
	{
		if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
		{
			CreateInit();
		}
		else
		{
			ResumeInit();
		}
	}

	int CreateInit()
	{
		Initialize();
		return 0;
	}

	int ResumeInit()
	{
		return 0;
	}

	void Initialize()
	{
		Clear();
	}

	bool Empty() const
	{
		return (m_iFront == m_iRear);
	}

	bool Full() const
	{
		return (((m_iRear + 1) % REAL_ELEMENT_NUM) == m_iFront);
	}

	int Size() const
	{
		return (m_iRear + REAL_ELEMENT_NUM - m_iFront) % REAL_ELEMENT_NUM;
	}

	int Push(const DataType& Data)
	{
		if (Full())
		{
			return -1;
		}
		m_data[m_iRear] = Data;
		m_iRear = (m_iRear + 1) % REAL_ELEMENT_NUM;

		return 0;
	}

	int Pop()
	{
		if (!Empty())
		{
			m_iFront = (m_iFront + 1) % REAL_ELEMENT_NUM;
		}
		else
		{
			return -1;
		}
		return 0;
	}

	int Front(DataType& data)
	{
		if (!Empty())
		{
			data = m_data[m_iFront];
		}
		else
		{
			return -1;
		}
		return 0;
	}

	DataType * FrontPointer()
	{
		if (!Empty())
		{
			return &m_data[m_iFront];
		}

		return NULL;
	}

	DataType *GetData(int iPos)
	{
		return &m_data[iPos % REAL_ELEMENT_NUM];
	}

	int FrontPos()
	{
		return m_iFront;
	}

	int RearPos()
	{
		return m_iRear;
	}

	int Back(DataType& data)
	{
		if (!Empty())
		{
			data = m_data[(m_iRear - 1 + REAL_ELEMENT_NUM) % REAL_ELEMENT_NUM];
		}
		else
		{
			return -1;
		}
		return 0;
	}

	void Clear()
	{
		m_iFront = m_iRear = 0;
		memset(m_data, 0, sizeof(m_data));
	}
private:
	int m_iFront;
	int m_iRear;
	DataType m_data[REAL_ELEMENT_NUM];
};
