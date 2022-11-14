// -------------------------------------------------------------------------
//    @FileName         :    NFCZdbDriver.cpp
//    @Author           :    eliteYang
//    @Date             :   2022-11-09
//    @Module           :    NFCZdbDriver
//    @Desc             :
// -------------------------------------------------------------------------
#include <NFComm/NFPluginModule/NFCheck.h>
#include "NFCZdbDriver.h"
#include "NFComm/NFCore/NFCommon.h"

NFCZdbDriver::NFCZdbDriver()
{
    m_dbPort = 0;
    m_connectionpool = NULL;
}

NFCZdbDriver::~NFCZdbDriver()
{
    ConnectionPool_free(&m_connectionpool);
    URL_free(&m_url);
}

int NFCZdbDriver::Connect(const std::string &strDBType, const string &strDBName, const string &strDBHost, int nDBPort, const string &strDBUser,
                          const string &strDBPwd)
{
    m_dbType = NFCommon::lower(strDBType);
    m_dbName = strDBName;
    m_dbHost = strDBHost;
    m_dbPort = nDBPort;
    m_dbUser = strDBUser;
    m_dbPwd = strDBPwd;
    Connect();
    return 0;
}

int NFCZdbDriver::Connect()
{
    int iRetCode = 0;
    std::string errStr = 0;
    std::string strUrl;
    if (m_dbType == "mysql")
    {
        strUrl = NF_FORMAT("mysql://{}:{}/{}?user={}&password={}", m_dbHost, m_dbPort, m_dbName, m_dbUser, m_dbPwd);
    }
    else if (m_dbType == "sqlite")
    {
        strUrl = NF_FORMAT("sqlite:///var/sqlite/{}.db?synchronous=normal&heap_limit=8000&foreign_keys=on", m_dbName);
    }

    NF_ZDB_TRY_BEGIN
    URL_T m_url = URL_new(strUrl.c_str());
    if (m_url == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "URL_new Failed:{}", strUrl);
        return -1;
    }

    ConnectionPool_T m_connectionpool = ConnectionPool_new(m_url);
    if (m_connectionpool == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "ConnectionPool_new Failed:{}", strUrl);
        return -1;
    }

    ConnectionPool_start(m_connectionpool);
    NF_ZDB_TRY_END(iRetCode, errStr, "Conect Failed " + strUrl + ", ");

    return 0;
}

Connection_T NFCZdbDriver::GetConnection()
{
    return ConnectionPool_getConnection(m_connectionpool);
}

int NFCZdbDriver::Query(const string &qstr, ResultSet_T &resultSet, string &errormsg)
{
    int iRetCode = 0;
    NF_ZDB_TRY_BEGIN
    Connection_T pConn = GetConnection();
    CHECK_NULL(pConn);

    resultSet = Connection_executeQuery(pConn, qstr.c_str());

    if (resultSet == NULL)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "Connection_executeQuery Error, sql:{}", qstr);
        errormsg = Connection_getLastError(pConn);
        return -1;
    }
    NF_ZDB_TRY_END(iRetCode, errormsg, "Query Fail");
    return iRetCode;
}

int NFCZdbDriver::ExecuteOne(const string &qstr, std::unordered_map<std::string, std::string> &valueVec, string &errormsg)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "query:{}", qstr);

    ResultSet_T result;
    if (Query(qstr, result, errormsg) == 0)
    {
        while (ResultSet_next(result)) //游标滑到下一行
        {
            int colnum = ResultSet_getColumnCount(result);
            for (int i = 0; i < colnum; i++)
            {
                std::string key = ResultSet_getColumnName(result, i);

                std::string value;
                if (!ResultSet_isnull(result, i))
                {
                    value = ResultSet_getString(result, i);
                }
                valueVec.emplace(key, value);
            }
            return 0;
        }
        return 0;
    }
    return -1;
}

int NFCZdbDriver::Execute(const string &qstr, string &errormsg)
{
    int iRetCode = 0;
    NF_ZDB_TRY_BEGIN
    Connection_T pConn = GetConnection();
    CHECK_NULL(pConn);

    Connection_execute(pConn, qstr.c_str());
    NF_ZDB_TRY_END(iRetCode, errormsg, "Execute Sql:" + qstr + " Error,");
    return iRetCode;
}
