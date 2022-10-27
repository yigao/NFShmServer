// -------------------------------------------------------------------------
//    @FileName         :    NFILogicServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFILogicServerModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFWorkServerModule.h"

class NFILogicServerModule : public NFWorkServerModule
{
public:
    NFILogicServerModule(NFIPluginManager* p) :NFWorkServerModule(p, NF_ST_LOGIC_SERVER)
    {

    }

    virtual ~NFILogicServerModule()
    {

    }
};