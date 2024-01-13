// -------------------------------------------------------------------------
//    @FileName         :    NFIGameServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFServerCommon
//
// -------------------------------------------------------------------------

#pragma once

#include <NFComm/NFPluginModule/NFServerDefine.h>
#include "NFWorkServerModule.h"

class NFIWorldServerModule : public NFWorkServerModule
{
public:
    NFIWorldServerModule(NFIPluginManager *p) : NFWorkServerModule(p, NF_ST_WORLD_SERVER)
    {

    }

    virtual ~NFIWorldServerModule()
    {

    }
};

