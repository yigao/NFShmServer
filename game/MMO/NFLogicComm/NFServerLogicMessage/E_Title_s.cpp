#include "E_Title_s.h"

namespace proto_ff_s {

E_TitleType_s::E_TitleType_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TitleType_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_TitleType_s::ResumeInit() {
	return 0;
}

void E_TitleType_s::write_to_pbmsg(::proto_ff::E_TitleType & msg) const {
	msg.set_m_id((int32_t)m_id);
}

void E_TitleType_s::read_from_pbmsg(const ::proto_ff::E_TitleType & msg) {
	m_id = msg.m_id();
}

Sheet_TitleType_s::Sheet_TitleType_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TitleType_s::CreateInit() {
	return 0;
}

int Sheet_TitleType_s::ResumeInit() {
	return 0;
}

void Sheet_TitleType_s::write_to_pbmsg(::proto_ff::Sheet_TitleType & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TitleType_List.size(); ++i) {
		::proto_ff::E_TitleType* temp_e_titletype_list = msg.add_e_titletype_list();
		E_TitleType_List[i].write_to_pbmsg(*temp_e_titletype_list);
	}
}

void Sheet_TitleType_s::read_from_pbmsg(const ::proto_ff::Sheet_TitleType & msg) {
	E_TitleType_List.resize((int)msg.e_titletype_list_size() > (int)E_TitleType_List.max_size() ? E_TitleType_List.max_size() : msg.e_titletype_list_size());
	for(int32_t i = 0; i < (int32_t)E_TitleType_List.size(); ++i) {
		const ::proto_ff::E_TitleType & temp_e_titletype_list = msg.e_titletype_list(i);
		E_TitleType_List[i].read_from_pbmsg(temp_e_titletype_list);
	}
}

E_TitleTitleAttributeDesc_s::E_TitleTitleAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TitleTitleAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_TitleTitleAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_TitleTitleAttributeDesc_s::write_to_pbmsg(::proto_ff::E_TitleTitleAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_TitleTitleAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_TitleTitleAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_TitleTitle_s::E_TitleTitle_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TitleTitle_s::CreateInit() {
	m_id = (int64_t)0;
	m_type = (int32_t)0;
	m_subtype = (int32_t)0;
	m_addtime = (int32_t)0;
	m_timetpye = (int32_t)0;
	m_lifetime = (int32_t)0;
	m_activationitem = (int64_t)0;
	m_activationnum = (int32_t)0;
	m_starid = (int64_t)0;
	m_starup = (int32_t)0;
	m_starber = (int32_t)0;
	return 0;
}

int E_TitleTitle_s::ResumeInit() {
	return 0;
}

void E_TitleTitle_s::write_to_pbmsg(::proto_ff::E_TitleTitle & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_type((int32_t)m_type);
	msg.set_m_subtype((int32_t)m_subtype);
	msg.set_m_eventvalue(m_eventvalue.data());
	msg.set_m_describe(m_describe.data());
	msg.set_m_addtime((int32_t)m_addtime);
	msg.set_m_timetpye((int32_t)m_timetpye);
	msg.set_m_lifetime((int32_t)m_lifetime);
	msg.set_m_activationitem((int64_t)m_activationitem);
	msg.set_m_activationnum((int32_t)m_activationnum);
	msg.set_m_starid((int64_t)m_starid);
	msg.set_m_starnum(m_starnum.data());
	msg.set_m_starup((int32_t)m_starup);
	msg.set_m_starber((int32_t)m_starber);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_TitleTitleAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_TitleTitle_s::read_from_pbmsg(const ::proto_ff::E_TitleTitle & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_type = msg.m_type();
	m_subtype = msg.m_subtype();
	m_eventvalue = msg.m_eventvalue();
	m_describe = msg.m_describe();
	m_addtime = msg.m_addtime();
	m_timetpye = msg.m_timetpye();
	m_lifetime = msg.m_lifetime();
	m_activationitem = msg.m_activationitem();
	m_activationnum = msg.m_activationnum();
	m_starid = msg.m_starid();
	m_starnum = msg.m_starnum();
	m_starup = msg.m_starup();
	m_starber = msg.m_starber();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_TitleTitleAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_TitleTitle_s::Sheet_TitleTitle_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TitleTitle_s::CreateInit() {
	return 0;
}

int Sheet_TitleTitle_s::ResumeInit() {
	return 0;
}

void Sheet_TitleTitle_s::write_to_pbmsg(::proto_ff::Sheet_TitleTitle & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TitleTitle_List.size(); ++i) {
		::proto_ff::E_TitleTitle* temp_e_titletitle_list = msg.add_e_titletitle_list();
		E_TitleTitle_List[i].write_to_pbmsg(*temp_e_titletitle_list);
	}
}

void Sheet_TitleTitle_s::read_from_pbmsg(const ::proto_ff::Sheet_TitleTitle & msg) {
	E_TitleTitle_List.resize((int)msg.e_titletitle_list_size() > (int)E_TitleTitle_List.max_size() ? E_TitleTitle_List.max_size() : msg.e_titletitle_list_size());
	for(int32_t i = 0; i < (int32_t)E_TitleTitle_List.size(); ++i) {
		const ::proto_ff::E_TitleTitle & temp_e_titletitle_list = msg.e_titletitle_list(i);
		E_TitleTitle_List[i].read_from_pbmsg(temp_e_titletitle_list);
	}
}

}
