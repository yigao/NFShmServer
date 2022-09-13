// -------------------------------------------------------------------------
//    @FileName         :    NFStat.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPlatform.h"

#include <unordered_map>
#include <stdint.h>

/// @brief 资源类统计结果
class ResourceStatItem
{
public:
	float _average_value;
	float _max_value;
	float _min_value;

	ResourceStatItem()
	{
		_average_value = 0;
		_max_value = 0;
		_min_value = 0;
	}
};

/// @brief 消息类统计结果
class MessageStatItem
{
public:
	float _failure_rate;
	std::unordered_map<int32_t, uint32_t> _result;
	uint32_t _average_cost_ms;
	uint32_t _max_cost_ms;
	uint32_t _min_cost_ms;

	MessageStatItem()
	{
		_failure_rate = 0;
		_average_cost_ms = 0;
		_max_cost_ms = 0;
		_min_cost_ms = UINT32_MAX;
	}
};

typedef std::unordered_map<std::string, ResourceStatItem> ResourceStatResult;
typedef std::unordered_map<std::string, MessageStatItem> MessageStatResult;

/// @brief 基础的统计模块，只提供数据的记录和计算，数据的使用交给调用者
class NFStat
{
public:
	NFStat() : m_message_counts(0), m_failure_message_counts(0)
	{
	}

	~NFStat()
	{
	}

	/// @brief 清理已经记录的数据
	void Clear();

	/// @brief 添加资源统计项，资源类统计一般定时采样，周期输出(比例、平均、最大、最小等)
	/// @param name 资源项名称，要求非空
	/// @param value 采样值
	/// @return 0 成功
	/// @return 非0 失败
	int32_t AddResourceItem(const std::string& name, float value);

	/// @brief 添加消息统计
	/// @param name 消息标识，如消息名，要求非空
	/// @param result 消息处理结果，0表示成功，非0为错误码，表示失败
	/// @param time_cost_ms 消息处理时延，单位毫秒
	/// @return 0 成功
	/// @return 非0 失败
	int32_t AddMessageItem(const std::string& name, int32_t result, int32_t time_cost_ms);

	/// @brief 添加消息统计，如果无此消息的统计则增加一个统计项，值为0，如果有
	/// @param name 消息标识，如消息名，要求非空
	/// @return 0 成功
	/// @return 非0 失败
	int32_t AddMessageItem(const std::string& name);

	/// @brief 按名字获取资源型统计结果
	/// @return NULL 失败 无此名字的统计
	/// @return 非NULL 成功
	const ResourceStatItem* GetResourceResultByName(const std::string& name);

	/// @brief 按名字获取消息型统计结果
	/// @return NULL 失败 无此名字的统计
	/// @return 非NULL 成功
	const MessageStatItem* GetMessageResultByName(const std::string& name);

	/// @brief 获取所有资源型统计结果
	const ResourceStatResult* GetAllResourceResults();

	/// @brief 获取所有消息型统计结果
	const MessageStatResult* GetAllMessageResults();

	/// @brief 获取所有消息数
	uint32_t GetAllMessageCounts() const;

	/// @brief 获取所有失败的消息数
	uint32_t GetAllFailureMessageCounts() const;

private:
	// 资源类统计中的临时数据
	class ResourceStatTempData
	{
	public:
		uint32_t _count;
		float _total_value;
		ResourceStatItem* _result;

		ResourceStatTempData()
		{
			_count = 0;
			_total_value = 0;
			_result = nullptr;
		}
	};

	// 消息类统计中的临时数据
	class MessageStatTempData
	{
	public:
		int64_t _total_count;
		int64_t _total_cost_ms;
		float _failure_count;
		MessageStatItem* _result;

		MessageStatTempData()
		{
			_total_count = 0;
			_failure_count = 0;
			_total_cost_ms = 0;
			_result = nullptr;
		}
	};

	static void CalculateResourceStatResult(ResourceStatTempData* resource_stat_temp);
	static void CalculateMessageStatResult(MessageStatTempData* message_stat_temp);

private:
	uint32_t m_message_counts;
	uint32_t m_failure_message_counts;
	ResourceStatResult m_resource_stat_result;
	MessageStatResult m_message_stat_result;

	// 统计过程中的临时数据
	typedef std::unordered_map<std::string, ResourceStatTempData> ResourceStatTemp;
	typedef std::unordered_map<std::string, MessageStatTempData> MessageStatTemp;
	ResourceStatTemp m_resource_stat_temp;
	MessageStatTemp m_message_stat_temp;
};

