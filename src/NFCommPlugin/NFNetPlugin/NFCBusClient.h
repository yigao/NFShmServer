// -------------------------------------------------------------------------
//    @FileName         :    NFCBusClient.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCBusClient.h
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

class NFCBusClient : public NFIBusConnection
{
public:
    explicit NFCBusClient(NFIPluginManager* p, NF_SERVER_TYPES serverType, const NFMessageFlag& flag, const NFMessageFlag& bindFlag):NFIBusConnection(p, serverType, flag)
    {
        m_bindFlag = bindFlag;
        mxSendBuffer.AssureSpace(MAX_SEND_BUFFER_SIZE);
    }

    virtual ~NFCBusClient();

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
    virtual int64_t ConnectServer(const NFMessageFlag& flag, const NFMessageFlag& bindFlag);

    /**
     * @brief	发送数据 不包含数据头
     *
     * @param pData		发送的数据,
     * @param unSize	数据的大小
     * @return
     */
    virtual bool Send(NFDataPackage& packet, const char* msg, uint32_t nLen) override;
    virtual bool Send(NFDataPackage& packet, const google::protobuf::Message& xData) override;

    virtual bool Send(NFShmChannel *pChannel, int packetParseType, NFDataPackage& packet, const char* msg, uint32_t nLen);
private:
    NFBuffer mxSendBuffer;
};
