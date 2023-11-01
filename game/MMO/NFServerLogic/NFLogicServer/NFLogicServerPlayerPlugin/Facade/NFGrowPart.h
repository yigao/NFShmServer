// -------------------------------------------------------------------------
//    @FileName         :    NFGrowPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFGrowPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFGrowPart : public NFShmObjTemplate<NFGrowPart, EOT_LOGIC_PART_ID+PART_GROW, NFPart>
{
public:
    NFGrowPart();

    virtual ~NFGrowPart();

    int CreateInit();

    int ResumeInit();

public:
    /**
     * ����ͷ����Ϣ
     * @param outproto
     */
    virtual void FillHeadProto(proto_ff::RoleHeadPicProto &outproto) { }
};