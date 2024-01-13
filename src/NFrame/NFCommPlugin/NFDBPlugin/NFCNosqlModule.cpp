
#include <algorithm>
#include "NFCNosqlModule.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFPluginModule/NFCheck.h"

NFCNosqlModule::NFCNosqlModule(NFIPluginManager* p): NFINosqlModule(p)
{
    m_pNoSqlDriverManager = NF_NEW NFCNosqlDriverManager();
}

NFCNosqlModule::~NFCNosqlModule()
{

}


bool NFCNosqlModule::Init()
{
	return true;
}

bool NFCNosqlModule::Shut()
{
	return true;
}

bool NFCNosqlModule::AfterInit()
{
	return true;
}

bool NFCNosqlModule::Enable()
{
	return m_pNoSqlDriverManager->Enable();
}

bool NFCNosqlModule::Busy()
{
	return m_pNoSqlDriverManager->Busy();
}

bool NFCNosqlModule::KeepLive()
{
	return m_pNoSqlDriverManager->KeepLive();
}

bool NFCNosqlModule::Execute()
{
	return m_pNoSqlDriverManager->Execute();
}

int NFCNosqlModule::AddNosqlServer(const std::string& strID, const std::string& strIP)
{
	return m_pNoSqlDriverManager->AddNosqlServer(strID, strIP);
}

int NFCNosqlModule::AddNosqlServer(const std::string& strID, const std::string& strIP, const int nPort)
{
	return m_pNoSqlDriverManager->AddNosqlServer(strID, strIP, nPort);
}

int NFCNosqlModule::AddNosqlServer(const std::string& strID, const std::string& strIP, const int nPort, const std::string& strPass)
{
	return m_pNoSqlDriverManager->AddNosqlServer(strID, strIP, nPort, strPass);
}

int NFCNosqlModule::SelectObj(const std::string& strID, const storesvr_sqldata::storesvr_selobj &select, storesvr_sqldata::storesvr_selobj_res &select_res)
{
    auto pDriver = m_pNoSqlDriverManager->GetNosqlDriver(strID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", strID);
    return pDriver->SelectObj(select, select_res);
}

int NFCNosqlModule::SaveObj(const std::string& strID, const storesvr_sqldata::storesvr_selobj &select,
                            storesvr_sqldata::storesvr_selobj_res &select_res)
{
    auto pDriver = m_pNoSqlDriverManager->GetNosqlDriver(strID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", strID);
    return pDriver->SaveObj(select, select_res);
}

int NFCNosqlModule::SaveObj(const std::string& strID, const storesvr_sqldata::storesvr_insertobj &select, storesvr_sqldata::storesvr_insertobj_res &select_res)
{
    auto pDriver = m_pNoSqlDriverManager->GetNosqlDriver(strID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", strID);
    return pDriver->SaveObj(select, select_res);
}

int NFCNosqlModule::SaveObj(const std::string& strID, const storesvr_sqldata::storesvr_modobj &select, storesvr_sqldata::storesvr_modobj_res &select_res)
{
    auto pDriver = m_pNoSqlDriverManager->GetNosqlDriver(strID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", strID);
    return pDriver->SaveObj(select, select_res);
}

int NFCNosqlModule::SaveObj(const std::string& strID, const storesvr_sqldata::storesvr_updateobj &select, storesvr_sqldata::storesvr_updateobj_res &select_res)
{
    auto pDriver = m_pNoSqlDriverManager->GetNosqlDriver(strID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", strID);
    return pDriver->SaveObj(select, select_res);
}

int NFCNosqlModule::DeleteObj(const std::string& strID, const storesvr_sqldata::storesvr_delobj &select)
{
    auto pDriver = m_pNoSqlDriverManager->GetNosqlDriver(strID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", strID);
    return pDriver->DeleteObj(select);
}

int NFCNosqlModule::DeleteObj(const std::string& strID, const storesvr_sqldata::storesvr_insertobj &select)
{
    auto pDriver = m_pNoSqlDriverManager->GetNosqlDriver(strID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", strID);
    return pDriver->DeleteObj(select);
}

int NFCNosqlModule::DeleteObj(const std::string& strID, const storesvr_sqldata::storesvr_modobj &select)
{
    auto pDriver = m_pNoSqlDriverManager->GetNosqlDriver(strID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", strID);
    return pDriver->DeleteObj(select);
}

NFINosqlDriver* NFCNosqlModule::GetNosqlDriver(const std::string& strID)
{
	return m_pNoSqlDriverManager->GetNosqlDriver(strID);
}

