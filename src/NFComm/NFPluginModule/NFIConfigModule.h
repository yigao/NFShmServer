// -------------------------------------------------------------------------
//    @FileName         :    NFIConfigModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFIModule.h"

#include "NFIPluginManager.h"
#include "NFServerDefine.h"

#include <unordered_map>
#include <vector>

#include "NFConfigDefine.h"


class NFIConfigModule : public NFIModule
{
public:
	NFIConfigModule(NFIPluginManager* p) :NFIModule(p)
	{

	}

	virtual ~NFIConfigModule()
	{

	}
	
	virtual NFPluginConfig* GetPluginConfig(const std::string& pluginName) = 0;
	virtual NFLogConfig* GetLogConfig() = 0;
	virtual bool LoadConfig() = 0;
    virtual NFServerConfig* GetServerConfig(NF_SERVER_TYPES eServerType) = 0;
    virtual NFServerConfig* GetAppConfig(NF_SERVER_TYPES eServerType) = 0;
    virtual std::string GetDefaultDBName(NF_SERVER_TYPES nfServerTypes) = 0;
    virtual std::string GetRedisIp(NF_SERVER_TYPES nfServerTypes) = 0;
    virtual uint32_t GetRedisPort(NF_SERVER_TYPES nfServerTypes) = 0;
    virtual std::string GetRedisPass(NF_SERVER_TYPES nfServerTypes) = 0;
};
