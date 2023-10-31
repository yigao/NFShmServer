#include "E_Escort_s.h"

namespace proto_ff_s {

E_EscortEscort_s::E_EscortEscort_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EscortEscort_s::CreateInit() {
	m_convoyId = (int32_t)0;
	m_MonsterId = (int32_t)0;
	m_convoyLevel = (int32_t)0;
	m_chance = (int32_t)0;
	m_rewardLvMultiply = (int32_t)0;
	return 0;
}

int E_EscortEscort_s::ResumeInit() {
	return 0;
}

void E_EscortEscort_s::write_to_pbmsg(::proto_ff::E_EscortEscort & msg) const {
	msg.set_m_convoyid((int32_t)m_convoyId);
	msg.set_m_convoyname(m_convoyName.data());
	msg.set_m_monsterid((int32_t)m_MonsterId);
	msg.set_m_scalle(m_scalle.data());
	msg.set_m_convoylevel((int32_t)m_convoyLevel);
	msg.set_m_chance((int32_t)m_chance);
	msg.set_m_rewardlvmultiply((int32_t)m_rewardLvMultiply);
}

void E_EscortEscort_s::read_from_pbmsg(const ::proto_ff::E_EscortEscort & msg) {
	m_convoyId = msg.m_convoyid();
	m_convoyName = msg.m_convoyname();
	m_MonsterId = msg.m_monsterid();
	m_scalle = msg.m_scalle();
	m_convoyLevel = msg.m_convoylevel();
	m_chance = msg.m_chance();
	m_rewardLvMultiply = msg.m_rewardlvmultiply();
}

Sheet_EscortEscort_s::Sheet_EscortEscort_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EscortEscort_s::CreateInit() {
	return 0;
}

int Sheet_EscortEscort_s::ResumeInit() {
	return 0;
}

void Sheet_EscortEscort_s::write_to_pbmsg(::proto_ff::Sheet_EscortEscort & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EscortEscort_List.size(); ++i) {
		::proto_ff::E_EscortEscort* temp_e_escortescort_list = msg.add_e_escortescort_list();
		E_EscortEscort_List[i].write_to_pbmsg(*temp_e_escortescort_list);
	}
}

void Sheet_EscortEscort_s::read_from_pbmsg(const ::proto_ff::Sheet_EscortEscort & msg) {
	E_EscortEscort_List.resize((int)msg.e_escortescort_list_size() > (int)E_EscortEscort_List.max_size() ? E_EscortEscort_List.max_size() : msg.e_escortescort_list_size());
	for(int32_t i = 0; i < (int32_t)E_EscortEscort_List.size(); ++i) {
		const ::proto_ff::E_EscortEscort & temp_e_escortescort_list = msg.e_escortescort_list(i);
		E_EscortEscort_List[i].read_from_pbmsg(temp_e_escortescort_list);
	}
}

E_EscortChanceEscortDesc_s::E_EscortChanceEscortDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EscortChanceEscortDesc_s::CreateInit() {
	m_chance = (int32_t)0;
	m_ID = (int32_t)0;
	return 0;
}

int E_EscortChanceEscortDesc_s::ResumeInit() {
	return 0;
}

void E_EscortChanceEscortDesc_s::write_to_pbmsg(::proto_ff::E_EscortChanceEscortDesc & msg) const {
	msg.set_m_chance((int32_t)m_chance);
	msg.set_m_id((int32_t)m_ID);
}

void E_EscortChanceEscortDesc_s::read_from_pbmsg(const ::proto_ff::E_EscortChanceEscortDesc & msg) {
	m_chance = msg.m_chance();
	m_ID = msg.m_id();
}

E_EscortChance_s::E_EscortChance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EscortChance_s::CreateInit() {
	m_convoyId = (int32_t)0;
	return 0;
}

int E_EscortChance_s::ResumeInit() {
	return 0;
}

void E_EscortChance_s::write_to_pbmsg(::proto_ff::E_EscortChance & msg) const {
	msg.set_m_convoyid((int32_t)m_convoyId);
	for(int32_t i = 0; i < (int32_t)m_escort.size(); ++i) {
		::proto_ff::E_EscortChanceEscortDesc* temp_m_escort = msg.add_m_escort();
		m_escort[i].write_to_pbmsg(*temp_m_escort);
	}
}

void E_EscortChance_s::read_from_pbmsg(const ::proto_ff::E_EscortChance & msg) {
	m_convoyId = msg.m_convoyid();
	m_escort.resize((int)msg.m_escort_size() > (int)m_escort.max_size() ? m_escort.max_size() : msg.m_escort_size());
	for(int32_t i = 0; i < (int32_t)m_escort.size(); ++i) {
		const ::proto_ff::E_EscortChanceEscortDesc & temp_m_escort = msg.m_escort(i);
		m_escort[i].read_from_pbmsg(temp_m_escort);
	}
}

Sheet_EscortChance_s::Sheet_EscortChance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EscortChance_s::CreateInit() {
	return 0;
}

int Sheet_EscortChance_s::ResumeInit() {
	return 0;
}

void Sheet_EscortChance_s::write_to_pbmsg(::proto_ff::Sheet_EscortChance & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EscortChance_List.size(); ++i) {
		::proto_ff::E_EscortChance* temp_e_escortchance_list = msg.add_e_escortchance_list();
		E_EscortChance_List[i].write_to_pbmsg(*temp_e_escortchance_list);
	}
}

void Sheet_EscortChance_s::read_from_pbmsg(const ::proto_ff::Sheet_EscortChance & msg) {
	E_EscortChance_List.resize((int)msg.e_escortchance_list_size() > (int)E_EscortChance_List.max_size() ? E_EscortChance_List.max_size() : msg.e_escortchance_list_size());
	for(int32_t i = 0; i < (int32_t)E_EscortChance_List.size(); ++i) {
		const ::proto_ff::E_EscortChance & temp_e_escortchance_list = msg.e_escortchance_list(i);
		E_EscortChance_List[i].read_from_pbmsg(temp_e_escortchance_list);
	}
}

E_EscortRewardRewardDesc_s::E_EscortRewardRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EscortRewardRewardDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_item = (int32_t)0;
	m_ID = (int32_t)0;
	return 0;
}

int E_EscortRewardRewardDesc_s::ResumeInit() {
	return 0;
}

void E_EscortRewardRewardDesc_s::write_to_pbmsg(::proto_ff::E_EscortRewardRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_item((int32_t)m_item);
	msg.set_m_id((int32_t)m_ID);
}

void E_EscortRewardRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_EscortRewardRewardDesc & msg) {
	m_num = msg.m_num();
	m_item = msg.m_item();
	m_ID = msg.m_id();
}

E_EscortReward_s::E_EscortReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EscortReward_s::CreateInit() {
	m_lv = (int32_t)0;
	m_exp = (int64_t)0;
	return 0;
}

int E_EscortReward_s::ResumeInit() {
	return 0;
}

void E_EscortReward_s::write_to_pbmsg(::proto_ff::E_EscortReward & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int64_t)m_exp);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_EscortRewardRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_EscortReward_s::read_from_pbmsg(const ::proto_ff::E_EscortReward & msg) {
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_EscortRewardRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_EscortReward_s::Sheet_EscortReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EscortReward_s::CreateInit() {
	return 0;
}

int Sheet_EscortReward_s::ResumeInit() {
	return 0;
}

void Sheet_EscortReward_s::write_to_pbmsg(::proto_ff::Sheet_EscortReward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EscortReward_List.size(); ++i) {
		::proto_ff::E_EscortReward* temp_e_escortreward_list = msg.add_e_escortreward_list();
		E_EscortReward_List[i].write_to_pbmsg(*temp_e_escortreward_list);
	}
}

void Sheet_EscortReward_s::read_from_pbmsg(const ::proto_ff::Sheet_EscortReward & msg) {
	E_EscortReward_List.resize((int)msg.e_escortreward_list_size() > (int)E_EscortReward_List.max_size() ? E_EscortReward_List.max_size() : msg.e_escortreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_EscortReward_List.size(); ++i) {
		const ::proto_ff::E_EscortReward & temp_e_escortreward_list = msg.e_escortreward_list(i);
		E_EscortReward_List[i].read_from_pbmsg(temp_e_escortreward_list);
	}
}

E_EscortConst_s::E_EscortConst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EscortConst_s::CreateInit() {
	m_id = (int32_t)0;
	m_tokenId = (int32_t)0;
	m_tokenNumber = (int32_t)0;
	m_dayTime = (int32_t)0;
	m_freeNum = (int32_t)0;
	m_mapId = (int32_t)0;
	m_startNpcID = (int32_t)0;
	m_startNpcPointID = (int32_t)0;
	m_overNpcID = (int32_t)0;
	m_activityID = (int32_t)0;
	m_taskID = (int32_t)0;
	m_DistanceA = (int32_t)0;
	m_DistanceB = (int32_t)0;
	m_DistanceC = (int32_t)0;
	m_timeLimit = (int32_t)0;
	return 0;
}

int E_EscortConst_s::ResumeInit() {
	return 0;
}

void E_EscortConst_s::write_to_pbmsg(::proto_ff::E_EscortConst & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_tokenid((int32_t)m_tokenId);
	msg.set_m_tokennumber((int32_t)m_tokenNumber);
	msg.set_m_daytime((int32_t)m_dayTime);
	msg.set_m_freenum((int32_t)m_freeNum);
	msg.set_m_mapid((int32_t)m_mapId);
	msg.set_m_startnpcid((int32_t)m_startNpcID);
	msg.set_m_startnpcpointid((int32_t)m_startNpcPointID);
	msg.set_m_overnpcid((int32_t)m_overNpcID);
	msg.set_m_activityid((int32_t)m_activityID);
	msg.set_m_taskid((int32_t)m_taskID);
	msg.set_m_distancea((int32_t)m_DistanceA);
	msg.set_m_distanceb((int32_t)m_DistanceB);
	msg.set_m_distancec((int32_t)m_DistanceC);
	msg.set_m_timelimit((int32_t)m_timeLimit);
}

void E_EscortConst_s::read_from_pbmsg(const ::proto_ff::E_EscortConst & msg) {
	m_id = msg.m_id();
	m_tokenId = msg.m_tokenid();
	m_tokenNumber = msg.m_tokennumber();
	m_dayTime = msg.m_daytime();
	m_freeNum = msg.m_freenum();
	m_mapId = msg.m_mapid();
	m_startNpcID = msg.m_startnpcid();
	m_startNpcPointID = msg.m_startnpcpointid();
	m_overNpcID = msg.m_overnpcid();
	m_activityID = msg.m_activityid();
	m_taskID = msg.m_taskid();
	m_DistanceA = msg.m_distancea();
	m_DistanceB = msg.m_distanceb();
	m_DistanceC = msg.m_distancec();
	m_timeLimit = msg.m_timelimit();
}

Sheet_EscortConst_s::Sheet_EscortConst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EscortConst_s::CreateInit() {
	return 0;
}

int Sheet_EscortConst_s::ResumeInit() {
	return 0;
}

void Sheet_EscortConst_s::write_to_pbmsg(::proto_ff::Sheet_EscortConst & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EscortConst_List.size(); ++i) {
		::proto_ff::E_EscortConst* temp_e_escortconst_list = msg.add_e_escortconst_list();
		E_EscortConst_List[i].write_to_pbmsg(*temp_e_escortconst_list);
	}
}

void Sheet_EscortConst_s::read_from_pbmsg(const ::proto_ff::Sheet_EscortConst & msg) {
	E_EscortConst_List.resize((int)msg.e_escortconst_list_size() > (int)E_EscortConst_List.max_size() ? E_EscortConst_List.max_size() : msg.e_escortconst_list_size());
	for(int32_t i = 0; i < (int32_t)E_EscortConst_List.size(); ++i) {
		const ::proto_ff::E_EscortConst & temp_e_escortconst_list = msg.e_escortconst_list(i);
		E_EscortConst_List[i].read_from_pbmsg(temp_e_escortconst_list);
	}
}

}
