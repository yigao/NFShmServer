// -------------------------------------------------------------------------
//    @FileName         :    NFEquipPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFEquipPart
//
// -------------------------------------------------------------------------

#pragma once

#include <NFLogicCommon/Item/NFDressEquip.hpp>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFEquipSlot : public NFEquipSlotInfo
{
public:
    NFEquipSlot()
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

    ~NFEquipSlot()
    {

    }

    int CreateInit()
    {
        m_stronglv = 0;
        m_total_score = 0;
        return 0;
    }

    int ResumeInit()
    {
        return 0;
    }

    virtual bool ReadFromPB(const proto_ff::EquipSlotInfo &proto)
    {
        CHECK_EXPR(NFEquipSlotInfo::ReadFromPB(proto), false, "");
        m_stronglv = proto.stronglv();
        m_total_score = proto.total_score();
        return true;
    }

    virtual bool WriteToPB(proto_ff::EquipSlotInfo &proto)
    {
        CHECK_EXPR(NFEquipSlotInfo::WriteToPB(proto), false, "");
        proto.set_stronglv(m_stronglv);
        proto.set_total_score(m_total_score);
        return true;
    }

public:
    uint32_t m_stronglv;
    uint32_t m_total_score;
};

class NFEquipPart : public NFShmObjTemplate<NFEquipPart, EOT_LOGIC_PART_ID+PART_EQUIP, NFPart>
{
public:
    typedef NFDressEquipInfo<NFDeityEquip, NFEquipSlot, proto_ff::EEquipPos_limit-1, proto_ff::EEquipPos_m_weapon> NFEquipVec;
public:
    NFEquipPart();

    virtual ~NFEquipPart();

    int CreateInit();

    int ResumeInit();

    int32_t GetStrongLvNum(int32_t level) { return 0; }
public:
    NFEquipVec& GetEquip() { return m_equips; }
    const NFEquipVec& GetEquip() const { return m_equips; }
private:
    NFEquipVec m_equips;
};