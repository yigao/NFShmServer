#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Wordshout.pb.h"
#include "E_Wordshout_s.h"

#define DEFINE_SHEET_WORDSHOUTSHOUT_E_WORDSHOUTSHOUT_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_WordshoutShout_s : public NFDescStoreSeqOP {
		E_WordshoutShout_s();
		virtual ~E_WordshoutShout_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_ID;//id
		int32_t m_Channel;//频道字段

		virtual void write_to_pbmsg(::proto_ff::E_WordshoutShout & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WordshoutShout & msg);
		static ::proto_ff::E_WordshoutShout* new_pbmsg(){ return new ::proto_ff::E_WordshoutShout(); }
		static ::proto_ff::E_WordshoutShout make_pbmsg(){ return ::proto_ff::E_WordshoutShout(); }
	};
	typedef struct E_WordshoutShout_s E_WordshoutShout_t;

	struct Sheet_WordshoutShout_s : public NFDescStoreSeqOP {
		Sheet_WordshoutShout_s();
		virtual ~Sheet_WordshoutShout_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WordshoutShout_s, DEFINE_SHEET_WORDSHOUTSHOUT_E_WORDSHOUTSHOUT_LIST_MAX_NUM> E_WordshoutShout_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WordshoutShout & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WordshoutShout & msg);
		static ::proto_ff::Sheet_WordshoutShout* new_pbmsg(){ return new ::proto_ff::Sheet_WordshoutShout(); }
		static ::proto_ff::Sheet_WordshoutShout make_pbmsg(){ return ::proto_ff::Sheet_WordshoutShout(); }
	};
	typedef struct Sheet_WordshoutShout_s Sheet_WordshoutShout_t;

}

