#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Yanglong.pb.h"
#include "E_Yanglong_s.h"

#define DEFINE_SHEET_YANGLONGYANGLONG_E_YANGLONGYANGLONG_LIST_MAX_NUM 16
#define DEFINE_SHEET_YANGLONGZADAN_E_YANGLONGZADAN_LIST_MAX_NUM 16
#define DEFINE_SHEET_YANGLONGRANKING_E_YANGLONGRANKING_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_YanglongYanglong_s : public NFDescStoreSeqOP {
		E_YanglongYanglong_s();
		virtual ~E_YanglongYanglong_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_projectID;//项目ID
		int32_t m_groupID;//副本组ID
		int32_t m_dupId;//副本ID

		virtual void write_to_pbmsg(::proto_ff::E_YanglongYanglong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_YanglongYanglong & msg);
		static ::proto_ff::E_YanglongYanglong* new_pbmsg(){ return new ::proto_ff::E_YanglongYanglong(); }
		static ::proto_ff::E_YanglongYanglong make_pbmsg(){ return ::proto_ff::E_YanglongYanglong(); }
	};
	typedef struct E_YanglongYanglong_s E_YanglongYanglong_t;

	struct Sheet_YanglongYanglong_s : public NFDescStoreSeqOP {
		Sheet_YanglongYanglong_s();
		virtual ~Sheet_YanglongYanglong_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_YanglongYanglong_s, DEFINE_SHEET_YANGLONGYANGLONG_E_YANGLONGYANGLONG_LIST_MAX_NUM> E_YanglongYanglong_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_YanglongYanglong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_YanglongYanglong & msg);
		static ::proto_ff::Sheet_YanglongYanglong* new_pbmsg(){ return new ::proto_ff::Sheet_YanglongYanglong(); }
		static ::proto_ff::Sheet_YanglongYanglong make_pbmsg(){ return ::proto_ff::Sheet_YanglongYanglong(); }
	};
	typedef struct Sheet_YanglongYanglong_s Sheet_YanglongYanglong_t;

	struct E_YanglongZadan_s : public NFDescStoreSeqOP {
		E_YanglongZadan_s();
		virtual ~E_YanglongZadan_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_taskId;//任务ID
		int32_t m_achievementSubType;//事件类型
		int32_t m_bossType;//BOSS分类
		int32_t m_reachPrice;//达成值
		int32_t m_reward;//奖励物品
		int32_t m_reward_Value;//奖励物品数量
		int32_t m_linkId;//跳转ID

		virtual void write_to_pbmsg(::proto_ff::E_YanglongZadan & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_YanglongZadan & msg);
		static ::proto_ff::E_YanglongZadan* new_pbmsg(){ return new ::proto_ff::E_YanglongZadan(); }
		static ::proto_ff::E_YanglongZadan make_pbmsg(){ return ::proto_ff::E_YanglongZadan(); }
	};
	typedef struct E_YanglongZadan_s E_YanglongZadan_t;

	struct Sheet_YanglongZadan_s : public NFDescStoreSeqOP {
		Sheet_YanglongZadan_s();
		virtual ~Sheet_YanglongZadan_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_YanglongZadan_s, DEFINE_SHEET_YANGLONGZADAN_E_YANGLONGZADAN_LIST_MAX_NUM> E_YanglongZadan_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_YanglongZadan & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_YanglongZadan & msg);
		static ::proto_ff::Sheet_YanglongZadan* new_pbmsg(){ return new ::proto_ff::Sheet_YanglongZadan(); }
		static ::proto_ff::Sheet_YanglongZadan make_pbmsg(){ return ::proto_ff::Sheet_YanglongZadan(); }
	};
	typedef struct Sheet_YanglongZadan_s Sheet_YanglongZadan_t;

	struct E_YanglongRanking_s : public NFDescStoreSeqOP {
		E_YanglongRanking_s();
		virtual ~E_YanglongRanking_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_rankingID;//排名礼包ID
		int32_t m_rank;//排名条件
		int32_t m_boxID;//boxl礼包ID

		virtual void write_to_pbmsg(::proto_ff::E_YanglongRanking & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_YanglongRanking & msg);
		static ::proto_ff::E_YanglongRanking* new_pbmsg(){ return new ::proto_ff::E_YanglongRanking(); }
		static ::proto_ff::E_YanglongRanking make_pbmsg(){ return ::proto_ff::E_YanglongRanking(); }
	};
	typedef struct E_YanglongRanking_s E_YanglongRanking_t;

	struct Sheet_YanglongRanking_s : public NFDescStoreSeqOP {
		Sheet_YanglongRanking_s();
		virtual ~Sheet_YanglongRanking_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_YanglongRanking_s, DEFINE_SHEET_YANGLONGRANKING_E_YANGLONGRANKING_LIST_MAX_NUM> E_YanglongRanking_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_YanglongRanking & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_YanglongRanking & msg);
		static ::proto_ff::Sheet_YanglongRanking* new_pbmsg(){ return new ::proto_ff::Sheet_YanglongRanking(); }
		static ::proto_ff::Sheet_YanglongRanking make_pbmsg(){ return ::proto_ff::Sheet_YanglongRanking(); }
	};
	typedef struct Sheet_YanglongRanking_s Sheet_YanglongRanking_t;

}

