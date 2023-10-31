// -------------------------------------------------------------------------
//    @FileName         :    NFItemMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFItemMgr
//
// -------------------------------------------------------------------------

#include "NFItemMgr.h"

NFItemMgr::NFItemMgr()
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

NFItemMgr::~NFItemMgr()
{
}

int NFItemMgr::CreateInit()
{
    return 0;
}

int NFItemMgr::ResumeInit()
{
    return 0;
}
bool NFItemMgr::IsVirItem(uint64_t itemId)
{
    return false;
}
bool NFItemMgr::IsVirItem(uint64_t itemId, uint32_t &attrId)
{
    return false;
}
void NFItemMgr::FilterVirItem(LIST_ITEM &lstItem, LIST_ITEM &lstOutItem, MAP_UINT32_INT64 &mapAttr)
{

}
void NFItemMgr::FilterVirItem(LIST_ITEM &lstItem, LIST_ITEM &lstOutItem)
{

}
void NFItemMgr::FilterVirItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecOutProtoItemsEx, MAP_UINT32_INT64 &mapAttr)
{

}
void NFItemMgr::FilterVirItem(VEC_ITEM_PROTO_EX &vecProtoItemsEx, VEC_ITEM_PROTO_EX &vecOutProtoItemsEx)
{

}
bool NFItemMgr::IsDynExpItem(uint64_t itemId)
{
    return false;
}
