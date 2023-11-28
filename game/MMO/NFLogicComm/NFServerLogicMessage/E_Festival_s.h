#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Festival.pb.h"
#include "E_Festival_s.h"

#define DEFINE_E_FESTIVALPERIODINDEX_M_PERIOD_MAX_NUM 15
#define DEFINE_SHEET_FESTIVALPERIODINDEX_E_FESTIVALPERIODINDEX_LIST_MAX_NUM 64
#define DEFINE_SHEET_FESTIVALFESTIVAL_E_FESTIVALFESTIVAL_LIST_MAX_NUM 16
#define DEFINE_E_FESTIVALTEMPLATE_M_TIMEARG_MAX_NUM 3
#define DEFINE_SHEET_FESTIVALTEMPLATE_E_FESTIVALTEMPLATE_LIST_MAX_NUM 128
#define DEFINE_SHEET_FESTIVALMUBAN_EGGSDRAW_E_FESTIVALMUBAN_EGGSDRAW_LIST_MAX_NUM 16
#define DEFINE_SHEET_FESTIVALMUBAN_EGGSDRAW_POOL_E_FESTIVALMUBAN_EGGSDRAW_POOL_LIST_MAX_NUM 16
#define DEFINE_E_FESTIVALMUBAN_EGGSDRAW_TASK_M_PARAM_MAX_NUM 2
#define DEFINE_SHEET_FESTIVALMUBAN_EGGSDRAW_TASK_E_FESTIVALMUBAN_EGGSDRAW_TASK_LIST_MAX_NUM 16
#define DEFINE_SHEET_FESTIVALMUBAN_FTREWARD_E_FESTIVALMUBAN_FTREWARD_LIST_MAX_NUM 2
#define DEFINE_SHEET_FESTIVALMUBAN_CHALLENGE_E_FESTIVALMUBAN_CHALLENGE_LIST_MAX_NUM 2
#define DEFINE_E_FESTIVALMUBAN_MYSTMALL_M_OPEN_MAX_NUM 3
#define DEFINE_SHEET_FESTIVALMUBAN_MYSTMALL_E_FESTIVALMUBAN_MYSTMALL_LIST_MAX_NUM 8
#define DEFINE_SHEET_FESTIVALMUBAN_MYSTMALL_MALL_E_FESTIVALMUBAN_MYSTMALL_MALL_LIST_MAX_NUM 32
#define DEFINE_E_FESTIVALMUBAN_REBATESTORE_M_EXPEND_MAX_NUM 6
#define DEFINE_SHEET_FESTIVALMUBAN_REBATESTORE_E_FESTIVALMUBAN_REBATESTORE_LIST_MAX_NUM 2
#define DEFINE_SHEET_FESTIVALMUBAN_REBATESTORE_MALL_E_FESTIVALMUBAN_REBATESTORE_MALL_LIST_MAX_NUM 32
#define DEFINE_SHEET_FESTIVALMUBAN_CONTRECHARGE_E_FESTIVALMUBAN_CONTRECHARGE_LIST_MAX_NUM 2
#define DEFINE_E_FESTIVALMUBAN_CONTRECHARGE_TOTAL_M_TOTAL_MAX_NUM 4
#define DEFINE_SHEET_FESTIVALMUBAN_CONTRECHARGE_TOTAL_E_FESTIVALMUBAN_CONTRECHARGE_TOTAL_LIST_MAX_NUM 8
#define DEFINE_SHEET_FESTIVALMUBAN_CONTRECHARGE_DAY_E_FESTIVALMUBAN_CONTRECHARGE_DAY_LIST_MAX_NUM 64
#define DEFINE_SHEET_FESTIVALMUBAN_LOGIN_E_FESTIVALMUBAN_LOGIN_LIST_MAX_NUM 8
#define DEFINE_SHEET_FESTIVALMUBAN_FIRSTRECHARGE_E_FESTIVALMUBAN_FIRSTRECHARGE_LIST_MAX_NUM 16
#define DEFINE_SHEET_FESTIVALMUBAN_LOVE_E_FESTIVALMUBAN_LOVE_LIST_MAX_NUM 8
#define DEFINE_SHEET_FESTIVALMUBAN_LOVE_RANK_E_FESTIVALMUBAN_LOVE_RANK_LIST_MAX_NUM 2
#define DEFINE_SHEET_FESTIVALMUBAN_LOVE_RANK_DATA_E_FESTIVALMUBAN_LOVE_RANK_DATA_LIST_MAX_NUM 8
#define DEFINE_E_FESTIVALMUBAN_LOVE_TASK_M_PARAM_MAX_NUM 2
#define DEFINE_SHEET_FESTIVALMUBAN_LOVE_TASK_E_FESTIVALMUBAN_LOVE_TASK_LIST_MAX_NUM 16
#define DEFINE_SHEET_FESTIVALMUBAN_LOVE_TASKREWARD_E_FESTIVALMUBAN_LOVE_TASKREWARD_LIST_MAX_NUM 8
#define DEFINE_SHEET_FESTIVALMUBAN_ADDBOX_E_FESTIVALMUBAN_ADDBOX_LIST_MAX_NUM 32
#define DEFINE_SHEET_FESTIVALMUBAN_DOUBLEBOX_E_FESTIVALMUBAN_DOUBLEBOX_LIST_MAX_NUM 32
#define DEFINE_SHEET_FESTIVALMUBAN_BOSSFRISTKILL_E_FESTIVALMUBAN_BOSSFRISTKILL_LIST_MAX_NUM 64
#define DEFINE_SHEET_FESTIVALMUBAN_SEVERRANK_E_FESTIVALMUBAN_SEVERRANK_LIST_MAX_NUM 128
#define DEFINE_SHEET_FESTIVALMUBAN_SEVERRANK_DATA_E_FESTIVALMUBAN_SEVERRANK_DATA_LIST_MAX_NUM 128
#define DEFINE_E_FESTIVALMUBAN_COLLECTWORD_M_COST_MAX_NUM 5
#define DEFINE_SHEET_FESTIVALMUBAN_COLLECTWORD_E_FESTIVALMUBAN_COLLECTWORD_LIST_MAX_NUM 16
#define DEFINE_SHEET_FESTIVALMUBAN_SIGN_E_FESTIVALMUBAN_SIGN_LIST_MAX_NUM 2
#define DEFINE_SHEET_FESTIVALMUBAN_SHOP_E_FESTIVALMUBAN_SHOP_LIST_MAX_NUM 32
#define DEFINE_SHEET_FESTIVALMUBAN_RECHANGE_E_FESTIVALMUBAN_RECHANGE_LIST_MAX_NUM 16
#define DEFINE_SHEET_FESTIVALMUBAN_LEIJI_E_FESTIVALMUBAN_LEIJI_LIST_MAX_NUM 16
#define DEFINE_SHEET_FESTIVALZADANCONSTANT_E_FESTIVALZADANCONSTANT_LIST_MAX_NUM 32
#define DEFINE_SHEET_FESTIVALMUBAN_ZADAN_E_FESTIVALMUBAN_ZADAN_LIST_MAX_NUM 64
#define DEFINE_SHEET_FESTIVALMUBAN_TURNTABLE_E_FESTIVALMUBAN_TURNTABLE_LIST_MAX_NUM 2
#define DEFINE_SHEET_FESTIVALMUBAN_TURNTABLE_POOL_E_FESTIVALMUBAN_TURNTABLE_POOL_LIST_MAX_NUM 16
#define DEFINE_E_FESTIVALMUBAN_TURNTABLE_TASK_M_PARAM_MAX_NUM 2
#define DEFINE_SHEET_FESTIVALMUBAN_TURNTABLE_TASK_E_FESTIVALMUBAN_TURNTABLE_TASK_LIST_MAX_NUM 16
#define DEFINE_SHEET_FESTIVALMUBAN_DONATE_E_FESTIVALMUBAN_DONATE_LIST_MAX_NUM 2
#define DEFINE_SHEET_FESTIVALMUBAN_DONATE_SEVER_E_FESTIVALMUBAN_DONATE_SEVER_LIST_MAX_NUM 64
#define DEFINE_SHEET_FESTIVALMUBAN_DONATE_SINGLE_E_FESTIVALMUBAN_DONATE_SINGLE_LIST_MAX_NUM 8
#define DEFINE_E_FESTIVALMUBAN_DONATE_TASK_M_PARAM_MAX_NUM 2
#define DEFINE_SHEET_FESTIVALMUBAN_DONATE_TASK_E_FESTIVALMUBAN_DONATE_TASK_LIST_MAX_NUM 8
#define DEFINE_SHEET_FESTIVALMUBAN_ONLINE_E_FESTIVALMUBAN_ONLINE_LIST_MAX_NUM 4
#define DEFINE_SHEET_FESTIVALMUBAN_RTURNTABLE_E_FESTIVALMUBAN_RTURNTABLE_LIST_MAX_NUM 2
#define DEFINE_SHEET_FESTIVALMUBAN_RTURNTABLE_RECHARGE_E_FESTIVALMUBAN_RTURNTABLE_RECHARGE_LIST_MAX_NUM 16
#define DEFINE_SHEET_FESTIVALMUBAN_RTURNTABLE_RECHARGE_RATIO_E_FESTIVALMUBAN_RTURNTABLE_RECHARGE_RATIO_LIST_MAX_NUM 64
#define DEFINE_SHEET_FESTIVALMUBAN_DRAWPIZE_E_FESTIVALMUBAN_DRAWPIZE_LIST_MAX_NUM 4
#define DEFINE_SHEET_FESTIVALMUBAN_DRAWPIZE_POOL_E_FESTIVALMUBAN_DRAWPIZE_POOL_LIST_MAX_NUM 64
#define DEFINE_SHEET_FESTIVALMUBAN_DRAWPIZE_TOTAL_E_FESTIVALMUBAN_DRAWPIZE_TOTAL_LIST_MAX_NUM 64
#define DEFINE_SHEET_FESTIVALMUBAN_TOTALRECHARGE_E_FESTIVALMUBAN_TOTALRECHARGE_LIST_MAX_NUM 16
#define DEFINE_SHEET_FESTIVALMUBAN_DAILYTOTALRECHARGE_E_FESTIVALMUBAN_DAILYTOTALRECHARGE_LIST_MAX_NUM 8
#define DEFINE_SHEET_FESTIVALMUBAN_RECHARGEPRIZE_E_FESTIVALMUBAN_RECHARGEPRIZE_LIST_MAX_NUM 2
#define DEFINE_SHEET_FESTIVALMUBAN_RPTASK_E_FESTIVALMUBAN_RPTASK_LIST_MAX_NUM 32
#define DEFINE_SHEET_FESTIVALMUBAN_RPPOOL_E_FESTIVALMUBAN_RPPOOL_LIST_MAX_NUM 16
#define DEFINE_E_FESTIVALMUBAN_PLAY_M_OPENTIME_MAX_NUM 2
#define DEFINE_SHEET_FESTIVALMUBAN_PLAY_E_FESTIVALMUBAN_PLAY_LIST_MAX_NUM 2
#define DEFINE_SHEET_FESTIVALMUBAN_PLAY_REWARD_E_FESTIVALMUBAN_PLAY_REWARD_LIST_MAX_NUM 8
#define DEFINE_E_FESTIVALMUBAN_PLAY_GAME_M_PLAYARG_MAX_NUM 5
#define DEFINE_SHEET_FESTIVALMUBAN_PLAY_GAME_E_FESTIVALMUBAN_PLAY_GAME_LIST_MAX_NUM 64
#define DEFINE_SHEET_FESTIVALMUBAN_PLAY_SCORE_E_FESTIVALMUBAN_PLAY_SCORE_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_FestivalPeriodindex_s : public NFDescStoreSeqOP {
		E_FestivalPeriodindex_s();
		virtual ~E_FestivalPeriodindex_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_minOrigalDay;//最小原始开服时间
		NFShmVector<int32_t, DEFINE_E_FESTIVALPERIODINDEX_M_PERIOD_MAX_NUM> m_period;//期数类型

		virtual void write_to_pbmsg(::proto_ff::E_FestivalPeriodindex & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalPeriodindex & msg);
		static ::proto_ff::E_FestivalPeriodindex* new_pbmsg(){ return new ::proto_ff::E_FestivalPeriodindex(); }
		static ::proto_ff::E_FestivalPeriodindex make_pbmsg(){ return ::proto_ff::E_FestivalPeriodindex(); }
	};
	typedef struct E_FestivalPeriodindex_s E_FestivalPeriodindex_t;

	struct Sheet_FestivalPeriodindex_s : public NFDescStoreSeqOP {
		Sheet_FestivalPeriodindex_s();
		virtual ~Sheet_FestivalPeriodindex_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalPeriodindex_s, DEFINE_SHEET_FESTIVALPERIODINDEX_E_FESTIVALPERIODINDEX_LIST_MAX_NUM> E_FestivalPeriodindex_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalPeriodindex & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalPeriodindex & msg);
		static ::proto_ff::Sheet_FestivalPeriodindex* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalPeriodindex(); }
		static ::proto_ff::Sheet_FestivalPeriodindex make_pbmsg(){ return ::proto_ff::Sheet_FestivalPeriodindex(); }
	};
	typedef struct Sheet_FestivalPeriodindex_s Sheet_FestivalPeriodindex_t;

	struct E_FestivalFestival_s : public NFDescStoreSeqOP {
		E_FestivalFestival_s();
		virtual ~E_FestivalFestival_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//节日ID
		int32_t m_type;//活动类型

		virtual void write_to_pbmsg(::proto_ff::E_FestivalFestival & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalFestival & msg);
		static ::proto_ff::E_FestivalFestival* new_pbmsg(){ return new ::proto_ff::E_FestivalFestival(); }
		static ::proto_ff::E_FestivalFestival make_pbmsg(){ return ::proto_ff::E_FestivalFestival(); }
	};
	typedef struct E_FestivalFestival_s E_FestivalFestival_t;

	struct Sheet_FestivalFestival_s : public NFDescStoreSeqOP {
		Sheet_FestivalFestival_s();
		virtual ~Sheet_FestivalFestival_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalFestival_s, DEFINE_SHEET_FESTIVALFESTIVAL_E_FESTIVALFESTIVAL_LIST_MAX_NUM> E_FestivalFestival_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalFestival & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalFestival & msg);
		static ::proto_ff::Sheet_FestivalFestival* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalFestival(); }
		static ::proto_ff::Sheet_FestivalFestival make_pbmsg(){ return ::proto_ff::Sheet_FestivalFestival(); }
	};
	typedef struct Sheet_FestivalFestival_s Sheet_FestivalFestival_t;

	struct E_FestivalTemplate_s : public NFDescStoreSeqOP {
		E_FestivalTemplate_s();
		virtual ~E_FestivalTemplate_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//活动ID
		NFShmString<64> m_name;//模板名称
		NFShmString<64> m_actionName;//动态名称
		int32_t m_festivalId;//引用主体
		NFShmString<64> m_actionFestivalId;//动态引用主体
		int32_t m_timeType;//时间类型
		int32_t m_level;//等级要求
		int32_t m_vipLevel;//vip等级要求
		int32_t m_rechange;//充值要求高级运营活动计数
		int32_t m_severType;//服务器活动类型
		NFShmString<64> m_typeArg;//模板特殊参数
		int32_t m_periodType;//期数类型
		int32_t m_period;//期数参数
		int32_t m_ifOpen;//活动开关
		int32_t m_activeID;//激活活动ID
		NFShmVector<NFShmString<64>, DEFINE_E_FESTIVALTEMPLATE_M_TIMEARG_MAX_NUM> m_timeArg;//时间参数

		virtual void write_to_pbmsg(::proto_ff::E_FestivalTemplate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalTemplate & msg);
		static ::proto_ff::E_FestivalTemplate* new_pbmsg(){ return new ::proto_ff::E_FestivalTemplate(); }
		static ::proto_ff::E_FestivalTemplate make_pbmsg(){ return ::proto_ff::E_FestivalTemplate(); }
	};
	typedef struct E_FestivalTemplate_s E_FestivalTemplate_t;

	struct Sheet_FestivalTemplate_s : public NFDescStoreSeqOP {
		Sheet_FestivalTemplate_s();
		virtual ~Sheet_FestivalTemplate_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalTemplate_s, DEFINE_SHEET_FESTIVALTEMPLATE_E_FESTIVALTEMPLATE_LIST_MAX_NUM> E_FestivalTemplate_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalTemplate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalTemplate & msg);
		static ::proto_ff::Sheet_FestivalTemplate* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalTemplate(); }
		static ::proto_ff::Sheet_FestivalTemplate make_pbmsg(){ return ::proto_ff::Sheet_FestivalTemplate(); }
	};
	typedef struct Sheet_FestivalTemplate_s Sheet_FestivalTemplate_t;

	struct E_FestivalMuban_eggsdraw_s : public NFDescStoreSeqOP {
		E_FestivalMuban_eggsdraw_s();
		virtual ~E_FestivalMuban_eggsdraw_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_costItem;//抽奖道具id
		NFShmString<64> m_costNum;//物品数量
		int32_t m_poolGroupID;//奖池组id
		int32_t m_showType;//表现形式
		NFShmString<64> m_baseImage;//蛋底图
		NFShmString<64> m_eggImage;//蛋资源
		NFShmString<64> m_clickDesc;//点击描述
		NFShmString<64> m_costDesc;//消耗描述
		NFShmString<64> m_residueDesc;//剩余描述
		int32_t m_restartItem;//重置消耗道具
		int32_t m_restartCost;//重置消耗数量
		int32_t m_dailyRestart;//每日重置
		int32_t m_free;//免费每日重置次数
		int32_t m_taskGroupID;//任务组ID
		int32_t m_dailyTaskRestart;//任务是否每日重置

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_eggsdraw & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_eggsdraw & msg);
		static ::proto_ff::E_FestivalMuban_eggsdraw* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_eggsdraw(); }
		static ::proto_ff::E_FestivalMuban_eggsdraw make_pbmsg(){ return ::proto_ff::E_FestivalMuban_eggsdraw(); }
	};
	typedef struct E_FestivalMuban_eggsdraw_s E_FestivalMuban_eggsdraw_t;

	struct Sheet_FestivalMuban_eggsdraw_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_eggsdraw_s();
		virtual ~Sheet_FestivalMuban_eggsdraw_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_eggsdraw_s, DEFINE_SHEET_FESTIVALMUBAN_EGGSDRAW_E_FESTIVALMUBAN_EGGSDRAW_LIST_MAX_NUM> E_FestivalMuban_eggsdraw_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_eggsdraw & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_eggsdraw & msg);
		static ::proto_ff::Sheet_FestivalMuban_eggsdraw* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_eggsdraw(); }
		static ::proto_ff::Sheet_FestivalMuban_eggsdraw make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_eggsdraw(); }
	};
	typedef struct Sheet_FestivalMuban_eggsdraw_s Sheet_FestivalMuban_eggsdraw_t;

	struct E_FestivalMuban_eggsdraw_pool_s : public NFDescStoreSeqOP {
		E_FestivalMuban_eggsdraw_pool_s();
		virtual ~E_FestivalMuban_eggsdraw_pool_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//组ID
		int64_t m_itemid;//物品
		int32_t m_num;//数量
		int32_t m_prof;//职业
		int32_t m_weights;//掉落权重
		int32_t m_Record;//奖励记录稀有度
		int32_t m_poolLv;//奖池等级

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_eggsdraw_pool & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_eggsdraw_pool & msg);
		static ::proto_ff::E_FestivalMuban_eggsdraw_pool* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_eggsdraw_pool(); }
		static ::proto_ff::E_FestivalMuban_eggsdraw_pool make_pbmsg(){ return ::proto_ff::E_FestivalMuban_eggsdraw_pool(); }
	};
	typedef struct E_FestivalMuban_eggsdraw_pool_s E_FestivalMuban_eggsdraw_pool_t;

	struct Sheet_FestivalMuban_eggsdraw_pool_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_eggsdraw_pool_s();
		virtual ~Sheet_FestivalMuban_eggsdraw_pool_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_eggsdraw_pool_s, DEFINE_SHEET_FESTIVALMUBAN_EGGSDRAW_POOL_E_FESTIVALMUBAN_EGGSDRAW_POOL_LIST_MAX_NUM> E_FestivalMuban_eggsdraw_pool_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_eggsdraw_pool & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_eggsdraw_pool & msg);
		static ::proto_ff::Sheet_FestivalMuban_eggsdraw_pool* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_eggsdraw_pool(); }
		static ::proto_ff::Sheet_FestivalMuban_eggsdraw_pool make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_eggsdraw_pool(); }
	};
	typedef struct Sheet_FestivalMuban_eggsdraw_pool_s Sheet_FestivalMuban_eggsdraw_pool_t;

	struct E_FestivalMuban_eggsdraw_task_s : public NFDescStoreSeqOP {
		E_FestivalMuban_eggsdraw_task_s();
		virtual ~E_FestivalMuban_eggsdraw_task_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//组id
		int32_t m_eventType;//事件类型
		int32_t m_reachPrice;//达成值
		int32_t m_rewardItem;//奖励道具ID
		int32_t m_rewardNum;//奖励数量
		int32_t m_link;//连接
		NFShmVector<int32_t, DEFINE_E_FESTIVALMUBAN_EGGSDRAW_TASK_M_PARAM_MAX_NUM> m_param;//事件完成参数

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_eggsdraw_task & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_eggsdraw_task & msg);
		static ::proto_ff::E_FestivalMuban_eggsdraw_task* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_eggsdraw_task(); }
		static ::proto_ff::E_FestivalMuban_eggsdraw_task make_pbmsg(){ return ::proto_ff::E_FestivalMuban_eggsdraw_task(); }
	};
	typedef struct E_FestivalMuban_eggsdraw_task_s E_FestivalMuban_eggsdraw_task_t;

	struct Sheet_FestivalMuban_eggsdraw_task_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_eggsdraw_task_s();
		virtual ~Sheet_FestivalMuban_eggsdraw_task_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_eggsdraw_task_s, DEFINE_SHEET_FESTIVALMUBAN_EGGSDRAW_TASK_E_FESTIVALMUBAN_EGGSDRAW_TASK_LIST_MAX_NUM> E_FestivalMuban_eggsdraw_task_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_eggsdraw_task & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_eggsdraw_task & msg);
		static ::proto_ff::Sheet_FestivalMuban_eggsdraw_task* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_eggsdraw_task(); }
		static ::proto_ff::Sheet_FestivalMuban_eggsdraw_task make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_eggsdraw_task(); }
	};
	typedef struct Sheet_FestivalMuban_eggsdraw_task_s Sheet_FestivalMuban_eggsdraw_task_t;

	struct E_FestivalMuban_ftreward_s : public NFDescStoreSeqOP {
		E_FestivalMuban_ftreward_s();
		virtual ~E_FestivalMuban_ftreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		NFShmString<64> m_FTID;//抽奖组id
		int32_t m_addItemID;//额外奖励道具
		NFShmString<64> m_showReward;//奖励展示
		int32_t m_linkid;//跳转
		int32_t m_functionID;//功能开放ID

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_ftreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_ftreward & msg);
		static ::proto_ff::E_FestivalMuban_ftreward* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_ftreward(); }
		static ::proto_ff::E_FestivalMuban_ftreward make_pbmsg(){ return ::proto_ff::E_FestivalMuban_ftreward(); }
	};
	typedef struct E_FestivalMuban_ftreward_s E_FestivalMuban_ftreward_t;

	struct Sheet_FestivalMuban_ftreward_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_ftreward_s();
		virtual ~Sheet_FestivalMuban_ftreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_ftreward_s, DEFINE_SHEET_FESTIVALMUBAN_FTREWARD_E_FESTIVALMUBAN_FTREWARD_LIST_MAX_NUM> E_FestivalMuban_ftreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_ftreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_ftreward & msg);
		static ::proto_ff::Sheet_FestivalMuban_ftreward* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_ftreward(); }
		static ::proto_ff::Sheet_FestivalMuban_ftreward make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_ftreward(); }
	};
	typedef struct Sheet_FestivalMuban_ftreward_s Sheet_FestivalMuban_ftreward_t;

	struct E_FestivalMuban_challenge_s : public NFDescStoreSeqOP {
		E_FestivalMuban_challenge_s();
		virtual ~E_FestivalMuban_challenge_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		NFShmString<64> m_name;//名称
		int32_t m_joinBox;//参与奖励
		int32_t m_killBoxShow;//完成展示奖励
		int32_t m_monster;//怪物ID
		int32_t m_point;//刷新点
		NFShmString<64> m_showTime;//显示时间点
		int32_t m_faceid;//显示外观
		NFShmString<64> m_scalle;//缩放
		int32_t m_linkid;//linkID

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_challenge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_challenge & msg);
		static ::proto_ff::E_FestivalMuban_challenge* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_challenge(); }
		static ::proto_ff::E_FestivalMuban_challenge make_pbmsg(){ return ::proto_ff::E_FestivalMuban_challenge(); }
	};
	typedef struct E_FestivalMuban_challenge_s E_FestivalMuban_challenge_t;

	struct Sheet_FestivalMuban_challenge_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_challenge_s();
		virtual ~Sheet_FestivalMuban_challenge_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_challenge_s, DEFINE_SHEET_FESTIVALMUBAN_CHALLENGE_E_FESTIVALMUBAN_CHALLENGE_LIST_MAX_NUM> E_FestivalMuban_challenge_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_challenge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_challenge & msg);
		static ::proto_ff::Sheet_FestivalMuban_challenge* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_challenge(); }
		static ::proto_ff::Sheet_FestivalMuban_challenge make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_challenge(); }
	};
	typedef struct Sheet_FestivalMuban_challenge_s Sheet_FestivalMuban_challenge_t;

	struct E_FestivalMuban_mystmallOpenDesc_s : public NFDescStoreSeqOP {
		E_FestivalMuban_mystmallOpenDesc_s();
		virtual ~E_FestivalMuban_mystmallOpenDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_dur;//持续时间
		int32_t m_mallID;//商店组
		NFShmString<64> m_time;//时间点
		int32_t m_ID;//id

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_mystmallOpenDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_mystmallOpenDesc & msg);
		static ::proto_ff::E_FestivalMuban_mystmallOpenDesc* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_mystmallOpenDesc(); }
		static ::proto_ff::E_FestivalMuban_mystmallOpenDesc make_pbmsg(){ return ::proto_ff::E_FestivalMuban_mystmallOpenDesc(); }
	};
	typedef struct E_FestivalMuban_mystmallOpenDesc_s E_FestivalMuban_mystmallOpenDesc_t;

	struct E_FestivalMuban_mystmall_s : public NFDescStoreSeqOP {
		E_FestivalMuban_mystmall_s();
		virtual ~E_FestivalMuban_mystmall_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_day;//天数
		NFShmVector<struct E_FestivalMuban_mystmallOpenDesc_s, DEFINE_E_FESTIVALMUBAN_MYSTMALL_M_OPEN_MAX_NUM> m_open;//开放

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_mystmall & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_mystmall & msg);
		static ::proto_ff::E_FestivalMuban_mystmall* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_mystmall(); }
		static ::proto_ff::E_FestivalMuban_mystmall make_pbmsg(){ return ::proto_ff::E_FestivalMuban_mystmall(); }
	};
	typedef struct E_FestivalMuban_mystmall_s E_FestivalMuban_mystmall_t;

	struct Sheet_FestivalMuban_mystmall_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_mystmall_s();
		virtual ~Sheet_FestivalMuban_mystmall_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_mystmall_s, DEFINE_SHEET_FESTIVALMUBAN_MYSTMALL_E_FESTIVALMUBAN_MYSTMALL_LIST_MAX_NUM> E_FestivalMuban_mystmall_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_mystmall & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_mystmall & msg);
		static ::proto_ff::Sheet_FestivalMuban_mystmall* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_mystmall(); }
		static ::proto_ff::Sheet_FestivalMuban_mystmall make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_mystmall(); }
	};
	typedef struct Sheet_FestivalMuban_mystmall_s Sheet_FestivalMuban_mystmall_t;

	struct E_FestivalMuban_mystmall_mall_s : public NFDescStoreSeqOP {
		E_FestivalMuban_mystmall_mall_s();
		virtual ~E_FestivalMuban_mystmall_mall_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//商品ID
		int32_t m_groupID;//商城组ID
		int32_t m_itemID;//物品ID
		int32_t m_itemNum;//购买数量
		int32_t m_priceType;//价格类型
		int32_t m_price;//价格
		int32_t m_originPrice;//原价
		int32_t m_discount;//折扣
		int32_t m_buyAmount;//限制数量
		int32_t m_functionUnlock;//关联功能开放

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_mystmall_mall & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_mystmall_mall & msg);
		static ::proto_ff::E_FestivalMuban_mystmall_mall* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_mystmall_mall(); }
		static ::proto_ff::E_FestivalMuban_mystmall_mall make_pbmsg(){ return ::proto_ff::E_FestivalMuban_mystmall_mall(); }
	};
	typedef struct E_FestivalMuban_mystmall_mall_s E_FestivalMuban_mystmall_mall_t;

	struct Sheet_FestivalMuban_mystmall_mall_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_mystmall_mall_s();
		virtual ~Sheet_FestivalMuban_mystmall_mall_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_mystmall_mall_s, DEFINE_SHEET_FESTIVALMUBAN_MYSTMALL_MALL_E_FESTIVALMUBAN_MYSTMALL_MALL_LIST_MAX_NUM> E_FestivalMuban_mystmall_mall_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_mystmall_mall & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_mystmall_mall & msg);
		static ::proto_ff::Sheet_FestivalMuban_mystmall_mall* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_mystmall_mall(); }
		static ::proto_ff::Sheet_FestivalMuban_mystmall_mall make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_mystmall_mall(); }
	};
	typedef struct Sheet_FestivalMuban_mystmall_mall_s Sheet_FestivalMuban_mystmall_mall_t;

	struct E_FestivalMuban_rebatestoreExpendDesc_s : public NFDescStoreSeqOP {
		E_FestivalMuban_rebatestoreExpendDesc_s();
		virtual ~E_FestivalMuban_rebatestoreExpendDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_BoxID;//奖励
		int32_t m_Value;//值

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_rebatestoreExpendDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rebatestoreExpendDesc & msg);
		static ::proto_ff::E_FestivalMuban_rebatestoreExpendDesc* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_rebatestoreExpendDesc(); }
		static ::proto_ff::E_FestivalMuban_rebatestoreExpendDesc make_pbmsg(){ return ::proto_ff::E_FestivalMuban_rebatestoreExpendDesc(); }
	};
	typedef struct E_FestivalMuban_rebatestoreExpendDesc_s E_FestivalMuban_rebatestoreExpendDesc_t;

	struct E_FestivalMuban_rebatestore_s : public NFDescStoreSeqOP {
		E_FestivalMuban_rebatestore_s();
		virtual ~E_FestivalMuban_rebatestore_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_groupID;//商店组ID
		NFShmVector<struct E_FestivalMuban_rebatestoreExpendDesc_s, DEFINE_E_FESTIVALMUBAN_REBATESTORE_M_EXPEND_MAX_NUM> m_expend;//消费

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_rebatestore & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rebatestore & msg);
		static ::proto_ff::E_FestivalMuban_rebatestore* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_rebatestore(); }
		static ::proto_ff::E_FestivalMuban_rebatestore make_pbmsg(){ return ::proto_ff::E_FestivalMuban_rebatestore(); }
	};
	typedef struct E_FestivalMuban_rebatestore_s E_FestivalMuban_rebatestore_t;

	struct Sheet_FestivalMuban_rebatestore_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_rebatestore_s();
		virtual ~Sheet_FestivalMuban_rebatestore_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_rebatestore_s, DEFINE_SHEET_FESTIVALMUBAN_REBATESTORE_E_FESTIVALMUBAN_REBATESTORE_LIST_MAX_NUM> E_FestivalMuban_rebatestore_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_rebatestore & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_rebatestore & msg);
		static ::proto_ff::Sheet_FestivalMuban_rebatestore* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_rebatestore(); }
		static ::proto_ff::Sheet_FestivalMuban_rebatestore make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_rebatestore(); }
	};
	typedef struct Sheet_FestivalMuban_rebatestore_s Sheet_FestivalMuban_rebatestore_t;

	struct E_FestivalMuban_rebatestore_mall_s : public NFDescStoreSeqOP {
		E_FestivalMuban_rebatestore_mall_s();
		virtual ~E_FestivalMuban_rebatestore_mall_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//商品ID
		int32_t m_groupID;//商城组ID
		int32_t m_mallType;//商城分类
		int32_t m_itemID;//物品ID
		int32_t m_itemNum;//购买数量
		int32_t m_price;//价格
		int32_t m_originPrice;//原价
		int32_t m_discount;//折扣
		int32_t m_daily;//是否每日重置
		int32_t m_buyAmount;//限制数量
		int32_t m_functionUnlock;//关联功能开放
		int32_t m_openDay;//开放天数
		int32_t m_closeDay;//消失天数

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_rebatestore_mall & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rebatestore_mall & msg);
		static ::proto_ff::E_FestivalMuban_rebatestore_mall* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_rebatestore_mall(); }
		static ::proto_ff::E_FestivalMuban_rebatestore_mall make_pbmsg(){ return ::proto_ff::E_FestivalMuban_rebatestore_mall(); }
	};
	typedef struct E_FestivalMuban_rebatestore_mall_s E_FestivalMuban_rebatestore_mall_t;

	struct Sheet_FestivalMuban_rebatestore_mall_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_rebatestore_mall_s();
		virtual ~Sheet_FestivalMuban_rebatestore_mall_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_rebatestore_mall_s, DEFINE_SHEET_FESTIVALMUBAN_REBATESTORE_MALL_E_FESTIVALMUBAN_REBATESTORE_MALL_LIST_MAX_NUM> E_FestivalMuban_rebatestore_mall_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_rebatestore_mall & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_rebatestore_mall & msg);
		static ::proto_ff::Sheet_FestivalMuban_rebatestore_mall* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_rebatestore_mall(); }
		static ::proto_ff::Sheet_FestivalMuban_rebatestore_mall make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_rebatestore_mall(); }
	};
	typedef struct Sheet_FestivalMuban_rebatestore_mall_s Sheet_FestivalMuban_rebatestore_mall_t;

	struct E_FestivalMuban_contrecharge_s : public NFDescStoreSeqOP {
		E_FestivalMuban_contrecharge_s();
		virtual ~E_FestivalMuban_contrecharge_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_totalGroup;//组ID
		int32_t m_dailyGroup;//每日充值组

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_contrecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_contrecharge & msg);
		static ::proto_ff::E_FestivalMuban_contrecharge* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_contrecharge(); }
		static ::proto_ff::E_FestivalMuban_contrecharge make_pbmsg(){ return ::proto_ff::E_FestivalMuban_contrecharge(); }
	};
	typedef struct E_FestivalMuban_contrecharge_s E_FestivalMuban_contrecharge_t;

	struct Sheet_FestivalMuban_contrecharge_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_contrecharge_s();
		virtual ~Sheet_FestivalMuban_contrecharge_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_contrecharge_s, DEFINE_SHEET_FESTIVALMUBAN_CONTRECHARGE_E_FESTIVALMUBAN_CONTRECHARGE_LIST_MAX_NUM> E_FestivalMuban_contrecharge_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_contrecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_contrecharge & msg);
		static ::proto_ff::Sheet_FestivalMuban_contrecharge* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_contrecharge(); }
		static ::proto_ff::Sheet_FestivalMuban_contrecharge make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_contrecharge(); }
	};
	typedef struct Sheet_FestivalMuban_contrecharge_s Sheet_FestivalMuban_contrecharge_t;

	struct E_FestivalMuban_contrecharge_totalTotalDesc_s : public NFDescStoreSeqOP {
		E_FestivalMuban_contrecharge_totalTotalDesc_s();
		virtual ~E_FestivalMuban_contrecharge_totalTotalDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Box;//奖励
		int32_t m_Days;//天数

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_contrecharge_totalTotalDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_contrecharge_totalTotalDesc & msg);
		static ::proto_ff::E_FestivalMuban_contrecharge_totalTotalDesc* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_contrecharge_totalTotalDesc(); }
		static ::proto_ff::E_FestivalMuban_contrecharge_totalTotalDesc make_pbmsg(){ return ::proto_ff::E_FestivalMuban_contrecharge_totalTotalDesc(); }
	};
	typedef struct E_FestivalMuban_contrecharge_totalTotalDesc_s E_FestivalMuban_contrecharge_totalTotalDesc_t;

	struct E_FestivalMuban_contrecharge_total_s : public NFDescStoreSeqOP {
		E_FestivalMuban_contrecharge_total_s();
		virtual ~E_FestivalMuban_contrecharge_total_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//组ID
		int32_t m_Gear;//档位
		int32_t m_recharge;//充值金额
		NFShmVector<struct E_FestivalMuban_contrecharge_totalTotalDesc_s, DEFINE_E_FESTIVALMUBAN_CONTRECHARGE_TOTAL_M_TOTAL_MAX_NUM> m_total;//连续

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_contrecharge_total & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_contrecharge_total & msg);
		static ::proto_ff::E_FestivalMuban_contrecharge_total* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_contrecharge_total(); }
		static ::proto_ff::E_FestivalMuban_contrecharge_total make_pbmsg(){ return ::proto_ff::E_FestivalMuban_contrecharge_total(); }
	};
	typedef struct E_FestivalMuban_contrecharge_total_s E_FestivalMuban_contrecharge_total_t;

	struct Sheet_FestivalMuban_contrecharge_total_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_contrecharge_total_s();
		virtual ~Sheet_FestivalMuban_contrecharge_total_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_contrecharge_total_s, DEFINE_SHEET_FESTIVALMUBAN_CONTRECHARGE_TOTAL_E_FESTIVALMUBAN_CONTRECHARGE_TOTAL_LIST_MAX_NUM> E_FestivalMuban_contrecharge_total_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_contrecharge_total & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_contrecharge_total & msg);
		static ::proto_ff::Sheet_FestivalMuban_contrecharge_total* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_contrecharge_total(); }
		static ::proto_ff::Sheet_FestivalMuban_contrecharge_total make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_contrecharge_total(); }
	};
	typedef struct Sheet_FestivalMuban_contrecharge_total_s Sheet_FestivalMuban_contrecharge_total_t;

	struct E_FestivalMuban_contrecharge_day_s : public NFDescStoreSeqOP {
		E_FestivalMuban_contrecharge_day_s();
		virtual ~E_FestivalMuban_contrecharge_day_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//连充奖励组
		int32_t m_day;//天数
		int32_t m_gear;//档位
		int32_t m_box;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_contrecharge_day & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_contrecharge_day & msg);
		static ::proto_ff::E_FestivalMuban_contrecharge_day* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_contrecharge_day(); }
		static ::proto_ff::E_FestivalMuban_contrecharge_day make_pbmsg(){ return ::proto_ff::E_FestivalMuban_contrecharge_day(); }
	};
	typedef struct E_FestivalMuban_contrecharge_day_s E_FestivalMuban_contrecharge_day_t;

	struct Sheet_FestivalMuban_contrecharge_day_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_contrecharge_day_s();
		virtual ~Sheet_FestivalMuban_contrecharge_day_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_contrecharge_day_s, DEFINE_SHEET_FESTIVALMUBAN_CONTRECHARGE_DAY_E_FESTIVALMUBAN_CONTRECHARGE_DAY_LIST_MAX_NUM> E_FestivalMuban_contrecharge_day_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_contrecharge_day & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_contrecharge_day & msg);
		static ::proto_ff::Sheet_FestivalMuban_contrecharge_day* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_contrecharge_day(); }
		static ::proto_ff::Sheet_FestivalMuban_contrecharge_day make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_contrecharge_day(); }
	};
	typedef struct Sheet_FestivalMuban_contrecharge_day_s Sheet_FestivalMuban_contrecharge_day_t;

	struct E_FestivalMuban_login_s : public NFDescStoreSeqOP {
		E_FestivalMuban_login_s();
		virtual ~E_FestivalMuban_login_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_loginDay;//天数要求
		int32_t m_boxid;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_login & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_login & msg);
		static ::proto_ff::E_FestivalMuban_login* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_login(); }
		static ::proto_ff::E_FestivalMuban_login make_pbmsg(){ return ::proto_ff::E_FestivalMuban_login(); }
	};
	typedef struct E_FestivalMuban_login_s E_FestivalMuban_login_t;

	struct Sheet_FestivalMuban_login_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_login_s();
		virtual ~Sheet_FestivalMuban_login_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_login_s, DEFINE_SHEET_FESTIVALMUBAN_LOGIN_E_FESTIVALMUBAN_LOGIN_LIST_MAX_NUM> E_FestivalMuban_login_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_login & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_login & msg);
		static ::proto_ff::Sheet_FestivalMuban_login* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_login(); }
		static ::proto_ff::Sheet_FestivalMuban_login make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_login(); }
	};
	typedef struct Sheet_FestivalMuban_login_s Sheet_FestivalMuban_login_t;

	struct E_FestivalMuban_firstrecharge_s : public NFDescStoreSeqOP {
		E_FestivalMuban_firstrecharge_s();
		virtual ~E_FestivalMuban_firstrecharge_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_day;//天数
		int32_t m_gear;//档位
		int32_t m_recharge;//充值金额
		int32_t m_boxid;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_firstrecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_firstrecharge & msg);
		static ::proto_ff::E_FestivalMuban_firstrecharge* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_firstrecharge(); }
		static ::proto_ff::E_FestivalMuban_firstrecharge make_pbmsg(){ return ::proto_ff::E_FestivalMuban_firstrecharge(); }
	};
	typedef struct E_FestivalMuban_firstrecharge_s E_FestivalMuban_firstrecharge_t;

	struct Sheet_FestivalMuban_firstrecharge_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_firstrecharge_s();
		virtual ~Sheet_FestivalMuban_firstrecharge_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_firstrecharge_s, DEFINE_SHEET_FESTIVALMUBAN_FIRSTRECHARGE_E_FESTIVALMUBAN_FIRSTRECHARGE_LIST_MAX_NUM> E_FestivalMuban_firstrecharge_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_firstrecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_firstrecharge & msg);
		static ::proto_ff::Sheet_FestivalMuban_firstrecharge* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_firstrecharge(); }
		static ::proto_ff::Sheet_FestivalMuban_firstrecharge make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_firstrecharge(); }
	};
	typedef struct Sheet_FestivalMuban_firstrecharge_s Sheet_FestivalMuban_firstrecharge_t;

	struct E_FestivalMuban_love_s : public NFDescStoreSeqOP {
		E_FestivalMuban_love_s();
		virtual ~E_FestivalMuban_love_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_taskPointID;//任务进度道具id
		int32_t m_rankGroup;//排行组
		int32_t m_taskGroup;//任务组
		int32_t m_taskRewardGroup;//任务奖励组

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_love & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_love & msg);
		static ::proto_ff::E_FestivalMuban_love* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_love(); }
		static ::proto_ff::E_FestivalMuban_love make_pbmsg(){ return ::proto_ff::E_FestivalMuban_love(); }
	};
	typedef struct E_FestivalMuban_love_s E_FestivalMuban_love_t;

	struct Sheet_FestivalMuban_love_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_love_s();
		virtual ~Sheet_FestivalMuban_love_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_love_s, DEFINE_SHEET_FESTIVALMUBAN_LOVE_E_FESTIVALMUBAN_LOVE_LIST_MAX_NUM> E_FestivalMuban_love_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_love & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_love & msg);
		static ::proto_ff::Sheet_FestivalMuban_love* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_love(); }
		static ::proto_ff::Sheet_FestivalMuban_love make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_love(); }
	};
	typedef struct Sheet_FestivalMuban_love_s Sheet_FestivalMuban_love_t;

	struct E_FestivalMuban_love_rank_s : public NFDescStoreSeqOP {
		E_FestivalMuban_love_rank_s();
		virtual ~E_FestivalMuban_love_rank_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupid;//组ID
		int32_t m_rewardShow;//第一名的展示资源
		int32_t m_dataGroupID;//排行数据组id
		int32_t m_rankType;//排行类型

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_love_rank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_love_rank & msg);
		static ::proto_ff::E_FestivalMuban_love_rank* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_love_rank(); }
		static ::proto_ff::E_FestivalMuban_love_rank make_pbmsg(){ return ::proto_ff::E_FestivalMuban_love_rank(); }
	};
	typedef struct E_FestivalMuban_love_rank_s E_FestivalMuban_love_rank_t;

	struct Sheet_FestivalMuban_love_rank_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_love_rank_s();
		virtual ~Sheet_FestivalMuban_love_rank_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_love_rank_s, DEFINE_SHEET_FESTIVALMUBAN_LOVE_RANK_E_FESTIVALMUBAN_LOVE_RANK_LIST_MAX_NUM> E_FestivalMuban_love_rank_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_love_rank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_love_rank & msg);
		static ::proto_ff::Sheet_FestivalMuban_love_rank* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_love_rank(); }
		static ::proto_ff::Sheet_FestivalMuban_love_rank make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_love_rank(); }
	};
	typedef struct Sheet_FestivalMuban_love_rank_s Sheet_FestivalMuban_love_rank_t;

	struct E_FestivalMuban_love_rank_data_s : public NFDescStoreSeqOP {
		E_FestivalMuban_love_rank_data_s();
		virtual ~E_FestivalMuban_love_rank_data_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//组id
		int32_t m_maxRank;//排名上限
		int32_t m_minRank;//排名下限
		int32_t m_rankValue;//最低排行值数值要求
		int32_t m_boxID;//奖励内容

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_love_rank_data & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_love_rank_data & msg);
		static ::proto_ff::E_FestivalMuban_love_rank_data* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_love_rank_data(); }
		static ::proto_ff::E_FestivalMuban_love_rank_data make_pbmsg(){ return ::proto_ff::E_FestivalMuban_love_rank_data(); }
	};
	typedef struct E_FestivalMuban_love_rank_data_s E_FestivalMuban_love_rank_data_t;

	struct Sheet_FestivalMuban_love_rank_data_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_love_rank_data_s();
		virtual ~Sheet_FestivalMuban_love_rank_data_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_love_rank_data_s, DEFINE_SHEET_FESTIVALMUBAN_LOVE_RANK_DATA_E_FESTIVALMUBAN_LOVE_RANK_DATA_LIST_MAX_NUM> E_FestivalMuban_love_rank_data_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_love_rank_data & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_love_rank_data & msg);
		static ::proto_ff::Sheet_FestivalMuban_love_rank_data* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_love_rank_data(); }
		static ::proto_ff::Sheet_FestivalMuban_love_rank_data make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_love_rank_data(); }
	};
	typedef struct Sheet_FestivalMuban_love_rank_data_s Sheet_FestivalMuban_love_rank_data_t;

	struct E_FestivalMuban_love_task_s : public NFDescStoreSeqOP {
		E_FestivalMuban_love_task_s();
		virtual ~E_FestivalMuban_love_task_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//组id
		int32_t m_eventType;//事件类型
		int32_t m_reachPrice;//达成值
		int32_t m_link;//连接
		int32_t m_rewardTimes;//奖励心数
		int32_t m_reward;//奖励内容
		NFShmVector<int32_t, DEFINE_E_FESTIVALMUBAN_LOVE_TASK_M_PARAM_MAX_NUM> m_param;//事件完成参数

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_love_task & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_love_task & msg);
		static ::proto_ff::E_FestivalMuban_love_task* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_love_task(); }
		static ::proto_ff::E_FestivalMuban_love_task make_pbmsg(){ return ::proto_ff::E_FestivalMuban_love_task(); }
	};
	typedef struct E_FestivalMuban_love_task_s E_FestivalMuban_love_task_t;

	struct Sheet_FestivalMuban_love_task_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_love_task_s();
		virtual ~Sheet_FestivalMuban_love_task_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_love_task_s, DEFINE_SHEET_FESTIVALMUBAN_LOVE_TASK_E_FESTIVALMUBAN_LOVE_TASK_LIST_MAX_NUM> E_FestivalMuban_love_task_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_love_task & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_love_task & msg);
		static ::proto_ff::Sheet_FestivalMuban_love_task* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_love_task(); }
		static ::proto_ff::Sheet_FestivalMuban_love_task make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_love_task(); }
	};
	typedef struct Sheet_FestivalMuban_love_task_s Sheet_FestivalMuban_love_task_t;

	struct E_FestivalMuban_love_taskreward_s : public NFDescStoreSeqOP {
		E_FestivalMuban_love_taskreward_s();
		virtual ~E_FestivalMuban_love_taskreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//组id
		int32_t m_value;//进度值
		int32_t m_box;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_love_taskreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_love_taskreward & msg);
		static ::proto_ff::E_FestivalMuban_love_taskreward* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_love_taskreward(); }
		static ::proto_ff::E_FestivalMuban_love_taskreward make_pbmsg(){ return ::proto_ff::E_FestivalMuban_love_taskreward(); }
	};
	typedef struct E_FestivalMuban_love_taskreward_s E_FestivalMuban_love_taskreward_t;

	struct Sheet_FestivalMuban_love_taskreward_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_love_taskreward_s();
		virtual ~Sheet_FestivalMuban_love_taskreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_love_taskreward_s, DEFINE_SHEET_FESTIVALMUBAN_LOVE_TASKREWARD_E_FESTIVALMUBAN_LOVE_TASKREWARD_LIST_MAX_NUM> E_FestivalMuban_love_taskreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_love_taskreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_love_taskreward & msg);
		static ::proto_ff::Sheet_FestivalMuban_love_taskreward* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_love_taskreward(); }
		static ::proto_ff::Sheet_FestivalMuban_love_taskreward make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_love_taskreward(); }
	};
	typedef struct Sheet_FestivalMuban_love_taskreward_s Sheet_FestivalMuban_love_taskreward_t;

	struct E_FestivalMuban_addbox_s : public NFDescStoreSeqOP {
		E_FestivalMuban_addbox_s();
		virtual ~E_FestivalMuban_addbox_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_period;//期数
		int32_t m_lvLimit;//最低的怪物等级
		int32_t m_type;//类型
		NFShmString<64> m_arg;//参数
		int32_t m_addBoxId;//附加的boxid

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_addbox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_addbox & msg);
		static ::proto_ff::E_FestivalMuban_addbox* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_addbox(); }
		static ::proto_ff::E_FestivalMuban_addbox make_pbmsg(){ return ::proto_ff::E_FestivalMuban_addbox(); }
	};
	typedef struct E_FestivalMuban_addbox_s E_FestivalMuban_addbox_t;

	struct Sheet_FestivalMuban_addbox_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_addbox_s();
		virtual ~Sheet_FestivalMuban_addbox_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_addbox_s, DEFINE_SHEET_FESTIVALMUBAN_ADDBOX_E_FESTIVALMUBAN_ADDBOX_LIST_MAX_NUM> E_FestivalMuban_addbox_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_addbox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_addbox & msg);
		static ::proto_ff::Sheet_FestivalMuban_addbox* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_addbox(); }
		static ::proto_ff::Sheet_FestivalMuban_addbox make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_addbox(); }
	};
	typedef struct Sheet_FestivalMuban_addbox_s Sheet_FestivalMuban_addbox_t;

	struct E_FestivalMuban_doublebox_s : public NFDescStoreSeqOP {
		E_FestivalMuban_doublebox_s();
		virtual ~E_FestivalMuban_doublebox_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_period;//期数
		int32_t m_type;//类型
		NFShmString<64> m_arg;//类型参数
		int32_t m_multiply;//倍率

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_doublebox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_doublebox & msg);
		static ::proto_ff::E_FestivalMuban_doublebox* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_doublebox(); }
		static ::proto_ff::E_FestivalMuban_doublebox make_pbmsg(){ return ::proto_ff::E_FestivalMuban_doublebox(); }
	};
	typedef struct E_FestivalMuban_doublebox_s E_FestivalMuban_doublebox_t;

	struct Sheet_FestivalMuban_doublebox_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_doublebox_s();
		virtual ~Sheet_FestivalMuban_doublebox_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_doublebox_s, DEFINE_SHEET_FESTIVALMUBAN_DOUBLEBOX_E_FESTIVALMUBAN_DOUBLEBOX_LIST_MAX_NUM> E_FestivalMuban_doublebox_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_doublebox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_doublebox & msg);
		static ::proto_ff::Sheet_FestivalMuban_doublebox* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_doublebox(); }
		static ::proto_ff::Sheet_FestivalMuban_doublebox make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_doublebox(); }
	};
	typedef struct Sheet_FestivalMuban_doublebox_s Sheet_FestivalMuban_doublebox_t;

	struct E_FestivalMuban_bossfristkill_s : public NFDescStoreSeqOP {
		E_FestivalMuban_bossfristkill_s();
		virtual ~E_FestivalMuban_bossfristkill_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_type;//类型
		int32_t m_bossid;//bossid
		int32_t m_fristKillReward;//首杀奖励
		int32_t m_killReward;//击杀奖励
		int32_t m_fristKillPacket;//首杀红包

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_bossfristkill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_bossfristkill & msg);
		static ::proto_ff::E_FestivalMuban_bossfristkill* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_bossfristkill(); }
		static ::proto_ff::E_FestivalMuban_bossfristkill make_pbmsg(){ return ::proto_ff::E_FestivalMuban_bossfristkill(); }
	};
	typedef struct E_FestivalMuban_bossfristkill_s E_FestivalMuban_bossfristkill_t;

	struct Sheet_FestivalMuban_bossfristkill_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_bossfristkill_s();
		virtual ~Sheet_FestivalMuban_bossfristkill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_bossfristkill_s, DEFINE_SHEET_FESTIVALMUBAN_BOSSFRISTKILL_E_FESTIVALMUBAN_BOSSFRISTKILL_LIST_MAX_NUM> E_FestivalMuban_bossfristkill_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_bossfristkill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_bossfristkill & msg);
		static ::proto_ff::Sheet_FestivalMuban_bossfristkill* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_bossfristkill(); }
		static ::proto_ff::Sheet_FestivalMuban_bossfristkill make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_bossfristkill(); }
	};
	typedef struct Sheet_FestivalMuban_bossfristkill_s Sheet_FestivalMuban_bossfristkill_t;

	struct E_FestivalMuban_severrank_s : public NFDescStoreSeqOP {
		E_FestivalMuban_severrank_s();
		virtual ~E_FestivalMuban_severrank_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		NFShmString<64> m_order;//排序
		NFShmString<64> m_name;//名称
		int32_t m_openDay;//开放天数
		int32_t m_closeDay;//结束天数
		NFShmString<64> m_championTitle;//第一名的title
		NFShmString<64> m_rewardShow;//第一名的展示资源
		int32_t m_dataGroupID;//排行数据组id
		int32_t m_rankType;//排行类型
		NFShmString<64> m_rankGift;//冲榜宝箱名称
		NFShmString<64> m_giftIcon;//宝箱Icon
		int32_t m_giftItemId;//宝箱itemid
		int32_t m_originalPrice;//宝箱原价
		int32_t m_price;//宝箱现价
		int32_t m_ratioShow;//宝箱倍率
		int32_t m_redPointBox;//红点礼包奖励box

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_severrank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_severrank & msg);
		static ::proto_ff::E_FestivalMuban_severrank* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_severrank(); }
		static ::proto_ff::E_FestivalMuban_severrank make_pbmsg(){ return ::proto_ff::E_FestivalMuban_severrank(); }
	};
	typedef struct E_FestivalMuban_severrank_s E_FestivalMuban_severrank_t;

	struct Sheet_FestivalMuban_severrank_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_severrank_s();
		virtual ~Sheet_FestivalMuban_severrank_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_severrank_s, DEFINE_SHEET_FESTIVALMUBAN_SEVERRANK_E_FESTIVALMUBAN_SEVERRANK_LIST_MAX_NUM> E_FestivalMuban_severrank_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_severrank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_severrank & msg);
		static ::proto_ff::Sheet_FestivalMuban_severrank* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_severrank(); }
		static ::proto_ff::Sheet_FestivalMuban_severrank make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_severrank(); }
	};
	typedef struct Sheet_FestivalMuban_severrank_s Sheet_FestivalMuban_severrank_t;

	struct E_FestivalMuban_severrank_data_s : public NFDescStoreSeqOP {
		E_FestivalMuban_severrank_data_s();
		virtual ~E_FestivalMuban_severrank_data_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//组id
		int32_t m_maxRank;//排名上限
		int32_t m_minRank;//排名下限
		int32_t m_rankValue;//最低排行值数值要求
		int32_t m_addRankValue;//额外最低排行值数值要求
		NFShmString<64> m_UnachieveDisplay;//未满足的排行显示
		NFShmString<64> m_addUnachieveDisplay;//额外未满足的排行显示
		int32_t m_boxID;//奖励内容

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_severrank_data & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_severrank_data & msg);
		static ::proto_ff::E_FestivalMuban_severrank_data* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_severrank_data(); }
		static ::proto_ff::E_FestivalMuban_severrank_data make_pbmsg(){ return ::proto_ff::E_FestivalMuban_severrank_data(); }
	};
	typedef struct E_FestivalMuban_severrank_data_s E_FestivalMuban_severrank_data_t;

	struct Sheet_FestivalMuban_severrank_data_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_severrank_data_s();
		virtual ~Sheet_FestivalMuban_severrank_data_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_severrank_data_s, DEFINE_SHEET_FESTIVALMUBAN_SEVERRANK_DATA_E_FESTIVALMUBAN_SEVERRANK_DATA_LIST_MAX_NUM> E_FestivalMuban_severrank_data_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_severrank_data & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_severrank_data & msg);
		static ::proto_ff::Sheet_FestivalMuban_severrank_data* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_severrank_data(); }
		static ::proto_ff::Sheet_FestivalMuban_severrank_data make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_severrank_data(); }
	};
	typedef struct Sheet_FestivalMuban_severrank_data_s Sheet_FestivalMuban_severrank_data_t;

	struct E_FestivalMuban_collectwordCostDesc_s : public NFDescStoreSeqOP {
		E_FestivalMuban_collectwordCostDesc_s();
		virtual ~E_FestivalMuban_collectwordCostDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_collectwordCostDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_collectwordCostDesc & msg);
		static ::proto_ff::E_FestivalMuban_collectwordCostDesc* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_collectwordCostDesc(); }
		static ::proto_ff::E_FestivalMuban_collectwordCostDesc make_pbmsg(){ return ::proto_ff::E_FestivalMuban_collectwordCostDesc(); }
	};
	typedef struct E_FestivalMuban_collectwordCostDesc_s E_FestivalMuban_collectwordCostDesc_t;

	struct E_FestivalMuban_collectword_s : public NFDescStoreSeqOP {
		E_FestivalMuban_collectword_s();
		virtual ~E_FestivalMuban_collectword_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数id
		int32_t m_exchange_id;//兑换道具id
		int32_t m_exchange_num;//兑换道具数量
		int32_t m_times;//可兑换次数
		NFShmVector<struct E_FestivalMuban_collectwordCostDesc_s, DEFINE_E_FESTIVALMUBAN_COLLECTWORD_M_COST_MAX_NUM> m_cost;//花费

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_collectword & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_collectword & msg);
		static ::proto_ff::E_FestivalMuban_collectword* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_collectword(); }
		static ::proto_ff::E_FestivalMuban_collectword make_pbmsg(){ return ::proto_ff::E_FestivalMuban_collectword(); }
	};
	typedef struct E_FestivalMuban_collectword_s E_FestivalMuban_collectword_t;

	struct Sheet_FestivalMuban_collectword_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_collectword_s();
		virtual ~Sheet_FestivalMuban_collectword_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_collectword_s, DEFINE_SHEET_FESTIVALMUBAN_COLLECTWORD_E_FESTIVALMUBAN_COLLECTWORD_LIST_MAX_NUM> E_FestivalMuban_collectword_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_collectword & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_collectword & msg);
		static ::proto_ff::Sheet_FestivalMuban_collectword* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_collectword(); }
		static ::proto_ff::Sheet_FestivalMuban_collectword make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_collectword(); }
	};
	typedef struct Sheet_FestivalMuban_collectword_s Sheet_FestivalMuban_collectword_t;

	struct E_FestivalMuban_sign_s : public NFDescStoreSeqOP {
		E_FestivalMuban_sign_s();
		virtual ~E_FestivalMuban_sign_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_boxID;//礼包内容

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_sign & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_sign & msg);
		static ::proto_ff::E_FestivalMuban_sign* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_sign(); }
		static ::proto_ff::E_FestivalMuban_sign make_pbmsg(){ return ::proto_ff::E_FestivalMuban_sign(); }
	};
	typedef struct E_FestivalMuban_sign_s E_FestivalMuban_sign_t;

	struct Sheet_FestivalMuban_sign_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_sign_s();
		virtual ~Sheet_FestivalMuban_sign_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_sign_s, DEFINE_SHEET_FESTIVALMUBAN_SIGN_E_FESTIVALMUBAN_SIGN_LIST_MAX_NUM> E_FestivalMuban_sign_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_sign & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_sign & msg);
		static ::proto_ff::Sheet_FestivalMuban_sign* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_sign(); }
		static ::proto_ff::Sheet_FestivalMuban_sign make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_sign(); }
	};
	typedef struct Sheet_FestivalMuban_sign_s Sheet_FestivalMuban_sign_t;

	struct E_FestivalMuban_shop_s : public NFDescStoreSeqOP {
		E_FestivalMuban_shop_s();
		virtual ~E_FestivalMuban_shop_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_vipLevel;//判断vip等级
		int32_t m_box;//礼包内容
		int32_t m_timeLimit;//限购次数
		int32_t m_price;//价格参数
		int32_t m_priceType;//价格类型
		int32_t m_starTime;//礼包出现时间
		int32_t m_durTime;//持续时间

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_shop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_shop & msg);
		static ::proto_ff::E_FestivalMuban_shop* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_shop(); }
		static ::proto_ff::E_FestivalMuban_shop make_pbmsg(){ return ::proto_ff::E_FestivalMuban_shop(); }
	};
	typedef struct E_FestivalMuban_shop_s E_FestivalMuban_shop_t;

	struct Sheet_FestivalMuban_shop_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_shop_s();
		virtual ~Sheet_FestivalMuban_shop_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_shop_s, DEFINE_SHEET_FESTIVALMUBAN_SHOP_E_FESTIVALMUBAN_SHOP_LIST_MAX_NUM> E_FestivalMuban_shop_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_shop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_shop & msg);
		static ::proto_ff::Sheet_FestivalMuban_shop* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_shop(); }
		static ::proto_ff::Sheet_FestivalMuban_shop make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_shop(); }
	};
	typedef struct Sheet_FestivalMuban_shop_s Sheet_FestivalMuban_shop_t;

	struct E_FestivalMuban_rechange_s : public NFDescStoreSeqOP {
		E_FestivalMuban_rechange_s();
		virtual ~E_FestivalMuban_rechange_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_rebate;//返利
		int32_t m_timeLimit;//限购次数
		int32_t m_price;//价格参数
		int32_t m_typer;//礼包类型

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_rechange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rechange & msg);
		static ::proto_ff::E_FestivalMuban_rechange* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_rechange(); }
		static ::proto_ff::E_FestivalMuban_rechange make_pbmsg(){ return ::proto_ff::E_FestivalMuban_rechange(); }
	};
	typedef struct E_FestivalMuban_rechange_s E_FestivalMuban_rechange_t;

	struct Sheet_FestivalMuban_rechange_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_rechange_s();
		virtual ~Sheet_FestivalMuban_rechange_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_rechange_s, DEFINE_SHEET_FESTIVALMUBAN_RECHANGE_E_FESTIVALMUBAN_RECHANGE_LIST_MAX_NUM> E_FestivalMuban_rechange_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_rechange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_rechange & msg);
		static ::proto_ff::Sheet_FestivalMuban_rechange* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_rechange(); }
		static ::proto_ff::Sheet_FestivalMuban_rechange make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_rechange(); }
	};
	typedef struct Sheet_FestivalMuban_rechange_s Sheet_FestivalMuban_rechange_t;

	struct E_FestivalMuban_leiji_s : public NFDescStoreSeqOP {
		E_FestivalMuban_leiji_s();
		virtual ~E_FestivalMuban_leiji_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_leiji;//伤害累计
		int32_t m_boxID;//奖励ID

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_leiji & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_leiji & msg);
		static ::proto_ff::E_FestivalMuban_leiji* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_leiji(); }
		static ::proto_ff::E_FestivalMuban_leiji make_pbmsg(){ return ::proto_ff::E_FestivalMuban_leiji(); }
	};
	typedef struct E_FestivalMuban_leiji_s E_FestivalMuban_leiji_t;

	struct Sheet_FestivalMuban_leiji_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_leiji_s();
		virtual ~Sheet_FestivalMuban_leiji_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_leiji_s, DEFINE_SHEET_FESTIVALMUBAN_LEIJI_E_FESTIVALMUBAN_LEIJI_LIST_MAX_NUM> E_FestivalMuban_leiji_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_leiji & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_leiji & msg);
		static ::proto_ff::Sheet_FestivalMuban_leiji* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_leiji(); }
		static ::proto_ff::Sheet_FestivalMuban_leiji make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_leiji(); }
	};
	typedef struct Sheet_FestivalMuban_leiji_s Sheet_FestivalMuban_leiji_t;

	struct E_FestivalZadanconstant_s : public NFDescStoreSeqOP {
		E_FestivalZadanconstant_s();
		virtual ~E_FestivalZadanconstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_period;//期数
		int64_t m_costItem;//抽奖消耗的物id
		int32_t m_number;//物品数量
		int32_t m_free;//免费重置次数
		int32_t m_currency;//消耗钻石重置

		virtual void write_to_pbmsg(::proto_ff::E_FestivalZadanconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalZadanconstant & msg);
		static ::proto_ff::E_FestivalZadanconstant* new_pbmsg(){ return new ::proto_ff::E_FestivalZadanconstant(); }
		static ::proto_ff::E_FestivalZadanconstant make_pbmsg(){ return ::proto_ff::E_FestivalZadanconstant(); }
	};
	typedef struct E_FestivalZadanconstant_s E_FestivalZadanconstant_t;

	struct Sheet_FestivalZadanconstant_s : public NFDescStoreSeqOP {
		Sheet_FestivalZadanconstant_s();
		virtual ~Sheet_FestivalZadanconstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalZadanconstant_s, DEFINE_SHEET_FESTIVALZADANCONSTANT_E_FESTIVALZADANCONSTANT_LIST_MAX_NUM> E_FestivalZadanconstant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalZadanconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalZadanconstant & msg);
		static ::proto_ff::Sheet_FestivalZadanconstant* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalZadanconstant(); }
		static ::proto_ff::Sheet_FestivalZadanconstant make_pbmsg(){ return ::proto_ff::Sheet_FestivalZadanconstant(); }
	};
	typedef struct Sheet_FestivalZadanconstant_s Sheet_FestivalZadanconstant_t;

	struct E_FestivalMuban_zadan_s : public NFDescStoreSeqOP {
		E_FestivalMuban_zadan_s();
		virtual ~E_FestivalMuban_zadan_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int64_t m_itemid;//物品
		int32_t m_num;//数量
		int32_t m_type;//奖池类型
		int32_t m_probability;//掉落权重

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_zadan & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_zadan & msg);
		static ::proto_ff::E_FestivalMuban_zadan* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_zadan(); }
		static ::proto_ff::E_FestivalMuban_zadan make_pbmsg(){ return ::proto_ff::E_FestivalMuban_zadan(); }
	};
	typedef struct E_FestivalMuban_zadan_s E_FestivalMuban_zadan_t;

	struct Sheet_FestivalMuban_zadan_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_zadan_s();
		virtual ~Sheet_FestivalMuban_zadan_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_zadan_s, DEFINE_SHEET_FESTIVALMUBAN_ZADAN_E_FESTIVALMUBAN_ZADAN_LIST_MAX_NUM> E_FestivalMuban_zadan_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_zadan & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_zadan & msg);
		static ::proto_ff::Sheet_FestivalMuban_zadan* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_zadan(); }
		static ::proto_ff::Sheet_FestivalMuban_zadan make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_zadan(); }
	};
	typedef struct Sheet_FestivalMuban_zadan_s Sheet_FestivalMuban_zadan_t;

	struct E_FestivalMuban_turntable_s : public NFDescStoreSeqOP {
		E_FestivalMuban_turntable_s();
		virtual ~E_FestivalMuban_turntable_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_poolGroup;//奖池组
		int32_t m_taskGroup;//任务组

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_turntable & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_turntable & msg);
		static ::proto_ff::E_FestivalMuban_turntable* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_turntable(); }
		static ::proto_ff::E_FestivalMuban_turntable make_pbmsg(){ return ::proto_ff::E_FestivalMuban_turntable(); }
	};
	typedef struct E_FestivalMuban_turntable_s E_FestivalMuban_turntable_t;

	struct Sheet_FestivalMuban_turntable_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_turntable_s();
		virtual ~Sheet_FestivalMuban_turntable_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_turntable_s, DEFINE_SHEET_FESTIVALMUBAN_TURNTABLE_E_FESTIVALMUBAN_TURNTABLE_LIST_MAX_NUM> E_FestivalMuban_turntable_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_turntable & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_turntable & msg);
		static ::proto_ff::Sheet_FestivalMuban_turntable* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_turntable(); }
		static ::proto_ff::Sheet_FestivalMuban_turntable make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_turntable(); }
	};
	typedef struct Sheet_FestivalMuban_turntable_s Sheet_FestivalMuban_turntable_t;

	struct E_FestivalMuban_turntable_pool_s : public NFDescStoreSeqOP {
		E_FestivalMuban_turntable_pool_s();
		virtual ~E_FestivalMuban_turntable_pool_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//组ID
		int32_t m_itemID;//物品
		int32_t m_num;//数量
		int32_t m_weight;//权重

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_turntable_pool & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_turntable_pool & msg);
		static ::proto_ff::E_FestivalMuban_turntable_pool* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_turntable_pool(); }
		static ::proto_ff::E_FestivalMuban_turntable_pool make_pbmsg(){ return ::proto_ff::E_FestivalMuban_turntable_pool(); }
	};
	typedef struct E_FestivalMuban_turntable_pool_s E_FestivalMuban_turntable_pool_t;

	struct Sheet_FestivalMuban_turntable_pool_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_turntable_pool_s();
		virtual ~Sheet_FestivalMuban_turntable_pool_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_turntable_pool_s, DEFINE_SHEET_FESTIVALMUBAN_TURNTABLE_POOL_E_FESTIVALMUBAN_TURNTABLE_POOL_LIST_MAX_NUM> E_FestivalMuban_turntable_pool_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_turntable_pool & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_turntable_pool & msg);
		static ::proto_ff::Sheet_FestivalMuban_turntable_pool* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_turntable_pool(); }
		static ::proto_ff::Sheet_FestivalMuban_turntable_pool make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_turntable_pool(); }
	};
	typedef struct Sheet_FestivalMuban_turntable_pool_s Sheet_FestivalMuban_turntable_pool_t;

	struct E_FestivalMuban_turntable_task_s : public NFDescStoreSeqOP {
		E_FestivalMuban_turntable_task_s();
		virtual ~E_FestivalMuban_turntable_task_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//组id
		int32_t m_eventType;//事件类型
		int32_t m_reachPrice;//达成值
		int32_t m_link;//连接
		int32_t m_rewardTimes;//奖励次数
		NFShmVector<int32_t, DEFINE_E_FESTIVALMUBAN_TURNTABLE_TASK_M_PARAM_MAX_NUM> m_param;//事件完成参数

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_turntable_task & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_turntable_task & msg);
		static ::proto_ff::E_FestivalMuban_turntable_task* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_turntable_task(); }
		static ::proto_ff::E_FestivalMuban_turntable_task make_pbmsg(){ return ::proto_ff::E_FestivalMuban_turntable_task(); }
	};
	typedef struct E_FestivalMuban_turntable_task_s E_FestivalMuban_turntable_task_t;

	struct Sheet_FestivalMuban_turntable_task_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_turntable_task_s();
		virtual ~Sheet_FestivalMuban_turntable_task_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_turntable_task_s, DEFINE_SHEET_FESTIVALMUBAN_TURNTABLE_TASK_E_FESTIVALMUBAN_TURNTABLE_TASK_LIST_MAX_NUM> E_FestivalMuban_turntable_task_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_turntable_task & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_turntable_task & msg);
		static ::proto_ff::Sheet_FestivalMuban_turntable_task* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_turntable_task(); }
		static ::proto_ff::Sheet_FestivalMuban_turntable_task make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_turntable_task(); }
	};
	typedef struct Sheet_FestivalMuban_turntable_task_s Sheet_FestivalMuban_turntable_task_t;

	struct E_FestivalMuban_donate_s : public NFDescStoreSeqOP {
		E_FestivalMuban_donate_s();
		virtual ~E_FestivalMuban_donate_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_donateItem;//捐献道具
		int32_t m_donateReward;//捐献获得奖励
		int32_t m_severReward;//服务器奖励组
		int32_t m_singleReward;//个人奖励组
		int32_t m_taskGroupID;//任务组

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_donate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_donate & msg);
		static ::proto_ff::E_FestivalMuban_donate* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_donate(); }
		static ::proto_ff::E_FestivalMuban_donate make_pbmsg(){ return ::proto_ff::E_FestivalMuban_donate(); }
	};
	typedef struct E_FestivalMuban_donate_s E_FestivalMuban_donate_t;

	struct Sheet_FestivalMuban_donate_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_donate_s();
		virtual ~Sheet_FestivalMuban_donate_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_donate_s, DEFINE_SHEET_FESTIVALMUBAN_DONATE_E_FESTIVALMUBAN_DONATE_LIST_MAX_NUM> E_FestivalMuban_donate_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_donate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_donate & msg);
		static ::proto_ff::Sheet_FestivalMuban_donate* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_donate(); }
		static ::proto_ff::Sheet_FestivalMuban_donate make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_donate(); }
	};
	typedef struct Sheet_FestivalMuban_donate_s Sheet_FestivalMuban_donate_t;

	struct E_FestivalMuban_donate_sever_s : public NFDescStoreSeqOP {
		E_FestivalMuban_donate_sever_s();
		virtual ~E_FestivalMuban_donate_sever_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//组id
		int32_t m_value;//进度值
		int32_t m_type;//奖励类型
		NFShmString<64> m_typeArg;//奖励参数
		NFShmString<64> m_pro;//职业
		int32_t m_num;//数量

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_donate_sever & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_donate_sever & msg);
		static ::proto_ff::E_FestivalMuban_donate_sever* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_donate_sever(); }
		static ::proto_ff::E_FestivalMuban_donate_sever make_pbmsg(){ return ::proto_ff::E_FestivalMuban_donate_sever(); }
	};
	typedef struct E_FestivalMuban_donate_sever_s E_FestivalMuban_donate_sever_t;

	struct Sheet_FestivalMuban_donate_sever_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_donate_sever_s();
		virtual ~Sheet_FestivalMuban_donate_sever_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_donate_sever_s, DEFINE_SHEET_FESTIVALMUBAN_DONATE_SEVER_E_FESTIVALMUBAN_DONATE_SEVER_LIST_MAX_NUM> E_FestivalMuban_donate_sever_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_donate_sever & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_donate_sever & msg);
		static ::proto_ff::Sheet_FestivalMuban_donate_sever* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_donate_sever(); }
		static ::proto_ff::Sheet_FestivalMuban_donate_sever make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_donate_sever(); }
	};
	typedef struct Sheet_FestivalMuban_donate_sever_s Sheet_FestivalMuban_donate_sever_t;

	struct E_FestivalMuban_donate_single_s : public NFDescStoreSeqOP {
		E_FestivalMuban_donate_single_s();
		virtual ~E_FestivalMuban_donate_single_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//组id
		int32_t m_value;//进度值
		NFShmString<64> m_itemID;//物品ID
		NFShmString<64> m_pro;//职业
		int32_t m_num;//数量

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_donate_single & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_donate_single & msg);
		static ::proto_ff::E_FestivalMuban_donate_single* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_donate_single(); }
		static ::proto_ff::E_FestivalMuban_donate_single make_pbmsg(){ return ::proto_ff::E_FestivalMuban_donate_single(); }
	};
	typedef struct E_FestivalMuban_donate_single_s E_FestivalMuban_donate_single_t;

	struct Sheet_FestivalMuban_donate_single_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_donate_single_s();
		virtual ~Sheet_FestivalMuban_donate_single_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_donate_single_s, DEFINE_SHEET_FESTIVALMUBAN_DONATE_SINGLE_E_FESTIVALMUBAN_DONATE_SINGLE_LIST_MAX_NUM> E_FestivalMuban_donate_single_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_donate_single & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_donate_single & msg);
		static ::proto_ff::Sheet_FestivalMuban_donate_single* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_donate_single(); }
		static ::proto_ff::Sheet_FestivalMuban_donate_single make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_donate_single(); }
	};
	typedef struct Sheet_FestivalMuban_donate_single_s Sheet_FestivalMuban_donate_single_t;

	struct E_FestivalMuban_donate_task_s : public NFDescStoreSeqOP {
		E_FestivalMuban_donate_task_s();
		virtual ~E_FestivalMuban_donate_task_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//组id
		int32_t m_eventType;//事件类型
		int32_t m_reachPrice;//达成值
		int32_t m_itemID;//奖励道具id
		int32_t m_itemNum;//奖励道具数量
		NFShmVector<int32_t, DEFINE_E_FESTIVALMUBAN_DONATE_TASK_M_PARAM_MAX_NUM> m_param;//事件完成参数

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_donate_task & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_donate_task & msg);
		static ::proto_ff::E_FestivalMuban_donate_task* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_donate_task(); }
		static ::proto_ff::E_FestivalMuban_donate_task make_pbmsg(){ return ::proto_ff::E_FestivalMuban_donate_task(); }
	};
	typedef struct E_FestivalMuban_donate_task_s E_FestivalMuban_donate_task_t;

	struct Sheet_FestivalMuban_donate_task_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_donate_task_s();
		virtual ~Sheet_FestivalMuban_donate_task_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_donate_task_s, DEFINE_SHEET_FESTIVALMUBAN_DONATE_TASK_E_FESTIVALMUBAN_DONATE_TASK_LIST_MAX_NUM> E_FestivalMuban_donate_task_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_donate_task & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_donate_task & msg);
		static ::proto_ff::Sheet_FestivalMuban_donate_task* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_donate_task(); }
		static ::proto_ff::Sheet_FestivalMuban_donate_task make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_donate_task(); }
	};
	typedef struct Sheet_FestivalMuban_donate_task_s Sheet_FestivalMuban_donate_task_t;

	struct E_FestivalMuban_online_s : public NFDescStoreSeqOP {
		E_FestivalMuban_online_s();
		virtual ~E_FestivalMuban_online_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		NFShmString<64> m_timeStart;//开始时间
		NFShmString<64> m_timeEnd;//结束时间
		int32_t m_itemID;//奖励道具
		int32_t m_itemNum;//奖励数量
		int32_t m_vip;//补领要求vip等级

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_online & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_online & msg);
		static ::proto_ff::E_FestivalMuban_online* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_online(); }
		static ::proto_ff::E_FestivalMuban_online make_pbmsg(){ return ::proto_ff::E_FestivalMuban_online(); }
	};
	typedef struct E_FestivalMuban_online_s E_FestivalMuban_online_t;

	struct Sheet_FestivalMuban_online_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_online_s();
		virtual ~Sheet_FestivalMuban_online_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_online_s, DEFINE_SHEET_FESTIVALMUBAN_ONLINE_E_FESTIVALMUBAN_ONLINE_LIST_MAX_NUM> E_FestivalMuban_online_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_online & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_online & msg);
		static ::proto_ff::Sheet_FestivalMuban_online* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_online(); }
		static ::proto_ff::Sheet_FestivalMuban_online make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_online(); }
	};
	typedef struct Sheet_FestivalMuban_online_s Sheet_FestivalMuban_online_t;

	struct E_FestivalMuban_rturntable_s : public NFDescStoreSeqOP {
		E_FestivalMuban_rturntable_s();
		virtual ~E_FestivalMuban_rturntable_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_rechargeGroupID;//充值组ID

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_rturntable & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rturntable & msg);
		static ::proto_ff::E_FestivalMuban_rturntable* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_rturntable(); }
		static ::proto_ff::E_FestivalMuban_rturntable make_pbmsg(){ return ::proto_ff::E_FestivalMuban_rturntable(); }
	};
	typedef struct E_FestivalMuban_rturntable_s E_FestivalMuban_rturntable_t;

	struct Sheet_FestivalMuban_rturntable_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_rturntable_s();
		virtual ~Sheet_FestivalMuban_rturntable_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_rturntable_s, DEFINE_SHEET_FESTIVALMUBAN_RTURNTABLE_E_FESTIVALMUBAN_RTURNTABLE_LIST_MAX_NUM> E_FestivalMuban_rturntable_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_rturntable & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_rturntable & msg);
		static ::proto_ff::Sheet_FestivalMuban_rturntable* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_rturntable(); }
		static ::proto_ff::Sheet_FestivalMuban_rturntable make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_rturntable(); }
	};
	typedef struct Sheet_FestivalMuban_rturntable_s Sheet_FestivalMuban_rturntable_t;

	struct E_FestivalMuban_rturntable_recharge_s : public NFDescStoreSeqOP {
		E_FestivalMuban_rturntable_recharge_s();
		virtual ~E_FestivalMuban_rturntable_recharge_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//组
		int32_t m_rechargeID;//充值档位
		int32_t m_limit;//限制次数
		int32_t m_ratioGroupID;//使用充值倍率组

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_rturntable_recharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rturntable_recharge & msg);
		static ::proto_ff::E_FestivalMuban_rturntable_recharge* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_rturntable_recharge(); }
		static ::proto_ff::E_FestivalMuban_rturntable_recharge make_pbmsg(){ return ::proto_ff::E_FestivalMuban_rturntable_recharge(); }
	};
	typedef struct E_FestivalMuban_rturntable_recharge_s E_FestivalMuban_rturntable_recharge_t;

	struct Sheet_FestivalMuban_rturntable_recharge_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_rturntable_recharge_s();
		virtual ~Sheet_FestivalMuban_rturntable_recharge_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_rturntable_recharge_s, DEFINE_SHEET_FESTIVALMUBAN_RTURNTABLE_RECHARGE_E_FESTIVALMUBAN_RTURNTABLE_RECHARGE_LIST_MAX_NUM> E_FestivalMuban_rturntable_recharge_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_rturntable_recharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_rturntable_recharge & msg);
		static ::proto_ff::Sheet_FestivalMuban_rturntable_recharge* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_rturntable_recharge(); }
		static ::proto_ff::Sheet_FestivalMuban_rturntable_recharge make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_rturntable_recharge(); }
	};
	typedef struct Sheet_FestivalMuban_rturntable_recharge_s Sheet_FestivalMuban_rturntable_recharge_t;

	struct E_FestivalMuban_rturntable_recharge_ratio_s : public NFDescStoreSeqOP {
		E_FestivalMuban_rturntable_recharge_ratio_s();
		virtual ~E_FestivalMuban_rturntable_recharge_ratio_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//组
		int32_t m_ratio;//倍率
		int32_t m_weight;//权重

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_rturntable_recharge_ratio & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rturntable_recharge_ratio & msg);
		static ::proto_ff::E_FestivalMuban_rturntable_recharge_ratio* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_rturntable_recharge_ratio(); }
		static ::proto_ff::E_FestivalMuban_rturntable_recharge_ratio make_pbmsg(){ return ::proto_ff::E_FestivalMuban_rturntable_recharge_ratio(); }
	};
	typedef struct E_FestivalMuban_rturntable_recharge_ratio_s E_FestivalMuban_rturntable_recharge_ratio_t;

	struct Sheet_FestivalMuban_rturntable_recharge_ratio_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_rturntable_recharge_ratio_s();
		virtual ~Sheet_FestivalMuban_rturntable_recharge_ratio_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_rturntable_recharge_ratio_s, DEFINE_SHEET_FESTIVALMUBAN_RTURNTABLE_RECHARGE_RATIO_E_FESTIVALMUBAN_RTURNTABLE_RECHARGE_RATIO_LIST_MAX_NUM> E_FestivalMuban_rturntable_recharge_ratio_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_rturntable_recharge_ratio & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_rturntable_recharge_ratio & msg);
		static ::proto_ff::Sheet_FestivalMuban_rturntable_recharge_ratio* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_rturntable_recharge_ratio(); }
		static ::proto_ff::Sheet_FestivalMuban_rturntable_recharge_ratio make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_rturntable_recharge_ratio(); }
	};
	typedef struct Sheet_FestivalMuban_rturntable_recharge_ratio_s Sheet_FestivalMuban_rturntable_recharge_ratio_t;

	struct E_FestivalMuban_drawpize_s : public NFDescStoreSeqOP {
		E_FestivalMuban_drawpize_s();
		virtual ~E_FestivalMuban_drawpize_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_costID;//道具id
		int32_t m_drawPutback;//是否放回
		int32_t m_costType;//消耗类型
		NFShmString<64> m_costNum;//抽奖消耗
		int32_t m_poolGroupId;//奖池id
		int32_t m_totalGroupID;//累计次数奖励id
		int32_t m_severLimit;//全服次数限制
		int32_t m_protectTime;//保底奖池次数

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_drawpize & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_drawpize & msg);
		static ::proto_ff::E_FestivalMuban_drawpize* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_drawpize(); }
		static ::proto_ff::E_FestivalMuban_drawpize make_pbmsg(){ return ::proto_ff::E_FestivalMuban_drawpize(); }
	};
	typedef struct E_FestivalMuban_drawpize_s E_FestivalMuban_drawpize_t;

	struct Sheet_FestivalMuban_drawpize_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_drawpize_s();
		virtual ~Sheet_FestivalMuban_drawpize_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_drawpize_s, DEFINE_SHEET_FESTIVALMUBAN_DRAWPIZE_E_FESTIVALMUBAN_DRAWPIZE_LIST_MAX_NUM> E_FestivalMuban_drawpize_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_drawpize & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_drawpize & msg);
		static ::proto_ff::Sheet_FestivalMuban_drawpize* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_drawpize(); }
		static ::proto_ff::Sheet_FestivalMuban_drawpize make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_drawpize(); }
	};
	typedef struct Sheet_FestivalMuban_drawpize_s Sheet_FestivalMuban_drawpize_t;

	struct E_FestivalMuban_drawpize_pool_s : public NFDescStoreSeqOP {
		E_FestivalMuban_drawpize_pool_s();
		virtual ~E_FestivalMuban_drawpize_pool_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//奖池组ID
		int64_t m_itemid;//物品
		int32_t m_num;//数量
		int32_t m_prof;//职业
		int32_t m_weights;//掉落权重
		int32_t m_proWeights;//保底掉落权重
		int32_t m_timeLimit;//限制抽奖次数
		int32_t m_Record;//奖励记录稀有度
		int32_t m_poolLv;//奖池等级
		NFShmString<64> m_image;//底图
		NFShmString<64> m_point;//坐标

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_drawpize_pool & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_drawpize_pool & msg);
		static ::proto_ff::E_FestivalMuban_drawpize_pool* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_drawpize_pool(); }
		static ::proto_ff::E_FestivalMuban_drawpize_pool make_pbmsg(){ return ::proto_ff::E_FestivalMuban_drawpize_pool(); }
	};
	typedef struct E_FestivalMuban_drawpize_pool_s E_FestivalMuban_drawpize_pool_t;

	struct Sheet_FestivalMuban_drawpize_pool_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_drawpize_pool_s();
		virtual ~Sheet_FestivalMuban_drawpize_pool_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_drawpize_pool_s, DEFINE_SHEET_FESTIVALMUBAN_DRAWPIZE_POOL_E_FESTIVALMUBAN_DRAWPIZE_POOL_LIST_MAX_NUM> E_FestivalMuban_drawpize_pool_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_drawpize_pool & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_drawpize_pool & msg);
		static ::proto_ff::Sheet_FestivalMuban_drawpize_pool* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_drawpize_pool(); }
		static ::proto_ff::Sheet_FestivalMuban_drawpize_pool make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_drawpize_pool(); }
	};
	typedef struct Sheet_FestivalMuban_drawpize_pool_s Sheet_FestivalMuban_drawpize_pool_t;

	struct E_FestivalMuban_drawpize_total_s : public NFDescStoreSeqOP {
		E_FestivalMuban_drawpize_total_s();
		virtual ~E_FestivalMuban_drawpize_total_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupid;//组id
		int32_t m_value;//条件值
		int32_t m_itemID;//奖励道具id
		int32_t m_num;//奖励道具数量

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_drawpize_total & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_drawpize_total & msg);
		static ::proto_ff::E_FestivalMuban_drawpize_total* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_drawpize_total(); }
		static ::proto_ff::E_FestivalMuban_drawpize_total make_pbmsg(){ return ::proto_ff::E_FestivalMuban_drawpize_total(); }
	};
	typedef struct E_FestivalMuban_drawpize_total_s E_FestivalMuban_drawpize_total_t;

	struct Sheet_FestivalMuban_drawpize_total_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_drawpize_total_s();
		virtual ~Sheet_FestivalMuban_drawpize_total_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_drawpize_total_s, DEFINE_SHEET_FESTIVALMUBAN_DRAWPIZE_TOTAL_E_FESTIVALMUBAN_DRAWPIZE_TOTAL_LIST_MAX_NUM> E_FestivalMuban_drawpize_total_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_drawpize_total & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_drawpize_total & msg);
		static ::proto_ff::Sheet_FestivalMuban_drawpize_total* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_drawpize_total(); }
		static ::proto_ff::Sheet_FestivalMuban_drawpize_total make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_drawpize_total(); }
	};
	typedef struct Sheet_FestivalMuban_drawpize_total_s Sheet_FestivalMuban_drawpize_total_t;

	struct E_FestivalMuban_totalrecharge_s : public NFDescStoreSeqOP {
		E_FestivalMuban_totalrecharge_s();
		virtual ~E_FestivalMuban_totalrecharge_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_value;//充值额度
		int32_t m_boxid;//奖励内容

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_totalrecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_totalrecharge & msg);
		static ::proto_ff::E_FestivalMuban_totalrecharge* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_totalrecharge(); }
		static ::proto_ff::E_FestivalMuban_totalrecharge make_pbmsg(){ return ::proto_ff::E_FestivalMuban_totalrecharge(); }
	};
	typedef struct E_FestivalMuban_totalrecharge_s E_FestivalMuban_totalrecharge_t;

	struct Sheet_FestivalMuban_totalrecharge_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_totalrecharge_s();
		virtual ~Sheet_FestivalMuban_totalrecharge_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_totalrecharge_s, DEFINE_SHEET_FESTIVALMUBAN_TOTALRECHARGE_E_FESTIVALMUBAN_TOTALRECHARGE_LIST_MAX_NUM> E_FestivalMuban_totalrecharge_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_totalrecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_totalrecharge & msg);
		static ::proto_ff::Sheet_FestivalMuban_totalrecharge* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_totalrecharge(); }
		static ::proto_ff::Sheet_FestivalMuban_totalrecharge make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_totalrecharge(); }
	};
	typedef struct Sheet_FestivalMuban_totalrecharge_s Sheet_FestivalMuban_totalrecharge_t;

	struct E_FestivalMuban_dailytotalrecharge_s : public NFDescStoreSeqOP {
		E_FestivalMuban_dailytotalrecharge_s();
		virtual ~E_FestivalMuban_dailytotalrecharge_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_value;//充值额度
		int32_t m_boxid;//奖励内容

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_dailytotalrecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_dailytotalrecharge & msg);
		static ::proto_ff::E_FestivalMuban_dailytotalrecharge* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_dailytotalrecharge(); }
		static ::proto_ff::E_FestivalMuban_dailytotalrecharge make_pbmsg(){ return ::proto_ff::E_FestivalMuban_dailytotalrecharge(); }
	};
	typedef struct E_FestivalMuban_dailytotalrecharge_s E_FestivalMuban_dailytotalrecharge_t;

	struct Sheet_FestivalMuban_dailytotalrecharge_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_dailytotalrecharge_s();
		virtual ~Sheet_FestivalMuban_dailytotalrecharge_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_dailytotalrecharge_s, DEFINE_SHEET_FESTIVALMUBAN_DAILYTOTALRECHARGE_E_FESTIVALMUBAN_DAILYTOTALRECHARGE_LIST_MAX_NUM> E_FestivalMuban_dailytotalrecharge_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_dailytotalrecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_dailytotalrecharge & msg);
		static ::proto_ff::Sheet_FestivalMuban_dailytotalrecharge* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_dailytotalrecharge(); }
		static ::proto_ff::Sheet_FestivalMuban_dailytotalrecharge make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_dailytotalrecharge(); }
	};
	typedef struct Sheet_FestivalMuban_dailytotalrecharge_s Sheet_FestivalMuban_dailytotalrecharge_t;

	struct E_FestivalMuban_rechargeprize_s : public NFDescStoreSeqOP {
		E_FestivalMuban_rechargeprize_s();
		virtual ~E_FestivalMuban_rechargeprize_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_poolType;//奖池类型
		int32_t m_poolNum;//奖品数量
		int32_t m_showBoost;//显示倍率
		int32_t m_maxPrize;//最大抽取次数
		int32_t m_taskID;//任务组ID
		int32_t m_prizeID;//抽奖组ID
		int32_t m_itemID;//抽奖道具id
		int32_t m_freeBox;//免费奖励

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_rechargeprize & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rechargeprize & msg);
		static ::proto_ff::E_FestivalMuban_rechargeprize* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_rechargeprize(); }
		static ::proto_ff::E_FestivalMuban_rechargeprize make_pbmsg(){ return ::proto_ff::E_FestivalMuban_rechargeprize(); }
	};
	typedef struct E_FestivalMuban_rechargeprize_s E_FestivalMuban_rechargeprize_t;

	struct Sheet_FestivalMuban_rechargeprize_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_rechargeprize_s();
		virtual ~Sheet_FestivalMuban_rechargeprize_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_rechargeprize_s, DEFINE_SHEET_FESTIVALMUBAN_RECHARGEPRIZE_E_FESTIVALMUBAN_RECHARGEPRIZE_LIST_MAX_NUM> E_FestivalMuban_rechargeprize_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_rechargeprize & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_rechargeprize & msg);
		static ::proto_ff::Sheet_FestivalMuban_rechargeprize* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_rechargeprize(); }
		static ::proto_ff::Sheet_FestivalMuban_rechargeprize make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_rechargeprize(); }
	};
	typedef struct Sheet_FestivalMuban_rechargeprize_s Sheet_FestivalMuban_rechargeprize_t;

	struct E_FestivalMuban_rptask_s : public NFDescStoreSeqOP {
		E_FestivalMuban_rptask_s();
		virtual ~E_FestivalMuban_rptask_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//id组
		int32_t m_type;//任务类型
		NFShmString<64> m_typeArg;//任务参数
		int32_t m_prizeNum;//奖励次数
		NFShmString<64> m_desc;//文本描述
		int32_t m_link;//连接

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_rptask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rptask & msg);
		static ::proto_ff::E_FestivalMuban_rptask* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_rptask(); }
		static ::proto_ff::E_FestivalMuban_rptask make_pbmsg(){ return ::proto_ff::E_FestivalMuban_rptask(); }
	};
	typedef struct E_FestivalMuban_rptask_s E_FestivalMuban_rptask_t;

	struct Sheet_FestivalMuban_rptask_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_rptask_s();
		virtual ~Sheet_FestivalMuban_rptask_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_rptask_s, DEFINE_SHEET_FESTIVALMUBAN_RPTASK_E_FESTIVALMUBAN_RPTASK_LIST_MAX_NUM> E_FestivalMuban_rptask_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_rptask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_rptask & msg);
		static ::proto_ff::Sheet_FestivalMuban_rptask* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_rptask(); }
		static ::proto_ff::Sheet_FestivalMuban_rptask make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_rptask(); }
	};
	typedef struct Sheet_FestivalMuban_rptask_s Sheet_FestivalMuban_rptask_t;

	struct E_FestivalMuban_rppool_s : public NFDescStoreSeqOP {
		E_FestivalMuban_rppool_s();
		virtual ~E_FestivalMuban_rppool_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//id组
		int32_t m_prizeOrder;//抽奖顺序
		int32_t m_prizeMix;//抽取最小值
		int32_t m_prizeMax;//抽取最大值

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_rppool & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rppool & msg);
		static ::proto_ff::E_FestivalMuban_rppool* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_rppool(); }
		static ::proto_ff::E_FestivalMuban_rppool make_pbmsg(){ return ::proto_ff::E_FestivalMuban_rppool(); }
	};
	typedef struct E_FestivalMuban_rppool_s E_FestivalMuban_rppool_t;

	struct Sheet_FestivalMuban_rppool_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_rppool_s();
		virtual ~Sheet_FestivalMuban_rppool_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_rppool_s, DEFINE_SHEET_FESTIVALMUBAN_RPPOOL_E_FESTIVALMUBAN_RPPOOL_LIST_MAX_NUM> E_FestivalMuban_rppool_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_rppool & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_rppool & msg);
		static ::proto_ff::Sheet_FestivalMuban_rppool* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_rppool(); }
		static ::proto_ff::Sheet_FestivalMuban_rppool make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_rppool(); }
	};
	typedef struct Sheet_FestivalMuban_rppool_s Sheet_FestivalMuban_rppool_t;

	struct E_FestivalMuban_play_s : public NFDescStoreSeqOP {
		E_FestivalMuban_play_s();
		virtual ~E_FestivalMuban_play_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_period;//期数
		int32_t m_rewardGroup;//奖励组
		int32_t m_gameGroup;//玩法组
		NFShmVector<NFShmString<64>, DEFINE_E_FESTIVALMUBAN_PLAY_M_OPENTIME_MAX_NUM> m_openTime;//开启时间

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_play & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_play & msg);
		static ::proto_ff::E_FestivalMuban_play* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_play(); }
		static ::proto_ff::E_FestivalMuban_play make_pbmsg(){ return ::proto_ff::E_FestivalMuban_play(); }
	};
	typedef struct E_FestivalMuban_play_s E_FestivalMuban_play_t;

	struct Sheet_FestivalMuban_play_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_play_s();
		virtual ~Sheet_FestivalMuban_play_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_play_s, DEFINE_SHEET_FESTIVALMUBAN_PLAY_E_FESTIVALMUBAN_PLAY_LIST_MAX_NUM> E_FestivalMuban_play_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_play & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_play & msg);
		static ::proto_ff::Sheet_FestivalMuban_play* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_play(); }
		static ::proto_ff::Sheet_FestivalMuban_play make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_play(); }
	};
	typedef struct Sheet_FestivalMuban_play_s Sheet_FestivalMuban_play_t;

	struct E_FestivalMuban_play_reward_s : public NFDescStoreSeqOP {
		E_FestivalMuban_play_reward_s();
		virtual ~E_FestivalMuban_play_reward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		int32_t m_groupID;//奖励组id
		int32_t m_points;//积分要求
		int32_t m_boxID;//奖励box

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_play_reward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_play_reward & msg);
		static ::proto_ff::E_FestivalMuban_play_reward* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_play_reward(); }
		static ::proto_ff::E_FestivalMuban_play_reward make_pbmsg(){ return ::proto_ff::E_FestivalMuban_play_reward(); }
	};
	typedef struct E_FestivalMuban_play_reward_s E_FestivalMuban_play_reward_t;

	struct Sheet_FestivalMuban_play_reward_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_play_reward_s();
		virtual ~Sheet_FestivalMuban_play_reward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_play_reward_s, DEFINE_SHEET_FESTIVALMUBAN_PLAY_REWARD_E_FESTIVALMUBAN_PLAY_REWARD_LIST_MAX_NUM> E_FestivalMuban_play_reward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_play_reward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_play_reward & msg);
		static ::proto_ff::Sheet_FestivalMuban_play_reward* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_play_reward(); }
		static ::proto_ff::Sheet_FestivalMuban_play_reward make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_play_reward(); }
	};
	typedef struct Sheet_FestivalMuban_play_reward_s Sheet_FestivalMuban_play_reward_t;

	struct E_FestivalMuban_play_game_s : public NFDescStoreSeqOP {
		E_FestivalMuban_play_game_s();
		virtual ~E_FestivalMuban_play_game_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		int32_t m_groupID;//玩法组id
		int32_t m_order;//玩法排序
		int32_t m_playType;//玩法类型
		NFShmString<64> m_arg;//玩法参数
		int32_t m_rewardBox;//活动奖励
		int32_t m_preTime;//活动开始准备时间
		NFShmVector<NFShmString<128>, DEFINE_E_FESTIVALMUBAN_PLAY_GAME_M_PLAYARG_MAX_NUM> m_playArg;//玩法参数

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_play_game & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_play_game & msg);
		static ::proto_ff::E_FestivalMuban_play_game* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_play_game(); }
		static ::proto_ff::E_FestivalMuban_play_game make_pbmsg(){ return ::proto_ff::E_FestivalMuban_play_game(); }
	};
	typedef struct E_FestivalMuban_play_game_s E_FestivalMuban_play_game_t;

	struct Sheet_FestivalMuban_play_game_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_play_game_s();
		virtual ~Sheet_FestivalMuban_play_game_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_play_game_s, DEFINE_SHEET_FESTIVALMUBAN_PLAY_GAME_E_FESTIVALMUBAN_PLAY_GAME_LIST_MAX_NUM> E_FestivalMuban_play_game_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_play_game & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_play_game & msg);
		static ::proto_ff::Sheet_FestivalMuban_play_game* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_play_game(); }
		static ::proto_ff::Sheet_FestivalMuban_play_game make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_play_game(); }
	};
	typedef struct Sheet_FestivalMuban_play_game_s Sheet_FestivalMuban_play_game_t;

	struct E_FestivalMuban_play_score_s : public NFDescStoreSeqOP {
		E_FestivalMuban_play_score_s();
		virtual ~E_FestivalMuban_play_score_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		int32_t m_score;//分数
		NFShmString<64> m_image;//描述
		int32_t m_point;//获得声望积分

		virtual void write_to_pbmsg(::proto_ff::E_FestivalMuban_play_score & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FestivalMuban_play_score & msg);
		static ::proto_ff::E_FestivalMuban_play_score* new_pbmsg(){ return new ::proto_ff::E_FestivalMuban_play_score(); }
		static ::proto_ff::E_FestivalMuban_play_score make_pbmsg(){ return ::proto_ff::E_FestivalMuban_play_score(); }
	};
	typedef struct E_FestivalMuban_play_score_s E_FestivalMuban_play_score_t;

	struct Sheet_FestivalMuban_play_score_s : public NFDescStoreSeqOP {
		Sheet_FestivalMuban_play_score_s();
		virtual ~Sheet_FestivalMuban_play_score_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FestivalMuban_play_score_s, DEFINE_SHEET_FESTIVALMUBAN_PLAY_SCORE_E_FESTIVALMUBAN_PLAY_SCORE_LIST_MAX_NUM> E_FestivalMuban_play_score_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_play_score & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_play_score & msg);
		static ::proto_ff::Sheet_FestivalMuban_play_score* new_pbmsg(){ return new ::proto_ff::Sheet_FestivalMuban_play_score(); }
		static ::proto_ff::Sheet_FestivalMuban_play_score make_pbmsg(){ return ::proto_ff::Sheet_FestivalMuban_play_score(); }
	};
	typedef struct Sheet_FestivalMuban_play_score_s Sheet_FestivalMuban_play_score_t;

}

