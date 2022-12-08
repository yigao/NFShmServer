#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "back.pb.h"
#include "back_s.h"

namespace proto_ff_s {

	struct backback_s : public NFDescStoreSeqOP {
		backback_s();
		virtual ~backback_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t type;
		int32_t typeParam;
		NFShmString<60> name;
		int32_t group;
		int32_t functionUnlock;
		int32_t levelLimit;
		int64_t PboxId;
		int64_t boxId;
		int32_t backDay;
		int32_t costItemID;
		int32_t costNum;
		int32_t PcostItemID;
		int32_t PcostNum;
		int32_t AcostItemID;
		int32_t AcostNum;
		NFArray<int32_t, 2> param;

		virtual void write_to_pbmsg(::proto_ff::backback & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::backback & msg);
		static ::proto_ff::backback* new_pbmsg(){ return new ::proto_ff::backback(); }
		static ::proto_ff::backback make_pbmsg(){ return ::proto_ff::backback(); }
	};
	typedef struct backback_s backback_t;

	struct Sheet_backback_s : public NFDescStoreSeqOP {
		Sheet_backback_s();
		virtual ~Sheet_backback_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct backback_s, 20> backback_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_backback & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_backback & msg);
		static ::proto_ff::Sheet_backback* new_pbmsg(){ return new ::proto_ff::Sheet_backback(); }
		static ::proto_ff::Sheet_backback make_pbmsg(){ return ::proto_ff::Sheet_backback(); }
	};
	typedef struct Sheet_backback_s Sheet_backback_t;

}

