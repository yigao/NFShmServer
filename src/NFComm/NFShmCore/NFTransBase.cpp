// -------------------------------------------------------------------------
//    @FileName         :    NFTransBase.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransBase.cpp
//
// -------------------------------------------------------------------------

#include "NFTransBase.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFTimeUtil.h"
#include "NFComm/NFShmCore/NFTypeDefines.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFPluginModule/NFError.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransBase, EOT_TRANS_BASE, NFShmObj)

NFTransBase::NFTransBase() : NFShmObj()
{
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT)
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFTransBase::~NFTransBase()
{

}

int NFTransBase::CreateInit()
{
    m_wCurState = 0;
    m_dwStartTime = 0;
    m_bIsFinished = false;
    m_wRunedTimes = 0;
    m_iRunLogicRetCode = 0;
    Init();
    return 0;
}

int NFTransBase::ResumeInit()
{
    return 0;
}

int NFTransBase::Init()
{
    m_wCurState = 0;
    m_dwStartTime = NFTime::Now().UnixSec();
    m_dwKeepAliveTime = m_dwStartTime;
    m_wRunedTimes = 0;
    return 0;
}

void NFTransBase::IncreaseRunTimes()
{
    m_wRunedTimes++;
}

bool NFTransBase::IsFinished() const
{
    return m_bIsFinished;
}

void NFTransBase::SetFinished(int iRetCode)
{
    if (m_bIsFinished)
    {
        return;
    }

    if (iRetCode != 0)
    {
        m_iRunLogicRetCode = iRetCode;
    }

    HandleTransFinished(m_iRunLogicRetCode);

    OnTransFinished(m_iRunLogicRetCode);

    m_bIsFinished = true;
}

int NFTransBase::ProcessCSMsgReq(const google::protobuf::Message *pCSMsgReq)
{
    int iRetCode = 0;
    iRetCode = RunCommLogic();
    CHECK_RET(iRetCode, "RunCommLogic Failed, RunedTimes:", m_wRunedTimes);

    iRetCode = HandleCSMsgReq(pCSMsgReq);
    if (iRetCode != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "HandleCSMsgReq Failed");
        SetFinished(iRetCode);
        m_iRunLogicRetCode = iRetCode;
        return iRetCode;
    }

    return 0;
}

int NFTransBase::ProcessDBMsgRes(proto_ff::Proto_SvrPkg &svrPkg)
{
    switch (svrPkg.store_info().cmd())
    {
        case proto_ff::NF_STORESVR_S2C_SELECT:
        {
            storesvr_sqldata::storesvr_sel_res select_res;
            select_res.ParsePartialFromString(svrPkg.msg_data());
            ProcessDBMsgRes(&select_res, svrPkg.store_info().cmd(),
                            svrPkg.store_info().cb_data().table_id(),
                            svrPkg.store_info().cb_data().seq(),
                            svrPkg.store_info().err_code());
        }
            break;
        case proto_ff::NF_STORESVR_S2C_SELECTOBJ:
        {
            storesvr_sqldata::storesvr_selobj_res select_res;
            select_res.ParsePartialFromString(svrPkg.msg_data());
            ProcessDBMsgRes(&select_res, svrPkg.store_info().cmd(),
                            svrPkg.store_info().cb_data().table_id(),
                            svrPkg.store_info().cb_data().seq(),
                            svrPkg.store_info().err_code());
        }
            break;
        case proto_ff::NF_STORESVR_S2C_INSERT:
        {
            storesvr_sqldata::storesvr_insertobj_res select_res;
            select_res.ParsePartialFromString(svrPkg.msg_data());
            ProcessDBMsgRes(&select_res, svrPkg.store_info().cmd(),
                            svrPkg.store_info().cb_data().table_id(),
                            svrPkg.store_info().cb_data().seq(),
                            svrPkg.store_info().err_code());
        }
            break;
        case proto_ff::NF_STORESVR_S2C_DELETE:
        {
            storesvr_sqldata::storesvr_del_res select_res;
            select_res.ParsePartialFromString(svrPkg.msg_data());
            ProcessDBMsgRes(&select_res, svrPkg.store_info().cmd(),
                            svrPkg.store_info().cb_data().table_id(),
                            svrPkg.store_info().cb_data().seq(),
                            svrPkg.store_info().err_code());
        }
            break;
        case proto_ff::NF_STORESVR_S2C_DELETEOBJ:
        {
            storesvr_sqldata::storesvr_delobj_res select_res;
            select_res.ParsePartialFromString(svrPkg.msg_data());
            ProcessDBMsgRes(&select_res, svrPkg.store_info().cmd(),
                            svrPkg.store_info().cb_data().table_id(),
                            svrPkg.store_info().cb_data().seq(),
                            svrPkg.store_info().err_code());
        }
            break;
        case proto_ff::NF_STORESVR_S2C_MODIFY:
        {
            storesvr_sqldata::storesvr_mod_res select_res;
            select_res.ParsePartialFromString(svrPkg.msg_data());
            ProcessDBMsgRes(&select_res, svrPkg.store_info().cmd(),
                            svrPkg.store_info().cb_data().table_id(),
                            svrPkg.store_info().cb_data().seq(),
                            svrPkg.store_info().err_code());
        }
            break;
        case proto_ff::NF_STORESVR_S2C_MODIFYOBJ:
        {
            storesvr_sqldata::storesvr_modobj_res select_res;
            select_res.ParsePartialFromString(svrPkg.msg_data());
            ProcessDBMsgRes(&select_res, svrPkg.store_info().cmd(),
                            svrPkg.store_info().cb_data().table_id(),
                            svrPkg.store_info().cb_data().seq(),
                            svrPkg.store_info().err_code());
        }
            break;
        case proto_ff::NF_STORESVR_S2C_UPDATE:
        {
            storesvr_sqldata::storesvr_update_res select_res;
            select_res.ParsePartialFromString(svrPkg.msg_data());
            ProcessDBMsgRes(&select_res, svrPkg.store_info().cmd(),
                            svrPkg.store_info().cb_data().table_id(),
                            svrPkg.store_info().cb_data().seq(),
                            svrPkg.store_info().err_code());
        }
            break;
        case proto_ff::NF_STORESVR_S2C_UPDATEOBJ:
        {
            storesvr_sqldata::storesvr_updateobj_res select_res;
            select_res.ParsePartialFromString(svrPkg.msg_data());
            ProcessDBMsgRes(&select_res, svrPkg.store_info().cmd(),
                            svrPkg.store_info().cb_data().table_id(),
                            svrPkg.store_info().cb_data().seq(),
                            svrPkg.store_info().err_code());
        }
            break;
        case proto_ff::NF_STORESVR_S2C_EXECUTE:
        {
            storesvr_sqldata::storesvr_execute_res select_res;
            select_res.ParsePartialFromString(svrPkg.msg_data());
            ProcessDBMsgRes(&select_res, svrPkg.store_info().cmd(),
                            svrPkg.store_info().cb_data().table_id(),
                            svrPkg.store_info().cb_data().seq(),
                            svrPkg.store_info().err_code());
        }
            break;
        default:
        {

        }
            break;
    }

    return 0;
}

int NFTransBase::ProcessDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq, int32_t err_code)
{
    int iRetCode = 0;
    iRetCode = RunCommLogic();
    CHECK_RET(iRetCode, "RunCommLogic Failed, RunedTimes:", m_wRunedTimes);

    iRetCode = HandleDBMsgRes(pSSMsgRes, cmd, table_id, seq, err_code);
    if (iRetCode != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "HandleDBMsgRes Failed, cmd:{} table_id:{} err_code:{}", cmd, table_id, GetErrorStr(err_code));
        SetFinished(iRetCode);
        m_iRunLogicRetCode = iRetCode;
        return iRetCode;
    }

    return 0;
}

int
NFTransBase::HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq,
                            int32_t err_code)
{
    NFLogFatal(NF_LOG_SYSTEMLOG, 0, "Fatal Err Calling the Method");
    NF_ASSERT(false);
    return -1;
}

int NFTransBase::ProcessDispSvrRes(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    int iRetCode = 0;
    iRetCode = RunCommLogic();
    CHECK_RET(iRetCode, "RunCommLogic Failed RunedTimes:{}", m_wRunedTimes);
    iRetCode = HandleDispSvrRes(nMsgId, packet, reqTransId, rspTransId);

    if (iRetCode != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "HandleDispSvrRes Failed");
        SetFinished(iRetCode);
        m_iRunLogicRetCode = iRetCode;
        return iRetCode;
    }

    return 0;
}

int NFTransBase::HandleDispSvrRes(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId)
{
    NFLogError(NF_LOG_SYSTEMLOG, 0, "the msg not handle, nMsgId:{} reqTransId:{} rspTransId:{}", nMsgId, reqTransId, rspTransId);
    NF_ASSERT(false);
    return -1;
}

bool NFTransBase::CanRelease()
{
    if (IsFinished())
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "This Trans can release, {} return code:{}", DebugString(), m_iRunLogicRetCode);
        return true;
    }
    return false;
}

std::string NFTransBase::DebugString() const
{
    std::string str = NF_FORMAT("GlobalID:{} Type:{} ClassName:{} ItemCount:{} UsedCount:{} FreeCount:{} CurState:{} StartTime:{} RunedTimes:{}",
                                GetGlobalId(), GetClassType(), GetClassName(), GetItemCount(), GetUsedCount(), GetFreeCount(), m_wCurState,
                                DateTimeToStr((int) m_dwStartTime), m_wRunedTimes);
    return str;
}

bool NFTransBase::IsTimeOut()
{
    if (NFTime::Now().UnixSec() >= m_dwKeepAliveTime + TRANS_ACTIVE_TIMEOUT)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "This Trans TimeOut Info:{}", DebugString());
        OnTimeOut();
        return true;
    }
    return false;
}

int NFTransBase::OnTimeOut()
{
    return 0;
}

int NFTransBase::CheckCanRunNow()
{
    CHECK_EXPR(m_wRunedTimes < MAX_TRANS_RUNED_TIMES, -1, " RunedTiems Too Much:{} Max:{}", m_wRunedTimes,
               MAX_TRANS_RUNED_TIMES);
    return 0;
}

int NFTransBase::RunCommLogic()
{
    int iRetCode = 0;
    iRetCode = CheckCanRunNow();

    if (iRetCode != 0)
    {
        SetFinished(ERR_TRANS_RUNED_TOO_MUCH);
        m_iRunLogicRetCode = ERR_TRANS_RUNED_TOO_MUCH;
        return ERR_TRANS_RUNED_TOO_MUCH;
    }
    else
    {
        m_dwKeepAliveTime = NFTime::Now().UnixSec();
        IncreaseRunTimes();
        return 0;
    }
}

int NFTransBase::HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq)
{
    NFLogFatal(NF_LOG_SYSTEMLOG, 0, "Fatal Err Calling the Method");
    NF_ASSERT(false);
    return -1;
}




