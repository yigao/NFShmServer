// -------------------------------------------------------------------------
//    @FileName         :    NFIAsySqlModule.h
//    @Author           :    gaoyi
//    @Date             :    23-9-12
//    @Email			:    445267987@qq.com
//    @Module           :    NFIAsySqlModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIAsycModule.h"

class NFIAsySqlModule :  public NFIAsycModule
{
public:
    NFIAsySqlModule(NFIPluginManager* p) : NFIAsycModule(p)
    {

    }

    virtual ~NFIAsySqlModule()
    {

    }

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
    virtual int SelectByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_sel &select, bool useCache,
                             const SelectByCond_CB& cb) = 0;

    /**
     * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
     *
     * @param  select 查询语句
     * @param  message 表结构体
     * @param  select_res 查询结果
     * @return int =0执行成功, != 0失败
     */
    virtual int SelectObj(const std::string& nServerID, const storesvr_sqldata::storesvr_selobj &select, bool useCache,
                          const SelectObj_CB& cb) = 0;

    /**
     * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
     *
     * @param  select 查询语句
     * @param  select_res 查询结果
     * @return int =0执行成功, != 0失败
     */
    virtual int DeleteByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_del &select, bool useCache,
                             const DeleteByCond_CB& cb) = 0;

    /**
     * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
     *
     * @param  select 查询语句
     * @param  select_res 查询结果
     * @return int =0执行成功, != 0失败
     */
    virtual int DeleteObj(const std::string& nServerID, const storesvr_sqldata::storesvr_delobj &select, bool useCache,
                          const DeleteObj_CB& cb) = 0;

    /**
     * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
     *
     * @param  select 查询语句
     * @param  select_res 查询结果
     * @return int =0执行成功, != 0失败
     */
    virtual int InsertObj(const std::string& nServerID, const storesvr_sqldata::storesvr_insertobj &select, bool useCache,
                          const InsertObj_CB& cb) = 0;

    /**
     * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
     *
     * @param  select 查询语句
     * @param  select_res 查询结果
     * @return int =0执行成功, != 0失败
     */
    virtual int ModifyByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_mod &select, bool useCache,
                             const ModifyByCond_CB& cb) = 0;

    virtual int ModifyObj(const std::string& nServerID, const storesvr_sqldata::storesvr_modobj &select, bool useCache,
                          const ModifyObj_CB& cb) = 0;

    /**
     * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
     *
     * @param  select 查询语句
     * @param  select_res 查询结果
     * @return int =0执行成功, != 0失败
     */
    virtual int UpdateByCond(const std::string& nServerID, const storesvr_sqldata::storesvr_update &select, bool useCache,
                             const UpdateByCond_CB& cb) = 0;

    virtual int UpdateObj(const std::string& nServerID, const storesvr_sqldata::storesvr_updateobj &select, bool useCache,
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

    /**
     * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
     *
     * @param  select 查询语句
     * @param  select_res 查询结果
     * @return int =0执行成功, != 0失败
     */
    virtual int ExecuteMore(const std::string& nServerID, const storesvr_sqldata::storesvr_execute_more &select,
                            const ExecuteMore_CB& cb) = 0;
};
