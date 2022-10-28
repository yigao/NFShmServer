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
    return OnHandleClientMessage(packet.nMsgId, packet, packet.nParam1, packet.nParam2);
}

int NFIDynamicModule::OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet)
{
    return OnHandleServerMessage(packet.nMsgId, packet, packet.nParam1, packet.nParam2);
}

int NFIDynamicModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "client msg:({}) not handle", packet.ToString());
    return 0;
}

int NFIDynamicModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "server msg:({}) not handle", packet.ToString());
    return 0;
}

/**
 * @brief 注册客户端信息处理函数
 * @param eType
 * @param nMsgID
 * @return
 */
bool NFIDynamicModule::RegisterClientMessage(NF_SERVER_TYPES eType, uint32_t nMsgID)
{
    NET_RECEIVE_FUNCTOR functor = std::bind((int(NFIDynamicModule::*)(uint64_t, NFDataPackage&))(&NFIDynamicModule::OnHandleClientMessage), this, std::placeholders::_1, std::placeholders::_2);
    return FindModule<NFIMessageModule>()->AddMessageCallBack(eType, NF_MODULE_CLIENT, nMsgID, this, functor);
}

/**
 * @brief 注册服务器信息处理函数
 * @param eType
 * @param nMsgID
 * @return
 */
bool NFIDynamicModule::RegisterServerMessage(NF_SERVER_TYPES eType, uint32_t nMsgID)
{
    NET_RECEIVE_FUNCTOR functor = std::bind((int(NFIDynamicModule::*)(uint64_t, NFDataPackage&))&NFIDynamicModule::OnHandleServerMessage, this, std::placeholders::_1, std::placeholders::_2);
    return FindModule<NFIMessageModule>()->AddMessageCallBack(eType, NF_MODULE_SERVER, nMsgID, this, functor);
}