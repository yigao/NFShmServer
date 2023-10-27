// -------------------------------------------------------------------------
//    @FileName         :    NFCreatureMgr.h
//    @Author           :    gaoyi
//    @Date             :    22-11-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFCreatureMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"

class NFCreature;
class NFBattlePlayer;
class NFCreatureMgr : public NFShmObjTemplate<NFCreatureMgr, EOT_GAME_CREATURE_MGR_ID, NFShmObj>
{
public:
    NFCreatureMgr();

    virtual ~NFCreatureMgr();

    int CreateInit();

    int ResumeInit();
public:
    int OnTimer(int timeId, int callcount);

    int Update();
public:
    /**
     * @brief 需要查找NFShmObj之间继承关系， 只有NFCreature的子类才能获得对象
     * @param cid
     * @return
     */
    NFCreature* GetCreature(uint64_t cid);


    /**
     * @brief
     * @param kindType
     * @param cid
     * @return
     */
    NFCreature* CreateCreature(uint32_t kindType, uint64_t cid = 0);

    /**
     * @brief
     * @param pCreature
     */
    int  DestroyCreature(NFCreature* pCreature);
public:
    /**
     * @brief
     * @param cid
     * @return
     */
    NFBattlePlayer* GetBattlePlayer(uint64_t cid);
private:
    int m_creatureTickTimer;
};