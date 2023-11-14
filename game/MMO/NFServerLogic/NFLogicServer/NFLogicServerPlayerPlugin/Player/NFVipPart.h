// -------------------------------------------------------------------------
//    @FileName         :    NFVipPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFVipPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFVipPart : public NFShmObjTemplate<NFVipPart, EOT_LOGIC_PART_ID+PART_VIP, NFPart>
{
public:
    NFVipPart();

    virtual ~NFVipPart();

    int CreateInit();

    int ResumeInit();
public:
    void DoAttrChange(uint32_t ANum, int64_t nValue, int64_t attrValue, SCommonSource* pSource) {}
    int32_t PrivilegeVal(int32_t privilegeType)	{ return 0; }							//获得通用整数参数总和
};