// -------------------------------------------------------------------------
//    @FileName         :    NFIWebServerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
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