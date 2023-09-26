// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeMadCow.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeMadCow
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"

class NFFishTypeMadCow : public NFFishTypeHandler
{
public:
    NFFishTypeMadCow();

    virtual ~NFFishTypeMadCow();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFFishTypeMadCow)
};