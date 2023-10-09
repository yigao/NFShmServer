// -------------------------------------------------------------------------
//    @FileName         :    RelationDefine.h
//    @Author           :    gaoyi
//    @Date             :    23-3-20
//    @Email			:    445267987@qq.com
//    @Module           :    RelationDefine
//
// -------------------------------------------------------------------------

#pragma once


#include <stdint.h>
#include <map>
#include <vector>
#include <set>
#include <queue>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4512) //assignment operator could not be generated
#pragma warning(disable:4244) //conversion from '__int64' to 'int', possible loss of data
#pragma warning(disable:4267) //conversion from 'size_t' to 'int', possible loss of data
#pragma warning(disable:4127) //conditional expression is constant
#endif

//#define LOAD_RELATION_ONLINE	//登录加载开关
#define MAX_CLOSENESS_VALUE  199999	//亲密度最大值


// 好友关系分组索引
enum SYSTEM_GROUP_INDEX
{
//----------------------------------------------更新类型-------------数据类型-------是否存库----------添加方式

    GROUP_FRIEND= 0,	//好友              在线状态实时更新           双向           存库            客户端添加
    GROUP_BLACK	= 1,    //黑名单            打开界面时更新             单向           存库            客户端添加
    GROUP_HATE	= 2,    //仇人              打开界面时更新             单向           存库            服务器添加
    GROUP_RECENT= 3,    //最近联系人        打开界面时更新		      双向			 不存库          服务器添加
    GROUP_APPLY = 4,    //申请好友列表      在线状态实时更新           单向           存库             客户端添加
    GROUP_SHIELD = 5,   //屏蔽发言列表      不更新到客户端             单向           不存库           客户端添加
    GROUP_MAX	= 6,    //最大值
    GROUP_ERROR	= 9999, //错误值
};

// 好友数据同步类型
enum RELATION_SYNC_TYPE
{
    RELATION_SYNC_TYPE_EACHOTHER = 0,   //相互同步
    RELATION_SYNC_TYPE_TO_ACTIVE = 1,   //只同步给主动方
    RELATION_SYNC_TYPE_TO_PASSIVE = 2,  //只同步给被动方
};


enum RELATION_OPERATOR_TYPE
{
    RELATION_APPLY = 1, //申请
    RELATION_PASS = 2, //通过
    RELATION_PASSIVE_PASS = 3, //被动通过
    RELATION_DELETE = 4, //删除
};


enum RELATION_RECENT_TYPE
{
    RELATION_RECENT_CHAT = 1,	//聊天关系的
    RELATION_RECENT_TRADE = 2,	//交易关系的
    RELATION_RECENT_TEAM = 3,	//组队关系的
    RELATION_RECENT_SYSTEM = 4, //系统推荐
};

//增加亲密度类型
enum RELATION_ADD_CLOSENESS_TYPE
{
    RELATION_CLOSENESS_NONE		= 0,    //空
    RELATION_CLOSENESS_PASSDUP	= 1,	//通关副本
    RELATION_CLOSENESS_VIPBOSS	= 2,	//击杀VIP BOSS
    RELATION_CLOSENESS_GIFT		= 3,	//送礼
    RELATION_CLOSENESS_MAXTYPE	= 4,	//最大值
};

//中心服通知逻辑服类型
enum RELATION_NOTICE_LOGIC_TYPE
{
    RELATION_NOTICE_LOGIC_ADDFRIEND = 1,	//添加好友

};


//好友送礼配置  货币类型
enum GIFT_MONEY_TYPE
{
    GIFT_MONEY_TYPE_DIAMOND = 1,		//钻石
    GIFT_MONEY_TYPE_BIND_DIAMOND = 2,	//绑钻
};

//好友送礼配置  送礼类型
enum GIFT_SEND_TYPE
{
    GIFT_SEND_TYPE_GET = 0,			//收礼
    GIFT_SEND_TYPE_GIVE = 1,		//送礼
};



enum RELATION_OPERATE_TYPE
{
    RELATION_OPERATE_TYPE_NONE					= 0,
    RELATION_OPERATE_TYPE_LOAD					= 1,			//加载
    RELATION_OPERATE_TYPE_APPLY					= 2,			//申请添加好友
    RELATION_OPERATE_TYPE_AGREE_OR_REFUSE		= 3,			//同意/拒绝添加
    RELATION_OPERATE_TYPE_AGREE_ONEKEY			= 4,			//一键同意添加
    RELATION_OPERATE_TYPE_DELETE				= 5,			//删除
    RELATION_OPERATE_TYPE_INFO					= 6,			//请求好友信息
    RELATION_OPERATE_TYPE_RECENT				= 7,			//添加到临时列表
    RELATION_OPERATE_TYPE_QUERY					= 8,			//请求角色信息(from queryMgr)
    RELATION_OPERATE_TYPE_ADDBLACK				= 9,            //请求添加黑名单
    RELATION_OPERATE_TYPE_GIFT					= 10,           //请求送礼
    RELATION_OPERATE_TYPE_LIMIT,
};

const uint32_t MAX_APPLY_SIZE = 50; //最大申请者数量50
const uint32_t MAX_FRIEND_SIZE = 100; //最大好友人数上限100
const uint32_t MAX_BLACK_SIZE = 50; //最大黑名单个数
const uint32_t MAX_RECENT_SIZE = 50; //最近联系人50
const uint32_t MAX_HATE_SIZE = 50;	//仇恨列表人数
const uint32_t MAX_SHIELD_SIZE = 100; //最大屏蔽发言数量
const uint32_t MAX_GIFT_RECORD_COUNT = 50; //最大礼物记录数量

const uint32_t RELATION_CD_TIME = 5;  //打开好友推荐面板冷却时间
const int32_t RELATION_LEVEL_INTERVAL = 3; //好友推荐等级差距（包括）

const uint32_t RELATION_RECOMMEND_MAX_PLAYER = 6;  //好友推荐最多人数

const uint32_t RELATION_PASS_DUP_CLOSENESS_LIMIT = 5; //每天5点
const uint32_t RELATION_KLLL_MONSTER_CLOSENESS_LIMIT = 50; //每天50点


const uint32_t RELATION_ADD_CLOSENESS_PASS_DUP = 30; // 好友组队通关副本加1个亲密度
const uint32_t RELATION_ADD_CLOSENESS_MAX_ONEDAY = 150; //每天最多增加的亲密度

const uint32_t RELATION_ROBOT_FRIEND_MAXID = 100000; //机器人好友id上限

