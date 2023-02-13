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
    /**
     * @brief iStrongType = 0 的时候， 需要查找NFShmObj之间继承关系， 只有NFCreature的子类才能获得对象
     */
    return dynamic_cast<NFCreature *>(FindModule<NFISharedMemModule>()->GetObjFromGlobalID(cid, EOT_GAME_CREATURE_ID, 0));
}
