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
	m_systemType = (int32_t)0;
	return 0;
}

int E_AttributeAttribute_s::ResumeInit() {
	return 0;
}

void E_AttributeAttribute_s::write_to_pbmsg(::proto_ff::E_AttributeAttribute & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_percent((int32_t)m_percent);
	msg.set_m_power((float)m_power);
	msg.set_m_systemtype((int32_t)m_systemType);
}

void E_AttributeAttribute_s::read_from_pbmsg(const ::proto_ff::E_AttributeAttribute & msg) {
	m_id = msg.m_id();
	m_percent = msg.m_percent();
	m_power = msg.m_power();
	m_systemType = msg.m_systemtype();
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
	m_lvlDiff = (int32_t)0;
	m_hitSupPve = (int32_t)0;
	m_critSupPve = (int32_t)0;
	m_killSupPve = (int32_t)0;
	m_stateSupPve = (int32_t)0;
	m_lvSupPve = (int32_t)0;
	m_hitSupPvp = (int32_t)0;
	m_critSupPvp = (int32_t)0;
	m_killSupPvp = (int32_t)0;
	m_stateSupPvp = (int32_t)0;
	m_lvSupPvp = (int32_t)0;
	return 0;
}

int E_AttributeSuppress_s::ResumeInit() {
	return 0;
}

void E_AttributeSuppress_s::write_to_pbmsg(::proto_ff::E_AttributeSuppress & msg) const {
	msg.set_m_lvldiff((int32_t)m_lvlDiff);
	msg.set_m_hitsuppve((int32_t)m_hitSupPve);
	msg.set_m_critsuppve((int32_t)m_critSupPve);
	msg.set_m_killsuppve((int32_t)m_killSupPve);
	msg.set_m_statesuppve((int32_t)m_stateSupPve);
	msg.set_m_lvsuppve((int32_t)m_lvSupPve);
	msg.set_m_hitsuppvp((int32_t)m_hitSupPvp);
	msg.set_m_critsuppvp((int32_t)m_critSupPvp);
	msg.set_m_killsuppvp((int32_t)m_killSupPvp);
	msg.set_m_statesuppvp((int32_t)m_stateSupPvp);
	msg.set_m_lvsuppvp((int32_t)m_lvSupPvp);
}

void E_AttributeSuppress_s::read_from_pbmsg(const ::proto_ff::E_AttributeSuppress & msg) {
	m_lvlDiff = msg.m_lvldiff();
	m_hitSupPve = msg.m_hitsuppve();
	m_critSupPve = msg.m_critsuppve();
	m_killSupPve = msg.m_killsuppve();
	m_stateSupPve = msg.m_statesuppve();
	m_lvSupPve = msg.m_lvsuppve();
	m_hitSupPvp = msg.m_hitsuppvp();
	m_critSupPvp = msg.m_critsuppvp();
	m_killSupPvp = msg.m_killsuppvp();
	m_stateSupPvp = msg.m_statesuppvp();
	m_lvSupPvp = msg.m_lvsuppvp();
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
	m_powerDiff = (int32_t)0;
	m_powerSupPve = (int32_t)0;
	m_powerSupPvp = (int32_t)0;
	return 0;
}

int E_AttributePowersup_s::ResumeInit() {
	return 0;
}

void E_AttributePowersup_s::write_to_pbmsg(::proto_ff::E_AttributePowersup & msg) const {
	msg.set_m_powerdiff((int32_t)m_powerDiff);
	msg.set_m_powersuppve((int32_t)m_powerSupPve);
	msg.set_m_powersuppvp((int32_t)m_powerSupPvp);
}

void E_AttributePowersup_s::read_from_pbmsg(const ::proto_ff::E_AttributePowersup & msg) {
	m_powerDiff = msg.m_powerdiff();
	m_powerSupPve = msg.m_powersuppve();
	m_powerSupPvp = msg.m_powersuppvp();
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
