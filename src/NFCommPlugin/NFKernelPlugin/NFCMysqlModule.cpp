// -------------------------------------------------------------------------
//    @FileName         :    NFCMysqlModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFMysqlPlugin
//
// -------------------------------------------------------------------------

#include <algorithm>
#include "NFCMysqlDriver.h"
#include "NFCMysqlModule.h"
#include "NFCMysqlDriverManager.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFTimerAxis.h"

NFCMysqlModule::NFCMysqlModule(NFIPluginManager* p): NFIMysqlModule(p)
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
int NFCMysqlModule::InsertObj(const std::string& nServerID, const storesvr_sqldata::storesvr_insertobj &select,
                              storesvr_sqldata::storesvr_insertobj_res &select_res) {
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
int NFCMysqlModule::UpdateObj(const std::string& nServerID, const storesvr_sqldata::storesvr_updateobj &select,
                              storesvr_sqldata::storesvr_updateobj_res &select_res) {
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

int NFCMysqlModule::OnTimer(uint32_t nTimerID)
{
	if (m_pMysqlDriverManager)
	{
		m_pMysqlDriverManager->CheckMysql();
	}
    return 0;
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

int NFCMysqlModule::CloseMysql(const std::string& serverID)
{
    if (!m_pMysqlDriverManager)
    {
        return -1;
    }

    return m_pMysqlDriverManager->CloseMysql(serverID);
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

/**
 * @brief 是否存在数据库
 * @param dbName
 * @return
 */
int NFCMysqlModule::ExistsDB(const std::string& serverID, const std::string& dbName, bool &bExit)
{
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(serverID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, dbName:{} ", dbName);

    return pDriver->ExistsDB(dbName, bExit);
}

/**
 * @brief 创建数据库
 * @param dbName
 * @return
 */
int NFCMysqlModule::CreateDB(const std::string& serverID, const std::string& dbName)
{
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(serverID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, dbName:{} ", dbName);

    return pDriver->CreateDB(dbName);
}

/**
 * @brief 选择数据库
 * @param dbName
 * @return
 */
int NFCMysqlModule::SelectDB(const std::string& serverID, const std::string& dbName)
{
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(serverID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, dbName:{} ", dbName);

    return pDriver->SelectDB(dbName);
}

/**
 * @brief 是否存在表格
 * @param dbName
 * @param tableName
 * @param bExit
 * @return
 */
int NFCMysqlModule::ExistTable(const std::string& serverID, const std::string& dbName, const std::string& tableName, bool &bExit)
{
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(serverID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, dbName:{} ", dbName);

    return pDriver->ExistTable(dbName, tableName, bExit);
}

/**
 * @brief 获取表列信息
 * @param dbName
 * @param tableName
 * @param col
 * @return
 */
int NFCMysqlModule::GetTableColInfo(const std::string& serverID, const std::string& dbName, const std::string& tableName, std::map<std::string, DBTableColInfo>& col)
{
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(serverID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, dbName:{} ", dbName);

    return pDriver->GetTableColInfo(dbName, tableName, col);
}

/**
 * @brief 查询表格信息
 * @param tableName
 * @param pTableMessage
 * @param needCreateColumn
 * @return
 */
int NFCMysqlModule::QueryTableInfo(const std::string& serverID, const std::string& dbName, const std::string& tableName, bool &bExit, std::map<std::string, DBTableColInfo> &primaryKey, std::multimap<uint32_t, std::string>& needCreateColumn)
{
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(serverID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, dbName:{} ", dbName);

    return pDriver->QueryTableInfo(dbName, tableName, bExit, primaryKey, needCreateColumn);
}

int NFCMysqlModule::CreateTable(const std::string& serverID, const std::string& tableName, const std::map<std::string, DBTableColInfo> &primaryKey, const std::multimap<uint32_t, std::string>& needCreateColumn)
{
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(serverID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, dbName:{} ", serverID);

    int iRet = pDriver->CreateTable(tableName, primaryKey, needCreateColumn);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateTable Failed! tableName:{}",tableName);
        return iRet;
    }

    return iRet;
}

int NFCMysqlModule::AddTableRow(const std::string& serverID, const std::string& tableName, const std::multimap<uint32_t, std::string>& needCreateColumn)
{
    NFCMysqlDriver *pDriver = m_pMysqlDriverManager->GetMysqlDriver(serverID);
    CHECK_EXPR(pDriver, -1, "pDriver == NULL, dbName:{} ", serverID);

    int iRet = pDriver->AddTableRow(tableName, needCreateColumn);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "AddTableRow Failed! tableName:{}", tableName);
        return iRet;
    }

    return iRet;
}