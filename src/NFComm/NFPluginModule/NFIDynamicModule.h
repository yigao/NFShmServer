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


/**
* @brief 用来实现动态加载的模块，所有可以动态加载的引擎的module都需要继承这个类
*/

class NFIDynamicModule : public NFIModule, public NFTimerObj, public NFEventObj
{
public:
	NFIDynamicModule(NFIPluginManager* p);

	virtual ~NFIDynamicModule();

	virtual void OnTimer(uint32_t nTimerID);

	virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message);

    /**
     * @brief 注册客户端信息处理函数
     * @param eType
     * @param nMsgID
     * @return
     */
    virtual bool RegisterClientMessage(NF_SERVER_TYPES eType, uint32_t nMsgID)
    {
        NET_RECEIVE_FUNCTOR functor = std::bind(&NFIDynamicModule::OnHandleClientMessage, this, std::placeholders::_1, std::placeholders::_2);
        return FindModule<NFIMessageModule>()->AddMessageCallBack(eType, NF_MODULE_CLIENT, nMsgID, this, functor);
    }

    /**
     * @brief 注册服务器信息处理函数
     * @param eType
     * @param nMsgID
     * @return
     */
    virtual bool RegisterServerMessage(NF_SERVER_TYPES eType, uint32_t nMsgID)
    {
        NET_RECEIVE_FUNCTOR functor = std::bind(&NFIDynamicModule::OnHandleServerMessage, this, std::placeholders::_1, std::placeholders::_2);
        return FindModule<NFIMessageModule>()->AddMessageCallBack(eType, NF_MODULE_SERVER, nMsgID, this, functor);
    }

    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint64_t unLinkId, NFDataPackage& packet);

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint64_t unLinkId, NFDataPackage& packet);

    /// @brief 初始化zookeeper连接
    /// @param host zk地址，如 "127.0.0.1:1888,127.0.0.1:2888"
    /// @param time_out_ms 连接超时时间，单位ms，默认为20s，当<=0时使用默认值
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int InitAppInfo(NF_SERVER_TYPES eServerType, int time_out_ms = 20000);

    /**
     * @brief 注册要完成的服务器启动任务
     * @param eServerType
     * @param taskType
     * @param desc
     * @param initStatus
     * @return
     */
    virtual int RegisterAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, const std::string &desc,
                                uint32_t initStatus = APP_INIT_STATUS_SERVER_CONNECT);

    /**
     * @brief 完成的服务器启动任务
     * @param eServerType
     * @param taskType
     * @param initStatus
     * @return
     */
    virtual int FinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType,
                              uint32_t initStatus = APP_INIT_STATUS_SERVER_CONNECT);
};
