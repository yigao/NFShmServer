#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "common_logic.pb.h"
#include "common_logic_s.h"

namespace proto_ff_s {

	struct PacketMsg_s {
		PacketMsg_s();
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
		int CreateInit();
		int ResumeInit();
		std::vector<struct PacketMsg_s> PacketMsg;

		virtual void write_to_pbmsg(::proto_ff::ServerPacketMsg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ServerPacketMsg & msg);
		static ::proto_ff::ServerPacketMsg* new_pbmsg(){ return new ::proto_ff::ServerPacketMsg(); }
		static ::proto_ff::ServerPacketMsg make_pbmsg(){ return ::proto_ff::ServerPacketMsg(); }
	};
	typedef struct ServerPacketMsg_s ServerPacketMsg_t;

}

