// -------------------------------------------------------------------------
//    @FileName         :    NFIAsyMysqlModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :   2022-09-18
//    @Module           :    NFIAsyMysqlModule
//
//
// -------------------------------------------------------------------------

#pragma once

#include "NFIAsySqlModule.h"

#include <vector>
#include <functional>

class NFIAsyDBModule
	: public NFIAsySqlModule
{
public:
	NFIAsyDBModule(NFIPluginManager* p) : NFIAsySqlModule(p)
	{

	}

	virtual ~NFIAsyDBModule()
	{

	}
	
	/**
	 * @brief 添加Mysql链接
	 *
	 * @param  nServerID			ID
	 * @param  strIP				IP地址
	 * @param  nPort				端口
	 * @param  strDBName			数据库名字
	 * @param  strDBUser			数据库用户名
	 * @param  strDBPwd				数据库密码
	 * @param  nRconnectTime		重连间隔
	 * @param  nRconneCount			重连次数
	 * @return bool					成功或失败
	 */
	virtual int AddDBServer(const std::string& nServerID, const std::string &strIP, int nPort, std::string strDBName,
                            std::string strDBUser, std::string strDBPwd, const std::string& noSqlIp, int nNosqlPort, const std::string& noSqlPass, int nRconnectTime = 10,
                            int nRconneCount = -1) = 0;
};
