// -------------------------------------------------------------------------
//    @FileName         :    NFLoginEventDisp.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
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