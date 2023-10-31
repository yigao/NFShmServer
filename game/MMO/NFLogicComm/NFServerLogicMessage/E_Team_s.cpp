#include "E_Team_s.h"

namespace proto_ff_s {

E_TeamTeam_s::E_TeamTeam_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TeamTeam_s::CreateInit() {
	m_TeamObjectID = (int32_t)0;
	m_FObjectNameID = (int32_t)0;
	m_SObjectNameID = (int32_t)0;
	m_duplicateId = (int64_t)0;
	m_activityId = (int64_t)0;
	m_LowLV = (int32_t)0;
	m_UpLV = (int32_t)0;
	m_isAutoMatch = (int32_t)0;
	m_speakChannel = (int32_t)0;
	m_teamnumber = (int32_t)0;
	return 0;
}

int E_TeamTeam_s::ResumeInit() {
	return 0;
}

void E_TeamTeam_s::write_to_pbmsg(::proto_ff::E_TeamTeam & msg) const {
	msg.set_m_teamobjectid((int32_t)m_TeamObjectID);
	msg.set_m_fobjectnameid((int32_t)m_FObjectNameID);
	msg.set_m_sobjectnameid((int32_t)m_SObjectNameID);
	msg.set_m_duplicateid((int64_t)m_duplicateId);
	msg.set_m_activityid((int64_t)m_activityId);
	msg.set_m_lowlv((int32_t)m_LowLV);
	msg.set_m_uplv((int32_t)m_UpLV);
	msg.set_m_isautomatch((int32_t)m_isAutoMatch);
	msg.set_m_speakchannel((int32_t)m_speakChannel);
	msg.set_m_teamnumber((int32_t)m_teamnumber);
}

void E_TeamTeam_s::read_from_pbmsg(const ::proto_ff::E_TeamTeam & msg) {
	m_TeamObjectID = msg.m_teamobjectid();
	m_FObjectNameID = msg.m_fobjectnameid();
	m_SObjectNameID = msg.m_sobjectnameid();
	m_duplicateId = msg.m_duplicateid();
	m_activityId = msg.m_activityid();
	m_LowLV = msg.m_lowlv();
	m_UpLV = msg.m_uplv();
	m_isAutoMatch = msg.m_isautomatch();
	m_speakChannel = msg.m_speakchannel();
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
	E_TeamTeam_List.resize((int)msg.e_teamteam_list_size() > (int)E_TeamTeam_List.max_size() ? E_TeamTeam_List.max_size() : msg.e_teamteam_list_size());
	for(int32_t i = 0; i < (int32_t)E_TeamTeam_List.size(); ++i) {
		const ::proto_ff::E_TeamTeam & temp_e_teamteam_list = msg.e_teamteam_list(i);
		E_TeamTeam_List[i].read_from_pbmsg(temp_e_teamteam_list);
	}
}

}
