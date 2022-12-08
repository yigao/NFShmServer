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
        auto pArray = m_mapIdToGameBusIdMap.Find(mapId);
        if (pArray == NULL)
        {
            pArray = m_mapIdToGameBusIdMap.Insert(mapId);
            CHECK_EXPR_CONTINUE(pArray, "m_mapIdToGameBusIdMap.Insert Failed, Not Enough Space, mapId:{} gameBus:{}", mapId, gameBus);
        }

        bool notHas = true;
        for(int j = 0; j < pArray->GetSize(); j++)
        {
            if ((*pArray)[j] == gameBus)
            {
                notHas = false;
                break;
            }
        }

        if (notHas)
        {
            int ret = pArray->Add(gameBus);
            CHECK_EXPR_CONTINUE(ret >= 0, "Add Failed, Not Enough Space, mapId:{} gameBus:{}", mapId, gameBus);
        }
    }
    return 0;
}

bool NFWorldSceneMgr::IsStaticMapId(uint64_t mapId) const
{
    auto pArray = m_mapIdToGameBusIdMap.Find(mapId);
    if (pArray == NULL)
    {
        return true;
    }
    return false;
}

uint32_t NFWorldSceneMgr::GetStaticMapGameId(uint64_t mapId) const
{
    auto pArray = m_mapIdToGameBusIdMap.Find(mapId);
    if (pArray == NULL)
    {
        return 0;
    }

    int index = NFRandInt((int)0, (int)pArray->GetSize());
    return (*pArray)[index];
}
