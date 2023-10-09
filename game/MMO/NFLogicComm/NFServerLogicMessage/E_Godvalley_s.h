#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Godvalley.pb.h"
#include "E_Godvalley_s.h"

#define DEFINE_SHEET_GODVALLEYBATTLE_E_GODVALLEYBATTLE_LIST_MAX_NUM 8
#define DEFINE_E_GODVALLEYREWARDS_M_REWARD_MAX_NUM 5
#define DEFINE_SHEET_GODVALLEYREWARDS_E_GODVALLEYREWARDS_LIST_MAX_NUM 16
#define DEFINE_E_GODVALLEYATTRIBUTE_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_GODVALLEYATTRIBUTE_E_GODVALLEYATTRIBUTE_LIST_MAX_NUM 2


namespace proto_ff_s {

	struct E_GodvalleyBattle_s : public NFDescStoreSeqOP {
		E_GodvalleyBattle_s();
		virtual ~E_GodvalleyBattle_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//序号
		int32_t m_roomplayersmax;//一个房间最大人数
		NFShmString<64> m_team1n;//组名
		NFShmString<64> m_team2n;//组名
		NFShmString<64> m_name1;//名称
		NFShmString<64> m_name2;//名称
		int32_t m_winscore;//胜利的资源点
		int32_t m_timescore;//时间增加积分
		int32_t m_killscore;//杀人得积分
		int32_t m_killkeepscore;//连杀得积分
		int32_t m_breakkillkeepscore;//打断别人连杀得积分
		int32_t m_killmonsterscore;//杀怪得积分
		int32_t m_crystalpoints;//运水晶加资源点
		int32_t m_crystalscore;//运水晶加个人积分
		int32_t m_interceptpoints;//拦截水晶增加资源点
		int32_t m_interceptscore;//拦截水晶增加个人积分
		int32_t m_crystalreborntime;//水晶刷新时间（秒
		int32_t m_crystalmonsterid;//水晶采集物id
		NFShmString<64> m_crystalpos;//水晶位置
		int32_t m_match_s;//匹配时间
		int32_t m_duration_s;//打多久
		NFShmString<64> m_matchmapentry;//匹配地图出生位置
		int64_t m_mapid;//所在地图
		NFShmString<64> m_mapentry1;//青云起始位置
		NFShmString<64> m_mapentry2;//蜀山起始位置
		NFShmString<64> m_monster1;//青云怪物
		NFShmString<64> m_revivalpoint1;//青云怪物复活点
		NFShmString<64> m_monster2;//妖龙之末怪物
		NFShmString<64> m_revivalpoint2;//妖龙之末怪物复活点
		NFShmString<64> m_monster3;//蜀山怪物
		NFShmString<64> m_revivalpoint3;//蜀山怪物复活点
		NFShmString<64> m_npc1pos;//青云神匠
		NFShmString<64> m_npc2pos;//蜀山神匠
		int32_t m_actid;//所在活动ID
		int32_t m_skill;//模版技能

		virtual void write_to_pbmsg(::proto_ff::E_GodvalleyBattle & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodvalleyBattle & msg);
		static ::proto_ff::E_GodvalleyBattle* new_pbmsg(){ return new ::proto_ff::E_GodvalleyBattle(); }
		static ::proto_ff::E_GodvalleyBattle make_pbmsg(){ return ::proto_ff::E_GodvalleyBattle(); }
	};
	typedef struct E_GodvalleyBattle_s E_GodvalleyBattle_t;

	struct Sheet_GodvalleyBattle_s : public NFDescStoreSeqOP {
		Sheet_GodvalleyBattle_s();
		virtual ~Sheet_GodvalleyBattle_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodvalleyBattle_s, DEFINE_SHEET_GODVALLEYBATTLE_E_GODVALLEYBATTLE_LIST_MAX_NUM> E_GodvalleyBattle_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodvalleyBattle & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodvalleyBattle & msg);
		static ::proto_ff::Sheet_GodvalleyBattle* new_pbmsg(){ return new ::proto_ff::Sheet_GodvalleyBattle(); }
		static ::proto_ff::Sheet_GodvalleyBattle make_pbmsg(){ return ::proto_ff::Sheet_GodvalleyBattle(); }
	};
	typedef struct Sheet_GodvalleyBattle_s Sheet_GodvalleyBattle_t;

	struct E_GodvalleyRewardsRewardDesc_s : public NFDescStoreSeqOP {
		E_GodvalleyRewardsRewardDesc_s();
		virtual ~E_GodvalleyRewardsRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int64_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_GodvalleyRewardsRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodvalleyRewardsRewardDesc & msg);
		static ::proto_ff::E_GodvalleyRewardsRewardDesc* new_pbmsg(){ return new ::proto_ff::E_GodvalleyRewardsRewardDesc(); }
		static ::proto_ff::E_GodvalleyRewardsRewardDesc make_pbmsg(){ return ::proto_ff::E_GodvalleyRewardsRewardDesc(); }
	};
	typedef struct E_GodvalleyRewardsRewardDesc_s E_GodvalleyRewardsRewardDesc_t;

	struct E_GodvalleyRewards_s : public NFDescStoreSeqOP {
		E_GodvalleyRewards_s();
		virtual ~E_GodvalleyRewards_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_score;//积分数量
		NFShmVector<struct E_GodvalleyRewardsRewardDesc_s, DEFINE_E_GODVALLEYREWARDS_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_GodvalleyRewards & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodvalleyRewards & msg);
		static ::proto_ff::E_GodvalleyRewards* new_pbmsg(){ return new ::proto_ff::E_GodvalleyRewards(); }
		static ::proto_ff::E_GodvalleyRewards make_pbmsg(){ return ::proto_ff::E_GodvalleyRewards(); }
	};
	typedef struct E_GodvalleyRewards_s E_GodvalleyRewards_t;

	struct Sheet_GodvalleyRewards_s : public NFDescStoreSeqOP {
		Sheet_GodvalleyRewards_s();
		virtual ~Sheet_GodvalleyRewards_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodvalleyRewards_s, DEFINE_SHEET_GODVALLEYREWARDS_E_GODVALLEYREWARDS_LIST_MAX_NUM> E_GodvalleyRewards_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodvalleyRewards & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodvalleyRewards & msg);
		static ::proto_ff::Sheet_GodvalleyRewards* new_pbmsg(){ return new ::proto_ff::Sheet_GodvalleyRewards(); }
		static ::proto_ff::Sheet_GodvalleyRewards make_pbmsg(){ return ::proto_ff::Sheet_GodvalleyRewards(); }
	};
	typedef struct Sheet_GodvalleyRewards_s Sheet_GodvalleyRewards_t;

	struct E_GodvalleyAttributeAttributeDesc_s : public NFDescStoreSeqOP {
		E_GodvalleyAttributeAttributeDesc_s();
		virtual ~E_GodvalleyAttributeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_GodvalleyAttributeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodvalleyAttributeAttributeDesc & msg);
		static ::proto_ff::E_GodvalleyAttributeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_GodvalleyAttributeAttributeDesc(); }
		static ::proto_ff::E_GodvalleyAttributeAttributeDesc make_pbmsg(){ return ::proto_ff::E_GodvalleyAttributeAttributeDesc(); }
	};
	typedef struct E_GodvalleyAttributeAttributeDesc_s E_GodvalleyAttributeAttributeDesc_t;

	struct E_GodvalleyAttribute_s : public NFDescStoreSeqOP {
		E_GodvalleyAttribute_s();
		virtual ~E_GodvalleyAttribute_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmVector<struct E_GodvalleyAttributeAttributeDesc_s, DEFINE_E_GODVALLEYATTRIBUTE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_GodvalleyAttribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodvalleyAttribute & msg);
		static ::proto_ff::E_GodvalleyAttribute* new_pbmsg(){ return new ::proto_ff::E_GodvalleyAttribute(); }
		static ::proto_ff::E_GodvalleyAttribute make_pbmsg(){ return ::proto_ff::E_GodvalleyAttribute(); }
	};
	typedef struct E_GodvalleyAttribute_s E_GodvalleyAttribute_t;

	struct Sheet_GodvalleyAttribute_s : public NFDescStoreSeqOP {
		Sheet_GodvalleyAttribute_s();
		virtual ~Sheet_GodvalleyAttribute_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodvalleyAttribute_s, DEFINE_SHEET_GODVALLEYATTRIBUTE_E_GODVALLEYATTRIBUTE_LIST_MAX_NUM> E_GodvalleyAttribute_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodvalleyAttribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodvalleyAttribute & msg);
		static ::proto_ff::Sheet_GodvalleyAttribute* new_pbmsg(){ return new ::proto_ff::Sheet_GodvalleyAttribute(); }
		static ::proto_ff::Sheet_GodvalleyAttribute make_pbmsg(){ return ::proto_ff::Sheet_GodvalleyAttribute(); }
	};
	typedef struct Sheet_GodvalleyAttribute_s Sheet_GodvalleyAttribute_t;

}

