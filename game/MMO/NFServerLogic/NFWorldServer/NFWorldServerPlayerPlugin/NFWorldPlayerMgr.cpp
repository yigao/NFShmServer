// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayerIDHashTable.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayerIDHashTable.cpp
//
// -------------------------------------------------------------------------

#include "NFWorldPlayerMgr.h"
#include "NFWorldPlayer.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include <map>
#include <NFComm/NFPluginModule/NFCheck.h>
#include "NFComm/NFCore/NFServerTime.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFWorldPlayerMgr, EOT_WORLD_PLAYER_MGR_ID, NFShmObj)

NFWorldPlayerMgr::NFWorldPlayerMgr() : NFShmObj()
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

NFWorldPlayerMgr::~NFWorldPlayerMgr()
{
    if (m_playerTickTimer != INVALID_ID)
    {
        DeleteTimer(m_playerTickTimer);
        m_playerTickTimer = INVALID_ID;
    }
}

int NFWorldPlayerMgr::CreateInit()
{
    m_currentLoginNum = 0;
    m_maxQueueNum = 2000;    //排队总人数
    m_startQueueNum = 2000; //开始排队人数
    m_playerTickTimer = SetTimer(1000, 0, 0, 0, 1, 0);
    return 0;
}

int NFWorldPlayerMgr::ResumeInit()
{
    return 0;
}

int NFWorldPlayerMgr::OnTimer(int timeId, int callcount)
{
    if (m_playerTickTimer == timeId)
    {
        PlayerTick();
    }
    return 0;
}

int NFWorldPlayerMgr::PlayerTick()
{
    std::vector<uint64_t> willRemovePlayer;
    NFWorldPlayer* pPlayer = dynamic_cast<NFWorldPlayer *>(FindModule<NFISharedMemModule>()->GetHeadObj(EOT_WORLD_PLAYER_ID));
    while (pPlayer)
    {
        pPlayer->Tick();
        if (pPlayer->GetStatus() == PLAYER_STATUS_DEAD)
        {
            willRemovePlayer.push_back(pPlayer->GetUid());
        }
        pPlayer = dynamic_cast<NFWorldPlayer *>(FindModule<NFISharedMemModule>()->GetNextObj(EOT_WORLD_PLAYER_ID, pPlayer));
    }

    for(int i = 0; i < (int)willRemovePlayer.size(); i++)
    {
        pPlayer = GetPlayerByUid(willRemovePlayer[i]);
        if (pPlayer)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, pPlayer->GetUid(), "player:{} be erase from memory", pPlayer->GetUid());
            DeletePlayer(pPlayer);
        }
    }
    return 0;
}


NFWorldPlayer *NFWorldPlayerMgr::GetPlayerByUid(uint64_t uid)
{
    return dynamic_cast<NFWorldPlayer *>(FindModule<NFISharedMemModule>()->GetObjByHashKey(uid, EOT_WORLD_PLAYER_ID));
}

NFWorldPlayer *NFWorldPlayerMgr::CreatePlayerByUid(uint64_t uid)
{
    NFWorldPlayer *pPlayer = GetPlayerByUid(uid);
    CHECK_EXPR(pPlayer == NULL, NULL, "Create player Failed, player exist, uid:{}", uid);

    pPlayer = dynamic_cast<NFWorldPlayer *>(FindModule<NFISharedMemModule>()->CreateObjByHashKey(uid, EOT_WORLD_PLAYER_ID));
    CHECK_EXPR(pPlayer, NULL, "Create Player Obj Failed, playerID:{}", uid);

    pPlayer->SetUid(uid);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Add Player Success, uid:{} globalId:{}", uid,
              pPlayer->GetGlobalID());
    return pPlayer;
}

int NFWorldPlayerMgr::DeletePlayer(NFWorldPlayer *pPlayer)
{
    CHECK_NULL(pPlayer);

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Delete Player Info, playerID, gloablId:{}", pPlayer->GetUid(), pPlayer->GetGlobalID());

    auto& mapRoleInfo = pPlayer->GetAllRoleInfo();
    for(auto iter = mapRoleInfo.Begin(); iter != mapRoleInfo.End(); iter++)
    {
        uint64_t roleId = *(iter->first);
        DeleteCidIndex(roleId);
    }

    FindModule<NFISharedMemModule>()->DestroyObj(pPlayer);

    return 0;
}


uint32_t NFWorldPlayerMgr::GetCurrentLoginNum() const
{
    return m_currentLoginNum;
}

void NFWorldPlayerMgr::SetCurrentLoginNum(uint32_t currentLoginNum)
{
    m_currentLoginNum = currentLoginNum;
}

uint32_t NFWorldPlayerMgr::GetMaxQueueNum() const
{
    return m_maxQueueNum;
}

void NFWorldPlayerMgr::SetMaxQueueNum(uint32_t maxQueueNum)
{
    m_maxQueueNum = maxQueueNum;
}

uint32_t NFWorldPlayerMgr::GetStartQueueNum() const
{
    return m_startQueueNum;
}

void NFWorldPlayerMgr::SetStartQueueNum(uint32_t startQueueNum)
{
    m_startQueueNum = startQueueNum;
}

bool NFWorldPlayerMgr::IsNeedLoginQueue() const
{
    if (m_currentLoginNum >= m_startQueueNum)
    {
        return true;
    }

    return false;
}

bool NFWorldPlayerMgr::IsLoginQueueFull() const
{
    if ((uint32_t) m_loginQueueMap.GetUsedNum() >= m_maxQueueNum)
    {
        return true;
    }

    return false;
}

/**
 * @brief 是否在排队队列中
 * @param playerId
 * @return
 */
bool NFWorldPlayerMgr::IsInLoginQueue(uint64_t playerId) const
{
    auto pData = m_loginQueueMap.Find(playerId);
    if (pData)
    {
        return true;
    }
    return false;
}

/**
 * @brief 加入到登陆排队中
 * @param playerId
 * @return
 */
bool NFWorldPlayerMgr::InsertLoginQueue(uint64_t playerId)
{
    auto pData = m_loginQueueMap.Insert(playerId);
    if (pData)
    {
        pData->SetPlayerId(playerId);
        pData->SetLastReqTime(NFServerTime::Instance()->UnixSec());
        return true;
    }
    return false;
}

NFLoginQueue *NFWorldPlayerMgr::GetLoginQueue(uint64_t playerId)
{
    return m_loginQueueMap.Find(playerId);
}

/**
 * @brief 获得当前排队人数
 * @return
 */
uint32_t NFWorldPlayerMgr::GetLoginQueueNum() const
{
    return (uint32_t) m_loginQueueMap.GetUsedNum();
}

/**
 * @brief 删除玩家的排队信息
 * @param playerId
 * @return
 */
int NFWorldPlayerMgr::DeleteLoginQueue(uint64_t playerId)
{
    return m_loginQueueMap.Erase(playerId);
}

NFWorldPlayer *NFWorldPlayerMgr::CreateCidIndexToUid(uint64_t cid, uint64_t uid)
{
    NFWorldPlayer *pPlayer = dynamic_cast<NFWorldPlayer *>(FindModule<NFISharedMemModule>()->CreateIndexToHashKey(NF_WORLD_PLAYER_ROLE_ID_INDEX,
                                                                                                                  cid, uid,
                                                                                                                  EOT_WORLD_PLAYER_ID));
    CHECK_EXPR(pPlayer, pPlayer, "CreateIndexToHashKey Failed, cid:{} uid:{}", cid, uid);
    return pPlayer;
}

NFWorldPlayer *NFWorldPlayerMgr::GetPlayerByCid(uint64_t cid)
{
    NFWorldPlayer *pPlayer = dynamic_cast<NFWorldPlayer *>(FindModule<NFISharedMemModule>()->GetObjByIndexKey(NF_WORLD_PLAYER_ROLE_ID_INDEX,
                                                                                                              cid, EOT_WORLD_PLAYER_ID));
    CHECK_EXPR(pPlayer, pPlayer, "GetObjByIndexKey Failed, cid:{}", cid);
    return pPlayer;
}

int NFWorldPlayerMgr::DeleteCidIndex(uint64_t cid)
{
    int ret = FindModule<NFISharedMemModule>()->DelIndexKey(NF_WORLD_PLAYER_ROLE_ID_INDEX, cid, EOT_WORLD_PLAYER_ID);
    CHECK_RET(ret, "DelIndexKey Failed, cid:{}", cid);

    return ret;
}
