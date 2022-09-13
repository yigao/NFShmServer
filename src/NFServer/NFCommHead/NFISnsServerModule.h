// -------------------------------------------------------------------------
//    @FileName         :    NFISnsServerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFISnsServerModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFISnsServerModule : public NFIDynamicModule
{
public:
    NFISnsServerModule(NFIPluginManager* p) :NFIDynamicModule(p)
    {

    }

    virtual ~NFISnsServerModule()
    {

    }
};