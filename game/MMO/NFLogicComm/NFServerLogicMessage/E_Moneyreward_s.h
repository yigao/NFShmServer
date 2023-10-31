#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Moneyreward.pb.h"
#include "E_Moneyreward_s.h"

#define DEFINE_SHEET_MONEYREWARDMONEYREWARD_E_MONEYREWARDMONEYREWARD_LIST_MAX_NUM 4


namespace proto_ff_s {

	struct E_MoneyrewardMoneyreward_s : public NFDescStoreSeqOP {
		E_MoneyrewardMoneyreward_s();
		virtual ~E_MoneyrewardMoneyreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_taskreward;//任务奖励类型
		NFShmString<64> m_boxTaskreward;//宝箱奖励
		NFShmString<64> m_boxNum;//宝箱奖励次数条件
		int32_t m_task;//抽取的任务类型
		int32_t m_taskMax;//任务上限（抽取次数）
		NFShmString<64> m_onePrice;//一键完成单次货币价格
		NFShmString<64> m_freeUnlockLv;//免费一键开放等级和VIP
		int32_t m_vipLV;//双倍需求vip等级
		int32_t m_timeGet;//接取任务倒计时时间
		int32_t m_timeGetMoney;//领取倒计时时间
		int32_t m_timeGo;//前往倒计时时间

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
		NFShmVector<struct E_MoneyrewardMoneyreward_s, DEFINE_SHEET_MONEYREWARDMONEYREWARD_E_MONEYREWARDMONEYREWARD_LIST_MAX_NUM> E_MoneyrewardMoneyreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MoneyrewardMoneyreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MoneyrewardMoneyreward & msg);
		static ::proto_ff::Sheet_MoneyrewardMoneyreward* new_pbmsg(){ return new ::proto_ff::Sheet_MoneyrewardMoneyreward(); }
		static ::proto_ff::Sheet_MoneyrewardMoneyreward make_pbmsg(){ return ::proto_ff::Sheet_MoneyrewardMoneyreward(); }
	};
	typedef struct Sheet_MoneyrewardMoneyreward_s Sheet_MoneyrewardMoneyreward_t;

}

