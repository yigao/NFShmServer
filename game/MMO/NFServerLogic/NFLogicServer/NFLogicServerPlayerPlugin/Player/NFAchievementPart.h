// -------------------------------------------------------------------------
//    @FileName         :    NFAchievementPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFAchievementPart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

class NFAchievementPart : public NFPart
{
public:
    NFAchievementPart();
    
    virtual ~NFAchievementPart();
    
    int CreateInit();
    
    int ResumeInit();
public:
public:
    void OnCommonAddNum(int32_t num, int32_t eventType) {}
    void OnCommonAddNum(int32_t num, int32_t param1, int32_t eventType) {}
    void OnCommonAddNumWithLess(int32_t num, int32_t param1, int32_t eventType) {}
    void OnCommonAddNumWithLess(int32_t num, int32_t param1, int32_t param2, int32_t eventType) {}
    void OnCommonAddNumWithLess(int32_t num, int32_t param1, int32_t param2, int32_t param3, int32_t eventType) {}
    void OnCommonFinishNum(int32_t num, int32_t eventType) {}
    void OnCommonFinishNum(int32_t num, int32_t param, int32_t eventType) {}
    void OnCommonFinishNum(int32_t num, int32_t param1, int32_t param2, int32_t eventType) {}
    void OnCommonFinishNum(int32_t num, int32_t param1, int32_t param2, int32_t param3, int32_t eventType) {}
    void OnCommonFinishNumWithLess(int32_t num, int32_t param, int32_t eventType) {}
    void OnCommonFinishNumWithLess(int32_t num, int32_t param1, int32_t param2, int32_t eventType) {}
    void OnCommonFinishNumWithLess(int32_t num, int32_t param1, int32_t param2, int param3, int32_t eventType) {}
    void OnCommonClear(int32_t eventType) {}
private:
DECLARE_IDCREATE(NFAchievementPart)
};