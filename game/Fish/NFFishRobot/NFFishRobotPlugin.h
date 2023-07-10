// -------------------------------------------------------------------------
//    @FileName         :    NFRobotPlugin.h
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFRobotPlugin.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

//////////////////////////////////////////////////////////////////////////
class NFFishRobotPlugin : public NFIPlugin
{
public:
    explicit NFFishRobotPlugin(NFIPluginManager* p):NFIPlugin(p)
    {

    }

    virtual int GetPluginVersion();

    virtual std::string GetPluginName();

    virtual void Install();

    virtual void Uninstall();
};