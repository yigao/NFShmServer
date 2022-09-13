// -------------------------------------------------------------------------
//    @FileName         :    NFLoginEventDisp.cpp.c
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
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
