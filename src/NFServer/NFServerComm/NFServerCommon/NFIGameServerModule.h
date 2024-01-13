// -------------------------------------------------------------------------
//    @FileName         :    NFIGameServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFServerCommon
//
// -------------------------------------------------------------------------

#pragma once

#include "NFWorkServerModule.h"

class NFIGameServerModule : public NFWorkServerModule
{
public:
    NFIGameServerModule(NFIPluginManager* p) :NFWorkServerModule(p, NF_ST_GAME_SERVER)
    {

    }

    virtual ~NFIGameServerModule()
    {

    }
};
