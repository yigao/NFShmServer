
#include <algorithm>
#include "NFCNoSqlDriverManager.h"
#include "NFComm/NFCore/NFTime.h"

NFCNoSqlDriverManager::NFCNoSqlDriverManager()
{
    mLastCheckTime = 0;
}

NFCNoSqlDriverManager::~NFCNoSqlDriverManager()
{

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
    NF_SHARE_PTR<NFIRedisDriver> xNosqlDriver = this->mxNoSqlDriver.First();
    while (xNosqlDriver)
    {
        xNosqlDriver->Execute();

        xNosqlDriver = this->mxNoSqlDriver.Next();
    }

    CheckConnect();

    return true;
}

NF_SHARE_PTR<NFIRedisDriver> NFCNoSqlDriverManager::GetDriverBySuitRandom()
{
    NF_SHARE_PTR<NFIRedisDriver> xDriver = mxNoSqlDriver.GetElementBySuitRandom();
    if (xDriver && xDriver->Enable())
    {
        return xDriver;
    }

    return nullptr;
}

NF_SHARE_PTR<NFIRedisDriver> NFCNoSqlDriverManager::GetDriverBySuitConsistent()
{
    NF_SHARE_PTR<NFIRedisDriver> xDriver = mxNoSqlDriver.GetElementBySuitConsistent();
    if (xDriver && xDriver->Enable())
    {
        return xDriver;
    }

    return nullptr;
}

NF_SHARE_PTR<NFIRedisDriver> NFCNoSqlDriverManager::GetDriverBySuit(const std::string& strHash)
{
    NF_SHARE_PTR<NFIRedisDriver> xDriver = mxNoSqlDriver.GetElementBySuit(strHash);
    if (xDriver && xDriver->Enable())
    {
        return xDriver;
    }

    NFLogError(NF_LOG_SYSTEMLOG, 0, "GetDriverBySuit ===> NULL hash:{}", strHash);
    return nullptr;
}

/*
NF_SHARE_PTR<NFIRedisDriver> NFCNoSqlModule::GetDriverBySuit(const int nHash)
{
return mxNoSqlDriver.GetElementBySuit(nHash);
}
*/
bool NFCNoSqlDriverManager::AddConnectSql(const std::string& strID, const std::string& strIP)
{
    if (!mxNoSqlDriver.ExistElement(strID))
    {
        NF_SHARE_PTR<NFRedisDriver> pNoSqlDriver(new NFRedisDriver());
        pNoSqlDriver->Connect(strIP, 6379, "");
        CheckConnect();
        return mxNoSqlDriver.AddElement(strID, pNoSqlDriver);
    }

    return false;
}

bool NFCNoSqlDriverManager::AddConnectSql(const std::string& strID, const std::string& strIP, const int nPort)
{
    if (!mxNoSqlDriver.ExistElement(strID))
    {
        NF_SHARE_PTR<NFIRedisDriver> pNoSqlDriver(new NFRedisDriver());
        pNoSqlDriver->Connect(strIP, nPort, "");
        return mxNoSqlDriver.AddElement(strID, pNoSqlDriver);
    }

    return false;
}

bool NFCNoSqlDriverManager::AddConnectSql(const std::string& strID, const std::string& strIP, const int nPort, const std::string& strPass)
{
    if (!mxNoSqlDriver.ExistElement(strID))
    {
        NF_SHARE_PTR<NFIRedisDriver> pNoSqlDriver(NF_NEW NFRedisDriver());
        pNoSqlDriver->Connect(strIP, nPort, strPass);
        return mxNoSqlDriver.AddElement(strID, pNoSqlDriver);
    }

    return false;
}

std::vector<std::string> NFCNoSqlDriverManager::GetDriverIdList()
{
    std::vector<std::string> lDriverIdList;
    std::string strDriverId;
    NF_SHARE_PTR<NFIRedisDriver> pDriver = mxNoSqlDriver.First(strDriverId);
    while (pDriver)
    {
        lDriverIdList.push_back(strDriverId);
        pDriver = mxNoSqlDriver.Next(strDriverId);
    }
    return lDriverIdList;
}

NF_SHARE_PTR<NFIRedisDriver> NFCNoSqlDriverManager::GetDriver(const std::string& strID)
{
    NF_SHARE_PTR<NFIRedisDriver> xDriver = mxNoSqlDriver.GetElement(strID);
    if (xDriver && xDriver->Enable())
    {
        return xDriver;
    }

    return nullptr;
}

bool NFCNoSqlDriverManager::RemoveConnectSql(const std::string& strID)
{
    return mxNoSqlDriver.RemoveElement(strID);
}

void NFCNoSqlDriverManager::CheckConnect()
{
    static const int CHECK_TIME = 15;
    if (mLastCheckTime + CHECK_TIME > NFTime::Now().UnixSec())
    {
        return;
    }

    mLastCheckTime = NFTime::Now().UnixSec();

    NF_SHARE_PTR<NFIRedisDriver> xNosqlDriver = this->mxNoSqlDriver.First();
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

