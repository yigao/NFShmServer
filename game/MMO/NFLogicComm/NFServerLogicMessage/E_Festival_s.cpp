#include "E_Festival_s.h"

namespace proto_ff_s {

E_FestivalPeriodindex_s::E_FestivalPeriodindex_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalPeriodindex_s::CreateInit() {
	m_minOrigalDay = (int32_t)0;
	return 0;
}

int E_FestivalPeriodindex_s::ResumeInit() {
	return 0;
}

void E_FestivalPeriodindex_s::write_to_pbmsg(::proto_ff::E_FestivalPeriodindex & msg) const {
	msg.set_m_minorigalday((int32_t)m_minOrigalDay);
	for(int32_t i = 0; i < (int32_t)m_period.size(); ++i) {
		msg.add_m_period((int32_t)m_period[i]);
	}
}

void E_FestivalPeriodindex_s::read_from_pbmsg(const ::proto_ff::E_FestivalPeriodindex & msg) {
	m_minOrigalDay = msg.m_minorigalday();
	m_period.resize((int)msg.m_period_size() > (int)m_period.max_size() ? m_period.max_size() : msg.m_period_size());
	for(int32_t i = 0; i < (int32_t)m_period.size(); ++i) {
		m_period[i] = msg.m_period(i);
	}
}

Sheet_FestivalPeriodindex_s::Sheet_FestivalPeriodindex_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalPeriodindex_s::CreateInit() {
	return 0;
}

int Sheet_FestivalPeriodindex_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalPeriodindex_s::write_to_pbmsg(::proto_ff::Sheet_FestivalPeriodindex & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalPeriodindex_List.size(); ++i) {
		::proto_ff::E_FestivalPeriodindex* temp_e_festivalperiodindex_list = msg.add_e_festivalperiodindex_list();
		E_FestivalPeriodindex_List[i].write_to_pbmsg(*temp_e_festivalperiodindex_list);
	}
}

void Sheet_FestivalPeriodindex_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalPeriodindex & msg) {
	E_FestivalPeriodindex_List.resize((int)msg.e_festivalperiodindex_list_size() > (int)E_FestivalPeriodindex_List.max_size() ? E_FestivalPeriodindex_List.max_size() : msg.e_festivalperiodindex_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalPeriodindex_List.size(); ++i) {
		const ::proto_ff::E_FestivalPeriodindex & temp_e_festivalperiodindex_list = msg.e_festivalperiodindex_list(i);
		E_FestivalPeriodindex_List[i].read_from_pbmsg(temp_e_festivalperiodindex_list);
	}
}

E_FestivalFestival_s::E_FestivalFestival_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalFestival_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_FestivalFestival_s::ResumeInit() {
	return 0;
}

void E_FestivalFestival_s::write_to_pbmsg(::proto_ff::E_FestivalFestival & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
}

void E_FestivalFestival_s::read_from_pbmsg(const ::proto_ff::E_FestivalFestival & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
}

Sheet_FestivalFestival_s::Sheet_FestivalFestival_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalFestival_s::CreateInit() {
	return 0;
}

int Sheet_FestivalFestival_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalFestival_s::write_to_pbmsg(::proto_ff::Sheet_FestivalFestival & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalFestival_List.size(); ++i) {
		::proto_ff::E_FestivalFestival* temp_e_festivalfestival_list = msg.add_e_festivalfestival_list();
		E_FestivalFestival_List[i].write_to_pbmsg(*temp_e_festivalfestival_list);
	}
}

void Sheet_FestivalFestival_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalFestival & msg) {
	E_FestivalFestival_List.resize((int)msg.e_festivalfestival_list_size() > (int)E_FestivalFestival_List.max_size() ? E_FestivalFestival_List.max_size() : msg.e_festivalfestival_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalFestival_List.size(); ++i) {
		const ::proto_ff::E_FestivalFestival & temp_e_festivalfestival_list = msg.e_festivalfestival_list(i);
		E_FestivalFestival_List[i].read_from_pbmsg(temp_e_festivalfestival_list);
	}
}

E_FestivalTemplate_s::E_FestivalTemplate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalTemplate_s::CreateInit() {
	m_id = (int32_t)0;
	m_festivalId = (int32_t)0;
	m_timeType = (int32_t)0;
	m_level = (int32_t)0;
	m_vipLevel = (int32_t)0;
	m_rechange = (int32_t)0;
	m_severType = (int32_t)0;
	m_periodType = (int32_t)0;
	m_period = (int32_t)0;
	m_ifOpen = (int32_t)0;
	m_activeID = (int32_t)0;
	return 0;
}

int E_FestivalTemplate_s::ResumeInit() {
	return 0;
}

void E_FestivalTemplate_s::write_to_pbmsg(::proto_ff::E_FestivalTemplate & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_festivalid((int32_t)m_festivalId);
	msg.set_m_timetype((int32_t)m_timeType);
	msg.set_m_level((int32_t)m_level);
	msg.set_m_viplevel((int32_t)m_vipLevel);
	msg.set_m_rechange((int32_t)m_rechange);
	msg.set_m_severtype((int32_t)m_severType);
	msg.set_m_typearg(m_typeArg.data());
	msg.set_m_periodtype((int32_t)m_periodType);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_ifopen((int32_t)m_ifOpen);
	msg.set_m_activeid((int32_t)m_activeID);
	for(int32_t i = 0; i < (int32_t)m_timeArg.size(); ++i) {
		msg.add_m_timearg(m_timeArg[i].data());
	}
}

void E_FestivalTemplate_s::read_from_pbmsg(const ::proto_ff::E_FestivalTemplate & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_festivalId = msg.m_festivalid();
	m_timeType = msg.m_timetype();
	m_level = msg.m_level();
	m_vipLevel = msg.m_viplevel();
	m_rechange = msg.m_rechange();
	m_severType = msg.m_severtype();
	m_typeArg = msg.m_typearg();
	m_periodType = msg.m_periodtype();
	m_period = msg.m_period();
	m_ifOpen = msg.m_ifopen();
	m_activeID = msg.m_activeid();
	m_timeArg.resize((int)msg.m_timearg_size() > (int)m_timeArg.max_size() ? m_timeArg.max_size() : msg.m_timearg_size());
	for(int32_t i = 0; i < (int32_t)m_timeArg.size(); ++i) {
		m_timeArg[i] = msg.m_timearg(i);
	}
}

Sheet_FestivalTemplate_s::Sheet_FestivalTemplate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalTemplate_s::CreateInit() {
	return 0;
}

int Sheet_FestivalTemplate_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalTemplate_s::write_to_pbmsg(::proto_ff::Sheet_FestivalTemplate & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalTemplate_List.size(); ++i) {
		::proto_ff::E_FestivalTemplate* temp_e_festivaltemplate_list = msg.add_e_festivaltemplate_list();
		E_FestivalTemplate_List[i].write_to_pbmsg(*temp_e_festivaltemplate_list);
	}
}

void Sheet_FestivalTemplate_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalTemplate & msg) {
	E_FestivalTemplate_List.resize((int)msg.e_festivaltemplate_list_size() > (int)E_FestivalTemplate_List.max_size() ? E_FestivalTemplate_List.max_size() : msg.e_festivaltemplate_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalTemplate_List.size(); ++i) {
		const ::proto_ff::E_FestivalTemplate & temp_e_festivaltemplate_list = msg.e_festivaltemplate_list(i);
		E_FestivalTemplate_List[i].read_from_pbmsg(temp_e_festivaltemplate_list);
	}
}

E_FestivalMuban_login_s::E_FestivalMuban_login_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_login_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_loginDay = (int32_t)0;
	m_boxid = (int32_t)0;
	return 0;
}

int E_FestivalMuban_login_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_login_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_login & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_loginday((int32_t)m_loginDay);
	msg.set_m_boxid((int32_t)m_boxid);
}

void E_FestivalMuban_login_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_login & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_loginDay = msg.m_loginday();
	m_boxid = msg.m_boxid();
}

Sheet_FestivalMuban_login_s::Sheet_FestivalMuban_login_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_login_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_login_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_login_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_login & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_login_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_login* temp_e_festivalmuban_login_list = msg.add_e_festivalmuban_login_list();
		E_FestivalMuban_login_List[i].write_to_pbmsg(*temp_e_festivalmuban_login_list);
	}
}

void Sheet_FestivalMuban_login_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_login & msg) {
	E_FestivalMuban_login_List.resize((int)msg.e_festivalmuban_login_list_size() > (int)E_FestivalMuban_login_List.max_size() ? E_FestivalMuban_login_List.max_size() : msg.e_festivalmuban_login_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_login_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_login & temp_e_festivalmuban_login_list = msg.e_festivalmuban_login_list(i);
		E_FestivalMuban_login_List[i].read_from_pbmsg(temp_e_festivalmuban_login_list);
	}
}

E_FestivalMuban_firstrecharge_s::E_FestivalMuban_firstrecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_firstrecharge_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_day = (int32_t)0;
	m_gear = (int32_t)0;
	m_recharge = (int32_t)0;
	m_boxid = (int32_t)0;
	return 0;
}

int E_FestivalMuban_firstrecharge_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_firstrecharge_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_firstrecharge & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_day((int32_t)m_day);
	msg.set_m_gear((int32_t)m_gear);
	msg.set_m_recharge((int32_t)m_recharge);
	msg.set_m_boxid((int32_t)m_boxid);
}

void E_FestivalMuban_firstrecharge_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_firstrecharge & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_day = msg.m_day();
	m_gear = msg.m_gear();
	m_recharge = msg.m_recharge();
	m_boxid = msg.m_boxid();
}

Sheet_FestivalMuban_firstrecharge_s::Sheet_FestivalMuban_firstrecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_firstrecharge_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_firstrecharge_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_firstrecharge_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_firstrecharge & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_firstrecharge_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_firstrecharge* temp_e_festivalmuban_firstrecharge_list = msg.add_e_festivalmuban_firstrecharge_list();
		E_FestivalMuban_firstrecharge_List[i].write_to_pbmsg(*temp_e_festivalmuban_firstrecharge_list);
	}
}

void Sheet_FestivalMuban_firstrecharge_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_firstrecharge & msg) {
	E_FestivalMuban_firstrecharge_List.resize((int)msg.e_festivalmuban_firstrecharge_list_size() > (int)E_FestivalMuban_firstrecharge_List.max_size() ? E_FestivalMuban_firstrecharge_List.max_size() : msg.e_festivalmuban_firstrecharge_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_firstrecharge_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_firstrecharge & temp_e_festivalmuban_firstrecharge_list = msg.e_festivalmuban_firstrecharge_list(i);
		E_FestivalMuban_firstrecharge_List[i].read_from_pbmsg(temp_e_festivalmuban_firstrecharge_list);
	}
}

E_FestivalMuban_love_s::E_FestivalMuban_love_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_love_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_taskPointID = (int32_t)0;
	m_rankGroup = (int32_t)0;
	m_taskGroup = (int32_t)0;
	m_taskRewardGroup = (int32_t)0;
	return 0;
}

int E_FestivalMuban_love_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_love_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_love & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_taskpointid((int32_t)m_taskPointID);
	msg.set_m_rankgroup((int32_t)m_rankGroup);
	msg.set_m_taskgroup((int32_t)m_taskGroup);
	msg.set_m_taskrewardgroup((int32_t)m_taskRewardGroup);
}

void E_FestivalMuban_love_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_love & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_taskPointID = msg.m_taskpointid();
	m_rankGroup = msg.m_rankgroup();
	m_taskGroup = msg.m_taskgroup();
	m_taskRewardGroup = msg.m_taskrewardgroup();
}

Sheet_FestivalMuban_love_s::Sheet_FestivalMuban_love_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_love_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_love_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_love_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_love & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_love_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_love* temp_e_festivalmuban_love_list = msg.add_e_festivalmuban_love_list();
		E_FestivalMuban_love_List[i].write_to_pbmsg(*temp_e_festivalmuban_love_list);
	}
}

void Sheet_FestivalMuban_love_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_love & msg) {
	E_FestivalMuban_love_List.resize((int)msg.e_festivalmuban_love_list_size() > (int)E_FestivalMuban_love_List.max_size() ? E_FestivalMuban_love_List.max_size() : msg.e_festivalmuban_love_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_love_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_love & temp_e_festivalmuban_love_list = msg.e_festivalmuban_love_list(i);
		E_FestivalMuban_love_List[i].read_from_pbmsg(temp_e_festivalmuban_love_list);
	}
}

E_FestivalMuban_love_rank_s::E_FestivalMuban_love_rank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_love_rank_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupid = (int32_t)0;
	m_rewardShow = (int32_t)0;
	m_dataGroupID = (int32_t)0;
	m_rankType = (int32_t)0;
	return 0;
}

int E_FestivalMuban_love_rank_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_love_rank_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_love_rank & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_rewardshow((int32_t)m_rewardShow);
	msg.set_m_datagroupid((int32_t)m_dataGroupID);
	msg.set_m_ranktype((int32_t)m_rankType);
}

void E_FestivalMuban_love_rank_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_love_rank & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_rewardShow = msg.m_rewardshow();
	m_dataGroupID = msg.m_datagroupid();
	m_rankType = msg.m_ranktype();
}

Sheet_FestivalMuban_love_rank_s::Sheet_FestivalMuban_love_rank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_love_rank_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_love_rank_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_love_rank_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_love_rank & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_love_rank_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_love_rank* temp_e_festivalmuban_love_rank_list = msg.add_e_festivalmuban_love_rank_list();
		E_FestivalMuban_love_rank_List[i].write_to_pbmsg(*temp_e_festivalmuban_love_rank_list);
	}
}

void Sheet_FestivalMuban_love_rank_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_love_rank & msg) {
	E_FestivalMuban_love_rank_List.resize((int)msg.e_festivalmuban_love_rank_list_size() > (int)E_FestivalMuban_love_rank_List.max_size() ? E_FestivalMuban_love_rank_List.max_size() : msg.e_festivalmuban_love_rank_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_love_rank_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_love_rank & temp_e_festivalmuban_love_rank_list = msg.e_festivalmuban_love_rank_list(i);
		E_FestivalMuban_love_rank_List[i].read_from_pbmsg(temp_e_festivalmuban_love_rank_list);
	}
}

E_FestivalMuban_love_rank_data_s::E_FestivalMuban_love_rank_data_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_love_rank_data_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_maxRank = (int32_t)0;
	m_minRank = (int32_t)0;
	m_rankValue = (int32_t)0;
	m_boxID = (int32_t)0;
	return 0;
}

int E_FestivalMuban_love_rank_data_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_love_rank_data_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_love_rank_data & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_maxrank((int32_t)m_maxRank);
	msg.set_m_minrank((int32_t)m_minRank);
	msg.set_m_rankvalue((int32_t)m_rankValue);
	msg.set_m_boxid((int32_t)m_boxID);
}

void E_FestivalMuban_love_rank_data_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_love_rank_data & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_maxRank = msg.m_maxrank();
	m_minRank = msg.m_minrank();
	m_rankValue = msg.m_rankvalue();
	m_boxID = msg.m_boxid();
}

Sheet_FestivalMuban_love_rank_data_s::Sheet_FestivalMuban_love_rank_data_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_love_rank_data_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_love_rank_data_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_love_rank_data_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_love_rank_data & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_love_rank_data_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_love_rank_data* temp_e_festivalmuban_love_rank_data_list = msg.add_e_festivalmuban_love_rank_data_list();
		E_FestivalMuban_love_rank_data_List[i].write_to_pbmsg(*temp_e_festivalmuban_love_rank_data_list);
	}
}

void Sheet_FestivalMuban_love_rank_data_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_love_rank_data & msg) {
	E_FestivalMuban_love_rank_data_List.resize((int)msg.e_festivalmuban_love_rank_data_list_size() > (int)E_FestivalMuban_love_rank_data_List.max_size() ? E_FestivalMuban_love_rank_data_List.max_size() : msg.e_festivalmuban_love_rank_data_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_love_rank_data_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_love_rank_data & temp_e_festivalmuban_love_rank_data_list = msg.e_festivalmuban_love_rank_data_list(i);
		E_FestivalMuban_love_rank_data_List[i].read_from_pbmsg(temp_e_festivalmuban_love_rank_data_list);
	}
}

E_FestivalMuban_love_task_s::E_FestivalMuban_love_task_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_love_task_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_eventType = (int32_t)0;
	m_reachPrice = (int32_t)0;
	m_link = (int32_t)0;
	m_rewardTimes = (int32_t)0;
	m_reward = (int32_t)0;
	return 0;
}

int E_FestivalMuban_love_task_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_love_task_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_love_task & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_eventtype((int32_t)m_eventType);
	msg.set_m_reachprice((int32_t)m_reachPrice);
	msg.set_m_link((int32_t)m_link);
	msg.set_m_rewardtimes((int32_t)m_rewardTimes);
	msg.set_m_reward((int32_t)m_reward);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
}

void E_FestivalMuban_love_task_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_love_task & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_eventType = msg.m_eventtype();
	m_reachPrice = msg.m_reachprice();
	m_link = msg.m_link();
	m_rewardTimes = msg.m_rewardtimes();
	m_reward = msg.m_reward();
	m_param.resize((int)msg.m_param_size() > (int)m_param.max_size() ? m_param.max_size() : msg.m_param_size());
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		m_param[i] = msg.m_param(i);
	}
}

Sheet_FestivalMuban_love_task_s::Sheet_FestivalMuban_love_task_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_love_task_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_love_task_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_love_task_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_love_task & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_love_task_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_love_task* temp_e_festivalmuban_love_task_list = msg.add_e_festivalmuban_love_task_list();
		E_FestivalMuban_love_task_List[i].write_to_pbmsg(*temp_e_festivalmuban_love_task_list);
	}
}

void Sheet_FestivalMuban_love_task_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_love_task & msg) {
	E_FestivalMuban_love_task_List.resize((int)msg.e_festivalmuban_love_task_list_size() > (int)E_FestivalMuban_love_task_List.max_size() ? E_FestivalMuban_love_task_List.max_size() : msg.e_festivalmuban_love_task_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_love_task_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_love_task & temp_e_festivalmuban_love_task_list = msg.e_festivalmuban_love_task_list(i);
		E_FestivalMuban_love_task_List[i].read_from_pbmsg(temp_e_festivalmuban_love_task_list);
	}
}

E_FestivalMuban_love_taskreward_s::E_FestivalMuban_love_taskreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_love_taskreward_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_value = (int32_t)0;
	m_box = (int32_t)0;
	return 0;
}

int E_FestivalMuban_love_taskreward_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_love_taskreward_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_love_taskreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_box((int32_t)m_box);
}

void E_FestivalMuban_love_taskreward_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_love_taskreward & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_value = msg.m_value();
	m_box = msg.m_box();
}

Sheet_FestivalMuban_love_taskreward_s::Sheet_FestivalMuban_love_taskreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_love_taskreward_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_love_taskreward_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_love_taskreward_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_love_taskreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_love_taskreward_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_love_taskreward* temp_e_festivalmuban_love_taskreward_list = msg.add_e_festivalmuban_love_taskreward_list();
		E_FestivalMuban_love_taskreward_List[i].write_to_pbmsg(*temp_e_festivalmuban_love_taskreward_list);
	}
}

void Sheet_FestivalMuban_love_taskreward_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_love_taskreward & msg) {
	E_FestivalMuban_love_taskreward_List.resize((int)msg.e_festivalmuban_love_taskreward_list_size() > (int)E_FestivalMuban_love_taskreward_List.max_size() ? E_FestivalMuban_love_taskreward_List.max_size() : msg.e_festivalmuban_love_taskreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_love_taskreward_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_love_taskreward & temp_e_festivalmuban_love_taskreward_list = msg.e_festivalmuban_love_taskreward_list(i);
		E_FestivalMuban_love_taskreward_List[i].read_from_pbmsg(temp_e_festivalmuban_love_taskreward_list);
	}
}

E_FestivalMuban_addbox_s::E_FestivalMuban_addbox_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_addbox_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_lvLimit = (int32_t)0;
	m_type = (int32_t)0;
	m_addBoxId = (int32_t)0;
	return 0;
}

int E_FestivalMuban_addbox_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_addbox_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_addbox & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_lvlimit((int32_t)m_lvLimit);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_arg(m_arg.data());
	msg.set_m_addboxid((int32_t)m_addBoxId);
}

void E_FestivalMuban_addbox_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_addbox & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_lvLimit = msg.m_lvlimit();
	m_type = msg.m_type();
	m_arg = msg.m_arg();
	m_addBoxId = msg.m_addboxid();
}

Sheet_FestivalMuban_addbox_s::Sheet_FestivalMuban_addbox_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_addbox_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_addbox_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_addbox_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_addbox & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_addbox_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_addbox* temp_e_festivalmuban_addbox_list = msg.add_e_festivalmuban_addbox_list();
		E_FestivalMuban_addbox_List[i].write_to_pbmsg(*temp_e_festivalmuban_addbox_list);
	}
}

void Sheet_FestivalMuban_addbox_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_addbox & msg) {
	E_FestivalMuban_addbox_List.resize((int)msg.e_festivalmuban_addbox_list_size() > (int)E_FestivalMuban_addbox_List.max_size() ? E_FestivalMuban_addbox_List.max_size() : msg.e_festivalmuban_addbox_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_addbox_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_addbox & temp_e_festivalmuban_addbox_list = msg.e_festivalmuban_addbox_list(i);
		E_FestivalMuban_addbox_List[i].read_from_pbmsg(temp_e_festivalmuban_addbox_list);
	}
}

E_FestivalMuban_doublebox_s::E_FestivalMuban_doublebox_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_doublebox_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_type = (int32_t)0;
	m_multiply = (int32_t)0;
	return 0;
}

int E_FestivalMuban_doublebox_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_doublebox_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_doublebox & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_arg(m_arg.data());
	msg.set_m_multiply((int32_t)m_multiply);
}

void E_FestivalMuban_doublebox_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_doublebox & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_type = msg.m_type();
	m_arg = msg.m_arg();
	m_multiply = msg.m_multiply();
}

Sheet_FestivalMuban_doublebox_s::Sheet_FestivalMuban_doublebox_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_doublebox_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_doublebox_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_doublebox_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_doublebox & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_doublebox_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_doublebox* temp_e_festivalmuban_doublebox_list = msg.add_e_festivalmuban_doublebox_list();
		E_FestivalMuban_doublebox_List[i].write_to_pbmsg(*temp_e_festivalmuban_doublebox_list);
	}
}

void Sheet_FestivalMuban_doublebox_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_doublebox & msg) {
	E_FestivalMuban_doublebox_List.resize((int)msg.e_festivalmuban_doublebox_list_size() > (int)E_FestivalMuban_doublebox_List.max_size() ? E_FestivalMuban_doublebox_List.max_size() : msg.e_festivalmuban_doublebox_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_doublebox_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_doublebox & temp_e_festivalmuban_doublebox_list = msg.e_festivalmuban_doublebox_list(i);
		E_FestivalMuban_doublebox_List[i].read_from_pbmsg(temp_e_festivalmuban_doublebox_list);
	}
}

E_FestivalMuban_bossfristkill_s::E_FestivalMuban_bossfristkill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_bossfristkill_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_type = (int32_t)0;
	m_bossid = (int32_t)0;
	m_fristKillReward = (int32_t)0;
	m_killReward = (int32_t)0;
	m_fristKillPacket = (int32_t)0;
	return 0;
}

int E_FestivalMuban_bossfristkill_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_bossfristkill_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_bossfristkill & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_bossid((int32_t)m_bossid);
	msg.set_m_fristkillreward((int32_t)m_fristKillReward);
	msg.set_m_killreward((int32_t)m_killReward);
	msg.set_m_fristkillpacket((int32_t)m_fristKillPacket);
}

void E_FestivalMuban_bossfristkill_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_bossfristkill & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_type = msg.m_type();
	m_bossid = msg.m_bossid();
	m_fristKillReward = msg.m_fristkillreward();
	m_killReward = msg.m_killreward();
	m_fristKillPacket = msg.m_fristkillpacket();
}

Sheet_FestivalMuban_bossfristkill_s::Sheet_FestivalMuban_bossfristkill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_bossfristkill_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_bossfristkill_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_bossfristkill_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_bossfristkill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_bossfristkill_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_bossfristkill* temp_e_festivalmuban_bossfristkill_list = msg.add_e_festivalmuban_bossfristkill_list();
		E_FestivalMuban_bossfristkill_List[i].write_to_pbmsg(*temp_e_festivalmuban_bossfristkill_list);
	}
}

void Sheet_FestivalMuban_bossfristkill_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_bossfristkill & msg) {
	E_FestivalMuban_bossfristkill_List.resize((int)msg.e_festivalmuban_bossfristkill_list_size() > (int)E_FestivalMuban_bossfristkill_List.max_size() ? E_FestivalMuban_bossfristkill_List.max_size() : msg.e_festivalmuban_bossfristkill_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_bossfristkill_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_bossfristkill & temp_e_festivalmuban_bossfristkill_list = msg.e_festivalmuban_bossfristkill_list(i);
		E_FestivalMuban_bossfristkill_List[i].read_from_pbmsg(temp_e_festivalmuban_bossfristkill_list);
	}
}

E_FestivalMuban_severrank_s::E_FestivalMuban_severrank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_severrank_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_openDay = (int32_t)0;
	m_closeDay = (int32_t)0;
	m_rewardShow = (int32_t)0;
	m_dataGroupID = (int32_t)0;
	m_rankType = (int32_t)0;
	m_giftItemId = (int32_t)0;
	m_originalPrice = (int32_t)0;
	m_price = (int32_t)0;
	m_ratioShow = (int32_t)0;
	m_redPointBox = (int32_t)0;
	return 0;
}

int E_FestivalMuban_severrank_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_severrank_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_severrank & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_order(m_order.data());
	msg.set_m_name(m_name.data());
	msg.set_m_openday((int32_t)m_openDay);
	msg.set_m_closeday((int32_t)m_closeDay);
	msg.set_m_championtitle(m_championTitle.data());
	msg.set_m_rewardshow((int32_t)m_rewardShow);
	msg.set_m_datagroupid((int32_t)m_dataGroupID);
	msg.set_m_ranktype((int32_t)m_rankType);
	msg.set_m_rankgift(m_rankGift.data());
	msg.set_m_gifticon(m_giftIcon.data());
	msg.set_m_giftitemid((int32_t)m_giftItemId);
	msg.set_m_originalprice((int32_t)m_originalPrice);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_ratioshow((int32_t)m_ratioShow);
	msg.set_m_redpointbox((int32_t)m_redPointBox);
}

void E_FestivalMuban_severrank_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_severrank & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_order = msg.m_order();
	m_name = msg.m_name();
	m_openDay = msg.m_openday();
	m_closeDay = msg.m_closeday();
	m_championTitle = msg.m_championtitle();
	m_rewardShow = msg.m_rewardshow();
	m_dataGroupID = msg.m_datagroupid();
	m_rankType = msg.m_ranktype();
	m_rankGift = msg.m_rankgift();
	m_giftIcon = msg.m_gifticon();
	m_giftItemId = msg.m_giftitemid();
	m_originalPrice = msg.m_originalprice();
	m_price = msg.m_price();
	m_ratioShow = msg.m_ratioshow();
	m_redPointBox = msg.m_redpointbox();
}

Sheet_FestivalMuban_severrank_s::Sheet_FestivalMuban_severrank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_severrank_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_severrank_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_severrank_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_severrank & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_severrank_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_severrank* temp_e_festivalmuban_severrank_list = msg.add_e_festivalmuban_severrank_list();
		E_FestivalMuban_severrank_List[i].write_to_pbmsg(*temp_e_festivalmuban_severrank_list);
	}
}

void Sheet_FestivalMuban_severrank_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_severrank & msg) {
	E_FestivalMuban_severrank_List.resize((int)msg.e_festivalmuban_severrank_list_size() > (int)E_FestivalMuban_severrank_List.max_size() ? E_FestivalMuban_severrank_List.max_size() : msg.e_festivalmuban_severrank_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_severrank_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_severrank & temp_e_festivalmuban_severrank_list = msg.e_festivalmuban_severrank_list(i);
		E_FestivalMuban_severrank_List[i].read_from_pbmsg(temp_e_festivalmuban_severrank_list);
	}
}

E_FestivalMuban_severrank_data_s::E_FestivalMuban_severrank_data_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_severrank_data_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_maxRank = (int32_t)0;
	m_minRank = (int32_t)0;
	m_rankValue = (int32_t)0;
	m_boxID = (int32_t)0;
	return 0;
}

int E_FestivalMuban_severrank_data_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_severrank_data_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_severrank_data & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_maxrank((int32_t)m_maxRank);
	msg.set_m_minrank((int32_t)m_minRank);
	msg.set_m_rankvalue((int32_t)m_rankValue);
	msg.set_m_unachievedisplay(m_UnachieveDisplay.data());
	msg.set_m_boxid((int32_t)m_boxID);
}

void E_FestivalMuban_severrank_data_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_severrank_data & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_maxRank = msg.m_maxrank();
	m_minRank = msg.m_minrank();
	m_rankValue = msg.m_rankvalue();
	m_UnachieveDisplay = msg.m_unachievedisplay();
	m_boxID = msg.m_boxid();
}

Sheet_FestivalMuban_severrank_data_s::Sheet_FestivalMuban_severrank_data_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_severrank_data_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_severrank_data_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_severrank_data_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_severrank_data & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_severrank_data_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_severrank_data* temp_e_festivalmuban_severrank_data_list = msg.add_e_festivalmuban_severrank_data_list();
		E_FestivalMuban_severrank_data_List[i].write_to_pbmsg(*temp_e_festivalmuban_severrank_data_list);
	}
}

void Sheet_FestivalMuban_severrank_data_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_severrank_data & msg) {
	E_FestivalMuban_severrank_data_List.resize((int)msg.e_festivalmuban_severrank_data_list_size() > (int)E_FestivalMuban_severrank_data_List.max_size() ? E_FestivalMuban_severrank_data_List.max_size() : msg.e_festivalmuban_severrank_data_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_severrank_data_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_severrank_data & temp_e_festivalmuban_severrank_data_list = msg.e_festivalmuban_severrank_data_list(i);
		E_FestivalMuban_severrank_data_List[i].read_from_pbmsg(temp_e_festivalmuban_severrank_data_list);
	}
}

E_FestivalMuban_collectwordCostDesc_s::E_FestivalMuban_collectwordCostDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_collectwordCostDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_FestivalMuban_collectwordCostDesc_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_collectwordCostDesc_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_collectwordCostDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_FestivalMuban_collectwordCostDesc_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_collectwordCostDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_FestivalMuban_collectword_s::E_FestivalMuban_collectword_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_collectword_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_exchange_id = (int32_t)0;
	m_exchange_num = (int32_t)0;
	m_times = (int32_t)0;
	return 0;
}

int E_FestivalMuban_collectword_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_collectword_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_collectword & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_exchange_id((int32_t)m_exchange_id);
	msg.set_m_exchange_num((int32_t)m_exchange_num);
	msg.set_m_times((int32_t)m_times);
	for(int32_t i = 0; i < (int32_t)m_cost.size(); ++i) {
		::proto_ff::E_FestivalMuban_collectwordCostDesc* temp_m_cost = msg.add_m_cost();
		m_cost[i].write_to_pbmsg(*temp_m_cost);
	}
}

void E_FestivalMuban_collectword_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_collectword & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_exchange_id = msg.m_exchange_id();
	m_exchange_num = msg.m_exchange_num();
	m_times = msg.m_times();
	m_cost.resize((int)msg.m_cost_size() > (int)m_cost.max_size() ? m_cost.max_size() : msg.m_cost_size());
	for(int32_t i = 0; i < (int32_t)m_cost.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_collectwordCostDesc & temp_m_cost = msg.m_cost(i);
		m_cost[i].read_from_pbmsg(temp_m_cost);
	}
}

Sheet_FestivalMuban_collectword_s::Sheet_FestivalMuban_collectword_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_collectword_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_collectword_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_collectword_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_collectword & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_collectword_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_collectword* temp_e_festivalmuban_collectword_list = msg.add_e_festivalmuban_collectword_list();
		E_FestivalMuban_collectword_List[i].write_to_pbmsg(*temp_e_festivalmuban_collectword_list);
	}
}

void Sheet_FestivalMuban_collectword_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_collectword & msg) {
	E_FestivalMuban_collectword_List.resize((int)msg.e_festivalmuban_collectword_list_size() > (int)E_FestivalMuban_collectword_List.max_size() ? E_FestivalMuban_collectword_List.max_size() : msg.e_festivalmuban_collectword_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_collectword_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_collectword & temp_e_festivalmuban_collectword_list = msg.e_festivalmuban_collectword_list(i);
		E_FestivalMuban_collectword_List[i].read_from_pbmsg(temp_e_festivalmuban_collectword_list);
	}
}

E_FestivalMuban_sign_s::E_FestivalMuban_sign_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_sign_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_boxID = (int32_t)0;
	return 0;
}

int E_FestivalMuban_sign_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_sign_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_sign & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_boxid((int32_t)m_boxID);
}

void E_FestivalMuban_sign_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_sign & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_boxID = msg.m_boxid();
}

Sheet_FestivalMuban_sign_s::Sheet_FestivalMuban_sign_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_sign_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_sign_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_sign_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_sign & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_sign_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_sign* temp_e_festivalmuban_sign_list = msg.add_e_festivalmuban_sign_list();
		E_FestivalMuban_sign_List[i].write_to_pbmsg(*temp_e_festivalmuban_sign_list);
	}
}

void Sheet_FestivalMuban_sign_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_sign & msg) {
	E_FestivalMuban_sign_List.resize((int)msg.e_festivalmuban_sign_list_size() > (int)E_FestivalMuban_sign_List.max_size() ? E_FestivalMuban_sign_List.max_size() : msg.e_festivalmuban_sign_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_sign_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_sign & temp_e_festivalmuban_sign_list = msg.e_festivalmuban_sign_list(i);
		E_FestivalMuban_sign_List[i].read_from_pbmsg(temp_e_festivalmuban_sign_list);
	}
}

E_FestivalMuban_shop_s::E_FestivalMuban_shop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_shop_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_vipLevel = (int32_t)0;
	m_box = (int32_t)0;
	m_timeLimit = (int32_t)0;
	m_price = (int32_t)0;
	m_priceType = (int32_t)0;
	m_starTime = (int32_t)0;
	m_durTime = (int32_t)0;
	return 0;
}

int E_FestivalMuban_shop_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_shop_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_shop & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_viplevel((int32_t)m_vipLevel);
	msg.set_m_box((int32_t)m_box);
	msg.set_m_timelimit((int32_t)m_timeLimit);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_pricetype((int32_t)m_priceType);
	msg.set_m_startime((int32_t)m_starTime);
	msg.set_m_durtime((int32_t)m_durTime);
}

void E_FestivalMuban_shop_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_shop & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_vipLevel = msg.m_viplevel();
	m_box = msg.m_box();
	m_timeLimit = msg.m_timelimit();
	m_price = msg.m_price();
	m_priceType = msg.m_pricetype();
	m_starTime = msg.m_startime();
	m_durTime = msg.m_durtime();
}

Sheet_FestivalMuban_shop_s::Sheet_FestivalMuban_shop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_shop_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_shop_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_shop_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_shop & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_shop_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_shop* temp_e_festivalmuban_shop_list = msg.add_e_festivalmuban_shop_list();
		E_FestivalMuban_shop_List[i].write_to_pbmsg(*temp_e_festivalmuban_shop_list);
	}
}

void Sheet_FestivalMuban_shop_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_shop & msg) {
	E_FestivalMuban_shop_List.resize((int)msg.e_festivalmuban_shop_list_size() > (int)E_FestivalMuban_shop_List.max_size() ? E_FestivalMuban_shop_List.max_size() : msg.e_festivalmuban_shop_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_shop_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_shop & temp_e_festivalmuban_shop_list = msg.e_festivalmuban_shop_list(i);
		E_FestivalMuban_shop_List[i].read_from_pbmsg(temp_e_festivalmuban_shop_list);
	}
}

E_FestivalMuban_rechange_s::E_FestivalMuban_rechange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_rechange_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_rebate = (int32_t)0;
	m_timeLimit = (int32_t)0;
	m_price = (int32_t)0;
	m_typer = (int32_t)0;
	return 0;
}

int E_FestivalMuban_rechange_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_rechange_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_rechange & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_rebate((int32_t)m_rebate);
	msg.set_m_timelimit((int32_t)m_timeLimit);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_typer((int32_t)m_typer);
}

void E_FestivalMuban_rechange_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rechange & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_rebate = msg.m_rebate();
	m_timeLimit = msg.m_timelimit();
	m_price = msg.m_price();
	m_typer = msg.m_typer();
}

Sheet_FestivalMuban_rechange_s::Sheet_FestivalMuban_rechange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_rechange_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_rechange_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_rechange_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_rechange & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_rechange_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_rechange* temp_e_festivalmuban_rechange_list = msg.add_e_festivalmuban_rechange_list();
		E_FestivalMuban_rechange_List[i].write_to_pbmsg(*temp_e_festivalmuban_rechange_list);
	}
}

void Sheet_FestivalMuban_rechange_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_rechange & msg) {
	E_FestivalMuban_rechange_List.resize((int)msg.e_festivalmuban_rechange_list_size() > (int)E_FestivalMuban_rechange_List.max_size() ? E_FestivalMuban_rechange_List.max_size() : msg.e_festivalmuban_rechange_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_rechange_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_rechange & temp_e_festivalmuban_rechange_list = msg.e_festivalmuban_rechange_list(i);
		E_FestivalMuban_rechange_List[i].read_from_pbmsg(temp_e_festivalmuban_rechange_list);
	}
}

E_FestivalMuban_leiji_s::E_FestivalMuban_leiji_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_leiji_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_leiji = (int32_t)0;
	m_boxID = (int32_t)0;
	return 0;
}

int E_FestivalMuban_leiji_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_leiji_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_leiji & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_leiji((int32_t)m_leiji);
	msg.set_m_boxid((int32_t)m_boxID);
}

void E_FestivalMuban_leiji_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_leiji & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_leiji = msg.m_leiji();
	m_boxID = msg.m_boxid();
}

Sheet_FestivalMuban_leiji_s::Sheet_FestivalMuban_leiji_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_leiji_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_leiji_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_leiji_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_leiji & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_leiji_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_leiji* temp_e_festivalmuban_leiji_list = msg.add_e_festivalmuban_leiji_list();
		E_FestivalMuban_leiji_List[i].write_to_pbmsg(*temp_e_festivalmuban_leiji_list);
	}
}

void Sheet_FestivalMuban_leiji_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_leiji & msg) {
	E_FestivalMuban_leiji_List.resize((int)msg.e_festivalmuban_leiji_list_size() > (int)E_FestivalMuban_leiji_List.max_size() ? E_FestivalMuban_leiji_List.max_size() : msg.e_festivalmuban_leiji_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_leiji_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_leiji & temp_e_festivalmuban_leiji_list = msg.e_festivalmuban_leiji_list(i);
		E_FestivalMuban_leiji_List[i].read_from_pbmsg(temp_e_festivalmuban_leiji_list);
	}
}

E_FestivalMuban_zadan_s::E_FestivalMuban_zadan_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_zadan_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_itemid = (int64_t)0;
	m_num = (int32_t)0;
	m_type = (int32_t)0;
	m_probability = (int32_t)0;
	return 0;
}

int E_FestivalMuban_zadan_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_zadan_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_zadan & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_itemid((int64_t)m_itemid);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_probability((int32_t)m_probability);
}

void E_FestivalMuban_zadan_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_zadan & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_itemid = msg.m_itemid();
	m_num = msg.m_num();
	m_type = msg.m_type();
	m_probability = msg.m_probability();
}

Sheet_FestivalMuban_zadan_s::Sheet_FestivalMuban_zadan_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_zadan_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_zadan_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_zadan_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_zadan & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_zadan_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_zadan* temp_e_festivalmuban_zadan_list = msg.add_e_festivalmuban_zadan_list();
		E_FestivalMuban_zadan_List[i].write_to_pbmsg(*temp_e_festivalmuban_zadan_list);
	}
}

void Sheet_FestivalMuban_zadan_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_zadan & msg) {
	E_FestivalMuban_zadan_List.resize((int)msg.e_festivalmuban_zadan_list_size() > (int)E_FestivalMuban_zadan_List.max_size() ? E_FestivalMuban_zadan_List.max_size() : msg.e_festivalmuban_zadan_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_zadan_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_zadan & temp_e_festivalmuban_zadan_list = msg.e_festivalmuban_zadan_list(i);
		E_FestivalMuban_zadan_List[i].read_from_pbmsg(temp_e_festivalmuban_zadan_list);
	}
}

E_FestivalZadanconstant_s::E_FestivalZadanconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalZadanconstant_s::CreateInit() {
	m_period = (int32_t)0;
	m_costItem = (int64_t)0;
	m_number = (int32_t)0;
	m_free = (int32_t)0;
	m_currency = (int32_t)0;
	return 0;
}

int E_FestivalZadanconstant_s::ResumeInit() {
	return 0;
}

void E_FestivalZadanconstant_s::write_to_pbmsg(::proto_ff::E_FestivalZadanconstant & msg) const {
	msg.set_m_period((int32_t)m_period);
	msg.set_m_costitem((int64_t)m_costItem);
	msg.set_m_number((int32_t)m_number);
	msg.set_m_free((int32_t)m_free);
	msg.set_m_currency((int32_t)m_currency);
}

void E_FestivalZadanconstant_s::read_from_pbmsg(const ::proto_ff::E_FestivalZadanconstant & msg) {
	m_period = msg.m_period();
	m_costItem = msg.m_costitem();
	m_number = msg.m_number();
	m_free = msg.m_free();
	m_currency = msg.m_currency();
}

Sheet_FestivalZadanconstant_s::Sheet_FestivalZadanconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalZadanconstant_s::CreateInit() {
	return 0;
}

int Sheet_FestivalZadanconstant_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalZadanconstant_s::write_to_pbmsg(::proto_ff::Sheet_FestivalZadanconstant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalZadanconstant_List.size(); ++i) {
		::proto_ff::E_FestivalZadanconstant* temp_e_festivalzadanconstant_list = msg.add_e_festivalzadanconstant_list();
		E_FestivalZadanconstant_List[i].write_to_pbmsg(*temp_e_festivalzadanconstant_list);
	}
}

void Sheet_FestivalZadanconstant_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalZadanconstant & msg) {
	E_FestivalZadanconstant_List.resize((int)msg.e_festivalzadanconstant_list_size() > (int)E_FestivalZadanconstant_List.max_size() ? E_FestivalZadanconstant_List.max_size() : msg.e_festivalzadanconstant_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalZadanconstant_List.size(); ++i) {
		const ::proto_ff::E_FestivalZadanconstant & temp_e_festivalzadanconstant_list = msg.e_festivalzadanconstant_list(i);
		E_FestivalZadanconstant_List[i].read_from_pbmsg(temp_e_festivalzadanconstant_list);
	}
}

E_FestivalMuban_turntable_s::E_FestivalMuban_turntable_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_turntable_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_poolGroup = (int32_t)0;
	m_taskGroup = (int32_t)0;
	return 0;
}

int E_FestivalMuban_turntable_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_turntable_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_turntable & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_poolgroup((int32_t)m_poolGroup);
	msg.set_m_taskgroup((int32_t)m_taskGroup);
}

void E_FestivalMuban_turntable_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_turntable & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_poolGroup = msg.m_poolgroup();
	m_taskGroup = msg.m_taskgroup();
}

Sheet_FestivalMuban_turntable_s::Sheet_FestivalMuban_turntable_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_turntable_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_turntable_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_turntable_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_turntable & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_turntable_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_turntable* temp_e_festivalmuban_turntable_list = msg.add_e_festivalmuban_turntable_list();
		E_FestivalMuban_turntable_List[i].write_to_pbmsg(*temp_e_festivalmuban_turntable_list);
	}
}

void Sheet_FestivalMuban_turntable_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_turntable & msg) {
	E_FestivalMuban_turntable_List.resize((int)msg.e_festivalmuban_turntable_list_size() > (int)E_FestivalMuban_turntable_List.max_size() ? E_FestivalMuban_turntable_List.max_size() : msg.e_festivalmuban_turntable_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_turntable_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_turntable & temp_e_festivalmuban_turntable_list = msg.e_festivalmuban_turntable_list(i);
		E_FestivalMuban_turntable_List[i].read_from_pbmsg(temp_e_festivalmuban_turntable_list);
	}
}

E_FestivalMuban_turntable_pool_s::E_FestivalMuban_turntable_pool_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_turntable_pool_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_itemID = (int32_t)0;
	m_num = (int32_t)0;
	m_weight = (int32_t)0;
	return 0;
}

int E_FestivalMuban_turntable_pool_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_turntable_pool_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_turntable_pool & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_weight((int32_t)m_weight);
}

void E_FestivalMuban_turntable_pool_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_turntable_pool & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_itemID = msg.m_itemid();
	m_num = msg.m_num();
	m_weight = msg.m_weight();
}

Sheet_FestivalMuban_turntable_pool_s::Sheet_FestivalMuban_turntable_pool_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_turntable_pool_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_turntable_pool_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_turntable_pool_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_turntable_pool & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_turntable_pool_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_turntable_pool* temp_e_festivalmuban_turntable_pool_list = msg.add_e_festivalmuban_turntable_pool_list();
		E_FestivalMuban_turntable_pool_List[i].write_to_pbmsg(*temp_e_festivalmuban_turntable_pool_list);
	}
}

void Sheet_FestivalMuban_turntable_pool_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_turntable_pool & msg) {
	E_FestivalMuban_turntable_pool_List.resize((int)msg.e_festivalmuban_turntable_pool_list_size() > (int)E_FestivalMuban_turntable_pool_List.max_size() ? E_FestivalMuban_turntable_pool_List.max_size() : msg.e_festivalmuban_turntable_pool_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_turntable_pool_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_turntable_pool & temp_e_festivalmuban_turntable_pool_list = msg.e_festivalmuban_turntable_pool_list(i);
		E_FestivalMuban_turntable_pool_List[i].read_from_pbmsg(temp_e_festivalmuban_turntable_pool_list);
	}
}

E_FestivalMuban_turntable_task_s::E_FestivalMuban_turntable_task_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_turntable_task_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_eventType = (int32_t)0;
	m_reachPrice = (int32_t)0;
	m_link = (int32_t)0;
	m_rewardTimes = (int32_t)0;
	return 0;
}

int E_FestivalMuban_turntable_task_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_turntable_task_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_turntable_task & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_eventtype((int32_t)m_eventType);
	msg.set_m_reachprice((int32_t)m_reachPrice);
	msg.set_m_link((int32_t)m_link);
	msg.set_m_rewardtimes((int32_t)m_rewardTimes);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
}

void E_FestivalMuban_turntable_task_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_turntable_task & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_eventType = msg.m_eventtype();
	m_reachPrice = msg.m_reachprice();
	m_link = msg.m_link();
	m_rewardTimes = msg.m_rewardtimes();
	m_param.resize((int)msg.m_param_size() > (int)m_param.max_size() ? m_param.max_size() : msg.m_param_size());
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		m_param[i] = msg.m_param(i);
	}
}

Sheet_FestivalMuban_turntable_task_s::Sheet_FestivalMuban_turntable_task_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_turntable_task_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_turntable_task_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_turntable_task_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_turntable_task & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_turntable_task_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_turntable_task* temp_e_festivalmuban_turntable_task_list = msg.add_e_festivalmuban_turntable_task_list();
		E_FestivalMuban_turntable_task_List[i].write_to_pbmsg(*temp_e_festivalmuban_turntable_task_list);
	}
}

void Sheet_FestivalMuban_turntable_task_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_turntable_task & msg) {
	E_FestivalMuban_turntable_task_List.resize((int)msg.e_festivalmuban_turntable_task_list_size() > (int)E_FestivalMuban_turntable_task_List.max_size() ? E_FestivalMuban_turntable_task_List.max_size() : msg.e_festivalmuban_turntable_task_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_turntable_task_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_turntable_task & temp_e_festivalmuban_turntable_task_list = msg.e_festivalmuban_turntable_task_list(i);
		E_FestivalMuban_turntable_task_List[i].read_from_pbmsg(temp_e_festivalmuban_turntable_task_list);
	}
}

E_FestivalMuban_donate_s::E_FestivalMuban_donate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_donate_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_donateItem = (int32_t)0;
	m_donateReward = (int32_t)0;
	m_severReward = (int32_t)0;
	m_singleReward = (int32_t)0;
	m_taskGroupID = (int32_t)0;
	return 0;
}

int E_FestivalMuban_donate_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_donate_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_donate & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_donateitem((int32_t)m_donateItem);
	msg.set_m_donatereward((int32_t)m_donateReward);
	msg.set_m_severreward((int32_t)m_severReward);
	msg.set_m_singlereward((int32_t)m_singleReward);
	msg.set_m_taskgroupid((int32_t)m_taskGroupID);
}

void E_FestivalMuban_donate_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_donate & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_donateItem = msg.m_donateitem();
	m_donateReward = msg.m_donatereward();
	m_severReward = msg.m_severreward();
	m_singleReward = msg.m_singlereward();
	m_taskGroupID = msg.m_taskgroupid();
}

Sheet_FestivalMuban_donate_s::Sheet_FestivalMuban_donate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_donate_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_donate_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_donate_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_donate & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_donate_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_donate* temp_e_festivalmuban_donate_list = msg.add_e_festivalmuban_donate_list();
		E_FestivalMuban_donate_List[i].write_to_pbmsg(*temp_e_festivalmuban_donate_list);
	}
}

void Sheet_FestivalMuban_donate_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_donate & msg) {
	E_FestivalMuban_donate_List.resize((int)msg.e_festivalmuban_donate_list_size() > (int)E_FestivalMuban_donate_List.max_size() ? E_FestivalMuban_donate_List.max_size() : msg.e_festivalmuban_donate_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_donate_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_donate & temp_e_festivalmuban_donate_list = msg.e_festivalmuban_donate_list(i);
		E_FestivalMuban_donate_List[i].read_from_pbmsg(temp_e_festivalmuban_donate_list);
	}
}

E_FestivalMuban_donate_sever_s::E_FestivalMuban_donate_sever_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_donate_sever_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_FestivalMuban_donate_sever_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_donate_sever_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_donate_sever & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_typearg(m_typeArg.data());
	msg.set_m_pro(m_pro.data());
	msg.set_m_num((int32_t)m_num);
}

void E_FestivalMuban_donate_sever_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_donate_sever & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_value = msg.m_value();
	m_type = msg.m_type();
	m_typeArg = msg.m_typearg();
	m_pro = msg.m_pro();
	m_num = msg.m_num();
}

Sheet_FestivalMuban_donate_sever_s::Sheet_FestivalMuban_donate_sever_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_donate_sever_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_donate_sever_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_donate_sever_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_donate_sever & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_donate_sever_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_donate_sever* temp_e_festivalmuban_donate_sever_list = msg.add_e_festivalmuban_donate_sever_list();
		E_FestivalMuban_donate_sever_List[i].write_to_pbmsg(*temp_e_festivalmuban_donate_sever_list);
	}
}

void Sheet_FestivalMuban_donate_sever_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_donate_sever & msg) {
	E_FestivalMuban_donate_sever_List.resize((int)msg.e_festivalmuban_donate_sever_list_size() > (int)E_FestivalMuban_donate_sever_List.max_size() ? E_FestivalMuban_donate_sever_List.max_size() : msg.e_festivalmuban_donate_sever_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_donate_sever_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_donate_sever & temp_e_festivalmuban_donate_sever_list = msg.e_festivalmuban_donate_sever_list(i);
		E_FestivalMuban_donate_sever_List[i].read_from_pbmsg(temp_e_festivalmuban_donate_sever_list);
	}
}

E_FestivalMuban_donate_single_s::E_FestivalMuban_donate_single_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_donate_single_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_value = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_FestivalMuban_donate_single_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_donate_single_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_donate_single & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_itemid(m_itemID.data());
	msg.set_m_pro(m_pro.data());
	msg.set_m_num((int32_t)m_num);
}

void E_FestivalMuban_donate_single_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_donate_single & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_value = msg.m_value();
	m_itemID = msg.m_itemid();
	m_pro = msg.m_pro();
	m_num = msg.m_num();
}

Sheet_FestivalMuban_donate_single_s::Sheet_FestivalMuban_donate_single_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_donate_single_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_donate_single_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_donate_single_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_donate_single & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_donate_single_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_donate_single* temp_e_festivalmuban_donate_single_list = msg.add_e_festivalmuban_donate_single_list();
		E_FestivalMuban_donate_single_List[i].write_to_pbmsg(*temp_e_festivalmuban_donate_single_list);
	}
}

void Sheet_FestivalMuban_donate_single_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_donate_single & msg) {
	E_FestivalMuban_donate_single_List.resize((int)msg.e_festivalmuban_donate_single_list_size() > (int)E_FestivalMuban_donate_single_List.max_size() ? E_FestivalMuban_donate_single_List.max_size() : msg.e_festivalmuban_donate_single_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_donate_single_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_donate_single & temp_e_festivalmuban_donate_single_list = msg.e_festivalmuban_donate_single_list(i);
		E_FestivalMuban_donate_single_List[i].read_from_pbmsg(temp_e_festivalmuban_donate_single_list);
	}
}

E_FestivalMuban_donate_task_s::E_FestivalMuban_donate_task_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_donate_task_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_eventType = (int32_t)0;
	m_reachPrice = (int32_t)0;
	m_itemID = (int32_t)0;
	m_itemNum = (int32_t)0;
	return 0;
}

int E_FestivalMuban_donate_task_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_donate_task_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_donate_task & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_eventtype((int32_t)m_eventType);
	msg.set_m_reachprice((int32_t)m_reachPrice);
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_itemnum((int32_t)m_itemNum);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
}

void E_FestivalMuban_donate_task_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_donate_task & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_eventType = msg.m_eventtype();
	m_reachPrice = msg.m_reachprice();
	m_itemID = msg.m_itemid();
	m_itemNum = msg.m_itemnum();
	m_param.resize((int)msg.m_param_size() > (int)m_param.max_size() ? m_param.max_size() : msg.m_param_size());
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		m_param[i] = msg.m_param(i);
	}
}

Sheet_FestivalMuban_donate_task_s::Sheet_FestivalMuban_donate_task_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_donate_task_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_donate_task_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_donate_task_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_donate_task & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_donate_task_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_donate_task* temp_e_festivalmuban_donate_task_list = msg.add_e_festivalmuban_donate_task_list();
		E_FestivalMuban_donate_task_List[i].write_to_pbmsg(*temp_e_festivalmuban_donate_task_list);
	}
}

void Sheet_FestivalMuban_donate_task_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_donate_task & msg) {
	E_FestivalMuban_donate_task_List.resize((int)msg.e_festivalmuban_donate_task_list_size() > (int)E_FestivalMuban_donate_task_List.max_size() ? E_FestivalMuban_donate_task_List.max_size() : msg.e_festivalmuban_donate_task_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_donate_task_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_donate_task & temp_e_festivalmuban_donate_task_list = msg.e_festivalmuban_donate_task_list(i);
		E_FestivalMuban_donate_task_List[i].read_from_pbmsg(temp_e_festivalmuban_donate_task_list);
	}
}

E_FestivalMuban_online_s::E_FestivalMuban_online_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_online_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_itemID = (int32_t)0;
	m_itemNum = (int32_t)0;
	m_vip = (int32_t)0;
	return 0;
}

int E_FestivalMuban_online_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_online_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_online & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_timestart(m_timeStart.data());
	msg.set_m_timeend(m_timeEnd.data());
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_itemnum((int32_t)m_itemNum);
	msg.set_m_vip((int32_t)m_vip);
}

void E_FestivalMuban_online_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_online & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_timeStart = msg.m_timestart();
	m_timeEnd = msg.m_timeend();
	m_itemID = msg.m_itemid();
	m_itemNum = msg.m_itemnum();
	m_vip = msg.m_vip();
}

Sheet_FestivalMuban_online_s::Sheet_FestivalMuban_online_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_online_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_online_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_online_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_online & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_online_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_online* temp_e_festivalmuban_online_list = msg.add_e_festivalmuban_online_list();
		E_FestivalMuban_online_List[i].write_to_pbmsg(*temp_e_festivalmuban_online_list);
	}
}

void Sheet_FestivalMuban_online_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_online & msg) {
	E_FestivalMuban_online_List.resize((int)msg.e_festivalmuban_online_list_size() > (int)E_FestivalMuban_online_List.max_size() ? E_FestivalMuban_online_List.max_size() : msg.e_festivalmuban_online_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_online_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_online & temp_e_festivalmuban_online_list = msg.e_festivalmuban_online_list(i);
		E_FestivalMuban_online_List[i].read_from_pbmsg(temp_e_festivalmuban_online_list);
	}
}

E_FestivalMuban_rturntable_s::E_FestivalMuban_rturntable_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_rturntable_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_rechargeGroupID = (int32_t)0;
	return 0;
}

int E_FestivalMuban_rturntable_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_rturntable_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_rturntable & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_rechargegroupid((int32_t)m_rechargeGroupID);
}

void E_FestivalMuban_rturntable_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rturntable & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_rechargeGroupID = msg.m_rechargegroupid();
}

Sheet_FestivalMuban_rturntable_s::Sheet_FestivalMuban_rturntable_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_rturntable_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_rturntable_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_rturntable_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_rturntable & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_rturntable_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_rturntable* temp_e_festivalmuban_rturntable_list = msg.add_e_festivalmuban_rturntable_list();
		E_FestivalMuban_rturntable_List[i].write_to_pbmsg(*temp_e_festivalmuban_rturntable_list);
	}
}

void Sheet_FestivalMuban_rturntable_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_rturntable & msg) {
	E_FestivalMuban_rturntable_List.resize((int)msg.e_festivalmuban_rturntable_list_size() > (int)E_FestivalMuban_rturntable_List.max_size() ? E_FestivalMuban_rturntable_List.max_size() : msg.e_festivalmuban_rturntable_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_rturntable_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_rturntable & temp_e_festivalmuban_rturntable_list = msg.e_festivalmuban_rturntable_list(i);
		E_FestivalMuban_rturntable_List[i].read_from_pbmsg(temp_e_festivalmuban_rturntable_list);
	}
}

E_FestivalMuban_rturntable_recharge_s::E_FestivalMuban_rturntable_recharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_rturntable_recharge_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_rechargeID = (int32_t)0;
	m_limit = (int32_t)0;
	m_ratioGroupID = (int32_t)0;
	return 0;
}

int E_FestivalMuban_rturntable_recharge_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_rturntable_recharge_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_rturntable_recharge & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_rechargeid((int32_t)m_rechargeID);
	msg.set_m_limit((int32_t)m_limit);
	msg.set_m_ratiogroupid((int32_t)m_ratioGroupID);
}

void E_FestivalMuban_rturntable_recharge_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rturntable_recharge & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_rechargeID = msg.m_rechargeid();
	m_limit = msg.m_limit();
	m_ratioGroupID = msg.m_ratiogroupid();
}

Sheet_FestivalMuban_rturntable_recharge_s::Sheet_FestivalMuban_rturntable_recharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_rturntable_recharge_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_rturntable_recharge_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_rturntable_recharge_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_rturntable_recharge & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_rturntable_recharge_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_rturntable_recharge* temp_e_festivalmuban_rturntable_recharge_list = msg.add_e_festivalmuban_rturntable_recharge_list();
		E_FestivalMuban_rturntable_recharge_List[i].write_to_pbmsg(*temp_e_festivalmuban_rturntable_recharge_list);
	}
}

void Sheet_FestivalMuban_rturntable_recharge_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_rturntable_recharge & msg) {
	E_FestivalMuban_rturntable_recharge_List.resize((int)msg.e_festivalmuban_rturntable_recharge_list_size() > (int)E_FestivalMuban_rturntable_recharge_List.max_size() ? E_FestivalMuban_rturntable_recharge_List.max_size() : msg.e_festivalmuban_rturntable_recharge_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_rturntable_recharge_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_rturntable_recharge & temp_e_festivalmuban_rturntable_recharge_list = msg.e_festivalmuban_rturntable_recharge_list(i);
		E_FestivalMuban_rturntable_recharge_List[i].read_from_pbmsg(temp_e_festivalmuban_rturntable_recharge_list);
	}
}

E_FestivalMuban_rturntable_recharge_ratio_s::E_FestivalMuban_rturntable_recharge_ratio_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_rturntable_recharge_ratio_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_ratio = (int32_t)0;
	m_weight = (int32_t)0;
	return 0;
}

int E_FestivalMuban_rturntable_recharge_ratio_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_rturntable_recharge_ratio_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_rturntable_recharge_ratio & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_ratio((int32_t)m_ratio);
	msg.set_m_weight((int32_t)m_weight);
}

void E_FestivalMuban_rturntable_recharge_ratio_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rturntable_recharge_ratio & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_ratio = msg.m_ratio();
	m_weight = msg.m_weight();
}

Sheet_FestivalMuban_rturntable_recharge_ratio_s::Sheet_FestivalMuban_rturntable_recharge_ratio_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_rturntable_recharge_ratio_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_rturntable_recharge_ratio_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_rturntable_recharge_ratio_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_rturntable_recharge_ratio & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_rturntable_recharge_ratio_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_rturntable_recharge_ratio* temp_e_festivalmuban_rturntable_recharge_ratio_list = msg.add_e_festivalmuban_rturntable_recharge_ratio_list();
		E_FestivalMuban_rturntable_recharge_ratio_List[i].write_to_pbmsg(*temp_e_festivalmuban_rturntable_recharge_ratio_list);
	}
}

void Sheet_FestivalMuban_rturntable_recharge_ratio_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_rturntable_recharge_ratio & msg) {
	E_FestivalMuban_rturntable_recharge_ratio_List.resize((int)msg.e_festivalmuban_rturntable_recharge_ratio_list_size() > (int)E_FestivalMuban_rturntable_recharge_ratio_List.max_size() ? E_FestivalMuban_rturntable_recharge_ratio_List.max_size() : msg.e_festivalmuban_rturntable_recharge_ratio_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_rturntable_recharge_ratio_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_rturntable_recharge_ratio & temp_e_festivalmuban_rturntable_recharge_ratio_list = msg.e_festivalmuban_rturntable_recharge_ratio_list(i);
		E_FestivalMuban_rturntable_recharge_ratio_List[i].read_from_pbmsg(temp_e_festivalmuban_rturntable_recharge_ratio_list);
	}
}

E_FestivalMuban_drawpize_s::E_FestivalMuban_drawpize_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_drawpize_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_costID = (int64_t)0;
	m_poolGroupId = (int32_t)0;
	m_totalGroupID = (int32_t)0;
	m_severLimit = (int32_t)0;
	m_protectTime = (int32_t)0;
	return 0;
}

int E_FestivalMuban_drawpize_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_drawpize_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_drawpize & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_costid((int64_t)m_costID);
	msg.set_m_costnum(m_costNum.data());
	msg.set_m_poolgroupid((int32_t)m_poolGroupId);
	msg.set_m_totalgroupid((int32_t)m_totalGroupID);
	msg.set_m_severlimit((int32_t)m_severLimit);
	msg.set_m_protecttime((int32_t)m_protectTime);
}

void E_FestivalMuban_drawpize_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_drawpize & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_costID = msg.m_costid();
	m_costNum = msg.m_costnum();
	m_poolGroupId = msg.m_poolgroupid();
	m_totalGroupID = msg.m_totalgroupid();
	m_severLimit = msg.m_severlimit();
	m_protectTime = msg.m_protecttime();
}

Sheet_FestivalMuban_drawpize_s::Sheet_FestivalMuban_drawpize_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_drawpize_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_drawpize_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_drawpize_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_drawpize & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_drawpize_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_drawpize* temp_e_festivalmuban_drawpize_list = msg.add_e_festivalmuban_drawpize_list();
		E_FestivalMuban_drawpize_List[i].write_to_pbmsg(*temp_e_festivalmuban_drawpize_list);
	}
}

void Sheet_FestivalMuban_drawpize_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_drawpize & msg) {
	E_FestivalMuban_drawpize_List.resize((int)msg.e_festivalmuban_drawpize_list_size() > (int)E_FestivalMuban_drawpize_List.max_size() ? E_FestivalMuban_drawpize_List.max_size() : msg.e_festivalmuban_drawpize_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_drawpize_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_drawpize & temp_e_festivalmuban_drawpize_list = msg.e_festivalmuban_drawpize_list(i);
		E_FestivalMuban_drawpize_List[i].read_from_pbmsg(temp_e_festivalmuban_drawpize_list);
	}
}

E_FestivalMuban_drawpize_pool_s::E_FestivalMuban_drawpize_pool_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_drawpize_pool_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_itemid = (int64_t)0;
	m_num = (int32_t)0;
	m_prof = (int32_t)0;
	m_weights = (int32_t)0;
	m_proWeights = (int32_t)0;
	m_timeLimit = (int32_t)0;
	m_Record = (int32_t)0;
	return 0;
}

int E_FestivalMuban_drawpize_pool_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_drawpize_pool_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_drawpize_pool & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_itemid((int64_t)m_itemid);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_prof((int32_t)m_prof);
	msg.set_m_weights((int32_t)m_weights);
	msg.set_m_proweights((int32_t)m_proWeights);
	msg.set_m_timelimit((int32_t)m_timeLimit);
	msg.set_m_record((int32_t)m_Record);
}

void E_FestivalMuban_drawpize_pool_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_drawpize_pool & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_itemid = msg.m_itemid();
	m_num = msg.m_num();
	m_prof = msg.m_prof();
	m_weights = msg.m_weights();
	m_proWeights = msg.m_proweights();
	m_timeLimit = msg.m_timelimit();
	m_Record = msg.m_record();
}

Sheet_FestivalMuban_drawpize_pool_s::Sheet_FestivalMuban_drawpize_pool_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_drawpize_pool_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_drawpize_pool_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_drawpize_pool_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_drawpize_pool & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_drawpize_pool_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_drawpize_pool* temp_e_festivalmuban_drawpize_pool_list = msg.add_e_festivalmuban_drawpize_pool_list();
		E_FestivalMuban_drawpize_pool_List[i].write_to_pbmsg(*temp_e_festivalmuban_drawpize_pool_list);
	}
}

void Sheet_FestivalMuban_drawpize_pool_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_drawpize_pool & msg) {
	E_FestivalMuban_drawpize_pool_List.resize((int)msg.e_festivalmuban_drawpize_pool_list_size() > (int)E_FestivalMuban_drawpize_pool_List.max_size() ? E_FestivalMuban_drawpize_pool_List.max_size() : msg.e_festivalmuban_drawpize_pool_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_drawpize_pool_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_drawpize_pool & temp_e_festivalmuban_drawpize_pool_list = msg.e_festivalmuban_drawpize_pool_list(i);
		E_FestivalMuban_drawpize_pool_List[i].read_from_pbmsg(temp_e_festivalmuban_drawpize_pool_list);
	}
}

E_FestivalMuban_drawpize_total_s::E_FestivalMuban_drawpize_total_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_drawpize_total_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupid = (int32_t)0;
	m_value = (int32_t)0;
	m_itemID = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_FestivalMuban_drawpize_total_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_drawpize_total_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_drawpize_total & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_num((int32_t)m_num);
}

void E_FestivalMuban_drawpize_total_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_drawpize_total & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_value = msg.m_value();
	m_itemID = msg.m_itemid();
	m_num = msg.m_num();
}

Sheet_FestivalMuban_drawpize_total_s::Sheet_FestivalMuban_drawpize_total_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_drawpize_total_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_drawpize_total_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_drawpize_total_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_drawpize_total & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_drawpize_total_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_drawpize_total* temp_e_festivalmuban_drawpize_total_list = msg.add_e_festivalmuban_drawpize_total_list();
		E_FestivalMuban_drawpize_total_List[i].write_to_pbmsg(*temp_e_festivalmuban_drawpize_total_list);
	}
}

void Sheet_FestivalMuban_drawpize_total_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_drawpize_total & msg) {
	E_FestivalMuban_drawpize_total_List.resize((int)msg.e_festivalmuban_drawpize_total_list_size() > (int)E_FestivalMuban_drawpize_total_List.max_size() ? E_FestivalMuban_drawpize_total_List.max_size() : msg.e_festivalmuban_drawpize_total_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_drawpize_total_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_drawpize_total & temp_e_festivalmuban_drawpize_total_list = msg.e_festivalmuban_drawpize_total_list(i);
		E_FestivalMuban_drawpize_total_List[i].read_from_pbmsg(temp_e_festivalmuban_drawpize_total_list);
	}
}

E_FestivalMuban_totalrecharge_s::E_FestivalMuban_totalrecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_totalrecharge_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_value = (int32_t)0;
	m_boxid = (int32_t)0;
	return 0;
}

int E_FestivalMuban_totalrecharge_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_totalrecharge_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_totalrecharge & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_boxid((int32_t)m_boxid);
}

void E_FestivalMuban_totalrecharge_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_totalrecharge & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_value = msg.m_value();
	m_boxid = msg.m_boxid();
}

Sheet_FestivalMuban_totalrecharge_s::Sheet_FestivalMuban_totalrecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_totalrecharge_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_totalrecharge_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_totalrecharge_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_totalrecharge & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_totalrecharge_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_totalrecharge* temp_e_festivalmuban_totalrecharge_list = msg.add_e_festivalmuban_totalrecharge_list();
		E_FestivalMuban_totalrecharge_List[i].write_to_pbmsg(*temp_e_festivalmuban_totalrecharge_list);
	}
}

void Sheet_FestivalMuban_totalrecharge_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_totalrecharge & msg) {
	E_FestivalMuban_totalrecharge_List.resize((int)msg.e_festivalmuban_totalrecharge_list_size() > (int)E_FestivalMuban_totalrecharge_List.max_size() ? E_FestivalMuban_totalrecharge_List.max_size() : msg.e_festivalmuban_totalrecharge_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_totalrecharge_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_totalrecharge & temp_e_festivalmuban_totalrecharge_list = msg.e_festivalmuban_totalrecharge_list(i);
		E_FestivalMuban_totalrecharge_List[i].read_from_pbmsg(temp_e_festivalmuban_totalrecharge_list);
	}
}

E_FestivalMuban_dailytotalrecharge_s::E_FestivalMuban_dailytotalrecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_dailytotalrecharge_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_value = (int32_t)0;
	m_boxid = (int32_t)0;
	return 0;
}

int E_FestivalMuban_dailytotalrecharge_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_dailytotalrecharge_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_dailytotalrecharge & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_boxid((int32_t)m_boxid);
}

void E_FestivalMuban_dailytotalrecharge_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_dailytotalrecharge & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_value = msg.m_value();
	m_boxid = msg.m_boxid();
}

Sheet_FestivalMuban_dailytotalrecharge_s::Sheet_FestivalMuban_dailytotalrecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_dailytotalrecharge_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_dailytotalrecharge_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_dailytotalrecharge_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_dailytotalrecharge & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_dailytotalrecharge_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_dailytotalrecharge* temp_e_festivalmuban_dailytotalrecharge_list = msg.add_e_festivalmuban_dailytotalrecharge_list();
		E_FestivalMuban_dailytotalrecharge_List[i].write_to_pbmsg(*temp_e_festivalmuban_dailytotalrecharge_list);
	}
}

void Sheet_FestivalMuban_dailytotalrecharge_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_dailytotalrecharge & msg) {
	E_FestivalMuban_dailytotalrecharge_List.resize((int)msg.e_festivalmuban_dailytotalrecharge_list_size() > (int)E_FestivalMuban_dailytotalrecharge_List.max_size() ? E_FestivalMuban_dailytotalrecharge_List.max_size() : msg.e_festivalmuban_dailytotalrecharge_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_dailytotalrecharge_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_dailytotalrecharge & temp_e_festivalmuban_dailytotalrecharge_list = msg.e_festivalmuban_dailytotalrecharge_list(i);
		E_FestivalMuban_dailytotalrecharge_List[i].read_from_pbmsg(temp_e_festivalmuban_dailytotalrecharge_list);
	}
}

E_FestivalMuban_play_s::E_FestivalMuban_play_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_play_s::CreateInit() {
	m_id = (int32_t)0;
	m_period = (int32_t)0;
	m_rewardGroup = (int32_t)0;
	m_gameGroup = (int32_t)0;
	return 0;
}

int E_FestivalMuban_play_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_play_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_play & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_rewardgroup((int32_t)m_rewardGroup);
	msg.set_m_gamegroup((int32_t)m_gameGroup);
	for(int32_t i = 0; i < (int32_t)m_openTime.size(); ++i) {
		msg.add_m_opentime(m_openTime[i].data());
	}
}

void E_FestivalMuban_play_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_play & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_rewardGroup = msg.m_rewardgroup();
	m_gameGroup = msg.m_gamegroup();
	m_openTime.resize((int)msg.m_opentime_size() > (int)m_openTime.max_size() ? m_openTime.max_size() : msg.m_opentime_size());
	for(int32_t i = 0; i < (int32_t)m_openTime.size(); ++i) {
		m_openTime[i] = msg.m_opentime(i);
	}
}

Sheet_FestivalMuban_play_s::Sheet_FestivalMuban_play_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_play_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_play_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_play_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_play & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_play_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_play* temp_e_festivalmuban_play_list = msg.add_e_festivalmuban_play_list();
		E_FestivalMuban_play_List[i].write_to_pbmsg(*temp_e_festivalmuban_play_list);
	}
}

void Sheet_FestivalMuban_play_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_play & msg) {
	E_FestivalMuban_play_List.resize((int)msg.e_festivalmuban_play_list_size() > (int)E_FestivalMuban_play_List.max_size() ? E_FestivalMuban_play_List.max_size() : msg.e_festivalmuban_play_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_play_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_play & temp_e_festivalmuban_play_list = msg.e_festivalmuban_play_list(i);
		E_FestivalMuban_play_List[i].read_from_pbmsg(temp_e_festivalmuban_play_list);
	}
}

E_FestivalMuban_play_reward_s::E_FestivalMuban_play_reward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_play_reward_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_points = (int32_t)0;
	m_boxID = (int32_t)0;
	return 0;
}

int E_FestivalMuban_play_reward_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_play_reward_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_play_reward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_points((int32_t)m_points);
	msg.set_m_boxid((int32_t)m_boxID);
}

void E_FestivalMuban_play_reward_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_play_reward & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_points = msg.m_points();
	m_boxID = msg.m_boxid();
}

Sheet_FestivalMuban_play_reward_s::Sheet_FestivalMuban_play_reward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_play_reward_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_play_reward_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_play_reward_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_play_reward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_play_reward_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_play_reward* temp_e_festivalmuban_play_reward_list = msg.add_e_festivalmuban_play_reward_list();
		E_FestivalMuban_play_reward_List[i].write_to_pbmsg(*temp_e_festivalmuban_play_reward_list);
	}
}

void Sheet_FestivalMuban_play_reward_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_play_reward & msg) {
	E_FestivalMuban_play_reward_List.resize((int)msg.e_festivalmuban_play_reward_list_size() > (int)E_FestivalMuban_play_reward_List.max_size() ? E_FestivalMuban_play_reward_List.max_size() : msg.e_festivalmuban_play_reward_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_play_reward_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_play_reward & temp_e_festivalmuban_play_reward_list = msg.e_festivalmuban_play_reward_list(i);
		E_FestivalMuban_play_reward_List[i].read_from_pbmsg(temp_e_festivalmuban_play_reward_list);
	}
}

E_FestivalMuban_play_game_s::E_FestivalMuban_play_game_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_play_game_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_order = (int32_t)0;
	m_playType = (int32_t)0;
	m_rewardBox = (int32_t)0;
	m_preTime = (int32_t)0;
	return 0;
}

int E_FestivalMuban_play_game_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_play_game_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_play_game & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_order((int32_t)m_order);
	msg.set_m_playtype((int32_t)m_playType);
	msg.set_m_arg(m_arg.data());
	msg.set_m_rewardbox((int32_t)m_rewardBox);
	msg.set_m_pretime((int32_t)m_preTime);
	for(int32_t i = 0; i < (int32_t)m_playArg.size(); ++i) {
		msg.add_m_playarg(m_playArg[i].data());
	}
}

void E_FestivalMuban_play_game_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_play_game & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_order = msg.m_order();
	m_playType = msg.m_playtype();
	m_arg = msg.m_arg();
	m_rewardBox = msg.m_rewardbox();
	m_preTime = msg.m_pretime();
	m_playArg.resize((int)msg.m_playarg_size() > (int)m_playArg.max_size() ? m_playArg.max_size() : msg.m_playarg_size());
	for(int32_t i = 0; i < (int32_t)m_playArg.size(); ++i) {
		m_playArg[i] = msg.m_playarg(i);
	}
}

Sheet_FestivalMuban_play_game_s::Sheet_FestivalMuban_play_game_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_play_game_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_play_game_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_play_game_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_play_game & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_play_game_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_play_game* temp_e_festivalmuban_play_game_list = msg.add_e_festivalmuban_play_game_list();
		E_FestivalMuban_play_game_List[i].write_to_pbmsg(*temp_e_festivalmuban_play_game_list);
	}
}

void Sheet_FestivalMuban_play_game_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_play_game & msg) {
	E_FestivalMuban_play_game_List.resize((int)msg.e_festivalmuban_play_game_list_size() > (int)E_FestivalMuban_play_game_List.max_size() ? E_FestivalMuban_play_game_List.max_size() : msg.e_festivalmuban_play_game_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_play_game_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_play_game & temp_e_festivalmuban_play_game_list = msg.e_festivalmuban_play_game_list(i);
		E_FestivalMuban_play_game_List[i].read_from_pbmsg(temp_e_festivalmuban_play_game_list);
	}
}

E_FestivalMuban_play_score_s::E_FestivalMuban_play_score_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalMuban_play_score_s::CreateInit() {
	m_id = (int32_t)0;
	m_score = (int32_t)0;
	m_point = (int32_t)0;
	return 0;
}

int E_FestivalMuban_play_score_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_play_score_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_play_score & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_score((int32_t)m_score);
	msg.set_m_image(m_image.data());
	msg.set_m_point((int32_t)m_point);
}

void E_FestivalMuban_play_score_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_play_score & msg) {
	m_id = msg.m_id();
	m_score = msg.m_score();
	m_image = msg.m_image();
	m_point = msg.m_point();
}

Sheet_FestivalMuban_play_score_s::Sheet_FestivalMuban_play_score_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FestivalMuban_play_score_s::CreateInit() {
	return 0;
}

int Sheet_FestivalMuban_play_score_s::ResumeInit() {
	return 0;
}

void Sheet_FestivalMuban_play_score_s::write_to_pbmsg(::proto_ff::Sheet_FestivalMuban_play_score & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_play_score_List.size(); ++i) {
		::proto_ff::E_FestivalMuban_play_score* temp_e_festivalmuban_play_score_list = msg.add_e_festivalmuban_play_score_list();
		E_FestivalMuban_play_score_List[i].write_to_pbmsg(*temp_e_festivalmuban_play_score_list);
	}
}

void Sheet_FestivalMuban_play_score_s::read_from_pbmsg(const ::proto_ff::Sheet_FestivalMuban_play_score & msg) {
	E_FestivalMuban_play_score_List.resize((int)msg.e_festivalmuban_play_score_list_size() > (int)E_FestivalMuban_play_score_List.max_size() ? E_FestivalMuban_play_score_List.max_size() : msg.e_festivalmuban_play_score_list_size());
	for(int32_t i = 0; i < (int32_t)E_FestivalMuban_play_score_List.size(); ++i) {
		const ::proto_ff::E_FestivalMuban_play_score & temp_e_festivalmuban_play_score_list = msg.e_festivalmuban_play_score_list(i);
		E_FestivalMuban_play_score_List[i].read_from_pbmsg(temp_e_festivalmuban_play_score_list);
	}
}

}
