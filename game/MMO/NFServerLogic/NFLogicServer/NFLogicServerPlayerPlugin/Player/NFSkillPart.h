// -------------------------------------------------------------------------
//    @FileName         :    NFSkillPart.h
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFSkillPart
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "Part/NFPart.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

class NFSkillPart : public NFPart
{
public:
    NFSkillPart();

    virtual ~NFSkillPart();

    int CreateInit();

    int ResumeInit();
public:
    //ÉúÃü¸Ä±ä
    void OnHpChange(int64_t oldHp, int64_t curHp, int64_t maxHp);
private:
DECLARE_IDCREATE(NFSkillPart)
};