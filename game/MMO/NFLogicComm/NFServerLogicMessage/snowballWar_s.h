#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "snowballWar.pb.h"
#include "snowballWar_s.h"

namespace proto_ff_s {

	struct snowballWarcons_s : public NFDescStoreSeqOP {
		snowballWarcons_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int64_t valuedata;
		NFSizeString<32> stringdata;

		virtual void write_to_pbmsg(::proto_ff::snowballWarcons & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::snowballWarcons & msg);
		static ::proto_ff::snowballWarcons* new_pbmsg(){ return new ::proto_ff::snowballWarcons(); }
		static ::proto_ff::snowballWarcons make_pbmsg(){ return ::proto_ff::snowballWarcons(); }
	};
	typedef struct snowballWarcons_s snowballWarcons_t;

	struct Sheet_snowballWarcons_s : public NFDescStoreSeqOP {
		Sheet_snowballWarcons_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct snowballWarcons_s, 118> snowballWarcons_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_snowballWarcons & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_snowballWarcons & msg);
		static ::proto_ff::Sheet_snowballWarcons* new_pbmsg(){ return new ::proto_ff::Sheet_snowballWarcons(); }
		static ::proto_ff::Sheet_snowballWarcons make_pbmsg(){ return ::proto_ff::Sheet_snowballWarcons(); }
	};
	typedef struct Sheet_snowballWarcons_s Sheet_snowballWarcons_t;

}

