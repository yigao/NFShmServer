// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayer.h
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayer.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFCore/NFTime.h"
#include "ComDefine.pb.h"
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "Trans/NFTransSaveDB.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "AllProtocol.h"
#include "NFLogicCommon/NFLogicCommon.h"
#include "NFLogicCommon/NFCharactorDefine.h"
#include "DBProxy_s.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Player.pb.h"
#include "NFGameCommon/NFComTypeDefine.h"
#include "NFLogicCommon/NFLogDefine.h"
#include "NFLogicCommon/NFAttr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"

class NFPart;

class NFPlayer : public NFShmObjTemplate<NFPlayer, EOT_LOGIC_PLAYER_ID, NFShmObj>, public NFSeqOP
{
public:
    NFPlayer();
    
    virtual ~NFPlayer();
    
    int CreateInit();
    
    int ResumeInit();
    
    void Tick();
    
    virtual int OnTimer(int timeId, int callcount);

public:
    virtual int Init(const proto_ff::RoleDBData &data);
    
    virtual int UnInit();
    
    /**
     * @brief
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::RoleDBData &data);
    
    /**
     * @brief
     * @param data
     * @return
     */
    virtual int InitConfig(const proto_ff::RoleDBData &data);
    
    /**
     * @brief
     * @param data
     * @return
     */
    virtual int SaveDB(proto_ff::RoleDBData &data);
    
    /**
     * @brief
     * @return
     */
    virtual int Update();
    
    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin();
    
    virtual int OnLogin(proto_ff::PlayerInfoRsp &playerInfo);
    
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
    
    /**
     * 设置外观信息
     * @param outproto
     */
    virtual void SetFacadeProto(proto_ff::RoleFacadeProto &outproto);
    
    /**
     * 设置头像信息
     * @param outproto
     */
    virtual void SetHeadProto(proto_ff::RoleHeadPicProto &outproto);
public:
    //读取基础数据
    bool ReadBaseData(const proto_ff::RoleDBData &proto);
    void SetBaseData(proto_ff::RoleDBData &proto);
    void SetBaseData(proto_ff::RoleDBBaseData *protobase);
    void SetAttrData(proto_ff::RoleDBData &proto);
    void SetEnterSceneProto(proto_ff::RoleEnterSceneData& outproto);
public:
    //状态
    bool BState(proto_ff::ECState state);
    proto_ff::ECState GetState();
    void SetState(proto_ff::ECState state);
public:
    //同步外观
    virtual void SyncFacade();
    //设置是否需要计算战力
    virtual void SetCalcFight(bool calc) { m_calcfight = calc; }
    //计算战力
    virtual void CalcFight(bool sync);
    //设置是否需要计算宠物系统的战力
    virtual void SetCalcPetFight(bool calc) { m_petFight = calc; }
    //计算宠物系统的战斗力
    virtual void CalcPetFight(bool sync);
    //计算世界等级经验加成
    void CalcWorldLvExpAdd();
public:
    //////////////////////////////////////////////////////////////////////////
    //增加属性 主要是为了增加虚拟物品相关的属性 costFlag:是否是扣除属性
    virtual void AddVirAttr(MAP_UINT32_INT64 &mapAttr, bool costFlag = false, SCommonSource *pSource = nullptr, bool syn = false);
    
    //属性是否足够，主要是为了属性虚拟物品的判断
    virtual bool EnoughVirAttr(MAP_UINT32_INT64 &mapAttr);
    
    //增加属性
    virtual bool AddAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr, bool syn = false);
    
    //增加属性 不同步到客户端
    virtual bool AddAttrCache(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr);
    
    //能否增加属性
    virtual bool CanAddAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr);
    
    //增加属性处理
    virtual void OnAddAttr(uint32_t ANum, int64_t oldVal, int64_t attrValue, int64_t newVal, SCommonSource *pSource = nullptr);
    
    //设置属性
    virtual bool SetAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr, bool syn = false);
    
    //设置属性 不同步客户端
    virtual bool SetAttrCache(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr);
    
    //能否设置属性
    virtual bool CanSetAttr(uint32_t ANum, int64_t attrValue, SCommonSource *pSource = nullptr);
    
    //设置属性处理
    virtual void OnSetAttr(uint32_t ANum, int64_t oldVal, int64_t attrValue, int64_t newVal, SCommonSource *pSource = nullptr);
    
    //获取该组属性值
    virtual int64_t GetAttrGroup(uint32_t attrGroup, uint32_t ANum);
    
    //获取该组所有属性值
    virtual void GetAttrGroup(uint32_t attrGroup, MAP_UINT32_INT64 &mapattr);
    
    //清除某一组属性
    virtual bool ClearAttrGroup(uint32_t attrGroup, SCommonSource *pSource = nullptr, bool syn = false);
    
    virtual bool ClearAttrGroupCache(uint32_t attrGroup, SCommonSource *pSource = nullptr);
    
    //增加属性组属性
    virtual bool AddAttrGroup(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource = nullptr, bool syn = false);
    
    virtual bool AddAttrGroupCache(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource = nullptr);
    
    //设置属性组属性
    virtual bool SetAttrGroup(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource = nullptr, bool syn = false);
    
    virtual bool SetAttrGroupCache(uint32_t attrGroup, uint32_t ANum, int64_t val, SCommonSource *pSource = nullptr);
    
    //设置属性组所有属性
    virtual bool SetAttrGroup(uint32_t attrGroup, const MAP_UINT32_INT64 &mapattr, SCommonSource *pSource = nullptr, bool syn = false);
    
    virtual bool SetAttrGroupCache(uint32_t attrGroup, const MAP_UINT32_INT64 &mapattr, SCommonSource *pSource = nullptr);
    
    //计算属性
    virtual void CalcAttr(uint32_t ANum);
    
    //计算属性组属性 主要是把属性组中的属性汇总到总属性中 ANum:属性组中的属性ID
    virtual void CalcAttrGroup(uint32_t attrgroup, uint32_t ANum, MAP_UINT32_INT64 &mapchg);
    
    //获取属性值
    virtual int64_t GetAttr(uint32_t ANum);
    
    //获取所有属性组属性之和
    virtual void GetAttrGroupTotal(MAP_UINT32_INT64 &mapattr);
    
    //属性改变
    virtual void OnAttrChange(int32_t ANum, int64_t oldVal, int64_t newVal, SCommonSource *pSource = nullptr);
    
    //同步属性
    virtual void SynAttrToClient();
public:
    //检查经验值
    void CheckExp(int64_t oldexp, SCommonSource *pSource);
    
    //是否是需要保存的属性
    bool IsNeeSaveAttr(uint32_t ANum);
    
    //同步属性到中心服
    void SynAttrToSns(const proto_ff::CenterRoleProto &proto);
public:
    /**
     * 登陆前的处理
     * @return
     */
    int OnPrevLogin();
    
    /**
     * 同步角色数据给客户端
     * @return
     */
    int NotifyPlayerInfo();

public:
    /**
     * 登陆sns
     * @return
     */
    int LoginSns();
    
    /**
     * 进入游戏
     * @return
     */
    int EnterGame();

public:
    /**
     * 进入场景
     * @param mapId
     * @param sceneId
     * @param dstPos
     * @return
     */
    int EnterScene(uint64_t mapId, uint64_t sceneId, const NFPoint3<float> &dstPos);
public:
    uint64_t GetCid() const { return m_cid; }
    
    uint64_t Cid() const { return m_cid; }
    
    void SetCid(uint64_t cid) { m_cid = cid; }
    
    uint64_t GetUid() const { return m_uid; }
    
    void SetUid(uint64_t uid) { m_uid = uid; }
    
    uint32_t GetZid() const { return m_zid; }
    
    void SetZid(uint32_t zid) { m_zid = zid; }
    
    std::string GetName() const { return m_name.data(); }
public:
    proto_ff::enPlayerStatus GetStatus() const { return m_iStatus; }
    
    void SetStatus(proto_ff::enPlayerStatus status) { m_iStatus = status; }
    
    uint64_t GetLastDisconnectTime() const { return m_lastDiconnectTime; }
    
    void SetLastDisconnectTime(uint64_t distime) { m_lastDiconnectTime = distime; }
    
    uint64_t GetLastLogoutTime() const { return m_lastLogoutTime; }
    
    void SetLastLogtouTime(uint64_t logoutTime) { m_lastLogoutTime = logoutTime; }

public:
    uint32_t GetProxyId() const { return m_proxyId; }
    
    void SetProxyId(uint32_t proxyId) { m_proxyId = proxyId; }
    
    uint32_t GetGameId() const { return m_gameId; }
    
    void SetGameId(uint32_t gameId) { m_gameId = gameId; }
    
    uint32_t GetWorldId() const { return m_worldId; }
    
    void SetWorldId(uint32_t worldId) { m_worldId = worldId; }
    
    uint32_t GetSnsId() const { return m_snsId; }
    
    void SetSnsId(uint32_t snsId) { m_snsId = snsId; }

public:
    /**
     * @brief
     * @return
     */
    virtual PLAYER_SCENE_STATE GetSceneStatus() const;
    
    /**
     * @brief
     * @param status
     */
    virtual void SetSceneStatus(PLAYER_SCENE_STATE status);
    
    /**
     * @brief
     * @return
     */
    virtual bool IsInBattle();
    
    /**
     *
     * @return
     */
    virtual bool IsInTransSceneing();
public:
    /**
     * @brief trans num
     */
    void IncreaseTransNum();
    
    void DecreaseTransNum();

public:
    /**
     * @brief save db
     * @return
     */
    uint64_t GetLastSaveDBTime() const { return m_lastSavingDBTime; }
    
    void SetLastSaveDBTime(uint64_t saveTime) { m_lastSavingDBTime = saveTime; }
    
    bool IsInSaving() { return m_lastSavingDBTime > 0 && m_lastSavingDBTime + TRANS_ACTIVE_TIMEOUT + 5 >= (uint64_t) NFTime::Now().UnixSec(); }
    
    bool IsNeedSave();
    
    /**
     * @brief
     * @param iReason
     * @return
     */
    int SendTransToDB(TRANS_SAVEROLEDETAIL_REASON iReason = TRANS_SAVEROLEDETAIL_NORMAL);
    
    /**
     * @brief
     * @param iReason
     * @param bForce
     * @return
     */
    int SaveToDB(TRANS_SAVEROLEDETAIL_REASON iReason = TRANS_SAVEROLEDETAIL_NORMAL, bool bForce = false);
    
    /**
     * @brief
     * @param success
     * @param seq
     * @return
     */
    int OnSaveDB(bool success, uint32_t seq);
    
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
     * @brief
     * @param nMsgId
     * @param errCode
     * @return
     */
    int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData);
    
    int SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    
    int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    
    int SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    
    /**
     * @brief 在协程里获取远程服务器的rpc服务, 这个程序必须在协程里调用，需要先创建协程
     * @return 如果你在player或part的函数里，请优先调用这个函数，而不是调用FindModule<NFIMessageModule>()->GetRpcService系统函数， 因为玩家的生命周期是不确定的
     */
    template<size_t msgId, typename RequestType, typename ResponeType>
    int GetRpcService(NF_SERVER_TYPES dstServerType, uint32_t dstBusId, const RequestType &request, ResponeType &respone)
    {
        FindModule<NFICoroutineModule>()->AddUserCo(m_cid);
        int iRet = FindModule<NFIMessageModule>()->GetRpcService<msgId>(NF_ST_LOGIC_SERVER, dstServerType, dstBusId, request, respone, m_cid);
        FindModule<NFICoroutineModule>()->DelUserCo(m_cid);
        return iRet;
    }
    
    int64_t MakeCoroutine(const std::function<void()> &func)
    {
        FindModule<NFICoroutineModule>()->AddUserCo(m_cid);
        int64_t rpcId = FindModule<NFICoroutineModule>()->MakeCoroutine(func);
        FindModule<NFICoroutineModule>()->DelUserCo(m_cid);
        return rpcId;
    }

public:
    template<typename PART>
    PART *GetPart(uint32_t partType)
    {
        return dynamic_cast<PART *>(GetPart(partType));
    }
    
    template<typename PART>
    const PART *GetPart(uint32_t partType) const
    {
        return dynamic_cast<const PART *>(GetPart(partType));
    }
    
    NFPart *GetPart(uint32_t partType);
    
    const NFPart *GetPart(uint32_t partType) const;
    
    /**
     * @brief 创建Part
     * @param partType
     * @param dbData
     * @return
     */
    NFPart *CreatePart(uint32_t partType, const ::proto_ff::RoleDBData &dbData);
    
    /**
     * @brief 创建Part
     * @param partType
     * @return
     */
    NFPart *CreatePart(uint32_t partType);
    
    /**
     * @brief 释放Part
     * @param pPart
     * @return
     */
    int RecylePart(NFPart *pPart);

private:
    uint64_t m_cid;
    uint64_t m_uid;
    uint32_t m_zid;
    proto_ff::ECState m_state;                    //状态
    PLAYER_SCENE_STATE m_sceneState;
private:
    /**
     * 玩家场景数据
     */
    NFPoint3<float> m_pos;                   //当前生物坐标
    uint64_t m_sceneId;                //场景id
    uint64_t m_mapId;                  //地图模板id
    NFPoint3<float> m_lastPos;                //上个地图坐标
    uint64_t m_lastSceneId;             //上个场景ID
    uint64_t m_lastMapId;               //上个地图ID
public:
    bool m_calcfight;        //是否需要计算战力
    int64_t m_petFight;      //宠物系统的战斗力(只是缓存在玩家身上)
    bool m_calcpetfight;     //是否需要计算宠物系统的战斗力
private:
    NFShmPtr<IFightAttr> m_pFightAttr;        //战斗属性
    NFShmPtr<IAttr> m_pAttr;                //普通属性
    NFShmHashMap<uint32_t, int64_t, 100> m_attrCache;            //需要同步单个客户端属性缓存
    NFShmHashMap<uint32_t, int64_t, 100> m_attrBroadCache;        //需要广播属性缓存
private:
    /**
     * 玩家基础数据
     */
    NFCommonStr m_name;                        // 游戏内的角色名字
    int32_t m_color;                    //模型颜色
    uint64_t m_createTime;                    //创建时间（UTC时间）
    uint64_t m_createZeroTime;                //创角那一天的0点时间(UTC时间）
    uint64_t m_loginTime;                    //上一次登陆的时间（UTC时间）
    uint64_t m_logoutTime;                //上一次下线时间（UTC时间）
    uint32_t m_totalLoginDay;                //总登录天数
    uint64_t m_loginDayTime;                //总登录天数变更时间
    
    proto_ff_s::RoleFacadeProto_s m_lastfacade;                //最近一次外观数据，用于和最新的外观比较
    proto_ff_s::RoleReliveProto_s m_relive;                //复活信息
    uint32_t m_dayPrestige;            //今日获得的声望
    uint64_t m_resetPrestige;        //今日获得声望重置时间
    uint64_t m_lastHpTick;                //上一次同步HP的时间
    int32_t m_memCount;                    //队伍成员数量(有队伍才有效，用于计算队伍经验加成)
    NFCommonStr m_factionName;                //帮派名字
    int8_t m_headFlag;                //玩家头顶显示掉落归属标记
    NFShmString<1024> m_strGuidelines;        //新手指引信息
    int8_t m_subpackType;            //分包类型 1 小包，2 大包
    int8_t m_subpackFetch;            //是否领取分包奖励 0 未领取，1 已领取
private:
    uint32_t m_gameId;
    uint32_t m_proxyId;
    uint32_t m_snsId;
    uint32_t m_worldId;
private:
    NFShmVector<NFShmPtr<NFPart>, PART_MAX> m_pPart;
private:
    proto_ff::enPlayerStatus m_iStatus;
    uint64_t m_lastCreateTime;
    uint64_t m_lastDiconnectTime;
    uint64_t m_lastLogoutTime;
private:
    int m_iTransNum;
    uint64_t m_lastSavingDBTime;
    int m_saveDBTimer;
};
