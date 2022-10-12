#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "randomname.pb.h"
#include "randomname_s.h"

namespace proto_ff_s {

	struct randomnamemanfirst_s : public NFDescStoreSeqOP {
		randomnamemanfirst_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<60> name;

		virtual void write_to_pbmsg(::proto_ff::randomnamemanfirst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::randomnamemanfirst & msg);
		static ::proto_ff::randomnamemanfirst* new_pbmsg(){ return new ::proto_ff::randomnamemanfirst(); }
		static ::proto_ff::randomnamemanfirst make_pbmsg(){ return ::proto_ff::randomnamemanfirst(); }
	};
	typedef struct randomnamemanfirst_s randomnamemanfirst_t;

	struct Sheet_randomnamemanfirst_s : public NFDescStoreSeqOP {
		Sheet_randomnamemanfirst_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct randomnamemanfirst_s, 100> randomnamemanfirst_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_randomnamemanfirst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_randomnamemanfirst & msg);
		static ::proto_ff::Sheet_randomnamemanfirst* new_pbmsg(){ return new ::proto_ff::Sheet_randomnamemanfirst(); }
		static ::proto_ff::Sheet_randomnamemanfirst make_pbmsg(){ return ::proto_ff::Sheet_randomnamemanfirst(); }
	};
	typedef struct Sheet_randomnamemanfirst_s Sheet_randomnamemanfirst_t;

	struct randomnamemansecond_s : public NFDescStoreSeqOP {
		randomnamemansecond_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<60> name;

		virtual void write_to_pbmsg(::proto_ff::randomnamemansecond & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::randomnamemansecond & msg);
		static ::proto_ff::randomnamemansecond* new_pbmsg(){ return new ::proto_ff::randomnamemansecond(); }
		static ::proto_ff::randomnamemansecond make_pbmsg(){ return ::proto_ff::randomnamemansecond(); }
	};
	typedef struct randomnamemansecond_s randomnamemansecond_t;

	struct Sheet_randomnamemansecond_s : public NFDescStoreSeqOP {
		Sheet_randomnamemansecond_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct randomnamemansecond_s, 60> randomnamemansecond_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_randomnamemansecond & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_randomnamemansecond & msg);
		static ::proto_ff::Sheet_randomnamemansecond* new_pbmsg(){ return new ::proto_ff::Sheet_randomnamemansecond(); }
		static ::proto_ff::Sheet_randomnamemansecond make_pbmsg(){ return ::proto_ff::Sheet_randomnamemansecond(); }
	};
	typedef struct Sheet_randomnamemansecond_s Sheet_randomnamemansecond_t;

	struct randomnamemanthird_s : public NFDescStoreSeqOP {
		randomnamemanthird_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<60> name;

		virtual void write_to_pbmsg(::proto_ff::randomnamemanthird & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::randomnamemanthird & msg);
		static ::proto_ff::randomnamemanthird* new_pbmsg(){ return new ::proto_ff::randomnamemanthird(); }
		static ::proto_ff::randomnamemanthird make_pbmsg(){ return ::proto_ff::randomnamemanthird(); }
	};
	typedef struct randomnamemanthird_s randomnamemanthird_t;

	struct Sheet_randomnamemanthird_s : public NFDescStoreSeqOP {
		Sheet_randomnamemanthird_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct randomnamemanthird_s, 500> randomnamemanthird_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_randomnamemanthird & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_randomnamemanthird & msg);
		static ::proto_ff::Sheet_randomnamemanthird* new_pbmsg(){ return new ::proto_ff::Sheet_randomnamemanthird(); }
		static ::proto_ff::Sheet_randomnamemanthird make_pbmsg(){ return ::proto_ff::Sheet_randomnamemanthird(); }
	};
	typedef struct Sheet_randomnamemanthird_s Sheet_randomnamemanthird_t;

	struct randomnamewomanfirst_s : public NFDescStoreSeqOP {
		randomnamewomanfirst_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<60> name;

		virtual void write_to_pbmsg(::proto_ff::randomnamewomanfirst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::randomnamewomanfirst & msg);
		static ::proto_ff::randomnamewomanfirst* new_pbmsg(){ return new ::proto_ff::randomnamewomanfirst(); }
		static ::proto_ff::randomnamewomanfirst make_pbmsg(){ return ::proto_ff::randomnamewomanfirst(); }
	};
	typedef struct randomnamewomanfirst_s randomnamewomanfirst_t;

	struct Sheet_randomnamewomanfirst_s : public NFDescStoreSeqOP {
		Sheet_randomnamewomanfirst_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct randomnamewomanfirst_s, 300> randomnamewomanfirst_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_randomnamewomanfirst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_randomnamewomanfirst & msg);
		static ::proto_ff::Sheet_randomnamewomanfirst* new_pbmsg(){ return new ::proto_ff::Sheet_randomnamewomanfirst(); }
		static ::proto_ff::Sheet_randomnamewomanfirst make_pbmsg(){ return ::proto_ff::Sheet_randomnamewomanfirst(); }
	};
	typedef struct Sheet_randomnamewomanfirst_s Sheet_randomnamewomanfirst_t;

	struct randomnamewomansecond_s : public NFDescStoreSeqOP {
		randomnamewomansecond_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<60> name;

		virtual void write_to_pbmsg(::proto_ff::randomnamewomansecond & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::randomnamewomansecond & msg);
		static ::proto_ff::randomnamewomansecond* new_pbmsg(){ return new ::proto_ff::randomnamewomansecond(); }
		static ::proto_ff::randomnamewomansecond make_pbmsg(){ return ::proto_ff::randomnamewomansecond(); }
	};
	typedef struct randomnamewomansecond_s randomnamewomansecond_t;

	struct Sheet_randomnamewomansecond_s : public NFDescStoreSeqOP {
		Sheet_randomnamewomansecond_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct randomnamewomansecond_s, 40> randomnamewomansecond_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_randomnamewomansecond & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_randomnamewomansecond & msg);
		static ::proto_ff::Sheet_randomnamewomansecond* new_pbmsg(){ return new ::proto_ff::Sheet_randomnamewomansecond(); }
		static ::proto_ff::Sheet_randomnamewomansecond make_pbmsg(){ return ::proto_ff::Sheet_randomnamewomansecond(); }
	};
	typedef struct Sheet_randomnamewomansecond_s Sheet_randomnamewomansecond_t;

	struct randomnamewomanthird_s : public NFDescStoreSeqOP {
		randomnamewomanthird_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<60> name;

		virtual void write_to_pbmsg(::proto_ff::randomnamewomanthird & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::randomnamewomanthird & msg);
		static ::proto_ff::randomnamewomanthird* new_pbmsg(){ return new ::proto_ff::randomnamewomanthird(); }
		static ::proto_ff::randomnamewomanthird make_pbmsg(){ return ::proto_ff::randomnamewomanthird(); }
	};
	typedef struct randomnamewomanthird_s randomnamewomanthird_t;

	struct Sheet_randomnamewomanthird_s : public NFDescStoreSeqOP {
		Sheet_randomnamewomanthird_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct randomnamewomanthird_s, 400> randomnamewomanthird_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_randomnamewomanthird & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_randomnamewomanthird & msg);
		static ::proto_ff::Sheet_randomnamewomanthird* new_pbmsg(){ return new ::proto_ff::Sheet_randomnamewomanthird(); }
		static ::proto_ff::Sheet_randomnamewomanthird make_pbmsg(){ return ::proto_ff::Sheet_randomnamewomanthird(); }
	};
	typedef struct Sheet_randomnamewomanthird_s Sheet_randomnamewomanthird_t;

}

