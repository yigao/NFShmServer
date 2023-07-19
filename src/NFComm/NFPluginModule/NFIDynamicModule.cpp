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

NFIDynamicModule::NFIDynamicModule(NFIPluginManager* p) : NFITimerEventModule(p)
{

}

NFIDynamicModule::~NFIDynamicModule()
{
	FindModule<NFIMessageModule>()->DelAllCallBack(this);
}

int NFIDynamicModule::OnTimer(uint32_t nTimerID)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "nTimerID:({}) not handle", nTimerID);
    return 0;
}

int NFIDynamicModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "Event msg:(evnetId:{} nSrcID:{} bySrcType:{}) not handle, message:{}", nEventID, nSrcID, bySrcType, pMessage->DebugString());
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

int NFIDynamicModule::OnHandleRpcMessage(uint32_t msgId, google::protobuf::Message* pRequest, google::protobuf::Message* pRespone, uint64_t param1, uint64_t param2)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "server rpc msgId:{} param1:{} param2:{} not handle", msgId, param1, param2);
    return 0;
}

/**
 * @brief 注册客户端信息处理函数
 * @param eType
 * @param nMsgID
 * @return
 */
bool NFIDynamicModule::RegisterClientMessage(NF_SERVER_TYPES eType, uint32_t nMsgID, bool createCo)
{
    NET_RECEIVE_FUNCTOR functor = std::bind((int(NFIDynamicModule::*)(uint64_t, NFDataPackage&))(&NFIDynamicModule::OnHandleClientMessage), this, std::placeholders::_1, std::placeholders::_2);
    return FindModule<NFIMessageModule>()->AddMessageCallBack(eType, NF_MODULE_CLIENT, nMsgID, this, functor, createCo);
}

/**
 * @brief 注册服务器信息处理函数
 * @param eType
 * @param nMsgID
 * @return
 */
bool NFIDynamicModule::RegisterServerMessage(NF_SERVER_TYPES eType, uint32_t nMsgID, bool createCo)
{
    NET_RECEIVE_FUNCTOR functor = std::bind((int(NFIDynamicModule::*)(uint64_t, NFDataPackage&))&NFIDynamicModule::OnHandleServerMessage, this, std::placeholders::_1, std::placeholders::_2);
    return FindModule<NFIMessageModule>()->AddMessageCallBack(eType, NF_MODULE_SERVER, nMsgID, this, functor, createCo);
}