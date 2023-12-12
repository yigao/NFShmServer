#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Sensitiveword.pb.h"
#include "E_Sensitiveword_s.h"

#define DEFINE_SHEET_SENSITIVEWORDWORD1_E_SENSITIVEWORDWORD1_LIST_MAX_NUM 32768
#define DEFINE_SHEET_SENSITIVEWORDWORD2_E_SENSITIVEWORDWORD2_LIST_MAX_NUM 32768
#define DEFINE_SHEET_SENSITIVEWORDWORD3_E_SENSITIVEWORDWORD3_LIST_MAX_NUM 32768


namespace proto_ff_s {

	struct E_SensitivewordWord1_s : public NFDescStoreSeqOP {
		E_SensitivewordWord1_s();
		virtual ~E_SensitivewordWord1_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		NFShmString<64> m_sensitiveWord;//敏感字

		virtual void write_to_pbmsg(::proto_ff::E_SensitivewordWord1 & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SensitivewordWord1 & msg);
		static ::proto_ff::E_SensitivewordWord1* new_pbmsg(){ return new ::proto_ff::E_SensitivewordWord1(); }
		static ::proto_ff::E_SensitivewordWord1 make_pbmsg(){ return ::proto_ff::E_SensitivewordWord1(); }
	};
	typedef struct E_SensitivewordWord1_s E_SensitivewordWord1_t;

	struct Sheet_SensitivewordWord1_s : public NFDescStoreSeqOP {
		Sheet_SensitivewordWord1_s();
		virtual ~Sheet_SensitivewordWord1_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SensitivewordWord1_s, DEFINE_SHEET_SENSITIVEWORDWORD1_E_SENSITIVEWORDWORD1_LIST_MAX_NUM> E_SensitivewordWord1_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SensitivewordWord1 & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SensitivewordWord1 & msg);
		static ::proto_ff::Sheet_SensitivewordWord1* new_pbmsg(){ return new ::proto_ff::Sheet_SensitivewordWord1(); }
		static ::proto_ff::Sheet_SensitivewordWord1 make_pbmsg(){ return ::proto_ff::Sheet_SensitivewordWord1(); }
	};
	typedef struct Sheet_SensitivewordWord1_s Sheet_SensitivewordWord1_t;

	struct E_SensitivewordWord2_s : public NFDescStoreSeqOP {
		E_SensitivewordWord2_s();
		virtual ~E_SensitivewordWord2_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		NFShmString<64> m_sensitiveWord;//敏感字

		virtual void write_to_pbmsg(::proto_ff::E_SensitivewordWord2 & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SensitivewordWord2 & msg);
		static ::proto_ff::E_SensitivewordWord2* new_pbmsg(){ return new ::proto_ff::E_SensitivewordWord2(); }
		static ::proto_ff::E_SensitivewordWord2 make_pbmsg(){ return ::proto_ff::E_SensitivewordWord2(); }
	};
	typedef struct E_SensitivewordWord2_s E_SensitivewordWord2_t;

	struct Sheet_SensitivewordWord2_s : public NFDescStoreSeqOP {
		Sheet_SensitivewordWord2_s();
		virtual ~Sheet_SensitivewordWord2_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SensitivewordWord2_s, DEFINE_SHEET_SENSITIVEWORDWORD2_E_SENSITIVEWORDWORD2_LIST_MAX_NUM> E_SensitivewordWord2_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SensitivewordWord2 & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SensitivewordWord2 & msg);
		static ::proto_ff::Sheet_SensitivewordWord2* new_pbmsg(){ return new ::proto_ff::Sheet_SensitivewordWord2(); }
		static ::proto_ff::Sheet_SensitivewordWord2 make_pbmsg(){ return ::proto_ff::Sheet_SensitivewordWord2(); }
	};
	typedef struct Sheet_SensitivewordWord2_s Sheet_SensitivewordWord2_t;

	struct E_SensitivewordWord3_s : public NFDescStoreSeqOP {
		E_SensitivewordWord3_s();
		virtual ~E_SensitivewordWord3_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		NFShmString<64> m_sensitiveWord;//敏感字

		virtual void write_to_pbmsg(::proto_ff::E_SensitivewordWord3 & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SensitivewordWord3 & msg);
		static ::proto_ff::E_SensitivewordWord3* new_pbmsg(){ return new ::proto_ff::E_SensitivewordWord3(); }
		static ::proto_ff::E_SensitivewordWord3 make_pbmsg(){ return ::proto_ff::E_SensitivewordWord3(); }
	};
	typedef struct E_SensitivewordWord3_s E_SensitivewordWord3_t;

	struct Sheet_SensitivewordWord3_s : public NFDescStoreSeqOP {
		Sheet_SensitivewordWord3_s();
		virtual ~Sheet_SensitivewordWord3_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SensitivewordWord3_s, DEFINE_SHEET_SENSITIVEWORDWORD3_E_SENSITIVEWORDWORD3_LIST_MAX_NUM> E_SensitivewordWord3_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SensitivewordWord3 & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SensitivewordWord3 & msg);
		static ::proto_ff::Sheet_SensitivewordWord3* new_pbmsg(){ return new ::proto_ff::Sheet_SensitivewordWord3(); }
		static ::proto_ff::Sheet_SensitivewordWord3 make_pbmsg(){ return ::proto_ff::Sheet_SensitivewordWord3(); }
	};
	typedef struct Sheet_SensitivewordWord3_s Sheet_SensitivewordWord3_t;

}

