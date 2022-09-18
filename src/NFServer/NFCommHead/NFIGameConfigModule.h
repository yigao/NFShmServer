// -------------------------------------------------------------------------
//    @FileName         :    NFIGameConfigModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFIGameConfigModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFIGameConfigModule : public NFIDynamicModule
{
public:
    NFIGameConfigModule(NFIPluginManager* p) :NFIDynamicModule(p)
    {

    }

    virtual ~NFIGameConfigModule()
    {

    }
};
