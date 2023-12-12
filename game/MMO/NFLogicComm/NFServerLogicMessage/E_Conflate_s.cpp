#include "E_Conflate_s.h"

namespace proto_ff_s {

E_ConflateEquipElemDesc_s::E_ConflateEquipElemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConflateEquipElemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_ConflateEquipElemDesc_s::ResumeInit() {
	return 0;
}

void E_ConflateEquipElemDesc_s::write_to_pbmsg(::proto_ff::E_ConflateEquipElemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_ConflateEquipElemDesc_s::read_from_pbmsg(const ::proto_ff::E_ConflateEquipElemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_ConflateEquip_s::E_ConflateEquip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConflateEquip_s::CreateInit() {
	m_id = (int32_t)0;
	m_openLv = (int32_t)0;
	m_groupType = (int32_t)0;
	m_subType = (int32_t)0;
	m_needsameposition = (int32_t)0;
	m_star = (int32_t)0;
	m_quality = (int32_t)0;
	m_wearQuality = (int32_t)0;
	m_elemStar = (int32_t)0;
	m_elemQuality = (int32_t)0;
	m_elemWearQuality = (int32_t)0;
	m_minimum = (int32_t)0;
	m_minisuccessrate = (int32_t)0;
	m_maxmum = (int32_t)0;
	m_maxsuccessrate = (int32_t)0;
	m_mustStar = (int32_t)0;
	m_mustQuality = (int32_t)0;
	m_mustWearQuality = (int32_t)0;
	m_mustNum = (int32_t)0;
	m_usemoney = (int32_t)0;
	m_cost = (int32_t)0;
	return 0;
}

int E_ConflateEquip_s::ResumeInit() {
	return 0;
}

void E_ConflateEquip_s::write_to_pbmsg(::proto_ff::E_ConflateEquip & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_openlv((int32_t)m_openLv);
	msg.set_m_grouptype((int32_t)m_groupType);
	msg.set_m_subtype((int32_t)m_subType);
	msg.set_m_needsameposition((int32_t)m_needsameposition);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_wearquality((int32_t)m_wearQuality);
	msg.set_m_elemstar((int32_t)m_elemStar);
	msg.set_m_elemquality((int32_t)m_elemQuality);
	msg.set_m_elemwearquality((int32_t)m_elemWearQuality);
	msg.set_m_minimum((int32_t)m_minimum);
	msg.set_m_minisuccessrate((int32_t)m_minisuccessrate);
	msg.set_m_maxmum((int32_t)m_maxmum);
	msg.set_m_maxsuccessrate((int32_t)m_maxsuccessrate);
	msg.set_m_muststar((int32_t)m_mustStar);
	msg.set_m_mustquality((int32_t)m_mustQuality);
	msg.set_m_mustwearquality((int32_t)m_mustWearQuality);
	msg.set_m_mustnum((int32_t)m_mustNum);
	msg.set_m_usemoney((int32_t)m_usemoney);
	msg.set_m_cost((int32_t)m_cost);
	for(int32_t i = 0; i < (int32_t)m_elem.size(); ++i) {
		::proto_ff::E_ConflateEquipElemDesc* temp_m_elem = msg.add_m_elem();
		m_elem[i].write_to_pbmsg(*temp_m_elem);
	}
}

void E_ConflateEquip_s::read_from_pbmsg(const ::proto_ff::E_ConflateEquip & msg) {
	m_id = msg.m_id();
	m_openLv = msg.m_openlv();
	m_groupType = msg.m_grouptype();
	m_subType = msg.m_subtype();
	m_needsameposition = msg.m_needsameposition();
	m_star = msg.m_star();
	m_quality = msg.m_quality();
	m_wearQuality = msg.m_wearquality();
	m_elemStar = msg.m_elemstar();
	m_elemQuality = msg.m_elemquality();
	m_elemWearQuality = msg.m_elemwearquality();
	m_minimum = msg.m_minimum();
	m_minisuccessrate = msg.m_minisuccessrate();
	m_maxmum = msg.m_maxmum();
	m_maxsuccessrate = msg.m_maxsuccessrate();
	m_mustStar = msg.m_muststar();
	m_mustQuality = msg.m_mustquality();
	m_mustWearQuality = msg.m_mustwearquality();
	m_mustNum = msg.m_mustnum();
	m_usemoney = msg.m_usemoney();
	m_cost = msg.m_cost();
	m_elem.resize((int)msg.m_elem_size() > (int)m_elem.max_size() ? m_elem.max_size() : msg.m_elem_size());
	for(int32_t i = 0; i < (int32_t)m_elem.size(); ++i) {
		const ::proto_ff::E_ConflateEquipElemDesc & temp_m_elem = msg.m_elem(i);
		m_elem[i].read_from_pbmsg(temp_m_elem);
	}
}

Sheet_ConflateEquip_s::Sheet_ConflateEquip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ConflateEquip_s::CreateInit() {
	return 0;
}

int Sheet_ConflateEquip_s::ResumeInit() {
	return 0;
}

void Sheet_ConflateEquip_s::write_to_pbmsg(::proto_ff::Sheet_ConflateEquip & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ConflateEquip_List.size(); ++i) {
		::proto_ff::E_ConflateEquip* temp_e_conflateequip_list = msg.add_e_conflateequip_list();
		E_ConflateEquip_List[i].write_to_pbmsg(*temp_e_conflateequip_list);
	}
}

void Sheet_ConflateEquip_s::read_from_pbmsg(const ::proto_ff::Sheet_ConflateEquip & msg) {
	E_ConflateEquip_List.resize((int)msg.e_conflateequip_list_size() > (int)E_ConflateEquip_List.max_size() ? E_ConflateEquip_List.max_size() : msg.e_conflateequip_list_size());
	for(int32_t i = 0; i < (int32_t)E_ConflateEquip_List.size(); ++i) {
		const ::proto_ff::E_ConflateEquip & temp_e_conflateequip_list = msg.e_conflateequip_list(i);
		E_ConflateEquip_List[i].read_from_pbmsg(temp_e_conflateequip_list);
	}
}

E_ConflateGrouptype_s::E_ConflateGrouptype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConflateGrouptype_s::CreateInit() {
	m_id = (int32_t)0;
	m_unlockId = (int32_t)0;
	m_entry = (int32_t)0;
	m_rule = (int32_t)0;
	return 0;
}

int E_ConflateGrouptype_s::ResumeInit() {
	return 0;
}

void E_ConflateGrouptype_s::write_to_pbmsg(::proto_ff::E_ConflateGrouptype & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_position(m_position.data());
	msg.set_m_profession(m_profession.data());
	msg.set_m_typename(m_typeName.data());
	msg.set_m_unlockid((int32_t)m_unlockId);
	msg.set_m_entry((int32_t)m_entry);
	msg.set_m_rule((int32_t)m_rule);
}

void E_ConflateGrouptype_s::read_from_pbmsg(const ::proto_ff::E_ConflateGrouptype & msg) {
	m_id = msg.m_id();
	m_position = msg.m_position();
	m_profession = msg.m_profession();
	m_typeName = msg.m_typename();
	m_unlockId = msg.m_unlockid();
	m_entry = msg.m_entry();
	m_rule = msg.m_rule();
}

Sheet_ConflateGrouptype_s::Sheet_ConflateGrouptype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ConflateGrouptype_s::CreateInit() {
	return 0;
}

int Sheet_ConflateGrouptype_s::ResumeInit() {
	return 0;
}

void Sheet_ConflateGrouptype_s::write_to_pbmsg(::proto_ff::Sheet_ConflateGrouptype & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ConflateGrouptype_List.size(); ++i) {
		::proto_ff::E_ConflateGrouptype* temp_e_conflategrouptype_list = msg.add_e_conflategrouptype_list();
		E_ConflateGrouptype_List[i].write_to_pbmsg(*temp_e_conflategrouptype_list);
	}
}

void Sheet_ConflateGrouptype_s::read_from_pbmsg(const ::proto_ff::Sheet_ConflateGrouptype & msg) {
	E_ConflateGrouptype_List.resize((int)msg.e_conflategrouptype_list_size() > (int)E_ConflateGrouptype_List.max_size() ? E_ConflateGrouptype_List.max_size() : msg.e_conflategrouptype_list_size());
	for(int32_t i = 0; i < (int32_t)E_ConflateGrouptype_List.size(); ++i) {
		const ::proto_ff::E_ConflateGrouptype & temp_e_conflategrouptype_list = msg.e_conflategrouptype_list(i);
		E_ConflateGrouptype_List[i].read_from_pbmsg(temp_e_conflategrouptype_list);
	}
}

E_ConflateSubtype_s::E_ConflateSubtype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConflateSubtype_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupid = (int32_t)0;
	m_openLv = (int32_t)0;
	return 0;
}

int E_ConflateSubtype_s::ResumeInit() {
	return 0;
}

void E_ConflateSubtype_s::write_to_pbmsg(::proto_ff::E_ConflateSubtype & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_subname(m_subName.data());
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_openlv((int32_t)m_openLv);
}

void E_ConflateSubtype_s::read_from_pbmsg(const ::proto_ff::E_ConflateSubtype & msg) {
	m_id = msg.m_id();
	m_subName = msg.m_subname();
	m_groupid = msg.m_groupid();
	m_openLv = msg.m_openlv();
}

Sheet_ConflateSubtype_s::Sheet_ConflateSubtype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ConflateSubtype_s::CreateInit() {
	return 0;
}

int Sheet_ConflateSubtype_s::ResumeInit() {
	return 0;
}

void Sheet_ConflateSubtype_s::write_to_pbmsg(::proto_ff::Sheet_ConflateSubtype & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ConflateSubtype_List.size(); ++i) {
		::proto_ff::E_ConflateSubtype* temp_e_conflatesubtype_list = msg.add_e_conflatesubtype_list();
		E_ConflateSubtype_List[i].write_to_pbmsg(*temp_e_conflatesubtype_list);
	}
}

void Sheet_ConflateSubtype_s::read_from_pbmsg(const ::proto_ff::Sheet_ConflateSubtype & msg) {
	E_ConflateSubtype_List.resize((int)msg.e_conflatesubtype_list_size() > (int)E_ConflateSubtype_List.max_size() ? E_ConflateSubtype_List.max_size() : msg.e_conflatesubtype_list_size());
	for(int32_t i = 0; i < (int32_t)E_ConflateSubtype_List.size(); ++i) {
		const ::proto_ff::E_ConflateSubtype & temp_e_conflatesubtype_list = msg.e_conflatesubtype_list(i);
		E_ConflateSubtype_List[i].read_from_pbmsg(temp_e_conflatesubtype_list);
	}
}

E_ConflatePropReplaceDesc_s::E_ConflatePropReplaceDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConflatePropReplaceDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_ConflatePropReplaceDesc_s::ResumeInit() {
	return 0;
}

void E_ConflatePropReplaceDesc_s::write_to_pbmsg(::proto_ff::E_ConflatePropReplaceDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int32_t)m_id);
}

void E_ConflatePropReplaceDesc_s::read_from_pbmsg(const ::proto_ff::E_ConflatePropReplaceDesc & msg) {
	m_Num = msg.m_num();
	m_id = msg.m_id();
}

E_ConflatePropElemDesc_s::E_ConflatePropElemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConflatePropElemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_ConflatePropElemDesc_s::ResumeInit() {
	return 0;
}

void E_ConflatePropElemDesc_s::write_to_pbmsg(::proto_ff::E_ConflatePropElemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_ConflatePropElemDesc_s::read_from_pbmsg(const ::proto_ff::E_ConflatePropElemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_ConflateProp_s::E_ConflateProp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConflateProp_s::CreateInit() {
	m_target = (int32_t)0;
	m_openLv = (int32_t)0;
	m_subType = (int32_t)0;
	m_order = (int32_t)0;
	m_activate = (int32_t)0;
	m_display = (int32_t)0;
	m_replaceType = (int32_t)0;
	m_culture = (int32_t)0;
	m_usemoney = (int32_t)0;
	m_cost = (int32_t)0;
	return 0;
}

int E_ConflateProp_s::ResumeInit() {
	return 0;
}

void E_ConflateProp_s::write_to_pbmsg(::proto_ff::E_ConflateProp & msg) const {
	msg.set_m_target((int32_t)m_target);
	msg.set_m_openlv((int32_t)m_openLv);
	msg.set_m_subtype((int32_t)m_subType);
	msg.set_m_order((int32_t)m_order);
	msg.set_m_activate((int32_t)m_activate);
	msg.set_m_display((int32_t)m_display);
	msg.set_m_replacetype((int32_t)m_replaceType);
	msg.set_m_culture((int32_t)m_culture);
	msg.set_m_usemoney((int32_t)m_usemoney);
	msg.set_m_cost((int32_t)m_cost);
	for(int32_t i = 0; i < (int32_t)m_replace.size(); ++i) {
		::proto_ff::E_ConflatePropReplaceDesc* temp_m_replace = msg.add_m_replace();
		m_replace[i].write_to_pbmsg(*temp_m_replace);
	}
	for(int32_t i = 0; i < (int32_t)m_elem.size(); ++i) {
		::proto_ff::E_ConflatePropElemDesc* temp_m_elem = msg.add_m_elem();
		m_elem[i].write_to_pbmsg(*temp_m_elem);
	}
}

void E_ConflateProp_s::read_from_pbmsg(const ::proto_ff::E_ConflateProp & msg) {
	m_target = msg.m_target();
	m_openLv = msg.m_openlv();
	m_subType = msg.m_subtype();
	m_order = msg.m_order();
	m_activate = msg.m_activate();
	m_display = msg.m_display();
	m_replaceType = msg.m_replacetype();
	m_culture = msg.m_culture();
	m_usemoney = msg.m_usemoney();
	m_cost = msg.m_cost();
	m_replace.resize((int)msg.m_replace_size() > (int)m_replace.max_size() ? m_replace.max_size() : msg.m_replace_size());
	for(int32_t i = 0; i < (int32_t)m_replace.size(); ++i) {
		const ::proto_ff::E_ConflatePropReplaceDesc & temp_m_replace = msg.m_replace(i);
		m_replace[i].read_from_pbmsg(temp_m_replace);
	}
	m_elem.resize((int)msg.m_elem_size() > (int)m_elem.max_size() ? m_elem.max_size() : msg.m_elem_size());
	for(int32_t i = 0; i < (int32_t)m_elem.size(); ++i) {
		const ::proto_ff::E_ConflatePropElemDesc & temp_m_elem = msg.m_elem(i);
		m_elem[i].read_from_pbmsg(temp_m_elem);
	}
}

Sheet_ConflateProp_s::Sheet_ConflateProp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ConflateProp_s::CreateInit() {
	return 0;
}

int Sheet_ConflateProp_s::ResumeInit() {
	return 0;
}

void Sheet_ConflateProp_s::write_to_pbmsg(::proto_ff::Sheet_ConflateProp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ConflateProp_List.size(); ++i) {
		::proto_ff::E_ConflateProp* temp_e_conflateprop_list = msg.add_e_conflateprop_list();
		E_ConflateProp_List[i].write_to_pbmsg(*temp_e_conflateprop_list);
	}
}

void Sheet_ConflateProp_s::read_from_pbmsg(const ::proto_ff::Sheet_ConflateProp & msg) {
	E_ConflateProp_List.resize((int)msg.e_conflateprop_list_size() > (int)E_ConflateProp_List.max_size() ? E_ConflateProp_List.max_size() : msg.e_conflateprop_list_size());
	for(int32_t i = 0; i < (int32_t)E_ConflateProp_List.size(); ++i) {
		const ::proto_ff::E_ConflateProp & temp_e_conflateprop_list = msg.e_conflateprop_list(i);
		E_ConflateProp_List[i].read_from_pbmsg(temp_e_conflateprop_list);
	}
}

E_ConflateJewelry_spElemDesc_s::E_ConflateJewelry_spElemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConflateJewelry_spElemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_ConflateJewelry_spElemDesc_s::ResumeInit() {
	return 0;
}

void E_ConflateJewelry_spElemDesc_s::write_to_pbmsg(::proto_ff::E_ConflateJewelry_spElemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_ConflateJewelry_spElemDesc_s::read_from_pbmsg(const ::proto_ff::E_ConflateJewelry_spElemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_ConflateJewelry_sp_s::E_ConflateJewelry_sp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConflateJewelry_sp_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupType = (int32_t)0;
	m_openwearQuality = (int32_t)0;
	m_openspecial = (int32_t)0;
	m_position = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	m_next = (int32_t)0;
	return 0;
}

int E_ConflateJewelry_sp_s::ResumeInit() {
	return 0;
}

void E_ConflateJewelry_sp_s::write_to_pbmsg(::proto_ff::E_ConflateJewelry_sp & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_grouptype((int32_t)m_groupType);
	msg.set_m_openwearquality((int32_t)m_openwearQuality);
	msg.set_m_openspecial((int32_t)m_openspecial);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_next((int32_t)m_next);
	for(int32_t i = 0; i < (int32_t)m_elem.size(); ++i) {
		::proto_ff::E_ConflateJewelry_spElemDesc* temp_m_elem = msg.add_m_elem();
		m_elem[i].write_to_pbmsg(*temp_m_elem);
	}
}

void E_ConflateJewelry_sp_s::read_from_pbmsg(const ::proto_ff::E_ConflateJewelry_sp & msg) {
	m_id = msg.m_id();
	m_groupType = msg.m_grouptype();
	m_openwearQuality = msg.m_openwearquality();
	m_openspecial = msg.m_openspecial();
	m_position = msg.m_position();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_next = msg.m_next();
	m_elem.resize((int)msg.m_elem_size() > (int)m_elem.max_size() ? m_elem.max_size() : msg.m_elem_size());
	for(int32_t i = 0; i < (int32_t)m_elem.size(); ++i) {
		const ::proto_ff::E_ConflateJewelry_spElemDesc & temp_m_elem = msg.m_elem(i);
		m_elem[i].read_from_pbmsg(temp_m_elem);
	}
}

Sheet_ConflateJewelry_sp_s::Sheet_ConflateJewelry_sp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ConflateJewelry_sp_s::CreateInit() {
	return 0;
}

int Sheet_ConflateJewelry_sp_s::ResumeInit() {
	return 0;
}

void Sheet_ConflateJewelry_sp_s::write_to_pbmsg(::proto_ff::Sheet_ConflateJewelry_sp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ConflateJewelry_sp_List.size(); ++i) {
		::proto_ff::E_ConflateJewelry_sp* temp_e_conflatejewelry_sp_list = msg.add_e_conflatejewelry_sp_list();
		E_ConflateJewelry_sp_List[i].write_to_pbmsg(*temp_e_conflatejewelry_sp_list);
	}
}

void Sheet_ConflateJewelry_sp_s::read_from_pbmsg(const ::proto_ff::Sheet_ConflateJewelry_sp & msg) {
	E_ConflateJewelry_sp_List.resize((int)msg.e_conflatejewelry_sp_list_size() > (int)E_ConflateJewelry_sp_List.max_size() ? E_ConflateJewelry_sp_List.max_size() : msg.e_conflatejewelry_sp_list_size());
	for(int32_t i = 0; i < (int32_t)E_ConflateJewelry_sp_List.size(); ++i) {
		const ::proto_ff::E_ConflateJewelry_sp & temp_e_conflatejewelry_sp_list = msg.e_conflatejewelry_sp_list(i);
		E_ConflateJewelry_sp_List[i].read_from_pbmsg(temp_e_conflatejewelry_sp_list);
	}
}

E_ConflateJewelry_zlElemDesc_s::E_ConflateJewelry_zlElemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConflateJewelry_zlElemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_ConflateJewelry_zlElemDesc_s::ResumeInit() {
	return 0;
}

void E_ConflateJewelry_zlElemDesc_s::write_to_pbmsg(::proto_ff::E_ConflateJewelry_zlElemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_ConflateJewelry_zlElemDesc_s::read_from_pbmsg(const ::proto_ff::E_ConflateJewelry_zlElemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_ConflateJewelry_zl_s::E_ConflateJewelry_zl_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConflateJewelry_zl_s::CreateInit() {
	m_id = (int32_t)0;
	m_openquality = (int32_t)0;
	m_groupType = (int32_t)0;
	m_position = (int32_t)0;
	m_Zllv = (int32_t)0;
	m_next = (int32_t)0;
	return 0;
}

int E_ConflateJewelry_zl_s::ResumeInit() {
	return 0;
}

void E_ConflateJewelry_zl_s::write_to_pbmsg(::proto_ff::E_ConflateJewelry_zl & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_openquality((int32_t)m_openquality);
	msg.set_m_grouptype((int32_t)m_groupType);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_zllv((int32_t)m_Zllv);
	msg.set_m_next((int32_t)m_next);
	msg.set_m_zlname(m_Zlname.data());
	for(int32_t i = 0; i < (int32_t)m_elem.size(); ++i) {
		::proto_ff::E_ConflateJewelry_zlElemDesc* temp_m_elem = msg.add_m_elem();
		m_elem[i].write_to_pbmsg(*temp_m_elem);
	}
}

void E_ConflateJewelry_zl_s::read_from_pbmsg(const ::proto_ff::E_ConflateJewelry_zl & msg) {
	m_id = msg.m_id();
	m_openquality = msg.m_openquality();
	m_groupType = msg.m_grouptype();
	m_position = msg.m_position();
	m_Zllv = msg.m_zllv();
	m_next = msg.m_next();
	m_Zlname = msg.m_zlname();
	m_elem.resize((int)msg.m_elem_size() > (int)m_elem.max_size() ? m_elem.max_size() : msg.m_elem_size());
	for(int32_t i = 0; i < (int32_t)m_elem.size(); ++i) {
		const ::proto_ff::E_ConflateJewelry_zlElemDesc & temp_m_elem = msg.m_elem(i);
		m_elem[i].read_from_pbmsg(temp_m_elem);
	}
}

Sheet_ConflateJewelry_zl_s::Sheet_ConflateJewelry_zl_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ConflateJewelry_zl_s::CreateInit() {
	return 0;
}

int Sheet_ConflateJewelry_zl_s::ResumeInit() {
	return 0;
}

void Sheet_ConflateJewelry_zl_s::write_to_pbmsg(::proto_ff::Sheet_ConflateJewelry_zl & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ConflateJewelry_zl_List.size(); ++i) {
		::proto_ff::E_ConflateJewelry_zl* temp_e_conflatejewelry_zl_list = msg.add_e_conflatejewelry_zl_list();
		E_ConflateJewelry_zl_List[i].write_to_pbmsg(*temp_e_conflatejewelry_zl_list);
	}
}

void Sheet_ConflateJewelry_zl_s::read_from_pbmsg(const ::proto_ff::Sheet_ConflateJewelry_zl & msg) {
	E_ConflateJewelry_zl_List.resize((int)msg.e_conflatejewelry_zl_list_size() > (int)E_ConflateJewelry_zl_List.max_size() ? E_ConflateJewelry_zl_List.max_size() : msg.e_conflatejewelry_zl_list_size());
	for(int32_t i = 0; i < (int32_t)E_ConflateJewelry_zl_List.size(); ++i) {
		const ::proto_ff::E_ConflateJewelry_zl & temp_e_conflatejewelry_zl_list = msg.e_conflatejewelry_zl_list(i);
		E_ConflateJewelry_zl_List[i].read_from_pbmsg(temp_e_conflatejewelry_zl_list);
	}
}

E_ConflateJewelry_sjElemDesc_s::E_ConflateJewelry_sjElemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConflateJewelry_sjElemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_ConflateJewelry_sjElemDesc_s::ResumeInit() {
	return 0;
}

void E_ConflateJewelry_sjElemDesc_s::write_to_pbmsg(::proto_ff::E_ConflateJewelry_sjElemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_ConflateJewelry_sjElemDesc_s::read_from_pbmsg(const ::proto_ff::E_ConflateJewelry_sjElemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_ConflateJewelry_sj_s::E_ConflateJewelry_sj_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConflateJewelry_sj_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupType = (int32_t)0;
	m_position = (int32_t)0;
	m_wearQuality = (int32_t)0;
	m_next = (int32_t)0;
	m_openLv = (int32_t)0;
	return 0;
}

int E_ConflateJewelry_sj_s::ResumeInit() {
	return 0;
}

void E_ConflateJewelry_sj_s::write_to_pbmsg(::proto_ff::E_ConflateJewelry_sj & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_grouptype((int32_t)m_groupType);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_wearquality((int32_t)m_wearQuality);
	msg.set_m_next((int32_t)m_next);
	msg.set_m_openlv((int32_t)m_openLv);
	for(int32_t i = 0; i < (int32_t)m_elem.size(); ++i) {
		::proto_ff::E_ConflateJewelry_sjElemDesc* temp_m_elem = msg.add_m_elem();
		m_elem[i].write_to_pbmsg(*temp_m_elem);
	}
}

void E_ConflateJewelry_sj_s::read_from_pbmsg(const ::proto_ff::E_ConflateJewelry_sj & msg) {
	m_id = msg.m_id();
	m_groupType = msg.m_grouptype();
	m_position = msg.m_position();
	m_wearQuality = msg.m_wearquality();
	m_next = msg.m_next();
	m_openLv = msg.m_openlv();
	m_elem.resize((int)msg.m_elem_size() > (int)m_elem.max_size() ? m_elem.max_size() : msg.m_elem_size());
	for(int32_t i = 0; i < (int32_t)m_elem.size(); ++i) {
		const ::proto_ff::E_ConflateJewelry_sjElemDesc & temp_m_elem = msg.m_elem(i);
		m_elem[i].read_from_pbmsg(temp_m_elem);
	}
}

Sheet_ConflateJewelry_sj_s::Sheet_ConflateJewelry_sj_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ConflateJewelry_sj_s::CreateInit() {
	return 0;
}

int Sheet_ConflateJewelry_sj_s::ResumeInit() {
	return 0;
}

void Sheet_ConflateJewelry_sj_s::write_to_pbmsg(::proto_ff::Sheet_ConflateJewelry_sj & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ConflateJewelry_sj_List.size(); ++i) {
		::proto_ff::E_ConflateJewelry_sj* temp_e_conflatejewelry_sj_list = msg.add_e_conflatejewelry_sj_list();
		E_ConflateJewelry_sj_List[i].write_to_pbmsg(*temp_e_conflatejewelry_sj_list);
	}
}

void Sheet_ConflateJewelry_sj_s::read_from_pbmsg(const ::proto_ff::Sheet_ConflateJewelry_sj & msg) {
	E_ConflateJewelry_sj_List.resize((int)msg.e_conflatejewelry_sj_list_size() > (int)E_ConflateJewelry_sj_List.max_size() ? E_ConflateJewelry_sj_List.max_size() : msg.e_conflatejewelry_sj_list_size());
	for(int32_t i = 0; i < (int32_t)E_ConflateJewelry_sj_List.size(); ++i) {
		const ::proto_ff::E_ConflateJewelry_sj & temp_e_conflatejewelry_sj_list = msg.e_conflatejewelry_sj_list(i);
		E_ConflateJewelry_sj_List[i].read_from_pbmsg(temp_e_conflatejewelry_sj_list);
	}
}

}
