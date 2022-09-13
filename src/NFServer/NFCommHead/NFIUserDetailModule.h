// -------------------------------------------------------------------------
//    @FileName         :    NFIUserDetailModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
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
