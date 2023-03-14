// -------------------------------------------------------------------------
//    @FileName         :    NFGrowDescStoreEx.h
//    @Author           :    gaoyi
//    @Date             :    23-3-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFGrowDescStoreEx
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFLogicCommon/NFComTypeDefine.h"
#include "NFComm/NFShmStl/NFShmHashSet.h"
#include "fashion_s.h"

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
    NFShmHashMap<int32_t, int32_t, DEFINE_E_FASHIONFASHION_M_ATTRIBUTE_MAX_NUM> attrsMap;		//属性加成 key->value attrid->attrvalue
    NFShmHashMap<int32_t, int32_t, DEFINE_E_FASHIONFASHION_M_ACTIVEATTRIBUTE_MAX_NUM> activeAttrMap;	//激活加成的属性
    bool LimitProf(int32_t prof);
    int32_t GetStarLvNum(int32_t lv);
};

typedef NFShmHashMap<int64_t, GrowInfoCfg, 100> GrowCfgMap;
typedef NFShmHashMap<int32_t, GrowCfgMap, 20> GrowTypeMap;

class NFGrowDescStoreEx : public NFIDescStore
{
public:
    NFGrowDescStoreEx();

    virtual ~NFGrowDescStoreEx();

    int CreateInit();

    int ResumeInit();

    virtual bool IsNeedReload();

    virtual int PrepareReload();
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
    MAP_INT64_INT32 m_id2typeMap;	//所有配置表ID不能重复
private:
DECLARE_IDCREATE(NFGrowDescStoreEx)
IMPL_RES_SIMPLE_DESC(NFGrowDescStoreEx);
};