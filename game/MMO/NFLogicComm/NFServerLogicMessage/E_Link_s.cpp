#include "E_Link_s.h"

namespace proto_ff_s {

E_LinkLink_s::E_LinkLink_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_LinkLink_s::CreateInit() {
	m_id = (int64_t)0;
	m_functionunlock = (int32_t)0;
	return 0;
}

int E_LinkLink_s::ResumeInit() {
	return 0;
}

void E_LinkLink_s::write_to_pbmsg(::proto_ff::E_LinkLink & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_icon(m_icon.data());
	msg.set_m_dbargs(m_dbargs.data());
	msg.set_m_argsm(m_argsm.data());
	msg.set_m_functionunlock((int32_t)m_functionunlock);
	msg.set_m_linknpc(m_linknpc.data());
}

void E_LinkLink_s::read_from_pbmsg(const ::proto_ff::E_LinkLink & msg) {
	m_id = msg.m_id();
	m_icon = msg.m_icon();
	m_dbargs = msg.m_dbargs();
	m_argsm = msg.m_argsm();
	m_functionunlock = msg.m_functionunlock();
	m_linknpc = msg.m_linknpc();
}

Sheet_LinkLink_s::Sheet_LinkLink_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_LinkLink_s::CreateInit() {
	return 0;
}

int Sheet_LinkLink_s::ResumeInit() {
	return 0;
}

void Sheet_LinkLink_s::write_to_pbmsg(::proto_ff::Sheet_LinkLink & msg) const {
	for(int32_t i = 0; i < (int32_t)E_LinkLink_List.size(); ++i) {
		::proto_ff::E_LinkLink* temp_e_linklink_list = msg.add_e_linklink_list();
		E_LinkLink_List[i].write_to_pbmsg(*temp_e_linklink_list);
	}
}

void Sheet_LinkLink_s::read_from_pbmsg(const ::proto_ff::Sheet_LinkLink & msg) {
	E_LinkLink_List.resize((int)msg.e_linklink_list_size() > (int)E_LinkLink_List.max_size() ? E_LinkLink_List.max_size() : msg.e_linklink_list_size());
	for(int32_t i = 0; i < (int32_t)E_LinkLink_List.size(); ++i) {
		const ::proto_ff::E_LinkLink & temp_e_linklink_list = msg.e_linklink_list(i);
		E_LinkLink_List[i].read_from_pbmsg(temp_e_linklink_list);
	}
}

E_LinkImagelink_s::E_LinkImagelink_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_LinkImagelink_s::CreateInit() {
	m_id = (int32_t)0;
	m_closetype = (int32_t)0;
	m_closearg = (int32_t)0;
	return 0;
}

int E_LinkImagelink_s::ResumeInit() {
	return 0;
}

void E_LinkImagelink_s::write_to_pbmsg(::proto_ff::E_LinkImagelink & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_closetype((int32_t)m_closetype);
	msg.set_m_closearg((int32_t)m_closearg);
}

void E_LinkImagelink_s::read_from_pbmsg(const ::proto_ff::E_LinkImagelink & msg) {
	m_id = msg.m_id();
	m_closetype = msg.m_closetype();
	m_closearg = msg.m_closearg();
}

Sheet_LinkImagelink_s::Sheet_LinkImagelink_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_LinkImagelink_s::CreateInit() {
	return 0;
}

int Sheet_LinkImagelink_s::ResumeInit() {
	return 0;
}

void Sheet_LinkImagelink_s::write_to_pbmsg(::proto_ff::Sheet_LinkImagelink & msg) const {
	for(int32_t i = 0; i < (int32_t)E_LinkImagelink_List.size(); ++i) {
		::proto_ff::E_LinkImagelink* temp_e_linkimagelink_list = msg.add_e_linkimagelink_list();
		E_LinkImagelink_List[i].write_to_pbmsg(*temp_e_linkimagelink_list);
	}
}

void Sheet_LinkImagelink_s::read_from_pbmsg(const ::proto_ff::Sheet_LinkImagelink & msg) {
	E_LinkImagelink_List.resize((int)msg.e_linkimagelink_list_size() > (int)E_LinkImagelink_List.max_size() ? E_LinkImagelink_List.max_size() : msg.e_linkimagelink_list_size());
	for(int32_t i = 0; i < (int32_t)E_LinkImagelink_List.size(); ++i) {
		const ::proto_ff::E_LinkImagelink & temp_e_linkimagelink_list = msg.e_linkimagelink_list(i);
		E_LinkImagelink_List[i].read_from_pbmsg(temp_e_linkimagelink_list);
	}
}

}
