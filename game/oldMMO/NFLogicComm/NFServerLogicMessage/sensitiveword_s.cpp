#include "sensitiveword_s.h"

namespace proto_ff_s {

E_SensitivewordSensitive_word_s::E_SensitivewordSensitive_word_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SensitivewordSensitive_word_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_SensitivewordSensitive_word_s::ResumeInit() {
	return 0;
}

void E_SensitivewordSensitive_word_s::write_to_pbmsg(::proto_ff::E_SensitivewordSensitive_word & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_sensitiveword((const char*)m_sensitiveword.data());
}

void E_SensitivewordSensitive_word_s::read_from_pbmsg(const ::proto_ff::E_SensitivewordSensitive_word & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_SensitivewordSensitive_word_s));
	m_id = msg.m_id();
	m_sensitiveword = msg.m_sensitiveword();
}

Sheet_SensitivewordSensitive_word_s::Sheet_SensitivewordSensitive_word_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SensitivewordSensitive_word_s::CreateInit() {
	return 0;
}

int Sheet_SensitivewordSensitive_word_s::ResumeInit() {
	return 0;
}

void Sheet_SensitivewordSensitive_word_s::write_to_pbmsg(::proto_ff::Sheet_SensitivewordSensitive_word & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SensitivewordSensitive_word_List.size(); ++i) {
		::proto_ff::E_SensitivewordSensitive_word* temp_e_sensitivewordsensitive_word_list = msg.add_e_sensitivewordsensitive_word_list();
		E_SensitivewordSensitive_word_List[i].write_to_pbmsg(*temp_e_sensitivewordsensitive_word_list);
	}
}

void Sheet_SensitivewordSensitive_word_s::read_from_pbmsg(const ::proto_ff::Sheet_SensitivewordSensitive_word & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_SensitivewordSensitive_word_s));
	E_SensitivewordSensitive_word_List.resize((int)msg.e_sensitivewordsensitive_word_list_size() > (int)E_SensitivewordSensitive_word_List.max_size() ? E_SensitivewordSensitive_word_List.max_size() : msg.e_sensitivewordsensitive_word_list_size());
	for(int32_t i = 0; i < (int32_t)E_SensitivewordSensitive_word_List.size(); ++i) {
		const ::proto_ff::E_SensitivewordSensitive_word & temp_e_sensitivewordsensitive_word_list = msg.e_sensitivewordsensitive_word_list(i);
		E_SensitivewordSensitive_word_List[i].read_from_pbmsg(temp_e_sensitivewordsensitive_word_list);
	}
}

E_SensitivewordRolesensitive_s::E_SensitivewordRolesensitive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SensitivewordRolesensitive_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_SensitivewordRolesensitive_s::ResumeInit() {
	return 0;
}

void E_SensitivewordRolesensitive_s::write_to_pbmsg(::proto_ff::E_SensitivewordRolesensitive & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_sensitiveword((const char*)m_sensitiveword.data());
}

void E_SensitivewordRolesensitive_s::read_from_pbmsg(const ::proto_ff::E_SensitivewordRolesensitive & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_SensitivewordRolesensitive_s));
	m_id = msg.m_id();
	m_sensitiveword = msg.m_sensitiveword();
}

Sheet_SensitivewordRolesensitive_s::Sheet_SensitivewordRolesensitive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SensitivewordRolesensitive_s::CreateInit() {
	return 0;
}

int Sheet_SensitivewordRolesensitive_s::ResumeInit() {
	return 0;
}

void Sheet_SensitivewordRolesensitive_s::write_to_pbmsg(::proto_ff::Sheet_SensitivewordRolesensitive & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SensitivewordRolesensitive_List.size(); ++i) {
		::proto_ff::E_SensitivewordRolesensitive* temp_e_sensitivewordrolesensitive_list = msg.add_e_sensitivewordrolesensitive_list();
		E_SensitivewordRolesensitive_List[i].write_to_pbmsg(*temp_e_sensitivewordrolesensitive_list);
	}
}

void Sheet_SensitivewordRolesensitive_s::read_from_pbmsg(const ::proto_ff::Sheet_SensitivewordRolesensitive & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_SensitivewordRolesensitive_s));
	E_SensitivewordRolesensitive_List.resize((int)msg.e_sensitivewordrolesensitive_list_size() > (int)E_SensitivewordRolesensitive_List.max_size() ? E_SensitivewordRolesensitive_List.max_size() : msg.e_sensitivewordrolesensitive_list_size());
	for(int32_t i = 0; i < (int32_t)E_SensitivewordRolesensitive_List.size(); ++i) {
		const ::proto_ff::E_SensitivewordRolesensitive & temp_e_sensitivewordrolesensitive_list = msg.e_sensitivewordrolesensitive_list(i);
		E_SensitivewordRolesensitive_List[i].read_from_pbmsg(temp_e_sensitivewordrolesensitive_list);
	}
}

}