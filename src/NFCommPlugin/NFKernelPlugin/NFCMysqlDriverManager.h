// -------------------------------------------------------------------------
//    @FileName         :    NFCMysqlDriverManager.h
//    @Author           :    Chuanbo.Guo
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFCMysqlDriverManager
//
// -------------------------------------------------------------------------

#pragma once

#include "NFCMysqlDriver.h"
#include <NFComm/NFCore/NFMap.hpp>

class NFCMysqlDriverManager
{
public:
	NFCMysqlDriverManager();

	virtual ~NFCMysqlDriverManager();

	/**
	 * @brief
	 *
	 * @param  nServerID
	 * @param  strIP
	 * @param  nPort
	 * @param  strDBName
	 * @param  strDBUser
	 * @param  strDBPwd
	 * @param  nRconnectTime
	 * @param  nRconneCount
	 * @return bool 
	 */
	int AddMysqlServer(const std::string& serverID, const std::string& strIP, int nPort, std::string strDBName,
	                    std::string strDBUser, std::string strDBPwd, int nRconnectTime/* = 10*/,
	                    int nRconneCount/* = -1*/);

	/**
	 * @brief
	 *
	 * @return NFIMysqlDriver* 
	 */
    NFCMysqlDriver* GetMysqlDriver(const std::string& serverID);

	/**
	 * @brief
	 *
	 * @return void 
	 */
	void CheckMysql() ;
protected:
	NFMap<std::string, NFCMysqlDriver> mvMysql;
	NFMap<std::string, NFCMysqlDriver> mvInvalidMsyql;
	uint64_t mnLastCheckTime;
};
