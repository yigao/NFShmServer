#include "E_Peractivity_s.h"

namespace proto_ff_s {

E_PeractivityPeractivity_s::E_PeractivityPeractivity_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PeractivityPeractivity_s::CreateInit() {
	m_activeId = (int64_t)0;
	m_typeId = (int32_t)0;
	m_functionID = (int32_t)0;
	m_serverdelayTime = (int32_t)0;
	m_serverTime = (int32_t)0;
	m_openingTime = (int32_t)0;
	m_advanceTime = (int32_t)0;
	m_intervalTime = (int32_t)0;
	m_isCross = (int32_t)0;
	m_isFestvial = (int32_t)0;
	return 0;
}

int E_PeractivityPeractivity_s::ResumeInit() {
	return 0;
}

void E_PeractivityPeractivity_s::write_to_pbmsg(::proto_ff::E_PeractivityPeractivity & msg) const {
	msg.set_m_activeid((int64_t)m_activeId);
	msg.set_m_activename(m_activeName.data());
	msg.set_m_typeid((int32_t)m_typeId);
	msg.set_m_functionid((int32_t)m_functionID);
	msg.set_m_opeday(m_opeDay.data());
	msg.set_m_closeday(m_closeDay.data());
	msg.set_m_serverdelaytime((int32_t)m_serverdelayTime);
	msg.set_m_servertime((int32_t)m_serverTime);
	msg.set_m_openingtime((int32_t)m_openingTime);
	msg.set_m_advancetime((int32_t)m_advanceTime);
	msg.set_m_intervaltime((int32_t)m_intervalTime);
	msg.set_m_iscross((int32_t)m_isCross);
	msg.set_m_isfestvial((int32_t)m_isFestvial);
}

void E_PeractivityPeractivity_s::read_from_pbmsg(const ::proto_ff::E_PeractivityPeractivity & msg) {
	m_activeId = msg.m_activeid();
	m_activeName = msg.m_activename();
	m_typeId = msg.m_typeid();
	m_functionID = msg.m_functionid();
	m_opeDay = msg.m_opeday();
	m_closeDay = msg.m_closeday();
	m_serverdelayTime = msg.m_serverdelaytime();
	m_serverTime = msg.m_servertime();
	m_openingTime = msg.m_openingtime();
	m_advanceTime = msg.m_advancetime();
	m_intervalTime = msg.m_intervaltime();
	m_isCross = msg.m_iscross();
	m_isFestvial = msg.m_isfestvial();
}

Sheet_PeractivityPeractivity_s::Sheet_PeractivityPeractivity_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PeractivityPeractivity_s::CreateInit() {
	return 0;
}

int Sheet_PeractivityPeractivity_s::ResumeInit() {
	return 0;
}

void Sheet_PeractivityPeractivity_s::write_to_pbmsg(::proto_ff::Sheet_PeractivityPeractivity & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PeractivityPeractivity_List.size(); ++i) {
		::proto_ff::E_PeractivityPeractivity* temp_e_peractivityperactivity_list = msg.add_e_peractivityperactivity_list();
		E_PeractivityPeractivity_List[i].write_to_pbmsg(*temp_e_peractivityperactivity_list);
	}
}

void Sheet_PeractivityPeractivity_s::read_from_pbmsg(const ::proto_ff::Sheet_PeractivityPeractivity & msg) {
	E_PeractivityPeractivity_List.resize((int)msg.e_peractivityperactivity_list_size() > (int)E_PeractivityPeractivity_List.max_size() ? E_PeractivityPeractivity_List.max_size() : msg.e_peractivityperactivity_list_size());
	for(int32_t i = 0; i < (int32_t)E_PeractivityPeractivity_List.size(); ++i) {
		const ::proto_ff::E_PeractivityPeractivity & temp_e_peractivityperactivity_list = msg.e_peractivityperactivity_list(i);
		E_PeractivityPeractivity_List[i].read_from_pbmsg(temp_e_peractivityperactivity_list);
	}
}

E_PeractivityWeek_s::E_PeractivityWeek_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PeractivityWeek_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_PeractivityWeek_s::ResumeInit() {
	return 0;
}

void E_PeractivityWeek_s::write_to_pbmsg(::proto_ff::E_PeractivityWeek & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_time(m_time.data());
	for(int32_t i = 0; i < (int32_t)m_week.size(); ++i) {
		msg.add_m_week(m_week[i].data());
	}
}

void E_PeractivityWeek_s::read_from_pbmsg(const ::proto_ff::E_PeractivityWeek & msg) {
	m_id = msg.m_id();
	m_time = msg.m_time();
	m_week.resize((int)msg.m_week_size() > (int)m_week.max_size() ? m_week.max_size() : msg.m_week_size());
	for(int32_t i = 0; i < (int32_t)m_week.size(); ++i) {
		m_week[i] = msg.m_week(i);
	}
}

Sheet_PeractivityWeek_s::Sheet_PeractivityWeek_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PeractivityWeek_s::CreateInit() {
	return 0;
}

int Sheet_PeractivityWeek_s::ResumeInit() {
	return 0;
}

void Sheet_PeractivityWeek_s::write_to_pbmsg(::proto_ff::Sheet_PeractivityWeek & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PeractivityWeek_List.size(); ++i) {
		::proto_ff::E_PeractivityWeek* temp_e_peractivityweek_list = msg.add_e_peractivityweek_list();
		E_PeractivityWeek_List[i].write_to_pbmsg(*temp_e_peractivityweek_list);
	}
}

void Sheet_PeractivityWeek_s::read_from_pbmsg(const ::proto_ff::Sheet_PeractivityWeek & msg) {
	E_PeractivityWeek_List.resize((int)msg.e_peractivityweek_list_size() > (int)E_PeractivityWeek_List.max_size() ? E_PeractivityWeek_List.max_size() : msg.e_peractivityweek_list_size());
	for(int32_t i = 0; i < (int32_t)E_PeractivityWeek_List.size(); ++i) {
		const ::proto_ff::E_PeractivityWeek & temp_e_peractivityweek_list = msg.e_peractivityweek_list(i);
		E_PeractivityWeek_List[i].read_from_pbmsg(temp_e_peractivityweek_list);
	}
}

}
