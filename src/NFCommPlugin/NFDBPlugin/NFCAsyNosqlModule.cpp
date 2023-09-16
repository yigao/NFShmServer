// -------------------------------------------------------------------------
//    @FileName         :    NFCAsyNoSqlModule.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFCAsyNoSqlModule
//
// -------------------------------------------------------------------------

#include "NFCAsyNosqlModule.h"
#include "NFCNosqlDriverManager.h"
#include "NFComm/NFPluginModule/NFITaskComponent.h"
#include "NFComm/NFPluginModule/NFCheck.h"

class NFNosqlTask : public NFTask
{
public:
    NFNosqlTask(const std::string &serverId) : m_serverId(serverId)
    {
        m_pNosqlDriver = nullptr;
        m_taskName = GET_CLASS_NAME(NFNosqlTask);
    }

    virtual ~NFNosqlTask()
    {
    }

    virtual bool IsCheck()
    {
        return false;
    }

    virtual bool IsConnect()
    {
        return false;
    }

public:
    NFINosqlDriver *m_pNosqlDriver;
    std::string m_serverId;
};

class NFNosqlConnectTask : public NFNosqlTask
{
public:
    NFNosqlConnectTask() : NFNosqlTask("")
    {
        m_taskName = GET_CLASS_NAME(NFNosqlConnectTask);
        nNosqlPort = 0;
    }

    virtual ~NFNosqlConnectTask()
    {
    }

    virtual bool IsConnect()
    {
        return true;
    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        return true;
    }

    /**
    ** 主线程处理函数，将在线程处理完后，提交给主线程来处理，根据返回函数是否继续处理
    返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
    */
    TPTaskState MainThreadProcess() override
    {
        return TPTASK_STATE_COMPLETED;
    }

public:
    std::string nServerID;
    std::string nNosqlIp;
    int nNosqlPort;
    std::string nNosqlPass;
};

class NFNosqlCheckTask : public NFNosqlTask
{
public:
    NFNosqlCheckTask() : NFNosqlTask("")
    {
        m_taskName = GET_CLASS_NAME(NFNosqlCheckTask);
    }

    virtual ~NFNosqlCheckTask()
    {
    }

    virtual bool IsCheck()
    {
        return true;
    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        return true;
    }

    /**
    ** 主线程处理函数，将在线程处理完后，提交给主线程来处理，根据返回函数是否继续处理
    返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
    */
    TPTaskState MainThreadProcess() override
    {
        return TPTASK_STATE_COMPLETED;
    }
};

class NFSelectObjNosqlTask : public NFNosqlTask
{
public:
    NFSelectObjNosqlTask(const std::string &serverId, const storesvr_sqldata::storesvr_selobj &select, const SelectObj_CB &cb) : NFNosqlTask(serverId)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFSelectObjNosqlTask);
    }

    virtual ~NFSelectObjNosqlTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pNosqlDriver)
        {
            iRet = m_pNosqlDriver->SelectObj(mSelect, mSelectRes);
        }
        else {
            iRet = -1;
        }

        return true;
    }

    /**
    ** 主线程处理函数，将在线程处理完后，提交给主线程来处理，根据返回函数是否继续处理
    返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
    */
    TPTaskState MainThreadProcess() override
    {
        if (mCB)
        {
            mCB(iRet, mSelectRes);
        }
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_selobj mSelect;
    storesvr_sqldata::storesvr_selobj_res mSelectRes;
    SelectObj_CB mCB;
    int iRet;
};

class NFDeleteObjNosqlTask : public NFNosqlTask
{
public:
    NFDeleteObjNosqlTask(const std::string &serverId, const storesvr_sqldata::storesvr_delobj &select, const DeleteObj_CB &cb) : NFNosqlTask(serverId)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFDeleteObjNosqlTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFDeleteObjNosqlTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pNosqlDriver)
        {
            iRet = m_pNosqlDriver->DeleteObj(mSelect);
        }
        return true;
    }

    /**
    ** 主线程处理函数，将在线程处理完后，提交给主线程来处理，根据返回函数是否继续处理
    返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
    */
    TPTaskState MainThreadProcess() override
    {
        if (mCB)
        {
            mCB(iRet, mSelectRes);
        }
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_delobj mSelect;
    storesvr_sqldata::storesvr_delobj_res mSelectRes;
    DeleteObj_CB mCB;
    int iRet;
};

class NFInsertObjNosqlTask : public NFNosqlTask
{
public:
    NFInsertObjNosqlTask(const std::string &serverId, const storesvr_sqldata::storesvr_insertobj &select, const InsertObj_CB &cb) : NFNosqlTask(serverId)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFInsertObjNosqlTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFInsertObjNosqlTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pNosqlDriver)
        {
            iRet = m_pNosqlDriver->SaveObj(mSelect, mSelectRes);
        }
        return true;
    }

    /**
    ** 主线程处理函数，将在线程处理完后，提交给主线程来处理，根据返回函数是否继续处理
    返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
    */
    TPTaskState MainThreadProcess() override
    {
        if (mCB)
        {
            mCB(iRet, mSelectRes);
        }
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_insertobj mSelect;
    storesvr_sqldata::storesvr_insertobj_res mSelectRes;
    InsertObj_CB mCB;
    int iRet;
};

class NFModifyObjNosqlTask : public NFNosqlTask
{
public:
    NFModifyObjNosqlTask(const std::string &serverId, const storesvr_sqldata::storesvr_modobj &select, const ModifyObj_CB &cb) : NFNosqlTask(serverId)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFModifyObjNosqlTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFModifyObjNosqlTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pNosqlDriver)
        {
            iRet = m_pNosqlDriver->SaveObj(mSelect, mSelectRes);
        }
        return true;
    }

    /**
    ** 主线程处理函数，将在线程处理完后，提交给主线程来处理，根据返回函数是否继续处理
    返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
    */
    TPTaskState MainThreadProcess() override
    {
        if (mCB)
        {
            mCB(iRet, mSelectRes);
        }
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_modobj mSelect;
    storesvr_sqldata::storesvr_modobj_res mSelectRes;
    ModifyObj_CB mCB;
    int iRet;
};

class NFDBUpdateObjTask : public NFNosqlTask
{
public:
    NFDBUpdateObjTask(const std::string &serverId, const storesvr_sqldata::storesvr_updateobj &select, const UpdateObj_CB &cb) : NFNosqlTask(serverId)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFDBUpdateObjTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFDBUpdateObjTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pNosqlDriver)
        {
            iRet = m_pNosqlDriver->SaveObj(mSelect, mSelectRes);
        }
        return true;
    }

    /**
    ** 主线程处理函数，将在线程处理完后，提交给主线程来处理，根据返回函数是否继续处理
    返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
    */
    TPTaskState MainThreadProcess() override
    {
        if (mCB)
        {
            mCB(iRet, mSelectRes);
        }
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_updateobj mSelect;
    storesvr_sqldata::storesvr_updateobj_res mSelectRes;
    UpdateObj_CB mCB;
    int iRet;
};

class NFNosqlTaskComponent : public NFITaskComponent
{
public:
    NFNosqlTaskComponent()
    {
        m_pNoSqlDriverManager = NF_NEW NFCNosqlDriverManager();
    }

    virtual ~NFNosqlTaskComponent()
    {
        NF_SAFE_DELETE(m_pNoSqlDriverManager);
    }


    void ProcessTaskStart(NFTask *pTask) override
    {
        NFNosqlTask *pMysqlTask = dynamic_cast<NFNosqlTask *>(pTask);
        if (pMysqlTask)
        {
            if (pMysqlTask->IsConnect())
            {
                NFNosqlConnectTask *pConnectTask = dynamic_cast<NFNosqlConnectTask *>(pTask);
                if (pConnectTask == NULL) return;
                int iRet = m_pNoSqlDriverManager->AddNosqlServer(pConnectTask->nServerID, pConnectTask->nNosqlIp, pConnectTask->nNosqlPort,
                                                                 pConnectTask->nNosqlPass);
                if (iRet != 0)
                {
                    NFSLEEP(1000);
                    exit(0);
                }
            }
            else if (pMysqlTask->IsCheck())
            {
                m_pNoSqlDriverManager->CheckNoSql();
            }
            else
            {
                m_pNoSqlDriverManager->CheckNoSql();
                pMysqlTask->m_pNosqlDriver = m_pNoSqlDriverManager->GetNosqlDriver(pMysqlTask->m_serverId);
                CHECK_EXPR(pMysqlTask->m_pNosqlDriver, , "GetNosqlDriver:{} Failed", pMysqlTask->m_serverId);
            }
        }
    }

    void ProcessTask(NFTask *pTask) override
    {
        if (pTask)
        {
            pTask->ThreadProcess();
        }
    }

    void ProcessTaskEnd(NFTask *pTask) override
    {
        NFNosqlTask *pMysqlTask = dynamic_cast<NFNosqlTask *>(pTask);
        if (pMysqlTask)
        {
            pMysqlTask->m_pNosqlDriver = nullptr;
        }
    }

    virtual void HandleTaskTimeOut(const std::string &taskName, uint64_t useTime) override
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "taskName:{} timeOut, userTime:{}", taskName, useTime);
    }

public:
    NFCNosqlDriverManager *m_pNoSqlDriverManager;
};


NFCAsyNosqlModule::NFCAsyNosqlModule(NFIPluginManager *p) : NFIAsyNosqlModule(p)
{
    mnLastCheckTime = NFGetTime();
    m_initComponet = false;
}

NFCAsyNosqlModule::~NFCAsyNosqlModule()
{

}

bool NFCAsyNosqlModule::Execute()
{
    return NFIModule::Execute();
}

bool NFCAsyNosqlModule::InitActorPool(int maxTaskGroup, int maxActorNum)
{
    NFIAsycModule::InitActorPool(maxTaskGroup, maxActorNum);
    if (!m_initComponet)
    {
        m_initComponet = true;
        for (size_t i = 0; i < m_vecActorGroupPool[NF_TASK_GROUP_DEFAULT].size(); i++)
        {
            NFNosqlTaskComponent *pComonnet = NF_NEW NFNosqlTaskComponent();
            AddActorComponent(NF_TASK_GROUP_DEFAULT, m_vecActorGroupPool[NF_TASK_GROUP_DEFAULT][i], pComonnet);
        }
    }

    return true;
}

int NFCAsyNosqlModule::AddDBServer(const std::string& nServerID, const string &noSqlIp, int nosqlPort, const string &noSqlPass)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    InitActorPool(NF_TASK_MAX_GROUP_DEFAULT);

    for (size_t i = 0; i < m_vecActorGroupPool[NF_TASK_GROUP_DEFAULT].size(); i++)
    {
        NFNosqlConnectTask *pTask = NF_NEW NFNosqlConnectTask();
        pTask->nServerID = nServerID;
        pTask->nNosqlIp = noSqlIp;
        pTask->nNosqlPort = nosqlPort;
        pTask->nNosqlPass = noSqlPass;
        int iRet = FindModule<NFITaskModule>()->AddTask(m_vecActorGroupPool[NF_TASK_GROUP_DEFAULT][i], pTask);
        CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyNosqlModule::SelectObj(const string &nServerID, const storesvr_sqldata::storesvr_selobj &select, const SelectObj_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFSelectObjNosqlTask *pTask = NF_NEW NFSelectObjNosqlTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyNosqlModule::DeleteObj(const string &nServerID, const storesvr_sqldata::storesvr_delobj &select, const DeleteObj_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFDeleteObjNosqlTask *pTask = NF_NEW NFDeleteObjNosqlTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyNosqlModule::InsertObj(const string &nServerID, const storesvr_sqldata::storesvr_insertobj &select, const InsertObj_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFInsertObjNosqlTask *pTask = NF_NEW NFInsertObjNosqlTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyNosqlModule::ModifyObj(const string &nServerID, const storesvr_sqldata::storesvr_modobj &select, const ModifyObj_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFModifyObjNosqlTask *pTask = NF_NEW NFModifyObjNosqlTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyNosqlModule::UpdateObj(const string &nServerID, const storesvr_sqldata::storesvr_updateobj &select, const UpdateObj_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFDBUpdateObjTask *pTask = NF_NEW NFDBUpdateObjTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}
