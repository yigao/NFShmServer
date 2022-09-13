// -------------------------------------------------------------------------
//    @FileName         :    NFZookeeperNaming.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFZookeeperNaming.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFNaming.h"
#include <map>

class NFBusppNaming : public NFNaming
{
public:
	NFBusppNaming() { }
	virtual ~NFBusppNaming() { }

	/// @brief 初始化zookeeper连接
	/// @param host zk地址，如 "127.0.0.1:1888,127.0.0.1:2888"
	/// @param time_out_ms 连接超时时间，单位ms，默认为20s，当<=0时使用默认值
	/// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
	int32_t Init(const std::string& host, int32_t time_out_ms = 20000)
	{
		return 0;
	}

	/// @brief 结束调用回收资源
	/// @return 0成功
	int32_t Fini()
	{
		return 0;
	}

	/// @brief 设置查询的缓存
	/// @param use_cache 是否启动查询的缓存
	/// @param refresh_time_ms 缓存的自动刷新时间，最小为5000
	/// @param invaild_time_ms 缓存的失效时间，最小为10000且大于刷新时间
	/// @return 0成功
	int32_t SetCache(bool use_cache = true, int32_t refresh_time_ms = 300000, int32_t invaild_time_ms = 1800000)
	{
		return 0;
	}
public:
	// 实现Naming接口

	/// @brief 设置app信息和appkey，Init调用后调用此接口添加需要访问的各个app的授权信息
	/// @param app_id 应用ID
	/// @param app_key 应用的key
	/// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
	virtual int32_t SetAppInfo(const std::string& app_id, const std::string& app_key)
	{
		return 0;
	}

	virtual bool IsInitApp() const
	{
		return false;
	}

	virtual void FinishInitApp() { }

	virtual int32_t Register(const std::string& name,
		const std::string& url,
		int64_t instance_id = 0)
	{
		return 0;
	}

	/// @brief 同步注册到名字服务
	/// @param name 名字(带完整路径)
	/// @param urls 地址列表
	/// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
	/// @note 对于同步接口调用如果不设置协程调度器或不在协程内调用会一直阻塞等待
	virtual int32_t Register(const std::string& name, const std::vector<std::string>& urls, int64_t instance_id = 0)
	{
		return 0;
	}

	virtual int32_t RegisterAsync(const std::string& name,
		const std::string& url,
		const NFNamingCbReturnCode& cb,
		int64_t instance_id = 0)
	{
		return 0;
	}

	/// @brief 异步注册到名字服务
	/// @param name 名字(带完整路径)
	/// @param urls 地址列表
	/// @param cb 异步操作结果的回调返回
	/// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
	virtual int32_t RegisterAsync(const std::string& name,
		const std::vector<std::string>& urls,
		const NFNamingCbReturnCode& cb,
		int64_t instance_id = 0)
	{
		return 0;
	}

	/// @brief 注销名字同步接口
	/// @param name 名字(带完整路径)
	/// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
	/// @note 对于同步接口调用如果不设置协程调度器或不在协程内调用会一直阻塞等待
	virtual int32_t UnRegister(const std::string& name, int64_t instance_id = 0)
	{
		return 0;
	}

	/// @brief 注销名字同步接口
	/// @param name 名字(带完整路径)
	/// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
	/// @note 对于同步接口调用如果不设置协程调度器或不在协程内调用会一直阻塞等待
	virtual int32_t ForceDelete(const std::string& name, const std::string& url, int64_t instance_id = 0)
	{
		return 0;
	}

	virtual int32_t ForceDeleteAsync(const std::string& name,
		const std::string& url,
		const NFNamingCbReturnCode& cb,
		int64_t instance_id = 0)
	{
		return 0;
	}

	virtual int32_t ForceDeleteAsync(const std::string& name,
		const std::vector<std::string>& urls,
		const NFNamingCbReturnCode& cb,
		int64_t instance_id = 0)
	{
		return 0;
	}

	/// @brief 注销名字异步接口
	/// @param name 名字(带完整路径)
	/// @param cb 异步操作结果的回调返回
	/// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
	/// @note 对于同步接口调用如果不设置协程调度器或不在协程内调用会一直阻塞等待
	virtual int32_t UnRegisterAsync(const std::string& name,
		const NFNamingCbReturnCode& cb,
		int64_t instance_id = 0)
	{
		return 0;
	}

	/// @brief 同步获取名字的地址列表
	/// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
	/// @param urls 地址列表
	/// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
	virtual int32_t GetUrlsByName(const std::string& name, std::vector<std::string>* urls)
	{
		return 0;
	}

	/// @brief 异步获取名字的地址列表
	/// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
	/// @param cb 异步操作结果的回调返回
	/// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
	virtual int32_t GetUrlsByNameAsync(const std::string& name, const NFNamingCbReturnValue& cb)
	{
		return 0;
	}

	/// @brief 同步监控名字变化
	/// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
	/// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
	/// @note  注册监控成功时会在此接口中回调 CbNodeChanged 通知地址信息。\n
	///        即使当前节点不存在或其它原因失败导致zk节点上没有添加成功监控点，在恢复后也可以监控
	virtual int32_t WatchName(const std::string& name, const NFNamingWatchFunc& wc)
	{
		return 0;
	}

	/// @brief 异步监控名字变化
	/// @param name 名字(带完整路径，支持*通配符号，格式"/a/b"或"/a*/*b/c*d/*")
	/// @param cb 异步操作结果的回调返回
	/// @return 0成功，其他失败，错误码意义见@ref ZookeeperErrorCode
	/// @note  注册监控成功时，在cb回调前，会通过 CbNodeChanged 通知地址信息。\n
	///        即使当前节点不存在或其它原因失败导致zk节点上没有添加成功监控点，在恢复后也可以监控
	virtual int32_t WatchNameAsync(const std::string& name, const NFNamingWatchFunc& wc, const NFNamingCbReturnCode& cb)
	{
		return 0;
	}

	/// @brief 驱动异步更新
	virtual int32_t Update()
	{
		return 0;
	}

	/// @brief 获取上次的错误信息
	virtual const char* GetLastError() { return "nfbuspp"; }
};

