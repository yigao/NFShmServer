#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "dynamicexp.pb.h"
#include "dynamicexp_s.h"

namespace proto_ff_s {

	struct dynamicexpdynamicexpdynamicDesc_s : public NFDescStoreSeqOP {
		dynamicexpdynamicexpdynamicDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t exp;

		virtual void write_to_pbmsg(::proto_ff::dynamicexpdynamicexpdynamicDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dynamicexpdynamicexpdynamicDesc & msg);
		static ::proto_ff::dynamicexpdynamicexpdynamicDesc* new_pbmsg(){ return new ::proto_ff::dynamicexpdynamicexpdynamicDesc(); }
		static ::proto_ff::dynamicexpdynamicexpdynamicDesc make_pbmsg(){ return ::proto_ff::dynamicexpdynamicexpdynamicDesc(); }
	};
	typedef struct dynamicexpdynamicexpdynamicDesc_s dynamicexpdynamicexpdynamicDesc_t;

	struct dynamicexpdynamicexp_s : public NFDescStoreSeqOP {
		dynamicexpdynamicexp_s();
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		NFArray<struct dynamicexpdynamicexpdynamicDesc_s, 5> dynamic;

		virtual void write_to_pbmsg(::proto_ff::dynamicexpdynamicexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dynamicexpdynamicexp & msg);
		static ::proto_ff::dynamicexpdynamicexp* new_pbmsg(){ return new ::proto_ff::dynamicexpdynamicexp(); }
		static ::proto_ff::dynamicexpdynamicexp make_pbmsg(){ return ::proto_ff::dynamicexpdynamicexp(); }
	};
	typedef struct dynamicexpdynamicexp_s dynamicexpdynamicexp_t;

	struct Sheet_dynamicexpdynamicexp_s : public NFDescStoreSeqOP {
		Sheet_dynamicexpdynamicexp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct dynamicexpdynamicexp_s, 2000> dynamicexpdynamicexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_dynamicexpdynamicexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_dynamicexpdynamicexp & msg);
		static ::proto_ff::Sheet_dynamicexpdynamicexp* new_pbmsg(){ return new ::proto_ff::Sheet_dynamicexpdynamicexp(); }
		static ::proto_ff::Sheet_dynamicexpdynamicexp make_pbmsg(){ return ::proto_ff::Sheet_dynamicexpdynamicexp(); }
	};
	typedef struct Sheet_dynamicexpdynamicexp_s Sheet_dynamicexpdynamicexp_t;

}

