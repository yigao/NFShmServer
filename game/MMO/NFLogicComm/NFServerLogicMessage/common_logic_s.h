#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "common_logic.pb.h"
#include "common_logic_s.h"

namespace proto_ff_s {

	struct PacketMsg_s {
		PacketMsg_s();
		virtual ~PacketMsg_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t cmd;
		uint32_t serverType;
		uint32_t upper_limit;
		uint32_t min_interval;
		uint32_t control_time;

		virtual void write_to_pbmsg(::proto_ff::PacketMsg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::PacketMsg & msg);
		static ::proto_ff::PacketMsg* new_pbmsg(){ return new ::proto_ff::PacketMsg(); }
		static ::proto_ff::PacketMsg make_pbmsg(){ return ::proto_ff::PacketMsg(); }
	};
	typedef struct PacketMsg_s PacketMsg_t;

	struct ServerPacketMsg_s {
		ServerPacketMsg_s();
		virtual ~ServerPacketMsg_s(){}
		int CreateInit();
		int ResumeInit();
		std::vector<struct PacketMsg_s> PacketMsg;

		virtual void write_to_pbmsg(::proto_ff::ServerPacketMsg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ServerPacketMsg & msg);
		static ::proto_ff::ServerPacketMsg* new_pbmsg(){ return new ::proto_ff::ServerPacketMsg(); }
		static ::proto_ff::ServerPacketMsg make_pbmsg(){ return ::proto_ff::ServerPacketMsg(); }
	};
	typedef struct ServerPacketMsg_s ServerPacketMsg_t;

	struct WorldExternalConfig_s : public NFDescStoreSeqOP {
		WorldExternalConfig_s();
		virtual ~WorldExternalConfig_s(){}
		int CreateInit();
		int ResumeInit();
		bool TokenTimeCheck;
		bool WhiteListState;
		uint32_t MaxRegisterNum;
		NFShmVector<uint64_t, 100> WhiteList;

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

	struct MapPosInfo_s {
		MapPosInfo_s();
		virtual ~MapPosInfo_s(){}
		int CreateInit();
		int ResumeInit();
		double x;
		double y;
		double z;

		virtual void write_to_pbmsg(::proto_ff::MapPosInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MapPosInfo & msg);
		static ::proto_ff::MapPosInfo* new_pbmsg(){ return new ::proto_ff::MapPosInfo(); }
		static ::proto_ff::MapPosInfo make_pbmsg(){ return ::proto_ff::MapPosInfo(); }
	};
	typedef struct MapPosInfo_s MapPosInfo_t;

	struct MapJsonConfigObjsPos_s {
		MapJsonConfigObjsPos_s();
		virtual ~MapJsonConfigObjsPos_s(){}
		int CreateInit();
		int ResumeInit();
		struct MapPosInfo_s pos;
		double rot;

		virtual void write_to_pbmsg(::proto_ff::MapJsonConfigObjsPos & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MapJsonConfigObjsPos & msg);
		static ::proto_ff::MapJsonConfigObjsPos* new_pbmsg(){ return new ::proto_ff::MapJsonConfigObjsPos(); }
		static ::proto_ff::MapJsonConfigObjsPos make_pbmsg(){ return ::proto_ff::MapJsonConfigObjsPos(); }
	};
	typedef struct MapJsonConfigObjsPos_s MapJsonConfigObjsPos_t;

	struct MapJsonConfigObjs_s {
		MapJsonConfigObjs_s();
		virtual ~MapJsonConfigObjs_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		std::vector<struct MapJsonConfigObjsPos_s> pos;

		virtual void write_to_pbmsg(::proto_ff::MapJsonConfigObjs & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MapJsonConfigObjs & msg);
		static ::proto_ff::MapJsonConfigObjs* new_pbmsg(){ return new ::proto_ff::MapJsonConfigObjs(); }
		static ::proto_ff::MapJsonConfigObjs make_pbmsg(){ return ::proto_ff::MapJsonConfigObjs(); }
	};
	typedef struct MapJsonConfigObjs_s MapJsonConfigObjs_t;

	struct MapJsonConfigAreaDetail_s {
		MapJsonConfigAreaDetail_s();
		virtual ~MapJsonConfigAreaDetail_s(){}
		int CreateInit();
		int ResumeInit();
		double radius;
		struct MapPosInfo_s pos;

		virtual void write_to_pbmsg(::proto_ff::MapJsonConfigAreaDetail & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MapJsonConfigAreaDetail & msg);
		static ::proto_ff::MapJsonConfigAreaDetail* new_pbmsg(){ return new ::proto_ff::MapJsonConfigAreaDetail(); }
		static ::proto_ff::MapJsonConfigAreaDetail make_pbmsg(){ return ::proto_ff::MapJsonConfigAreaDetail(); }
	};
	typedef struct MapJsonConfigAreaDetail_s MapJsonConfigAreaDetail_t;

	struct MapJsonConfigArea_s {
		MapJsonConfigArea_s();
		virtual ~MapJsonConfigArea_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		std::vector<struct MapJsonConfigAreaDetail_s> detail;

		virtual void write_to_pbmsg(::proto_ff::MapJsonConfigArea & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MapJsonConfigArea & msg);
		static ::proto_ff::MapJsonConfigArea* new_pbmsg(){ return new ::proto_ff::MapJsonConfigArea(); }
		static ::proto_ff::MapJsonConfigArea make_pbmsg(){ return ::proto_ff::MapJsonConfigArea(); }
	};
	typedef struct MapJsonConfigArea_s MapJsonConfigArea_t;

	struct MapJsonConfigPath_s {
		MapJsonConfigPath_s();
		virtual ~MapJsonConfigPath_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		std::vector<struct MapPosInfo_s> pos;

		virtual void write_to_pbmsg(::proto_ff::MapJsonConfigPath & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MapJsonConfigPath & msg);
		static ::proto_ff::MapJsonConfigPath* new_pbmsg(){ return new ::proto_ff::MapJsonConfigPath(); }
		static ::proto_ff::MapJsonConfigPath make_pbmsg(){ return ::proto_ff::MapJsonConfigPath(); }
	};
	typedef struct MapJsonConfigPath_s MapJsonConfigPath_t;

	struct MapJsonConfig_s {
		MapJsonConfig_s();
		virtual ~MapJsonConfig_s(){}
		int CreateInit();
		int ResumeInit();
		std::vector<struct MapJsonConfigObjs_s> objs;
		std::vector<struct MapJsonConfigArea_s> areas;
		std::vector<struct MapJsonConfigPath_s> paths;

		virtual void write_to_pbmsg(::proto_ff::MapJsonConfig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MapJsonConfig & msg);
		static ::proto_ff::MapJsonConfig* new_pbmsg(){ return new ::proto_ff::MapJsonConfig(); }
		static ::proto_ff::MapJsonConfig make_pbmsg(){ return ::proto_ff::MapJsonConfig(); }
	};
	typedef struct MapJsonConfig_s MapJsonConfig_t;

}

