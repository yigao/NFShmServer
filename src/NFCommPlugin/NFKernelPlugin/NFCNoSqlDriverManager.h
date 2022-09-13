// -------------------------------------------------------------------------
//    @FileName         :    NFCNosqlDriverManager.h
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFCNosqlDriverManager
//
// -------------------------------------------------------------------------

#pragma once

#include "NFRedisDriver.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"

class NFCNoSqlDriverManager
{
public:
    NFCNoSqlDriverManager();
    virtual ~NFCNoSqlDriverManager();

    virtual bool Execute();

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
    //virtual NF_SHARE_PTR<NFIRedisDriver> GetDriverBySuit(const int nHash);
    virtual bool RemoveConnectSql(const std::string& strID);

protected:
    void CheckConnect();

protected:
    NFConsistentHashMapEx<std::string, NFIRedisDriver> mxNoSqlDriver;
    int mLastCheckTime = 0;
};