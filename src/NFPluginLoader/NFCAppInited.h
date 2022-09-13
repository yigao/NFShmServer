// -------------------------------------------------------------------------
//    @FileName         :    dllmain.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginLoader
//
// -------------------------------------------------------------------------

#pragma once
#include "NFComm/NFCore/NFPlatform.h"
#include <unordered_map>
#include "NFComm/NFPluginModule/NFServerDefine.h"

class NFCAppInitTask
{
public:
    NFCAppInitTask():m_taskType(APP_INIT_NONE),m_finished(false)
    {
    }
public:
    uint32_t m_taskType;
    bool m_finished;
    std::string m_desc;
};

class NFCAppInited
{
public:
	NFCAppInited(): m_initServerConnectTasks(false), m_initDestStoreTasks(false), m_initOBjLoadForomDBTasks(false)
	{
        m_serverConnectTasks.resize(NF_ST_MAX);
        m_serverLoadDestStore.resize(NF_ST_MAX);
        m_appObjLoadFromDBTask.resize(NF_ST_MAX);
        m_lastTime = NFGetSecondTime();
	}

	virtual ~NFCAppInited()
	{

	}

	int Execute();

	int RegisterAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, const std::string& desc, uint32_t initStatus = APP_INIT_STATUS_SERVER_CONNECT);

	int FinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, uint32_t initStatus = APP_INIT_STATUS_SERVER_CONNECT);

	int CheckTaskFinished();

	bool IsInitTasked() const;

	void PrintTimeout();
private:
    std::vector<std::vector<NFCAppInitTask>> m_serverConnectTasks;
    std::vector<std::vector<NFCAppInitTask>> m_serverLoadDestStore;
    std::vector<std::vector<NFCAppInitTask>> m_appObjLoadFromDBTask;
    bool m_initServerConnectTasks;
	bool m_initDestStoreTasks;
	bool m_initOBjLoadForomDBTasks;
	uint64_t m_lastTime;
};
