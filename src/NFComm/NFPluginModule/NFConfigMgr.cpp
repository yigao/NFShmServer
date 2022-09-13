// -------------------------------------------------------------------------
//    @FileName         :    NFConfigMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#include "NFConfigMgr.h"

#include "NFIConfigModule.h"

bool NFConfigMgr::Init(NFIConfigModule *pConfigModule) {
    m_pConfigModule = pConfigModule;
    return true;
}

void NFConfigMgr::UnInit() {
    m_pConfigModule = nullptr;
}

NFLogConfig *NFConfigMgr::GetLogConfig() {
    if (m_pConfigModule) {
        return m_pConfigModule->GetLogConfig();
    }
    return nullptr;
}

NFPluginConfig *NFConfigMgr::GetPluginConfig(const std::string &pluginName) {
    if (m_pConfigModule) {
        return m_pConfigModule->GetPluginConfig(pluginName);
    }
    return nullptr;
}

NFServerConfig *NFConfigMgr::GetAppConfig(NF_SERVER_TYPES eServerType) {
    if (m_pConfigModule) {
        return m_pConfigModule->GetAppConfig(eServerType);
    }
    return nullptr;
}

std::string NFConfigMgr::GetGameDbName(NF_SERVER_TYPES eServerType) {
    if (m_pConfigModule) {
        return m_pConfigModule->GetGameDbName(eServerType);
    }
    return std::string();
}

std::string NFConfigMgr::GetDefaultDBName(NF_SERVER_TYPES nfServerTypes)
{
    if (m_pConfigModule) {
        return m_pConfigModule->GetDefaultDBName(nfServerTypes);
    }
    return std::string();
}

std::string NFConfigMgr::GetRedisIp(NF_SERVER_TYPES nfServerTypes)
{
    if (m_pConfigModule) {
        return m_pConfigModule->GetRedisIp(nfServerTypes);
    }
    return std::string();
}

uint32_t NFConfigMgr::GetRedisPort(NF_SERVER_TYPES nfServerTypes)
{
    if (m_pConfigModule) {
        return m_pConfigModule->GetRedisPort(nfServerTypes);
    }
    return 0;
}

std::string NFConfigMgr::GetRedisPass(NF_SERVER_TYPES nfServerTypes)
{
    if (m_pConfigModule) {
        return m_pConfigModule->GetRedisPass(nfServerTypes);
    }
    return std::string();
}

uint32_t NFConfigMgr::GetGameId(NF_SERVER_TYPES eServerType) {
	if (m_pConfigModule) {
		return m_pConfigModule->GetGameId(eServerType);
	}
	return 0;
}

std::vector<uint32_t> NFConfigMgr::GetRoomIdList(NF_SERVER_TYPES eServerType) {
	if (m_pConfigModule) {
		return m_pConfigModule->GetRoomIdList(eServerType);
	}
	return std::vector<uint32_t>();
}


