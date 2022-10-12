// -------------------------------------------------------------------------
//    @FileName         :    NFLoginBehaviorMgr.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoginBehaviorMgr.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFMessageDefine/proto_svr_behavior.pb.h"
#include "NFAccountLoginMgr.h"

class NFLoginBLogHandle
{
public:
    static int AccountRegister(NFAccountLogin* pLogin);
    static int AccountLogin(NFAccountLogin* pLogin);
};