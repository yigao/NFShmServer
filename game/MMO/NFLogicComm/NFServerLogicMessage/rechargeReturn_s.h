#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "rechargeReturn.pb.h"
#include "rechargeReturn_s.h"

namespace proto_ff_s {

	struct rechargeReturnrechargeReturn_s : public NFDescStoreSeqOP {
		rechargeReturnrechargeReturn_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t group;
		int32_t minLine;
		int32_t diamondRRatio;
		int32_t timeID;
		int64_t mailID;

		virtual void write_to_pbmsg(::proto_ff::rechargeReturnrechargeReturn & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rechargeReturnrechargeReturn & msg);
		static ::proto_ff::rechargeReturnrechargeReturn* new_pbmsg(){ return new ::proto_ff::rechargeReturnrechargeReturn(); }
		static ::proto_ff::rechargeReturnrechargeReturn make_pbmsg(){ return ::proto_ff::rechargeReturnrechargeReturn(); }
	};
	typedef struct rechargeReturnrechargeReturn_s rechargeReturnrechargeReturn_t;

	struct Sheet_rechargeReturnrechargeReturn_s : public NFDescStoreSeqOP {
		Sheet_rechargeReturnrechargeReturn_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct rechargeReturnrechargeReturn_s, 112> rechargeReturnrechargeReturn_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_rechargeReturnrechargeReturn & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_rechargeReturnrechargeReturn & msg);
		static ::proto_ff::Sheet_rechargeReturnrechargeReturn* new_pbmsg(){ return new ::proto_ff::Sheet_rechargeReturnrechargeReturn(); }
		static ::proto_ff::Sheet_rechargeReturnrechargeReturn make_pbmsg(){ return ::proto_ff::Sheet_rechargeReturnrechargeReturn(); }
	};
	typedef struct Sheet_rechargeReturnrechargeReturn_s Sheet_rechargeReturnrechargeReturn_t;

	struct rechargeReturntime_s : public NFDescStoreSeqOP {
		rechargeReturntime_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t timeType;
		NFSizeString<32> timeA;
		NFSizeString<32> timeB;

		virtual void write_to_pbmsg(::proto_ff::rechargeReturntime & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rechargeReturntime & msg);
		static ::proto_ff::rechargeReturntime* new_pbmsg(){ return new ::proto_ff::rechargeReturntime(); }
		static ::proto_ff::rechargeReturntime make_pbmsg(){ return ::proto_ff::rechargeReturntime(); }
	};
	typedef struct rechargeReturntime_s rechargeReturntime_t;

	struct Sheet_rechargeReturntime_s : public NFDescStoreSeqOP {
		Sheet_rechargeReturntime_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct rechargeReturntime_s, 109> rechargeReturntime_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_rechargeReturntime & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_rechargeReturntime & msg);
		static ::proto_ff::Sheet_rechargeReturntime* new_pbmsg(){ return new ::proto_ff::Sheet_rechargeReturntime(); }
		static ::proto_ff::Sheet_rechargeReturntime make_pbmsg(){ return ::proto_ff::Sheet_rechargeReturntime(); }
	};
	typedef struct Sheet_rechargeReturntime_s Sheet_rechargeReturntime_t;

	struct rechargeReturncontinuousReturn_s : public NFDescStoreSeqOP {
		rechargeReturncontinuousReturn_s();
		int CreateInit();
		int ResumeInit();
		int32_t Gear;
		int64_t boxid;

		virtual void write_to_pbmsg(::proto_ff::rechargeReturncontinuousReturn & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rechargeReturncontinuousReturn & msg);
		static ::proto_ff::rechargeReturncontinuousReturn* new_pbmsg(){ return new ::proto_ff::rechargeReturncontinuousReturn(); }
		static ::proto_ff::rechargeReturncontinuousReturn make_pbmsg(){ return ::proto_ff::rechargeReturncontinuousReturn(); }
	};
	typedef struct rechargeReturncontinuousReturn_s rechargeReturncontinuousReturn_t;

	struct Sheet_rechargeReturncontinuousReturn_s : public NFDescStoreSeqOP {
		Sheet_rechargeReturncontinuousReturn_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct rechargeReturncontinuousReturn_s, 109> rechargeReturncontinuousReturn_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_rechargeReturncontinuousReturn & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_rechargeReturncontinuousReturn & msg);
		static ::proto_ff::Sheet_rechargeReturncontinuousReturn* new_pbmsg(){ return new ::proto_ff::Sheet_rechargeReturncontinuousReturn(); }
		static ::proto_ff::Sheet_rechargeReturncontinuousReturn make_pbmsg(){ return ::proto_ff::Sheet_rechargeReturncontinuousReturn(); }
	};
	typedef struct Sheet_rechargeReturncontinuousReturn_s Sheet_rechargeReturncontinuousReturn_t;

	struct rechargeReturnrechargeTrigger_s : public NFDescStoreSeqOP {
		rechargeReturnrechargeTrigger_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t timeType;
		NFSizeString<32> timeA;
		NFSizeString<32> timeB;
		int32_t reset;
		int32_t triggerType;
		NFSizeString<90> TriggerValue;
		int64_t boxId;
		int64_t mailId;

		virtual void write_to_pbmsg(::proto_ff::rechargeReturnrechargeTrigger & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rechargeReturnrechargeTrigger & msg);
		static ::proto_ff::rechargeReturnrechargeTrigger* new_pbmsg(){ return new ::proto_ff::rechargeReturnrechargeTrigger(); }
		static ::proto_ff::rechargeReturnrechargeTrigger make_pbmsg(){ return ::proto_ff::rechargeReturnrechargeTrigger(); }
	};
	typedef struct rechargeReturnrechargeTrigger_s rechargeReturnrechargeTrigger_t;

	struct Sheet_rechargeReturnrechargeTrigger_s : public NFDescStoreSeqOP {
		Sheet_rechargeReturnrechargeTrigger_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct rechargeReturnrechargeTrigger_s, 141> rechargeReturnrechargeTrigger_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_rechargeReturnrechargeTrigger & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_rechargeReturnrechargeTrigger & msg);
		static ::proto_ff::Sheet_rechargeReturnrechargeTrigger* new_pbmsg(){ return new ::proto_ff::Sheet_rechargeReturnrechargeTrigger(); }
		static ::proto_ff::Sheet_rechargeReturnrechargeTrigger make_pbmsg(){ return ::proto_ff::Sheet_rechargeReturnrechargeTrigger(); }
	};
	typedef struct Sheet_rechargeReturnrechargeTrigger_s Sheet_rechargeReturnrechargeTrigger_t;

	struct rechargeReturnconstant_s : public NFDescStoreSeqOP {
		rechargeReturnconstant_s();
		int CreateInit();
		int ResumeInit();
		int64_t constantid;
		int64_t constantdata;
		NFSizeString<32> stringdata;

		virtual void write_to_pbmsg(::proto_ff::rechargeReturnconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rechargeReturnconstant & msg);
		static ::proto_ff::rechargeReturnconstant* new_pbmsg(){ return new ::proto_ff::rechargeReturnconstant(); }
		static ::proto_ff::rechargeReturnconstant make_pbmsg(){ return ::proto_ff::rechargeReturnconstant(); }
	};
	typedef struct rechargeReturnconstant_s rechargeReturnconstant_t;

	struct Sheet_rechargeReturnconstant_s : public NFDescStoreSeqOP {
		Sheet_rechargeReturnconstant_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct rechargeReturnconstant_s, 105> rechargeReturnconstant_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_rechargeReturnconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_rechargeReturnconstant & msg);
		static ::proto_ff::Sheet_rechargeReturnconstant* new_pbmsg(){ return new ::proto_ff::Sheet_rechargeReturnconstant(); }
		static ::proto_ff::Sheet_rechargeReturnconstant make_pbmsg(){ return ::proto_ff::Sheet_rechargeReturnconstant(); }
	};
	typedef struct Sheet_rechargeReturnconstant_s Sheet_rechargeReturnconstant_t;

}

