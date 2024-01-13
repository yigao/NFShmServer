// -------------------------------------------------------------------------
//    @FileName         :    NFIProxyServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFServerCommon
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFTransMsgServerModule.h"
#include "NFServerComm/NFServerCommon/NFServerCommonDefine.h"

class NFIProxyServerModule : public NFTransMsgServerModule
{
public:
	NFIProxyServerModule(NFIPluginManager* p) :NFTransMsgServerModule(p, NF_ST_PROXY_SERVER)
	{

	}

	virtual ~NFIProxyServerModule()
	{
		
	}

    virtual uint32_t GetClientMsgServer(uint32_t msgId) = 0;
};
