// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeHaiWangCrab.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeHaiWangCrab
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"

class NFFishTypeHaiWangCrab : public NFFishTypeHandler
{
public:
    NFFishTypeHaiWangCrab();

    virtual ~NFFishTypeHaiWangCrab();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFFishTypeHaiWangCrab)
};