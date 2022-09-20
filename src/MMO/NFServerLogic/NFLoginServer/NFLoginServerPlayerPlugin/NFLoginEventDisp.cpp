// -------------------------------------------------------------------------
//    @FileName         :    NFLoginEventDisp.cpp.c
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoginEventDisp.cpp.c
//
// -------------------------------------------------------------------------

#include "NFLoginEventDisp.h"
#include "NFLoginBLogHandle.h"

int NFLoginEventDisp::AccountRegister(NFAccountLogin *pLogin)
{
    NFLoginBLogHandle::AccountRegister(pLogin);
    return 0;
}

int NFLoginEventDisp::AccountLogin(NFAccountLogin *pLogin)
{
    NFLoginBLogHandle::AccountLogin(pLogin);
    return 0;
}
