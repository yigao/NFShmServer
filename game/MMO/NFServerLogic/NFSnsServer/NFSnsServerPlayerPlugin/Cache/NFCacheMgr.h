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
#include "NFPlayerOnline.h"

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
     * @param player
     * @return
     */
    NFPlayerOnline *GetPlayerOnline(uint64_t player);

    /**
     * @brief
     * @param cid
     * @return
     */
    NFPlayerOnline *CreatePlayerOnline(uint64_t cid);

    /**
     * @brief
     * @param pRoleSimple
     * @return
     */
    int DeletePlayerOnline(NFPlayerOnline *pRoleSimple);
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
    NFPlayerSimple *GetPlayerSimple(uint64_t player);

    /**
     * @brief
     * @param cid
     * @return
     */
    NFPlayerSimple *CreatePlayerSimple(uint64_t cid);

    /**
     * @brief
     * @param pRoleSimple
     * @return
     */
    int DeletePlayerSimple(NFPlayerSimple *pRoleSimple);

    /**
     * @brief 获取角色数据，如果找不到,通过trans异步去数据库拉取数据
     * @param cid
     * @return
     */
    NFPlayerSimple* QueryPlayerSimple(uint64_t cid);

    /**
     * @brief 获取角色数据，如果找不到,通过rpc异步去数据库拉取数据
     * @param cid
     * @return
     */
    NFPlayerSimple* QueryPlayerSimpleByRpc(uint64_t cid);

    /**
     * @brief 玩家PlayerId 查询 玩家query_id 的数据， 主要放在NFPlayerDetail以及part里使用，确保NFPlayterDetail part的生命周期在协程完成前，一直存在
     * @param role_id
     * @return
     */
    NFPlayerSimple* QueryPlayerSimpleByRpc(uint64_t cid, uint64_t query_id);
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
     * @param cid
     * @return
     */
    NFPlayerDetail *CreatePlayerDetail(uint64_t cid);

    /**
     * @brief
     * @param pRoleDetail
     * @return
     */
    int DeletePlayerDetail(NFPlayerDetail *pRoleDetail);

    /**
     * @brief
     * @param cid
     * @return
     */
    NFPlayerDetail* QueryPlayerDetailByRpc(uint64_t cid);

    /**
     * @brief 玩家PlayerId 查询 玩家query_id 的数据， 主要放在NFPlayerDetail以及part里使用，确保NFPlayterDetail part的生命周期在协程完成前，一直存在
     * @param cid
     * @param query_id
     * @return
     */
    NFPlayerDetail* QueryPlayerDetailByRpc(uint64_t cid, uint64_t query_id);
public:
    std::pair<NFPlayerSimple*, NFPlayerDetail*> QueryPlayerByRpc(uint64_t cid, uint64_t query_id);
private:
DECLARE_IDCREATE(NFCacheMgr)
};