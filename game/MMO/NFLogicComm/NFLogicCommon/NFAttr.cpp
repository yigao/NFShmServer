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
#include "NFLogicShmTypeDefines.h"


int64_t AddVal(int64_t oldval, int64_t val)
{
    if (0 == val) return oldval;
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
IMPLEMENT_IDCREATE_WITHTYPE(ComFightAttr, EOT_SERVER_COMMON_COMFIGHT_ATTR_ID, NFShmObj)

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
    for (uint32_t i = 0; i < COMMON_FIGHT_ATTR_GROUP_END; ++i)
    {
        memset(m_attr[i], 0, sizeof(int64_t) * COMMON_FIGHT_ATTR_END);
    }
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
    if (ValidIndex(index)) return m_attr[0][index];
    return 0;
}

void ComFightAttr::GetAttr(std::unordered_map<uint32_t, int64_t> &mapattr)
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

void ComFightAttr::CalcAttr(std::unordered_map<uint32_t, int64_t> &mapchg)
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

bool ComFightAttr::CalcAttr(uint32_t ANum, bool *chgflag)
{
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightIndex(ANum);
    if (!ValidIndex(index)) return false;
    int64_t oldval = m_attr[0][index];
    int64_t newval = 0;
    for (uint32_t i = 1; i < COMMON_FIGHT_ATTR_GROUP_END; ++i)
    {
        newval += m_attr[i][index];
    }
    if (oldval == newval) return true;
    m_attr[0][index] = newval;
    if (nullptr != chgflag) *chgflag = true;
    return true;
}

int64_t ComFightAttr::GetAttrGroup(uint32_t groupid, uint32_t ANum)
{
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightIndex(ANum);
    if (groupid < COMMON_FIGHT_ATTR_GROUP_END && ValidIndex(index)) return m_attr[groupid][index];
    return 0;
}

bool ComFightAttr::GetAttrGroup(uint32_t groupid, MAP_UINT32_INT64 &mapattr)
{
    if (!ValidAttrGroup(groupid)) return false;
    for (uint32_t i = 1; i < COMMON_FIGHT_ATTR_END; ++i)
    {
        uint32_t ANum = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightAttr(i);
        if (ANum > 0) mapattr[ANum] = m_attr[groupid][i];
    }
    return true;
}

bool ComFightAttr::AddAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool *chgflag)
{
    if (0 == val) return true;
    if (!ValidAttrGroup(groupid)) return false;
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightIndex(ANum);
    if (!ValidIndex(index)) return false;
    int64_t oldval = m_attr[groupid][index];
    int64_t newval = AddVal(oldval, val);
    if (newval == oldval) return true;
    m_attr[groupid][index] = newval;
    if (nullptr != chgflag) *chgflag = true;
    return true;
}

bool ComFightAttr::SetAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool *chgflag)
{
    if (!ValidAttrGroup(groupid)) return false;
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightIndex(ANum);
    if (!ValidIndex(index)) return false;
    int64_t oldval = m_attr[groupid][index];
    if (oldval == val) return true;
    m_attr[groupid][index] = val;
    if (nullptr != chgflag) *chgflag = true;
    return true;
}

bool ComFightAttr::ClearAttrGroup(uint32_t groupid, bool *chgflag)
{
    if (!ValidAttrGroup(groupid)) return false;
    for (uint32_t i = 1; i < COMMON_FIGHT_ATTR_END; ++i)
    {
        if (0 != m_attr[groupid][i])
        {
            m_attr[groupid][i] = 0;
            if (nullptr != chgflag) *chgflag = true;
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
IMPLEMENT_IDCREATE_WITHTYPE(RoleFightAttr, EOT_SERVER_COMMON_ROLEFIGHT_ATTR_ID, NFShmObj)

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
    for (uint32_t i = 0; i < ROLE_FIGHT_ATTR_GROUP_END; ++i)
    {
        memset(m_attr[i], 0, sizeof(int64_t) * ROLE_FIGHT_ATTR_END);
    }
    memset(m_fightattr, 0, sizeof(int64_t) * ROLE_FIGHT_ATTR_END);
    m_fightchg = false;
    return 0;
}

int RoleFightAttr::ResumeInit()
{
    return 0;
}

RoleFightAttr::~RoleFightAttr()
{
    for (uint32_t i = 0; i < ROLE_FIGHT_ATTR_GROUP_END; ++i)
    {
        memset(m_attr[i], 0, sizeof(int64_t) * ROLE_FIGHT_ATTR_END);
    }
    memset(m_fightattr, 0, sizeof(int64_t) * ROLE_FIGHT_ATTR_END);
    m_fightchg = false;
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
    return NFAttrMgr::Instance(m_pObjPluginManager)->IsRoleFightAttrGroup(groupid);
}

int64_t RoleFightAttr::GetAttr(uint32_t ANum)
{
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(ANum);
    if (ValidIndex(index)) return m_attr[0][index];
    return 0;
}

void RoleFightAttr::GetAttr(MAP_UINT32_INT64 &mapattr)
{
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_END; ++i)
    {
        uint32_t ANum = NFAttrMgr::Instance(m_pObjPluginManager)->GetComFightAttr(i);
        if (ANum > 0)
        {
            mapattr[ANum] = m_attr[0][i];
        }
    }
}

void RoleFightAttr::CalcAttr(std::unordered_map<uint32_t, int64_t> &mapchg)
{
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_END; ++i)
    {
        int64_t oldval = m_attr[0][i];
        int64_t newval = 0;
        int64_t fightattrval = 0;
        for (uint32_t j = 1; j < ROLE_FIGHT_ATTR_GROUP_END; ++j)
        {
            newval += m_attr[j][i];
            if (IsFightAttrGroup(j)) fightattrval += m_attr[j][i];
        }
        if (newval != oldval)
        {
            m_attr[0][i] = newval;
            mapchg[i] = newval;
        }
        if (fightattrval != m_fightattr[i])
        {
            m_fightattr[i] = fightattrval;
            m_fightchg = true;
        }

    }
}

bool RoleFightAttr::CalcAttr(uint32_t ANum, bool *chgflag)
{
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(ANum);
    if (!ValidIndex(index)) return false;
    int64_t oldval = m_attr[0][index];
    int64_t newval = 0;
    int64_t fightattrval = 0;
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_GROUP_END; ++i)
    {
        newval += m_attr[i][index];
        if (IsFightAttrGroup(i)) fightattrval += m_attr[i][index];

    }
    if (oldval != newval)
    {
        m_attr[0][index] = newval;
        if (nullptr != chgflag) *chgflag = true;
    }
    if (fightattrval != m_fightattr[index])
    {
        m_fightattr[index] = fightattrval;
        m_fightchg = true;
    }
    return true;
}

int64_t RoleFightAttr::GetAttrGroup(uint32_t groupid, uint32_t ANum)
{
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(ANum);
    if ((groupid < ROLE_FIGHT_ATTR_GROUP_END) && ValidIndex(index)) return m_attr[groupid][index];
    return 0;
}

bool RoleFightAttr::GetAttrGroup(uint32_t groupid, MAP_UINT32_INT64 &mapattr)
{
    if (!ValidAttrGroup(groupid)) return false;
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_END; ++i)
    {
        uint32_t ANum = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightAttr(i);
        if (ANum > 0) mapattr[ANum] = m_attr[groupid][i];
    }
    return true;
}

bool RoleFightAttr::AddAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool *chgflag)
{
    if (!ValidAttrGroup(groupid)) return false;
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(ANum);
    if (!ValidIndex(index)) return false;
    if (0 == val) return true;
    int64_t oldval = m_attr[groupid][index];
    int64_t newval = AddVal(oldval, val);
    if (newval == oldval) return true;
    m_attr[groupid][index] = newval;
    if (nullptr != chgflag) *chgflag = true;
    return true;
}

bool RoleFightAttr::SetAttrGroup(uint32_t groupid, uint32_t ANum, int64_t val, bool *chgflag)
{
    if (!ValidAttrGroup(groupid)) return false;
    uint8_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleFightIndex(ANum);
    if (!ValidIndex(index)) return false;
    int64_t oldval = m_attr[groupid][index];
    if (oldval == val) return true;
    m_attr[groupid][index] = val;
    if (nullptr != chgflag) *chgflag = true;
    return true;
}

bool RoleFightAttr::ClearAttrGroup(uint32_t groupid, bool *chgflag)
{
    if (!ValidAttrGroup(groupid)) return false;
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_END; ++i)
    {
        if (0 != m_attr[groupid][i])
        {
            m_attr[groupid][i] = 0;
            if (nullptr != chgflag) *chgflag = true;
        }
    }
    return true;
}

void RoleFightAttr::GetFightAttr(MAP_UINT32_INT64 &mapattr)
{
    for (uint32_t i = 1; i < ROLE_FIGHT_ATTR_END; ++i)
    {
        if (m_fightattr[i] > 0) mapattr[i] = m_fightattr[i];
    }
}

bool RoleFightAttr::IsFightAttrGroup(uint32_t groupid)
{
    return (proto_ff::EAttrGroup_Skill != groupid && proto_ff::EAttrGroup_Buff != groupid);
}








// ------------------------------------------- ComAttr -------------------------------------
IMPLEMENT_IDCREATE_WITHTYPE(ComAttr, EOT_SERVER_COMMON_COM_ATTR_ID, NFShmObj)

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
    if (ValidIndex(index)) return m_attr[index];
    return 0;
}

bool ComAttr::AddAttr(uint32_t ANum, int64_t val, bool *chgflag)
{
    uint16_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetComIndex(ANum);

    if (!ValidIndex(index)) return false;

    if (0 == val) return true;

    int64_t oldval = m_attr[index];
    int64_t newval = AddVal(oldval, val);

    if (newval == oldval) return true;

    m_attr[index] = newval;

    if (nullptr != chgflag) *chgflag = true;

    return true;
}

bool ComAttr::SetAttr(uint32_t ANum, int64_t val, bool *chgflag)
{
    uint16_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetComIndex(ANum);

    if (!ValidIndex(index)) return false;

    m_attr[index] = val;

    if (nullptr != chgflag) *chgflag = true;

    return true;
}






//------------------------------------------------- RoleAttr ---------------------------------------
IMPLEMENT_IDCREATE_WITHTYPE(RoleAttr, EOT_SERVER_COMMON_ROLE_ATTR_ID, NFShmObj)

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
    memset(m_attr, 0, sizeof(m_attr));
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
    if (ValidIndex(index)) return m_attr[index];
    return 0;
}

bool RoleAttr::AddAttr(uint32_t ANum, int64_t val, bool *chgflag)
{
    uint16_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleIndex(ANum);
    if (!ValidIndex(index)) return false;
    if (0 == val) return true;
    int64_t oldval = m_attr[index];
    int64_t newval = AddVal(oldval, val);
    if (newval == oldval) return true;
    m_attr[index] = newval;
    if (nullptr != chgflag) *chgflag = true;
    return true;
}

bool RoleAttr::SetAttr(uint32_t ANum, int64_t val, bool *chgflag)
{
    uint16_t index = NFAttrMgr::Instance(m_pObjPluginManager)->GetRoleIndex(ANum);
    if (!ValidIndex(index)) return false;
    m_attr[index] = val;
    if (nullptr != chgflag) *chgflag = true;
    return true;
}
