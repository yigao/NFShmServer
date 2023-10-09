#include "team_s.h"

namespace proto_ff_s {

E_TeamTeam_s::E_TeamTeam_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TeamTeam_s::CreateInit() {
	m_teamobjectid = (int32_t)0;
	m_fobjectnameid = (int32_t)0;
	m_sobjectnameid = (int32_t)0;
	m_duplicateid = (int64_t)0;
	m_activityid = (int64_t)0;
	m_lowlv = (int32_t)0;
	m_uplv = (int32_t)0;
	m_isautomatch = (int32_t)0;
	m_speakchannel = (int32_t)0;
	m_teamnumber = (int32_t)0;
	return 0;
}

int E_TeamTeam_s::ResumeInit() {
	return 0;
}

void E_TeamTeam_s::write_to_pbmsg(::proto_ff::E_TeamTeam & msg) const {
	msg.set_m_teamobjectid((int32_t)m_teamobjectid);
	msg.set_m_fobjectnameid((int32_t)m_fobjectnameid);
	msg.set_m_sobjectnameid((int32_t)m_sobjectnameid);
	msg.set_m_duplicateid((int64_t)m_duplicateid);
	msg.set_m_activityid((int64_t)m_activityid);
	msg.set_m_lowlv((int32_t)m_lowlv);
	msg.set_m_uplv((int32_t)m_uplv);
	msg.set_m_isautomatch((int32_t)m_isautomatch);
	msg.set_m_speakchannel((int32_t)m_speakchannel);
	msg.set_m_teamnumber((int32_t)m_teamnumber);
}

void E_TeamTeam_s::read_from_pbmsg(const ::proto_ff::E_TeamTeam & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_TeamTeam_s));
	m_teamobjectid = msg.m_teamobjectid();
	m_fobjectnameid = msg.m_fobjectnameid();
	m_sobjectnameid = msg.m_sobjectnameid();
	m_duplicateid = msg.m_duplicateid();
	m_activityid = msg.m_activityid();
	m_lowlv = msg.m_lowlv();
	m_uplv = msg.m_uplv();
	m_isautomatch = msg.m_isautomatch();
	m_speakchannel = msg.m_speakchannel();
	m_teamnumber = msg.m_teamnumber();
}

Sheet_TeamTeam_s::Sheet_TeamTeam_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TeamTeam_s::CreateInit() {
	return 0;
}

int Sheet_TeamTeam_s::ResumeInit() {
	return 0;
}

void Sheet_TeamTeam_s::write_to_pbmsg(::proto_ff::Sheet_TeamTeam & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TeamTeam_List.size(); ++i) {
		::proto_ff::E_TeamTeam* temp_e_teamteam_list = msg.add_e_teamteam_list();
		E_TeamTeam_List[i].write_to_pbmsg(*temp_e_teamteam_list);
	}
}

void Sheet_TeamTeam_s::read_from_pbmsg(const ::proto_ff::Sheet_TeamTeam & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_TeamTeam_s));
	E_TeamTeam_List.resize((int)msg.e_teamteam_list_size() > (int)E_TeamTeam_List.max_size() ? E_TeamTeam_List.max_size() : msg.e_teamteam_list_size());
	for(int32_t i = 0; i < (int32_t)E_TeamTeam_List.size(); ++i) {
		const ::proto_ff::E_TeamTeam & temp_e_teamteam_list = msg.e_teamteam_list(i);
		E_TeamTeam_List[i].read_from_pbmsg(temp_e_teamteam_list);
	}
}

}