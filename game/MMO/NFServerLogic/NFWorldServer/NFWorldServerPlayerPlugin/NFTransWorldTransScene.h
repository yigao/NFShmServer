// -------------------------------------------------------------------------
//    @FileName         :    NFTransWorldTransScene.h
//    @Author           :    gaoyi
//    @Date             :    23-3-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransWorldTransScene
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFLogicCommon/NFPoint3.h"
#include "ServerInternal2.pb.h"

class NFTransWorldTransScene : public NFTransBase
{
public:
    NFTransWorldTransScene();

    virtual ~NFTransWorldTransScene();

    int CreateInit();

    int ResumeInit();
public:
    int Init(uint64_t roleId, uint64_t mapId, uint64_t sceneId, const NFPoint3<float>& pos, int reqTransId, uint32_t cmd);
    int OnHandleTransScene(const proto_ff::LogicToWorldEnterSceneReq& xData);
    int OnHandleLeaveScene(const proto_ff::LogicToWorldLeaveSceneReq& xData);
    virtual int OnTransFinished(int iRunLogicRetCode);
    virtual int HandleDispSvrRes(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId);
    int OnHandleGameEnterSceneRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId);
    int OnHandleGameLeaveSceneRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId);
private:
    uint64_t m_roleId;
    uint64_t m_mapId;
    uint64_t m_sceneId;
    uint32_t m_gameId;
    uint32_t m_logicId;
    NFPoint3<float> m_pos;
    uint32_t m_cmd;
    int m_reqTransId;
DECLARE_IDCREATE(NFTransWorldTransScene)
};