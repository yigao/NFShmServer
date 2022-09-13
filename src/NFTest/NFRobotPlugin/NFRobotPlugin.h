// -------------------------------------------------------------------------
//    @FileName         :    NFRobotPlugin.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFRobotPlugin.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

//////////////////////////////////////////////////////////////////////////
class NFRobotPlugin : public NFIPlugin
{
public:
    explicit NFRobotPlugin(NFIPluginManager* p):NFIPlugin(p)
    {

    }

    virtual int GetPluginVersion();

    virtual std::string GetPluginName();

    virtual void Install();

    virtual void Uninstall();
};