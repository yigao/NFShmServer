#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Achievement.pb.h"
#include "E_Achievement_s.h"

#define DEFINE_E_ACHIEVEMENTACHIEVEMENT_M_PARAM_MAX_NUM 2
#define DEFINE_E_ACHIEVEMENTACHIEVEMENT_M_ITEMREWARD_MAX_NUM 2
#define DEFINE_SHEET_ACHIEVEMENTACHIEVEMENT_E_ACHIEVEMENTACHIEVEMENT_LIST_MAX_NUM 256
#define DEFINE_SHEET_ACHIEVEMENTTOTALACHIEVEMENTS_E_ACHIEVEMENTTOTALACHIEVEMENTS_LIST_MAX_NUM 16


namespace proto_ff_s {

	struct E_AchievementAchievementItemrewardDesc_s : public NFDescStoreSeqOP {
		E_AchievementAchievementItemrewardDesc_s();
		virtual ~E_AchievementAchievementItemrewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数量
		int64_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_AchievementAchievementItemrewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AchievementAchievementItemrewardDesc & msg);
		static ::proto_ff::E_AchievementAchievementItemrewardDesc* new_pbmsg(){ return new ::proto_ff::E_AchievementAchievementItemrewardDesc(); }
		static ::proto_ff::E_AchievementAchievementItemrewardDesc make_pbmsg(){ return ::proto_ff::E_AchievementAchievementItemrewardDesc(); }
	};
	typedef struct E_AchievementAchievementItemrewardDesc_s E_AchievementAchievementItemrewardDesc_t;

	struct E_AchievementAchievement_s : public NFDescStoreSeqOP {
		E_AchievementAchievement_s();
		virtual ~E_AchievementAchievement_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_achievementid;//成就ID
		int32_t m_achievementlevel;//成就触发等级
		int32_t m_achievementtype;//成就类型
		int32_t m_achievementsubtype;//事件类型
		int32_t m_subtype;//事件细分
		int32_t m_achievementobjectvalue;//事件目标完成值
		NFShmString<64> m_typename;//类型名称
		NFShmString<64> m_label;//二级标签
		int32_t m_achievementpoint;//获取成就点数量
		int32_t m_overview;//是否进入总览进度
		NFShmVector<int32_t, DEFINE_E_ACHIEVEMENTACHIEVEMENT_M_PARAM_MAX_NUM> m_param;//事件完成参数
		NFShmVector<struct E_AchievementAchievementItemrewardDesc_s, DEFINE_E_ACHIEVEMENTACHIEVEMENT_M_ITEMREWARD_MAX_NUM> m_itemreward;//获得物品

		virtual void write_to_pbmsg(::proto_ff::E_AchievementAchievement & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AchievementAchievement & msg);
		static ::proto_ff::E_AchievementAchievement* new_pbmsg(){ return new ::proto_ff::E_AchievementAchievement(); }
		static ::proto_ff::E_AchievementAchievement make_pbmsg(){ return ::proto_ff::E_AchievementAchievement(); }
	};
	typedef struct E_AchievementAchievement_s E_AchievementAchievement_t;

	struct Sheet_AchievementAchievement_s : public NFDescStoreSeqOP {
		Sheet_AchievementAchievement_s();
		virtual ~Sheet_AchievementAchievement_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AchievementAchievement_s, DEFINE_SHEET_ACHIEVEMENTACHIEVEMENT_E_ACHIEVEMENTACHIEVEMENT_LIST_MAX_NUM> E_AchievementAchievement_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AchievementAchievement & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AchievementAchievement & msg);
		static ::proto_ff::Sheet_AchievementAchievement* new_pbmsg(){ return new ::proto_ff::Sheet_AchievementAchievement(); }
		static ::proto_ff::Sheet_AchievementAchievement make_pbmsg(){ return ::proto_ff::Sheet_AchievementAchievement(); }
	};
	typedef struct Sheet_AchievementAchievement_s Sheet_AchievementAchievement_t;

	struct E_AchievementTotalachievements_s : public NFDescStoreSeqOP {
		E_AchievementTotalachievements_s();
		virtual ~E_AchievementTotalachievements_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_totalsum;//总额成就ID
		NFShmString<64> m_totalachievementname;//总览成就名
		int32_t m_achievedpoints;//达成点数
		int32_t m_totalitems;//总览奖励物品
		int32_t m_rewardvalue;//奖励物品数量

		virtual void write_to_pbmsg(::proto_ff::E_AchievementTotalachievements & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AchievementTotalachievements & msg);
		static ::proto_ff::E_AchievementTotalachievements* new_pbmsg(){ return new ::proto_ff::E_AchievementTotalachievements(); }
		static ::proto_ff::E_AchievementTotalachievements make_pbmsg(){ return ::proto_ff::E_AchievementTotalachievements(); }
	};
	typedef struct E_AchievementTotalachievements_s E_AchievementTotalachievements_t;

	struct Sheet_AchievementTotalachievements_s : public NFDescStoreSeqOP {
		Sheet_AchievementTotalachievements_s();
		virtual ~Sheet_AchievementTotalachievements_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AchievementTotalachievements_s, DEFINE_SHEET_ACHIEVEMENTTOTALACHIEVEMENTS_E_ACHIEVEMENTTOTALACHIEVEMENTS_LIST_MAX_NUM> E_AchievementTotalachievements_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AchievementTotalachievements & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AchievementTotalachievements & msg);
		static ::proto_ff::Sheet_AchievementTotalachievements* new_pbmsg(){ return new ::proto_ff::Sheet_AchievementTotalachievements(); }
		static ::proto_ff::Sheet_AchievementTotalachievements make_pbmsg(){ return ::proto_ff::Sheet_AchievementTotalachievements(); }
	};
	typedef struct Sheet_AchievementTotalachievements_s Sheet_AchievementTotalachievements_t;

}

