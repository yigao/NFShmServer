// -------------------------------------------------------------------------
//    @FileName         :    NFRobotModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFRobotModule.cpp
//
// -------------------------------------------------------------------------

#include "NFRobotModule.h"
#include "NFTestRobot.h"
#include "NFComm/NFCore/NFRandom.hpp"
#include "NFComm/NFCore/NFStringUtility.h"

NFCRobotModule::NFCRobotModule(NFIPluginManager* p):NFIDynamicModule(p)
{
    std::string param = p->GetStrParam();
    std::vector<std::string> vecParam;

    m_startId = 10000;
    m_robotNum = 1;
    m_serverIp = "127.0.0.1";
    m_port = 8013;
    NFStringUtility::SplitStringToVector(param, ",", vecParam);
    if (vecParam.size() >= 2)
    {
        m_startId = NFCommon::strto<int>(vecParam[0]);
        m_robotNum = NFCommon::strto<int>(vecParam[1]);
    }
    if (vecParam.size() >= 3)
    {
        m_serverIp = vecParam[2];
    }
    if (vecParam.size() >= 4)
    {
        m_port = NFCommon::strto<int>(vecParam[3]);
    }
    m_robotIndex = m_startId;
}

NFCRobotModule::~NFCRobotModule()
{
}

bool NFCRobotModule::Init()
{
    SetTimer(1, 10000, m_robotNum);
    return true;
}

NFTestRobot* NFCRobotModule::CreateRobot()
{
    NFTestRobot* pRobot = NF_NEW NFTestRobot(m_pObjPluginManager);
    pRobot->m_robotId = ++m_robotIndex;

    m_robotMap.emplace(pRobot->m_robotId, pRobot);

    return pRobot;
}

uint64_t NFCRobotModule::GetRandRobotUserId()
{
    int i = NFRandomInt(0, m_robotUserIdList.size());
    if (i >= 0 && i < (int)m_robotUserIdList.size())
    {
        return m_robotUserIdList[i];
    }
    else if (m_robotUserIdList.size() > 0)
    {
        return m_robotUserIdList[0];
    }
    else
    {
        if ((int)m_robotMap.size() > 0)
        {
            return m_robotMap.begin()->second->m_playerId;
        }
    }

    return 0;
}

int NFCRobotModule::OnTimer(uint32_t nTimerID)
{
    NFTestRobot* pRobot = CreateRobot();
    std::string url = NF_FORMAT("tcp://{}:{}", m_serverIp, m_port);
    pRobot->ConnectServer(url);
    return 0;
}

bool NFCRobotModule::Execute()
{
    return true;
}

bool NFCRobotModule::BeforeShut()
{
    return true;
}

bool NFCRobotModule::Shut()
{
    return true;
}

