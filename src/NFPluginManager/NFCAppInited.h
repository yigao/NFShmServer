// -------------------------------------------------------------------------
//    @FileName         :    dllmain.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginManager
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include <unordered_map>
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFPluginModule/NFObject.h"

class NFCAppInitTask
{
public:
    NFCAppInitTask() : m_taskType(APP_INIT_NONE), m_finished(false)
    {
    }

public:
    uint32_t m_taskType;
    bool m_finished;
    std::string m_desc;
};

class NFCAppInited : public NFObject
{
public:
    NFCAppInited(NFIPluginManager *pPluginManager) : NFObject(pPluginManager), m_initServerConnectTasks(false), m_initDestStoreTasks(false),
                                                     m_initOBjLoadForomDBTasks(false), m_initServerRegisterTasks(false)
    {
        m_serverConnectTasks.resize(NF_ST_MAX);
        for(int i = 0; i < (int)m_serverConnectTasks.size(); i++)
        {
            m_serverConnectTasks[i].first = false;
        }
        m_serverLoadDestStore.resize(NF_ST_MAX);
        for(int i = 0; i < (int)m_serverLoadDestStore.size(); i++)
        {
            m_serverLoadDestStore[i].first = false;
        }
        m_appObjLoadFromDBTask.resize(NF_ST_MAX);
        for(int i = 0; i < (int)m_appObjLoadFromDBTask.size(); i++)
        {
            m_appObjLoadFromDBTask[i].first = false;
        }
        m_serverRegisterTask.resize(NF_ST_MAX);
        for(int i = 0; i < (int)m_serverRegisterTask.size(); i++)
        {
            m_serverRegisterTask[i].first = false;
        }
        m_initedFlag.resize(NF_ST_MAX);
        for (int i = 0; i < (int) m_initedFlag.size(); i++)
        {
            m_initedFlag[i] = false;
        }
        m_lastTime = NFGetSecondTime();
    }

    virtual ~NFCAppInited()
    {

    }

    int Execute();

    int
    RegisterAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, const std::string &desc, uint32_t initStatus = APP_INIT_STATUS_SERVER_CONNECT);

    int FinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, uint32_t initStatus = APP_INIT_STATUS_SERVER_CONNECT);

    int CheckTaskFinished();

    bool IsInitTasked() const;

    void PrintTimeout();

    bool IsInited(NF_SERVER_TYPES eServerType) const;

private:
    std::vector<std::pair<bool, std::vector<NFCAppInitTask>>> m_serverConnectTasks;
    std::vector<std::pair<bool, std::vector<NFCAppInitTask>>> m_serverLoadDestStore;
    std::vector<std::pair<bool, std::vector<NFCAppInitTask>>> m_appObjLoadFromDBTask;
    std::vector<std::pair<bool, std::vector<NFCAppInitTask>>> m_serverRegisterTask;
    std::vector<bool> m_initedFlag;
    bool m_initServerConnectTasks;
    bool m_initDestStoreTasks;
    bool m_initOBjLoadForomDBTasks;
    bool m_initServerRegisterTasks;
    uint64_t m_lastTime;
};
