// -------------------------------------------------------------------------
//    @FileName         :    NFEventDefine.h
//    @Author           :    gaoyi
//    @Date             :    22-11-16
//    @Email			:    445267987@qq.com
//    @Module           :    NFEventDefine
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFCharactorDefine.h"

#pragma pack(push)
#pragma pack(1)

enum NF_EVENT_ID
{
    NF_EVENT_CREATE_SCENE_EVENT = 100,
};

enum EventId
{
    EVENT_NONE = 0,
    ///////////////////////视野事件//////////////////////////
    EVENT_BEEN_SEE,						//被别人看见
    EVENT_MONSTER_BEEN_FIRST_PLAYER_SEE, //怪物被第一个玩家进入视野的玩家看见
    EVENT_MONSTER_NO_PLAYER_SEE, //没有人看见怪物
    EVENT_SCENE_FIRST_PLAYER, //第一个进入场景的玩家
    EVENT_SCENE_NO_PLAYER, //最后玩家离开场景
    
    ///////////////////////战斗事件//////////////////////////
    EVENT_UNDER_ATTACK,					//被人攻击
    EVENT_ATTACK_SOMEBODY,				//攻击别人
    EVENT_USE_SKILL,					//使用技能事件
    
    
    ///////////////////////技能事件//////////////////////////
    EVENT_USE_SKILL_ATTACK,				//玩家使用技能，并且达到了人，使用一次技能，只发送一次事件
    EVENT_BUFF_START_TYPE,				//BUFF生效条件
    EVENT_BUFF_END_TYPE,				//BUFF结束条件
    EVENT_BUFF_START_BUFF,				//开始一个BUFF
    EVENT_BUFF_DODGE,					//技能闪避事件
    EVENT_BUFF_CRIT,					//技能暴击事件
    
    ///////////////////////角色相关事件//////////////////////
    EVENT_CREATURE_DEAD,				//生物死亡(发送事件参数是 killer_cid 和 kind)
    EVENT_DEAD,                         //生物死亡(发送事件参数是 cid 和 kind)
    EVENT_CREATURE_REVIVE,				//生物复活
    EVENT_LOGIN_GAME,					//登入游戏
    EVENT_LOGOUT_GAME,					//登出游戏
    EVENT_START_MOVE,					//开始移动
    EVENT_END_MOVE,						//停止移动
    EVENT_TELEPORT_MOVE,				//瞬间移动
    EVENT_DISCONNECT,					//断开连接
    EVENT_LEVELUP,						//升级
    EVENT_FACADE_CHANGE,				//外观改变
    EVENT_CALC_FIGHT_POWER,				//通知计算战斗力事件，在计算战斗力条件改变的时候，触发
    EVENT_ADD_TITLE,					//获得称号			titileId
    EVENT_SKILL_UP,						//升级角色技能
    EVENT_RECHARGE,						//充值钻石			num
    EVENT_VIP_UP,						//vip等级提升		vipLevel
    EVENT_VIP_ACTIVE,                   //vip激活
    EVENT_VIP_TIMEOUT,                  //vip过期
    EVENT_LEAVE_TEAM,					//离开队伍
    EVENT_JOIN_TEAM,					//加入队伍
    EVENT_DISMISS_TEAM,					//解散队伍
    EVENT_RECONNECT_SUCCEED,			//重连成功
    EVENT_PAY,                          //玩家充值
    EVENT_INVISIBLE_STATE,				//玩家隐身
    ////////////////////////场景相关事件//////////////////////////
    EVENT_CREATE_SCENE,					//创建场景
    EVENT_LEAVE_SCENE,					//离开场景
    EVENT_ENTER_SCENE,					//进入场景
    EVENT_TRANS_CHECK_RES,				//传送校验结果（通知源逻辑节点，跨逻辑节点传送之校验结果）
    EVENT_TRANS_PREPARE,				//准备传送（跨逻辑节点传送 校验完了之后，准备传送）
    EVENT_TRANS_SUCCESS,				//传送成功（跨逻辑节点传送 目标逻辑节点成功收到传送参数信息）
    EVENT_CHANGE_SCENE,					//生物场景改变
    EVENT_SYNC_SCENE_POS,               //场景位置同步
    EVENT_SYNC_SCENE_STATE,             //场景状态同步事件
    EVENT_SYNC_SCENE_FACADE,            //同步场景外观
    EVENT_SYNC_CREATURE_ATTR,           //生物属性同步
    EVENT_SYNC_CREATURE_BROADCAST_ATTR, //广播属性同步
    EVENT_SYNC_SNS_ATTR,                //广播属性同步

    ////////////////////////任务事件/////////////////////////
    EVENT_ACCEPT_TASK,					//接取任务
    EVENT_FINISH_NOT_SUMIT_TASK,		//完成任务但是还没有提交
    EVENT_FINISH_TASK,					//完成任务
    //////////////////////////////////////////////////////////////////////////
    
    ////////////////////////副本事件///////////////////////////
    EVENT_PASS_DUPLICATE,				//通关副本
    EVENT_ENTER_DUPLICATE,				//进入副本
    EVENT_INSPIRE_DUPLICATE,			//副本鼓舞
    EVENT_SWEEP_DUPLICATE,				//扫荡副本
    EVENT_WAVE_DUPLICATE,               //副本怪物波次变化
    
    ////////////////////////物品装备事件////////////////////////
    EVENT_EQUP_STREN,					//装备强化
    EVENT_ITEM_CHANGE,					//物品改变
    EVENT_ITEM_USE,						//使用物品
    EVENT_PICK_ITEM,					//拾取事件
    EVENT_EQUIP_REFINE,					//装备精炼
    EVENT_STONE_INLAY,					//镶嵌宝石
    EVENT_EQUIP_DRESS,					//装备穿戴
    EVENT_EQUIP_DRESS_SUIT,				//装备穿戴 套装
    EVENT_EQUIP_SCORE_CHANGE,			//装备评分
    EVENT_MATERIAL_COMPOSE,				//材料合成
    EVENT_MATERIAL_COMPOSE_FAIL,		//材料合成失败
    ////////////////////////好友事件//////////////////////////////
    EVENT_ADD_FRIEND,					//添加好友事件   2019.6.27 修改
    EVENT_RELATION_GIVE,                //好友送礼
    ////////////////////////成就事件//////////////////////////////
    EVENT_FINISH_ACHIVEMENT,			//领取成就
    EVENT_ADD_ACHIVEMENT_PROGRESS,      //成就进度增加
    
    ///////////////////////竞技场事件/////////////////////////////
    EVENT_ARENA_LEVEL_UP,				//竞技场排名提升
    EVENT_ARENA_RESULT,					//挑战竞技场		胜负、层数、是否连续7天位于竞技场第2的位置上(尼玛)
    EVENT_ARENA_JOIN,					//参加竞技场事件
    EVENT_ARENA_SCORE_CHANGE,			//积分改变
    
    ///////////////////////活动相关////////////////////////////////
    EVENT_ACT_OPEN,                     //活动开启
    EVENT_ACT_CLOSE,                    //活动关闭
    EVENT_ACT_PRE_FINISH,               //活动提前完成
    ///////////////////////聊天事件////////////////////////////////
    EVENT_CHAT,							//聊天				channel、是否发送坐标
    
    ///////////////////////帮派事件////////////////////////////////
    EVENT_GUILD_CHANGE,					//帮派改变
    EVENT_DISMISS_GUILD,				//帮派解散
    
    
    EVENT_FUNCTIONUNLOCK,				//功能解锁
    
    
    EVENT_EQUIP_UNDRESS,				//装备卸装
    
    EVENT_GROW_PART_ACTIVE,					//养成激活事件
    EVENT_GROW_PART_LVUP,					//养成升级事件
    EVENT_GROW_PART_DRESS,					//穿戴外观部件
    
    EVENT_WING_FIGHT_CHANGE,			//翅膀战力改变事件
    EVENT_TREASURE_FIGHT_CHANGE,        //宝具战力改变事件
    EVENT_PARTNER_FIGHT_CHANGE,			//伙伴战力改变事件
    EVENT_ARTIFACT_FIGHT_CHANGE,        //神器战力改变事件
    
    EVENT_WING_FANTASY,					//翅膀幻化事件
    EVENT_TREASURE_FANTASY,				//宝具幻化事件
    EVENT_ARTIFACT_FANTASY,				//神器幻化事件
    EVENT_PARTNER_FANTASY,				//幻伙伴化事件
    
    EVENT_WING_ADVANCE,                 //翅膀升级事件
    EVENT_TREASURE_ADVANCE,             //宝具升级事件
    EVENT_ARTIFACT_ADVANCE,             //神器升级事件
    EVENT_PARTNER_ADVANCE,              //幻伙升级事件
    EVENT_KILL_BOSS,					//击杀BOSS事件
    EVENT_DAILY_BACK,				    //每日找回事件
    EVENT_CONVOY_ESCORT,				//护送镖车事件
    EVENT_CONVOY_ESCORT_CMPT,			//护送镖车事件
    EVENT_CONVOY_ACCEPT,
    EVENT_MOUNT_FIGHT_CHANGE,          //坐骑战力改变事件
    //坐骑事件
    EVENT_MOUNT_LEVELUP,				//坐骑升级
    EVENT_MOUNT_OPEN_MOUNT_EGG_SLOT,    //宠物蛋孵化槽位
    
    EVENT_OCCUPATION_LEVELUP,           //转职几转完成
    
    
    EVENT_GET_PET,                      //获得一个宠物
    EVENT_PET_STEPLV,                   //宠物进阶升级
    EVENT_PET_LV,                       //宠物升级
    EVENT_PET_STARLV,                   //宠物升星
    EVENT_DAILY_TASK_DAILY_SCORE,       //每日活跃的改变
    EVENT_ONLINE_TIME,                  //每日在线时间
    EVENT_PET_CALL,                     //宠物上阵
    EVENT_PET_OPEN_EGG_SLOT,            //宠物蛋孵化槽位
    EVENT_PET_FIGHT_CHANGE,
    //助战
    EVENT_ASSIST_MONSTER_RECALC_HURT,   //可援助怪物重新计算血量
    EVENT_LOGIN_DAY,                    //登陆天数事件
    
    //神魔
    EVENT_GODE_EVIL_ACTIVE,             //激活神魔系统
    EVENT_WASH_UNLOCK,                  //洗练解锁
    EVENT_WASH,                         //洗练
    EVENT_WASH_QUALITY,                 //洗练洗练属性整体修改
    
    EVENT_LIGHT_SOUL,                   //点亮龙魂
    //神机装备
    EVENT_BEQ_DECOMPOSE,                //神机装备分解事件
    EVENT_BEQ_STRONG,                   //神机装备打造事件
    EVENT_BEQ_DRESS,                    //神机装备穿戴事件
    EVENT_BEQ_POUR,                     //神机装备注灵事件
    EVENT_BEQ_BREAK_LVUP,               //神机装备槽位铭刻升级事件
    EVENT_BEQ_AWAKEN_LVUP,              //神机装备觉醒升级事件
    EVENT_BEQ_CMPT_TASK,                //完成并领取了神机装备前置任务
    
    //采集
    EVENT_COLLECT,                      //采集
    //结婚
    EVENT_MARRY_CHILD_LV,                //仙娃升级事件
    EVENT_MARRY_CHILD_GET,              //获得仙娃事件
    EVENT_MARRY_EXPRESS_LV,             //表白等级提升事件
    EVENT_MARRY_LOCK_LV,                //同心锁升级事件
    EVENT_MARRY_CMPT_RECV_TASK,         //完成并领取结婚前置任务
    EVENT_MARRY_CMPT,                   //完成结婚
    EVENT_MARRY_EXPRESS,                //表白事件
    //天机普
    EVENT_GOD_RELICS_FINISH,            //天机普任务完成
    EVENT_GOD_RELICS_GROUP_FINISH,      //天神遗物完成
    
    //天神
    EVENT_DEITY_FANTASY_ACTIVE,         //激活一个天神
    EVENT_DEITY_FANTASY_BATTLE,         //出战天神
    //战队
    EVENT_CLAN_CREATE,                  //创建战队
    EVENT_JOIN_CLAN,                    //加入团队
    
    //修真
    EVENT_PT_LEVELUP,                   //仙阶升级
    
    EVENT_DRAGONSOUL_DRESS,				//装备穿戴龙魂
    EVENT_DRAGONSOUL_ACTIVE_SLOT,		//激活龙魂核心孔
    EVENT_HANDBOOK_BEAST_ACTIVE,        //激活图鉴神兽
    EVENT_ANCIENT_LEVELUP,              //上古神灵
    
    EVENT_MAGIC_SUM_CHANGE,             //魔晶累计
    EVENT_VERSION_ID_CHANGE,            //版本号修改
    EVENT_WELFARE_QIFU,                 //福利祈福
    EVENT_FACTION_TRANS,                //公会传功
    EVENT_WASH_PARTY,                   //瑶池
    
    EVENT_TURN_CMPT_TASK,                //完成并领取了转生装备前置任务
    EVENT_SOUL_CMPT_TASK,                //完成并领取了战魂前置任务
    
    EVENT_ID_LIMIT = 255,				//事件ID最大值
    
    
};


//传送校验结果（跨逻辑节点传送之前的校验）
struct TransCheckResEvent
{
    int32_t result = 0;
    uint64_t creature_cid = 0;
    uint64_t dst_sceneid = 0;
};

struct LoginGameEvent
{
    uint32_t uid = 0;      //帐号id
    uint64_t cid = 0;      //角色id
};

struct LogoutGameEvent
{
    uint32_t uid = 0;      //帐号id
    uint64_t cid = 0;      //角色id
};

struct GrowPartActiveEvent
{
    int32_t type = 0;
    int32_t id = 0;
    int32_t curLv = 0;
};
//开始移动事件
struct StartMove
{
};

struct GrowPartLvUpEvent
{
    int32_t type = 0;
    int32_t id = 0;
    int32_t curLv = 0;
};

struct GrowPartDressEvent
{
    int32_t type = 0;
    int32_t id = 0;
    int32_t curLv = 0;
};


//进入场景事件
struct EnterSceneEvent
{
    uint64_t cid = 0;      //生物id
    uint32_t uid = 0;
    uint64_t clientid = 0;
    uint64_t mapid = 0;	   //地图ID
    int32_t x = 0;
    int32_t y = 0;
    int32_t z = 0;
    //STransParam transParam;	//切换地图参数
};
//改变场景事件
struct ChgSceneEvent
{
    uint64_t cid = 0;			//玩家cid
    bool enterFalg = false;		//是否是进入场景
};

//世界聊天次数
struct ChatWorldEvent
{};

struct DressEquipChangeEvent
{
};

struct EquipScoreChangeEvent
{
    uint64_t all_score = 0;
};

struct DressEquipSuitEvent
{
    std::map<uint32_t, std::map<uint32_t, std::map<uint32_t, uint32_t>>> wearQualityQualityStarMap; //普通装备
    std::map<uint32_t, std::map<uint32_t, uint32_t>> wearQualityStarMap; //普通装备
    std::map<uint32_t, std::map<uint32_t, uint32_t>> wearXQQualityStarMap;//仙器
    int wearGuardNum = 0;// 永久守护
};

struct EquipUndress
{
};

//好友送礼事件
struct FriendAddEvent
{
    uint32_t num = 0;
    uint32_t curNum = 0;
};

//复活事件
struct ReliveEvent
{
    uint64_t cid = 0;
};


//死亡事件结构
struct DieEvent
{
    uint64_t monsterId = 0;								//怪物ID
    int32_t count = 0; 									//这次操作数量 count为正数表示相加 count为负数表示相减
    uint64_t  killerCid = 0;							//击杀者id,杀怪任务特定参数
    uint64_t sceneId = 0;								//场景ID
    uint64_t nCid = 0;									//生物CID
    uint64_t planUid = 0;								//位面UID
    SET_UINT64 setHate;									//仇恨列表
    int32_t createType = 0;								//怪物创建类型（来源）
    uint64_t createTypeVal = 0;							//怪物创建类型值
    int32_t level = 0;									//怪物等级
    int64_t camp = 0;                                   //阵营
    
    //专属怪字段
    bool	IsExclusive = false;						//是否是专属怪
    uint64_t ExclusiveCid = 0;							//专属怪所属的玩家cid
    
    //归属相关的字段
    SET_UINT64 setJoinPick;								//参与掉落 可拾取玩家
    SET_UINT64 setHarmPick;								//伤害掉落 可拾取玩家
    //打宝那边用到的掉落归属
    
    //经验加成
    int32_t  expAdd = 0;								//怪物经验加成
    //boss layerkey
    int64_t  layerKey = 0;
    uint64_t killExp = 0;                               //玩家击杀怪物获得的经验
};

struct WingFightChgEvent
{
    uint64_t cid = 0;		//玩家cid
    uint64_t fight = 0;		//战力值
};
//进入副本
struct EnterDupEvent
{
    uint64_t dupId = 0; //副本ID
    uint64_t groupId = 0;	//副本组ID
};

//EVENT_WAVE_DUPLICATE
struct WaveDupEvent
{
    uint64_t dupId = 0;
    uint32_t cur_wave = 0;
    uint32_t max_wave = 0;
};

//离开场景
struct LeaveSceneEvent
{
    uint64_t cId = 0;      //生物cid
    uint64_t sceneId = 0;
    uint64_t mapId = 0;
};
//帮派改变
struct CuildChangeEvent
{
    int32_t level = 0;		//帮派等级
};


struct PartnerFightChgEvent
{
    uint64_t cid;		//玩家cid
    uint64_t fight;		//战力值
    PartnerFightChgEvent()
    {
        cid = 0;
        fight = 0;
    }
};

struct ArtifactFightChgEvent
{
    uint64_t cid;		//玩家cid
    uint64_t fight;		//战力值
    ArtifactFightChgEvent()
    {
        cid = 0;
        fight = 0;
    }
};

struct TreasureFightChgEvent
{
    uint64_t cid;		//玩家cid
    uint64_t fight;		//战力值
    TreasureFightChgEvent()
    {
        cid = 0;
        fight = 0;
    }
};

struct ArtifactFantasy
{
    uint64_t nFantasyId;
    uint32_t nLevel;
    uint32_t nTotalLv;
    ArtifactFantasy()
    {
        nFantasyId = 0;
        nLevel = 0;
        nTotalLv = 0;
    }
};

struct TreasureFantasy
{
    uint64_t nFantasyId;
    uint32_t nLevel;
    uint32_t nTotalLv;
    TreasureFantasy()
    {
        nFantasyId = 0;
        nLevel = 0;
        nTotalLv = 0;
    }
};

struct WingFantasy
{
    uint64_t nFantasyId;
    uint32_t nLevel;
    uint32_t nTotalLv;
    WingFantasy()
    {
        nFantasyId = 0;
        nLevel = 0;
        nTotalLv = 0;
    }
};

struct PartnerFantasy
{
    uint64_t nFantasyId;
    uint32_t nLevel;
    uint32_t nTotalLv;
    PartnerFantasy()
    {
        nFantasyId = 0;
        nLevel = 0;
        nTotalLv = 0;
    }
};

struct WingAdvance
{
    uint32_t nLevel;
    WingAdvance()
    {
        nLevel = 0;
    }
};

struct TreasureAdvance
{
    uint32_t nLevel;
    TreasureAdvance()
    {
        nLevel = 0;
    }
};

struct ArtifactAdvance
{
    uint32_t nLevel;
    ArtifactAdvance()
    {
        nLevel = 0;
    }
};

struct MountAdvance
{
    uint32_t nLevel;
    MountAdvance()
    {
        nLevel = 0;
    }
};

struct OccupationAdvance
{
    uint32_t nGrade;
    OccupationAdvance()
    {
        nGrade = 0;
    }
};

struct PartnerAdvance
{
    uint32_t nLevel;
    PartnerAdvance()
    {
        nLevel = 0;
    }
};

//使用物品
struct ItemUseEvent
{
    uint64_t itemId;
    int32_t num;
    ItemUseEvent()
    {
        itemId = 0;
        num = 0;
    }
};

//活动开放事件
struct ActivityReadyEvent
{
    uint64_t activity_id;
    int32_t activity_type;
    
    ActivityReadyEvent()
    {
        memset(this, 0, sizeof(ActivityReadyEvent));
    }
};

//活动开放事件
struct ActivityStartEvent
{
    uint64_t activity_id;
    int32_t activity_type;
    
    ActivityStartEvent()
    {
        memset(this, 0, sizeof(ActivityStartEvent));
    }
};


//活动结束事件
struct ActivityEndEvent
{
    uint64_t activity_id;
    int32_t activity_type;
    
    ActivityEndEvent()
    {
        memset(this, 0, sizeof(ActivityStartEvent));
    }
};

//玩家参与活动事件
struct ActivityPlayerEnterEvent
{
    uint64_t activity_id;
    int32_t activity_type;
    
    ActivityPlayerEnterEvent()
    {
        memset(this, 0, sizeof(ActivityPlayerEnterEvent));
    }
};

//玩家离开活动事件
struct ActivityPlayerLeaveEvent
{
    uint64_t activity_id;
    int32_t activity_type;
    
    ActivityPlayerLeaveEvent()
    {
        memset(this, 0, sizeof(ActivityPlayerLeaveEvent));
    }
};


//玩家完成活动事件
struct ActivityPlayerCompleteEvent
{
    uint64_t activity_id;
    int32_t activity_type;
    
    ActivityPlayerCompleteEvent()
    {
        memset(this, 0, sizeof(ActivityPlayerCompleteEvent));
    }
};

struct KillBossEvent
{
    int64_t monster_id;
    int32_t boss_type;
    uint64_t kill_id;
    int32_t boss_id;
    KillBossEvent()
    {
        kill_id = 0;
        monster_id = 0;
        boss_type = 0;
        boss_id = 0;
    }
};

//副本找回事件
struct DailyBackEvent
{
    uint64_t id;	//
    uint32_t left_num;		//剩余次数，
    uint32_t external_left_num; //剩余购买的次数
    
    DailyBackEvent()
    {
        id = 0;
        left_num = 0;
        external_left_num = 0;
    }
};

//接取任务
struct AcceptTaskEvent
{
    uint64_t taskId;
    uint64_t cid;
    uint32_t taskType;
    AcceptTaskEvent()
    {
        taskId = 0;
        cid = 0;
        taskType = 0;
    }
};
struct PickItemEvent
{
    uint64_t pickerId;		//拾取方ID
    SCommonSource  source;		//掉落的来源
};
//技能攻击事件
struct SkillAttackEvent
{
    uint64_t attacker = 0;		//攻击方cid
    uint64_t victim = 0;		//受害者cid
    uint64_t skillId = 0;		//使用的技能id
    uint64_t buffId = 0;        //造成伤害的buffid（buff伤害才有值）
    int64_t  sufferedValue = 0; //遭受的数值
    bool rebound = false;		//是否是反弹伤害
    int8_t atk_kind = 0;        //攻击方生物类型
    int8_t victim_kind = 0;     //受害者生物类型
    uint64_t m_victim_cfgid = 0;//受害者配置ID
};
//使用技能事件
struct UseSkillEvent
{
    int64_t skillId = 0;	//技能配置ID
    int32_t group = 0;      //技能组ID
};


struct VipUpEvent
{
    int32_t oldLv;
    int32_t newLv;
    
};


struct VipActiveEvent
{

};

struct VipOutTimeEvent
{

};


//玩家隐身
struct InvisibleEvent
{
    uint64_t cid = 0;			//玩家CID
    int32_t invisibleFlag = 0;  //隐身标记，1-隐身状态，0-非隐身状态
};

//竞技场胜利失败事件
struct ArenaResultEvent
{
    bool isWin;
    ArenaResultEvent()
    {
        isWin = false;
    }
};

struct ArenaJoinEvent
{
};

struct ArenaScoreEvent
{
    uint32_t score = 0;
};

struct StoneInlayEvent
{
    int32_t pos;				//装备部位
    uint64_t stone_itemId;		//宝石ID
    uint32_t stone_level;		//宝石等级
    uint32_t total_level;		//宝石总等级
    uint32_t ave_stone_level;	//全身穿戴装备全部镶嵌满xx级以上的宝石
    uint32_t count;				//镶嵌宝石数量
    std::map<uint32_t, uint32_t> qualityMap;
    StoneInlayEvent()
    {
        pos = 0;
        stone_itemId = 0;
        stone_level = 0;
        total_level = 0;
        ave_stone_level = 0;
        count = 0;
    }
};

// 强化
struct EquipStrongEvent
{
    int32_t pos;				// 槽位
    uint64_t equip_id;			// 装备ID
    uint64_t stonelv;			// 强化后等级
    uint16_t lowest_stren_lv;   // 全身装备中最低的强化等级
    uint16_t total_stren_lv;    // 总强化等级
    uint16_t total_com_lv;
    uint16_t total_xianqi_lv;
    
    EquipStrongEvent()
    {
        pos = 0;
        equip_id = 0;
        stonelv = 0;
        lowest_stren_lv = 0;
        total_stren_lv = 0;
        total_com_lv = 0;
        total_xianqi_lv = 0;
    }
};



struct ArenaLevelUpEvent
{
    uint32_t level;	//竞技场当前排名
};

//扫荡副本
struct SweepDupEvent
{
    uint64_t dupId;	//扫荡副本
    uint64_t dupGroupId; //副本组ID
    int32_t num;
    SweepDupEvent()
    {
        dupId = 0;
        dupGroupId = 0;
        num = 0;
    }
};

//伙伴升级事件
struct PartnerUpgradeEvent
{
    uint32_t nLevel; //等级
    PartnerUpgradeEvent()
    {
        nLevel = 0;
    }
};

//伙伴幻化事件
struct PartnerFantasyEvent
{
    uint64_t nFantasyId;
    uint64_t nLevel; //等级
    uint32_t nTotalLv;
    PartnerFantasyEvent()
    {
        nFantasyId = 0;
        nLevel = 0;
        nTotalLv = 0;
    }
};

struct ItemChangeEvent
{
    uint64_t itemId;
    int64_t itemNum;
    int64_t itemChgNum;
    int32_t changeType;
    SCommonSource itemSource;
    int32_t opetateType;
    ItemChangeEvent()
    {
        itemId = 0;
        itemNum = 0;
        itemChgNum = 0;
        changeType = 0;
        opetateType = 0;
        itemSource.clear();
    }
};

struct MountFightChgEvent
{
    uint64_t cid;		//玩家cid
    uint64_t fight;		//战力值
    MountFightChgEvent()
    {
        cid = 0;
        fight = 0;
    }
};

//激活坐骑
struct HorseActiveEvent
{
    uint64_t id;    //激活的坐骑id
    uint32_t count; //拥有激活的坐骑数量
    HorseActiveEvent()
    {
        id = 0;
        count = 0;
    }
};


//坐骑升级
struct HorseLevelUp
{
    uint64_t id;    //激活的坐骑id
    uint32_t level; //等级
    uint32_t nTotalLv;	//总等级
    HorseLevelUp()
    {
        id = 0;
        level = 0;
        nTotalLv = 0;
    }
};

//获得一个宠物
struct GetPetEvent
{
    int32_t instId; //宠物ID
    int32_t cfgId;
    int32_t curPetNum;
    int32_t quality;
};

//召唤一个宠物
struct CallPetEvent
{
    int32_t instId; //宠物ID
    int32_t cfgId;
    int32_t curCallPetNum;
    
};

//宠物进阶升级
struct PetStepLvEvent
{
    int32_t instId; //宠物ID
    int32_t cfgId;
    int32_t newStepLv;
};

//宠物升级
struct PetLvEvent
{
    int32_t instId; //宠物ID
    int32_t cfgId;
    int32_t oldLv;
    int32_t newLv;
};

//宠物升星
struct PetStarLvEvent
{
    int32_t instId; //宠物ID
    int32_t cfgId;
    int32_t newLv;
};

//重生宠物
struct PetRestEvent
{
    int32_t instId; //宠物ID
    int32_t cfgId;
    int32_t curPetNum;
    
};
//护送镖车完成事件
struct ConvoyEscortCmptEvent
{
    uint64_t cid = 0;		//玩家cid
    int32_t escortId = 0;
    
};
struct ConvoyAcceptEvent
{

};
//断开链接
struct DisConnectEvent
{
    uint64_t cid = 0;
};
//重连成功事件
struct ReconnectSucceedEvent
{
    uint64_t cid = 0;
};

//EVENT_DAILY_TASK_DAILY_SCORE,       //每日活跃的改变
struct DailyTaskDailyScoreEvent
{
    uint32_t old_score = 0;
    uint32_t new_score = 0;
};

struct DailyOnlineTimeEvent
{
    uint32_t online_time = 0;
};


struct AssistMonsterRecalcHurtEvent
{
    EMonsCreateType createType = EMonsCreateType::None;      //创建怪物key
    int64_t createVal = 0;                                  //怪物创建类型
    int64_t sendHelperCid = 0;
    int64_t helpCid = 0;
    int32_t opt = 0;        //操作1 玩家离开援助 2:玩家确认帮助 3 玩家主动退出删除援助
};


//登录天数
struct LoginDayEvent
{
    uint32_t day = 0;
};


//洗练解锁事件
struct EquipWashUnlockEvent
{
    int32_t equip_slot =0;
    int32_t wash_slot =0;
};

//洗练事件
struct EquipWashEvent
{
    int32_t equip_slot =0;
    int32_t wash_slot =0;
    int32_t quality =0;
    MAP_UINT32_UINT32 qualityMap;
};

//洗练事件
struct EquipWashQualityEvent
{
    MAP_UINT32_UINT32 qualityMap;
};

//点亮龙魂 EVENT_LIGHT_SOUL
struct LightSoulEvent
{
    int32_t grade = 0;
    int32_t stage = 0;
    int32_t soul_type = 0;
};

//神机装备穿戴事件
struct BestEQDressEvent
{
    int32_t cfgId;
    int32_t grade;  //评级
    int32_t quality; //品质
    int32_t stars;  //星级
};

//神机装备分解事件
struct BestEQDecomposeEvent
{
    int32_t cfgId;
};

//神机装备打造事件
struct BestEQStrongEvent
{
    int32_t cfgId;
    int32_t instId;
    int32_t grade;//评级
    int32_t quality; //品质
    int32_t stars;  //星级
};

//神机装备注灵事件
struct BestEQPourEvent
{
    int32_t slot;
    int32_t oldLv;
    int32_t newLv;
};


//神机装备槽位铭刻升级事件
struct BestEQBreakLvUpEvent
{
    int32_t slot;
    int32_t newLv;
};

//神机装备觉醒升级事件
struct BestEQAwakenLvUpEvent
{
    int32_t slot;
    int32_t newLv;
};
//完成神机装备前置任务
struct BestEQCmptTaskEvent
{
};

//活动开启
struct ActOpenEvent
{
    uint64_t actuid = 0;    //活动唯一ID
    uint32_t actid = 0;     //活动配置ID
    uint32_t acttype = 0;   //活动类型
    uint32_t zid = 0;       //区服ID
};
//活动关闭
struct ActCloseEvent
{
    uint64_t actuid = 0;        //活动唯一ID
    uint32_t actid = 0;         //活动配置ID
    uint32_t acttype = 0;       //活动类型
    uint32_t zid = 0;           //区服ID
};
//活动提前完成
struct ActPreFinishEvent
{
    uint64_t actuid = 0;         //活动唯一ID
    uint32_t actid = 0;         //活动配置ID
    uint32_t acttype = 0;       //活动类型
    uint32_t zid = 0;           //区服ID
    uint64_t pretime = 0;       //提前完成的时间
};


//采集
struct CollectEvent
{
    uint64_t monsid = 0;        //采集怪物ID
    uint32_t collectid = 0;     //采集ID
    uint64_t monsterCid = 0;
};

//结婚仙娃升级事件 EVENT_MARRY_CHILD_LV
struct MarryChildLvEvent
{
    int32_t childId = 0;
    int32_t lv=0;
};
//获得仙娃事件 EVENT_MARRY_CHILD_GET
struct MarryGetChildEvent
{
    int32_t childId = 0;
};
//表白等级提升事件 EVENT_MARRY_EXPRESS_LV
struct MarryExpressLvEvent
{
    int32_t lv =0;
};
//同心锁升级事件 EVENT_MARRY_LOCK_LV
struct MarryLockLvEvent
{
    int32_t lv = 0;
};

//表白事件 EVENT_MARRY_EXPRESS
struct MarryExpressEvent
{
    int32_t itemId = 0;
    int32_t num = 0;
};

//好友送礼 EVENT_RELATION_GIVE
struct RelationGiveEvent
{
    int32_t itemId = 0;
    int32_t num = 0;
};

//天机普
//EVENT_GOD_RELICS_FINISH,            //天机普任务完成
struct GodRelicsFinish
{
    int64_t id = 0;
};



//完成神机装备前置任务
struct MarryCmptTaskEvent
{
};
struct MarryCmptEvent
{
};
//加入战队 EVENT_JOIN_CLAN
struct ClanJoinEvent
{
    uint64_t clan_id = 0;
    uint64_t clan_type = 0; //1:3v3 2:5v5
};
//创建战队 EVENT_CLAN_CREATE
struct ClanCreateEvent
{
    uint64_t clan_id = 0;
    uint64_t clan_type = 0; //1:3v3 2:5v5
};

//EVENT_PT_LEVELUP,                   //仙阶升级
struct PTLevelEvent
{
    uint64_t cid = 0;	//玩家cid
    uint32_t level = 0;	//升级到的等级
};

//EVENT_MOUNT_OPEN_MOUNT_EGG_SLOT
struct MountOpenEggSlotEvent
{
    uint64_t cid = 0;	//玩家cid
    uint32_t slot = 0;	//
};

//EVENT_PET_OPEN_EGG_SLOT,            //宠物蛋孵化槽位
struct PetOpenEggSlotEvent
{
    uint64_t cid = 0;	//玩家cid
    uint32_t slot = 0;	//
};

// EVENT_DRAGONSOUL_DRESS,				//装备穿戴龙魂
struct DressDragonSoulEvent
{
    MAP_UINT32_UINT32 wearQualityMap;
};

//EVENT_DRAGONSOUL_ACTIVE_SLOT,		//激活龙魂核心孔
struct ActiveDragonSoulSlot
{
    uint64_t cid = 0;	//玩家cid
    uint32_t slot = 0;	//
};

//EVENT_HANDBOOK_BEAST_ACTIVE,        //激活图鉴神兽
struct HandeBookBeastActiveEvent
{
    uint64_t id = 0;
};

//EVENT_ANCIENT_LEVELUP,              //上古神灵
struct AncientLevelUpEvent
{
    uint64_t id = 0;
    MAP_UINT32_UINT32 lvMap;
    uint32_t maxSlot = 0;
};

struct MagicSumChangeEvent
{
    uint64_t sum = 0;
};

struct VersionIdChange
{
    int32_t versionId = 0;
};

//EVENT_WELFARE_QIFU,                 //福利祈福
struct WelfareQifuEvent
{
    int32_t type = 0;
};

//EVENT_FACTION_TRANS,                //公会传功
struct FactionTransEvent
{
    int32_t count = 0;
};


//EVENT_WASH_PARTY,                   //瑶池
struct WashPartyEvent
{

};
//完成神机装备前置任务
struct TurnCmptTaskEvent
{
};

//完成战魂装备前置任务
struct SoulCmptTaskEvent
{
};

#pragma pack(pop)