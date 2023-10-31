#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Back.pb.h"
#include "E_Back_s.h"

#define DEFINE_E_BACKBACK_M_PARAM_MAX_NUM 2
#define DEFINE_SHEET_BACKBACK_E_BACKBACK_LIST_MAX_NUM 64


namespace proto_ff_s {

	struct E_BackBack_s : public NFDescStoreSeqOP {
		E_BackBack_s();
		virtual ~E_BackBack_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//唯一id
		int32_t m_type;//找回类型
		int32_t m_typeParam;//类型参数
		NFShmString<64> m_name;//显示名称
		int32_t m_group;//组
		int32_t m_functionUnlock;//关联功能开放
		int32_t m_levelLimit;//等级要求下限
		int64_t m_PboxId;//完美找回物品box
		int64_t m_boxId;//找回物品box
		int32_t m_backDay;//找回天数
		int32_t m_costItemID;//普通找回消耗物
		int32_t m_costNum;//普通找回消耗数量
		int32_t m_PcostItemID;//完美找回消耗物
		int32_t m_PcostNum;//完美找回消耗数量
		int32_t m_AcostItemID;//额外找回消耗物
		int32_t m_AcostNum;//额外找回小号数量
		NFShmVector<int32_t, DEFINE_E_BACKBACK_M_PARAM_MAX_NUM> m_param;//参数

		virtual void write_to_pbmsg(::proto_ff::E_BackBack & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BackBack & msg);
		static ::proto_ff::E_BackBack* new_pbmsg(){ return new ::proto_ff::E_BackBack(); }
		static ::proto_ff::E_BackBack make_pbmsg(){ return ::proto_ff::E_BackBack(); }
	};
	typedef struct E_BackBack_s E_BackBack_t;

	struct Sheet_BackBack_s : public NFDescStoreSeqOP {
		Sheet_BackBack_s();
		virtual ~Sheet_BackBack_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BackBack_s, DEFINE_SHEET_BACKBACK_E_BACKBACK_LIST_MAX_NUM> E_BackBack_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_BackBack & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BackBack & msg);
		static ::proto_ff::Sheet_BackBack* new_pbmsg(){ return new ::proto_ff::Sheet_BackBack(); }
		static ::proto_ff::Sheet_BackBack make_pbmsg(){ return ::proto_ff::Sheet_BackBack(); }
	};
	typedef struct Sheet_BackBack_s Sheet_BackBack_t;

}

