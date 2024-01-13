// -------------------------------------------------------------------------
//    @FileName         :    NFIWebServerModule.h
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFIWebServerModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFWorkServerModule.h"

class NFIWebServerModule : public NFWorkServerModule
{
public:
    NFIWebServerModule(NFIPluginManager* p) :NFWorkServerModule(p,NF_ST_WEB_SERVER)
    {

    }

    virtual ~NFIWebServerModule()
    {

    }
};