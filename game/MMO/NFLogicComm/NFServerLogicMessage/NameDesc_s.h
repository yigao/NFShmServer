#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "NameDesc.pb.h"
#include "NameDesc_s.h"
#include "proto_common.pb.h"
#include "proto_common_s.h"

namespace proto_ff_s {

	struct NameDesc_s : public NFDescStoreSeqOP {
		NameDesc_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		NFSizeString<64> name;

		virtual void write_to_pbmsg(::proto_ff::NameDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::NameDesc & msg);
		static ::proto_ff::NameDesc* new_pbmsg(){ return new ::proto_ff::NameDesc(); }
		static ::proto_ff::NameDesc make_pbmsg(){ return ::proto_ff::NameDesc(); }
	};
	typedef struct NameDesc_s NameDesc_t;

	struct Sheet_NameDesc_s : public NFDescStoreSeqOP {
		Sheet_NameDesc_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct NameDesc_s, 100> NameDesc_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_NameDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_NameDesc & msg);
		static ::proto_ff::Sheet_NameDesc* new_pbmsg(){ return new ::proto_ff::Sheet_NameDesc(); }
		static ::proto_ff::Sheet_NameDesc make_pbmsg(){ return ::proto_ff::Sheet_NameDesc(); }
	};
	typedef struct Sheet_NameDesc_s Sheet_NameDesc_t;

}

