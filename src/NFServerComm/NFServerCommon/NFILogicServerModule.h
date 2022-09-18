// -------------------------------------------------------------------------
//    @FileName         :    NFILogicServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
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