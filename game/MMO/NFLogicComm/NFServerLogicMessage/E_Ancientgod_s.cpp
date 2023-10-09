#include "E_Ancientgod_s.h"

namespace proto_ff_s {

E_AncientgodAncientgodFraDesc_s::E_AncientgodAncientgodFraDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AncientgodAncientgodFraDesc_s::CreateInit() {
	m_attid = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_AncientgodAncientgodFraDesc_s::ResumeInit() {
	return 0;
}

void E_AncientgodAncientgodFraDesc_s::write_to_pbmsg(::proto_ff::E_AncientgodAncientgodFraDesc & msg) const {
	msg.set_m_attid((int32_t)m_attid);
	msg.set_m_num((int32_t)m_num);
}

void E_AncientgodAncientgodFraDesc_s::read_from_pbmsg(const ::proto_ff::E_AncientgodAncientgodFraDesc & msg) {
	m_attid = msg.m_attid();
	m_num = msg.m_num();
}

E_AncientgodAncientgod_s::E_AncientgodAncientgod_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AncientgodAncientgod_s::CreateInit() {
	m_id = (int32_t)0;
	m_parama = (float)0;
	m_showlv = (int32_t)0;
	m_unlocklv = (int32_t)0;
	m_lvlimit = (int32_t)0;
	m_stars = (int32_t)0;
	return 0;
}

int E_AncientgodAncientgod_s::ResumeInit() {
	return 0;
}

void E_AncientgodAncientgod_s::write_to_pbmsg(::proto_ff::E_AncientgodAncientgod & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_parama((float)m_parama);
	msg.set_m_showlv((int32_t)m_showlv);
	msg.set_m_unlocklv((int32_t)m_unlocklv);
	msg.set_m_condition(m_condition.data());
	msg.set_m_lvlimit((int32_t)m_lvlimit);
	msg.set_m_stars((int32_t)m_stars);
	for(int32_t i = 0; i < (int32_t)m_fra.size(); ++i) {
		::proto_ff::E_AncientgodAncientgodFraDesc* temp_m_fra = msg.add_m_fra();
		m_fra[i].write_to_pbmsg(*temp_m_fra);
	}
}

void E_AncientgodAncientgod_s::read_from_pbmsg(const ::proto_ff::E_AncientgodAncientgod & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_parama = msg.m_parama();
	m_showlv = msg.m_showlv();
	m_unlocklv = msg.m_unlocklv();
	m_condition = msg.m_condition();
	m_lvlimit = msg.m_lvlimit();
	m_stars = msg.m_stars();
	m_fra.resize((int)msg.m_fra_size() > (int)m_fra.max_size() ? m_fra.max_size() : msg.m_fra_size());
	for(int32_t i = 0; i < (int32_t)m_fra.size(); ++i) {
		const ::proto_ff::E_AncientgodAncientgodFraDesc & temp_m_fra = msg.m_fra(i);
		m_fra[i].read_from_pbmsg(temp_m_fra);
	}
}

Sheet_AncientgodAncientgod_s::Sheet_AncientgodAncientgod_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AncientgodAncientgod_s::CreateInit() {
	return 0;
}

int Sheet_AncientgodAncientgod_s::ResumeInit() {
	return 0;
}

void Sheet_AncientgodAncientgod_s::write_to_pbmsg(::proto_ff::Sheet_AncientgodAncientgod & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AncientgodAncientgod_List.size(); ++i) {
		::proto_ff::E_AncientgodAncientgod* temp_e_ancientgodancientgod_list = msg.add_e_ancientgodancientgod_list();
		E_AncientgodAncientgod_List[i].write_to_pbmsg(*temp_e_ancientgodancientgod_list);
	}
}

void Sheet_AncientgodAncientgod_s::read_from_pbmsg(const ::proto_ff::Sheet_AncientgodAncientgod & msg) {
	E_AncientgodAncientgod_List.resize((int)msg.e_ancientgodancientgod_list_size() > (int)E_AncientgodAncientgod_List.max_size() ? E_AncientgodAncientgod_List.max_size() : msg.e_ancientgodancientgod_list_size());
	for(int32_t i = 0; i < (int32_t)E_AncientgodAncientgod_List.size(); ++i) {
		const ::proto_ff::E_AncientgodAncientgod & temp_e_ancientgodancientgod_list = msg.e_ancientgodancientgod_list(i);
		E_AncientgodAncientgod_List[i].read_from_pbmsg(temp_e_ancientgodancientgod_list);
	}
}

E_AncientgodLvupAttributeDesc_s::E_AncientgodLvupAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AncientgodLvupAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AncientgodLvupAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AncientgodLvupAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AncientgodLvupAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_AncientgodLvupAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AncientgodLvupAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_AncientgodLvup_s::E_AncientgodLvup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AncientgodLvup_s::CreateInit() {
	m_id = (int32_t)0;
	m_lv = (int32_t)0;
	m_ancientid = (int32_t)0;
	m_itemid = (int32_t)0;
	m_mallid = (int32_t)0;
	m_num = (int32_t)0;
	m_initialvalue = (int32_t)0;
	m_position = (int32_t)0;
	return 0;
}

int E_AncientgodLvup_s::ResumeInit() {
	return 0;
}

void E_AncientgodLvup_s::write_to_pbmsg(::proto_ff::E_AncientgodLvup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_ancientid((int32_t)m_ancientid);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_mallid((int32_t)m_mallid);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_initialvalue((int32_t)m_initialvalue);
	msg.set_m_position((int32_t)m_position);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_AncientgodLvupAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AncientgodLvup_s::read_from_pbmsg(const ::proto_ff::E_AncientgodLvup & msg) {
	m_id = msg.m_id();
	m_lv = msg.m_lv();
	m_ancientid = msg.m_ancientid();
	m_itemid = msg.m_itemid();
	m_mallid = msg.m_mallid();
	m_num = msg.m_num();
	m_initialvalue = msg.m_initialvalue();
	m_position = msg.m_position();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_AncientgodLvupAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AncientgodLvup_s::Sheet_AncientgodLvup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AncientgodLvup_s::CreateInit() {
	return 0;
}

int Sheet_AncientgodLvup_s::ResumeInit() {
	return 0;
}

void Sheet_AncientgodLvup_s::write_to_pbmsg(::proto_ff::Sheet_AncientgodLvup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AncientgodLvup_List.size(); ++i) {
		::proto_ff::E_AncientgodLvup* temp_e_ancientgodlvup_list = msg.add_e_ancientgodlvup_list();
		E_AncientgodLvup_List[i].write_to_pbmsg(*temp_e_ancientgodlvup_list);
	}
}

void Sheet_AncientgodLvup_s::read_from_pbmsg(const ::proto_ff::Sheet_AncientgodLvup & msg) {
	E_AncientgodLvup_List.resize((int)msg.e_ancientgodlvup_list_size() > (int)E_AncientgodLvup_List.max_size() ? E_AncientgodLvup_List.max_size() : msg.e_ancientgodlvup_list_size());
	for(int32_t i = 0; i < (int32_t)E_AncientgodLvup_List.size(); ++i) {
		const ::proto_ff::E_AncientgodLvup & temp_e_ancientgodlvup_list = msg.e_ancientgodlvup_list(i);
		E_AncientgodLvup_List[i].read_from_pbmsg(temp_e_ancientgodlvup_list);
	}
}

E_AncientgodEquipvalue_s::E_AncientgodEquipvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AncientgodEquipvalue_s::CreateInit() {
	m_id = (int32_t)0;
	m_quality = (int32_t)0;
	m_wearquality = (int32_t)0;
	m_star = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_AncientgodEquipvalue_s::ResumeInit() {
	return 0;
}

void E_AncientgodEquipvalue_s::write_to_pbmsg(::proto_ff::E_AncientgodEquipvalue & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_wearquality((int32_t)m_wearquality);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_value((int32_t)m_value);
}

void E_AncientgodEquipvalue_s::read_from_pbmsg(const ::proto_ff::E_AncientgodEquipvalue & msg) {
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_wearquality = msg.m_wearquality();
	m_star = msg.m_star();
	m_value = msg.m_value();
}

Sheet_AncientgodEquipvalue_s::Sheet_AncientgodEquipvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AncientgodEquipvalue_s::CreateInit() {
	return 0;
}

int Sheet_AncientgodEquipvalue_s::ResumeInit() {
	return 0;
}

void Sheet_AncientgodEquipvalue_s::write_to_pbmsg(::proto_ff::Sheet_AncientgodEquipvalue & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AncientgodEquipvalue_List.size(); ++i) {
		::proto_ff::E_AncientgodEquipvalue* temp_e_ancientgodequipvalue_list = msg.add_e_ancientgodequipvalue_list();
		E_AncientgodEquipvalue_List[i].write_to_pbmsg(*temp_e_ancientgodequipvalue_list);
	}
}

void Sheet_AncientgodEquipvalue_s::read_from_pbmsg(const ::proto_ff::Sheet_AncientgodEquipvalue & msg) {
	E_AncientgodEquipvalue_List.resize((int)msg.e_ancientgodequipvalue_list_size() > (int)E_AncientgodEquipvalue_List.max_size() ? E_AncientgodEquipvalue_List.max_size() : msg.e_ancientgodequipvalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_AncientgodEquipvalue_List.size(); ++i) {
		const ::proto_ff::E_AncientgodEquipvalue & temp_e_ancientgodequipvalue_list = msg.e_ancientgodequipvalue_list(i);
		E_AncientgodEquipvalue_List[i].read_from_pbmsg(temp_e_ancientgodequipvalue_list);
	}
}

E_AncientgodBlessAttributeDesc_s::E_AncientgodBlessAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AncientgodBlessAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AncientgodBlessAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AncientgodBlessAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AncientgodBlessAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_AncientgodBlessAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AncientgodBlessAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_AncientgodBless_s::E_AncientgodBless_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AncientgodBless_s::CreateInit() {
	m_id = (int32_t)0;
	m_ancientid = (int32_t)0;
	m_position = (int32_t)0;
	m_itemid = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_AncientgodBless_s::ResumeInit() {
	return 0;
}

void E_AncientgodBless_s::write_to_pbmsg(::proto_ff::E_AncientgodBless & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_ancientid((int32_t)m_ancientid);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_num((int32_t)m_num);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_AncientgodBlessAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AncientgodBless_s::read_from_pbmsg(const ::proto_ff::E_AncientgodBless & msg) {
	m_id = msg.m_id();
	m_ancientid = msg.m_ancientid();
	m_position = msg.m_position();
	m_itemid = msg.m_itemid();
	m_num = msg.m_num();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_AncientgodBlessAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AncientgodBless_s::Sheet_AncientgodBless_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AncientgodBless_s::CreateInit() {
	return 0;
}

int Sheet_AncientgodBless_s::ResumeInit() {
	return 0;
}

void Sheet_AncientgodBless_s::write_to_pbmsg(::proto_ff::Sheet_AncientgodBless & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AncientgodBless_List.size(); ++i) {
		::proto_ff::E_AncientgodBless* temp_e_ancientgodbless_list = msg.add_e_ancientgodbless_list();
		E_AncientgodBless_List[i].write_to_pbmsg(*temp_e_ancientgodbless_list);
	}
}

void Sheet_AncientgodBless_s::read_from_pbmsg(const ::proto_ff::Sheet_AncientgodBless & msg) {
	E_AncientgodBless_List.resize((int)msg.e_ancientgodbless_list_size() > (int)E_AncientgodBless_List.max_size() ? E_AncientgodBless_List.max_size() : msg.e_ancientgodbless_list_size());
	for(int32_t i = 0; i < (int32_t)E_AncientgodBless_List.size(); ++i) {
		const ::proto_ff::E_AncientgodBless & temp_e_ancientgodbless_list = msg.e_ancientgodbless_list(i);
		E_AncientgodBless_List[i].read_from_pbmsg(temp_e_ancientgodbless_list);
	}
}

E_AncientgodAdvanceAttributeDesc_s::E_AncientgodAdvanceAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AncientgodAdvanceAttributeDesc_s::CreateInit() {
	m_star = (int32_t)0;
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AncientgodAdvanceAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AncientgodAdvanceAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AncientgodAdvanceAttributeDesc & msg) const {
	msg.set_m_star((int32_t)m_star);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_AncientgodAdvanceAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AncientgodAdvanceAttributeDesc & msg) {
	m_star = msg.m_star();
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_AncientgodAdvance_s::E_AncientgodAdvance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AncientgodAdvance_s::CreateInit() {
	m_id = (int32_t)0;
	m_ancientid = (int32_t)0;
	m_position = (int32_t)0;
	return 0;
}

int E_AncientgodAdvance_s::ResumeInit() {
	return 0;
}

void E_AncientgodAdvance_s::write_to_pbmsg(::proto_ff::E_AncientgodAdvance & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_ancientid((int32_t)m_ancientid);
	msg.set_m_position((int32_t)m_position);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_AncientgodAdvanceAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AncientgodAdvance_s::read_from_pbmsg(const ::proto_ff::E_AncientgodAdvance & msg) {
	m_id = msg.m_id();
	m_ancientid = msg.m_ancientid();
	m_position = msg.m_position();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_AncientgodAdvanceAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AncientgodAdvance_s::Sheet_AncientgodAdvance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AncientgodAdvance_s::CreateInit() {
	return 0;
}

int Sheet_AncientgodAdvance_s::ResumeInit() {
	return 0;
}

void Sheet_AncientgodAdvance_s::write_to_pbmsg(::proto_ff::Sheet_AncientgodAdvance & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AncientgodAdvance_List.size(); ++i) {
		::proto_ff::E_AncientgodAdvance* temp_e_ancientgodadvance_list = msg.add_e_ancientgodadvance_list();
		E_AncientgodAdvance_List[i].write_to_pbmsg(*temp_e_ancientgodadvance_list);
	}
}

void Sheet_AncientgodAdvance_s::read_from_pbmsg(const ::proto_ff::Sheet_AncientgodAdvance & msg) {
	E_AncientgodAdvance_List.resize((int)msg.e_ancientgodadvance_list_size() > (int)E_AncientgodAdvance_List.max_size() ? E_AncientgodAdvance_List.max_size() : msg.e_ancientgodadvance_list_size());
	for(int32_t i = 0; i < (int32_t)E_AncientgodAdvance_List.size(); ++i) {
		const ::proto_ff::E_AncientgodAdvance & temp_e_ancientgodadvance_list = msg.e_ancientgodadvance_list(i);
		E_AncientgodAdvance_List[i].read_from_pbmsg(temp_e_ancientgodadvance_list);
	}
}

E_AncientgodAttAttributeDesc_s::E_AncientgodAttAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AncientgodAttAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AncientgodAttAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AncientgodAttAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AncientgodAttAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_AncientgodAttAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AncientgodAttAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_AncientgodAtt_s::E_AncientgodAtt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AncientgodAtt_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_AncientgodAtt_s::ResumeInit() {
	return 0;
}

void E_AncientgodAtt_s::write_to_pbmsg(::proto_ff::E_AncientgodAtt & msg) const {
	msg.set_m_id((int32_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_AncientgodAttAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AncientgodAtt_s::read_from_pbmsg(const ::proto_ff::E_AncientgodAtt & msg) {
	m_id = msg.m_id();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_AncientgodAttAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AncientgodAtt_s::Sheet_AncientgodAtt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AncientgodAtt_s::CreateInit() {
	return 0;
}

int Sheet_AncientgodAtt_s::ResumeInit() {
	return 0;
}

void Sheet_AncientgodAtt_s::write_to_pbmsg(::proto_ff::Sheet_AncientgodAtt & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AncientgodAtt_List.size(); ++i) {
		::proto_ff::E_AncientgodAtt* temp_e_ancientgodatt_list = msg.add_e_ancientgodatt_list();
		E_AncientgodAtt_List[i].write_to_pbmsg(*temp_e_ancientgodatt_list);
	}
}

void Sheet_AncientgodAtt_s::read_from_pbmsg(const ::proto_ff::Sheet_AncientgodAtt & msg) {
	E_AncientgodAtt_List.resize((int)msg.e_ancientgodatt_list_size() > (int)E_AncientgodAtt_List.max_size() ? E_AncientgodAtt_List.max_size() : msg.e_ancientgodatt_list_size());
	for(int32_t i = 0; i < (int32_t)E_AncientgodAtt_List.size(); ++i) {
		const ::proto_ff::E_AncientgodAtt & temp_e_ancientgodatt_list = msg.e_ancientgodatt_list(i);
		E_AncientgodAtt_List[i].read_from_pbmsg(temp_e_ancientgodatt_list);
	}
}

E_AncientgodStarcollectAttributeDesc_s::E_AncientgodStarcollectAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AncientgodStarcollectAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AncientgodStarcollectAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AncientgodStarcollectAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AncientgodStarcollectAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_AncientgodStarcollectAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AncientgodStarcollectAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_AncientgodStarcollect_s::E_AncientgodStarcollect_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AncientgodStarcollect_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_AncientgodStarcollect_s::ResumeInit() {
	return 0;
}

void E_AncientgodStarcollect_s::write_to_pbmsg(::proto_ff::E_AncientgodStarcollect & msg) const {
	msg.set_m_id((int32_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_AncientgodStarcollectAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AncientgodStarcollect_s::read_from_pbmsg(const ::proto_ff::E_AncientgodStarcollect & msg) {
	m_id = msg.m_id();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_AncientgodStarcollectAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AncientgodStarcollect_s::Sheet_AncientgodStarcollect_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AncientgodStarcollect_s::CreateInit() {
	return 0;
}

int Sheet_AncientgodStarcollect_s::ResumeInit() {
	return 0;
}

void Sheet_AncientgodStarcollect_s::write_to_pbmsg(::proto_ff::Sheet_AncientgodStarcollect & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AncientgodStarcollect_List.size(); ++i) {
		::proto_ff::E_AncientgodStarcollect* temp_e_ancientgodstarcollect_list = msg.add_e_ancientgodstarcollect_list();
		E_AncientgodStarcollect_List[i].write_to_pbmsg(*temp_e_ancientgodstarcollect_list);
	}
}

void Sheet_AncientgodStarcollect_s::read_from_pbmsg(const ::proto_ff::Sheet_AncientgodStarcollect & msg) {
	E_AncientgodStarcollect_List.resize((int)msg.e_ancientgodstarcollect_list_size() > (int)E_AncientgodStarcollect_List.max_size() ? E_AncientgodStarcollect_List.max_size() : msg.e_ancientgodstarcollect_list_size());
	for(int32_t i = 0; i < (int32_t)E_AncientgodStarcollect_List.size(); ++i) {
		const ::proto_ff::E_AncientgodStarcollect & temp_e_ancientgodstarcollect_list = msg.e_ancientgodstarcollect_list(i);
		E_AncientgodStarcollect_List[i].read_from_pbmsg(temp_e_ancientgodstarcollect_list);
	}
}

}
