// -------------------------------------------------------------------------
//    @FileName         :    NFAccountLoginMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-7-6
//    @Email			:    445267987@qq.com
//    @Module           :    NFAccountLoginMgr
//
// -------------------------------------------------------------------------

#include "NFAccountLoginMgr.h"
#include "NFComm/NFCore/NFHash.hpp"
#include "NFComm/NFCore/NFTime.h"

NFAccountLogin::NFAccountLogin()
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

NFAccountLogin::~NFAccountLogin()
{
}

int NFAccountLogin::CreateInit()
{
	mPlayerId = 0;
	mLastLoginTime = NFTime::Now().UnixSec();
	mAccountType = 0;
	mPhoneNum = 0;
	return 0;
}

int NFAccountLogin::ResumeInit()
{
	return 0;
}

NFAccountLoginMgr::NFAccountLoginMgr()
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

NFAccountLoginMgr::~NFAccountLoginMgr()
{
	if (m_timerId != INVALID_ID)
	{
		DeleteTimer(m_timerId);
		m_timerId = INVALID_ID;
	}
}

int NFAccountLoginMgr::CreateInit()
{
	m_timerId = INVALID_ID;

	m_timerId = SetTimer(100, 0, 0, 0, 10, 0);

	return 0;
}

int NFAccountLoginMgr::ResumeInit()
{
	return 0;
}

int NFAccountLoginMgr::OnTimer(int timeId, int callcount)
{
	Tick();
	return 0;
}

int NFAccountLoginMgr::Tick()
{
	uint64_t now = NFTime::Now().UnixSec();
	for (auto iter = m_accountMap.begin(); iter != m_accountMap.end();)
	{
		if (now - iter->second.mLastLoginTime >= MAX_ACCOUNT_EXIST_TIME)
		{
			iter = m_accountMap.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	return 0;
}

int NFAccountLoginMgr::ClearOne()
{
	m_accountMap.auto_erase(1);
	return 0;
}

NFAccountLogin* NFAccountLoginMgr::FindAccount(const std::string& account)
{
	auto iter = m_accountMap.find(account);
	if (iter != m_accountMap.end())
	{
		return &iter->second;
	}
	return nullptr;
}

NFAccountLogin* NFAccountLoginMgr::CreateAccount(const std::string& account, const std::string& password, uint64_t playerId, uint32_t accountType, const std::string& deviceId, uint64_t phonenum)
{
	NFCommonStr strAccount;
	strAccount = account;

	if (m_accountMap.full())
	{
		ClearOne();
	}

	if (m_accountMap.full())
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "m_accountMap full! CreateAccount:{} Failed!", account);
		return NULL;
	}

	auto iter = m_accountMap.emplace_hint(strAccount, NFAccountLogin());
	if (iter == m_accountMap.end())
	{
		NFLogError(NF_LOG_SYSTEMLOG, 0, "m_accountMap.emplace_hint account:{} Failed", account);
		return NULL;
	}

	NFAccountLogin* pLogin = &iter->second;

	pLogin->mAccount = account;
	pLogin->mPassword = password;
	pLogin->mPlayerId = playerId;
	pLogin->mAccountType = accountType;
	pLogin->mLastLoginTime = NFTime::Now().UnixSec();
	pLogin->mDeviceId = deviceId;
	pLogin->mPhoneNum = phonenum;

	return pLogin;
}
