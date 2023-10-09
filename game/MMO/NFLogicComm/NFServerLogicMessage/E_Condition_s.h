#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Condition.pb.h"
#include "E_Condition_s.h"

#define DEFINE_E_CONDITIONCONDITION_M_CONDITION_MAX_NUM 3
#define DEFINE_SHEET_CONDITIONCONDITION_E_CONDITIONCONDITION_LIST_MAX_NUM 32


namespace proto_ff_s {

	struct E_ConditionConditionConditionDesc_s : public NFDescStoreSeqOP {
		E_ConditionConditionConditionDesc_s();
		virtual ~E_ConditionConditionConditionDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_param;//参数
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_ConditionConditionConditionDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConditionConditionConditionDesc & msg);
		static ::proto_ff::E_ConditionConditionConditionDesc* new_pbmsg(){ return new ::proto_ff::E_ConditionConditionConditionDesc(); }
		static ::proto_ff::E_ConditionConditionConditionDesc make_pbmsg(){ return ::proto_ff::E_ConditionConditionConditionDesc(); }
	};
	typedef struct E_ConditionConditionConditionDesc_s E_ConditionConditionConditionDesc_t;

	struct E_ConditionCondition_s : public NFDescStoreSeqOP {
		E_ConditionCondition_s();
		virtual ~E_ConditionCondition_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmVector<struct E_ConditionConditionConditionDesc_s, DEFINE_E_CONDITIONCONDITION_M_CONDITION_MAX_NUM> m_condition;//条件

		virtual void write_to_pbmsg(::proto_ff::E_ConditionCondition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConditionCondition & msg);
		static ::proto_ff::E_ConditionCondition* new_pbmsg(){ return new ::proto_ff::E_ConditionCondition(); }
		static ::proto_ff::E_ConditionCondition make_pbmsg(){ return ::proto_ff::E_ConditionCondition(); }
	};
	typedef struct E_ConditionCondition_s E_ConditionCondition_t;

	struct Sheet_ConditionCondition_s : public NFDescStoreSeqOP {
		Sheet_ConditionCondition_s();
		virtual ~Sheet_ConditionCondition_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ConditionCondition_s, DEFINE_SHEET_CONDITIONCONDITION_E_CONDITIONCONDITION_LIST_MAX_NUM> E_ConditionCondition_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ConditionCondition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ConditionCondition & msg);
		static ::proto_ff::Sheet_ConditionCondition* new_pbmsg(){ return new ::proto_ff::Sheet_ConditionCondition(); }
		static ::proto_ff::Sheet_ConditionCondition make_pbmsg(){ return ::proto_ff::Sheet_ConditionCondition(); }
	};
	typedef struct Sheet_ConditionCondition_s Sheet_ConditionCondition_t;

}

