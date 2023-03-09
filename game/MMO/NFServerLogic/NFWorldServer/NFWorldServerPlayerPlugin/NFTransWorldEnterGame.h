// -------------------------------------------------------------------------
//    @FileName         :    NFTransWorldEnterGame.h
//    @Author           :    gaoyi
//    @Date             :    23-3-7
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransWorldEnterGame
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "ServerInternal2.pb.h"
#include "CSLogin.pb.h"

class NFTransWorldEnterGame : public NFTransBase
{
public:
    NFTransWorldEnterGame();

    virtual ~NFTransWorldEnterGame();

    int CreateInit();

    int ResumeInit();
public:
    int Init(uint64_t uid, uint64_t roleId, uint32_t proxyId, uint64_t clientId);

    int OnHandleEnterGame(const proto_ff::ClientEnterGameReq& req);

    int SendLoadRoleInfo(const proto_ff::WorldToLogicLoginReq& req);

    virtual int HandleDispSvrRes(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId);

public:
    /**
     * @brief 处理逻辑登陆返回
     * @param msgId
     * @param packet
     * @param reqTransId
     * @param rspTransId
     * @return
     */
    int OnHandleLogicLoginRsp(uint32_t msgId, const NFDataPackage& packet, uint32_t reqTransId, uint32_t rspTransId);

    /**
     * @brief 处理Sns登陆返回
     * @param msgId
     * @param packet
     * @param reqTransId
     * @param rspTransId
     * @return
     */
    int OnHandleSnsLoginRsp(uint32_t msgId, const NFDataPackage& packet, uint32_t reqTransId, uint32_t rspTransId);

    virtual int OnTransFinished(int iRunLogicRetCode);
private:
    uint64_t m_uid;
    uint64_t m_roleId;
    uint32_t m_proxyId;
    uint64_t m_clientId;

    bool m_loadLogic;
    bool m_loadSns;
DECLARE_IDCREATE(NFTransWorldEnterGame)
};