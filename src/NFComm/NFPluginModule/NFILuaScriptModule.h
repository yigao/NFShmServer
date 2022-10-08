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

class NFILuaScriptModule : public NFIModule
{
public:
	NFILuaScriptModule(NFIPluginManager* pPluginManager) : NFIModule(pPluginManager)
    {

    }

    virtual ~NFILuaScriptModule()
    {

    }

public:
	virtual void RunNetRecvLuaFunc(const std::string& luaFunc, const uint32_t unLinkId, const uint64_t valueId, const uint32_t opreateId, const uint32_t nMsgId, const std::string& strMsg) = 0;
	virtual void RunNetRecvLuaFuncWithMainSub(const std::string& luaFunc, const uint32_t unLinkId, const uint64_t valueId, const uint32_t opreateId, const uint16_t nMainMsgId, const uint16_t nSubMsgId, const std::string& strMsg) = 0;
	virtual void RunHttpRecvLuaFunc(const std::string& luaFunc, const uint32_t unLinkId, const uint32_t requestId, const std::string& firstPath, const std::string& secondPath, const std::string& strMsg) = 0;

	virtual void SessionReport(uint64_t playerId, const std::string& report) = 0;
	virtual void SessionClose(uint64_t playerId) = 0;

	virtual void ReloadAllLuaFiles() = 0;
	virtual void ReloadLuaFiles() = 0;

	virtual void ReloadLuaFiles(const std::vector<std::string>& vecStr) = 0;

	virtual void RunGmFunction(const std::string& luaFunc, const std::vector<std::string>& vecStr) = 0;
};

