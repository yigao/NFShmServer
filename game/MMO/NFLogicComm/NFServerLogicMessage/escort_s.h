#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "escort.pb.h"
#include "escort_s.h"

namespace proto_ff_s {

	struct escortescortshuangDesc_s : public NFDescStoreSeqOP {
		escortescortshuangDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t duration;
		int32_t Time;

		virtual void write_to_pbmsg(::proto_ff::escortescortshuangDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::escortescortshuangDesc & msg);
		static ::proto_ff::escortescortshuangDesc* new_pbmsg(){ return new ::proto_ff::escortescortshuangDesc(); }
		static ::proto_ff::escortescortshuangDesc make_pbmsg(){ return ::proto_ff::escortescortshuangDesc(); }
	};
	typedef struct escortescortshuangDesc_s escortescortshuangDesc_t;

	struct escortescort_s : public NFDescStoreSeqOP {
		escortescort_s();
		int CreateInit();
		int ResumeInit();
		int64_t convoyId;
		NFSizeString<60> convoyName;
		int64_t MonsterId;
		int32_t convoyLevel;
		int32_t chance;
		int64_t tokenId;
		int32_t tokenNumber;
		int32_t dayTime;
		int64_t mapId;
		int64_t startArea;
		int64_t endArea;
		int64_t startAreaLink;
		int64_t endAreaLink;
		int32_t DistanceA;
		int32_t DistanceB;
		int32_t DistanceC;
		int32_t rewardMoney;
		int32_t timeLimit;
		NFArray<struct escortescortshuangDesc_s, 2> shuang;

		virtual void write_to_pbmsg(::proto_ff::escortescort & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::escortescort & msg);
		static ::proto_ff::escortescort* new_pbmsg(){ return new ::proto_ff::escortescort(); }
		static ::proto_ff::escortescort make_pbmsg(){ return ::proto_ff::escortescort(); }
	};
	typedef struct escortescort_s escortescort_t;

	struct Sheet_escortescort_s : public NFDescStoreSeqOP {
		Sheet_escortescort_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct escortescort_s, 20> escortescort_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_escortescort & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_escortescort & msg);
		static ::proto_ff::Sheet_escortescort* new_pbmsg(){ return new ::proto_ff::Sheet_escortescort(); }
		static ::proto_ff::Sheet_escortescort make_pbmsg(){ return ::proto_ff::Sheet_escortescort(); }
	};
	typedef struct Sheet_escortescort_s Sheet_escortescort_t;

	struct escortchanceescortDesc_s : public NFDescStoreSeqOP {
		escortchanceescortDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t chance;
		int64_t ID;

		virtual void write_to_pbmsg(::proto_ff::escortchanceescortDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::escortchanceescortDesc & msg);
		static ::proto_ff::escortchanceescortDesc* new_pbmsg(){ return new ::proto_ff::escortchanceescortDesc(); }
		static ::proto_ff::escortchanceescortDesc make_pbmsg(){ return ::proto_ff::escortchanceescortDesc(); }
	};
	typedef struct escortchanceescortDesc_s escortchanceescortDesc_t;

	struct escortchance_s : public NFDescStoreSeqOP {
		escortchance_s();
		int CreateInit();
		int ResumeInit();
		int64_t convoyId;
		NFArray<struct escortchanceescortDesc_s, 4> escort;

		virtual void write_to_pbmsg(::proto_ff::escortchance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::escortchance & msg);
		static ::proto_ff::escortchance* new_pbmsg(){ return new ::proto_ff::escortchance(); }
		static ::proto_ff::escortchance make_pbmsg(){ return ::proto_ff::escortchance(); }
	};
	typedef struct escortchance_s escortchance_t;

	struct Sheet_escortchance_s : public NFDescStoreSeqOP {
		Sheet_escortchance_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct escortchance_s, 20> escortchance_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_escortchance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_escortchance & msg);
		static ::proto_ff::Sheet_escortchance* new_pbmsg(){ return new ::proto_ff::Sheet_escortchance(); }
		static ::proto_ff::Sheet_escortchance make_pbmsg(){ return ::proto_ff::Sheet_escortchance(); }
	};
	typedef struct Sheet_escortchance_s Sheet_escortchance_t;

	struct escortrewardExprewardDesc_s : public NFDescStoreSeqOP {
		escortrewardExprewardDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t Exp;

		virtual void write_to_pbmsg(::proto_ff::escortrewardExprewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::escortrewardExprewardDesc & msg);
		static ::proto_ff::escortrewardExprewardDesc* new_pbmsg(){ return new ::proto_ff::escortrewardExprewardDesc(); }
		static ::proto_ff::escortrewardExprewardDesc make_pbmsg(){ return ::proto_ff::escortrewardExprewardDesc(); }
	};
	typedef struct escortrewardExprewardDesc_s escortrewardExprewardDesc_t;

	struct escortrewardExp_s : public NFDescStoreSeqOP {
		escortrewardExp_s();
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		NFArray<struct escortrewardExprewardDesc_s, 4> reward;

		virtual void write_to_pbmsg(::proto_ff::escortrewardExp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::escortrewardExp & msg);
		static ::proto_ff::escortrewardExp* new_pbmsg(){ return new ::proto_ff::escortrewardExp(); }
		static ::proto_ff::escortrewardExp make_pbmsg(){ return ::proto_ff::escortrewardExp(); }
	};
	typedef struct escortrewardExp_s escortrewardExp_t;

	struct Sheet_escortrewardExp_s : public NFDescStoreSeqOP {
		Sheet_escortrewardExp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct escortrewardExp_s, 2000> escortrewardExp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_escortrewardExp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_escortrewardExp & msg);
		static ::proto_ff::Sheet_escortrewardExp* new_pbmsg(){ return new ::proto_ff::Sheet_escortrewardExp(); }
		static ::proto_ff::Sheet_escortrewardExp make_pbmsg(){ return ::proto_ff::Sheet_escortrewardExp(); }
	};
	typedef struct Sheet_escortrewardExp_s Sheet_escortrewardExp_t;

}

