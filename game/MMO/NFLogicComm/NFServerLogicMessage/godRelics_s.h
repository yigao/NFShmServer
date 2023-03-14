#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "godRelics.pb.h"
#include "godRelics_s.h"

#define DEFINE_SHEET_GODRELICSGODRELICS_E_GODRELICSGODRELICS_LIST_MAX_NUM 20
#define DEFINE_SHEET_GODRELICSCONDITION_E_GODRELICSCONDITION_LIST_MAX_NUM 20
namespace proto_ff_s {

	struct E_GodrelicsGodrelics_s : public NFDescStoreSeqOP {
		E_GodrelicsGodrelics_s();
		virtual ~E_GodrelicsGodrelics_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_functionid;
		int32_t m_group;
		int32_t m_skillid;

		virtual void write_to_pbmsg(::proto_ff::E_GodrelicsGodrelics & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodrelicsGodrelics & msg);
		static ::proto_ff::E_GodrelicsGodrelics* new_pbmsg(){ return new ::proto_ff::E_GodrelicsGodrelics(); }
		static ::proto_ff::E_GodrelicsGodrelics make_pbmsg(){ return ::proto_ff::E_GodrelicsGodrelics(); }
	};
	typedef struct E_GodrelicsGodrelics_s E_GodrelicsGodrelics_t;

	struct Sheet_GodrelicsGodrelics_s : public NFDescStoreSeqOP {
		Sheet_GodrelicsGodrelics_s();
		virtual ~Sheet_GodrelicsGodrelics_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodrelicsGodrelics_s, DEFINE_SHEET_GODRELICSGODRELICS_E_GODRELICSGODRELICS_LIST_MAX_NUM> E_GodrelicsGodrelics_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodrelicsGodrelics & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodrelicsGodrelics & msg);
		static ::proto_ff::Sheet_GodrelicsGodrelics* new_pbmsg(){ return new ::proto_ff::Sheet_GodrelicsGodrelics(); }
		static ::proto_ff::Sheet_GodrelicsGodrelics make_pbmsg(){ return ::proto_ff::Sheet_GodrelicsGodrelics(); }
	};
	typedef struct Sheet_GodrelicsGodrelics_s Sheet_GodrelicsGodrelics_t;

	struct E_GodrelicsCondition_s : public NFDescStoreSeqOP {
		E_GodrelicsCondition_s();
		virtual ~E_GodrelicsCondition_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_group;
		int32_t m_conditon;
		NFShmString<60> m_parama;
		int32_t m_count;
		int32_t m_rewarditem;
		int32_t m_rewardnumber;

		virtual void write_to_pbmsg(::proto_ff::E_GodrelicsCondition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodrelicsCondition & msg);
		static ::proto_ff::E_GodrelicsCondition* new_pbmsg(){ return new ::proto_ff::E_GodrelicsCondition(); }
		static ::proto_ff::E_GodrelicsCondition make_pbmsg(){ return ::proto_ff::E_GodrelicsCondition(); }
	};
	typedef struct E_GodrelicsCondition_s E_GodrelicsCondition_t;

	struct Sheet_GodrelicsCondition_s : public NFDescStoreSeqOP {
		Sheet_GodrelicsCondition_s();
		virtual ~Sheet_GodrelicsCondition_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodrelicsCondition_s, DEFINE_SHEET_GODRELICSCONDITION_E_GODRELICSCONDITION_LIST_MAX_NUM> E_GodrelicsCondition_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodrelicsCondition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodrelicsCondition & msg);
		static ::proto_ff::Sheet_GodrelicsCondition* new_pbmsg(){ return new ::proto_ff::Sheet_GodrelicsCondition(); }
		static ::proto_ff::Sheet_GodrelicsCondition make_pbmsg(){ return ::proto_ff::Sheet_GodrelicsCondition(); }
	};
	typedef struct Sheet_GodrelicsCondition_s Sheet_GodrelicsCondition_t;

}

