#include "Godvalley_s.h"

namespace proto_ff_s {

E_GodvalleyBattle_s::E_GodvalleyBattle_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodvalleyBattle_s::CreateInit() {
	m_id = (int64_t)0;
	m_killscore = (int32_t)0;
	m_killkeepscore = (int32_t)0;
	m_breakkillkeepscore = (int32_t)0;
	m_killmonsterscore = (int32_t)0;
	m_crystalscore = (int32_t)0;
	m_crystalreborntime = (int32_t)0;
	m_match_s = (int32_t)0;
	m_duration_s = (int32_t)0;
	m_matchmapid = (int64_t)0;
	m_mapid = (int64_t)0;
	return 0;
}

int E_GodvalleyBattle_s::ResumeInit() {
	return 0;
}

void E_GodvalleyBattle_s::write_to_pbmsg(::proto_ff::E_GodvalleyBattle & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_team1n((const char*)m_team1n.data());
	msg.set_m_team2n((const char*)m_team2n.data());
	msg.set_m_killscore((int32_t)m_killscore);
	msg.set_m_killkeepscore((int32_t)m_killkeepscore);
	msg.set_m_breakkillkeepscore((int32_t)m_breakkillkeepscore);
	msg.set_m_killmonsterscore((int32_t)m_killmonsterscore);
	msg.set_m_crystalscore((int32_t)m_crystalscore);
	msg.set_m_crystalreborntime((int32_t)m_crystalreborntime);
	msg.set_m_match_s((int32_t)m_match_s);
	msg.set_m_duration_s((int32_t)m_duration_s);
	msg.set_m_matchmapid((int64_t)m_matchmapid);
	msg.set_m_matchmapentry((const char*)m_matchmapentry.data());
	msg.set_m_mapid((int64_t)m_mapid);
	msg.set_m_mapentry1((const char*)m_mapentry1.data());
	msg.set_m_mapentry2((const char*)m_mapentry2.data());
	msg.set_m_monster1((const char*)m_monster1.data());
	msg.set_m_monster2((const char*)m_monster2.data());
	msg.set_m_monster3((const char*)m_monster3.data());
	msg.set_m_npc1pos((const char*)m_npc1pos.data());
	msg.set_m_npc2pos((const char*)m_npc2pos.data());
}

void E_GodvalleyBattle_s::read_from_pbmsg(const ::proto_ff::E_GodvalleyBattle & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GodvalleyBattle_s));
	m_id = msg.m_id();
	m_team1n = msg.m_team1n();
	m_team2n = msg.m_team2n();
	m_killscore = msg.m_killscore();
	m_killkeepscore = msg.m_killkeepscore();
	m_breakkillkeepscore = msg.m_breakkillkeepscore();
	m_killmonsterscore = msg.m_killmonsterscore();
	m_crystalscore = msg.m_crystalscore();
	m_crystalreborntime = msg.m_crystalreborntime();
	m_match_s = msg.m_match_s();
	m_duration_s = msg.m_duration_s();
	m_matchmapid = msg.m_matchmapid();
	m_matchmapentry = msg.m_matchmapentry();
	m_mapid = msg.m_mapid();
	m_mapentry1 = msg.m_mapentry1();
	m_mapentry2 = msg.m_mapentry2();
	m_monster1 = msg.m_monster1();
	m_monster2 = msg.m_monster2();
	m_monster3 = msg.m_monster3();
	m_npc1pos = msg.m_npc1pos();
	m_npc2pos = msg.m_npc2pos();
}

Sheet_GodvalleyBattle_s::Sheet_GodvalleyBattle_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodvalleyBattle_s::CreateInit() {
	return 0;
}

int Sheet_GodvalleyBattle_s::ResumeInit() {
	return 0;
}

void Sheet_GodvalleyBattle_s::write_to_pbmsg(::proto_ff::Sheet_GodvalleyBattle & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodvalleyBattle_List.size(); ++i) {
		::proto_ff::E_GodvalleyBattle* temp_e_godvalleybattle_list = msg.add_e_godvalleybattle_list();
		E_GodvalleyBattle_List[i].write_to_pbmsg(*temp_e_godvalleybattle_list);
	}
}

void Sheet_GodvalleyBattle_s::read_from_pbmsg(const ::proto_ff::Sheet_GodvalleyBattle & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GodvalleyBattle_s));
	E_GodvalleyBattle_List.resize((int)msg.e_godvalleybattle_list_size() > (int)E_GodvalleyBattle_List.max_size() ? E_GodvalleyBattle_List.max_size() : msg.e_godvalleybattle_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodvalleyBattle_List.size(); ++i) {
		const ::proto_ff::E_GodvalleyBattle & temp_e_godvalleybattle_list = msg.e_godvalleybattle_list(i);
		E_GodvalleyBattle_List[i].read_from_pbmsg(temp_e_godvalleybattle_list);
	}
}

}