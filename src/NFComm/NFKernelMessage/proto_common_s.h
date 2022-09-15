#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "proto_common.pb.h"
#include "proto_common_s.h"

namespace proto_ff_s {

	struct tbServerMgr_s : public NFDescStoreSeqOP {
		tbServerMgr_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		NFSizeString<128> contract;
		NFSizeString<128> machine_addr;
		NFSizeString<128> ip;
		NFSizeString<128> bus_name;
		NFSizeString<128> server_desc;
		uint32_t cur_count;
		uint64_t last_login_time;
		uint64_t last_logout_time;
		uint64_t create_time;

		static void write_to_pbmsg(const struct tbServerMgr_s & obj, ::proto_ff::tbServerMgr & msg);
		static void read_from_pbmsg(const ::proto_ff::tbServerMgr & msg, struct tbServerMgr_s & obj);
		static ::proto_ff::tbServerMgr* new_pbmsg(){ return new ::proto_ff::tbServerMgr(); }
		static ::proto_ff::tbServerMgr make_pbmsg(){ return ::proto_ff::tbServerMgr(); }
	};
	typedef struct tbServerMgr_s tbServerMgr_t;

	struct pbNFServerConfig_s : public NFDescStoreSeqOP {
		pbNFServerConfig_s();
		int CreateInit();
		int ResumeInit();
		NFSizeString<128> ServerId;
		uint32_t ServerType;
		NFSizeString<128> ServerName;
		uint32_t BusId;
		uint32_t BusLength;
		NFSizeString<128> BusName;
		NFSizeString<128> LinkMode;
		NFSizeString<128> Url;
		uint32_t IdleSleepUs;
		NFSizeString<128> ServerIp;
		uint32_t ServerPort;
		NFSizeString<128> ExternalServerIp;
		uint32_t ExternalServerPort;
		uint32_t HttpPort;
		uint32_t MaxConnectNum;
		uint32_t WorkThreadNum;
		uint32_t NetThreadNum;
		bool Security;
		bool WebSocket;
		uint32_t mParseType;
		NFSizeString<128> MasterIp;
		uint32_t MasterPort;
		NFSizeString<128> NamingHost;
		NFSizeString<128> NamingPath;
		NFSizeString<128> RouteAgent;
		NFSizeString<128> MysqlIp;
		uint32_t MysqlPort;
		NFSizeString<128> MysqlDbName;
		NFSizeString<128> MysqlUser;
		NFSizeString<128> MysqlPassword;
		NFSizeString<128> RedisIp;
		uint32_t RedisPort;
		NFSizeString<128> RedisPass;
		NFSizeString<128> WwwUrl;
		NFSizeString<128> Email;
		uint32_t MaxOnlinePlayerNum;
		uint32_t HeartBeatTimeout;
		uint32_t ClientKeepAliveTimeout;

		static void write_to_pbmsg(const struct pbNFServerConfig_s & obj, ::proto_ff::pbNFServerConfig & msg);
		static void read_from_pbmsg(const ::proto_ff::pbNFServerConfig & msg, struct pbNFServerConfig_s & obj);
		static ::proto_ff::pbNFServerConfig* new_pbmsg(){ return new ::proto_ff::pbNFServerConfig(); }
		static ::proto_ff::pbNFServerConfig make_pbmsg(){ return ::proto_ff::pbNFServerConfig(); }
	};
	typedef struct pbNFServerConfig_s pbNFServerConfig_t;

	struct pbNFServerConfigList_s : public NFDescStoreSeqOP {
		pbNFServerConfigList_s();
		int CreateInit();
		int ResumeInit();

		static void write_to_pbmsg(const struct pbNFServerConfigList_s & obj, ::proto_ff::pbNFServerConfigList & msg);
		static void read_from_pbmsg(const ::proto_ff::pbNFServerConfigList & msg, struct pbNFServerConfigList_s & obj);
		static ::proto_ff::pbNFServerConfigList* new_pbmsg(){ return new ::proto_ff::pbNFServerConfigList(); }
		static ::proto_ff::pbNFServerConfigList make_pbmsg(){ return ::proto_ff::pbNFServerConfigList(); }
	};
	typedef struct pbNFServerConfigList_s pbNFServerConfigList_t;

}

