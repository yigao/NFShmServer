// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeZuanTou.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeZuanTou
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"

class NFFishTypeZuanTou : public NFFishTypeHandler
{
public:
    NFFishTypeZuanTou();

    virtual ~NFFishTypeZuanTou();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFFishTypeZuanTou)
};