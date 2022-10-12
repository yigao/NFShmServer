#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "ranking.pb.h"
#include "ranking_s.h"

namespace proto_ff_s {

	struct rankingranking_s : public NFDescStoreSeqOP {
		rankingranking_s();
		int CreateInit();
		int ResumeInit();
		int32_t rankingID;
		NFSizeString<60> rankingName;
		int32_t save;
		int32_t capacity;
		int32_t showSize;
		int32_t rankModule;
		NFArray<int32_t, 5> dateID;

		virtual void write_to_pbmsg(::proto_ff::rankingranking & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rankingranking & msg);
		static ::proto_ff::rankingranking* new_pbmsg(){ return new ::proto_ff::rankingranking(); }
		static ::proto_ff::rankingranking make_pbmsg(){ return ::proto_ff::rankingranking(); }
	};
	typedef struct rankingranking_s rankingranking_t;

	struct Sheet_rankingranking_s : public NFDescStoreSeqOP {
		Sheet_rankingranking_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct rankingranking_s, 100> rankingranking_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_rankingranking & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_rankingranking & msg);
		static ::proto_ff::Sheet_rankingranking* new_pbmsg(){ return new ::proto_ff::Sheet_rankingranking(); }
		static ::proto_ff::Sheet_rankingranking make_pbmsg(){ return ::proto_ff::Sheet_rankingranking(); }
	};
	typedef struct Sheet_rankingranking_s Sheet_rankingranking_t;

	struct rankingdate_s : public NFDescStoreSeqOP {
		rankingdate_s();
		int CreateInit();
		int ResumeInit();
		int32_t dateID;
		NFSizeString<60> dateName;

		virtual void write_to_pbmsg(::proto_ff::rankingdate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rankingdate & msg);
		static ::proto_ff::rankingdate* new_pbmsg(){ return new ::proto_ff::rankingdate(); }
		static ::proto_ff::rankingdate make_pbmsg(){ return ::proto_ff::rankingdate(); }
	};
	typedef struct rankingdate_s rankingdate_t;

	struct Sheet_rankingdate_s : public NFDescStoreSeqOP {
		Sheet_rankingdate_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct rankingdate_s, 100> rankingdate_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_rankingdate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_rankingdate & msg);
		static ::proto_ff::Sheet_rankingdate* new_pbmsg(){ return new ::proto_ff::Sheet_rankingdate(); }
		static ::proto_ff::Sheet_rankingdate make_pbmsg(){ return ::proto_ff::Sheet_rankingdate(); }
	};
	typedef struct Sheet_rankingdate_s Sheet_rankingdate_t;

	struct rankingpkcons_s : public NFDescStoreSeqOP {
		rankingpkcons_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t valuedata;
		NFSizeString<60> stringdata;

		virtual void write_to_pbmsg(::proto_ff::rankingpkcons & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rankingpkcons & msg);
		static ::proto_ff::rankingpkcons* new_pbmsg(){ return new ::proto_ff::rankingpkcons(); }
		static ::proto_ff::rankingpkcons make_pbmsg(){ return ::proto_ff::rankingpkcons(); }
	};
	typedef struct rankingpkcons_s rankingpkcons_t;

	struct Sheet_rankingpkcons_s : public NFDescStoreSeqOP {
		Sheet_rankingpkcons_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct rankingpkcons_s, 20> rankingpkcons_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_rankingpkcons & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_rankingpkcons & msg);
		static ::proto_ff::Sheet_rankingpkcons* new_pbmsg(){ return new ::proto_ff::Sheet_rankingpkcons(); }
		static ::proto_ff::Sheet_rankingpkcons make_pbmsg(){ return ::proto_ff::Sheet_rankingpkcons(); }
	};
	typedef struct Sheet_rankingpkcons_s Sheet_rankingpkcons_t;

}

