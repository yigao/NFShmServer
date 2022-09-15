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

}

