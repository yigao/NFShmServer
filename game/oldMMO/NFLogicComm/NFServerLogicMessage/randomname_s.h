#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "randomname.pb.h"
#include "randomname_s.h"

#define DEFINE_SHEET_RANDOMNAMEMANFIRST_E_RANDOMNAMEMANFIRST_LIST_MAX_NUM 100
#define DEFINE_SHEET_RANDOMNAMEMANSECOND_E_RANDOMNAMEMANSECOND_LIST_MAX_NUM 60
#define DEFINE_SHEET_RANDOMNAMEMANTHIRD_E_RANDOMNAMEMANTHIRD_LIST_MAX_NUM 500
#define DEFINE_SHEET_RANDOMNAMEWOMANFIRST_E_RANDOMNAMEWOMANFIRST_LIST_MAX_NUM 300
#define DEFINE_SHEET_RANDOMNAMEWOMANSECOND_E_RANDOMNAMEWOMANSECOND_LIST_MAX_NUM 40
#define DEFINE_SHEET_RANDOMNAMEWOMANTHIRD_E_RANDOMNAMEWOMANTHIRD_LIST_MAX_NUM 400
namespace proto_ff_s {

	struct E_RandomnameManfirst_s : public NFDescStoreSeqOP {
		E_RandomnameManfirst_s();
		virtual ~E_RandomnameManfirst_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmString<60> m_name;

		virtual void write_to_pbmsg(::proto_ff::E_RandomnameManfirst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RandomnameManfirst & msg);
		static ::proto_ff::E_RandomnameManfirst* new_pbmsg(){ return new ::proto_ff::E_RandomnameManfirst(); }
		static ::proto_ff::E_RandomnameManfirst make_pbmsg(){ return ::proto_ff::E_RandomnameManfirst(); }
	};
	typedef struct E_RandomnameManfirst_s E_RandomnameManfirst_t;

	struct Sheet_RandomnameManfirst_s : public NFDescStoreSeqOP {
		Sheet_RandomnameManfirst_s();
		virtual ~Sheet_RandomnameManfirst_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RandomnameManfirst_s, DEFINE_SHEET_RANDOMNAMEMANFIRST_E_RANDOMNAMEMANFIRST_LIST_MAX_NUM> E_RandomnameManfirst_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RandomnameManfirst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RandomnameManfirst & msg);
		static ::proto_ff::Sheet_RandomnameManfirst* new_pbmsg(){ return new ::proto_ff::Sheet_RandomnameManfirst(); }
		static ::proto_ff::Sheet_RandomnameManfirst make_pbmsg(){ return ::proto_ff::Sheet_RandomnameManfirst(); }
	};
	typedef struct Sheet_RandomnameManfirst_s Sheet_RandomnameManfirst_t;

	struct E_RandomnameMansecond_s : public NFDescStoreSeqOP {
		E_RandomnameMansecond_s();
		virtual ~E_RandomnameMansecond_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmString<60> m_name;

		virtual void write_to_pbmsg(::proto_ff::E_RandomnameMansecond & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RandomnameMansecond & msg);
		static ::proto_ff::E_RandomnameMansecond* new_pbmsg(){ return new ::proto_ff::E_RandomnameMansecond(); }
		static ::proto_ff::E_RandomnameMansecond make_pbmsg(){ return ::proto_ff::E_RandomnameMansecond(); }
	};
	typedef struct E_RandomnameMansecond_s E_RandomnameMansecond_t;

	struct Sheet_RandomnameMansecond_s : public NFDescStoreSeqOP {
		Sheet_RandomnameMansecond_s();
		virtual ~Sheet_RandomnameMansecond_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RandomnameMansecond_s, DEFINE_SHEET_RANDOMNAMEMANSECOND_E_RANDOMNAMEMANSECOND_LIST_MAX_NUM> E_RandomnameMansecond_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RandomnameMansecond & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RandomnameMansecond & msg);
		static ::proto_ff::Sheet_RandomnameMansecond* new_pbmsg(){ return new ::proto_ff::Sheet_RandomnameMansecond(); }
		static ::proto_ff::Sheet_RandomnameMansecond make_pbmsg(){ return ::proto_ff::Sheet_RandomnameMansecond(); }
	};
	typedef struct Sheet_RandomnameMansecond_s Sheet_RandomnameMansecond_t;

	struct E_RandomnameManthird_s : public NFDescStoreSeqOP {
		E_RandomnameManthird_s();
		virtual ~E_RandomnameManthird_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmString<60> m_name;

		virtual void write_to_pbmsg(::proto_ff::E_RandomnameManthird & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RandomnameManthird & msg);
		static ::proto_ff::E_RandomnameManthird* new_pbmsg(){ return new ::proto_ff::E_RandomnameManthird(); }
		static ::proto_ff::E_RandomnameManthird make_pbmsg(){ return ::proto_ff::E_RandomnameManthird(); }
	};
	typedef struct E_RandomnameManthird_s E_RandomnameManthird_t;

	struct Sheet_RandomnameManthird_s : public NFDescStoreSeqOP {
		Sheet_RandomnameManthird_s();
		virtual ~Sheet_RandomnameManthird_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RandomnameManthird_s, DEFINE_SHEET_RANDOMNAMEMANTHIRD_E_RANDOMNAMEMANTHIRD_LIST_MAX_NUM> E_RandomnameManthird_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RandomnameManthird & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RandomnameManthird & msg);
		static ::proto_ff::Sheet_RandomnameManthird* new_pbmsg(){ return new ::proto_ff::Sheet_RandomnameManthird(); }
		static ::proto_ff::Sheet_RandomnameManthird make_pbmsg(){ return ::proto_ff::Sheet_RandomnameManthird(); }
	};
	typedef struct Sheet_RandomnameManthird_s Sheet_RandomnameManthird_t;

	struct E_RandomnameWomanfirst_s : public NFDescStoreSeqOP {
		E_RandomnameWomanfirst_s();
		virtual ~E_RandomnameWomanfirst_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmString<60> m_name;

		virtual void write_to_pbmsg(::proto_ff::E_RandomnameWomanfirst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RandomnameWomanfirst & msg);
		static ::proto_ff::E_RandomnameWomanfirst* new_pbmsg(){ return new ::proto_ff::E_RandomnameWomanfirst(); }
		static ::proto_ff::E_RandomnameWomanfirst make_pbmsg(){ return ::proto_ff::E_RandomnameWomanfirst(); }
	};
	typedef struct E_RandomnameWomanfirst_s E_RandomnameWomanfirst_t;

	struct Sheet_RandomnameWomanfirst_s : public NFDescStoreSeqOP {
		Sheet_RandomnameWomanfirst_s();
		virtual ~Sheet_RandomnameWomanfirst_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RandomnameWomanfirst_s, DEFINE_SHEET_RANDOMNAMEWOMANFIRST_E_RANDOMNAMEWOMANFIRST_LIST_MAX_NUM> E_RandomnameWomanfirst_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RandomnameWomanfirst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RandomnameWomanfirst & msg);
		static ::proto_ff::Sheet_RandomnameWomanfirst* new_pbmsg(){ return new ::proto_ff::Sheet_RandomnameWomanfirst(); }
		static ::proto_ff::Sheet_RandomnameWomanfirst make_pbmsg(){ return ::proto_ff::Sheet_RandomnameWomanfirst(); }
	};
	typedef struct Sheet_RandomnameWomanfirst_s Sheet_RandomnameWomanfirst_t;

	struct E_RandomnameWomansecond_s : public NFDescStoreSeqOP {
		E_RandomnameWomansecond_s();
		virtual ~E_RandomnameWomansecond_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmString<60> m_name;

		virtual void write_to_pbmsg(::proto_ff::E_RandomnameWomansecond & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RandomnameWomansecond & msg);
		static ::proto_ff::E_RandomnameWomansecond* new_pbmsg(){ return new ::proto_ff::E_RandomnameWomansecond(); }
		static ::proto_ff::E_RandomnameWomansecond make_pbmsg(){ return ::proto_ff::E_RandomnameWomansecond(); }
	};
	typedef struct E_RandomnameWomansecond_s E_RandomnameWomansecond_t;

	struct Sheet_RandomnameWomansecond_s : public NFDescStoreSeqOP {
		Sheet_RandomnameWomansecond_s();
		virtual ~Sheet_RandomnameWomansecond_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RandomnameWomansecond_s, DEFINE_SHEET_RANDOMNAMEWOMANSECOND_E_RANDOMNAMEWOMANSECOND_LIST_MAX_NUM> E_RandomnameWomansecond_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RandomnameWomansecond & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RandomnameWomansecond & msg);
		static ::proto_ff::Sheet_RandomnameWomansecond* new_pbmsg(){ return new ::proto_ff::Sheet_RandomnameWomansecond(); }
		static ::proto_ff::Sheet_RandomnameWomansecond make_pbmsg(){ return ::proto_ff::Sheet_RandomnameWomansecond(); }
	};
	typedef struct Sheet_RandomnameWomansecond_s Sheet_RandomnameWomansecond_t;

	struct E_RandomnameWomanthird_s : public NFDescStoreSeqOP {
		E_RandomnameWomanthird_s();
		virtual ~E_RandomnameWomanthird_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmString<60> m_name;

		virtual void write_to_pbmsg(::proto_ff::E_RandomnameWomanthird & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RandomnameWomanthird & msg);
		static ::proto_ff::E_RandomnameWomanthird* new_pbmsg(){ return new ::proto_ff::E_RandomnameWomanthird(); }
		static ::proto_ff::E_RandomnameWomanthird make_pbmsg(){ return ::proto_ff::E_RandomnameWomanthird(); }
	};
	typedef struct E_RandomnameWomanthird_s E_RandomnameWomanthird_t;

	struct Sheet_RandomnameWomanthird_s : public NFDescStoreSeqOP {
		Sheet_RandomnameWomanthird_s();
		virtual ~Sheet_RandomnameWomanthird_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RandomnameWomanthird_s, DEFINE_SHEET_RANDOMNAMEWOMANTHIRD_E_RANDOMNAMEWOMANTHIRD_LIST_MAX_NUM> E_RandomnameWomanthird_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RandomnameWomanthird & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RandomnameWomanthird & msg);
		static ::proto_ff::Sheet_RandomnameWomanthird* new_pbmsg(){ return new ::proto_ff::Sheet_RandomnameWomanthird(); }
		static ::proto_ff::Sheet_RandomnameWomanthird make_pbmsg(){ return ::proto_ff::Sheet_RandomnameWomanthird(); }
	};
	typedef struct Sheet_RandomnameWomanthird_s Sheet_RandomnameWomanthird_t;

}

