#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "proto_common.pb.h"
#include "proto_common_s.h"



namespace proto_ff_s {

	struct tbServerMgr_s : public NFDescStoreSeqOP {
		tbServerMgr_s();
		virtual ~tbServerMgr_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		NFShmString<128> contract;//
		NFShmString<128> machine_addr;//
		NFShmString<128> ip;//
		NFShmString<128> bus_name;//
		NFShmString<128> server_desc;//
		uint32_t cur_count;//
		uint64_t last_login_time;//
		uint64_t last_logout_time;//
		uint64_t create_time;//

		virtual void write_to_pbmsg(::proto_ff::tbServerMgr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::tbServerMgr & msg);
		static ::proto_ff::tbServerMgr* new_pbmsg(){ return new ::proto_ff::tbServerMgr(); }
		static ::proto_ff::tbServerMgr make_pbmsg(){ return ::proto_ff::tbServerMgr(); }
	};
	typedef struct tbServerMgr_s tbServerMgr_t;

	struct pbMysqlConfig_s {
		pbMysqlConfig_s();
		virtual ~pbMysqlConfig_s(){}
		int CreateInit();
		int ResumeInit();
		std::string MysqlIp;//
		uint32_t MysqlPort;//
		std::string MysqlDbName;//
		std::string MysqlUser;//
		std::string MysqlPassword;//
		std::vector<struct pbTableConfig_s> TBConfList;//

		virtual void write_to_pbmsg(::proto_ff::pbMysqlConfig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::pbMysqlConfig & msg);
		static ::proto_ff::pbMysqlConfig* new_pbmsg(){ return new ::proto_ff::pbMysqlConfig(); }
		static ::proto_ff::pbMysqlConfig make_pbmsg(){ return ::proto_ff::pbMysqlConfig(); }
	};
	typedef struct pbMysqlConfig_s pbMysqlConfig_t;

	struct pbRedisConfig_s {
		pbRedisConfig_s();
		virtual ~pbRedisConfig_s(){}
		int CreateInit();
		int ResumeInit();
		std::string RedisIp;//
		uint32_t RedisPort;//
		std::string RedisPass;//

		virtual void write_to_pbmsg(::proto_ff::pbRedisConfig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::pbRedisConfig & msg);
		static ::proto_ff::pbRedisConfig* new_pbmsg(){ return new ::proto_ff::pbRedisConfig(); }
		static ::proto_ff::pbRedisConfig make_pbmsg(){ return ::proto_ff::pbRedisConfig(); }
	};
	typedef struct pbRedisConfig_s pbRedisConfig_t;

	struct pbRouteConfig_s {
		pbRouteConfig_s();
		virtual ~pbRouteConfig_s(){}
		int CreateInit();
		int ResumeInit();
		std::string MasterIp;//
		uint32_t MasterPort;//
		std::string NamingHost;//
		std::string NamingPath;//
		std::string RouteAgent;//

		virtual void write_to_pbmsg(::proto_ff::pbRouteConfig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::pbRouteConfig & msg);
		static ::proto_ff::pbRouteConfig* new_pbmsg(){ return new ::proto_ff::pbRouteConfig(); }
		static ::proto_ff::pbRouteConfig make_pbmsg(){ return ::proto_ff::pbRouteConfig(); }
	};
	typedef struct pbRouteConfig_s pbRouteConfig_t;

	struct pbAllServerConfig_s {
		pbAllServerConfig_s();
		virtual ~pbAllServerConfig_s(){}
		int CreateInit();
		int ResumeInit();
		std::string Server;//
		std::string ID;//
		uint32_t ServerType;//

		virtual void write_to_pbmsg(::proto_ff::pbAllServerConfig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::pbAllServerConfig & msg);
		static ::proto_ff::pbAllServerConfig* new_pbmsg(){ return new ::proto_ff::pbAllServerConfig(); }
		static ::proto_ff::pbAllServerConfig make_pbmsg(){ return ::proto_ff::pbAllServerConfig(); }
	};
	typedef struct pbAllServerConfig_s pbAllServerConfig_t;

	struct pbPluginConfig_s {
		pbPluginConfig_s();
		virtual ~pbPluginConfig_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t ServerType;//
		std::vector<std::string> FramePlugins;//
		std::vector<std::string> ServerPlugins;//
		std::vector<std::string> WorkPlugins;//
		std::vector<struct pbAllServerConfig_s> ServerList;//

		virtual void write_to_pbmsg(::proto_ff::pbPluginConfig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::pbPluginConfig & msg);
		static ::proto_ff::pbPluginConfig* new_pbmsg(){ return new ::proto_ff::pbPluginConfig(); }
		static ::proto_ff::pbPluginConfig make_pbmsg(){ return ::proto_ff::pbPluginConfig(); }
	};
	typedef struct pbPluginConfig_s pbPluginConfig_t;

	struct pbTableConfig_s {
		pbTableConfig_s();
		virtual ~pbTableConfig_s(){}
		int CreateInit();
		int ResumeInit();
		std::string TableName;//
		uint32_t TableCount;//
		bool Cache;//

		virtual void write_to_pbmsg(::proto_ff::pbTableConfig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::pbTableConfig & msg);
		static ::proto_ff::pbTableConfig* new_pbmsg(){ return new ::proto_ff::pbTableConfig(); }
		static ::proto_ff::pbTableConfig make_pbmsg(){ return ::proto_ff::pbTableConfig(); }
	};
	typedef struct pbTableConfig_s pbTableConfig_t;

	struct pbNFServerConfig_s {
		pbNFServerConfig_s();
		virtual ~pbNFServerConfig_s(){}
		int CreateInit();
		int ResumeInit();
		std::string ServerId;//
		uint32_t ServerType;//
		std::string ServerName;//
		uint32_t BusId;//
		uint32_t BusLength;//
		std::string LinkMode;//
		std::string Url;//
		uint32_t IdleSleepUS;//
		uint32_t HandleMsgNumPerFrame;//
		uint64_t ServerOpenTime;//
		std::string LoadProtoDs;//
		bool CrossServer;//
		std::string ServerIp;//
		uint32_t ServerPort;//
		std::string ExternalServerIp;//
		uint32_t ExternalServerPort;//
		uint32_t HttpPort;//
		uint32_t MaxConnectNum;//
		uint32_t WorkThreadNum;//
		uint32_t NetThreadNum;//
		bool Security;//
		bool WebSocket;//
		uint32_t ParseType;//
		struct pbRouteConfig_s RouteConfig;//
		struct pbMysqlConfig_s MysqlConfig;//
		std::string DefaultDBName;//
		std::string CrossDBName;//
		struct pbRedisConfig_s RedisConfig;//
		std::string sendEmail;//
		std::string sendEmailPass;//
		std::string sendEmailUrl;//
		std::string sendEmailPort;//
		std::string recvEmail;//
		std::string wxWorkdRobot;//
		uint32_t MaxOnlinePlayerNum;//
		uint32_t HeartBeatTimeout;//
		uint32_t ClientKeepAliveTimeout;//
		uint32_t ClientVersion;//

		virtual void write_to_pbmsg(::proto_ff::pbNFServerConfig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::pbNFServerConfig & msg);
		static ::proto_ff::pbNFServerConfig* new_pbmsg(){ return new ::proto_ff::pbNFServerConfig(); }
		static ::proto_ff::pbNFServerConfig make_pbmsg(){ return ::proto_ff::pbNFServerConfig(); }
	};
	typedef struct pbNFServerConfig_s pbNFServerConfig_t;

	struct wxWorkRobotText_s {
		wxWorkRobotText_s();
		virtual ~wxWorkRobotText_s(){}
		int CreateInit();
		int ResumeInit();
		std::string content;//
		std::vector<std::string> mentioned_list;//
		std::vector<std::string> mentioned_mobile_list;//

		virtual void write_to_pbmsg(::proto_ff::wxWorkRobotText & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::wxWorkRobotText & msg);
		static ::proto_ff::wxWorkRobotText* new_pbmsg(){ return new ::proto_ff::wxWorkRobotText(); }
		static ::proto_ff::wxWorkRobotText make_pbmsg(){ return ::proto_ff::wxWorkRobotText(); }
	};
	typedef struct wxWorkRobotText_s wxWorkRobotText_t;

	struct wxWorkRobotHttpPost_s {
		wxWorkRobotHttpPost_s();
		virtual ~wxWorkRobotHttpPost_s(){}
		int CreateInit();
		int ResumeInit();
		std::string msgtype;//
		struct wxWorkRobotText_s text;//

		virtual void write_to_pbmsg(::proto_ff::wxWorkRobotHttpPost & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::wxWorkRobotHttpPost & msg);
		static ::proto_ff::wxWorkRobotHttpPost* new_pbmsg(){ return new ::proto_ff::wxWorkRobotHttpPost(); }
		static ::proto_ff::wxWorkRobotHttpPost make_pbmsg(){ return ::proto_ff::wxWorkRobotHttpPost(); }
	};
	typedef struct wxWorkRobotHttpPost_s wxWorkRobotHttpPost_t;

}

