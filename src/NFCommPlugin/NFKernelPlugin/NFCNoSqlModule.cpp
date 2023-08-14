﻿
#include <algorithm>
#include "NFCNoSqlModule.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFComm/NFPluginModule/NFCheck.h"

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

int NFCNoSqlModule::AddNoSqlServer(const std::string& strID, const std::string& strIP)
{
	return m_pNoSqlDriverManager->AddNoSqlServer(strID, strIP);
}

int NFCNoSqlModule::AddNoSqlServer(const std::string& strID, const std::string& strIP, const int nPort)
{
	return m_pNoSqlDriverManager->AddNoSqlServer(strID, strIP, nPort);
}

int NFCNoSqlModule::AddNoSqlServer(const std::string& strID, const std::string& strIP, const int nPort, const std::string& strPass)
{
	return m_pNoSqlDriverManager->AddNoSqlServer(strID, strIP, nPort, strPass);
}

int NFCNoSqlModule::SelectObj(const std::string& strID, const storesvr_sqldata::storesvr_selobj &select, storesvr_sqldata::storesvr_selobj_res &select_res)
{
    auto pDriver = m_pNoSqlDriverManager->GetNosqlDriver(strID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", strID);
    return pDriver->SelectObj(select, select_res);
}

int NFCNoSqlModule::SaveObj(const std::string& strID, const storesvr_sqldata::storesvr_selobj &select,
                            storesvr_sqldata::storesvr_selobj_res &select_res)
{
    auto pDriver = m_pNoSqlDriverManager->GetNosqlDriver(strID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", strID);
    return pDriver->SaveObj(select, select_res);
}

int NFCNoSqlModule::SaveObj(const std::string& strID, const storesvr_sqldata::storesvr_insertobj &select)
{
    auto pDriver = m_pNoSqlDriverManager->GetNosqlDriver(strID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", strID);
    return pDriver->SaveObj(select);
}

int NFCNoSqlModule::SaveObj(const std::string& strID, const storesvr_sqldata::storesvr_modobj &select)
{
    auto pDriver = m_pNoSqlDriverManager->GetNosqlDriver(strID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", strID);
    return pDriver->SaveObj(select);
}

int NFCNoSqlModule::DeleteObj(const std::string& strID, const storesvr_sqldata::storesvr_delobj &select)
{
    auto pDriver = m_pNoSqlDriverManager->GetNosqlDriver(strID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", strID);
    return pDriver->DeleteObj(select);
}

int NFCNoSqlModule::DeleteObj(const std::string& strID, const storesvr_sqldata::storesvr_insertobj &select)
{
    auto pDriver = m_pNoSqlDriverManager->GetNosqlDriver(strID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", strID);
    return pDriver->DeleteObj(select);
}

int NFCNoSqlModule::DeleteObj(const std::string& strID, const storesvr_sqldata::storesvr_modobj &select)
{
    auto pDriver = m_pNoSqlDriverManager->GetNosqlDriver(strID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", strID);
    return pDriver->DeleteObj(select);
}

NFIRedisDriver* NFCNoSqlModule::GetNosqlDriver(const std::string& strID)
{
	return m_pNoSqlDriverManager->GetNosqlDriver(strID);
}

