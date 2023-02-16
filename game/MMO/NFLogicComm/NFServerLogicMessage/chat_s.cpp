#include "chat_s.h"

namespace proto_ff_s {

E_ChatChat_s::E_ChatChat_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ChatChat_s::CreateInit() {
	m_chatid = (int64_t)0;
	m_chattype = (int32_t)0;
	m_showtime = (int32_t)0;
	m_channel = (int32_t)0;
	m_crossservice = (int32_t)0;
	return 0;
}

int E_ChatChat_s::ResumeInit() {
	return 0;
}

void E_ChatChat_s::write_to_pbmsg(::proto_ff::E_ChatChat & msg) const {
	msg.set_m_chatid((int64_t)m_chatid);
	msg.set_m_chattype((int32_t)m_chattype);
	msg.set_m_showtime((int32_t)m_showtime);
	msg.set_m_chatcontent((const char*)m_chatcontent.data());
	msg.set_m_channel((int32_t)m_channel);
	msg.set_m_crossservice((int32_t)m_crossservice);
}

void E_ChatChat_s::read_from_pbmsg(const ::proto_ff::E_ChatChat & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ChatChat_s));
	m_chatid = msg.m_chatid();
	m_chattype = msg.m_chattype();
	m_showtime = msg.m_showtime();
	m_chatcontent = msg.m_chatcontent();
	m_channel = msg.m_channel();
	m_crossservice = msg.m_crossservice();
}

Sheet_ChatChat_s::Sheet_ChatChat_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ChatChat_s::CreateInit() {
	return 0;
}

int Sheet_ChatChat_s::ResumeInit() {
	return 0;
}

void Sheet_ChatChat_s::write_to_pbmsg(::proto_ff::Sheet_ChatChat & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ChatChat_List.size(); ++i) {
		::proto_ff::E_ChatChat* temp_e_chatchat_list = msg.add_e_chatchat_list();
		E_ChatChat_List[i].write_to_pbmsg(*temp_e_chatchat_list);
	}
}

void Sheet_ChatChat_s::read_from_pbmsg(const ::proto_ff::Sheet_ChatChat & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_ChatChat_s));
	E_ChatChat_List.resize((int)msg.e_chatchat_list_size() > (int)E_ChatChat_List.max_size() ? E_ChatChat_List.max_size() : msg.e_chatchat_list_size());
	for(int32_t i = 0; i < (int32_t)E_ChatChat_List.size(); ++i) {
		const ::proto_ff::E_ChatChat & temp_e_chatchat_list = msg.e_chatchat_list(i);
		E_ChatChat_List[i].read_from_pbmsg(temp_e_chatchat_list);
	}
}

E_ChatSpecialchat_s::E_ChatSpecialchat_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ChatSpecialchat_s::CreateInit() {
	m_type = (int32_t)0;
	m_chat_id = (int64_t)0;
	return 0;
}

int E_ChatSpecialchat_s::ResumeInit() {
	return 0;
}

void E_ChatSpecialchat_s::write_to_pbmsg(::proto_ff::E_ChatSpecialchat & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_parama((const char*)m_parama.data());
	msg.set_m_paramb((const char*)m_paramb.data());
	msg.set_m_chat_id((int64_t)m_chat_id);
}

void E_ChatSpecialchat_s::read_from_pbmsg(const ::proto_ff::E_ChatSpecialchat & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ChatSpecialchat_s));
	m_type = msg.m_type();
	m_parama = msg.m_parama();
	m_paramb = msg.m_paramb();
	m_chat_id = msg.m_chat_id();
}

Sheet_ChatSpecialchat_s::Sheet_ChatSpecialchat_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ChatSpecialchat_s::CreateInit() {
	return 0;
}

int Sheet_ChatSpecialchat_s::ResumeInit() {
	return 0;
}

void Sheet_ChatSpecialchat_s::write_to_pbmsg(::proto_ff::Sheet_ChatSpecialchat & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ChatSpecialchat_List.size(); ++i) {
		::proto_ff::E_ChatSpecialchat* temp_e_chatspecialchat_list = msg.add_e_chatspecialchat_list();
		E_ChatSpecialchat_List[i].write_to_pbmsg(*temp_e_chatspecialchat_list);
	}
}

void Sheet_ChatSpecialchat_s::read_from_pbmsg(const ::proto_ff::Sheet_ChatSpecialchat & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_ChatSpecialchat_s));
	E_ChatSpecialchat_List.resize((int)msg.e_chatspecialchat_list_size() > (int)E_ChatSpecialchat_List.max_size() ? E_ChatSpecialchat_List.max_size() : msg.e_chatspecialchat_list_size());
	for(int32_t i = 0; i < (int32_t)E_ChatSpecialchat_List.size(); ++i) {
		const ::proto_ff::E_ChatSpecialchat & temp_e_chatspecialchat_list = msg.e_chatspecialchat_list(i);
		E_ChatSpecialchat_List[i].read_from_pbmsg(temp_e_chatspecialchat_list);
	}
}

}