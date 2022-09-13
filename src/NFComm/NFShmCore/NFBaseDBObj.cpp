// -------------------------------------------------------------------------
//    @FileName         :    NFBaseDBObj.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFBaseDBObj.cpp
//
// -------------------------------------------------------------------------

#include "NFBaseDBObj.h"
#include "NFServerFrameTypeDefines.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFBaseDBObj, EOT_BASE_DB_OBJ, NFShmObj)

NFBaseDBObj::NFBaseDBObj()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
        CreateInit();
    } else {
        ResumeInit();
    }
}

NFBaseDBObj::~NFBaseDBObj()
{

}

int NFBaseDBObj::CreateInit() {
    m_bDataInited = false;
    m_iTransID = 0;
    m_iLastDBOpTime = 0;
    m_uModKey = 0;
    m_iRetryTimes = 0;
    m_bNeedInsertDB = false;
    m_iServerType = NF_ST_NONE;
    return 0;
}

int NFBaseDBObj::ResumeInit() {
    return 0;
}
