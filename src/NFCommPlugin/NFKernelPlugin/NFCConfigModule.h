// -------------------------------------------------------------------------
//    @FileName         :    NFCConfigModule.h
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFKernelPlugin
//    @Desc             :
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIConfigModule.h"

#include "NFComm/NFPluginModule/NFILuaModule.h"
#include <string>

class NFCConfigModule : public NFIConfigModule, public NFILuaModule
{
public:
	explicit NFCConfigModule(NFIPluginManager* p);

	virtual ~NFCConfigModule();

	bool BeforeShut() override;
	bool Shut() override;
	bool Finalize() override;
	bool Execute() override;
	bool OnReloadPlugin() override;

	virtual bool LoadConfig() override;
public:
	
	bool LoadPluginConfig();
	bool LoadServerConfig();
	bool LoadLogConfig();
	bool CheckConfig();
public:
	NFPluginConfig* GetPluginConfig(const std::string& pluginName) override;
	NFLogConfig* GetLogConfig() override;
public:
    virtual NFServerConfig* GetServerConfig(NF_SERVER_TYPES eServerType) override;
    virtual NFServerConfig* GetAppConfig(NF_SERVER_TYPES eServerType) override;
    virtual std::string GetGameDbName(NF_SERVER_TYPES nfServerTypes) override;
    virtual std::string GetDefaultDBName(NF_SERVER_TYPES nfServerTypes) override;
    virtual std::string GetRedisIp(NF_SERVER_TYPES nfServerTypes) override;
    virtual uint32_t GetRedisPort(NF_SERVER_TYPES nfServerTypes) override;
    virtual std::string GetRedisPass(NF_SERVER_TYPES nfServerTypes) override;
	virtual uint32_t GetGameId(NF_SERVER_TYPES nfServerTypes) override;
	virtual std::vector<uint32_t> GetRoomIdList(NF_SERVER_TYPES nfServerTypes) override;
protected:
	std::unordered_map<std::string, NFPluginConfig*> mPluginConfig; //pluginName--key
	std::vector<NFServerConfig*> mServerConfig; //serverid--key
    NFServerConfig* m_appConfig;
	NFLogConfig mLogConfig;
};
