
#include <algorithm>
#include "NFCNoSqlModule.h"
#include "NFComm/NFCore/NFTime.h"

NFCNoSqlModule::NFCNoSqlModule(NFIPluginManager* p):NFINoSqlModule(p)
{
    m_pNoSqlDriverManager = NF_NEW NFCNoSqlDriverManager();
}

NFCNoSqlModule::~NFCNoSqlModule()
{

}


bool NFCNoSqlModule::Init()
{
	return true;
}

bool NFCNoSqlModule::Shut()
{
	return true;
}

bool NFCNoSqlModule::AfterInit()
{
	return true;
}

bool NFCNoSqlModule::Enable()
{
	return m_pNoSqlDriverManager->Enable();
}

bool NFCNoSqlModule::Busy()
{
	return m_pNoSqlDriverManager->Busy();
}

bool NFCNoSqlModule::KeepLive()
{
	return m_pNoSqlDriverManager->KeepLive();
}

bool NFCNoSqlModule::Execute()
{
	return m_pNoSqlDriverManager->Execute();
}

NF_SHARE_PTR<NFIRedisDriver> NFCNoSqlModule::GetDriverBySuitRandom()
{
	return m_pNoSqlDriverManager->GetDriverBySuitRandom();
}

NF_SHARE_PTR<NFIRedisDriver> NFCNoSqlModule::GetDriverBySuitConsistent()
{
	return m_pNoSqlDriverManager->GetDriverBySuitConsistent();
}

NF_SHARE_PTR<NFIRedisDriver> NFCNoSqlModule::GetDriverBySuit(const std::string& strHash)
{
	return m_pNoSqlDriverManager->GetDriverBySuit(strHash);
}

/*
NF_SHARE_PTR<NFIRedisDriver> NFCNoSqlModule::GetDriverBySuit(const int nHash)
{
return mxNoSqlDriver.GetElementBySuit(nHash);
}
*/
bool NFCNoSqlModule::AddConnectSql(const std::string& strID, const std::string& strIP)
{
	return m_pNoSqlDriverManager->AddConnectSql(strID, strIP);
}

bool NFCNoSqlModule::AddConnectSql(const std::string& strID, const std::string& strIP, const int nPort)
{
	return m_pNoSqlDriverManager->AddConnectSql(strID, strIP, nPort);
}

bool NFCNoSqlModule::AddConnectSql(const std::string& strID, const std::string& strIP, const int nPort, const std::string& strPass)
{
	return m_pNoSqlDriverManager->AddConnectSql(strID, strIP, nPort, strPass);
}

std::vector<std::string> NFCNoSqlModule::GetDriverIdList()
{
	return m_pNoSqlDriverManager->GetDriverIdList();
}

NF_SHARE_PTR<NFIRedisDriver> NFCNoSqlModule::GetDriver(const std::string& strID)
{
	return m_pNoSqlDriverManager->GetDriver(strID);
}

bool NFCNoSqlModule::RemoveConnectSql(const std::string& strID)
{
	return m_pNoSqlDriverManager->RemoveConnectSql(strID);
}
