// -------------------------------------------------------------------------
//    @FileName         :    NFISnsServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFISnsServerModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFWorkServerModule.h"


class NFISnsServerModule : public NFWorkServerModule
{
public:
    NFISnsServerModule(NFIPluginManager* p) :NFWorkServerModule(p, NF_ST_SNS_SERVER)
    {

    }

    virtual ~NFISnsServerModule()
    {

    }
};