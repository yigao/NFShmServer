#include "E_Qypeak_s.h"

namespace proto_ff_s {

E_QypeakBack_s::E_QypeakBack_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_QypeakBack_s::CreateInit() {
	m_layers = (int32_t)0;
	m_skillNum = (int32_t)0;
	m_reward = (int32_t)0;
	return 0;
}

int E_QypeakBack_s::ResumeInit() {
	return 0;
}

void E_QypeakBack_s::write_to_pbmsg(::proto_ff::E_QypeakBack & msg) const {
	msg.set_m_layers((int32_t)m_layers);
	msg.set_m_skillnum((int32_t)m_skillNum);
	msg.set_m_reward((int32_t)m_reward);
}

void E_QypeakBack_s::read_from_pbmsg(const ::proto_ff::E_QypeakBack & msg) {
	m_layers = msg.m_layers();
	m_skillNum = msg.m_skillnum();
	m_reward = msg.m_reward();
}

Sheet_QypeakBack_s::Sheet_QypeakBack_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_QypeakBack_s::CreateInit() {
	return 0;
}

int Sheet_QypeakBack_s::ResumeInit() {
	return 0;
}

void Sheet_QypeakBack_s::write_to_pbmsg(::proto_ff::Sheet_QypeakBack & msg) const {
	for(int32_t i = 0; i < (int32_t)E_QypeakBack_List.size(); ++i) {
		::proto_ff::E_QypeakBack* temp_e_qypeakback_list = msg.add_e_qypeakback_list();
		E_QypeakBack_List[i].write_to_pbmsg(*temp_e_qypeakback_list);
	}
}

void Sheet_QypeakBack_s::read_from_pbmsg(const ::proto_ff::Sheet_QypeakBack & msg) {
	E_QypeakBack_List.resize((int)msg.e_qypeakback_list_size() > (int)E_QypeakBack_List.max_size() ? E_QypeakBack_List.max_size() : msg.e_qypeakback_list_size());
	for(int32_t i = 0; i < (int32_t)E_QypeakBack_List.size(); ++i) {
		const ::proto_ff::E_QypeakBack & temp_e_qypeakback_list = msg.e_qypeakback_list(i);
		E_QypeakBack_List[i].read_from_pbmsg(temp_e_qypeakback_list);
	}
}

E_QypeakConstant_s::E_QypeakConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_QypeakConstant_s::CreateInit() {
	m_id = (int32_t)0;
	m_mapid = (int32_t)0;
	m_revivalBuff = (int32_t)0;
	return 0;
}

int E_QypeakConstant_s::ResumeInit() {
	return 0;
}

void E_QypeakConstant_s::write_to_pbmsg(::proto_ff::E_QypeakConstant & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_mapid((int32_t)m_mapid);
	msg.set_m_revivalbuff((int32_t)m_revivalBuff);
	for(int32_t i = 0; i < (int32_t)m_rankreward.size(); ++i) {
		msg.add_m_rankreward((int32_t)m_rankreward[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_titleshow.size(); ++i) {
		msg.add_m_titleshow((int32_t)m_titleshow[i]);
	}
}

void E_QypeakConstant_s::read_from_pbmsg(const ::proto_ff::E_QypeakConstant & msg) {
	m_id = msg.m_id();
	m_mapid = msg.m_mapid();
	m_revivalBuff = msg.m_revivalbuff();
	m_rankreward.resize((int)msg.m_rankreward_size() > (int)m_rankreward.max_size() ? m_rankreward.max_size() : msg.m_rankreward_size());
	for(int32_t i = 0; i < (int32_t)m_rankreward.size(); ++i) {
		m_rankreward[i] = msg.m_rankreward(i);
	}
	m_titleshow.resize((int)msg.m_titleshow_size() > (int)m_titleshow.max_size() ? m_titleshow.max_size() : msg.m_titleshow_size());
	for(int32_t i = 0; i < (int32_t)m_titleshow.size(); ++i) {
		m_titleshow[i] = msg.m_titleshow(i);
	}
}

Sheet_QypeakConstant_s::Sheet_QypeakConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_QypeakConstant_s::CreateInit() {
	return 0;
}

int Sheet_QypeakConstant_s::ResumeInit() {
	return 0;
}

void Sheet_QypeakConstant_s::write_to_pbmsg(::proto_ff::Sheet_QypeakConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_QypeakConstant_List.size(); ++i) {
		::proto_ff::E_QypeakConstant* temp_e_qypeakconstant_list = msg.add_e_qypeakconstant_list();
		E_QypeakConstant_List[i].write_to_pbmsg(*temp_e_qypeakconstant_list);
	}
}

void Sheet_QypeakConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_QypeakConstant & msg) {
	E_QypeakConstant_List.resize((int)msg.e_qypeakconstant_list_size() > (int)E_QypeakConstant_List.max_size() ? E_QypeakConstant_List.max_size() : msg.e_qypeakconstant_list_size());
	for(int32_t i = 0; i < (int32_t)E_QypeakConstant_List.size(); ++i) {
		const ::proto_ff::E_QypeakConstant & temp_e_qypeakconstant_list = msg.e_qypeakconstant_list(i);
		E_QypeakConstant_List[i].read_from_pbmsg(temp_e_qypeakconstant_list);
	}
}

}
