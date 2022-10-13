// -------------------------------------------------------------------------
//    @FileName         :    NFLogMgr.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFKernelMessage/proto_common.pb.h"
#include "NFILuaModule.h"
#include <vector>

class NFIPluginManager;

class NFGlobalSystem : public NFSingleton<NFGlobalSystem>, public NFILuaModule
{
public:
    NFGlobalSystem();

    virtual ~NFGlobalSystem();

public:
    bool LoadConfig(const std::string &path);
public:
    /*
     * reload server 重新加载服务器的配置数据
     * */
    bool IsReloadApp() const;

    /*
     * reload server 重新加载服务器的配置数据
     * */
    void SetReloadServer(bool reloadApp);

    /*
     * stop server，停服，意味着需要保存该保存的数据，共享内存可能后面会被清理，服务器会走正常的停服流程
     * */
    bool IsServerStopping() const;

    /*
     * stop server，停服，意味着需要保存该保存的数据，共享内存可能后面会被清理，服务器会走正常的停服流程
     * */
    void SetServerStopping(bool exitApp);

    /*
     * 热更退出app, 用于服务器需要热更app代码的情况，这时候会杀掉正在运行的的的app,重启新的服务器app
     * */
    bool IsHotfixServer() const;

    /*
     * 热更退出app, 用于服务器需要热更app代码的情况，这时候会杀掉正在运行的的的app,重启新的服务器app
     * */
    void SetHotfixServer(bool hotfixExitApp);
public:
    /**
     * @brief 释放singleton资源
     */
    void ReleaseSingleton();
private:
    bool m_gIsMoreServer;
    NFIPluginManager *m_gGlobalPluginManager;
    std::vector<NFIPluginManager *> m_gGlobalPluginManagerList;
    proto_ff::pbPluginConfig m_gAllMoreServerConfig;
    bool m_reloadApp;
    bool m_serverStopping;
    bool m_hotfixServer;
public:
    bool IsMoreServer() const
    {
        return m_gIsMoreServer;
    }

    void SetMoreServer(bool isMoreServer)
    {
        m_gIsMoreServer = isMoreServer;
    }

    NFIPluginManager *GetGlobalPluginManager() const
    {
        return m_gGlobalPluginManager;
    }

    void SetGlobalPluginManager(NFIPluginManager *pPluginManager)
    {
        m_gGlobalPluginManager = pPluginManager;
    }

    void AddPluginManager(NFIPluginManager *pPluginManager)
    {
        m_gGlobalPluginManagerList.push_back(pPluginManager);
    }

    std::vector<NFIPluginManager *> GetPluginManagerList()
    {
        return m_gGlobalPluginManagerList;
    }

    const proto_ff::pbPluginConfig *GetAllMoreServerConfig() const
    {
        return &m_gAllMoreServerConfig;
    }
};