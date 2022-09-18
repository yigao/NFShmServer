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
    bool LoadConfig(const std::string& path);
private:
    bool m_gIsMoreServer;
    NFIPluginManager* m_gGlobalPluginManager;
    std::vector<NFIPluginManager*> m_gGlobalPluginManagerList;
    proto_ff::pbPluginConfig m_gAllMoreServerConfig;
public:
    bool IsMoreServer() const {
        return m_gIsMoreServer;
    }

    void SetMoreServer(bool isMoreServer) {
        m_gIsMoreServer = isMoreServer;
    }

    NFIPluginManager* GetGlobalPluginManager() const {
        return m_gGlobalPluginManager;
    }

    void SetGlobalPluginManager(NFIPluginManager* pPluginManager) {
        m_gGlobalPluginManager = pPluginManager;
    }

    void AddPluginManager(NFIPluginManager* pPluginManager) {
        m_gGlobalPluginManagerList.push_back(pPluginManager);
    }

    std::vector<NFIPluginManager*> GetPluginManagerList() {
        return m_gGlobalPluginManagerList;
    }

    const proto_ff::pbPluginConfig* GetAllMoreServerConfig() const {
        return &m_gAllMoreServerConfig;
    }
};