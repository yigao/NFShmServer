// -------------------------------------------------------------------------
//    @FileName         :    NFIAsyMysqlModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFIAsyMysqlModule
//
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIAsycModule.h"
#include "google/protobuf/message.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include <vector>
#include <functional>

using QueryDescStore_CB = std::function<void(int iRet, google::protobuf::Message& message)>;

using SelectByCond_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_sel_res &select_res)>;

using SelectObj_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_selobj_res &select_res)>;

using DeleteByCond_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_del_res &select_res)>;

using DeleteObj_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_delobj_res &select_res)>;

using InsertObj_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_ins_res &select_res)>;

using ModifyByCond_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_mod_res &select_res)>;

using ModifyObj_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_modobj_res &select_res)>;

using UpdateByCond_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_modins_res &select_res)>;
using UpdateObj_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_modinsobj_res &select_res)>;

using Execute_CB = std::function<void(int iRet, storesvr_sqldata::storesvr_execute_res &select_res)>;

class NFIAsyMysqlModule
	: public NFIAsycModule
{
public:
	NFIAsyMysqlModule(NFIPluginManager* p) :NFIAsycModule(p)
	{

	}

	virtual ~NFIAsyMysqlModule()
	{

	}
	
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
		int nRconneCount = -1) = 0;

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
	virtual int QueryDescStore(const std::string& serverID, const std::string &table, const google::protobuf::Message *pSheetMessageObject, const QueryDescStore_CB& cb) = 0;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
	virtual int SelectByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_sel &select,
		const SelectByCond_CB& cb) = 0;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  message 表结构体
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
	virtual int SelectObj(const std::string& nServerID, const storesvr_sqldata::storesvr_selobj &select,
		const SelectObj_CB& cb) = 0;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
	virtual int DeleteByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_del &select,
		const DeleteByCond_CB& cb) = 0;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
	virtual int DeleteObj(const std::string& nServerID, const storesvr_sqldata::storesvr_delobj &select,
		const DeleteObj_CB& cb) = 0;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
	virtual int InsertObj(const std::string& nServerID, const storesvr_sqldata::storesvr_ins &select,
		const InsertObj_CB& cb) = 0;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
    virtual int ModifyByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_mod &select,
                             const ModifyByCond_CB& cb) = 0;

	virtual int ModifyObj(const std::string& nServerID, const storesvr_sqldata::storesvr_modobj &select,
		const ModifyObj_CB& cb) = 0;

	/**
	 * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
	 *
	 * @param  select 查询语句
	 * @param  select_res 查询结果
	 * @return int =0执行成功, != 0失败
	 */
    virtual int UpdateByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_modins &select,
                          const UpdateByCond_CB& cb) = 0;

	virtual int UpdateObj(const std::string& nServerID, const storesvr_sqldata::storesvr_modinsobj &select,
		const UpdateObj_CB& cb) = 0;

    /**
     * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
     *
     * @param  select 查询语句
     * @param  select_res 查询结果
     * @return int =0执行成功, != 0失败
     */
    virtual int Execute(const std::string& nServerID, const storesvr_sqldata::storesvr_execute &select,
                          const Execute_CB& cb) = 0;
};
