// -------------------------------------------------------------------------
//    @FileName         :    NFIFishAlgoModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFIFishAlgoModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFMessageDefine/ResMeta_s.h"
#include "NFComm/NFMessageDefine/FishResMeta_s.h"

// 算法数据类型
enum eAlgoDataType 
{
    DAlgoType_RealUser = 0,     // 真实充值的玩家
    DAlgoType_FreeUser,         // 免费赠送的玩家
    DAlgoType_Robot,            // 机器人
    DAlgoType_Total
};

// 算法类型
enum	E_ALGORITHM_TYPE
{
    E_ALGORITHM_TYPE_FISH			    = 0,    // 捕鱼游戏算法类型
    E_ALGORITHM_TYPE_CHARGE_POINT	    = 1,    // 押分游戏算法类型
    E_ALGORITHM_TYPE_CONECTED		    = 2,    // 连线机游戏算法类型
    E_ALGORITHM_TYPE_CHESS			    = 3,    // 棋牌游戏算法类型
    E_ALGORITHM_TYPE_JLXB_LOT		    = 4,    // 金龙献宝彩金更新回写数据库
    E_ALGORITHM_TYPE_LINE_GAME_CTRL     = 5,    // 连线类游戏系统控制
    E_ALGORITHM_TYPE_LHDB_POINT         = 6,    // 连环夺宝连环夺宝玩家收入回写数据库
    E_ALGORITHM_TYPE_LHDB_REWARD_LOG    = 7,    // 连环夺宝玩家中奖日志回写数据库
    E_ALGORITHM_TYPE_LHDB_USER_STATE    = 8,	// 连环夺宝用户状态
    E_ALGORITHM_TYPE_BAIREN             = 9,    // 百人回写
    E_ALGORITHM_TYPE_LHDB_ROOM_STATUS   = 10,	// 连环夺宝房间控制状态回写
    E_ALGORITHM_TYPE_WXHH_LOT           = 11,   // 金龙献宝彩金更新回写数据库

    E_ALGORITHM_TYPE_CARD_ROOM_SCORE    = 100,  // 开房卡回写用户积分

    E_ALGORITHM_TYPE_BOUTIQUE_GAME_SCORE= 200,  // 精品游戏回写用户积分增减、赢局

    E_ALGORITHM_TYPE_MAX
};

//算法修改类型
enum	E_ALGORITHM_MODIFY_TYPE
{
    E_ALGORITHM_MODIFY_TYPE_SWICH  = 0,    //只切换算法
    E_ALGORITHM_MODIFY_TYPE_UPDATE = 1,    //只修改了算法
    E_ALGORITHM_MODIFY_TYPE_TOTAL  = 2,    //修改了整个桌子的控制信息

    E_ALGORITHM_MODIFY_TYPE_MAX
};

enum eFishAlgoTypeInter
{
    //FishAlgoTypeInter_3ChiFang=0,
    FishAlgoTypeInter_RMB=0,
    FishAlgoTypeInter_Rand,  //随机算法
    FishAlgoTypeInter_Total  //总个数
};

//控制类型 0不控制，1控正值，2控负值
enum enFishCaptureCtrlType {
    en_FishCtrlType_no = 0, //不控制
    en_FishCtrlType_ZhenUp, //控正值
    en_FishCtrlType_FuDown  //控负值
};

/*

[QianCheng]

///初始鱼奖池  个数

///鱼类型ID：表示被捕获的海鱼的ID，具体参考FishRate.ini



///----------------鱼ID，初始个数

///小黄鱼

InitPoolCount_1  =   1 ,    0

*/

struct SFishInitPool {
    std::vector<std::vector<int> > m_vectInitPoolCount;  //鱼ID，初始个数
};



#define MAX_CANNON_COUNT            10                                  //炮台等级最大个数

//吃平放算法状态  顺序不能改变

enum enAlgorithmStatus 
{
    enAlgoStatus_Chi3 = 0,  //三级吃
    enAlgoStatus_Chi2,    //二级吃
    enAlgoStatus_Chi1,    //一级吃
    enAlgoStatus_Ping,    //平
    enAlgoStatus_Fang1,   //一级放
    enAlgoStatus_Fang2,   //二级放
    enAlgoStatus_Fang3,   //三级放
    enAlgoStatus_Total
};

//GM类型
enum enGmCtrlType {
    GMCTRL_ALLCTRL = 0, //总控
    GMCTRL_SINGLE,      //单控
    GMCTRL_TOTAL
};

//算法控制信息
typedef struct tagFishAlgoCtrlInfo {
    int iDrawRate;                //抽水率（万分比）
    int iNanduSpec;               //难度等级
    int iCurChang;                //当前场
    int iAlgoRangeC3;             //三级吃范围值
    int iAlgoRangeC2;             //二级吃范围值
    int iAlgoRangeC1;             //一级吃范围值
    int iAlgoRangeF1;             //一级放范围值
    int iAlgoRangeF2;             //二级放范围值
    int iAlgoRangeF3;             //三级放范围值

    tagFishAlgoCtrlInfo() {
        memset(this, 0, sizeof(*this));
    }
} TFishAlgoCtrlInfo;

//桌子表吃放类型

enum enCFTableType {
    enCFTable_Chi = 0, //吃表
    enCFTable_Fang,  //放表
    enCFTable_Total
};



//桌位吃放表类型

enum enCFSeatTableType {

    enCFSEATTable_Chi3 = 0, //三级吃

    enCFSEATTable_Chi2, //二级吃

    enCFSEATTable_Chi1, //一级吃

    enCFSEATTable_Ping, //平

    enCFSEATTable_Fang1, //一级放

    enCFSEATTable_Fang2, //二级放

    enCFSEATTable_Fang3, //三级放

    enCFSEATTable_Total

};

/*

///座位算法配置

///说明：

///  a=玩家所得总和

///  b=玩家消耗总和  , b-a系统目前暂时利润

///  c=系统抽水率,百分比(一般设置为97-101)

///  y=b*c-a ,运营承受范围和控制吃放表的条件控制

///  f=奖池积分

///  算法说明：座位算法





///座位算法功能开关(0关，1开)

SeatCtrlIsOpen = 1





///座位换挡区间范围配置

///切值流水(倍数)：等于最大炮的多少倍

///C3(倍数)：等于切值流水多少倍

///  y<C3 三级吃  , [C3,C2) 二级吃,  [C2,C1) 一级吃, [C1,F1]平区间 , (F1,F2] 一级放  , (F2,F3] 二级放 , y>F3 三级放

///----------------------------切值流水(倍数)  ,  [  C3(倍数) ,  C2(倍数)  ,  C1(倍数)  ,  F1(倍数)  , F2(倍数) , F3(倍数) ]

///默认难度范围

///屌丝A配置

SeatDangRange_Def_A     =        5             ,       -60    ,    -32     ,    -10     ,     10     ,   32     ,  60

///充值B配置

SeatDangRange_Def_B     =        5             ,       -60    ,    -32     ,    -10     ,     10     ,   32     ,  60

///机器人配置

SeatDangRange_Def_Robot =        5             ,       -60    ,    -32     ,    -10     ,     10     ,   32     ,  60





///桌子独立难度---（  桌子号 , 切值流水(倍数)  ,  [  C3(倍数) ,  C2(倍数)  ,  C1(倍数)  ,  F1(倍数)  , F2(倍数) , F3(倍数) ] ）

SeatDangRange_B_1  =     0   ,   5             ,       -60    ,    -32     ,    -10     ,     10     ,   32     ,  60





///当总押 或 总得 达到一定的值之后 自动进行清理数据---(达到平衡流水 = 7*1000*切值流水),程序自动乘以切值流水

ClearDataMaxVal = 7000



///当y值大于三级放多少倍时候 自动清理数据 , 0是默认不处理

ClearDataFangCondation = 3



///当y值小于三级吃多少倍时候 自动清理数据 , 0是默认不处理

ClearDataChiCondation  = 3

*/

class NFIFishAlgoModule : public NFIDynamicModule {
public:
    NFIFishAlgoModule(NFIPluginManager *p) : NFIDynamicModule(p) {

    }

    virtual ~NFIFishAlgoModule() {

    }

    virtual int CreateFishAlgoTypeLogic(eFishAlgoTypeInter procAlgoType) = 0;
    virtual void DelFishAlgoTypeLogic(int algoObjId) = 0;
    virtual int  Init(int algoObjId, int iGameID, int iRoomID, int iDeskID, int iTotalFishKind, int iTotalConnonCount, int iMaxConnonVal, int iRoomLevel) = 0;
    virtual void GameStart(int algoObjId) = 0;
    virtual void GameEnd(int algoObjId) = 0;
    //游戏房间启动通知
    virtual bool OnRoomStartNotify(int algoObjId) = 0;
    virtual void OnBaseTime(int algoObjId) = 0;
    //分配打击次数
    virtual bool GetAlgoHitCountCfg(int algoObjId, eAlgoDataType dataType,int iConnonIndex,uint32_t btFishKind, uint32_t btFishKindGroup1,int nBaseMul,int& iHitCountCfg,double& dbConnonHitPool) = 0;
    //总发射炮弹富贵豆
    virtual long long GetTableTotalShootMoney(int algoObjId, eAlgoDataType dataType) = 0;
    virtual void    SetTableTotalShootMoney(int algoObjId, eAlgoDataType dataType,long long iTotalShootMoney) = 0;
    virtual bool    AddTableTotalShootMoney(int algoObjId, eAlgoDataType dataType,double dbShootMoney) = 0;
    virtual bool    SubTableTotalShootMoney(int algoObjId, eAlgoDataType dataType,double dbShootMoney) = 0;

    //总捕获富贵豆
    virtual long long GetTableTotalCaptureMoney(int algoObjId, eAlgoDataType dataType) = 0;
    virtual void    SetTableTotalCaptureMoney(int algoObjId, eAlgoDataType dataType,long long iTotalCaptureMoney) = 0;
    virtual bool    AddTableTotalCaptureMoney(int algoObjId, eAlgoDataType dataType,double dbCaptureMoney) = 0;

    //获取条件控制值Y
    virtual int64_t GetCtrlAlgoY(int algoObjId, eAlgoDataType dataType) = 0;
    //设置抽水率和难度
    virtual void SetDrawRateNandu(int algoObjId, eAlgoDataType dataType, double dbParamC,int iNanduSpec) = 0;
    //获取算法控制信息
    virtual tagFishAlgoCtrlInfo GetAlgoCtrlInfo(int algoObjId, eAlgoDataType dataType) = 0;
    //更新桌子游戏实时算法数据信息
    //(usAlgorithmType, 表示算法类型，这个参考(GameDef.h)枚举: E_ALGORITHM_TYPE)
    //(usModifyFlag,表示算法没有修改，这个参考(GameDef.h)枚举: E_ALGORITHM_MODIFY_TYPE)
    virtual int UpdateDeskRealtimeData(int algoObjId, void *pDeskRealTimeData, unsigned short usAlgorithmType, unsigned short usModifyFlag) = 0;
    //获取算法类型
    virtual eFishAlgoTypeInter GetDataFishAlgoType(int algoObjId, eAlgoDataType dataType) = 0;
    //概率算法 获取概率
    virtual bool GetDataFishRandAlgoRate(int algoObjId, eAlgoDataType dataType,int iCannonIndex,int nBaseMul,double& dbRate) = 0;

    virtual void UpdateYValueB(int algoObjId, int64_t llGMWinMoney) = 0;

	virtual void ReadAllAlgoData(int algoObjId) = 0;

    virtual int ClearJiangChi(int algoObjId) = 0;
    virtual int ChangeJiangChi(int algoObjId, int64_t jiangchi) = 0;
};
