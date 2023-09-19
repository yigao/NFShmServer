// -------------------------------------------------------------------------
//    @FileName         :    NFItemDescStoreEx.h
//    @Author           :    gaoyi
//    @Date             :    22-12-2
//    @Email			:    445267987@qq.com
//    @Module           :    NFItemDescStoreEx
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmOldHashMap.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFServerComm/NFServerCommon/NFIDescStore.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFLogicCommon/NFComTypeDefine.h"
#include "DescStore/EquipEquipDesc.h"
#include "DescStore/ItemItemDesc.h"
#include "NFComm/NFShmCore/NFArray.h"

typedef NFShmOldHashMap<uint64_t, NFArray<int64_t, 10>, MAX_ITEM_ITEM_NUM>  ITEM_FUNC_MAP;
typedef NFShmOldHashMap<uint64_t, NFShmOldHashMap<int32_t, bool, 10>, MAX_EQUIP_EQUIP_NUM>  ITEM_PROF_LIMIT_MAP;
typedef NFShmOldHashMap<uint64_t, NFShmOldHashMap<int64_t, bool, 10>, MAX_ITEM_ITEM_NUM>  ITEM_MAP_LIMIT_MAP;
typedef NFShmOldHashMap<uint64_t, NFShmOldHashMap<int32_t, bool, 10>, MAX_ITEM_ITEM_NUM>  ITEM_CD_GROUP_MAP;
typedef NFShmOldHashMap<uint64_t, bool, MAX_ITEM_ITEM_NUM>  SET_NATURAL_MAP;
typedef NFShmOldHashMap<uint64_t, int32_t, MAX_ITEM_ITEM_NUM>  MAP_VIRTUAL_ITEM_ATTR_MAP;
typedef NFShmOldHashMap<int32_t, uint64_t, MAX_ITEM_ITEM_NUM>  MAP_ATTR_ITEM_VIRTUAL_MAP;
typedef NFShmOldHashMap<uint64_t, NFShmOldHashMap<uint64_t, uint64_t, 10>, MAX_ITEM_ITEM_NUM>  MAP_FIX_MAP;
typedef NFShmOldHashMap<uint64_t, NFShmOldHashMap<int64_t, bool, 10>, MAX_ITEM_ITEM_NUM>  MAP_ITEM_USE_COND_ITEM;
typedef NFShmOldHashMap<uint64_t, int64_t, MAX_ITEM_ITEM_NUM>  ITEM_ADD_MISSION_MAP;
typedef NFShmOldHashMap<uint64_t, NFShmOldHashMap<int64_t, bool, 10>, MAX_EQUIP_EQUIP_NUM*5>  MAP_DECOMPOSE_MAP;
typedef NFShmOldHashMap<uint64_t, NFShmOldHashMap<uint64_t, uint64_t, 10>, MAX_EQUIP_EQUIP_NUM>  MAP_EQUIP_SMELT;

class NFItemDescStoreEx : public NFIDescStore
{
    //单双命星和命星品质组合成一个key
#define STAR_UPGRADE_KEY(single,qua) (single * 100 + qua)
//装备分级   星级、阶级、品质、职业、部位  组合成一个key，key对应的列表里面是满足key条件的装备ID
#define DE_COMPOSE_KEY(star,rank,qua,prof,pos) ((star << 32) | (rank << 24)| (qua << 16) | (prof << 8) | pos)
public:
    NFItemDescStoreEx();

    virtual ~NFItemDescStoreEx();

    int CreateInit();

    int ResumeInit();

public:
    int ProcessItem();
public:
    //根据物品ID获取对应的属性ID
    uint32_t AttrIdByItem(uint64_t itemId);
    //根据属性ID 获取对应的物品ID
    uint64_t ItemIdByAttrId(uint32_t attrId);
private:
    ITEM_FUNC_MAP m_mapItemFunc;					//物品表功能参数解析
    ITEM_PROF_LIMIT_MAP m_mapItemProfLimit;			//物品的职业限制
    ITEM_MAP_LIMIT_MAP m_mapItemMapLimit;				//物品地图限制
    ITEM_CD_GROUP_MAP  m_mapItemOrCdGroup;				//物品或CD组 的cd
    SET_NATURAL_MAP m_setNaturalBind;						//天然绑定的物品，不能有非绑定的状态
    MAP_VIRTUAL_ITEM_ATTR_MAP m_mapVirtualItemAttr;				//虚拟物品增加的属性ID  itemid - attrid
    MAP_ATTR_ITEM_VIRTUAL_MAP m_mapAttrVirtualItem;				//属性ID对应的虚拟物品ID attrid - itemid
    MAP_FIX_MAP m_mapFixAttr;			//物品加永久属性
    MAP_ITEM_USE_COND_ITEM m_mapItemUseCond;				//物品使用条件
    ITEM_ADD_MISSION_MAP  m_mapItemAddMissionCheck;			//使用物品获得任务，需要校验的物品对应的任务ID
    MAP_DECOMPOSE_MAP m_mapDecompose;				//分解需要的数据
    MAP_EQUIP_SMELT  m_mapEquipSmelt;		//装备熔炼配置
DECLARE_IDCREATE(NFItemDescStoreEx)
IMPL_RES_SIMPLE_DESC(NFItemDescStoreEx);
};