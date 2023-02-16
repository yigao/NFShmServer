#include "assist_s.h"

namespace proto_ff_s {

E_AssistAssistbox_s::E_AssistAssistbox_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AssistAssistbox_s::CreateInit() {
	m_id = (int32_t)0;
	m_times = (int32_t)0;
	m_itemid = (int32_t)0;
	return 0;
}

int E_AssistAssistbox_s::ResumeInit() {
	return 0;
}

void E_AssistAssistbox_s::write_to_pbmsg(::proto_ff::E_AssistAssistbox & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_times((int32_t)m_times);
	msg.set_m_itemid((int32_t)m_itemid);
}

void E_AssistAssistbox_s::read_from_pbmsg(const ::proto_ff::E_AssistAssistbox & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_AssistAssistbox_s));
	m_id = msg.m_id();
	m_times = msg.m_times();
	m_itemid = msg.m_itemid();
}

Sheet_AssistAssistbox_s::Sheet_AssistAssistbox_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AssistAssistbox_s::CreateInit() {
	return 0;
}

int Sheet_AssistAssistbox_s::ResumeInit() {
	return 0;
}

void Sheet_AssistAssistbox_s::write_to_pbmsg(::proto_ff::Sheet_AssistAssistbox & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AssistAssistbox_List.size(); ++i) {
		::proto_ff::E_AssistAssistbox* temp_e_assistassistbox_list = msg.add_e_assistassistbox_list();
		E_AssistAssistbox_List[i].write_to_pbmsg(*temp_e_assistassistbox_list);
	}
}

void Sheet_AssistAssistbox_s::read_from_pbmsg(const ::proto_ff::Sheet_AssistAssistbox & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_AssistAssistbox_s));
	E_AssistAssistbox_List.resize((int)msg.e_assistassistbox_list_size() > (int)E_AssistAssistbox_List.max_size() ? E_AssistAssistbox_List.max_size() : msg.e_assistassistbox_list_size());
	for(int32_t i = 0; i < (int32_t)E_AssistAssistbox_List.size(); ++i) {
		const ::proto_ff::E_AssistAssistbox & temp_e_assistassistbox_list = msg.e_assistassistbox_list(i);
		E_AssistAssistbox_List[i].read_from_pbmsg(temp_e_assistassistbox_list);
	}
}

E_AssistAssistthank_s::E_AssistAssistthank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AssistAssistthank_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_AssistAssistthank_s::ResumeInit() {
	return 0;
}

void E_AssistAssistthank_s::write_to_pbmsg(::proto_ff::E_AssistAssistthank & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_msg((const char*)m_msg.data());
}

void E_AssistAssistthank_s::read_from_pbmsg(const ::proto_ff::E_AssistAssistthank & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_AssistAssistthank_s));
	m_id = msg.m_id();
	m_msg = msg.m_msg();
}

Sheet_AssistAssistthank_s::Sheet_AssistAssistthank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AssistAssistthank_s::CreateInit() {
	return 0;
}

int Sheet_AssistAssistthank_s::ResumeInit() {
	return 0;
}

void Sheet_AssistAssistthank_s::write_to_pbmsg(::proto_ff::Sheet_AssistAssistthank & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AssistAssistthank_List.size(); ++i) {
		::proto_ff::E_AssistAssistthank* temp_e_assistassistthank_list = msg.add_e_assistassistthank_list();
		E_AssistAssistthank_List[i].write_to_pbmsg(*temp_e_assistassistthank_list);
	}
}

void Sheet_AssistAssistthank_s::read_from_pbmsg(const ::proto_ff::Sheet_AssistAssistthank & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_AssistAssistthank_s));
	E_AssistAssistthank_List.resize((int)msg.e_assistassistthank_list_size() > (int)E_AssistAssistthank_List.max_size() ? E_AssistAssistthank_List.max_size() : msg.e_assistassistthank_list_size());
	for(int32_t i = 0; i < (int32_t)E_AssistAssistthank_List.size(); ++i) {
		const ::proto_ff::E_AssistAssistthank & temp_e_assistassistthank_list = msg.e_assistassistthank_list(i);
		E_AssistAssistthank_List[i].read_from_pbmsg(temp_e_assistassistthank_list);
	}
}

}