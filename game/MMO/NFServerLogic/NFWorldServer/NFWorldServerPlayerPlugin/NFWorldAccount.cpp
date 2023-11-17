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

    m_cid = 0;
    m_chanId = 0;
    m_bornZid = 0;
    m_timeMulti = 2;
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