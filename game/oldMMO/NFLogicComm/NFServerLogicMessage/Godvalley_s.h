#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "Godvalley.pb.h"
#include "Godvalley_s.h"

#define DEFINE_SHEET_GODVALLEYBATTLE_E_GODVALLEYBATTLE_LIST_MAX_NUM 20
#define DEFINE_E_GODVALLEYREWARDS_M_REWARD_MAX_NUM 4
#define DEFINE_SHEET_GODVALLEYREWARDS_E_GODVALLEYREWARDS_LIST_MAX_NUM 20
namespace proto_ff_s {

	struct E_GodvalleyBattle_s : public NFDescStoreSeqOP {
		E_GodvalleyBattle_s();
		virtual ~E_GodvalleyBattle_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		NFShmString<60> m_team1n;
		NFShmString<60> m_team2n;
		int32_t m_winscore;
		int32_t m_timescore;
		int32_t m_killscore;
		int32_t m_killkeepscore;
		int32_t m_breakkillkeepscore;
		int32_t m_killmonsterscore;
		int32_t m_crystalpoints;
		int32_t m_crystalscore;
		int32_t m_interceptpoints;
		int32_t m_interceptscore;
		int32_t m_crystalreborntime;
		NFShmString<60> m_crystalpos;
		int32_t m_match_s;
		int32_t m_duration_s;
		int64_t m_matchmapid;
		NFShmString<60> m_matchmapentry;
		int64_t m_mapid;
		NFShmString<60> m_mapentry1;
		NFShmString<60> m_mapentry2;
		NFShmString<60> m_monster1;
		NFShmString<60> m_monster2;
		NFShmString<60> m_monster3;
		NFShmString<60> m_npc1pos;
		NFShmString<60> m_npc2pos;

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
		NFShmVector<struct E_GodvalleyBattle_s, DEFINE_SHEET_GODVALLEYBATTLE_E_GODVALLEYBATTLE_LIST_MAX_NUM> E_GodvalleyBattle_List;

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
		int32_t m_num;
		int64_t m_id;

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
		int32_t m_id;
		int32_t m_score;
		NFShmVector<struct E_GodvalleyRewardsRewardDesc_s, DEFINE_E_GODVALLEYREWARDS_M_REWARD_MAX_NUM> m_reward;

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
		NFShmVector<struct E_GodvalleyRewards_s, DEFINE_SHEET_GODVALLEYREWARDS_E_GODVALLEYREWARDS_LIST_MAX_NUM> E_GodvalleyRewards_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodvalleyRewards & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodvalleyRewards & msg);
		static ::proto_ff::Sheet_GodvalleyRewards* new_pbmsg(){ return new ::proto_ff::Sheet_GodvalleyRewards(); }
		static ::proto_ff::Sheet_GodvalleyRewards make_pbmsg(){ return ::proto_ff::Sheet_GodvalleyRewards(); }
	};
	typedef struct Sheet_GodvalleyRewards_s Sheet_GodvalleyRewards_t;

}

