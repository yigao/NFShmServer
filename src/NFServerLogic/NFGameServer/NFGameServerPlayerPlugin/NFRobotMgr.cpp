// -------------------------------------------------------------------------
//    @FileName         :    NFRobotMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFRankMgr.cpp
//
// -------------------------------------------------------------------------

#include "NFRobotMgr.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFRobotCommon.h"
#include "NFComm/NFShmCore/NFDBObjMgr.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFTransCreateRobot.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFRobotMgr, EOT_GAME_ROBOT_MGR_ID, NFShmObj)

NFRobotMgr::NFRobotMgr() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFRobotMgr::~NFRobotMgr() {

}

int NFRobotMgr::CreateInit() {
    m_bInited = false;
    m_checkTimer = INVALID_ID;
    return 0;
}

int NFRobotMgr::ResumeInit() {
    return 0;
}

void NFRobotMgr::OnTimer(int timeId, int callcount)
{
    if (m_checkTimer == timeId)
    {
        bool flag = true;
        for(int i = 0; i < m_gameRobotObjId.GetSize(); i++)
        {
            int* pGlobalId = m_gameRobotObjId.GetByIndex(i);
            if (pGlobalId == NULL) continue;

            NFRobotCommon* pRank = dynamic_cast<NFRobotCommon*>(NFShmMgr::Instance()->GetObjFromGlobalID(*pGlobalId, EOT_GAME_ROBOT_COMMON_ID, 0));
            if (pRank)
            {
                if (!pRank->IsDataInited())
                {
                    flag = false;
                    break;
                }
            }
        }

        if (flag)
        {
            DeleteTimer(m_checkTimer);
            m_checkTimer = INVALID_ID;
            NFIPluginManager::Instance()->FinishAppTask(NF_ST_GAME_SERVER, APP_INIT_LOAD_GAME_ROBOT_FROM_DB, APP_INIT_STATUS_SERVER_LOAD_OBJ_FROM_DB);
        }
    }
}

int NFRobotMgr::Init()
{
    if (m_bInited)
    {
        return 0;
    }

    m_checkTimer = SetTimer(1000, 0, 0, 0, 0, 0);
    NFIPluginManager::Instance()->RegisterAppTask(NF_ST_GAME_SERVER, APP_INIT_LOAD_GAME_ROBOT_FROM_DB, "Load Robot From DB", APP_INIT_STATUS_SERVER_LOAD_OBJ_FROM_DB);

    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_GAME_SERVER);
    if (pConfig)
    {
        for(int i = 0; i < (int)pConfig->mRoomIdList.size(); i++)
        {
            InitOneRoom(pConfig->mGameId, pConfig->mRoomIdList[i]);
        }
    }

    m_bInited = true;
    return 0;
}

int NFRobotMgr::InitOneRoom(uint32_t gameId, uint32_t roomId)
{
    NFRobotCommon* pRobot = dynamic_cast<NFRobotCommon*>(NFShmMgr::Instance()->CreateObj(EOT_GAME_ROBOT_COMMON_ID));
    CHECK_EXPR(pRobot, -1, "Create NFRobotCommon Failed, use count:{}", NFRobotCommon::GetUsedCount());
    CHECK_EXPR(pRobot->IsDataInited() == false, -1, "gameId:{} roomId:{} already inited!", gameId, roomId);

    uint32_t id = gameId * 1000 + roomId;

    int* pData = m_gameRobotObjId.Insert(id);
    if (pData)
    {
        *pData = pRobot->GetGlobalID();
    }

    pRobot->Init(NF_ST_GAME_SERVER, gameId, roomId);
    int iRet = NFDBObjMgr::Instance()->LoadFromDB(pRobot);
    CHECK_RET(iRet, "inti failed, gameId:{} roomId:{} iRet:{}", gameId, roomId, iRet);
    return 0;
}

NFRobotCommon* NFRobotMgr::GetRobotCommon(uint32_t gameId, uint32_t roomId)
{
    uint32_t id = gameId * 1000 + roomId;
    int* pGlobalId = m_gameRobotObjId.Find(id);
    if (pGlobalId)
    {
        return dynamic_cast<NFRobotCommon*>(NFShmMgr::Instance()->GetObjFromGlobalID(*pGlobalId, EOT_GAME_ROBOT_COMMON_ID, 0));
    }
    return NULL;
}

proto_ff_s::RobotCommonData_s* NFRobotMgr::GetRobotData(uint32_t gameId, uint32_t roomId, uint64_t robotId)
{
    NFRobotCommon* pCommon = GetRobotCommon(gameId, roomId);
    if (pCommon)
    {
        return pCommon->GetRobot(robotId);
    }
    return NULL;
}

int NFRobotMgr::SetRobotJetton(uint32_t gameId, uint32_t roomId, uint64_t robotId, uint64_t jetton)
{
    NFRobotCommon* pCommon = GetRobotCommon(gameId, roomId);
    if (pCommon)
    {
        auto pRobot = pCommon->GetRobot(robotId);
        if (pRobot)
        {
            pRobot->jetton = jetton;
            pCommon->MarkDirty();
            return 0;
        }
    }
    return -1;
}

uint64_t NFRobotMgr::GetFreeRobot(uint32_t gameId, uint32_t roomId)
{
    NFRobotCommon* pRobotCommon = GetRobotCommon(gameId, roomId);
    if (pRobotCommon)
    {
        proto_ff_s::RobotCommonData_s* pData = pRobotCommon->GetFreeRobot();
        if (pData)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, pData->robot_id, "GetFreeRobot:{}", pData->robot_id);
            pData->is_use = true;
            return pData->robot_id;
        }
    }
    return 0;
}

int NFRobotMgr::CreateRobot(uint32_t gameId, uint32_t roomId)
{
    NFTransCreateRobot* pTrans = dynamic_cast<NFTransCreateRobot *>(NFShmMgr::Instance()->CreateTrans(EOT_GAME_CREATE_ROBOT_TRANS_ID));
    CHECK_EXPR(pTrans, -1, "pTrans createobj failed!");

    pTrans->Init(gameId, roomId);
    return 0;
}

