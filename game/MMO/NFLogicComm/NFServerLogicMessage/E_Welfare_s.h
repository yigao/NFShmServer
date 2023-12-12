#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Welfare.pb.h"
#include "E_Welfare_s.h"

#define DEFINE_SHEET_WELFARESIGN_E_WELFARESIGN_LIST_MAX_NUM 128
#define DEFINE_SHEET_WELFAREACCRUEREWARD_E_WELFAREACCRUEREWARD_LIST_MAX_NUM 16
#define DEFINE_SHEET_WELFARELVREWARD_E_WELFARELVREWARD_LIST_MAX_NUM 64
#define DEFINE_SHEET_WELFAREONLINE_E_WELFAREONLINE_LIST_MAX_NUM 8
#define DEFINE_SHEET_WELFAREFRAUD_E_WELFAREFRAUD_LIST_MAX_NUM 16
#define DEFINE_E_WELFAREWEEKENDGIFT_M_REWARDS_MAX_NUM 3
#define DEFINE_SHEET_WELFAREWEEKENDGIFT_E_WELFAREWEEKENDGIFT_LIST_MAX_NUM 8
#define DEFINE_SHEET_WELFARECONSTANT_E_WELFARECONSTANT_LIST_MAX_NUM 2
#define DEFINE_SHEET_WELFAREQIFU_E_WELFAREQIFU_LIST_MAX_NUM 16
#define DEFINE_SHEET_WELFAREWISH_E_WELFAREWISH_LIST_MAX_NUM 2048
#define DEFINE_SHEET_WELFARELOGON_E_WELFARELOGON_LIST_MAX_NUM 16
#define DEFINE_E_WELFAREFIRSTCHARGE_M_MODEL_MAX_NUM 2
#define DEFINE_E_WELFAREFIRSTCHARGE_M_REWARDSHOW_MAX_NUM 2
#define DEFINE_E_WELFAREFIRSTCHARGE_M_REWARDDES_MAX_NUM 3
#define DEFINE_SHEET_WELFAREFIRSTCHARGE_E_WELFAREFIRSTCHARGE_LIST_MAX_NUM 8
#define DEFINE_SHEET_WELFARESCTYPE_E_WELFARESCTYPE_LIST_MAX_NUM 8
#define DEFINE_SHEET_WELFAREMIBAO_E_WELFAREMIBAO_LIST_MAX_NUM 32
#define DEFINE_SHEET_WELFAREKFLEICHONG_E_WELFAREKFLEICHONG_LIST_MAX_NUM 16
#define DEFINE_SHEET_WELFAREDAILYGIFT_E_WELFAREDAILYGIFT_LIST_MAX_NUM 16
#define DEFINE_SHEET_WELFARELCGIFT_E_WELFARELCGIFT_LIST_MAX_NUM 32
#define DEFINE_SHEET_WELFARELCRAFFLE_E_WELFARELCRAFFLE_LIST_MAX_NUM 8
#define DEFINE_E_WELFARELCTURNTABLE_M_RAFFLE_MAX_NUM 2
#define DEFINE_SHEET_WELFARELCTURNTABLE_E_WELFARELCTURNTABLE_LIST_MAX_NUM 4
#define DEFINE_SHEET_WELFAREJACKPOT_E_WELFAREJACKPOT_LIST_MAX_NUM 64
#define DEFINE_SHEET_WELFAREMONTHLYCARD_E_WELFAREMONTHLYCARD_LIST_MAX_NUM 16
#define DEFINE_SHEET_WELFAREGOAL_E_WELFAREGOAL_LIST_MAX_NUM 2
#define DEFINE_E_WELFAREGOALTASK_M_PARAM_MAX_NUM 3
#define DEFINE_SHEET_WELFAREGOALTASK_E_WELFAREGOALTASK_LIST_MAX_NUM 16
#define DEFINE_SHEET_WELFAREINVEST_E_WELFAREINVEST_LIST_MAX_NUM 8
#define DEFINE_E_WELFAREINVESTREWARD_M_ITEM_MAX_NUM 2
#define DEFINE_SHEET_WELFAREINVESTREWARD_E_WELFAREINVESTREWARD_LIST_MAX_NUM 64
#define DEFINE_SHEET_WELFAREYTTLGIFT_E_WELFAREYTTLGIFT_LIST_MAX_NUM 4


namespace proto_ff_s {

	struct E_WelfareSign_s : public NFDescStoreSeqOP {
		E_WelfareSign_s();
		virtual ~E_WelfareSign_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_month;//月份
		int32_t m_days;//天数
		int32_t m_VIP;//VIP双倍等级
		NFShmString<64> m_icon;//图标
		int32_t m_reward;//道具奖励
		int32_t m_rewardNum;//道具数量

		virtual void write_to_pbmsg(::proto_ff::E_WelfareSign & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareSign & msg);
		static ::proto_ff::E_WelfareSign* new_pbmsg(){ return new ::proto_ff::E_WelfareSign(); }
		static ::proto_ff::E_WelfareSign make_pbmsg(){ return ::proto_ff::E_WelfareSign(); }
	};
	typedef struct E_WelfareSign_s E_WelfareSign_t;

	struct Sheet_WelfareSign_s : public NFDescStoreSeqOP {
		Sheet_WelfareSign_s();
		virtual ~Sheet_WelfareSign_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareSign_s, DEFINE_SHEET_WELFARESIGN_E_WELFARESIGN_LIST_MAX_NUM> E_WelfareSign_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareSign & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareSign & msg);
		static ::proto_ff::Sheet_WelfareSign* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareSign(); }
		static ::proto_ff::Sheet_WelfareSign make_pbmsg(){ return ::proto_ff::Sheet_WelfareSign(); }
	};
	typedef struct Sheet_WelfareSign_s Sheet_WelfareSign_t;

	struct E_WelfareAccruereward_s : public NFDescStoreSeqOP {
		E_WelfareAccruereward_s();
		virtual ~E_WelfareAccruereward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_month;//月份
		int32_t m_accrueDays;//累积签到天数
		int32_t m_reward;//累积奖励道具
		int32_t m_rewardNum;//累积奖励道具数量

		virtual void write_to_pbmsg(::proto_ff::E_WelfareAccruereward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareAccruereward & msg);
		static ::proto_ff::E_WelfareAccruereward* new_pbmsg(){ return new ::proto_ff::E_WelfareAccruereward(); }
		static ::proto_ff::E_WelfareAccruereward make_pbmsg(){ return ::proto_ff::E_WelfareAccruereward(); }
	};
	typedef struct E_WelfareAccruereward_s E_WelfareAccruereward_t;

	struct Sheet_WelfareAccruereward_s : public NFDescStoreSeqOP {
		Sheet_WelfareAccruereward_s();
		virtual ~Sheet_WelfareAccruereward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareAccruereward_s, DEFINE_SHEET_WELFAREACCRUEREWARD_E_WELFAREACCRUEREWARD_LIST_MAX_NUM> E_WelfareAccruereward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareAccruereward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareAccruereward & msg);
		static ::proto_ff::Sheet_WelfareAccruereward* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareAccruereward(); }
		static ::proto_ff::Sheet_WelfareAccruereward make_pbmsg(){ return ::proto_ff::Sheet_WelfareAccruereward(); }
	};
	typedef struct Sheet_WelfareAccruereward_s Sheet_WelfareAccruereward_t;

	struct E_WelfareLvreward_s : public NFDescStoreSeqOP {
		E_WelfareLvreward_s();
		virtual ~E_WelfareLvreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_lv;//等级
		int32_t m_lvReward;//奖励
		int32_t m_vip;//VIP等级
		int32_t m_vipReward;//VIP奖励

		virtual void write_to_pbmsg(::proto_ff::E_WelfareLvreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareLvreward & msg);
		static ::proto_ff::E_WelfareLvreward* new_pbmsg(){ return new ::proto_ff::E_WelfareLvreward(); }
		static ::proto_ff::E_WelfareLvreward make_pbmsg(){ return ::proto_ff::E_WelfareLvreward(); }
	};
	typedef struct E_WelfareLvreward_s E_WelfareLvreward_t;

	struct Sheet_WelfareLvreward_s : public NFDescStoreSeqOP {
		Sheet_WelfareLvreward_s();
		virtual ~Sheet_WelfareLvreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareLvreward_s, DEFINE_SHEET_WELFARELVREWARD_E_WELFARELVREWARD_LIST_MAX_NUM> E_WelfareLvreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareLvreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareLvreward & msg);
		static ::proto_ff::Sheet_WelfareLvreward* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareLvreward(); }
		static ::proto_ff::Sheet_WelfareLvreward make_pbmsg(){ return ::proto_ff::Sheet_WelfareLvreward(); }
	};
	typedef struct Sheet_WelfareLvreward_s Sheet_WelfareLvreward_t;

	struct E_WelfareOnline_s : public NFDescStoreSeqOP {
		E_WelfareOnline_s();
		virtual ~E_WelfareOnline_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_onlineTime;//在线时间
		int32_t m_lvReward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_WelfareOnline & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareOnline & msg);
		static ::proto_ff::E_WelfareOnline* new_pbmsg(){ return new ::proto_ff::E_WelfareOnline(); }
		static ::proto_ff::E_WelfareOnline make_pbmsg(){ return ::proto_ff::E_WelfareOnline(); }
	};
	typedef struct E_WelfareOnline_s E_WelfareOnline_t;

	struct Sheet_WelfareOnline_s : public NFDescStoreSeqOP {
		Sheet_WelfareOnline_s();
		virtual ~Sheet_WelfareOnline_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareOnline_s, DEFINE_SHEET_WELFAREONLINE_E_WELFAREONLINE_LIST_MAX_NUM> E_WelfareOnline_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareOnline & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareOnline & msg);
		static ::proto_ff::Sheet_WelfareOnline* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareOnline(); }
		static ::proto_ff::Sheet_WelfareOnline make_pbmsg(){ return ::proto_ff::Sheet_WelfareOnline(); }
	};
	typedef struct Sheet_WelfareOnline_s Sheet_WelfareOnline_t;

	struct E_WelfareFraud_s : public NFDescStoreSeqOP {
		E_WelfareFraud_s();
		virtual ~E_WelfareFraud_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<64> m_picture;//图片资源
		int32_t m_correct;//是否为正确答案

		virtual void write_to_pbmsg(::proto_ff::E_WelfareFraud & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareFraud & msg);
		static ::proto_ff::E_WelfareFraud* new_pbmsg(){ return new ::proto_ff::E_WelfareFraud(); }
		static ::proto_ff::E_WelfareFraud make_pbmsg(){ return ::proto_ff::E_WelfareFraud(); }
	};
	typedef struct E_WelfareFraud_s E_WelfareFraud_t;

	struct Sheet_WelfareFraud_s : public NFDescStoreSeqOP {
		Sheet_WelfareFraud_s();
		virtual ~Sheet_WelfareFraud_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareFraud_s, DEFINE_SHEET_WELFAREFRAUD_E_WELFAREFRAUD_LIST_MAX_NUM> E_WelfareFraud_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareFraud & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareFraud & msg);
		static ::proto_ff::Sheet_WelfareFraud* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareFraud(); }
		static ::proto_ff::Sheet_WelfareFraud make_pbmsg(){ return ::proto_ff::Sheet_WelfareFraud(); }
	};
	typedef struct Sheet_WelfareFraud_s Sheet_WelfareFraud_t;

	struct E_WelfareWeekendgift_s : public NFDescStoreSeqOP {
		E_WelfareWeekendgift_s();
		virtual ~E_WelfareWeekendgift_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_lvMin;//最小等级
		int32_t m_lvMax;//最大等级
		int32_t m_date;//日期
		NFShmVector<int32_t, DEFINE_E_WELFAREWEEKENDGIFT_M_REWARDS_MAX_NUM> m_rewards;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_WelfareWeekendgift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareWeekendgift & msg);
		static ::proto_ff::E_WelfareWeekendgift* new_pbmsg(){ return new ::proto_ff::E_WelfareWeekendgift(); }
		static ::proto_ff::E_WelfareWeekendgift make_pbmsg(){ return ::proto_ff::E_WelfareWeekendgift(); }
	};
	typedef struct E_WelfareWeekendgift_s E_WelfareWeekendgift_t;

	struct Sheet_WelfareWeekendgift_s : public NFDescStoreSeqOP {
		Sheet_WelfareWeekendgift_s();
		virtual ~Sheet_WelfareWeekendgift_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareWeekendgift_s, DEFINE_SHEET_WELFAREWEEKENDGIFT_E_WELFAREWEEKENDGIFT_LIST_MAX_NUM> E_WelfareWeekendgift_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareWeekendgift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareWeekendgift & msg);
		static ::proto_ff::Sheet_WelfareWeekendgift* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareWeekendgift(); }
		static ::proto_ff::Sheet_WelfareWeekendgift make_pbmsg(){ return ::proto_ff::Sheet_WelfareWeekendgift(); }
	};
	typedef struct Sheet_WelfareWeekendgift_s Sheet_WelfareWeekendgift_t;

	struct E_WelfareConstant_s : public NFDescStoreSeqOP {
		E_WelfareConstant_s();
		virtual ~E_WelfareConstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_addSigncost;//补签花费货币
		int32_t m_addSignprice;//补签花费价格
		int32_t m_noticeReward;//公告奖励
		int32_t m_wrongMin;//最小错误答案
		int32_t m_wrongMax;//最大错误答案数量
		int32_t m_fraudReward;//防诈骗奖励
		int32_t m_firstRcharge;//首充额度
		int32_t m_secondRcharge;//续充额度
		int32_t m_gemMB;//钻石秘宝额度
		int32_t m_starMB;//星耀秘宝额度
		int32_t m_kingMB;//王者秘宝额度
		int32_t m_keyRebate;//密匙返利

		virtual void write_to_pbmsg(::proto_ff::E_WelfareConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareConstant & msg);
		static ::proto_ff::E_WelfareConstant* new_pbmsg(){ return new ::proto_ff::E_WelfareConstant(); }
		static ::proto_ff::E_WelfareConstant make_pbmsg(){ return ::proto_ff::E_WelfareConstant(); }
	};
	typedef struct E_WelfareConstant_s E_WelfareConstant_t;

	struct Sheet_WelfareConstant_s : public NFDescStoreSeqOP {
		Sheet_WelfareConstant_s();
		virtual ~Sheet_WelfareConstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareConstant_s, DEFINE_SHEET_WELFARECONSTANT_E_WELFARECONSTANT_LIST_MAX_NUM> E_WelfareConstant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareConstant & msg);
		static ::proto_ff::Sheet_WelfareConstant* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareConstant(); }
		static ::proto_ff::Sheet_WelfareConstant make_pbmsg(){ return ::proto_ff::Sheet_WelfareConstant(); }
	};
	typedef struct Sheet_WelfareConstant_s Sheet_WelfareConstant_t;

	struct E_WelfareQifu_s : public NFDescStoreSeqOP {
		E_WelfareQifu_s();
		virtual ~E_WelfareQifu_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_constantid;//配置id
		int32_t m_constantdata;//数据
		NFShmString<64> m_stringdata;//字符串数据

		virtual void write_to_pbmsg(::proto_ff::E_WelfareQifu & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareQifu & msg);
		static ::proto_ff::E_WelfareQifu* new_pbmsg(){ return new ::proto_ff::E_WelfareQifu(); }
		static ::proto_ff::E_WelfareQifu make_pbmsg(){ return ::proto_ff::E_WelfareQifu(); }
	};
	typedef struct E_WelfareQifu_s E_WelfareQifu_t;

	struct Sheet_WelfareQifu_s : public NFDescStoreSeqOP {
		Sheet_WelfareQifu_s();
		virtual ~Sheet_WelfareQifu_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareQifu_s, DEFINE_SHEET_WELFAREQIFU_E_WELFAREQIFU_LIST_MAX_NUM> E_WelfareQifu_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareQifu & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareQifu & msg);
		static ::proto_ff::Sheet_WelfareQifu* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareQifu(); }
		static ::proto_ff::Sheet_WelfareQifu make_pbmsg(){ return ::proto_ff::Sheet_WelfareQifu(); }
	};
	typedef struct Sheet_WelfareQifu_s Sheet_WelfareQifu_t;

	struct E_WelfareWish_s : public NFDescStoreSeqOP {
		E_WelfareWish_s();
		virtual ~E_WelfareWish_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_level;//等级
		int64_t m_exp;//经验祈愿

		virtual void write_to_pbmsg(::proto_ff::E_WelfareWish & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareWish & msg);
		static ::proto_ff::E_WelfareWish* new_pbmsg(){ return new ::proto_ff::E_WelfareWish(); }
		static ::proto_ff::E_WelfareWish make_pbmsg(){ return ::proto_ff::E_WelfareWish(); }
	};
	typedef struct E_WelfareWish_s E_WelfareWish_t;

	struct Sheet_WelfareWish_s : public NFDescStoreSeqOP {
		Sheet_WelfareWish_s();
		virtual ~Sheet_WelfareWish_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareWish_s, DEFINE_SHEET_WELFAREWISH_E_WELFAREWISH_LIST_MAX_NUM> E_WelfareWish_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareWish & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareWish & msg);
		static ::proto_ff::Sheet_WelfareWish* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareWish(); }
		static ::proto_ff::Sheet_WelfareWish make_pbmsg(){ return ::proto_ff::Sheet_WelfareWish(); }
	};
	typedef struct Sheet_WelfareWish_s Sheet_WelfareWish_t;

	struct E_WelfareLogon_s : public NFDescStoreSeqOP {
		E_WelfareLogon_s();
		virtual ~E_WelfareLogon_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_days;//登录天数
		int32_t m_type;//奖励类型
		int32_t m_icon;//入口icon
		int32_t m_showItem;//展示物品
		int32_t m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_WelfareLogon & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareLogon & msg);
		static ::proto_ff::E_WelfareLogon* new_pbmsg(){ return new ::proto_ff::E_WelfareLogon(); }
		static ::proto_ff::E_WelfareLogon make_pbmsg(){ return ::proto_ff::E_WelfareLogon(); }
	};
	typedef struct E_WelfareLogon_s E_WelfareLogon_t;

	struct Sheet_WelfareLogon_s : public NFDescStoreSeqOP {
		Sheet_WelfareLogon_s();
		virtual ~Sheet_WelfareLogon_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareLogon_s, DEFINE_SHEET_WELFARELOGON_E_WELFARELOGON_LIST_MAX_NUM> E_WelfareLogon_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareLogon & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareLogon & msg);
		static ::proto_ff::Sheet_WelfareLogon* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareLogon(); }
		static ::proto_ff::Sheet_WelfareLogon make_pbmsg(){ return ::proto_ff::Sheet_WelfareLogon(); }
	};
	typedef struct Sheet_WelfareLogon_s Sheet_WelfareLogon_t;

	struct E_WelfareFirstcharge_s : public NFDescStoreSeqOP {
		E_WelfareFirstcharge_s();
		virtual ~E_WelfareFirstcharge_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_constantid;//配置id
		int32_t m_openlv;//开启等级
		int32_t m_type;//充值类型
		int32_t m_openDays;//开服天数
		int32_t m_reward;//奖励
		NFShmVector<NFShmString<64>, DEFINE_E_WELFAREFIRSTCHARGE_M_MODEL_MAX_NUM> m_model;//展示模型
		NFShmVector<int32_t, DEFINE_E_WELFAREFIRSTCHARGE_M_REWARDSHOW_MAX_NUM> m_rewardShow;//展示奖励
		NFShmVector<NFShmString<64>, DEFINE_E_WELFAREFIRSTCHARGE_M_REWARDDES_MAX_NUM> m_rewardDes;//奖励描述

		virtual void write_to_pbmsg(::proto_ff::E_WelfareFirstcharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareFirstcharge & msg);
		static ::proto_ff::E_WelfareFirstcharge* new_pbmsg(){ return new ::proto_ff::E_WelfareFirstcharge(); }
		static ::proto_ff::E_WelfareFirstcharge make_pbmsg(){ return ::proto_ff::E_WelfareFirstcharge(); }
	};
	typedef struct E_WelfareFirstcharge_s E_WelfareFirstcharge_t;

	struct Sheet_WelfareFirstcharge_s : public NFDescStoreSeqOP {
		Sheet_WelfareFirstcharge_s();
		virtual ~Sheet_WelfareFirstcharge_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareFirstcharge_s, DEFINE_SHEET_WELFAREFIRSTCHARGE_E_WELFAREFIRSTCHARGE_LIST_MAX_NUM> E_WelfareFirstcharge_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareFirstcharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareFirstcharge & msg);
		static ::proto_ff::Sheet_WelfareFirstcharge* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareFirstcharge(); }
		static ::proto_ff::Sheet_WelfareFirstcharge make_pbmsg(){ return ::proto_ff::Sheet_WelfareFirstcharge(); }
	};
	typedef struct Sheet_WelfareFirstcharge_s Sheet_WelfareFirstcharge_t;

	struct E_WelfareSctype_s : public NFDescStoreSeqOP {
		E_WelfareSctype_s();
		virtual ~E_WelfareSctype_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_functionid;//功能开放id
		NFShmString<64> m_title;//标题图片
		NFShmString<64> m_baseMap;//底图
		int32_t m_rcharge;//充值额度

		virtual void write_to_pbmsg(::proto_ff::E_WelfareSctype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareSctype & msg);
		static ::proto_ff::E_WelfareSctype* new_pbmsg(){ return new ::proto_ff::E_WelfareSctype(); }
		static ::proto_ff::E_WelfareSctype make_pbmsg(){ return ::proto_ff::E_WelfareSctype(); }
	};
	typedef struct E_WelfareSctype_s E_WelfareSctype_t;

	struct Sheet_WelfareSctype_s : public NFDescStoreSeqOP {
		Sheet_WelfareSctype_s();
		virtual ~Sheet_WelfareSctype_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareSctype_s, DEFINE_SHEET_WELFARESCTYPE_E_WELFARESCTYPE_LIST_MAX_NUM> E_WelfareSctype_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareSctype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareSctype & msg);
		static ::proto_ff::Sheet_WelfareSctype* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareSctype(); }
		static ::proto_ff::Sheet_WelfareSctype make_pbmsg(){ return ::proto_ff::Sheet_WelfareSctype(); }
	};
	typedef struct Sheet_WelfareSctype_s Sheet_WelfareSctype_t;

	struct E_WelfareMibao_s : public NFDescStoreSeqOP {
		E_WelfareMibao_s();
		virtual ~E_WelfareMibao_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_openlv;//开启等级
		int32_t m_type;//充值类型
		int32_t m_rank;//排序
		int32_t m_openDays;//开服天数
		int32_t m_reward;//奖励
		NFShmString<64> m_des;//倍数描述

		virtual void write_to_pbmsg(::proto_ff::E_WelfareMibao & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareMibao & msg);
		static ::proto_ff::E_WelfareMibao* new_pbmsg(){ return new ::proto_ff::E_WelfareMibao(); }
		static ::proto_ff::E_WelfareMibao make_pbmsg(){ return ::proto_ff::E_WelfareMibao(); }
	};
	typedef struct E_WelfareMibao_s E_WelfareMibao_t;

	struct Sheet_WelfareMibao_s : public NFDescStoreSeqOP {
		Sheet_WelfareMibao_s();
		virtual ~Sheet_WelfareMibao_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareMibao_s, DEFINE_SHEET_WELFAREMIBAO_E_WELFAREMIBAO_LIST_MAX_NUM> E_WelfareMibao_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareMibao & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareMibao & msg);
		static ::proto_ff::Sheet_WelfareMibao* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareMibao(); }
		static ::proto_ff::Sheet_WelfareMibao make_pbmsg(){ return ::proto_ff::Sheet_WelfareMibao(); }
	};
	typedef struct Sheet_WelfareMibao_s Sheet_WelfareMibao_t;

	struct E_WelfareKfleichong_s : public NFDescStoreSeqOP {
		E_WelfareKfleichong_s();
		virtual ~E_WelfareKfleichong_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//档次
		int32_t m_money;//充值货币
		int32_t m_limit;//充值额度
		int32_t m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_WelfareKfleichong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareKfleichong & msg);
		static ::proto_ff::E_WelfareKfleichong* new_pbmsg(){ return new ::proto_ff::E_WelfareKfleichong(); }
		static ::proto_ff::E_WelfareKfleichong make_pbmsg(){ return ::proto_ff::E_WelfareKfleichong(); }
	};
	typedef struct E_WelfareKfleichong_s E_WelfareKfleichong_t;

	struct Sheet_WelfareKfleichong_s : public NFDescStoreSeqOP {
		Sheet_WelfareKfleichong_s();
		virtual ~Sheet_WelfareKfleichong_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareKfleichong_s, DEFINE_SHEET_WELFAREKFLEICHONG_E_WELFAREKFLEICHONG_LIST_MAX_NUM> E_WelfareKfleichong_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareKfleichong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareKfleichong & msg);
		static ::proto_ff::Sheet_WelfareKfleichong* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareKfleichong(); }
		static ::proto_ff::Sheet_WelfareKfleichong make_pbmsg(){ return ::proto_ff::Sheet_WelfareKfleichong(); }
	};
	typedef struct Sheet_WelfareKfleichong_s Sheet_WelfareKfleichong_t;

	struct E_WelfareDailygift_s : public NFDescStoreSeqOP {
		E_WelfareDailygift_s();
		virtual ~E_WelfareDailygift_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//礼包类型
		int32_t m_rechargeId;//价格链接
		int32_t m_OneclickBuy;//是否一键购买
		int32_t m_reward;//奖励
		int32_t m_quality;//礼包品质

		virtual void write_to_pbmsg(::proto_ff::E_WelfareDailygift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareDailygift & msg);
		static ::proto_ff::E_WelfareDailygift* new_pbmsg(){ return new ::proto_ff::E_WelfareDailygift(); }
		static ::proto_ff::E_WelfareDailygift make_pbmsg(){ return ::proto_ff::E_WelfareDailygift(); }
	};
	typedef struct E_WelfareDailygift_s E_WelfareDailygift_t;

	struct Sheet_WelfareDailygift_s : public NFDescStoreSeqOP {
		Sheet_WelfareDailygift_s();
		virtual ~Sheet_WelfareDailygift_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareDailygift_s, DEFINE_SHEET_WELFAREDAILYGIFT_E_WELFAREDAILYGIFT_LIST_MAX_NUM> E_WelfareDailygift_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareDailygift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareDailygift & msg);
		static ::proto_ff::Sheet_WelfareDailygift* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareDailygift(); }
		static ::proto_ff::Sheet_WelfareDailygift make_pbmsg(){ return ::proto_ff::Sheet_WelfareDailygift(); }
	};
	typedef struct Sheet_WelfareDailygift_s Sheet_WelfareDailygift_t;

	struct E_WelfareLcgift_s : public NFDescStoreSeqOP {
		E_WelfareLcgift_s();
		virtual ~E_WelfareLcgift_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//礼包类型
		int32_t m_limit;//充值额度
		int32_t m_days;//累充天数
		int32_t m_starNum;//星星数量
		int32_t m_reward;//奖励
		int32_t m_showItem;//道具展示

		virtual void write_to_pbmsg(::proto_ff::E_WelfareLcgift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareLcgift & msg);
		static ::proto_ff::E_WelfareLcgift* new_pbmsg(){ return new ::proto_ff::E_WelfareLcgift(); }
		static ::proto_ff::E_WelfareLcgift make_pbmsg(){ return ::proto_ff::E_WelfareLcgift(); }
	};
	typedef struct E_WelfareLcgift_s E_WelfareLcgift_t;

	struct Sheet_WelfareLcgift_s : public NFDescStoreSeqOP {
		Sheet_WelfareLcgift_s();
		virtual ~Sheet_WelfareLcgift_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareLcgift_s, DEFINE_SHEET_WELFARELCGIFT_E_WELFARELCGIFT_LIST_MAX_NUM> E_WelfareLcgift_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareLcgift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareLcgift & msg);
		static ::proto_ff::Sheet_WelfareLcgift* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareLcgift(); }
		static ::proto_ff::Sheet_WelfareLcgift make_pbmsg(){ return ::proto_ff::Sheet_WelfareLcgift(); }
	};
	typedef struct Sheet_WelfareLcgift_s Sheet_WelfareLcgift_t;

	struct E_WelfareLcraffle_s : public NFDescStoreSeqOP {
		E_WelfareLcraffle_s();
		virtual ~E_WelfareLcraffle_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_money;//充值货币
		int32_t m_limit;//充值额度
		int32_t m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_WelfareLcraffle & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareLcraffle & msg);
		static ::proto_ff::E_WelfareLcraffle* new_pbmsg(){ return new ::proto_ff::E_WelfareLcraffle(); }
		static ::proto_ff::E_WelfareLcraffle make_pbmsg(){ return ::proto_ff::E_WelfareLcraffle(); }
	};
	typedef struct E_WelfareLcraffle_s E_WelfareLcraffle_t;

	struct Sheet_WelfareLcraffle_s : public NFDescStoreSeqOP {
		Sheet_WelfareLcraffle_s();
		virtual ~Sheet_WelfareLcraffle_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareLcraffle_s, DEFINE_SHEET_WELFARELCRAFFLE_E_WELFARELCRAFFLE_LIST_MAX_NUM> E_WelfareLcraffle_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareLcraffle & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareLcraffle & msg);
		static ::proto_ff::Sheet_WelfareLcraffle* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareLcraffle(); }
		static ::proto_ff::Sheet_WelfareLcraffle make_pbmsg(){ return ::proto_ff::Sheet_WelfareLcraffle(); }
	};
	typedef struct Sheet_WelfareLcraffle_s Sheet_WelfareLcraffle_t;

	struct E_WelfareLcturntableRaffleDesc_s : public NFDescStoreSeqOP {
		E_WelfareLcturntableRaffleDesc_s();
		virtual ~E_WelfareLcturntableRaffleDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_item;//道具

		virtual void write_to_pbmsg(::proto_ff::E_WelfareLcturntableRaffleDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareLcturntableRaffleDesc & msg);
		static ::proto_ff::E_WelfareLcturntableRaffleDesc* new_pbmsg(){ return new ::proto_ff::E_WelfareLcturntableRaffleDesc(); }
		static ::proto_ff::E_WelfareLcturntableRaffleDesc make_pbmsg(){ return ::proto_ff::E_WelfareLcturntableRaffleDesc(); }
	};
	typedef struct E_WelfareLcturntableRaffleDesc_s E_WelfareLcturntableRaffleDesc_t;

	struct E_WelfareLcturntable_s : public NFDescStoreSeqOP {
		E_WelfareLcturntable_s();
		virtual ~E_WelfareLcturntable_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_jackpotType;//奖池类型
		int32_t m_raffleTimes;//累积抽奖次数
		int32_t m_raTimesRew;//累积抽奖奖励
		NFShmVector<struct E_WelfareLcturntableRaffleDesc_s, DEFINE_E_WELFARELCTURNTABLE_M_RAFFLE_MAX_NUM> m_raffle;//抽奖

		virtual void write_to_pbmsg(::proto_ff::E_WelfareLcturntable & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareLcturntable & msg);
		static ::proto_ff::E_WelfareLcturntable* new_pbmsg(){ return new ::proto_ff::E_WelfareLcturntable(); }
		static ::proto_ff::E_WelfareLcturntable make_pbmsg(){ return ::proto_ff::E_WelfareLcturntable(); }
	};
	typedef struct E_WelfareLcturntable_s E_WelfareLcturntable_t;

	struct Sheet_WelfareLcturntable_s : public NFDescStoreSeqOP {
		Sheet_WelfareLcturntable_s();
		virtual ~Sheet_WelfareLcturntable_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareLcturntable_s, DEFINE_SHEET_WELFARELCTURNTABLE_E_WELFARELCTURNTABLE_LIST_MAX_NUM> E_WelfareLcturntable_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareLcturntable & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareLcturntable & msg);
		static ::proto_ff::Sheet_WelfareLcturntable* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareLcturntable(); }
		static ::proto_ff::Sheet_WelfareLcturntable make_pbmsg(){ return ::proto_ff::Sheet_WelfareLcturntable(); }
	};
	typedef struct Sheet_WelfareLcturntable_s Sheet_WelfareLcturntable_t;

	struct E_WelfareJackpot_s : public NFDescStoreSeqOP {
		E_WelfareJackpot_s();
		virtual ~E_WelfareJackpot_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//奖池类型
		int32_t m_rank;//排序
		int32_t m_item;//道具
		int32_t m_itemNum;//数量
		int32_t m_weight;//抽取权重

		virtual void write_to_pbmsg(::proto_ff::E_WelfareJackpot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareJackpot & msg);
		static ::proto_ff::E_WelfareJackpot* new_pbmsg(){ return new ::proto_ff::E_WelfareJackpot(); }
		static ::proto_ff::E_WelfareJackpot make_pbmsg(){ return ::proto_ff::E_WelfareJackpot(); }
	};
	typedef struct E_WelfareJackpot_s E_WelfareJackpot_t;

	struct Sheet_WelfareJackpot_s : public NFDescStoreSeqOP {
		Sheet_WelfareJackpot_s();
		virtual ~Sheet_WelfareJackpot_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareJackpot_s, DEFINE_SHEET_WELFAREJACKPOT_E_WELFAREJACKPOT_LIST_MAX_NUM> E_WelfareJackpot_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareJackpot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareJackpot & msg);
		static ::proto_ff::Sheet_WelfareJackpot* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareJackpot(); }
		static ::proto_ff::Sheet_WelfareJackpot make_pbmsg(){ return ::proto_ff::Sheet_WelfareJackpot(); }
	};
	typedef struct Sheet_WelfareJackpot_s Sheet_WelfareJackpot_t;

	struct E_WelfareMonthlycard_s : public NFDescStoreSeqOP {
		E_WelfareMonthlycard_s();
		virtual ~E_WelfareMonthlycard_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_cardType;//月卡类型
		int32_t m_cardMoney;//月卡购买链接
		int32_t m_cardBuyitem;//月卡购买立得材料
		int32_t m_cardDailyitem;//月卡每日材料
		int32_t m_cardTime;//月卡持续时间
		int32_t m_Flmultiple;//返利倍数

		virtual void write_to_pbmsg(::proto_ff::E_WelfareMonthlycard & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareMonthlycard & msg);
		static ::proto_ff::E_WelfareMonthlycard* new_pbmsg(){ return new ::proto_ff::E_WelfareMonthlycard(); }
		static ::proto_ff::E_WelfareMonthlycard make_pbmsg(){ return ::proto_ff::E_WelfareMonthlycard(); }
	};
	typedef struct E_WelfareMonthlycard_s E_WelfareMonthlycard_t;

	struct Sheet_WelfareMonthlycard_s : public NFDescStoreSeqOP {
		Sheet_WelfareMonthlycard_s();
		virtual ~Sheet_WelfareMonthlycard_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareMonthlycard_s, DEFINE_SHEET_WELFAREMONTHLYCARD_E_WELFAREMONTHLYCARD_LIST_MAX_NUM> E_WelfareMonthlycard_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareMonthlycard & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareMonthlycard & msg);
		static ::proto_ff::Sheet_WelfareMonthlycard* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareMonthlycard(); }
		static ::proto_ff::Sheet_WelfareMonthlycard make_pbmsg(){ return ::proto_ff::Sheet_WelfareMonthlycard(); }
	};
	typedef struct Sheet_WelfareMonthlycard_s Sheet_WelfareMonthlycard_t;

	struct E_WelfareGoal_s : public NFDescStoreSeqOP {
		E_WelfareGoal_s();
		virtual ~E_WelfareGoal_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_functionid;//关联开关
		int32_t m_taskGroup;//任务列表组
		int32_t m_tasknum;//需要完成的任务数量
		int32_t m_rewrdItem;//完成奖励
		int32_t m_time;//持续时间

		virtual void write_to_pbmsg(::proto_ff::E_WelfareGoal & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareGoal & msg);
		static ::proto_ff::E_WelfareGoal* new_pbmsg(){ return new ::proto_ff::E_WelfareGoal(); }
		static ::proto_ff::E_WelfareGoal make_pbmsg(){ return ::proto_ff::E_WelfareGoal(); }
	};
	typedef struct E_WelfareGoal_s E_WelfareGoal_t;

	struct Sheet_WelfareGoal_s : public NFDescStoreSeqOP {
		Sheet_WelfareGoal_s();
		virtual ~Sheet_WelfareGoal_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareGoal_s, DEFINE_SHEET_WELFAREGOAL_E_WELFAREGOAL_LIST_MAX_NUM> E_WelfareGoal_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareGoal & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareGoal & msg);
		static ::proto_ff::Sheet_WelfareGoal* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareGoal(); }
		static ::proto_ff::Sheet_WelfareGoal make_pbmsg(){ return ::proto_ff::Sheet_WelfareGoal(); }
	};
	typedef struct Sheet_WelfareGoal_s Sheet_WelfareGoal_t;

	struct E_WelfareGoaltask_s : public NFDescStoreSeqOP {
		E_WelfareGoaltask_s();
		virtual ~E_WelfareGoaltask_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//任务组id
		int32_t m_eventType;//事件类型
		int32_t m_reachPrice;//达成值
		int32_t m_itemID;//奖励道具
		int32_t m_itemNum;//道具数量
		NFShmVector<int32_t, DEFINE_E_WELFAREGOALTASK_M_PARAM_MAX_NUM> m_param;//事件完成参数

		virtual void write_to_pbmsg(::proto_ff::E_WelfareGoaltask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareGoaltask & msg);
		static ::proto_ff::E_WelfareGoaltask* new_pbmsg(){ return new ::proto_ff::E_WelfareGoaltask(); }
		static ::proto_ff::E_WelfareGoaltask make_pbmsg(){ return ::proto_ff::E_WelfareGoaltask(); }
	};
	typedef struct E_WelfareGoaltask_s E_WelfareGoaltask_t;

	struct Sheet_WelfareGoaltask_s : public NFDescStoreSeqOP {
		Sheet_WelfareGoaltask_s();
		virtual ~Sheet_WelfareGoaltask_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareGoaltask_s, DEFINE_SHEET_WELFAREGOALTASK_E_WELFAREGOALTASK_LIST_MAX_NUM> E_WelfareGoaltask_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareGoaltask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareGoaltask & msg);
		static ::proto_ff::Sheet_WelfareGoaltask* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareGoaltask(); }
		static ::proto_ff::Sheet_WelfareGoaltask make_pbmsg(){ return ::proto_ff::Sheet_WelfareGoaltask(); }
	};
	typedef struct Sheet_WelfareGoaltask_s Sheet_WelfareGoaltask_t;

	struct E_WelfareInvest_s : public NFDescStoreSeqOP {
		E_WelfareInvest_s();
		virtual ~E_WelfareInvest_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_functionID;//开放条件
		int32_t m_price;//价格
		int32_t m_rewardItem;//奖励道具
		int32_t m_rewardGroup;//投资奖励组

		virtual void write_to_pbmsg(::proto_ff::E_WelfareInvest & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareInvest & msg);
		static ::proto_ff::E_WelfareInvest* new_pbmsg(){ return new ::proto_ff::E_WelfareInvest(); }
		static ::proto_ff::E_WelfareInvest make_pbmsg(){ return ::proto_ff::E_WelfareInvest(); }
	};
	typedef struct E_WelfareInvest_s E_WelfareInvest_t;

	struct Sheet_WelfareInvest_s : public NFDescStoreSeqOP {
		Sheet_WelfareInvest_s();
		virtual ~Sheet_WelfareInvest_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareInvest_s, DEFINE_SHEET_WELFAREINVEST_E_WELFAREINVEST_LIST_MAX_NUM> E_WelfareInvest_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareInvest & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareInvest & msg);
		static ::proto_ff::Sheet_WelfareInvest* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareInvest(); }
		static ::proto_ff::Sheet_WelfareInvest make_pbmsg(){ return ::proto_ff::Sheet_WelfareInvest(); }
	};
	typedef struct Sheet_WelfareInvest_s Sheet_WelfareInvest_t;

	struct E_WelfareInvestrewardItemDesc_s : public NFDescStoreSeqOP {
		E_WelfareInvestrewardItemDesc_s();
		virtual ~E_WelfareInvestrewardItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_WelfareInvestrewardItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareInvestrewardItemDesc & msg);
		static ::proto_ff::E_WelfareInvestrewardItemDesc* new_pbmsg(){ return new ::proto_ff::E_WelfareInvestrewardItemDesc(); }
		static ::proto_ff::E_WelfareInvestrewardItemDesc make_pbmsg(){ return ::proto_ff::E_WelfareInvestrewardItemDesc(); }
	};
	typedef struct E_WelfareInvestrewardItemDesc_s E_WelfareInvestrewardItemDesc_t;

	struct E_WelfareInvestreward_s : public NFDescStoreSeqOP {
		E_WelfareInvestreward_s();
		virtual ~E_WelfareInvestreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_group;//组id
		int32_t m_lv;//领取等级
		NFShmVector<struct E_WelfareInvestrewardItemDesc_s, DEFINE_E_WELFAREINVESTREWARD_M_ITEM_MAX_NUM> m_Item;//奖励道具

		virtual void write_to_pbmsg(::proto_ff::E_WelfareInvestreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareInvestreward & msg);
		static ::proto_ff::E_WelfareInvestreward* new_pbmsg(){ return new ::proto_ff::E_WelfareInvestreward(); }
		static ::proto_ff::E_WelfareInvestreward make_pbmsg(){ return ::proto_ff::E_WelfareInvestreward(); }
	};
	typedef struct E_WelfareInvestreward_s E_WelfareInvestreward_t;

	struct Sheet_WelfareInvestreward_s : public NFDescStoreSeqOP {
		Sheet_WelfareInvestreward_s();
		virtual ~Sheet_WelfareInvestreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareInvestreward_s, DEFINE_SHEET_WELFAREINVESTREWARD_E_WELFAREINVESTREWARD_LIST_MAX_NUM> E_WelfareInvestreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareInvestreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareInvestreward & msg);
		static ::proto_ff::Sheet_WelfareInvestreward* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareInvestreward(); }
		static ::proto_ff::Sheet_WelfareInvestreward make_pbmsg(){ return ::proto_ff::Sheet_WelfareInvestreward(); }
	};
	typedef struct Sheet_WelfareInvestreward_s Sheet_WelfareInvestreward_t;

	struct E_WelfareYttlgift_s : public NFDescStoreSeqOP {
		E_WelfareYttlgift_s();
		virtual ~E_WelfareYttlgift_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_rechargeId;//价格链接
		int32_t m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_WelfareYttlgift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WelfareYttlgift & msg);
		static ::proto_ff::E_WelfareYttlgift* new_pbmsg(){ return new ::proto_ff::E_WelfareYttlgift(); }
		static ::proto_ff::E_WelfareYttlgift make_pbmsg(){ return ::proto_ff::E_WelfareYttlgift(); }
	};
	typedef struct E_WelfareYttlgift_s E_WelfareYttlgift_t;

	struct Sheet_WelfareYttlgift_s : public NFDescStoreSeqOP {
		Sheet_WelfareYttlgift_s();
		virtual ~Sheet_WelfareYttlgift_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WelfareYttlgift_s, DEFINE_SHEET_WELFAREYTTLGIFT_E_WELFAREYTTLGIFT_LIST_MAX_NUM> E_WelfareYttlgift_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WelfareYttlgift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WelfareYttlgift & msg);
		static ::proto_ff::Sheet_WelfareYttlgift* new_pbmsg(){ return new ::proto_ff::Sheet_WelfareYttlgift(); }
		static ::proto_ff::Sheet_WelfareYttlgift make_pbmsg(){ return ::proto_ff::Sheet_WelfareYttlgift(); }
	};
	typedef struct Sheet_WelfareYttlgift_s Sheet_WelfareYttlgift_t;

}

