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
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFCreature.h"
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "Com_s.h"
#include "Move.pb.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Player.pb.h"
#include "CommonClass.pb.h"
#include "NFLogicCommon/NFPlayerStatus.h"

class NFBattlePlayer : public NFShmObjTemplate<NFBattlePlayer, EOT_GAME_NFBattlePlayer_ID, NFCreature>, public NFSeqOP, public NFPlayerStatus
{
public:
    NFBattlePlayer();
    
    virtual ~NFBattlePlayer();
    
    int CreateInit();
    
    int ResumeInit();

public:
    virtual int Init();
    
    virtual int Init(const proto_ff::RoleEnterSceneData& data);
    
    virtual int Init(uint32_t proxyId, uint32_t logicId, uint32_t worldId, uint32_t snsId, const proto_ff::RoleEnterSceneData& data);
    
    virtual int Update(uint64_t tick);
    
    virtual int ReadBaseData(const ::proto_ff::RoleDBBaseData& dbData);
    
    virtual int ReadViewAttrData(const ::proto_ff::AttrDBData& dbData);
    
    //视野数据
    virtual void GetVisibleDataToClient(proto_ff::CreatureCreateData& CvData);
    
    virtual int OnTimer(int timeId, int callcount);
    
    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage);

public:
    int SyncFacade(const proto_ff::RoleFacadeProto* pEvent);
    
    int SyncAttr(const proto_ff::CreatureAttrSyn* pEvent);
    
    int SyncBroadAttr(const proto_ff::CreatureAttrBroadRsp* pEvent);

public:
    int OnDisconnect();
    
    int OnLogout();

public:
    virtual uint64_t GetUid() { return m_uid; }
    
    virtual uint64_t GetRoleId() { return m_cid; }
    
    virtual uint32_t GetChannId() { return m_channId; }
    
    virtual uint32_t GetZid() { return m_zid; }
    
    virtual uint32_t GetProxyId() { return m_proxyId; }
    
    virtual uint32_t GetLogicId() { return m_logicId; }
public:
    virtual uint64_t StatusId() const { return Cid(); }
    
    virtual bool IsCanLogout() { return true; }
    
    virtual int DoOnline() { return 0; }
    
    virtual bool IsCanDead() { return true; }
    
    virtual int DoLogout() { return 0; }
public:
    /**
     * @brief 强制传送(场景内传送、切场景传送)
     * @param scenceId 目标场景ID（唯一ID，静态地图场景ID和地图ID相同）
     * @param dstPos 目标场景坐标
     * @param mapId 地图ID
     * @param transParam 传送参数
     * @return
     */
    virtual int TransScene(uint64_t scenceId, const NFPoint3<float>& dstPos, uint64_t mapId, const proto_ff::SceneTransParam& transParam);
    
    /**
     * @brief 是否可以传送
     * @param dstSceneId
     * @param dstMapId
     * @param dstPos
     * @param outPos
     * @param transParam
     * @param checkPosFlag
     * @return
     */
    virtual int CanTrans(uint64_t dstSceneId, uint64_t dstMapId, const NFPoint3<float>& dstPos, NFPoint3<float>& outPos, const proto_ff::SceneTransParam& transParam, bool checkPosFlag = true);

public:
    //移动到目标坐标
    virtual int MoveTo(const NFPoint3<float>& dstPos);
    
    //停止当前移动
    virtual int StopMove();
    
    //瞬间移动
    virtual int Teleporting(const NFPoint3<float>& dstPos, int32_t type = proto_ff::MoveTeleportRsp_Type_common);
    
    //切换逻辑节点
    virtual int ChangeLogic(uint64_t dstSceneId, uint64_t dstMapId, const NFPoint3<float>& dstPos, proto_ff::CreatureTransParam& creatureParam);
    
    //切换逻辑节点失败
    virtual int ChangeLogicFail();
    
    //切换场景成功(同一逻辑服内切换，不同逻辑服之间切换)
    virtual void OnTransSceneSuccess(const proto_ff::SceneTransParam& param);
public:
    //设置帐号状态
    bool SetAccountState(AccountGameState state);
    virtual AccountGameState GetAccountState() { return m_accountState; }
public:
    //进入战斗状态
    virtual bool EnterFightState();
    
    //离开战斗状态
    virtual bool LeaveFigthState();
    
    //取消打坐状态
    virtual bool EnterSeatState();
    
    virtual bool LeaveSeatState();
    
    //状态改变
    virtual void OnChangeState(uint8_t curstate, uint8_t laststate);
public:
    NFBattlePart* CreatePart(uint32_t partType, const ::proto_ff::RoleEnterSceneData& data);
    
    int RecylePart(NFBattlePart* pPart);
    
    //获取对应部件指针
    virtual NFBattlePart* GetPart(uint32_t partType);

public:
    //是否处于疲劳状态
    bool IsTired() { return false; }
    //是否处于PVP状态
    virtual bool IsPVPState() { return m_pvpstate; }
private:
    bool m_pvpstate = false;            //是否处于PVP状态
    AccountGameState	m_accountState = ACCOUNT_GAME_STATE_NULL;		// 此账号在游戏中的状态
private:
    /**
     * @brief
     */
    uint64_t m_uid;
    
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
    int m_timerId_FightState;
public:
    NFShmVector<int, BATTLE_PART_MAX> m_pPart;
};