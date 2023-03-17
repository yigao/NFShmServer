// -------------------------------------------------------------------------
//    @FileName         :    NFEquipDefine.h
//    @Author           :    gaoyi
//    @Date             :    23-3-17
//    @Email			:    445267987@qq.com
//    @Module           :    NFEquipDefine
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFItemDefine.h"

struct stStoneSlotInfo
{
    stStoneSlotInfo()
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

    int CreateInit()
    {
        pos = -1;
        stone_id = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    int8_t pos; //0-4 索引，发给客户端1-5
    int64_t stone_id;
};

//洗练
struct stWashSlotInfo
{
    stWashSlotInfo()
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

    int CreateInit()
    {
        slot = 0;     //槽位 0 开始
        quality = 0;  //品质 (随机槽位索引+1)
        lock = 0;     //0未解锁。1解锁
        id = 0;         //属性id
        value = 0;     //属性值
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    int8_t slot;     //槽位 0 开始
    int8_t quality;  //品质 (随机槽位索引+1)
    int8_t lock;     //0未解锁。1解锁
    int32_t id;         //属性id
    int32_t value;     //属性值
};

struct stEquipSlotInfo
{
    stEquipSlotInfo()
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

    int CreateInit()
    {
        slot_pos = 0;                                        //槽位
        total_score = 0;                                    //总评分
        stronglv = 0;                                        //强化等级
        stone_pay_slot_open = 0;                            //付费宝石槽位是否开放
        suitLv = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    int8_t slot_pos;                                        //槽位
    int32_t total_score;                                    //总评分
    int32_t stronglv;                                        //强化等级
    NFShmVector<stStoneSlotInfo, MAX_STONE_SLOT> vec_stone;              //宝石槽位信息
    int32_t stone_pay_slot_open;                            //付费宝石槽位是否开放
    NFShmVector<stWashSlotInfo, MAX_WASH_SLOT> vec_wash;               //洗练槽位信息
    uint8_t suitLv;                                          //套装等级

    int unpack(const proto_ff::EquipSlotInfo &proto);

    int pack(proto_ff::EquipSlotInfo *pProto, bool clientFalg = false);

    void initStone();

    void initWash();

    int32_t GetWashReachQulity();
};

//穿戴的装备信息及该槽位的信息
struct stDressEquipInfo
{
    stDressEquipInfo()
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

    int CreateInit()
    {
        pos = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    int8_t pos;
    NFGridItem m_equip;
    stEquipSlotInfo slot;

    int unpack(const proto_ff::EquipInfo &proto);

    int pack(proto_ff::EquipInfo *pProto, bool clientFalg = false);
};

//背包物品
typedef NFShmVector<stDressEquipInfo, proto_ff::EEquipPos_limit> VecDressEquip;
