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
#include "NFComm/NFPluginModule/NFNetPackagePool.h"
#include "NFComm/NFShmCore/NFShmMgr.h"

NFGlobalSystem::NFGlobalSystem() : m_gIsMoreServer(false), m_reloadApp(false), m_serverStopping(false), m_serverKilling(false), m_hotfixServer(false)
{
    m_gGlobalPluginManager = NULL;
    mSpecialMsgMap.resize(NF_MODULE_MAX);
    for(int i = 0; i < NF_MODULE_MAX; i++)
    {
        mSpecialMsgMap[i].resize(NF_NET_MAX_MSG_ID);
    }
    RegisterSpecialMsg(NF_MODULE_SERVER, proto_ff::NF_SERVER_TO_SERVER_HEART_BEAT);
    RegisterSpecialMsg(NF_MODULE_SERVER, proto_ff::NF_SERVER_TO_SERVER_HEART_BEAT_RSP);
    RegisterSpecialMsg(NF_MODULE_SERVER, proto_ff::NF_SERVER_TO_SERVER_BUS_CONNECT_REQ);
    RegisterSpecialMsg(NF_MODULE_SERVER, proto_ff::NF_SERVER_TO_SERVER_BUS_CONNECT_RSP);
    RegisterSpecialMsg(NF_MODULE_SERVER, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER);
    RegisterSpecialMsg(NF_MODULE_SERVER, proto_ff::NF_MASTER_SERVER_SEND_OTHERS_TO_SERVER);
    RegisterSpecialMsg(NF_MODULE_SERVER, proto_ff::NF_SERVER_TO_MASTER_SERVER_REPORT);
    RegisterSpecialMsg(NF_MODULE_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER);
    RegisterSpecialMsg(NF_MODULE_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER_RSP);
    RegisterSpecialMsg(NF_MODULE_SERVER, proto_ff::NF_SERVER_TO_SERVER_REGISTER);
}

NFGlobalSystem::~NFGlobalSystem()
{
    m_gGlobalPluginManager = NULL;
    m_gGlobalPluginManagerList.clear();
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

/*
 * kill server
 * */
bool NFGlobalSystem::IsServerKilling() const
{
    return m_serverKilling;
}

/*
 * kill server
 * */
void NFGlobalSystem::SetServerKilling(bool exitApp)
{
    m_serverKilling = exitApp;
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
    NFMemTracker::Instance()->ReleaseInstance();

    NFServerTime::Instance()->ReleaseInstance();
    NFLogMgr::Instance()->ReleaseInstance();
    NFShmMgr::Instance()->ReleaseInstance();
    NFProtobufCommon::Instance()->ReleaseInstance();
    //最后释放
    NFGlobalSystem::Instance()->ReleaseInstance();
}

bool NFGlobalSystem::RegisterSpecialMsg(uint32_t moduleId, uint32_t msgId)
{
    CHECK_EXPR(moduleId < NF_MODULE_MAX, false, "");
    CHECK_EXPR(msgId < NF_NET_MAX_MSG_ID, false, "");
    mSpecialMsgMap[moduleId][msgId] = true;
    return true;
}

bool NFGlobalSystem::IsSpecialMsg(uint32_t moduleId, uint32_t msgId)
{
    if (moduleId < NF_MODULE_MAX && msgId < NF_NET_MAX_MSG_ID)
    {
        return mSpecialMsgMap[moduleId][msgId];
    }
    return false;
}