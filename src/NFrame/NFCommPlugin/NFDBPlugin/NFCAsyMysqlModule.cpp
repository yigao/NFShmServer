// -------------------------------------------------------------------------
//    @FileName         :    NFCAsyMysqlModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Module           :    NFCAsyMysqlModule
//
// -------------------------------------------------------------------------

#include "NFCAsyMysqlModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFTask.h"
#include "NFComm/NFPluginModule/NFITaskComponent.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"

class NFMysqlTask : public NFTask
{
public:
    NFMysqlTask(const std::string& serverId):m_serverId(serverId)
    {
        m_pMysqlDriver = nullptr;
        m_taskName = GET_CLASS_NAME(NFMysqlTask);
    }

    virtual ~NFMysqlTask()
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
    NFCMysqlDriver* m_pMysqlDriver;
    std::string m_serverId;
};

class NFMysqlConnectTask : public NFMysqlTask
{
public:
    NFMysqlConnectTask():NFMysqlTask("")
    {
        m_taskName = GET_CLASS_NAME(NFMysqlConnectTask);
        nRconnectTime = 0;
        nRconneCount = 0;
        nPort = 0;
    }

    virtual ~NFMysqlConnectTask()
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
    std::string strIP;
    int nPort;
    std::string strDBName;
    std::string strDBUser;
    std::string strDBPwd;
    int nRconnectTime;
    int nRconneCount;
};

class NFMysqlCheckTask : public NFMysqlTask
{
public:
    NFMysqlCheckTask():NFMysqlTask("")
    {
        m_taskName = GET_CLASS_NAME(NFMysqlCheckTask);
    }

    virtual ~NFMysqlCheckTask()
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

class NFMysqlSelectByCondTask : public NFMysqlTask
{
public:
    NFMysqlSelectByCondTask(const std::string& serverId, const storesvr_sqldata::storesvr_sel& select, const SelectByCond_CB& cb) : NFMysqlTask(serverId)
    {
        m_balanceId = 0;
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFMysqlSelectByCondTask);
    }

    virtual ~NFMysqlSelectByCondTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pMysqlDriver)
        {
            iRet = m_pMysqlDriver->SelectByCond(mSelect, mSelectRes);
        }
        else
        {
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
        for(int i = 0; i < (int)mSelectRes.size(); i++)
        {
            mCB(iRet, *mSelectRes.Mutable(i));
        }

        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_sel mSelect;
    ::google::protobuf::RepeatedPtrField<storesvr_sqldata::storesvr_sel_res> mSelectRes;
    SelectByCond_CB mCB;
    int iRet;
};

class NFMysqlSelectObjTask : public NFMysqlTask
{
public:
    NFMysqlSelectObjTask(const std::string& serverId, const storesvr_sqldata::storesvr_selobj& select, const SelectObj_CB& cb) : NFMysqlTask(serverId)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFMysqlSelectObjTask);
    }

    virtual ~NFMysqlSelectObjTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pMysqlDriver)
        {
            iRet = m_pMysqlDriver->SelectObj(mSelect, mSelectRes);
        }
        else
        {
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
        mCB(iRet, mSelectRes);
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_selobj mSelect;
    storesvr_sqldata::storesvr_selobj_res mSelectRes;
    SelectObj_CB mCB;
    int iRet;
};

class NFMysqlDeleteByCondTask : public NFMysqlTask
{
public:
    NFMysqlDeleteByCondTask(const std::string& serverId, const storesvr_sqldata::storesvr_del& select, const DeleteByCond_CB& cb) : NFMysqlTask(serverId)
    {
        m_balanceId = 0;
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFMysqlDeleteByCondTask) + std::string("_") + select.baseinfo().tbname();
    }

    virtual ~NFMysqlDeleteByCondTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pMysqlDriver)
        {
            iRet = m_pMysqlDriver->DeleteByCond(mSelect, mSelectRes);
        }
        else
        {
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
        mCB(iRet, mSelectRes);
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_del mSelect;
    storesvr_sqldata::storesvr_del_res mSelectRes;
    DeleteByCond_CB mCB;
    int iRet;
};

class NFMysqlDeleteObjTask : public NFMysqlTask
{
public:
    NFMysqlDeleteObjTask(const std::string& serverId, const storesvr_sqldata::storesvr_delobj& select, const DeleteObj_CB& cb) : NFMysqlTask(serverId)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFMysqlDeleteObjTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFMysqlDeleteObjTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pMysqlDriver)
        {
            iRet = m_pMysqlDriver->DeleteObj(mSelect, mSelectRes);
        }
        else
        {
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
        mCB(iRet, mSelectRes);
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_delobj mSelect;
    storesvr_sqldata::storesvr_delobj_res mSelectRes;
    DeleteObj_CB mCB;
    int iRet;
};

class NFMysqlInsertObjTask : public NFMysqlTask
{
public:
    NFMysqlInsertObjTask(const std::string& serverId, const storesvr_sqldata::storesvr_insertobj& select, const InsertObj_CB& cb) : NFMysqlTask(serverId)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFMysqlInsertObjTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFMysqlInsertObjTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pMysqlDriver)
        {
            iRet = m_pMysqlDriver->InsertObj(mSelect, mSelectRes);
        }
        else
        {
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
        mCB(iRet, mSelectRes);
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_insertobj mSelect;
    storesvr_sqldata::storesvr_insertobj_res mSelectRes;
    InsertObj_CB mCB;
    int iRet;
};

class NFMysqlModifyByCondTask : public NFMysqlTask
{
public:
    NFMysqlModifyByCondTask(const std::string& serverId, const storesvr_sqldata::storesvr_mod& select, const ModifyByCond_CB& cb) : NFMysqlTask(serverId)
    {
        m_balanceId = 0;
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFMysqlModifyByCondTask) + std::string("_") + select.baseinfo().tbname();
    }

    virtual ~NFMysqlModifyByCondTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pMysqlDriver)
        {
            iRet = m_pMysqlDriver->ModifyByCond(mSelect, mSelectRes);
        }
        else
        {
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
        mCB(iRet, mSelectRes);
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_mod mSelect;
    storesvr_sqldata::storesvr_mod_res mSelectRes;
    ModifyByCond_CB mCB;
    int iRet;
};

class NFMysqlModifyObjTask : public NFMysqlTask
{
public:
    NFMysqlModifyObjTask(const std::string& serverId, const storesvr_sqldata::storesvr_modobj& select, const ModifyObj_CB& cb) : NFMysqlTask(serverId)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFMysqlModifyObjTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFMysqlModifyObjTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pMysqlDriver)
        {
            iRet = m_pMysqlDriver->ModifyObj(mSelect, mSelectRes);
        }
        else
        {
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
        mCB(iRet, mSelectRes);
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_modobj mSelect;
    storesvr_sqldata::storesvr_modobj_res mSelectRes;
    ModifyObj_CB mCB;
    int iRet;
};

class NFMysqlUpdateByCondTask : public NFMysqlTask
{
public:
    NFMysqlUpdateByCondTask(const std::string& serverId, const storesvr_sqldata::storesvr_update& select, const UpdateByCond_CB& cb) : NFMysqlTask(serverId)
    {
        m_balanceId = 0;
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFMysqlUpdateByCondTask) + std::string("_") + select.baseinfo().tbname();
    }

    virtual ~NFMysqlUpdateByCondTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pMysqlDriver)
        {
            iRet = m_pMysqlDriver->UpdateByCond(mSelect, mSelectRes);
        }
        else
        {
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
        mCB(iRet, mSelectRes);
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_update mSelect;
    storesvr_sqldata::storesvr_update_res mSelectRes;
    UpdateByCond_CB mCB;
    int iRet;
};

class NFMysqlUpdateObjTask : public NFMysqlTask
{
public:
    NFMysqlUpdateObjTask(const std::string& serverId, const storesvr_sqldata::storesvr_updateobj& select, const UpdateObj_CB& cb): NFMysqlTask(serverId)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFMysqlUpdateObjTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFMysqlUpdateObjTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pMysqlDriver)
        {
            iRet = m_pMysqlDriver->UpdateObj(mSelect, mSelectRes);
        }
        else
        {
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
        mCB(iRet, mSelectRes);
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_updateobj mSelect;
    storesvr_sqldata::storesvr_updateobj_res mSelectRes;
    UpdateObj_CB mCB;
    int iRet;
};

class NFMysqlExecuteTask : public NFMysqlTask
{
public:
    NFMysqlExecuteTask(const std::string& serverId, const storesvr_sqldata::storesvr_execute& select, const Execute_CB& cb): NFMysqlTask(serverId)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFMysqlExecuteTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFMysqlExecuteTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pMysqlDriver)
        {
            iRet = m_pMysqlDriver->Execute(mSelect, mSelectRes);
        }
        else
        {
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
        mCB(iRet, mSelectRes);
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_execute mSelect;
    storesvr_sqldata::storesvr_execute_res mSelectRes;
    Execute_CB mCB;
    int iRet;
};

class NFMysqlExecuteMoreTask : public NFMysqlTask
{
public:
    NFMysqlExecuteMoreTask(const std::string& serverId, const storesvr_sqldata::storesvr_execute_more& select, const ExecuteMore_CB& cb) : NFMysqlTask(serverId)
    {
        m_balanceId = 0;
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFMysqlExecuteMoreTask);
    }

    virtual ~NFMysqlExecuteMoreTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pMysqlDriver)
        {
            iRet = m_pMysqlDriver->ExecuteMore(mSelect, mSelectRes);
        }
        else
        {
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
        for(int i = 0; i < (int)mSelectRes.size(); i++)
        {
            mCB(iRet, *mSelectRes.Mutable(i));
        }

        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_execute_more mSelect;
    ::google::protobuf::RepeatedPtrField<storesvr_sqldata::storesvr_execute_more_res> mSelectRes;
    ExecuteMore_CB mCB;
    int iRet;
};

class NFMysqlTaskComponent : public NFITaskComponent
{
public:
    NFMysqlTaskComponent(NFCAsyMysqlModule* pAsyMysqlModule)
    {
        m_pAsyMysqlModule = pAsyMysqlModule;
        m_pMysqlDriverManager = NF_NEW NFCMysqlDriverManager();
    }

    virtual ~NFMysqlTaskComponent()
    {
        NF_SAFE_DELETE(m_pMysqlDriverManager);
    }


    void ProcessTaskStart(NFTask* pTask) override
    {
        NFMysqlTask* pMysqlTask = dynamic_cast<NFMysqlTask*>(pTask);
        if (pMysqlTask)
        {
            if (pMysqlTask->IsConnect())
            {
                NFMysqlConnectTask* pConnectTask = dynamic_cast<NFMysqlConnectTask*>(pTask);
                if (pConnectTask == NULL) return;
                int iRet = m_pMysqlDriverManager->AddMysqlServer(pConnectTask->nServerID, pConnectTask->strIP, pConnectTask->nPort, pConnectTask->strDBName, pConnectTask->strDBUser,
                                                                 pConnectTask->strDBPwd, pConnectTask->nRconnectTime, pConnectTask->nRconneCount);
                if (iRet != 0)
                {
                    NFSLEEP(1000);
                    exit(0);
                }
            }
            else if (pMysqlTask->IsCheck())
            {
                m_pMysqlDriverManager->CheckMysql();
            }
            else
            {
                m_pMysqlDriverManager->CheckMysql();
                pMysqlTask->m_pMysqlDriver = m_pMysqlDriverManager->GetMysqlDriver(pMysqlTask->m_serverId);
                CHECK_EXPR(pMysqlTask->m_pMysqlDriver, , "GetMysqlDriver:{} Failed", pMysqlTask->m_serverId);
            }
        }
    }

    void ProcessTask(NFTask* pTask) override
    {
        if (pTask)
        {
            pTask->ThreadProcess();
        }
    }

    void ProcessTaskEnd(NFTask* pTask) override
    {
        NFMysqlTask* pMysqlTask = dynamic_cast<NFMysqlTask*>(pTask);
        if (pMysqlTask)
        {
            pMysqlTask->m_pMysqlDriver = nullptr;
        }
    }

    virtual void HandleTaskTimeOut(const std::string& taskName, uint64_t useTime) override
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "taskName:{} timeOut, userTime:{}", taskName, useTime);
    }
public:
    NFCMysqlDriverManager* m_pMysqlDriverManager;
    NFCAsyMysqlModule* m_pAsyMysqlModule;
};


NFCAsyMysqlModule::NFCAsyMysqlModule(NFIPluginManager* p):NFIAsyMysqlModule(p)
{
    mnLastCheckTime = NFGetTime();
    m_initComponet = false;
}

NFCAsyMysqlModule::~NFCAsyMysqlModule()
{
}

bool NFCAsyMysqlModule::InitActorPool(int maxTaskGroup, int maxActorNum)
{
    NFIAsycModule::InitActorPool(maxTaskGroup, maxActorNum);
    if (!m_initComponet)
    {
        m_initComponet = true;
        for (size_t i = 0; i < m_vecActorGroupPool.size(); i++)
        {
            for(size_t j = 0; j < m_vecActorGroupPool[i].size(); j++)
            {
                NFMysqlTaskComponent* pComonnet = NF_NEW NFMysqlTaskComponent(this);
                AddActorComponent(i, m_vecActorGroupPool[i][j], pComonnet);
            }
        }
    }

    return true;
}

int NFCAsyMysqlModule::AddMysqlServer(const std::string& nServerID, const std::string &strIP, int nPort, std::string strDBName,
                                      std::string strDBUser, std::string strDBPwd, int nRconnectTime,
                                      int nRconneCount)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    InitActorPool(NF_TASK_MAX_GROUP_DEFAULT);

    for (size_t i = 0; i < m_vecActorGroupPool.size(); i++)
    {
        for(size_t j = 0; j < m_vecActorGroupPool[i].size(); j++)
        {
            NFMysqlConnectTask* pTask = NF_NEW NFMysqlConnectTask();
            pTask->nServerID = nServerID;
            pTask->strIP = strIP;
            pTask->nPort = nPort;
            pTask->strDBName = strDBName;
            pTask->strDBUser = strDBUser;
            pTask->strDBPwd = strDBPwd;
            pTask->nRconnectTime = nRconnectTime;
            pTask->nRconneCount = nRconneCount;
            int iRet = FindModule<NFITaskModule>()->AddTask(i, m_vecActorGroupPool[i][j], pTask);
            CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
        }
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyMysqlModule::SelectByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_sel &select, bool useCache,
                                    const SelectByCond_CB& cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFMysqlSelectByCondTask* pTask = NF_NEW NFMysqlSelectByCondTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}


int NFCAsyMysqlModule::SelectObj(const std::string& nServerID, const storesvr_sqldata::storesvr_selobj &select, bool useCache,
                                 const SelectObj_CB& cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFMysqlSelectObjTask* pTask = NF_NEW NFMysqlSelectObjTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}


int NFCAsyMysqlModule::DeleteByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_del &select, bool useCache,
                                    const DeleteByCond_CB& cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFMysqlDeleteByCondTask* pTask = NF_NEW NFMysqlDeleteByCondTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}


int NFCAsyMysqlModule::DeleteObj(const std::string& nServerID, const storesvr_sqldata::storesvr_delobj &select, bool useCache,
                                 const DeleteObj_CB& cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFMysqlDeleteObjTask* pTask = NF_NEW NFMysqlDeleteObjTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}


int NFCAsyMysqlModule::InsertObj(const std::string& nServerID, const storesvr_sqldata::storesvr_insertobj &select, bool useCache,
                                 const InsertObj_CB& cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFMysqlInsertObjTask* pTask = NF_NEW NFMysqlInsertObjTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyMysqlModule::ModifyByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_mod &select, bool useCache,
                                    const ModifyByCond_CB& cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFMysqlModifyByCondTask* pTask = NF_NEW NFMysqlModifyByCondTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyMysqlModule::ModifyObj(const std::string& nServerID, const storesvr_sqldata::storesvr_modobj &select, bool useCache,
                                 const ModifyObj_CB& cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFMysqlModifyObjTask* pTask = NF_NEW NFMysqlModifyObjTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyMysqlModule::UpdateByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_update &select, bool useCache,
                                    const UpdateByCond_CB& cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFMysqlUpdateByCondTask* pTask = NF_NEW NFMysqlUpdateByCondTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyMysqlModule::UpdateObj(const std::string& nServerID, const storesvr_sqldata::storesvr_updateobj &select, bool useCache,
                                 const UpdateObj_CB& cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFMysqlUpdateObjTask* pTask = NF_NEW NFMysqlUpdateObjTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyMysqlModule::Execute(const std::string& nServerID, const storesvr_sqldata::storesvr_execute &select,
                               const Execute_CB& cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFMysqlExecuteTask* pTask = NF_NEW NFMysqlExecuteTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyMysqlModule::ExecuteMore(const std::string& nServerID, const storesvr_sqldata::storesvr_execute_more &select,
                                   const ExecuteMore_CB& cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFMysqlExecuteMoreTask* pTask = NF_NEW NFMysqlExecuteMoreTask(nServerID, select, cb);
    int iRet = AddTask(NF_TASK_GROUP_DEFAULT, pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

bool NFCAsyMysqlModule::Execute()
{
    if (!m_initComponet) return true;
    if (NFGetTime() - mnLastCheckTime < 10000) return true;

    mnLastCheckTime = NFGetTime();

    for(int i = 0; i < (int)m_vecActorGroupPool.size(); i++)
    {
        for(int j = 0; j < (int)m_vecActorGroupPool[i].size(); j++)
        {
            NFMysqlCheckTask* pTask = NF_NEW NFMysqlCheckTask();
            FindModule<NFITaskModule>()->AddTask(i, m_vecActorGroupPool[i][j], pTask);
        }
    }

    return true;
}
