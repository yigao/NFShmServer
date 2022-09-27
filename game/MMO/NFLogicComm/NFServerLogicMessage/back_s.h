#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "back.pb.h"
#include "back_s.h"

namespace proto_ff_s {

	struct backbackbackDesc_s : public NFDescStoreSeqOP {
		backbackbackDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Expend;
		int32_t Num;
		int32_t Exp;

		virtual void write_to_pbmsg(::proto_ff::backbackbackDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::backbackbackDesc & msg);
		static ::proto_ff::backbackbackDesc* new_pbmsg(){ return new ::proto_ff::backbackbackDesc(); }
		static ::proto_ff::backbackbackDesc make_pbmsg(){ return ::proto_ff::backbackbackDesc(); }
	};
	typedef struct backbackbackDesc_s backbackbackDesc_t;

	struct backback_s : public NFDescStoreSeqOP {
		backback_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t type;
		NFSizeString<60> name;
		int32_t backTimes;
		int32_t vipType;
		int32_t group;
		int64_t duplicateID;
		int64_t bossTypeID;
		int32_t functionUnlock;
		int32_t levelLimit;
		int64_t itemId;
		NFSizeString<60> icon;
		NFArray<struct backbackbackDesc_s, 2> back;
		NFArray<int32_t, 2> param;

		virtual void write_to_pbmsg(::proto_ff::backback & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::backback & msg);
		static ::proto_ff::backback* new_pbmsg(){ return new ::proto_ff::backback(); }
		static ::proto_ff::backback make_pbmsg(){ return ::proto_ff::backback(); }
	};
	typedef struct backback_s backback_t;

	struct Sheet_backback_s : public NFDescStoreSeqOP {
		Sheet_backback_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct backback_s, 160> backback_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_backback & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_backback & msg);
		static ::proto_ff::Sheet_backback* new_pbmsg(){ return new ::proto_ff::Sheet_backback(); }
		static ::proto_ff::Sheet_backback make_pbmsg(){ return ::proto_ff::Sheet_backback(); }
	};
	typedef struct Sheet_backback_s Sheet_backback_t;

}

