// -------------------------------------------------------------------------
//    @FileName         :    NFIDynamicModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFIDynamicModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFPluginModule/NFTimerObj.h"
#include "NFComm/NFPluginModule/NFEventObj.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFConfigDefine.h"
#include "NFEventObj.h"
#include "NFITimerEventModule.h"


/**
* @brief 用来实现动态加载的模块，所有可以动态加载的引擎的module都需要继承这个类
*/

class NFIDynamicModule : public NFITimerEventModule
{
public:
	NFIDynamicModule(NFIPluginManager* p);

	virtual ~NFIDynamicModule();

	virtual int OnTimer(uint32_t nTimerID) override;

	virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage) override;

    virtual int RegisterAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, const std::string &desc,
                                uint32_t taskGroup)
    {
        return m_pObjPluginManager->RegisterAppTask(eServerType, taskType, desc, taskGroup);
    }

    virtual int FinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType,
                              uint32_t taskGroup)
    {
        return m_pObjPluginManager->FinishAppTask(eServerType, taskType, taskGroup);
    }

    template<size_t msgId, typename RequestType, typename ResponeType>
    bool AddRpcService(NF_SERVER_TYPES serverType, bool createCo = false)
    {
        return FindModule<NFIMessageModule>()->AddRpcService<msgId, NFIDynamicModule, RequestType, ResponeType>(serverType, this, &NFIDynamicModule::OnHandleRpcMessage, createCo);
    }

    /**
     * @brief 注册客户端信息处理函数
     * @param eType
     * @param nMsgID
     * @return
     */
    virtual bool RegisterClientMessage(NF_SERVER_TYPES eType, uint32_t nMsgID, bool createCo = false);

    /**
     * @brief 注册服务器信息处理函数
     * @param eType
     * @param nMsgID
     * @return
     */
    virtual bool RegisterServerMessage(NF_SERVER_TYPES eType, uint32_t nMsgID, bool createCo = false);

    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2);

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet, uint64_t param1, uint64_t param2);

    /** 处理服务器之间的rpc，这里负责转发玩家part的rpc
     * @brief
     * @param msgId
     * @param pRequest
     * @param pRespone
     * @param param1
     * @param param2
     * @return
     */
    virtual int OnHandleRpcMessage(uint32_t msgId, google::protobuf::Message& request, google::protobuf::Message& respone, uint64_t param1, uint64_t param2);
};
