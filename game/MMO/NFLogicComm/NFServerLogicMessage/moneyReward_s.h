#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "moneyReward.pb.h"
#include "moneyReward_s.h"

#define DEFINE_SHEET_MONEYREWARDMONEYREWARD_E_MONEYREWARDMONEYREWARD_LIST_MAX_NUM 20
namespace proto_ff_s {

	struct E_MoneyrewardMoneyreward_s : public NFDescStoreSeqOP {
		E_MoneyrewardMoneyreward_s();
		virtual ~E_MoneyrewardMoneyreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_taskreward;
		NFShmString<60> m_boxtaskreward;
		NFShmString<60> m_boxnum;
		int32_t m_task;
		int32_t m_taskmax;
		NFShmString<60> m_oneprice;
		int32_t m_freeunlocklv;
		int32_t m_viplv;
		int32_t m_timeget;
		int32_t m_timegetmoney;
		int32_t m_timego;

		virtual void write_to_pbmsg(::proto_ff::E_MoneyrewardMoneyreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MoneyrewardMoneyreward & msg);
		static ::proto_ff::E_MoneyrewardMoneyreward* new_pbmsg(){ return new ::proto_ff::E_MoneyrewardMoneyreward(); }
		static ::proto_ff::E_MoneyrewardMoneyreward make_pbmsg(){ return ::proto_ff::E_MoneyrewardMoneyreward(); }
	};
	typedef struct E_MoneyrewardMoneyreward_s E_MoneyrewardMoneyreward_t;

	struct Sheet_MoneyrewardMoneyreward_s : public NFDescStoreSeqOP {
		Sheet_MoneyrewardMoneyreward_s();
		virtual ~Sheet_MoneyrewardMoneyreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MoneyrewardMoneyreward_s, DEFINE_SHEET_MONEYREWARDMONEYREWARD_E_MONEYREWARDMONEYREWARD_LIST_MAX_NUM> E_MoneyrewardMoneyreward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MoneyrewardMoneyreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MoneyrewardMoneyreward & msg);
		static ::proto_ff::Sheet_MoneyrewardMoneyreward* new_pbmsg(){ return new ::proto_ff::Sheet_MoneyrewardMoneyreward(); }
		static ::proto_ff::Sheet_MoneyrewardMoneyreward make_pbmsg(){ return ::proto_ff::Sheet_MoneyrewardMoneyreward(); }
	};
	typedef struct Sheet_MoneyrewardMoneyreward_s Sheet_MoneyrewardMoneyreward_t;

}

