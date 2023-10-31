#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Daily.pb.h"
#include "E_Daily_s.h"

#define DEFINE_SHEET_DAILYDAILY_E_DAILYDAILY_LIST_MAX_NUM 64
#define DEFINE_SHEET_DAILYREWARD_E_DAILYREWARD_LIST_MAX_NUM 16
#define DEFINE_E_DAILYCULTIVATE_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_DAILYCULTIVATE_E_DAILYCULTIVATE_LIST_MAX_NUM 1024
#define DEFINE_SHEET_DAILYSPORTS_E_DAILYSPORTS_LIST_MAX_NUM 16
#define DEFINE_SHEET_DAILYHELPER_E_DAILYHELPER_LIST_MAX_NUM 16


namespace proto_ff_s {

	struct E_DailyDaily_s : public NFDescStoreSeqOP {
		E_DailyDaily_s();
		virtual ~E_DailyDaily_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//类型ID
		NFShmString<64> m_name;//显示名称
		int32_t m_type;//活动类型
		int32_t m_args;//玩法参数
		int32_t m_playType;//玩法类型
		int32_t m_playArgs;//玩法参数
		int64_t m_funciontID;//功能ID
		int32_t m_number;//次数
		int32_t m_eachScore;//每次活跃值
		int32_t m_cycle;//重置周期
		int32_t m_regReward;//报名奖励道具boxid

		virtual void write_to_pbmsg(::proto_ff::E_DailyDaily & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DailyDaily & msg);
		static ::proto_ff::E_DailyDaily* new_pbmsg(){ return new ::proto_ff::E_DailyDaily(); }
		static ::proto_ff::E_DailyDaily make_pbmsg(){ return ::proto_ff::E_DailyDaily(); }
	};
	typedef struct E_DailyDaily_s E_DailyDaily_t;

	struct Sheet_DailyDaily_s : public NFDescStoreSeqOP {
		Sheet_DailyDaily_s();
		virtual ~Sheet_DailyDaily_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DailyDaily_s, DEFINE_SHEET_DAILYDAILY_E_DAILYDAILY_LIST_MAX_NUM> E_DailyDaily_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DailyDaily & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DailyDaily & msg);
		static ::proto_ff::Sheet_DailyDaily* new_pbmsg(){ return new ::proto_ff::Sheet_DailyDaily(); }
		static ::proto_ff::Sheet_DailyDaily make_pbmsg(){ return ::proto_ff::Sheet_DailyDaily(); }
	};
	typedef struct Sheet_DailyDaily_s Sheet_DailyDaily_t;

	struct E_DailyReward_s : public NFDescStoreSeqOP {
		E_DailyReward_s();
		virtual ~E_DailyReward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//索引
		int32_t m_type;//类型
		int32_t m_activeScore;//活跃度值
		int64_t m_rewardId;//奖励ID
		int32_t m_rewardNum;//奖励数量

		virtual void write_to_pbmsg(::proto_ff::E_DailyReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DailyReward & msg);
		static ::proto_ff::E_DailyReward* new_pbmsg(){ return new ::proto_ff::E_DailyReward(); }
		static ::proto_ff::E_DailyReward make_pbmsg(){ return ::proto_ff::E_DailyReward(); }
	};
	typedef struct E_DailyReward_s E_DailyReward_t;

	struct Sheet_DailyReward_s : public NFDescStoreSeqOP {
		Sheet_DailyReward_s();
		virtual ~Sheet_DailyReward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DailyReward_s, DEFINE_SHEET_DAILYREWARD_E_DAILYREWARD_LIST_MAX_NUM> E_DailyReward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DailyReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DailyReward & msg);
		static ::proto_ff::Sheet_DailyReward* new_pbmsg(){ return new ::proto_ff::Sheet_DailyReward(); }
		static ::proto_ff::Sheet_DailyReward make_pbmsg(){ return ::proto_ff::Sheet_DailyReward(); }
	};
	typedef struct Sheet_DailyReward_s Sheet_DailyReward_t;

	struct E_DailyCultivateAttributeDesc_s : public NFDescStoreSeqOP {
		E_DailyCultivateAttributeDesc_s();
		virtual ~E_DailyCultivateAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Value;//值
		int32_t m_ID;//id

		virtual void write_to_pbmsg(::proto_ff::E_DailyCultivateAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DailyCultivateAttributeDesc & msg);
		static ::proto_ff::E_DailyCultivateAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_DailyCultivateAttributeDesc(); }
		static ::proto_ff::E_DailyCultivateAttributeDesc make_pbmsg(){ return ::proto_ff::E_DailyCultivateAttributeDesc(); }
	};
	typedef struct E_DailyCultivateAttributeDesc_s E_DailyCultivateAttributeDesc_t;

	struct E_DailyCultivate_s : public NFDescStoreSeqOP {
		E_DailyCultivate_s();
		virtual ~E_DailyCultivate_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_ID;//id
		int32_t m_lv;//等级
		int32_t m_exp;//升级所需经验
		NFShmVector<struct E_DailyCultivateAttributeDesc_s, DEFINE_E_DAILYCULTIVATE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_DailyCultivate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DailyCultivate & msg);
		static ::proto_ff::E_DailyCultivate* new_pbmsg(){ return new ::proto_ff::E_DailyCultivate(); }
		static ::proto_ff::E_DailyCultivate make_pbmsg(){ return ::proto_ff::E_DailyCultivate(); }
	};
	typedef struct E_DailyCultivate_s E_DailyCultivate_t;

	struct Sheet_DailyCultivate_s : public NFDescStoreSeqOP {
		Sheet_DailyCultivate_s();
		virtual ~Sheet_DailyCultivate_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DailyCultivate_s, DEFINE_SHEET_DAILYCULTIVATE_E_DAILYCULTIVATE_LIST_MAX_NUM> E_DailyCultivate_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DailyCultivate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DailyCultivate & msg);
		static ::proto_ff::Sheet_DailyCultivate* new_pbmsg(){ return new ::proto_ff::Sheet_DailyCultivate(); }
		static ::proto_ff::Sheet_DailyCultivate make_pbmsg(){ return ::proto_ff::Sheet_DailyCultivate(); }
	};
	typedef struct Sheet_DailyCultivate_s Sheet_DailyCultivate_t;

	struct E_DailySports_s : public NFDescStoreSeqOP {
		E_DailySports_s();
		virtual ~E_DailySports_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		NFShmString<64> m_name;//名称
		int32_t m_functionID;//功能开放ID
		int32_t m_perActivityid;//活动id
		int32_t m_des;//ui说明
		int32_t m_linkid;//linkID

		virtual void write_to_pbmsg(::proto_ff::E_DailySports & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DailySports & msg);
		static ::proto_ff::E_DailySports* new_pbmsg(){ return new ::proto_ff::E_DailySports(); }
		static ::proto_ff::E_DailySports make_pbmsg(){ return ::proto_ff::E_DailySports(); }
	};
	typedef struct E_DailySports_s E_DailySports_t;

	struct Sheet_DailySports_s : public NFDescStoreSeqOP {
		Sheet_DailySports_s();
		virtual ~Sheet_DailySports_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DailySports_s, DEFINE_SHEET_DAILYSPORTS_E_DAILYSPORTS_LIST_MAX_NUM> E_DailySports_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DailySports & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DailySports & msg);
		static ::proto_ff::Sheet_DailySports* new_pbmsg(){ return new ::proto_ff::Sheet_DailySports(); }
		static ::proto_ff::Sheet_DailySports make_pbmsg(){ return ::proto_ff::Sheet_DailySports(); }
	};
	typedef struct Sheet_DailySports_s Sheet_DailySports_t;

	struct E_DailyHelper_s : public NFDescStoreSeqOP {
		E_DailyHelper_s();
		virtual ~E_DailyHelper_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_helperID;//扫荡ID
		int32_t m_helperType;//扫荡玩法的类型
		NFShmString<64> m_playID;//玩法ID
		int32_t m_linkId;//跳转ID
		NFShmString<64> m_name;//标题显示
		NFShmString<64> m_condition;//条件显示

		virtual void write_to_pbmsg(::proto_ff::E_DailyHelper & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DailyHelper & msg);
		static ::proto_ff::E_DailyHelper* new_pbmsg(){ return new ::proto_ff::E_DailyHelper(); }
		static ::proto_ff::E_DailyHelper make_pbmsg(){ return ::proto_ff::E_DailyHelper(); }
	};
	typedef struct E_DailyHelper_s E_DailyHelper_t;

	struct Sheet_DailyHelper_s : public NFDescStoreSeqOP {
		Sheet_DailyHelper_s();
		virtual ~Sheet_DailyHelper_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DailyHelper_s, DEFINE_SHEET_DAILYHELPER_E_DAILYHELPER_LIST_MAX_NUM> E_DailyHelper_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DailyHelper & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DailyHelper & msg);
		static ::proto_ff::Sheet_DailyHelper* new_pbmsg(){ return new ::proto_ff::Sheet_DailyHelper(); }
		static ::proto_ff::Sheet_DailyHelper make_pbmsg(){ return ::proto_ff::Sheet_DailyHelper(); }
	};
	typedef struct Sheet_DailyHelper_s Sheet_DailyHelper_t;

}

