// -------------------------------------------------------------------------
//    @FileName         :    NFGameFishDefine.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameFishDefine.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"

///////////////////fish define////////////////////////
#define MAX_FISH_ROOM_DESC_NUM 10
#define ONE_ROOM_MAX_GUN_NUM 10
#define MAX_GUN_CONFIG_DESC_NUM (MAX_FISH_ROOM_DESC_NUM*ONE_ROOM_MAX_GUN_NUM)


///////////////////fish define///////////////////////

#define NF_FISH_GAME_ID  101    //这个正式要通过配置

#define NF_GAMEFRAME_CMD_LEVELLIST 10
#define NF_FAMEFRAME_CMD_ROOMLIST  11

//#define NF_FISH_CMD_ENTER         4901
//#define NF_FISH_CMD_ENTER_RSP     4902

//#define NF_FISH_CMD_LEAVE         490300
//#define NF_FISH_CMD_LEAVE_RSP     490400


#define NF_FISH_CMD_GAMESTATUS         10001
#define NF_FISH_CMD_GAMESTATUS_RSP     10002

#define NF_FISH_CMD_FISHES_RSP    10004

#define NF_FISH_CMD_SHOOTBULLET     10005
#define NF_FISH_CMD_SHOOTBULLET_RSP 10006

#define NF_FISH_CMD_HITFISH         10007
#define NF_FISH_CMD_KILLFISH        10008

#define NF_FISH_CMD_LOCKFISH        10009
#define NF_FISH_CMD_LOCKFISH_RSP    10010

#define NF_FISH_CMD_LOCKONOFF       10011
#define NF_FISH_CMD_LOCKONOFF_RSP   10012

#define NF_FISH_CMD_AUTOSHOOT       10013
#define NF_FISH_CMD_AUTOSHOOT_RSP   10014

#define NF_FISH_CMD_BULLETSPEED     10015
#define NF_FISH_CMD_BULLETSPEED_RSP 10016

//#define NF_FISH_CMD_DESKINFO        10017
//#define NF_FISH_CMD_DESKINFO_RSP    10018

#define NF_FISH_CMD_CHANGECANNON     10019
#define NF_FISH_CMD_CHANGECANNON_RSP 10020

#define NF_FISH_CMD_USERMONEY_RSP    10022

#define NF_FISH_CMD_CHANGESCENE_RSP  10024 //切换场景

#define NF_FISH_CMD_FREEZEFISHES_RSP 10026

#define NF_FISH_CMD_USERENTERDESK_RSP 10028

#define NF_FISH_CMD_USERLEAVEDESK_RSP 10030

#define NF_FISH_CMD_DOUBLEGUNONOFF_RSP 10032

#define NF_FISH_CMD_PROMPTINFO_RSP     10034   //下发提示信息


#define NF_FISH_CMD_CREATEDIANCICANNON_RSP    10036  //创键电磁炮
#define NF_FISH_CMD_DIANCICANNONAIM_REQ       10037  //电磁炮瞄准
#define NF_FISH_CMD_DIANCICANNONAIM_RSP       10038  //电磁炮瞄准广播
#define NF_FISH_CMD_DIANCICANNONSHOOT_REQ     10039  //电磁炮发射
#define NF_FISH_CMD_DIANCICANNONSHOOT_RSP     10040  //电磁炮发射广播
#define NF_FISH_CMD_DIANCICANNONHITFISH_REQ   10041  //电磁炮攻击鱼上传
#define NF_FISH_CMD_DIANCICANNONDESTORY_RSP   10042  //电磁炮销毁
											  
#define NF_FISH_CMD_CREATEZUANTOU_RSP         10046   //创建钻头蟹钻头
#define NF_FISH_CMD_ZUANTOUAIM_REQ            10047   //钻头瞄准
#define NF_FISH_CMD_ZUANTOUAIM_RSP            10048   //钻头瞄准广播
#define NF_FISH_CMD_ZUANTOUSHOOT_REQ          10049   //发射钻头
#define NF_FISH_CMD_ZUANTOUSHOOT_RSP          10050   //发射钻头广播
#define NF_FISH_CMD_ZUANTOUHITFISH_REQ        10051   //钻头击中鱼上传
#define NF_FISH_CMD_ZUANTOUBOMB_RSP           10052   //钻头爆炸
											  
#define NF_FISH_CMD_CREATESOMEZUANTOU_RSP     10060   //创建连环钻头
#define NF_FISH_CMD_SOMEZUANTOUSHOOT_RSP      10062   //发射钻头
#define NF_FISH_CMD_SOMEZUANTOUHITFISH_REQ    10064   //钻头击中鱼上传
#define NF_FISH_CMD_SOMEZUANTOBOMB_RSP        10066   //连环钻头爆炸
											  
#define NF_FISH_CMD_CREATEFIRESTORM_RSP       10070   //创建烈焰风爆
#define NF_FISH_CMD_DESTORYFIRESTORM_RSP      10072   //销毁烈焰风爆
#define NF_FISH_CMD_FIRESTORMSTATUS_RSP       10074   //烈焰风爆状态
#define NF_FISH_CMD_FIRESTORMSCORE_RSP        10076   //烈焰风爆分数
											  
#define NF_FISH_CMD_CREATEMADCOW_RSP          10080   //创建疯牛
#define NF_FISH_CMD_DISTORYMADCOW_RSP         10082   //销毁疯牛
#define NF_FISH_CMD_MADCOWSTATUS_RSP          10084   //疯牛状态
#define NF_FISH_CMD_MADCOWSCORE_RSP           10086   //疯牛分数

#define NF_FISH_CMD_CREATESERIALBOMBCRAB_RSP  10090   //创建连环炸弹螃蟹炸弹
#define NF_FISH_CMD_SERIALBOMBCRAB_BOMB_RSP   10092   //连环炸弹螃蟹爆炸一次
#define NF_FISH_CMD_DESTORYSERIALBOMBCRAB_RSP 10094   //销毁连环炸弹螃蟹

#define NF_FISH_CMD_HAIWANGCRABHITPART_REQ     10101   //海王螃蟹击中一个部位
#define NF_FISH_CMD_HAIWANGCRAB_KILLEDPART_RSP 10102   //海王螃蟹打死一个部位广播
#define NF_FISH_CMD_HAIWANGCRABKILLEDDEAD_RSP  10104   //海王螃蟹打死部位信息下发


#define NF_FISH_CMD_CREATEDELAYBOMB_RSP       10106   //创建延时炸弹
#define NF_FISH_CMD_DELAYBOMB_BOMB_RSP        10108   //延时炸弹爆炸

//#define NF_FISH_CMD_USERDISCONNECTDESK_RSP    10110







enum ePromptInfoType
{
	eInfoType_YuChao_Come  = 0,        //鱼潮
	eInfoType_FishTip_Come = 1,        //提示鱼
};

enum eChangeSceneType
{
	eType_Null = 0,
	eType_WaveTide = 1,        //切场景波浪
	eInfoType_FishOutScne = 2, //鱼快速移除屏幕
	eInfoType_ChangeSceneBG = 3, //切换场景的背景图
};


//#########################################################################
//
//#########################################################################
// 获取捕鱼玩家特殊配置

////控制类型 0不控制，1控正值，2控负值
//enum enFishCaptureCtrlType
//{
//	en_FishCtrlType_no = 0, //不控制
//	en_FishCtrlType_ZhenUp, //控正值
//	en_FishCtrlType_FuDown  //控负值
//};

struct FishConfigGameidRoomidCombineHashKey
{
    FishConfigGameidRoomidCombineHashKey()
    {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        }
        else {
            ResumeInit();
        }
    }
    int CreateInit()
    {
        m_gameId=0;
        m_roomId=0;
        return 0;
    }
    int ResumeInit()
    {
        return 0;
    }
    int64_t m_gameId;
    int64_t m_roomId;
    bool operator==(const FishConfigGameidRoomidCombineHashKey& data) const
    {
        return m_gameId==data.m_gameId && m_roomId==data.m_roomId;
    }
};

namespace std
{
    template<>
    struct hash<FishConfigGameidRoomidCombineHashKey>
    {
        size_t operator()(const FishConfigGameidRoomidCombineHashKey& data) const
        {
            return NFHash::hash_combine(data.m_gameId,data.m_roomId);
        }
    };
}





