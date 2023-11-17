// -------------------------------------------------------------------------
//    @FileName         :    NFRoleSimple.h
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleSimple
//
// -------------------------------------------------------------------------

#pragma once

#include <NFLogicCommon/NFPlayerStatus.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "AllProtocol.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFCore/NFTime.h"
#include "DBProxy2_s.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFPlayerSimple : public NFShmObjTemplate<NFPlayerSimple, EOT_SNS_ROLE_SIMPLE_ID, NFShmObj>, public NFPlayerStatus
{
public:
    NFPlayerSimple();

    virtual ~NFPlayerSimple();

    int CreateInit();

    int ResumeInit();

public:
    //must be virtual
    virtual int OnTimer(int timeId, int callcount);
public:
    /**
     * \brief 处理继承NFPlayerStatus 负责玩家数据的生命周期管理
     */
    virtual uint64_t StatusId() const { return GetCid(); }

    virtual bool IsCanLogout();

    bool CanDelete();
public:
    uint64_t GetCid() const;

    void SetCid(uint64_t cid);

    uint64_t Cid() const;

    uint64_t GetUid() const;

    uint32_t GetZid() const;

    std::string GetName() const;

    //获取职业ID
    uint32_t Prof() const { return m_data.base.facade.prof; }
    //获取等级
    uint32_t Level() const { return m_data.base.level; }
    //设置等级
    void Level(uint32_t level) { m_data.base.level = level; }
    int64_t GetCurHp() { return m_data.base.hp; }
    void SetCurHp(int64_t hp) { m_data.base.hp = hp; }
    int64_t GetMaxHp() { return m_data.base.hp; }
    void SetMaxHp(int64_t maxhp) { m_data.base.hp = maxhp; }
    //获取战力
    uint64_t Fight() const { return m_data.base.fight; }
    //设置战力
    void Fight(uint64_t fight) { m_data.base.fight = fight; }
    //获取外观
    const proto_ff_s::RoleFacadeProto_s& Facade() const { return m_data.base.facade; }
    proto_ff::RoleFacadeProto FacadeToPB() const;
    //设置外观
    void Facade(const proto_ff_s::RoleFacadeProto_s& facade) { m_data.base.facade = facade; };
    //获取VIP等级
    uint32_t VipLevel() const { return m_data.base.vip_level; }
    //设置VIP等级
    void VipLevel(uint32_t viplevel) { m_data.base.vip_level = viplevel; }
    //获取地图ID
    uint64_t MapId() const { return m_data.base.enter_map_id; }
    //设置地图ID
    void MapId(uint64_t mapid) { m_data.base.enter_map_id = mapid; }
    //获取场景ID
    uint64_t SceneId() const { return m_data.base.enter_scene_id; }
    //设置场景ID
    void SceneId(uint64_t sceneid) { m_data.base.enter_scene_id = sceneid; }
    //填充玩家数据
    void FillPlayerProto(proto_ff::RolePlayerMiniInfo* proto) const;
    //获取修真
    uint32_t PtStage() const { return m_data.base.pt_stage; }
    //设置VIP等级
    void PtStage(uint32_t ptStage) { m_data.base.pt_stage = ptStage; }
public:
    const proto_ff_s::RoleDBSnsSimple_s& GetBaseData() const;

    void SetBaseData(const proto_ff_s::RoleDBSnsSimple_s& baseData);

    void ReadFromPB(const proto_ff::RoleDBSnsSimple& dbData);

    bool IsInited() const;

    void SetIsInited(bool isInited);

public:
    /**
     * @brief
     * @param dbData
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(const proto_ff::RoleDBSnsSimple& dbData);

    /**
     * @brief
     * @return
     */
    virtual int UnInit();

public:
    /**
     * @brief
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::RoleDBSnsSimple& data);

    /**
     * @brief
     * @return
     */
    virtual int InitConfig(const proto_ff::RoleDBSnsSimple& data);

public:
    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin();

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

public:
    ////////////////////////////////// 每日每周刷新接口 ///////////////////////////////////
    /**
     * @brief 每日刷新接口
     * @param unixSec
     * @return
     */
    virtual int DailyZeroUpdate() { return 0; }

    /**
     * @brief 每周刷新接口
     * @param unixSec
     * @return
     */
    virtual int WeekZeroUpdate() { return 0; }

    /**
     * @brief 每月刷新接口
     * @param unixSec
     * @return
     */
    virtual int MonthZeroUpdate() { return 0; }

public:
    uint32_t GetLogicId() const;

    void SetLogicId(uint32_t logicId);

    uint32_t GetGameId() const;

    void SetGameId(uint32_t gameId);

    uint32_t GetProxyId() const;

    void SetProxyId(uint32_t proxyId);

public:
    int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message& xData);

    int SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message& xData);
    int SendTransToLogicServer(uint32_t msgId, const google::protobuf::Message& xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message& xData);
    int SendTransToWorldServer(uint32_t msgId, const google::protobuf::Message& xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    int SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message& xData);
    int SendTransToGameServer(uint32_t msgId, const google::protobuf::Message& xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

private:
    /**
     * @brief
     */
    bool m_isInited;

public:
    proto_ff_s::RoleDBSnsSimple_s m_data;
private:
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
    uint32_t m_gameId;
};
