//
// Created by gaoyi on 2022/9/18.
//

#include "NFGlobalSystem.h"
#include "NFIPluginManager.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFProtobufCommon.h"

#include "NFComm/NFCore/NFServerTime.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFMemTracker.h"
#include "NFComm/NFPluginModule/NFNetInfoPool.h"
#include "NFComm/NFShmCore/NFShmMgr.h"

NFGlobalSystem::NFGlobalSystem() : m_gIsMoreServer(false), m_reloadApp(false), m_serverStopping(false), m_hotfixServer(false)
{
}

NFGlobalSystem::~NFGlobalSystem()
{

}

bool NFGlobalSystem::LoadConfig(const std::string &path)
{
    TryAddPackagePath(path); //Add Search Path to Lua

    std::list<std::string> fileList;
    NFFileUtility::GetFiles(path, fileList, true, "*.lua");

    for (auto it = fileList.begin(); it != fileList.end(); ++it)
    {
        if (TryLoadScriptFile(*it) == false)
        {
            std::cout << "load lua file " << *it << " failed!" << std::endl;
            assert(0);
        }
    }

    NFLuaRef pluginRef = GetGlobal("AllMoreServer");
    if (!pluginRef.isValid())
    {
        std::cout << "can't find the config AllMoreServer" << std::endl;
        assert(0);
    }

    NFProtobufCommon::LuaToProtoMessage(pluginRef, &m_gAllMoreServerConfig);
    std::cout << "all more server config:" << m_gAllMoreServerConfig.DebugString() << std::endl;
    if (m_gAllMoreServerConfig.serverlist_size() <= 0)
    {
        std::cout << "AllMoreServer no server" << std::endl;
        assert(0);
    }

    return true;
}

bool NFGlobalSystem::IsReloadApp() const
{
    return m_reloadApp;
}

void NFGlobalSystem::SetReloadServer(bool reloadApp)
{
    m_reloadApp = reloadApp;
}

bool NFGlobalSystem::IsServerStopping() const
{
    return m_serverStopping;
}

void NFGlobalSystem::SetServerStopping(bool exitApp)
{
    m_serverStopping = exitApp;
}

bool NFGlobalSystem::IsHotfixServer() const
{
    return m_hotfixServer;
}

void NFGlobalSystem::SetHotfixServer(bool hotfixExitApp)
{
    m_hotfixServer = hotfixExitApp;
}

/**
 * @brief 释放singleton资源
 */
void NFGlobalSystem::ReleaseSingleton()
{
    /**
     * @brief 释放网络信息包
     */
    NFNetInfoPool<NFDataPackage>::Instance()->ReleaseInstance();

    NFMemTracker::Instance()->ReleaseInstance();

    NFServerTime::Instance()->ReleaseInstance();
    NFLogMgr::Instance()->ReleaseInstance();
    NFShmMgr::Instance()->ReleaseInstance();
    //最后释放
    NFGlobalSystem::Instance()->ReleaseInstance();
}
