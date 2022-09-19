// -------------------------------------------------------------------------
//    @FileName         :    NFConfigDefine.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include <unordered_map>
#include "NFComm/NFKernelMessage/proto_common_s.h"

#define DEFINE_LUA_STRING_LOAD_PLUGIN			"LoadPlugin"
#define DEFINE_LUA_STRING_SERVER_PLUGINS		"ServerPlugins"

#define DEFINE_LUA_STRING_LOG_LEVEL				"LogLevel"					//log等级配置
#define DEFINE_LUA_STRING_LOG_FLUSH_LEVEL		"LogFlushLevel"				//log刷新等级配置

#define DEFINE_LUA_STRING_LOG_INFO				"LogInfo"			//log配置

enum EnumLogInfoLuaString
{
	LOG_INFO_LOG_ID = 0,
	LOG_INFO_DISPLAY = 1,
	LOG_INFO_LEVEL = 2,
	LOG_INFO_LOG_NAME = 3,
	LOG_INFO_LOG_GUID = 4,
};

typedef proto_ff_s::pbPluginConfig_s NFPluginConfig;

struct NFLogConfig
{
	NFLogConfig()
	{
		Clear();
	}

	void Clear()
	{
		mLogLevel = 0;
		mLogFlushLevel = 0;
		mLineConfigList.clear();
	}

	uint32_t mLogLevel;
	uint32_t mLogFlushLevel;
	std::vector<LogInfoConfig> mLineConfigList;
};

struct NFServerConfig : public proto_ff_s::pbNFServerConfig_s
{
public:
	NFServerConfig()
	{

	}

	virtual void read_from_pbmsg(const ::proto_ff::pbNFServerConfig & msg) override
	{
		proto_ff_s::pbNFServerConfig_s::read_from_pbmsg(msg);
		for(int i = 0; i < (int)TBConfList.size(); i++)
        {
            struct proto_ff_s::pbTableConfig_s& tableConfig = TBConfList[i];
            mTBConfMap.emplace(tableConfig.TableName, tableConfig.TableCount);
        }
	}

    std::unordered_map<std::string, uint32_t> mTBConfMap;
};
