// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFAccountLoginMgr.h"
#include "NFComm/NFCore/NFHash.hpp"
#include "NFComm/NFPluginModule/NFCommLogic.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFTime.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFAccountLoginMgr, EOT_ACCOUNTLOGIN_HASHTABLE_ID, NFShmObj)

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

    m_oAccountHash.Init(NFAccountLoginMgr::GetExternalBuffer(), NFAccountLoginMgr::GetExternalItemCount(), true);
	return 0;
}


int NFAccountLoginMgr::ResumeInit()
{
    m_oAccountHash.Init(NFAccountLoginMgr::GetExternalBuffer(), NFAccountLoginMgr::GetExternalItemCount(), false);
	return 0;
}

void NFAccountLoginMgr::OnTimer(int timeId, int callcount)
{
    Tick();
}

int NFAccountLoginMgr::Tick()
{
    uint64_t now = NFTime::Now().UnixSec();

    std::vector<int> vecIndex;
    int staticIndex = m_oAccountHash.GetHeadIndex();
    while(m_oAccountHash.CheckIndexUsed(staticIndex))
    {
        NFAccountLogin *pLogin = &m_oAccountHash[staticIndex];
        if (pLogin)
        {
            if (now - pLogin->mLastLoginTime >= MAX_ACCOUNT_EXIST_TIME)
            {
                vecIndex.push_back(staticIndex);
            }
        }
        staticIndex = m_oAccountHash.GetNextIndex(staticIndex);
    }

    for(int i = 0; i < (int)vecIndex.size(); i++)
    {
        if ((m_oAccountHash.CheckIndexUsed(vecIndex[i])))
        {
            m_oAccountHash.HashFreeByIndex(vecIndex[i]);
        }
    }
    return 0;
}

int NFAccountLoginMgr::ClearOne()
{
    m_oAccountHash.HashFreeHead();
    m_oAccountHash.SwapHashByMaxCount(m_oAccountHash.GetObjectCount()*0.9);
    return 0;
}

NFAccountLogin *NFAccountLoginMgr::FindAccount(const std::string& account)
{
    SZ_USER_ACCOUNT strAccount;
    strAccount = account;

    int index = m_oAccountHash.HashFind(strAccount);
    if (index >= 0)
    {
        return &m_oAccountHash[index];
    }

    return NULL;
}

NFAccountLogin *NFAccountLoginMgr::CreateAccount(const std::string& account, const std::string& password, uint64_t playerId, uint32_t accountType, const std::string& deviceId, uint64_t phonenum)
{
    SZ_USER_ACCOUNT strAccount;
    strAccount = account;

    if (m_oAccountHash.IsFull())
    {
        ClearOne();
    }

    int index =  m_oAccountHash.HashAlloc(strAccount);
    if (index < 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "m_oAccountHash.Insert account:{} Failed", account);
        return NULL;
    }
    NFAccountLogin* pLogin = &m_oAccountHash[index];

    pLogin->mAccount = account;
    pLogin->mPassword = password;
    pLogin->mPlayerId = playerId;
    pLogin->mAccountType = accountType;
    pLogin->mLastLoginTime = NFTime::Now().UnixSec();
    pLogin->mDeviceId = deviceId;
    pLogin->mPhoneNum = phonenum;

    return pLogin;
}
