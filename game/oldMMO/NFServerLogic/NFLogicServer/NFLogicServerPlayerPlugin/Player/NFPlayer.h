// -------------------------------------------------------------------------
//    @FileName         :    NFUserDetail.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFUserDetail.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "NFComm/NFCore/NFTime.h"

typedef enum
{
    PLAYER_STATUS_NONE = 0,     //
    PLAYER_STATUS_ONLINE = 1,    //
    PLAYER_STATUS_OFFLINE = 2,   //
    PLAYER_STATUS_LOGOUT = 3,    //
} PLAYER_STATUS;

class NFPlayer : public NFShmObj, public NFSeqOP
{
public:
    NFPlayer(NFIPluginManager *pPluginManager);

    virtual ~NFPlayer();

    int CreateInit();

    int ResumeInit();

public:
    /**
     * @brief 当前玩家正在使用的trans数量 +1
     */
    void IncreaseTransNum();

    /**
     * @brief 当前玩家正在使用的trans数量 -1
     */
    void DecreaseTransNum();

    /**
     * @brief 当前玩家正在使用的trans数量
     * @return
     */
    int GetTransNum() const;

    /**
     * @brief 角色ID
     * @return
     */
    uint64_t GetRoleId() const;

    /**
     * @brief
     * @param roleId
     */
    void SetRoleId(uint64_t roleId);

    /**
     * @brief 玩家ID
     * @return
     */
    uint64_t GetPlayerId() const;

    /**
     * @brief
     * @param playerId
     */
    void SetPlayerId(uint64_t playerId);
private:
    /**
     * @brief 玩家数据是否初始化
     */
    bool m_bIsInited;

    /**
     * @brief 当前玩家正在使用的trans数量
     */
    int m_iTransNum;

    /**
     * @brief 角色ID
     */
    uint64_t m_roleId;

    /**
     * @brief 玩家ID
     */
    uint64_t m_playerId;
DECLARE_IDCREATE(NFPlayer)
};
