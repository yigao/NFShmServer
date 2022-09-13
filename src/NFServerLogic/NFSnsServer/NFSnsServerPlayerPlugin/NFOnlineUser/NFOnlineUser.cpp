// -------------------------------------------------------------------------
//    @FileName         :    NFOnlineUser.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFOnlineUser.cpp
//
// -------------------------------------------------------------------------

#include "NFOnlineUser.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFUserSimple/NFSnsUserSimpleUtil.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFOnlineUser, EOT_SNS_ONLINE_USER_ID, NFShmObj)

NFOnlineUser::NFOnlineUser() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFOnlineUser::~NFOnlineUser() {
    if (m_validPlayerTimer != INVALID_ID)
    {
        DeleteTimer(m_validPlayerTimer);
        m_validPlayerTimer = INVALID_ID;
    }
}

int NFOnlineUser::CreateInit() {
	m_logicSvrId = 0;
	m_llUserID = 0;
	m_ulLastLoginTime = 0;
	m_ulLastLogoutTime = 0;
	m_gameId = 0;
	m_roomId = 0;
	m_gameBusId = 0;
    m_validPlayerTimer = INVALID_ID;
    m_validPlayerTimer = SetTimer(15*60*1000, 1, 0, 15, 0, 0);
    return 0;
}

int NFOnlineUser::ResumeInit() {
    return 0;
}

int NFOnlineUser::GetHashKey(void *pvKey, int &iKeyLength) {
    *( ( uint64_t * )pvKey ) = m_llUserID;
    iKeyLength = sizeof( m_llUserID );

    return 0;
}

int NFOnlineUser::SetHashKey(const void *pvKey, int iKeyLength) {
    m_llUserID = *( ( uint64_t * )pvKey );
    return 0;
}

int NFOnlineUser::Init(uint64_t ulRoldID, uint32_t logicSvrId, uint64_t ulLastLoginTime, uint64_t ulLastLogoutTime) {
    m_llUserID = ulRoldID;
	m_logicSvrId = logicSvrId;
    m_ulLastLoginTime = ulLastLoginTime;
    m_ulLastLogoutTime = ulLastLogoutTime;
    return 0;
}

int NFOnlineUser::SendErrToClient(uint32_t nMsgId, proto_ff::Proto_CS_ErrorCode errCode)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");

    proto_ff::Proto_CSErrorRsp rspMsg;
    rspMsg.set_user_id(m_llUserID);
    rspMsg.set_req_msg_id(nMsgId);
    rspMsg.set_error(errCode);

    NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_SNS_SERVER, m_logicSvrId, proto_ff::E_CS_ERROR, rspMsg);
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFOnlineUser::SendMsgToLogicServer(uint32_t nMMsgId, const google::protobuf::Message &xData)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    NFMessageMgr::Instance()->SendMsgToLogicServer(NF_ST_SNS_SERVER, m_logicSvrId, nMMsgId, xData);
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

void NFOnlineUser::OnTimer(int timeId, int callcount)
{
    if (m_validPlayerTimer == timeId)
    {
        m_validPlayerTimer = INVALID_ID;

        NFSnsUserSimple*  pUserSimple = NFSnsUserSimpleUtil::GetInstance()->GetRoleSimpe(m_llUserID, false);
        if (pUserSimple)
        {
        }
    }
}
