// -------------------------------------------------------------------------
//    @FileName         :    NFWebServerPlugin.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFWebServerPlugin.h
//
// -------------------------------------------------------------------------


#pragma once

#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include <string>

//////////////////////////////////////////////////////////////////////////
class NFWebServerPlugin : public NFIPlugin
{
public:
    explicit NFWebServerPlugin(NFIPluginManager* p):NFIPlugin(p)
    {
    }

    virtual int GetPluginVersion() override;

    virtual std::string GetPluginName() override;

    virtual void Install() override;

    virtual void Uninstall() override;
};

