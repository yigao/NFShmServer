// -------------------------------------------------------------------------
//    @FileName         :    NFIWebServerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFIWebServerModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFIWebServerModule : public NFIDynamicModule
{
public:
    NFIWebServerModule(NFIPluginManager* p) :NFIDynamicModule(p)
    {

    }

    virtual ~NFIWebServerModule()
    {

    }
};