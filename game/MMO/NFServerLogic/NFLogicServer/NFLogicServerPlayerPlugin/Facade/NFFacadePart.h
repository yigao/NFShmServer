// -------------------------------------------------------------------------
//    @FileName         :    NFFacadePart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFFacadePart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFRawShmObj.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "DescStore/FacadeSoulDesc.h"
#include "DescStore/FacadeSoulachievementDesc.h"
#include "ClientServer.pb.h"
#include "DescStore/FacadeValueDesc.h"
#include "DescStore/FacadeChangeDesc.h"
#include "DescStore/FacadeFragmentDesc.h"
#include "DescStore/FacadeSoullvDesc.h"

#define MAX_FACADE_INFO_SKILL_NUM 10

enum FACADE_SOUL_ACTIVITY_TYPE
{
    FACADE_SOUL_ACTIVITY_TYPE_LEVEL = 1,
    FACADE_SOUL_ACTIVITY_TYPE_FANTASY = 2,
};

enum FACADE_SOUL_SKILL_ACTIVE_TYPE
{
    FACADE_SOUL_SKILL_ACTIVE_TYPE_ACTIVE_WING = 1,
    FACADE_SOUL_SKILL_ACTIVE_TYPE_ACTIVE_TREASURE = 2,
    FACADE_SOUL_SKILL_ACTIVE_TYPE_ACTIVE_PARTNER = 3,
    FACADE_SOUL_SKILL_ACTIVE_TYPE_WING_SOUL_LEVEL = 4,
    FACADE_SOUL_SKILL_ACTIVE_TYPE_TREASURE_SOUL_LEVEL = 5,
    FACADE_SOUL_SKILL_ACTIVE_TYPE_PARTNER_SOUL_LEVEL = 6,
};

class FacadeSoulInfo
{
public:
    FacadeSoulInfo()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }
    
    virtual ~FacadeSoulInfo()
    {
    
    }
    
    int CreateInit()
    {
        m_bSoulActive = false;
        m_soulLevel = 0;
        m_soulId = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    uint32_t GetSkillStatus(int64_t skillId) const
    {
        auto iter = m_soulSkillInfo.find(skillId);
        if (iter != m_soulSkillInfo.end())
        {
            return iter->second;
        }
        return 0;
    }
    
    void SetSkillStatus(int64_t skillId, uint32_t status)
    {
        auto iter = m_soulSkillInfo.find(skillId);
        if (iter != m_soulSkillInfo.end())
        {
            iter->second = status;
        }
    }
    
    bool IsSkillExist(int64_t skillId) const
    {
        auto iter = m_soulSkillInfo.find(skillId);
        if (iter != m_soulSkillInfo.end())
        {
            return true;
        }
        return false;
    }
    
    uint32_t GetActivityStatus(int64_t activityId) const
    {
        auto iter = m_soulActivityInfo.find(activityId);
        if (iter != m_soulActivityInfo.end())
        {
            return iter->second;
        }
        return 0;
    }
    
    void SetActivityStatus(int64_t activityId, uint32_t status)
    {
        auto iter = m_soulActivityInfo.find(activityId);
        if (iter != m_soulActivityInfo.end())
        {
            iter->second = status;
        }
    }
    
    bool IsActivityExist(int64_t activityId) const
    {
        auto iter = m_soulActivityInfo.find(activityId);
        if (iter != m_soulActivityInfo.end())
        {
            return true;
        }
        return false;
    }
    
    void InitData()
    {
        m_soulId = 0;
        m_bSoulActive = false;
        m_soulLevel = 0;
        m_soulSkillInfo.clear();
    }
    
    void ActiveSoul()
    {
        m_bSoulActive = true;
        m_soulLevel = 1;
    }
    
    void BuySoul(uint32_t soulId)
    {
        InitData();
        m_soulId = soulId;
        auto pCfgInfo = FacadeSoulDesc::Instance()->GetDesc(soulId);
        if (pCfgInfo)
        {
            if (pCfgInfo->m_mainSkill > 0)
            {
                m_soulSkillInfo[pCfgInfo->m_mainSkill] = proto_ff::FACADE_SOUL_SKILL_STATUS_NONE;
            }
            
            for (int i = 0; i < (int) pCfgInfo->m_minorSkill.size(); i++)
            {
                if (pCfgInfo->m_minorSkill[i] > 0)
                {
                    m_soulSkillInfo[pCfgInfo->m_minorSkill[i]] = proto_ff::FACADE_SOUL_SKILL_STATUS_NONE;
                }
            }
        }
        
        auto pCfgMap = FacadeSoulachievementDesc::Instance()->GetResDescPtr();
        if (pCfgMap)
        {
            for (auto iter = pCfgMap->begin(); iter != pCfgMap->end(); iter++)
            {
                if (iter->second.m_soulID == (int32_t) soulId)
                {
                    m_soulActivityInfo[iter->first] = proto_ff::FACADE_SOUL_ACTIVITY_STATUS_NONE;
                }
            }
        }
    }
    
    void LoadFromDB(const proto_ff::FacadeSoulData &dbInfo)
    {
        m_soulId = dbInfo.soul_id();
        m_bSoulActive = dbInfo.soul_active();
        m_soulLevel = dbInfo.soul_level();
        for (int i = 0; i < (int) dbInfo.skill_data_size(); i++)
        {
            m_soulSkillInfo[dbInfo.skill_data(i).skill_id()] = dbInfo.skill_data(i).status();
        }
        
        for (int i = 0; i < (int) dbInfo.acviity_data_size(); i++)
        {
            m_soulActivityInfo[dbInfo.acviity_data(i).activity_id()] = dbInfo.acviity_data(i).status();
        }
        
        //往后兼容
        auto pCfgMap = FacadeSoulachievementDesc::Instance()->GetResDescPtr();
        if (pCfgMap)
        {
            for (auto iter = pCfgMap->begin(); iter != pCfgMap->end(); iter++)
            {
                if (iter->second.m_soulID == (int32_t) m_soulId)
                {
                    if (m_soulActivityInfo.find(iter->first) == m_soulActivityInfo.end())
                    {
                        m_soulActivityInfo[iter->first] = proto_ff::FACADE_SOUL_ACTIVITY_STATUS_NONE;
                    }
                }
            }
        }
    }
    
    void SaveToDB(proto_ff::FacadeSoulData *pInfo)
    {
        WriteToProto(pInfo);
    }
    
    void WriteToProto(proto_ff::FacadeSoulData *pInfo)
    {
        pInfo->set_soul_id(m_soulId);
        pInfo->set_soul_active(m_bSoulActive);
        pInfo->set_soul_level(m_soulLevel);
        for (auto iter = m_soulSkillInfo.begin(); iter != m_soulSkillInfo.end(); iter++)
        {
            auto pSkillInfo = pInfo->add_skill_data();
            if (pSkillInfo)
            {
                pSkillInfo->set_skill_id(iter->first);
                pSkillInfo->set_status(iter->second);
            }
        }
        
        for (auto iter = m_soulActivityInfo.begin(); iter != m_soulActivityInfo.end(); iter++)
        {
            auto pActivityInfo = pInfo->add_acviity_data();
            if (pActivityInfo)
            {
                pActivityInfo->set_activity_id(iter->first);
                pActivityInfo->set_status(iter->second);
            }
        }
    }

public:
    uint32_t m_soulId;
    bool m_bSoulActive;
    uint32_t m_soulLevel;
    NFShmHashMap<int64_t, uint32_t, DEFINE_E_FACADESOUL_M_MINORSKILL_MAX_NUM + 1> m_soulSkillInfo;
    NFShmHashMap<int64_t, uint32_t, MAX_INDEX_FACADE_SOULACHIEVEMENT_SOULID_NUM> m_soulActivityInfo;
};

class NFFacadePart;

class FacadeInfo : public NFRawShmObj
{
public:
    FacadeInfo()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }
    
    ~FacadeInfo()
    {
    
    }
    
    int CreateInit()
    {
        m_facadeType = 0;
        m_nEquipFantasyID = 0;
        m_nFacadeID = 0;
        m_nFacadeLev = 0;
        m_nFacadeExp = 0;
        m_bUseSoulItem = false;
        m_bUseFacade = false;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    bool IsSpecAttr(int32_t spec_attrid)          //是否是系统特殊属性ID
    {
        switch (spec_attrid)
        {
            case proto_ff::A_WING_ALL_ADD:
            case proto_ff::A_MAG_WEAPON_ALL_ADD:
            case proto_ff::A_ARTIFACT_ALL_ADD:
            case proto_ff::A_SWORD_ALL_ADD:return true;
        }
        
        return false;
    }

public:
    bool Init(NFFacadePart *pPart, const proto_ff::RoleDBData &dbData);
    bool SaveDB(proto_ff::RoleDBData &characterDB);
public:
    void LoadFromDB(const proto_ff::FacadeDataInfo &dbInfo);
    void SaveToDB(proto_ff::FacadeDataInfo *pInfo);
public:
    /**
     * @brief 填充外观数据
     * @param facadeProto
     */
    void GetFacade(proto_ff::RoleFacadeProto &facadeProto);
    
    /**
     * @brief
     * @param rsp
     */
    void GetFacadeInfo(proto_ff::FacadeInfoRsp &rsp);
    
    /**
     * @brief
     * @param rsp
     */
    void GetFacadeFantasyInfo(proto_ff::FacadeFantasyInfoRsp &rsp);
    
    int GetSkillLev(int64_t skillId);
    void SetSkillInfo(int64_t skillId, uint32_t lev);
    int GetFacadeFantasyQualityNum(int quality);
public:
    /**
     * @brief 初始化最初的数据
     */
    void ActiveDefaultFacade(bool bSync);
    const proto_ff_s::E_FacadeDisplay_s *GetDefaultFacadeDisplay();
    const proto_ff_s::E_FacadeDisplay_s *GetCurFacadeDisplay();
    bool ProcessFantasyLevel(int64_t fantasyId, int32_t level);
    int64_t GetFightValue();
    const proto_ff_s::E_FacadeStarup_s *GetFacadeStarInfo(int64_t attrId, int32_t startId);
    int32_t GetFantasyTotalLv();
    bool ProcessSoulActivity(int32_t type, int32_t param);
    bool ProcessSoulSkill();
public:
    void calcAdvanceAttr(MAP_INT32_INT64 &outAttr);
    void calcFantasyAttr(MAP_INT32_INT64 &outAttr);
    void calcFantasyAttr(int64_t fantasyId, int32_t level, MAP_INT32_INT64 &outAttr);
    void calcFragmentAttr(MAP_INT32_INT64 &outAttr);
    void calcFragmentAttr(int64_t fragmentId, int32_t nTimes, MAP_INT32_INT64 &outAttr);
    void calcSoulAttr(int64_t soulId, int32_t level, MAP_INT32_INT64 &outAttr);
    void calcAttr(MAP_INT32_INT64& allAttr);
    void MergeAttr(const MAP_INT32_INT64 &src, MAP_INT32_INT64 &dst);
    void PrintAttr(const MAP_INT32_INT64 &attr);
    void OnCalc();
public:
    NFFacadePart *GetFacadePart();
    NFPlayer *GetMaster();
public:
    uint32_t m_facadeType;
    int64_t m_nFacadeID;            //ID
    int32_t m_nFacadeLev;            //
    int64_t m_nFacadeExp;            //进阶宝具经验
    bool m_bUseSoulItem;         //器魂道具是否使用
    FacadeSoulInfo m_soulInfo;      //器魂
    bool m_bUseFacade;           //是否使用外观幻化
    
    int64_t m_nEquipFantasyID;            //装备的宝具ID: 进阶宝具和幻化宝具同时只能装备一个
    NFShmHashMap<int64_t, int32_t, MAX_INDEX_FACADE_CHANGE_TYPE_NUM> m_mapFantasyFacade;    //当前拥有的幻化宝具
    NFShmHashMap<int64_t, int32_t, DEFINE_E_FACADEDISPLAY_M_FRAGMENTID_MAX_NUM> m_mapFragment;        //法灵数据
    NFShmHashMap<int64_t, int32_t, MAX_FACADE_INFO_SKILL_NUM> m_mapSkill;        //技能数据
};

class NFFacadePart : public NFShmObjTemplate<NFFacadePart, EOT_LOGIC_PART_ID + PART_FACADE, NFPart>
{
public:
    NFFacadePart();
    
    virtual ~NFFacadePart();
    
    int CreateInit();
    
    int ResumeInit();
public:
public:
    //******************part调用接口******************
    /**
     * @brief 初始化part
     * @param pMaster
     * @param partType
     * @param dbData
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData);
    
    /**
     * @brief 释放part资源
     * @return
     */
    virtual int UnInit();
    
    virtual int OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage);
public:
    /**
     * @brief 从数据库中加载数据
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::RoleDBData &data);
    
    /**
     * @brief 从配置中初始化数据
     * @return
     */
    virtual int InitConfig(const proto_ff::RoleDBData &data);
    
    /**
     * @brief 存储DB部件入口
     * @param proto
     * @return
     */
    virtual int SaveDB(proto_ff::RoleDBData &dbData);
    
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
    virtual int OnLogout() { return 0; }
    
    /**
     * @brief 掉线入口
     * @return
     */
    virtual int OnDisconnect() { return 0; }
    
    /**
     * @brief 重连入口
     * @return
     */
    virtual int OnReconnect() { return 0; }
    
    ////////////////////////////////// 每日零点 每周一零点 刷新接口 ///////////////////////////////////
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int DailyZeroUpdate();
    
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int WeekZeroUpdate() { return 0; }
    
    /**
     * @brief 每月刷新接口
     * @return
     */
    virtual int MonthZeroUpdate() { return 0; };
    
    /**
     * 设置外观信息
     * @param outproto
     */
    virtual int FillFacadeProto(proto_ff::RoleFacadeProto &outproto);
public:
    /**
     * @brief update
     */
    virtual int Update() { return 0; }

public:
    /**
     * @brief 注册要处理的消息
     * @return
     */
    virtual int RegisterMessage();
public:
    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet);
public:
    const proto_ff_s::E_FacadeValue_s *GetAdvanceFacadeCfgByLevel(int32_t level);
    void ActiveDefaultFacade(uint32_t facadeType);
    void calcAttr(bool sync);
    void calcAttr(int32_t type, MAP_INT32_INT64 &outAttr);
    void MergeAttr(const MAP_INT32_INT64 &src, MAP_INT32_INT64 &dst);
    void PrintAttr(int32_t type, const MAP_INT32_INT64 &attr);
    FacadeInfo *GetFacadeInfo(uint32_t facadeType);
public: //消息回调接口
    /**
     * @brief 获取外观基本信息
     */
    int OnHandleFacadeInfo(uint32_t msgId, NFDataPackage &packet);
    int _OnHandleFacadeInfo(uint32_t facadeType);
    
    /**
     * @brief 处理升级
     */
    int OnHandleLevelUp(uint32_t msgId, NFDataPackage &packet);
    
    int OnHandleFacadeSkillLev(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 处理穿戴和卸载
     */
    int OnHandleDress(uint32_t msgId, NFDataPackage &packet);
    int OnDress(uint32_t facadeType);
    
    /**
     * @brief 处理卸载
     */
    int OnHandleUnDress(uint32_t msgId, NFDataPackage &packet);
    int OnUnDress(uint32_t facadeType);
    
    /**
     * @brief 处理Fragment使用
     */
    int OnHandleFragmentUse(uint32_t msgId, NFDataPackage &packet);
public:
    /**
     * @brief
     */
    int OnHandleFacadeFantasyInfo(uint32_t msgId, NFDataPackage &packet);
    int _OnHandleFacadeFantasyInfo(uint32_t facadeType);
    
    /**
     * @brief 处理幻化激活
     */
    int OnHandleFastasyActiveInfo(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 处理幻化升级
     */
    int OnHandleFantasyLevelupInfo(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 处理穿戴和卸载
     */
    int OnHandleFantasyDress(uint32_t msgId, NFDataPackage &packet);
    int OnFantasyDress(uint32_t facadeType, uint64_t fantasyId);
    
    /**
     * @brief 处理卸载
     */
    int OnHandleFantasyUnDress(uint32_t msgId, NFDataPackage &packet);
    int OnFantasyUnDress(uint32_t facadeType);
    
    /**
     * @brief 器魂购买
     * @return
     */
    int OnHandleFacadeBuySoulReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 器魂信息
     * @return
     */
    int OnHandleFacadeSoulInfoReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 器魂激活
     * @return
     */
    int OnHandleSoulActiveReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 器魂升级
     * @return
     */
    int OnHandleSoulLevelupReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 器魂成就领取
     * @return
     */
    int OnHandleSoulActivityRecvReq(uint32_t msgId, NFDataPackage &packet);
    
    /**
     * @brief 器魂技能重置
     * @return
     */
    int OnHandleSoulResetSkillReq(uint32_t msgId, NFDataPackage &packet);
public:
    /**
     * @brief 计算升级到满级需要的材料个数
     * @param type
     * @param lev
     * @param addExp
     * @return
     */
    int32_t CalNeedItemNum(uint32_t type, uint32_t lev, int32_t addExp);
private:
    NFShmVector<FacadeInfo, proto_ff::FACADE_TYPE_MAX - 1> m_facadeInfo;
};