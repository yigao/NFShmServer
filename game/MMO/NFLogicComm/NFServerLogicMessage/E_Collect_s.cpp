#include "E_Collect_s.h"

namespace proto_ff_s {

E_CollectCollectAttributDesc_s::E_CollectCollectAttributDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CollectCollectAttributDesc_s::CreateInit() {
	m_ID = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_CollectCollectAttributDesc_s::ResumeInit() {
	return 0;
}

void E_CollectCollectAttributDesc_s::write_to_pbmsg(::proto_ff::E_CollectCollectAttributDesc & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_num((int32_t)m_num);
}

void E_CollectCollectAttributDesc_s::read_from_pbmsg(const ::proto_ff::E_CollectCollectAttributDesc & msg) {
	m_ID = msg.m_id();
	m_num = msg.m_num();
}

E_CollectCollect_s::E_CollectCollect_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CollectCollect_s::CreateInit() {
	m_id = (int32_t)0;
	m_lv = (int32_t)0;
	m_group = (int32_t)0;
	m_grade = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	m_skillID = (int32_t)0;
	return 0;
}

int E_CollectCollect_s::ResumeInit() {
	return 0;
}

void E_CollectCollect_s::write_to_pbmsg(::proto_ff::E_CollectCollect & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_stagetitle(m_stageTitle.data());
	msg.set_m_position(m_position.data());
	msg.set_m_grade((int32_t)m_grade);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_skillid((int32_t)m_skillID);
	for(int32_t i = 0; i < (int32_t)m_attribut.size(); ++i) {
		::proto_ff::E_CollectCollectAttributDesc* temp_m_attribut = msg.add_m_attribut();
		m_attribut[i].write_to_pbmsg(*temp_m_attribut);
	}
}

void E_CollectCollect_s::read_from_pbmsg(const ::proto_ff::E_CollectCollect & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_lv = msg.m_lv();
	m_group = msg.m_group();
	m_stageTitle = msg.m_stagetitle();
	m_position = msg.m_position();
	m_grade = msg.m_grade();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_skillID = msg.m_skillid();
	m_attribut.resize((int)msg.m_attribut_size() > (int)m_attribut.max_size() ? m_attribut.max_size() : msg.m_attribut_size());
	for(int32_t i = 0; i < (int32_t)m_attribut.size(); ++i) {
		const ::proto_ff::E_CollectCollectAttributDesc & temp_m_attribut = msg.m_attribut(i);
		m_attribut[i].read_from_pbmsg(temp_m_attribut);
	}
}

Sheet_CollectCollect_s::Sheet_CollectCollect_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CollectCollect_s::CreateInit() {
	return 0;
}

int Sheet_CollectCollect_s::ResumeInit() {
	return 0;
}

void Sheet_CollectCollect_s::write_to_pbmsg(::proto_ff::Sheet_CollectCollect & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CollectCollect_List.size(); ++i) {
		::proto_ff::E_CollectCollect* temp_e_collectcollect_list = msg.add_e_collectcollect_list();
		E_CollectCollect_List[i].write_to_pbmsg(*temp_e_collectcollect_list);
	}
}

void Sheet_CollectCollect_s::read_from_pbmsg(const ::proto_ff::Sheet_CollectCollect & msg) {
	E_CollectCollect_List.resize((int)msg.e_collectcollect_list_size() > (int)E_CollectCollect_List.max_size() ? E_CollectCollect_List.max_size() : msg.e_collectcollect_list_size());
	for(int32_t i = 0; i < (int32_t)E_CollectCollect_List.size(); ++i) {
		const ::proto_ff::E_CollectCollect & temp_e_collectcollect_list = msg.e_collectcollect_list(i);
		E_CollectCollect_List[i].read_from_pbmsg(temp_e_collectcollect_list);
	}
}

E_CollectAttributetpyeAttributeDesc_s::E_CollectAttributetpyeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CollectAttributetpyeAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_CollectAttributetpyeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_CollectAttributetpyeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_CollectAttributetpyeAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_CollectAttributetpyeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_CollectAttributetpyeAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_CollectAttributetpye_s::E_CollectAttributetpye_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CollectAttributetpye_s::CreateInit() {
	m_id = (int64_t)0;
	return 0;
}

int E_CollectAttributetpye_s::ResumeInit() {
	return 0;
}

void E_CollectAttributetpye_s::write_to_pbmsg(::proto_ff::E_CollectAttributetpye & msg) const {
	msg.set_m_id((int64_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_CollectAttributetpyeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_CollectAttributetpye_s::read_from_pbmsg(const ::proto_ff::E_CollectAttributetpye & msg) {
	m_id = msg.m_id();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_CollectAttributetpyeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_CollectAttributetpye_s::Sheet_CollectAttributetpye_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CollectAttributetpye_s::CreateInit() {
	return 0;
}

int Sheet_CollectAttributetpye_s::ResumeInit() {
	return 0;
}

void Sheet_CollectAttributetpye_s::write_to_pbmsg(::proto_ff::Sheet_CollectAttributetpye & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CollectAttributetpye_List.size(); ++i) {
		::proto_ff::E_CollectAttributetpye* temp_e_collectattributetpye_list = msg.add_e_collectattributetpye_list();
		E_CollectAttributetpye_List[i].write_to_pbmsg(*temp_e_collectattributetpye_list);
	}
}

void Sheet_CollectAttributetpye_s::read_from_pbmsg(const ::proto_ff::Sheet_CollectAttributetpye & msg) {
	E_CollectAttributetpye_List.resize((int)msg.e_collectattributetpye_list_size() > (int)E_CollectAttributetpye_List.max_size() ? E_CollectAttributetpye_List.max_size() : msg.e_collectattributetpye_list_size());
	for(int32_t i = 0; i < (int32_t)E_CollectAttributetpye_List.size(); ++i) {
		const ::proto_ff::E_CollectAttributetpye & temp_e_collectattributetpye_list = msg.e_collectattributetpye_list(i);
		E_CollectAttributetpye_List[i].read_from_pbmsg(temp_e_collectattributetpye_list);
	}
}

}
