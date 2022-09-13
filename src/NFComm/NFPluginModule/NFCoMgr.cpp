// -------------------------------------------------------------------------
//    @FileName         :    NFCoMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCoMgr.cpp
//
// -------------------------------------------------------------------------

#include "NFCoMgr.h"
#include "NFLogMgr.h"
#include "NFCheck.h"
#include "NFCoroutineTask.h"

NFCoMgr::NFCoMgr() {
    m_pCoModule = NULL;
}

NFCoMgr::~NFCoMgr() {
   m_pCoModule = NULL;
}

bool NFCoMgr::Init(NFICoroutineModule *pModule) {
    m_pCoModule = pModule;
    return true;
}

void NFCoMgr::UnInit() {
    m_pCoModule = NULL;
}

int64_t NFCoMgr::Start(NFCoroutineTask* pTask, bool is_immediately)
{
    if (m_pCoModule)
    {
        return m_pCoModule->Start(pTask, is_immediately);
    }
    CHECK_EXPR(m_pCoModule, -1, "m_pCoModule == NULL");
    return -1;
}

int NFCoMgr::DeleteTask(NFCoroutineTask *pTask)
{
    if (m_pCoModule)
    {
        return m_pCoModule->DeleteTask(pTask);
    }
    CHECK_EXPR(m_pCoModule, -1, "m_pCoModule == NULL");
    return -1;
}

int NFCoMgr::AddTask(NFCoroutineTask *pTask)
{
    if (m_pCoModule)
    {
        return m_pCoModule->AddTask(pTask);
    }
    CHECK_EXPR(m_pCoModule, -1, "m_pCoModule == NULL");
    return -1;
}

int NFCoMgr::Size() const
{
    if (m_pCoModule)
    {
        return m_pCoModule->Size();
    }
    CHECK_EXPR(m_pCoModule, -1, "m_pCoModule == NULL");
    return -1;
}

NFCoroutineTask *NFCoMgr::CurrentTask() const
{
    if (m_pCoModule)
    {
        return m_pCoModule->CurrentTask();
    }
    CHECK_EXPR(m_pCoModule, NULL, "m_pCoModule == NULL");
    return NULL;
}

int64_t NFCoMgr::CurrentTaskId() const
{
    if (m_pCoModule)
    {
        return m_pCoModule->CurrentTaskId();
    }
    CHECK_EXPR(m_pCoModule, -1, "m_pCoModule == NULL");
    return -1;
}

int32_t NFCoMgr::Yield(int32_t timeout_ms)
{
    if (m_pCoModule)
    {
        return m_pCoModule->Yield(timeout_ms);
    }
    CHECK_EXPR(m_pCoModule, -1, "m_pCoModule == NULL");
    return -1;
}

int32_t NFCoMgr::Resume(int64_t id, int32_t result)
{
    if (m_pCoModule)
    {
        return m_pCoModule->Resume(id, result);
    }
    CHECK_EXPR(m_pCoModule, -1, "m_pCoModule == NULL");
    return -1;
}

int NFCoMgr::Status(int64_t id)
{
    if (m_pCoModule)
    {
        return m_pCoModule->Status(id);
    }
    CHECK_EXPR(m_pCoModule, -1, "m_pCoModule == NULL");
    return -1;
}

int NFCoMgr::MakeCoroutine(const std::function<void()> &func)
{
    NFCommonCoroutineTask *pTask = NewTask<NFCommonCoroutineTask>();
    if (pTask == NULL) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "new co task failed!");
        return -1;
    }

    pTask->Init(func);
    int64_t coid = pTask->Start(true);
    return coid < 0 ? -1 : 0;
}