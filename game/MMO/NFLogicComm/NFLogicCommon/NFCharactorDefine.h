// -------------------------------------------------------------------------
//    @FileName         :    NFCharactorDefine.h
//    @Author           :    gaoyi
//    @Date             :    23-10-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFCharactorDefine
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFGameCommon/NFPoint3.h"
#include "NFGameCommon/NFPoint2.h"

#pragma pack (push)
#pragma pack(1)

using CharIDType = uint64_t;

#define MAX_CHARACTER_SINGLERANGE  30      //视野
#define MAX_CHARACTER_SINGLERANGE_SQUARE 900
//grid count (100-200)*(100-200)
#define GRID_LENGTH 10   //和视野是1:3的关系
#define F_TEN_THOUSAND 10000.0f
#define F_THOUSAND 1000.0f
#define F_ONE_HANDURD 100.0f
#define TEN_THOUSAND 10000
#define ONE_THOUSAND 1000
#define ONE_HANDURD 100
#define MAX_KILLING_VALUE 250  //杀戮值上限

//
struct HitWallParam
{
    float         tangentDir;			// �ƶ���ǽ���߷���
    float         hitLength;			// �ƶ���ǽʣ�����
    float         hitPos[3];			// ��ǽ��λ��
    unsigned int  hitRef;				// ����λ��PolyRef
    unsigned int* pathPolys;			// ������poly
    int           polyCount;			// ������poly����

    void Clear()
    {
        tangentDir = 0.0f;
        hitLength = 0.0f;
        hitPos[0] = 0.0f;
        hitPos[1] = 0.0f;
        hitPos[2] = 0.0f;
        hitRef    = 0;
        pathPolys = nullptr;
        polyCount = 0;
    }

    HitWallParam()
    {
        Clear();
    }
};

using VEC_POINT3 = std::vector<NFPoint3<float>>;

using VEC_FLAGS = std::vector<int>;


//生物类型
enum CreatureType
{
    CREATURE_NONE = 0,
    CREATURE_PLAYER,    //玩家
    CREATURE_MONSTER,   //怪物
    CREATURE_DROP,		//掉落
    CREATURE_REBOT,     //机器人
    CREATURE_PET,		//宠物
    CREATURE_MAX
};

enum PartType
{
    PART_NONE = 0,
    PART_VIP,				//VIP (VIP里面有权限,权限不存数据库，各模块加载要再次添加权限。所以放在前面)
    PART_MOVE,				//移动
    PART_FUNCTIONUNLOCK,	//功能解锁
    PART_PACKAGE,			//背包
    PART_GROW,				//养成
    PART_MINI,				//杂项模块
    PART_CHAT,				//聊天
    PART_EQUIP,				//装备模块
    PART_SKILL,				//技能
    PART_BUFF,				//buff
    PART_FACADE,            //外观
    PART_DUP,				//副本
    PART_MINI_ACTIVITY,     //杂项活动
    PART_BOSS,				//boss
    PART_MISSION,			//任务
    PART_MOUNT,             //坐骑
    PART_MALL,				//商城
    PART_DEITY,            //天神
    PART_PET,			   //宠物
    PART_CONVOY,		   //护送
    PART_ARMOR,			   //玄功真甲
    PART_TITLE,            //title
    PART_ASSIST,		   //Boss助战
    PART_GODEVIL,		   //神魔
    PART_OCCUPATION,        //转职
    PART_PAY,			   //充值
    PART_FACTION,		   //帮派
    PART_PracticeTrue,		//修真
    PART_BESTEQ,		   //神机装备
    PART_COLLECT,		   //采集
    PART_ACHIEVEMENT,      //成就系统
    PART_PVP,			   //PVP
    PART_ANCIENT,		   //上古神灵
    PART_ENCYLOPEDIA,      //藏经阁
    PART_MARRY,			   //结婚
    PART_GVBPData,			//神谷战场
    PART_RANK,              //排行榜
    PART_PersonalShop,     //个人商店
    PART_DRAGONSOUL,        //龙魂
    PART_WELFARE,           //福利
    PART_DAILYWELFARE,      //每日特惠
    PART_GIFT,				//礼包
    PART_FINDTREASURE,      //真龙寻宝
    PART_FEST,				//节日活动
    PART_DRAGON,			//幻世烛龙
    PART_STAR,              //灭星辰
    PART_GMA,				//神元区域
    PART_TURN,				//神体
    PART_MAX,
};

//角色信息事件
enum class ERoleEvent
{
    None = 0,		//
    Login = 1,		//登录
    Logout = 2,		//登出
    Disconnect = 3,	//断线
    Reconnect = 4,	//重连
    Facade = 5,		//外观
    Level = 6,		//等级
    Fight = 7,		//战力
    VipLevel = 8,	//vip等级
    Name = 9,		//改名字
    Hp = 10,		//血量
    MaxHp = 11,		//最大血量
    ChgScene = 12,	//改变场景
    Faction = 13,	//帮派
    PTStage = 14,  //修真
    Head = 15,	    //头像
    YaoTa = 16,		//九层妖塔最高副本id
    Max				//
};
//客户端提示、飘字等显示信息类型
enum class EClientShowType
{
    Exp = 1,		//经验
    Drop = 2,		//掉落(前端掉落飘入背包的效果), 现在没用到了
    Virtual = 3,	//虚拟物品提示
    Dispute = 4,	//纷争之地贡献提示
    Help = 5,		//助攻提示
    WarScore = 6,	//工会战积分限时
    UseContri = 7,	//工会可用贡献提示
    MonsExp = 8,	//打怪经验
};


//怪物职业
enum class EMonsProf
{
    Small = 1,	//小怪
    Elite = 2,	//精英
    Boss = 3,	//BOSS
};


//怪物 伤害加成类型
enum class EDamAddType
{
    None = 0,
    Boss = 1,
    Mons = 2,
};

//生物功能类型
enum class EFuncType
{
    Mons = 101,						//怪物
    Npc = 201,						//常驻NPC
    TaskNpc = 202,					//任务NPC
    Collect_Meat = 301,				//采集物-帮派晚宴中的肉
    Collect_BigCrystal = 302,		//采集物-蛮荒神兽大水晶
    Collect_SmallCrystal = 303,		//采集物-蛮荒神兽小水晶
    Collect_BigSecrit = 304,		//采集物-上古遗迹大秘宝
    Collect_SmallSecrit = 305,		//采集物-上古遗迹小秘宝
    Collect_TrunkTask = 306,		//采集物-主线任务
    Collect_BranchTask = 307,		//采集物-支线任务
    Collect_Hunt = 308,				//采集物-蓬莱探宝
    UseThing = 401,					//可使用物件
    DartCar = 501,					//镖车
    Transfer = 601,					//传送门
    Pet = 701,						//宠物
    PlotPet = 702,					//剧情宠物

};

//是否是采集功能
#define IS_COLLECT_FUNC(functype) (3 == ((functype) / 100) )


//怪物创建类型
enum class EMonsCreateType
{
    None = 0,
    Map = 1,	//地图怪(地图ID)
    Dup = 2,	//副本怪(副本ID)
    Activity = 3,	//活动怪(活动ID)
    Mission = 4,	//任务怪(任务ID)
    GM = 5,	//GM怪(通过GM刷新的怪)
    MapBoss = 6,	//野外BOSS
    WorldBoss = 7,	//世界BOSS
    FlushWorldBoss = 8,	//通过flash.xlsx 刷新的世界BOSS
    ShareBoss = 9,	//共享BOSS
    Dinner = 10,    //帮派晚宴
    Cake =11,		//蛋糕
    Banquet = 12,   //宴席
    FactionWar_Crystal = 13,	//帮派战水晶
    FactionWar_Tower = 14,		//帮派战防御塔
    FactionWar_Car = 15,		//帮派战战车
    CallSkill = 16,				//召唤技能
    Limit,
};

//怪物创建参数
struct MonsCreateParam
{
    //压制参数
    enum class ESuppress
    {
        none = 0,
        fight = 1,			//战力压制
        lev = 2,			//等级压制
        fight_lev = 3,		//战力、等级压制
        limit,
    };

    //-----------  怪物来源参数 ----------------------
    EMonsCreateType createType = EMonsCreateType::None;	//怪物创建类型
    int64_t createTypeVal = 0;							//创建类型值

    //------------- 专属怪参数 --------------------
    uint64_t exclusiveCid = 0;							//归属者cid，怪物属于谁,用于专属怪
    uint32_t survivalTime = 0;							//生存时间，怪物创建多久之后消失,单位：秒，用于专属怪,默认是五分钟

    //-------------- 经验加成(万分比) -----------------
    int32_t expAdd = 0;									//怪物死亡时，玩家增加的经验加成(目前用于无限狩猎副本中的怪)

    //------------- 怪物组ID 参数 --------------------
    int32_t groupId = 0;

    //------------- 怪物等级 参数 ---------------------
    int32_t level = 0;									//用于动态等级，大于0才生效


    //------------- 怪物掉落 参数 ---------------------
    int32_t dropType = 0;			//掉落类型，对应 monster.xlsx表格 dropType 字段
    int32_t showType = 0;			//掉落显示类型 对应 monster.xlsx表格 ifMultiple 字段

    //------------- 怪物副本掉落数据 参数，仅针对副本怪有效 ---------------------
    int8_t dupDropType = 0;				//副本掉落类型 详见 DuplicateDefine.h 文件中 EDupMonsDropType 枚举
    std::vector<uint64_t> vecDupDrop;				//副本掉落数据

    // ----------- 怪物朝向坐标点，目前只有野外场景的NPC有朝向(flash.xlsx表中刷出的NPC)
    NFPoint2<float> dirpos; //朝向坐标

    //------------- 怪物AI路径ID -------------------
    uint64_t aipathId = 0;	//ai 路径ID, 有路径ID的怪出生点需要在 路径的起始点位置

    //------------------ 自动适配怪物属性标记 --------------------------
    //是否使用自动适配怪物属性标记，根据配置的数值ID是表格查找对应等级的怪物属性，如果不存在，则自动使用数值ID对应的最大等级的怪物属性
    bool suitableFlag = false;

    //flash表刷新时使用的point点
    int64_t pointId = 0;		//flash表刷新时使用的point点

    int32_t campId = 0;			//阵营ID

    //boss 专用
    int64_t layerKey = 0;		//boss层key
    uint64_t masterCid = 0;		//主人cid

    //伤害计算时的 战力压制、等级压制
    ESuppress sup = ESuppress::none;

    //TODO: 创建怪物需要的参数可以在下面添加


};

typedef enum
{
    TRANS_SAVEROLEDETAIL_STATE_INIT = 0,
    TRANS_SAVEROLEDETAIL_STATE_SAVING_ROLE = 1,
    TRANS_SAVEROLEDETAIL_FIN_OK,
} TRANS_SAVEROLEDETAIL_STATE;

typedef enum
{
    TRANS_SAVEROLEDETAIL_NORMAL = 1,
    TRANS_SAVEROLEDETAIL_LOGOUT = 2,
} TRANS_SAVEROLEDETAIL_REASON;

enum BattlePartType
{
    BATTLE_PART_NONE = 0,
    BATTLE_PART_MOVE,
    BATTLE_PART_MAX,
};

enum SnsPartType
{
    SNS_PART_NONE = 0,
    SNS_PART_RELATION,
    SNS_PART_MAX,
};

#pragma pack(pop)