// -------------------------------------------------------------------------
//    @FileName         :    NFDBObjMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFDBObjMgr.cpp
//
// -------------------------------------------------------------------------

#include "NFDBObjMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFShmCore/NFBaseDBObj.h"
#include "NFDBObjTrans.h"
#include "NFShmMgr.h"
#include "NFComm/NFCore/NFTime.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFDBObjMgr, EOT_TRANS_DB_OBJ_MGR, NFShmObj)

NFDBObjMgr::NFDBObjMgr() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFDBObjMgr::~NFDBObjMgr() {
    if (m_iTimer != INVALID_ID)
    {
        DeleteTimer(m_iTimer);
        m_iTimer = INVALID_ID;
    }
}

int NFDBObjMgr::CreateInit() {
    m_iLastSavingObjIndex = 0;
    m_iLastTickTime = 0;
    m_iTransMngObjID = 0;
    m_runningObjList.CreateInit();
    m_failedObjList.CreateInit();
    m_iTimer = INVALID_ID;
    m_iTimer = SetTimer(1000, 0, 0, 0, 10, 0);
    return 0;
}

int NFDBObjMgr::ResumeInit() {
    return 0;
}

void NFDBObjMgr::OnTimer(int timeId, int callcount)
{
    if (m_iTimer == timeId)
    {
        Tick();
    }
}

int NFDBObjMgr::Tick()
{
    for(auto iter = m_failedObjList.Begin(); iter != m_failedObjList.End(); )
    {
        NFBaseDBObj* pObj = GetObj(*iter);
        if (pObj)
        {
            int iRet = LoadFromDB(pObj);
            if (iRet == 0)
            {
                iter = m_failedObjList.Erase(iter);
            }
            else
            {
                iter++;
            }
        }
        else
        {
            iter = m_failedObjList.Erase(iter);
        }
    }

    if (m_iLastSavingObjIndex >= (int)m_runningObjList.Size())
    {
        m_iLastSavingObjIndex = 0;
    }

    int iSavedObjNum = 0;
    int idx = 0;
    uint64_t now = NFTime::Now().UnixSec();
    for(auto iter = m_runningObjList.Begin(); iter != m_runningObjList.End() && iSavedObjNum < MAX_SAVED_OBJ_PRE_SEC; )
    {
        if (idx < m_iLastSavingObjIndex)
        {
            ++idx;
            ++iter;
            continue;
        }

        NFBaseDBObj* pObj = GetObj(*iter);
        if (pObj)
        {
            // 不在存储中 + 有修改
            if (pObj->GetTransID() == 0 && pObj->IsUrgentNeedSave())
            {
                if (pObj->GetLastDBOpTime() + pObj->GetSaveDis() < now)
                {
                    int iRet = SaveToDB(pObj);
                    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "save obj ret:{} {} {} {}", iRet, pObj->GetClassName(), pObj->GetTableID(), pObj->GetDBWrapName());
                    ++iSavedObjNum;
                }
            }
            ++iter;
            ++idx;
            ++m_iLastSavingObjIndex;
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Remove running obj:{}", *iter);
            iter = m_runningObjList.Erase(iter);
        }
    }

    return 0;
}

int NFDBObjMgr::LoadFromDB(NFBaseDBObj *pObj) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    CHECK_NULL(pObj);

    if (pObj->IsDataInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "data already inited:{} name:{}", pObj->GetGlobalID(), pObj->GetClassName())
        return -1;
    }

    NFDBObjTrans* pTrans = dynamic_cast<NFDBObjTrans*>(NFShmMgr::Instance()->CreateTrans(EOT_TRANS_DB_OBJ));
    CHECK_EXPR(pTrans, -1, "Create NFDBObjTrans:EOT_TRANS_DB_OBJ Failed! use num:{}", NFDBObjTrans::GetUsedCount());

    int iRet = pTrans->Init(pObj->GetServerType(), pObj->GetGlobalID(), pObj->GetCurSeq());
    CHECK_EXPR(iRet == 0, -1, "Init Trans Failed!");

    google::protobuf::Message* pMessage = pObj->CreateTempProtobufData();
    CHECK_NULL(pMessage);
    iRet = pObj->MakeLoadData(pMessage);
    if (iRet != 0)
    {
        NF_SAFE_DELETE(pMessage);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Make LoadData Failed:{} iRet:{}", pObj->GetClassName(), iRet);
        m_failedObjList.PushBack(pObj->GetGlobalID());
        return iRet;
    }

    pObj->SetLastDBOpTime(NFTime::Now().UnixSec());
    pObj->SetTransID(pTrans->GetGlobalID());
    iRet = pTrans->Load(pObj->GetTableID(), pObj->GetDBWrapName(), pObj->GetModeKey(), pMessage);
    NFLogDebug(NF_LOG_SYSTEMLOG, 0, "Load db ob from tableid:{} tablename:{} transName:{} iRet:{}", pObj->GetTableID(), pObj->GetDBWrapName(), pTrans->GetClassName(), iRet);
    NF_SAFE_DELETE(pMessage);
    if (iRet != 0)
    {
        m_failedObjList.PushBack(pObj->GetGlobalID());
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Make LoadData Failed:{} iRet:{}", pObj->GetClassName(), iRet);
        return iRet;
    }
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
    return 0;
}

int NFDBObjMgr::OnDataLoaded(int iObjID, uint32_t err_code, const std::string* msg) {
    NFLogDebug(NF_LOG_SYSTEMLOG, 0, "Date Loaded:{} err_code:{}", iObjID, err_code);
    NFBaseDBObj* pObj = GetObj(iObjID);
    CHECK_NULL(pObj);

    pObj->SetTransID(0);
    int iRet = 0;
    if (err_code == 0) {
        pObj->SetRetryTimes(0);
        iRet = pObj->InitWithDBData(msg);
    }
    else if (err_code == proto_ff::E_STORESVR_ERRCODE_SELECT_EMPTY) {
        pObj->SetRetryTimes(0);
        pObj->SetNeedInsertDB(true);
        iRet = pObj->InitWithoutDBData();
    }
    else
    {
        iRet = -1;
    }

    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "DBName:{} TableID:{} load faled! iRet:{}", pObj->GetDBWrapName(), pObj->GetTableID(), iRet);
        switch (pObj->DealWithFailed()) {
            case EN_DW_LOG_FAIL: {
                pObj->SetInRecycle(true);
                NFLogError(NF_LOG_SYSTEMLOG, 0, "Load From DB Error:{} DB error code:{}", iRet, err_code);
                break;
            }
            case EN_DW_RETRY: {
                pObj->SetRetryTimes(pObj->GetRetryTimes() + 1);
                iRet = LoadFromDB(pObj);
                break;
            }
            case EN_DW_SHUTDOWN:
            {
                NFLogFatal(NF_LOG_SYSTEMLOG, 0, "DBName:{} Load Failed", pObj->GetDBWrapName());
                NFLogFatal(NF_LOG_SYSTEMLOG, 0, "Shutdown Server by obj init faled, tableId:{} tableName:{}", pObj->GetTableID(), pObj->GetDBWrapName());
                assert(0);
                return -1;
            }
            case EN_DW_RETRY_ANY_SHUTDOWN:
            {
                if (pObj->GetRetryTimes() > MAX_FAIL_RETRY_TIMES)
                {
                    NFLogFatal(NF_LOG_SYSTEMLOG, 0, "DBName:{} Load Failed", pObj->GetDBWrapName());
                    NFLogFatal(NF_LOG_SYSTEMLOG, 0, "Shutdown Server by obj init faled, tableId:{} tableName:{}", pObj->GetTableID(), pObj->GetDBWrapName());
                    NF_ASSERT(false);
                    return -1;
                }
                pObj->SetRetryTimes(pObj->GetRetryTimes()+1);
                iRet = LoadFromDB(pObj);
                break;
            }
            default:
            {
                break;
            }
        }
    }
    else
    {
        m_runningObjList.PushBack(pObj->GetGlobalID());
    }

    return 0;
}

int NFDBObjMgr::OnDataInserted(NFDBObjTrans* pTrans, bool success)
{
    CHECK_NULL(pTrans);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Data Inserted:{} {}", pTrans->GetLinkedObjID(), pTrans->GetClassName());
    NFBaseDBObj* pObj = GetObj(pTrans->GetLinkedObjID());
    CHECK_NULL(pObj);

    pObj->SetTransID(0);
    if (success)
    {
        pObj->SetLastDBOpTime(NFTime::Now().UnixSec());
        pObj->SetNeedInsertDB(false);
        if (pTrans->GetObjSeqOP() == pObj->GetCurSeq())
        {
            pObj->ClearUrgent();
        }
    }
    return 0;
}

int NFDBObjMgr::OnDataSaved(NFDBObjTrans* pTrans, bool success)
{
    CHECK_NULL(pTrans);
    NFBaseDBObj* pObj = GetObj(pTrans->GetLinkedObjID());
    CHECK_NULL(pObj);

    pObj->SetTransID(0);
    if (success)
    {
        pObj->SetLastDBOpTime(NFTime::Now().UnixSec());
        if (pTrans->GetObjSeqOP() == pObj->GetCurSeq())
        {
            pObj->ClearUrgent();
        }
    }
    return 0;
}

NFBaseDBObj *NFDBObjMgr::GetObj(int iObjID) {
    return dynamic_cast<NFBaseDBObj*>(NFShmMgr::Instance()->GetObjFromGlobalID(iObjID, EOT_BASE_DB_OBJ, 0));
}

int NFDBObjMgr::SaveToDB(NFBaseDBObj *pObj) {
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--begin--");
    CHECK_NULL(pObj);

    if (!pObj->IsDataInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "data not init:{} name:{}", pObj->GetGlobalID(), pObj->GetClassName())
        return -1;
    }

    NFDBObjTrans* pTrans = dynamic_cast<NFDBObjTrans*>(NFShmMgr::Instance()->CreateTrans(EOT_TRANS_DB_OBJ));
    CHECK_EXPR(pTrans, -1, "Create NFDBObjTrans:EOT_TRANS_DB_OBJ Failed! use num:{}", NFDBObjTrans::GetUsedCount());

    int iRet = pTrans->Init(pObj->GetServerType(), pObj->GetGlobalID(), pObj->GetCurSeq());
    CHECK_EXPR(iRet == 0, -1, "Init Trans Failed!");

    google::protobuf::Message* pMessage = pObj->CreateTempProtobufData();
    CHECK_NULL(pMessage);
    iRet = pObj->MakeSaveData(pMessage);
    if (iRet != 0)
    {
        NF_SAFE_DELETE(pMessage);
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Make save Failed:{} iRet:{}", pObj->GetClassName(), iRet);
        return iRet;
    }

    pObj->SetTransID(pTrans->GetGlobalID());
    if (pObj->GetNeedInsertDB())
    {
        iRet = pTrans->Insert(pObj->GetTableID(), pObj->GetDBWrapName(), pObj->GetModeKey(), pMessage);
    }
    else
    {
        iRet = pTrans->Save(pObj->GetTableID(), pObj->GetDBWrapName(), pObj->GetModeKey(), pMessage);
    }

    NF_SAFE_DELETE(pMessage);
    CHECK_RET(iRet, "SaveToDB Failed, TableID:{} TableName:{}", pObj->GetTableID(), pObj->GetDBWrapName());
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--end--");
    return 0;
}
