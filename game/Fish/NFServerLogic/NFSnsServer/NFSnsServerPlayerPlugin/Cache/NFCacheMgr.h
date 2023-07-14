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
    NFPlayerSimple *GetPlayerSimple(uint64_t roleId);

    /**
     * @brief
     * @param playerId
     * @return
     */
    NFPlayerSimple *CreatePlayerSimple(uint64_t playerId);

    /**
     * @brief
     * @param pRoleSimple
     * @return
     */
    int DeletePlayerSimple(NFPlayerSimple *pRoleSimple);

    /**
     * @brief 获取角色数据，如果找不到,通过trans异步去数据库拉取数据
     * @param role_id
     * @return
     */
    NFPlayerSimple* QueryPlayerSimple(uint64_t role_id);

    /**
     * @brief 获取角色数据，如果找不到,通过rpc异步去数据库拉取数据
     * @param role_id
     * @return
     */
    NFPlayerSimple* QueryPlayerSimpleByRpc(uint64_t role_id);
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
    NFPlayerDetail *GetPlayerDetail(uint64_t roleId);

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

    /**
     * @brief
     * @param role_id
     * @return
     */
    NFPlayerDetail* QueryPlayerDetailByRpc(uint64_t role_id);
private:
DECLARE_IDCREATE(NFCacheMgr)
};