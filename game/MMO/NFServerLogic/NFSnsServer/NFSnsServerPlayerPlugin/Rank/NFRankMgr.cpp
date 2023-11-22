// -------------------------------------------------------------------------
//    @FileName         :    NFRankMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFRankMgr
//
// -------------------------------------------------------------------------

#include "NFRankMgr.h"

#include <NFServerComm/NFServerCommon/NFDBObjMgr.h>

NFRankMgr::NFRankMgr()
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

NFRankMgr::~NFRankMgr()
{
}

int NFRankMgr::CreateInit()
{
    return 0;
}

int NFRankMgr::ResumeInit()
{
    return 0;
}

int NFRankMgr::RegisterMessage()
{
    return 0;
}

int NFRankMgr::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFRankMgr::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFRankMgr::LoadFromDB(const std::string& dbData)
{
    return 0;
}

int NFRankMgr::SaveToDB(std::string& dbData)
{
    return 0;
}

int NFRankMgr::InitConfig()
{
    MarkDirty();
    return 0;
}

int NFRankMgr::LoadAllRank()
{
    m_rankData[RANK_TYPE_POWER] = CreateRankList(RANK_TYPE_POWER);
    m_rankData[RANK_TYPE_LEVEL] = CreateRankList(RANK_TYPE_LEVEL);
    m_rankData[RANK_TYPE_GUILD] = CreateRankList(RANK_TYPE_GUILD);
    m_rankData[RANK_TYPE_EQUIP] = CreateRankList(RANK_TYPE_EQUIP);
    m_rankData[RANK_TYPE_XIUZHEN] = CreateRankList(RANK_TYPE_XIUZHEN);
    m_rankData[RANK_TYPE_FANGREN_XIUZHEN] = CreateRankList(RANK_TYPE_FANGREN_XIUZHEN);
    m_rankData[RANK_TYPE_BATTLE_PASS_XIANCE] = CreateRankList(RANK_TYPE_BATTLE_PASS_XIANCE);
    m_rankData[RANK_TYPE_BATTLE_PASS_BAODING] = CreateRankList(RANK_TYPE_BATTLE_PASS_BAODING);
    m_rankData[RANK_TYPE_PET_FIGHT] = CreateRankList(RANK_TYPE_PET_FIGHT);
    m_rankData[RANK_TYPE_MOUNT_FIGHT] = CreateRankList(RANK_TYPE_MOUNT_FIGHT);
    m_rankData[RANK_TYPE_YUANMAO_SUM] = CreateRankList(RANK_TYPE_YUANMAO_SUM);
    m_rankData[RANK_TYPE_WING_FIGHT] = CreateRankList(RANK_TYPE_WING_FIGHT);
    m_rankData[RANK_TYPE_BAOSHI_LEVEL] = CreateRankList(RANK_TYPE_BAOSHI_LEVEL);
    m_rankData[RANK_TYPE_MARRY_VALUE] = CreateRankList(RANK_TYPE_MARRY_VALUE);
    m_rankData[RANK_TYPE_DEITY_FIGHT] = CreateRankList(RANK_TYPE_DEITY_FIGHT);
    m_rankData[RANK_TYPE_BEAST_FIGHT] = CreateRankList(RANK_TYPE_BEAST_FIGHT);
    m_rankData[RANK_TYPE_BIAOBAI_VALUE] = CreateRankList(RANK_TYPE_BIAOBAI_VALUE);
    m_rankData[RANK_TYPE_MEILI_VALUE] = CreateRankList(RANK_TYPE_MEILI_VALUE);
    m_rankData[RANK_TYPE_ANQI_FIGHT] = CreateRankList(RANK_TYPE_ANQI_FIGHT);
    m_rankData[RANK_TYPE_LINGJIA_FIGHT] = CreateRankList(RANK_TYPE_LINGJIA_FIGHT);

    for (auto iter = m_rankData.begin(); iter != m_rankData.end(); iter++)
    {
        NFDBObjMgr::Instance(m_pObjPluginManager)->LoadFromDB(iter->second.GetPoint());
    }
    return 0;
}

NFCommonRank* NFRankMgr::CreateRankList(uint32_t nType)
{
    auto pRank = NFCommonRank::CreateObj(m_pObjPluginManager);
    CHECK_EXPR(pRank, NULL, "CreateRankList Failed, nType:{}", nType);
    pRank->InitRank(nType);
    return pRank;
}

NFCommonRank* NFRankMgr::GetRankList(uint32_t nType)
{
    auto iter = m_rankData.find(nType);
    if (iter != m_rankData.end())
    {
        return iter->second.GetPoint();
    }
    return NULL;
}
