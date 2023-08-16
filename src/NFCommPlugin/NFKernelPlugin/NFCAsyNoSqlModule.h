// -------------------------------------------------------------------------
//    @FileName         :    NFCAsyNoSqlModule.h
//    @Author           :    gaoyi
//    @Date             :    23-8-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFCAsyNoSqlModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIAsyDBModule.h"
#include "NFComm/NFPluginModule/NFIEventModule.h"
#include "NFCMysqlDriverManager.h"
#include "NFCMysqlDriver.h"
#include "NFComm/NFPluginModule/NFEventDefine.h"
#include "NFComm/NFPluginModule/NFIAsyNosqlModule.h"

class NFCAsyNoSqlModule : public NFIAsyNosqlModule
{
public:
    NFCAsyNoSqlModule(NFIPluginManager* p);

    virtual ~NFCAsyNoSqlModule();
    virtual bool Execute() override;

    virtual bool InitActorPool(int maxActorNum) override;
    /**
     * @brief 添加Mysql链接
     *
     * @return bool					成功或失败
     */
    virtual int AddDBServer(const std::string& nServerID, const std::string& noSqlIp, int nosqlPort, const std::string& noSqlPass) override;

    /**
     * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
     *
     * @param  select 查询语句
     * @param  message 表结构体
     * @param  select_res 查询结果
     * @return int =0执行成功, != 0失败
     */
    virtual int SelectObj(const std::string& nServerID, const storesvr_sqldata::storesvr_selobj &select, const SelectObj_CB& cb) override;

    /**
     * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
     *
     * @param  select 查询语句
     * @param  select_res 查询结果
     * @return int =0执行成功, != 0失败
     */
    virtual int DeleteObj(const std::string& nServerID, const storesvr_sqldata::storesvr_delobj &select, const DeleteObj_CB& cb) override;

    /**
     * @brief 通过select结构体， 从数据库获取数据，并把结果放到selelct_res
     *
     * @param  select 查询语句
     * @param  select_res 查询结果
     * @return int =0执行成功, != 0失败
     */
    virtual int InsertObj(const std::string& nServerID, const storesvr_sqldata::storesvr_insertobj &select, const InsertObj_CB& cb) override;

    virtual int ModifyObj(const std::string& nServerID, const storesvr_sqldata::storesvr_modobj &select, const ModifyObj_CB& cb) override;

    virtual int UpdateObj(const std::string& nServerID, const storesvr_sqldata::storesvr_updateobj &select, const UpdateObj_CB& cb) override;
private:
    uint64_t mnLastCheckTime;
    bool m_initComponet;
};