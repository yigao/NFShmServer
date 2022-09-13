// -------------------------------------------------------------------------
//    @FileName         :    NFDBObjTrans.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFDBObjTrans.cpp
//
// -------------------------------------------------------------------------

#include "NFDBObjTrans.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFDBObjMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFDBObjTrans, EOT_TRANS_DB_OBJ, NFTransBase)

NFDBObjTrans::NFDBObjTrans() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFDBObjTrans::~NFDBObjTrans() {

}

int NFDBObjTrans::CreateInit() {
    m_iLinkedObjID = 0;
    m_iObjSeqOP = 0;
    m_iDBOP = 0;
    m_iServerType = NF_ST_NONE;
    return 0;
}

int NFDBObjTrans::ResumeInit() {
    return 0;
}

int NFDBObjTrans::Init(NF_SERVER_TYPES eType, int iObjID, uint32_t iSeqOP) {
    m_iLinkedObjID = iObjID;
    m_iObjSeqOP = iSeqOP;
    m_iServerType = eType;
    return 0;
}

int NFDBObjTrans::Insert(proto_ff::TableID eTableID, const std::string &sTableName, uint64_t iModKey,
                         google::protobuf::Message *data) {
    CHECK_NULL(data);
    NFLogDebug(NF_LOG_SYSTEMLOG, 0, "InsertToDB, tableId:{} tableName:{} trans:{} msg:{}", eTableID, sTableName, GetGlobalID(), data->DebugString());

    m_iDBOP = proto_ff::E_STORESVR_C2S_INSERT;
    int iRetCode = NFMessageMgr::Instance()->SendTransToStoreServer(m_iServerType,
                                                                          proto_ff::E_STORESVR_C2S_INSERT,
                                                                          eTableID,
                                                                          NF_DEFAULT_MYSQL_DB_NAME, sTableName, *data,
                                                                          GetGlobalID(),
                                                                          m_iObjSeqOP, iModKey);
    if (iRetCode)
    {
        SetFinished(0);
    }
    return iRetCode;
}

int NFDBObjTrans::Save(proto_ff::TableID eTableID, const string &sTableName, uint64_t iModKey,
                       google::protobuf::Message *data) {
    CHECK_NULL(data);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "SaveToDB, tableId:{} tableName:{} trans:{} ", eTableID, sTableName, GetGlobalID());

    m_iDBOP = proto_ff::E_STORESVR_C2S_MODIFYOBJ;
    int iRetCode = NFMessageMgr::Instance()->SendTransToStoreServer(m_iServerType,
                                                                          proto_ff::E_STORESVR_C2S_MODIFYOBJ,
                                                                          eTableID,
                                                                          NF_DEFAULT_MYSQL_DB_NAME, sTableName, *data,
                                                                          GetGlobalID(),
                                                                          m_iObjSeqOP, iModKey);
    if (iRetCode)
    {
        SetFinished(0);
    }
    return iRetCode;
}

int NFDBObjTrans::Load(proto_ff::TableID eTableID, const string &sTableName, uint64_t iModKey,
                       google::protobuf::Message *data) {
    CHECK_NULL(data);
    NFLogDebug(NF_LOG_SYSTEMLOG, 0, "LoadFromDB, tableId:{} tableName:{} trans:{} msg:{}", eTableID, sTableName, GetGlobalID(), data->DebugString());

    m_iDBOP = proto_ff::E_STORESVR_C2S_SELECTOBJ;
    int iRetCode = NFMessageMgr::Instance()->SendTransToStoreServer(m_iServerType,
                                                                          proto_ff::E_STORESVR_C2S_SELECTOBJ,
                                                                          eTableID,
                                                                          NF_DEFAULT_MYSQL_DB_NAME, sTableName, *data,
                                                                          GetGlobalID(),
                                                                          m_iObjSeqOP, iModKey);
    if (iRetCode)
    {
        SetFinished(0);
    }
    return iRetCode;
}

int NFDBObjTrans::OnTimeOut() {
    switch (m_iDBOP) {
        case proto_ff::E_STORESVR_C2S_SELECTOBJ:
        {
            return NFDBObjMgr::Instance()->OnDataLoaded(m_iLinkedObjID, proto_ff::E_STORESVR_ERRCODE_BUSY, NULL);
        }
        case proto_ff::E_STORESVR_C2S_INSERT:
        {
            NFDBObjMgr::Instance()->OnDataInserted(this, false);
            NFLogError(NF_LOG_SYSTEMLOG, 0, "save obj timeout:{}", m_iLinkedObjID);
            break;
        }
        case proto_ff::E_STORESVR_C2S_MODIFYOBJ:
        {
            NFDBObjMgr::Instance()->OnDataSaved(this, false);
            NFLogError(NF_LOG_SYSTEMLOG, 0, "save obj timeout:{}", m_iLinkedObjID);
            break;
        }
        default:
        {
            NFLogFatal(NF_LOG_SYSTEMLOG, 0, "unkown db op:{} obj_id:{}", m_iDBOP, m_iLinkedObjID);
            break;
        }
    }
    return 0;
}

int NFDBObjTrans::HandleTransFinished(int iRunLogicRetCode) {
    if (iRunLogicRetCode == 0)
    {
        return 0;
    }

    switch(m_iDBOP)
    {
        case proto_ff::E_STORESVR_C2S_SELECTOBJ:
        {
            return NFDBObjMgr::Instance()->OnDataLoaded(m_iLinkedObjID, proto_ff::E_STORESVR_ERRCODE_UNKNOWN, NULL);
        }
        case proto_ff::E_STORESVR_C2S_MODIFYOBJ:
        {
            NFDBObjMgr::Instance()->OnDataSaved(this, false);
            NFLogError(NF_LOG_SYSTEMLOG, 0, "save obj failed:{} err:{}", m_iLinkedObjID, m_iRunLogicRetCode);
            break;
        }
        default:
        {
            NFLogFatal(NF_LOG_SYSTEMLOG, 0, "unknown db op:{} objId:{}", m_iDBOP, m_iLinkedObjID);
            break;
        }
    }

    return 0;
}

int
NFDBObjTrans::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq,
                             uint32_t err_code) {
    int iRet = 0;
    switch(cmd)
    {
        case proto_ff::E_STORESVR_S2C_SELECTOBJ:
        {
            if (!pSSMsgRes)
            {
                iRet  = NFDBObjMgr::Instance()->OnDataLoaded(m_iLinkedObjID, err_code, NULL);
            }
            else
            {
                const storesvr_sqldata::storesvr_selobj_res* pRes = dynamic_cast<const storesvr_sqldata::storesvr_selobj_res*>(pSSMsgRes);
                CHECK_NULL(pRes);
                iRet  = NFDBObjMgr::Instance()->OnDataLoaded(m_iLinkedObjID, err_code, &pRes->sel_record());
            }
            break;
        }
        case proto_ff::E_STORESVR_S2C_INSERT:
        {
            if (err_code == proto_ff::E_STORESVR_ERRCODE_OK)
            {
                NFDBObjMgr::Instance()->OnDataInserted(this, true);
            }
            else
            {
                NFDBObjMgr::Instance()->OnDataInserted(this, false);
            }
            break;
        }
        case proto_ff::E_STORESVR_S2C_MODIFYOBJ:
        {
            if (err_code == proto_ff::E_STORESVR_ERRCODE_OK)
            {
                NFDBObjMgr::Instance()->OnDataSaved(this, true);
            }
            else
            {
                NFDBObjMgr::Instance()->OnDataSaved(this, false);
            }
            break;
        }
        default:
        {
            NFLogFatal(NF_LOG_SYSTEMLOG, 0, "unknown cmd:{}", cmd);
            break;
        }
    }

    SetFinished(0);
    return iRet;
}


