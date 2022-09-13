// -------------------------------------------------------------------------
//    @FileName         :    NFIGameConfigModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
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
