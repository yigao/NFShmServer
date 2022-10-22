// -------------------------------------------------------------------------
//    @FileName         :    NFCBusServer.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCBusServer.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIBusModule.h"
#include "NFComm/NFCore/NFSpinLock.h"
#include "NFBusHash.h"
#include "NFBusDefine.h"
#include "NFBusShm.h"
#include "NFINetMessage.h"
#include "NFNetDefine.h"
#include "NFComm/NFCore/NFBuffer.h"
#include "NFIBusConnection.h"
#include <map>

class NFCBusServer : public NFIBusConnection
{
public:
    explicit NFCBusServer(NFIPluginManager* p, NF_SERVER_TYPES serverType, const NFMessageFlag& flag);

    virtual ~NFCBusServer();

    virtual bool Execute() override;

    virtual bool Init() override;

    virtual bool Shut() override;

    virtual bool Finalize() override;
public:
    /**
    * @brief	初始化
    *
    * @return 是否成功
    */
    virtual int64_t BindServer(const NFMessageFlag& flag);

    /**
     * @brief 主线程处理消息队列
     */
    virtual void ProcessMsgLogicThread();

    virtual bool Send(NFDataPackage& packet, const char* msg, uint32_t nLen) override;
    virtual bool Send(NFDataPackage& packet, const google::protobuf::Message& xData) override;
private:
    /**
     * @brief 服务器每一帧处理的消息数
     */
    uint32_t mHandleMsgNumPerFrame;
};
