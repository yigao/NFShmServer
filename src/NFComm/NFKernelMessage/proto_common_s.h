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

		void write_to_pbmsg(::proto_ff::tbServerMgr & msg) const;
		void read_from_pbmsg(const ::proto_ff::tbServerMgr & msg);
		static ::proto_ff::tbServerMgr* new_pbmsg(){ return new ::proto_ff::tbServerMgr(); }
		static ::proto_ff::tbServerMgr make_pbmsg(){ return ::proto_ff::tbServerMgr(); }
	};
	typedef struct tbServerMgr_s tbServerMgr_t;

	struct pbMysqlConfig_s {
		pbMysqlConfig_s();
		int CreateInit();
		int ResumeInit();
		std::string MysqlIp;
		uint32_t MysqlPort;
		std::string MysqlDbName;
		std::string MysqlUser;
		std::string MysqlPassword;

		void write_to_pbmsg(::proto_ff::pbMysqlConfig & msg) const;
		void read_from_pbmsg(const ::proto_ff::pbMysqlConfig & msg);
		static ::proto_ff::pbMysqlConfig* new_pbmsg(){ return new ::proto_ff::pbMysqlConfig(); }
		static ::proto_ff::pbMysqlConfig make_pbmsg(){ return ::proto_ff::pbMysqlConfig(); }
	};
	typedef struct pbMysqlConfig_s pbMysqlConfig_t;

	struct pbRedisConfig_s {
		pbRedisConfig_s();
		int CreateInit();
		int ResumeInit();
		std::string RedisIp;
		uint32_t RedisPort;
		std::string RedisPass;

		void write_to_pbmsg(::proto_ff::pbRedisConfig & msg) const;
		void read_from_pbmsg(const ::proto_ff::pbRedisConfig & msg);
		static ::proto_ff::pbRedisConfig* new_pbmsg(){ return new ::proto_ff::pbRedisConfig(); }
		static ::proto_ff::pbRedisConfig make_pbmsg(){ return ::proto_ff::pbRedisConfig(); }
	};
	typedef struct pbRedisConfig_s pbRedisConfig_t;

	struct tempServerConfig_s {
		tempServerConfig_s();
		int CreateInit();
		int ResumeInit();
		uint32_t server_id;
		std::string server_type;
		std::vector<std::string> server_list;
		struct pbMysqlConfig_s mysql;
		std::vector<struct pbRedisConfig_s> redis;

		void write_to_pbmsg(::proto_ff::tempServerConfig & msg) const;
		void read_from_pbmsg(const ::proto_ff::tempServerConfig & msg);
		static ::proto_ff::tempServerConfig* new_pbmsg(){ return new ::proto_ff::tempServerConfig(); }
		static ::proto_ff::tempServerConfig make_pbmsg(){ return ::proto_ff::tempServerConfig(); }
	};
	typedef struct tempServerConfig_s tempServerConfig_t;

	struct pbNFServerConfig_s {
		pbNFServerConfig_s();
		int CreateInit();
		int ResumeInit();
		std::string ServerId;
		uint32_t ServerType;
		std::string ServerName;
		uint32_t BusId;
		uint32_t BusLength;
		std::string BusName;
		std::string LinkMode;
		std::string Url;
		uint32_t IdleSleepUs;
		std::string ServerIp;
		uint32_t ServerPort;
		std::string ExternalServerIp;
		uint32_t ExternalServerPort;
		uint32_t HttpPort;
		uint32_t MaxConnectNum;
		uint32_t WorkThreadNum;
		uint32_t NetThreadNum;
		bool Security;
		bool WebSocket;
		uint32_t mParseType;
		std::string MasterIp;
		uint32_t MasterPort;
		std::string NamingHost;
		std::string NamingPath;
		std::string RouteAgent;
		std::string MysqlIp;
		uint32_t MysqlPort;
		std::string MysqlDbName;
		std::string MysqlUser;
		std::string MysqlPassword;
		std::string RedisIp;
		uint32_t RedisPort;
		std::string RedisPass;
		std::string WwwUrl;
		std::string Email;
		uint32_t MaxOnlinePlayerNum;
		uint32_t HeartBeatTimeout;
		uint32_t ClientKeepAliveTimeout;

		void write_to_pbmsg(::proto_ff::pbNFServerConfig & msg) const;
		void read_from_pbmsg(const ::proto_ff::pbNFServerConfig & msg);
		static ::proto_ff::pbNFServerConfig* new_pbmsg(){ return new ::proto_ff::pbNFServerConfig(); }
		static ::proto_ff::pbNFServerConfig make_pbmsg(){ return ::proto_ff::pbNFServerConfig(); }
	};
	typedef struct pbNFServerConfig_s pbNFServerConfig_t;

	struct pbNFServerConfigList_s {
		pbNFServerConfigList_s();
		int CreateInit();
		int ResumeInit();
		std::vector<struct pbNFServerConfig_s> list;

		void write_to_pbmsg(::proto_ff::pbNFServerConfigList & msg) const;
		void read_from_pbmsg(const ::proto_ff::pbNFServerConfigList & msg);
		static ::proto_ff::pbNFServerConfigList* new_pbmsg(){ return new ::proto_ff::pbNFServerConfigList(); }
		static ::proto_ff::pbNFServerConfigList make_pbmsg(){ return ::proto_ff::pbNFServerConfigList(); }
	};
	typedef struct pbNFServerConfigList_s pbNFServerConfigList_t;

}

