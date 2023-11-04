// -------------------------------------------------------------------------
//    @FileName         :    NFGrowDescEx.h
//    @Author           :    gaoyi
//    @Date             :    23-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFGrowDescEx
//
// -------------------------------------------------------------------------

#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFComm/NFShmStl/NFShmHashSet.h"
#include "DescStore/FashionFashionDesc.h"
#include "DescStore/HeadportraitHeadDesc.h"
#include "DescStore/DecorateDecorateDesc.h"
#include "DescStore/FootprintFootprintDesc.h"
#include "DescStore/MeditationMeditationDesc.h"
#include "DescStore/HaloHaloDesc.h"
#include "ComDefine.pb.h"
#include "Com.pb.h"
#include "NFGameCommon/NFComTypeDefine.h"

#define MAX_GROW_ACTIVE_ATTR_NUM 10

//养成配置信息
struct GrowInfoCfg
{
    GrowInfoCfg()
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
        id = 0;
        type = 0;
        activationItem =0;
        activationNum = 0;
        startItem =0;
        starBar = 0;
        return 0;
    }
    
    int ResumeInit()
    {
        return 0;
    }
    
    int64_t id;						//ID
    int32_t type;					//类型
    NFShmHashSet<uint32_t, proto_ff::ERoleProf_MAX> profLimits;			//职业限制
    int64_t activationItem;		//激活道具ID
    int32_t activationNum;		//激活道具数量
    int32_t startItem;			//升星道具id
    NFShmHashMap<int32_t, int32_t, 100> lvMap;			//升星消耗道具数量
    int32_t starBar;			//每次升星属性增加的百分比值
    NFShmHashMap<int32_t, int32_t, MAX_GROW_ACTIVE_ATTR_NUM> attrsMap;		//属性加成 key->value attrid->attrvalue
    NFShmHashMap<int32_t, int32_t, MAX_GROW_ACTIVE_ATTR_NUM> activeAttrMap;	//激活加成的属性
    bool LimitProf(int32_t prof);
    int32_t GetStarLvNum(int32_t lv);
};

typedef NFShmHashMap<int64_t, GrowInfoCfg, 100> GrowCfgMap;
typedef NFShmHashMap<int32_t, GrowCfgMap, proto_ff::GrowType_MAX> GrowTypeMap;

class NFGrowDescEx : public NFShmObjGlobalTemplate<NFGrowDescEx, EOT_CONST_GROW_DESC_EX_ID, NFIDescStoreEx>
{
public:
    NFGrowDescEx();
    
    virtual ~NFGrowDescEx();
    
    int CreateInit();
    int ResumeInit();
public:
    virtual int Load() override;
    virtual int CheckWhenAllDataLoaded() override;
public:
    GrowInfoCfg* GetGrowCfg(int64_t id);
private:
    bool Process();
    bool ProcessLvMap(MAP_INT32_INT32& lvMap, const std::string& cfg);
private:
    bool ProcessFashion();			//处理时装
    bool ProcessDecorate();			//处理首饰
    bool ProcessFootPrint();		//处理足迹
    bool ProcessMeditation();		//处理打坐
    bool ProcessHalo();				//处理光环
    bool ProcessHead();				//处理头像
    
    bool addId(int64_t id, int32_t type); //对ID处理
private:
    GrowTypeMap		m_typeGrowMap;
    NFShmHashMap<int64_t, int32_t, MAX_FASHION_FASHION_NUM+MAX_HEADPORTRAIT_HEAD_NUM+MAX_DECORATE_DECORATE_NUM+MAX_FOOTPRINT_FOOTPRINT_NUM+MAX_MEDITATION_MEDITATION_NUM+MAX_HALO_HALO_NUM> m_id2typeMap;	//所有配置表ID不能重复
};