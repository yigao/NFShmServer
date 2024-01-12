#include "E_Fish_s.h"

namespace proto_ff_s {

E_FishRoom_s::E_FishRoom_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FishRoom_s::CreateInit() {
	m_id = (int32_t)0;
	m_roomId = (int32_t)0;
	m_gameId = (int32_t)0;
	m_roomType = (int32_t)0;
	m_roomLevel = (int32_t)0;
	m_siteNum = (int32_t)0;
	m_deskCount = (int32_t)0;
	m_maxPeople = (int32_t)0;
	m_enterMin = (int32_t)0;
	m_enterMax = (int32_t)0;
	m_autoChair = (int32_t)0;
	m_isExpScene = (int32_t)0;
	m_expSceneGold = (int32_t)0;
	m_tax = (int32_t)0;
	return 0;
}

int E_FishRoom_s::ResumeInit() {
	return 0;
}

void E_FishRoom_s::write_to_pbmsg(::proto_ff::E_FishRoom & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_roomid((int32_t)m_roomId);
	msg.set_m_gameid((int32_t)m_gameId);
	msg.set_m_gamename(m_gameName.data());
	msg.set_m_roomtype((int32_t)m_roomType);
	msg.set_m_roomlevel((int32_t)m_roomLevel);
	msg.set_m_roomname(m_roomName.data());
	msg.set_m_sitenum((int32_t)m_siteNum);
	msg.set_m_deskcount((int32_t)m_deskCount);
	msg.set_m_maxpeople((int32_t)m_maxPeople);
	msg.set_m_entermin((int32_t)m_enterMin);
	msg.set_m_entermax((int32_t)m_enterMax);
	msg.set_m_autochair((int32_t)m_autoChair);
	msg.set_m_isexpscene((int32_t)m_isExpScene);
	msg.set_m_expscenegold((int32_t)m_expSceneGold);
	msg.set_m_tax((int32_t)m_tax);
}

void E_FishRoom_s::read_from_pbmsg(const ::proto_ff::E_FishRoom & msg) {
	m_id = msg.m_id();
	m_roomId = msg.m_roomid();
	m_gameId = msg.m_gameid();
	m_gameName = msg.m_gamename();
	m_roomType = msg.m_roomtype();
	m_roomLevel = msg.m_roomlevel();
	m_roomName = msg.m_roomname();
	m_siteNum = msg.m_sitenum();
	m_deskCount = msg.m_deskcount();
	m_maxPeople = msg.m_maxpeople();
	m_enterMin = msg.m_entermin();
	m_enterMax = msg.m_entermax();
	m_autoChair = msg.m_autochair();
	m_isExpScene = msg.m_isexpscene();
	m_expSceneGold = msg.m_expscenegold();
	m_tax = msg.m_tax();
}

Sheet_FishRoom_s::Sheet_FishRoom_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FishRoom_s::CreateInit() {
	return 0;
}

int Sheet_FishRoom_s::ResumeInit() {
	return 0;
}

void Sheet_FishRoom_s::write_to_pbmsg(::proto_ff::Sheet_FishRoom & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FishRoom_List.size(); ++i) {
		::proto_ff::E_FishRoom* temp_e_fishroom_list = msg.add_e_fishroom_list();
		E_FishRoom_List[i].write_to_pbmsg(*temp_e_fishroom_list);
	}
}

void Sheet_FishRoom_s::read_from_pbmsg(const ::proto_ff::Sheet_FishRoom & msg) {
	E_FishRoom_List.resize((int)msg.e_fishroom_list_size() > (int)E_FishRoom_List.max_size() ? E_FishRoom_List.max_size() : msg.e_fishroom_list_size());
	for(int32_t i = 0; i < (int32_t)E_FishRoom_List.size(); ++i) {
		const ::proto_ff::E_FishRoom & temp_e_fishroom_list = msg.e_fishroom_list(i);
		E_FishRoom_List[i].read_from_pbmsg(temp_e_fishroom_list);
	}
}

E_FishGunvalue_s::E_FishGunvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FishGunvalue_s::CreateInit() {
	m_id = (int32_t)0;
	m_value = (int32_t)0;
	m_gameId = (int32_t)0;
	m_roomId = (int32_t)0;
	m_gunId = (int32_t)0;
	return 0;
}

int E_FishGunvalue_s::ResumeInit() {
	return 0;
}

void E_FishGunvalue_s::write_to_pbmsg(::proto_ff::E_FishGunvalue & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_gameid((int32_t)m_gameId);
	msg.set_m_roomid((int32_t)m_roomId);
	msg.set_m_gunid((int32_t)m_gunId);
}

void E_FishGunvalue_s::read_from_pbmsg(const ::proto_ff::E_FishGunvalue & msg) {
	m_id = msg.m_id();
	m_value = msg.m_value();
	m_gameId = msg.m_gameid();
	m_roomId = msg.m_roomid();
	m_gunId = msg.m_gunid();
}

Sheet_FishGunvalue_s::Sheet_FishGunvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FishGunvalue_s::CreateInit() {
	return 0;
}

int Sheet_FishGunvalue_s::ResumeInit() {
	return 0;
}

void Sheet_FishGunvalue_s::write_to_pbmsg(::proto_ff::Sheet_FishGunvalue & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FishGunvalue_List.size(); ++i) {
		::proto_ff::E_FishGunvalue* temp_e_fishgunvalue_list = msg.add_e_fishgunvalue_list();
		E_FishGunvalue_List[i].write_to_pbmsg(*temp_e_fishgunvalue_list);
	}
}

void Sheet_FishGunvalue_s::read_from_pbmsg(const ::proto_ff::Sheet_FishGunvalue & msg) {
	E_FishGunvalue_List.resize((int)msg.e_fishgunvalue_list_size() > (int)E_FishGunvalue_List.max_size() ? E_FishGunvalue_List.max_size() : msg.e_fishgunvalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_FishGunvalue_List.size(); ++i) {
		const ::proto_ff::E_FishGunvalue & temp_e_fishgunvalue_list = msg.e_fishgunvalue_list(i);
		E_FishGunvalue_List[i].read_from_pbmsg(temp_e_fishgunvalue_list);
	}
}

E_FishCtrllevel_s::E_FishCtrllevel_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FishCtrllevel_s::CreateInit() {
	m_ControlLevel = (int32_t)0;
	m_ControlRate = (int32_t)0;
	return 0;
}

int E_FishCtrllevel_s::ResumeInit() {
	return 0;
}

void E_FishCtrllevel_s::write_to_pbmsg(::proto_ff::E_FishCtrllevel & msg) const {
	msg.set_m_controllevel((int32_t)m_ControlLevel);
	msg.set_m_controlrate((int32_t)m_ControlRate);
}

void E_FishCtrllevel_s::read_from_pbmsg(const ::proto_ff::E_FishCtrllevel & msg) {
	m_ControlLevel = msg.m_controllevel();
	m_ControlRate = msg.m_controlrate();
}

Sheet_FishCtrllevel_s::Sheet_FishCtrllevel_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FishCtrllevel_s::CreateInit() {
	return 0;
}

int Sheet_FishCtrllevel_s::ResumeInit() {
	return 0;
}

void Sheet_FishCtrllevel_s::write_to_pbmsg(::proto_ff::Sheet_FishCtrllevel & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FishCtrllevel_List.size(); ++i) {
		::proto_ff::E_FishCtrllevel* temp_e_fishctrllevel_list = msg.add_e_fishctrllevel_list();
		E_FishCtrllevel_List[i].write_to_pbmsg(*temp_e_fishctrllevel_list);
	}
}

void Sheet_FishCtrllevel_s::read_from_pbmsg(const ::proto_ff::Sheet_FishCtrllevel & msg) {
	E_FishCtrllevel_List.resize((int)msg.e_fishctrllevel_list_size() > (int)E_FishCtrllevel_List.max_size() ? E_FishCtrllevel_List.max_size() : msg.e_fishctrllevel_list_size());
	for(int32_t i = 0; i < (int32_t)E_FishCtrllevel_List.size(); ++i) {
		const ::proto_ff::E_FishCtrllevel & temp_e_fishctrllevel_list = msg.e_fishctrllevel_list(i);
		E_FishCtrllevel_List[i].read_from_pbmsg(temp_e_fishctrllevel_list);
	}
}

}
