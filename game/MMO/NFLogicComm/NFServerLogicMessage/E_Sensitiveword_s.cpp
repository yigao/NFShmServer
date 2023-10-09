#include "E_Sensitiveword_s.h"

namespace proto_ff_s {

E_SensitivewordWord1_s::E_SensitivewordWord1_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SensitivewordWord1_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_SensitivewordWord1_s::ResumeInit() {
	return 0;
}

void E_SensitivewordWord1_s::write_to_pbmsg(::proto_ff::E_SensitivewordWord1 & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_sensitiveword(m_sensitiveword.data());
}

void E_SensitivewordWord1_s::read_from_pbmsg(const ::proto_ff::E_SensitivewordWord1 & msg) {
	m_id = msg.m_id();
	m_sensitiveword = msg.m_sensitiveword();
}

Sheet_SensitivewordWord1_s::Sheet_SensitivewordWord1_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SensitivewordWord1_s::CreateInit() {
	return 0;
}

int Sheet_SensitivewordWord1_s::ResumeInit() {
	return 0;
}

void Sheet_SensitivewordWord1_s::write_to_pbmsg(::proto_ff::Sheet_SensitivewordWord1 & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SensitivewordWord1_List.size(); ++i) {
		::proto_ff::E_SensitivewordWord1* temp_e_sensitivewordword1_list = msg.add_e_sensitivewordword1_list();
		E_SensitivewordWord1_List[i].write_to_pbmsg(*temp_e_sensitivewordword1_list);
	}
}

void Sheet_SensitivewordWord1_s::read_from_pbmsg(const ::proto_ff::Sheet_SensitivewordWord1 & msg) {
	E_SensitivewordWord1_List.resize((int)msg.e_sensitivewordword1_list_size() > (int)E_SensitivewordWord1_List.max_size() ? E_SensitivewordWord1_List.max_size() : msg.e_sensitivewordword1_list_size());
	for(int32_t i = 0; i < (int32_t)E_SensitivewordWord1_List.size(); ++i) {
		const ::proto_ff::E_SensitivewordWord1 & temp_e_sensitivewordword1_list = msg.e_sensitivewordword1_list(i);
		E_SensitivewordWord1_List[i].read_from_pbmsg(temp_e_sensitivewordword1_list);
	}
}

E_SensitivewordWord2_s::E_SensitivewordWord2_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SensitivewordWord2_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_SensitivewordWord2_s::ResumeInit() {
	return 0;
}

void E_SensitivewordWord2_s::write_to_pbmsg(::proto_ff::E_SensitivewordWord2 & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_sensitiveword(m_sensitiveword.data());
}

void E_SensitivewordWord2_s::read_from_pbmsg(const ::proto_ff::E_SensitivewordWord2 & msg) {
	m_id = msg.m_id();
	m_sensitiveword = msg.m_sensitiveword();
}

Sheet_SensitivewordWord2_s::Sheet_SensitivewordWord2_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SensitivewordWord2_s::CreateInit() {
	return 0;
}

int Sheet_SensitivewordWord2_s::ResumeInit() {
	return 0;
}

void Sheet_SensitivewordWord2_s::write_to_pbmsg(::proto_ff::Sheet_SensitivewordWord2 & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SensitivewordWord2_List.size(); ++i) {
		::proto_ff::E_SensitivewordWord2* temp_e_sensitivewordword2_list = msg.add_e_sensitivewordword2_list();
		E_SensitivewordWord2_List[i].write_to_pbmsg(*temp_e_sensitivewordword2_list);
	}
}

void Sheet_SensitivewordWord2_s::read_from_pbmsg(const ::proto_ff::Sheet_SensitivewordWord2 & msg) {
	E_SensitivewordWord2_List.resize((int)msg.e_sensitivewordword2_list_size() > (int)E_SensitivewordWord2_List.max_size() ? E_SensitivewordWord2_List.max_size() : msg.e_sensitivewordword2_list_size());
	for(int32_t i = 0; i < (int32_t)E_SensitivewordWord2_List.size(); ++i) {
		const ::proto_ff::E_SensitivewordWord2 & temp_e_sensitivewordword2_list = msg.e_sensitivewordword2_list(i);
		E_SensitivewordWord2_List[i].read_from_pbmsg(temp_e_sensitivewordword2_list);
	}
}

E_SensitivewordWord3_s::E_SensitivewordWord3_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SensitivewordWord3_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_SensitivewordWord3_s::ResumeInit() {
	return 0;
}

void E_SensitivewordWord3_s::write_to_pbmsg(::proto_ff::E_SensitivewordWord3 & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_sensitiveword(m_sensitiveword.data());
}

void E_SensitivewordWord3_s::read_from_pbmsg(const ::proto_ff::E_SensitivewordWord3 & msg) {
	m_id = msg.m_id();
	m_sensitiveword = msg.m_sensitiveword();
}

Sheet_SensitivewordWord3_s::Sheet_SensitivewordWord3_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SensitivewordWord3_s::CreateInit() {
	return 0;
}

int Sheet_SensitivewordWord3_s::ResumeInit() {
	return 0;
}

void Sheet_SensitivewordWord3_s::write_to_pbmsg(::proto_ff::Sheet_SensitivewordWord3 & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SensitivewordWord3_List.size(); ++i) {
		::proto_ff::E_SensitivewordWord3* temp_e_sensitivewordword3_list = msg.add_e_sensitivewordword3_list();
		E_SensitivewordWord3_List[i].write_to_pbmsg(*temp_e_sensitivewordword3_list);
	}
}

void Sheet_SensitivewordWord3_s::read_from_pbmsg(const ::proto_ff::Sheet_SensitivewordWord3 & msg) {
	E_SensitivewordWord3_List.resize((int)msg.e_sensitivewordword3_list_size() > (int)E_SensitivewordWord3_List.max_size() ? E_SensitivewordWord3_List.max_size() : msg.e_sensitivewordword3_list_size());
	for(int32_t i = 0; i < (int32_t)E_SensitivewordWord3_List.size(); ++i) {
		const ::proto_ff::E_SensitivewordWord3 & temp_e_sensitivewordword3_list = msg.e_sensitivewordword3_list(i);
		E_SensitivewordWord3_List[i].read_from_pbmsg(temp_e_sensitivewordword3_list);
	}
}

}
