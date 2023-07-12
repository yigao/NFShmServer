// -------------------------------------------------------------------------
//    @FileName         :    NFCCoroutineModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCCoroutineModule.cpp
//
// -------------------------------------------------------------------------

#include "NFCCoroutineModule.h"
#include "NFCoroutineSchedule.h"

#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFICoroutineModule.h"
#include "NFSchedule.h"
#include "NFComm/NFPluginModule/NFCoroutineTask.h"

void DoTask(NFSchedule *, void *ud)
{
    NFCoroutineTask *task = static_cast<NFCoroutineTask *>(ud);
    assert(task != NULL);
    task->Run();
    delete task;
}

NFCCoroutineModule::NFCCoroutineModule(NFIPluginManager *p) : NFICoroutineModule(p)
{
    m_pCorSched = NF_NEW NFCoroutineSchedule(p);
    m_pCorSched->Init();
}

NFCCoroutineModule::~NFCCoroutineModule()
{

}

bool NFCCoroutineModule::OnStopServer()
{
    if (m_pCorSched)
    {
        return m_pCorSched->OnStopServer();
    }

    return true;
}

bool NFCCoroutineModule::Shut()
{
    return true;
}

bool NFCCoroutineModule::Finalize()
{
    NF_SAFE_DELETE(m_pCorSched);
    return true;
}

bool NFCCoroutineModule::Execute()
{
    return true;
}

int64_t NFCCoroutineModule::Start(NFCoroutineTask *pTask, bool is_immediately)
{
    CHECK_EXPR(pTask, -1, "pTask == NULL");
    CHECK_EXPR(m_pCorSched, -1, "m_pCorSched == NULL");

    if (is_immediately && m_pCorSched->CurrentTaskId() != INVALID_CO_ID)
    {
        delete pTask;
        return -1;
    }

    pTask->id_ = m_pCorSched->schedule_->CreateCoroutine(DoTask, pTask);
    int64_t id = pTask->id_;
    m_pCorSched->task_map_[pTask->id_] = pTask;
    m_pCorSched->pre_start_task_.erase(pTask);
    if (is_immediately)
    {
        int32_t ret = m_pCorSched->schedule_->CoroutineResume(pTask->id_);
        if (ret != 0)
        {
            id = -1;
        }
    }

    return id;
}

int NFCCoroutineModule::DeleteTask(NFCoroutineTask *pTask)
{
    CHECK_EXPR(pTask, -1, "pTask == NULL");
    CHECK_EXPR(m_pCorSched, -1, "m_pCorSched == NULL");

    if (m_pCorSched->schedule_ != NULL)
    {
        if (pTask->id_ == -1)
        {
            m_pCorSched->pre_start_task_.erase(pTask);
        }
        else
        {
            m_pCorSched->task_map_.erase(pTask->id_);
        }
    }
    return 0;
}

int NFCCoroutineModule::AddTask(NFCoroutineTask *pTask)
{
    CHECK_EXPR(pTask, -1, "pTask == NULL");
    CHECK_EXPR(m_pCorSched, -1, "m_pCorSched == NULL");
    return m_pCorSched->AddTaskToSchedule(pTask);
}

int NFCCoroutineModule::Size() const
{
    CHECK_EXPR(m_pCorSched, -1, "m_pCorSched == NULL");
    return m_pCorSched->Size();
}

NFCoroutineTask *NFCCoroutineModule::CurrentTask() const
{
    CHECK_EXPR(m_pCorSched, NULL, "m_pCorSched == NULL");
    return m_pCorSched->CurrentTask();
}

int64_t NFCCoroutineModule::CurrentTaskId() const
{
    CHECK_EXPR(m_pCorSched, -1, "m_pCorSched == NULL");
    return m_pCorSched->CurrentTaskId();
}

bool NFCCoroutineModule::IsInCoroutine() const
{
    CHECK_EXPR(m_pCorSched, false, "m_pCorSched == NULL");
    return m_pCorSched->IsInCoroutine();
}

int32_t NFCCoroutineModule::Yield(int32_t timeout_ms)
{
    CHECK_EXPR(m_pCorSched, -1, "m_pCorSched == NULL");
    return m_pCorSched->Yield(timeout_ms);
}

int32_t NFCCoroutineModule::Resume(int64_t id, int32_t result)
{
    CHECK_EXPR(m_pCorSched, -1, "m_pCorSched == NULL");
    return m_pCorSched->Resume(id, result);
}

int NFCCoroutineModule::Status(int64_t id)
{
    CHECK_EXPR(m_pCorSched, -1, "m_pCorSched == NULL");
    return m_pCorSched->Status(id);
}

google::protobuf::Message *NFCCoroutineModule::GetUserData(int64_t id)
{
    CHECK_EXPR(m_pCorSched, NULL, "m_pCorSched == NULL");
    return m_pCorSched->GetUserData(id);
}

int NFCCoroutineModule::SetUserData(google::protobuf::Message *pUserData)
{
    CHECK_EXPR(m_pCorSched, -1, "m_pCorSched == NULL");
    int64_t coId = CurrentTaskId();
    if (INVALID_CO_ID == coId)
    {
        return NULL;
    }
    return m_pCorSched->SetUserData(coId, pUserData);
}

/**
 * @brief 协程是否存在，是否已经死亡
 * @return
 */
bool NFCCoroutineModule::IsDead(int64_t id)
{
    return Status(id) == NF_COROUTINE_DEAD;
}

/**
 * @brief 是否正在运行
 * @return
 */
bool NFCCoroutineModule::IsRunning(int64_t id)
{
    return Status(id) == NF_COROUTINE_RUNNING;
}

/**
 * @brief 是否协程正在挂起
 * @return
 */
bool NFCCoroutineModule::IsYielding(int64_t id)
{
    return Status(id) == NF_COROUTINE_SUSPEND;
}

int64_t NFCCoroutineModule::MakeCoroutine(const std::function<void()> &func)
{
    NFCommonCoroutineTask *pTask = NewTask<NFCommonCoroutineTask>();
    if (pTask == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "new co task failed!");
        return -1;
    }

    pTask->Init(func);
    int64_t coid = pTask->Start(true);
    return coid < 0 ? -1 : coid;
}

