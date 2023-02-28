// -------------------------------------------------------------------------
//    @FileName         :    NFBattlePlayer.h
//    @Author           :    gaoyi
//    @Date             :    23-2-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFBattlePlayer
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFCreature.h"
#include "DBProto2.pb.h"

class NFBattlePlayer : public NFCreature
{
public:
    NFBattlePlayer();

    virtual ~NFBattlePlayer();

    int CreateInit();

    int ResumeInit();

public:
    int Init(const proto_ff::RoleEnterSceneData& data);
    //视野数据
    virtual void GetVisibleDataToClient(proto_ff::CreatureCreateData& CvData) { }
private:
DECLARE_IDCREATE(NFBattlePlayer)
};