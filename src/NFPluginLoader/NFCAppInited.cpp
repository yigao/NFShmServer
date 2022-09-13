// -------------------------------------------------------------------------
//    @FileName         :    dllmain.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginLoader
//
// -------------------------------------------------------------------------

#include "NFCAppInited.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"
#include "NFComm/NFPluginModule/NFEventMgr.h"

int NFCAppInited::RegisterAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, const std::string& desc, uint32_t initStatus)
{
    if (initStatus == APP_INIT_STATUS_SERVER_CONNECT)
    {
        CHECK_EXPR(eServerType < (int)m_serverConnectTasks.size(), -1, "serverType:{} taskType:{} desc:{}", eServerType, taskType, desc);
        NFCAppInitTask task;
        task.m_taskType = taskType;
        task.m_desc = desc;

        m_serverConnectTasks[eServerType].push_back(task);
        m_initServerConnectTasks = false;
    }
    else if (initStatus == APP_INIT_STATUS_SERVER_LOAD_DESC_STORE)
    {
        CHECK_EXPR(eServerType < (int)m_serverLoadDestStore.size(), -1, "serverType:{} taskType:{} desc:{}", eServerType, taskType, desc);
        NFCAppInitTask task;
        task.m_taskType = taskType;
        task.m_desc = desc;

        m_serverLoadDestStore[eServerType].push_back(task);
        m_initDestStoreTasks = false;
    }
    else if (initStatus == APP_INIT_STATUS_SERVER_LOAD_OBJ_FROM_DB)
    {
        CHECK_EXPR(eServerType < (int)m_appObjLoadFromDBTask.size(), -1, "serverType:{} taskType:{} desc:{}", eServerType, taskType, desc);
        NFCAppInitTask task;
        task.m_taskType = taskType;
        task.m_desc = desc;

        m_appObjLoadFromDBTask[eServerType].push_back(task);
        m_initOBjLoadForomDBTasks = false;


    }

	return 0;
}

int NFCAppInited::FinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, uint32_t initStatus)
{
    bool flag = false;
    if (initStatus == APP_INIT_STATUS_SERVER_CONNECT)
    {
        CHECK_EXPR(eServerType < (int)m_serverConnectTasks.size(), -1, "serverType:{} taskType:{}", eServerType, taskType);
        for(int i = 0; i < (int)m_serverConnectTasks[eServerType].size(); i++)
        {
            if (m_serverConnectTasks[eServerType][i].m_taskType == taskType)
            {
                flag = true;
                if (m_serverConnectTasks[eServerType][i].m_finished == false)
                {
                    m_serverConnectTasks[eServerType][i].m_finished = true;
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Finish App Init Task, serverType:{} taskType:{} desc:{}", eServerType, taskType, m_serverConnectTasks[eServerType][i].m_desc);
                }
            }
        }
    }
    else if (initStatus == APP_INIT_STATUS_SERVER_LOAD_DESC_STORE)
    {
        CHECK_EXPR(eServerType >= 0 && eServerType < (int)m_serverLoadDestStore.size(), -1, "serverType:{} taskType:{}", eServerType, taskType);
        for(int i = 0; i < (int)m_serverLoadDestStore[eServerType].size(); i++)
        {
            if (m_serverLoadDestStore[eServerType][i].m_taskType == taskType)
            {
                flag = true;
                if (m_serverLoadDestStore[eServerType][i].m_finished == false)
                {
                    m_serverLoadDestStore[eServerType][i].m_finished = true;
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Finish App Init Task, serverType:{} taskType:{} desc:{}", eServerType, taskType, m_serverLoadDestStore[eServerType][i].m_desc);
                }
            }
        }
    }
    else if (initStatus == APP_INIT_STATUS_SERVER_LOAD_OBJ_FROM_DB)
    {
        CHECK_EXPR(eServerType < (int)m_appObjLoadFromDBTask.size(), -1, "serverType:{} taskType:{}", eServerType, taskType);
        for(int i = 0; i < (int)m_appObjLoadFromDBTask[eServerType].size(); i++)
        {
            if (m_appObjLoadFromDBTask[eServerType][i].m_taskType == taskType)
            {
                flag = true;
                if (m_appObjLoadFromDBTask[eServerType][i].m_finished == false)
                {
                    m_appObjLoadFromDBTask[eServerType][i].m_finished = true;
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Finish App Init Task, serverType:{} taskType:{} desc:{}", eServerType, taskType, m_appObjLoadFromDBTask[eServerType][i].m_desc);
                }
            }
        }
    }

    if (flag == false)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Not Find the App Init Task, serverType:{} taskType:{} initStatus:{}", eServerType, taskType, initStatus);
    }

	return 0;
}

int NFCAppInited::CheckTaskFinished()
{
	if (!m_initServerConnectTasks)
	{
	    bool flag = true;
	    for(int i = 0; i < (int)m_serverConnectTasks.size(); i++)
        {
	        for(int j = 0; j < (int)m_serverConnectTasks[i].size(); j++)
            {
	            if (m_serverConnectTasks[i][j].m_finished == false)
                {
	                flag = false;
	                break;
                }
            }

            if (flag == false)
            {
                break;
            }
        }

        if (flag)
        {
            m_initServerConnectTasks = true;

            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "App Finish All Server Connect Task..............");

            proto_ff::NFEventNoneData event;
            NFEventMgr::Instance()->FireExecute(proto_ff::NF_EVENT_SERVER_APP_TASK_FINISH, 0, proto_ff::NF_EVENT_SERVER_TYPE, event);
        }
	}
	else
    {
        if (!m_initDestStoreTasks)
        {
            bool flag = true;
            for(int i = 0; i < (int)m_serverLoadDestStore.size(); i++)
            {
                for(int j = 0; j < (int)m_serverLoadDestStore[i].size(); j++)
                {
                    if (m_serverLoadDestStore[i][j].m_finished == false)
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag == false)
                {
                    break;
                }
            }


            if (flag)
            {
                m_initDestStoreTasks = true;

                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "App Finish All Desc Store Load Task..............");

                proto_ff::NFEventNoneData event;
                NFEventMgr::Instance()->FireExecute(proto_ff::NF_EVENT_SERVER_LOAD_DESC_STORE, 0, proto_ff::NF_EVENT_SERVER_TYPE, event);
            }
        }
        else
        {
            if (!m_initOBjLoadForomDBTasks)
            {
                bool flag = true;
                for(int i = 0; i < (int)m_appObjLoadFromDBTask.size(); i++)
                {
                    for(int j = 0; j < (int)m_appObjLoadFromDBTask[i].size(); j++)
                    {
                        if (m_appObjLoadFromDBTask[i][j].m_finished == false)
                        {
                            flag = false;
                            break;
                        }
                    }

                    if (flag == false)
                    {
                        break;
                    }
                }


                if (flag)
                {
                    m_initOBjLoadForomDBTasks = true;

                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "App Finish All Obj Load From DB Task..............");

                    proto_ff::NFEventNoneData event;
                    NFEventMgr::Instance()->FireExecute(proto_ff::NF_EVENT_SERVER_OBJ_LOAD_FROM_DB, 0, proto_ff::NF_EVENT_SERVER_TYPE, event);
                }
            }
        }
    }

	return 0;
}

bool NFCAppInited::IsInitTasked() const
{
	return m_initDestStoreTasks && m_initServerConnectTasks && m_initOBjLoadForomDBTasks;
}

void NFCAppInited::PrintTimeout()
{
    if (NFGetSecondTime() - m_lastTime < 30)
    {
        return;
    }

    m_lastTime = NFGetSecondTime();

    for(int i = 0; i < (int)m_serverConnectTasks.size(); i++)
    {
        for(int j = 0; j < (int)m_serverConnectTasks[i].size(); j++)
        {
            if (m_serverConnectTasks[i][j].m_finished == false)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "App Init Task:{} not finish", m_serverConnectTasks[i][j].m_desc);
            }
        }
    }

    for(int i = 0; i < (int)m_serverLoadDestStore.size(); i++)
    {
        for(int j = 0; j < (int)m_serverLoadDestStore[i].size(); j++)
        {
            if (m_serverLoadDestStore[i][j].m_finished == false)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "App Init Task:{} not finish", m_serverLoadDestStore[i][j].m_desc);
            }
        }
    }

    for(int i = 0; i < (int)m_appObjLoadFromDBTask.size(); i++)
    {
        for(int j = 0; j < (int)m_appObjLoadFromDBTask[i].size(); j++)
        {
            if (m_appObjLoadFromDBTask[i][j].m_finished == false)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "App Init Task:{} not finish", m_appObjLoadFromDBTask[i][j].m_desc);
            }
        }
    }
}

int NFCAppInited::Execute()
{
    if (!IsInitTasked())
    {
        CheckTaskFinished();
        PrintTimeout();
    }
    return 0;
}