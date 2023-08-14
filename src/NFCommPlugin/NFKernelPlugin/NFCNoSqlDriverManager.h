// -------------------------------------------------------------------------
//    @FileName         :    NFCNosqlDriverManager.h
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFCNosqlDriverManager
//
// -------------------------------------------------------------------------

#pragma once

#include "NFRedisDriver.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFMap.hpp"

class NFCNoSqlDriverManager
{
public:
    NFCNoSqlDriverManager();
    virtual ~NFCNoSqlDriverManager();
public:
    virtual bool Execute();
public:
    virtual int AddNoSqlServer(const std::string& strID, const std::string& strIP);
    virtual int AddNoSqlServer(const std::string& strID, const std::string& strIP, const int nPort);
    virtual int AddNoSqlServer(const std::string& strID, const std::string& strIP, const int nPort, const std::string& strPass);
public:
    virtual bool Enable();
    virtual bool Busy();
    virtual bool KeepLive();
public:
    void CheckNoSql();
public:
    virtual NFIRedisDriver* GetNosqlDriver(const std::string& strID);
protected:
    NFMap<std::string, NFIRedisDriver> mxNoSqlDriver;
    int mLastCheckTime = 0;
};