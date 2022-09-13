// -------------------------------------------------------------------------
//    @FileName         :    NFStat.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include "NFStat.h"

void NFStat::Clear()
{
	m_message_counts = 0;
	m_failure_message_counts = 0;
	m_resource_stat_temp.clear();
	m_message_stat_temp.clear();
	m_resource_stat_result.clear();
	m_message_stat_result.clear();
}

int32_t NFStat::AddResourceItem(const std::string& name, float value)
{
	if (name.empty())
	{
		return -1;
	}

	ResourceStatItem& item = m_resource_stat_result[name];
	ResourceStatTempData& temp = m_resource_stat_temp[name];
	temp._result = &item;
	temp._count++;
	temp._total_value += value;
	value > item._max_value ? item._max_value = value : value;
	value < item._min_value ? item._min_value = value : value;

	return 0;
}

int32_t NFStat::AddMessageItem(const std::string& name, int32_t result, int32_t time_cost_ms)
{
	if (name.empty())
	{
		return -1;
	}

	m_message_counts++;

	MessageStatItem& item = m_message_stat_result[name];
	MessageStatTempData& temp = m_message_stat_temp[name];
	temp._result = &item;
	temp._total_count++;
	if (result != 0)
	{
		temp._failure_count++;
		m_failure_message_counts++;
	}
	temp._total_cost_ms += time_cost_ms;

	uint32_t time_cost = static_cast<uint32_t>(time_cost_ms);
	time_cost > item._max_cost_ms ? item._max_cost_ms = time_cost : time_cost;
	time_cost < item._min_cost_ms ? item._min_cost_ms = time_cost : time_cost;
	item._result[result]++;

	return 0;
}

int32_t NFStat::AddMessageItem(const std::string& name)
{
	if (name.empty())
	{
		return -1;
	}

	MessageStatItem& item = m_message_stat_result[name];
	MessageStatTempData& temp = m_message_stat_temp[name];
	temp._result = &item;

	item._result[0];

	return 0;
}

const ResourceStatItem* NFStat::GetResourceResultByName(const std::string& name)
{
	std::unordered_map<std::string, ResourceStatTempData>::iterator it;
	it = m_resource_stat_temp.find(name);
	if (m_resource_stat_temp.end() == it)
	{
		return NULL;
	}

	CalculateResourceStatResult(&(it->second));

	return it->second._result;
}

const MessageStatItem* NFStat::GetMessageResultByName(const std::string& name)
{
	std::unordered_map<std::string, MessageStatTempData>::iterator it;
	it = m_message_stat_temp.find(name);
	if (m_message_stat_temp.end() == it)
	{
		return NULL;
	}

	CalculateMessageStatResult(&(it->second));

	return it->second._result;
}

const ResourceStatResult* NFStat::GetAllResourceResults()
{
	std::unordered_map<std::string, ResourceStatTempData>::iterator it;
	for (it = m_resource_stat_temp.begin(); it != m_resource_stat_temp.end(); ++it)
	{
		CalculateResourceStatResult(&(it->second));
	}

	return &m_resource_stat_result;
}

const MessageStatResult* NFStat::GetAllMessageResults()
{
	std::unordered_map<std::string, MessageStatTempData>::iterator it;
	for (it = m_message_stat_temp.begin(); it != m_message_stat_temp.end(); ++it)
	{
		CalculateMessageStatResult(&(it->second));
	}

	return &m_message_stat_result;
}

uint32_t NFStat::GetAllMessageCounts() const
{
	return m_message_counts;
}

uint32_t NFStat::GetAllFailureMessageCounts() const
{
	return m_failure_message_counts;
}

void NFStat::CalculateResourceStatResult(ResourceStatTempData* resource_stat_temp)
{
	if (0 == resource_stat_temp->_count)
	{
		return;
	}
	ResourceStatItem* result = resource_stat_temp->_result;
	result->_average_value = resource_stat_temp->_total_value / resource_stat_temp->_count;
}

void NFStat::CalculateMessageStatResult(MessageStatTempData* message_stat_temp)
{
	if (0 == message_stat_temp->_total_count)
	{
		return;
	}
	MessageStatItem* result = message_stat_temp->_result;
	result->_failure_rate = message_stat_temp->_failure_count / message_stat_temp->_total_count;
	result->_average_cost_ms = message_stat_temp->_total_cost_ms / message_stat_temp->_total_count;
}

