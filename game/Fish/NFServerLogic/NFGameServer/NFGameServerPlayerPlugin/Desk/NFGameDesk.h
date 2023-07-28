// -------------------------------------------------------------------------
//    @FileName         :    NFGameDesc.h
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameDesc
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFGameDesk : public NFShmObj
{
public:
    NFGameDesk();

    virtual ~NFGameDesk();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFGameDesk)
};