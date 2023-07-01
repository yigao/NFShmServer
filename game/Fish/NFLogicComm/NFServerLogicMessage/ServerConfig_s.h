#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "ServerConfig.pb.h"
#include "ServerConfig_s.h"

#define DEFINE_WORLDEXTERNALCONFIG_WHITELIST_MAX_NUM 100
namespace proto_ff_s {

	struct WorldExternalConfig_s : public NFDescStoreSeqOP {
		WorldExternalConfig_s();
		virtual ~WorldExternalConfig_s(){}
		int CreateInit();
		int ResumeInit();
		bool TokenTimeCheck;
		bool WhiteListState;
		uint32_t MaxRegisterNum;
		NFShmVector<uint64_t, DEFINE_WORLDEXTERNALCONFIG_WHITELIST_MAX_NUM> WhiteList;
		uint32_t StartQueueNum;
		uint32_t MaxQueueNum;

		virtual void write_to_pbmsg(::proto_ff::WorldExternalConfig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::WorldExternalConfig & msg);
		static ::proto_ff::WorldExternalConfig* new_pbmsg(){ return new ::proto_ff::WorldExternalConfig(); }
		static ::proto_ff::WorldExternalConfig make_pbmsg(){ return ::proto_ff::WorldExternalConfig(); }
	};
	typedef struct WorldExternalConfig_s WorldExternalConfig_t;

	struct GameExternalConfig_s {
		GameExternalConfig_s();
		virtual ~GameExternalConfig_s(){}
		int CreateInit();
		int ResumeInit();
		std::vector<uint64_t> map;

		virtual void write_to_pbmsg(::proto_ff::GameExternalConfig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GameExternalConfig & msg);
		static ::proto_ff::GameExternalConfig* new_pbmsg(){ return new ::proto_ff::GameExternalConfig(); }
		static ::proto_ff::GameExternalConfig make_pbmsg(){ return ::proto_ff::GameExternalConfig(); }
	};
	typedef struct GameExternalConfig_s GameExternalConfig_t;

}

