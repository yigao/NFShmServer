// -------------------------------------------------------------------------
//    @FileName         :    NFCNosqlDriverManager.h
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFCNosqlDriverManager
//
// -------------------------------------------------------------------------

#pragma once

#include "NFCommPlugin/NFDBPlugin/NFRedisDriver.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFCommMapEx.hpp"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFCommMap.hpp"

class NFCNosqlDriverManager
{
public:
    NFCNosqlDriverManager();
    virtual ~NFCNosqlDriverManager();
public:
    virtual bool Execute();
public:
    virtual int AddNosqlServer(const std::string& strID, const std::string& strIP);
    virtual int AddNosqlServer(const std::string& strID, const std::string& strIP, const int nPort);
    virtual int AddNosqlServer(const std::string& strID, const std::string& strIP, const int nPort, const std::string& strPass);
public:
    virtual bool Enable();
    virtual bool Busy();
    virtual bool KeepLive();
public:
    void CheckNoSql();
public:
    virtual NFINosqlDriver* GetNosqlDriver(const std::string& strID);
protected:
    NFCommMap<std::string, NFINosqlDriver> mxNoSqlDriver;
    int mLastCheckTime = 0;
};