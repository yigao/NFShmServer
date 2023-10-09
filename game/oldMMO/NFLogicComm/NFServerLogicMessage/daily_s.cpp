#include "daily_s.h"

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
	m_playtype = (int32_t)0;
	m_playargs = (int32_t)0;
	m_funciontid = (int64_t)0;
	m_number = (int32_t)0;
	m_eachscore = (int32_t)0;
	m_cycle = (int32_t)0;
	m_regreward = (int32_t)0;
	return 0;
}

int E_DailyDaily_s::ResumeInit() {
	return 0;
}

void E_DailyDaily_s::write_to_pbmsg(::proto_ff::E_DailyDaily & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_name((const char*)m_name.data());
	msg.set_m_type((int32_t)m_type);
	msg.set_m_args((int32_t)m_args);
	msg.set_m_playtype((int32_t)m_playtype);
	msg.set_m_playargs((int32_t)m_playargs);
	msg.set_m_funciontid((int64_t)m_funciontid);
	msg.set_m_number((int32_t)m_number);
	msg.set_m_eachscore((int32_t)m_eachscore);
	msg.set_m_cycle((int32_t)m_cycle);
	msg.set_m_regreward((int32_t)m_regreward);
}

void E_DailyDaily_s::read_from_pbmsg(const ::proto_ff::E_DailyDaily & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_DailyDaily_s));
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_type = msg.m_type();
	m_args = msg.m_args();
	m_playtype = msg.m_playtype();
	m_playargs = msg.m_playargs();
	m_funciontid = msg.m_funciontid();
	m_number = msg.m_number();
	m_eachscore = msg.m_eachscore();
	m_cycle = msg.m_cycle();
	m_regreward = msg.m_regreward();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_DailyDaily_s));
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
	m_activescore = (int32_t)0;
	m_rewardid = (int64_t)0;
	m_rewardnum = (int32_t)0;
	return 0;
}

int E_DailyReward_s::ResumeInit() {
	return 0;
}

void E_DailyReward_s::write_to_pbmsg(::proto_ff::E_DailyReward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_activescore((int32_t)m_activescore);
	msg.set_m_rewardid((int64_t)m_rewardid);
	msg.set_m_rewardnum((int32_t)m_rewardnum);
}

void E_DailyReward_s::read_from_pbmsg(const ::proto_ff::E_DailyReward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_DailyReward_s));
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_activescore = msg.m_activescore();
	m_rewardid = msg.m_rewardid();
	m_rewardnum = msg.m_rewardnum();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_DailyReward_s));
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
	m_id = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_DailyCultivateAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_DailyCultivateAttributeDesc_s::write_to_pbmsg(::proto_ff::E_DailyCultivateAttributeDesc & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_value((int32_t)m_value);
}

void E_DailyCultivateAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_DailyCultivateAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_DailyCultivateAttributeDesc_s));
	m_id = msg.m_id();
	m_value = msg.m_value();
}

E_DailyCultivate_s::E_DailyCultivate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DailyCultivate_s::CreateInit() {
	m_id = (int32_t)0;
	m_lv = (int32_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_DailyCultivate_s::ResumeInit() {
	return 0;
}

void E_DailyCultivate_s::write_to_pbmsg(::proto_ff::E_DailyCultivate & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int32_t)m_exp);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_DailyCultivateAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_DailyCultivate_s::read_from_pbmsg(const ::proto_ff::E_DailyCultivate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_DailyCultivate_s));
	m_id = msg.m_id();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_DailyCultivate_s));
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
	m_functionid = (int32_t)0;
	m_peractivityid = (int32_t)0;
	m_des = (int32_t)0;
	m_linkid = (int32_t)0;
	return 0;
}

int E_DailySports_s::ResumeInit() {
	return 0;
}

void E_DailySports_s::write_to_pbmsg(::proto_ff::E_DailySports & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name((const char*)m_name.data());
	msg.set_m_functionid((int32_t)m_functionid);
	msg.set_m_peractivityid((int32_t)m_peractivityid);
	msg.set_m_des((int32_t)m_des);
	msg.set_m_linkid((int32_t)m_linkid);
}

void E_DailySports_s::read_from_pbmsg(const ::proto_ff::E_DailySports & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_DailySports_s));
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_functionid = msg.m_functionid();
	m_peractivityid = msg.m_peractivityid();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_DailySports_s));
	E_DailySports_List.resize((int)msg.e_dailysports_list_size() > (int)E_DailySports_List.max_size() ? E_DailySports_List.max_size() : msg.e_dailysports_list_size());
	for(int32_t i = 0; i < (int32_t)E_DailySports_List.size(); ++i) {
		const ::proto_ff::E_DailySports & temp_e_dailysports_list = msg.e_dailysports_list(i);
		E_DailySports_List[i].read_from_pbmsg(temp_e_dailysports_list);
	}
}

}