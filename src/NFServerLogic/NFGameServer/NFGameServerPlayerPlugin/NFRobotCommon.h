// -------------------------------------------------------------------------
//    @FileName         :    NFRobotCommon.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFRobotCommon.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFBaseDBObj.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"

class NFRobotCommon : public NFBaseDBObj {
public:
    NFRobotCommon();

    virtual ~NFRobotCommon();

    //非继承函数, 不要加virtual
    int CreateInit();

    //非继承函数, 不要加virtual
    int ResumeInit();

public:
    int Init(NF_SERVER_TYPES serverType, uint32_t gameId, uint32_t roomId);
public:
    int AddRobot(uint64_t robotId, const std::string& nickName, uint32_t faceId, uint32_t age, uint32_t gender, uint64_t jetton);
    proto_ff_s::RobotCommonData_s* GetRobot(uint64_t robotId);
    proto_ff_s::RobotCommonData_s* GetFreeRobot();
public:
    uint32_t m_gameId;
    uint32_t m_roomId;
    uint32_t m_iRobotTypeID;
    proto_ff_s::tbGameRobot_s m_stData;
DECLARE_DB_OBJ_SETTING(proto_ff::E_TABLE_GAME_ROBOT, tbGameRobot, ROBOT_MAX_SAVE_TIME, EN_DW_RETRY_ANY_SHUTDOWN);
DECLARE_IDCREATE(NFRobotCommon)
};