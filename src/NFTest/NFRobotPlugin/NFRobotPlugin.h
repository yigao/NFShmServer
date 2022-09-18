// -------------------------------------------------------------------------
//    @FileName         :    NFRobotPlugin.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
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