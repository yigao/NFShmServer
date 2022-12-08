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
private:
    uint64_t m_mapId;
    uint64_t m_sceneId;
    uint64_t m_gameBusId;
DECLARE_IDCREATE(NFTransEnterScene)
};