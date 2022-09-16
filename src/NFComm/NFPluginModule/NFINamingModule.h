// -------------------------------------------------------------------------
//    @FileName         :    NFINamingModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFINamingModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFIModule.h"
#include <vector>
#include <string>
#include "NFNaming.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"

#define STORE_SERVER_DB_TITLE "DB"

typedef std::function<void(const string &name, const proto_ff::ServerInfoReport& xData, int32_t errCode)> NFNamingServerWatchFunc;

class NFINamingModule : public NFIModule
{
public:
    NFINamingModule(NFIPluginManager* p) :NFIModule(p)
    {

    }

    virtual ~NFINamingModule()
    {

    }

public:

	virtual proto_ff::ServerInfoReport GetDefaultMasterInfo(NF_SERVER_TYPES eServerType) = 0;
    /// @brief 初始化zookeeper连接
    /// @param host zk地址，如 "127.0.0.1:1888,127.0.0.1:2888"
    /// @param time_out_ms 连接超时时间，单位ms，默认为20s，当<=0时使用默认值
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t InitAppInfo(NF_SERVER_TYPES eServerType, int time_out_ms = 20000) = 0;

    virtual bool IsInitApp(NF_SERVER_TYPES eServerType) = 0;

    virtual void FinishInitApp(NF_SERVER_TYPES eServerType) = 0;

    virtual int32_t RegisterAppInfo(NF_SERVER_TYPES eServerType) = 0;

    virtual int32_t ClearDBInfo(NF_SERVER_TYPES eServerType) = 0;

    virtual int32_t RegisterDBInfo(NF_SERVER_TYPES eServerType, const std::string& content) = 0;

    /// @brief 同步获取名字的地址列表
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @param urls 地址列表
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t GetTcpUrlsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, std::vector<std::string>& tcpUrl) = 0;

    /// @brief 同步获取名字的地址列表
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @param urls 地址列表
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t GetBusUrlsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, std::vector<std::string>& busUrl) = 0;

    /// @brief 同步获取名字的地址列表
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @param urls 地址列表
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t GetRouteAgentsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, std::vector<std::string>& busUrl) = 0;

    /// @brief 同步获取名字的地址列表
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @param urls 地址列表
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t GetExternalServerIpsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, std::vector<std::string>& busUrl) = 0;

    /// @brief 同步获取名字的地址列表
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @param urls 地址列表
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t GetExternalServerPortsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, std::vector<std::string>& busUrl) = 0;

    virtual int32_t GetDBNameByServer(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, uint32_t destBusId, std::vector<std::string>& dbName) = 0;

    /// @brief 同步监控名字变化
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    /// @note  注册监控成功时会在此接口中回调 CbNodeChanged 通知地址信息。\n
    ///        即使当前节点不存在或其它原因失败导致zk节点上没有添加成功监控点，在恢复后也可以监控
    virtual int32_t WatchTcpUrls(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, const NFNamingServerWatchFunc& wc) = 0;

    /// @brief 同步监控名字变化
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    /// @note  注册监控成功时会在此接口中回调 CbNodeChanged 通知地址信息。\n
    ///        即使当前节点不存在或其它原因失败导致zk节点上没有添加成功监控点，在恢复后也可以监控
    virtual int32_t WatchBusUrls(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, const NFNamingServerWatchFunc& wc) = 0;
public:

    /// @brief 初始化zookeeper连接
    /// @param host zk地址，如 "127.0.0.1:1888,127.0.0.1:2888"
    /// @param time_out_ms 连接超时时间，单位ms，默认为20s，当<=0时使用默认值
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t Init(NF_SERVER_TYPES eServerType, const std::string& host, int32_t time_out_ms = 20000) = 0;

    /// @brief 设置查询的缓存
    /// @param use_cache 是否启动查询的缓存
    /// @param refresh_time_ms 缓存的自动刷新时间，最小为5000
    /// @param invaild_time_ms 缓存的失效时间，最小为10000且大于刷新时间
    /// @return 0成功
    virtual int32_t SetCache(NF_SERVER_TYPES eServerType, bool use_cache = true, int32_t refresh_time_ms = 300000, int32_t invaild_time_ms = 1800000) = 0;
public:
    // 实现Naming接口

    /// @brief 设置app信息和appkey，Init调用后调用此接口添加需要访问的各个app的授权信息
    /// @param app_id 应用ID
    /// @param app_key 应用的key
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t SetAppInfo(NF_SERVER_TYPES eServerType, const std::string& app_id, const std::string& app_key) = 0;

    virtual int32_t Register(NF_SERVER_TYPES eServerType, const std::string& name,
                             const std::string& url,
                             int64_t instance_id = 0) = 0;

    /// @brief 注销名字同步接口
    /// @param name 名字(带完整路径)
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    /// @note 对于同步接口调用如果不设置协程调度器或不在协程内调用会一直阻塞等待
    virtual int32_t UnRegister(NF_SERVER_TYPES eServerType, const std::string& name, int64_t instance_id = 0) = 0;

    /// @brief 注销名字同步接口
    /// @param name 名字(带完整路径)
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    /// @note 对于同步接口调用如果不设置协程调度器或不在协程内调用会一直阻塞等待
    virtual int32_t ForceDelete(NF_SERVER_TYPES eServerType, const std::string& name, const std::string& url, int64_t instance_id = 0) = 0;

    /// @brief 同步获取名字的地址列表
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @param urls 地址列表
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t GetUrlsByName(NF_SERVER_TYPES eServerType, const std::string& name, std::vector<std::string>* urls) = 0;

    /// @brief 同步监控名字变化
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    /// @note  注册监控成功时会在此接口中回调 CbNodeChanged 通知地址信息。\n
    ///        即使当前节点不存在或其它原因失败导致zk节点上没有添加成功监控点，在恢复后也可以监控
    virtual int32_t WatchName(NF_SERVER_TYPES eServerType, const std::string& name, const NFNamingWatchFunc& wc) = 0;
};


