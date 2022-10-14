// -------------------------------------------------------------------------
//    @FileName         :    NFTransPlayerBase.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/14
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransPlayerBase
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFTransBase.h"

class NFPlayer;
class NFTransPlayerBase : public NFTransBase {
public:
    NFTransPlayerBase(NFIPluginManager* pPluginManager);

    virtual ~NFTransPlayerBase();

    int CreateInit();

    int ResumeInit();

    int Init(uint64_t playerId, uint64_t roleId, uint32_t cmd, uint32_t fromBusId = 0, uint32_t reqTransId = 0);
    int Init(NFPlayer* pPlayer, uint32_t cmd, uint32_t fromBusId = 0, uint32_t reqTransId = 0);

    NFPlayer *GetPlayer();

    virtual int OnTimeOut();
    virtual int OnTransFinished(int iRunLogicRetCode);
protected:
    uint32_t m_cmd;
    uint64_t m_playerId;
    uint64_t m_roleId;
    uint32_t m_fromBusId;
    uint32_t m_reqTransId;
    bool m_bHasIncreasedCount;
DECLARE_IDCREATE(NFTransPlayerBase)
};


