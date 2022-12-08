#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "constant.pb.h"
#include "constant_s.h"

namespace proto_ff_s {

	struct constantconstant_s : public NFDescStoreSeqOP {
		constantconstant_s();
		virtual ~constantconstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t constantid;
		int64_t constantdata;
		NFShmString<200> stringdata;

		virtual void write_to_pbmsg(::proto_ff::constantconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::constantconstant & msg);
		static ::proto_ff::constantconstant* new_pbmsg(){ return new ::proto_ff::constantconstant(); }
		static ::proto_ff::constantconstant make_pbmsg(){ return ::proto_ff::constantconstant(); }
	};
	typedef struct constantconstant_s constantconstant_t;

	struct Sheet_constantconstant_s : public NFDescStoreSeqOP {
		Sheet_constantconstant_s();
		virtual ~Sheet_constantconstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct constantconstant_s, 300> constantconstant_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_constantconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_constantconstant & msg);
		static ::proto_ff::Sheet_constantconstant* new_pbmsg(){ return new ::proto_ff::Sheet_constantconstant(); }
		static ::proto_ff::Sheet_constantconstant make_pbmsg(){ return ::proto_ff::Sheet_constantconstant(); }
	};
	typedef struct Sheet_constantconstant_s Sheet_constantconstant_t;

}

