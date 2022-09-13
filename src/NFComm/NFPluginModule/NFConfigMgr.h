// -------------------------------------------------------------------------
//    @FileName         :    NFConfigMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFSingleton.hpp"

#include <unordered_map>
#include <vector>

#include "NFIConfigModule.h"

class _NFExport NFConfigMgr : public NFSingleton<NFConfigMgr>
{
public:
	NFConfigMgr()
	{
		m_pConfigModule = nullptr;
	}

	virtual ~NFConfigMgr()
	{

	}

	bool Init(NFIConfigModule* pConfigModule = nullptr);
	void UnInit();

	virtual NFPluginConfig* GetPluginConfig(const std::string& pluginName);
	virtual NFLogConfig* GetLogConfig();
    virtual NFServerConfig* GetAppConfig(NF_SERVER_TYPES eServerType);
    virtual std::string GetGameDbName(NF_SERVER_TYPES nfServerTypes);
    virtual std::string GetDefaultDBName(NF_SERVER_TYPES nfServerTypes);
	virtual uint32_t GetGameId(NF_SERVER_TYPES nfServerTypes);
	virtual std::vector<uint32_t> GetRoomIdList(NF_SERVER_TYPES nfServerTypes);
    virtual std::string GetRedisIp(NF_SERVER_TYPES nfServerTypes);
    virtual uint32_t GetRedisPort(NF_SERVER_TYPES nfServerTypes);
    virtual std::string GetRedisPass(NF_SERVER_TYPES nfServerTypes);
protected:
	NFIConfigModule* m_pConfigModule;
};

