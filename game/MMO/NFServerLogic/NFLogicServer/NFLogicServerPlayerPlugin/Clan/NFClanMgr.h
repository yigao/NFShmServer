// -------------------------------------------------------------------------
//    @FileName         :    NFClanMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFClanMgr
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"

/**
 * \brief 战队管理器
 */
class NFClanMgr : public NFShmObjTemplate<NFClanMgr, EOT_NFClanMgr_ID, NFShmObj>
{
public:
    NFClanMgr();

    virtual ~NFClanMgr();

    int CreateInit();
    int ResumeInit();

public:
    uint64_t GetClan3Id(uint64_t cid) { return 0; } //获得3v3战队ID
    uint64_t GetClan5Id(uint64_t cid) { return 0; } //获得5v5战队ID
};
