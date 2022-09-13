// -------------------------------------------------------------------------
//    @FileName         :    NFCNamingModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCNamingModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFINamingModule.h"
#include "NFComm/NFPluginModule/NFNaming.h"

class NFCNamingModule : public NFINamingModule
{
public:
    explicit NFCNamingModule(NFIPluginManager* p);

    virtual ~NFCNamingModule();

    bool BeforeShut() override;
    bool Shut() override;
    bool Execute() override;
    bool OnReloadPlugin() override;
public:
	virtual proto_ff::ServerInfoReport GetDefaultMasterInfo(NF_SERVER_TYPES eServerType);
    /// @brief 初始化zookeeper连接
    /// @param host zk地址，如 "127.0.0.1:1888,127.0.0.1:2888"
    /// @param time_out_ms 连接超时时间，单位ms，默认为20s，当<=0时使用默认值
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t InitAppInfo(NF_SERVER_TYPES eServerType, int time_out_ms = 20000) override;

    virtual bool IsInitApp(NF_SERVER_TYPES eServerType) override;

    virtual void FinishInitApp(NF_SERVER_TYPES eServerType) override;

    virtual int32_t RegisterAppInfo(NF_SERVER_TYPES eServerType) override;

    virtual int32_t RegisterDBInfo(NF_SERVER_TYPES eServerType, const std::string& content) override;

    virtual int32_t ClearDBInfo(NF_SERVER_TYPES eServerType) override;
    virtual int32_t GetDBInfoByName(NF_SERVER_TYPES eServerType, std::vector<std::string>& tcpUrlVec);

    /// @brief 同步获取名字的地址列表
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @param urls 地址列表
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t GetTcpUrlsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, std::vector<std::string>& tcpUrl) override;
    virtual int32_t GetTcpUrlsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, uint32_t busId, std::vector<std::string>& tcpUrl);

    /// @brief 同步获取名字的地址列表
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @param urls 地址列表
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t GetBusUrlsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, std::vector<std::string>& busUrl) override;
    virtual int32_t GetBusUrlsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, uint32_t busId, std::vector<std::string>& busUrl);

    /// @brief 同步获取名字的地址列表
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @param urls 地址列表
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t GetRouteAgentsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, std::vector<std::string>& routeAgent) override;
    virtual int32_t GetRouteAgentsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, uint32_t busId, std::vector<std::string>& routeAgent);

    /// @brief 同步获取名字的地址列表
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @param urls 地址列表
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t GetExternalServerIpsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, std::vector<std::string>& busUrl) override;
    virtual int32_t GetExternalServerIpsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, uint32_t busId, std::vector<std::string>& externalServerIp);

    /// @brief 同步获取名字的地址列表
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @param urls 地址列表
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t GetExternalServerPortsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, std::vector<std::string>& busUrl) override;
    virtual int32_t GetExternalServerPortsByName(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, uint32_t busId, std::vector<std::string>& externalServerPort);


    virtual int32_t GetDBNameByServer(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, uint32_t destBusId, std::vector<std::string>& dbName) override;

    /// @brief 同步监控名字变化
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    /// @note  注册监控成功时会在此接口中回调 CbNodeChanged 通知地址信息。\n
    ///        即使当前节点不存在或其它原因失败导致zk节点上没有添加成功监控点，在恢复后也可以监控
    virtual int32_t WatchTcpUrls(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, const NFNamingServerWatchFunc& wc)  override;

    /// @brief 同步监控名字变化
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    /// @note  注册监控成功时会在此接口中回调 CbNodeChanged 通知地址信息。\n
    ///        即使当前节点不存在或其它原因失败导致zk节点上没有添加成功监控点，在恢复后也可以监控
    virtual int32_t WatchBusUrls(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServerType, const NFNamingServerWatchFunc& wc) override;

    virtual int32_t UnInitAppInfo(NF_SERVER_TYPES eServerType);
public:

    /// @brief 初始化zookeeper连接
    /// @param host zk地址，如 "127.0.0.1:1888,127.0.0.1:2888"
    /// @param time_out_ms 连接超时时间，单位ms，默认为20s，当<=0时使用默认值
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t Init(NF_SERVER_TYPES eServerType, const std::string& host, int32_t time_out_ms = 20000) override;

    /// @brief 设置查询的缓存
    /// @param use_cache 是否启动查询的缓存
    /// @param refresh_time_ms 缓存的自动刷新时间，最小为5000
    /// @param invaild_time_ms 缓存的失效时间，最小为10000且大于刷新时间
    /// @return 0成功
    virtual int32_t SetCache(NF_SERVER_TYPES eServerType, bool use_cache = true, int32_t refresh_time_ms = 300000, int32_t invaild_time_ms = 1800000) override;
public:
    // 实现Naming接口

    /// @brief 设置app信息和appkey，Init调用后调用此接口添加需要访问的各个app的授权信息
    /// @param app_id 应用ID
    /// @param app_key 应用的key
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t SetAppInfo(NF_SERVER_TYPES eServerType, const std::string& app_id, const std::string& app_key) override;

    virtual int32_t Register(NF_SERVER_TYPES eServerType, const std::string& name,
                             const std::string& url,
                             int64_t instance_id = 0) override;

    /// @brief 注销名字同步接口
    /// @param name 名字(带完整路径)
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    /// @note 对于同步接口调用如果不设置协程调度器或不在协程内调用会一直阻塞等待
    virtual int32_t UnRegister(NF_SERVER_TYPES eServerType, const std::string& name, int64_t instance_id = 0) override;

    /// @brief 注销名字同步接口
    /// @param name 名字(带完整路径)
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    /// @note 对于同步接口调用如果不设置协程调度器或不在协程内调用会一直阻塞等待
    virtual int32_t ForceDelete(NF_SERVER_TYPES eServerType, const std::string& name, const std::string& url, int64_t instance_id = 0) override;

    /// @brief 同步获取名字的地址列表
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @param urls 地址列表
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    virtual int32_t GetUrlsByName(NF_SERVER_TYPES eServerType, const std::string& name, std::vector<std::string>* urls) override;

    /// @brief 同步监控名字变化
    /// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
    /// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
    /// @note  注册监控成功时会在此接口中回调 CbNodeChanged 通知地址信息。\n
    ///        即使当前节点不存在或其它原因失败导致zk节点上没有添加成功监控点，在恢复后也可以监控
    virtual int32_t WatchName(NF_SERVER_TYPES eServerType, const std::string& name, const NFNamingWatchFunc& wc) override;
private:
    std::vector<NFNaming*> m_namingList;
};
