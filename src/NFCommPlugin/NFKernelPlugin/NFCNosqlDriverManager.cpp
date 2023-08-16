
#include <algorithm>
#include "NFCNosqlDriverManager.h"
#include "NFComm/NFCore/NFTime.h"

NFCNosqlDriverManager::NFCNosqlDriverManager()
{
    mLastCheckTime = 0;
}

NFCNosqlDriverManager::~NFCNosqlDriverManager()
{
    for (auto pMysqlDriver = mxNoSqlDriver.First(); nullptr != pMysqlDriver; pMysqlDriver = mxNoSqlDriver.Next())
    {
        NF_SAFE_DELETE(pMysqlDriver);
        pMysqlDriver = nullptr;
    }
    mxNoSqlDriver.ClearAll();
}

bool NFCNosqlDriverManager::Enable()
{
    return false;
}

bool NFCNosqlDriverManager::Busy()
{
    return false;
}

bool NFCNosqlDriverManager::KeepLive()
{
    return false;
}

bool NFCNosqlDriverManager::Execute()
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

int NFCNosqlDriverManager::AddNosqlServer(const std::string& strID, const std::string& strIP)
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

int NFCNosqlDriverManager::AddNosqlServer(const std::string& strID, const std::string& strIP, const int nPort)
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

int NFCNosqlDriverManager::AddNosqlServer(const std::string& strID, const std::string& strIP, const int nPort, const std::string& strPass)
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

NFINosqlDriver* NFCNosqlDriverManager::GetNosqlDriver(const std::string& strID)
{
    auto xDriver = mxNoSqlDriver.GetElement(strID);
    if (xDriver && xDriver->Enable())
    {
        return xDriver;
    }

    return nullptr;
}

void NFCNosqlDriverManager::CheckNoSql()
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

