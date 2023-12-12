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
	m_teleportID = (int64_t)0;
	m_teleportType = (int32_t)0;
	m_monsterId = (int64_t)0;
	m_showCondition = (int32_t)0;
	m_canEnter = (int32_t)0;
	m_showPathID = (int64_t)0;
	m_toPathID = (int64_t)0;
	m_toDuplicateId = (int64_t)0;
	m_trigRange = (int32_t)0;
	m_livingTime = (int32_t)0;
	m_openChatId = (int64_t)0;
	m_progressChatId = (int64_t)0;
	return 0;
}

int E_TeleportTeleport_s::ResumeInit() {
	return 0;
}

void E_TeleportTeleport_s::write_to_pbmsg(::proto_ff::E_TeleportTeleport & msg) const {
	msg.set_m_teleportid((int64_t)m_teleportID);
	msg.set_m_teleporttype((int32_t)m_teleportType);
	msg.set_m_name(m_name.data());
	msg.set_m_monsterid((int64_t)m_monsterId);
	msg.set_m_showcondition((int32_t)m_showCondition);
	msg.set_m_conditionvalue(m_conditionValue.data());
	msg.set_m_canenter((int32_t)m_canEnter);
	msg.set_m_showpathid((int64_t)m_showPathID);
	msg.set_m_topathid((int64_t)m_toPathID);
	msg.set_m_toduplicateid((int64_t)m_toDuplicateId);
	msg.set_m_entercost(m_enterCost.data());
	msg.set_m_trigrange((int32_t)m_trigRange);
	msg.set_m_livingtime((int32_t)m_livingTime);
	msg.set_m_openchatid((int64_t)m_openChatId);
	msg.set_m_progresschatid((int64_t)m_progressChatId);
}

void E_TeleportTeleport_s::read_from_pbmsg(const ::proto_ff::E_TeleportTeleport & msg) {
	m_teleportID = msg.m_teleportid();
	m_teleportType = msg.m_teleporttype();
	m_name = msg.m_name();
	m_monsterId = msg.m_monsterid();
	m_showCondition = msg.m_showcondition();
	m_conditionValue = msg.m_conditionvalue();
	m_canEnter = msg.m_canenter();
	m_showPathID = msg.m_showpathid();
	m_toPathID = msg.m_topathid();
	m_toDuplicateId = msg.m_toduplicateid();
	m_enterCost = msg.m_entercost();
	m_trigRange = msg.m_trigrange();
	m_livingTime = msg.m_livingtime();
	m_openChatId = msg.m_openchatid();
	m_progressChatId = msg.m_progresschatid();
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
