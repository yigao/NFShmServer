// -------------------------------------------------------------------------
//    @FileName         :    NFMapAddr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-23
//    @Email			:    445267987@qq.com
//    @Module           :    NFMapAddr
//
// -------------------------------------------------------------------------

#include "NFMapAddr.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

NFMapAddr::NFMapAddr() {
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFMapAddr::~NFMapAddr() {
}

int NFMapAddr::CreateInit()
{
    m_mapId = 0;
    return 0;
}

int NFMapAddr::ResumeInit() {
    return 0;
}
