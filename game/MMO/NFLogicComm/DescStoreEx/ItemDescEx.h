#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmHashSet.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFLogicCommon/NFPackageDefine.h"
#include "NFGameCommon/NFComTypeDefine.h"
#include "Com.pb.h"
#include "DescStore/ItemItemDesc.h"
#include "DescStore/EquipEquipDesc.h"
#include "DescStore/AvatarChangeDesc.h"
#include "E_Condition_s.h"

#define MAX_NATURAL_BIND_ITEM_NUM (MAX_ITEM_ITEM_NUM/10)
#define MAX_MAP_LIMIT_ITEM_NUM (MAX_ITEM_ITEM_NUM/50)
#define MAX_MAP_LIMIT_ITEM_MAP_NUM 5
#define MAX_PROF_LIMIT_ITEM_NUM (MAX_EQUIP_EQUIP_NUM)
#define MAX_PROF_LIMIT_ITEM_MAP_NUM 10
#define MAX_ITEM_FUNC_PARAM_NUM 10
#define MAX_REPLACE_ITEM_NUM 100

#define MAX_DECOMPOSE_ITEM_KEY_NUM MAX_EQUIP_EQUIP_NUM*2
#define MAX_DECOMPOSE_ITEM_ONE_KEY_EQUIP_NUM 10

#define MAX_EQUIP_SMELT_EQUIP_NUM 100
#define MAX_EQUIP_SMELT_EQUIP_MAX_ITEM_NUM 2

#define MAX_DY_EXP_ITEM_NUM 100

//装备分级   星级、阶级、品质、职业、部位  组合成一个key，key对应的列表里面是满足key条件的装备ID
#define DE_COMPOSE_KEY(star,rank,qua,prof,pos) ((star << 32) | (rank << 24)| (qua << 16) | (prof << 8) | pos)

class ItemDescEx : public NFShmObjGlobalTemplate<ItemDescEx, EOT_CONST_ITEM_DESC_EX_ID, NFIDescStoreEx>
{
    enum
    {
        VIR_ITEM_ID_MAX_OFFSET = 1000,	//虚拟物品ID最大偏移，虚拟物品ID配置尽量紧凑一些
    };
    
    typedef NFShmHashSet<uint64_t, MAX_NATURAL_BIND_ITEM_NUM> NaturalBindSet;
    typedef NFShmHashMap<uint64_t, NFShmHashSet<int64_t, MAX_MAP_LIMIT_ITEM_MAP_NUM>, MAX_MAP_LIMIT_ITEM_NUM> ItemMapLimitMap;
    typedef NFShmHashMap<uint64_t, NFShmHashSet<int32_t, MAX_PROF_LIMIT_ITEM_MAP_NUM>, MAX_PROF_LIMIT_ITEM_NUM> ItemProfLimitMap;
    typedef NFShmHashMap<uint64_t, NFShmVector<int64_t, MAX_ITEM_FUNC_PARAM_NUM>, DEFINE_SHEET_ITEMITEM_E_ITEMITEM_LIST_MAX_NUM> ItemFuncMap;
    typedef NFShmHashMap<uint64_t, NFShmPair<uint32_t, uint32_t>, MAX_REPLACE_ITEM_NUM> ItemReplaceMap;
    typedef NFShmHashMap<uint64_t, NFShmHashSet<uint64_t, MAX_DECOMPOSE_ITEM_ONE_KEY_EQUIP_NUM>, MAX_DECOMPOSE_ITEM_KEY_NUM> ItemDecomposeMap;
    typedef NFShmHashMap<uint64_t, NFShmHashMap<uint64_t, uint64_t, MAX_EQUIP_SMELT_EQUIP_MAX_ITEM_NUM>, MAX_EQUIP_SMELT_EQUIP_NUM> EqupSmeltMap;
    typedef NFShmHashMap<uint64_t, uint64_t, MAX_AVATAR_CHANGE_NUM> TsActiveMap;
    typedef NFShmHashMap<uint64_t, uint32_t, MAX_DY_EXP_ITEM_NUM> DyExpItemMap;
    typedef NFShmHashMap<uint64_t, NFShmHashSet<int64_t, 5>, 100> ItemUseConditionMap;
    typedef NFShmHashMap<uint64_t, uint64_t, 100> ItemAddMissionCheckMap;
    typedef NFShmHashMap<uint64_t, NFShmHashMap<uint64_t, uint64_t, 10>, 100> FixAttrMap;
public:
	ItemDescEx();
	virtual ~ItemDescEx();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load() override;
	virtual int CheckWhenAllDataLoaded() override;
public:
    const NFShmVector<int64_t, MAX_ITEM_FUNC_PARAM_NUM> *GetItemFuncParamCfg(uint64_t nItemId);		//获取物品功能配置参数
    int32_t GetItemOrGroupCd(uint64_t itemId_cdGroup);			//获取物品CD
    bool IsNautralBind(uint64_t nItemId);						//是否天然绑定物品
    bool IsMatchProf(uint64_t itemid, uint8_t prof);			//职业是否匹配物品的职业限制
    bool IsNotAllowMap(uint64_t itemid, uint64_t mapid);		//是否是不允许使用的地图
    //根据 星级、阶级、品质、职业、部位 随机一件装备
    uint64_t RandDeComposeEquip(int64_t star, int64_t rank, int64_t qua, int64_t prof, int64_t pos);
    //根据物品ID获取对应的属性ID
    uint32_t AttrIdByItem(uint64_t itemId);
    //根据属性ID 获取对应的物品ID
    uint64_t ItemIdByAttrId(uint32_t attrId);
    const NFShmHashMap<uint64_t, uint64_t, 10>* GetItemFixAttr(uint64_t nItemId);
    //获取装备熔炼的材料
    const NFShmHashMap<uint64_t, uint64_t, MAX_EQUIP_SMELT_EQUIP_MAX_ITEM_NUM> *GetSmeltMaterialCfg(uint64_t equipid);
    //获取需要校验的 使用物品添加任务
    const ItemAddMissionCheckMap *GetChkItemAddMission() { return &m_mapItemAddMissionCheck; }
    //校验是否满足物品使用条件
    bool CheckItemUseCond(uint64_t itemid,proto_ff::StatisticDataProto &proto);
    int32_t GetEquipStoveExp(int32_t wearQuality, int32_t quality);
    bool replaceItem(uint64_t itemId, int32_t num, uint64_t& outItemId, int32_t& outNum);
    bool IsTianShenActiveNum(const proto_ff_s::E_ItemItem_s* itemCfg);
    int32_t GetTianShenId(uint64_t itemId);
    bool IsDynExpItem(uint64_t itemId);
    int32_t GetDynExpType(uint64_t itemId);
private:
    bool Process();
    bool ProcessTSActive();
    //是否满足物品使用条件
    bool CheckItemUseCond(const proto_ff_s::E_ConditionCondition_s *pCondCfg, proto_ff::StatisticDataProto &proto);
private:
    ItemFuncMap m_mapItemFunc;					//物品表功能参数解析
    ItemProfLimitMap m_mapItemProfLimit;			//物品的职业限制
    ItemMapLimitMap m_mapItemMapLimit;				//物品地图限制
    MAP_UINT64_INT32  m_mapItemOrCdGroup;				//物品或CD组 的cd
    NaturalBindSet m_setNaturalBind;						//天然绑定的物品，不能有非绑定的状态
    
    uint64_t m_virMinId;							//虚拟物品ID列表中最小的物品ID减1
    uint16_t m_virOffset[VIR_ITEM_ID_MAX_OFFSET+1]{};		//虚拟物品ID最大偏移（ 物品ID对应的偏移 = 物品ID - m_virMinId ）
    uint16_t m_virAttr[proto_ff::A_COMMON_END+1]{};		//属性ID对应的虚拟物品ID的偏移
    
    FixAttrMap m_mapFixAttr;			//物品加永久属性
    ItemDecomposeMap m_mapDecompose;				//分解需要的数据
    
    EqupSmeltMap  m_mapEquipSmelt;		//装备熔炼配置
    
    ItemAddMissionCheckMap  m_mapItemAddMissionCheck;			//使用物品获得任务，需要校验的物品对应的任务ID
    
    ItemUseConditionMap m_mapItemUseCond;				//物品使用条件
    ItemReplaceMap m_replaceItem; //ID -> replace itemid , num
    TsActiveMap m_ts_active_id;					//天神激活物品对应天神id
    DyExpItemMap m_dynexp_items;
};
