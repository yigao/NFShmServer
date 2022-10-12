#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "treasureBowl.pb.h"
#include "treasureBowl_s.h"

namespace proto_ff_s {

	struct treasureBowltreasureBowl_s : public NFDescStoreSeqOP {
		treasureBowltreasureBowl_s();
		int CreateInit();
		int ResumeInit();
		int32_t Id;
		int32_t level;
		int32_t Type;
		int32_t price;
		int32_t returnD;
		int32_t returnVip;
		int64_t returnItemID;
		int32_t returnItem;
		int64_t boxid;
		int64_t skillid;
		NFSizeString<60> skilldes;

		virtual void write_to_pbmsg(::proto_ff::treasureBowltreasureBowl & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::treasureBowltreasureBowl & msg);
		static ::proto_ff::treasureBowltreasureBowl* new_pbmsg(){ return new ::proto_ff::treasureBowltreasureBowl(); }
		static ::proto_ff::treasureBowltreasureBowl make_pbmsg(){ return ::proto_ff::treasureBowltreasureBowl(); }
	};
	typedef struct treasureBowltreasureBowl_s treasureBowltreasureBowl_t;

	struct Sheet_treasureBowltreasureBowl_s : public NFDescStoreSeqOP {
		Sheet_treasureBowltreasureBowl_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct treasureBowltreasureBowl_s, 20> treasureBowltreasureBowl_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_treasureBowltreasureBowl & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_treasureBowltreasureBowl & msg);
		static ::proto_ff::Sheet_treasureBowltreasureBowl* new_pbmsg(){ return new ::proto_ff::Sheet_treasureBowltreasureBowl(); }
		static ::proto_ff::Sheet_treasureBowltreasureBowl make_pbmsg(){ return ::proto_ff::Sheet_treasureBowltreasureBowl(); }
	};
	typedef struct Sheet_treasureBowltreasureBowl_s Sheet_treasureBowltreasureBowl_t;

}

