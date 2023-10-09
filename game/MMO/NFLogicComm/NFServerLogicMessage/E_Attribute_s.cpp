#include "E_Attribute_s.h"

namespace proto_ff_s {

E_AttributeAttribute_s::E_AttributeAttribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AttributeAttribute_s::CreateInit() {
	m_id = (int32_t)0;
	m_percent = (int32_t)0;
	m_power = (float)0;
	m_systemtype = (int32_t)0;
	return 0;
}

int E_AttributeAttribute_s::ResumeInit() {
	return 0;
}

void E_AttributeAttribute_s::write_to_pbmsg(::proto_ff::E_AttributeAttribute & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_percent((int32_t)m_percent);
	msg.set_m_power((float)m_power);
	msg.set_m_systemtype((int32_t)m_systemtype);
}

void E_AttributeAttribute_s::read_from_pbmsg(const ::proto_ff::E_AttributeAttribute & msg) {
	m_id = msg.m_id();
	m_percent = msg.m_percent();
	m_power = msg.m_power();
	m_systemtype = msg.m_systemtype();
}

Sheet_AttributeAttribute_s::Sheet_AttributeAttribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AttributeAttribute_s::CreateInit() {
	return 0;
}

int Sheet_AttributeAttribute_s::ResumeInit() {
	return 0;
}

void Sheet_AttributeAttribute_s::write_to_pbmsg(::proto_ff::Sheet_AttributeAttribute & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AttributeAttribute_List.size(); ++i) {
		::proto_ff::E_AttributeAttribute* temp_e_attributeattribute_list = msg.add_e_attributeattribute_list();
		E_AttributeAttribute_List[i].write_to_pbmsg(*temp_e_attributeattribute_list);
	}
}

void Sheet_AttributeAttribute_s::read_from_pbmsg(const ::proto_ff::Sheet_AttributeAttribute & msg) {
	E_AttributeAttribute_List.resize((int)msg.e_attributeattribute_list_size() > (int)E_AttributeAttribute_List.max_size() ? E_AttributeAttribute_List.max_size() : msg.e_attributeattribute_list_size());
	for(int32_t i = 0; i < (int32_t)E_AttributeAttribute_List.size(); ++i) {
		const ::proto_ff::E_AttributeAttribute & temp_e_attributeattribute_list = msg.e_attributeattribute_list(i);
		E_AttributeAttribute_List[i].read_from_pbmsg(temp_e_attributeattribute_list);
	}
}

E_AttributeSuppress_s::E_AttributeSuppress_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AttributeSuppress_s::CreateInit() {
	m_lvldiff = (int32_t)0;
	m_hitsuppve = (int32_t)0;
	m_critsuppve = (int32_t)0;
	m_killsuppve = (int32_t)0;
	m_statesuppve = (int32_t)0;
	m_lvsuppve = (int32_t)0;
	m_hitsuppvp = (int32_t)0;
	m_critsuppvp = (int32_t)0;
	m_killsuppvp = (int32_t)0;
	m_statesuppvp = (int32_t)0;
	m_lvsuppvp = (int32_t)0;
	return 0;
}

int E_AttributeSuppress_s::ResumeInit() {
	return 0;
}

void E_AttributeSuppress_s::write_to_pbmsg(::proto_ff::E_AttributeSuppress & msg) const {
	msg.set_m_lvldiff((int32_t)m_lvldiff);
	msg.set_m_hitsuppve((int32_t)m_hitsuppve);
	msg.set_m_critsuppve((int32_t)m_critsuppve);
	msg.set_m_killsuppve((int32_t)m_killsuppve);
	msg.set_m_statesuppve((int32_t)m_statesuppve);
	msg.set_m_lvsuppve((int32_t)m_lvsuppve);
	msg.set_m_hitsuppvp((int32_t)m_hitsuppvp);
	msg.set_m_critsuppvp((int32_t)m_critsuppvp);
	msg.set_m_killsuppvp((int32_t)m_killsuppvp);
	msg.set_m_statesuppvp((int32_t)m_statesuppvp);
	msg.set_m_lvsuppvp((int32_t)m_lvsuppvp);
}

void E_AttributeSuppress_s::read_from_pbmsg(const ::proto_ff::E_AttributeSuppress & msg) {
	m_lvldiff = msg.m_lvldiff();
	m_hitsuppve = msg.m_hitsuppve();
	m_critsuppve = msg.m_critsuppve();
	m_killsuppve = msg.m_killsuppve();
	m_statesuppve = msg.m_statesuppve();
	m_lvsuppve = msg.m_lvsuppve();
	m_hitsuppvp = msg.m_hitsuppvp();
	m_critsuppvp = msg.m_critsuppvp();
	m_killsuppvp = msg.m_killsuppvp();
	m_statesuppvp = msg.m_statesuppvp();
	m_lvsuppvp = msg.m_lvsuppvp();
}

Sheet_AttributeSuppress_s::Sheet_AttributeSuppress_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AttributeSuppress_s::CreateInit() {
	return 0;
}

int Sheet_AttributeSuppress_s::ResumeInit() {
	return 0;
}

void Sheet_AttributeSuppress_s::write_to_pbmsg(::proto_ff::Sheet_AttributeSuppress & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AttributeSuppress_List.size(); ++i) {
		::proto_ff::E_AttributeSuppress* temp_e_attributesuppress_list = msg.add_e_attributesuppress_list();
		E_AttributeSuppress_List[i].write_to_pbmsg(*temp_e_attributesuppress_list);
	}
}

void Sheet_AttributeSuppress_s::read_from_pbmsg(const ::proto_ff::Sheet_AttributeSuppress & msg) {
	E_AttributeSuppress_List.resize((int)msg.e_attributesuppress_list_size() > (int)E_AttributeSuppress_List.max_size() ? E_AttributeSuppress_List.max_size() : msg.e_attributesuppress_list_size());
	for(int32_t i = 0; i < (int32_t)E_AttributeSuppress_List.size(); ++i) {
		const ::proto_ff::E_AttributeSuppress & temp_e_attributesuppress_list = msg.e_attributesuppress_list(i);
		E_AttributeSuppress_List[i].read_from_pbmsg(temp_e_attributesuppress_list);
	}
}

E_AttributePowersup_s::E_AttributePowersup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AttributePowersup_s::CreateInit() {
	m_powerdiff = (int32_t)0;
	m_powersuppve = (int32_t)0;
	m_powersuppvp = (int32_t)0;
	return 0;
}

int E_AttributePowersup_s::ResumeInit() {
	return 0;
}

void E_AttributePowersup_s::write_to_pbmsg(::proto_ff::E_AttributePowersup & msg) const {
	msg.set_m_powerdiff((int32_t)m_powerdiff);
	msg.set_m_powersuppve((int32_t)m_powersuppve);
	msg.set_m_powersuppvp((int32_t)m_powersuppvp);
}

void E_AttributePowersup_s::read_from_pbmsg(const ::proto_ff::E_AttributePowersup & msg) {
	m_powerdiff = msg.m_powerdiff();
	m_powersuppve = msg.m_powersuppve();
	m_powersuppvp = msg.m_powersuppvp();
}

Sheet_AttributePowersup_s::Sheet_AttributePowersup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AttributePowersup_s::CreateInit() {
	return 0;
}

int Sheet_AttributePowersup_s::ResumeInit() {
	return 0;
}

void Sheet_AttributePowersup_s::write_to_pbmsg(::proto_ff::Sheet_AttributePowersup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AttributePowersup_List.size(); ++i) {
		::proto_ff::E_AttributePowersup* temp_e_attributepowersup_list = msg.add_e_attributepowersup_list();
		E_AttributePowersup_List[i].write_to_pbmsg(*temp_e_attributepowersup_list);
	}
}

void Sheet_AttributePowersup_s::read_from_pbmsg(const ::proto_ff::Sheet_AttributePowersup & msg) {
	E_AttributePowersup_List.resize((int)msg.e_attributepowersup_list_size() > (int)E_AttributePowersup_List.max_size() ? E_AttributePowersup_List.max_size() : msg.e_attributepowersup_list_size());
	for(int32_t i = 0; i < (int32_t)E_AttributePowersup_List.size(); ++i) {
		const ::proto_ff::E_AttributePowersup & temp_e_attributepowersup_list = msg.e_attributepowersup_list(i);
		E_AttributePowersup_List[i].read_from_pbmsg(temp_e_attributepowersup_list);
	}
}

}
