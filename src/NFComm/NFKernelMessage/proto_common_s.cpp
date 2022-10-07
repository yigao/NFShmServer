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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct tbServerMgr_s));
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
	for(int32_t i = 0; i < (int32_t)TBConfList.size(); ++i) {
		::proto_ff::pbTableConfig* temp_tbconflist = msg.add_tbconflist();
		TBConfList[i].write_to_pbmsg(*temp_tbconflist);
	}
}

void pbMysqlConfig_s::read_from_pbmsg(const ::proto_ff::pbMysqlConfig & msg) {
	MysqlIp = msg.mysqlip();
	MysqlPort = msg.mysqlport();
	MysqlDbName = msg.mysqldbname();
	MysqlUser = msg.mysqluser();
	MysqlPassword = msg.mysqlpassword();
	TBConfList.resize(msg.tbconflist_size());
	for(int32_t i = 0; i < (int32_t)TBConfList.size(); ++i) {
		const ::proto_ff::pbTableConfig & temp_tbconflist = msg.tbconflist(i);
		TBConfList[i].read_from_pbmsg(temp_tbconflist);
	}
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
	RedisIp = msg.redisip();
	RedisPort = msg.redisport();
	RedisPass = msg.redispass();
}

pbRouteConfig_s::pbRouteConfig_s() {
	CreateInit();
}

int pbRouteConfig_s::CreateInit() {
	MasterPort = (uint32_t)0;
	return 0;
}

int pbRouteConfig_s::ResumeInit() {
	return 0;
}

void pbRouteConfig_s::write_to_pbmsg(::proto_ff::pbRouteConfig & msg) const {
	msg.set_masterip(MasterIp);
	msg.set_masterport((uint32_t)MasterPort);
	msg.set_naminghost(NamingHost);
	msg.set_namingpath(NamingPath);
	msg.set_routeagent(RouteAgent);
}

void pbRouteConfig_s::read_from_pbmsg(const ::proto_ff::pbRouteConfig & msg) {
	MasterIp = msg.masterip();
	MasterPort = msg.masterport();
	NamingHost = msg.naminghost();
	NamingPath = msg.namingpath();
	RouteAgent = msg.routeagent();
}

pbNetConfig_s::pbNetConfig_s() {
	CreateInit();
}

int pbNetConfig_s::CreateInit() {
	ServerPort = (uint32_t)0;
	ExternalServerPort = (uint32_t)0;
	HttpPort = (uint32_t)0;
	MaxConnectNum = (uint32_t)0;
	WorkThreadNum = (uint32_t)0;
	NetThreadNum = (uint32_t)0;
	Security = (bool)0;
	WebSocket = (bool)0;
	mParseType = (uint32_t)0;
	return 0;
}

int pbNetConfig_s::ResumeInit() {
	return 0;
}

void pbNetConfig_s::write_to_pbmsg(::proto_ff::pbNetConfig & msg) const {
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
}

void pbNetConfig_s::read_from_pbmsg(const ::proto_ff::pbNetConfig & msg) {
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
}

pbAllServerConfig_s::pbAllServerConfig_s() {
	CreateInit();
}

int pbAllServerConfig_s::CreateInit() {
	ServerType = (uint32_t)0;
	return 0;
}

int pbAllServerConfig_s::ResumeInit() {
	return 0;
}

void pbAllServerConfig_s::write_to_pbmsg(::proto_ff::pbAllServerConfig & msg) const {
	msg.set_server(Server);
	msg.set_id(ID);
	msg.set_servertype((uint32_t)ServerType);
}

void pbAllServerConfig_s::read_from_pbmsg(const ::proto_ff::pbAllServerConfig & msg) {
	Server = msg.server();
	ID = msg.id();
	ServerType = msg.servertype();
}

pbPluginConfig_s::pbPluginConfig_s() {
	CreateInit();
}

int pbPluginConfig_s::CreateInit() {
	ServerType = (uint32_t)0;
	return 0;
}

int pbPluginConfig_s::ResumeInit() {
	return 0;
}

void pbPluginConfig_s::write_to_pbmsg(::proto_ff::pbPluginConfig & msg) const {
	msg.set_servertype((uint32_t)ServerType);
	for(int32_t i = 0; i < (int32_t)ServerPlugins.size(); ++i) {
		msg.add_serverplugins(ServerPlugins[i]);
	}
	for(int32_t i = 0; i < (int32_t)ServerList.size(); ++i) {
		::proto_ff::pbAllServerConfig* temp_serverlist = msg.add_serverlist();
		ServerList[i].write_to_pbmsg(*temp_serverlist);
	}
}

void pbPluginConfig_s::read_from_pbmsg(const ::proto_ff::pbPluginConfig & msg) {
	ServerType = msg.servertype();
	ServerPlugins.resize(msg.serverplugins_size());
	for(int32_t i = 0; i < (int32_t)ServerPlugins.size(); ++i) {
		ServerPlugins[i] = msg.serverplugins(i);
	}
	ServerList.resize(msg.serverlist_size());
	for(int32_t i = 0; i < (int32_t)ServerList.size(); ++i) {
		const ::proto_ff::pbAllServerConfig & temp_serverlist = msg.serverlist(i);
		ServerList[i].read_from_pbmsg(temp_serverlist);
	}
}

pbTableConfig_s::pbTableConfig_s() {
	CreateInit();
}

int pbTableConfig_s::CreateInit() {
	TableCount = (uint32_t)0;
	return 0;
}

int pbTableConfig_s::ResumeInit() {
	return 0;
}

void pbTableConfig_s::write_to_pbmsg(::proto_ff::pbTableConfig & msg) const {
	msg.set_tablename(TableName);
	msg.set_tablecount((uint32_t)TableCount);
}

void pbTableConfig_s::read_from_pbmsg(const ::proto_ff::pbTableConfig & msg) {
	TableName = msg.tablename();
	TableCount = msg.tablecount();
}

pbNFServerConfig_s::pbNFServerConfig_s() {
	CreateInit();
}

int pbNFServerConfig_s::CreateInit() {
	ServerType = (uint32_t)0;
	BusId = (uint32_t)0;
	BusLength = (uint32_t)0;
    IdleSleepUS = (uint32_t)0;
	ServerPort = (uint32_t)0;
	ExternalServerPort = (uint32_t)0;
	HttpPort = (uint32_t)0;
	MaxConnectNum = (uint32_t)0;
	WorkThreadNum = (uint32_t)0;
	NetThreadNum = (uint32_t)0;
	Security = (bool)0;
	WebSocket = (bool)0;
	ParseType = (uint32_t)0;
	MasterPort = (uint32_t)0;
	MysqlPort = (uint32_t)0;
	RedisPort = (uint32_t)0;
	MaxOnlinePlayerNum = (uint32_t)0;
	HeartBeatTimeout = (uint32_t)0;
	ClientKeepAliveTimeout = (uint32_t)0;
	ClientVersion = (uint32_t)0;
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
	msg.set_linkmode(LinkMode);
	msg.set_url(Url);
	msg.set_idlesleepus((uint32_t)IdleSleepUS);
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
	msg.set_parsetype((uint32_t)ParseType);
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
	msg.set_defaultdbname(DefaultDBName);
	msg.set_crossdbname(CrossDBName);
	for(int32_t i = 0; i < (int32_t)TBConfList.size(); ++i) {
		::proto_ff::pbTableConfig* temp_tbconflist = msg.add_tbconflist();
		TBConfList[i].write_to_pbmsg(*temp_tbconflist);
	}
	msg.set_redisip(RedisIp);
	msg.set_redisport((uint32_t)RedisPort);
	msg.set_redispass(RedisPass);
	msg.set_wwwurl(WwwUrl);
	msg.set_email(Email);
	msg.set_maxonlineplayernum((uint32_t)MaxOnlinePlayerNum);
	msg.set_heartbeattimeout((uint32_t)HeartBeatTimeout);
	msg.set_clientkeepalivetimeout((uint32_t)ClientKeepAliveTimeout);
	msg.set_clientversion((uint32_t)ClientVersion);
}

void pbNFServerConfig_s::read_from_pbmsg(const ::proto_ff::pbNFServerConfig & msg) {
	ServerId = msg.serverid();
	ServerType = msg.servertype();
	ServerName = msg.servername();
	BusId = msg.busid();
	BusLength = msg.buslength();
	LinkMode = msg.linkmode();
	Url = msg.url();
    IdleSleepUS = msg.idlesleepus();
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
	ParseType = msg.parsetype();
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
	DefaultDBName = msg.defaultdbname();
	CrossDBName = msg.crossdbname();
	TBConfList.resize(msg.tbconflist_size());
	for(int32_t i = 0; i < (int32_t)TBConfList.size(); ++i) {
		const ::proto_ff::pbTableConfig & temp_tbconflist = msg.tbconflist(i);
		TBConfList[i].read_from_pbmsg(temp_tbconflist);
	}
	RedisIp = msg.redisip();
	RedisPort = msg.redisport();
	RedisPass = msg.redispass();
	WwwUrl = msg.wwwurl();
	Email = msg.email();
	MaxOnlinePlayerNum = msg.maxonlineplayernum();
	HeartBeatTimeout = msg.heartbeattimeout();
	ClientKeepAliveTimeout = msg.clientkeepalivetimeout();
	ClientVersion = msg.clientversion();
}

}