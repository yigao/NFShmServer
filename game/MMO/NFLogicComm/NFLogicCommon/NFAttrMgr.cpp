// -------------------------------------------------------------------------
//    @FileName         :    NFAttrMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFAttrMgr
//
// -------------------------------------------------------------------------

#include "NFAttrMgr.h"
#include "NFLogicShmTypeDefines.h"
#include "DescStore/AttributeAttributeDesc.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFAttrMgr, EOT_SERVER_COMMON_ATTR_MGR_ID, NFShmObj)

NFAttrMgr::NFAttrMgr()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    } else
    {
        ResumeInit();
    }
}

NFAttrMgr::~NFAttrMgr()
{
    UnInit();
}

int NFAttrMgr::CreateInit()
{
    //是否是计算战斗力相关的属性
    m_CalcFightAttr.resize(proto_ff::A_BASE_END + 1);
    
    //同步到客户端的属性
    //对应属性索引所在元素值为0表示不需要同步到客户端, 为1表示需要同步到客户端
    m_arySynClient.resize(proto_ff::A_COMMON_END);
    //需要广播到客户端的属性
    m_aryBroadClient.resize(proto_ff::A_COMMON_END);
    
    //玩家视野数据中用到的 属性ID
    m_setPlayerViewAttr.resize(proto_ff::A_COMMON_END);
    //怪物视野数据中用到的 属性ID
    m_setMonsViewAttr.resize(proto_ff::A_COMMON_END);
    //伙伴视野数据中用到的 属性ID
    m_setPartnerViewAttr.resize(proto_ff::A_COMMON_END);
    
    //百分比加成属性变化影响的 属性ID列表
    m_perAddAftList.resize(proto_ff::A_BASE_END + 1);
    //百分比减免属性变化影响的 属性ID列表
    m_perReduAftList.resize(proto_ff::A_BASE_END + 1);
    //属性ID对应的 百分比加成属性ID
    m_Attr_PerAdd.resize(proto_ff::A_BASE_END + 1);
    //属性ID对应的 百分比减免属性ID
    m_Attr_PerRedu.resize(proto_ff::A_BASE_END + 1);
    
    //所有有百分比 加成属性  的属性ID列表
    m_setAttrHasPer.resize(proto_ff::A_COMMON_END);
    //所有百分比属性ID列表
    m_setPercentAttr.resize(proto_ff::A_COMMON_END);
    //所有非百分比属性ID列表
    m_setNoPercentAttr.resize(proto_ff::A_COMMON_END);
    
    //通用的 配置表中的 战斗属性ID 和 程序中使用的 通用战斗属性数组的索引 之间的映射
    m_comIdToIndex.resize(proto_ff::A_FIGHT_END);
    m_comIndexToId.resize(proto_ff::A_FIGHT_END);
    
    //配置表中的 战斗属性 和 程序中使用的 角色战斗属性数组的索引 之间的映射
    m_roleIdToIndex.resize(proto_ff::A_FIGHT_END);
    m_roleIndexToId.resize(proto_ff::A_FIGHT_END);
    
    //通用的 配置表中的 普通属性ID 和 程序中使用的 通用普通属性数组的索引 之间的映射
    m_comNormal_IdToIndex.resize(proto_ff::A_COMMON_END);
    m_comNormal_IndexToId.resize(proto_ff::A_COMMON_END);
    
    //配置表中的 普通属性ID 和 程序中使用的 角色普通属性数组的索引 之间的映射
    m_roleNormal_IdToIndex.resize(proto_ff::A_COMMON_END);
    m_roleNormal_IndexToId.resize(proto_ff::A_COMMON_END);
    
    return 0;
}

int NFAttrMgr::ResumeInit()
{
    return 0;
}

bool NFAttrMgr::Init()
{
    if (!InitFightAttrToIndex())
    {
        return false;
    }
    
    if (!ProcessAttribute())
    {
        return false;
    }
    
    //战斗属性都需要同步到客户端，常规属性根据需求同步
    for (uint32_t i = 1; i < proto_ff::A_FIGHT_END; ++i)
    {
        if (GetRoleFightIndex(i) > 0)
        {
            m_arySynClient[i] = 1;
        }
    }
    
    //并不是所有的常规属性都需要同步到客户端的，有些常规属性只是用与系统逻辑中
    m_arySynClient[proto_ff::A_GOLD] = 1;
    m_arySynClient[proto_ff::A_MAGIC] = 1;
    m_arySynClient[proto_ff::A_DIA] = 1;
    m_arySynClient[proto_ff::A_BD_DIA] = 1;
    m_arySynClient[proto_ff::A_PRESTIGE] = 1;
    m_arySynClient[proto_ff::A_FIGHT] = 1;
    m_arySynClient[proto_ff::A_EXP] = 1;
    m_arySynClient[proto_ff::A_CUR_HP] = 1;
    m_arySynClient[proto_ff::A_PROF] = 1;
    m_arySynClient[proto_ff::A_LEVEL] = 1;
    m_arySynClient[proto_ff::A_VIP_LEVEL] = 1;
    m_arySynClient[proto_ff::A_HANGUP_TIME] = 1;
    m_arySynClient[proto_ff::A_ARENA_COIN] = 1;
    m_arySynClient[proto_ff::A_CAMP_ID] = 1;
    m_arySynClient[proto_ff::A_CONTRI] = 1;
    m_arySynClient[proto_ff::A_ESCORT_ID] = 1;
    m_arySynClient[proto_ff::A_TITLE_ID] = 1;
    m_arySynClient[proto_ff::A_GODEVIL_EXP] = 1;
    m_arySynClient[proto_ff::A_GODEVIL_LEV] = 1;
    m_arySynClient[proto_ff::A_BEST_AQ] = 1;
    m_arySynClient[proto_ff::A_BEST_LJ] = 1;
    m_arySynClient[proto_ff::PT_STAGE] = 1;
    m_arySynClient[proto_ff::A_HOLYBEAST_BUILD] = 1;
    m_arySynClient[proto_ff::A_BATTLEPASS_XIANCE] = 1;
    m_arySynClient[proto_ff::A_BATTLEPASS_BAODING] = 1;
    m_arySynClient[proto_ff::A_FINDTREASURE_SHENGJIFU] = 1;
    m_arySynClient[proto_ff::A_FINDTREASURE_BATTLE_SOUL] = 1;
    
    //需要广播的属性
    m_aryBroadClient[proto_ff::A_CUR_HP] = 1;
    m_aryBroadClient[proto_ff::A_MAX_HP] = 1;
    m_aryBroadClient[proto_ff::A_SPEED] = 1;
    m_aryBroadClient[proto_ff::A_TEAM_ID] = 1;
    m_aryBroadClient[proto_ff::A_TEAM_LEADER] = 1;
    m_aryBroadClient[proto_ff::A_VIP_LEVEL] = 1;
    m_aryBroadClient[proto_ff::A_CAMP_ID] = 1;
    m_aryBroadClient[proto_ff::A_ESCORT_ID] = 1;
    m_aryBroadClient[proto_ff::A_TITLE_ID] = 1;
    m_aryBroadClient[proto_ff::PT_STAGE] = 1;
    
    //玩家视野数据中用到的属性
    m_setPlayerViewAttr.insert(proto_ff::A_LEVEL);
    m_setPlayerViewAttr.insert(proto_ff::A_PROF);
    m_setPlayerViewAttr.insert(proto_ff::A_FIGHT);
    m_setPlayerViewAttr.insert(proto_ff::A_CUR_HP);
    m_setPlayerViewAttr.insert(proto_ff::A_MAX_HP);
    m_setPlayerViewAttr.insert(proto_ff::A_SPEED);
    m_setPlayerViewAttr.insert(proto_ff::A_TEAM_ID);
    m_setPlayerViewAttr.insert(proto_ff::A_TEAM_LEADER);
    m_setPlayerViewAttr.insert(proto_ff::A_VIP_LEVEL);
    m_setPlayerViewAttr.insert(proto_ff::A_FACTION_ID);
    m_setPlayerViewAttr.insert(proto_ff::A_ESCORT_ID);
    m_setPlayerViewAttr.insert(proto_ff::A_TITLE_ID);
    m_setPlayerViewAttr.insert(proto_ff::PT_STAGE);
    m_setPlayerViewAttr.insert(proto_ff::A_CAMP_ID);
    /*
    m_setPlayerViewAttr.insert(A_USE_TITLE);
    m_setPlayerViewAttr.insert(A_UNION_ID);
    m_setPlayerViewAttr.insert(A_TEAM_ID);*/
    
    //怪物视野数据中用到的属性
    m_setMonsViewAttr.insert(proto_ff::A_CUR_HP);
    m_setMonsViewAttr.insert(proto_ff::A_MAX_HP);
    m_setMonsViewAttr.insert(proto_ff::A_LEVEL);
    m_setMonsViewAttr.insert(proto_ff::A_SPEED);
    m_setMonsViewAttr.insert(proto_ff::A_CAMP_ID);
    
    //伙伴视野中用到的属性
    m_setPartnerViewAttr.insert(proto_ff::A_LEVEL);
    m_setPartnerViewAttr.insert(proto_ff::A_SPEED);
    
    //
    m_perAddAftList[proto_ff::A_SPEED_ADD] = proto_ff::A_SPEED;
    m_perAddAftList[proto_ff::A_HP_ADD] = proto_ff::A_MAX_HP;
    m_perAddAftList[proto_ff::A_ATK_ADD] = proto_ff::A_ATK;
    m_perAddAftList[proto_ff::A_DEF_ADD] = proto_ff::A_DEF;
    m_perAddAftList[proto_ff::A_FIVE_DAM_ADD] = proto_ff::A_FIVE_DAM;
    m_perAddAftList[proto_ff::A_FIVE_ARMOR_ADD] = proto_ff::A_FIVE_ARMOR;
    m_perAddAftList[proto_ff::A_MAG_WEAPON_SOUL_ADD] = proto_ff::A_MAG_WEAPON_SOUL;
    m_perAddAftList[proto_ff::A_CAPE_SOUL_ADD] = proto_ff::A_CAPE_SOUL;
    m_perAddAftList[proto_ff::A_SKY_ADD] = proto_ff::A_SKY;
    m_perAddAftList[proto_ff::A_MAG_SHIELD_ADD] = proto_ff::A_MAG_SHIELD;
    m_perAddAftList[proto_ff::A_MAG_ATK_ADD] = proto_ff::A_MAG_ATK;
    m_perAddAftList[proto_ff::A_MAG_DEF_ADD] = proto_ff::A_MAG_DEF;
    m_perAddAftList[proto_ff::A_SHIELD] = proto_ff::A_GOD_SHIELD;
    //
    m_perReduAftList[proto_ff::A_MAG_WEAPON_SOUL_REDU] = proto_ff::A_MAG_WEAPON_SOUL;
    m_perReduAftList[proto_ff::A_CAPE_SOUL_REDU] = proto_ff::A_CAPE_SOUL;
    
    //
    for (uint32_t k = proto_ff::A_NONE + 1; k <= proto_ff::A_BASE_END; ++k)
    {
        if (m_perAddAftList[k] > proto_ff::A_NONE && m_perAddAftList[k] <= proto_ff::A_BASE_END)
        {
            m_Attr_PerAdd[m_perAddAftList[k]] = k;
            m_setAttrHasPer.insert(m_perAddAftList[k]);
        }
        if (m_perReduAftList[k] > proto_ff::A_NONE && m_perReduAftList[k] <= proto_ff::A_BASE_END)
        {
            m_Attr_PerRedu[m_perReduAftList[k]] = k;
        }
    }
    return true;
}

bool NFAttrMgr::UnInit()
{
    return true;
}

//是否是战斗属性ID
bool NFAttrMgr::ValidFightAttrId(uint32_t ANum)
{
    return (ANum > 0 && ANum < proto_ff::A_FIGHT_END);
}

//是否是普通属性ID
bool NFAttrMgr::ValidCommonAttrId(uint32_t ANum)
{
    return (ANum > proto_ff::A_FIGHT_END && ANum < proto_ff::A_COMMON_END);
}


//是否是 通用战斗属性ID
bool NFAttrMgr::IsComFightAttr(uint32_t ANum)
{
    return (GetComFightIndex(ANum) > 0);
}

//是否是通用的战斗属性组ID
bool NFAttrMgr::IsComFightAttrGroup(uint32_t groupid)
{
    return (groupid > 0 && groupid < COMMON_FIGHT_ATTR_GROUP_END);
}

//根据 战斗属性ID获取 通用战斗属性数组的索引
uint8_t NFAttrMgr::GetComFightIndex(uint32_t ANum)
{
    if (ANum > 0 && ANum < proto_ff::A_FIGHT_END)
        return m_comIdToIndex[ANum];
    return 0;
}

//根据 通用战斗属性数组的索引 获取 战斗属性ID
uint32_t NFAttrMgr::GetComFightAttr(uint8_t index)
{
    if (index > 0 && index < proto_ff::A_FIGHT_END)
        return m_comIndexToId[index];
    return 0;
}


//是否是 角色战斗属性ID
bool NFAttrMgr::IsRoleFightAttr(uint32_t ANum)
{
    return (GetRoleFightIndex(ANum) > 0);
}

//是否是 角色战斗属性组ID
bool NFAttrMgr::IsRoleFightAttrGroup(uint32_t groupid)
{
    return (groupid > 0 && groupid < ROLE_FIGHT_ATTR_GROUP_END);
}

//根据 战斗属性ID获取 角色战斗属性数组的索引
uint8_t NFAttrMgr::GetRoleFightIndex(uint32_t ANum)
{
    if (ANum > 0 && ANum < proto_ff::A_FIGHT_END)
        return m_roleIdToIndex[ANum];
    return 0;
}

//根据 角色战斗属性数组的索引 获取 战斗属性ID
uint32_t NFAttrMgr::GetRoleFightAttr(uint8_t index)
{
    if (index > 0 && index < proto_ff::A_FIGHT_END)
        return m_roleIndexToId[index];
    return 0;
}


//是否是通用  普通属性ID
bool NFAttrMgr::IsComAttr(uint32_t ANum)
{
    return (GetComIndex(ANum) > 0);
}

//根据属性ID 获取普通属性数组的索引
uint16_t NFAttrMgr::GetComIndex(uint32_t ANum)
{
    if (ANum > 0 && ANum < proto_ff::A_COMMON_END)
        return m_comNormal_IdToIndex[ANum];
    return 0;
}

//根据 普通属性数组的索引 获取属性ID
uint32_t NFAttrMgr::GetComAttr(uint16_t index)
{
    if (index > 0 && index < proto_ff::A_COMMON_END)
        return m_comNormal_IndexToId[index];
    return 0;
}


//是否是角色  普通属性ID
bool NFAttrMgr::IsRoleAttr(uint32_t ANum)
{
    return (GetRoleIndex(ANum) > 0);
}

//根据属性ID 获取角色 普通属性数组的索引
uint16_t NFAttrMgr::GetRoleIndex(uint32_t ANum)
{
    if (ANum > 0 && ANum < proto_ff::A_COMMON_END)
        return m_roleNormal_IdToIndex[ANum];
    return 0;
}

//根据 角色普通属性数组的索引 获取属性ID
uint32_t NFAttrMgr::GetRoleAttr(uint16_t index)
{
    if (index > 0 && index < proto_ff::A_COMMON_END)
        return m_roleNormal_IndexToId[index];
    return 0;
}

//获取百分比属性对应的加成的属性ID
uint32_t NFAttrMgr::GetPerAddToAttr(uint32_t ANum)
{
    if (ANum > 0 && ANum <= proto_ff::A_BASE_END)
        return m_perAddAftList[ANum];
    return 0;
}

//获取百分比属性对应的减免的属性ID
uint32_t NFAttrMgr::GetPerReduToAttr(uint32_t ANum)
{
    if (ANum > 0 && ANum <= proto_ff::A_BASE_END)
        return m_perReduAftList[ANum];
    return 0;
}

//获取属性对应的 百分比加成属性属性ID
uint32_t NFAttrMgr::GetAttrToPerAdd(uint32_t ANum)
{
    if (ANum > 0 && ANum <= proto_ff::A_BASE_END)
        return m_Attr_PerAdd[ANum];
    return 0;
}

//获取属性对应的 百分比减免属性属性ID
uint32_t NFAttrMgr::GetAttrToPerRedu(uint32_t ANum)
{
    if (ANum > 0 && ANum <= proto_ff::A_BASE_END)
        return m_Attr_PerRedu[ANum];
    return 0;
}

//所有 有百分比加成属性的 属性ID列表
const NFShmHashSet<uint8_t, proto_ff::A_COMMON_END> &NFAttrMgr::AttrHasPer()
{
    return m_setAttrHasPer;
}

//是否是计算战斗力相关的属性
bool NFAttrMgr::IsCalcFightAttr(uint32_t ANum)
{
    if (ANum <= proto_ff::A_NONE || ANum > proto_ff::A_BASE_END)
        return false;
    return (1 == m_CalcFightAttr[ANum]);
}

IFightAttr *NFAttrMgr::MakeFightAttrObj(EAttrType type)
{
    IFightAttr *pattr = nullptr;
    switch (type)
    {
        case EAttrType::common:pattr = dynamic_cast<IFightAttr *>(ComFightAttr::CreateObj(m_pObjPluginManager));
            break;
        case EAttrType::role:pattr = dynamic_cast<IFightAttr *>(RoleFightAttr::CreateObj(m_pObjPluginManager));
            break;
        default:break;
    }
    return pattr;
}

void NFAttrMgr::FreeFightAttrObj(IFightAttr *obj)
{
    FindModule<NFISharedMemModule>()->DestroyObj(obj);
}

IAttr *NFAttrMgr::MakeAttrObj(EAttrType type)
{
    IAttr *pattr = nullptr;
    switch (type)
    {
        case EAttrType::common:pattr = dynamic_cast<IAttr *>(FindModule<NFISharedMemModule>()->CreateObj<ComAttr>());
            break;
        case EAttrType::role:pattr = dynamic_cast<IAttr *>(FindModule<NFISharedMemModule>()->CreateObj<RoleAttr>());
            break;
        default:break;
    }
    return pattr;
}

void NFAttrMgr::FreeAttrObj(IAttr *obj)
{
    FindModule<NFISharedMemModule>()->DestroyObj(obj);
}


//是否需要同步到客户端的属性
bool NFAttrMgr::IsSynClient(uint32_t ANum)
{
    if (ANum > 0 && ANum < proto_ff::A_COMMON_END)
    {
        return m_arySynClient[ANum];
    }
    return false;
}

//是否需要广播到客户端
bool NFAttrMgr::IsBroadClient(uint32_t ANum)
{
    if (ANum > 0 && ANum < proto_ff::A_COMMON_END)
    {
        return m_aryBroadClient[ANum];
    }
    return false;
}

//获取玩家视野数据中用到的属性ID
const NFShmHashSet<int32_t, proto_ff::A_COMMON_END> &NFAttrMgr::PlayerViewAttr()
{
    return m_setPlayerViewAttr;
}

//获取怪物视野数据中用到的属性ID
const NFShmHashSet<int32_t, proto_ff::A_COMMON_END> &NFAttrMgr::MonViewAttr()
{
    return m_setMonsViewAttr;
}

//获取怪物视野数据中用到的属性ID
const NFShmHashSet<int32_t, proto_ff::A_COMMON_END> &NFAttrMgr::PartnerViewAttr()
{
    return m_setPartnerViewAttr;
}

//初始化战斗属性和索引之间的映射
bool NFAttrMgr::InitFightAttrToIndex()
{
    /* attribute 配置表中，通用战斗属性ID范围 1-70
       71 - 117 属于角色专属的战斗属性ID
       后续怪物和玩家都有可能扩展各自专属的战斗属性ID
       扩展之后，可能会出现怪物的战斗属性会存在几段的情况
       这里是把分段后的属性ID 映射到一个连续的属性数组中
    */
    
    //通用的属性ID范围 1-70，如果后续有新增或调整，这里需要跟着变动
    uint8_t comfightindex = 1;
    uint8_t i = 1;
    for (; i <= 70; ++i)
    {
        if (comfightindex >= COMMON_FIGHT_ATTR_END)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] AttrMgr::InitFightAttrToIndex.... comfightindex error... comindex:{}, attrid:{} ",
                       comfightindex, i);
            return false;
        }
        m_comIdToIndex[i] = comfightindex;
        m_comIndexToId[comfightindex] = i;
        ++comfightindex;
    }
    m_comIdToIndex[proto_ff::A_SPEED] = comfightindex;
    m_comIndexToId[comfightindex] = i++;
    ++comfightindex;
    //
    m_comIdToIndex[proto_ff::A_COM_SHIELD] = comfightindex;
    m_comIndexToId[comfightindex] = i++;
    ++comfightindex;
    
    
    //角色属性ID 范围 1-130, 如果后续有新增或调整，这里需要跟着变动
    uint8_t rolefightindex = 1;
    for (uint8_t j = 1; j <= 130; ++j)
    {
        if (rolefightindex >= ROLE_FIGHT_ATTR_END)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] AttrMgr::InitFightAttrToIndex.... roleindex error... roleindex:{}, attrid:{} ", rolefightindex,
                       j);
            return false;
        }
        
        m_roleIdToIndex[j] = rolefightindex;
        m_roleIndexToId[rolefightindex] = j;
        ++rolefightindex;
    }
    
    /* 普通属性ID 从 201 - 400 之间
    */
    uint16_t comnormal_index = 1;
    m_comNormal_IdToIndex[proto_ff::A_FIGHT] = comnormal_index;
    m_comNormal_IndexToId[comnormal_index++] = proto_ff::A_FIGHT;
    //
    m_comNormal_IdToIndex[proto_ff::A_CUR_HP] = comnormal_index;
    m_comNormal_IndexToId[comnormal_index++] = proto_ff::A_CUR_HP;
    //
    m_comNormal_IdToIndex[proto_ff::A_PROF] = comnormal_index;
    m_comNormal_IndexToId[comnormal_index++] = proto_ff::A_PROF;
    //
    m_comNormal_IdToIndex[proto_ff::A_LEVEL] = comnormal_index;
    m_comNormal_IndexToId[comnormal_index++] = proto_ff::A_LEVEL;
    
    m_comNormal_IdToIndex[proto_ff::A_CAMP_ID] = comnormal_index;
    m_comNormal_IndexToId[comnormal_index++] = proto_ff::A_CAMP_ID;
    
    m_comNormal_IdToIndex[proto_ff::A_TEAM_ID] = comnormal_index;
    m_comNormal_IndexToId[comnormal_index++] = proto_ff::A_TEAM_ID;
    
    //
    if (comnormal_index > COMMON_ATTR_END)
    {
        
        NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] AttrMgr::InitFightAttrToIndex.... comnormal_index error... comnormal_index:{} ", comnormal_index);
        return false;
    }
    //
    uint16_t rolenormal_index = 1;
    for (uint32_t n = 201; n < proto_ff::A_COMMON_END; ++n)
    {
        if (rolenormal_index >= ROLE_ATTR_END)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "[common] AttrMgr::InitFightAttrToIndex.... rolenormal_index error... rolenormal_index:{}, n:{}  ",
                       comnormal_index, n);
            return false;
        }
        m_roleNormal_IdToIndex[n] = rolenormal_index;
        m_roleNormal_IndexToId[rolenormal_index] = n;
        ++rolenormal_index;
    }
    
    return true;
}

bool NFAttrMgr::ProcessAttribute()
{
    //
    auto pResDesc = AttributeAttributeDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
    CHECK_NULL(pResDesc);
    
    for (auto iter = pResDesc->begin(); iter != pResDesc->end(); iter++)
    {
        if (iter->m_id > proto_ff::A_BASE_END)
            continue;
        //
        int64_t power = iter->m_power * 100;
        if (power > 0)
            m_CalcFightAttr[iter->m_id] = 1;
        else
            m_CalcFightAttr[iter->m_id] = 0;
        //
        if (iter->m_percent > 0)
            m_setPercentAttr.insert(iter->m_id);
        else
            m_setNoPercentAttr.insert(iter->m_id);
    }
    
    return true;
}