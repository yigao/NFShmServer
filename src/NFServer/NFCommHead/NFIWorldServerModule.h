// -------------------------------------------------------------------------
//    @FileName         :    NFIGameServerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFServerCommon
//
// -------------------------------------------------------------------------

#pragma once

#include <NFComm/NFPluginModule/NFServerDefine.h>
#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFCommLogicHead.h"

class NFIWorldServerModule : public NFIDynamicModule
{
public:
	NFIWorldServerModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}

	virtual ~NFIWorldServerModule()
	{

	}
};

