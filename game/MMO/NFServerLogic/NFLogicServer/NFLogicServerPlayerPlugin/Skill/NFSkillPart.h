// -------------------------------------------------------------------------
//    @FileName         :    NFSkillPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFSkillPart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFSkillDefine.h"
#include "NFComm/NFShmStl/NFShmHashSet.h"
#include "Skill.pb.h"
#include "DescStoreEx/SkillDescEx.h"

#define SKILL_MAX_SKILL_INFO_NUM 100

//技能信息
struct SkillInfo
{
    SkillInfo()
    {
        if(EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }
    
    int CreateInit()
    {
        skill_id = 0;
        level = 0;
        wakeup = 0;
        advance = 0;
        use_msc = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    uint64_t skill_id;        //技能ID
    int32_t level;            //技能等级
    int8_t wakeup;            //是否觉醒
    int8_t advance;            //进阶类型 1-火，2-雷，3-冰
    uint64_t use_msc;        //最近一次使用技能的时间，单位：unix毫秒
};

using MapSkillData = NFShmHashMap<uint64_t, SkillInfo, SKILL_MAX_SKILL_INFO_NUM>;

//技能组信息
struct SkillGroup
{
    uint32_t group = 0;                    //技能组ID
    uint64_t pos[MAX_ROLE_SKILL_POS];    //技能组指定位置处的技能ID
    uint8_t autouse[MAX_ROLE_SKILL_POS];//是否自动释放 1-是，0-否
    
    SkillGroup()
    {
        if(EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }
    
    int CreateInit()
    {
        memset(pos, 0, sizeof(pos));
        memset(autouse, 0, sizeof(autouse));
        group = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    SkillGroup(const SkillGroup &info)
    {
        group = info.group;
        for(uint32_t i = 0; i < MAX_ROLE_SKILL_POS; ++i)
        {
            pos[i] = info.pos[i];
            autouse[i] = info.autouse[i];
        }
    }
    
    SkillGroup &operator=(const SkillGroup &info)
    {
        group = info.group;
        for(uint32_t i = 0; i < MAX_ROLE_SKILL_POS; ++i)
        {
            pos[i] = info.pos[i];
            autouse[i] = info.autouse[i];
        }
        return *this;
    }
};

using MapSkillGroupData = NFShmHashMap<uint32_t, SkillGroup, 20>;

//宠物技能的cd
struct PetSkillCd
{
    PetSkillCd()
    {
        if(EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }
    
    int CreateInit()
    {
        petInstid = 0;
        usemsec = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    int64_t petInstid;
    uint64_t usemsec;
};
//skillid - PetSkillCd
using MapPetSkillCd = NFShmHashMap<uint64_t, PetSkillCd, 10>;

//技能进阶
struct SkillAdvPosInfo
{
    SkillAdvPosInfo()
    {
        if(EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
        {
            CreateInit();
        }
        else
        {
            ResumeInit();
        }
    }
    
    int CreateInit()
    {
        advance = 0;
        unlock = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    uint8_t advance;        //进阶类型
    uint8_t unlock;         //是否解锁，0-未解锁，1-已解锁
};

class NFSkillPart : public NFShmObjTemplate<NFSkillPart, EOT_LOGIC_PART_ID + PART_SKILL, NFPart>
{
public:
    enum
    {
        ETimerId_Anger = 1,
    };
    //天赋信息
    struct TalentInfo
    {
        TalentInfo()
        {
            if(EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
            {
                CreateInit();
            }
            else
            {
                ResumeInit();
            }
        }
        
        int CreateInit()
        {
            id = 0;
            lev = 0;
            return 0;
        }
        
        int ResumeInit()
        {
            return 0;
        }
        
        int32_t id;		//天赋ID
        int32_t lev;	//天赋等级
    };
    using MapTalent = NFShmHashMap<int32_t, TalentInfo, 10>;
public:
    NFSkillPart();
    
    virtual ~NFSkillPart();
    
    int CreateInit();
    
    int ResumeInit();

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
    
    virtual int OnLogin(proto_ff::PlayerInfoRsp &playerInfo) { return 0; }
    
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
    virtual int DailyZeroUpdate() { return 0; }
    
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
    virtual int FillFacadeProto(proto_ff::RoleFacadeProto &outproto) { return 0; }

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
public:
    //添加技能(永久增加)
    bool AddSkill(uint64_t skillid, int32_t level, const SCommonSource& src, bool sync = false, uint64_t use_msec = 0);
    bool AddSkill(const SkillCfg *pcfg, int32_t level, const SCommonSource& src, bool sync = false, uint64_t use_msec = 0);
    //移除技能(一定存在)
    bool RemoveSkill(uint64_t skillid, const SCommonSource& src, bool sync = false);
    //减少技能CD
    bool ReduceSkillCd(uint64_t skillid, uint32_t cd);
    //获取一个可使用的技能
    //生物移除技能 移除该技能的全部buff
    bool CreatureRemoveSkill(uint64_t skillid, bool sync);
    //生物移除技能 移除该技能的全部buff
    bool CreatureRemoveSkill(const SkillCfg* pcfg, bool sync);
    //生物移除技能，只移除单层buff
    bool CreatureRemoveSingleSkill(uint64_t skillid, bool sync);
    bool CreatureRemoveSingleSkill(const SkillCfg* pcfg, bool sync);
    //重置所有技能cd
    void ResetSkillCd();
    //技能总战力
    int64_t SkillFight() { return m_fight; }
    //处理技能升级(必须保证玩家已经拥有这个技能)
    bool OnSkillUpgrade(uint64_t skillid, int32_t level, SCommonSource &src);
    //进阶类型和等级
    void AdvanceInfo(int32_t& advancetype, int32_t& advancelev);
    //天神变身 deityId：天神ID
    int32_t OnDeityChgFacade(int64_t deityId);
    //天神开始变身
    void OnDeityStartFacade(int64_t deityId, bool sync = false);
    //天神结束变身
    void OnDeityEndFacade(bool sync = false);
    //变身的天神ID
    uint64_t FacadeDeityId() { return m_deityid; }
    //增加天赋点
    void OnAddTalent(int32_t cnt);
    //进入战斗状态
    void OnEnterFightState();
    //离开战斗状态
    void OnLeaveFightState();
    //生命改变
    void OnHpChange(int64_t oldHp, int64_t curHp, int64_t maxHp);
    //增加怒气值
    void AddAnger(int32_t anger);
    //添加技能组 chg:是否把当前使用的技能组切换成新的技能组
    bool AddSkillGroup(int32_t skillGroupid,bool chg, bool sync);
    //移除技能组
    bool RmvSkillGroup(int32_t skillGroupid, bool sync);
public:
    //宠物出战 petInstid:宠物实例ID
    int32_t OnPetWar(int64_t petInstid);
    //宠物休息 petInstid:宠物实例ID
    void OnPetRest(int64_t petInstid);
    //宠物技能升级
    void OnPetSkillUpgrade(uint64_t skillid, int32_t level);
public:
    //怪物回归
    void OnGoBack();
private:
    //是否是第一次释放技能
    bool IsFirst(uint64_t skillid);
    //设置第一次释放技能
    void FirstUse(uint64_t skillid);
public:
    void OnLevelUp(int32_t oldlev, bool sync = false);
    //技能升级，返回 RET_SUCCESS 成功，其他表示错误码
    int32_t SkillUpgrade(uint64_t skillid);
    //获取技能信息
    const SkillInfo* GetSkillInfo(uint64_t skillid);
private:
    //使用技能
    int OnUseSkill(uint32_t msgId, NFDataPackage &packet);
    //同步技能目标
    int OnSyncTarget(uint32_t msgId, NFDataPackage &packet);
    //取消使用技能
    int OnCancelUse(uint32_t msgId, NFDataPackage &packet);
    //客户端中断连续性技能
    int OnBreakSkill(uint32_t msgId, NFDataPackage &packet);
    //技能详细信息
    int OnDetail(uint32_t msgId, NFDataPackage &packet);
    //技能觉醒
    int OnWakeup(uint32_t msgId, NFDataPackage &packet);
    //改变技能位置
    int OnChgPos(uint32_t msgId, NFDataPackage &packet);
    //技能升级
    int OnUpgrade(uint32_t msgId, NFDataPackage &packet);
    //设置自动释放
    int OnSetAutoUse(uint32_t msgId, NFDataPackage &packet);
    //技能进阶
    int OnAdvance(uint32_t msgId, NFDataPackage &packet);
    //切换进阶位置
    int OnAdvanceChgPos(uint32_t msgId, NFDataPackage &packet);
    //技能进阶重置
    int OnAdvanceReset(uint32_t msgId, NFDataPackage &packet);
    //解锁进阶位置
    int OnAdvanceUnlockpos(uint32_t msgId, NFDataPackage &packet);
    //更新技能进阶数据
    void OnUpdateAdvance();
    //更新技能组信息
    void OnUpdateSkillGroup();
    //天赋信息
    int OnTalentInfo(uint32_t msgId, NFDataPackage &packet);
    //使用天赋点数
    int OnTalentUsePoint(uint32_t msgId, NFDataPackage &packet);
    //重置天赋信息
    int OnTalentReset(uint32_t msgId, NFDataPackage &packet);
    //怒气值更新
    void OnAngerUpdateRsp();
private:
    void AddSkillInfo(const SkillInfo &info);
    void DelSkillInfo(uint64_t skillid);
    SkillInfo* GetSkillData(uint64_t skillid);
    int32_t LeftCd(uint64_t curmsc, uint32_t cd, const  SkillInfo *pinfo);
    void SetSkillProto(const SkillInfo* pinfo, proto_ff::SkillInfoProto& proto);
    void SetAllSkillProto(proto_ff::SkillInfoListProto& proto);
    void SetAdvanceListProto(proto_ff::SkillAdvanceListProto& proto);
private:
    SkillGroup* GetSkillGroup(uint32_t groupid);
    void AddSkillGroup(SkillGroup& info);
    void DelSkillGroup(uint32_t groupid);
    bool IsDySkill(int64_t skillid);						//是否是动态技能
    void SetSkillGroupProto(SkillGroup *pgroup, proto_ff::SkillGroupProto &proto);
    void SetAllSkillGroupProto(proto_ff::SkillGroupListProto &proto);
    int32_t SkillUpgrade(const SkillCfg* pcfg, SkillInfo* pinfo,bool sync);
    void CalcSkillFight();
    void OnSkillUpgrade(const SkillCfg* pcfg, SkillInfo* pinfo, int32_t oldlev);
    void OnAddSkill(const SkillCfg* pcfg, int32_t level);
    void OnRemoveSkill(const SkillCfg* pcfg, int32_t level);
    void OnAddSkillGroup(const SkillCfg* pcfg, bool sync = false);			//技能添加到技能组对应位置上
    void OnRemoveSkillGroup(const SkillCfg* pcfg, bool sync = false);		//技能从技能组位置上移除
    void OnShrinkSkillGroup(uint32_t groupid,bool sync = false);			//收缩技能组位置上的技能
    //处理添加被动技能
    bool OnAddPassiveSkill(string strpre, const SkillCfg* pcfg, int32_t level,const SCommonSource& src, bool sync = false);
private:
    PetSkillCd* GetPetSkillCd(uint64_t skillid);				//获取宠物技能的cd
    void AddPetSkillCd(uint64_t skillid, PetSkillCd &cd);		//添加宠物技能的cd
    void DelPetSkillCd(uint64_t skillid);						//移除宠物技能的cd
private:
    bool ValidUseSkillIndex(uint32_t index);
    uint32_t NewIndex();
private:
    //当前选中的进阶位置
    uint8_t CurAdvpos() { return m_curadvpos; }
    void CurAdvpos(uint8_t pos) { m_curadvpos = pos; }
    //进阶位置信息
    SkillAdvPosInfo* GetAdvPosInfo(uint8_t pos);
    //获取一个未解锁的进阶位置信息
    uint8_t GetAdvLockPos();
    //获取一个未设置进阶类型的位置信息
    uint8_t GetNoAdvPos();
    //进阶位置是否解锁
    bool IsAdvposUnlock(uint8_t pos);
    //解锁进阶位置
    void UnlockAdvpos(uint8_t pos);
    //设置指定位置处的进阶类型
    void SetAdvPosInfo(uint8_t pos, uint8_t advtype);
    //获取进阶类型对应的等级
    uint8_t GetAdvLev(uint8_t advtype);
    //设置进阶类型的等级
    void SetAdvLev(uint8_t advtype, uint8_t advlev);
    //处理进阶类型和等级的buff
    bool OnAdvanceBuff(uint8_t advance, uint8_t advancelev,bool rmvflag);
private:
    uint32_t TalentCnt() { return m_talentcnt; }
    void TalentCnt(uint32_t cnt) { m_talentcnt = cnt;}
    TalentInfo* GetTalentInfo(int32_t id);
    void AddTalentInfo(TalentInfo &info);
    void DelTalentInfo(int32_t id);
    void ClearTalentInfo();
    void OnTalentCntNotify();
private:
    //怒气值是否满了
    bool IsAngerFull();
private:
    /**
     * @brief 技能数据
     */
    MapSkillData m_mapskill;
    
    /**
     * @brief 技能组位置
     */
    MapSkillGroupData m_mapGroup;
    
    /**
     * @brief 宠物技能的cd
     */
    MapPetSkillCd m_mapPetSkillCd;
private:
    /**
     * @brief 当前选中的进阶位置
     */
    uint8_t m_curadvpos;
    
    /**
     * @brief 进阶位置
     */
    SkillAdvPosInfo m_advpos[MAX_ROLE_SKILL_ADVANCE_POS];
    
    /**
     * @brief 进阶等级
     */
    uint8_t m_advlev[(int8_t) ESkillAdvance::limit];
private:
    /**
     * @brief 当前使用的技能组ID
     */
    uint32_t m_group;
    
    /**
     * @brief 最近一次切换技能组的时间
     */
    uint64_t m_lastgroup;
public:
    /**
     * @brief 公共cd起始时间
     */
    int64_t m_startpubcd;
    
    /**
     * @brief 技能战力
     */
    int64_t m_fight;
    
    /**
     * @brief 变身天神ID，只是用于数据中转
     */
    uint64_t m_deityid;
    
    /**
     * @brief 可用天赋点数
     */
    uint32_t m_talentcnt;

    /**
     * @brief 天赋信息
     */
    MapTalent m_talent;
    
    /**
     * @brief 亢龙有悔技能的怒气值
     */
    uint32_t m_anger;
    
    NFShmHashSet<uint64_t, 10> m_setuse;                            //回归后使用过的技能列表
    bool m_first;                            //是否是第一次释放技能
};