#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Ranking.pb.h"
#include "E_Ranking_s.h"

#define DEFINE_E_RANKINGRANKING_M_DATEID_MAX_NUM 5
#define DEFINE_SHEET_RANKINGRANKING_E_RANKINGRANKING_LIST_MAX_NUM 32
#define DEFINE_SHEET_RANKINGDATE_E_RANKINGDATE_LIST_MAX_NUM 32
#define DEFINE_SHEET_RANKINGBUTTON_E_RANKINGBUTTON_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_RankingRanking_s : public NFDescStoreSeqOP {
		E_RankingRanking_s();
		virtual ~E_RankingRanking_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_rankingID;//排行榜ID
		NFShmString<64> m_rankingName;//排行名称
		NFShmString<64> m_title;//榜一称号
		int32_t m_capacity;//实际排多少元素
		int32_t m_showSize;//显示多少个元素
		int32_t m_rankHide;//是否在排行榜隐藏
		NFShmVector<int32_t, DEFINE_E_RANKINGRANKING_M_DATEID_MAX_NUM> m_dateID;//排行数据

		virtual void write_to_pbmsg(::proto_ff::E_RankingRanking & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RankingRanking & msg);
		static ::proto_ff::E_RankingRanking* new_pbmsg(){ return new ::proto_ff::E_RankingRanking(); }
		static ::proto_ff::E_RankingRanking make_pbmsg(){ return ::proto_ff::E_RankingRanking(); }
	};
	typedef struct E_RankingRanking_s E_RankingRanking_t;

	struct Sheet_RankingRanking_s : public NFDescStoreSeqOP {
		Sheet_RankingRanking_s();
		virtual ~Sheet_RankingRanking_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RankingRanking_s, DEFINE_SHEET_RANKINGRANKING_E_RANKINGRANKING_LIST_MAX_NUM> E_RankingRanking_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RankingRanking & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RankingRanking & msg);
		static ::proto_ff::Sheet_RankingRanking* new_pbmsg(){ return new ::proto_ff::Sheet_RankingRanking(); }
		static ::proto_ff::Sheet_RankingRanking make_pbmsg(){ return ::proto_ff::Sheet_RankingRanking(); }
	};
	typedef struct Sheet_RankingRanking_s Sheet_RankingRanking_t;

	struct E_RankingDate_s : public NFDescStoreSeqOP {
		E_RankingDate_s();
		virtual ~E_RankingDate_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_dateID;//数据ID
		NFShmString<64> m_dateName;//数据名称

		virtual void write_to_pbmsg(::proto_ff::E_RankingDate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RankingDate & msg);
		static ::proto_ff::E_RankingDate* new_pbmsg(){ return new ::proto_ff::E_RankingDate(); }
		static ::proto_ff::E_RankingDate make_pbmsg(){ return ::proto_ff::E_RankingDate(); }
	};
	typedef struct E_RankingDate_s E_RankingDate_t;

	struct Sheet_RankingDate_s : public NFDescStoreSeqOP {
		Sheet_RankingDate_s();
		virtual ~Sheet_RankingDate_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RankingDate_s, DEFINE_SHEET_RANKINGDATE_E_RANKINGDATE_LIST_MAX_NUM> E_RankingDate_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RankingDate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RankingDate & msg);
		static ::proto_ff::Sheet_RankingDate* new_pbmsg(){ return new ::proto_ff::Sheet_RankingDate(); }
		static ::proto_ff::Sheet_RankingDate make_pbmsg(){ return ::proto_ff::Sheet_RankingDate(); }
	};
	typedef struct Sheet_RankingDate_s Sheet_RankingDate_t;

	struct E_RankingButton_s : public NFDescStoreSeqOP {
		E_RankingButton_s();
		virtual ~E_RankingButton_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_buttonID;//数据ID
		NFShmString<64> m_buttonName;//数据名称
		int32_t m_display;//是否显示

		virtual void write_to_pbmsg(::proto_ff::E_RankingButton & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RankingButton & msg);
		static ::proto_ff::E_RankingButton* new_pbmsg(){ return new ::proto_ff::E_RankingButton(); }
		static ::proto_ff::E_RankingButton make_pbmsg(){ return ::proto_ff::E_RankingButton(); }
	};
	typedef struct E_RankingButton_s E_RankingButton_t;

	struct Sheet_RankingButton_s : public NFDescStoreSeqOP {
		Sheet_RankingButton_s();
		virtual ~Sheet_RankingButton_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RankingButton_s, DEFINE_SHEET_RANKINGBUTTON_E_RANKINGBUTTON_LIST_MAX_NUM> E_RankingButton_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RankingButton & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RankingButton & msg);
		static ::proto_ff::Sheet_RankingButton* new_pbmsg(){ return new ::proto_ff::Sheet_RankingButton(); }
		static ::proto_ff::Sheet_RankingButton make_pbmsg(){ return ::proto_ff::Sheet_RankingButton(); }
	};
	typedef struct Sheet_RankingButton_s Sheet_RankingButton_t;

}

