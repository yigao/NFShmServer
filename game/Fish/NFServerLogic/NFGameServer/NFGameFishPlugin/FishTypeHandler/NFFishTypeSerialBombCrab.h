// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeSerialBombCrab.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeSerialBombCrab
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"

class NFFishTypeSerialBombCrab : public NFFishTypeHandler
{
public:
    NFFishTypeSerialBombCrab();

    virtual ~NFFishTypeSerialBombCrab();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFFishTypeSerialBombCrab)
};