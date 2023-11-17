// -------------------------------------------------------------------------
//    @FileName         :    NFObService.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFObService
//
// -------------------------------------------------------------------------

#include "NFObService.h"

NFObService::NFObService()
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

NFObService::~NFObService()
{
}

int NFObService::CreateInit()
{
    m_serviceId = 0;
    return 0;
}
    
int NFObService::ResumeInit()
{
    return 0;
}

int NFObService::Init(uint32_t serviceId)
{
    m_serviceId = serviceId;
    return 0;
}

int NFObService::UnInit()
{
    return 0;
}

int NFObService::RegisterMessage()
{
    return 0;
}

int NFObService::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "client service package not handle:{}", packet.ToString());
    return 0;
}

int NFObService::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "server service package not handle:{}", packet.ToString());
    return 0;
}

int NFObService::RegisterClientMessage(uint32_t nMsgID, bool createCo)
{
    return FindModule<NFObServiceModule>()->RegisterClientMessage(NF_ST_SNS_SERVER, nMsgID, m_serviceId, createCo);
}

int NFObService::RegisterServerMessage(uint32_t nMsgID, bool createCo)
{
    return FindModule<NFObServiceModule>()->RegisterServerMessage(NF_ST_SNS_SERVER, nMsgID, m_serviceId, createCo);
}
