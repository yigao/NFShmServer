#include "E_Teleport_s.h"

namespace proto_ff_s {

E_TeleportTeleport_s::E_TeleportTeleport_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TeleportTeleport_s::CreateInit() {
	m_teleportid = (int64_t)0;
	m_teleporttype = (int32_t)0;
	m_monsterid = (int64_t)0;
	m_showcondition = (int32_t)0;
	m_canenter = (int32_t)0;
	m_showpathid = (int64_t)0;
	m_topathid = (int64_t)0;
	m_toduplicateid = (int64_t)0;
	m_trigrange = (int32_t)0;
	m_livingtime = (int32_t)0;
	m_openchatid = (int64_t)0;
	m_progresschatid = (int64_t)0;
	return 0;
}

int E_TeleportTeleport_s::ResumeInit() {
	return 0;
}

void E_TeleportTeleport_s::write_to_pbmsg(::proto_ff::E_TeleportTeleport & msg) const {
	msg.set_m_teleportid((int64_t)m_teleportid);
	msg.set_m_teleporttype((int32_t)m_teleporttype);
	msg.set_m_name(m_name.data());
	msg.set_m_monsterid((int64_t)m_monsterid);
	msg.set_m_showcondition((int32_t)m_showcondition);
	msg.set_m_conditionvalue(m_conditionvalue.data());
	msg.set_m_canenter((int32_t)m_canenter);
	msg.set_m_showpathid((int64_t)m_showpathid);
	msg.set_m_topathid((int64_t)m_topathid);
	msg.set_m_toduplicateid((int64_t)m_toduplicateid);
	msg.set_m_entercost(m_entercost.data());
	msg.set_m_trigrange((int32_t)m_trigrange);
	msg.set_m_livingtime((int32_t)m_livingtime);
	msg.set_m_openchatid((int64_t)m_openchatid);
	msg.set_m_progresschatid((int64_t)m_progresschatid);
}

void E_TeleportTeleport_s::read_from_pbmsg(const ::proto_ff::E_TeleportTeleport & msg) {
	m_teleportid = msg.m_teleportid();
	m_teleporttype = msg.m_teleporttype();
	m_name = msg.m_name();
	m_monsterid = msg.m_monsterid();
	m_showcondition = msg.m_showcondition();
	m_conditionvalue = msg.m_conditionvalue();
	m_canenter = msg.m_canenter();
	m_showpathid = msg.m_showpathid();
	m_topathid = msg.m_topathid();
	m_toduplicateid = msg.m_toduplicateid();
	m_entercost = msg.m_entercost();
	m_trigrange = msg.m_trigrange();
	m_livingtime = msg.m_livingtime();
	m_openchatid = msg.m_openchatid();
	m_progresschatid = msg.m_progresschatid();
}

Sheet_TeleportTeleport_s::Sheet_TeleportTeleport_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TeleportTeleport_s::CreateInit() {
	return 0;
}

int Sheet_TeleportTeleport_s::ResumeInit() {
	return 0;
}

void Sheet_TeleportTeleport_s::write_to_pbmsg(::proto_ff::Sheet_TeleportTeleport & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TeleportTeleport_List.size(); ++i) {
		::proto_ff::E_TeleportTeleport* temp_e_teleportteleport_list = msg.add_e_teleportteleport_list();
		E_TeleportTeleport_List[i].write_to_pbmsg(*temp_e_teleportteleport_list);
	}
}

void Sheet_TeleportTeleport_s::read_from_pbmsg(const ::proto_ff::Sheet_TeleportTeleport & msg) {
	E_TeleportTeleport_List.resize((int)msg.e_teleportteleport_list_size() > (int)E_TeleportTeleport_List.max_size() ? E_TeleportTeleport_List.max_size() : msg.e_teleportteleport_list_size());
	for(int32_t i = 0; i < (int32_t)E_TeleportTeleport_List.size(); ++i) {
		const ::proto_ff::E_TeleportTeleport & temp_e_teleportteleport_list = msg.e_teleportteleport_list(i);
		E_TeleportTeleport_List[i].read_from_pbmsg(temp_e_teleportteleport_list);
	}
}

}
