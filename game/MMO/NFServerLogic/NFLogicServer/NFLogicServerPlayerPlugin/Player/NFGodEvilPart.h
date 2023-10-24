// -------------------------------------------------------------------------
//    @FileName         :    NFGodevilPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFGodevilPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFGodEvilPart : public NFPart
{
public:
    NFGodEvilPart();

    virtual ~NFGodEvilPart();

    int CreateInit();

    int ResumeInit();

public:
    void OnSetExp(int64_t &value) {}

    //处理 增加神魔之息
    void OnAddExp(int64_t &value) {}
private:
DECLARE_IDCREATE(NFGodEvilPart)
};