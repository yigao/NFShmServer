// -------------------------------------------------------------------------
//    @FileName         :    NFPlayerMgr.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/14
//    @Email			:    445267987@qq.com
//    @Module           :    NFPlayerMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFShmHashMap.h"

class NFPlayer;
class NFPlayerMgr : public NFShmObj
{
public:
    NFPlayerMgr(NFIPluginManager *pPluginManager);

    virtual ~NFPlayerMgr();

    int CreateInit();

    int ResumeInit();

public:
    /**
     * @brief 通过roleId获取玩家数据
     * @param roleId
     * @return
     */
    NFPlayer *GetPlayerByRoleId(uint64_t roleId);

    /**
     * @brief 通过playerId获取玩家数据
     * @param playerId
     * @return
     */
    NFPlayer *GetPlayerByPlayerId(uint64_t playerId);

    /**
     * @brief 通过roleId创建玩家数据, 如果玩家存在，返回NULL
     * @param roleId
     * @return
     */
    NFPlayer *CreatePlayer(uint64_t playerId, uint64_t roleId);

    /**
     * @brief 删除玩家数据
     * @param pPlayer
     * @return
     */
    int DeletePlayer(NFPlayer *pPlayer);

private:
    /**
     * @brief playerId => NFPlayer's globalId
     */
    NFShmHashMap<uint64_t, uint64_t, 1000000> m_playerIdMap;
DECLARE_IDCREATE(NFPlayerMgr);
};