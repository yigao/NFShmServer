// -------------------------------------------------------------------------
//    @FileName         :    NFGrowDescStoreEx.cpp
//    @Author           :    gaoyi
//    @Date             :    23-3-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFGrowDescStoreEx
//
// -------------------------------------------------------------------------

#include "NFGrowDescStoreEx.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "DescStore/FashionFashionDesc.h"
#include "NFComm/NFCore/NFCommonApi.h"
#include "DescStore/HeadportraitHeadDesc.h"
#include "DescStore/DecorateDecorateDesc.h"
#include "DescStore/FootprintFootprintDesc.h"
#include "DescStore/MeditationMeditationDesc.h"
#include "DescStore/HaloHaloDesc.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGrowDescStoreEx, EOT_NFGrowDescStoreEx_ID, NFShmObj)

NFGrowDescStoreEx::NFGrowDescStoreEx()
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

NFGrowDescStoreEx::~NFGrowDescStoreEx()
{
}

int NFGrowDescStoreEx::CreateInit()
{
    return 0;
}

int NFGrowDescStoreEx::ResumeInit()
{
    return 0;
}

bool NFGrowDescStoreEx::IsNeedReload()
{
    CHECK_DESC_RELOADING(FashionFashionDesc);
    CHECK_DESC_RELOADING(HeadportraitHeadDesc);
    CHECK_DESC_RELOADING(DecorateDecorateDesc);
    CHECK_DESC_RELOADING(FootprintFootprintDesc);
    CHECK_DESC_RELOADING(HaloHaloDesc);
    CHECK_DESC_RELOADING(MeditationMeditationDesc);
    return false;
}

int NFGrowDescStoreEx::PrepareReload()
{
    m_typeGrowMap.clear();
    m_id2typeMap.clear();
    return 0;
}

int NFGrowDescStoreEx::Load(NFResDB *pDB)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    CHECK_EXPR(pDB != NULL, -1, "pDB == NULL");

    CHECK_EXPR(Process(), -1, "");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
    return 0;
}

int NFGrowDescStoreEx::CheckWhenAllDataLoaded()
{
    return 0;
}

bool NFGrowDescStoreEx::Process()
{
    CHECK_EXPR(ProcessFashion(), false, "");
    CHECK_EXPR(ProcessDecorate(), false, "");
    CHECK_EXPR(ProcessFootPrint(), false, "");
    CHECK_EXPR(ProcessMeditation(), false, "");
    CHECK_EXPR(ProcessHalo(), false, "");
    CHECK_EXPR(ProcessHead(), false, "");
    return true;
}

bool NFGrowDescStoreEx::ProcessLvMap(MAP_INT32_INT32 &lvMap, const string &cfg)
{
    VEC_INT32 v;
    NFCommonApi::SplitStrToVecInt(cfg, ";", &v);
    int32_t index = 1;
    for (auto &e: v)
    {
        lvMap[index] = e;
        index++;
    }

    return true;
}

bool NFGrowDescStoreEx::ProcessFashion()
{
    auto pMap = FashionFashionDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
    CHECK_EXPR(pMap, false, "GrowMgrCfg::ProcessFashion not find");

    for (auto &e: *pMap)
    {
        int32_t type = e.m_type;
        GrowCfgMap &t = m_typeGrowMap[type];
        GrowInfoCfg c;
        c.id = e.m_id;
        c.type = type;
        NFCommonApi::SplitStrToSetInt32(e.m_professionlimit.ToString(), ";", &c.profLimits);
        c.activationItem = e.m_activationitem;
        c.activationNum = e.m_activationnum;
        c.startItem = e.m_starid;
        MAP_INT32_INT32 lvMap;
        ProcessLvMap(lvMap, e.m_starnum.ToString());
        c.lvMap.insert(lvMap.begin(), lvMap.end());
        CHECK_EXPR((int32_t) c.lvMap.size() == e.m_starup, false, "GrowMgrCfg::ProcessFashion id:{} lvMap_size:{} starUp:{} error",
                   e.m_id, c.lvMap.size(), e.m_starup);
        c.starBar = e.m_starber;
        for (auto &ie: e.m_attribute)
        {
            c.attrsMap[ie.m_type] = ie.m_value;
        }

        for (auto &te: e.m_activeattribute)
        {
            c.activeAttrMap[te.m_type] = te.m_value;
        }

        t[c.id] = c;
        CHECK_EXPR(addId(c.id, type), false, "GrowMgrCfg::ProcessFashion id:{} repeated!", c.id);
    }

    return true;
}

bool NFGrowDescStoreEx::ProcessDecorate()
{
    auto pMap = DecorateDecorateDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
    CHECK_EXPR(pMap, false, "GrowMgrCfg::ProcessDecorate not find");

    for (auto &e: *pMap)
    {
        int32_t type = e.m_type;
        GrowCfgMap &t = m_typeGrowMap[type];
        GrowInfoCfg c;
        c.id = e.m_id;
        c.type = type;
        NFCommonApi::SplitStrToSetInt32(e.m_professionlimit.ToString(), ";", &c.profLimits);
        c.activationItem = e.m_activationitem;
        c.activationNum = e.m_activationnum;
        c.startItem = e.m_starid;
        MAP_INT32_INT32 lvMap;
        ProcessLvMap(lvMap, e.m_starnum.ToString());
        c.lvMap.insert(lvMap.begin(), lvMap.end());
        CHECK_EXPR((int32_t) c.lvMap.size() == e.m_starup, false, "GrowMgrCfg::ProcessDecorate id:{} lvMap_size:{} starUp:{} error",
                   e.m_id, c.lvMap.size(), e.m_starup);
        c.starBar = e.m_starber;
        for (auto &ie: e.m_attribute)
        {
            c.attrsMap[ie.m_type] = ie.m_value;
        }

        for (auto &te: e.m_activeattribute)
        {
            c.activeAttrMap[te.m_type] = te.m_value;
        }

        t[c.id] = c;
        CHECK_EXPR(addId(c.id, type), false, "GrowMgrCfg::ProcessDecorate id:{} repeated!", c.id);
    }

    return true;
}

bool NFGrowDescStoreEx::ProcessFootPrint()
{
    auto pMap = FootprintFootprintDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
    CHECK_EXPR(pMap, false, "GrowMgrCfg::ProcessFootPrint not find");

    for (auto &e: *pMap)
    {
        int32_t type = e.m_type;
        GrowCfgMap &t = m_typeGrowMap[type];
        GrowInfoCfg c;
        c.id = e.m_id;
        c.type = type;
        NFCommonApi::SplitStrToSetInt32(e.m_professionlimit.ToString(), ";", &c.profLimits);
        c.activationItem = e.m_activationitem;
        c.activationNum = e.m_activationnum;
        c.startItem = e.m_starid;
        MAP_INT32_INT32 lvMap;
        ProcessLvMap(lvMap, e.m_starnum.ToString());
        c.lvMap.insert(lvMap.begin(), lvMap.end());
        CHECK_EXPR((int32_t) c.lvMap.size() == e.m_starup, false, "GrowMgrCfg::ProcessFootPrint id:{} lvMap_size:{} starUp:{} error",
                   e.m_id, c.lvMap.size(), e.m_starup);
        c.starBar = e.m_starber;
        for (auto &ie: e.m_attribute)
        {
            c.attrsMap[ie.m_type] = ie.m_value;
        }

        for (auto &te: e.m_activeattribute)
        {
            c.activeAttrMap[te.m_type] = te.m_value;
        }

        t[c.id] = c;
        CHECK_EXPR(addId(c.id, type), false, "GrowMgrCfg::ProcessFootPrint id:{} repeated!", c.id);
    }

    return true;
}

bool NFGrowDescStoreEx::ProcessMeditation()
{
    auto pMap = MeditationMeditationDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
    CHECK_EXPR(pMap, false, "GrowMgrCfg::ProcessMeditation not find");

    for (auto &e: *pMap)
    {
        int32_t type = e.m_type;
        GrowCfgMap &t = m_typeGrowMap[type];
        GrowInfoCfg c;
        c.id = e.m_id;
        c.type = type;
        NFCommonApi::SplitStrToSetInt32(e.m_professionlimit.ToString(), ";", &c.profLimits);
        c.activationItem = e.m_activationitem;
        c.activationNum = e.m_activationnum;
        c.startItem = e.m_starid;
        MAP_INT32_INT32 lvMap;
        ProcessLvMap(lvMap, e.m_starnum.ToString());
        c.lvMap.insert(lvMap.begin(), lvMap.end());
        CHECK_EXPR((int32_t) c.lvMap.size() == e.m_starup, false, "GrowMgrCfg::ProcessMeditation id:{} lvMap_size:{} starUp:{} error",
                   e.m_id, c.lvMap.size(), e.m_starup);
        c.starBar = e.m_starber;
        for (auto &ie: e.m_attribute)
        {
            c.attrsMap[ie.m_type] = ie.m_value;
        }

        for (auto &te: e.m_activeattribute)
        {
            c.activeAttrMap[te.m_type] = te.m_value;
        }

        t[c.id] = c;
        CHECK_EXPR(addId(c.id, type), false, "GrowMgrCfg::ProcessMeditation id:{} repeated!", c.id);
    }

    return true;
}

bool NFGrowDescStoreEx::ProcessHalo()
{
    auto pMap = HaloHaloDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
    CHECK_EXPR(pMap, false, "GrowMgrCfg::ProcessHalo not find");

    for (auto &e: *pMap)
    {
        int32_t type = e.m_type;
        GrowCfgMap &t = m_typeGrowMap[type];
        GrowInfoCfg c;
        c.id = e.m_id;
        c.type = type;
        NFCommonApi::SplitStrToSetInt32(e.m_professionlimit.ToString(), ";", &c.profLimits);
        c.activationItem = e.m_activationitem;
        c.activationNum = e.m_activationnum;
        c.startItem = e.m_starid;
        MAP_INT32_INT32 lvMap;
        ProcessLvMap(lvMap, e.m_starnum.ToString());
        c.lvMap.insert(lvMap.begin(), lvMap.end());
        CHECK_EXPR((int32_t) c.lvMap.size() == e.m_starup, false, "GrowMgrCfg::ProcessHalo id:{} lvMap_size:{} starUp:{} error",
                   e.m_id, c.lvMap.size(), e.m_starup);
        c.starBar = e.m_starber;
        for (auto &ie: e.m_attribute)
        {
            c.attrsMap[ie.m_type] = ie.m_value;
        }

        for (auto &te: e.m_activeattribute)
        {
            c.activeAttrMap[te.m_type] = te.m_value;
        }

        t[c.id] = c;
        CHECK_EXPR(addId(c.id, type), false, "GrowMgrCfg::ProcessHalo id:{} repeated!", c.id);
    }

    return true;
}

bool NFGrowDescStoreEx::ProcessHead()
{
    auto pMap = HeadportraitHeadDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
    CHECK_EXPR(pMap, false, "GrowMgrCfg::ProcessHead not find");

    for (auto &e: *pMap)
    {
        int32_t type = e.m_type;
        GrowCfgMap &t = m_typeGrowMap[type];
        GrowInfoCfg c;
        c.id = e.m_id;
        c.type = type;
        NFCommonApi::SplitStrToSetInt32(e.m_professionlimit.ToString(), ",", &c.profLimits);
        c.activationItem = e.m_activationitem;
        c.activationNum = e.m_activationnum;
        c.startItem = e.m_starid;
        MAP_INT32_INT32 lvMap;
        ProcessLvMap(lvMap, e.m_starnum.ToString());
        c.lvMap.insert(lvMap.begin(), lvMap.end());
        CHECK_EXPR((int32_t) c.lvMap.size() == e.m_starup, false, "GrowMgrCfg::ProcessHead id:{} lvMap_size:{} starUp:{} error",
                   e.m_id, c.lvMap.size(), e.m_starup);
        c.starBar = e.m_starber;
        for (auto &ie: e.m_attribute)
        {
            c.attrsMap[ie.m_type] = ie.m_value;
        }
        for (auto &te: e.m_activeattribute)
        {
            c.activeAttrMap[te.m_type] = te.m_value;
        }
        t[c.id] = c;

        CHECK_EXPR(addId(c.id, type), false, "GrowMgrCfg::ProcessHead id:{} repeated!", c.id);
    }

    return true;
}

bool NFGrowDescStoreEx::addId(int64_t id, int32_t type)
{
    auto iter = m_id2typeMap.find(id);
    if (iter != m_id2typeMap.end())
    {
        return false;
    }
    m_id2typeMap[id] = type;
    return true;
}

GrowInfoCfg *NFGrowDescStoreEx::GetGrowCfg(int64_t id)
{
    auto iter = m_id2typeMap.find(id);
    CHECK_EXPR(iter != m_id2typeMap.end(), nullptr, "");
    GrowCfgMap &t = m_typeGrowMap[iter->second];
    auto iditer = t.find(id);
    CHECK_EXPR(iditer != t.end(), nullptr, "");
    return &(iditer->second);
}

bool GrowInfoCfg::LimitProf(int32_t prof)
{
    auto ci = std::find(profLimits.begin(), profLimits.end(), 0);
    if (ci != profLimits.end()) return false;
    auto iter = std::find(profLimits.begin(), profLimits.end(), prof);
    return (iter != profLimits.end()) ? false : true;
}

int32_t GrowInfoCfg::GetStarLvNum(int32_t lv)
{
    auto iter = lvMap.find(lv);
    return iter != lvMap.end() ? iter->second : -1;
}

