#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "intimacy.pb.h"
#include "intimacy_s.h"

namespace proto_ff_s {

	struct intimacyintimacyattributeDesc_s : public NFDescStoreSeqOP {
		intimacyintimacyattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::intimacyintimacyattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::intimacyintimacyattributeDesc & msg);
		static ::proto_ff::intimacyintimacyattributeDesc* new_pbmsg(){ return new ::proto_ff::intimacyintimacyattributeDesc(); }
		static ::proto_ff::intimacyintimacyattributeDesc make_pbmsg(){ return ::proto_ff::intimacyintimacyattributeDesc(); }
	};
	typedef struct intimacyintimacyattributeDesc_s intimacyintimacyattributeDesc_t;

	struct intimacyintimacy_s : public NFDescStoreSeqOP {
		intimacyintimacy_s();
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int32_t intimacyMin;
		int32_t intimacyMax;
		NFArray<struct intimacyintimacyattributeDesc_s, 3> attribute;

		virtual void write_to_pbmsg(::proto_ff::intimacyintimacy & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::intimacyintimacy & msg);
		static ::proto_ff::intimacyintimacy* new_pbmsg(){ return new ::proto_ff::intimacyintimacy(); }
		static ::proto_ff::intimacyintimacy make_pbmsg(){ return ::proto_ff::intimacyintimacy(); }
	};
	typedef struct intimacyintimacy_s intimacyintimacy_t;

	struct Sheet_intimacyintimacy_s : public NFDescStoreSeqOP {
		Sheet_intimacyintimacy_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct intimacyintimacy_s, 115> intimacyintimacy_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_intimacyintimacy & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_intimacyintimacy & msg);
		static ::proto_ff::Sheet_intimacyintimacy* new_pbmsg(){ return new ::proto_ff::Sheet_intimacyintimacy(); }
		static ::proto_ff::Sheet_intimacyintimacy make_pbmsg(){ return ::proto_ff::Sheet_intimacyintimacy(); }
	};
	typedef struct Sheet_intimacyintimacy_s Sheet_intimacyintimacy_t;

	struct intimacygift_s : public NFDescStoreSeqOP {
		intimacygift_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t moneyType;
		int32_t price;
		int32_t intimacy;

		virtual void write_to_pbmsg(::proto_ff::intimacygift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::intimacygift & msg);
		static ::proto_ff::intimacygift* new_pbmsg(){ return new ::proto_ff::intimacygift(); }
		static ::proto_ff::intimacygift make_pbmsg(){ return ::proto_ff::intimacygift(); }
	};
	typedef struct intimacygift_s intimacygift_t;

	struct Sheet_intimacygift_s : public NFDescStoreSeqOP {
		Sheet_intimacygift_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct intimacygift_s, 105> intimacygift_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_intimacygift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_intimacygift & msg);
		static ::proto_ff::Sheet_intimacygift* new_pbmsg(){ return new ::proto_ff::Sheet_intimacygift(); }
		static ::proto_ff::Sheet_intimacygift make_pbmsg(){ return ::proto_ff::Sheet_intimacygift(); }
	};
	typedef struct Sheet_intimacygift_s Sheet_intimacygift_t;

}

