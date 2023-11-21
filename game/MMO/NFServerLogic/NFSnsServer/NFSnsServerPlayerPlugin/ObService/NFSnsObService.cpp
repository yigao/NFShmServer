// -------------------------------------------------------------------------
//    @FileName         :    NFSnsObService.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsObService
//
// -------------------------------------------------------------------------

#include "NFSnsObService.h"

NFSnsObService::NFSnsObService()
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

NFSnsObService::~NFSnsObService()
{
}

int NFSnsObService::CreateInit()
{
    m_iServerType = NF_ST_SNS_SERVER;
    return 0;
}
    
int NFSnsObService::ResumeInit()
{
    return 0;
}

int NFSnsObService::RegisterMessage()
{
    return 0;
}

int NFSnsObService::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "client service package not handle:{}", packet.ToString());
    return 0;
}

int NFSnsObService::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "server service package not handle:{}", packet.ToString());
    return 0;
}

int NFSnsObService::RegisterClientMessage(uint32_t nMsgID, bool createCo)
{
    return FindModule<NFSnsObServiceModule>()->RegisterClientMessage(NF_ST_SNS_SERVER, nMsgID, GetServiceId(), createCo);
}

int NFSnsObService::RegisterServerMessage(uint32_t nMsgID, bool createCo)
{
    return FindModule<NFSnsObServiceModule>()->RegisterServerMessage(NF_ST_SNS_SERVER, nMsgID, GetServiceId(), createCo);
}
