// -------------------------------------------------------------------------
//    @FileName         :    NFCreatureMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFCreatureMgr
//
// -------------------------------------------------------------------------

#include "NFCreatureMgr.h"
#include "NFCreature.h"
#include "NFBattlePlayer.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFCreatureMgr, EOT_GAME_CREATURE_MGR_ID, NFShmObj)

NFCreatureMgr::NFCreatureMgr() : NFShmObj()
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

NFCreatureMgr::~NFCreatureMgr()
{
}

int NFCreatureMgr::CreateInit()
{
    return 0;
}

int NFCreatureMgr::ResumeInit()
{
    return 0;
}

NFCreature *NFCreatureMgr::GetCreature(uint64_t cid)
{
    NFCreature* pCreature = GetBattlePlayer(cid);
    if (pCreature == NULL)
    {
        /**
         * @brief iStrongType = 0 的时候， 需要查找NFShmObj之间继承关系， 只有NFCreature的子类才能获得对象
         */
        pCreature = dynamic_cast<NFCreature *>(FindModule<NFISharedMemModule>()->GetObjFromGlobalID(cid, EOT_GAME_CREATURE_ID, 0));
    }

    return pCreature;
}

NFCreature* NFCreatureMgr::CreateCreature(uint32_t kindType, uint64_t id)
{
    NFCreature *pCreature = NULL;
    switch (kindType)
    {
        case CREATURE_PLAYER:
        {
            pCreature = FindModule<NFISharedMemModule>()->CreateObjByHashKey<NFBattlePlayer>(id);
            if (pCreature == NULL)
            {
                NFLogError(NF_LOG_SYSTEMLOG, id, "Create NFBattlePlayer failed! id:{} NFBattlePlayer: FreeCount:{} UseCount:{} ItemCount:{}", id,
                           NFBattlePlayer::GetFreeCount(m_pObjPluginManager), NFBattlePlayer::GetUsedCount(m_pObjPluginManager),
                           NFBattlePlayer::GetItemCount(m_pObjPluginManager))
            }

            NFCreature* pGetCreature = GetBattlePlayer(id);
            NF_ASSERT_MSG(pGetCreature == pCreature, "pGetCreature != pCreature, id:{}", id);

            pCreature->Init();
            break;
        }
        default:
            break;
    }

    return pCreature;
}

int NFCreatureMgr::DestroyCreature(NFCreature* pCreature)
{
    CHECK_NULL(pCreature);
    pCreature->UnInit();
    NFLogInfo(NF_LOG_SYSTEMLOG, pCreature->Cid(), "Destroy Creature, kind:{} cid:{} roleId:{} uid:{} ", pCreature->Kind(), pCreature->Cid(), pCreature->GetRoleId(), pCreature->GetUid());
    FindModule<NFISharedMemModule>()->DestroyObj(pCreature);
    return 0;
}

NFBattlePlayer* NFCreatureMgr::GetBattlePlayer(uint64_t roleId)
{
    return FindModule<NFISharedMemModule>()->GetObjByHashKey<NFBattlePlayer>(roleId);
}
