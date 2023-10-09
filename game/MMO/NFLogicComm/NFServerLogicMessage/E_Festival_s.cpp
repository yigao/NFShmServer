#include "E_Festival_s.h"

namespace proto_ff_s {

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
	m_festivalid = (int32_t)0;
	m_timetype = (int32_t)0;
	m_level = (int32_t)0;
	m_viplevel = (int32_t)0;
	m_rechange = (int32_t)0;
	m_severtype = (int32_t)0;
	m_periodtype = (int32_t)0;
	m_period = (int32_t)0;
	m_ifopen = (int32_t)0;
	return 0;
}

int E_FestivalTemplate_s::ResumeInit() {
	return 0;
}

void E_FestivalTemplate_s::write_to_pbmsg(::proto_ff::E_FestivalTemplate & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_festivalid((int32_t)m_festivalid);
	msg.set_m_timetype((int32_t)m_timetype);
	msg.set_m_level((int32_t)m_level);
	msg.set_m_viplevel((int32_t)m_viplevel);
	msg.set_m_rechange((int32_t)m_rechange);
	msg.set_m_severtype((int32_t)m_severtype);
	msg.set_m_typearg(m_typearg.data());
	msg.set_m_periodtype((int32_t)m_periodtype);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_ifopen((int32_t)m_ifopen);
	for(int32_t i = 0; i < (int32_t)m_timearg.size(); ++i) {
		msg.add_m_timearg(m_timearg[i].data());
	}
}

void E_FestivalTemplate_s::read_from_pbmsg(const ::proto_ff::E_FestivalTemplate & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_festivalid = msg.m_festivalid();
	m_timetype = msg.m_timetype();
	m_level = msg.m_level();
	m_viplevel = msg.m_viplevel();
	m_rechange = msg.m_rechange();
	m_severtype = msg.m_severtype();
	m_typearg = msg.m_typearg();
	m_periodtype = msg.m_periodtype();
	m_period = msg.m_period();
	m_ifopen = msg.m_ifopen();
	m_timearg.resize((int)msg.m_timearg_size() > (int)m_timearg.max_size() ? m_timearg.max_size() : msg.m_timearg_size());
	for(int32_t i = 0; i < (int32_t)m_timearg.size(); ++i) {
		m_timearg[i] = msg.m_timearg(i);
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
	m_taskpointid = (int32_t)0;
	m_rankgroup = (int32_t)0;
	m_taskgroup = (int32_t)0;
	m_taskrewardgroup = (int32_t)0;
	return 0;
}

int E_FestivalMuban_love_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_love_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_love & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_taskpointid((int32_t)m_taskpointid);
	msg.set_m_rankgroup((int32_t)m_rankgroup);
	msg.set_m_taskgroup((int32_t)m_taskgroup);
	msg.set_m_taskrewardgroup((int32_t)m_taskrewardgroup);
}

void E_FestivalMuban_love_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_love & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_taskpointid = msg.m_taskpointid();
	m_rankgroup = msg.m_rankgroup();
	m_taskgroup = msg.m_taskgroup();
	m_taskrewardgroup = msg.m_taskrewardgroup();
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
	m_rewardshow = (int32_t)0;
	m_datagroupid = (int32_t)0;
	m_ranktype = (int32_t)0;
	return 0;
}

int E_FestivalMuban_love_rank_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_love_rank_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_love_rank & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_rewardshow((int32_t)m_rewardshow);
	msg.set_m_datagroupid((int32_t)m_datagroupid);
	msg.set_m_ranktype((int32_t)m_ranktype);
}

void E_FestivalMuban_love_rank_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_love_rank & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_rewardshow = msg.m_rewardshow();
	m_datagroupid = msg.m_datagroupid();
	m_ranktype = msg.m_ranktype();
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
	m_groupid = (int32_t)0;
	m_maxrank = (int32_t)0;
	m_minrank = (int32_t)0;
	m_rankvalue = (int32_t)0;
	m_boxid = (int32_t)0;
	return 0;
}

int E_FestivalMuban_love_rank_data_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_love_rank_data_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_love_rank_data & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_maxrank((int32_t)m_maxrank);
	msg.set_m_minrank((int32_t)m_minrank);
	msg.set_m_rankvalue((int32_t)m_rankvalue);
	msg.set_m_boxid((int32_t)m_boxid);
}

void E_FestivalMuban_love_rank_data_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_love_rank_data & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_maxrank = msg.m_maxrank();
	m_minrank = msg.m_minrank();
	m_rankvalue = msg.m_rankvalue();
	m_boxid = msg.m_boxid();
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
	m_groupid = (int32_t)0;
	m_eventtype = (int32_t)0;
	m_reachprice = (int32_t)0;
	m_link = (int32_t)0;
	m_rewardtimes = (int32_t)0;
	m_reward = (int32_t)0;
	return 0;
}

int E_FestivalMuban_love_task_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_love_task_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_love_task & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_eventtype((int32_t)m_eventtype);
	msg.set_m_reachprice((int32_t)m_reachprice);
	msg.set_m_link((int32_t)m_link);
	msg.set_m_rewardtimes((int32_t)m_rewardtimes);
	msg.set_m_reward((int32_t)m_reward);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
}

void E_FestivalMuban_love_task_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_love_task & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_eventtype = msg.m_eventtype();
	m_reachprice = msg.m_reachprice();
	m_link = msg.m_link();
	m_rewardtimes = msg.m_rewardtimes();
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
	m_groupid = (int32_t)0;
	m_value = (int32_t)0;
	m_box = (int32_t)0;
	return 0;
}

int E_FestivalMuban_love_taskreward_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_love_taskreward_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_love_taskreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_box((int32_t)m_box);
}

void E_FestivalMuban_love_taskreward_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_love_taskreward & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
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

E_FestivalPeriodindex_s::E_FestivalPeriodindex_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FestivalPeriodindex_s::CreateInit() {
	m_minorigalday = (int32_t)0;
	return 0;
}

int E_FestivalPeriodindex_s::ResumeInit() {
	return 0;
}

void E_FestivalPeriodindex_s::write_to_pbmsg(::proto_ff::E_FestivalPeriodindex & msg) const {
	msg.set_m_minorigalday((int32_t)m_minorigalday);
	for(int32_t i = 0; i < (int32_t)m_period.size(); ++i) {
		msg.add_m_period((int32_t)m_period[i]);
	}
}

void E_FestivalPeriodindex_s::read_from_pbmsg(const ::proto_ff::E_FestivalPeriodindex & msg) {
	m_minorigalday = msg.m_minorigalday();
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
	m_fristkillreward = (int32_t)0;
	m_killreward = (int32_t)0;
	m_fristkillpacket = (int32_t)0;
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
	msg.set_m_fristkillreward((int32_t)m_fristkillreward);
	msg.set_m_killreward((int32_t)m_killreward);
	msg.set_m_fristkillpacket((int32_t)m_fristkillpacket);
}

void E_FestivalMuban_bossfristkill_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_bossfristkill & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_type = msg.m_type();
	m_bossid = msg.m_bossid();
	m_fristkillreward = msg.m_fristkillreward();
	m_killreward = msg.m_killreward();
	m_fristkillpacket = msg.m_fristkillpacket();
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
	m_openday = (int32_t)0;
	m_closeday = (int32_t)0;
	m_rewardshow = (int32_t)0;
	m_datagroupid = (int32_t)0;
	m_ranktype = (int32_t)0;
	m_giftitemid = (int32_t)0;
	m_originalprice = (int32_t)0;
	m_price = (int32_t)0;
	m_ratioshow = (int32_t)0;
	m_redpointbox = (int32_t)0;
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
	msg.set_m_openday((int32_t)m_openday);
	msg.set_m_closeday((int32_t)m_closeday);
	msg.set_m_championtitle(m_championtitle.data());
	msg.set_m_rewardshow((int32_t)m_rewardshow);
	msg.set_m_datagroupid((int32_t)m_datagroupid);
	msg.set_m_ranktype((int32_t)m_ranktype);
	msg.set_m_rankgift(m_rankgift.data());
	msg.set_m_gifticon(m_gifticon.data());
	msg.set_m_giftitemid((int32_t)m_giftitemid);
	msg.set_m_originalprice((int32_t)m_originalprice);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_ratioshow((int32_t)m_ratioshow);
	msg.set_m_redpointbox((int32_t)m_redpointbox);
}

void E_FestivalMuban_severrank_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_severrank & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_order = msg.m_order();
	m_name = msg.m_name();
	m_openday = msg.m_openday();
	m_closeday = msg.m_closeday();
	m_championtitle = msg.m_championtitle();
	m_rewardshow = msg.m_rewardshow();
	m_datagroupid = msg.m_datagroupid();
	m_ranktype = msg.m_ranktype();
	m_rankgift = msg.m_rankgift();
	m_gifticon = msg.m_gifticon();
	m_giftitemid = msg.m_giftitemid();
	m_originalprice = msg.m_originalprice();
	m_price = msg.m_price();
	m_ratioshow = msg.m_ratioshow();
	m_redpointbox = msg.m_redpointbox();
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
	m_groupid = (int32_t)0;
	m_maxrank = (int32_t)0;
	m_minrank = (int32_t)0;
	m_rankvalue = (int32_t)0;
	m_boxid = (int32_t)0;
	return 0;
}

int E_FestivalMuban_severrank_data_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_severrank_data_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_severrank_data & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_maxrank((int32_t)m_maxrank);
	msg.set_m_minrank((int32_t)m_minrank);
	msg.set_m_rankvalue((int32_t)m_rankvalue);
	msg.set_m_boxid((int32_t)m_boxid);
}

void E_FestivalMuban_severrank_data_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_severrank_data & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_maxrank = msg.m_maxrank();
	m_minrank = msg.m_minrank();
	m_rankvalue = msg.m_rankvalue();
	m_boxid = msg.m_boxid();
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
	m_boxid = (int32_t)0;
	return 0;
}

int E_FestivalMuban_sign_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_sign_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_sign & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_boxid((int32_t)m_boxid);
}

void E_FestivalMuban_sign_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_sign & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_boxid = msg.m_boxid();
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
	m_viplevel = (int32_t)0;
	m_box = (int32_t)0;
	m_timelimit = (int32_t)0;
	m_price = (int32_t)0;
	m_pricetype = (int32_t)0;
	m_startime = (int32_t)0;
	m_durtime = (int32_t)0;
	return 0;
}

int E_FestivalMuban_shop_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_shop_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_shop & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_viplevel((int32_t)m_viplevel);
	msg.set_m_box((int32_t)m_box);
	msg.set_m_timelimit((int32_t)m_timelimit);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_pricetype((int32_t)m_pricetype);
	msg.set_m_startime((int32_t)m_startime);
	msg.set_m_durtime((int32_t)m_durtime);
}

void E_FestivalMuban_shop_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_shop & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_viplevel = msg.m_viplevel();
	m_box = msg.m_box();
	m_timelimit = msg.m_timelimit();
	m_price = msg.m_price();
	m_pricetype = msg.m_pricetype();
	m_startime = msg.m_startime();
	m_durtime = msg.m_durtime();
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
	m_timelimit = (int32_t)0;
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
	msg.set_m_timelimit((int32_t)m_timelimit);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_typer((int32_t)m_typer);
}

void E_FestivalMuban_rechange_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rechange & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_rebate = msg.m_rebate();
	m_timelimit = msg.m_timelimit();
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
	m_boxid = (int32_t)0;
	return 0;
}

int E_FestivalMuban_leiji_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_leiji_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_leiji & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_leiji((int32_t)m_leiji);
	msg.set_m_boxid((int32_t)m_boxid);
}

void E_FestivalMuban_leiji_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_leiji & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_leiji = msg.m_leiji();
	m_boxid = msg.m_boxid();
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
	m_costitem = (int64_t)0;
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
	msg.set_m_costitem((int64_t)m_costitem);
	msg.set_m_number((int32_t)m_number);
	msg.set_m_free((int32_t)m_free);
	msg.set_m_currency((int32_t)m_currency);
}

void E_FestivalZadanconstant_s::read_from_pbmsg(const ::proto_ff::E_FestivalZadanconstant & msg) {
	m_period = msg.m_period();
	m_costitem = msg.m_costitem();
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
	m_poolgroup = (int32_t)0;
	m_taskgroup = (int32_t)0;
	return 0;
}

int E_FestivalMuban_turntable_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_turntable_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_turntable & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_poolgroup((int32_t)m_poolgroup);
	msg.set_m_taskgroup((int32_t)m_taskgroup);
}

void E_FestivalMuban_turntable_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_turntable & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_poolgroup = msg.m_poolgroup();
	m_taskgroup = msg.m_taskgroup();
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
	m_groupid = (int32_t)0;
	m_itemid = (int32_t)0;
	m_num = (int32_t)0;
	m_weight = (int32_t)0;
	return 0;
}

int E_FestivalMuban_turntable_pool_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_turntable_pool_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_turntable_pool & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_weight((int32_t)m_weight);
}

void E_FestivalMuban_turntable_pool_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_turntable_pool & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_itemid = msg.m_itemid();
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
	m_groupid = (int32_t)0;
	m_eventtype = (int32_t)0;
	m_reachprice = (int32_t)0;
	m_link = (int32_t)0;
	m_rewardtimes = (int32_t)0;
	return 0;
}

int E_FestivalMuban_turntable_task_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_turntable_task_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_turntable_task & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_eventtype((int32_t)m_eventtype);
	msg.set_m_reachprice((int32_t)m_reachprice);
	msg.set_m_link((int32_t)m_link);
	msg.set_m_rewardtimes((int32_t)m_rewardtimes);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
}

void E_FestivalMuban_turntable_task_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_turntable_task & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_eventtype = msg.m_eventtype();
	m_reachprice = msg.m_reachprice();
	m_link = msg.m_link();
	m_rewardtimes = msg.m_rewardtimes();
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
	m_donateitem = (int32_t)0;
	m_donatereward = (int32_t)0;
	m_severreward = (int32_t)0;
	m_singlereward = (int32_t)0;
	m_taskgroupid = (int32_t)0;
	return 0;
}

int E_FestivalMuban_donate_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_donate_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_donate & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_donateitem((int32_t)m_donateitem);
	msg.set_m_donatereward((int32_t)m_donatereward);
	msg.set_m_severreward((int32_t)m_severreward);
	msg.set_m_singlereward((int32_t)m_singlereward);
	msg.set_m_taskgroupid((int32_t)m_taskgroupid);
}

void E_FestivalMuban_donate_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_donate & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_donateitem = msg.m_donateitem();
	m_donatereward = msg.m_donatereward();
	m_severreward = msg.m_severreward();
	m_singlereward = msg.m_singlereward();
	m_taskgroupid = msg.m_taskgroupid();
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
	m_groupid = (int32_t)0;
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
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_typearg(m_typearg.data());
	msg.set_m_pro(m_pro.data());
	msg.set_m_num((int32_t)m_num);
}

void E_FestivalMuban_donate_sever_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_donate_sever & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_value = msg.m_value();
	m_type = msg.m_type();
	m_typearg = msg.m_typearg();
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
	m_groupid = (int32_t)0;
	m_value = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_FestivalMuban_donate_single_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_donate_single_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_donate_single & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_itemid(m_itemid.data());
	msg.set_m_pro(m_pro.data());
	msg.set_m_num((int32_t)m_num);
}

void E_FestivalMuban_donate_single_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_donate_single & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_value = msg.m_value();
	m_itemid = msg.m_itemid();
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
	m_groupid = (int32_t)0;
	m_eventtype = (int32_t)0;
	m_reachprice = (int32_t)0;
	m_itemid = (int32_t)0;
	m_itemnum = (int32_t)0;
	return 0;
}

int E_FestivalMuban_donate_task_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_donate_task_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_donate_task & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_eventtype((int32_t)m_eventtype);
	msg.set_m_reachprice((int32_t)m_reachprice);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_itemnum((int32_t)m_itemnum);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
}

void E_FestivalMuban_donate_task_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_donate_task & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_eventtype = msg.m_eventtype();
	m_reachprice = msg.m_reachprice();
	m_itemid = msg.m_itemid();
	m_itemnum = msg.m_itemnum();
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
	m_itemid = (int32_t)0;
	m_itemnum = (int32_t)0;
	m_vip = (int32_t)0;
	return 0;
}

int E_FestivalMuban_online_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_online_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_online & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_timestart(m_timestart.data());
	msg.set_m_timeend(m_timeend.data());
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_itemnum((int32_t)m_itemnum);
	msg.set_m_vip((int32_t)m_vip);
}

void E_FestivalMuban_online_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_online & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_timestart = msg.m_timestart();
	m_timeend = msg.m_timeend();
	m_itemid = msg.m_itemid();
	m_itemnum = msg.m_itemnum();
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
	m_rechargegroupid = (int32_t)0;
	return 0;
}

int E_FestivalMuban_rturntable_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_rturntable_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_rturntable & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_rechargegroupid((int32_t)m_rechargegroupid);
}

void E_FestivalMuban_rturntable_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rturntable & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_rechargegroupid = msg.m_rechargegroupid();
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
	m_groupid = (int32_t)0;
	m_rechargeid = (int32_t)0;
	m_limit = (int32_t)0;
	m_ratiogroupid = (int32_t)0;
	return 0;
}

int E_FestivalMuban_rturntable_recharge_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_rturntable_recharge_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_rturntable_recharge & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_rechargeid((int32_t)m_rechargeid);
	msg.set_m_limit((int32_t)m_limit);
	msg.set_m_ratiogroupid((int32_t)m_ratiogroupid);
}

void E_FestivalMuban_rturntable_recharge_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rturntable_recharge & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_rechargeid = msg.m_rechargeid();
	m_limit = msg.m_limit();
	m_ratiogroupid = msg.m_ratiogroupid();
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
	m_groupid = (int32_t)0;
	m_ratio = (int32_t)0;
	m_weight = (int32_t)0;
	return 0;
}

int E_FestivalMuban_rturntable_recharge_ratio_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_rturntable_recharge_ratio_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_rturntable_recharge_ratio & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_ratio((int32_t)m_ratio);
	msg.set_m_weight((int32_t)m_weight);
}

void E_FestivalMuban_rturntable_recharge_ratio_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_rturntable_recharge_ratio & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
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
	m_costid = (int64_t)0;
	m_poolgroupid = (int32_t)0;
	m_totalgroupid = (int32_t)0;
	m_severlimit = (int32_t)0;
	m_protecttime = (int32_t)0;
	return 0;
}

int E_FestivalMuban_drawpize_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_drawpize_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_drawpize & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_costid((int64_t)m_costid);
	msg.set_m_costnum(m_costnum.data());
	msg.set_m_poolgroupid((int32_t)m_poolgroupid);
	msg.set_m_totalgroupid((int32_t)m_totalgroupid);
	msg.set_m_severlimit((int32_t)m_severlimit);
	msg.set_m_protecttime((int32_t)m_protecttime);
}

void E_FestivalMuban_drawpize_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_drawpize & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_costid = msg.m_costid();
	m_costnum = msg.m_costnum();
	m_poolgroupid = msg.m_poolgroupid();
	m_totalgroupid = msg.m_totalgroupid();
	m_severlimit = msg.m_severlimit();
	m_protecttime = msg.m_protecttime();
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
	m_groupid = (int32_t)0;
	m_itemid = (int64_t)0;
	m_num = (int32_t)0;
	m_prof = (int32_t)0;
	m_weights = (int32_t)0;
	m_proweights = (int32_t)0;
	m_timelimit = (int32_t)0;
	m_record = (int32_t)0;
	return 0;
}

int E_FestivalMuban_drawpize_pool_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_drawpize_pool_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_drawpize_pool & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_itemid((int64_t)m_itemid);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_prof((int32_t)m_prof);
	msg.set_m_weights((int32_t)m_weights);
	msg.set_m_proweights((int32_t)m_proweights);
	msg.set_m_timelimit((int32_t)m_timelimit);
	msg.set_m_record((int32_t)m_record);
}

void E_FestivalMuban_drawpize_pool_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_drawpize_pool & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_itemid = msg.m_itemid();
	m_num = msg.m_num();
	m_prof = msg.m_prof();
	m_weights = msg.m_weights();
	m_proweights = msg.m_proweights();
	m_timelimit = msg.m_timelimit();
	m_record = msg.m_record();
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
	m_itemid = (int32_t)0;
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
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_num((int32_t)m_num);
}

void E_FestivalMuban_drawpize_total_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_drawpize_total & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_value = msg.m_value();
	m_itemid = msg.m_itemid();
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
	m_a = (int32_t)0;
	m_value = (int32_t)0;
	m_boxid = (int32_t)0;
	return 0;
}

int E_FestivalMuban_totalrecharge_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_totalrecharge_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_totalrecharge & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_a((int32_t)m_a);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_boxid((int32_t)m_boxid);
}

void E_FestivalMuban_totalrecharge_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_totalrecharge & msg) {
	m_id = msg.m_id();
	m_a = msg.m_a();
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
	m_rewardgroup = (int32_t)0;
	m_gamegroup = (int32_t)0;
	return 0;
}

int E_FestivalMuban_play_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_play_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_play & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_period((int32_t)m_period);
	msg.set_m_rewardgroup((int32_t)m_rewardgroup);
	msg.set_m_gamegroup((int32_t)m_gamegroup);
	for(int32_t i = 0; i < (int32_t)m_opentime.size(); ++i) {
		msg.add_m_opentime(m_opentime[i].data());
	}
}

void E_FestivalMuban_play_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_play & msg) {
	m_id = msg.m_id();
	m_period = msg.m_period();
	m_rewardgroup = msg.m_rewardgroup();
	m_gamegroup = msg.m_gamegroup();
	m_opentime.resize((int)msg.m_opentime_size() > (int)m_opentime.max_size() ? m_opentime.max_size() : msg.m_opentime_size());
	for(int32_t i = 0; i < (int32_t)m_opentime.size(); ++i) {
		m_opentime[i] = msg.m_opentime(i);
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
	m_groupid = (int32_t)0;
	m_points = (int32_t)0;
	m_boxid = (int32_t)0;
	return 0;
}

int E_FestivalMuban_play_reward_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_play_reward_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_play_reward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_points((int32_t)m_points);
	msg.set_m_boxid((int32_t)m_boxid);
}

void E_FestivalMuban_play_reward_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_play_reward & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_points = msg.m_points();
	m_boxid = msg.m_boxid();
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
	m_groupid = (int32_t)0;
	m_order = (int32_t)0;
	m_playtype = (int32_t)0;
	m_rewardbox = (int32_t)0;
	m_pretime = (int32_t)0;
	return 0;
}

int E_FestivalMuban_play_game_s::ResumeInit() {
	return 0;
}

void E_FestivalMuban_play_game_s::write_to_pbmsg(::proto_ff::E_FestivalMuban_play_game & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_order((int32_t)m_order);
	msg.set_m_playtype((int32_t)m_playtype);
	msg.set_m_arg(m_arg.data());
	msg.set_m_rewardbox((int32_t)m_rewardbox);
	msg.set_m_pretime((int32_t)m_pretime);
	for(int32_t i = 0; i < (int32_t)m_playarg.size(); ++i) {
		msg.add_m_playarg(m_playarg[i].data());
	}
}

void E_FestivalMuban_play_game_s::read_from_pbmsg(const ::proto_ff::E_FestivalMuban_play_game & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_order = msg.m_order();
	m_playtype = msg.m_playtype();
	m_arg = msg.m_arg();
	m_rewardbox = msg.m_rewardbox();
	m_pretime = msg.m_pretime();
	m_playarg.resize((int)msg.m_playarg_size() > (int)m_playarg.max_size() ? m_playarg.max_size() : msg.m_playarg_size());
	for(int32_t i = 0; i < (int32_t)m_playarg.size(); ++i) {
		m_playarg[i] = msg.m_playarg(i);
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
