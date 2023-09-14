// -------------------------------------------------------------------------
//    @FileName         :    NFCAsyMysqlModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Module           :    NFCAsyMysqlModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIAsyDBModule.h"
#include "NFComm/NFPluginModule/NFIEventModule.h"
#include "NFCMysqlDriverManager.h"
#include "NFCMysqlDriver.h"
#include "NFComm/NFPluginModule/NFEventDefine.h"


/**
 * @brief 异步mysql
 */
class NFCAsyDBModule final
	: public NFIAsyDBModule
{
public:
	NFCAsyDBModule(NFIPluginManager* p);
	virtual ~NFCAsyDBModule();

	virtual bool Execute() override;

	virtual bool InitActorPool(int maxActorNum) override;

    /**
     * @brief 添加Mysql链接
     *
     * @param  nServerID			ID
     * @param  strIP				IP地址
     * @param  nPort				端口
     * @param  strDBName			数据库名字
     * @param  strDBUser			数据库用户名
     * @param  strDBPwd				数据库密码
     * @param  nRconnectTime		重连间隔
     * @param  nRconneCount			重连次数
     * @return bool					成功或失败
     */
	virtual int AddDBServer(const std::string& nServerID, const std::string &strIP, int nPort, std::string strDBName, std::string strDBUser, std::string strDBPwd,
                            const std::string& noSqlIp, int nosqlPort, const std::string& noSqlPass,
                            int nRconnectTime = 10, int nRconneCount = -1) override;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
	virtual int SelectByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_sel &select, bool useCache,
		const SelectByCond_CB& cb) override;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  message 表结构体
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
	virtual int SelectObj(const std::string& nServerID, const storesvr_sqldata::storesvr_selobj &select, bool useCache,
		const SelectObj_CB& cb) override;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
	virtual int DeleteByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_del &select, bool useCache,
		const DeleteByCond_CB& cb) override;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
	virtual int DeleteObj(const std::string& nServerID, const storesvr_sqldata::storesvr_delobj &select, bool useCache,
		const DeleteObj_CB& cb) override;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
	virtual int InsertObj(const std::string& nServerID, const storesvr_sqldata::storesvr_insertobj &select, bool useCache,
		const InsertObj_CB& cb) override;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
    virtual int ModifyByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_mod &select, bool useCache,
                          const ModifyByCond_CB& cb) override;

	virtual int ModifyObj(const std::string& nServerID, const storesvr_sqldata::storesvr_modobj &select, bool useCache,
		const ModifyObj_CB& cb) override;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
    virtual int UpdateByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_update &select, bool useCache,
                          const UpdateByCond_CB& cb) override;

	virtual int UpdateObj(const std::string& nServerID, const storesvr_sqldata::storesvr_updateobj &select, bool useCache,
		const UpdateObj_CB& cb) override;

    virtual int Execute(const std::string& nServerID, const storesvr_sqldata::storesvr_execute &select,
                const Execute_CB& cb) override;

    virtual int ExecuteMore(const std::string& nServerID, const storesvr_sqldata::storesvr_execute_more &select,
                    const ExecuteMore_CB& cb) override;
private:
	uint64_t mnLastCheckTime;
	bool m_initComponet;
};
