// -------------------------------------------------------------------------
//    @FileName         :    NFICenterServerModule.h
//    @Author           :    gaoyi
//    @Date             :    23-10-19
//    @Email			:    445267987@qq.com
//    @Module           :    NFICenterServerModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFWorkServerModule.h"

class NFICenterServerModule : public NFWorkServerModule
{
public:
    NFICenterServerModule(NFIPluginManager* p) : NFWorkServerModule(p, NF_ST_CENTER_SERVER)
    {

    }

    virtual ~NFICenterServerModule()
    {

    }
};