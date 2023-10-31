#include "ItemDescEx.h"
#include "DescStore/ItemItemDesc.h"
#include "NFComm/NFCore/NFCommonApi.h"
#include "DescStore/ConditionConditionDesc.h"

ItemDescEx::ItemDescEx()
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

ItemDescEx::~ItemDescEx()
{
}

int ItemDescEx::CreateInit()
{
    return 0;
}

int ItemDescEx::ResumeInit()
{
    return 0;
}

int ItemDescEx::Load()
{
    if (!Process())
    {
        return false;
    }
    if (!ProcessStoveExp())
    {
        return false;
    }
    if (!ProcessTSActive())
    {
        return false;
    }
    return true;
}

int ItemDescEx::CheckWhenAllDataLoaded()
{
    return 0;
}

const VEC_INT64 *ItemDescEx::GetItemFuncParamCfg(uint64_t nItemId)
{
    return nullptr;
}

int32_t ItemDescEx::GetItemOrGroupCd(uint64_t itemId_cdGroup)
{
    return 0;
}

bool ItemDescEx::IsNautralBind(uint64_t nItemId)
{
    return false;
}

bool ItemDescEx::IsMatchProf(uint64_t itemid, uint8_t prof)
{
    return false;
}

bool ItemDescEx::IsNotAllowMap(uint64_t itemid, uint64_t mapid)
{
    return false;
}

uint64_t ItemDescEx::RandDeComposeEquip(int64_t star, int64_t rank, int64_t qua, int64_t prof, int64_t pos)
{
    return 0;
}

uint32_t ItemDescEx::AttrIdByItem(uint64_t itemId)
{
    return 0;
}

uint64_t ItemDescEx::ItemIdByAttrId(uint32_t attrId)
{
    return 0;
}

const MAP_UINT64_UINT64 *ItemDescEx::GetItemFixAttr(uint64_t nItemId)
{
    return nullptr;
}

const MAP_UINT64_UINT64 *ItemDescEx::GetSmeltMaterialCfg(uint64_t equipid)
{
    return nullptr;
}

bool ItemDescEx::CheckItemUseCond(uint64_t itemid, proto_ff::StatisticDataProto &proto)
{
    return false;
}

int32_t ItemDescEx::GetEquipStoveExp(int32_t wearQuality, int32_t quality)
{
    return 0;
}

bool ItemDescEx::replaceItem(uint64_t itemId, int32_t num, uint64_t &outItemId, int32_t &outNum)
{
    return false;
}

bool ItemDescEx::IsTianShenActiveNum(const proto_ff_s::E_ItemItem_s *itemCfg)
{
    return false;
}

int32_t ItemDescEx::GetTianShenId(uint64_t itemId)
{
    return 0;
}

bool ItemDescEx::IsDynExpItem(uint64_t itemId)
{
    return false;
}

int32_t ItemDescEx::GetDynExpType(uint64_t itemId)
{
    return 0;
}

bool ItemDescEx::Process()
{
    return true;
}

bool ItemDescEx::ProcessStoveExp()
{
    return false;
}

bool ItemDescEx::ProcessTSActive()
{
    return false;
}

