#include "fashion_s.h"

namespace proto_ff_s {

E_FashionFashionAttributeDesc_s::E_FashionFashionAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FashionFashionAttributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_FashionFashionAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_FashionFashionAttributeDesc_s::write_to_pbmsg(::proto_ff::E_FashionFashionAttributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_FashionFashionAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FashionFashionAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FashionFashionAttributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_FashionFashionActiveattributeDesc_s::E_FashionFashionActiveattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FashionFashionActiveattributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_FashionFashionActiveattributeDesc_s::ResumeInit() {
	return 0;
}

void E_FashionFashionActiveattributeDesc_s::write_to_pbmsg(::proto_ff::E_FashionFashionActiveattributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_FashionFashionActiveattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FashionFashionActiveattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FashionFashionActiveattributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_FashionFashion_s::E_FashionFashion_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FashionFashion_s::CreateInit() {
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

int E_FashionFashion_s::ResumeInit() {
	return 0;
}

void E_FashionFashion_s::write_to_pbmsg(::proto_ff::E_FashionFashion & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_name((const char*)m_name.data());
	msg.set_m_type((int32_t)m_type);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_professionlimit((const char*)m_professionlimit.data());
	msg.set_m_activationitem((int64_t)m_activationitem);
	msg.set_m_activationnum((int32_t)m_activationnum);
	msg.set_m_starid((int64_t)m_starid);
	msg.set_m_starnum((const char*)m_starnum.data());
	msg.set_m_starup((int32_t)m_starup);
	msg.set_m_starber((int32_t)m_starber);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_FashionFashionAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_activeattribute.size(); ++i) {
		::proto_ff::E_FashionFashionActiveattributeDesc* temp_m_activeattribute = msg.add_m_activeattribute();
		m_activeattribute[i].write_to_pbmsg(*temp_m_activeattribute);
	}
}

void E_FashionFashion_s::read_from_pbmsg(const ::proto_ff::E_FashionFashion & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FashionFashion_s));
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
		const ::proto_ff::E_FashionFashionAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_activeattribute.resize((int)msg.m_activeattribute_size() > (int)m_activeattribute.max_size() ? m_activeattribute.max_size() : msg.m_activeattribute_size());
	for(int32_t i = 0; i < (int32_t)m_activeattribute.size(); ++i) {
		const ::proto_ff::E_FashionFashionActiveattributeDesc & temp_m_activeattribute = msg.m_activeattribute(i);
		m_activeattribute[i].read_from_pbmsg(temp_m_activeattribute);
	}
}

Sheet_FashionFashion_s::Sheet_FashionFashion_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FashionFashion_s::CreateInit() {
	return 0;
}

int Sheet_FashionFashion_s::ResumeInit() {
	return 0;
}

void Sheet_FashionFashion_s::write_to_pbmsg(::proto_ff::Sheet_FashionFashion & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FashionFashion_List.size(); ++i) {
		::proto_ff::E_FashionFashion* temp_e_fashionfashion_list = msg.add_e_fashionfashion_list();
		E_FashionFashion_List[i].write_to_pbmsg(*temp_e_fashionfashion_list);
	}
}

void Sheet_FashionFashion_s::read_from_pbmsg(const ::proto_ff::Sheet_FashionFashion & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FashionFashion_s));
	E_FashionFashion_List.resize((int)msg.e_fashionfashion_list_size() > (int)E_FashionFashion_List.max_size() ? E_FashionFashion_List.max_size() : msg.e_fashionfashion_list_size());
	for(int32_t i = 0; i < (int32_t)E_FashionFashion_List.size(); ++i) {
		const ::proto_ff::E_FashionFashion & temp_e_fashionfashion_list = msg.e_fashionfashion_list(i);
		E_FashionFashion_List[i].read_from_pbmsg(temp_e_fashionfashion_list);
	}
}

}