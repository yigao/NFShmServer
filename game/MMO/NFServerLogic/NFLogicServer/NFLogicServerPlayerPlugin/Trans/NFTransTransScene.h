// -------------------------------------------------------------------------
//    @FileName         :    NFTransEnterScene.h
//    @Author           :    gaoyi
//    @Date             :    22-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransEnterScene
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Base/NFTransPlayerBase.h"
#include "Com_s.h"
#include "NFLogicCommon/NFPoint3.h"

class NFTransTransScene : public NFTransPlayerBase
{
public:
    NFTransTransScene();

    virtual ~NFTransTransScene();

    int CreateInit();

    int ResumeInit();
public:
    /**
     * @brief
     * @param pCSMsgReq
     * @return
     */
    virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);
    virtual int HandleDispSvrRes(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId);
    int OnHandleWorldEnterSceneRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId);
    int OnHandleWorldLeaveSceneRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId);
    int OnHandleGetMapInfoRsp(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId);
public:
    /**
     * @brief
     * @return
     */
    int InitStaticMapInfo(uint64_t mapId, uint64_t scenceId, const NFPoint3<float> &dstPos);

public:
    /**
     * @brief
     * @return
     */
    int SendEnterScene();

    /**
     * @brief
     * @return
     */
    int SendLeaveScene();

    /**
     * @brief
     * @param mapId
     * @param sceneId
     * @param pos
     * @return
     */
    int TransScene(uint64_t mapId, uint32_t transType, uint64_t dstId);

    int SendGetMapInfoReq();
public:
    /**
     * @brief
     * @param iRunLogicRetCode
     * @return
     */
    int HandleTransFinished(int iRunLogicRetCode);
private:
    uint64_t m_mapId;
    uint64_t m_sceneId;
    NFPoint3<float> m_pos;
    uint32_t m_transType;
    uint64_t m_transId;
DECLARE_IDCREATE(NFTransTransScene)
};