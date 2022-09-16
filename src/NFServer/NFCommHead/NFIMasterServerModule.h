// -------------------------------------------------------------------------
//    @FileName         :    NFIGameServerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFServerCommon
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFServerComm/NFServerCore/NFServerCommonDefine.h"

class NFIMasterServerModule : public NFIDynamicModule
{
NF_MODULE_STATIC_CONST_MODULE_ID(NF_MASTER_SERVER_MODULE_ID);
public:
	NFIMasterServerModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}

	virtual ~NFIMasterServerModule()
	{

	}
};

