#include "E_Washparty_s.h"

namespace proto_ff_s {

E_WashpartyWashparty_s::E_WashpartyWashparty_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WashpartyWashparty_s::CreateInit() {
	m_id = (int32_t)0;
	m_collectId = (int32_t)0;
	m_collectNum = (int32_t)0;
	m_collectPosId = (int32_t)0;
	m_collectGenInterval = (int32_t)0;
	m_collectMax = (int32_t)0;
	m_splashNum = (int32_t)0;
	m_splashReward = (int32_t)0;
	m_massageNum = (int32_t)0;
	m_massageTime = (int32_t)0;
	m_massageReward = (int32_t)0;
	m_pairExpAddition = (int32_t)0;
	m_mapId = (int32_t)0;
	m_duration = (int32_t)0;
	m_expAddInterval = (int32_t)0;
	m_splashSI = (int32_t)0;
	m_birthAreaId = (int32_t)0;
	m_actId = (int32_t)0;
	return 0;
}

int E_WashpartyWashparty_s::ResumeInit() {
	return 0;
}

void E_WashpartyWashparty_s::write_to_pbmsg(::proto_ff::E_WashpartyWashparty & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_collectid((int32_t)m_collectId);
	msg.set_m_collectnum((int32_t)m_collectNum);
	msg.set_m_collectposid((int32_t)m_collectPosId);
	msg.set_m_collectgeninterval((int32_t)m_collectGenInterval);
	msg.set_m_collectmax((int32_t)m_collectMax);
	msg.set_m_splashnum((int32_t)m_splashNum);
	msg.set_m_splashreward((int32_t)m_splashReward);
	msg.set_m_massagenum((int32_t)m_massageNum);
	msg.set_m_massagetime((int32_t)m_massageTime);
	msg.set_m_massagereward((int32_t)m_massageReward);
	msg.set_m_pairexpaddition((int32_t)m_pairExpAddition);
	msg.set_m_mapid((int32_t)m_mapId);
	msg.set_m_duration((int32_t)m_duration);
	msg.set_m_expaddinterval((int32_t)m_expAddInterval);
	msg.set_m_splashsi((int32_t)m_splashSI);
	msg.set_m_birthareaid((int32_t)m_birthAreaId);
	msg.set_m_actid((int32_t)m_actId);
}

void E_WashpartyWashparty_s::read_from_pbmsg(const ::proto_ff::E_WashpartyWashparty & msg) {
	m_id = msg.m_id();
	m_collectId = msg.m_collectid();
	m_collectNum = msg.m_collectnum();
	m_collectPosId = msg.m_collectposid();
	m_collectGenInterval = msg.m_collectgeninterval();
	m_collectMax = msg.m_collectmax();
	m_splashNum = msg.m_splashnum();
	m_splashReward = msg.m_splashreward();
	m_massageNum = msg.m_massagenum();
	m_massageTime = msg.m_massagetime();
	m_massageReward = msg.m_massagereward();
	m_pairExpAddition = msg.m_pairexpaddition();
	m_mapId = msg.m_mapid();
	m_duration = msg.m_duration();
	m_expAddInterval = msg.m_expaddinterval();
	m_splashSI = msg.m_splashsi();
	m_birthAreaId = msg.m_birthareaid();
	m_actId = msg.m_actid();
}

Sheet_WashpartyWashparty_s::Sheet_WashpartyWashparty_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WashpartyWashparty_s::CreateInit() {
	return 0;
}

int Sheet_WashpartyWashparty_s::ResumeInit() {
	return 0;
}

void Sheet_WashpartyWashparty_s::write_to_pbmsg(::proto_ff::Sheet_WashpartyWashparty & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WashpartyWashparty_List.size(); ++i) {
		::proto_ff::E_WashpartyWashparty* temp_e_washpartywashparty_list = msg.add_e_washpartywashparty_list();
		E_WashpartyWashparty_List[i].write_to_pbmsg(*temp_e_washpartywashparty_list);
	}
}

void Sheet_WashpartyWashparty_s::read_from_pbmsg(const ::proto_ff::Sheet_WashpartyWashparty & msg) {
	E_WashpartyWashparty_List.resize((int)msg.e_washpartywashparty_list_size() > (int)E_WashpartyWashparty_List.max_size() ? E_WashpartyWashparty_List.max_size() : msg.e_washpartywashparty_list_size());
	for(int32_t i = 0; i < (int32_t)E_WashpartyWashparty_List.size(); ++i) {
		const ::proto_ff::E_WashpartyWashparty & temp_e_washpartywashparty_list = msg.e_washpartywashparty_list(i);
		E_WashpartyWashparty_List[i].read_from_pbmsg(temp_e_washpartywashparty_list);
	}
}

E_WashpartyExp_s::E_WashpartyExp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WashpartyExp_s::CreateInit() {
	m_lv = (int32_t)0;
	m_washExp = (int32_t)0;
	return 0;
}

int E_WashpartyExp_s::ResumeInit() {
	return 0;
}

void E_WashpartyExp_s::write_to_pbmsg(::proto_ff::E_WashpartyExp & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_washexp((int32_t)m_washExp);
}

void E_WashpartyExp_s::read_from_pbmsg(const ::proto_ff::E_WashpartyExp & msg) {
	m_lv = msg.m_lv();
	m_washExp = msg.m_washexp();
}

Sheet_WashpartyExp_s::Sheet_WashpartyExp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WashpartyExp_s::CreateInit() {
	return 0;
}

int Sheet_WashpartyExp_s::ResumeInit() {
	return 0;
}

void Sheet_WashpartyExp_s::write_to_pbmsg(::proto_ff::Sheet_WashpartyExp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WashpartyExp_List.size(); ++i) {
		::proto_ff::E_WashpartyExp* temp_e_washpartyexp_list = msg.add_e_washpartyexp_list();
		E_WashpartyExp_List[i].write_to_pbmsg(*temp_e_washpartyexp_list);
	}
}

void Sheet_WashpartyExp_s::read_from_pbmsg(const ::proto_ff::Sheet_WashpartyExp & msg) {
	E_WashpartyExp_List.resize((int)msg.e_washpartyexp_list_size() > (int)E_WashpartyExp_List.max_size() ? E_WashpartyExp_List.max_size() : msg.e_washpartyexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_WashpartyExp_List.size(); ++i) {
		const ::proto_ff::E_WashpartyExp & temp_e_washpartyexp_list = msg.e_washpartyexp_list(i);
		E_WashpartyExp_List[i].read_from_pbmsg(temp_e_washpartyexp_list);
	}
}

}
