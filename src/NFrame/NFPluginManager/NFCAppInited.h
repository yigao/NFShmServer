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

class NFCAppInitTaskGroup
{
public:
    NFCAppInitTaskGroup()
    {
        m_finishAllFlag = false;
    }
    std::vector<NFCAppInitTask> m_taskList;
    bool m_finishAllFlag;
};

class NFCServerAppInitTaskGroup
{
public:
    NFCServerAppInitTaskGroup()
    {
        m_taskGroupList.resize(APP_INIT_MAX_TASK_GROUP);
        m_isInited = false;
    }
    std::vector<NFCAppInitTaskGroup> m_taskGroupList;
    bool m_isInited;
};

class NFCAppInited : public NFObject
{
public:
    NFCAppInited(NFIPluginManager *pPluginManager) : NFObject(pPluginManager)
    {
        m_serverTaskGroup.resize(NF_ST_MAX);
        m_serverTaskGroup[NF_ST_NONE].m_isInited = true;
        for(int i = 0; i < (int)m_serverTaskGroup[NF_ST_NONE].m_taskGroupList.size(); i++)
        {
            m_serverTaskGroup[NF_ST_NONE].m_taskGroupList[i].m_finishAllFlag = true;
        }
        m_taskGroupFlag.resize(APP_INIT_MAX_TASK_GROUP);
        for(int i = 0; i < (int)m_taskGroupFlag.size(); i++)
        {
            m_taskGroupFlag[i] = false;
        }

        m_lastTime = NFGetSecondTime();
    }

    virtual ~NFCAppInited()
    {

    }

    int Execute();

    int
    RegisterAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, const std::string &desc, uint32_t taskGroup = APP_INIT_TASK_GROUP_SERVER_CONNECT);

    int FinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskType, uint32_t taskGroup = APP_INIT_TASK_GROUP_SERVER_CONNECT);

    int CheckTaskFinished();

    bool IsInitTasked() const;

    void PrintTimeout();

    bool IsInited(NF_SERVER_TYPES eServerType) const;

    bool IsFinishAppTask(NF_SERVER_TYPES eServerType, uint32_t taskGroup) const;

    bool IsHasAppTask(NF_SERVER_TYPES eServerType, uint32_t taskGroup) const;

    bool IsHasAppTask(NF_SERVER_TYPES eServerType, uint32_t taskGroup, uint32_t taskType) const;
private:
    std::vector<NFCServerAppInitTaskGroup> m_serverTaskGroup;
    std::vector<bool> m_taskGroupFlag;
    uint64_t m_lastTime;
};
