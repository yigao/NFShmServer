// -------------------------------------------------------------------------
//    @FileName         :    NFFishDescStoreEx.h
//    @Author           :    gaoyi
//    @Date             :    23-9-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishDescStoreEx
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"

class NFFishDescStoreEx : public NFIDescStoreEx
{
public:
    NFFishDescStoreEx();

    virtual ~NFFishDescStoreEx();

    int CreateInit();

    int ResumeInit();

private:
IMPL_RES_DESC_EX(NFFishDescStoreEx);
DECLARE_IDCREATE(NFFishDescStoreEx)
};