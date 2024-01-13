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

enum {
    NF_ASY_TASK_READ_GROUP = 0,
    NF_ASY_TASK_WRITE_GROUP = 1,
    NF_ASY_TASK_MAX_GROUP = 2,
};

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
