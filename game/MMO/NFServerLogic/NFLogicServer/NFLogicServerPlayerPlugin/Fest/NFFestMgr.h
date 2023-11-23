// -------------------------------------------------------------------------
//    @FileName         :    NFFestMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-11-23
//    @Email			:    445267987@qq.com
//    @Module           :    NFFestMgr
//
// -------------------------------------------------------------------------

#pragma once

#include <ObService/NFLogicObService.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"

class NFFestMgr : NFShmObjTemplate<NFFestMgr, EOT_LOGIC_SERVICE_ID+LOGIC_OB_SERVICE_FEST, NFLogicObService>
{
public:
    NFFestMgr();
    
    virtual ~NFFestMgr();
    
    int CreateInit();
    int ResumeInit();
public:
    virtual int OnTimer(int timeId, int callcount);
    int OnCheckTimer();
private:
    uint64_t m_lasttime;//最近一次检查日期类活动状态的时间
    int m_checkTimer;
};