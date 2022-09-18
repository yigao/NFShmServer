// -------------------------------------------------------------------------
//    @FileName         :    NFWebServerLogicPlugin.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWebServerLogicPlugin.h
//
// -------------------------------------------------------------------------


#pragma once

#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include <string>

//////////////////////////////////////////////////////////////////////////
class NFWebServerLogicPlugin : public NFIPlugin
{
public:
    explicit NFWebServerLogicPlugin(NFIPluginManager* p):NFIPlugin(p)
    {
    }

    virtual int GetPluginVersion() override;

    virtual std::string GetPluginName() override;

    virtual void Install() override;

    virtual void Uninstall() override;
};

