// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeFullScrBomb.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeFullScrBomb
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"

class NFFishTypeFullScrBomb : public NFFishTypeHandler
{
public:
    NFFishTypeFullScrBomb();

    virtual ~NFFishTypeFullScrBomb();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFFishTypeFullScrBomb)
};