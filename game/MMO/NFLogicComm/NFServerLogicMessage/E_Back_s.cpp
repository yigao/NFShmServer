#include "E_Back_s.h"

namespace proto_ff_s {

E_BackBack_s::E_BackBack_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BackBack_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_typeparam = (int32_t)0;
	m_group = (int32_t)0;
	m_functionunlock = (int32_t)0;
	m_levellimit = (int32_t)0;
	m_pboxid = (int64_t)0;
	m_boxid = (int64_t)0;
	m_backday = (int32_t)0;
	m_costitemid = (int32_t)0;
	m_costnum = (int32_t)0;
	m_pcostitemid = (int32_t)0;
	m_pcostnum = (int32_t)0;
	m_acostitemid = (int32_t)0;
	m_acostnum = (int32_t)0;
	return 0;
}

int E_BackBack_s::ResumeInit() {
	return 0;
}

void E_BackBack_s::write_to_pbmsg(::proto_ff::E_BackBack & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_typeparam((int32_t)m_typeparam);
	msg.set_m_name(m_name.data());
	msg.set_m_group((int32_t)m_group);
	msg.set_m_functionunlock((int32_t)m_functionunlock);
	msg.set_m_levellimit((int32_t)m_levellimit);
	msg.set_m_pboxid((int64_t)m_pboxid);
	msg.set_m_boxid((int64_t)m_boxid);
	msg.set_m_backday((int32_t)m_backday);
	msg.set_m_costitemid((int32_t)m_costitemid);
	msg.set_m_costnum((int32_t)m_costnum);
	msg.set_m_pcostitemid((int32_t)m_pcostitemid);
	msg.set_m_pcostnum((int32_t)m_pcostnum);
	msg.set_m_acostitemid((int32_t)m_acostitemid);
	msg.set_m_acostnum((int32_t)m_acostnum);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
}

void E_BackBack_s::read_from_pbmsg(const ::proto_ff::E_BackBack & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_typeparam = msg.m_typeparam();
	m_name = msg.m_name();
	m_group = msg.m_group();
	m_functionunlock = msg.m_functionunlock();
	m_levellimit = msg.m_levellimit();
	m_pboxid = msg.m_pboxid();
	m_boxid = msg.m_boxid();
	m_backday = msg.m_backday();
	m_costitemid = msg.m_costitemid();
	m_costnum = msg.m_costnum();
	m_pcostitemid = msg.m_pcostitemid();
	m_pcostnum = msg.m_pcostnum();
	m_acostitemid = msg.m_acostitemid();
	m_acostnum = msg.m_acostnum();
	m_param.resize((int)msg.m_param_size() > (int)m_param.max_size() ? m_param.max_size() : msg.m_param_size());
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		m_param[i] = msg.m_param(i);
	}
}

Sheet_BackBack_s::Sheet_BackBack_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_BackBack_s::CreateInit() {
	return 0;
}

int Sheet_BackBack_s::ResumeInit() {
	return 0;
}

void Sheet_BackBack_s::write_to_pbmsg(::proto_ff::Sheet_BackBack & msg) const {
	for(int32_t i = 0; i < (int32_t)E_BackBack_List.size(); ++i) {
		::proto_ff::E_BackBack* temp_e_backback_list = msg.add_e_backback_list();
		E_BackBack_List[i].write_to_pbmsg(*temp_e_backback_list);
	}
}

void Sheet_BackBack_s::read_from_pbmsg(const ::proto_ff::Sheet_BackBack & msg) {
	E_BackBack_List.resize((int)msg.e_backback_list_size() > (int)E_BackBack_List.max_size() ? E_BackBack_List.max_size() : msg.e_backback_list_size());
	for(int32_t i = 0; i < (int32_t)E_BackBack_List.size(); ++i) {
		const ::proto_ff::E_BackBack & temp_e_backback_list = msg.e_backback_list(i);
		E_BackBack_List[i].read_from_pbmsg(temp_e_backback_list);
	}
}

}
