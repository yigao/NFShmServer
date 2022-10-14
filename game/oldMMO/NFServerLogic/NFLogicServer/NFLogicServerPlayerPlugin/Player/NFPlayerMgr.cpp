// -------------------------------------------------------------------------
//    @FileName         :    NFPlayerMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/10/14
//    @Email			:    445267987@qq.com
//    @Module           :    NFPlayerMgr
//
// -------------------------------------------------------------------------

#include "NFPlayerMgr.h"
#include "NFPlayer.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include <map>
#include <NFComm/NFPluginModule/NFCheck.h>
#include "NFComm/NFCore/NFServerTime.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFPlayerMgr, EOT_LOGIC_PLAYER_MGR_ID, NFShmObj)

NFPlayerMgr::NFPlayerMgr(NFIPluginManager *pPluginManager) : NFShmObj(pPluginManager)
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    } else
    {
        ResumeInit();
    }
}

NFPlayerMgr::~NFPlayerMgr()
{
}

int NFPlayerMgr::CreateInit()
{
    return 0;
}

int NFPlayerMgr::ResumeInit()
{
    return 0;
}

NFPlayer *NFPlayerMgr::GetPlayerByRoleId(uint64_t roleId)
{
    return dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->GetObjByHashKey(roleId, EOT_WORLD_PLAYER_ID));
}

NFPlayer *NFPlayerMgr::GetPlayerByPlayerId(uint64_t playerId)
{
    uint64_t* pGlobalId = m_playerIdMap.Find(playerId);
    if (pGlobalId)
    {
        return dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->GetObjFromGlobalID(*pGlobalId, EOT_WORLD_PLAYER_ID));
    }
    return NULL;
}

NFPlayer *NFPlayerMgr::CreatePlayer(uint64_t playerId, uint64_t roleId)
{
    NFPlayer *pPlayer = GetPlayerByRoleId(roleId);
    CHECK_EXPR(pPlayer == NULL, NULL, "Create player Failed, player exist, roleId:{}", roleId);

    pPlayer = dynamic_cast<NFPlayer *>(FindModule<NFISharedMemModule>()->CreateObjByHashKey(roleId, EOT_WORLD_PLAYER_ID));
    CHECK_EXPR(pPlayer, NULL, "Create Player Obj Failed, roleId:{}", roleId);

    pPlayer->SetPlayerId(playerId);
    pPlayer->SetRoleId(roleId);

    uint64_t* pGlobalId = m_playerIdMap.Insert(playerId);
    if (pGlobalId)
    {
        *pGlobalId = pPlayer->GetGlobalID();
    }
    else {
        DeletePlayer(pPlayer);
        pPlayer = NULL;
        CHECK_EXPR(pGlobalId, NULL, "m_playerIdMap.Insert(playerId:{}) Failed", playerId);
    }

    NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, roleId, "Add Player Success, playerId:{} roleId:{} globalId:{}", playerId, roleId,
              pPlayer->GetGlobalID());
    return pPlayer;
}

int NFPlayerMgr::DeletePlayer(NFPlayer *pPlayer)
{
    CHECK_NULL(pPlayer);

    NFLogInfo(NF_LOG_GAME_SERVER_PLUGIN, 0, "Delete Player Info, playerID, gloablId:{}", pPlayer->GetPlayerId(), pPlayer->GetGlobalID());

    FindModule<NFISharedMemModule>()->DestroyObj(pPlayer);

    return 0;
}
