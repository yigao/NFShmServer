// -------------------------------------------------------------------------
//    @FileName         :    NFIUserDetailModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFIUserDetailModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFIUserDetailModule : public NFIDynamicModule
{
public:
    NFIUserDetailModule(NFIPluginManager* p) :NFIDynamicModule(p)
    {

    }

    virtual ~NFIUserDetailModule()
    {

    }
};
