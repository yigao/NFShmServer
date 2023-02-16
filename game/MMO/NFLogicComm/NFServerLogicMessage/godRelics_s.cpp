#include "godRelics_s.h"

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
	m_functionid = (int32_t)0;
	m_group = (int32_t)0;
	m_skillid = (int32_t)0;
	return 0;
}

int E_GodrelicsGodrelics_s::ResumeInit() {
	return 0;
}

void E_GodrelicsGodrelics_s::write_to_pbmsg(::proto_ff::E_GodrelicsGodrelics & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_functionid((int32_t)m_functionid);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_skillid((int32_t)m_skillid);
}

void E_GodrelicsGodrelics_s::read_from_pbmsg(const ::proto_ff::E_GodrelicsGodrelics & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GodrelicsGodrelics_s));
	m_id = msg.m_id();
	m_functionid = msg.m_functionid();
	m_group = msg.m_group();
	m_skillid = msg.m_skillid();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GodrelicsGodrelics_s));
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
	m_rewarditem = (int32_t)0;
	m_rewardnumber = (int32_t)0;
	return 0;
}

int E_GodrelicsCondition_s::ResumeInit() {
	return 0;
}

void E_GodrelicsCondition_s::write_to_pbmsg(::proto_ff::E_GodrelicsCondition & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_conditon((int32_t)m_conditon);
	msg.set_m_parama((const char*)m_parama.data());
	msg.set_m_count((int32_t)m_count);
	msg.set_m_rewarditem((int32_t)m_rewarditem);
	msg.set_m_rewardnumber((int32_t)m_rewardnumber);
}

void E_GodrelicsCondition_s::read_from_pbmsg(const ::proto_ff::E_GodrelicsCondition & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GodrelicsCondition_s));
	m_id = msg.m_id();
	m_group = msg.m_group();
	m_conditon = msg.m_conditon();
	m_parama = msg.m_parama();
	m_count = msg.m_count();
	m_rewarditem = msg.m_rewarditem();
	m_rewardnumber = msg.m_rewardnumber();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GodrelicsCondition_s));
	E_GodrelicsCondition_List.resize((int)msg.e_godrelicscondition_list_size() > (int)E_GodrelicsCondition_List.max_size() ? E_GodrelicsCondition_List.max_size() : msg.e_godrelicscondition_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodrelicsCondition_List.size(); ++i) {
		const ::proto_ff::E_GodrelicsCondition & temp_e_godrelicscondition_list = msg.e_godrelicscondition_list(i);
		E_GodrelicsCondition_List[i].read_from_pbmsg(temp_e_godrelicscondition_list);
	}
}

}