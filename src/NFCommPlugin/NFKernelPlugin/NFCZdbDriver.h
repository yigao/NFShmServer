// -------------------------------------------------------------------------
//    @FileName         :    NFCZdbDriver.h
//    @Author           :    eliteYang
//    @Date             :   2022-11-09
//    @Module           :    NFCZdbDriver
//    @Desc             :
// -------------------------------------------------------------------------

#pragma once

#include <string>
#include <vector>
#include <set>
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include <string>
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "zdb/zdb.h"

#define  NF_ZDB_TRY_BEGIN  TRY


#define NF_ZDB_TRY_END(msg)\
        ELSE\
        {\
            NFLogError(NF_LOG_SYSTEMLOG, 0, "{} {}: {} raised in {} at {}:{}", msg,\
            Exception_frame.exception->name,\
            Exception_frame.message,\
            Exception_frame.func,\
            Exception_frame.file,\
            Exception_frame.line);\
        }\
        END_TRY;\


class NFCZdbDriver
{
public:
    NFCZdbDriver();
    virtual ~NFCZdbDriver();
public:
    /**
     * @brief 连接数据库
     *
     * @param  strDBType 数据库类型，比如mysql,sqlite3
     * @param  strDBName 数据库名字
     * @param  strDBHost 数据库IP
     * @param  nDBPort   数据库端口
     * @param  strDBUser 数据库用户名
     * @param  strDBPwd  数据库密码
     * @return int
     */
    virtual int Connect(const std::string& strDBType, const std::string &strDBName, const std::string &strDBHost, int nDBPort, const std::string &strDBUser,
                const std::string &strDBPwd);

    /**
     * @brief 连接
     *
     * @return int
     */
    virtual int Connect();

    /**
     * @brief 获得zdb的连接
     *
     * @return Connection_T
     */
    Connection_T GetConnection();
private:
    /**
     * @brief 数据库类型，比如mysql,sqlite3
     */
    std::string m_dbType;

    /**
     * @brief 数据库名字
     */
    std::string m_dbName;

    /**
     * @brief 数据库IP
     */
    std::string m_dbHost;

    /**
     * @brief 数据库端口
     */
    int m_dbPort;

    /**
     * @brief 数据库用户名
     */
    std::string m_dbUser;

    /**
     * @brief 数据库用户秘密
     */
    std::string m_dbPwd;

    /**
     * @brief url对象
     */
    URL_T m_url;

    /**
     * @brief zdb连接池
     */
    ConnectionPool_T m_connectionpool;
};


