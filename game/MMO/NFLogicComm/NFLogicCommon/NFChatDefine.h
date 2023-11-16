// -------------------------------------------------------------------------
//    @FileName         :    NFChatDefine.h
//    @Author           :    gaoyi
//    @Date             :    23-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFChatDefine
//
// -------------------------------------------------------------------------

#pragma once

#include "Item/NFItem.h"

/*--------------------------------------------
*	系统传闻广播类型定义
-------------------------------------------*/

enum BROADCAST_TYPE
{
    BT_NONE = -1,

    BT_ACTIVE_GODRELICS = 151, //xxx成功修复天机谱xxx，永久激活了xxx被动技能，战力暴涨xxx【天机谱】
};


/*--------------------------------------------
*	传闻或各系统广播消息所需发送数据结构体定义
-------------------------------------------*/
struct SystemChatMsgData
{
    std::vector<proto_ff::RolePlayerMiniInfo> players;		//玩家基本数据
    std::vector<std::string> 				  text;				//突出显示的文本数据，例如：XXX副本 XXX怪物 XX工会 XX杀等等
    std::vector<uint64_t>					  params;			//数字参数：颜色等级，工会id 副本id 等数据都按顺序填充到这个字段
    VEC_ITEM_PROTO_EX						  items;
    //CTODO后续继续扩展

    SystemChatMsgData()
    {
        players.clear();
        text.clear();
        params.clear();
        items.clear();
    }

    void Clear()
    {
        players.clear();
        text.clear();
        params.clear();
        items.clear();
    }
};

const uint32_t MAX_OFFLINE_MSG = 15;   //每人最多保存20个离线私聊记录
const uint32_t CHAT_WORLD_USE_GOODS_ID = 180109003;	//小喇叭
const uint32_t CHAT_WORLD_USE_HORN_GOODS_ID = 180109004;//大喇叭

const uint32_t CHAT_WORLD_CD_TIME = 10;
const uint32_t CHAT_OTHER_CD_TIME = 5;



/////////////////////////////////  特殊事件的跑马灯  /////////////////////////////////////////

enum EChatSpecialEvent
{
    EChatSpecialEvent_EquipRefine = 4,	//装备精炼
    EChatSpecialEvent_ArenaRank = 5,	//竞技场排名
    EChatSpecialEvent_ComposStone = 6,	//宝石合成
    EChatSpecialEvent_UnionHall = 7,	//工会大厅等级
};