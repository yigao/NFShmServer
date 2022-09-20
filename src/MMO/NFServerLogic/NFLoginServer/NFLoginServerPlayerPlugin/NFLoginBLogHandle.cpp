// -------------------------------------------------------------------------
//    @FileName         :    NFLoginBehaviorMgr.cpp.c
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFLoginBehaviorMgr.cpp.c
//
// -------------------------------------------------------------------------

#include "NFLoginBLogHandle.h"
#include "NFComm/NFPluginModule/NFCheck.h"

int NFLoginBLogHandle::AccountRegister(NFAccountLogin *pLogin)
{
    CHECK_NULL(pLogin);
    proto_ff::AccountRegisterFlow flow;
    flow.set_account(pLogin->mAccount.GetString());
    flow.set_result(0);
    NFLogBehavior(NF_ST_LOGIN_SERVER, pLogin->mPlayerId, pLogin->mAccount.GetString(), flow);
    return 0;
}

int NFLoginBLogHandle::AccountLogin(NFAccountLogin *pLogin)
{
    CHECK_NULL(pLogin);
    proto_ff::AccountLoginFlow flow;
    flow.set_account(pLogin->mAccount.GetString());
    flow.set_result(0);
    NFLogBehavior(NF_ST_LOGIN_SERVER, pLogin->mPlayerId, pLogin->mAccount.GetString(), flow);
    return 0;
}
