#include "E_Wordshout_s.h"

namespace proto_ff_s {

E_WordshoutShout_s::E_WordshoutShout_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WordshoutShout_s::CreateInit() {
	m_ID = (int32_t)0;
	m_Channel = (int32_t)0;
	return 0;
}

int E_WordshoutShout_s::ResumeInit() {
	return 0;
}

void E_WordshoutShout_s::write_to_pbmsg(::proto_ff::E_WordshoutShout & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_channel((int32_t)m_Channel);
}

void E_WordshoutShout_s::read_from_pbmsg(const ::proto_ff::E_WordshoutShout & msg) {
	m_ID = msg.m_id();
	m_Channel = msg.m_channel();
}

Sheet_WordshoutShout_s::Sheet_WordshoutShout_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WordshoutShout_s::CreateInit() {
	return 0;
}

int Sheet_WordshoutShout_s::ResumeInit() {
	return 0;
}

void Sheet_WordshoutShout_s::write_to_pbmsg(::proto_ff::Sheet_WordshoutShout & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WordshoutShout_List.size(); ++i) {
		::proto_ff::E_WordshoutShout* temp_e_wordshoutshout_list = msg.add_e_wordshoutshout_list();
		E_WordshoutShout_List[i].write_to_pbmsg(*temp_e_wordshoutshout_list);
	}
}

void Sheet_WordshoutShout_s::read_from_pbmsg(const ::proto_ff::Sheet_WordshoutShout & msg) {
	E_WordshoutShout_List.resize((int)msg.e_wordshoutshout_list_size() > (int)E_WordshoutShout_List.max_size() ? E_WordshoutShout_List.max_size() : msg.e_wordshoutshout_list_size());
	for(int32_t i = 0; i < (int32_t)E_WordshoutShout_List.size(); ++i) {
		const ::proto_ff::E_WordshoutShout & temp_e_wordshoutshout_list = msg.e_wordshoutshout_list(i);
		E_WordshoutShout_List[i].read_from_pbmsg(temp_e_wordshoutshout_list);
	}
}

}
