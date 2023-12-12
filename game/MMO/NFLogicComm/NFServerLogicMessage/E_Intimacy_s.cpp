#include "E_Intimacy_s.h"

namespace proto_ff_s {

E_IntimacyIntimacyAttributeDesc_s::E_IntimacyIntimacyAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_IntimacyIntimacyAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_IntimacyIntimacyAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_IntimacyIntimacyAttributeDesc_s::write_to_pbmsg(::proto_ff::E_IntimacyIntimacyAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_IntimacyIntimacyAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_IntimacyIntimacyAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_IntimacyIntimacy_s::E_IntimacyIntimacy_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_IntimacyIntimacy_s::CreateInit() {
	m_lv = (int32_t)0;
	m_intimacyMin = (int32_t)0;
	m_intimacyMax = (int32_t)0;
	return 0;
}

int E_IntimacyIntimacy_s::ResumeInit() {
	return 0;
}

void E_IntimacyIntimacy_s::write_to_pbmsg(::proto_ff::E_IntimacyIntimacy & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_intimacymin((int32_t)m_intimacyMin);
	msg.set_m_intimacymax((int32_t)m_intimacyMax);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_IntimacyIntimacyAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_IntimacyIntimacy_s::read_from_pbmsg(const ::proto_ff::E_IntimacyIntimacy & msg) {
	m_lv = msg.m_lv();
	m_intimacyMin = msg.m_intimacymin();
	m_intimacyMax = msg.m_intimacymax();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_IntimacyIntimacyAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_IntimacyIntimacy_s::Sheet_IntimacyIntimacy_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_IntimacyIntimacy_s::CreateInit() {
	return 0;
}

int Sheet_IntimacyIntimacy_s::ResumeInit() {
	return 0;
}

void Sheet_IntimacyIntimacy_s::write_to_pbmsg(::proto_ff::Sheet_IntimacyIntimacy & msg) const {
	for(int32_t i = 0; i < (int32_t)E_IntimacyIntimacy_List.size(); ++i) {
		::proto_ff::E_IntimacyIntimacy* temp_e_intimacyintimacy_list = msg.add_e_intimacyintimacy_list();
		E_IntimacyIntimacy_List[i].write_to_pbmsg(*temp_e_intimacyintimacy_list);
	}
}

void Sheet_IntimacyIntimacy_s::read_from_pbmsg(const ::proto_ff::Sheet_IntimacyIntimacy & msg) {
	E_IntimacyIntimacy_List.resize((int)msg.e_intimacyintimacy_list_size() > (int)E_IntimacyIntimacy_List.max_size() ? E_IntimacyIntimacy_List.max_size() : msg.e_intimacyintimacy_list_size());
	for(int32_t i = 0; i < (int32_t)E_IntimacyIntimacy_List.size(); ++i) {
		const ::proto_ff::E_IntimacyIntimacy & temp_e_intimacyintimacy_list = msg.e_intimacyintimacy_list(i);
		E_IntimacyIntimacy_List[i].read_from_pbmsg(temp_e_intimacyintimacy_list);
	}
}

E_IntimacyGift_s::E_IntimacyGift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_IntimacyGift_s::CreateInit() {
	m_mallid = (int32_t)0;
	m_itemId = (int32_t)0;
	m_nameType = (int32_t)0;
	m_intimacy = (int32_t)0;
	m_charm = (int32_t)0;
	m_acceptCharm = (int32_t)0;
	return 0;
}

int E_IntimacyGift_s::ResumeInit() {
	return 0;
}

void E_IntimacyGift_s::write_to_pbmsg(::proto_ff::E_IntimacyGift & msg) const {
	msg.set_m_mallid((int32_t)m_mallid);
	msg.set_m_itemid((int32_t)m_itemId);
	msg.set_m_nametype((int32_t)m_nameType);
	msg.set_m_uipic(m_uiPic.data());
	msg.set_m_intimacy((int32_t)m_intimacy);
	msg.set_m_charm((int32_t)m_charm);
	msg.set_m_acceptcharm((int32_t)m_acceptCharm);
}

void E_IntimacyGift_s::read_from_pbmsg(const ::proto_ff::E_IntimacyGift & msg) {
	m_mallid = msg.m_mallid();
	m_itemId = msg.m_itemid();
	m_nameType = msg.m_nametype();
	m_uiPic = msg.m_uipic();
	m_intimacy = msg.m_intimacy();
	m_charm = msg.m_charm();
	m_acceptCharm = msg.m_acceptcharm();
}

Sheet_IntimacyGift_s::Sheet_IntimacyGift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_IntimacyGift_s::CreateInit() {
	return 0;
}

int Sheet_IntimacyGift_s::ResumeInit() {
	return 0;
}

void Sheet_IntimacyGift_s::write_to_pbmsg(::proto_ff::Sheet_IntimacyGift & msg) const {
	for(int32_t i = 0; i < (int32_t)E_IntimacyGift_List.size(); ++i) {
		::proto_ff::E_IntimacyGift* temp_e_intimacygift_list = msg.add_e_intimacygift_list();
		E_IntimacyGift_List[i].write_to_pbmsg(*temp_e_intimacygift_list);
	}
}

void Sheet_IntimacyGift_s::read_from_pbmsg(const ::proto_ff::Sheet_IntimacyGift & msg) {
	E_IntimacyGift_List.resize((int)msg.e_intimacygift_list_size() > (int)E_IntimacyGift_List.max_size() ? E_IntimacyGift_List.max_size() : msg.e_intimacygift_list_size());
	for(int32_t i = 0; i < (int32_t)E_IntimacyGift_List.size(); ++i) {
		const ::proto_ff::E_IntimacyGift & temp_e_intimacygift_list = msg.e_intimacygift_list(i);
		E_IntimacyGift_List[i].read_from_pbmsg(temp_e_intimacygift_list);
	}
}

}
