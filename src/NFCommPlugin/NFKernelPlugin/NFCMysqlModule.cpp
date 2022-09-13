// -------------------------------------------------------------------------
//    @FileName         :    NFCMysqlModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFMysqlPlugin
//
// -------------------------------------------------------------------------

#include <algorithm>
#include "NFCMysqlDriver.h"
#include "NFCMysqlModule.h"
#include "NFCMysqlDriverManager.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"

NFCMysqlModule::NFCMysqlModule(NFIPluginManager* p):NFIMysqlModule(p)
{
	mnLastCheckTime = 0;
	m_pMysqlDriverManager = NF_NEW NFCMysqlDriverManager();
}

NFCMysqlModule::~NFCMysqlModule()
{
	NF_SAFE_DELETE(m_pMysqlDriverManager);
}

bool NFCMysqlModule::Init()
{
	this->SetTimer(0, 10000, INFINITY_CALL);
	return true;
}

bool NFCMysqlModule::Shut()
{
	return true;
}

int NFCMysqlModule::ExecuteMore(const std::string& nServerID, const std::string &qstr,
                                std::vector<std::map<std::string, std::string>> &keyvalueMap, std::string &errormsg) {
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{} qstr:{}", nServerID, qstr);
    return pDriver->ExecuteMore(qstr, keyvalueMap, errormsg);
}

int NFCMysqlModule::QueryDescStore(const std::string& nServerID, const std::string& table, google::protobuf::Message** pMessage)
{
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
	CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{} table:{}", nServerID, table);
    return pDriver->QueryDescStore(table, pMessage);
}

int NFCMysqlModule::QueryDescStore(const std::string& nServerID, const std::string &table, google::protobuf::Message *pMessage)
{
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{} table:{}", nServerID, table);
    return pDriver->QueryDescStore(table, pMessage);
}

int NFCMysqlModule::SelectByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_sel &select,
                                 storesvr_sqldata::storesvr_sel_res &select_res) {
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", nServerID);
    return pDriver->SelectByCond(select, select_res);
}

int NFCMysqlModule::SelectObj(const std::string& nServerID, const std::string& tbName, google::protobuf::Message *pMessage, std::string& errMsg)
{
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", nServerID);
    return pDriver->SelectObj(tbName, pMessage, errMsg);
}

/**
 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
 *
 * @param  select 查询语句
 * @param  message 表结构体
 * @param  select_res 查询结果
 * @return int =0执行成功, != 0失败
 */
int NFCMysqlModule::SelectObj(const std::string& nServerID, const storesvr_sqldata::storesvr_selobj &select,
                              storesvr_sqldata::storesvr_selobj_res &select_res) {
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", nServerID);
    return pDriver->SelectObj(select, select_res);
}

/**
 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
 *
 * @param  select 查询语句
 * @param  select_res 查询结果
 * @return int =0执行成功, != 0失败
 */
int NFCMysqlModule::DeleteByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_del &select,
                                 storesvr_sqldata::storesvr_del_res &select_res) {
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", nServerID);
    return pDriver->DeleteByCond(select, select_res);
}

/**
 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
 *
 * @param  select 查询语句
 * @param  select_res 查询结果
 * @return int =0执行成功, != 0失败
 */
int NFCMysqlModule::DeleteObj(const std::string& nServerID, const storesvr_sqldata::storesvr_delobj &select,
                              storesvr_sqldata::storesvr_delobj_res &select_res) {
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", nServerID);
    return pDriver->DeleteObj(select, select_res);
}

int NFCMysqlModule::InsertObj(const std::string& nServerID, const std::string& tbName, const google::protobuf::Message *pMessage, std::string& errMsg)
{
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", nServerID);
    return pDriver->InsertObj(tbName, pMessage, errMsg);
}

/**
 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
 *
 * @param  select 查询语句
 * @param  select_res 查询结果
 * @return int =0执行成功, != 0失败
 */
int NFCMysqlModule::InsertObj(const std::string& nServerID, const storesvr_sqldata::storesvr_ins &select,
                              storesvr_sqldata::storesvr_ins_res &select_res) {
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", nServerID);
    return pDriver->InsertObj(select, select_res);
}

int NFCMysqlModule::ModifyObj(const std::string& nServerID, const std::string& tbName, const google::protobuf::Message *pMessage, std::string& errMsg)
{
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", nServerID);
    return pDriver->ModifyObj(tbName, pMessage, errMsg);
}

/**
 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
 *
 * @param  select 查询语句
 * @param  select_res 查询结果
 * @return int =0执行成功, != 0失败
 */
int NFCMysqlModule::ModifyObj(const std::string& nServerID, const storesvr_sqldata::storesvr_modobj &select,
                              storesvr_sqldata::storesvr_modobj_res &select_res) {
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", nServerID);
    return pDriver->ModifyObj(select, select_res);
}

int NFCMysqlModule::UpdateObj(const std::string& nServerID, const std::string& tbName, const google::protobuf::Message *pMessage, std::string& errMsg)
{
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", nServerID);
    return pDriver->UpdateObj(tbName, pMessage, errMsg);
}

/**
 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
 *
 * @param  select 查询语句
 * @param  select_res 查询结果
 * @return int =0执行成功, != 0失败
 */
int NFCMysqlModule::UpdateObj(const std::string& nServerID, const storesvr_sqldata::storesvr_modinsobj &select,
                              storesvr_sqldata::storesvr_modinsobj_res &select_res) {
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{}", nServerID);
    return pDriver->UpdateObj(select, select_res);
}

int NFCMysqlModule::ExecuteOne(const std::string& nServerID, const std::string &qstr, std::map<std::string, std::string> &keyvalueMap,
                               std::string &errormsg) {
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{} qstr:{}", nServerID, qstr);
    return pDriver->ExecuteOne(qstr, keyvalueMap, errormsg);
}

int
NFCMysqlModule::UpdateOne(const std::string& nServerID, const std::string &strTableName, std::map<std::string, std::string> &keyMap,
                          const std::map<std::string, std::string> &keyvalueMap, std::string &errormsg) {
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{} strTableName:{} keymap:{} keyvalueMap:{}", nServerID,
               strTableName, NFCommon::tostr(keyMap), NFCommon::tostr(keyvalueMap));
    return pDriver->Update(strTableName, keyMap, keyvalueMap, errormsg);
}

int NFCMysqlModule::QueryOne(const std::string& nServerID, const std::string &strTableName,
                             const std::map<std::string, std::string> &keyMap,
                             const std::vector<std::string> &fieldVec, std::map<std::string, std::string> &valueVec,
                             std::string &errormsg) {
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{} strTableName:{} keyMap:{} strKeyColName:{} fieldVec:{}",
               nServerID, strTableName, NFCommon::tostr(keyMap), NFCommon::tostr(fieldVec));
    return pDriver->QueryOne(strTableName, keyMap, fieldVec, valueVec, errormsg);
}

int
NFCMysqlModule::QueryMore(const std::string& nServerID, const std::string &strTableName,
                          const std::map<std::string, std::string> &keyMap,
                          const std::vector<std::string> &fieldVec,
                          std::vector<std::map<std::string, std::string>> &valueVec, std::string &errormsg) {
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{} strTableName:{} keyMap:{} strKeyColName:{} fieldVec:{}",
               nServerID, strTableName, NFCommon::tostr(keyMap), NFCommon::tostr(fieldVec));
    return pDriver->QueryMore(strTableName, keyMap, fieldVec, valueVec, errormsg);
}

bool NFCMysqlModule::Execute()
{
	return true;
}

void NFCMysqlModule::OnTimer(uint32_t nTimerID)
{
	if (m_pMysqlDriverManager)
	{
		m_pMysqlDriverManager->CheckMysql();
	}
}

int NFCMysqlModule::AddMysqlServer(const std::string& nServerID, const std::string& strIP, const int nPort,
                                    const std::string strDBName, const std::string strDBUser,
                                    const std::string strDBPwd, const int nRconnectTime/* = 10*/,
                                    const int nRconneCount/* = -1*/)
{
	if (!m_pMysqlDriverManager)
	{
		return -1;
	}

	return m_pMysqlDriverManager->AddMysqlServer(nServerID, strIP, nPort, strDBName, strDBUser, strDBPwd, nRconnectTime,
	                                             nRconneCount);
}

int NFCMysqlModule::Delete(const std::string& nServerID, const std::string &strTableName, const std::string &strKeyColName,
                           const std::string &strKey, std::string &errormsg) {
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{} strTableName:{} strKeyColName:{} strKey:{}", nServerID,
               strTableName, strKeyColName, strKey);
    return pDriver->Delete(strTableName, strKeyColName, strKey, errormsg);
}

int NFCMysqlModule::Exists(const std::string& nServerID, const std::string& strTableName, const std::string& strKeyColName,
	const std::string& strKey, bool& bExit)
{
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(nServerID);
	CHECK_EXPR(pDriver, -1, "pDriver == NULL, nServerID:{} strTableName:{} strKeyColName:{} strKey:{}", nServerID, strTableName, strKeyColName, strKey);

	return pDriver->Exists(strTableName, strKeyColName, strKey, bExit);
}

