// -------------------------------------------------------------------------
//    @FileName         :    NFRobotCommon.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFRobotCommon.cpp
//
// -------------------------------------------------------------------------

#include "NFRobotCommon.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFRobotCommon, EOT_GAME_ROBOT_COMMON_ID, NFBaseDBObj)

static bool compare_robot_id(const proto_ff_s::RobotCommonData_s &p1, const proto_ff_s::RobotCommonData_s &p2)
{
    return p1.robot_id < p2.robot_id;
}

NFRobotCommon::NFRobotCommon()
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

NFRobotCommon::~NFRobotCommon()
{

}

int NFRobotCommon::CreateInit() {
    m_iRobotTypeID = 0;
    m_gameId = 0;
    m_roomId = 0;
    memset(&m_stData, 0, sizeof(m_stData));
    return 0;
}

int NFRobotCommon::ResumeInit() {
    return 0;
}

int NFRobotCommon::MakeLoadData(google::protobuf::Message* data)
{
    if (m_bDataInited) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "aleady inited !" );
        return -1;
    }
    CHECK_EXPR(m_iRobotTypeID, -1, "No Rank Type ");

    CHECK_NULL(data);
    proto_ff::tbGameRobot* p = dynamic_cast<proto_ff::tbGameRobot*>(data);

    CHECK_NULL(p);
    p->set_id4db(m_iRobotTypeID);

    return 0;
}
int NFRobotCommon::MakeSaveData(google::protobuf::Message* data)
{
    if ( !m_bDataInited ) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "not init!" );
        return -1;
    }
    CHECK_NULL(data);

    proto_ff::tbGameRobot* p = dynamic_cast<proto_ff::tbGameRobot*>(data);
    CHECK_NULL(p);
    proto_ff_s::tbGameRobot_s::write_to_pbmsg(m_stData, *p);

    return 0;
}

int NFRobotCommon::Init(NF_SERVER_TYPES serverType, uint32_t gameId, uint32_t roomId)
{
    SetServerType(serverType);
    m_gameId = gameId;
    m_roomId = roomId;
    m_iRobotTypeID = m_gameId * 1000 + roomId;
    return 0;
}



int NFRobotCommon::InitWithDBData(const std::string* data)
{
    CHECK_NULL( data );
    proto_ff::tbGameRobot pb;
    bool ok = pb.ParseFromString(*data);
    CHECK_EXPR( ok, -1, "parse failed!");
    proto_ff_s::tbGameRobot_s::read_from_pbmsg(pb, m_stData);
    NFLogDebug(NF_LOG_SYSTEMLOG, 0, "init with db data: {} ", m_iRobotTypeID);

    for(int i = 0; i < (int)m_stData.body.robot_data.GetSize(); i++)
    {
        m_stData.body.robot_data[i].is_use = false;
    }

    m_bDataInited = true;
    return 0;
}

int NFRobotCommon::InitWithoutDBData()
{
    CHECK_EXPR(m_iRobotTypeID, -1, "No Rank Type ");
    memset(&m_stData, 0, sizeof(m_stData));
    m_stData.id4db = m_iRobotTypeID;
    CHECK_EXPR( m_stData.id4db > 0, -1, "error: {}", m_stData.id4db);

    NFLogDebug(NF_LOG_SYSTEMLOG, 0, "init without db data: robottype:{} ", m_iRobotTypeID);
    m_bDataInited = true;
    return 0;
}

int NFRobotCommon::AddRobot(uint64_t robotId, const std::string& nickName, uint32_t faceId, uint32_t age, uint32_t gender, uint64_t jetton)
{
    CHECK_EXPR(m_bDataInited, -1, "data not init! ");

    proto_ff_s::RobotCommonData_s robot;
    robot.robot_id = robotId;

    proto_ff_s::RobotCommonData_s *pInfo = m_stData.body.robot_data.BinarySearch(robot, compare_robot_id);
    if (pInfo)
    {
        CHECK_EXPR(pInfo->robot_id == robotId, -1, "m_stData.body.robot_data.BinarySearch Error, gameId:{} roomId:{}", m_gameId, m_roomId);
        pInfo->nickname = nickName;
        pInfo->jetton = jetton;
        pInfo->face_id = faceId;
        pInfo->age = age;
        pInfo->gender = gender;
        pInfo->is_use = false;
    }
    else
    {
        CHECK_EXPR(!m_stData.body.robot_data.IsFull(), -1, "m_stData.body.robot_data.IsFull() Error, gameId:{} roomId:{}", m_gameId, m_roomId);

        pInfo = m_stData.body.robot_data.BinaryInsert(robot, compare_robot_id);
        CHECK_EXPR(pInfo && pInfo->robot_id == robotId, -1, "insert into robot failed: gameId:{} roomId:{}", m_gameId, m_roomId);

        pInfo->nickname = nickName;
        pInfo->jetton = jetton;
        pInfo->face_id = faceId;
        pInfo->age = age;
        pInfo->gender = gender;
        pInfo->is_use = false;
    }

    MarkDirty();

    return 0;
}

proto_ff_s::RobotCommonData_s* NFRobotCommon::GetRobot(uint64_t robotId)
{
    CHECK_EXPR(m_bDataInited, NULL, "data not init! ");

    proto_ff_s::RobotCommonData_s robot;
    robot.robot_id = robotId;

    return m_stData.body.robot_data.BinarySearch(robot, compare_robot_id);
}

proto_ff_s::RobotCommonData_s* NFRobotCommon::GetFreeRobot()
{
    CHECK_EXPR(m_bDataInited, NULL, "data not init! ");
    for(int i = 0; i < (int)m_stData.body.robot_data.GetSize(); i++)
    {
        if (m_stData.body.robot_data[i].is_use == false)
        {
            return &m_stData.body.robot_data[i];
        }
    }

    return NULL;
}