#include "E_Achievement_s.h"

namespace proto_ff_s {

E_AchievementAchievementItemrewardDesc_s::E_AchievementAchievementItemrewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AchievementAchievementItemrewardDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_id = (int64_t)0;
	return 0;
}

int E_AchievementAchievementItemrewardDesc_s::ResumeInit() {
	return 0;
}

void E_AchievementAchievementItemrewardDesc_s::write_to_pbmsg(::proto_ff::E_AchievementAchievementItemrewardDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_id((int64_t)m_id);
}

void E_AchievementAchievementItemrewardDesc_s::read_from_pbmsg(const ::proto_ff::E_AchievementAchievementItemrewardDesc & msg) {
	m_value = msg.m_value();
	m_id = msg.m_id();
}

E_AchievementAchievement_s::E_AchievementAchievement_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AchievementAchievement_s::CreateInit() {
	m_achievementid = (int32_t)0;
	m_achievementlevel = (int32_t)0;
	m_achievementtype = (int32_t)0;
	m_achievementsubtype = (int32_t)0;
	m_subtype = (int32_t)0;
	m_achievementobjectvalue = (int32_t)0;
	m_achievementpoint = (int32_t)0;
	m_overview = (int32_t)0;
	return 0;
}

int E_AchievementAchievement_s::ResumeInit() {
	return 0;
}

void E_AchievementAchievement_s::write_to_pbmsg(::proto_ff::E_AchievementAchievement & msg) const {
	msg.set_m_achievementid((int32_t)m_achievementid);
	msg.set_m_achievementlevel((int32_t)m_achievementlevel);
	msg.set_m_achievementtype((int32_t)m_achievementtype);
	msg.set_m_achievementsubtype((int32_t)m_achievementsubtype);
	msg.set_m_subtype((int32_t)m_subtype);
	msg.set_m_achievementobjectvalue((int32_t)m_achievementobjectvalue);
	msg.set_m_typename(m_typename.data());
	msg.set_m_label(m_label.data());
	msg.set_m_achievementpoint((int32_t)m_achievementpoint);
	msg.set_m_overview((int32_t)m_overview);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_itemreward.size(); ++i) {
		::proto_ff::E_AchievementAchievementItemrewardDesc* temp_m_itemreward = msg.add_m_itemreward();
		m_itemreward[i].write_to_pbmsg(*temp_m_itemreward);
	}
}

void E_AchievementAchievement_s::read_from_pbmsg(const ::proto_ff::E_AchievementAchievement & msg) {
	m_achievementid = msg.m_achievementid();
	m_achievementlevel = msg.m_achievementlevel();
	m_achievementtype = msg.m_achievementtype();
	m_achievementsubtype = msg.m_achievementsubtype();
	m_subtype = msg.m_subtype();
	m_achievementobjectvalue = msg.m_achievementobjectvalue();
	m_typename = msg.m_typename();
	m_label = msg.m_label();
	m_achievementpoint = msg.m_achievementpoint();
	m_overview = msg.m_overview();
	m_param.resize((int)msg.m_param_size() > (int)m_param.max_size() ? m_param.max_size() : msg.m_param_size());
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		m_param[i] = msg.m_param(i);
	}
	m_itemreward.resize((int)msg.m_itemreward_size() > (int)m_itemreward.max_size() ? m_itemreward.max_size() : msg.m_itemreward_size());
	for(int32_t i = 0; i < (int32_t)m_itemreward.size(); ++i) {
		const ::proto_ff::E_AchievementAchievementItemrewardDesc & temp_m_itemreward = msg.m_itemreward(i);
		m_itemreward[i].read_from_pbmsg(temp_m_itemreward);
	}
}

Sheet_AchievementAchievement_s::Sheet_AchievementAchievement_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AchievementAchievement_s::CreateInit() {
	return 0;
}

int Sheet_AchievementAchievement_s::ResumeInit() {
	return 0;
}

void Sheet_AchievementAchievement_s::write_to_pbmsg(::proto_ff::Sheet_AchievementAchievement & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AchievementAchievement_List.size(); ++i) {
		::proto_ff::E_AchievementAchievement* temp_e_achievementachievement_list = msg.add_e_achievementachievement_list();
		E_AchievementAchievement_List[i].write_to_pbmsg(*temp_e_achievementachievement_list);
	}
}

void Sheet_AchievementAchievement_s::read_from_pbmsg(const ::proto_ff::Sheet_AchievementAchievement & msg) {
	E_AchievementAchievement_List.resize((int)msg.e_achievementachievement_list_size() > (int)E_AchievementAchievement_List.max_size() ? E_AchievementAchievement_List.max_size() : msg.e_achievementachievement_list_size());
	for(int32_t i = 0; i < (int32_t)E_AchievementAchievement_List.size(); ++i) {
		const ::proto_ff::E_AchievementAchievement & temp_e_achievementachievement_list = msg.e_achievementachievement_list(i);
		E_AchievementAchievement_List[i].read_from_pbmsg(temp_e_achievementachievement_list);
	}
}

E_AchievementTotalachievements_s::E_AchievementTotalachievements_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AchievementTotalachievements_s::CreateInit() {
	m_totalsum = (int32_t)0;
	m_achievedpoints = (int32_t)0;
	m_totalitems = (int32_t)0;
	m_rewardvalue = (int32_t)0;
	return 0;
}

int E_AchievementTotalachievements_s::ResumeInit() {
	return 0;
}

void E_AchievementTotalachievements_s::write_to_pbmsg(::proto_ff::E_AchievementTotalachievements & msg) const {
	msg.set_m_totalsum((int32_t)m_totalsum);
	msg.set_m_totalachievementname(m_totalachievementname.data());
	msg.set_m_achievedpoints((int32_t)m_achievedpoints);
	msg.set_m_totalitems((int32_t)m_totalitems);
	msg.set_m_rewardvalue((int32_t)m_rewardvalue);
}

void E_AchievementTotalachievements_s::read_from_pbmsg(const ::proto_ff::E_AchievementTotalachievements & msg) {
	m_totalsum = msg.m_totalsum();
	m_totalachievementname = msg.m_totalachievementname();
	m_achievedpoints = msg.m_achievedpoints();
	m_totalitems = msg.m_totalitems();
	m_rewardvalue = msg.m_rewardvalue();
}

Sheet_AchievementTotalachievements_s::Sheet_AchievementTotalachievements_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AchievementTotalachievements_s::CreateInit() {
	return 0;
}

int Sheet_AchievementTotalachievements_s::ResumeInit() {
	return 0;
}

void Sheet_AchievementTotalachievements_s::write_to_pbmsg(::proto_ff::Sheet_AchievementTotalachievements & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AchievementTotalachievements_List.size(); ++i) {
		::proto_ff::E_AchievementTotalachievements* temp_e_achievementtotalachievements_list = msg.add_e_achievementtotalachievements_list();
		E_AchievementTotalachievements_List[i].write_to_pbmsg(*temp_e_achievementtotalachievements_list);
	}
}

void Sheet_AchievementTotalachievements_s::read_from_pbmsg(const ::proto_ff::Sheet_AchievementTotalachievements & msg) {
	E_AchievementTotalachievements_List.resize((int)msg.e_achievementtotalachievements_list_size() > (int)E_AchievementTotalachievements_List.max_size() ? E_AchievementTotalachievements_List.max_size() : msg.e_achievementtotalachievements_list_size());
	for(int32_t i = 0; i < (int32_t)E_AchievementTotalachievements_List.size(); ++i) {
		const ::proto_ff::E_AchievementTotalachievements & temp_e_achievementtotalachievements_list = msg.e_achievementtotalachievements_list(i);
		E_AchievementTotalachievements_List[i].read_from_pbmsg(temp_e_achievementtotalachievements_list);
	}
}

}
