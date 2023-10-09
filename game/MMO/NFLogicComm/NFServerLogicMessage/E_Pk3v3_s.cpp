#include "E_Pk3v3_s.h"

namespace proto_ff_s {

E_Pk3v3Level_s::E_Pk3v3Level_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_Pk3v3Level_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_starnum = (int32_t)0;
	m_scoring = (int32_t)0;
	m_scoringadd = (int32_t)0;
	m_scoringcut = (int32_t)0;
	return 0;
}

int E_Pk3v3Level_s::ResumeInit() {
	return 0;
}

void E_Pk3v3Level_s::write_to_pbmsg(::proto_ff::E_Pk3v3Level & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_name(m_name.data());
	msg.set_m_starnum((int32_t)m_starnum);
	msg.set_m_scoring((int32_t)m_scoring);
	msg.set_m_badge(m_badge.data());
	msg.set_m_showbadge(m_showbadge.data());
	msg.set_m_scoringadd((int32_t)m_scoringadd);
	msg.set_m_scoringcut((int32_t)m_scoringcut);
}

void E_Pk3v3Level_s::read_from_pbmsg(const ::proto_ff::E_Pk3v3Level & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_name = msg.m_name();
	m_starnum = msg.m_starnum();
	m_scoring = msg.m_scoring();
	m_badge = msg.m_badge();
	m_showbadge = msg.m_showbadge();
	m_scoringadd = msg.m_scoringadd();
	m_scoringcut = msg.m_scoringcut();
}

Sheet_Pk3v3Level_s::Sheet_Pk3v3Level_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_Pk3v3Level_s::CreateInit() {
	return 0;
}

int Sheet_Pk3v3Level_s::ResumeInit() {
	return 0;
}

void Sheet_Pk3v3Level_s::write_to_pbmsg(::proto_ff::Sheet_Pk3v3Level & msg) const {
	for(int32_t i = 0; i < (int32_t)E_Pk3v3Level_List.size(); ++i) {
		::proto_ff::E_Pk3v3Level* temp_e_pk3v3level_list = msg.add_e_pk3v3level_list();
		E_Pk3v3Level_List[i].write_to_pbmsg(*temp_e_pk3v3level_list);
	}
}

void Sheet_Pk3v3Level_s::read_from_pbmsg(const ::proto_ff::Sheet_Pk3v3Level & msg) {
	E_Pk3v3Level_List.resize((int)msg.e_pk3v3level_list_size() > (int)E_Pk3v3Level_List.max_size() ? E_Pk3v3Level_List.max_size() : msg.e_pk3v3level_list_size());
	for(int32_t i = 0; i < (int32_t)E_Pk3v3Level_List.size(); ++i) {
		const ::proto_ff::E_Pk3v3Level & temp_e_pk3v3level_list = msg.e_pk3v3level_list(i);
		E_Pk3v3Level_List[i].read_from_pbmsg(temp_e_pk3v3level_list);
	}
}

E_Pk3v3Reward_s::E_Pk3v3Reward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_Pk3v3Reward_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_condition = (int32_t)0;
	m_reward = (int64_t)0;
	return 0;
}

int E_Pk3v3Reward_s::ResumeInit() {
	return 0;
}

void E_Pk3v3Reward_s::write_to_pbmsg(::proto_ff::E_Pk3v3Reward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_condition((int32_t)m_condition);
	msg.set_m_reward((int64_t)m_reward);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
}

void E_Pk3v3Reward_s::read_from_pbmsg(const ::proto_ff::E_Pk3v3Reward & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_condition = msg.m_condition();
	m_reward = msg.m_reward();
	m_param.resize((int)msg.m_param_size() > (int)m_param.max_size() ? m_param.max_size() : msg.m_param_size());
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		m_param[i] = msg.m_param(i);
	}
}

Sheet_Pk3v3Reward_s::Sheet_Pk3v3Reward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_Pk3v3Reward_s::CreateInit() {
	return 0;
}

int Sheet_Pk3v3Reward_s::ResumeInit() {
	return 0;
}

void Sheet_Pk3v3Reward_s::write_to_pbmsg(::proto_ff::Sheet_Pk3v3Reward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_Pk3v3Reward_List.size(); ++i) {
		::proto_ff::E_Pk3v3Reward* temp_e_pk3v3reward_list = msg.add_e_pk3v3reward_list();
		E_Pk3v3Reward_List[i].write_to_pbmsg(*temp_e_pk3v3reward_list);
	}
}

void Sheet_Pk3v3Reward_s::read_from_pbmsg(const ::proto_ff::Sheet_Pk3v3Reward & msg) {
	E_Pk3v3Reward_List.resize((int)msg.e_pk3v3reward_list_size() > (int)E_Pk3v3Reward_List.max_size() ? E_Pk3v3Reward_List.max_size() : msg.e_pk3v3reward_list_size());
	for(int32_t i = 0; i < (int32_t)E_Pk3v3Reward_List.size(); ++i) {
		const ::proto_ff::E_Pk3v3Reward & temp_e_pk3v3reward_list = msg.e_pk3v3reward_list(i);
		E_Pk3v3Reward_List[i].read_from_pbmsg(temp_e_pk3v3reward_list);
	}
}

E_Pk3v3Badge_s::E_Pk3v3Badge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_Pk3v3Badge_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_Pk3v3Badge_s::ResumeInit() {
	return 0;
}

void E_Pk3v3Badge_s::write_to_pbmsg(::proto_ff::E_Pk3v3Badge & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_type((int32_t)m_type);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
}

void E_Pk3v3Badge_s::read_from_pbmsg(const ::proto_ff::E_Pk3v3Badge & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_type = msg.m_type();
	m_param.resize((int)msg.m_param_size() > (int)m_param.max_size() ? m_param.max_size() : msg.m_param_size());
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		m_param[i] = msg.m_param(i);
	}
}

Sheet_Pk3v3Badge_s::Sheet_Pk3v3Badge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_Pk3v3Badge_s::CreateInit() {
	return 0;
}

int Sheet_Pk3v3Badge_s::ResumeInit() {
	return 0;
}

void Sheet_Pk3v3Badge_s::write_to_pbmsg(::proto_ff::Sheet_Pk3v3Badge & msg) const {
	for(int32_t i = 0; i < (int32_t)E_Pk3v3Badge_List.size(); ++i) {
		::proto_ff::E_Pk3v3Badge* temp_e_pk3v3badge_list = msg.add_e_pk3v3badge_list();
		E_Pk3v3Badge_List[i].write_to_pbmsg(*temp_e_pk3v3badge_list);
	}
}

void Sheet_Pk3v3Badge_s::read_from_pbmsg(const ::proto_ff::Sheet_Pk3v3Badge & msg) {
	E_Pk3v3Badge_List.resize((int)msg.e_pk3v3badge_list_size() > (int)E_Pk3v3Badge_List.max_size() ? E_Pk3v3Badge_List.max_size() : msg.e_pk3v3badge_list_size());
	for(int32_t i = 0; i < (int32_t)E_Pk3v3Badge_List.size(); ++i) {
		const ::proto_ff::E_Pk3v3Badge & temp_e_pk3v3badge_list = msg.e_pk3v3badge_list(i);
		E_Pk3v3Badge_List[i].read_from_pbmsg(temp_e_pk3v3badge_list);
	}
}

E_Pk3v3Constant_s::E_Pk3v3Constant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_Pk3v3Constant_s::CreateInit() {
	m_id = (int32_t)0;
	m_teammember = (int32_t)0;
	m_teamtoplimit = (int32_t)0;
	m_cedetime = (int32_t)0;
	m_punishtime = (int32_t)0;
	m_breaktime = (int32_t)0;
	m_entryreward = (int32_t)0;
	m_entrtimes = (int32_t)0;
	m_mvpreward = (int32_t)0;
	m_mvptimes = (int32_t)0;
	m_matchtime = (int32_t)0;
	m_unitname = (int32_t)0;
	m_unitcost = (int32_t)0;
	m_initialzlid = (int32_t)0;
	m_matetime = (int32_t)0;
	m_addtime = (int32_t)0;
	return 0;
}

int E_Pk3v3Constant_s::ResumeInit() {
	return 0;
}

void E_Pk3v3Constant_s::write_to_pbmsg(::proto_ff::E_Pk3v3Constant & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_teammember((int32_t)m_teammember);
	msg.set_m_teamtoplimit((int32_t)m_teamtoplimit);
	msg.set_m_cedetime((int32_t)m_cedetime);
	msg.set_m_punishtime((int32_t)m_punishtime);
	msg.set_m_breaktime((int32_t)m_breaktime);
	msg.set_m_entryreward((int32_t)m_entryreward);
	msg.set_m_entrtimes((int32_t)m_entrtimes);
	msg.set_m_mvpreward((int32_t)m_mvpreward);
	msg.set_m_mvptimes((int32_t)m_mvptimes);
	msg.set_m_matchtime((int32_t)m_matchtime);
	msg.set_m_unitname((int32_t)m_unitname);
	msg.set_m_unitcost((int32_t)m_unitcost);
	msg.set_m_initialzlid((int32_t)m_initialzlid);
	msg.set_m_initialzlname(m_initialzlname.data());
	msg.set_m_robotname(m_robotname.data());
	msg.set_m_matetime((int32_t)m_matetime);
	msg.set_m_addtime((int32_t)m_addtime);
	msg.set_m_initialnotice(m_initialnotice.data());
	for(int32_t i = 0; i < (int32_t)m_showreward.size(); ++i) {
		msg.add_m_showreward((int32_t)m_showreward[i]);
	}
}

void E_Pk3v3Constant_s::read_from_pbmsg(const ::proto_ff::E_Pk3v3Constant & msg) {
	m_id = msg.m_id();
	m_teammember = msg.m_teammember();
	m_teamtoplimit = msg.m_teamtoplimit();
	m_cedetime = msg.m_cedetime();
	m_punishtime = msg.m_punishtime();
	m_breaktime = msg.m_breaktime();
	m_entryreward = msg.m_entryreward();
	m_entrtimes = msg.m_entrtimes();
	m_mvpreward = msg.m_mvpreward();
	m_mvptimes = msg.m_mvptimes();
	m_matchtime = msg.m_matchtime();
	m_unitname = msg.m_unitname();
	m_unitcost = msg.m_unitcost();
	m_initialzlid = msg.m_initialzlid();
	m_initialzlname = msg.m_initialzlname();
	m_robotname = msg.m_robotname();
	m_matetime = msg.m_matetime();
	m_addtime = msg.m_addtime();
	m_initialnotice = msg.m_initialnotice();
	m_showreward.resize((int)msg.m_showreward_size() > (int)m_showreward.max_size() ? m_showreward.max_size() : msg.m_showreward_size());
	for(int32_t i = 0; i < (int32_t)m_showreward.size(); ++i) {
		m_showreward[i] = msg.m_showreward(i);
	}
}

Sheet_Pk3v3Constant_s::Sheet_Pk3v3Constant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_Pk3v3Constant_s::CreateInit() {
	return 0;
}

int Sheet_Pk3v3Constant_s::ResumeInit() {
	return 0;
}

void Sheet_Pk3v3Constant_s::write_to_pbmsg(::proto_ff::Sheet_Pk3v3Constant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_Pk3v3Constant_List.size(); ++i) {
		::proto_ff::E_Pk3v3Constant* temp_e_pk3v3constant_list = msg.add_e_pk3v3constant_list();
		E_Pk3v3Constant_List[i].write_to_pbmsg(*temp_e_pk3v3constant_list);
	}
}

void Sheet_Pk3v3Constant_s::read_from_pbmsg(const ::proto_ff::Sheet_Pk3v3Constant & msg) {
	E_Pk3v3Constant_List.resize((int)msg.e_pk3v3constant_list_size() > (int)E_Pk3v3Constant_List.max_size() ? E_Pk3v3Constant_List.max_size() : msg.e_pk3v3constant_list_size());
	for(int32_t i = 0; i < (int32_t)E_Pk3v3Constant_List.size(); ++i) {
		const ::proto_ff::E_Pk3v3Constant & temp_e_pk3v3constant_list = msg.e_pk3v3constant_list(i);
		E_Pk3v3Constant_List[i].read_from_pbmsg(temp_e_pk3v3constant_list);
	}
}

E_Pk3v3Exp_s::E_Pk3v3Exp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_Pk3v3Exp_s::CreateInit() {
	m_lv = (int32_t)0;
	m_mateexp = (int32_t)0;
	return 0;
}

int E_Pk3v3Exp_s::ResumeInit() {
	return 0;
}

void E_Pk3v3Exp_s::write_to_pbmsg(::proto_ff::E_Pk3v3Exp & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_mateexp((int32_t)m_mateexp);
}

void E_Pk3v3Exp_s::read_from_pbmsg(const ::proto_ff::E_Pk3v3Exp & msg) {
	m_lv = msg.m_lv();
	m_mateexp = msg.m_mateexp();
}

Sheet_Pk3v3Exp_s::Sheet_Pk3v3Exp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_Pk3v3Exp_s::CreateInit() {
	return 0;
}

int Sheet_Pk3v3Exp_s::ResumeInit() {
	return 0;
}

void Sheet_Pk3v3Exp_s::write_to_pbmsg(::proto_ff::Sheet_Pk3v3Exp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_Pk3v3Exp_List.size(); ++i) {
		::proto_ff::E_Pk3v3Exp* temp_e_pk3v3exp_list = msg.add_e_pk3v3exp_list();
		E_Pk3v3Exp_List[i].write_to_pbmsg(*temp_e_pk3v3exp_list);
	}
}

void Sheet_Pk3v3Exp_s::read_from_pbmsg(const ::proto_ff::Sheet_Pk3v3Exp & msg) {
	E_Pk3v3Exp_List.resize((int)msg.e_pk3v3exp_list_size() > (int)E_Pk3v3Exp_List.max_size() ? E_Pk3v3Exp_List.max_size() : msg.e_pk3v3exp_list_size());
	for(int32_t i = 0; i < (int32_t)E_Pk3v3Exp_List.size(); ++i) {
		const ::proto_ff::E_Pk3v3Exp & temp_e_pk3v3exp_list = msg.e_pk3v3exp_list(i);
		E_Pk3v3Exp_List[i].read_from_pbmsg(temp_e_pk3v3exp_list);
	}
}

}
