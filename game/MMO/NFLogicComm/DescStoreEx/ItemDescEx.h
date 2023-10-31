#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFLogicCommon/NFPackageDefine.h"
#include "NFGameCommon/NFComTypeDefine.h"
#include "Com.pb.h"
#include "E_Item_s.h"

class ItemDescEx : public NFShmObjGlobalTemplate<ItemDescEx, EOT_CONST_ITEM_DESC_EX_ID, NFIDescStoreEx>
{
    enum
    {
        VIR_ITEM_ID_MAX_OFFSET = 1000,	//虚拟物品ID最大偏移，虚拟物品ID配置尽量紧凑一些
    };
public:
	ItemDescEx();
	virtual ~ItemDescEx();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load() override;
	virtual int CheckWhenAllDataLoaded() override;
public:
    const VEC_INT64 *GetItemFuncParamCfg(uint64_t nItemId);		//获取物品功能配置参数
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
    const MAP_UINT64_UINT64* GetItemFixAttr(uint64_t nItemId);
    //获取装备熔炼的材料
    const MAP_UINT64_UINT64 *GetSmeltMaterialCfg(uint64_t equipid);
    //获取需要校验的 使用物品添加任务
    const MAP_UINT64_INT64 *GetChkItemAddMission() { return &m_mapItemAddMissionCheck; }
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
    bool ProcessStoveExp();
    bool ProcessTSActive();
private:
    MAP_UINT64_VEC_INT64 m_mapItemFunc;					//物品表功能参数解析
    MAP_UINT64_SET_INT32 m_mapItemProfLimit;			//物品的职业限制
    MAP_UINT64_SET_INT64 m_mapItemMapLimit;				//物品地图限制
    MAP_UINT64_INT32  m_mapItemOrCdGroup;				//物品或CD组 的cd
    SET_UINT64 m_setNaturalBind;						//天然绑定的物品，不能有非绑定的状态
    
    uint64_t m_virMinId = 0;							//虚拟物品ID列表中最小的物品ID减1
    uint16_t m_virOffset[VIR_ITEM_ID_MAX_OFFSET+1];		//虚拟物品ID最大偏移（ 物品ID对应的偏移 = 物品ID - m_virMinId ）
    uint16_t m_virAttr[proto_ff::A_COMMON_END+1];					//属性ID对应的虚拟物品ID的偏移
    
    MAP_UINT64_MAP_UINT64_UINT64 m_mapFixAttr;			//物品加永久属性
    MAP_UINT64_SET_UINT64 m_mapDecompose;				//分解需要的数据
    
    
    MAP_UINT64_MAP_UINT64_UINT64  m_mapEquipSmelt;		//装备熔炼配置
    MAP_UINT64_MAP_UINT64_UINT64  m_mapEquipStoveExp;   //熔炉配置
    
    MAP_UINT64_INT64  m_mapItemAddMissionCheck;			//使用物品获得任务，需要校验的物品对应的任务ID
    
    MAP_UINT64_SET_INT64 m_mapItemUseCond;				//物品使用条件
    std::unordered_map<uint64_t, std::pair<uint64_t, int32_t>> m_replaceItem; //ID -> replace itemid , num
    MAP_UINT64_UINT32 m_ts_active_id;					//天神激活物品对应天神id
    MAP_UINT64_UINT32 m_dynexp_items;
};
