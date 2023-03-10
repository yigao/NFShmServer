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

class NFTransEnterScene : public NFTransPlayerBase
{
public:
    NFTransEnterScene();

    virtual ~NFTransEnterScene();

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
public:
    /**
     * @brief
     * @return
     */
    int InitStaticMapInfo();

public:
    /**
     * @brief
     * @return
     */
    int SendEnterScene();

    /**
     * @brief
     * @param mapId
     * @param sceneId
     * @param pos
     * @return
     */
    int TransScene(uint64_t mapId, uint64_t sceneId, const NFPoint3<float>& pos);
private:
    uint64_t m_mapId;
    uint64_t m_sceneId;
    NFPoint3<float> m_pos;
DECLARE_IDCREATE(NFTransEnterScene)
};