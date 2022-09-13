#include <NFComm/NFPluginModule/NFCheck.h>
#include <NFComm/NFPluginModule/NFProtobufCommon.h>
#include "NFRedisDriver.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"

NFRedisDriver::NFRedisDriver()
{
	mnPort = 0;
	mbBusy = false;
	mbAuthed = false;
    m_pRedisClientSocket = new NFRedisClientSocket();
}

bool NFRedisDriver::Enable()
{
	return m_pRedisClientSocket->IsConnect();
}

bool NFRedisDriver::Authed()
{
	return mbAuthed;
}

bool NFRedisDriver::Busy()
{
	return mbBusy;
}

bool NFRedisDriver::Connect(const std::string &ip, const int port, const std::string &auth)
{
    int64_t nFD = m_pRedisClientSocket->Connect(ip, port);
	if (nFD > 0)
	{
		mstrIP = ip;
		mnPort = port;
		mstrAuthKey = auth;
		while(m_pRedisClientSocket->IsNone())
        {
            Execute();
            NFSLEEP(1000);
        }
		if (!auth.empty())
        {
            if (Enable() && !Authed())
            {
                if (!AUTH(GetAuthKey()))
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "Redis AUTH failed! ip:{} port:{} auth:{}", ip, port, auth);
                    return false;
                }
            }
        }

		return true;
	}

    return false;
}

bool NFRedisDriver::SelectDB(int dbnum)
{
    NFRedisCommand cmd(GET_NAME(Select));
    cmd << dbnum;

    // if password error, redis will return REDIS_REPLY_ERROR
    // pReply will be null
    NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
    if (pReply == nullptr)
    {
        return false;
    }

    if (pReply->type == REDIS_REPLY_STATUS)
    {
        if (std::string("OK") == std::string(pReply->str, pReply->len) ||
            std::string("ok") == std::string(pReply->str, pReply->len))
        {
            return true;
        }
    }

    return false;
}

bool NFRedisDriver::KeepLive()
{
    return false;
}

bool NFRedisDriver::ReConnect()
{
    this->mbAuthed = false;
    return m_pRedisClientSocket->ReConnect(mstrIP, mnPort);
}

bool NFRedisDriver::IsConnect()
{
	if (m_pRedisClientSocket)
	{
		return m_pRedisClientSocket->IsConnect();
	}

	return false;
}

bool NFRedisDriver::Execute()
{
    m_pRedisClientSocket->Execute();

    return true;
}

int NFRedisDriver::SelectObj(const storesvr_sqldata::storesvr_selobj &select,
                              storesvr_sqldata::storesvr_selobj_res &select_res) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string tableName = select.baseinfo().tbname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    int iRet = 0;
    std::map<std::string, std::string> keyMap;
    iRet = CreateSql(select, keyMap);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed:{}");
    if (keyMap.size() != 1)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateSql Failed!, field not right:{} -- dbName:{} modkey:{}", NFCommon::tostr(keyMap), select.baseinfo().tbname(), select.mod_key());
        return -1;
    }

    *select_res.mutable_baseinfo() = select.baseinfo();
    select_res.mutable_sel_opres()->set_mod_key(select.mod_key());
    std::string errmsg;

    std::string db_field = select.baseinfo().tbname();
    std::string db_key = keyMap.begin()->second;
    bool bRet = SelectDB(NFREDIS_DB1);
    if (!bRet)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "SelectDB:{} Failed! dbName:{} modkey:{}", NFREDIS_DB1, select.baseinfo().tbname(), select.mod_key());
        return -1;
    }

    std::string value;
    bRet = HGET(db_key, db_field, value);
    if (!bRet)
    {
        return 1;
    }

    std::string proto_fullname = "proto_ff." + select.baseinfo().tbname();

    const ::google::protobuf::Message *pDefaultMessage = NFProtobufCommon::FindMessageTypeByName(proto_fullname);

    CHECK_EXPR(pDefaultMessage, -1,
               "NFProtobufCommon::FindMessageTypeByName:{} Failed", proto_fullname);

    //通过protobuf默认便利new出来一个新的proto_fullname变量
    ::google::protobuf::Message *pMessageObject = pDefaultMessage->New();
    CHECK_EXPR(pMessageObject, -1, "{} New Failed", proto_fullname);

    bRet = pMessageObject->ParseFromString(value);

    if (bRet && pMessageObject != NULL) {
        select_res.set_sel_record(pMessageObject->SerializeAsString());
        NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "{}", pMessageObject->Utf8DebugString());
    } else {
        NFLogError(NF_LOG_MYSQL_PLUGIN, 0, "ParseFromString Failed, tableName:{}, key:{}",
                  select.baseinfo().tbname(), db_key);
    }
    if (pMessageObject != NULL)
    {
        NF_SAFE_DELETE(pMessageObject);
    }
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFRedisDriver::InsertObj(const storesvr_sqldata::storesvr_modobj &select) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string tableName = select.baseinfo().tbname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    int iRet = 0;
    std::map<std::string, std::string> keyMap;
    iRet = CreateSql(select, keyMap);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed:{}");
    if (keyMap.size() != 1)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateSql Failed!, field not right:{} -- dbName:{} modkey:{}", NFCommon::tostr(keyMap), select.baseinfo().tbname(), select.mod_key());
        return -1;
    };

    std::string db_field = select.baseinfo().tbname();
    std::string db_key = keyMap.begin()->second;
    bool bRet = SelectDB(NFREDIS_DB1);
    if (!bRet)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "SelectDB:{} Failed! dbName:{} modkey:{}", NFREDIS_DB1, select.baseinfo().tbname(), select.mod_key());
        return -1;
    }

    bRet = HSET(db_key, db_field, select.mod_record());
    if (!bRet)
    {
        return 1;
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFRedisDriver::InsertObj(const storesvr_sqldata::storesvr_ins &select) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string tableName = select.baseinfo().tbname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    int iRet = 0;
    std::map<std::string, std::string> keyMap;
    iRet = CreateSql(select, keyMap);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed:{}");
    if (keyMap.size() != 1)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateSql Failed!, field not right:{} -- dbName:{} modkey:{}", NFCommon::tostr(keyMap), select.baseinfo().tbname(), select.mod_key());
        return -1;
    };

    std::string db_field = select.baseinfo().tbname();
    std::string db_key = keyMap.begin()->second;
    bool bRet = SelectDB(NFREDIS_DB1);
    if (!bRet)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "SelectDB:{} Failed! dbName:{} modkey:{}", NFREDIS_DB1, select.baseinfo().tbname(), select.mod_key());
        return -1;
    }

    bRet = HSET(db_key, db_field, select.ins_record());
    if (!bRet)
    {
        return 1;
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int
NFRedisDriver::CreateSql(const storesvr_sqldata::storesvr_selobj &select, std::map<std::string, std::string> &keyMap) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string tableName = select.baseinfo().tbname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    std::string full_name = "proto_ff." + tableName;
    google::protobuf::Message *pMessageObject = NFProtobufCommon::CreateMessageByName(full_name);
    CHECK_EXPR(pMessageObject, -1, "NFProtobufCommon::CreateMessageByName:{} Failed", full_name);
    CHECK_EXPR(pMessageObject->ParseFromString(select.sel_record()), -1, "ParseFromString Failed:{}", full_name);

    NFProtobufCommon::GetMapFieldsFromMessage(*pMessageObject, keyMap, true, true);
    delete pMessageObject;
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFRedisDriver::DeleteObj(const storesvr_sqldata::storesvr_delobj &select) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    int iRet = 0;
    std::map<std::string, std::string> keyMap;
    iRet = CreateSql(select, keyMap);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed");
    if (keyMap.size() != 1)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateSql Failed!, field not right:{} -- dbName:{} modkey:{}", NFCommon::tostr(keyMap), select.baseinfo().tbname(), select.mod_key());
        return -1;
    }

    std::string db_field = select.baseinfo().tbname();
    std::string db_key = keyMap.begin()->second;
    bool bRet = SelectDB(NFREDIS_DB1);
    if (!bRet)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "SelectDB:{} Failed! dbName:{} modkey:{}", NFREDIS_DB1, select.baseinfo().tbname(), select.mod_key());
        return -1;
    }

    std::string errmsg;
    bRet = HDEL(db_key, db_field);
    if (iRet == false) {
        return -1;
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFRedisDriver::DeleteObj(const storesvr_sqldata::storesvr_ins &select)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    int iRet = 0;
    std::map<std::string, std::string> keyMap;
    iRet = CreateSql(select, keyMap);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed");
    if (keyMap.size() != 1)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateSql Failed!, field not right:{} -- dbName:{} modkey:{}", NFCommon::tostr(keyMap), select.baseinfo().tbname(), select.mod_key());
        return -1;
    }

    std::string db_field = select.baseinfo().tbname();
    std::string db_key = keyMap.begin()->second;
    bool bRet = SelectDB(NFREDIS_DB1);
    if (!bRet)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "SelectDB:{} Failed! dbName:{} modkey:{}", NFREDIS_DB1, select.baseinfo().tbname(), select.mod_key());
        return -1;
    }

    std::string errmsg;
    bRet = HDEL(db_key, db_field);
    if (iRet == false) {
        return -1;
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFRedisDriver::DeleteObj(const storesvr_sqldata::storesvr_modobj &select)
{
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    int iRet = 0;
    std::map<std::string, std::string> keyMap;
    iRet = CreateSql(select, keyMap);
    CHECK_EXPR(iRet == 0, -1, "CreateSql Failed");
    if (keyMap.size() != 1)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateSql Failed!, field not right:{} -- dbName:{} modkey:{}", NFCommon::tostr(keyMap), select.baseinfo().tbname(), select.mod_key());
        return -1;
    }

    std::string db_field = select.baseinfo().tbname();
    std::string db_key = keyMap.begin()->second;
    bool bRet = SelectDB(NFREDIS_DB1);
    if (!bRet)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "SelectDB:{} Failed! dbName:{} modkey:{}", NFREDIS_DB1, select.baseinfo().tbname(), select.mod_key());
        return -1;
    }

    std::string errmsg;
    bRet = HDEL(db_key, db_field);
    if (iRet == false) {
        return -1;
    }

    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFRedisDriver::CreateSql(const storesvr_sqldata::storesvr_delobj &select, std::map<std::string, std::string> &keyMap) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string tableName = select.baseinfo().tbname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    std::string full_name = "proto_ff." + tableName;
    google::protobuf::Message *pMessageObject = NFProtobufCommon::CreateMessageByName(full_name);
    CHECK_EXPR(pMessageObject, -1, "NFProtobufCommon::CreateMessageByName:{} Failed", full_name);
    CHECK_EXPR(pMessageObject->ParseFromString(select.del_record()), -1, "ParseFromString Failed:{}", full_name);

    NFProtobufCommon::GetMapFieldsFromMessage(*pMessageObject, keyMap, true, true);
    delete pMessageObject;
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFRedisDriver::CreateSql(const storesvr_sqldata::storesvr_ins &select, std::map<std::string, std::string> &keyMap) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string tableName = select.baseinfo().tbname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    std::string full_name = "proto_ff." + tableName;
    google::protobuf::Message *pMessageObject = NFProtobufCommon::CreateMessageByName(full_name);
    CHECK_EXPR(pMessageObject, -1, "NFProtobufCommon::CreateMessageByName:{} Failed", full_name);
    CHECK_EXPR(pMessageObject->ParseFromString(select.ins_record()), -1, "ParseFromString Failed:{}", full_name);

    NFProtobufCommon::GetMapFieldsFromMessage(*pMessageObject, keyMap, true, true);
    delete pMessageObject;
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

int NFRedisDriver::CreateSql(const storesvr_sqldata::storesvr_modobj &select, std::map<std::string, std::string> &keyMap) {
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- begin --");
    std::string tableName = select.baseinfo().tbname();
    CHECK_EXPR(tableName.size() > 0, -1, "talbeName empty!");

    std::string full_name = "proto_ff." + tableName;
    google::protobuf::Message *pMessageObject = NFProtobufCommon::CreateMessageByName(full_name);
    CHECK_EXPR(pMessageObject, -1, "NFProtobufCommon::CreateMessageByName:{} Failed", full_name);
    CHECK_EXPR(pMessageObject->ParseFromString(select.mod_record()), -1, "ParseFromString Failed:{}", full_name);

    NFProtobufCommon::GetMapFieldsFromMessage(*pMessageObject, keyMap, false, true);
    delete pMessageObject;
    NFLogTrace(NF_LOG_MYSQL_PLUGIN, 0, "-- end --");
    return 0;
}

NF_SHARE_PTR<redisReply> NFRedisDriver::BuildSendCmd(const NFRedisCommand& cmd)
{
	mbBusy = true;

	if (!IsConnect())
	{
		mbBusy = false;

		ReConnect();
		return nullptr;
	}
	else
	{
		std::string msg = cmd.Serialize();
		if (msg.empty())
		{
			mbBusy = false;
			return nullptr;
		}
		int nRet = m_pRedisClientSocket->Write(msg.data(), msg.length());
		if (nRet != 0)
		{
			mbBusy = false;
			return nullptr;
		}
	}
	

	return ParseForReply();
}

NF_SHARE_PTR<redisReply> NFRedisDriver::ParseForReply()
{
	struct redisReply* reply = nullptr;
	while (true)
	{
		//std::this_thread::sleep_for(std::chrono::milliseconds(1));

		// When the buffer is empty, reply will be null
		int ret = redisReaderGetReply(m_pRedisClientSocket->GetRedisReader(), (void**)&reply);
		if (ret == REDIS_OK && reply != nullptr)
		{
			break;
		}

		Execute();

		if (!IsConnect())
		{
			ReConnect();
			break;
		}
	}

	mbBusy = false;

	if (reply == nullptr)
	{
		return nullptr;
	}

	if (REDIS_REPLY_ERROR == reply->type)
	{
		// write log
		freeReplyObject(reply);
		return nullptr;
	}

	return NF_SHARE_PTR<redisReply>(reply, [](redisReply* r) { if (r) freeReplyObject(r); });
}

bool NFRedisDriver::AUTH(const std::string& auth)
{
	NFRedisCommand cmd(GET_NAME(AUTH));
	cmd << auth;

	// if password error, redis will return REDIS_REPLY_ERROR
	// pReply will be null
	NF_SHARE_PTR<redisReply> pReply = BuildSendCmd(cmd);
	if (pReply == nullptr)
	{
		return false;
	}

	if (pReply->type == REDIS_REPLY_STATUS)
	{
		if (std::string("OK") == std::string(pReply->str, pReply->len) ||
			std::string("ok") == std::string(pReply->str, pReply->len))
		{
			mbAuthed = true;
			return true;
		}
	}
	
	return false;
}
