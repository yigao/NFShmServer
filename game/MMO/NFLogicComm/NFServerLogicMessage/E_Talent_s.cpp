#include "E_Talent_s.h"

namespace proto_ff_s {

E_TalentTalent_s::E_TalentTalent_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TalentTalent_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_skillid = (int32_t)0;
	m_lvlimit = (int32_t)0;
	m_aheadskill = (int32_t)0;
	m_aheadlv = (int32_t)0;
	m_needtype = (int32_t)0;
	m_typenum = (int32_t)0;
	m_cost = (int32_t)0;
	return 0;
}

int E_TalentTalent_s::ResumeInit() {
	return 0;
}

void E_TalentTalent_s::write_to_pbmsg(::proto_ff::E_TalentTalent & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_skillid((int32_t)m_skillid);
	msg.set_m_lvlimit((int32_t)m_lvlimit);
	msg.set_m_aheadskill((int32_t)m_aheadskill);
	msg.set_m_aheadlv((int32_t)m_aheadlv);
	msg.set_m_needtype((int32_t)m_needtype);
	msg.set_m_typenum((int32_t)m_typenum);
	msg.set_m_cost((int32_t)m_cost);
}

void E_TalentTalent_s::read_from_pbmsg(const ::proto_ff::E_TalentTalent & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_skillid = msg.m_skillid();
	m_lvlimit = msg.m_lvlimit();
	m_aheadskill = msg.m_aheadskill();
	m_aheadlv = msg.m_aheadlv();
	m_needtype = msg.m_needtype();
	m_typenum = msg.m_typenum();
	m_cost = msg.m_cost();
}

Sheet_TalentTalent_s::Sheet_TalentTalent_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TalentTalent_s::CreateInit() {
	return 0;
}

int Sheet_TalentTalent_s::ResumeInit() {
	return 0;
}

void Sheet_TalentTalent_s::write_to_pbmsg(::proto_ff::Sheet_TalentTalent & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TalentTalent_List.size(); ++i) {
		::proto_ff::E_TalentTalent* temp_e_talenttalent_list = msg.add_e_talenttalent_list();
		E_TalentTalent_List[i].write_to_pbmsg(*temp_e_talenttalent_list);
	}
}

void Sheet_TalentTalent_s::read_from_pbmsg(const ::proto_ff::Sheet_TalentTalent & msg) {
	E_TalentTalent_List.resize((int)msg.e_talenttalent_list_size() > (int)E_TalentTalent_List.max_size() ? E_TalentTalent_List.max_size() : msg.e_talenttalent_list_size());
	for(int32_t i = 0; i < (int32_t)E_TalentTalent_List.size(); ++i) {
		const ::proto_ff::E_TalentTalent & temp_e_talenttalent_list = msg.e_talenttalent_list(i);
		E_TalentTalent_List[i].read_from_pbmsg(temp_e_talenttalent_list);
	}
}

E_TalentTalenttype_s::E_TalentTalenttype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TalentTalenttype_s::CreateInit() {
	m_type = (int32_t)0;
	return 0;
}

int E_TalentTalenttype_s::ResumeInit() {
	return 0;
}

void E_TalentTalenttype_s::write_to_pbmsg(::proto_ff::E_TalentTalenttype & msg) const {
	msg.set_m_type((int32_t)m_type);
}

void E_TalentTalenttype_s::read_from_pbmsg(const ::proto_ff::E_TalentTalenttype & msg) {
	m_type = msg.m_type();
}

Sheet_TalentTalenttype_s::Sheet_TalentTalenttype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TalentTalenttype_s::CreateInit() {
	return 0;
}

int Sheet_TalentTalenttype_s::ResumeInit() {
	return 0;
}

void Sheet_TalentTalenttype_s::write_to_pbmsg(::proto_ff::Sheet_TalentTalenttype & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TalentTalenttype_List.size(); ++i) {
		::proto_ff::E_TalentTalenttype* temp_e_talenttalenttype_list = msg.add_e_talenttalenttype_list();
		E_TalentTalenttype_List[i].write_to_pbmsg(*temp_e_talenttalenttype_list);
	}
}

void Sheet_TalentTalenttype_s::read_from_pbmsg(const ::proto_ff::Sheet_TalentTalenttype & msg) {
	E_TalentTalenttype_List.resize((int)msg.e_talenttalenttype_list_size() > (int)E_TalentTalenttype_List.max_size() ? E_TalentTalenttype_List.max_size() : msg.e_talenttalenttype_list_size());
	for(int32_t i = 0; i < (int32_t)E_TalentTalenttype_List.size(); ++i) {
		const ::proto_ff::E_TalentTalenttype & temp_e_talenttalenttype_list = msg.e_talenttalenttype_list(i);
		E_TalentTalenttype_List[i].read_from_pbmsg(temp_e_talenttalenttype_list);
	}
}

}
