// -------------------------------------------------------------------------
//    @FileName         :    NFLogicObService.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicObService
//
// -------------------------------------------------------------------------

#include "NFLogicObService.h"

NFLogicObService::NFLogicObService()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFLogicObService::~NFLogicObService()
{
}

int NFLogicObService::CreateInit()
{
    return 0;
}

int NFLogicObService::ResumeInit()
{
    return 0;
}

int NFLogicObService::RegisterMessage()
{
    return 0;
}

int NFLogicObService::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "client service package not handle:{}", packet.ToString());
    return 0;
}

int NFLogicObService::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "server service package not handle:{}", packet.ToString());
    return 0;
}

int NFLogicObService::RegisterClientMessage(uint32_t nMsgID, bool createCo)
{
    return FindModule<NFLogicObServiceModule>()->RegisterClientMessage(NF_ST_LOGIC_SERVER, nMsgID, GetServiceId(), createCo);
}

int NFLogicObService::RegisterServerMessage(uint32_t nMsgID, bool createCo)
{
    return FindModule<NFLogicObServiceModule>()->RegisterServerMessage(NF_ST_LOGIC_SERVER, nMsgID, GetServiceId(), createCo);
}
