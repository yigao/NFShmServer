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

int NFMapAddr::AddBusId(uint32_t busId)
{
    if (!IsExist(busId))
    {
        if (m_serverData.size() >= m_serverData.max_size())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "add busId:{} failed, space not entough", busId);
            return -1;
        }

        m_serverData.insert(busId);
    }
    return 0;
}
