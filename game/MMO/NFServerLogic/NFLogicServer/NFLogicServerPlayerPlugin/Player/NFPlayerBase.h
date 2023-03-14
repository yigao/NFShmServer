// -------------------------------------------------------------------------
//    @FileName         :    NFPlayerBase.h
//    @Author           :    gaoyi
//    @Date             :    22-11-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFPlayerBase
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFCore/NFTime.h"
#include "DBProto.pb.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFRoleDefine.h"
#include "NFLogicCommon/NFLogDefine.h"
#include "NFLogicCommon/NFComTypeDefine.h"
#include "NFLogicCommon/NFLogicCommonDefine.h"
#include "NFPlayerBase.h"
#include "DBProto_s.h"
#include "NFLogicCommon/NFAttr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "DBProto2.pb.h"

class NFPlayerBase : public NFSeqOP
{
public:
    NFPlayerBase();

    virtual ~NFPlayerBase();

    int CreateInit();

    int ResumeInit();

public:
    int Init(NFIPluginManager* pPluginManager, const ::proto_ff::RoleDBData &dbData);

    int UnInit(NFIPluginManager* pPluginManager);

    //存储DB部件入口
    virtual int SaveDB(proto_ff::RoleDBData &dbData);

    virtual int ReadBaseData(const ::proto_ff::RoleDBData &dbData);
    virtual void SetBaseData(proto_ff::RoleDBData& proto);
    virtual void SetBaseData(proto_ff::RoleDBBaseData* proto);
    virtual void SetFacadeProto(proto_ff::RoleFacadeProto& outproto);
    virtual void SetEnterSceneProto(proto_ff::RoleEnterSceneData& outproto);
    virtual void SetAttrData(proto_ff::RoleDBData& proto);
public:
    /**
     * @brief 保存DB相关
     */

    /**
     * @brief
     * @return
     */
    virtual bool IsRoleDetailSaved() const;

    /**
     * @brief
     * @return
     */
    virtual uint32_t GetCurRoleDetailSeq() const;

    /**
     * @brief
     * @return
     */
    virtual bool IsRoleDetailNowSaving() const;

    /**
     * @brief
     * @param time
     */
    virtual void SetLastSendRoleDetailSavedTime(uint64_t time);

    /**
     * @brief
     * @param seq
     */
    virtual void SetRoleDetailSavedSeq(uint32_t seq);

    /**
     * @brief
     * @return
     */
    virtual bool IsRoleDetailNeedSave() const;

    virtual uint64_t GetRoleDetailSavingDBTime() const;

    virtual void SetRoleDetailSavingDBTime(uint64_t dwTime);

public:
    /**
     * @brief 当前玩家正在使用的trans数量 +1
     */
    virtual void IncreaseTransNum();

    /**
     * @brief 当前玩家正在使用的trans数量 -1
     */
    virtual void DecreaseTransNum();

    /**
     * @brief 当前玩家正在使用的trans数量
     * @return
     */
    virtual int GetTransNum() const;

    /**
     * @brief 角色ID
     * @return
     */
    virtual uint64_t GetRoleId() const;
    virtual uint64_t RoleId() const;

    /**
     * @brief
     * @param roleId
     */
    virtual void SetRoleId(uint64_t roleId);

    /**
     * @brief 玩家ID
     * @return
     */
    virtual uint64_t GetUid() const;

    /**
     * @brief
     * @param uid
     */
    virtual void SetUid(uint64_t uid);

    /**
     * @brief
     * @return
     */
    virtual std::string GetName() const;

    /**
     * @brief
     * @param name
     */
    virtual void SetName(const std::string& name);
public:
    /**
     * @brief
     * @return
     */
    virtual PLAYER_STATUS GetStatus() const;

    /**
     * @brief
     * @param status
     */
    virtual void SetStatus(PLAYER_STATUS status);

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

    virtual bool IsInTransSceneing();

    /**
     * @brief
     * @return
     */
    virtual bool IsDisconnect() const;

    /**
     * @brief
     * @param isDisConnect
     */
    virtual void SetIsDisconnect(bool isDisConnect);

    /**
     * @brief
     * @return
     */
    virtual uint64_t GetLastLogoutTime() const;

    /**
     * @brief
     * @param lastLogoutTime
     */
    virtual void SetLastLogoutTime(uint64_t lastLogoutTime);

    /**
     * @brief
     * @return
     */
    virtual uint64_t GetLastDiconnectTime() const;

    /**
     * @brief
     * @return
     */
    virtual uint64_t GetDisonnectType() const;

    /**
     * @brief
     * @param type
     */
    virtual void SetDisconnectType(uint32_t type);

    /**
     * @brief
     * @return
     */
    uint64_t GetZid() const;

    /**
     * @brief
     * @param zid
     */
    void SetZid(uint64_t zid);

    /**
     * @brief
     * @return
     */
    uint64_t GetChannelId() const;

    /**
     * @brief
     * @param channelId
     */
    void SetChannelId(uint64_t channelId);

    /**
     * @brief
     * @return
     */
    uint32_t GetProxyId() const;

    /**
     * @brief
     * @param proxyId
     */
    void SetProxyId(uint32_t proxyId);

    /**
     * @brief
     * @return
     */
    uint32_t GetClientId() const;

    /**
     * @brief
     * @param proxyId
     */
    void SetClientId(uint32_t clientId);

    uint32_t GetGameId() const;

    void SetGameId(uint32_t gameId);

    uint64_t GetMapId() const;
    uint64_t GetSceneId() const;
    NFPoint3<float> GetPos() const;
    void SetMapId(uint64_t mapId);
    void SetSceneId(uint64_t sceneId);
    void SetPos(const NFPoint3<float>& pos);

    uint64_t GetLastMapId() const;
    uint64_t GetLastSceneId() const;
    NFPoint3<float> GetLastPos() const;
    void SetLastMapId(uint64_t mapId);
    void SetLastSceneId(uint64_t sceneId);
    void SetLastPos(const NFPoint3<float>& pos);
public:
    bool BState(proto_ff::ECState state);
    uint8_t GetState();
    void SetState(proto_ff::ECState state);
protected:
    /**
     * @brief 玩家数据是否初始化
     */
    bool m_isInited;

    /**
     * @brief 当前玩家正在使用的trans数量
     */
    int m_transNum;
protected:
    /**
     * @brief 角色ID
     */
    uint64_t m_cid;

    /**
     * @brief 玩家ID
     */
    uint64_t m_uid;

    /**
     * @brief
     */
    uint64_t m_zid;

    /**
     * @brief
     */
    uint64_t m_channelId;

    /**
     * @brief
     */
    uint32_t m_proxyId;

    /**
     * @brief
     */
    uint64_t m_clientId;

    /**
     * @brief
     */
    uint32_t m_gameId;

    /**
     * @brief
     */
    uint32_t m_battleId;
protected:
    /**
     * @brief
     */
    PLAYER_STATUS m_status;

    /**
     * @brief
     */
    uint64_t m_curObjCreateTime;

    /**
     * @brief
     */
    uint64_t m_diconnectTime;

    /**
     * @brief
     */
    uint32_t m_disonnectType;

    /**
     * @brief
     */
    uint64_t m_logoutTime;


    /**
     * @brief
     */
    uint64_t m_loginTime;

    /**
     * @brief
     */
    uint64_t m_createTime;

    /**
     * @brief
     */
    bool m_isDisconnect;
protected:
    /**
     * @brief
     */
    uint32_t m_lastSendSaveRoleDetailTime;

    /**
     * @brief
     */
    uint32_t m_roleDetailSavedSeq;

    /**
     * @brief
     */
    uint32_t m_roleDetailSavingDBTime;
protected:
    int32_t  m_color;					//模型颜色
    proto_ff_s::RoleFacadeProto_s m_lastFacade;				//最近一次外观数据，用于和最新的外观比较
    NFShmString<64> m_name;
    uint64_t m_sceneId;      //场景id
    uint64_t m_mapId;       //地图模板id
    NFPoint3<float> m_pos; //当前生物坐标
    NFPoint3<float> m_lastPos;           //上个地图坐标
    uint64_t m_lastSceneId;             //上个场景ID
    uint64_t m_lastMapId;               //上个地图ID
    uint8_t m_curstate;
    uint8_t m_laststate;
    PLAYER_SCENE_STATE m_sceneState;
protected:
    NFShmPtr<IFightAttr> m_pFightAttr;		//战斗属性
    NFShmPtr<IAttr> m_pAttr;				//普通属性
    NFShmHashMap<uint32_t, int64_t, 10>  m_attrCache;			//需要同步单个客户端属性缓存
    NFShmHashMap<uint32_t, int64_t, 10>  m_attrBroadCache;		//需要广播属性缓存
};