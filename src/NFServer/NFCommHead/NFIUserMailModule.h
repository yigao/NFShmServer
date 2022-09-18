// -------------------------------------------------------------------------
//    @FileName         :    NFIUserMailModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFIUserMailModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFIUserMailModule : public NFIDynamicModule
{
public:
    NFIUserMailModule(NFIPluginManager* p) : NFIDynamicModule(p)
    {

    }

    virtual ~NFIUserMailModule()
    {

    }
};
