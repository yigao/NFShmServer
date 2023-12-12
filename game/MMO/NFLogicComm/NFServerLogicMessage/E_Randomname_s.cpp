#include "E_Randomname_s.h"

namespace proto_ff_s {

E_RandomnameManfirst_s::E_RandomnameManfirst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RandomnameManfirst_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_RandomnameManfirst_s::ResumeInit() {
	return 0;
}

void E_RandomnameManfirst_s::write_to_pbmsg(::proto_ff::E_RandomnameManfirst & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
}

void E_RandomnameManfirst_s::read_from_pbmsg(const ::proto_ff::E_RandomnameManfirst & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
}

Sheet_RandomnameManfirst_s::Sheet_RandomnameManfirst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RandomnameManfirst_s::CreateInit() {
	return 0;
}

int Sheet_RandomnameManfirst_s::ResumeInit() {
	return 0;
}

void Sheet_RandomnameManfirst_s::write_to_pbmsg(::proto_ff::Sheet_RandomnameManfirst & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RandomnameManfirst_List.size(); ++i) {
		::proto_ff::E_RandomnameManfirst* temp_e_randomnamemanfirst_list = msg.add_e_randomnamemanfirst_list();
		E_RandomnameManfirst_List[i].write_to_pbmsg(*temp_e_randomnamemanfirst_list);
	}
}

void Sheet_RandomnameManfirst_s::read_from_pbmsg(const ::proto_ff::Sheet_RandomnameManfirst & msg) {
	E_RandomnameManfirst_List.resize((int)msg.e_randomnamemanfirst_list_size() > (int)E_RandomnameManfirst_List.max_size() ? E_RandomnameManfirst_List.max_size() : msg.e_randomnamemanfirst_list_size());
	for(int32_t i = 0; i < (int32_t)E_RandomnameManfirst_List.size(); ++i) {
		const ::proto_ff::E_RandomnameManfirst & temp_e_randomnamemanfirst_list = msg.e_randomnamemanfirst_list(i);
		E_RandomnameManfirst_List[i].read_from_pbmsg(temp_e_randomnamemanfirst_list);
	}
}

E_RandomnameMansecond_s::E_RandomnameMansecond_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RandomnameMansecond_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_RandomnameMansecond_s::ResumeInit() {
	return 0;
}

void E_RandomnameMansecond_s::write_to_pbmsg(::proto_ff::E_RandomnameMansecond & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
}

void E_RandomnameMansecond_s::read_from_pbmsg(const ::proto_ff::E_RandomnameMansecond & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
}

Sheet_RandomnameMansecond_s::Sheet_RandomnameMansecond_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RandomnameMansecond_s::CreateInit() {
	return 0;
}

int Sheet_RandomnameMansecond_s::ResumeInit() {
	return 0;
}

void Sheet_RandomnameMansecond_s::write_to_pbmsg(::proto_ff::Sheet_RandomnameMansecond & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RandomnameMansecond_List.size(); ++i) {
		::proto_ff::E_RandomnameMansecond* temp_e_randomnamemansecond_list = msg.add_e_randomnamemansecond_list();
		E_RandomnameMansecond_List[i].write_to_pbmsg(*temp_e_randomnamemansecond_list);
	}
}

void Sheet_RandomnameMansecond_s::read_from_pbmsg(const ::proto_ff::Sheet_RandomnameMansecond & msg) {
	E_RandomnameMansecond_List.resize((int)msg.e_randomnamemansecond_list_size() > (int)E_RandomnameMansecond_List.max_size() ? E_RandomnameMansecond_List.max_size() : msg.e_randomnamemansecond_list_size());
	for(int32_t i = 0; i < (int32_t)E_RandomnameMansecond_List.size(); ++i) {
		const ::proto_ff::E_RandomnameMansecond & temp_e_randomnamemansecond_list = msg.e_randomnamemansecond_list(i);
		E_RandomnameMansecond_List[i].read_from_pbmsg(temp_e_randomnamemansecond_list);
	}
}

E_RandomnameManthird_s::E_RandomnameManthird_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RandomnameManthird_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_RandomnameManthird_s::ResumeInit() {
	return 0;
}

void E_RandomnameManthird_s::write_to_pbmsg(::proto_ff::E_RandomnameManthird & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
}

void E_RandomnameManthird_s::read_from_pbmsg(const ::proto_ff::E_RandomnameManthird & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
}

Sheet_RandomnameManthird_s::Sheet_RandomnameManthird_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RandomnameManthird_s::CreateInit() {
	return 0;
}

int Sheet_RandomnameManthird_s::ResumeInit() {
	return 0;
}

void Sheet_RandomnameManthird_s::write_to_pbmsg(::proto_ff::Sheet_RandomnameManthird & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RandomnameManthird_List.size(); ++i) {
		::proto_ff::E_RandomnameManthird* temp_e_randomnamemanthird_list = msg.add_e_randomnamemanthird_list();
		E_RandomnameManthird_List[i].write_to_pbmsg(*temp_e_randomnamemanthird_list);
	}
}

void Sheet_RandomnameManthird_s::read_from_pbmsg(const ::proto_ff::Sheet_RandomnameManthird & msg) {
	E_RandomnameManthird_List.resize((int)msg.e_randomnamemanthird_list_size() > (int)E_RandomnameManthird_List.max_size() ? E_RandomnameManthird_List.max_size() : msg.e_randomnamemanthird_list_size());
	for(int32_t i = 0; i < (int32_t)E_RandomnameManthird_List.size(); ++i) {
		const ::proto_ff::E_RandomnameManthird & temp_e_randomnamemanthird_list = msg.e_randomnamemanthird_list(i);
		E_RandomnameManthird_List[i].read_from_pbmsg(temp_e_randomnamemanthird_list);
	}
}

E_RandomnameWomanfirst_s::E_RandomnameWomanfirst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RandomnameWomanfirst_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_RandomnameWomanfirst_s::ResumeInit() {
	return 0;
}

void E_RandomnameWomanfirst_s::write_to_pbmsg(::proto_ff::E_RandomnameWomanfirst & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
}

void E_RandomnameWomanfirst_s::read_from_pbmsg(const ::proto_ff::E_RandomnameWomanfirst & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
}

Sheet_RandomnameWomanfirst_s::Sheet_RandomnameWomanfirst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RandomnameWomanfirst_s::CreateInit() {
	return 0;
}

int Sheet_RandomnameWomanfirst_s::ResumeInit() {
	return 0;
}

void Sheet_RandomnameWomanfirst_s::write_to_pbmsg(::proto_ff::Sheet_RandomnameWomanfirst & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RandomnameWomanfirst_List.size(); ++i) {
		::proto_ff::E_RandomnameWomanfirst* temp_e_randomnamewomanfirst_list = msg.add_e_randomnamewomanfirst_list();
		E_RandomnameWomanfirst_List[i].write_to_pbmsg(*temp_e_randomnamewomanfirst_list);
	}
}

void Sheet_RandomnameWomanfirst_s::read_from_pbmsg(const ::proto_ff::Sheet_RandomnameWomanfirst & msg) {
	E_RandomnameWomanfirst_List.resize((int)msg.e_randomnamewomanfirst_list_size() > (int)E_RandomnameWomanfirst_List.max_size() ? E_RandomnameWomanfirst_List.max_size() : msg.e_randomnamewomanfirst_list_size());
	for(int32_t i = 0; i < (int32_t)E_RandomnameWomanfirst_List.size(); ++i) {
		const ::proto_ff::E_RandomnameWomanfirst & temp_e_randomnamewomanfirst_list = msg.e_randomnamewomanfirst_list(i);
		E_RandomnameWomanfirst_List[i].read_from_pbmsg(temp_e_randomnamewomanfirst_list);
	}
}

E_RandomnameWomansecond_s::E_RandomnameWomansecond_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RandomnameWomansecond_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_RandomnameWomansecond_s::ResumeInit() {
	return 0;
}

void E_RandomnameWomansecond_s::write_to_pbmsg(::proto_ff::E_RandomnameWomansecond & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
}

void E_RandomnameWomansecond_s::read_from_pbmsg(const ::proto_ff::E_RandomnameWomansecond & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
}

Sheet_RandomnameWomansecond_s::Sheet_RandomnameWomansecond_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RandomnameWomansecond_s::CreateInit() {
	return 0;
}

int Sheet_RandomnameWomansecond_s::ResumeInit() {
	return 0;
}

void Sheet_RandomnameWomansecond_s::write_to_pbmsg(::proto_ff::Sheet_RandomnameWomansecond & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RandomnameWomansecond_List.size(); ++i) {
		::proto_ff::E_RandomnameWomansecond* temp_e_randomnamewomansecond_list = msg.add_e_randomnamewomansecond_list();
		E_RandomnameWomansecond_List[i].write_to_pbmsg(*temp_e_randomnamewomansecond_list);
	}
}

void Sheet_RandomnameWomansecond_s::read_from_pbmsg(const ::proto_ff::Sheet_RandomnameWomansecond & msg) {
	E_RandomnameWomansecond_List.resize((int)msg.e_randomnamewomansecond_list_size() > (int)E_RandomnameWomansecond_List.max_size() ? E_RandomnameWomansecond_List.max_size() : msg.e_randomnamewomansecond_list_size());
	for(int32_t i = 0; i < (int32_t)E_RandomnameWomansecond_List.size(); ++i) {
		const ::proto_ff::E_RandomnameWomansecond & temp_e_randomnamewomansecond_list = msg.e_randomnamewomansecond_list(i);
		E_RandomnameWomansecond_List[i].read_from_pbmsg(temp_e_randomnamewomansecond_list);
	}
}

E_RandomnameWomanthird_s::E_RandomnameWomanthird_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RandomnameWomanthird_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_RandomnameWomanthird_s::ResumeInit() {
	return 0;
}

void E_RandomnameWomanthird_s::write_to_pbmsg(::proto_ff::E_RandomnameWomanthird & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
}

void E_RandomnameWomanthird_s::read_from_pbmsg(const ::proto_ff::E_RandomnameWomanthird & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
}

Sheet_RandomnameWomanthird_s::Sheet_RandomnameWomanthird_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RandomnameWomanthird_s::CreateInit() {
	return 0;
}

int Sheet_RandomnameWomanthird_s::ResumeInit() {
	return 0;
}

void Sheet_RandomnameWomanthird_s::write_to_pbmsg(::proto_ff::Sheet_RandomnameWomanthird & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RandomnameWomanthird_List.size(); ++i) {
		::proto_ff::E_RandomnameWomanthird* temp_e_randomnamewomanthird_list = msg.add_e_randomnamewomanthird_list();
		E_RandomnameWomanthird_List[i].write_to_pbmsg(*temp_e_randomnamewomanthird_list);
	}
}

void Sheet_RandomnameWomanthird_s::read_from_pbmsg(const ::proto_ff::Sheet_RandomnameWomanthird & msg) {
	E_RandomnameWomanthird_List.resize((int)msg.e_randomnamewomanthird_list_size() > (int)E_RandomnameWomanthird_List.max_size() ? E_RandomnameWomanthird_List.max_size() : msg.e_randomnamewomanthird_list_size());
	for(int32_t i = 0; i < (int32_t)E_RandomnameWomanthird_List.size(); ++i) {
		const ::proto_ff::E_RandomnameWomanthird & temp_e_randomnamewomanthird_list = msg.e_randomnamewomanthird_list(i);
		E_RandomnameWomanthird_List[i].read_from_pbmsg(temp_e_randomnamewomanthird_list);
	}
}

}
