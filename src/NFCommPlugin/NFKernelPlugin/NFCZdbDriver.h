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
#include <unordered_map>
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "zdb/zdb.h"

#define  NF_ZDB_TRY_BEGIN  TRY {


#define NF_ZDB_TRY_END(outCode, outError, msg) }\
        CATCH(SQLException)\
        {\
            outCode = -1;\
            outError = NF_FORMAT("{} {}: {} raised in {} at {}:{}", msg,\
            Exception_frame.exception->name,\
            Exception_frame.message,\
            Exception_frame.func,\
            Exception_frame.file,\
            Exception_frame.line);\
            NFLogError(NF_LOG_SYSTEMLOG, 0, "{}", outError); \
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
public:
    /**
     * @brief 执行sql语句
     *
     * @param  qstr sql语句
     * @param  valueVec 返回数据
     * @return int =0执行成功, != 0失败
     */
    int ExecuteOne(const std::string &qstr, std::unordered_map<std::string, std::string> &valueVec, std::string &errormsg);

    /**
     * @brief 执行sql语句
     *
     * @param  qstr sql语句
     * @return int =0执行成功, != 0失败
     */
    int Execute(const std::string &qstr, std::string &errormsg);
private:
    /**
     * @brief 通过sql语句查询数据
     *
     * @param  qstr sql语句
     * @param  queryResult 查询结果
     * @return bool 查询成功或失败
     */
    int Query(const std::string &qstr, ResultSet_T& resultSet, std::string &errormsg);
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


