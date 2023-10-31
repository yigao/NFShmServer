#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Pk1v1.pb.h"
#include "E_Pk1v1_s.h"

#define DEFINE_SHEET_PK1V1RANK_E_PK1V1RANK_LIST_MAX_NUM 64
#define DEFINE_E_PK1V1REWARD_M_TYPEARG_MAX_NUM 3
#define DEFINE_SHEET_PK1V1REWARD_E_PK1V1REWARD_LIST_MAX_NUM 32
#define DEFINE_SHEET_PK1V1DAILYREWARD_E_PK1V1DAILYREWARD_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_Pk1v1Rank_s : public NFDescStoreSeqOP {
		E_Pk1v1Rank_s();
		virtual ~E_Pk1v1Rank_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_mark;//段位标识
		int32_t m_scoreMin;//分数下限
		int32_t m_scoreMax;//分数上限
		int32_t m_sucessScore;//胜利加分
		int32_t m_defeatScore;//失败扣分
		int32_t m_sucessBox;//单场获胜奖励
		int32_t m_defeatBox;//单场失败奖励
		int32_t m_tieBox;//单场平局奖励

		virtual void write_to_pbmsg(::proto_ff::E_Pk1v1Rank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_Pk1v1Rank & msg);
		static ::proto_ff::E_Pk1v1Rank* new_pbmsg(){ return new ::proto_ff::E_Pk1v1Rank(); }
		static ::proto_ff::E_Pk1v1Rank make_pbmsg(){ return ::proto_ff::E_Pk1v1Rank(); }
	};
	typedef struct E_Pk1v1Rank_s E_Pk1v1Rank_t;

	struct Sheet_Pk1v1Rank_s : public NFDescStoreSeqOP {
		Sheet_Pk1v1Rank_s();
		virtual ~Sheet_Pk1v1Rank_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_Pk1v1Rank_s, DEFINE_SHEET_PK1V1RANK_E_PK1V1RANK_LIST_MAX_NUM> E_Pk1v1Rank_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_Pk1v1Rank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_Pk1v1Rank & msg);
		static ::proto_ff::Sheet_Pk1v1Rank* new_pbmsg(){ return new ::proto_ff::Sheet_Pk1v1Rank(); }
		static ::proto_ff::Sheet_Pk1v1Rank make_pbmsg(){ return ::proto_ff::Sheet_Pk1v1Rank(); }
	};
	typedef struct Sheet_Pk1v1Rank_s Sheet_Pk1v1Rank_t;

	struct E_Pk1v1Reward_s : public NFDescStoreSeqOP {
		E_Pk1v1Reward_s();
		virtual ~E_Pk1v1Reward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//类型
		int32_t m_boxid;//奖励内容
		NFShmVector<int32_t, DEFINE_E_PK1V1REWARD_M_TYPEARG_MAX_NUM> m_typeArg;//类型参数

		virtual void write_to_pbmsg(::proto_ff::E_Pk1v1Reward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_Pk1v1Reward & msg);
		static ::proto_ff::E_Pk1v1Reward* new_pbmsg(){ return new ::proto_ff::E_Pk1v1Reward(); }
		static ::proto_ff::E_Pk1v1Reward make_pbmsg(){ return ::proto_ff::E_Pk1v1Reward(); }
	};
	typedef struct E_Pk1v1Reward_s E_Pk1v1Reward_t;

	struct Sheet_Pk1v1Reward_s : public NFDescStoreSeqOP {
		Sheet_Pk1v1Reward_s();
		virtual ~Sheet_Pk1v1Reward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_Pk1v1Reward_s, DEFINE_SHEET_PK1V1REWARD_E_PK1V1REWARD_LIST_MAX_NUM> E_Pk1v1Reward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_Pk1v1Reward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_Pk1v1Reward & msg);
		static ::proto_ff::Sheet_Pk1v1Reward* new_pbmsg(){ return new ::proto_ff::Sheet_Pk1v1Reward(); }
		static ::proto_ff::Sheet_Pk1v1Reward make_pbmsg(){ return ::proto_ff::Sheet_Pk1v1Reward(); }
	};
	typedef struct Sheet_Pk1v1Reward_s Sheet_Pk1v1Reward_t;

	struct E_Pk1v1Dailyreward_s : public NFDescStoreSeqOP {
		E_Pk1v1Dailyreward_s();
		virtual ~E_Pk1v1Dailyreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<64> m_name;//奖励名称
		int32_t m_times;//参与次数
		int32_t m_boxid;//奖励内容

		virtual void write_to_pbmsg(::proto_ff::E_Pk1v1Dailyreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_Pk1v1Dailyreward & msg);
		static ::proto_ff::E_Pk1v1Dailyreward* new_pbmsg(){ return new ::proto_ff::E_Pk1v1Dailyreward(); }
		static ::proto_ff::E_Pk1v1Dailyreward make_pbmsg(){ return ::proto_ff::E_Pk1v1Dailyreward(); }
	};
	typedef struct E_Pk1v1Dailyreward_s E_Pk1v1Dailyreward_t;

	struct Sheet_Pk1v1Dailyreward_s : public NFDescStoreSeqOP {
		Sheet_Pk1v1Dailyreward_s();
		virtual ~Sheet_Pk1v1Dailyreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_Pk1v1Dailyreward_s, DEFINE_SHEET_PK1V1DAILYREWARD_E_PK1V1DAILYREWARD_LIST_MAX_NUM> E_Pk1v1Dailyreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_Pk1v1Dailyreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_Pk1v1Dailyreward & msg);
		static ::proto_ff::Sheet_Pk1v1Dailyreward* new_pbmsg(){ return new ::proto_ff::Sheet_Pk1v1Dailyreward(); }
		static ::proto_ff::Sheet_Pk1v1Dailyreward make_pbmsg(){ return ::proto_ff::Sheet_Pk1v1Dailyreward(); }
	};
	typedef struct Sheet_Pk1v1Dailyreward_s Sheet_Pk1v1Dailyreward_t;

}

