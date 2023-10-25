// -------------------------------------------------------------------------
//    @FileName         :    NFRankPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFRankPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFRankDefine.h"

class NFRankPart : public NFPart
{
public:
    NFRankPart();

    virtual ~NFRankPart();

    int CreateInit();

    int ResumeInit();
public:
    //发送数值到中心服更新排行榜
    void UpdateRank(enRankType rankType, uint64_t value) { }
private:
DECLARE_IDCREATE(NFRankPart)
};