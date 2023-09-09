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

int NFCAppInited::RegisterAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, const std::string& desc, uint32_t taskGroup)
{
    CHECK_EXPR(eServerType < (uint32_t)m_serverTaskGroup.size(), -1, "serverType:{} taskType:{} desc:{} taskGroup:{}", eServerType, taskType, desc, taskGroup);
    CHECK_EXPR(taskGroup < (uint32_t)m_serverTaskGroup[eServerType].m_taskGroupList.size(), -1, "serverType:{} taskType:{} desc:{} taskGroup:{}", eServerType, taskType, desc, taskGroup);

    NFCAppInitTask task;
    task.m_taskType = taskType;
    task.m_desc = desc;

    if (eServerType == NF_ST_NONE)
    {
        for(int i = 1; i < (int)m_serverTaskGroup.size(); i++)
        {
            m_serverTaskGroup[i].m_taskGroupList[taskGroup].m_taskList.push_back(task);
        }
    }
    else {
        m_serverTaskGroup[eServerType].m_taskGroupList[taskGroup].m_taskList.push_back(task);
    }

    return 0;
}

int NFCAppInited::FinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, uint32_t taskGroup)
{
    CHECK_EXPR(eServerType < (uint32_t)m_serverTaskGroup.size(), -1, "serverType:{} taskType:{} taskGroup:{}", eServerType, taskType, taskGroup);
    CHECK_EXPR(taskGroup < (uint32_t)m_serverTaskGroup[eServerType].m_taskGroupList.size(), -1, "serverType:{} taskType:{} taskGroup:{}", eServerType, taskType, taskGroup);

    bool flag = false;
    if (eServerType == NF_ST_NONE)
    {
        for(int j = 1; j < (int)m_serverTaskGroup.size(); j++)
        {
            for(int i = 0; i < (int)m_serverTaskGroup[j].m_taskGroupList[taskGroup].m_taskList.size(); i++)
            {
                NFCAppInitTask& task = m_serverTaskGroup[j].m_taskGroupList[taskGroup].m_taskList[i];
                if (task.m_taskType == taskType)
                {
                    flag = true;
                    if (task.m_finished == false)
                    {
                        task.m_finished = true;
                        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Finish App Init Task, serverType:{}  desc:{}", j, task.m_desc);
                    }
                }
            }
        }
    }
    else {
        for(int i = 0; i < (int)m_serverTaskGroup[eServerType].m_taskGroupList[taskGroup].m_taskList.size(); i++)
        {
            NFCAppInitTask& task = m_serverTaskGroup[eServerType].m_taskGroupList[taskGroup].m_taskList[i];
            if (task.m_taskType == taskType)
            {
                flag = true;
                if (task.m_finished == false)
                {
                    task.m_finished = true;
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Finish App Init Task, serverType:{}  desc:{}", eServerType, task.m_desc);
                }
            }
        }
    }

    if (flag == false)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Not Find the App Init Task, serverType:{} taskGroup:{} taskType:{} ", eServerType, taskGroup, taskType);
    }

	return 0;
}

int NFCAppInited::CheckTaskFinished()
{
    for(int i = 0; i < (int)m_taskGroupFlag.size(); i++)
    {
        if (!m_taskGroupFlag[i])
        {
            m_taskGroupFlag[i] = true;
            for(int j = 1; j < (int)m_serverTaskGroup.size(); j++)
            {
                if (m_serverTaskGroup[j].m_taskGroupList[i].m_finishAllFlag == false)
                {
                    m_serverTaskGroup[j].m_taskGroupList[i].m_finishAllFlag = true;
                    for(int x = 0; x < (int)m_serverTaskGroup[j].m_taskGroupList[i].m_taskList.size(); x++)
                    {
                        if (m_serverTaskGroup[j].m_taskGroupList[i].m_taskList[x].m_finished == false)
                        {
                            m_taskGroupFlag[i] = false;
                            m_serverTaskGroup[j].m_taskGroupList[i].m_finishAllFlag = false;
                            break;
                        }
                    }

                    if (m_serverTaskGroup[j].m_taskGroupList[i].m_finishAllFlag)
                    {
                        proto_ff::NFEventNoneData event;
                        FindModule<NFIEventModule>()->FireExecute(j, proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH, proto_ff::NF_EVENT_SERVER_TYPE, i, event);
                    }
                }
            }

            if (m_taskGroupFlag[i])
            {
                proto_ff::NFEventNoneData event;
                FindModule<NFIEventModule>()->FireExecute(NF_ST_NONE, proto_ff::NF_EVENT_SERVER_TASK_GROUP_FINISH, proto_ff::NF_EVENT_SERVER_TYPE, i, event);

                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "App Finish All Server {} Task Group..............", i);
            }
        }
    }

    for(int i = 1; i < (int)m_serverTaskGroup.size(); i++)
    {
        if (!m_serverTaskGroup[i].m_isInited)
        {
            bool flag = true;
            for(int j = 0; j < (int)m_serverTaskGroup[i].m_taskGroupList.size(); j++)
            {
                if (!m_serverTaskGroup[i].m_taskGroupList[j].m_finishAllFlag)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                m_serverTaskGroup[i].m_isInited = true;
                proto_ff::NFEventNoneData event;
                FindModule<NFIEventModule>()->FireExecute(i, proto_ff::NF_EVENT_SERVER_APP_FINISH_INITED, proto_ff::NF_EVENT_SERVER_TYPE, 0, event);

                if (m_pObjPluginManager->IsLoadAllServer())
                {
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Server:{}({}) Finish All Task, App Inited Success..............", GetServerName((NF_SERVER_TYPES)i), i);
                }
            }
        }
    }

    if (IsInitTasked())
    {
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
    bool flag = true;
    for(int i = 1; i < (int)m_taskGroupFlag.size(); i++)
    {
        if (m_taskGroupFlag[i] == false)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

bool NFCAppInited::IsInited(NF_SERVER_TYPES eServerType) const
{
    CHECK_EXPR(eServerType < (uint32_t)m_serverTaskGroup.size(), false, "");
    return m_serverTaskGroup[eServerType].m_isInited;
}

bool NFCAppInited::IsFinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskGroup) const
{
    CHECK_EXPR(eServerType < (uint32_t)m_serverTaskGroup.size(), false, "serverType:{} taskGroup:{}", eServerType, taskGroup);
    CHECK_EXPR(taskGroup < (uint32_t)m_serverTaskGroup[eServerType].m_taskGroupList.size(), false, "serverType:{} taskGroup:{}", eServerType, taskGroup);

    return m_serverTaskGroup[eServerType].m_taskGroupList[taskGroup].m_finishAllFlag;
}

bool NFCAppInited::IsHasAppTask(NF_SERVER_TYPES eServerType, uint32_t taskGroup) const
{
    CHECK_EXPR(eServerType < (uint32_t)m_serverTaskGroup.size(), false, "serverType:{} taskGroup:{}", eServerType, taskGroup);
    CHECK_EXPR(taskGroup < (uint32_t)m_serverTaskGroup[eServerType].m_taskGroupList.size(), false, "serverType:{} taskGroup:{}", eServerType, taskGroup);

    return m_serverTaskGroup[eServerType].m_taskGroupList[taskGroup].m_taskList.size() > 0;
}

void NFCAppInited::PrintTimeout()
{
    if (NFGetSecondTime() - m_lastTime < 30)
    {
        return;
    }

    m_lastTime = NFGetSecondTime();

    for(int i = 0; i < (int)m_serverTaskGroup.size(); i++)
    {
        if (!m_serverTaskGroup[i].m_isInited)
        {
            for(int j = 0; j < (int)m_serverTaskGroup[i].m_taskGroupList.size(); j++)
            {
                if (!m_serverTaskGroup[i].m_taskGroupList[j].m_finishAllFlag)
                {
                    for(int x = 0; x < (int)m_serverTaskGroup[i].m_taskGroupList[j].m_taskList.size(); x++)
                    {
                        if (m_serverTaskGroup[i].m_taskGroupList[j].m_taskList[x].m_finished == false)
                        {
                            NFLogError(NF_LOG_SYSTEMLOG, 0, "App Init Task:{} not finish", m_serverTaskGroup[i].m_taskGroupList[j].m_taskList[x].m_desc);
                        }
                    }
                }
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