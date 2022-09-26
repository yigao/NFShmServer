#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "huoyuedu.pb.h"
#include "huoyuedu_s.h"

namespace proto_ff_s {

	struct huoyuedureward_s : public NFDescStoreSeqOP {
		huoyuedureward_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t type;
		int32_t activeScore;
		int64_t rewardId;
		int32_t rewardNum;

		virtual void write_to_pbmsg(::proto_ff::huoyuedureward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::huoyuedureward & msg);
		static ::proto_ff::huoyuedureward* new_pbmsg(){ return new ::proto_ff::huoyuedureward(); }
		static ::proto_ff::huoyuedureward make_pbmsg(){ return ::proto_ff::huoyuedureward(); }
	};
	typedef struct huoyuedureward_s huoyuedureward_t;

	struct Sheet_huoyuedureward_s : public NFDescStoreSeqOP {
		Sheet_huoyuedureward_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct huoyuedureward_s, 20> huoyuedureward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_huoyuedureward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_huoyuedureward & msg);
		static ::proto_ff::Sheet_huoyuedureward* new_pbmsg(){ return new ::proto_ff::Sheet_huoyuedureward(); }
		static ::proto_ff::Sheet_huoyuedureward make_pbmsg(){ return ::proto_ff::Sheet_huoyuedureward(); }
	};
	typedef struct Sheet_huoyuedureward_s Sheet_huoyuedureward_t;

	struct huoyueduactive_s : public NFDescStoreSeqOP {
		huoyueduactive_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<60> name;
		int32_t type;
		NFSizeString<60> args;
		int64_t funciontID;
		int32_t countRule;
		NFSizeString<60> countParam;
		int32_t number;
		int32_t viptype;
		int32_t otherNum;
		int32_t eachScore;
		int32_t activityNum;
		int32_t cycle;

		virtual void write_to_pbmsg(::proto_ff::huoyueduactive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::huoyueduactive & msg);
		static ::proto_ff::huoyueduactive* new_pbmsg(){ return new ::proto_ff::huoyueduactive(); }
		static ::proto_ff::huoyueduactive make_pbmsg(){ return ::proto_ff::huoyueduactive(); }
	};
	typedef struct huoyueduactive_s huoyueduactive_t;

	struct Sheet_huoyueduactive_s : public NFDescStoreSeqOP {
		Sheet_huoyueduactive_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct huoyueduactive_s, 80> huoyueduactive_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_huoyueduactive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_huoyueduactive & msg);
		static ::proto_ff::Sheet_huoyueduactive* new_pbmsg(){ return new ::proto_ff::Sheet_huoyueduactive(); }
		static ::proto_ff::Sheet_huoyueduactive make_pbmsg(){ return ::proto_ff::Sheet_huoyueduactive(); }
	};
	typedef struct Sheet_huoyueduactive_s Sheet_huoyueduactive_t;

}

