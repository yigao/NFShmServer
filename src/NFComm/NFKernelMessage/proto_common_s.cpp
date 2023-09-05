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
	msg.set_contract(contract.data());
	msg.set_machine_addr(machine_addr.data());
	msg.set_ip(ip.data());
	msg.set_bus_name(bus_name.data());
	msg.set_server_desc(server_desc.data());
	msg.set_cur_count((uint32_t)cur_count);
	msg.set_last_login_time((uint64_t)last_login_time);
	msg.set_last_logout_time((uint64_t)last_logout_time);
	msg.set_create_time((uint64_t)create_time);
}

void tbServerMgr_s::read_from_pbmsg(const ::proto_ff::tbServerMgr & msg) {
	id = msg.id();
	contract = msg.contract();
	machine_addr = msg.machine_addr();
	ip = msg.ip();
	bus_name = msg.bus_name();
	server_desc = msg.server_desc();
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
	msg.set_mysqlip(MysqlIp.data());
	msg.set_mysqlport((uint32_t)MysqlPort);
	msg.set_mysqldbname(MysqlDbName.data());
	msg.set_mysqluser(MysqlUser.data());
	msg.set_mysqlpassword(MysqlPassword.data());
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
	msg.set_redisip(RedisIp.data());
	msg.set_redisport((uint32_t)RedisPort);
	msg.set_redispass(RedisPass.data());
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
	msg.set_masterip(MasterIp.data());
	msg.set_masterport((uint32_t)MasterPort);
	msg.set_naminghost(NamingHost.data());
	msg.set_namingpath(NamingPath.data());
	msg.set_routeagent(RouteAgent.data());
}

void pbRouteConfig_s::read_from_pbmsg(const ::proto_ff::pbRouteConfig & msg) {
	MasterIp = msg.masterip();
	MasterPort = msg.masterport();
	NamingHost = msg.naminghost();
	NamingPath = msg.namingpath();
	RouteAgent = msg.routeagent();
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
	msg.set_server(Server.data());
	msg.set_id(ID.data());
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
	for(int32_t i = 0; i < (int32_t)FramePlugins.size(); ++i) {
		msg.add_frameplugins(FramePlugins[i].data());
	}
	for(int32_t i = 0; i < (int32_t)ServerPlugins.size(); ++i) {
		msg.add_serverplugins(ServerPlugins[i].data());
	}
	for(int32_t i = 0; i < (int32_t)WorkPlugins.size(); ++i) {
		msg.add_workplugins(WorkPlugins[i].data());
	}
	for(int32_t i = 0; i < (int32_t)ServerList.size(); ++i) {
		::proto_ff::pbAllServerConfig* temp_serverlist = msg.add_serverlist();
		ServerList[i].write_to_pbmsg(*temp_serverlist);
	}
}

void pbPluginConfig_s::read_from_pbmsg(const ::proto_ff::pbPluginConfig & msg) {
	ServerType = msg.servertype();
	FramePlugins.resize(msg.frameplugins_size());
	for(int32_t i = 0; i < (int32_t)FramePlugins.size(); ++i) {
		FramePlugins[i] = msg.frameplugins(i);
	}
	ServerPlugins.resize(msg.serverplugins_size());
	for(int32_t i = 0; i < (int32_t)ServerPlugins.size(); ++i) {
		ServerPlugins[i] = msg.serverplugins(i);
	}
	WorkPlugins.resize(msg.workplugins_size());
	for(int32_t i = 0; i < (int32_t)WorkPlugins.size(); ++i) {
		WorkPlugins[i] = msg.workplugins(i);
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
	Cache = (bool)0;
	return 0;
}

int pbTableConfig_s::ResumeInit() {
	return 0;
}

void pbTableConfig_s::write_to_pbmsg(::proto_ff::pbTableConfig & msg) const {
	msg.set_tablename(TableName.data());
	msg.set_tablecount((uint32_t)TableCount);
	msg.set_cache((bool)Cache);
}

void pbTableConfig_s::read_from_pbmsg(const ::proto_ff::pbTableConfig & msg) {
	TableName = msg.tablename();
	TableCount = msg.tablecount();
	Cache = msg.cache();
}

pbNFServerConfig_s::pbNFServerConfig_s() {
	CreateInit();
}

int pbNFServerConfig_s::CreateInit() {
	ServerType = (uint32_t)0;
	BusId = (uint32_t)0;
	BusLength = (uint32_t)0;
	IdleSleepUS = (uint32_t)0;
	HandleMsgNumPerFrame = (uint32_t)0;
	ServerOpenTime = (uint64_t)0;
	ServerPort = (uint32_t)0;
	ExternalServerPort = (uint32_t)0;
	HttpPort = (uint32_t)0;
	MaxConnectNum = (uint32_t)0;
	WorkThreadNum = (uint32_t)0;
	NetThreadNum = (uint32_t)0;
	Security = (bool)0;
	WebSocket = (bool)0;
	ParseType = (uint32_t)0;
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
	msg.set_serverid(ServerId.data());
	msg.set_servertype((uint32_t)ServerType);
	msg.set_servername(ServerName.data());
	msg.set_busid((uint32_t)BusId);
	msg.set_buslength((uint32_t)BusLength);
	msg.set_linkmode(LinkMode.data());
	msg.set_url(Url.data());
	msg.set_idlesleepus((uint32_t)IdleSleepUS);
	msg.set_handlemsgnumperframe((uint32_t)HandleMsgNumPerFrame);
	msg.set_serveropentime((uint64_t)ServerOpenTime);
	msg.set_loadprotods(LoadProtoDs.data());
	msg.set_serverip(ServerIp.data());
	msg.set_serverport((uint32_t)ServerPort);
	msg.set_externalserverip(ExternalServerIp.data());
	msg.set_externalserverport((uint32_t)ExternalServerPort);
	msg.set_httpport((uint32_t)HttpPort);
	msg.set_maxconnectnum((uint32_t)MaxConnectNum);
	msg.set_workthreadnum((uint32_t)WorkThreadNum);
	msg.set_netthreadnum((uint32_t)NetThreadNum);
	msg.set_security((bool)Security);
	msg.set_websocket((bool)WebSocket);
	msg.set_parsetype((uint32_t)ParseType);
	::proto_ff::pbRouteConfig* temp_routeconfig = msg.mutable_routeconfig();
	RouteConfig.write_to_pbmsg(*temp_routeconfig);
	::proto_ff::pbMysqlConfig* temp_mysqlconfig = msg.mutable_mysqlconfig();
	MysqlConfig.write_to_pbmsg(*temp_mysqlconfig);
	msg.set_defaultdbname(DefaultDBName.data());
	msg.set_crossdbname(CrossDBName.data());
	::proto_ff::pbRedisConfig* temp_redisconfig = msg.mutable_redisconfig();
	RedisConfig.write_to_pbmsg(*temp_redisconfig);
	msg.set_sendemail(sendEmail.data());
	msg.set_sendemailpass(sendEmailPass.data());
	msg.set_sendemailurl(sendEmailUrl.data());
	msg.set_sendemailport(sendEmailPort.data());
	msg.set_recvemail(recvEmail.data());
	msg.set_wxworkdrobot(wxWorkdRobot.data());
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
	HandleMsgNumPerFrame = msg.handlemsgnumperframe();
	ServerOpenTime = msg.serveropentime();
	LoadProtoDs = msg.loadprotods();
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
	const ::proto_ff::pbRouteConfig & temp_routeconfig = msg.routeconfig();
	RouteConfig.read_from_pbmsg(temp_routeconfig);
	const ::proto_ff::pbMysqlConfig & temp_mysqlconfig = msg.mysqlconfig();
	MysqlConfig.read_from_pbmsg(temp_mysqlconfig);
	DefaultDBName = msg.defaultdbname();
	CrossDBName = msg.crossdbname();
	const ::proto_ff::pbRedisConfig & temp_redisconfig = msg.redisconfig();
	RedisConfig.read_from_pbmsg(temp_redisconfig);
	sendEmail = msg.sendemail();
	sendEmailPass = msg.sendemailpass();
	sendEmailUrl = msg.sendemailurl();
	sendEmailPort = msg.sendemailport();
	recvEmail = msg.recvemail();
	wxWorkdRobot = msg.wxworkdrobot();
	MaxOnlinePlayerNum = msg.maxonlineplayernum();
	HeartBeatTimeout = msg.heartbeattimeout();
	ClientKeepAliveTimeout = msg.clientkeepalivetimeout();
	ClientVersion = msg.clientversion();
}

wxWorkRobotText_s::wxWorkRobotText_s() {
	CreateInit();
}

int wxWorkRobotText_s::CreateInit() {
	return 0;
}

int wxWorkRobotText_s::ResumeInit() {
	return 0;
}

void wxWorkRobotText_s::write_to_pbmsg(::proto_ff::wxWorkRobotText & msg) const {
	msg.set_content(content.data());
	for(int32_t i = 0; i < (int32_t)mentioned_list.size(); ++i) {
		msg.add_mentioned_list(mentioned_list[i].data());
	}
	for(int32_t i = 0; i < (int32_t)mentioned_mobile_list.size(); ++i) {
		msg.add_mentioned_mobile_list(mentioned_mobile_list[i].data());
	}
}

void wxWorkRobotText_s::read_from_pbmsg(const ::proto_ff::wxWorkRobotText & msg) {
	content = msg.content();
	mentioned_list.resize(msg.mentioned_list_size());
	for(int32_t i = 0; i < (int32_t)mentioned_list.size(); ++i) {
		mentioned_list[i] = msg.mentioned_list(i);
	}
	mentioned_mobile_list.resize(msg.mentioned_mobile_list_size());
	for(int32_t i = 0; i < (int32_t)mentioned_mobile_list.size(); ++i) {
		mentioned_mobile_list[i] = msg.mentioned_mobile_list(i);
	}
}

wxWorkRobotHttpPost_s::wxWorkRobotHttpPost_s() {
	CreateInit();
}

int wxWorkRobotHttpPost_s::CreateInit() {
	return 0;
}

int wxWorkRobotHttpPost_s::ResumeInit() {
	return 0;
}

void wxWorkRobotHttpPost_s::write_to_pbmsg(::proto_ff::wxWorkRobotHttpPost & msg) const {
	msg.set_msgtype(msgtype.data());
	::proto_ff::wxWorkRobotText* temp_text = msg.mutable_text();
	text.write_to_pbmsg(*temp_text);
}

void wxWorkRobotHttpPost_s::read_from_pbmsg(const ::proto_ff::wxWorkRobotHttpPost & msg) {
	msgtype = msg.msgtype();
	const ::proto_ff::wxWorkRobotText & temp_text = msg.text();
	text.read_from_pbmsg(temp_text);
}

}
