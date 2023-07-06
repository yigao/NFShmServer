#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "DBProto.pb.h"
#include "DBProto_s.h"
#include "Com.pb.h"
#include "Com_s.h"

namespace proto_ff_s {

	struct tbAccountTable_s : public NFDescStoreSeqOP {
		tbAccountTable_s();
		virtual ~tbAccountTable_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t player_id;
		NFShmString<128> account;
		NFShmString<128> password;
		uint32_t account_type;
		NFShmString<128> device_id;
		uint64_t phonenum;

		virtual void write_to_pbmsg(::proto_ff::tbAccountTable & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::tbAccountTable & msg);
		static ::proto_ff::tbAccountTable* new_pbmsg(){ return new ::proto_ff::tbAccountTable(); }
		static ::proto_ff::tbAccountTable make_pbmsg(){ return ::proto_ff::tbAccountTable(); }
	};
	typedef struct tbAccountTable_s tbAccountTable_t;

}

