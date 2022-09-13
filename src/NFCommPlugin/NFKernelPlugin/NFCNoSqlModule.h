#pragma once

#include "NFRedisDriver.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFINoSqlModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFCNoSqlDriverManager.h"

class NFCNoSqlModule
	: public NFINoSqlModule
{
public:

	NFCNoSqlModule(NFIPluginManager* p);
	virtual ~NFCNoSqlModule();

	virtual bool Init();
	virtual bool Shut();
	virtual bool Execute();
	virtual bool AfterInit();
	
	virtual bool Connect(const std::string& strIP, const int nPort, const std::string& strPass) { return false; };
	virtual bool Enable();
	virtual bool Busy();
	virtual bool KeepLive();


	virtual bool AddConnectSql(const std::string& strID, const std::string& strIP);
	virtual bool AddConnectSql(const std::string& strID, const std::string& strIP, const int nPort);
	virtual bool AddConnectSql(const std::string& strID, const std::string& strIP, const int nPort, const std::string& strPass);

	virtual std::vector<std::string> GetDriverIdList();
	virtual NF_SHARE_PTR<NFIRedisDriver> GetDriver(const std::string& strID);
	virtual NF_SHARE_PTR<NFIRedisDriver> GetDriverBySuitRandom();
	virtual NF_SHARE_PTR<NFIRedisDriver> GetDriverBySuitConsistent();
	virtual NF_SHARE_PTR<NFIRedisDriver> GetDriverBySuit(const std::string& strHash);
	virtual bool RemoveConnectSql(const std::string& strID);
protected:
    NFCNoSqlDriverManager* m_pNoSqlDriverManager;
};
