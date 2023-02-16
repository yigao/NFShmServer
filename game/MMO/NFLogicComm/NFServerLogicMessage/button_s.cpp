#include "button_s.h"

namespace proto_ff_s {

E_ButtonButton_s::E_ButtonButton_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ButtonButton_s::CreateInit() {
	m_id = (int64_t)0;
	m_time = (int32_t)0;
	return 0;
}

int E_ButtonButton_s::ResumeInit() {
	return 0;
}

void E_ButtonButton_s::write_to_pbmsg(::proto_ff::E_ButtonButton & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_time((int32_t)m_time);
}

void E_ButtonButton_s::read_from_pbmsg(const ::proto_ff::E_ButtonButton & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ButtonButton_s));
	m_id = msg.m_id();
	m_time = msg.m_time();
}

Sheet_ButtonButton_s::Sheet_ButtonButton_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ButtonButton_s::CreateInit() {
	return 0;
}

int Sheet_ButtonButton_s::ResumeInit() {
	return 0;
}

void Sheet_ButtonButton_s::write_to_pbmsg(::proto_ff::Sheet_ButtonButton & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ButtonButton_List.size(); ++i) {
		::proto_ff::E_ButtonButton* temp_e_buttonbutton_list = msg.add_e_buttonbutton_list();
		E_ButtonButton_List[i].write_to_pbmsg(*temp_e_buttonbutton_list);
	}
}

void Sheet_ButtonButton_s::read_from_pbmsg(const ::proto_ff::Sheet_ButtonButton & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_ButtonButton_s));
	E_ButtonButton_List.resize((int)msg.e_buttonbutton_list_size() > (int)E_ButtonButton_List.max_size() ? E_ButtonButton_List.max_size() : msg.e_buttonbutton_list_size());
	for(int32_t i = 0; i < (int32_t)E_ButtonButton_List.size(); ++i) {
		const ::proto_ff::E_ButtonButton & temp_e_buttonbutton_list = msg.e_buttonbutton_list(i);
		E_ButtonButton_List[i].read_from_pbmsg(temp_e_buttonbutton_list);
	}
}

}