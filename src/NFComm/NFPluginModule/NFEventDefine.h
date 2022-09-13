// -------------------------------------------------------------------------
//    @FileName         :    NFEventDefine.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFEventObj.h"

enum NFEventDefine
{
	NFEVENT_TEST = 0, //测试事件， 用来测试
	NFEVENT_GM = 1, //GM命令事件
	NFEVENT_LUA_ERROR_LOG = 2, //LUA系统报错
	NFEVENT_LUA_FINISH_LOAD = 3, //LUA系统完成加载

	NFEVENT_MYSQL_UPDATE_MESSAGE = 10, //mysql 数据库 update 操作
};

