#include "E_Daily_s.h"

namespace proto_ff_s {

E_DailyDaily_s::E_DailyDaily_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DailyDaily_s::CreateInit() {
	m_id = (int64_t)0;
	m_type = (int32_t)0;
	m_args = (int32_t)0;
	m_playType = (int32_t)0;
	m_playArgs = (int32_t)0;
	m_funciontID = (int64_t)0;
	m_number = (int32_t)0;
	m_eachScore = (int32_t)0;
	m_cycle = (int32_t)0;
	m_regReward = (int32_t)0;
	return 0;
}

int E_DailyDaily_s::ResumeInit() {
	return 0;
}

void E_DailyDaily_s::write_to_pbmsg(::proto_ff::E_DailyDaily & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_type((int32_t)m_type);
	msg.set_m_args((int32_t)m_args);
	msg.set_m_playtype((int32_t)m_playType);
	msg.set_m_playargs((int32_t)m_playArgs);
	msg.set_m_funciontid((int64_t)m_funciontID);
	msg.set_m_number((int32_t)m_number);
	msg.set_m_eachscore((int32_t)m_eachScore);
	msg.set_m_cycle((int32_t)m_cycle);
	msg.set_m_regreward((int32_t)m_regReward);
}

void E_DailyDaily_s::read_from_pbmsg(const ::proto_ff::E_DailyDaily & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_type = msg.m_type();
	m_args = msg.m_args();
	m_playType = msg.m_playtype();
	m_playArgs = msg.m_playargs();
	m_funciontID = msg.m_funciontid();
	m_number = msg.m_number();
	m_eachScore = msg.m_eachscore();
	m_cycle = msg.m_cycle();
	m_regReward = msg.m_regreward();
}

Sheet_DailyDaily_s::Sheet_DailyDaily_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DailyDaily_s::CreateInit() {
	return 0;
}

int Sheet_DailyDaily_s::ResumeInit() {
	return 0;
}

void Sheet_DailyDaily_s::write_to_pbmsg(::proto_ff::Sheet_DailyDaily & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DailyDaily_List.size(); ++i) {
		::proto_ff::E_DailyDaily* temp_e_dailydaily_list = msg.add_e_dailydaily_list();
		E_DailyDaily_List[i].write_to_pbmsg(*temp_e_dailydaily_list);
	}
}

void Sheet_DailyDaily_s::read_from_pbmsg(const ::proto_ff::Sheet_DailyDaily & msg) {
	E_DailyDaily_List.resize((int)msg.e_dailydaily_list_size() > (int)E_DailyDaily_List.max_size() ? E_DailyDaily_List.max_size() : msg.e_dailydaily_list_size());
	for(int32_t i = 0; i < (int32_t)E_DailyDaily_List.size(); ++i) {
		const ::proto_ff::E_DailyDaily & temp_e_dailydaily_list = msg.e_dailydaily_list(i);
		E_DailyDaily_List[i].read_from_pbmsg(temp_e_dailydaily_list);
	}
}

E_DailyReward_s::E_DailyReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DailyReward_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_activeScore = (int32_t)0;
	m_rewardId = (int64_t)0;
	m_rewardNum = (int32_t)0;
	return 0;
}

int E_DailyReward_s::ResumeInit() {
	return 0;
}

void E_DailyReward_s::write_to_pbmsg(::proto_ff::E_DailyReward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_activescore((int32_t)m_activeScore);
	msg.set_m_rewardid((int64_t)m_rewardId);
	msg.set_m_rewardnum((int32_t)m_rewardNum);
}

void E_DailyReward_s::read_from_pbmsg(const ::proto_ff::E_DailyReward & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_activeScore = msg.m_activescore();
	m_rewardId = msg.m_rewardid();
	m_rewardNum = msg.m_rewardnum();
}

Sheet_DailyReward_s::Sheet_DailyReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DailyReward_s::CreateInit() {
	return 0;
}

int Sheet_DailyReward_s::ResumeInit() {
	return 0;
}

void Sheet_DailyReward_s::write_to_pbmsg(::proto_ff::Sheet_DailyReward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DailyReward_List.size(); ++i) {
		::proto_ff::E_DailyReward* temp_e_dailyreward_list = msg.add_e_dailyreward_list();
		E_DailyReward_List[i].write_to_pbmsg(*temp_e_dailyreward_list);
	}
}

void Sheet_DailyReward_s::read_from_pbmsg(const ::proto_ff::Sheet_DailyReward & msg) {
	E_DailyReward_List.resize((int)msg.e_dailyreward_list_size() > (int)E_DailyReward_List.max_size() ? E_DailyReward_List.max_size() : msg.e_dailyreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_DailyReward_List.size(); ++i) {
		const ::proto_ff::E_DailyReward & temp_e_dailyreward_list = msg.e_dailyreward_list(i);
		E_DailyReward_List[i].read_from_pbmsg(temp_e_dailyreward_list);
	}
}

E_DailyCultivateAttributeDesc_s::E_DailyCultivateAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DailyCultivateAttributeDesc_s::CreateInit() {
	m_Value = (int32_t)0;
	m_ID = (int32_t)0;
	return 0;
}

int E_DailyCultivateAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_DailyCultivateAttributeDesc_s::write_to_pbmsg(::proto_ff::E_DailyCultivateAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_Value);
	msg.set_m_id((int32_t)m_ID);
}

void E_DailyCultivateAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_DailyCultivateAttributeDesc & msg) {
	m_Value = msg.m_value();
	m_ID = msg.m_id();
}

E_DailyCultivate_s::E_DailyCultivate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DailyCultivate_s::CreateInit() {
	m_ID = (int32_t)0;
	m_lv = (int32_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_DailyCultivate_s::ResumeInit() {
	return 0;
}

void E_DailyCultivate_s::write_to_pbmsg(::proto_ff::E_DailyCultivate & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int32_t)m_exp);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_DailyCultivateAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_DailyCultivate_s::read_from_pbmsg(const ::proto_ff::E_DailyCultivate & msg) {
	m_ID = msg.m_id();
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_DailyCultivateAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_DailyCultivate_s::Sheet_DailyCultivate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DailyCultivate_s::CreateInit() {
	return 0;
}

int Sheet_DailyCultivate_s::ResumeInit() {
	return 0;
}

void Sheet_DailyCultivate_s::write_to_pbmsg(::proto_ff::Sheet_DailyCultivate & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DailyCultivate_List.size(); ++i) {
		::proto_ff::E_DailyCultivate* temp_e_dailycultivate_list = msg.add_e_dailycultivate_list();
		E_DailyCultivate_List[i].write_to_pbmsg(*temp_e_dailycultivate_list);
	}
}

void Sheet_DailyCultivate_s::read_from_pbmsg(const ::proto_ff::Sheet_DailyCultivate & msg) {
	E_DailyCultivate_List.resize((int)msg.e_dailycultivate_list_size() > (int)E_DailyCultivate_List.max_size() ? E_DailyCultivate_List.max_size() : msg.e_dailycultivate_list_size());
	for(int32_t i = 0; i < (int32_t)E_DailyCultivate_List.size(); ++i) {
		const ::proto_ff::E_DailyCultivate & temp_e_dailycultivate_list = msg.e_dailycultivate_list(i);
		E_DailyCultivate_List[i].read_from_pbmsg(temp_e_dailycultivate_list);
	}
}

E_DailySports_s::E_DailySports_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DailySports_s::CreateInit() {
	m_id = (int32_t)0;
	m_functionID = (int32_t)0;
	m_perActivityid = (int32_t)0;
	m_des = (int32_t)0;
	m_linkid = (int32_t)0;
	return 0;
}

int E_DailySports_s::ResumeInit() {
	return 0;
}

void E_DailySports_s::write_to_pbmsg(::proto_ff::E_DailySports & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_functionid((int32_t)m_functionID);
	msg.set_m_peractivityid((int32_t)m_perActivityid);
	msg.set_m_des((int32_t)m_des);
	msg.set_m_linkid((int32_t)m_linkid);
}

void E_DailySports_s::read_from_pbmsg(const ::proto_ff::E_DailySports & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_functionID = msg.m_functionid();
	m_perActivityid = msg.m_peractivityid();
	m_des = msg.m_des();
	m_linkid = msg.m_linkid();
}

Sheet_DailySports_s::Sheet_DailySports_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DailySports_s::CreateInit() {
	return 0;
}

int Sheet_DailySports_s::ResumeInit() {
	return 0;
}

void Sheet_DailySports_s::write_to_pbmsg(::proto_ff::Sheet_DailySports & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DailySports_List.size(); ++i) {
		::proto_ff::E_DailySports* temp_e_dailysports_list = msg.add_e_dailysports_list();
		E_DailySports_List[i].write_to_pbmsg(*temp_e_dailysports_list);
	}
}

void Sheet_DailySports_s::read_from_pbmsg(const ::proto_ff::Sheet_DailySports & msg) {
	E_DailySports_List.resize((int)msg.e_dailysports_list_size() > (int)E_DailySports_List.max_size() ? E_DailySports_List.max_size() : msg.e_dailysports_list_size());
	for(int32_t i = 0; i < (int32_t)E_DailySports_List.size(); ++i) {
		const ::proto_ff::E_DailySports & temp_e_dailysports_list = msg.e_dailysports_list(i);
		E_DailySports_List[i].read_from_pbmsg(temp_e_dailysports_list);
	}
}

E_DailyHelper_s::E_DailyHelper_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DailyHelper_s::CreateInit() {
	m_helperID = (int32_t)0;
	m_helperType = (int32_t)0;
	m_linkId = (int32_t)0;
	return 0;
}

int E_DailyHelper_s::ResumeInit() {
	return 0;
}

void E_DailyHelper_s::write_to_pbmsg(::proto_ff::E_DailyHelper & msg) const {
	msg.set_m_helperid((int32_t)m_helperID);
	msg.set_m_helpertype((int32_t)m_helperType);
	msg.set_m_playid(m_playID.data());
	msg.set_m_linkid((int32_t)m_linkId);
	msg.set_m_name(m_name.data());
	msg.set_m_condition(m_condition.data());
}

void E_DailyHelper_s::read_from_pbmsg(const ::proto_ff::E_DailyHelper & msg) {
	m_helperID = msg.m_helperid();
	m_helperType = msg.m_helpertype();
	m_playID = msg.m_playid();
	m_linkId = msg.m_linkid();
	m_name = msg.m_name();
	m_condition = msg.m_condition();
}

Sheet_DailyHelper_s::Sheet_DailyHelper_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DailyHelper_s::CreateInit() {
	return 0;
}

int Sheet_DailyHelper_s::ResumeInit() {
	return 0;
}

void Sheet_DailyHelper_s::write_to_pbmsg(::proto_ff::Sheet_DailyHelper & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DailyHelper_List.size(); ++i) {
		::proto_ff::E_DailyHelper* temp_e_dailyhelper_list = msg.add_e_dailyhelper_list();
		E_DailyHelper_List[i].write_to_pbmsg(*temp_e_dailyhelper_list);
	}
}

void Sheet_DailyHelper_s::read_from_pbmsg(const ::proto_ff::Sheet_DailyHelper & msg) {
	E_DailyHelper_List.resize((int)msg.e_dailyhelper_list_size() > (int)E_DailyHelper_List.max_size() ? E_DailyHelper_List.max_size() : msg.e_dailyhelper_list_size());
	for(int32_t i = 0; i < (int32_t)E_DailyHelper_List.size(); ++i) {
		const ::proto_ff::E_DailyHelper & temp_e_dailyhelper_list = msg.e_dailyhelper_list(i);
		E_DailyHelper_List[i].read_from_pbmsg(temp_e_dailyhelper_list);
	}
}

}
