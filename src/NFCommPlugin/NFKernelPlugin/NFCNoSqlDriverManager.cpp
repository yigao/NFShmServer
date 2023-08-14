
#include <algorithm>
#include "NFCNoSqlDriverManager.h"
#include "NFComm/NFCore/NFTime.h"

NFCNoSqlDriverManager::NFCNoSqlDriverManager()
{
    mLastCheckTime = 0;
}

NFCNoSqlDriverManager::~NFCNoSqlDriverManager()
{
    for (auto pMysqlDriver = mxNoSqlDriver.First(); nullptr != pMysqlDriver; pMysqlDriver = mxNoSqlDriver.Next())
    {
        NF_SAFE_DELETE(pMysqlDriver);
        pMysqlDriver = nullptr;
    }
    mxNoSqlDriver.ClearAll();
}

bool NFCNoSqlDriverManager::Enable()
{
    return false;
}

bool NFCNoSqlDriverManager::Busy()
{
    return false;
}

bool NFCNoSqlDriverManager::KeepLive()
{
    return false;
}

bool NFCNoSqlDriverManager::Execute()
{
    auto xNosqlDriver = this->mxNoSqlDriver.First();
    while (xNosqlDriver)
    {
        xNosqlDriver->Execute();

        xNosqlDriver = this->mxNoSqlDriver.Next();
    }

    CheckNoSql();

    return true;
}

int NFCNoSqlDriverManager::AddNoSqlServer(const std::string& strID, const std::string& strIP)
{
    if (!mxNoSqlDriver.GetElement(strID))
    {
        NFRedisDriver* pNoSqlDriver = new NFRedisDriver();
        mxNoSqlDriver.AddElement(strID, pNoSqlDriver);
        if (pNoSqlDriver->Connect(strIP, 6379, ""))
        {
            return 0;
        }

        return -1;
    }

    return -1;
}

int NFCNoSqlDriverManager::AddNoSqlServer(const std::string& strID, const std::string& strIP, const int nPort)
{
    if (!mxNoSqlDriver.GetElement(strID))
    {
        auto pNoSqlDriver = NF_NEW NFRedisDriver();
        mxNoSqlDriver.AddElement(strID, pNoSqlDriver);
        if (pNoSqlDriver->Connect(strIP, nPort, ""))
        {
            return 0;
        }
        return -1;
    }

    return -1;
}

int NFCNoSqlDriverManager::AddNoSqlServer(const std::string& strID, const std::string& strIP, const int nPort, const std::string& strPass)
{
    if (!mxNoSqlDriver.GetElement(strID))
    {
        auto pNoSqlDriver = NF_NEW NFRedisDriver();
        mxNoSqlDriver.AddElement(strID, pNoSqlDriver);
        if (pNoSqlDriver->Connect(strIP, nPort, strPass))
        {
            return 0;
        }
        return -1;
    }

    return -1;
}

NFIRedisDriver* NFCNoSqlDriverManager::GetNosqlDriver(const std::string& strID)
{
    auto xDriver = mxNoSqlDriver.GetElement(strID);
    if (xDriver && xDriver->Enable())
    {
        return xDriver;
    }

    return nullptr;
}

void NFCNoSqlDriverManager::CheckNoSql()
{
    static const int CHECK_TIME = 15;
    if (mLastCheckTime + CHECK_TIME > NFTime::Now().UnixSec())
    {
        return;
    }

    mLastCheckTime = NFTime::Now().UnixSec();

    auto xNosqlDriver = this->mxNoSqlDriver.First();
    while (xNosqlDriver)
    {
        if (xNosqlDriver->Enable() && !xNosqlDriver->Authed())
        {
            xNosqlDriver->AUTH(xNosqlDriver->GetAuthKey());
        }
        else if (!xNosqlDriver->Enable())
        {
            //reconnect
            xNosqlDriver->ReConnect();
        }

        xNosqlDriver = this->mxNoSqlDriver.Next();
    }
}

