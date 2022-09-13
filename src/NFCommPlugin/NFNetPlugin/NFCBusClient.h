// -------------------------------------------------------------------------
//    @FileName         :    NFCBusClient.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
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
        m_eventLoop = NULL;
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
     * @brief	发送数据
     *
     * @param pData		发送的数据, 这里的数据已经包含了数据头
     * @param unSize	数据的大小
     * @return
     */
    virtual bool Send(const char* pData, uint32_t unSize) override;

    /**
     * @brief	发送数据 不包含数据头
     *
     * @param pData		发送的数据,
     * @param unSize	数据的大小
     * @return
     */
    virtual bool Send(uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId) override;

    virtual bool SendToLoop(NFShmChannel *pChannel, const char* pData, uint32_t unSize);
    virtual void SendStringInLoop(NFShmChannel *pChannel, const std::string& msg);
private:
    evpp::EventLoopThread* m_eventLoop;
};
