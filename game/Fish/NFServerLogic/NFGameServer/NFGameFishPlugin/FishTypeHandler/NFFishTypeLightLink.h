// -------------------------------------------------------------------------
//    @FileName         :    NFFishTypeLightLink.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishTypeLightLink
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFFishTypeHandler.h"

class NFFishTypeLightLink : public NFFishTypeHandler
{
public:
    NFFishTypeLightLink();

    virtual ~NFFishTypeLightLink();

    int CreateInit();

    int ResumeInit();

private:
DECLARE_IDCREATE(NFFishTypeLightLink)
};