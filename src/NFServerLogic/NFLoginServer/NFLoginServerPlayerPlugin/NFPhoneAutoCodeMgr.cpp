// -------------------------------------------------------------------------
//    @FileName         :    NFPhoneAutoCodeMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPhoneAutoCodeMgr.cpp
//
// -------------------------------------------------------------------------

#include "NFPhoneAutoCodeMgr.h"

#include "NFComm/NFCore/NFHash.hpp"
#include "NFComm/NFPluginModule/NFCommLogic.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFTime.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPhoneAutoCode, EOT_PHONE_AUTO_CODE_ID, NFShmObj)
IMPLEMENT_IDCREATE_WITHTYPE(NFPhoneAutoCodeMgr, EOT_PHONE_AUTO_CODE_MGR_ID, NFShmObj)

NFPhoneAutoCode::NFPhoneAutoCode()
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

NFPhoneAutoCode::~NFPhoneAutoCode()
{

}

int NFPhoneAutoCode::CreateInit()
{
    m_phoneNum = 0;
    m_lastTime = 0;
    m_checkSuccess = false;
    m_codeType = 0;
    return 0;
}


int NFPhoneAutoCode::ResumeInit()
{
    return 0;
}

NFPhoneAutoCodeMgr::NFPhoneAutoCodeMgr()
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

NFPhoneAutoCodeMgr::~NFPhoneAutoCodeMgr()
{
    if (m_timerId != INVALID_ID)
    {
        DeleteTimer(m_timerId);
        m_timerId = INVALID_ID;
    }
}

int NFPhoneAutoCodeMgr::CreateInit()
{
    m_timerId = INVALID_ID;

    m_timerId = SetTimer(1000, 0, 0, 0, 10, 0);
    return 0;
}


int NFPhoneAutoCodeMgr::ResumeInit()
{
    return 0;
}

void NFPhoneAutoCodeMgr::OnTimer(int timeId, int callcount)
{
    Tick();
}

int NFPhoneAutoCodeMgr::Tick()
{
    std::vector<uint64_t> delVec;
    uint64_t now = NFTime::Now().UnixSec();
    NFPhoneAutoCode* pPhone = dynamic_cast<NFPhoneAutoCode*>(NFShmMgr::Instance()->GetHeadObj(EOT_PHONE_AUTO_CODE_ID));
    while(pPhone)
    {
        if (now - pPhone->m_lastTime >= MAX_ACCOUNT_EXIST_TIME)
        {
            delVec.push_back(pPhone->m_phoneNum);
        }
        pPhone = dynamic_cast<NFPhoneAutoCode*>(NFShmMgr::Instance()->GetNextObj(EOT_PHONE_AUTO_CODE_ID, pPhone));
    }

    for(int i = 0; i < (int)delVec.size(); i++)
    {
        DeletePhone(delVec[i]);
    }
    return 0;
}

int NFPhoneAutoCodeMgr::ReleaseNum(int num)
{
    NFShmMgr::Instance()->DestroyObjAutoErase(EOT_PHONE_AUTO_CODE_ID, NFPhoneAutoCode::GetUsedCount() >= num ? NFPhoneAutoCode::GetUsedCount() - num : 0);
    return 0;
}

int NFPhoneAutoCodeMgr::DeletePhone(uint64_t phoneNum)
{
    NFPhoneAutoCode* pPhone = FindPhone(phoneNum);
    CHECK_NULL(pPhone);
    NFShmMgr::Instance()->DestroyObj(pPhone);
    return 0;
}

NFPhoneAutoCode *NFPhoneAutoCodeMgr::FindPhone(uint64_t phoneNum)
{
    return dynamic_cast<NFPhoneAutoCode*>(NFShmMgr::Instance()->GetObjFromHashKey(phoneNum, EOT_PHONE_AUTO_CODE_ID));
}

NFPhoneAutoCode *NFPhoneAutoCodeMgr::CreatePhone(uint64_t phoneNum)
{
    if (IsFull())
    {
        ReleaseNum(NFPhoneAutoCode::GetItemCount()*0.1);
    }

    NFPhoneAutoCode *pLogin =  dynamic_cast<NFPhoneAutoCode*>(NFShmMgr::Instance()->CreateObj(phoneNum, EOT_PHONE_AUTO_CODE_ID));
    if (pLogin == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "m_phoneMap.CreateObj phone:{} Failed", phoneNum);
        return NULL;
    }

    pLogin->m_phoneNum = phoneNum;
    pLogin->m_lastTime = NFTime::Now().UnixSec();

    return pLogin;
}
