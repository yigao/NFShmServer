// -------------------------------------------------------------------------
//    @FileName         :    NFSnsPart.h
//    @Author           :    gaoyi
//    @Date             :    23-3-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "AllProtocol.h"
#include "NFComm/NFPluginModule/NFIRpcService.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFSnsPartModule.h"
#include "NFLogicCommon/NFLogicBindRpcService.h"
#include "Cache/NFPlayerDetail.h"


class NFPlayerSimple;
class NFPlayerOnline;
class NFSnsPart : public NFShmObj, public NFSeqOP
{
public:
    NFSnsPart();

    virtual ~NFSnsPart();

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
    virtual int Init(NFPlayerDetail *pMaster, uint32_t partType, const proto_ff::RoleDBSnsDetail &data);

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
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet);

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet);

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
        return FindModule<NFSnsPartModule>()->AddPartRpcService<msgId, BaseType, RequestType, ResponeType>(pBase, handleRecieve, m_partType, createCo);
    }

    /**
     * @brief 在协程里获取远程服务器的rpc服务, 这个程序必须在协程里调用，需要先创建协程
     *        如果你在player或part的函数里，请优先调用这个函数，而不是调用FindModule<NFIMessageModule>()->GetRpcService系统函数， 因为玩家的生命周期是不确定的
     * @return
     */
    template<size_t msgId, typename RequestType, typename ResponeType>
    int GetRpcService(NF_SERVER_TYPES dstServerType, uint32_t dstBusId, const RequestType &request, ResponeType &respone)
    {
        return m_pMaster->GetRpcService<msgId>(dstServerType, dstBusId, request, respone);
    }
public:
    /**
     * @brief
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::RoleDBSnsDetail& data) { return 0; }

    /**
     * @brief
     * @return
     */
    virtual int InitConfig(const proto_ff::RoleDBSnsDetail& data) { return 0; }

    /**
     * @brief 存储DB部件入口
     * @param proto
     * @return
     */
    virtual int SaveDB(proto_ff::RoleDBSnsDetail &dbData) { return 0; }

    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin() { return 0; }

    /**
     * @brief 登出入口
     * @return
     */
    virtual int OnLogout() { return 0; }

    /**
     * @brief 掉线入口
     * @return
     */
    virtual int OnDisconnect() { return 0; }

    /**
     * @brief 重连入口
     * @return
     */
    virtual int OnReconnect() { return 0; }

public:
    ////////////////////////////////// 每日零点 每周一零点 刷新接口 ///////////////////////////////////
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int DailyZeroUpdate() { return 0; }

    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int WeekZeroUpdate() { return 0; }

    /**
     * @brief 每月刷新接口
     * @return
     */
    virtual int MonthZeroUpdate()  { return 0; }
public:
    /**
     * @brief update
     */
    virtual int Update() { return 0; }

public:
    virtual int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData);

    virtual int SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData);

    virtual int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData);

    virtual int SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData);
public:
    //部件类型
    uint32_t PartType() { return m_partType; }
    void SetPartType(uint32_t partType) { m_partType = partType; }
public:
    NFPlayerSimple* GetPlayerSimple();
    NFPlayerOnline* GetPlayerOnline();
protected:
    NFShmPtr<NFPlayerDetail> m_pMaster;
    uint64_t m_playerId;
    uint32_t m_partType;
private:
DECLARE_IDCREATE(NFSnsPart)
};