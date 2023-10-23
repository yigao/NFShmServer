// -------------------------------------------------------------------------
//    @FileName         :    NFMMOCenterPlayerPlugin.h
//    @Author           :    gaoyi
//    @Date             :    23-10-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFMMOCenterPlayerPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include <string>

//////////////////////////////////////////////////////////////////////////
class NFMMOCenterPlayerPlugin : public NFIPlugin
{
public:
    explicit NFMMOCenterPlayerPlugin(NFIPluginManager* p): NFIPlugin(p)
    {
    }

    virtual int GetPluginVersion() override;

    virtual std::string GetPluginName() override;

    virtual void Install() override;

    virtual void Uninstall() override;

    virtual bool InitShmObjectRegister() override;
};

