// -------------------------------------------------------------------------
//    @FileName         :    NFTransWorldSendGetRoleList.h
//    @Author           :    gaoyi
//    @Date             :    23-3-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransWorldSendGetRoleList
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFTransBase.h"

class NFTransWorldGetRoleList : public NFTransBase
{
public:
    NFTransWorldGetRoleList();

    virtual ~NFTransWorldGetRoleList();

    int CreateInit();

    int ResumeInit();
public:
    int Init(uint64_t uid, uint32_t proxyId, uint64_t clientId, uint32_t bornZid);

    int SendGetRoleList();
private:
    uint64_t m_uid;
    uint32_t m_proxyId;
    uint64_t m_clientId;
    uint32_t m_bornZid;
private:
DECLARE_IDCREATE(NFTransWorldGetRoleList)
};