// -------------------------------------------------------------------------
//    @FileName         :    NFTransSnsBase.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransSnsBase.cpp
//
// -------------------------------------------------------------------------

#include "NFTransSnsBase.h"
#include "NFSnsUserSimpleUtil.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFMessageDefine/proto_cs.pb.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFOnlineUser/NFOnlineUser.h"
#include "NFOnlineUser/NFOnlineUserMgr.h"
#include "NFSnsUserSimple.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransSnsBase, EOT_TRANS_SNS_BASE, NFTransBase)

NFTransSnsBase::NFTransSnsBase() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFTransSnsBase::~NFTransSnsBase() {

}

int NFTransSnsBase::CreateInit() {
    m_bNotify = false;
    memset(&m_query, 0, sizeof(m_query));
    return 0;
}


int NFTransSnsBase::ResumeInit() {
    return 0;
}

int NFTransSnsBase::Init(int reqTrans)
{
    memset(&m_query, 0, sizeof(m_query));
    m_reqTrans = reqTrans;
    return 0;
}

int NFTransSnsBase::QueryRole(tagQueryRole &query) {
    m_query = query;
    return QueryRole();
}

int NFTransSnsBase::QueryRole(uint64_t roleID) {
    m_query.Add(roleID);
    return QueryRole();
}

int NFTransSnsBase::QueryRole() {
    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- begin --");
    for (int i = 0; i < m_query.query_role.GetSize(); i++) {
        if (m_query.query_role[i] == 0) {
            ++m_query.queryed_num;
            continue;
        }

        if (NFSnsUserSimpleUtil::GetInstance()->GetRoleSimpe(m_query.query_role[i], false)) {
            m_query.queryed_num++;
        } else {
            NFSnsUserSimpleUtil::GetInstance()->GetRoleSimpleInfo(m_query.query_role[i], GetGlobalID(),
                                                                  m_dwKeepAliveTime);
        }
    }

    if (m_query.queryed_num >= m_query.query_role.GetSize()) {
        int iRetCode = QueryRole_CallBack(m_query);
        SetFinished(iRetCode);
    }

    NFLogTrace(NF_LOG_SNS_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFTransSnsBase::QueryRole_CallBack(tagQueryRole &query) {
    if (m_bNotify == false) {
        return 0;
    }

    NFOnlineUser* pOnline = NFOnlineUserMgr::GetInstance()->Find(query.userId);
    if (!pOnline)
    {
        return -1;
    }

    NFSnsUserSimple* pSimple = NFSnsUserSimpleUtil::GetInstance()->GetRoleSimpe(m_query.userId, false);
    if (!pSimple)
    {
        return -1;
    }

    proto_ff::Proto_STLQueryUserRsp rsp;
    rsp.set_result(0);
    rsp.set_user_id(query.userId);

    for(int i = 0; i < (int)query.query_role.GetSize(); i++)
    {
        uint64_t query_user_id = query.query_role[i];
        NFSnsUserSimple* pQuerySimple = NFSnsUserSimpleUtil::GetInstance()->GetRoleSimpe(query_user_id, false);
        if (pQuerySimple)
        {
            proto_ff::UserSimpleData* pData = rsp.add_query_user_list();
            pQuerySimple->GetLogicRoleSimpleInfo(*pData);
        }
        else
        {
            rsp.set_result(-1);
        }
    }

    if (m_reqTrans <= 0)
    {
        NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_SNS_SERVER, pOnline->GetLogicId(), proto_ff::NF_STL_QUERY_USER_RSP, rsp);
    }
    else
    {
        NFMessageMgr::Instance()->SendTransToLogicServer(NF_ST_SNS_SERVER, pOnline->GetLogicId(), proto_ff::NF_STL_QUERY_USER_RSP, rsp, 0, m_reqTrans);
    }

    return 0;
}

bool NFTransSnsBase::IsTimeOut() {
    if (NFTime::Now().UnixSec() >= m_dwKeepAliveTime + TRANS_SNS_BASE_TIMEOUT) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "This Trans TimeOut Type:{} Info:{}", GetClassType(), GetDebugInfo());
        OnTimeOut();
        return true;
    }

    return false;
}

int NFTransSnsBase::HandleGetRoleRes(int iRunLogicRetCode, uint64_t roleID) {
    ++m_query.queryed_num;
    if (iRunLogicRetCode && iRunLogicRetCode != proto_ff::ERR_CODE_PLAYER_NOT_EXIST) {
        NFLogError(NF_LOG_SYSTEMLOG, roleID, "get sns role simple info err {} {}", roleID, iRunLogicRetCode);
    }

    if (m_query.query_role.GetSize() <= m_query.queryed_num) {
        int iRetCode = QueryRole_CallBack(m_query);
        SetFinished(iRetCode);
    }

    return 0;
}
