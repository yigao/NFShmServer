// -------------------------------------------------------------------------
//    @FileName         :    NFWorldPlayer.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldPlayer.cpp
//
// -------------------------------------------------------------------------

#include <NFServerComm/NFServerCommon/NFIServerMessageModule.h>
#include "NFWorldAccount.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFLogicCommon/NFLogicCommon.h"

NFWorldAccount::NFWorldAccount()
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

NFWorldAccount::~NFWorldAccount()
{

}

int NFWorldAccount::CreateInit()
{
    m_uid = 0;
    m_proxyId = 0;
    m_clientId = 0;
    m_status = proto_ff::PLAYER_STATUS_NONE;
    m_createTime = 0;
    m_lastDiconnectTime = 0;
    m_lastLogoutTime = 0;
    m_isDisconnect = false;
    m_cid = 0;
    m_chanId = 0;
    m_bornZid = 0;
    return 0;
}

int NFWorldAccount::ResumeInit()
{
    return 0;
}

uint64_t NFWorldAccount::GetUid() const
{
    return m_uid;
}

void NFWorldAccount::SetUid(uint64_t uid)
{
    m_uid = uid;
}

uint32_t NFWorldAccount::GetProxyId() const
{
    return m_proxyId;
}

void NFWorldAccount::SetProxyId(uint32_t proxyId)
{
    m_proxyId = proxyId;
}

uint64_t NFWorldAccount::GetClientId() const
{
    return m_clientId;
}

void NFWorldAccount::SetClientId(uint64_t clientId)
{
    m_clientId = clientId;
}

proto_ff::enPlayerStatus NFWorldAccount::GetStatus() const
{
    return m_status;
}

void NFWorldAccount::SetStatus(proto_ff::enPlayerStatus status)
{
    m_status = status;
}

uint64_t NFWorldAccount::GetCreateTime() const
{
    return m_createTime;
}

void NFWorldAccount::SetCreateTime(uint64_t createTime)
{
    m_createTime = createTime;
}

uint64_t NFWorldAccount::GetLastDiconnectTime() const
{
    return m_lastDiconnectTime;
}

void NFWorldAccount::SetLastDiconnectTime(uint64_t lastDiconnectTime)
{
    m_lastDiconnectTime = lastDiconnectTime;
}

uint64_t NFWorldAccount::GetLastLogoutTime() const
{
    return m_lastLogoutTime;
}

void NFWorldAccount::SetLastLogoutTime(uint64_t lastLogoutTime)
{
    m_lastLogoutTime = lastLogoutTime;
}

bool NFWorldAccount::IsDisconnect() const
{
    return m_isDisconnect;
}

void NFWorldAccount::SetIsDisconnect(bool isDisconnect)
{
    m_isDisconnect = isDisconnect;
}

uint64_t NFWorldAccount::GetCid() const
{
    return m_cid;
}

void NFWorldAccount::SetCid(uint64_t curCid)
{
    m_cid = curCid;
}

uint32_t NFWorldAccount::GetRoleNum() const
{
    return m_roleSet.size();
}

void NFWorldAccount::AddRoleNum(uint64_t cid)
{
    m_roleSet.insert(cid);
}

bool NFWorldAccount::IsExistCid(uint64_t cid) const
{
    return m_roleSet.find(cid) != m_roleSet.end();
}

void NFWorldAccount::SetChanId(uint32_t chanId)
{
    m_chanId = chanId;
}

uint32_t NFWorldAccount::GetChanId() const
{
    return m_chanId;
}

void NFWorldAccount::SetBornZid(uint32_t bornZid)
{
    m_bornZid = bornZid;
}

uint32_t NFWorldAccount::GetBornZid() const
{
    return m_bornZid;
}

int NFWorldAccount::Tick()
{
    switch (m_status)
    {
        case proto_ff::PLAYER_STATUS_NONE:
        {
            if ((uint64_t)NFTime::Now().UnixSec() - m_createTime < WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            SetStatus(proto_ff::PLAYER_STATUS_LOGOUT);
            SetLastLogoutTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, GetUid(), "uid:{} status:PLAYER_STATUS_NONE change to PLAYER_STATUS_LOGOUT", GetUid());
        }
        break;
        case proto_ff::PLAYER_STATUS_ONLINE:
        {
        }
        break;
        case proto_ff::PLAYER_STATUS_OFFLINE:
        {
            if ((uint64_t)NFTime::Now().UnixSec() - GetLastDiconnectTime() < WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME)
                break;

            SetStatus(proto_ff::PLAYER_STATUS_LOGOUT);
            SetLastLogoutTime(NFTime::Now().UnixSec());
            NFLogInfo(NF_LOG_SYSTEMLOG, GetUid(), "uid:{} status:PLAYER_STATUS_OFFLINE change to PLAYER_STATUS_LOGOUT", GetUid());
        }
            break;
        case proto_ff::PLAYER_STATUS_LOGOUT:
        default:
        {
            if (GetLastLogoutTime() + WORLD_SERVER_PLAYER_CLIENT_DISCONNECT_WAITTIME > (uint64_t)NFTime::Now().UnixSec())
                break;

            SetStatus(proto_ff::PLAYER_STATUS_DEAD);
            NFLogInfo(NF_LOG_SYSTEMLOG, GetUid(), "uid:{} status change to PLAYER_STATUS_DEAD, will be erase from memory", GetUid());
        }
        break;
    }
    return 0;
}

