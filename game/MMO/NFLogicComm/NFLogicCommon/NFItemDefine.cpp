// -------------------------------------------------------------------------
//    @FileName         :    NFItemDefine.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFItemDefine
//
// -------------------------------------------------------------------------

#include "NFItemDefine.h"

NFGridItem::NFGridItem()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFGridItem::~NFGridItem()
{

}

int NFGridItem::CreateInit()
{
    base.CreateInit();
    return 0;
}

int NFGridItem::ResumeInit()
{
    return 0;
}

bool NFGridItem::Init(uint16_t nIndex, uint64_t nItemID, SItemCond &itemCond, uint64_t nNum, int8_t byBind)
{
    base.index = nIndex;
    base.item_id = nItemID;
    base.item_num = nNum;
    base.bind = byBind;
    return true;
}

int NFGridItem::read_from_pbmsg(const proto_ff::ItemProtoInfo &protoItem)
{
    base.index = protoItem.index();
    base.item_id = protoItem.item_id();
    base.item_num = protoItem.item_num();
    base.bind = protoItem.bind();
    base.level = protoItem.level();
    base.expireTime = protoItem.expiretime();
    NF_ASSERT((int)protoItem.base_size() <= (int)equip_ext.base.max_size());
    for(int i = 0; i < (int)protoItem.base_size(); i++)
    {
        const ::proto_ff::Attr& attr = protoItem.base(i);
        equip_ext.base.push_back();
        equip_ext.base.back().read_from_pbmsg(attr);
    }

    NF_ASSERT((int)protoItem.refine_size() <= (int)equip_ext.refine.max_size());
    for(int i = 0; i < (int)protoItem.refine_size(); i++)
    {
        const ::proto_ff::Attr& attr = protoItem.refine(i);
        equip_ext.refine.push_back();
        equip_ext.refine.back().read_from_pbmsg(attr);
    }

    NF_ASSERT((int)protoItem.blue_size() <= (int)equip_ext.blue.max_size());
    for(int i = 0; i < (int)protoItem.blue_size(); i++)
    {
        const ::proto_ff::BlueStarAttr& attr = protoItem.blue(i);
        equip_ext.blue.push_back();
        equip_ext.blue.back().read_from_pbmsg(attr);
    }

    NF_ASSERT((int)protoItem.god_size() <= (int)equip_ext.god.max_size());
    for(int i = 0; i < (int)protoItem.god_size(); i++)
    {
        const ::proto_ff::Attr& attr = protoItem.god(i);
        equip_ext.god.push_back();
        equip_ext.god.back().read_from_pbmsg(attr);
    }

    NF_ASSERT((int)protoItem.special_size() <= (int)equip_ext.special.max_size());
    for(int i = 0; i < (int)protoItem.special_size(); i++)
    {
        const ::proto_ff::Attr& attr = protoItem.special(i);
        equip_ext.special.push_back();
        equip_ext.special.back().read_from_pbmsg(attr);
    }

    equip_ext.strong_lv = protoItem.strong_lv();
    equip_ext.strong_wear_quality = protoItem.strong_wear_quality();

    return 0;
}

int NFGridItem::write_to_pbmsg(proto_ff::ItemProtoInfo &protoItem)
{
    protoItem.set_index(base.index);
    protoItem.set_item_id(base.item_id);
    protoItem.set_item_num(base.item_num);
    protoItem.set_bind(base.bind);
    protoItem.set_level(base.level);
    protoItem.set_expiretime(base.expireTime);

    for(int i = 0; i < (int)equip_ext.base.size(); i++)
    {
        equip_ext.base[i].write_to_pbmsg(*protoItem.add_base());
    }

    for(int i = 0; i < (int)equip_ext.refine.size(); i++)
    {
        equip_ext.refine[i].write_to_pbmsg(*protoItem.add_refine());
    }

    for(int i = 0; i < (int)equip_ext.blue.size(); i++)
    {
        equip_ext.blue[i].write_to_pbmsg(*protoItem.add_blue());
    }

    for(int i = 0; i < (int)equip_ext.god.size(); i++)
    {
        equip_ext.god[i].write_to_pbmsg(*protoItem.add_god());
    }

    for(int i = 0; i < (int)equip_ext.special.size(); i++)
    {
        equip_ext.special[i].write_to_pbmsg(*protoItem.add_special());
    }

    protoItem.set_strong_lv(equip_ext.strong_lv);
    protoItem.set_strong_wear_quality(equip_ext.strong_wear_quality);
    return 0;
}

uint16_t NFGridItem::GetIndex() const
{
    return base.index;
}

uint64_t NFGridItem::GetItemID() const
{
    return base.item_id;
}

uint64_t NFGridItem::GetNum() const
{
    return base.item_num;
}

int8_t NFGridItem::GetBind() const
{
    return base.bind;
}

uint8_t NFGridItem::GetType() const
{
    return base.type;
}

uint32_t NFGridItem::GetLevel() const
{
    return base.level;
}

int64_t NFGridItem::GetExpireTime() const
{
    return base.expireTime;
}

void NFGridItem::SetIndex(uint16_t nIndex)
{
    base.index = nIndex;
}

void NFGridItem::SetType(uint8_t type)
{
    base.type = type;
}

void NFGridItem::SetBind(int8_t byBind)
{
    base.bind = byBind;
}

void NFGridItem::SetNum(uint64_t nNum)
{
    base.item_num = nNum;
}

void NFGridItem::SetLevel(uint32_t nLevel)
{
    base.level = nLevel;
}

void NFGridItem::SetExpireTime(int64_t tick)
{
    base.expireTime = tick;
}

bool NFGridItem::AddNum(int64_t nAddNum)
{
    if (nAddNum > 0)
    {
        if (UINT32_MAX - base.item_num < (uint64_t)nAddNum)
        {
            base.item_num = UINT32_MAX;
            //数量超过 需要打印警告日志
            NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] CItemBase::AddNum....num > UINT32_MAX...nAddNum:%lu,m_nNum:%lu", nAddNum, base.item_num);
        }
        else
        {
            base.item_num += nAddNum;
        }
    }
    else
    {
        if (((int64_t)base.item_num + (int64_t)nAddNum) >=0 )
        {
            base.item_num += nAddNum;
        }
        else
        {
            base.item_num = 0;
        }
    }

    return true;
}
