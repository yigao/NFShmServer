// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeSomeZuanTou.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeSomeZuanTou
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"

class NFFishTypeSomeZuanTou : public NFFishTypeHandler
{
public:
    NFFishTypeSomeZuanTou();

    virtual ~NFFishTypeSomeZuanTou();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFFishTypeSomeZuanTou)
};