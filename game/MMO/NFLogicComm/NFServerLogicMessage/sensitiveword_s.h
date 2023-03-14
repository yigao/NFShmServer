#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "sensitiveword.pb.h"
#include "sensitiveword_s.h"

#define DEFINE_SHEET_SENSITIVEWORDSENSITIVE_WORD_E_SENSITIVEWORDSENSITIVE_WORD_LIST_MAX_NUM 6000
#define DEFINE_SHEET_SENSITIVEWORDROLESENSITIVE_E_SENSITIVEWORDROLESENSITIVE_LIST_MAX_NUM 300
namespace proto_ff_s {

	struct E_SensitivewordSensitive_word_s : public NFDescStoreSeqOP {
		E_SensitivewordSensitive_word_s();
		virtual ~E_SensitivewordSensitive_word_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmString<60> m_sensitiveword;

		virtual void write_to_pbmsg(::proto_ff::E_SensitivewordSensitive_word & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SensitivewordSensitive_word & msg);
		static ::proto_ff::E_SensitivewordSensitive_word* new_pbmsg(){ return new ::proto_ff::E_SensitivewordSensitive_word(); }
		static ::proto_ff::E_SensitivewordSensitive_word make_pbmsg(){ return ::proto_ff::E_SensitivewordSensitive_word(); }
	};
	typedef struct E_SensitivewordSensitive_word_s E_SensitivewordSensitive_word_t;

	struct Sheet_SensitivewordSensitive_word_s : public NFDescStoreSeqOP {
		Sheet_SensitivewordSensitive_word_s();
		virtual ~Sheet_SensitivewordSensitive_word_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SensitivewordSensitive_word_s, DEFINE_SHEET_SENSITIVEWORDSENSITIVE_WORD_E_SENSITIVEWORDSENSITIVE_WORD_LIST_MAX_NUM> E_SensitivewordSensitive_word_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_SensitivewordSensitive_word & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SensitivewordSensitive_word & msg);
		static ::proto_ff::Sheet_SensitivewordSensitive_word* new_pbmsg(){ return new ::proto_ff::Sheet_SensitivewordSensitive_word(); }
		static ::proto_ff::Sheet_SensitivewordSensitive_word make_pbmsg(){ return ::proto_ff::Sheet_SensitivewordSensitive_word(); }
	};
	typedef struct Sheet_SensitivewordSensitive_word_s Sheet_SensitivewordSensitive_word_t;

	struct E_SensitivewordRolesensitive_s : public NFDescStoreSeqOP {
		E_SensitivewordRolesensitive_s();
		virtual ~E_SensitivewordRolesensitive_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmString<60> m_sensitiveword;

		virtual void write_to_pbmsg(::proto_ff::E_SensitivewordRolesensitive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SensitivewordRolesensitive & msg);
		static ::proto_ff::E_SensitivewordRolesensitive* new_pbmsg(){ return new ::proto_ff::E_SensitivewordRolesensitive(); }
		static ::proto_ff::E_SensitivewordRolesensitive make_pbmsg(){ return ::proto_ff::E_SensitivewordRolesensitive(); }
	};
	typedef struct E_SensitivewordRolesensitive_s E_SensitivewordRolesensitive_t;

	struct Sheet_SensitivewordRolesensitive_s : public NFDescStoreSeqOP {
		Sheet_SensitivewordRolesensitive_s();
		virtual ~Sheet_SensitivewordRolesensitive_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SensitivewordRolesensitive_s, DEFINE_SHEET_SENSITIVEWORDROLESENSITIVE_E_SENSITIVEWORDROLESENSITIVE_LIST_MAX_NUM> E_SensitivewordRolesensitive_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_SensitivewordRolesensitive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SensitivewordRolesensitive & msg);
		static ::proto_ff::Sheet_SensitivewordRolesensitive* new_pbmsg(){ return new ::proto_ff::Sheet_SensitivewordRolesensitive(); }
		static ::proto_ff::Sheet_SensitivewordRolesensitive make_pbmsg(){ return ::proto_ff::Sheet_SensitivewordRolesensitive(); }
	};
	typedef struct Sheet_SensitivewordRolesensitive_s Sheet_SensitivewordRolesensitive_t;

}

