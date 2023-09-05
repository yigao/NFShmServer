#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "ServerConfig.pb.h"
#include "ServerConfig_s.h"

#define DEFINE_WORLDEXTERNALCONFIG_WHITELIST_MAX_NUM 100
#define DEFINE_GAMEEXTERNALGAME_ROOMID_MAX_NUM 10
#define DEFINE_GAMEEXTERNALCONFIG_GAME_MAX_NUM 10


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

	struct GameExternalGame_s : public NFDescStoreSeqOP {
		GameExternalGame_s();
		virtual ~GameExternalGame_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t GameId;
		NFShmVector<uint32_t, DEFINE_GAMEEXTERNALGAME_ROOMID_MAX_NUM> RoomId;

		virtual void write_to_pbmsg(::proto_ff::GameExternalGame & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GameExternalGame & msg);
		static ::proto_ff::GameExternalGame* new_pbmsg(){ return new ::proto_ff::GameExternalGame(); }
		static ::proto_ff::GameExternalGame make_pbmsg(){ return ::proto_ff::GameExternalGame(); }
	};
	typedef struct GameExternalGame_s GameExternalGame_t;

	struct GameExternalConfig_s : public NFDescStoreSeqOP {
		GameExternalConfig_s();
		virtual ~GameExternalConfig_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct GameExternalGame_s, DEFINE_GAMEEXTERNALCONFIG_GAME_MAX_NUM> Game;
		uint32_t MaxDeskNunOneRoom;

		virtual void write_to_pbmsg(::proto_ff::GameExternalConfig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GameExternalConfig & msg);
		static ::proto_ff::GameExternalConfig* new_pbmsg(){ return new ::proto_ff::GameExternalConfig(); }
		static ::proto_ff::GameExternalConfig make_pbmsg(){ return ::proto_ff::GameExternalConfig(); }
	};
	typedef struct GameExternalConfig_s GameExternalConfig_t;

}

