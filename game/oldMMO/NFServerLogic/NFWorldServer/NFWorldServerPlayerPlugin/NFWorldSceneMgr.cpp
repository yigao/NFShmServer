// -------------------------------------------------------------------------
//    @FileName         :    NFWorldSceneMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldSceneMgr
//
// -------------------------------------------------------------------------

#include "NFWorldSceneMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFWorldSceneMgr, EOT_WORLD_SCENE_MGR_ID, NFShmObj)

NFWorldSceneMgr::NFWorldSceneMgr() : NFShmObj()
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

NFWorldSceneMgr::~NFWorldSceneMgr()
{
}

int NFWorldSceneMgr::CreateInit()
{
    return 0;
}

int NFWorldSceneMgr::ResumeInit()
{
    return 0;
}

int NFWorldSceneMgr::LoadGameMap(const proto_ff::GameToWorldRegisterMapReq& xData)
{
    uint32_t gameBus = xData.game_bus();
    for(int i = 0; i < (int)xData.map_id_size(); i++)
    {
        uint64_t mapId = xData.map_id(i);
        auto iter = m_mapIdToGameBusIdMap.find(mapId);
        if (iter == m_mapIdToGameBusIdMap.end())
        {
            iter = m_mapIdToGameBusIdMap.emplace_hint(mapId, NFShmVector<uint32_t, NF_WORLD_MAP_ID_MAX_SERVER_NUM>());
            CHECK_EXPR_CONTINUE(iter != m_mapIdToGameBusIdMap.end(), "m_mapIdToGameBusIdMap.Insert Failed, Not Enough Space, mapId:{} gameBus:{}", mapId, gameBus);
        }

        bool notHas = true;
        for(int j = 0; j < (int)iter->second.size(); j++)
        {
            if (iter->second[j] == gameBus)
            {
                notHas = false;
                break;
            }
        }

        if (notHas)
        {
            int ret = iter->second.push_back(gameBus);
            CHECK_EXPR_CONTINUE(ret >= 0, "Add Failed, Not Enough Space, mapId:{} gameBus:{}", mapId, gameBus);
        }
    }
    return 0;
}

bool NFWorldSceneMgr::IsStaticMapId(uint64_t mapId) const
{
    auto iter = m_mapIdToGameBusIdMap.find(mapId);
    if (iter != m_mapIdToGameBusIdMap.end())
    {
        return true;
    }
    return false;
}

uint32_t NFWorldSceneMgr::GetStaticMapGameId(uint64_t mapId) const
{
    auto iter = m_mapIdToGameBusIdMap.find(mapId);
    if (iter == m_mapIdToGameBusIdMap.end())
    {
        return 0;
    }

    if (iter->second.size() == 0)
    {
        return -1;
    }
    else if (iter->second.size() == 1)
    {
        return iter->second[0];
    }
    else {
        int index = NFRandInt((int)0, (int)iter->second.size());
        return iter->second[index];
    }
}
