// -------------------------------------------------------------------------
//    @FileName         :    NFRobotMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFRobotMgr.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFArray.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFShmCore/NFShmHashMap.h"

#define MAX_GAME_ROBOT_LIST 10

class NFRobotCommon;
class NFRobotMgr : public NFShmObj
{
public:
    NFRobotMgr();
    virtual ~NFRobotMgr();
    //非继承函数, 不要加virtual
    int CreateInit();
    //非继承函数, 不要加virtual
    int ResumeInit();
public:
    int Init();
    int InitOneRoom(uint32_t gameId, uint32_t roomId);
    //must be virtual
    virtual void OnTimer(int timeId, int callcount);
public:
    NFRobotCommon* GetRobotCommon(uint32_t gameId, uint32_t roomId);
    proto_ff_s::RobotCommonData_s* GetRobotData(uint32_t gameId, uint32_t roomId, uint64_t robotId);
    uint64_t GetFreeRobot(uint32_t gameId, uint32_t roomId);
    int CreateRobot(uint32_t gameId, uint32_t roomId);
    int SetRobotJetton(uint32_t gameId, uint32_t roomId, uint64_t robotId, uint64_t jetton);
private:
    bool m_bInited;
    NFShmHashMap<int, int, MAX_GAME_ROBOT_LIST> m_gameRobotObjId;
    int m_checkTimer;
DECLARE_IDCREATE(NFRobotMgr)
};