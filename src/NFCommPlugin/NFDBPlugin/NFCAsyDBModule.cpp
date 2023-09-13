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
#include "NFComm/NFPluginModule/NFINosqlModule.h"
#include "NFCNosqlDriverManager.h"

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
    NFINosqlDriver *m_pNosqlDriver;
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

class NFDBQueryDescStoreTask : public NFDBTask
{
public:
    NFDBQueryDescStoreTask(const std::string &serverId, const std::string &tableName, const google::protobuf::Message *pSheetMessageObject,
                           const QueryDescStore_CB &cb) : NFDBTask(serverId)
    {
        m_balanceId = 0;
        m_tableName = tableName;
        iRet = 0;
        mCB = cb;
        m_pSheetMessageObject = pSheetMessageObject->New();
        m_taskName = GET_CLASS_NAME(NFDBQueryDescStoreTask);
    }

    virtual ~NFDBQueryDescStoreTask()
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
        if (mCB)
        {
            mCB(iRet, *m_pSheetMessageObject);
        }
        return TPTASK_STATE_COMPLETED;
    }

public:
    google::protobuf::Message *m_pSheetMessageObject;
    std::string m_tableName;
    int iRet;
    QueryDescStore_CB mCB;
};

class NFDBSelectByCondTask : public NFDBTask
{
public:
    NFDBSelectByCondTask(const std::string &serverId, const storesvr_sqldata::storesvr_sel &select, const SelectByCond_CB &cb, bool useCache) : NFDBTask(serverId, useCache)
    {
        m_balanceId = 0;
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFDBSelectByCondTask);
    }

    virtual ~NFDBSelectByCondTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        do {
            if (m_useCache)
            {
                if (m_pNosqlDriver && m_pMysqlDriver)
                {
                    std::string privateKey;
                    std::unordered_set<std::string> privateKeySet;
                    iRet = m_pMysqlDriver->SelectByCond(mSelect, privateKey, privateKeySet);
                    if (iRet != 0)
                    {
                        break;
                    }

                    std::unordered_set<std::string> leftPrivateKeySet;
                    iRet = m_pNosqlDriver->SelectByCond(mSelect, privateKey, privateKeySet, leftPrivateKeySet, mSelectRes);
                    if (iRet != 0)
                    {
                        break;
                    }

                    std::vector<std::string> records;
                    iRet = m_pMysqlDriver->SelectByCond(mSelect, privateKey, leftPrivateKeySet, mSelectRes, records);
                    if (iRet != 0)
                    {
                        break;
                    }

                    iRet = m_pNosqlDriver->SaveObj(mSelect.baseinfo().package_name(), mSelect.baseinfo().tbname(), mSelect.baseinfo().clname(), records);
                    if (iRet == 0)
                    {
                        return true;
                    }
                }
                else {
                    iRet = -1;
                    return true;
                }
            }
        } while(false);

        if (m_pMysqlDriver)
        {
            mSelectRes.Clear();
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
            if (mCB)
            {
                mCB(iRet, *mSelectRes.Mutable(i));
            }
        }

        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_sel mSelect;
    ::google::protobuf::RepeatedPtrField<storesvr_sqldata::storesvr_sel_res> mSelectRes;
    SelectByCond_CB mCB;
    int iRet;
};

class NFDBSelectObjTask : public NFDBTask
{
public:
    NFDBSelectObjTask(const std::string &serverId, const storesvr_sqldata::storesvr_selobj &select, const SelectObj_CB &cb, bool useCache) : NFDBTask(serverId, useCache)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFDBSelectObjTask);
    }

    virtual ~NFDBSelectObjTask()
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

class NFDBDeleteByCondTask : public NFDBTask
{
public:
    NFDBDeleteByCondTask(const std::string &serverId, const storesvr_sqldata::storesvr_del &select, const DeleteByCond_CB &cb, bool useCache) : NFDBTask(serverId, useCache)
    {
        m_balanceId = 0;
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFDBDeleteByCondTask) + std::string("_") + select.baseinfo().tbname();
    }

    virtual ~NFDBDeleteByCondTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_useCache)
        {
            if (m_pNosqlDriver && m_pMysqlDriver)
            {
                std::string privateKey;
                std::unordered_set<std::string> privateKeySet;
                iRet = m_pMysqlDriver->DeleteByCond(mSelect, privateKey, privateKeySet);
                if (iRet != 0)
                {
                    return true;
                }

                iRet = m_pNosqlDriver->DeleteByCond(mSelect, privateKey, privateKeySet, mSelectRes);
                if (iRet <= 0)
                {
                    return true;
                }

                iRet = m_pMysqlDriver->DeleteByCond(mSelect, privateKey, privateKeySet, mSelectRes);
                if (iRet != 0)
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
        if (mCB)
        {
            mCB(iRet, mSelectRes);
        }
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_del mSelect;
    storesvr_sqldata::storesvr_del_res mSelectRes;
    DeleteByCond_CB mCB;
    int iRet;
};

class NFDBDeleteObjTask : public NFDBTask
{
public:
    NFDBDeleteObjTask(const std::string &serverId, const storesvr_sqldata::storesvr_delobj &select, const DeleteObj_CB &cb, bool useCache) : NFDBTask(serverId, useCache)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFDBDeleteObjTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFDBDeleteObjTask()
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

class NFDBInsertObjTask : public NFDBTask
{
public:
    NFDBInsertObjTask(const std::string &serverId, const storesvr_sqldata::storesvr_insertobj &select, const InsertObj_CB &cb, bool useCache) : NFDBTask(serverId, useCache)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFDBInsertObjTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFDBInsertObjTask()
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

class NFDBModifyByCondTask : public NFDBTask
{
public:
    NFDBModifyByCondTask(const std::string &serverId, const storesvr_sqldata::storesvr_mod &select, const ModifyByCond_CB &cb, bool useCache) : NFDBTask(serverId, useCache)
    {
        m_balanceId = 0;
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFDBModifyByCondTask) + std::string("_") + select.baseinfo().tbname();
    }

    virtual ~NFDBModifyByCondTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
/*        if (m_useCache)
        {
            if (m_pNosqlDriver && m_pMysqlDriver)
            {
                std::string privateKey;
                std::unordered_set<std::string> privateKeySet;
                iRet = m_pMysqlDriver->DeleteByCond(mSelect, privateKey, privateKeySet);
                if (iRet != 0)
                {
                    return true;
                }

                iRet = m_pNosqlDriver->DeleteByCond(mSelect, privateKey, privateKeySet, mSelectRes);
                if (iRet <= 0)
                {
                    return true;
                }

                iRet = m_pMysqlDriver->DeleteByCond(mSelect, privateKey, privateKeySet, mSelectRes);
                if (iRet != 0)
                {
                    return true;
                }
            }
            else {
                iRet = -1;
                return true;
            }
        }
       */
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
        if (mCB)
        {
            mCB(iRet, mSelectRes);
        }
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_mod mSelect;
    storesvr_sqldata::storesvr_mod_res mSelectRes;
    ModifyByCond_CB mCB;
    int iRet;
};

class NFDBModifyObjTask : public NFDBTask
{
public:
    NFDBModifyObjTask(const std::string &serverId, const storesvr_sqldata::storesvr_modobj &select, const ModifyObj_CB &cb, bool useCache) : NFDBTask(serverId, useCache)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFDBModifyObjTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFDBModifyObjTask()
    {

    }

    /**
    **  异步线程处理函数，将在另一个线程里运行
    */
    bool ThreadProcess() override
    {
        if (m_useCache && m_pNosqlDriver)
        {
            iRet = m_pNosqlDriver->SaveObj(mSelect);
        }
        else {
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

        return true;
    }

    /**
    ** 主线程处理函数，将在线程处理完后，提交给主线程来处理，根据返回函数是否继续处理
    返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
    */
    TPTaskState MainThreadProcess() override
    {
        if (m_useCache)
        {
            if (iRet == 0)
            {
                if (mCB)
                {
                    mCB(iRet, mSelectRes);
                }
                mCB = nullptr;
                m_useCache = false;
                return TPTASK_STATE_CONTINUE_CHILDTHREAD;
            }
            else {
                if (mCB)
                {
                    mCB(iRet, mSelectRes);
                }
                return TPTASK_STATE_COMPLETED;
            }
        }
        else {
            if (mCB)
            {
                mCB(iRet, mSelectRes);
            }
            return TPTASK_STATE_COMPLETED;
        }
    }

public:
    storesvr_sqldata::storesvr_modobj mSelect;
    storesvr_sqldata::storesvr_modobj_res mSelectRes;
    ModifyObj_CB mCB;
    int iRet;
};

class NFDBUpdateByCondTask : public NFDBTask
{
public:
    NFDBUpdateByCondTask(const std::string &serverId, const storesvr_sqldata::storesvr_update &select, const UpdateByCond_CB &cb, bool useCache) : NFDBTask(
            serverId, useCache)
    {
        m_balanceId = 0;
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFDBUpdateByCondTask) + std::string("_") + select.baseinfo().tbname();
    }

    virtual ~NFDBUpdateByCondTask()
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
        if (mCB)
        {
            mCB(iRet, mSelectRes);
        }
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_update mSelect;
    storesvr_sqldata::storesvr_update_res mSelectRes;
    UpdateByCond_CB mCB;
    int iRet;
};

class NFDBUpdateObjTask : public NFDBTask
{
public:
    NFDBUpdateObjTask(const std::string &serverId, const storesvr_sqldata::storesvr_updateobj &select, const UpdateObj_CB &cb, bool useCache) : NFDBTask(serverId, useCache)
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
        if (m_useCache && m_pNosqlDriver)
        {
            iRet = m_pNosqlDriver->SaveObj(mSelect);
        }
        else {
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

        return true;
    }

    /**
    ** 主线程处理函数，将在线程处理完后，提交给主线程来处理，根据返回函数是否继续处理
    返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
    */
    TPTaskState MainThreadProcess() override
    {
        if (m_useCache)
        {
            if (iRet == 0)
            {
                if (mCB)
                {
                    mCB(iRet, mSelectRes);
                }
                mCB = nullptr;
                m_useCache = false;
                return TPTASK_STATE_CONTINUE_CHILDTHREAD;
            }
            else {
                if (mCB)
                {
                    mCB(iRet, mSelectRes);
                }
                return TPTASK_STATE_COMPLETED;
            }
        }
        else {
            if (mCB)
            {
                mCB(iRet, mSelectRes);
            }
            return TPTASK_STATE_COMPLETED;
        }
    }

public:
    storesvr_sqldata::storesvr_updateobj mSelect;
    storesvr_sqldata::storesvr_updateobj_res mSelectRes;
    UpdateObj_CB mCB;
    int iRet;
};

class NFDBExecuteTask : public NFDBTask
{
public:
    NFDBExecuteTask(const std::string &serverId, const storesvr_sqldata::storesvr_execute &select, const Execute_CB &cb) : NFDBTask(serverId)
    {
        m_balanceId = select.mod_key();
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFDBExecuteTask) + std::string("_") + select.baseinfo().tbname();;
    }

    virtual ~NFDBExecuteTask()
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
        if (mCB)
        {
            mCB(iRet, mSelectRes);
        }
        return TPTASK_STATE_COMPLETED;
    }

public:
    storesvr_sqldata::storesvr_execute mSelect;
    storesvr_sqldata::storesvr_execute_res mSelectRes;
    Execute_CB mCB;
    int iRet;
};

class NFDBExecuteMoreTask : public NFDBTask
{
public:
    NFDBExecuteMoreTask(const std::string &serverId, const storesvr_sqldata::storesvr_execute_more &select, const ExecuteMore_CB &cb) : NFDBTask(
            serverId)
    {
        m_balanceId = 0;
        mSelect = select;
        mCB = cb;
        iRet = 0;
        m_taskName = GET_CLASS_NAME(NFDBExecuteMoreTask);
    }

    virtual ~NFDBExecuteMoreTask()
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
            if (mCB)
            {
                mCB(iRet, *mSelectRes.Mutable(i));
            }
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
        m_pNoSqlDriverManager = NF_NEW NFCNosqlDriverManager();
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

                iRet = m_pNoSqlDriverManager->AddNosqlServer(pConnectTask->nServerID, pConnectTask->nNosqlIp, pConnectTask->nNosqlPort,
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
    NFCNosqlDriverManager *m_pNoSqlDriverManager;
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
    NFDBQueryDescStoreTask *pTask = NF_NEW NFDBQueryDescStoreTask(serverID, table, pSheetMessageObject, cb);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyDBModule::SelectByCond(const std::string &nServerID, const storesvr_sqldata::storesvr_sel &select, bool useCache,
                                    const SelectByCond_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFDBSelectByCondTask *pTask = NF_NEW NFDBSelectByCondTask(nServerID, select, cb, useCache);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}


int NFCAsyDBModule::SelectObj(const std::string &nServerID, const storesvr_sqldata::storesvr_selobj &select, bool useCache,
                                 const SelectObj_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFDBSelectObjTask *pTask = NF_NEW NFDBSelectObjTask(nServerID, select, cb, useCache);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}


int NFCAsyDBModule::DeleteByCond(const std::string &nServerID, const storesvr_sqldata::storesvr_del &select, bool useCache,
                                    const DeleteByCond_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFDBDeleteByCondTask *pTask = NF_NEW NFDBDeleteByCondTask(nServerID, select, cb, useCache);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}


int NFCAsyDBModule::DeleteObj(const std::string &nServerID, const storesvr_sqldata::storesvr_delobj &select, bool useCache,
                                 const DeleteObj_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFDBDeleteObjTask *pTask = NF_NEW NFDBDeleteObjTask(nServerID, select, cb, useCache);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}


int NFCAsyDBModule::InsertObj(const std::string &nServerID, const storesvr_sqldata::storesvr_insertobj &select, bool useCache,
                                 const InsertObj_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFDBInsertObjTask *pTask = NF_NEW NFDBInsertObjTask(nServerID, select, cb, useCache);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyDBModule::ModifyByCond(const std::string &nServerID, const storesvr_sqldata::storesvr_mod &select, bool useCache,
                                    const ModifyByCond_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFDBModifyByCondTask *pTask = NF_NEW NFDBModifyByCondTask(nServerID, select, cb, useCache);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyDBModule::ModifyObj(const std::string &nServerID, const storesvr_sqldata::storesvr_modobj &select, bool useCache,
                                 const ModifyObj_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFDBModifyObjTask *pTask = NF_NEW NFDBModifyObjTask(nServerID, select, cb, useCache);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyDBModule::UpdateByCond(const std::string &nServerID, const storesvr_sqldata::storesvr_update &select, bool useCache,
                                    const UpdateByCond_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFDBUpdateByCondTask *pTask = NF_NEW NFDBUpdateByCondTask(nServerID, select, cb, useCache);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyDBModule::UpdateObj(const std::string &nServerID, const storesvr_sqldata::storesvr_updateobj &select, bool useCache,
                                 const UpdateObj_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFDBUpdateObjTask *pTask = NF_NEW NFDBUpdateObjTask(nServerID, select, cb, useCache);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyDBModule::Execute(const std::string &nServerID, const storesvr_sqldata::storesvr_execute &select,
                               const Execute_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFDBExecuteTask *pTask = NF_NEW NFDBExecuteTask(nServerID, select, cb);
    int iRet = AddTask(pTask);
    CHECK_EXPR(iRet == 0, -1, "AddTask Failed");
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFCAsyDBModule::ExecuteMore(const std::string &nServerID, const storesvr_sqldata::storesvr_execute_more &select,
                                   const ExecuteMore_CB &cb)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    NFDBExecuteMoreTask *pTask = NF_NEW NFDBExecuteMoreTask(nServerID, select, cb);
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
