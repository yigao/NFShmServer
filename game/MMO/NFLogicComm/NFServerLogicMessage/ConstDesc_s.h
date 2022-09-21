#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "ConstDesc.pb.h"
#include "ConstDesc_s.h"
#include "proto_common.pb.h"
#include "proto_common_s.h"

namespace proto_ff_s {

	struct ConstDesc_s : public NFDescStoreSeqOP {
		ConstDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<128> value;

		virtual void write_to_pbmsg(::proto_ff::ConstDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ConstDesc & msg);
		static ::proto_ff::ConstDesc* new_pbmsg(){ return new ::proto_ff::ConstDesc(); }
		static ::proto_ff::ConstDesc make_pbmsg(){ return ::proto_ff::ConstDesc(); }
	};
	typedef struct ConstDesc_s ConstDesc_t;

	struct Sheet_ConstDesc_s : public NFDescStoreSeqOP {
		Sheet_ConstDesc_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct ConstDesc_s, 100> ConstDesc_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_ConstDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ConstDesc & msg);
		static ::proto_ff::Sheet_ConstDesc* new_pbmsg(){ return new ::proto_ff::Sheet_ConstDesc(); }
		static ::proto_ff::Sheet_ConstDesc make_pbmsg(){ return ::proto_ff::Sheet_ConstDesc(); }
	};
	typedef struct Sheet_ConstDesc_s Sheet_ConstDesc_t;

}

