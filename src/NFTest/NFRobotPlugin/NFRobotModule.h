// -------------------------------------------------------------------------
//    @FileName         :    NFRobotModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFRobotModule.h
//
// -------------------------------------------------------------------------

#pragma once
#include <string>

#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFPluginModule/NFTimerMgr.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"

class NFTestRobot;
class NFCRobotModule : public NFIModule, NFTimerObj
{
public:
    explicit NFCRobotModule(NFIPluginManager* p);
    virtual ~NFCRobotModule();

    virtual bool Init() override;

    virtual bool Execute() override;

    virtual bool BeforeShut() override;

    virtual bool Shut() override;

    virtual void OnTimer(uint32_t nTimerID) override;

    NFTestRobot* CreateRobot();
    uint64_t GetRandRobotUserId();
    void AddUserId(uint64_t userId) { m_robotUserIdList.push_back(userId); }
public:
    uint32_t m_robotIndex;
    std::map<uint32_t, NFTestRobot*> m_robotMap;
    std::vector<uint32_t> m_robotUserIdList;
    uint32_t m_startId;
    uint32_t m_robotNum;
    std::string m_serverIp;
    uint32_t m_port;
};
