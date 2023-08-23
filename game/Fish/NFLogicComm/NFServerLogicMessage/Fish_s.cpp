#include "Fish_s.h"

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
	m_roomid = (int32_t)0;
	m_gameid = (int32_t)0;
	m_roomtype = (int32_t)0;
	m_roomlevel = (int32_t)0;
	m_sitenum = (int32_t)0;
	m_deskcount = (int32_t)0;
	m_maxpeople = (int32_t)0;
	m_entermin = (int32_t)0;
	m_entermax = (int32_t)0;
	m_autochair = (int32_t)0;
	m_isexpscene = (int32_t)0;
	m_expscenegold = (int32_t)0;
	m_tax = (int32_t)0;
	return 0;
}

int E_FishRoom_s::ResumeInit() {
	return 0;
}

void E_FishRoom_s::write_to_pbmsg(::proto_ff::E_FishRoom & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_roomid((int32_t)m_roomid);
	msg.set_m_gameid((int32_t)m_gameid);
	msg.set_m_gamename((const char*)m_gamename.data());
	msg.set_m_roomtype((int32_t)m_roomtype);
	msg.set_m_roomlevel((int32_t)m_roomlevel);
	msg.set_m_roomname((const char*)m_roomname.data());
	msg.set_m_sitenum((int32_t)m_sitenum);
	msg.set_m_deskcount((int32_t)m_deskcount);
	msg.set_m_maxpeople((int32_t)m_maxpeople);
	msg.set_m_entermin((int32_t)m_entermin);
	msg.set_m_entermax((int32_t)m_entermax);
	msg.set_m_autochair((int32_t)m_autochair);
	msg.set_m_isexpscene((int32_t)m_isexpscene);
	msg.set_m_expscenegold((int32_t)m_expscenegold);
	msg.set_m_tax((int32_t)m_tax);
}

void E_FishRoom_s::read_from_pbmsg(const ::proto_ff::E_FishRoom & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FishRoom_s));
	m_id = msg.m_id();
	m_roomid = msg.m_roomid();
	m_gameid = msg.m_gameid();
	m_gamename = msg.m_gamename();
	m_roomtype = msg.m_roomtype();
	m_roomlevel = msg.m_roomlevel();
	m_roomname = msg.m_roomname();
	m_sitenum = msg.m_sitenum();
	m_deskcount = msg.m_deskcount();
	m_maxpeople = msg.m_maxpeople();
	m_entermin = msg.m_entermin();
	m_entermax = msg.m_entermax();
	m_autochair = msg.m_autochair();
	m_isexpscene = msg.m_isexpscene();
	m_expscenegold = msg.m_expscenegold();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FishRoom_s));
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
	m_gameid = (int32_t)0;
	m_roomid = (int32_t)0;
	m_gunid = (int32_t)0;
	return 0;
}

int E_FishGunvalue_s::ResumeInit() {
	return 0;
}

void E_FishGunvalue_s::write_to_pbmsg(::proto_ff::E_FishGunvalue & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_gameid((int32_t)m_gameid);
	msg.set_m_roomid((int32_t)m_roomid);
	msg.set_m_gunid((int32_t)m_gunid);
}

void E_FishGunvalue_s::read_from_pbmsg(const ::proto_ff::E_FishGunvalue & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FishGunvalue_s));
	m_id = msg.m_id();
	m_value = msg.m_value();
	m_gameid = msg.m_gameid();
	m_roomid = msg.m_roomid();
	m_gunid = msg.m_gunid();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FishGunvalue_s));
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
	m_controllevel = (int32_t)0;
	m_controlrate = (int32_t)0;
	return 0;
}

int E_FishCtrllevel_s::ResumeInit() {
	return 0;
}

void E_FishCtrllevel_s::write_to_pbmsg(::proto_ff::E_FishCtrllevel & msg) const {
	msg.set_m_controllevel((int32_t)m_controllevel);
	msg.set_m_controlrate((int32_t)m_controlrate);
}

void E_FishCtrllevel_s::read_from_pbmsg(const ::proto_ff::E_FishCtrllevel & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FishCtrllevel_s));
	m_controllevel = msg.m_controllevel();
	m_controlrate = msg.m_controlrate();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FishCtrllevel_s));
	E_FishCtrllevel_List.resize((int)msg.e_fishctrllevel_list_size() > (int)E_FishCtrllevel_List.max_size() ? E_FishCtrllevel_List.max_size() : msg.e_fishctrllevel_list_size());
	for(int32_t i = 0; i < (int32_t)E_FishCtrllevel_List.size(); ++i) {
		const ::proto_ff::E_FishCtrllevel & temp_e_fishctrllevel_list = msg.e_fishctrllevel_list(i);
		E_FishCtrllevel_List[i].read_from_pbmsg(temp_e_fishctrllevel_list);
	}
}

E_FishConfig_s::E_FishConfig_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FishConfig_s::CreateInit() {
	m_fishid = (int32_t)0;
	m_fishtype = (int32_t)0;
	m_buildfishtype = (int32_t)0;
	m_ratiomin = (int32_t)0;
	m_ratiomax = (int32_t)0;
	m_doubleawardminratio = (int32_t)0;
	m_childfishcount = (int32_t)0;
	m_damageradius = (int32_t)0;
	return 0;
}

int E_FishConfig_s::ResumeInit() {
	return 0;
}

void E_FishConfig_s::write_to_pbmsg(::proto_ff::E_FishConfig & msg) const {
	msg.set_m_fishid((int32_t)m_fishid);
	msg.set_m_fishtype((int32_t)m_fishtype);
	msg.set_m_buildfishtype((int32_t)m_buildfishtype);
	msg.set_m_ratiomin((int32_t)m_ratiomin);
	msg.set_m_ratiomax((int32_t)m_ratiomax);
	msg.set_m_doubleawardminratio((int32_t)m_doubleawardminratio);
	msg.set_m_childfishcount((int32_t)m_childfishcount);
	msg.set_m_damageradius((int32_t)m_damageradius);
	msg.set_m_damagefishids((const char*)m_damagefishids.data());
	for(int32_t i = 0; i < (int32_t)m_childfishids.size(); ++i) {
		msg.add_m_childfishids((const char*)m_childfishids[i].data());
	}
}

void E_FishConfig_s::read_from_pbmsg(const ::proto_ff::E_FishConfig & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FishConfig_s));
	m_fishid = msg.m_fishid();
	m_fishtype = msg.m_fishtype();
	m_buildfishtype = msg.m_buildfishtype();
	m_ratiomin = msg.m_ratiomin();
	m_ratiomax = msg.m_ratiomax();
	m_doubleawardminratio = msg.m_doubleawardminratio();
	m_childfishcount = msg.m_childfishcount();
	m_damageradius = msg.m_damageradius();
	m_damagefishids = msg.m_damagefishids();
	m_childfishids.resize((int)msg.m_childfishids_size() > (int)m_childfishids.max_size() ? m_childfishids.max_size() : msg.m_childfishids_size());
	for(int32_t i = 0; i < (int32_t)m_childfishids.size(); ++i) {
		m_childfishids[i] = msg.m_childfishids(i);
	}
}

Sheet_FishConfig_s::Sheet_FishConfig_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FishConfig_s::CreateInit() {
	return 0;
}

int Sheet_FishConfig_s::ResumeInit() {
	return 0;
}

void Sheet_FishConfig_s::write_to_pbmsg(::proto_ff::Sheet_FishConfig & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FishConfig_List.size(); ++i) {
		::proto_ff::E_FishConfig* temp_e_fishconfig_list = msg.add_e_fishconfig_list();
		E_FishConfig_List[i].write_to_pbmsg(*temp_e_fishconfig_list);
	}
}

void Sheet_FishConfig_s::read_from_pbmsg(const ::proto_ff::Sheet_FishConfig & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FishConfig_s));
	E_FishConfig_List.resize((int)msg.e_fishconfig_list_size() > (int)E_FishConfig_List.max_size() ? E_FishConfig_List.max_size() : msg.e_fishconfig_list_size());
	for(int32_t i = 0; i < (int32_t)E_FishConfig_List.size(); ++i) {
		const ::proto_ff::E_FishConfig & temp_e_fishconfig_list = msg.e_fishconfig_list(i);
		E_FishConfig_List[i].read_from_pbmsg(temp_e_fishconfig_list);
	}
}

}