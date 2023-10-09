#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "intimacy.pb.h"
#include "intimacy_s.h"

#define DEFINE_E_INTIMACYINTIMACY_M_ATTRIBUTE_MAX_NUM 3
#define DEFINE_SHEET_INTIMACYINTIMACY_E_INTIMACYINTIMACY_LIST_MAX_NUM 20
#define DEFINE_SHEET_INTIMACYGIFT_E_INTIMACYGIFT_LIST_MAX_NUM 20
namespace proto_ff_s {

	struct E_IntimacyIntimacyAttributeDesc_s : public NFDescStoreSeqOP {
		E_IntimacyIntimacyAttributeDesc_s();
		virtual ~E_IntimacyIntimacyAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_IntimacyIntimacyAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_IntimacyIntimacyAttributeDesc & msg);
		static ::proto_ff::E_IntimacyIntimacyAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_IntimacyIntimacyAttributeDesc(); }
		static ::proto_ff::E_IntimacyIntimacyAttributeDesc make_pbmsg(){ return ::proto_ff::E_IntimacyIntimacyAttributeDesc(); }
	};
	typedef struct E_IntimacyIntimacyAttributeDesc_s E_IntimacyIntimacyAttributeDesc_t;

	struct E_IntimacyIntimacy_s : public NFDescStoreSeqOP {
		E_IntimacyIntimacy_s();
		virtual ~E_IntimacyIntimacy_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;
		int32_t m_intimacymin;
		int32_t m_intimacymax;
		NFShmVector<struct E_IntimacyIntimacyAttributeDesc_s, DEFINE_E_INTIMACYINTIMACY_M_ATTRIBUTE_MAX_NUM> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_IntimacyIntimacy & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_IntimacyIntimacy & msg);
		static ::proto_ff::E_IntimacyIntimacy* new_pbmsg(){ return new ::proto_ff::E_IntimacyIntimacy(); }
		static ::proto_ff::E_IntimacyIntimacy make_pbmsg(){ return ::proto_ff::E_IntimacyIntimacy(); }
	};
	typedef struct E_IntimacyIntimacy_s E_IntimacyIntimacy_t;

	struct Sheet_IntimacyIntimacy_s : public NFDescStoreSeqOP {
		Sheet_IntimacyIntimacy_s();
		virtual ~Sheet_IntimacyIntimacy_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_IntimacyIntimacy_s, DEFINE_SHEET_INTIMACYINTIMACY_E_INTIMACYINTIMACY_LIST_MAX_NUM> E_IntimacyIntimacy_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_IntimacyIntimacy & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_IntimacyIntimacy & msg);
		static ::proto_ff::Sheet_IntimacyIntimacy* new_pbmsg(){ return new ::proto_ff::Sheet_IntimacyIntimacy(); }
		static ::proto_ff::Sheet_IntimacyIntimacy make_pbmsg(){ return ::proto_ff::Sheet_IntimacyIntimacy(); }
	};
	typedef struct Sheet_IntimacyIntimacy_s Sheet_IntimacyIntimacy_t;

	struct E_IntimacyGift_s : public NFDescStoreSeqOP {
		E_IntimacyGift_s();
		virtual ~E_IntimacyGift_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_moneytype;
		int32_t m_price;
		int32_t m_intimacy;

		virtual void write_to_pbmsg(::proto_ff::E_IntimacyGift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_IntimacyGift & msg);
		static ::proto_ff::E_IntimacyGift* new_pbmsg(){ return new ::proto_ff::E_IntimacyGift(); }
		static ::proto_ff::E_IntimacyGift make_pbmsg(){ return ::proto_ff::E_IntimacyGift(); }
	};
	typedef struct E_IntimacyGift_s E_IntimacyGift_t;

	struct Sheet_IntimacyGift_s : public NFDescStoreSeqOP {
		Sheet_IntimacyGift_s();
		virtual ~Sheet_IntimacyGift_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_IntimacyGift_s, DEFINE_SHEET_INTIMACYGIFT_E_INTIMACYGIFT_LIST_MAX_NUM> E_IntimacyGift_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_IntimacyGift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_IntimacyGift & msg);
		static ::proto_ff::Sheet_IntimacyGift* new_pbmsg(){ return new ::proto_ff::Sheet_IntimacyGift(); }
		static ::proto_ff::Sheet_IntimacyGift make_pbmsg(){ return ::proto_ff::Sheet_IntimacyGift(); }
	};
	typedef struct Sheet_IntimacyGift_s Sheet_IntimacyGift_t;

}

