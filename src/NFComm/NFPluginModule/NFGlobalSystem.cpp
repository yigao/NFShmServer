//
// Created by gaoyi on 2022/9/18.
//

#include "NFGlobalSystem.h"
#include "NFIPluginManager.h"
#include "NFComm/NFCore/NFFileUtility.h"

NFGlobalSystem::NFGlobalSystem() : m_gIsMoreServer(false) {

}

NFGlobalSystem::~NFGlobalSystem() {

}

bool NFGlobalSystem::LoadConfig(const std::string& path)
{
    TryAddPackagePath(path); //Add Search Path to Lua

    std::list<std::string> fileList;
    NFFileUtility::GetFiles(path, fileList, true, "*.lua");

    for (auto it = fileList.begin(); it != fileList.end(); ++it) {
        if (TryLoadScriptFile(*it) == false) {
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
    std::cout << "all more server config:{}" << m_gAllMoreServerConfig.DebugString() << std::endl;
    if (m_gAllMoreServerConfig.serverlist_size() <= 0)
    {
        std::cout << "AllMoreServer no server" << std::endl;
        assert(0);
    }
}
