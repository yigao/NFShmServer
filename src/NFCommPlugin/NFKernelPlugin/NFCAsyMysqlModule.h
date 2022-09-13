// -------------------------------------------------------------------------
//    @FileName         :    NFCAsyMysqlModule.h
//    @Author           :    Gao.Yi
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFCAsyMysqlModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIAsyMysqlModule.h"
#include "NFComm/NFPluginModule/NFIEventModule.h"
#include "NFCMysqlDriverManager.h"
#include "NFCMysqlDriver.h"
#include "NFComm/NFPluginModule/NFEventDefine.h"


/**
 * @brief 异步mysql
 */
class NFCAsyMysqlModule final
	: public NFIAsyMysqlModule
{
public:
	NFCAsyMysqlModule(NFIPluginManager* p);
	virtual ~NFCAsyMysqlModule();

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
	virtual int AddMysqlServer(const std::string& nServerID, const std::string &strIP, int nPort, std::string strDBName,
		std::string strDBUser, std::string strDBPwd, int nRconnectTime = 10,
		int nRconneCount = -1) override;

	/**
	 * @brief 执行sql语句, 把数据库配置表里的数据取出来
	 *
	 * @param  table 配置表表明
	 * @param  sheet_fullname protobuf中代表一个表格的message
	 * @param  pMessage sheet_fullname的protobuf的数据结构，携带返回数据
	 *  比如 message Sheet_GameRoomDesc
	 *		{
	 *			repeated GameRoomDesc GameRoomDesc_List = 1  [(yd_fieldoptions.field_arysize)=100];
	 *		}
	 * 代表一个Excel表格GameRoomDesc, 同时数据库有一个表GameRoomDesc
	 * 都用这个数据结构来表达，以及存取数据
	 *
	 *
	 * @return bool 执行成功或失败
	 */
	virtual int QueryDescStore(const std::string& serverID, const std::string &table, const google::protobuf::Message *pSheetMessageObject, const QueryDescStore_CB& cb) override;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
	virtual int SelectByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_sel &select,
		const SelectByCond_CB& cb) override;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  message 表结构体
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
	virtual int SelectObj(const std::string& nServerID, const storesvr_sqldata::storesvr_selobj &select,
		const SelectObj_CB& cb) override;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
	virtual int DeleteByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_del &select,
		const DeleteByCond_CB& cb) override;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
	virtual int DeleteObj(const std::string& nServerID, const storesvr_sqldata::storesvr_delobj &select,
		const DeleteObj_CB& cb) override;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
	virtual int InsertObj(const std::string& nServerID, const storesvr_sqldata::storesvr_ins &select,
		const InsertObj_CB& cb) override;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
    virtual int ModifyByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_mod &select,
                          const ModifyByCond_CB& cb) override;

	virtual int ModifyObj(const std::string& nServerID, const storesvr_sqldata::storesvr_modobj &select,
		const ModifyObj_CB& cb) override;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
    virtual int UpdateByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_modins &select,
                          const UpdateByCond_CB& cb) override;

	virtual int UpdateObj(const std::string& nServerID, const storesvr_sqldata::storesvr_modinsobj &select,
		const UpdateObj_CB& cb) override;

    virtual int Execute(const std::string& nServerID, const storesvr_sqldata::storesvr_execute &select,
                const Execute_CB& cb) override;
private:
	uint64_t mnLastCheckTime;
	bool m_initComponet;
};
