
#include "NFRedisDriver.h"
#include "NFComm/NFCore/NFLexicalCast.hpp"

bool NFRedisDriver::APPEND(const std::string &key, const std::string &value, int& length)
{
	NFRedisCommand cmd(GET_NAME(APPEND));
    cmd << key;
    cmd << value;

	NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
	if (pReply == nullptr)
	{
		return false;
	}

	if (pReply->type == REDIS_REPLY_INTEGER)
	{
		length = (int)pReply->integer;
	}

	return true;
}

bool NFRedisDriver::DECR(const std::string& key, int64_t& value)
{
	NFRedisCommand cmd(GET_NAME(DECR));
    cmd << key;

	NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
	if (pReply == nullptr)
	{
		return false;
	}

	if (pReply->type == REDIS_REPLY_INTEGER)
	{
		value = pReply->integer;
		
		return true;
	}

	return false;
}

bool NFRedisDriver::DECRBY(const std::string &key, const int64_t decrement, int64_t& value)
{
    NFRedisCommand cmd(GET_NAME(DECRBY));
    cmd << key;
    cmd << decrement;

	NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
	if (pReply == nullptr)
	{
		return false;
	}

	if (pReply->type == REDIS_REPLY_INTEGER)
	{
		value = pReply->integer;
		
		return true;
	}

	return false;
}

bool NFRedisDriver::GETSET(const std::string &key, const std::string &value, std::string &oldValue)
{
    NFRedisCommand cmd(GET_NAME(GETSET));
    cmd << key;
    cmd << value;

	NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
	if (pReply == nullptr)
	{
		return false;
	}

	if (pReply->type == REDIS_REPLY_STRING)
	{
		oldValue = pReply->str;
		
		return true;
	}

	return false;
}

bool NFRedisDriver::INCR(const std::string &key, int64_t& value)
{
    NFRedisCommand cmd(GET_NAME(INCR));
    cmd << key;

	NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
	if (pReply == nullptr)
	{
		return false;
	}

	if (pReply->type == REDIS_REPLY_INTEGER)
	{
		value = pReply->integer;
		
		return true;
	}

	return false;
}

bool NFRedisDriver::INCRBY(const std::string &key, const int64_t increment, int64_t& value)
{
    NFRedisCommand cmd(GET_NAME(INCRBY));
    cmd << key;
    cmd << increment;

	NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
	if (pReply == nullptr)
	{
		return false;
	}

	if (pReply->type == REDIS_REPLY_INTEGER)
	{
		value = pReply->integer;
		
		return true;
	}

	return false;
}

bool NFRedisDriver::INCRBYFLOAT(const std::string &key, const float increment, float& value)
{
    NFRedisCommand cmd(GET_NAME(INCRBYFLOAT));
    cmd << key;
    cmd << increment;

	NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
	if (pReply == nullptr)
	{
		return false;
	}

	bool success = false;
	if (pReply->type == REDIS_REPLY_STRING)
	{
		success = NFStrTo<float>(pReply->str, value);
	}

	return success;
}

bool NFRedisDriver::MGET(const string_vector &keys, string_vector &values)
{
	NFRedisCommand cmd(GET_NAME(MGET));

    for (int i = 0; i < keys.size(); ++i)
    {
        cmd << keys[i];
    }

	NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
	if (pReply == nullptr)
	{
		return false;
	}

	if (pReply->type == REDIS_REPLY_ARRAY)
	{
		for (size_t k = 0; k < pReply->elements; k++)
		{
			if (pReply->element[k]->type == REDIS_REPLY_STRING)
			{
				values.emplace_back(std::move(std::string(pReply->element[k]->str)));
			}
		}
	
		return true;
	}

	return false;
}

void NFRedisDriver::MSET(const string_pair_vector &values)
{
    NFRedisCommand cmd(GET_NAME(MSET));

    for (int i = 0; i < values.size(); ++i)
    {
        cmd << values[i].first;
        cmd << values[i].second;
    }

	NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
	if (pReply != nullptr)
	{
		
	}
}

bool NFRedisDriver::SETEX(const std::string &key, const std::string &value, int time)
{
    NFRedisCommand cmd(GET_NAME(SETEX));
    cmd << key;
    cmd << value;
    cmd << time;

	NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
	if (pReply == nullptr)
	{
		return false;
	}

	return true;
}

bool NFRedisDriver::SETNX(const std::string &key, const std::string &value)
{
    NFRedisCommand cmd(GET_NAME(SETNX));
    cmd << key;
    cmd << value;

	NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
	if (pReply == nullptr)
	{
		return false;
	}

	bool success = false;
	if (pReply->type == REDIS_REPLY_INTEGER)
	{
		success = (bool)pReply->integer;
	}

	return success;
}

bool NFRedisDriver::STRLEN(const std::string &key, int& length)
{
    NFRedisCommand cmd(GET_NAME(STRLEN));
    cmd << key;

	NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
	if (pReply == nullptr)
	{
		return false;
	}

	if (pReply->type == REDIS_REPLY_INTEGER)
	{
		length = (int)pReply->integer;
		
		return length != 0;
	}

	return false;
}

bool NFRedisDriver::SET(const std::string &key, const std::string &value)
{
    NFRedisCommand cmd(GET_NAME(SET));
    cmd << key;
    cmd << value;

	NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
	if (pReply == nullptr)
	{
		return false;
	}

	return true;
}

bool NFRedisDriver::GET(const std::string& key, std::string & value)
{
    NFRedisCommand cmd(GET_NAME(GET));
    cmd << key;

	NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
	if (pReply == nullptr)
	{
		return false;
	}

	if (pReply->type == REDIS_REPLY_STRING)
	{
		value.append(pReply->str, pReply->len);
		
		return true;
	}

	return false;
}
