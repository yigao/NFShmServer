// -------------------------------------------------------------------------
//    @FileName         :    NFRoleDetail.h
//    @Author           :    gaoyi
//    @Date             :    22-11-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleDetail
//
// -------------------------------------------------------------------------

#pragma once

#include <NFLogicCommon/NFISaveDB.h>
#include <NFLogicCommon/NFPlayerStatus.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "AllProtocol.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFPluginModule/NFICoroutineModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFLogicCommon/NFCharactorDefine.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFSnsPart;
class NFPlayerSimple;

class NFPlayerDetail : public NFShmObjTemplate<NFPlayerDetail, EOT_SNS_ROLE_DETAIL_ID, NFShmObj>, public NFISaveDB, public NFPlayerStatus
{
public:
    NFPlayerDetail();

    virtual ~NFPlayerDetail();

    int CreateInit();

    int ResumeInit();

public:
    uint64_t GetCid() const;

    uint64_t Cid() const;

    void SetCid(uint64_t cid);

    uint32_t GetUid() const;

    void SetUid(uint32_t uid);

    uint32_t GetZid() const;

    void SetZid(uint32_t zid);

public:
    bool IsInited() const;

    void SetIsInited(bool isInited);

public:
    //must be virtual
    virtual int OnTimer(int timeId, int callcount);

public:
    /**
     * \brief 处理继承NFPlayerStatus 负责玩家数据的生命周期管理
     */
    virtual uint64_t StatusId() const { return GetCid(); }
    virtual bool IsCanLogout();

    virtual int DoOnline();

    virtual bool IsCanDead();

    virtual int DoLogout();

    bool CanDelete();

public:
    /**
     * @brief
     * @param data
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(const proto_ff::RoleDBSnsDetail& data);

    /**
     * @brief
     * @return
     */
    virtual int UnInit();

public:
    uint32_t GetLogicId() const;

    void SetLogicId(uint32_t logicId);

    uint32_t GetGameId() const;

    void SetGameId(uint32_t gameId);

    uint32_t GetProxyId() const;

    void SetProxyId(uint32_t proxyId);

public:
    int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message& xData);

    int SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message& xData);
    int SendTransToLogicServer(uint32_t msgId, const google::protobuf::Message& xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message& xData);
    int SendTransToWorldServer(uint32_t msgId, const google::protobuf::Message& xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    int SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message& xData);
    int SendTransToGameServer(uint32_t msgId, const google::protobuf::Message& xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

public:
    /**
    * \brief 处理继承NFISaveDB
    */
    bool IsNeedSave();

    /**
     * @brief
     * @param iReason
     * @return
     */
    int SendTransToDB(TRANS_SAVEROLEDETAIL_REASON iReason = TRANS_SAVEROLEDETAIL_NORMAL);

    /**
     * @brief
     * @return
     */
    uint32_t GetAllSeq();

    /**
     * @brief
     */
    void ClearAllSeq();

public:
    /**
     * @brief 在协程里获取远程服务器的rpc服务, 这个程序必须在协程里调用，需要先创建协程
     * @return 如果你在player或part的函数里，请优先调用这个函数，而不是调用FindModule<NFIMessageModule>()->GetRpcService系统函数， 因为玩家的生命周期是不确定的
     */
    template<size_t msgId, typename RequestType, typename ResponeType>
    int GetRpcService(NF_SERVER_TYPES dstServerType, uint32_t dstBusId, const RequestType& request, ResponeType& respone)
    {
        FindModule<NFICoroutineModule>()->AddUserCo(m_cid);
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<msgId>(NF_ST_SNS_SERVER, dstServerType, dstBusId, request, respone, m_cid);
        FindModule<NFICoroutineModule>()->DelUserCo(m_cid);
        return iRet;
    }

public:
    /**
     * @brief 创建Part
     * @param partType
     * @param data
     * @param bCreatePlayer
     * @return
     */
    NFSnsPart* CreatePart(uint32_t partType, const ::proto_ff::RoleDBSnsDetail& data);

    /**
     * @brief 创建Part
     * @param partType
     * @return
     */
    NFSnsPart* CreatePart(uint32_t partType);

    /**
     * @brief 释放Part
     * @param pPart
     * @return
     */
    int RecylePart(NFSnsPart* pPart);

    //获取对应部件指针
    virtual NFSnsPart* GetPart(uint32_t partType);

    template<typename PART>
    PART* GetPart(uint32_t partType)
    {
        return dynamic_cast<PART *>(GetPart(partType));
    }

public:
    NFPlayerSimple* GetRoleSimple() const;

public:
    /**
     * @brief
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::RoleDBSnsDetail& data);

    /**
     * @brief
     * @param data
     * @return
     */
    virtual int SaveDB(proto_ff::RoleDBSnsDetail& data);

    /**
     * @brief
     * @return
     */
    virtual int InitConfig(const proto_ff::RoleDBSnsDetail& data);

    /**
     * @brief
     * @return
     */
    virtual int Update();

public:
    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin();

    /**
     * @brief 登出入口
     * @return
     */
    virtual int OnLogout();

    /**
     * @brief 掉线入口
     * @return
     */
    virtual int OnDisconnect();

    /**
     * @brief 重连入口
     * @return
     */
    virtual int OnReconnect();

    ////////////////////////////////// 每日每周刷新接口 ///////////////////////////////////
    /**
     * @brief 每日刷新接口
     * @param unixSec
     * @return
     */
    virtual int DailyZeroUpdate();

    /**
     * @brief 每周刷新接口
     * @param unixSec
     * @return
     */
    virtual int WeekZeroUpdate();

    /**
     * @brief 每月刷新接口
     * @param unixSec
     * @return
     */
    virtual int MonthZeroUpdate();

private:
    /**
     * @brief
     */
    bool m_isInited;

    /**
     * @brief
     */
    uint64_t m_cid;

    /**
     * \brief
     */
    uint32_t m_uid;

    /**
     * \brief
     */
    uint32_t m_zid;

    /**
     * @brief
     */
    uint32_t m_proxyId;

    /**
     * @brief
     */
    uint32_t m_logicId;

    /**
     * @brief
     */
    uint32_t m_gameId;

private:
    NFShmVector<NFShmPtr<NFSnsPart>, SNS_PART_MAX> m_pPart;
};
