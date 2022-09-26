#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "closetest.pb.h"
#include "closetest_s.h"

namespace proto_ff_s {

	struct closetestActivity_s : public NFDescStoreSeqOP {
		closetestActivity_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t Type;
		int32_t TypeParam;
		int64_t BoxId;

		virtual void write_to_pbmsg(::proto_ff::closetestActivity & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::closetestActivity & msg);
		static ::proto_ff::closetestActivity* new_pbmsg(){ return new ::proto_ff::closetestActivity(); }
		static ::proto_ff::closetestActivity make_pbmsg(){ return ::proto_ff::closetestActivity(); }
	};
	typedef struct closetestActivity_s closetestActivity_t;

	struct Sheet_closetestActivity_s : public NFDescStoreSeqOP {
		Sheet_closetestActivity_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct closetestActivity_s, 20> closetestActivity_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_closetestActivity & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_closetestActivity & msg);
		static ::proto_ff::Sheet_closetestActivity* new_pbmsg(){ return new ::proto_ff::Sheet_closetestActivity(); }
		static ::proto_ff::Sheet_closetestActivity make_pbmsg(){ return ::proto_ff::Sheet_closetestActivity(); }
	};
	typedef struct Sheet_closetestActivity_s Sheet_closetestActivity_t;

	struct closetestRebate_s : public NFDescStoreSeqOP {
		closetestRebate_s();
		int CreateInit();
		int ResumeInit();
		int32_t Day;
		int32_t ReturnParamA;
		int32_t ReturnParamB;

		virtual void write_to_pbmsg(::proto_ff::closetestRebate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::closetestRebate & msg);
		static ::proto_ff::closetestRebate* new_pbmsg(){ return new ::proto_ff::closetestRebate(); }
		static ::proto_ff::closetestRebate make_pbmsg(){ return ::proto_ff::closetestRebate(); }
	};
	typedef struct closetestRebate_s closetestRebate_t;

	struct Sheet_closetestRebate_s : public NFDescStoreSeqOP {
		Sheet_closetestRebate_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct closetestRebate_s, 20> closetestRebate_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_closetestRebate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_closetestRebate & msg);
		static ::proto_ff::Sheet_closetestRebate* new_pbmsg(){ return new ::proto_ff::Sheet_closetestRebate(); }
		static ::proto_ff::Sheet_closetestRebate make_pbmsg(){ return ::proto_ff::Sheet_closetestRebate(); }
	};
	typedef struct Sheet_closetestRebate_s Sheet_closetestRebate_t;

}

