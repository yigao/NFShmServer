// -------------------------------------------------------------------------
//    @FileName         :    NFILuaScriptModule.h
//    @Author           :    GaoYi
//    @Date             :    2018/05/25
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include <vector>
#include <map>
#include <memory>

#include "NFITimerModule.h"
#include "NFServerDefine.h"
#include "NFIDynamicModule.h"

class NFILuaScriptModule : public NFIDynamicModule
{
public:
	NFILuaScriptModule(NFIPluginManager* pPluginManager) : NFIDynamicModule(pPluginManager)
    {

    }

    virtual ~NFILuaScriptModule()
    {

    }

public:
	virtual void SessionReport(uint64_t playerId, const std::string& report) = 0;
	virtual void SessionClose(uint64_t playerId) = 0;

	virtual void ReloadAllLuaFiles() = 0;
	virtual void ReloadLuaFiles() = 0;

	virtual void ReloadLuaFiles(const std::vector<std::string>& vecStr) = 0;

	virtual void RunGmFunction(const std::string& luaFunc, const std::vector<std::string>& vecStr) = 0;
};

