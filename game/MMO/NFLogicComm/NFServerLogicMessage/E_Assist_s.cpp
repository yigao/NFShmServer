#include "E_Assist_s.h"

namespace proto_ff_s {

E_AssistBox_s::E_AssistBox_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AssistBox_s::CreateInit() {
	m_id = (int32_t)0;
	m_times = (int32_t)0;
	m_itemid = (int32_t)0;
	return 0;
}

int E_AssistBox_s::ResumeInit() {
	return 0;
}

void E_AssistBox_s::write_to_pbmsg(::proto_ff::E_AssistBox & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_times((int32_t)m_times);
	msg.set_m_itemid((int32_t)m_itemid);
}

void E_AssistBox_s::read_from_pbmsg(const ::proto_ff::E_AssistBox & msg) {
	m_id = msg.m_id();
	m_times = msg.m_times();
	m_itemid = msg.m_itemid();
}

Sheet_AssistBox_s::Sheet_AssistBox_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AssistBox_s::CreateInit() {
	return 0;
}

int Sheet_AssistBox_s::ResumeInit() {
	return 0;
}

void Sheet_AssistBox_s::write_to_pbmsg(::proto_ff::Sheet_AssistBox & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AssistBox_List.size(); ++i) {
		::proto_ff::E_AssistBox* temp_e_assistbox_list = msg.add_e_assistbox_list();
		E_AssistBox_List[i].write_to_pbmsg(*temp_e_assistbox_list);
	}
}

void Sheet_AssistBox_s::read_from_pbmsg(const ::proto_ff::Sheet_AssistBox & msg) {
	E_AssistBox_List.resize((int)msg.e_assistbox_list_size() > (int)E_AssistBox_List.max_size() ? E_AssistBox_List.max_size() : msg.e_assistbox_list_size());
	for(int32_t i = 0; i < (int32_t)E_AssistBox_List.size(); ++i) {
		const ::proto_ff::E_AssistBox & temp_e_assistbox_list = msg.e_assistbox_list(i);
		E_AssistBox_List[i].read_from_pbmsg(temp_e_assistbox_list);
	}
}

E_AssistThank_s::E_AssistThank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AssistThank_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_AssistThank_s::ResumeInit() {
	return 0;
}

void E_AssistThank_s::write_to_pbmsg(::proto_ff::E_AssistThank & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_msg(m_msg.data());
}

void E_AssistThank_s::read_from_pbmsg(const ::proto_ff::E_AssistThank & msg) {
	m_id = msg.m_id();
	m_msg = msg.m_msg();
}

Sheet_AssistThank_s::Sheet_AssistThank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AssistThank_s::CreateInit() {
	return 0;
}

int Sheet_AssistThank_s::ResumeInit() {
	return 0;
}

void Sheet_AssistThank_s::write_to_pbmsg(::proto_ff::Sheet_AssistThank & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AssistThank_List.size(); ++i) {
		::proto_ff::E_AssistThank* temp_e_assistthank_list = msg.add_e_assistthank_list();
		E_AssistThank_List[i].write_to_pbmsg(*temp_e_assistthank_list);
	}
}

void Sheet_AssistThank_s::read_from_pbmsg(const ::proto_ff::Sheet_AssistThank & msg) {
	E_AssistThank_List.resize((int)msg.e_assistthank_list_size() > (int)E_AssistThank_List.max_size() ? E_AssistThank_List.max_size() : msg.e_assistthank_list_size());
	for(int32_t i = 0; i < (int32_t)E_AssistThank_List.size(); ++i) {
		const ::proto_ff::E_AssistThank & temp_e_assistthank_list = msg.e_assistthank_list(i);
		E_AssistThank_List[i].read_from_pbmsg(temp_e_assistthank_list);
	}
}

E_AssistConst_s::E_AssistConst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AssistConst_s::CreateInit() {
	m_id = (int32_t)0;
	m_senderGift = (int32_t)0;
	m_senderGiftNum = (int32_t)0;
	m_helperGift = (int32_t)0;
	m_helperGiftNum = (int32_t)0;
	m_prestigeDaylimit = (int32_t)0;
	m_prestigeDayBosslimit = (int32_t)0;
	return 0;
}

int E_AssistConst_s::ResumeInit() {
	return 0;
}

void E_AssistConst_s::write_to_pbmsg(::proto_ff::E_AssistConst & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_sendergift((int32_t)m_senderGift);
	msg.set_m_sendergiftnum((int32_t)m_senderGiftNum);
	msg.set_m_helpergift((int32_t)m_helperGift);
	msg.set_m_helpergiftnum((int32_t)m_helperGiftNum);
	msg.set_m_prestigedaylimit((int32_t)m_prestigeDaylimit);
	msg.set_m_prestigedaybosslimit((int32_t)m_prestigeDayBosslimit);
}

void E_AssistConst_s::read_from_pbmsg(const ::proto_ff::E_AssistConst & msg) {
	m_id = msg.m_id();
	m_senderGift = msg.m_sendergift();
	m_senderGiftNum = msg.m_sendergiftnum();
	m_helperGift = msg.m_helpergift();
	m_helperGiftNum = msg.m_helpergiftnum();
	m_prestigeDaylimit = msg.m_prestigedaylimit();
	m_prestigeDayBosslimit = msg.m_prestigedaybosslimit();
}

Sheet_AssistConst_s::Sheet_AssistConst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AssistConst_s::CreateInit() {
	return 0;
}

int Sheet_AssistConst_s::ResumeInit() {
	return 0;
}

void Sheet_AssistConst_s::write_to_pbmsg(::proto_ff::Sheet_AssistConst & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AssistConst_List.size(); ++i) {
		::proto_ff::E_AssistConst* temp_e_assistconst_list = msg.add_e_assistconst_list();
		E_AssistConst_List[i].write_to_pbmsg(*temp_e_assistconst_list);
	}
}

void Sheet_AssistConst_s::read_from_pbmsg(const ::proto_ff::Sheet_AssistConst & msg) {
	E_AssistConst_List.resize((int)msg.e_assistconst_list_size() > (int)E_AssistConst_List.max_size() ? E_AssistConst_List.max_size() : msg.e_assistconst_list_size());
	for(int32_t i = 0; i < (int32_t)E_AssistConst_List.size(); ++i) {
		const ::proto_ff::E_AssistConst & temp_e_assistconst_list = msg.e_assistconst_list(i);
		E_AssistConst_List[i].read_from_pbmsg(temp_e_assistconst_list);
	}
}

}
