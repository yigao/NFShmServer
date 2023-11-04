// -------------------------------------------------------------------------
//    @FileName         :    NFGrowDescEx.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFGrowDescEx
//
// -------------------------------------------------------------------------

#include "NFGrowDescEx.h"
#include "NFComm/NFCore/NFCommonApi.h"

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

NFGrowDescEx::NFGrowDescEx()
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

NFGrowDescEx::~NFGrowDescEx()
{
}

int NFGrowDescEx::CreateInit()
{
    return 0;
}

int NFGrowDescEx::ResumeInit()
{
    return 0;
}

int NFGrowDescEx::Load()
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    CHECK_EXPR(Process(), -1, "");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
    return 0;
}

int NFGrowDescEx::CheckWhenAllDataLoaded()
{
    return NFIDescStoreEx::CheckWhenAllDataLoaded();
}

GrowInfoCfg *NFGrowDescEx::GetGrowCfg(int64_t id)
{
    auto iter = m_id2typeMap.find(id);
    CHECK_EXPR(iter != m_id2typeMap.end(), nullptr, "");
    GrowCfgMap &t = m_typeGrowMap[iter->second];
    auto iditer = t.find(id);
    CHECK_EXPR(iditer != t.end(), nullptr, "");
    return &(iditer->second);
}

bool NFGrowDescEx::Process()
{
    CHECK_EXPR(ProcessFashion(), false, "");
    CHECK_EXPR(ProcessDecorate(), false, "");
    CHECK_EXPR(ProcessFootPrint(), false, "");
    CHECK_EXPR(ProcessMeditation(), false, "");
    CHECK_EXPR(ProcessHalo(), false, "");
    CHECK_EXPR(ProcessHead(), false, "");
    return true;
}

bool NFGrowDescEx::ProcessLvMap(MAP_INT32_INT32 &lvMap, const string &cfg)
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

bool NFGrowDescEx::ProcessFashion()
{
    auto pMap = FashionFashionDesc::Instance()->GetResDescPtr();
    CHECK_EXPR(pMap, false, "GrowMgrCfg::ProcessFashion not find");
    
    for (auto iter = pMap->begin(); iter != pMap->end(); iter++)
    {
        auto& e = iter->second;
        int32_t type = e.m_type;
        GrowCfgMap &t = m_typeGrowMap[type];
        GrowInfoCfg c;
        c.id = e.m_ID;
        c.type = type;
        NFCommonApi::SplitStrToSetInt32(e.m_professionLimit.data(), ";", &c.profLimits);
        c.activationItem = e.m_activationItem;
        c.activationNum = e.m_activationNum;
        c.startItem = e.m_starId;
        MAP_INT32_INT32 lvMap;
        ProcessLvMap(lvMap, e.m_starNum.ToString());
        c.lvMap.insert(lvMap.begin(), lvMap.end());
        CHECK_EXPR((int32_t) c.lvMap.size() == e.m_starUp, false, "GrowMgrCfg::ProcessFashion id:{} lvMap_size:{} starUp:{} error",
                   e.m_ID, c.lvMap.size(), e.m_starUp);
        c.starBar = e.m_starBer;
        for (auto &ie: e.m_attribute)
        {
            c.attrsMap[ie.m_type] = ie.m_value;
        }
        
        for (auto &te: e.m_ActiveAttribute)
        {
            c.activeAttrMap[te.m_type] = te.m_value;
        }
        
        t[c.id] = c;
        CHECK_EXPR(addId(c.id, type), false, "GrowMgrCfg::ProcessFashion id:{} repeated!", c.id);
    }
    
    return true;
}

bool NFGrowDescEx::ProcessDecorate()
{
    auto pMap = DecorateDecorateDesc::Instance()->GetResDescPtr();
    CHECK_EXPR(pMap, false, "GrowMgrCfg::ProcessDecorate not find");
    
    for (auto iter = pMap->begin(); iter != pMap->end(); iter++)
    {
        auto& e = iter->second;
        int32_t type = e.m_type;
        GrowCfgMap &t = m_typeGrowMap[type];
        GrowInfoCfg c;
        c.id = e.m_ID;
        c.type = type;
        NFCommonApi::SplitStrToSetInt32(e.m_professionLimit.data(), ";", &c.profLimits);
        c.activationItem = e.m_activationItem;
        c.activationNum = e.m_activationNum;
        c.startItem = e.m_starId;
        MAP_INT32_INT32 lvMap;
        ProcessLvMap(lvMap, e.m_starNum.ToString());
        c.lvMap.insert(lvMap.begin(), lvMap.end());
        CHECK_EXPR((int32_t) c.lvMap.size() == e.m_starUp, false, "GrowMgrCfg::ProcessDecorate id:{} lvMap_size:{} starUp:{} error",
                   e.m_ID, c.lvMap.size(), e.m_starUp);
        c.starBar = e.m_starBer;
        for (auto &ie: e.m_attribute)
        {
            c.attrsMap[ie.m_type] = ie.m_value;
        }
        
        for (auto &te: e.m_ActiveAttribute)
        {
            c.activeAttrMap[te.m_type] = te.m_value;
        }
        
        t[c.id] = c;
        CHECK_EXPR(addId(c.id, type), false, "GrowMgrCfg::ProcessDecorate id:{} repeated!", c.id);
    }
    
    return true;
}

bool NFGrowDescEx::ProcessFootPrint()
{
    auto pMap = FootprintFootprintDesc::Instance()->GetResDescPtr();
    CHECK_EXPR(pMap, false, "GrowMgrCfg::ProcessFootPrint not find");
    
    for (auto iter = pMap->begin(); iter != pMap->end(); iter++)
    {
        auto& e = iter->second;
        int32_t type = e.m_type;
        GrowCfgMap &t = m_typeGrowMap[type];
        GrowInfoCfg c;
        c.id = e.m_ID;
        c.type = type;
        NFCommonApi::SplitStrToSetInt32(e.m_professionLimit.ToString(), ";", &c.profLimits);
        c.activationItem = e.m_activationItem;
        c.activationNum = e.m_activationNum;
        c.startItem = e.m_starId;
        MAP_INT32_INT32 lvMap;
        ProcessLvMap(lvMap, e.m_starNum.ToString());
        c.lvMap.insert(lvMap.begin(), lvMap.end());
        CHECK_EXPR((int32_t) c.lvMap.size() == e.m_starUp, false, "GrowMgrCfg::ProcessFootPrint id:{} lvMap_size:{} starUp:{} error",
                   e.m_ID, c.lvMap.size(), e.m_starUp);
        c.starBar = e.m_starBer;
        for (auto &ie: e.m_attribute)
        {
            c.attrsMap[ie.m_type] = ie.m_value;
        }
        
        for (auto &te: e.m_ActiveAttribute)
        {
            c.activeAttrMap[te.m_type] = te.m_value;
        }
        
        t[c.id] = c;
        CHECK_EXPR(addId(c.id, type), false, "GrowMgrCfg::ProcessFootPrint id:{} repeated!", c.id);
    }
    
    return true;
}

bool NFGrowDescEx::ProcessMeditation()
{
    auto pMap = MeditationMeditationDesc::Instance()->GetResDescPtr();
    CHECK_EXPR(pMap, false, "GrowMgrCfg::ProcessMeditation not find");
    
    for (auto iter = pMap->begin(); iter != pMap->end(); iter++)
    {
        auto& e = iter->second;
        int32_t type = e.m_type;
        GrowCfgMap &t = m_typeGrowMap[type];
        GrowInfoCfg c;
        c.id = e.m_ID;
        c.type = type;
        NFCommonApi::SplitStrToSetInt32(e.m_professionLimit.ToString(), ";", &c.profLimits);
        c.activationItem = e.m_activationItem;
        c.activationNum = e.m_activationNum;
        c.startItem = e.m_starId;
        MAP_INT32_INT32 lvMap;
        ProcessLvMap(lvMap, e.m_starNum.ToString());
        c.lvMap.insert(lvMap.begin(), lvMap.end());
        CHECK_EXPR((int32_t) c.lvMap.size() == e.m_starUp, false, "GrowMgrCfg::ProcessMeditation id:{} lvMap_size:{} starUp:{} error",
                   e.m_ID, c.lvMap.size(), e.m_starUp);
        c.starBar = e.m_starBer;
        for (auto &ie: e.m_attribute)
        {
            c.attrsMap[ie.m_type] = ie.m_value;
        }
        
        for (auto &te: e.m_ActiveAttribute)
        {
            c.activeAttrMap[te.m_type] = te.m_value;
        }
        
        t[c.id] = c;
        CHECK_EXPR(addId(c.id, type), false, "GrowMgrCfg::ProcessMeditation id:{} repeated!", c.id);
    }
    
    return true;
}

bool NFGrowDescEx::ProcessHalo()
{
    auto pMap = HaloHaloDesc::Instance()->GetResDescPtr();
    CHECK_EXPR(pMap, false, "GrowMgrCfg::ProcessHalo not find");
    
    for (auto iter = pMap->begin(); iter != pMap->end(); iter++)
    {
        auto& e = iter->second;
        int32_t type = e.m_type;
        GrowCfgMap &t = m_typeGrowMap[type];
        GrowInfoCfg c;
        c.id = e.m_ID;
        c.type = type;
        NFCommonApi::SplitStrToSetInt32(e.m_professionLimit.ToString(), ";", &c.profLimits);
        c.activationItem = e.m_activationItem;
        c.activationNum = e.m_activationNum;
        c.startItem = e.m_starId;
        MAP_INT32_INT32 lvMap;
        ProcessLvMap(lvMap, e.m_starNum.ToString());
        c.lvMap.insert(lvMap.begin(), lvMap.end());
        CHECK_EXPR((int32_t) c.lvMap.size() == e.m_starUp, false, "GrowMgrCfg::ProcessHalo id:{} lvMap_size:{} starUp:{} error",
                   e.m_ID, c.lvMap.size(), e.m_starUp);
        c.starBar = e.m_starBer;
        for (auto &ie: e.m_attribute)
        {
            c.attrsMap[ie.m_type] = ie.m_value;
        }
        
        for (auto &te: e.m_ActiveAttribute)
        {
            c.activeAttrMap[te.m_type] = te.m_value;
        }
        
        t[c.id] = c;
        CHECK_EXPR(addId(c.id, type), false, "GrowMgrCfg::ProcessHalo id:{} repeated!", c.id);
    }
    
    return true;
}

bool NFGrowDescEx::ProcessHead()
{
    auto pMap = HeadportraitHeadDesc::Instance()->GetResDescPtr();
    CHECK_EXPR(pMap, false, "GrowMgrCfg::ProcessHead not find");
    
    for (auto iter = pMap->begin(); iter != pMap->end(); iter++)
    {
        auto& e = iter->second;
        int32_t type = e.m_type;
        GrowCfgMap &t = m_typeGrowMap[type];
        GrowInfoCfg c;
        c.id = e.m_ID;
        c.type = type;
        NFCommonApi::SplitStrToSetInt32(e.m_professionLimit.ToString(), ",", &c.profLimits);
        c.activationItem = e.m_activationItem;
        c.activationNum = e.m_activationNum;
        c.startItem = e.m_starId;
        MAP_INT32_INT32 lvMap;
        ProcessLvMap(lvMap, e.m_starNum.ToString());
        c.lvMap.insert(lvMap.begin(), lvMap.end());
        CHECK_EXPR((int32_t) c.lvMap.size() == e.m_starUp, false, "GrowMgrCfg::ProcessHead id:{} lvMap_size:{} starUp:{} error",
                   e.m_ID, c.lvMap.size(), e.m_starUp);
        c.starBar = e.m_starBer;
        for (auto &ie: e.m_attribute)
        {
            c.attrsMap[ie.m_type] = ie.m_value;
        }
        for (auto &te: e.m_ActiveAttribute)
        {
            c.activeAttrMap[te.m_type] = te.m_value;
        }
        t[c.id] = c;
        
        CHECK_EXPR(addId(c.id, type), false, "GrowMgrCfg::ProcessHead id:{} repeated!", c.id);
    }
    
    return true;
}

bool NFGrowDescEx::addId(int64_t id, int32_t type)
{
    auto iter = m_id2typeMap.find(id);
    if (iter != m_id2typeMap.end())
    {
        return false;
    }
    m_id2typeMap[id] = type;
    return true;
}
