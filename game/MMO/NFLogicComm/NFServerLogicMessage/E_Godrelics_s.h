#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Godrelics.pb.h"
#include "E_Godrelics_s.h"

#define DEFINE_SHEET_GODRELICSGODRELICS_E_GODRELICSGODRELICS_LIST_MAX_NUM 16
#define DEFINE_E_GODRELICSCONDITION_M_PARAM_MAX_NUM 3
#define DEFINE_SHEET_GODRELICSCONDITION_E_GODRELICSCONDITION_LIST_MAX_NUM 128


namespace proto_ff_s {

	struct E_GodrelicsGodrelics_s : public NFDescStoreSeqOP {
		E_GodrelicsGodrelics_s();
		virtual ~E_GodrelicsGodrelics_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_functionid;//功能开放id
		int32_t m_group;//条件组ID
		int32_t m_skillid;//激活技能

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
		NFShmVector<struct E_GodrelicsGodrelics_s, DEFINE_SHEET_GODRELICSGODRELICS_E_GODRELICSGODRELICS_LIST_MAX_NUM> E_GodrelicsGodrelics_List;//

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
		int32_t m_id;//id
		int32_t m_group;//条件组id
		int32_t m_conditon;//条件类型
		int32_t m_count;//完成次数
		int32_t m_rewarditem;//奖励道具
		int32_t m_rewardnumber;//奖励道具数量
		NFShmVector<int32_t, DEFINE_E_GODRELICSCONDITION_M_PARAM_MAX_NUM> m_param;//事件完成参数

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
		NFShmVector<struct E_GodrelicsCondition_s, DEFINE_SHEET_GODRELICSCONDITION_E_GODRELICSCONDITION_LIST_MAX_NUM> E_GodrelicsCondition_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodrelicsCondition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodrelicsCondition & msg);
		static ::proto_ff::Sheet_GodrelicsCondition* new_pbmsg(){ return new ::proto_ff::Sheet_GodrelicsCondition(); }
		static ::proto_ff::Sheet_GodrelicsCondition make_pbmsg(){ return ::proto_ff::Sheet_GodrelicsCondition(); }
	};
	typedef struct Sheet_GodrelicsCondition_s Sheet_GodrelicsCondition_t;

}

