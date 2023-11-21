// -------------------------------------------------------------------------
//    @FileName         :    NFSnsRelationMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-11-16
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsRelationMgr
//
// -------------------------------------------------------------------------

#pragma once

#include <ComDefine.pb.h>
#include <NFLogicCommon/NFCharactorDefine.h>
#include <ObService/NFSnsObService.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"

class NFSnsRelationMgr : public NFShmObjTemplate<NFSnsRelationMgr, EOT_SNS_SERVICE_ID+SNS_OB_SERVICE_RELATION, NFSnsObService>
{
public:
    NFSnsRelationMgr();

    virtual ~NFSnsRelationMgr();

    int CreateInit();
    int ResumeInit();

    //是否是黑名单
    bool IsInBlack(CharIDType srcID, CharIDType dstID) { return false; }
    //是否是好友关系
    bool IsFriendRelation(CharIDType srcID, CharIDType dstID) { return true; }
    //添加最近联系人
    proto_ff::ERetCode UpdateRecentList(CharIDType srcID, CharIDType dstID, uint32_t type) { return proto_ff::RET_SUCCESS; }
};
