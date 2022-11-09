// -------------------------------------------------------------------------
//    @FileName         :    NFCZdbDriver.cpp
//    @Author           :    eliteYang
//    @Date             :   2022-11-09
//    @Module           :    NFCZdbDriver
//    @Desc             :
// -------------------------------------------------------------------------
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

int NFCZdbDriver::Connect(const std::string& strDBType, const string &strDBName, const string &strDBHost, int nDBPort, const string &strDBUser, const string &strDBPwd)
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
    std::string strUrl;
    if (m_dbType == "mysql")
    {
        strUrl = NF_FORMAT("{}://{}:{}/{}?user={}&password={}", m_dbType, m_dbHost, m_dbPort, m_dbName, m_dbUser, m_dbPwd);
    }

    TRY
    {
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
    }
    END_TRY;


    return 0;
}

Connection_T NFCZdbDriver::GetConnection()
{
    return ConnectionPool_getConnection(m_connectionpool);
}
