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
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "Com_s.h"

class NFBattlePlayer : public NFCreature, public NFSeqOP
{
public:
    NFBattlePlayer();

    virtual ~NFBattlePlayer();

    int CreateInit();

    int ResumeInit();

public:
    int Init(uint32_t gateId, uint32_t logicId, const proto_ff::RoleEnterSceneData &data);

    virtual int ReadBaseData(const ::proto_ff::RoleDBBaseData &dbData);

    //视野数据
    virtual void GetVisibleDataToClient(proto_ff::CreatureCreateData &CvData);

public:
    virtual uint64_t GetUid() { return 0; }

    virtual uint64_t GetRoleId() { return 0; }

    virtual uint32_t GetChannId() { return 0; }

    virtual uint64_t GetClientId() { return 0; }

    virtual uint32_t GetZid() { return 0; }

    virtual uint32_t GetGateId() { return 0; }

private:
    /**
     * @brief 玩家数据是否初始化
     */
    bool m_isInited;

    /**
     * @brief
     */
    uint64_t m_uid;

    /**
     * @brief
     */
    uint64_t m_roleId;

    /**
     * @brief
     */
    NFShmString<64> m_name;

    /**
     * @brief
     */
    uint32_t m_channId;

    /*
     *
     */
    uint32_t m_zid;

    /**
     * @brief
     */
    uint32_t m_gateId;

    /**
     * @brief
     */
    uint32_t m_logicId;

    /**
     * @brief
     */
    proto_ff_s::RoleFacadeProto_s m_facade;

    /**
     * @brief 玩家头顶显示掉落归属标记
     */
    int8_t m_headFlag;

DECLARE_IDCREATE(NFBattlePlayer)
};