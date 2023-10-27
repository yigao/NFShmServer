// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRoleMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-10-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRoleMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFWorldRole;
class NFWorldRoleMgr : public NFShmObjTemplate<NFWorldRoleMgr, EOT_WORLD_ROLE_MGR_ID, NFShmObj>
{
public:
    NFWorldRoleMgr();

    virtual ~NFWorldRoleMgr();

    int CreateInit();

    int ResumeInit();
public:
    virtual int OnTimer(int timeId, int callcount);
    int Tick();
public:
    /**
     * @brief 通过cid获取Role数据
     * @param cid
     * @return
     */
    NFWorldRole *GetRole(uint64_t cid);

    /**
     * @brief 通过cid创建Role数据, 如果玩家存在，返回NULL
     * @param cid
     * @return
     */
    NFWorldRole *CreateRole(uint64_t cid);

    /**
     * @brief 删除Role数据
     * @param pRole
     * @return
     */
    int DeleteRole(NFWorldRole *pRole);
};