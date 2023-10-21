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

IMPLEMENT_IDCREATE_WITHTYPE(NFAttrMgr, EOT_SERVER_COMMON_ATTR_MGR_ID, NFShmObj)

NFAttrMgr::NFAttrMgr()
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

NFAttrMgr::~NFAttrMgr()
{
    UnInit();
}

int NFAttrMgr::CreateInit()
{
    memset(m_arySynClient, 0, sizeof(m_arySynClient));
    memset(m_aryBroadClient, 0, sizeof(m_aryBroadClient));

    memset(m_comIdToIndex, 0, sizeof(m_comIdToIndex));
    memset(m_comIndexToId, 0, sizeof(m_comIndexToId));
    memset(m_roleIdToIndex, 0, sizeof(m_roleIdToIndex));
    memset(m_roleIndexToId, 0, sizeof(m_roleIndexToId));

    memset(m_comNormal_IdToIndex, 0, sizeof(m_comNormal_IdToIndex));
    memset(m_comNormal_IndexToId, 0, sizeof(m_comNormal_IndexToId));
    memset(m_roleNormal_IdToIndex, 0, sizeof(m_roleNormal_IdToIndex));
    memset(m_roleNormal_IndexToId, 0, sizeof(m_roleNormal_IndexToId));

    Init();
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

    //需要广播的属性
    m_aryBroadClient[proto_ff::A_CUR_HP] = 1;
    m_aryBroadClient[proto_ff::A_MAX_HP] = 1;
    m_aryBroadClient[proto_ff::A_SPEED] = 1;
    m_aryBroadClient[proto_ff::A_TEAM_ID] = 1;
    m_aryBroadClient[proto_ff::A_VIP_LEVEL] = 1;
    m_aryBroadClient[proto_ff::A_CAMP_ID] = 1;
    m_aryBroadClient[proto_ff::A_ESCORT_ID] = 1;
    m_aryBroadClient[proto_ff::A_TITLE_ID] = 1;

    //玩家视野数据中用到的属性
    m_setPlayerViewAttr.insert(proto_ff::A_LEVEL);
    m_setPlayerViewAttr.insert(proto_ff::A_PROF);
    m_setPlayerViewAttr.insert(proto_ff::A_FIGHT);
    m_setPlayerViewAttr.insert(proto_ff::A_CUR_HP);
    m_setPlayerViewAttr.insert(proto_ff::A_MAX_HP);
    m_setPlayerViewAttr.insert(proto_ff::A_SPEED);
    m_setPlayerViewAttr.insert(proto_ff::A_TEAM_ID);
    m_setPlayerViewAttr.insert(proto_ff::A_VIP_LEVEL);
    m_setPlayerViewAttr.insert(proto_ff::A_FACTION_ID);
    m_setPlayerViewAttr.insert(proto_ff::A_ESCORT_ID);
    m_setPlayerViewAttr.insert(proto_ff::A_TITLE_ID);
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


    for(int i = 0; i < proto_ff::A_COMMON_END; i++)
    {
        if (m_arySynClient[i] == 1)
        {
            m_setGameSyncAttr.insert(i);
        }
    }

    for(int i = 0; i < proto_ff::A_COMMON_END; i++)
    {
        if (m_aryBroadClient[i] == 1)
        {
            m_setGameSyncAttr.insert(i);
        }
    }

    m_setGameSyncAttr.insert(m_setPlayerViewAttr.begin(), m_setPlayerViewAttr.end());
    return true;
}

bool NFAttrMgr::UnInit()
{
    memset(m_arySynClient, 0, sizeof(m_arySynClient[0]) * proto_ff::A_COMMON_END);
    memset(m_aryBroadClient, 0, sizeof(m_aryBroadClient[0]) * proto_ff::A_COMMON_END);
    m_setPlayerViewAttr.clear();
    m_setMonsViewAttr.clear();
    m_setPartnerViewAttr.clear();

    memset(m_comIdToIndex, 0, sizeof(m_comIdToIndex));
    memset(m_comIndexToId, 0, sizeof(m_comIndexToId));
    memset(m_roleIdToIndex, 0, sizeof(m_roleIdToIndex));
    memset(m_roleIndexToId, 0, sizeof(m_roleIndexToId));

    memset(m_comNormal_IdToIndex, 0, sizeof(m_comNormal_IdToIndex));
    memset(m_comNormal_IndexToId, 0, sizeof(m_comNormal_IndexToId));
    memset(m_roleNormal_IdToIndex, 0, sizeof(m_roleNormal_IdToIndex));
    memset(m_roleNormal_IndexToId, 0, sizeof(m_roleNormal_IndexToId));

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
    if (ANum > 0 && ANum < proto_ff::A_FIGHT_END) return m_comIdToIndex[ANum];
    return 0;
}

//根据 通用战斗属性数组的索引 获取 战斗属性ID
uint32_t NFAttrMgr::GetComFightAttr(uint8_t index)
{
    if (index > 0 && index < proto_ff::A_FIGHT_END) return m_comIndexToId[index];
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
    if (ANum > 0 && ANum < proto_ff::A_FIGHT_END) return m_roleIdToIndex[ANum];
    return 0;
}

//根据 角色战斗属性数组的索引 获取 战斗属性ID
uint32_t NFAttrMgr::GetRoleFightAttr(uint8_t index)
{
    if (index > 0 && index < proto_ff::A_FIGHT_END) return m_roleIndexToId[index];
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
    if (ANum > 0 && ANum < proto_ff::A_COMMON_END) return m_comNormal_IdToIndex[ANum];
    return 0;
}

//根据 普通属性数组的索引 获取属性ID
uint32_t NFAttrMgr::GetComAttr(uint16_t index)
{
    if (index > 0 && index < proto_ff::A_COMMON_END) return m_comNormal_IndexToId[index];
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
    if (ANum > 0 && ANum < proto_ff::A_COMMON_END) return m_roleNormal_IdToIndex[ANum];
    return 0;
}

//根据 角色普通属性数组的索引 获取属性ID
uint32_t NFAttrMgr::GetRoleAttr(uint16_t index)
{
    if (index > 0 && index < proto_ff::A_COMMON_END) return m_roleNormal_IndexToId[index];
    return 0;
}

IFightAttr *NFAttrMgr::MakeFightAttrObj(EAttrType type)
{
    IFightAttr *pattr = nullptr;
    switch (type)
    {
        case EAttrType::common:
            pattr = dynamic_cast<IFightAttr *>(FindModule<NFISharedMemModule>()->CreateObj<ComFightAttr>());
            break;
        case EAttrType::role:
            pattr = dynamic_cast<IFightAttr *>(FindModule<NFISharedMemModule>()->CreateObj<RoleFightAttr>());
            break;
        default:
            break;
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
        case EAttrType::common:
            pattr = dynamic_cast<IAttr *>(FindModule<NFISharedMemModule>()->CreateObj<ComAttr>());
            break;
        case EAttrType::role:
            pattr = dynamic_cast<IAttr *>(FindModule<NFISharedMemModule>()->CreateObj<RoleAttr>());
            break;
        default:
            break;
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

const NFShmHashSet<int32_t, proto_ff::A_COMMON_END> &NFAttrMgr::GameSyncAttr()
{
    return m_setGameSyncAttr;
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


    //角色属性ID 范围 1-117, 如果后续有新增或调整，这里需要跟着变动
    uint8_t rolefightindex = 1;
    for (uint8_t j = 1; j <= 134; ++j)
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