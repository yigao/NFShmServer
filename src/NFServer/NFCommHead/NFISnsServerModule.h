// -------------------------------------------------------------------------
//    @FileName         :    NFISnsServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
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