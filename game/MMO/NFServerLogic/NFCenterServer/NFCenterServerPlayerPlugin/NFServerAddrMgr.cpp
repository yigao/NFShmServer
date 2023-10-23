// -------------------------------------------------------------------------
//    @FileName         :    NFMapAddrMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-23
//    @Email			:    445267987@qq.com
//    @Module           :    NFMapAddrMgr
//
// -------------------------------------------------------------------------

#include "NFServerAddrMgr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFServerAddrMgr, EOT_NFMapAddrMgr_ID, NFShmObj)

NFServerAddrMgr::NFServerAddrMgr() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFServerAddrMgr::~NFServerAddrMgr() {
}

int NFServerAddrMgr::CreateInit() {
    return 0;
}

int NFServerAddrMgr::ResumeInit() {
    return 0;
}
