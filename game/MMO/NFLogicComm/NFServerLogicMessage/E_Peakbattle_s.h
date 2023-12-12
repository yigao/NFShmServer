#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Peakbattle.pb.h"
#include "E_Peakbattle_s.h"

#define DEFINE_SHEET_PEAKBATTLECONSTANT_E_PEAKBATTLECONSTANT_LIST_MAX_NUM 2
#define DEFINE_E_PEAKBATTLEAWARD_M_AWARD_MAX_NUM 6
#define DEFINE_SHEET_PEAKBATTLEAWARD_E_PEAKBATTLEAWARD_LIST_MAX_NUM 32
#define DEFINE_SHEET_PEAKBATTLEGUESS_E_PEAKBATTLEGUESS_LIST_MAX_NUM 4


namespace proto_ff_s {

	struct E_PeakbattleConstant_s : public NFDescStoreSeqOP {
		E_PeakbattleConstant_s();
		virtual ~E_PeakbattleConstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//唯一ID

		virtual void write_to_pbmsg(::proto_ff::E_PeakbattleConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PeakbattleConstant & msg);
		static ::proto_ff::E_PeakbattleConstant* new_pbmsg(){ return new ::proto_ff::E_PeakbattleConstant(); }
		static ::proto_ff::E_PeakbattleConstant make_pbmsg(){ return ::proto_ff::E_PeakbattleConstant(); }
	};
	typedef struct E_PeakbattleConstant_s E_PeakbattleConstant_t;

	struct Sheet_PeakbattleConstant_s : public NFDescStoreSeqOP {
		Sheet_PeakbattleConstant_s();
		virtual ~Sheet_PeakbattleConstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PeakbattleConstant_s, DEFINE_SHEET_PEAKBATTLECONSTANT_E_PEAKBATTLECONSTANT_LIST_MAX_NUM> E_PeakbattleConstant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PeakbattleConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PeakbattleConstant & msg);
		static ::proto_ff::Sheet_PeakbattleConstant* new_pbmsg(){ return new ::proto_ff::Sheet_PeakbattleConstant(); }
		static ::proto_ff::Sheet_PeakbattleConstant make_pbmsg(){ return ::proto_ff::Sheet_PeakbattleConstant(); }
	};
	typedef struct Sheet_PeakbattleConstant_s Sheet_PeakbattleConstant_t;

	struct E_PeakbattleAwardAwardDesc_s : public NFDescStoreSeqOP {
		E_PeakbattleAwardAwardDesc_s();
		virtual ~E_PeakbattleAwardAwardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_time;//道具

		virtual void write_to_pbmsg(::proto_ff::E_PeakbattleAwardAwardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PeakbattleAwardAwardDesc & msg);
		static ::proto_ff::E_PeakbattleAwardAwardDesc* new_pbmsg(){ return new ::proto_ff::E_PeakbattleAwardAwardDesc(); }
		static ::proto_ff::E_PeakbattleAwardAwardDesc make_pbmsg(){ return ::proto_ff::E_PeakbattleAwardAwardDesc(); }
	};
	typedef struct E_PeakbattleAwardAwardDesc_s E_PeakbattleAwardAwardDesc_t;

	struct E_PeakbattleAward_s : public NFDescStoreSeqOP {
		E_PeakbattleAward_s();
		virtual ~E_PeakbattleAward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_awardId;//奖励id
		int32_t m_type;//奖励类型
		int32_t m_condition;//奖励条件
		NFShmVector<struct E_PeakbattleAwardAwardDesc_s, DEFINE_E_PEAKBATTLEAWARD_M_AWARD_MAX_NUM> m_award;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_PeakbattleAward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PeakbattleAward & msg);
		static ::proto_ff::E_PeakbattleAward* new_pbmsg(){ return new ::proto_ff::E_PeakbattleAward(); }
		static ::proto_ff::E_PeakbattleAward make_pbmsg(){ return ::proto_ff::E_PeakbattleAward(); }
	};
	typedef struct E_PeakbattleAward_s E_PeakbattleAward_t;

	struct Sheet_PeakbattleAward_s : public NFDescStoreSeqOP {
		Sheet_PeakbattleAward_s();
		virtual ~Sheet_PeakbattleAward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PeakbattleAward_s, DEFINE_SHEET_PEAKBATTLEAWARD_E_PEAKBATTLEAWARD_LIST_MAX_NUM> E_PeakbattleAward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PeakbattleAward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PeakbattleAward & msg);
		static ::proto_ff::Sheet_PeakbattleAward* new_pbmsg(){ return new ::proto_ff::Sheet_PeakbattleAward(); }
		static ::proto_ff::Sheet_PeakbattleAward make_pbmsg(){ return ::proto_ff::Sheet_PeakbattleAward(); }
	};
	typedef struct Sheet_PeakbattleAward_s Sheet_PeakbattleAward_t;

	struct E_PeakbattleGuess_s : public NFDescStoreSeqOP {
		E_PeakbattleGuess_s();
		virtual ~E_PeakbattleGuess_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//赛程
		int32_t m_clock;//竞猜倒计时
		int32_t m_item;//发放道具
		int32_t m_num;//数量
		int32_t m_max;//竞猜最大上限

		virtual void write_to_pbmsg(::proto_ff::E_PeakbattleGuess & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PeakbattleGuess & msg);
		static ::proto_ff::E_PeakbattleGuess* new_pbmsg(){ return new ::proto_ff::E_PeakbattleGuess(); }
		static ::proto_ff::E_PeakbattleGuess make_pbmsg(){ return ::proto_ff::E_PeakbattleGuess(); }
	};
	typedef struct E_PeakbattleGuess_s E_PeakbattleGuess_t;

	struct Sheet_PeakbattleGuess_s : public NFDescStoreSeqOP {
		Sheet_PeakbattleGuess_s();
		virtual ~Sheet_PeakbattleGuess_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PeakbattleGuess_s, DEFINE_SHEET_PEAKBATTLEGUESS_E_PEAKBATTLEGUESS_LIST_MAX_NUM> E_PeakbattleGuess_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PeakbattleGuess & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PeakbattleGuess & msg);
		static ::proto_ff::Sheet_PeakbattleGuess* new_pbmsg(){ return new ::proto_ff::Sheet_PeakbattleGuess(); }
		static ::proto_ff::Sheet_PeakbattleGuess make_pbmsg(){ return ::proto_ff::Sheet_PeakbattleGuess(); }
	};
	typedef struct Sheet_PeakbattleGuess_s Sheet_PeakbattleGuess_t;

}

