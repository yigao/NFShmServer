// -------------------------------------------------------------------------
//    @FileName         :    NFILogicServerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFILogicServerModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFILogicServerModule : public NFIDynamicModule
{
public:
    NFILogicServerModule(NFIPluginManager* p) :NFIDynamicModule(p)
    {

    }

    virtual ~NFILogicServerModule()
    {

    }
};