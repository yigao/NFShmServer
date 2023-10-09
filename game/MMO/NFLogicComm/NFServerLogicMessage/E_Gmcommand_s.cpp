#include "E_Gmcommand_s.h"

namespace proto_ff_s {

E_GmcommandGmcommand_s::E_GmcommandGmcommand_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GmcommandGmcommand_s::CreateInit() {
	m_id = (int32_t)0;
	m_paramcount = (int32_t)0;
	return 0;
}

int E_GmcommandGmcommand_s::ResumeInit() {
	return 0;
}

void E_GmcommandGmcommand_s::write_to_pbmsg(::proto_ff::E_GmcommandGmcommand & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_key(m_key.data());
	msg.set_m_paramcount((int32_t)m_paramcount);
	msg.set_m_des(m_des.data());
}

void E_GmcommandGmcommand_s::read_from_pbmsg(const ::proto_ff::E_GmcommandGmcommand & msg) {
	m_id = msg.m_id();
	m_key = msg.m_key();
	m_paramcount = msg.m_paramcount();
	m_des = msg.m_des();
}

Sheet_GmcommandGmcommand_s::Sheet_GmcommandGmcommand_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GmcommandGmcommand_s::CreateInit() {
	return 0;
}

int Sheet_GmcommandGmcommand_s::ResumeInit() {
	return 0;
}

void Sheet_GmcommandGmcommand_s::write_to_pbmsg(::proto_ff::Sheet_GmcommandGmcommand & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GmcommandGmcommand_List.size(); ++i) {
		::proto_ff::E_GmcommandGmcommand* temp_e_gmcommandgmcommand_list = msg.add_e_gmcommandgmcommand_list();
		E_GmcommandGmcommand_List[i].write_to_pbmsg(*temp_e_gmcommandgmcommand_list);
	}
}

void Sheet_GmcommandGmcommand_s::read_from_pbmsg(const ::proto_ff::Sheet_GmcommandGmcommand & msg) {
	E_GmcommandGmcommand_List.resize((int)msg.e_gmcommandgmcommand_list_size() > (int)E_GmcommandGmcommand_List.max_size() ? E_GmcommandGmcommand_List.max_size() : msg.e_gmcommandgmcommand_list_size());
	for(int32_t i = 0; i < (int32_t)E_GmcommandGmcommand_List.size(); ++i) {
		const ::proto_ff::E_GmcommandGmcommand & temp_e_gmcommandgmcommand_list = msg.e_gmcommandgmcommand_list(i);
		E_GmcommandGmcommand_List[i].read_from_pbmsg(temp_e_gmcommandgmcommand_list);
	}
}

}
