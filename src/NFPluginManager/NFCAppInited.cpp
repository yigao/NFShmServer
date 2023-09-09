// -------------------------------------------------------------------------
//    @FileName         :    dllmain.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginManager
//
// -------------------------------------------------------------------------

#include "NFCAppInited.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"
#include "NFComm/NFPluginModule/NFIEventModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"

int NFCAppInited::RegisterAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, const std::string& desc, uint32_t initStatus)
{
    if (initStatus == APP_INIT_STATUS_SERVER_CONNECT)
    {
        CHECK_EXPR(eServerType < (int)m_serverConnectTasks.size(), -1, "serverType:{} taskType:{} desc:{}", eServerType, taskType, desc);
        NFCAppInitTask task;
        task.m_taskType = taskType;
        task.m_desc = desc;

        m_serverConnectTasks[eServerType].second.push_back(task);
    }
    else if (initStatus == APP_INIT_STATUS_SERVER_LOAD_DESC_STORE)
    {
        CHECK_EXPR(eServerType < (int)m_serverLoadDestStore.size(), -1, "serverType:{} taskType:{} desc:{}", eServerType, taskType, desc);
        NFCAppInitTask task;
        task.m_taskType = taskType;
        task.m_desc = desc;

        m_serverLoadDestStore[eServerType].second.push_back(task);
    }
    else if (initStatus == APP_INIT_STATUS_SERVER_LOAD_OBJ_FROM_DB)
    {
        CHECK_EXPR(eServerType < (int)m_appObjLoadFromDBTask.size(), -1, "serverType:{} taskType:{} desc:{}", eServerType, taskType, desc);
        NFCAppInitTask task;
        task.m_taskType = taskType;
        task.m_desc = desc;

        m_appObjLoadFromDBTask[eServerType].second.push_back(task);
    }
    else if (initStatus == APP_INIT_STATUS_SERVER_REGISTER)
    {
        CHECK_EXPR(eServerType < (int)m_serverRegisterTask.size(), -1, "serverType:{} taskType:{} desc:{}", eServerType, taskType, desc);
        NFCAppInitTask task;
        task.m_taskType = taskType;
        task.m_desc = desc;

        m_serverRegisterTask[eServerType].second.push_back(task);
    }


    return 0;
}

int NFCAppInited::FinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, uint32_t initStatus)
{
    bool flag = false;
    if (initStatus == APP_INIT_STATUS_SERVER_CONNECT)
    {
        CHECK_EXPR(eServerType < (int)m_serverConnectTasks.size(), -1, "serverType:{} taskType:{}", eServerType, taskType);
        for(int i = 0; i < (int)m_serverConnectTasks[eServerType].second.size(); i++)
        {
            if (m_serverConnectTasks[eServerType].second[i].m_taskType == taskType)
            {
                flag = true;
                if (m_serverConnectTasks[eServerType].second[i].m_finished == false)
                {
                    m_serverConnectTasks[eServerType].second[i].m_finished = true;
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Finish App Init Task, serverType:{} taskType:{} desc:{}", eServerType, taskType, m_serverConnectTasks[eServerType].second[i].m_desc);
                }
            }
        }
    }
    else if (initStatus == APP_INIT_STATUS_SERVER_LOAD_DESC_STORE)
    {
        CHECK_EXPR(eServerType >= 0 && eServerType < (int)m_serverLoadDestStore.size(), -1, "serverType:{} taskType:{}", eServerType, taskType);
        for(int i = 0; i < (int)m_serverLoadDestStore[eServerType].second.size(); i++)
        {
            if (m_serverLoadDestStore[eServerType].second[i].m_taskType == taskType)
            {
                flag = true;
                if (m_serverLoadDestStore[eServerType].second[i].m_finished == false)
                {
                    m_serverLoadDestStore[eServerType].second[i].m_finished = true;
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Finish App Init Task, serverType:{} taskType:{} desc:{}", eServerType, taskType, m_serverLoadDestStore[eServerType].second[i].m_desc);
                }
            }
        }
    }
    else if (initStatus == APP_INIT_STATUS_SERVER_LOAD_OBJ_FROM_DB)
    {
        CHECK_EXPR(eServerType < (int)m_appObjLoadFromDBTask.size(), -1, "serverType:{} taskType:{}", eServerType, taskType);
        for(int i = 0; i < (int)m_appObjLoadFromDBTask[eServerType].second.size(); i++)
        {
            if (m_appObjLoadFromDBTask[eServerType].second[i].m_taskType == taskType)
            {
                flag = true;
                if (m_appObjLoadFromDBTask[eServerType].second[i].m_finished == false)
                {
                    m_appObjLoadFromDBTask[eServerType].second[i].m_finished = true;
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Finish App Init Task, serverType:{} taskType:{} desc:{}", eServerType, taskType, m_appObjLoadFromDBTask[eServerType].second[i].m_desc);
                }
            }
        }
    }
    else if (initStatus == APP_INIT_STATUS_SERVER_REGISTER)
    {
        CHECK_EXPR(eServerType < (int)m_serverRegisterTask.size(), -1, "serverType:{} taskType:{}", eServerType, taskType);
        for(int i = 0; i < (int)m_serverRegisterTask[eServerType].second.size(); i++)
        {
            if (m_serverRegisterTask[eServerType].second[i].m_taskType == taskType)
            {
                flag = true;
                if (m_serverRegisterTask[eServerType].second[i].m_finished == false)
                {
                    m_serverRegisterTask[eServerType].second[i].m_finished = true;
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Finish App Init Task, serverType:{} taskType:{} desc:{}", eServerType, taskType, m_serverRegisterTask[eServerType].second[i].m_desc);
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
        m_initServerConnectTasks = true;
        for(int i = 0; i < (int)m_serverConnectTasks.size(); i++)
        {
            if (m_serverConnectTasks[i].first == false)
            {
                m_serverConnectTasks[i].first = true;
                for(int j = 0; j < (int)m_serverConnectTasks[i].second.size(); j++)
                {
                    if (m_serverConnectTasks[i].second[j].m_finished == false)
                    {
                        m_initServerConnectTasks = false;
                        m_serverConnectTasks[i].first = false;
                        break;
                    }
                }

                if (i > 0 && m_serverConnectTasks[i].first)
                {
                    proto_ff::NFEventNoneData event;
                    FindModule<NFIEventModule>()->FireExecute(i, proto_ff::NF_EVENT_SERVER_CONNECT_TASK_FINISH, proto_ff::NF_EVENT_SERVER_TYPE, 0, event);
                }
            }
        }

        if (m_initServerConnectTasks)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "App Finish All Server Connect Task..............");

            proto_ff::NFEventNoneData event;
            FindModule<NFIEventModule>()->FireExecute(NF_ST_NONE, proto_ff::NF_EVENT_SERVER_CONNECT_TASK_FINISH, proto_ff::NF_EVENT_SERVER_TYPE, 0, event);

            m_pObjPluginManager->AfterServerRegisterFinish();
        }
	}

    if (!m_initDestStoreTasks)
    {
        m_initDestStoreTasks = true;

        for(int i = 0; i < (int)m_serverLoadDestStore.size(); i++)
        {
            if (m_serverLoadDestStore[i].first == false)
            {
                m_serverLoadDestStore[i].first = true;
                for(int j = 0; j < (int)m_serverLoadDestStore[i].second.size(); j++)
                {
                    if (m_serverLoadDestStore[i].second[j].m_finished == false)
                    {
                        m_initDestStoreTasks = false;
                        m_serverLoadDestStore[i].first = false;
                        break;
                    }
                }

                if (!m_pObjPluginManager->IsLoadAllServer())
                {
                    if (i > 0 && m_serverLoadDestStore[i].first)
                    {
                        proto_ff::NFEventNoneData event;
                        FindModule<NFIEventModule>()->FireExecute(i, proto_ff::NF_EVENT_SERVER_LOAD_DESC_STORE, proto_ff::NF_EVENT_SERVER_TYPE, 0, event);
                    }
                }
            }
        }

        if (m_initDestStoreTasks)
        {
            if (m_pObjPluginManager->IsLoadAllServer())
            {
                for(int i = 0; i < (int)m_serverLoadDestStore.size(); i++)
                {
                    if (i > 0 && m_serverLoadDestStore[i].first)
                    {
                        proto_ff::NFEventNoneData event;
                        FindModule<NFIEventModule>()->FireExecute(i, proto_ff::NF_EVENT_SERVER_LOAD_DESC_STORE, proto_ff::NF_EVENT_SERVER_TYPE, 0, event);
                    }
                }
            }
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "App Finish All Desc Store Load Task..............");
            proto_ff::NFEventNoneData event;
            FindModule<NFIEventModule>()->FireExecute(NF_ST_NONE, proto_ff::NF_EVENT_SERVER_LOAD_DESC_STORE, proto_ff::NF_EVENT_SERVER_TYPE, 0, event);

            m_pObjPluginManager->AfterAllDescStoreLoaded();
        }
    }

    if (!m_initOBjLoadForomDBTasks)
    {
        m_initOBjLoadForomDBTasks = true;
        for(int i = 0; i < (int)m_appObjLoadFromDBTask.size(); i++)
        {
            if (m_appObjLoadFromDBTask[i].first == false)
            {
                m_appObjLoadFromDBTask[i].first = true;
                for(int j = 0; j < (int)m_appObjLoadFromDBTask[i].second.size(); j++)
                {
                    if (m_appObjLoadFromDBTask[i].second[j].m_finished == false)
                    {
                        m_initOBjLoadForomDBTasks = false;
                        m_appObjLoadFromDBTask[i].first = false;
                        break;
                    }
                }

                if (i > 0 && m_appObjLoadFromDBTask[i].first)
                {
                    proto_ff::NFEventNoneData event;
                    FindModule<NFIEventModule>()->FireExecute(i, proto_ff::NF_EVENT_SERVER_OBJ_LOAD_FROM_DB, proto_ff::NF_EVENT_SERVER_TYPE, 0, event);
                }
            }
        }

        if (m_initOBjLoadForomDBTasks)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "App Finish All Obj Load From DB Task..............");
            proto_ff::NFEventNoneData event;
            FindModule<NFIEventModule>()->FireExecute(NF_ST_NONE, proto_ff::NF_EVENT_SERVER_OBJ_LOAD_FROM_DB, proto_ff::NF_EVENT_SERVER_TYPE, 0, event);

            m_pObjPluginManager->AfterObjFromDBLoaded();
        }
    }

    if (!m_initServerRegisterTasks)
    {
        m_initServerRegisterTasks = true;
        for(int i = 0; i < (int)m_serverRegisterTask.size(); i++)
        {
            if (m_serverRegisterTask[i].first == false)
            {
                m_serverRegisterTask[i].first = true;
                for(int j = 0; j < (int)m_serverRegisterTask[i].second.size(); j++)
                {
                    if (m_serverRegisterTask[i].second[j].m_finished == false)
                    {
                        m_initServerRegisterTasks = false;
                        m_serverRegisterTask[i].first = false;
                        break;
                    }
                }

                if (i > 0 && m_serverRegisterTask[i].first)
                {
                    proto_ff::NFEventNoneData event;
                    FindModule<NFIEventModule>()->FireExecute(i, proto_ff::NF_EVENT_SERVER_REG_EVENT, proto_ff::NF_EVENT_SERVER_TYPE, 0, event);
                }
            }
        }

        if (m_initServerRegisterTasks)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "App Finish All Server Register Task..............");
            proto_ff::NFEventNoneData event;
            FindModule<NFIEventModule>()->FireExecute(NF_ST_NONE, proto_ff::NF_EVENT_SERVER_REG_EVENT, proto_ff::NF_EVENT_SERVER_TYPE, 0, event);

            m_pObjPluginManager->AfterServerRegisterFinish();
        }
    }

    for(int i = 1; i < (int)NF_ST_MAX; i++)
    {
        if (m_serverConnectTasks[i].first && m_serverLoadDestStore[i].first && m_appObjLoadFromDBTask[i].first && m_serverRegisterTask[i].first && m_initedFlag[i] == false)
        {
            m_initedFlag[i] = true;
            proto_ff::NFEventNoneData event;
            FindModule<NFIEventModule>()->FireExecute(i, proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED, proto_ff::NF_EVENT_SERVER_TYPE, 0, event);

            if (m_pObjPluginManager->IsLoadAllServer())
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Server:{}({}) Finish All Task, App Inited Success..............", GetServerName((NF_SERVER_TYPES)i), i);
            }
        }
    }

    if (IsInitTasked())
    {
        m_initedFlag[NF_ST_NONE] = true;
        m_pObjPluginManager->SetIsInited(true);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "App Finish All Task, App Inited Success..............");

        proto_ff::NFEventNoneData event;
        FindModule<NFIEventModule>()->FireExecute(NF_ST_NONE, proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED, proto_ff::NF_EVENT_SERVER_TYPE, 0, event);

        m_pObjPluginManager->AfterAppInitFinish();
    }

	return 0;
}

bool NFCAppInited::IsInitTasked() const
{
	return m_initDestStoreTasks && m_initServerConnectTasks && m_initOBjLoadForomDBTasks && m_initServerRegisterTasks;
}

bool NFCAppInited::IsInited(NF_SERVER_TYPES eServerType) const
{
    if (!m_initedFlag[eServerType])
    {
        return m_serverConnectTasks[eServerType].first;
    }
    return true;
}

bool NFCAppInited::IsFinishAppTask(NF_SERVER_TYPES eServerType, uint32_t initStatus) const
{
    if (initStatus == APP_INIT_STATUS_SERVER_CONNECT)
    {
        CHECK_EXPR(eServerType < (int)m_serverConnectTasks.size(), false, "serverType:{} initStatus:{}", eServerType, initStatus);
        for(int i = 0; i < (int)m_serverConnectTasks[eServerType].second.size(); i++)
        {
            if (m_serverConnectTasks[eServerType].second[i].m_finished == false)
            {
                return false;
            }
        }
    }
    else if (initStatus == APP_INIT_STATUS_SERVER_LOAD_DESC_STORE)
    {
        CHECK_EXPR(eServerType >= 0 && eServerType < (int)m_serverLoadDestStore.size(), false, "serverType:{} initStatus:{}", eServerType, initStatus);
        for(int i = 0; i < (int)m_serverLoadDestStore[eServerType].second.size(); i++)
        {
            if (m_serverLoadDestStore[eServerType].second[i].m_finished == false)
            {
                return false;
            }
        }
    }
    else if (initStatus == APP_INIT_STATUS_SERVER_LOAD_OBJ_FROM_DB)
    {
        CHECK_EXPR(eServerType < (int)m_appObjLoadFromDBTask.size(), false, "serverType:{} initStatus:{}", eServerType, initStatus);
        for(int i = 0; i < (int)m_appObjLoadFromDBTask[eServerType].second.size(); i++)
        {
            if (m_appObjLoadFromDBTask[eServerType].second[i].m_finished == false)
            {
                return false;
            }
        }
    }
    else if (initStatus == APP_INIT_STATUS_SERVER_REGISTER)
    {
        CHECK_EXPR(eServerType < (int)m_serverRegisterTask.size(), false, "serverType:{} initStatus:{}", eServerType, initStatus);
        for(int i = 0; i < (int)m_serverRegisterTask[eServerType].second.size(); i++)
        {
            if (m_serverRegisterTask[eServerType].second[i].m_finished == false)
            {
                return false;
            }
        }
    }

    return true;
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
        for(int j = 0; j < (int)m_serverConnectTasks[i].second.size(); j++)
        {
            if (m_serverConnectTasks[i].second[j].m_finished == false)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "App Init Task:{} not finish", m_serverConnectTasks[i].second[j].m_desc);
            }
        }
    }

    for(int i = 0; i < (int)m_serverLoadDestStore.size(); i++)
    {
        for(int j = 0; j < (int)m_serverLoadDestStore[i].second.size(); j++)
        {
            if (m_serverLoadDestStore[i].second[j].m_finished == false)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "App Init Task:{} not finish", m_serverLoadDestStore[i].second[j].m_desc);
            }
        }
    }

    for(int i = 0; i < (int)m_appObjLoadFromDBTask.size(); i++)
    {
        for(int j = 0; j < (int)m_appObjLoadFromDBTask[i].second.size(); j++)
        {
            if (m_appObjLoadFromDBTask[i].second[j].m_finished == false)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "App Init Task:{} not finish", m_appObjLoadFromDBTask[i].second[j].m_desc);
            }
        }
    }

    for(int i = 0; i < (int)m_serverRegisterTask.size(); i++)
    {
        for(int j = 0; j < (int)m_serverRegisterTask[i].second.size(); j++)
        {
            if (m_serverRegisterTask[i].second[j].m_finished == false)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "App Init Task:{} not finish", m_serverRegisterTask[i].second[j].m_desc);
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