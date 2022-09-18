// -------------------------------------------------------------------------
//    @FileName         :    NFIWebServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
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