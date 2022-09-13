// -------------------------------------------------------------------------
//    @FileName         :    NFGameDeskService.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameDeskService.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmHashMap.h"
#include "NFComm/NFShmCore/NFSubGameTypeDefines.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFServer/NFCommHead/NFIGameDeskHandle.h"

class NFGameDeskService : public NFIGameDeskHandle {
public:
    NFGameDeskService() {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        } else {
            ResumeInit();
        }
    }

    virtual ~NFGameDeskService() {}

    int CreateInit() {
        m_loopStatus = 0;
        m_nNowTimeMark = 0;
        return 0;
    }

    int ResumeInit() {
        return 0;
    }

    virtual int ServerLoop() = 0;
protected:
    uint32_t m_loopStatus;
    uint32_t m_nNowTimeMark;
}