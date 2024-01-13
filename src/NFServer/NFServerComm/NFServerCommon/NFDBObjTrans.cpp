// -------------------------------------------------------------------------
//    @FileName         :    NFDBObjTrans.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFDBObjTrans.cpp
//
// -------------------------------------------------------------------------

#include "NFDBObjTrans.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFDBObjMgr.h"
#include "NFIServerMessageModule.h"

NFDBObjTrans::NFDBObjTrans()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFDBObjTrans::~NFDBObjTrans()
{
}

int NFDBObjTrans::CreateInit()
{
    m_iLinkedObjID = 0;
    m_iObjSeqOP = 0;
    m_iDBOP = 0;
    m_iServerType = NF_ST_NONE;
    return 0;
}

int NFDBObjTrans::ResumeInit()
{
    return 0;
}

int NFDBObjTrans::Init(NF_SERVER_TYPES eType, int iObjID, uint32_t iSeqOP)
{
    m_iLinkedObjID = iObjID;
    m_iObjSeqOP = iSeqOP;
    m_iServerType = eType;
    return 0;
}

int NFDBObjTrans::Insert(uint64_t iModKey, google::protobuf::Message* data)
{
    CHECK_NULL(data);
    NFLogDebug(NF_LOG_SYSTEMLOG, 0, "InsertToDB, tableName:{} trans:{} msg:{}", data->GetTypeName(), GetGlobalId(), data->DebugString());

    m_iDBOP = proto_ff::NF_STORESVR_C2S_INSERTOBJ;
    m_rpcId = FindModule<NFIServerMessageModule>()->GetRpcInsertObjService(m_iServerType, iModKey, *data, [this](int rpcRetCode)
    {
        if (rpcRetCode == proto_ff::ERR_CODE_SVR_OK)
        {
            NFDBObjMgr::Instance(m_pObjPluginManager)->OnDataInserted(this, true);
        }

        SetFinished(rpcRetCode);
    });

    if (m_rpcId == INVALID_ID)
    {
        SetFinished(0);
        return proto_ff::ERR_CODE_RPC_SYSTEM_ERROR;
    }
    return 0;
}

int NFDBObjTrans::Save(uint64_t iModKey, google::protobuf::Message* data)
{
    CHECK_NULL(data);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "SaveToDB, tableName:{} trans:{} ", data->GetTypeName(), GetGlobalId());

    m_iDBOP = proto_ff::NF_STORESVR_C2S_MODIFYOBJ;
    m_rpcId = FindModule<NFIServerMessageModule>()->GetRpcModifyObjService(m_iServerType, iModKey, *data, [this](int rpcRetCode)
    {
        if (rpcRetCode == proto_ff::ERR_CODE_SVR_OK)
        {
            NFDBObjMgr::Instance(m_pObjPluginManager)->OnDataSaved(this, true);
        }

        SetFinished(rpcRetCode);
    });

    if (m_rpcId == INVALID_ID)
    {
        SetFinished(0);
        return proto_ff::ERR_CODE_RPC_SYSTEM_ERROR;
    }
    return 0;
}

int NFDBObjTrans::Load(uint64_t iModKey, google::protobuf::Message* data)
{
    CHECK_NULL(data);
    NFLogDebug(NF_LOG_SYSTEMLOG, 0, "LoadFromDB, tableName:{} trans:{} msg:{}", data->GetTypeName(), GetGlobalId(), data->DebugString());

    m_iDBOP = proto_ff::NF_STORESVR_C2S_SELECTOBJ;
    m_rpcId = FindModule<NFIServerMessageModule>()->GetRpcSelectObjService(m_iServerType, iModKey, *data, [this](int rpcRetCode, google::protobuf::Message &respone)
    {
        if (rpcRetCode == proto_ff::ERR_CODE_SVR_OK)
        {
            NFDBObjMgr::Instance(m_pObjPluginManager)->OnDataLoaded(m_iLinkedObjID, rpcRetCode, &respone);
            SetFinished(0);
        }
        else if (rpcRetCode == proto_ff::ERR_CODE_STORESVR_ERRCODE_SELECT_EMPTY)
        {
            NFDBObjMgr::Instance(m_pObjPluginManager)->OnDataLoaded(m_iLinkedObjID, rpcRetCode, NULL);
            SetFinished(0);
        }
        else
        {
            SetFinished(rpcRetCode);
        }
    });

    if (m_rpcId == INVALID_ID)
    {
        SetFinished(0);
        return proto_ff::ERR_CODE_RPC_SYSTEM_ERROR;
    }
    return 0;
}

int NFDBObjTrans::OnTimeOut()
{
    return 0;
}

int NFDBObjTrans::HandleTransFinished(int iRunLogicRetCode)
{
    if (iRunLogicRetCode == 0)
    {
        return 0;
    }

    switch (m_iDBOP)
    {
        case proto_ff::NF_STORESVR_C2S_SELECTOBJ:
        {
            if (iRunLogicRetCode == proto_ff::ERR_CODE_SVR_SYSTEM_TIMEOUT)
            {
                NFDBObjMgr::Instance(m_pObjPluginManager)->OnDataLoaded(m_iLinkedObjID, proto_ff::ERR_CODE_STORESVR_ERRCODE_BUSY, NULL);
                NFLogError(NF_LOG_SYSTEMLOG, 0, "load obj timeout:{}", m_iLinkedObjID);
            }
            else
            {
                NFDBObjMgr::Instance(m_pObjPluginManager)->OnDataLoaded(m_iLinkedObjID, proto_ff::ERR_CODE_STORESVR_ERRCODE_UNKNOWN, NULL);
                NFLogError(NF_LOG_SYSTEMLOG, 0, "load obj:{} error:{}", m_iLinkedObjID, GetErrorStr(iRunLogicRetCode));
            }
            break;
        }
        case proto_ff::NF_STORESVR_C2S_INSERTOBJ:
        {
            NFDBObjMgr::Instance(m_pObjPluginManager)->OnDataInserted(this, false);
            if (iRunLogicRetCode == proto_ff::ERR_CODE_SVR_SYSTEM_TIMEOUT)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "insert obj timeout:{}", m_iLinkedObjID);
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "insert obj:{} error:{}", m_iLinkedObjID, GetErrorStr(iRunLogicRetCode));
            }
            break;
        }
        case proto_ff::NF_STORESVR_C2S_MODIFYOBJ:
        {
            NFDBObjMgr::Instance(m_pObjPluginManager)->OnDataSaved(this, false);
            if (iRunLogicRetCode == proto_ff::ERR_CODE_SVR_SYSTEM_TIMEOUT)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "save obj timeout:{}", m_iLinkedObjID);
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "save obj:{} error:{}", m_iLinkedObjID, GetErrorStr(iRunLogicRetCode));
            }

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

