#include "proto_common_s.h"

namespace proto_ff_s {

tbServerMgr_s::tbServerMgr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbServerMgr_s::CreateInit() {
	id = (uint64_t)0;
	cur_count = (uint32_t)0;
	last_login_time = (uint64_t)0;
	last_logout_time = (uint64_t)0;
	create_time = (uint64_t)0;
	return 0;
}

int tbServerMgr_s::ResumeInit() {
	return 0;
}

void tbServerMgr_s::write_to_pbmsg(::proto_ff::tbServerMgr & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_contract((const char*)contract.Get());
	msg.set_machine_addr((const char*)machine_addr.Get());
	msg.set_ip((const char*)ip.Get());
	msg.set_bus_name((const char*)bus_name.Get());
	msg.set_server_desc((const char*)server_desc.Get());
	msg.set_cur_count((uint32_t)cur_count);
	msg.set_last_login_time((uint64_t)last_login_time);
	msg.set_last_logout_time((uint64_t)last_logout_time);
	msg.set_create_time((uint64_t)create_time);
}

void tbServerMgr_s::read_from_pbmsg(const ::proto_ff::tbServerMgr & msg) {
	memset(this, 0, sizeof(struct tbServerMgr_s));
	id = msg.id();
	contract.Copy(msg.contract());
	machine_addr.Copy(msg.machine_addr());
	ip.Copy(msg.ip());
	bus_name.Copy(msg.bus_name());
	server_desc.Copy(msg.server_desc());
	cur_count = msg.cur_count();
	last_login_time = msg.last_login_time();
	last_logout_time = msg.last_logout_time();
	create_time = msg.create_time();
}

pbMysqlConfig_s::pbMysqlConfig_s() {
	CreateInit();
}

int pbMysqlConfig_s::CreateInit() {
	MysqlPort = (uint32_t)0;
	return 0;
}

int pbMysqlConfig_s::ResumeInit() {
	return 0;
}

void pbMysqlConfig_s::write_to_pbmsg(::proto_ff::pbMysqlConfig & msg) const {
	msg.set_mysqlip(MysqlIp);
	msg.set_mysqlport((uint32_t)MysqlPort);
	msg.set_mysqldbname(MysqlDbName);
	msg.set_mysqluser(MysqlUser);
	msg.set_mysqlpassword(MysqlPassword);
}

void pbMysqlConfig_s::read_from_pbmsg(const ::proto_ff::pbMysqlConfig & msg) {
	memset(this, 0, sizeof(struct pbMysqlConfig_s));
	MysqlIp = msg.mysqlip();
	MysqlPort = msg.mysqlport();
	MysqlDbName = msg.mysqldbname();
	MysqlUser = msg.mysqluser();
	MysqlPassword = msg.mysqlpassword();
}

pbRedisConfig_s::pbRedisConfig_s() {
	CreateInit();
}

int pbRedisConfig_s::CreateInit() {
	RedisPort = (uint32_t)0;
	return 0;
}

int pbRedisConfig_s::ResumeInit() {
	return 0;
}

void pbRedisConfig_s::write_to_pbmsg(::proto_ff::pbRedisConfig & msg) const {
	msg.set_redisip(RedisIp);
	msg.set_redisport((uint32_t)RedisPort);
	msg.set_redispass(RedisPass);
}

void pbRedisConfig_s::read_from_pbmsg(const ::proto_ff::pbRedisConfig & msg) {
	memset(this, 0, sizeof(struct pbRedisConfig_s));
	RedisIp = msg.redisip();
	RedisPort = msg.redisport();
	RedisPass = msg.redispass();
}

tempServerConfig_s::tempServerConfig_s() {
	CreateInit();
}

int tempServerConfig_s::CreateInit() {
	server_id = (uint32_t)0;
	return 0;
}

int tempServerConfig_s::ResumeInit() {
	return 0;
}

void tempServerConfig_s::write_to_pbmsg(::proto_ff::tempServerConfig & msg) const {
	msg.set_server_id((uint32_t)server_id);
	msg.set_server_type(server_type);
	for(int32_t i = 0; i < (int32_t)server_list.size(); ++i) {
		msg.add_server_list(server_list[i]);
	}
	::proto_ff::pbMysqlConfig* temp_mysql = msg.mutable_mysql();
	mysql.write_to_pbmsg(*temp_mysql);
	for(int32_t i = 0; i < (int32_t)redis.size(); ++i) {
		::proto_ff::pbRedisConfig* temp_redis = msg.add_redis();
		redis[i].write_to_pbmsg(*temp_redis);
	}
}

void tempServerConfig_s::read_from_pbmsg(const ::proto_ff::tempServerConfig & msg) {
	memset(this, 0, sizeof(struct tempServerConfig_s));
	server_id = msg.server_id();
	server_type = msg.server_type();
	server_list.resize(msg.server_list_size());
	for(int32_t i = 0; i < (int32_t)server_list.size(); ++i) {
		server_list[i] = msg.server_list(i);
	}
	const ::proto_ff::pbMysqlConfig & temp_mysql = msg.mysql();
	mysql.read_from_pbmsg(temp_mysql);
	redis.resize(msg.redis_size());
	for(int32_t i = 0; i < (int32_t)redis.size(); ++i) {
		const ::proto_ff::pbRedisConfig & temp_redis = msg.redis(i);
		redis[i].read_from_pbmsg(temp_redis);
	}
}

pbNFServerConfig_s::pbNFServerConfig_s() {
	CreateInit();
}

int pbNFServerConfig_s::CreateInit() {
	ServerType = (uint32_t)0;
	BusId = (uint32_t)0;
	BusLength = (uint32_t)0;
	IdleSleepUs = (uint32_t)0;
	ServerPort = (uint32_t)0;
	ExternalServerPort = (uint32_t)0;
	HttpPort = (uint32_t)0;
	MaxConnectNum = (uint32_t)0;
	WorkThreadNum = (uint32_t)0;
	NetThreadNum = (uint32_t)0;
	Security = (bool)0;
	WebSocket = (bool)0;
	mParseType = (uint32_t)0;
	MasterPort = (uint32_t)0;
	MysqlPort = (uint32_t)0;
	RedisPort = (uint32_t)0;
	MaxOnlinePlayerNum = (uint32_t)0;
	HeartBeatTimeout = (uint32_t)0;
	ClientKeepAliveTimeout = (uint32_t)0;
	return 0;
}

int pbNFServerConfig_s::ResumeInit() {
	return 0;
}

void pbNFServerConfig_s::write_to_pbmsg(::proto_ff::pbNFServerConfig & msg) const {
	msg.set_serverid(ServerId);
	msg.set_servertype((uint32_t)ServerType);
	msg.set_servername(ServerName);
	msg.set_busid((uint32_t)BusId);
	msg.set_buslength((uint32_t)BusLength);
	msg.set_busname(BusName);
	msg.set_linkmode(LinkMode);
	msg.set_url(Url);
	msg.set_idlesleepus((uint32_t)IdleSleepUs);
	msg.set_serverip(ServerIp);
	msg.set_serverport((uint32_t)ServerPort);
	msg.set_externalserverip(ExternalServerIp);
	msg.set_externalserverport((uint32_t)ExternalServerPort);
	msg.set_httpport((uint32_t)HttpPort);
	msg.set_maxconnectnum((uint32_t)MaxConnectNum);
	msg.set_workthreadnum((uint32_t)WorkThreadNum);
	msg.set_netthreadnum((uint32_t)NetThreadNum);
	msg.set_security((bool)Security);
	msg.set_websocket((bool)WebSocket);
	msg.set_mparsetype((uint32_t)mParseType);
	msg.set_masterip(MasterIp);
	msg.set_masterport((uint32_t)MasterPort);
	msg.set_naminghost(NamingHost);
	msg.set_namingpath(NamingPath);
	msg.set_routeagent(RouteAgent);
	msg.set_mysqlip(MysqlIp);
	msg.set_mysqlport((uint32_t)MysqlPort);
	msg.set_mysqldbname(MysqlDbName);
	msg.set_mysqluser(MysqlUser);
	msg.set_mysqlpassword(MysqlPassword);
	msg.set_redisip(RedisIp);
	msg.set_redisport((uint32_t)RedisPort);
	msg.set_redispass(RedisPass);
	msg.set_wwwurl(WwwUrl);
	msg.set_email(Email);
	msg.set_maxonlineplayernum((uint32_t)MaxOnlinePlayerNum);
	msg.set_heartbeattimeout((uint32_t)HeartBeatTimeout);
	msg.set_clientkeepalivetimeout((uint32_t)ClientKeepAliveTimeout);
}

void pbNFServerConfig_s::read_from_pbmsg(const ::proto_ff::pbNFServerConfig & msg) {
	memset(this, 0, sizeof(struct pbNFServerConfig_s));
	ServerId = msg.serverid();
	ServerType = msg.servertype();
	ServerName = msg.servername();
	BusId = msg.busid();
	BusLength = msg.buslength();
	BusName = msg.busname();
	LinkMode = msg.linkmode();
	Url = msg.url();
	IdleSleepUs = msg.idlesleepus();
	ServerIp = msg.serverip();
	ServerPort = msg.serverport();
	ExternalServerIp = msg.externalserverip();
	ExternalServerPort = msg.externalserverport();
	HttpPort = msg.httpport();
	MaxConnectNum = msg.maxconnectnum();
	WorkThreadNum = msg.workthreadnum();
	NetThreadNum = msg.netthreadnum();
	Security = msg.security();
	WebSocket = msg.websocket();
	mParseType = msg.mparsetype();
	MasterIp = msg.masterip();
	MasterPort = msg.masterport();
	NamingHost = msg.naminghost();
	NamingPath = msg.namingpath();
	RouteAgent = msg.routeagent();
	MysqlIp = msg.mysqlip();
	MysqlPort = msg.mysqlport();
	MysqlDbName = msg.mysqldbname();
	MysqlUser = msg.mysqluser();
	MysqlPassword = msg.mysqlpassword();
	RedisIp = msg.redisip();
	RedisPort = msg.redisport();
	RedisPass = msg.redispass();
	WwwUrl = msg.wwwurl();
	Email = msg.email();
	MaxOnlinePlayerNum = msg.maxonlineplayernum();
	HeartBeatTimeout = msg.heartbeattimeout();
	ClientKeepAliveTimeout = msg.clientkeepalivetimeout();
}

pbNFServerConfigList_s::pbNFServerConfigList_s() {
	CreateInit();
}

int pbNFServerConfigList_s::CreateInit() {
	return 0;
}

int pbNFServerConfigList_s::ResumeInit() {
	return 0;
}

void pbNFServerConfigList_s::write_to_pbmsg(::proto_ff::pbNFServerConfigList & msg) const {
	for(int32_t i = 0; i < (int32_t)list.size(); ++i) {
		::proto_ff::pbNFServerConfig* temp_list = msg.add_list();
		list[i].write_to_pbmsg(*temp_list);
	}
}

void pbNFServerConfigList_s::read_from_pbmsg(const ::proto_ff::pbNFServerConfigList & msg) {
	memset(this, 0, sizeof(struct pbNFServerConfigList_s));
	list.resize(msg.list_size());
	for(int32_t i = 0; i < (int32_t)list.size(); ++i) {
		const ::proto_ff::pbNFServerConfig & temp_list = msg.list(i);
		list[i].read_from_pbmsg(temp_list);
	}
}

}