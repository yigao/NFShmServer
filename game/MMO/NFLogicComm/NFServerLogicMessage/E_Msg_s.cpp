#include "E_Msg_s.h"

namespace proto_ff_s {

E_MsgPhpmsg_s::E_MsgPhpmsg_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MsgPhpmsg_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_MsgPhpmsg_s::ResumeInit() {
	return 0;
}

void E_MsgPhpmsg_s::write_to_pbmsg(::proto_ff::E_MsgPhpmsg & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_content(m_content.data());
	msg.set_m_note(m_note.data());
}

void E_MsgPhpmsg_s::read_from_pbmsg(const ::proto_ff::E_MsgPhpmsg & msg) {
	m_id = msg.m_id();
	m_content = msg.m_content();
	m_note = msg.m_note();
}

Sheet_MsgPhpmsg_s::Sheet_MsgPhpmsg_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MsgPhpmsg_s::CreateInit() {
	return 0;
}

int Sheet_MsgPhpmsg_s::ResumeInit() {
	return 0;
}

void Sheet_MsgPhpmsg_s::write_to_pbmsg(::proto_ff::Sheet_MsgPhpmsg & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MsgPhpmsg_List.size(); ++i) {
		::proto_ff::E_MsgPhpmsg* temp_e_msgphpmsg_list = msg.add_e_msgphpmsg_list();
		E_MsgPhpmsg_List[i].write_to_pbmsg(*temp_e_msgphpmsg_list);
	}
}

void Sheet_MsgPhpmsg_s::read_from_pbmsg(const ::proto_ff::Sheet_MsgPhpmsg & msg) {
	E_MsgPhpmsg_List.resize((int)msg.e_msgphpmsg_list_size() > (int)E_MsgPhpmsg_List.max_size() ? E_MsgPhpmsg_List.max_size() : msg.e_msgphpmsg_list_size());
	for(int32_t i = 0; i < (int32_t)E_MsgPhpmsg_List.size(); ++i) {
		const ::proto_ff::E_MsgPhpmsg & temp_e_msgphpmsg_list = msg.e_msgphpmsg_list(i);
		E_MsgPhpmsg_List[i].read_from_pbmsg(temp_e_msgphpmsg_list);
	}
}

}
