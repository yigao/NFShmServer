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
	m_Value = (int32_t)0;
	m_ID = (int64_t)0;
	return 0;
}

int E_AchievementAchievementItemrewardDesc_s::ResumeInit() {
	return 0;
}

void E_AchievementAchievementItemrewardDesc_s::write_to_pbmsg(::proto_ff::E_AchievementAchievementItemrewardDesc & msg) const {
	msg.set_m_value((int32_t)m_Value);
	msg.set_m_id((int64_t)m_ID);
}

void E_AchievementAchievementItemrewardDesc_s::read_from_pbmsg(const ::proto_ff::E_AchievementAchievementItemrewardDesc & msg) {
	m_Value = msg.m_value();
	m_ID = msg.m_id();
}

E_AchievementAchievement_s::E_AchievementAchievement_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AchievementAchievement_s::CreateInit() {
	m_achievementId = (int32_t)0;
	m_achievementLevel = (int32_t)0;
	m_achievementType = (int32_t)0;
	m_achievementSubType = (int32_t)0;
	m_SubType = (int32_t)0;
	m_achievementObjectValue = (int32_t)0;
	m_achievementPoint = (int32_t)0;
	m_Overview = (int32_t)0;
	return 0;
}

int E_AchievementAchievement_s::ResumeInit() {
	return 0;
}

void E_AchievementAchievement_s::write_to_pbmsg(::proto_ff::E_AchievementAchievement & msg) const {
	msg.set_m_achievementid((int32_t)m_achievementId);
	msg.set_m_achievementlevel((int32_t)m_achievementLevel);
	msg.set_m_achievementtype((int32_t)m_achievementType);
	msg.set_m_achievementsubtype((int32_t)m_achievementSubType);
	msg.set_m_subtype((int32_t)m_SubType);
	msg.set_m_achievementobjectvalue((int32_t)m_achievementObjectValue);
	msg.set_m_typename(m_typeName.data());
	msg.set_m_label(m_label.data());
	msg.set_m_achievementpoint((int32_t)m_achievementPoint);
	msg.set_m_overview((int32_t)m_Overview);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_itemReward.size(); ++i) {
		::proto_ff::E_AchievementAchievementItemrewardDesc* temp_m_itemreward = msg.add_m_itemreward();
		m_itemReward[i].write_to_pbmsg(*temp_m_itemreward);
	}
}

void E_AchievementAchievement_s::read_from_pbmsg(const ::proto_ff::E_AchievementAchievement & msg) {
	m_achievementId = msg.m_achievementid();
	m_achievementLevel = msg.m_achievementlevel();
	m_achievementType = msg.m_achievementtype();
	m_achievementSubType = msg.m_achievementsubtype();
	m_SubType = msg.m_subtype();
	m_achievementObjectValue = msg.m_achievementobjectvalue();
	m_typeName = msg.m_typename();
	m_label = msg.m_label();
	m_achievementPoint = msg.m_achievementpoint();
	m_Overview = msg.m_overview();
	m_param.resize((int)msg.m_param_size() > (int)m_param.max_size() ? m_param.max_size() : msg.m_param_size());
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		m_param[i] = msg.m_param(i);
	}
	m_itemReward.resize((int)msg.m_itemreward_size() > (int)m_itemReward.max_size() ? m_itemReward.max_size() : msg.m_itemreward_size());
	for(int32_t i = 0; i < (int32_t)m_itemReward.size(); ++i) {
		const ::proto_ff::E_AchievementAchievementItemrewardDesc & temp_m_itemreward = msg.m_itemreward(i);
		m_itemReward[i].read_from_pbmsg(temp_m_itemreward);
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
	m_totalSum = (int32_t)0;
	m_achievedPoints = (int32_t)0;
	m_totalItems = (int32_t)0;
	m_RewardValue = (int32_t)0;
	return 0;
}

int E_AchievementTotalachievements_s::ResumeInit() {
	return 0;
}

void E_AchievementTotalachievements_s::write_to_pbmsg(::proto_ff::E_AchievementTotalachievements & msg) const {
	msg.set_m_totalsum((int32_t)m_totalSum);
	msg.set_m_totalachievementname(m_totalAchievementName.data());
	msg.set_m_achievedpoints((int32_t)m_achievedPoints);
	msg.set_m_totalitems((int32_t)m_totalItems);
	msg.set_m_rewardvalue((int32_t)m_RewardValue);
}

void E_AchievementTotalachievements_s::read_from_pbmsg(const ::proto_ff::E_AchievementTotalachievements & msg) {
	m_totalSum = msg.m_totalsum();
	m_totalAchievementName = msg.m_totalachievementname();
	m_achievedPoints = msg.m_achievedpoints();
	m_totalItems = msg.m_totalitems();
	m_RewardValue = msg.m_rewardvalue();
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
