// -------------------------------------------------------------------------
//    @FileName         :    NFCAsyMysqlModule.h
//    @Author           :    Gao.Yi
//    @Date             :   xxxx-xx-xx
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

class NFQueryDescStoreTask : public NFMysqlTask
{
public:
	NFQueryDescStoreTask(const std::string& serverId, const std::string& tableName, const google::protobuf::Message *pSheetMessageObject, const QueryDescStore_CB& cb) :NFMysqlTask(serverId)
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

class NFSelectByCondTask : public NFMysqlTask
{
public:
	NFSelectByCondTask(const std::string& serverId, const storesvr_sqldata::storesvr_sel& select, const SelectByCond_CB& cb) :NFMysqlTask(serverId)
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

class NFSelectObjTask : public NFMysqlTask
{
public:
	NFSelectObjTask(const std::string& serverId, const storesvr_sqldata::storesvr_selobj& select, const SelectObj_CB& cb) :NFMysqlTask(serverId)
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

class NFDeleteByCondTask : public NFMysqlTask
{
public:
	NFDeleteByCondTask(const std::string& serverId, const storesvr_sqldata::storesvr_del& select, const DeleteByCond_CB& cb) :NFMysqlTask(serverId)
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

class NFDeleteObjTask : public NFMysqlTask
{
public:
	NFDeleteObjTask(const std::string& serverId, const storesvr_sqldata::storesvr_delobj& select, const DeleteObj_CB& cb) :NFMysqlTask(serverId)
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

class NFInsertObjTask : public NFMysqlTask
{
public:
	NFInsertObjTask(const std::string& serverId, const storesvr_sqldata::storesvr_ins& select, const InsertObj_CB& cb) :NFMysqlTask(serverId)
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
	storesvr_sqldata::storesvr_ins mSelect;
	storesvr_sqldata::storesvr_ins_res mSelectRes;
	InsertObj_CB mCB;
    int iRet;
};

class NFModifyByCondTask : public NFMysqlTask
{
public:
    NFModifyByCondTask(const std::string& serverId, const storesvr_sqldata::storesvr_mod& select, const ModifyByCond_CB& cb) :NFMysqlTask(serverId)
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

class NFModifyObjTask : public NFMysqlTask
{
public:
	NFModifyObjTask(const std::string& serverId, const storesvr_sqldata::storesvr_modobj& select, const ModifyObj_CB& cb) : NFMysqlTask(serverId)
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

class NFUpdateByCondTask : public NFMysqlTask
{
public:
    NFUpdateByCondTask(const std::string& serverId, const storesvr_sqldata::storesvr_modins& select, const UpdateByCond_CB& cb) :NFMysqlTask(serverId)
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
    storesvr_sqldata::storesvr_modins mSelect;
    storesvr_sqldata::storesvr_modins_res mSelectRes;
    UpdateByCond_CB mCB;
    int iRet;
};

class NFUpdateObjTask : public NFMysqlTask
{
public:
	NFUpdateObjTask(const std::string& serverId, const storesvr_sqldata::storesvr_modinsobj& select, const UpdateObj_CB& cb): NFMysqlTask(serverId)
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
	storesvr_sqldata::storesvr_modinsobj mSelect;
	storesvr_sqldata::storesvr_modinsobj_res mSelectRes;
	UpdateObj_CB mCB;
    int iRet;
};

class NFExecuteTask : public NFMysqlTask
{
public:
    NFExecuteTask(const std::string& serverId, const storesvr_sqldata::storesvr_execute& select, const Execute_CB& cb):NFMysqlTask(serverId)
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

bool NFCAsyMysqlModule::InitActorPool(int maxActorNum)
{
	NFIAsycModule::InitActorPool(maxActorNum);
	if (!m_initComponet)
	{
		m_initComponet = true;
		for (size_t i = 0; i < m_vecActorPool.size(); i++)
		{
			NFMysqlTaskComponent* pComonnet = NF_NEW NFMysqlTaskComponent(this);
			AddActorComponent(m_vecActorPool[i], pComonnet);
		}
	}

	return true;
}

int NFCAsyMysqlModule::AddMysqlServer(const std::string& nServerID, const std::string &strIP, int nPort, std::string strDBName,
	std::string strDBUser, std::string strDBPwd, int nRconnectTime,
	int nRconneCount)
{
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
	InitActorPool(FindModule<NFITaskModule>()->GetMaxThreads()*2);

	for (size_t i = 0; i < m_vecActorPool.size(); i++)
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
        int iRet = FindModule<NFITaskModule>()->AddTask(m_vecActorPool[i], pTask);
        CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
	}

	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCAsyMysqlModule::QueryDescStore(const std::string& serverID, const std::string &table, const google::protobuf::Message *pSheetMessageObject, const QueryDescStore_CB& cb)
{
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
	NFQueryDescStoreTask* pTask = NF_NEW NFQueryDescStoreTask(serverID, table, pSheetMessageObject, cb);
	int iRet = AddTask(pTask);
	CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCAsyMysqlModule::SelectByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_sel &select,
	const SelectByCond_CB& cb)
{
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
	NFSelectByCondTask* pTask = NF_NEW NFSelectByCondTask(nServerID, select, cb);
	int iRet = AddTask(pTask);
	CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
	return 0;
}


int NFCAsyMysqlModule::SelectObj(const std::string& nServerID, const storesvr_sqldata::storesvr_selobj &select,
	const SelectObj_CB& cb)
{
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
	NFSelectObjTask* pTask = NF_NEW NFSelectObjTask(nServerID, select, cb);
	int iRet = AddTask(pTask);
	CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
	return 0;
}


int NFCAsyMysqlModule::DeleteByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_del &select,
	const DeleteByCond_CB& cb)
{
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
	NFDeleteByCondTask* pTask = NF_NEW NFDeleteByCondTask(nServerID, select, cb);
	int iRet = AddTask(pTask);
	CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
	return 0;
}


int NFCAsyMysqlModule::DeleteObj(const std::string& nServerID, const storesvr_sqldata::storesvr_delobj &select,
	const DeleteObj_CB& cb)
{
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
	NFDeleteObjTask* pTask = NF_NEW NFDeleteObjTask(nServerID, select, cb);
	int iRet = AddTask(pTask);
	CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
	return 0;
}


int NFCAsyMysqlModule::InsertObj(const std::string& nServerID, const storesvr_sqldata::storesvr_ins &select,
	const InsertObj_CB& cb)
{
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
	NFInsertObjTask* pTask = NF_NEW NFInsertObjTask(nServerID, select, cb);
	int iRet = AddTask(pTask);
	CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCAsyMysqlModule::ModifyByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_mod &select,
                                 const ModifyByCond_CB& cb)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    NFModifyByCondTask* pTask = NF_NEW NFModifyByCondTask(nServerID, select, cb);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCAsyMysqlModule::ModifyObj(const std::string& nServerID, const storesvr_sqldata::storesvr_modobj &select,
		const ModifyObj_CB& cb)
{
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
	NFModifyObjTask* pTask = NF_NEW NFModifyObjTask(nServerID, select, cb);
	int iRet = AddTask(pTask);
	CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCAsyMysqlModule::UpdateByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_modins &select,
                                 const UpdateByCond_CB& cb)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    NFUpdateByCondTask* pTask = NF_NEW NFUpdateByCondTask(nServerID, select, cb);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCAsyMysqlModule::UpdateObj(const std::string& nServerID, const storesvr_sqldata::storesvr_modinsobj &select,
		const UpdateObj_CB& cb)
{
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
	NFUpdateObjTask* pTask = NF_NEW NFUpdateObjTask(nServerID, select, cb);
	int iRet = AddTask(pTask);
	CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
	NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
	return 0;
}

int NFCAsyMysqlModule::Execute(const std::string& nServerID, const storesvr_sqldata::storesvr_execute &select,
            const Execute_CB& cb)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    NFExecuteTask* pTask = NF_NEW NFExecuteTask(nServerID, select, cb);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

bool NFCAsyMysqlModule::Execute()
{
    if (!m_initComponet) return true;
    if (NFGetTime() - mnLastCheckTime < 10000) return true;

    mnLastCheckTime = NFGetTime();

    for(int i = 0; i < (int)m_vecActorPool.size(); i++)
    {
        NFMysqlCheckTask* pTask = NF_NEW NFMysqlCheckTask();
        FindModule<NFITaskModule>()->AddTask(m_vecActorPool[i], pTask);
    }

    return true;
}
