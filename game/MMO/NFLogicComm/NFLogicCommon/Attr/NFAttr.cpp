// -------------------------------------------------------------------------
//    @FileName         :    NFAttr.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFAttr
//
// -------------------------------------------------------------------------

#include "NFAttr.h"
#include "NFAttrMgr.h"
#include "NFLogicCommon/NFCharactorDefine.h"

int64_t AddVal(int64_t oldval, int64_t val)
{
    if (0 == val)
    {
        return oldval;
    }
    int64_t newval = 0;
    if (val > 0)
    {
        if (INT64_MAX - val < oldval)
        {
            newval = INT64_MAX;
        }
        else
        {
            newval = oldval + val;
        }
    }
    else
    {
        if ((oldval + val) >= 0)
        {
            newval = oldval + val;
        }
        else
        {
            newval = 0;
        }
    }
    return newval;
}


//------------------------------------------   ComFightAttr --------------------------------------------
ComFightAttr::ComFightAttr()
{
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT)
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

int ComFightAttr::CreateInit()
{
    memset(m_attr, 0, sizeof(m_attr));
    return 0;
}

int ComFightAttr::ResumeInit()
{
    return 0;
}

ComFightAttr::~ComFightAttr()
{
    for (uint32_t i = 0; i < COMMON_FIGHT_ATTR_GROUP_END; ++i)
    {
        memset(m_attr[i], 0, sizeof(int64_t) * COMMON_FIGHT_ATTR_END);
    }
}

int64_t ComFightAttr::GetAttr(uint32_t ANum)
{
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightIndex(ANum);
    if (ValidIndex(index))
    {
        return m_attr[0][index];
    }
    return 0;
}

void ComFightAttr::GetAttr(MAP_UINT32_INT64 &mapattr)
{
    for (uint32_t i = 1; i < COMMON_FIGHT_ATTR_END; ++i)
    {
        uint32_t ANum = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightAttr(i);
        if (ANum > 0)
        {
            mapattr[ANum] = m_attr[0][i];
        }
    }
}

void ComFightAttr::GetAttrGroupTotal(MAP_UINT32_INT64 &mapattr)
{
    for (uint32_t i = 1; i < COMMON_FIGHT_ATTR_END; ++i)
    {
        uint32_t ANum = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightAttr(i);
        if (!ValidAttr(ANum))
        {
            continue;
        }
        int64_t newval = 0;
        for (uint32_t j = 1; j < COMMON_FIGHT_ATTR_GROUP_END; ++j)
        {
            newval += m_attr[j][i];
        }
        mapattr[ANum] = newval;
    }
}

void ComFightAttr::CalcAttr(MAP_UINT32_INT64 &mapchg)
{
    for (uint32_t i = 1; i < COMMON_FIGHT_ATTR_END; ++i)
    {
        int64_t oldval = m_attr[0][i];
        int64_t newval = 0;
        for (uint32_t j = 1; j < COMMON_FIGHT_ATTR_GROUP_END; ++j)
        {
            newval += m_attr[j][i];
        }
        if (newval == oldval)
        {
            continue;
        }
        m_attr[0][i] = newval;
        mapchg[i] = newval;
    }
}

bool ComFightAttr::CalcAttr(uint32_t ANum, MAP_UINT32_INT64 &mapchg)
{
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightIndex(ANum);
    if (!ValidIndex(index)) { return false; }
    int64_t oldval = m_attr[0][index];
    int64_t newval = 0;
    for (uint32_t i = 1; i < COMMON_FIGHT_ATTR_GROUP_END; ++i)
    {
        newval += m_attr[i][index];
    }
    if (oldval == newval) { return true; }
    m_attr[0][index] = newval;
    mapchg[ANum] = newval;
    return true;
}

int64_t ComFightAttr::GetAttrGroup(uint32_t groupid, uint32_t ANum)
{
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightIndex(ANum);
    if (groupid < COMMON_FIGHT_ATTR_GROUP_END && ValidIndex(index))
    {
        return m_attr[groupid][index];
    }
    return 0;
}

bool ComFightAttr::GetAttrGroup(uint32_t groupid, MAP_UINT32_INT64 &mapattr)
{
    if (!ValidAttrGroup(groupid))
    {
        return false;
    }
    for (uint32_t i = 1; i < COMMON_FIGHT_ATTR_END; ++i)
    {
        uint32_t ANum = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightAttr(i);
        if (ANum > 0)
        {
            mapattr[ANum] = m_attr[groupid][i];
        }
    }
    return true;
}

bool ComFightAttr::AddAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool *chgflag)
{
    if (0 == val)
    {
        return true;
    }
    if (!ValidAttrGroup(groupid))
    {
        return false;
    }
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightIndex(ANum);
    if (!ValidIndex(index))
    {
        return false;
    }
    int64_t oldval = m_attr[groupid][index];
    int64_t newval = AddVal(oldval, val);
    if (newval == oldval)
    {
        return true;
    }
    m_attr[groupid][index] = newval;
    if (nullptr != chgflag)
    {
        *chgflag = true;
    }
    return true;
}

bool ComFightAttr::SetAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool *chgflag)
{
    if (!ValidAttrGroup(groupid))
    {
        return false;
    }
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightIndex(ANum);
    if (!ValidIndex(index))
    {
        return false;
    }
    int64_t oldval = m_attr[groupid][index];
    if (oldval == val)
    {
        return true;
    }
    m_attr[groupid][index] = val;
    if (nullptr != chgflag)
    {
        *chgflag = true;
    }
    return true;
}

bool ComFightAttr::SetAttrGroup(uint32_t groupid, const MAP_UINT32_INT64 &mapnew, MAP_UINT32_INT64 *pold)
{
    if (!ValidAttrGroup(groupid)) { return false; }
    for (uint32_t i = 1; i < COMMON_FIGHT_ATTR_END; ++i)
    {
        uint32_t ANum = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightAttr(i);
        if (!ValidAttr(ANum)) { continue; }
        int64_t newval = 0;
        auto iternew = mapnew.find(ANum);
        if (iternew != mapnew.end()) { newval = iternew->second; }
        if (newval != m_attr[groupid][i])
        {
            if (nullptr != pold) { pold->insert(make_pair(ANum, m_attr[groupid][i])); }
            m_attr[groupid][i] = newval;
        }
    }
    return true;
}

bool ComFightAttr::ClearAttrGroup(uint32_t groupid, MAP_UINT32_INT64 *pold)
{
    if (!ValidAttrGroup(groupid)) { return false; }
    for (uint32_t i = 1; i < COMMON_FIGHT_ATTR_END; ++i)
    {
        if (0 != m_attr[groupid][i])
        {
            if (nullptr != pold)
            {
                uint32_t ANum = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightAttr(i);
                if (ValidAttr(ANum)) { pold->insert(make_pair(ANum, m_attr[groupid][i])); }
            }
            m_attr[groupid][i] = 0;
        }
    }
    return true;
}

bool ComFightAttr::ValidAttr(uint32_t ANum)
{
    return NFAttrMgr::Instance(m_pObjPluginManager)->IsComFightAttr(ANum);
}

bool ComFightAttr::ValidIndex(uint8_t index)
{
    return (index > 0 && index < COMMON_FIGHT_ATTR_END);
}

bool ComFightAttr::ValidAttrGroup(uint32_t groupid)
{
    return NFAttrMgr::Instance(m_pObjPluginManager)->IsComFightAttrGroup(groupid);
}


//------------------------------------------   RoleFightAttr --------------------------------------------
RoleFightAttr::RoleFightAttr()
{
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT)
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

int RoleFightAttr::CreateInit()
{
    memset(m_attr, 0, sizeof(m_attr));
    memset(m_fightattr, 0, sizeof(m_fightattr));
    m_fightchg = false;
    m_lock = false;
    return 0;
}

int RoleFightAttr::ResumeInit()
{
    return 0;
}

RoleFightAttr::~RoleFightAttr()
{
}

bool RoleFightAttr::ValidAttr(uint32_t ANum)
{
    return NFAttrMgr::Instance(m_pObjPluginManager)->IsRoleFightAttr(ANum);
}

bool RoleFightAttr::ValidIndex(uint8_t index)
{
    return (index > 0 && index < ROLE_FIGHT_ATTR_END);
}

bool RoleFightAttr::ValidAttrGroup(uint32_t groupid)
{
    return (groupid > 0 && groupid < ROLE_FIGHT_ATTR_GROUP_END);
}

int64_t RoleFightAttr::GetAttr(uint32_t ANum)
{
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(ANum);
    if (ValidIndex(index)) { return m_attr[0][index]; }
    return 0;
}

void RoleFightAttr::GetAttr(MAP_UINT32_INT64 &mapattr)
{
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_END; ++i)
    {
        uint32_t ANum = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightAttr(i);
        if (ANum > 0)
        {
            mapattr[ANum] = m_attr[0][i];
        }
    }
}

void RoleFightAttr::CalcAttr(MAP_UINT32_INT64 &mapchg)
{
    if (IsLock()) { return; }
    SET_UINT8 setattr;
    MAP_UINT32_INT64 mapnew;
    MAP_UINT32_INT64 mapnewfight;
    static int64_t sumattr[ROLE_FIGHT_ATTR_END] = {0};
    static int64_t fight_sumattr[ROLE_FIGHT_ATTR_END] = {0};
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_END; ++i)
    {
        uint32_t ANum = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightAttr(i);
        if (!ValidAttr(ANum)) { continue; }
        int64_t oldval = m_attr[0][i];
        int64_t newval = 0;
        int64_t fightattrval = 0;
        for (uint32_t j = 1; j < ROLE_FIGHT_ATTR_GROUP_END; ++j)
        {
            newval += m_attr[j][i];
            if (IsFightAttrGroup(j)) { fightattrval += m_attr[j][i]; }
        }
        sumattr[i] = newval;
        fight_sumattr[i] = fightattrval;
        //
        if (newval != oldval)
        {
            mapnew[ANum] = newval;
            //
            uint8_t attr = NFAttrMgr::Instance(m_pObjPluginManager)->GetPerAddToAttr(ANum);
            if (attr > 0) { setattr.insert(attr); }
            else if (NFAttrMgr::Instance(m_pObjPluginManager)->GetAttrToPerAdd(ANum) > 0) { setattr.insert(ANum); }
        }
        if (fightattrval != m_fightattr[i])
        {
            mapnewfight[ANum] = fightattrval;
        }
    }
    //先计算总属性，再计算百分比属性
    for (auto &iter : setattr)
    {
        //百分比加成
        uint8_t peradd_attrid = NFAttrMgr::Instance(m_pObjPluginManager)->GetAttrToPerAdd(iter);
        if (peradd_attrid <= 0) { continue; }
        uint8_t peradd_attrindex = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(peradd_attrid);
        int64_t peradd_val = sumattr[peradd_attrindex];
        //百分比减免
        uint32_t perredu_attrid = NFAttrMgr::Instance(m_pObjPluginManager)->GetAttrToPerRedu(iter);
        int64_t perredu_val = 0;
        if (perredu_attrid > 0)
        {
            uint8_t perredu_attrindex = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(perredu_attrid);
            perredu_val = sumattr[perredu_attrindex];
        }
        uint8_t attr_index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(iter);
        int64_t attrval = sumattr[attr_index];
        //计算属性最终值
        int64_t perent_val = TEN_THOUSAND + peradd_val - perredu_val;
        if (perent_val < 1000) { perent_val = 1000; }
        int64_t new_attrval = (int64_t) (perent_val / F_TEN_THOUSAND * attrval);
        //
        if (new_attrval != m_attr[0][attr_index])
        {
            m_attr[0][attr_index] = new_attrval;
            mapchg[iter] = new_attrval;
        }
        //已经计算过，需要从 mapnew 中删除
        mapnew.erase(iter);
        
        //计算战力相关的属性
        if (NFAttrMgr::Instance(m_pObjPluginManager)->IsCalcFightAttr(iter))
        {
            int64_t fightadd_val = fight_sumattr[peradd_attrindex];
            int64_t fightredu_val = 0;
            if (perredu_attrid > 0)
            {
                uint8_t perredu_attrindex = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(perredu_attrid);
                fightredu_val = fight_sumattr[perredu_attrindex];
            }
            int64_t fightval = fight_sumattr[attr_index];
            int64_t fightperent_val = TEN_THOUSAND + fightadd_val - fightredu_val;
            if (fightperent_val < 1000) { fightperent_val = 1000; }
            int64_t new_fightattrval = (int64_t) (fightperent_val / F_TEN_THOUSAND * fightval);
            if (new_fightattrval != m_fightattr[attr_index])
            {
                m_fightattr[attr_index] = new_fightattrval;
                if (NFAttrMgr::Instance(m_pObjPluginManager)->IsCalcFightAttr(iter)) { m_fightchg = true; }
            }
            mapnewfight.erase(iter);
        }
    }
    for (auto &iternew : mapnew)
    {
        uint8_t idx = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(iternew.first);
        m_attr[0][idx] = iternew.second;
        mapchg[iternew.first] = iternew.second;
    }
    for (auto &iterf : mapnewfight)
    {
        uint8_t idx = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(iterf.first);
        m_fightattr[idx] = iterf.second;
        if (NFAttrMgr::Instance(m_pObjPluginManager)->IsCalcFightAttr(iterf.first)) { m_fightchg = true; }
    }
}

void RoleFightAttr::GetAttrGroupTotal(MAP_UINT32_INT64 &mapattr)
{
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_END; ++i)
    {
        uint32_t ANum = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightAttr(i);
        if (!ValidAttr(ANum)) { continue; }
        int64_t newval = 0;
        for (uint32_t j = 1; j < ROLE_FIGHT_ATTR_GROUP_END; ++j)
        {
            newval += m_attr[j][i];
        }
        mapattr[ANum] = newval;
    }
}

bool RoleFightAttr::CalcAttr(uint32_t ANum, MAP_UINT32_INT64 &mapchg)
{
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(ANum);
    if (!ValidIndex(index)) { return false; }
    if (IsLock()) { return true; }
    int64_t oldval = m_attr[0][index];
    int64_t newval = 0;
    int64_t fightattrval = 0;
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_GROUP_END; ++i)
    {
        newval += m_attr[i][index];
        if (IsFightAttrGroup(i)) { fightattrval += m_attr[i][index]; }
        
    }
    //
    bool calcflag = false; //ANum 属性是否已计算的 标记
    uint8_t attr = NFAttrMgr::Instance(m_pObjPluginManager)->GetPerAddToAttr(ANum);
    if (attr <= 0 && NFAttrMgr::Instance(m_pObjPluginManager)->GetAttrToPerAdd(ANum) > 0) { attr = ANum; }
    if (attr > 0)
    {
        uint8_t peradd_attrid = NFAttrMgr::Instance(m_pObjPluginManager)->GetAttrToPerAdd(attr);
        if (peradd_attrid > 0)
        {
            //百分比加成
            int64_t peradd_val = newval;
            int64_t fightadd_val = fightattrval;
            if (peradd_attrid != ANum) { GetAttrGroupTotal(peradd_attrid, peradd_val, fightadd_val); }
            //百分比减免
            uint32_t perredu_attrid = NFAttrMgr::Instance(m_pObjPluginManager)->GetAttrToPerRedu(attr);
            int64_t perredu_val = 0;
            int64_t fightredu_val = 0;
            if (perredu_attrid > 0) { GetAttrGroupTotal(perredu_attrid, perredu_val, fightredu_val); }
            //
            uint8_t attr_index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(attr);
            int64_t attrval = newval;
            int64_t fightval = fightattrval;
            if (attr != ANum) { GetAttrGroupTotal(attr, attrval, fightval); }
            //
            int64_t perent_val = TEN_THOUSAND + peradd_val - perredu_val;
            if (perent_val < 1000) { perent_val = 1000; }
            int64_t new_attrval = (int64_t) (perent_val / F_TEN_THOUSAND * attrval);
            if (new_attrval != m_attr[0][attr_index])
            {
                m_attr[0][attr_index] = new_attrval;
                mapchg[attr] = new_attrval;
            }
            //
            if (attr == ANum) { calcflag = true; }
            
            //战斗力相关的属性
            if (NFAttrMgr::Instance(m_pObjPluginManager)->IsCalcFightAttr(attr))
            {
                int64_t fight_perent_val = TEN_THOUSAND + fightadd_val - fightredu_val;
                if (fight_perent_val < 1000) { fight_perent_val = 1000; }
                int64_t new_fightattrval = (int64_t) (fight_perent_val / F_TEN_THOUSAND * fightval);
                //
                if (new_fightattrval != m_fightattr[attr_index])
                {
                    m_fightattr[attr_index] = new_fightattrval;
                    if (NFAttrMgr::Instance(m_pObjPluginManager)->IsCalcFightAttr(attr)) { m_fightchg = true; }
                }
            }
        }
    }
    if (!calcflag)
    {
        if (oldval != newval)
        {
            m_attr[0][index] = newval;
            mapchg[ANum] = newval;
            //
            if (fightattrval != m_fightattr[index])
            {
                m_fightattr[index] = fightattrval;
                if (NFAttrMgr::Instance(m_pObjPluginManager)->IsCalcFightAttr(ANum)) { m_fightchg = true; }
            }
        }
    }
    
    return true;
}

int64_t RoleFightAttr::GetAttrGroup(uint32_t groupid, uint32_t ANum)
{
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(ANum);
    if ((groupid < ROLE_FIGHT_ATTR_GROUP_END) && ValidIndex(index))
    {
        return m_attr[groupid][index];
    }
    return 0;
}

bool RoleFightAttr::GetAttrGroup(uint32_t groupid, MAP_UINT32_INT64 &mapattr)
{
    if (!ValidAttrGroup(groupid))
    {
        return false;
    }
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_END; ++i)
    {
        uint32_t ANum = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightAttr(i);
        if (ANum > 0)
        {
            mapattr[ANum] = m_attr[groupid][i];
        }
    }
    return true;
}

bool RoleFightAttr::AddAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool *chgflag)
{
    if (!ValidAttrGroup(groupid))
    {
        return false;
    }
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(ANum);
    if (!ValidIndex(index))
    {
        return false;
    }
    if (0 == val)
    {
        return true;
    }
    int64_t oldval = m_attr[groupid][index];
    int64_t newval = AddVal(oldval, val);
    if (newval == oldval)
    {
        return true;
    }
    m_attr[groupid][index] = newval;
    if (nullptr != chgflag)
    {
        *chgflag = true;
    }
    return true;
}

bool RoleFightAttr::SetAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool *chgflag)
{
    if (!ValidAttrGroup(groupid))
    {
        return false;
    }
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(ANum);
    if (!ValidIndex(index))
    {
        return false;
    }
    int64_t oldval = m_attr[groupid][index];
    if (oldval == val)
    {
        return true;
    }
    m_attr[groupid][index] = val;
    if (nullptr != chgflag)
    {
        *chgflag = true;
    }
    return true;
}

bool RoleFightAttr::SetAttrGroup(uint32_t groupid, const MAP_UINT32_INT64 &mapnew, MAP_UINT32_INT64 *pold)
{
    if (!ValidAttrGroup(groupid)) { return false; }
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_END; ++i)
    {
        uint32_t ANum = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightAttr(i);
        if (!ValidAttr(ANum)) { continue; }
        int64_t newval = 0;
        auto iternew = mapnew.find(ANum);
        if (iternew != mapnew.end()) { newval = iternew->second; }
        if (newval != m_attr[groupid][i])
        {
            if (nullptr != pold) { pold->insert(make_pair(ANum, m_attr[groupid][i])); }
            m_attr[groupid][i] = newval;
        }
    }
    return true;
}

bool RoleFightAttr::ClearAttrGroup(uint32_t groupid, MAP_UINT32_INT64 *pold)
{
    if (!ValidAttrGroup(groupid)) { return false; }
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_END; ++i)
    {
        if (0 != m_attr[groupid][i])
        {
            if (nullptr != pold)
            {
                uint32_t ANum = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightAttr(i);
                if (ValidAttr(ANum)) { pold->insert(make_pair(ANum, m_attr[groupid][i])); };
            }
            m_attr[groupid][i] = 0;
        }
    }
    return true;
}

void RoleFightAttr::GetFightAttr(MAP_UINT32_INT64 &mapattr)
{
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_END; ++i)
    {
        uint32_t ANum = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightAttr(i);
        if (NFAttrMgr::Instance(m_pObjPluginManager)->IsCalcFightAttr(ANum) && m_fightattr[i] > 0)
        {
            mapattr[i] = m_fightattr[i];
        }
    }
}

bool RoleFightAttr::IsFightAttrGroup(uint32_t groupid)
{
    return (proto_ff::EAttrGroup_Skill != groupid && proto_ff::EAttrGroup_Buff != groupid);
}

int64_t RoleFightAttr::GetAttrGroupTotal(uint32_t ANum)
{
    int64_t val = 0;
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_GROUP_END; ++i)
    {
        val += m_attr[i][ANum];
    }
    return val;
}

void RoleFightAttr::GetAttrGroupTotal(uint32_t ANum, int64_t &attrval, int64_t &fightval)
{
    attrval = 0;
    fightval = 0;
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_GROUP_END; ++i)
    {
        attrval += m_attr[i][ANum];
        if (IsFightAttrGroup(i)) { fightval += m_attr[i][ANum]; }
    }
}

int64_t RoleFightAttr::GetCalcFightAttrGroupTotal(uint32_t ANum)
{
    int64_t val = 0;
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_GROUP_END; ++i)
    {
        if (!IsFightAttrGroup(i)) { continue; }
        val += m_attr[i][ANum];
    }
    return val;
}

bool RoleFightAttr::Lock(const MAP_UINT32_INT64 &mapattr, MAP_UINT32_INT64 &mapchg)
{
    m_lock = true;
    for (auto &iter : mapattr)
    {
        if (!ValidAttr(iter.first)) { continue; }
        uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(iter.first);
        if (!ValidIndex(index)) { continue; }
        int64_t oldval = m_attr[0][index];
        if (oldval != iter.second)
        {
            m_attr[0][index] = iter.second;
            mapchg[iter.first] = iter.second;
        }
    }
    return true;
}

bool RoleFightAttr::UnLock(MAP_UINT32_INT64 &mapchg)
{
    m_lock = false;
    CalcAttr(mapchg);
    return true;
}


// ------------------------------------------- ComAttr -------------------------------------
ComAttr::ComAttr()
{
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT)
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
    
}

int ComAttr::CreateInit()
{
    memset(m_attr, 0, sizeof(m_attr));
    return 0;
}

int ComAttr::ResumeInit()
{
    return 0;
}

ComAttr::~ComAttr()
{

}

bool ComAttr::ValidAttr(uint32_t ANum)
{
    return NFAttrMgr::Instance(m_pObjPluginManager)->IsComAttr(ANum);
}

bool ComAttr::ValidIndex(uint16_t index)
{
    return (index > 0 && index < COMMON_ATTR_END);
}

int64_t ComAttr::GetAttr(uint32_t ANum)
{
    uint16_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetComIndex(ANum);
    if (ValidIndex(index)) { return m_attr[index]; }
    return 0;
}

bool ComAttr::AddAttr(uint32_t ANum, int64_t val, bool *chgflag)
{
    uint16_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetComIndex(ANum);
    if (!ValidIndex(index)) { return false; }
    if (0 == val) { return true; }
    int64_t oldval = m_attr[index];
    int64_t newval = AddVal(oldval, val);
    if (newval == oldval) { return true; }
    m_attr[index] = newval;
    if (nullptr != chgflag) { *chgflag = true; }
    return true;
}

bool ComAttr::SetAttr(uint32_t ANum, int64_t val, bool *chgflag)
{
    uint16_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetComIndex(ANum);
    if (!ValidIndex(index)) { return false; }
    m_attr[index] = val;
    if (nullptr != chgflag) { *chgflag = true; }
    return true;
}

//------------------------------------------------- RoleAttr ---------------------------------------
RoleAttr::RoleAttr()
{
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT)
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

RoleAttr::~RoleAttr()
{
}

int RoleAttr::CreateInit()
{
    memset(m_attr, 0, sizeof(m_attr));
    return 0;
}

int RoleAttr::ResumeInit()
{
    return 0;
}

bool RoleAttr::ValidAttr(uint32_t ANum)
{
    return NFAttrMgr::Instance(m_pObjPluginManager)->IsRoleAttr(ANum);
}

bool RoleAttr::ValidIndex(uint16_t index)
{
    return (index > 0 && index < ROLE_ATTR_END);
}

int64_t RoleAttr::GetAttr(uint32_t ANum)
{
    uint16_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleIndex(ANum);
    if (ValidIndex(index)) { return m_attr[index]; }
    return 0;
}

bool RoleAttr::AddAttr(uint32_t ANum, int64_t val, bool *chgflag)
{
    uint16_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleIndex(ANum);
    if (!ValidIndex(index)) { return false; }
    if (0 == val) { return true; }
    int64_t oldval = m_attr[index];
    int64_t newval = AddVal(oldval, val);
    if (newval == oldval) { return true; }
    m_attr[index] = newval;
    if (nullptr != chgflag) { *chgflag = true; }
    return true;
}

bool RoleAttr::SetAttr(uint32_t ANum, int64_t val, bool *chgflag)
{
    uint16_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleIndex(ANum);
    if (!ValidIndex(index)) { return false; }
    m_attr[index] = val;
    if (nullptr != chgflag) { *chgflag = true; }
    return true;
}