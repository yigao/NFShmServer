#include "E_Footprint_s.h"

namespace proto_ff_s {

E_FootprintFootprintAttributeDesc_s::E_FootprintFootprintAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FootprintFootprintAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_FootprintFootprintAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_FootprintFootprintAttributeDesc_s::write_to_pbmsg(::proto_ff::E_FootprintFootprintAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_FootprintFootprintAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FootprintFootprintAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_FootprintFootprintActiveattributeDesc_s::E_FootprintFootprintActiveattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FootprintFootprintActiveattributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_FootprintFootprintActiveattributeDesc_s::ResumeInit() {
	return 0;
}

void E_FootprintFootprintActiveattributeDesc_s::write_to_pbmsg(::proto_ff::E_FootprintFootprintActiveattributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_FootprintFootprintActiveattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FootprintFootprintActiveattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_FootprintFootprint_s::E_FootprintFootprint_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FootprintFootprint_s::CreateInit() {
	m_id = (int64_t)0;
	m_type = (int32_t)0;
	m_quality = (int32_t)0;
	m_activationitem = (int64_t)0;
	m_activationnum = (int32_t)0;
	m_starid = (int64_t)0;
	m_starup = (int32_t)0;
	m_starber = (int32_t)0;
	return 0;
}

int E_FootprintFootprint_s::ResumeInit() {
	return 0;
}

void E_FootprintFootprint_s::write_to_pbmsg(::proto_ff::E_FootprintFootprint & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_type((int32_t)m_type);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_professionlimit(m_professionlimit.data());
	msg.set_m_activationitem((int64_t)m_activationitem);
	msg.set_m_activationnum((int32_t)m_activationnum);
	msg.set_m_starid((int64_t)m_starid);
	msg.set_m_starnum(m_starnum.data());
	msg.set_m_starup((int32_t)m_starup);
	msg.set_m_starber((int32_t)m_starber);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_FootprintFootprintAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_activeattribute.size(); ++i) {
		::proto_ff::E_FootprintFootprintActiveattributeDesc* temp_m_activeattribute = msg.add_m_activeattribute();
		m_activeattribute[i].write_to_pbmsg(*temp_m_activeattribute);
	}
}

void E_FootprintFootprint_s::read_from_pbmsg(const ::proto_ff::E_FootprintFootprint & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_type = msg.m_type();
	m_quality = msg.m_quality();
	m_professionlimit = msg.m_professionlimit();
	m_activationitem = msg.m_activationitem();
	m_activationnum = msg.m_activationnum();
	m_starid = msg.m_starid();
	m_starnum = msg.m_starnum();
	m_starup = msg.m_starup();
	m_starber = msg.m_starber();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_FootprintFootprintAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_activeattribute.resize((int)msg.m_activeattribute_size() > (int)m_activeattribute.max_size() ? m_activeattribute.max_size() : msg.m_activeattribute_size());
	for(int32_t i = 0; i < (int32_t)m_activeattribute.size(); ++i) {
		const ::proto_ff::E_FootprintFootprintActiveattributeDesc & temp_m_activeattribute = msg.m_activeattribute(i);
		m_activeattribute[i].read_from_pbmsg(temp_m_activeattribute);
	}
}

Sheet_FootprintFootprint_s::Sheet_FootprintFootprint_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FootprintFootprint_s::CreateInit() {
	return 0;
}

int Sheet_FootprintFootprint_s::ResumeInit() {
	return 0;
}

void Sheet_FootprintFootprint_s::write_to_pbmsg(::proto_ff::Sheet_FootprintFootprint & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FootprintFootprint_List.size(); ++i) {
		::proto_ff::E_FootprintFootprint* temp_e_footprintfootprint_list = msg.add_e_footprintfootprint_list();
		E_FootprintFootprint_List[i].write_to_pbmsg(*temp_e_footprintfootprint_list);
	}
}

void Sheet_FootprintFootprint_s::read_from_pbmsg(const ::proto_ff::Sheet_FootprintFootprint & msg) {
	E_FootprintFootprint_List.resize((int)msg.e_footprintfootprint_list_size() > (int)E_FootprintFootprint_List.max_size() ? E_FootprintFootprint_List.max_size() : msg.e_footprintfootprint_list_size());
	for(int32_t i = 0; i < (int32_t)E_FootprintFootprint_List.size(); ++i) {
		const ::proto_ff::E_FootprintFootprint & temp_e_footprintfootprint_list = msg.e_footprintfootprint_list(i);
		E_FootprintFootprint_List[i].read_from_pbmsg(temp_e_footprintfootprint_list);
	}
}

}
