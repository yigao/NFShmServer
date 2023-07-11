// -------------------------------------------------------------------------
//    @FileName         :    NFCacheMgr.h
//    @Author           :    gaoyi
//    @Date             :    22-11-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFCacheMgr
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFPlayerSimple.h"
#include "NFPlayerDetail.h"

class NFCacheMgr : public NFShmObj
{
public:
    NFCacheMgr();

    virtual ~NFCacheMgr();

    int CreateInit();

    int ResumeInit();
public:
    /**
     * @brief
     * @param num
     * @return
     */
    int ReleaseSimpleCount(int num);

    /**
     * @brief
     * @param roleId
     * @return
     */
    NFPlayerSimple *GetRoleSimple(uint64_t roleId);

    /**
     * @brief
     * @param playerId
     * @return
     */
    NFPlayerSimple *CreateRoleSimple(uint64_t playerId);

    /**
     * @brief
     * @param pRoleSimple
     * @return
     */
    int DeleteRoleSimple(NFPlayerSimple *pRoleSimple);
public:
    /**
     * @brief
     * @param num
     * @return
     */
    int ReleaseDetailCount(int num);

    /**
     * @brief
     * @param roleId
     * @return
     */
    NFPlayerDetail *GetRoleDetail(uint64_t roleId);

    /**
     * @brief
     * @param playerId
     * @return
     */
    NFPlayerDetail *CreateRoleDetail(uint64_t playerId);

    /**
     * @brief
     * @param pRoleDetail
     * @return
     */
    int DeleteRoleDetail(NFPlayerDetail *pRoleDetail);
public:
    /** 获取角色数据，如果找不到,query=true的情况下就去数据库拉取数据
     * @brief
     * @param role_id
     * @param query 找不到是否查询数据库
     * @return
     */
    NFPlayerSimple* QueryRoleSimple(uint64_t role_id, bool query=true);
private:
DECLARE_IDCREATE(NFCacheMgr)
};