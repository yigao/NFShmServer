// -------------------------------------------------------------------------
//    @FileName         :    NFTransCreateUserDetail.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransCreateUserDetail.cpp
//
// -------------------------------------------------------------------------

#include "NFTransLogicUserBase.h"

#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"

#include "NFUserDetail.h"
#include "NFUserDetailMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransLogicUserBase, EOT_TRANS_LOGIC_USER_BASE, NFTransBase)

NFTransLogicUserBase::NFTransLogicUserBase() {
	if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

NFTransLogicUserBase::~NFTransLogicUserBase() {

}

int NFTransLogicUserBase::CreateInit() {
	m_userId = 0;
	m_cmd = 0;
	m_fromBusId = 0;
	m_bHasIncreasedCount = false;
	m_reqTransId = 0;
	return 0;
}

int NFTransLogicUserBase::ResumeInit() {
	return 0;
}

int NFTransLogicUserBase::Init(uint64_t userId, uint32_t cmd, uint32_t fromBusId, uint32_t reqTransId) {
	m_userId = userId;
	m_cmd = cmd;
	m_fromBusId = fromBusId;
	m_reqTransId = reqTransId;

    if (!m_bHasIncreasedCount)
    {
        NFUserDetail * pUser = UserDetail();
        if (pUser)
        {
            pUser->IncreaseTransNum();
            m_bHasIncreasedCount = true;
        }
    }
	return 0;
}

int NFTransLogicUserBase::Init(NFUserDetail* pUser, uint32_t cmd, uint32_t fromBusId, uint32_t reqTransId)
{
	CHECK_NULL(pUser);

	m_userId = pUser->GetUserId();
	m_cmd = cmd;
	m_fromBusId = fromBusId;
	m_reqTransId = reqTransId;

	if (!m_bHasIncreasedCount)
	{
		pUser->IncreaseTransNum();
		m_bHasIncreasedCount = true;
	}
	return 0;
}

NFUserDetail *NFTransLogicUserBase::UserDetail()
{
	NFUserDetail* pUser = NFUserDetailMgr::GetInstance()->GetUser(m_userId);

	return pUser;
}

int NFTransLogicUserBase::OnTimeOut()
{
	NFUserDetail * pUser = UserDetail();
	if (pUser && m_bHasIncreasedCount)
	{
		pUser->DecreaseTransNum();
		m_bHasIncreasedCount = false;
	}

	SetFinished(proto_ff::ERR_CODE_SYSTEM_TIMEOUT);

    NFLogError(NF_LOG_LOGIC_SERVER_PLUGIN, 0, "NFTransLogicUserBase timeout, roleId:{}, cmd:{}, transid:{}",
               m_userId, m_cmd, m_reqTransId);
	return 0;
}

int NFTransLogicUserBase::OnTransFinished(int iRunLogicRetCode)
{
	NFUserDetail * pUser = UserDetail();
	if (!pUser)
	{
		NFLogInfo(NF_LOG_SYSTEMLOG, m_userId, "Get User Detail Failed, this user may off line! cmd:{}", m_cmd);
		return 0;
	}

	if (m_bHasIncreasedCount)
	{
		pUser->DecreaseTransNum();
		m_bHasIncreasedCount = false;
	}

	if (0 == iRunLogicRetCode)
	{
		return 0;
	}

	NFLogDebug(NF_LOG_SYSTEMLOG, pUser->GetUserId(), "user:{} failed errcode={}, msgid={} globalid={} classtype:{}", pUser->GetUserId(), iRunLogicRetCode, m_cmd, GetGlobalID(), GetClassType());

	if (0 == m_cmd)
	{
		NFLogError(NF_LOG_SYSTEMLOG, pUser->GetUserId(),
			"Server should not call this function because request head uninitialized, userId:{}!", pUser->GetUserId());

		return -1;
	}

    if (iRunLogicRetCode && iRunLogicRetCode != -1) {
        NFUserDetail *pUserDetail = NFUserDetailMgr::GetInstance()->GetUser(m_userId);
        if (pUserDetail)
        {
            pUserDetail->SendErrToClient(m_cmd, (proto_ff::Proto_CS_ErrorCode)iRunLogicRetCode);
        }
    }

	return 0;
}