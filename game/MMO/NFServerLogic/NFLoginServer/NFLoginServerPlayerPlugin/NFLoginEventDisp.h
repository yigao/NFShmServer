// -------------------------------------------------------------------------
//    @FileName         :    NFLoginEventDisp.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoginEventDisp.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFMessageDefine/proto_svr_behavior.pb.h"
#include "NFAccountLoginMgr.h"

class NFLoginEventDisp
{
public:
    static int AccountRegister(NFAccountLogin* pLogin);
    static int AccountLogin(NFAccountLogin* pLogin);
};