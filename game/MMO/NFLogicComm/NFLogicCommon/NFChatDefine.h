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
    BT_OCCUPATION_SUCCSS = 152, //天地变色，风起云涌！xxx完成了转职试炼！
    BT_OCCUPATION_FLY_SUCCSS = 153, //天地变色，风起云涌！xxx完成了飞升试炼！
    //好友
    BT_FRIEND_SEND_FLOWER = 154, //xxx被xxx的魅力倾倒，赠送了xxx倾慕之情溢满全世界
    //时装
    BT_FASHION_ACTIVE = 159, //激活橙色以上时装
    BT_CONGRATULATION_ADD_TITLE = 160, 		//恭喜XXX玩家激活XXX称号
    BT_WING_ACTIVE_SOUL = 182,					//恭喜xxx成功激活羽翼器魂，战力暴涨！
    BT_WING_ACTIVE_FANTASY = 183,					//恭喜xxx激活了xxx，战力暴涨xxx！
    BT_TREASURE_ACTIVE_SOUL = 184,				//恭喜xxx成功激活宝物器魂，战力暴涨！
    BT_TREASURE_ACTIVE_FANTASY = 185,				//恭喜xxx激活了xxx，战力暴涨xxx！
    BT_ARTIFACT_ACTIVE_SOUL = 186,				//恭喜xxx成功激活神器器魂，战力暴涨！
    BT_ARTIFACT_ACTIVE_FANTASY = 187,				//x恭喜xxx激活了xxx，战力暴涨xxx！
    BT_PARTNER_ACTIVE_SOUL = 188,				//恭喜xxx成功激活剑灵器魂，战力暴涨！
    BT_PARTNER_ACTIVE_FANTASY = 189,				//恭喜xxx激活了xxx，战力暴涨xxx！
    //天神
    BT_DEITY_ACTIVE = 192,              //恭喜xxx激活了xxx，战力暴涨xxx！
    BT_DEITY_FLY = 193,                  //xxx成功将xxx进阶至xxx，外观进化，属性增强 !【我要归真】
    BT_DEITY_ARTIFACT_STAR = 194,          //xxx将天神神器xxx升至xxx星，提高了强化和附灵上限，战力暴涨！
    BY_DEITY_ACTIVE_ARTIFACT= 195,        //xxx激活了天神神器xxx，战力暴涨！可喜可贺！
    BT_DEITY_ACTIVE_ARTIFACT_FANTASY = 196,        //xxx激活了天神神器外观xxx，战力暴涨！可喜可贺！
    BT_DEITY_SHENGHE_BREAK = 197,         //恭喜xxx成功将天神xxx的神核突破到xxx级！【前往化神】
    BT_DEITY_ACTIVE_AXIULUO = 198,        //激活阿修罗
    BT_DEITY_ACTIVE_AXIULUO_STRONG_QUALITY = 199,        //阿修罗升阶
    BT_DEITY_ACTIVE_AXIULUO_STRING_LV = 200,        //阿修罗晋升
    BT_DEITY_ACTIVE_AXIULUO_SHENGGE_BACK = 201,     //阿修罗神格归位
    //装备炼器
    BT_EQUIP_ALL_COM_STRONG_LV = 212, //强化加成普通装备
    BT_EQUIP_ALL_XIANQI_STRONG_LV = 213, //强化加成仙器
    BT_EQUIP_ALL_STAR = 214, //装备星级
    BT_EQUIP_STRONG_QUALITY = 215, //升品
    BT_EQUIP_ALL_COM_STRONG_QUALITY = 216, //升品加成普通装备
    BT_EQUIP_ALL_XIANQI_STRONG_QUALITY = 217, //升品加成普通装备
    BT_EQUIP_ALL_AWAKE = 218, //觉醒
    BT_EQUIP_AWAKE_FLY = 219, //觉醒飞升
    BT_EQUIP_SEAL_SUIT = 220, //印记激活套装
    BT_EQUIP_ALL_STONE_LV = 221, //宝石加成
    BT_EQUIP_STONE_LV = 222, //宝石共鸣
    //山海经
    BT_ENCYLOPEDIA_ACTIVE_HANDBOOK = 225, //藏经阁-激活图鉴
    BT_ENCYLOPEDIA_ACTIVE_FETTER = 226, //藏经阁-激活羁绊
    BT_ENCYLOPEDIA_UPGRADE_PRIVATE = 227, //强化特权-强化达人
    BT_ENCYLOPEDIA_UPGRADE_PRIVATE2 = 228, //强化特权-强化大师
    //奇门
    BT_MOFA_SLOT_STRONG_QUALITY = 229, //八卦阵眼升品
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