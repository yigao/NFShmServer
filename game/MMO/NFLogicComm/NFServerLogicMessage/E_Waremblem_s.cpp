#include "E_Waremblem_s.h"

namespace proto_ff_s {

E_WaremblemWaremblemSkillDesc_s::E_WaremblemWaremblemSkillDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WaremblemWaremblemSkillDesc_s::CreateInit() {
	m_star = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_WaremblemWaremblemSkillDesc_s::ResumeInit() {
	return 0;
}

void E_WaremblemWaremblemSkillDesc_s::write_to_pbmsg(::proto_ff::E_WaremblemWaremblemSkillDesc & msg) const {
	msg.set_m_star((int32_t)m_star);
	msg.set_m_id((int32_t)m_id);
}

void E_WaremblemWaremblemSkillDesc_s::read_from_pbmsg(const ::proto_ff::E_WaremblemWaremblemSkillDesc & msg) {
	m_star = msg.m_star();
	m_id = msg.m_id();
}

E_WaremblemWaremblem_s::E_WaremblemWaremblem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WaremblemWaremblem_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_order = (int32_t)0;
	m_lvIndex = (int32_t)0;
	m_starIndex = (int32_t)0;
	return 0;
}

int E_WaremblemWaremblem_s::ResumeInit() {
	return 0;
}

void E_WaremblemWaremblem_s::write_to_pbmsg(::proto_ff::E_WaremblemWaremblem & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_order((int32_t)m_order);
	msg.set_m_lvindex((int32_t)m_lvIndex);
	msg.set_m_starindex((int32_t)m_starIndex);
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		::proto_ff::E_WaremblemWaremblemSkillDesc* temp_m_skill = msg.add_m_skill();
		m_skill[i].write_to_pbmsg(*temp_m_skill);
	}
}

void E_WaremblemWaremblem_s::read_from_pbmsg(const ::proto_ff::E_WaremblemWaremblem & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_order = msg.m_order();
	m_lvIndex = msg.m_lvindex();
	m_starIndex = msg.m_starindex();
	m_skill.resize((int)msg.m_skill_size() > (int)m_skill.max_size() ? m_skill.max_size() : msg.m_skill_size());
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		const ::proto_ff::E_WaremblemWaremblemSkillDesc & temp_m_skill = msg.m_skill(i);
		m_skill[i].read_from_pbmsg(temp_m_skill);
	}
}

Sheet_WaremblemWaremblem_s::Sheet_WaremblemWaremblem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WaremblemWaremblem_s::CreateInit() {
	return 0;
}

int Sheet_WaremblemWaremblem_s::ResumeInit() {
	return 0;
}

void Sheet_WaremblemWaremblem_s::write_to_pbmsg(::proto_ff::Sheet_WaremblemWaremblem & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WaremblemWaremblem_List.size(); ++i) {
		::proto_ff::E_WaremblemWaremblem* temp_e_waremblemwaremblem_list = msg.add_e_waremblemwaremblem_list();
		E_WaremblemWaremblem_List[i].write_to_pbmsg(*temp_e_waremblemwaremblem_list);
	}
}

void Sheet_WaremblemWaremblem_s::read_from_pbmsg(const ::proto_ff::Sheet_WaremblemWaremblem & msg) {
	E_WaremblemWaremblem_List.resize((int)msg.e_waremblemwaremblem_list_size() > (int)E_WaremblemWaremblem_List.max_size() ? E_WaremblemWaremblem_List.max_size() : msg.e_waremblemwaremblem_list_size());
	for(int32_t i = 0; i < (int32_t)E_WaremblemWaremblem_List.size(); ++i) {
		const ::proto_ff::E_WaremblemWaremblem & temp_e_waremblemwaremblem_list = msg.e_waremblemwaremblem_list(i);
		E_WaremblemWaremblem_List[i].read_from_pbmsg(temp_e_waremblemwaremblem_list);
	}
}

E_WaremblemLvAttributeDesc_s::E_WaremblemLvAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WaremblemLvAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_WaremblemLvAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_WaremblemLvAttributeDesc_s::write_to_pbmsg(::proto_ff::E_WaremblemLvAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_WaremblemLvAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_WaremblemLvAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_WaremblemLv_s::E_WaremblemLv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WaremblemLv_s::CreateInit() {
	m_id = (int32_t)0;
	m_index = (int32_t)0;
	m_lv = (int32_t)0;
	m_classBonus = (int32_t)0;
	m_costId = (int32_t)0;
	m_costNum = (int32_t)0;
	return 0;
}

int E_WaremblemLv_s::ResumeInit() {
	return 0;
}

void E_WaremblemLv_s::write_to_pbmsg(::proto_ff::E_WaremblemLv & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_index((int32_t)m_index);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_classbonus((int32_t)m_classBonus);
	msg.set_m_costid((int32_t)m_costId);
	msg.set_m_costnum((int32_t)m_costNum);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_WaremblemLvAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_WaremblemLv_s::read_from_pbmsg(const ::proto_ff::E_WaremblemLv & msg) {
	m_id = msg.m_id();
	m_index = msg.m_index();
	m_lv = msg.m_lv();
	m_classBonus = msg.m_classbonus();
	m_costId = msg.m_costid();
	m_costNum = msg.m_costnum();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_WaremblemLvAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_WaremblemLv_s::Sheet_WaremblemLv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WaremblemLv_s::CreateInit() {
	return 0;
}

int Sheet_WaremblemLv_s::ResumeInit() {
	return 0;
}

void Sheet_WaremblemLv_s::write_to_pbmsg(::proto_ff::Sheet_WaremblemLv & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WaremblemLv_List.size(); ++i) {
		::proto_ff::E_WaremblemLv* temp_e_waremblemlv_list = msg.add_e_waremblemlv_list();
		E_WaremblemLv_List[i].write_to_pbmsg(*temp_e_waremblemlv_list);
	}
}

void Sheet_WaremblemLv_s::read_from_pbmsg(const ::proto_ff::Sheet_WaremblemLv & msg) {
	E_WaremblemLv_List.resize((int)msg.e_waremblemlv_list_size() > (int)E_WaremblemLv_List.max_size() ? E_WaremblemLv_List.max_size() : msg.e_waremblemlv_list_size());
	for(int32_t i = 0; i < (int32_t)E_WaremblemLv_List.size(); ++i) {
		const ::proto_ff::E_WaremblemLv & temp_e_waremblemlv_list = msg.e_waremblemlv_list(i);
		E_WaremblemLv_List[i].read_from_pbmsg(temp_e_waremblemlv_list);
	}
}

E_WaremblemStarAttributeDesc_s::E_WaremblemStarAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WaremblemStarAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_WaremblemStarAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_WaremblemStarAttributeDesc_s::write_to_pbmsg(::proto_ff::E_WaremblemStarAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_WaremblemStarAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_WaremblemStarAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_WaremblemStar_s::E_WaremblemStar_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WaremblemStar_s::CreateInit() {
	m_id = (int32_t)0;
	m_index = (int32_t)0;
	m_star = (int32_t)0;
	m_costId = (int32_t)0;
	m_costNum = (int32_t)0;
	m_succes = (int32_t)0;
	return 0;
}

int E_WaremblemStar_s::ResumeInit() {
	return 0;
}

void E_WaremblemStar_s::write_to_pbmsg(::proto_ff::E_WaremblemStar & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_index((int32_t)m_index);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_costid((int32_t)m_costId);
	msg.set_m_costnum((int32_t)m_costNum);
	msg.set_m_succes((int32_t)m_succes);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_WaremblemStarAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_WaremblemStar_s::read_from_pbmsg(const ::proto_ff::E_WaremblemStar & msg) {
	m_id = msg.m_id();
	m_index = msg.m_index();
	m_star = msg.m_star();
	m_costId = msg.m_costid();
	m_costNum = msg.m_costnum();
	m_succes = msg.m_succes();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_WaremblemStarAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_WaremblemStar_s::Sheet_WaremblemStar_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WaremblemStar_s::CreateInit() {
	return 0;
}

int Sheet_WaremblemStar_s::ResumeInit() {
	return 0;
}

void Sheet_WaremblemStar_s::write_to_pbmsg(::proto_ff::Sheet_WaremblemStar & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WaremblemStar_List.size(); ++i) {
		::proto_ff::E_WaremblemStar* temp_e_waremblemstar_list = msg.add_e_waremblemstar_list();
		E_WaremblemStar_List[i].write_to_pbmsg(*temp_e_waremblemstar_list);
	}
}

void Sheet_WaremblemStar_s::read_from_pbmsg(const ::proto_ff::Sheet_WaremblemStar & msg) {
	E_WaremblemStar_List.resize((int)msg.e_waremblemstar_list_size() > (int)E_WaremblemStar_List.max_size() ? E_WaremblemStar_List.max_size() : msg.e_waremblemstar_list_size());
	for(int32_t i = 0; i < (int32_t)E_WaremblemStar_List.size(); ++i) {
		const ::proto_ff::E_WaremblemStar & temp_e_waremblemstar_list = msg.e_waremblemstar_list(i);
		E_WaremblemStar_List[i].read_from_pbmsg(temp_e_waremblemstar_list);
	}
}

}
