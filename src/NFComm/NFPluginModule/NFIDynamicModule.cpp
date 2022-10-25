// -------------------------------------------------------------------------
//    @FileName         :    NFIDynamicModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFIDynamicModule
//
// -------------------------------------------------------------------------


#include "NFIDynamicModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFINamingModule.h"

NFIDynamicModule::NFIDynamicModule(NFIPluginManager* p) :NFIModule(p),NFTimerObj(p),NFEventObj(p)
{

}

NFIDynamicModule::~NFIDynamicModule()
{
	FindModule<NFIMessageModule>()->DelAllCallBack(this);
}

void NFIDynamicModule::OnTimer(uint32_t nTimerID)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "nTimerID:({}) not handle", nTimerID);
}

int NFIDynamicModule::OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "Event msg:(evnetId:{} nSrcID:{} bySrcType:{}) not handle, message:{}", nEventID, nSrcID, bySrcType, message.DebugString());
    return 0;
}

int NFIDynamicModule::OnHandleClientMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "client msg:({}) not handle", packet.ToString());
    return 0;
}

int NFIDynamicModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "server msg:({}) not handle", packet.ToString());
    return 0;
}

int NFIDynamicModule::InitAppInfo(NF_SERVER_TYPES eServerType, int time_out_ms)
{
    return FindModule<NFINamingModule>()->InitAppInfo(NF_ST_GAME_SERVER, 10000);
}

/**
 * @brief 注册要完成的服务器启动任务
 * @param eServerType
 * @param taskType
 * @param desc
 * @param initStatus
 * @return
 */
int NFIDynamicModule::RegisterAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, const std::string &desc,
                            uint32_t initStatus/* = APP_INIT_STATUS_SERVER_CONNECT*/)
{
    return m_pObjPluginManager->RegisterAppTask(eServerType, taskType, desc, initStatus);
}

/**
 * @brief 完成的服务器启动任务
 * @param eServerType
 * @param taskType
 * @param initStatus
 * @return
 */
int NFIDynamicModule::FinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType,
                          uint32_t initStatus/* = APP_INIT_STATUS_SERVER_CONNECT*/)
{
    return m_pObjPluginManager->FinishAppTask(eServerType, taskType, initStatus);
}