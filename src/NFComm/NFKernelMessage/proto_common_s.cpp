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

void tbServerMgr_s::write_to_pbmsg(const struct tbServerMgr_s & obj, ::proto_ff::tbServerMgr & msg) {
	msg.set_id((uint64_t)obj.id);
	msg.set_contract((const char*)obj.contract.Get());
	msg.set_machine_addr((const char*)obj.machine_addr.Get());
	msg.set_ip((const char*)obj.ip.Get());
	msg.set_bus_name((const char*)obj.bus_name.Get());
	msg.set_server_desc((const char*)obj.server_desc.Get());
	msg.set_cur_count((uint32_t)obj.cur_count);
	msg.set_last_login_time((uint64_t)obj.last_login_time);
	msg.set_last_logout_time((uint64_t)obj.last_logout_time);
	msg.set_create_time((uint64_t)obj.create_time);
}

void tbServerMgr_s::read_from_pbmsg(const ::proto_ff::tbServerMgr & msg, struct tbServerMgr_s & obj) {
	memset(&obj, 0, sizeof(struct tbServerMgr_s));
	obj.id = msg.id();
	obj.contract.Copy(msg.contract());
	obj.machine_addr.Copy(msg.machine_addr());
	obj.ip.Copy(msg.ip());
	obj.bus_name.Copy(msg.bus_name());
	obj.server_desc.Copy(msg.server_desc());
	obj.cur_count = msg.cur_count();
	obj.last_login_time = msg.last_login_time();
	obj.last_logout_time = msg.last_logout_time();
	obj.create_time = msg.create_time();
}

pbNFServerConfig_s::pbNFServerConfig_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
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

void pbNFServerConfig_s::write_to_pbmsg(const struct pbNFServerConfig_s & obj, ::proto_ff::pbNFServerConfig & msg) {
	msg.set_serverid((const char*)obj.ServerId.Get());
	msg.set_servertype((uint32_t)obj.ServerType);
	msg.set_servername((const char*)obj.ServerName.Get());
	msg.set_busid((uint32_t)obj.BusId);
	msg.set_buslength((uint32_t)obj.BusLength);
	msg.set_busname((const char*)obj.BusName.Get());
	msg.set_linkmode((const char*)obj.LinkMode.Get());
	msg.set_url((const char*)obj.Url.Get());
	msg.set_idlesleepus((uint32_t)obj.IdleSleepUs);
	msg.set_serverip((const char*)obj.ServerIp.Get());
	msg.set_serverport((uint32_t)obj.ServerPort);
	msg.set_externalserverip((const char*)obj.ExternalServerIp.Get());
	msg.set_externalserverport((uint32_t)obj.ExternalServerPort);
	msg.set_httpport((uint32_t)obj.HttpPort);
	msg.set_maxconnectnum((uint32_t)obj.MaxConnectNum);
	msg.set_workthreadnum((uint32_t)obj.WorkThreadNum);
	msg.set_netthreadnum((uint32_t)obj.NetThreadNum);
	msg.set_security((bool)obj.Security);
	msg.set_websocket((bool)obj.WebSocket);
	msg.set_mparsetype((uint32_t)obj.mParseType);
	msg.set_masterip((const char*)obj.MasterIp.Get());
	msg.set_masterport((uint32_t)obj.MasterPort);
	msg.set_naminghost((const char*)obj.NamingHost.Get());
	msg.set_namingpath((const char*)obj.NamingPath.Get());
	msg.set_routeagent((const char*)obj.RouteAgent.Get());
	msg.set_mysqlip((const char*)obj.MysqlIp.Get());
	msg.set_mysqlport((uint32_t)obj.MysqlPort);
	msg.set_mysqldbname((const char*)obj.MysqlDbName.Get());
	msg.set_mysqluser((const char*)obj.MysqlUser.Get());
	msg.set_mysqlpassword((const char*)obj.MysqlPassword.Get());
	msg.set_redisip((const char*)obj.RedisIp.Get());
	msg.set_redisport((uint32_t)obj.RedisPort);
	msg.set_redispass((const char*)obj.RedisPass.Get());
	msg.set_wwwurl((const char*)obj.WwwUrl.Get());
	msg.set_email((const char*)obj.Email.Get());
	msg.set_maxonlineplayernum((uint32_t)obj.MaxOnlinePlayerNum);
	msg.set_heartbeattimeout((uint32_t)obj.HeartBeatTimeout);
	msg.set_clientkeepalivetimeout((uint32_t)obj.ClientKeepAliveTimeout);
}

void pbNFServerConfig_s::read_from_pbmsg(const ::proto_ff::pbNFServerConfig & msg, struct pbNFServerConfig_s & obj) {
	memset(&obj, 0, sizeof(struct pbNFServerConfig_s));
	obj.ServerId.Copy(msg.serverid());
	obj.ServerType = msg.servertype();
	obj.ServerName.Copy(msg.servername());
	obj.BusId = msg.busid();
	obj.BusLength = msg.buslength();
	obj.BusName.Copy(msg.busname());
	obj.LinkMode.Copy(msg.linkmode());
	obj.Url.Copy(msg.url());
	obj.IdleSleepUs = msg.idlesleepus();
	obj.ServerIp.Copy(msg.serverip());
	obj.ServerPort = msg.serverport();
	obj.ExternalServerIp.Copy(msg.externalserverip());
	obj.ExternalServerPort = msg.externalserverport();
	obj.HttpPort = msg.httpport();
	obj.MaxConnectNum = msg.maxconnectnum();
	obj.WorkThreadNum = msg.workthreadnum();
	obj.NetThreadNum = msg.netthreadnum();
	obj.Security = msg.security();
	obj.WebSocket = msg.websocket();
	obj.mParseType = msg.mparsetype();
	obj.MasterIp.Copy(msg.masterip());
	obj.MasterPort = msg.masterport();
	obj.NamingHost.Copy(msg.naminghost());
	obj.NamingPath.Copy(msg.namingpath());
	obj.RouteAgent.Copy(msg.routeagent());
	obj.MysqlIp.Copy(msg.mysqlip());
	obj.MysqlPort = msg.mysqlport();
	obj.MysqlDbName.Copy(msg.mysqldbname());
	obj.MysqlUser.Copy(msg.mysqluser());
	obj.MysqlPassword.Copy(msg.mysqlpassword());
	obj.RedisIp.Copy(msg.redisip());
	obj.RedisPort = msg.redisport();
	obj.RedisPass.Copy(msg.redispass());
	obj.WwwUrl.Copy(msg.wwwurl());
	obj.Email.Copy(msg.email());
	obj.MaxOnlinePlayerNum = msg.maxonlineplayernum();
	obj.HeartBeatTimeout = msg.heartbeattimeout();
	obj.ClientKeepAliveTimeout = msg.clientkeepalivetimeout();
}

pbNFServerConfigList_s::pbNFServerConfigList_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int pbNFServerConfigList_s::CreateInit() {
	return 0;
}

int pbNFServerConfigList_s::ResumeInit() {
	return 0;
}

void pbNFServerConfigList_s::write_to_pbmsg(const struct pbNFServerConfigList_s & obj, ::proto_ff::pbNFServerConfigList & msg) {
}

void pbNFServerConfigList_s::read_from_pbmsg(const ::proto_ff::pbNFServerConfigList & msg, struct pbNFServerConfigList_s & obj) {
	memset(&obj, 0, sizeof(struct pbNFServerConfigList_s));
}

}