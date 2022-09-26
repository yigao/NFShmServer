#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "GMtools.pb.h"
#include "GMtools_s.h"

namespace proto_ff_s {

	struct GMtoolsGMTools_s : public NFDescStoreSeqOP {
		GMtoolsGMTools_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t type;
		NFSizeString<32> typePrarm;

		virtual void write_to_pbmsg(::proto_ff::GMtoolsGMTools & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GMtoolsGMTools & msg);
		static ::proto_ff::GMtoolsGMTools* new_pbmsg(){ return new ::proto_ff::GMtoolsGMTools(); }
		static ::proto_ff::GMtoolsGMTools make_pbmsg(){ return ::proto_ff::GMtoolsGMTools(); }
	};
	typedef struct GMtoolsGMTools_s GMtoolsGMTools_t;

	struct Sheet_GMtoolsGMTools_s : public NFDescStoreSeqOP {
		Sheet_GMtoolsGMTools_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct GMtoolsGMTools_s, 112> GMtoolsGMTools_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GMtoolsGMTools & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GMtoolsGMTools & msg);
		static ::proto_ff::Sheet_GMtoolsGMTools* new_pbmsg(){ return new ::proto_ff::Sheet_GMtoolsGMTools(); }
		static ::proto_ff::Sheet_GMtoolsGMTools make_pbmsg(){ return ::proto_ff::Sheet_GMtoolsGMTools(); }
	};
	typedef struct Sheet_GMtoolsGMTools_s Sheet_GMtoolsGMTools_t;

	struct GMtoolsrecharge_s : public NFDescStoreSeqOP {
		GMtoolsrecharge_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t cost;
		int32_t rechaarge;

		virtual void write_to_pbmsg(::proto_ff::GMtoolsrecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GMtoolsrecharge & msg);
		static ::proto_ff::GMtoolsrecharge* new_pbmsg(){ return new ::proto_ff::GMtoolsrecharge(); }
		static ::proto_ff::GMtoolsrecharge make_pbmsg(){ return ::proto_ff::GMtoolsrecharge(); }
	};
	typedef struct GMtoolsrecharge_s GMtoolsrecharge_t;

	struct Sheet_GMtoolsrecharge_s : public NFDescStoreSeqOP {
		Sheet_GMtoolsrecharge_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct GMtoolsrecharge_s, 118> GMtoolsrecharge_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GMtoolsrecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GMtoolsrecharge & msg);
		static ::proto_ff::Sheet_GMtoolsrecharge* new_pbmsg(){ return new ::proto_ff::Sheet_GMtoolsrecharge(); }
		static ::proto_ff::Sheet_GMtoolsrecharge make_pbmsg(){ return ::proto_ff::Sheet_GMtoolsrecharge(); }
	};
	typedef struct Sheet_GMtoolsrecharge_s Sheet_GMtoolsrecharge_t;

	struct GMtoolsgift_s : public NFDescStoreSeqOP {
		GMtoolsgift_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t upperLimit;
		NFSizeString<32> condition;
		int32_t cost;
		int32_t daily;
		int64_t boxid;

		virtual void write_to_pbmsg(::proto_ff::GMtoolsgift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GMtoolsgift & msg);
		static ::proto_ff::GMtoolsgift* new_pbmsg(){ return new ::proto_ff::GMtoolsgift(); }
		static ::proto_ff::GMtoolsgift make_pbmsg(){ return ::proto_ff::GMtoolsgift(); }
	};
	typedef struct GMtoolsgift_s GMtoolsgift_t;

	struct Sheet_GMtoolsgift_s : public NFDescStoreSeqOP {
		Sheet_GMtoolsgift_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct GMtoolsgift_s, 117> GMtoolsgift_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GMtoolsgift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GMtoolsgift & msg);
		static ::proto_ff::Sheet_GMtoolsgift* new_pbmsg(){ return new ::proto_ff::Sheet_GMtoolsgift(); }
		static ::proto_ff::Sheet_GMtoolsgift make_pbmsg(){ return ::proto_ff::Sheet_GMtoolsgift(); }
	};
	typedef struct Sheet_GMtoolsgift_s Sheet_GMtoolsgift_t;

	struct GMtoolsunlimit_s : public NFDescStoreSeqOP {
		GMtoolsunlimit_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t upperLimit;
		int32_t cost;
		int64_t boxid;
		int32_t dailyNum;

		virtual void write_to_pbmsg(::proto_ff::GMtoolsunlimit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GMtoolsunlimit & msg);
		static ::proto_ff::GMtoolsunlimit* new_pbmsg(){ return new ::proto_ff::GMtoolsunlimit(); }
		static ::proto_ff::GMtoolsunlimit make_pbmsg(){ return ::proto_ff::GMtoolsunlimit(); }
	};
	typedef struct GMtoolsunlimit_s GMtoolsunlimit_t;

	struct Sheet_GMtoolsunlimit_s : public NFDescStoreSeqOP {
		Sheet_GMtoolsunlimit_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct GMtoolsunlimit_s, 108> GMtoolsunlimit_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GMtoolsunlimit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GMtoolsunlimit & msg);
		static ::proto_ff::Sheet_GMtoolsunlimit* new_pbmsg(){ return new ::proto_ff::Sheet_GMtoolsunlimit(); }
		static ::proto_ff::Sheet_GMtoolsunlimit make_pbmsg(){ return ::proto_ff::Sheet_GMtoolsunlimit(); }
	};
	typedef struct Sheet_GMtoolsunlimit_s Sheet_GMtoolsunlimit_t;

	struct GMtoolsupperLimit_s : public NFDescStoreSeqOP {
		GMtoolsupperLimit_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t type;
		int32_t param;

		virtual void write_to_pbmsg(::proto_ff::GMtoolsupperLimit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GMtoolsupperLimit & msg);
		static ::proto_ff::GMtoolsupperLimit* new_pbmsg(){ return new ::proto_ff::GMtoolsupperLimit(); }
		static ::proto_ff::GMtoolsupperLimit make_pbmsg(){ return ::proto_ff::GMtoolsupperLimit(); }
	};
	typedef struct GMtoolsupperLimit_s GMtoolsupperLimit_t;

	struct Sheet_GMtoolsupperLimit_s : public NFDescStoreSeqOP {
		Sheet_GMtoolsupperLimit_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct GMtoolsupperLimit_s, 108> GMtoolsupperLimit_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GMtoolsupperLimit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GMtoolsupperLimit & msg);
		static ::proto_ff::Sheet_GMtoolsupperLimit* new_pbmsg(){ return new ::proto_ff::Sheet_GMtoolsupperLimit(); }
		static ::proto_ff::Sheet_GMtoolsupperLimit make_pbmsg(){ return ::proto_ff::Sheet_GMtoolsupperLimit(); }
	};
	typedef struct Sheet_GMtoolsupperLimit_s Sheet_GMtoolsupperLimit_t;

}

