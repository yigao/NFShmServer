// -------------------------------------------------------------------------
//    @FileName         :    NFCAsyMysqlModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Module           :    NFCAsyMysqlModule
//
// -------------------------------------------------------------------------

#include "NFCAsyDBModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFTask.h"
#include "NFComm/NFPluginModule/NFITaskComponent.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFINoSqlModule.h"
#include "NFCNoSqlDriverManager.h"

class NFDBTask : public NFTask
{
public:
    NFDBTask(const std::string &serverId, bool useCache = false) : m_serverId(serverId)
    {
        m_pMysqlDriver = nullptr;
        m_pNosqlDriver = nullptr;
        m_taskName = GET_CLASS_NAME(NFDBTask);
        m_useCache = useCache;
    }

    virtual ~NFDBTask()
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
    NFCMysqlDriver *m_pMysqlDriver;
    NFIRedisDriver *m_pNosqlDriver;
    std::string m_serverId;
    bool m_useCache;
};

class NFDBConnectTask : public NFDBTask
{
public:
    NFDBConnectTask() : NFDBTask("")
    {
        m_taskName = GET_CLASS_NAME(NFDBConnectTask);
        nRconnectTime = 0;
        nRconneCount = 0;
        nPort = 0;
        nNosqlPort = 0;
    }

    virtual ~NFDBConnectTask()
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
public:
    std::string nNosqlIp;
    int nNosqlPort;
    std::string nNosqlPass;
};

class NFDBCheckTask : public NFDBTask
{
public:
    NFDBCheckTask() : NFDBTask("")
    {
        m_taskName = GET_CLASS_NAME(NFDBCheckTask);
    }

    virtual ~NFDBCheckTask()
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

class NFQueryDescStoreTask : public NFDBTask
{
public:
    NFQueryDescStoreTask(const std::string &serverId, const std::string &tableName, const google::protobuf::Message *pSheetMessageObject,
                         const QueryDescStore_CB &cb) : NFDBTask(serverId)
    {
        m_balanceId = 0;
        m_tableName = tableName;
        iRet = 0;
        mCB = cb;
        m_pSheetMessageObject = pSheetMessageObject->New();
        m_taskName = GET_CLASS_NAME(NFQueryDescStoreTask);
    }

    virtual ~NFQueryDescStoreTask()
    {
        if (m_pSheetMessageObject)
        {
            NF_SAFE_DELETE(m_pSheetMessageObject);
        }
    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_pMysqlDriver)
        {
            iRet = m_pMysqlDriver->QueryDescStore(m_tableName, m_pSheetMessageObject);
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
        mCB(iRet, *m_pSheetMessageObject);
        return TPTASK_STATE_COMPLETED;
    }

public:
    google::protobuf::Message *m_pSheetMessageObject;
    std::string m_tableName;
    int iRet;
    QueryDescStore_CB mCB;
};

class NFSelectByCondTask : public NFDBTask
{
public:
    NFSelectByCondTask(const std::string &serverId, const storesvr_sqldata::storesvr_sel &select, const SelectByCond_CB &cb) : NFDBTask(serverId)
    {
        m_balanceId = 0;
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFSelectByCondTask);
    }

    virtual ~NFSelectByCondTask()
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
        for (int i = 0; i < (int) mSelectRes.size(); i++)
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

class NFSelectObjTask : public NFDBTask
{
public:
    NFSelectObjTask(const std::string &serverId, const storesvr_sqldata::storesvr_selobj &select, const SelectObj_CB &cb, bool useCache) : NFDBTask(serverId, useCache)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFSelectObjTask);
    }

    virtual ~NFSelectObjTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_useCache)
        {
            if (m_pNosqlDriver)
            {
                iRet = m_pNosqlDriver->SelectObj(mSelect, mSelectRes);
                if (iRet <= 0)
                {
                    return true;
                }
            }
            else {
                iRet = -1;
                return true;
            }
        }

        if (m_pMysqlDriver)
        {
            iRet = m_pMysqlDriver->SelectObj(mSelect, mSelectRes);
        }
        else
        {
            iRet = -1;
        }

        if (iRet == 0 && m_useCache && m_pNosqlDriver)
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
        mCB(iRet, mSelectRes);
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_selobj mSelect;
    storesvr_sqldata::storesvr_selobj_res mSelectRes;
    SelectObj_CB mCB;
    int iRet;
};

class NFDeleteByCondTask : public NFDBTask
{
public:
    NFDeleteByCondTask(const std::string &serverId, const storesvr_sqldata::storesvr_del &select, const DeleteByCond_CB &cb) : NFDBTask(serverId)
    {
        m_balanceId = 0;
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFDeleteByCondTask) + std::string("_") + select.baseinfo().tbname();
    }

    virtual ~NFDeleteByCondTask()
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

class NFDeleteObjTask : public NFDBTask
{
public:
    NFDeleteObjTask(const std::string &serverId, const storesvr_sqldata::storesvr_delobj &select, const DeleteObj_CB &cb, bool useCache) : NFDBTask(serverId, useCache)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFDeleteObjTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFDeleteObjTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_useCache && m_pNosqlDriver)
        {
            m_pNosqlDriver->DeleteObj(mSelect);
        }

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

class NFInsertObjTask : public NFDBTask
{
public:
    NFInsertObjTask(const std::string &serverId, const storesvr_sqldata::storesvr_insertobj &select, const InsertObj_CB &cb, bool useCache) : NFDBTask(serverId, useCache)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFInsertObjTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFInsertObjTask()
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

        if (iRet == 0 && m_useCache && m_pNosqlDriver)
        {
            iRet = m_pNosqlDriver->SaveObj(mSelect);
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

class NFModifyByCondTask : public NFDBTask
{
public:
    NFModifyByCondTask(const std::string &serverId, const storesvr_sqldata::storesvr_mod &select, const ModifyByCond_CB &cb) : NFDBTask(serverId)
    {
        m_balanceId = 0;
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFModifyByCondTask) + std::string("_") + select.baseinfo().tbname();
    }

    virtual ~NFModifyByCondTask()
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

class NFModifyObjTask : public NFDBTask
{
public:
    NFModifyObjTask(const std::string &serverId, const storesvr_sqldata::storesvr_modobj &select, const ModifyObj_CB &cb, bool useCache) : NFDBTask(serverId, useCache)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFModifyObjTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFModifyObjTask()
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

        if (iRet == 0 && m_useCache && m_pNosqlDriver)
        {
            iRet = m_pNosqlDriver->SaveObj(mSelect);
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

class NFUpdateByCondTask : public NFDBTask
{
public:
    NFUpdateByCondTask(const std::string &serverId, const storesvr_sqldata::storesvr_update &select, const UpdateByCond_CB &cb) : NFDBTask(
            serverId)
    {
        m_balanceId = 0;
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFUpdateByCondTask) + std::string("_") + select.baseinfo().tbname();
    }

    virtual ~NFUpdateByCondTask()
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

class NFUpdateObjTask : public NFDBTask
{
public:
    NFUpdateObjTask(const std::string &serverId, const storesvr_sqldata::storesvr_updateobj &select, const UpdateObj_CB &cb, bool useCache) : NFDBTask(serverId, useCache)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFUpdateObjTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFUpdateObjTask()
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

        if (iRet == 0 && m_useCache && m_pNosqlDriver)
        {
            iRet = m_pNosqlDriver->SaveObj(mSelect);
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

class NFExecuteTask : public NFDBTask
{
public:
    NFExecuteTask(const std::string &serverId, const storesvr_sqldata::storesvr_execute &select, const Execute_CB &cb) : NFDBTask(serverId)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFExecuteTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFExecuteTask()
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

class NFExecuteMoreTask : public NFDBTask
{
public:
    NFExecuteMoreTask(const std::string &serverId, const storesvr_sqldata::storesvr_execute_more &select, const ExecuteMore_CB &cb) : NFDBTask(
            serverId)
    {
        m_balanceId = 0;
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFExecuteMoreTask);
    }

    virtual ~NFExecuteMoreTask()
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
        for (int i = 0; i < (int) mSelectRes.size(); i++)
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

class NFDBTaskComponent : public NFITaskComponent
{
public:
    NFDBTaskComponent()
    {
        m_pMysqlDriverManager = NF_NEW NFCMysqlDriverManager();
        m_pNoSqlDriverManager = NF_NEW NFCNoSqlDriverManager();
    }

    virtual ~NFDBTaskComponent()
    {
        NF_SAFE_DELETE(m_pMysqlDriverManager);
        NF_SAFE_DELETE(m_pNoSqlDriverManager);
    }


    void ProcessTaskStart(NFTask *pTask) override
    {
        NFDBTask *pMysqlTask = dynamic_cast<NFDBTask *>(pTask);
        if (pMysqlTask)
        {
            if (pMysqlTask->IsConnect())
            {
                NFDBConnectTask *pConnectTask = dynamic_cast<NFDBConnectTask *>(pTask);
                if (pConnectTask == NULL) return;
                int iRet = m_pMysqlDriverManager->AddMysqlServer(pConnectTask->nServerID, pConnectTask->strIP, pConnectTask->nPort,
                                                                 pConnectTask->strDBName, pConnectTask->strDBUser,
                                                                 pConnectTask->strDBPwd, pConnectTask->nRconnectTime, pConnectTask->nRconneCount);
                if (iRet != 0)
                {
                    NFSLEEP(1000);
                    exit(0);
                }

                iRet = m_pNoSqlDriverManager->AddNoSqlServer(pConnectTask->nServerID, pConnectTask->nNosqlIp, pConnectTask->nNosqlPort,
                                                             pConnectTask->nNosqlPass);
                if (iRet != 0)
                {
                    NFSLEEP(1000);
                    exit(0);
                }
            }
            else if (pMysqlTask->IsCheck())
            {
                m_pMysqlDriverManager->CheckMysql();
                m_pNoSqlDriverManager->CheckNoSql();
            }
            else
            {
                m_pMysqlDriverManager->CheckMysql();
                m_pNoSqlDriverManager->CheckNoSql();
                pMysqlTask->m_pMysqlDriver = m_pMysqlDriverManager->GetMysqlDriver(pMysqlTask->m_serverId);
                CHECK_EXPR(pMysqlTask->m_pMysqlDriver, , "GetMysqlDriver:{} Failed", pMysqlTask->m_serverId);
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
        NFDBTask *pMysqlTask = dynamic_cast<NFDBTask *>(pTask);
        if (pMysqlTask)
        {
            pMysqlTask->m_pMysqlDriver = nullptr;
            pMysqlTask->m_pNosqlDriver = nullptr;
        }
    }

    virtual void HandleTaskTimeOut(const std::string &taskName, uint64_t useTime) override
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "taskName:{} timeOut, userTime:{}", taskName, useTime);
    }

public:
    NFCMysqlDriverManager *m_pMysqlDriverManager;
    NFCNoSqlDriverManager *m_pNoSqlDriverManager;
};


NFCAsyDBModule::NFCAsyDBModule(NFIPluginManager *p) : NFIAsyDBModule(p)
{
    mnLastCheckTime = NFGetTime();
    m_initComponet = false;
}

NFCAsyDBModule::~NFCAsyDBModule()
{
}

bool NFCAsyDBModule::InitActorPool(int maxActorNum)
{
    NFIAsycModule::InitActorPool(maxActorNum);
    if (!m_initComponet)
    {
        m_initComponet = true;
        for (size_t i = 0; i < m_vecActorPool.size(); i++)
        {
            NFDBTaskComponent *pComonnet = NF_NEW NFDBTaskComponent();
            AddActorComponent(m_vecActorPool[i], pComonnet);
        }
    }

    return true;
}

int NFCAsyDBModule::AddDBServer(const std::string &nServerID, const std::string &strIP, int nPort, std::string strDBName,
                                std::string strDBUser, std::string strDBPwd, const std::string &noSqlIp, int nosqlPort,
                                const std::string &noSqlPass, int nRconnectTime,
                                int nRconneCount)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    InitActorPool(FindModule<NFITaskModule>()->GetMaxThreads() * 2);

    for (size_t i = 0; i < m_vecActorPool.size(); i++)
    {
        NFDBConnectTask *pTask = NF_NEW NFDBConnectTask();
        pTask->nServerID = nServerID;
        pTask->strIP = strIP;
        pTask->nPort = nPort;
        pTask->strDBName = strDBName;
        pTask->strDBUser = strDBUser;
        pTask->strDBPwd = strDBPwd;
        pTask->nRconnectTime = nRconnectTime;
        pTask->nRconneCount = nRconneCount;
        pTask->nNosqlIp = noSqlIp;
        pTask->nNosqlPort = nosqlPort;
        pTask->nNosqlPass = noSqlPass;
        int iRet = FindModule<NFITaskModule>()->AddTask(m_vecActorPool[i], pTask);
        CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyDBModule::QueryDescStore(const std::string &serverID, const std::string &table, const google::protobuf::Message *pSheetMessageObject,
                                      const QueryDescStore_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFQueryDescStoreTask *pTask = NF_NEW NFQueryDescStoreTask(serverID, table, pSheetMessageObject, cb);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyDBModule::SelectByCond(const std::string &nServerID, const storesvr_sqldata::storesvr_sel &select,
                                    const SelectByCond_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFSelectByCondTask *pTask = NF_NEW NFSelectByCondTask(nServerID, select, cb);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}


int NFCAsyDBModule::SelectObj(const std::string &nServerID, const storesvr_sqldata::storesvr_selobj &select, bool useCache,
                                 const SelectObj_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFSelectObjTask *pTask = NF_NEW NFSelectObjTask(nServerID, select, cb, useCache);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}


int NFCAsyDBModule::DeleteByCond(const std::string &nServerID, const storesvr_sqldata::storesvr_del &select,
                                    const DeleteByCond_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFDeleteByCondTask *pTask = NF_NEW NFDeleteByCondTask(nServerID, select, cb);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}


int NFCAsyDBModule::DeleteObj(const std::string &nServerID, const storesvr_sqldata::storesvr_delobj &select, bool useCache,
                                 const DeleteObj_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFDeleteObjTask *pTask = NF_NEW NFDeleteObjTask(nServerID, select, cb, useCache);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}


int NFCAsyDBModule::InsertObj(const std::string &nServerID, const storesvr_sqldata::storesvr_insertobj &select, bool useCache,
                                 const InsertObj_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFInsertObjTask *pTask = NF_NEW NFInsertObjTask(nServerID, select, cb, useCache);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyDBModule::ModifyByCond(const std::string &nServerID, const storesvr_sqldata::storesvr_mod &select,
                                    const ModifyByCond_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFModifyByCondTask *pTask = NF_NEW NFModifyByCondTask(nServerID, select, cb);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyDBModule::ModifyObj(const std::string &nServerID, const storesvr_sqldata::storesvr_modobj &select, bool useCache,
                                 const ModifyObj_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFModifyObjTask *pTask = NF_NEW NFModifyObjTask(nServerID, select, cb, useCache);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyDBModule::UpdateByCond(const std::string &nServerID, const storesvr_sqldata::storesvr_update &select,
                                    const UpdateByCond_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFUpdateByCondTask *pTask = NF_NEW NFUpdateByCondTask(nServerID, select, cb);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyDBModule::UpdateObj(const std::string &nServerID, const storesvr_sqldata::storesvr_updateobj &select, bool useCache,
                                 const UpdateObj_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFUpdateObjTask *pTask = NF_NEW NFUpdateObjTask(nServerID, select, cb, useCache);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyDBModule::Execute(const std::string &nServerID, const storesvr_sqldata::storesvr_execute &select,
                               const Execute_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFExecuteTask *pTask = NF_NEW NFExecuteTask(nServerID, select, cb);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyDBModule::ExecuteMore(const std::string &nServerID, const storesvr_sqldata::storesvr_execute_more &select,
                                   const ExecuteMore_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFExecuteMoreTask *pTask = NF_NEW NFExecuteMoreTask(nServerID, select, cb);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

bool NFCAsyDBModule::Execute()
{
    if (!m_initComponet) return true;
    if (NFGetTime() - mnLastCheckTime < 10000) return true;

    mnLastCheckTime = NFGetTime();

    for (int i = 0; i < (int) m_vecActorPool.size(); i++)
    {
        NFDBCheckTask *pTask = NF_NEW NFDBCheckTask();
        FindModule<NFITaskModule>()->AddTask(m_vecActorPool[i], pTask);
    }

    return true;
}
