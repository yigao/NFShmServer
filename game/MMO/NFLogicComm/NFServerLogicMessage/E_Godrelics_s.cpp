#include "E_Godrelics_s.h"

namespace proto_ff_s {

E_GodrelicsGodrelics_s::E_GodrelicsGodrelics_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodrelicsGodrelics_s::CreateInit() {
	m_id = (int32_t)0;
	m_functionId = (int32_t)0;
	m_group = (int32_t)0;
	m_skillID = (int32_t)0;
	return 0;
}

int E_GodrelicsGodrelics_s::ResumeInit() {
	return 0;
}

void E_GodrelicsGodrelics_s::write_to_pbmsg(::proto_ff::E_GodrelicsGodrelics & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_functionid((int32_t)m_functionId);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_skillid((int32_t)m_skillID);
}

void E_GodrelicsGodrelics_s::read_from_pbmsg(const ::proto_ff::E_GodrelicsGodrelics & msg) {
	m_id = msg.m_id();
	m_functionId = msg.m_functionid();
	m_group = msg.m_group();
	m_skillID = msg.m_skillid();
}

Sheet_GodrelicsGodrelics_s::Sheet_GodrelicsGodrelics_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodrelicsGodrelics_s::CreateInit() {
	return 0;
}

int Sheet_GodrelicsGodrelics_s::ResumeInit() {
	return 0;
}

void Sheet_GodrelicsGodrelics_s::write_to_pbmsg(::proto_ff::Sheet_GodrelicsGodrelics & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodrelicsGodrelics_List.size(); ++i) {
		::proto_ff::E_GodrelicsGodrelics* temp_e_godrelicsgodrelics_list = msg.add_e_godrelicsgodrelics_list();
		E_GodrelicsGodrelics_List[i].write_to_pbmsg(*temp_e_godrelicsgodrelics_list);
	}
}

void Sheet_GodrelicsGodrelics_s::read_from_pbmsg(const ::proto_ff::Sheet_GodrelicsGodrelics & msg) {
	E_GodrelicsGodrelics_List.resize((int)msg.e_godrelicsgodrelics_list_size() > (int)E_GodrelicsGodrelics_List.max_size() ? E_GodrelicsGodrelics_List.max_size() : msg.e_godrelicsgodrelics_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodrelicsGodrelics_List.size(); ++i) {
		const ::proto_ff::E_GodrelicsGodrelics & temp_e_godrelicsgodrelics_list = msg.e_godrelicsgodrelics_list(i);
		E_GodrelicsGodrelics_List[i].read_from_pbmsg(temp_e_godrelicsgodrelics_list);
	}
}

E_GodrelicsCondition_s::E_GodrelicsCondition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodrelicsCondition_s::CreateInit() {
	m_id = (int32_t)0;
	m_group = (int32_t)0;
	m_conditon = (int32_t)0;
	m_count = (int32_t)0;
	m_rewardItem = (int32_t)0;
	m_rewardNumber = (int32_t)0;
	m_determine = (int32_t)0;
	return 0;
}

int E_GodrelicsCondition_s::ResumeInit() {
	return 0;
}

void E_GodrelicsCondition_s::write_to_pbmsg(::proto_ff::E_GodrelicsCondition & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_conditon((int32_t)m_conditon);
	msg.set_m_count((int32_t)m_count);
	msg.set_m_rewarditem((int32_t)m_rewardItem);
	msg.set_m_rewardnumber((int32_t)m_rewardNumber);
	msg.set_m_determine((int32_t)m_determine);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
}

void E_GodrelicsCondition_s::read_from_pbmsg(const ::proto_ff::E_GodrelicsCondition & msg) {
	m_id = msg.m_id();
	m_group = msg.m_group();
	m_conditon = msg.m_conditon();
	m_count = msg.m_count();
	m_rewardItem = msg.m_rewarditem();
	m_rewardNumber = msg.m_rewardnumber();
	m_determine = msg.m_determine();
	m_param.resize((int)msg.m_param_size() > (int)m_param.max_size() ? m_param.max_size() : msg.m_param_size());
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		m_param[i] = msg.m_param(i);
	}
}

Sheet_GodrelicsCondition_s::Sheet_GodrelicsCondition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodrelicsCondition_s::CreateInit() {
	return 0;
}

int Sheet_GodrelicsCondition_s::ResumeInit() {
	return 0;
}

void Sheet_GodrelicsCondition_s::write_to_pbmsg(::proto_ff::Sheet_GodrelicsCondition & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodrelicsCondition_List.size(); ++i) {
		::proto_ff::E_GodrelicsCondition* temp_e_godrelicscondition_list = msg.add_e_godrelicscondition_list();
		E_GodrelicsCondition_List[i].write_to_pbmsg(*temp_e_godrelicscondition_list);
	}
}

void Sheet_GodrelicsCondition_s::read_from_pbmsg(const ::proto_ff::Sheet_GodrelicsCondition & msg) {
	E_GodrelicsCondition_List.resize((int)msg.e_godrelicscondition_list_size() > (int)E_GodrelicsCondition_List.max_size() ? E_GodrelicsCondition_List.max_size() : msg.e_godrelicscondition_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodrelicsCondition_List.size(); ++i) {
		const ::proto_ff::E_GodrelicsCondition & temp_e_godrelicscondition_list = msg.e_godrelicscondition_list(i);
		E_GodrelicsCondition_List[i].read_from_pbmsg(temp_e_godrelicscondition_list);
	}
}

}
