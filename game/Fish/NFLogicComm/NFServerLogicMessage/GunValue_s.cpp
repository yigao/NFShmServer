#include "GunValue_s.h"

namespace proto_ff_s {

E_GunvalueConfig_s::E_GunvalueConfig_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GunvalueConfig_s::CreateInit() {
	m_id = (int32_t)0;
	m_value = (int32_t)0;
	m_gameid = (int32_t)0;
	m_roomid = (int32_t)0;
	m_gunid = (int32_t)0;
	return 0;
}

int E_GunvalueConfig_s::ResumeInit() {
	return 0;
}

void E_GunvalueConfig_s::write_to_pbmsg(::proto_ff::E_GunvalueConfig & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_gameid((int32_t)m_gameid);
	msg.set_m_roomid((int32_t)m_roomid);
	msg.set_m_gunid((int32_t)m_gunid);
}

void E_GunvalueConfig_s::read_from_pbmsg(const ::proto_ff::E_GunvalueConfig & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GunvalueConfig_s));
	m_id = msg.m_id();
	m_value = msg.m_value();
	m_gameid = msg.m_gameid();
	m_roomid = msg.m_roomid();
	m_gunid = msg.m_gunid();
}

Sheet_GunvalueConfig_s::Sheet_GunvalueConfig_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GunvalueConfig_s::CreateInit() {
	return 0;
}

int Sheet_GunvalueConfig_s::ResumeInit() {
	return 0;
}

void Sheet_GunvalueConfig_s::write_to_pbmsg(::proto_ff::Sheet_GunvalueConfig & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GunvalueConfig_List.size(); ++i) {
		::proto_ff::E_GunvalueConfig* temp_e_gunvalueconfig_list = msg.add_e_gunvalueconfig_list();
		E_GunvalueConfig_List[i].write_to_pbmsg(*temp_e_gunvalueconfig_list);
	}
}

void Sheet_GunvalueConfig_s::read_from_pbmsg(const ::proto_ff::Sheet_GunvalueConfig & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GunvalueConfig_s));
	E_GunvalueConfig_List.resize((int)msg.e_gunvalueconfig_list_size() > (int)E_GunvalueConfig_List.max_size() ? E_GunvalueConfig_List.max_size() : msg.e_gunvalueconfig_list_size());
	for(int32_t i = 0; i < (int32_t)E_GunvalueConfig_List.size(); ++i) {
		const ::proto_ff::E_GunvalueConfig & temp_e_gunvalueconfig_list = msg.e_gunvalueconfig_list(i);
		E_GunvalueConfig_List[i].read_from_pbmsg(temp_e_gunvalueconfig_list);
	}
}

}