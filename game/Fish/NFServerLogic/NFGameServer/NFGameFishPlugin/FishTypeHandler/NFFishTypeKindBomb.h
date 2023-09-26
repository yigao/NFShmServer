// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeKindBomb.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeKindBomb
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"

class NFFishTypeKindBomb : public NFFishTypeHandler
{
public:
    NFFishTypeKindBomb();

    virtual ~NFFishTypeKindBomb();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFFishTypeKindBomb)
};