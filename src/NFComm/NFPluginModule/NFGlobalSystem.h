// -------------------------------------------------------------------------
//    @FileName         :    NFLogMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFSingleton.hpp"

class NFGlobalSystem : public NFSingleton<NFGlobalSystem>
{
public:
    NFGlobalSystem();

    virtual ~NFGlobalSystem();
private:
    bool m_gIsMoreServer;
public:
    bool IsMoreServer() const {
        return m_gIsMoreServer;
    }

    void SetMoreServer(bool isMoreServer) {
        m_gIsMoreServer = isMoreServer;
    }
};