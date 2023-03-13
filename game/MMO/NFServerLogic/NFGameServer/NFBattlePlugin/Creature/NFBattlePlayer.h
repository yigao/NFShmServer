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
#include "NFLogicCommon/NFLogicCommonDefine.h"
#include "Move.pb.h"

class NFBattlePlayer : public NFCreature, public NFSeqOP
{
public:
    NFBattlePlayer();

    virtual ~NFBattlePlayer();

    int CreateInit();

    int ResumeInit();

public:
    virtual int Init(const proto_ff::RoleEnterSceneData &data);

    virtual int Init(uint32_t gateId, uint64_t clientId, uint32_t logicId, const proto_ff::RoleEnterSceneData &data);

    virtual int Update(uint64_t tick);

    virtual int ReadBaseData(const ::proto_ff::RoleDBBaseData &dbData);

    //视野数据
    virtual void GetVisibleDataToClient(proto_ff::CreatureCreateData &CvData);

    virtual int OnTimer(int timeId, int callcount);
public:
    int OnDisconnect();

    int OnLogout();
public:
    virtual uint64_t GetUid() { return m_uid; }

    virtual uint64_t GetRoleId() { return m_roleId; }

    virtual uint32_t GetChannId() { return m_channId; }

    virtual uint32_t GetZid() { return m_zid; }

    virtual uint32_t GetProxyId() { return m_proxyId; }

    virtual uint64_t GetClientId() { return m_clientId; }

    virtual uint32_t GetLogicId() { return m_logicId; }

    PLAYER_STATUS GetPlayerStatus() const { return m_playerStatus; }

    void SetPlayerStatus(PLAYER_STATUS status) { m_playerStatus = status; }

    /**
     * @brief
     * @return
     */
    uint64_t GetCreateTime() const;

    /**
     * @brief
     * @param createTime
     */
    void SetCreateTime(uint64_t createTime);

    /**
     * @brief
     * @return
     */
    uint64_t GetLastDiconnectTime() const;

    /**
     * @brief
     * @param lastDiconnectTime
     */
    void SetLastDiconnectTime(uint64_t lastDiconnectTime);

    /**
     * @brief
     * @return
     */
    uint64_t GetLastLogoutTime() const;

    /**
     * @brief
     * @param lastLogoutTime
     */
    void SetLastLogoutTime(uint64_t lastLogoutTime);

public:
    /**
     * @brief
     * @return
     */
    bool IsDisconnect() const;

    /**
     * @brief
     * @param isDisConnect
     */
    void SetIsDisconnect(bool isDisConnect);

public:
    /**
     * @brief 强制传送(场景内传送、切场景传送)
     * @param scenceId 目标场景ID（唯一ID，静态地图场景ID和地图ID相同）
     * @param dstPos 目标场景坐标
     * @param mapId 地图ID
     * @param transParam 传送参数
     * @return
     */
    virtual int TransScene(uint64_t scenceId, const NFPoint3<float> &dstPos, uint64_t mapId, STransParam &transParam);

    virtual int CanTrans(uint64_t dstSceneId, uint64_t dstMapId, const NFPoint3<float> &dstPos, NFPoint3<float> &outPos, STransParam &transParam, bool checkPosFlag = true);
public:
    //移动到目标坐标
    virtual int MoveTo(const NFPoint3<float>& dstPos);
    //停止当前移动
    virtual int StopMove();
    //瞬间移动
    virtual int Teleporting(const NFPoint3<float>& dstPos, int32_t type = proto_ff::MoveTeleportRsp_Type_common);
public:
    //进入战斗状态
    virtual bool EnterFightState();
    //离开战斗状态
    virtual bool LeaveFigthState();

    //取消打坐状态
    virtual bool EnterSeatState();
    virtual bool LeaveSeatState();
public:
    NFBattlePart *CreatePart(uint32_t partType, const ::proto_ff::RoleEnterSceneData &data);
    int RecylePart(NFBattlePart *pPart);
    //获取对应部件指针
    virtual NFBattlePart *GetPart(uint32_t partType);
public:
    //是否处于疲劳状态
    bool IsTired() { return false; }
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
    uint32_t m_proxyId;

    uint64_t m_clientId;

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
public:
    /**
     * @brief
     */
    PLAYER_STATUS m_playerStatus;

    /**
     * @brief
     */
    uint64_t m_createTime;

    /**
     * @brief
     */
    uint64_t m_lastDiconnectTime;

    /**
     * @brief
     */
    uint64_t m_lastLogoutTime;

    /**
     * @brief
     */
    bool m_isDisconnect;
public:
    int m_timerId_FightState;
public:
    NFShmVector<int, BATTLE_PART_MAX> m_pPart;
DECLARE_IDCREATE(NFBattlePlayer)
};