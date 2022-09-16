// -------------------------------------------------------------------------
//    @FileName         :    NFIProxyServerModule.h
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

class NFIProxyServerModule : public NFIDynamicModule
{
NF_MODULE_STATIC_CONST_MODULE_ID(NF_PROXY_SERVER_MODULE_ID)
public:	
	NFIProxyServerModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}

	virtual ~NFIProxyServerModule()
	{
		
	}
};
