#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "Godvalley.pb.h"
#include "Godvalley_s.h"

namespace proto_ff_s {

	struct E_GodvalleyBattle_s : public NFDescStoreSeqOP {
		E_GodvalleyBattle_s();
		virtual ~E_GodvalleyBattle_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		NFShmString<60> m_team1n;
		NFShmString<60> m_team2n;
		int32_t m_killscore;
		int32_t m_killkeepscore;
		int32_t m_breakkillkeepscore;
		int32_t m_killmonsterscore;
		int32_t m_crystalscore;
		int32_t m_crystalreborntime;
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
		NFShmVector<struct E_GodvalleyBattle_s, 20> E_GodvalleyBattle_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodvalleyBattle & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodvalleyBattle & msg);
		static ::proto_ff::Sheet_GodvalleyBattle* new_pbmsg(){ return new ::proto_ff::Sheet_GodvalleyBattle(); }
		static ::proto_ff::Sheet_GodvalleyBattle make_pbmsg(){ return ::proto_ff::Sheet_GodvalleyBattle(); }
	};
	typedef struct Sheet_GodvalleyBattle_s Sheet_GodvalleyBattle_t;

}

