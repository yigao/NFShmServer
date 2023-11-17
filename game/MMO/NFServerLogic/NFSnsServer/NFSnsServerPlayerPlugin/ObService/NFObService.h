// -------------------------------------------------------------------------
//    @FileName         :    NFObService.h
//    @Author           :    gaoyi
//    @Date             :    23-11-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFObService
//
// -------------------------------------------------------------------------

#pragma once

#include <NFComm/NFShmCore/NFSeqOP.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFObServiceModule.h"

class NFObService : public NFShmObjTemplate<NFObService, EOT_SNS_SERVICE_ID, NFShmObj>, public NFSeqOP
{
public:
    NFObService();

    virtual ~NFObService();

    int CreateInit();
    int ResumeInit();

public:
    /**
     * @brief
     * @param pMaster
     * @param partType
     * @param data
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(uint32_t serviceId);

    /**
     * @brief
     * @return
     */
    virtual int UnInit();

public:
    /**
     * @brief 注册要处理的消息
     * @return
     */
    virtual int RegisterMessage();

public:
    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet);

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet);

public:
    /**
     * @brief
     * @param nMsgID
     * @param createCo
     * @return
     */
    int RegisterClientMessage(uint32_t nMsgID, bool createCo = false);

    /**
     * @brief
     * @param nMsgID
     * @param createCo
     * @return
     */
    int RegisterServerMessage(uint32_t nMsgID, bool createCo = false);

    /**
     * @brief 添加rpc服务， 这里的handleRecieve只是用来强绑定Request和Respone的类型，如果类型对不上，编译期间就会报错
     * @tparam msgId
     * @tparam BaseType
     * @tparam RequestType
     * @tparam ResponeType
     * @param handleRecieve
     * @param createCo
     * @return
     */
    template<size_t msgId, typename BaseType, typename RequestType, typename ResponeType>
    int AddRpcService(BaseType* pBase, int (BaseType::*handleRecieve)(RequestType& request, ResponeType& respone), bool createCo = false)
    {
        return FindModule<NFObServiceModule>()->AddServiceRpc<msgId, BaseType, RequestType, ResponeType>(pBase, handleRecieve, m_serviceId, createCo);
    }

public:
    //部件类型
    uint32_t GetServiceId() const { return m_serviceId; }

    void SetServiceId(uint32_t partType) { m_serviceId = partType; }

public:
    uint32_t m_serviceId;
};
