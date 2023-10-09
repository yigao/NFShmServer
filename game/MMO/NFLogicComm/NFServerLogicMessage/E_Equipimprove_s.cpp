#include "E_Equipimprove_s.h"

namespace proto_ff_s {

E_EquipimproveUpqualityMaterialDesc_s::E_EquipimproveUpqualityMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipimproveUpqualityMaterialDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_EquipimproveUpqualityMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_EquipimproveUpqualityMaterialDesc_s::write_to_pbmsg(::proto_ff::E_EquipimproveUpqualityMaterialDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_EquipimproveUpqualityMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipimproveUpqualityMaterialDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_EquipimproveUpqualityAttributeDesc_s::E_EquipimproveUpqualityAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipimproveUpqualityAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EquipimproveUpqualityAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_EquipimproveUpqualityAttributeDesc_s::write_to_pbmsg(::proto_ff::E_EquipimproveUpqualityAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_EquipimproveUpqualityAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipimproveUpqualityAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_EquipimproveUpquality_s::E_EquipimproveUpquality_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipimproveUpquality_s::CreateInit() {
	m_id = (int32_t)0;
	m_quality = (int32_t)0;
	m_wearqualitylimit = (int32_t)0;
	m_star = (int32_t)0;
	m_starnum = (int32_t)0;
	m_success = (int32_t)0;
	m_luckid = (int32_t)0;
	m_lucksuccess = (int32_t)0;
	m_lucknum = (int32_t)0;
	m_qualityatt = (int32_t)0;
	m_qualityvalue = (int32_t)0;
	return 0;
}

int E_EquipimproveUpquality_s::ResumeInit() {
	return 0;
}

void E_EquipimproveUpquality_s::write_to_pbmsg(::proto_ff::E_EquipimproveUpquality & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_position(m_position.data());
	msg.set_m_wearqualitylimit((int32_t)m_wearqualitylimit);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_starnum((int32_t)m_starnum);
	msg.set_m_success((int32_t)m_success);
	msg.set_m_luckid((int32_t)m_luckid);
	msg.set_m_lucksuccess((int32_t)m_lucksuccess);
	msg.set_m_lucknum((int32_t)m_lucknum);
	msg.set_m_qualityatt((int32_t)m_qualityatt);
	msg.set_m_qualityvalue((int32_t)m_qualityvalue);
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_EquipimproveUpqualityMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_EquipimproveUpqualityAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_EquipimproveUpquality_s::read_from_pbmsg(const ::proto_ff::E_EquipimproveUpquality & msg) {
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_position = msg.m_position();
	m_wearqualitylimit = msg.m_wearqualitylimit();
	m_star = msg.m_star();
	m_starnum = msg.m_starnum();
	m_success = msg.m_success();
	m_luckid = msg.m_luckid();
	m_lucksuccess = msg.m_lucksuccess();
	m_lucknum = msg.m_lucknum();
	m_qualityatt = msg.m_qualityatt();
	m_qualityvalue = msg.m_qualityvalue();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_EquipimproveUpqualityMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_EquipimproveUpqualityAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_EquipimproveUpquality_s::Sheet_EquipimproveUpquality_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipimproveUpquality_s::CreateInit() {
	return 0;
}

int Sheet_EquipimproveUpquality_s::ResumeInit() {
	return 0;
}

void Sheet_EquipimproveUpquality_s::write_to_pbmsg(::proto_ff::Sheet_EquipimproveUpquality & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipimproveUpquality_List.size(); ++i) {
		::proto_ff::E_EquipimproveUpquality* temp_e_equipimproveupquality_list = msg.add_e_equipimproveupquality_list();
		E_EquipimproveUpquality_List[i].write_to_pbmsg(*temp_e_equipimproveupquality_list);
	}
}

void Sheet_EquipimproveUpquality_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipimproveUpquality & msg) {
	E_EquipimproveUpquality_List.resize((int)msg.e_equipimproveupquality_list_size() > (int)E_EquipimproveUpquality_List.max_size() ? E_EquipimproveUpquality_List.max_size() : msg.e_equipimproveupquality_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipimproveUpquality_List.size(); ++i) {
		const ::proto_ff::E_EquipimproveUpquality & temp_e_equipimproveupquality_list = msg.e_equipimproveupquality_list(i);
		E_EquipimproveUpquality_List[i].read_from_pbmsg(temp_e_equipimproveupquality_list);
	}
}

E_EquipimproveAwakenAttributeDesc_s::E_EquipimproveAwakenAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipimproveAwakenAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EquipimproveAwakenAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_EquipimproveAwakenAttributeDesc_s::write_to_pbmsg(::proto_ff::E_EquipimproveAwakenAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_EquipimproveAwakenAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipimproveAwakenAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_EquipimproveAwakenBreakDesc_s::E_EquipimproveAwakenBreakDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipimproveAwakenBreakDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EquipimproveAwakenBreakDesc_s::ResumeInit() {
	return 0;
}

void E_EquipimproveAwakenBreakDesc_s::write_to_pbmsg(::proto_ff::E_EquipimproveAwakenBreakDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_EquipimproveAwakenBreakDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipimproveAwakenBreakDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_EquipimproveAwaken_s::E_EquipimproveAwaken_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipimproveAwaken_s::CreateInit() {
	m_id = (int32_t)0;
	m_quality = (int32_t)0;
	m_wearqualitylimit = (int32_t)0;
	m_qualitylimit = (int32_t)0;
	m_wearstarlimit = (int32_t)0;
	m_awakenlv = (int32_t)0;
	m_material_id = (int32_t)0;
	m_material_num = (int32_t)0;
	m_break_id = (int32_t)0;
	m_break_num = (int32_t)0;
	return 0;
}

int E_EquipimproveAwaken_s::ResumeInit() {
	return 0;
}

void E_EquipimproveAwaken_s::write_to_pbmsg(::proto_ff::E_EquipimproveAwaken & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_position(m_position.data());
	msg.set_m_wearqualitylimit((int32_t)m_wearqualitylimit);
	msg.set_m_qualitylimit((int32_t)m_qualitylimit);
	msg.set_m_wearstarlimit((int32_t)m_wearstarlimit);
	msg.set_m_awakenlv((int32_t)m_awakenlv);
	msg.set_m_material_id((int32_t)m_material_id);
	msg.set_m_material_num((int32_t)m_material_num);
	msg.set_m_break_id((int32_t)m_break_id);
	msg.set_m_break_num((int32_t)m_break_num);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_EquipimproveAwakenAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_break.size(); ++i) {
		::proto_ff::E_EquipimproveAwakenBreakDesc* temp_m_break = msg.add_m_break();
		m_break[i].write_to_pbmsg(*temp_m_break);
	}
}

void E_EquipimproveAwaken_s::read_from_pbmsg(const ::proto_ff::E_EquipimproveAwaken & msg) {
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_position = msg.m_position();
	m_wearqualitylimit = msg.m_wearqualitylimit();
	m_qualitylimit = msg.m_qualitylimit();
	m_wearstarlimit = msg.m_wearstarlimit();
	m_awakenlv = msg.m_awakenlv();
	m_material_id = msg.m_material_id();
	m_material_num = msg.m_material_num();
	m_break_id = msg.m_break_id();
	m_break_num = msg.m_break_num();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_EquipimproveAwakenAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_break.resize((int)msg.m_break_size() > (int)m_break.max_size() ? m_break.max_size() : msg.m_break_size());
	for(int32_t i = 0; i < (int32_t)m_break.size(); ++i) {
		const ::proto_ff::E_EquipimproveAwakenBreakDesc & temp_m_break = msg.m_break(i);
		m_break[i].read_from_pbmsg(temp_m_break);
	}
}

Sheet_EquipimproveAwaken_s::Sheet_EquipimproveAwaken_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipimproveAwaken_s::CreateInit() {
	return 0;
}

int Sheet_EquipimproveAwaken_s::ResumeInit() {
	return 0;
}

void Sheet_EquipimproveAwaken_s::write_to_pbmsg(::proto_ff::Sheet_EquipimproveAwaken & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipimproveAwaken_List.size(); ++i) {
		::proto_ff::E_EquipimproveAwaken* temp_e_equipimproveawaken_list = msg.add_e_equipimproveawaken_list();
		E_EquipimproveAwaken_List[i].write_to_pbmsg(*temp_e_equipimproveawaken_list);
	}
}

void Sheet_EquipimproveAwaken_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipimproveAwaken & msg) {
	E_EquipimproveAwaken_List.resize((int)msg.e_equipimproveawaken_list_size() > (int)E_EquipimproveAwaken_List.max_size() ? E_EquipimproveAwaken_List.max_size() : msg.e_equipimproveawaken_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipimproveAwaken_List.size(); ++i) {
		const ::proto_ff::E_EquipimproveAwaken & temp_e_equipimproveawaken_list = msg.e_equipimproveawaken_list(i);
		E_EquipimproveAwaken_List[i].read_from_pbmsg(temp_e_equipimproveawaken_list);
	}
}

E_EquipimproveSoaringAttrDesc_s::E_EquipimproveSoaringAttrDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipimproveSoaringAttrDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EquipimproveSoaringAttrDesc_s::ResumeInit() {
	return 0;
}

void E_EquipimproveSoaringAttrDesc_s::write_to_pbmsg(::proto_ff::E_EquipimproveSoaringAttrDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_EquipimproveSoaringAttrDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipimproveSoaringAttrDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_EquipimproveSoaring_s::E_EquipimproveSoaring_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipimproveSoaring_s::CreateInit() {
	m_id = (int32_t)0;
	m_lvid = (int32_t)0;
	m_awaken = (int32_t)0;
	m_itemid = (int32_t)0;
	m_itemnum = (int32_t)0;
	return 0;
}

int E_EquipimproveSoaring_s::ResumeInit() {
	return 0;
}

void E_EquipimproveSoaring_s::write_to_pbmsg(::proto_ff::E_EquipimproveSoaring & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lvid((int32_t)m_lvid);
	msg.set_m_awaken((int32_t)m_awaken);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_itemnum((int32_t)m_itemnum);
	msg.set_m_position(m_position.data());
	for(int32_t i = 0; i < (int32_t)m_attr.size(); ++i) {
		::proto_ff::E_EquipimproveSoaringAttrDesc* temp_m_attr = msg.add_m_attr();
		m_attr[i].write_to_pbmsg(*temp_m_attr);
	}
}

void E_EquipimproveSoaring_s::read_from_pbmsg(const ::proto_ff::E_EquipimproveSoaring & msg) {
	m_id = msg.m_id();
	m_lvid = msg.m_lvid();
	m_awaken = msg.m_awaken();
	m_itemid = msg.m_itemid();
	m_itemnum = msg.m_itemnum();
	m_position = msg.m_position();
	m_attr.resize((int)msg.m_attr_size() > (int)m_attr.max_size() ? m_attr.max_size() : msg.m_attr_size());
	for(int32_t i = 0; i < (int32_t)m_attr.size(); ++i) {
		const ::proto_ff::E_EquipimproveSoaringAttrDesc & temp_m_attr = msg.m_attr(i);
		m_attr[i].read_from_pbmsg(temp_m_attr);
	}
}

Sheet_EquipimproveSoaring_s::Sheet_EquipimproveSoaring_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipimproveSoaring_s::CreateInit() {
	return 0;
}

int Sheet_EquipimproveSoaring_s::ResumeInit() {
	return 0;
}

void Sheet_EquipimproveSoaring_s::write_to_pbmsg(::proto_ff::Sheet_EquipimproveSoaring & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipimproveSoaring_List.size(); ++i) {
		::proto_ff::E_EquipimproveSoaring* temp_e_equipimprovesoaring_list = msg.add_e_equipimprovesoaring_list();
		E_EquipimproveSoaring_List[i].write_to_pbmsg(*temp_e_equipimprovesoaring_list);
	}
}

void Sheet_EquipimproveSoaring_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipimproveSoaring & msg) {
	E_EquipimproveSoaring_List.resize((int)msg.e_equipimprovesoaring_list_size() > (int)E_EquipimproveSoaring_List.max_size() ? E_EquipimproveSoaring_List.max_size() : msg.e_equipimprovesoaring_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipimproveSoaring_List.size(); ++i) {
		const ::proto_ff::E_EquipimproveSoaring & temp_e_equipimprovesoaring_list = msg.e_equipimprovesoaring_list(i);
		E_EquipimproveSoaring_List[i].read_from_pbmsg(temp_e_equipimprovesoaring_list);
	}
}

E_EquipimproveSealSealDesc_s::E_EquipimproveSealSealDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipimproveSealSealDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EquipimproveSealSealDesc_s::ResumeInit() {
	return 0;
}

void E_EquipimproveSealSealDesc_s::write_to_pbmsg(::proto_ff::E_EquipimproveSealSealDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_EquipimproveSealSealDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipimproveSealSealDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_EquipimproveSeal_s::E_EquipimproveSeal_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipimproveSeal_s::CreateInit() {
	m_id = (int32_t)0;
	m_seallv = (int32_t)0;
	m_preid = (int32_t)0;
	m_nextid = (int32_t)0;
	m_nextvalue = (int32_t)0;
	return 0;
}

int E_EquipimproveSeal_s::ResumeInit() {
	return 0;
}

void E_EquipimproveSeal_s::write_to_pbmsg(::proto_ff::E_EquipimproveSeal & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_sealposition(m_sealposition.data());
	msg.set_m_seallv((int32_t)m_seallv);
	msg.set_m_preid((int32_t)m_preid);
	msg.set_m_nextid((int32_t)m_nextid);
	msg.set_m_numb(m_numb.data());
	msg.set_m_nextvalue((int32_t)m_nextvalue);
	for(int32_t i = 0; i < (int32_t)m_seal.size(); ++i) {
		::proto_ff::E_EquipimproveSealSealDesc* temp_m_seal = msg.add_m_seal();
		m_seal[i].write_to_pbmsg(*temp_m_seal);
	}
}

void E_EquipimproveSeal_s::read_from_pbmsg(const ::proto_ff::E_EquipimproveSeal & msg) {
	m_id = msg.m_id();
	m_sealposition = msg.m_sealposition();
	m_seallv = msg.m_seallv();
	m_preid = msg.m_preid();
	m_nextid = msg.m_nextid();
	m_numb = msg.m_numb();
	m_nextvalue = msg.m_nextvalue();
	m_seal.resize((int)msg.m_seal_size() > (int)m_seal.max_size() ? m_seal.max_size() : msg.m_seal_size());
	for(int32_t i = 0; i < (int32_t)m_seal.size(); ++i) {
		const ::proto_ff::E_EquipimproveSealSealDesc & temp_m_seal = msg.m_seal(i);
		m_seal[i].read_from_pbmsg(temp_m_seal);
	}
}

Sheet_EquipimproveSeal_s::Sheet_EquipimproveSeal_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipimproveSeal_s::CreateInit() {
	return 0;
}

int Sheet_EquipimproveSeal_s::ResumeInit() {
	return 0;
}

void Sheet_EquipimproveSeal_s::write_to_pbmsg(::proto_ff::Sheet_EquipimproveSeal & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipimproveSeal_List.size(); ++i) {
		::proto_ff::E_EquipimproveSeal* temp_e_equipimproveseal_list = msg.add_e_equipimproveseal_list();
		E_EquipimproveSeal_List[i].write_to_pbmsg(*temp_e_equipimproveseal_list);
	}
}

void Sheet_EquipimproveSeal_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipimproveSeal & msg) {
	E_EquipimproveSeal_List.resize((int)msg.e_equipimproveseal_list_size() > (int)E_EquipimproveSeal_List.max_size() ? E_EquipimproveSeal_List.max_size() : msg.e_equipimproveseal_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipimproveSeal_List.size(); ++i) {
		const ::proto_ff::E_EquipimproveSeal & temp_e_equipimproveseal_list = msg.e_equipimproveseal_list(i);
		E_EquipimproveSeal_List[i].read_from_pbmsg(temp_e_equipimproveseal_list);
	}
}

E_EquipimproveSealslot_s::E_EquipimproveSealslot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipimproveSealslot_s::CreateInit() {
	m_id = (int32_t)0;
	m_quality = (int32_t)0;
	m_character = (int32_t)0;
	m_star = (int32_t)0;
	return 0;
}

int E_EquipimproveSealslot_s::ResumeInit() {
	return 0;
}

void E_EquipimproveSealslot_s::write_to_pbmsg(::proto_ff::E_EquipimproveSealslot & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_character((int32_t)m_character);
	msg.set_m_star((int32_t)m_star);
}

void E_EquipimproveSealslot_s::read_from_pbmsg(const ::proto_ff::E_EquipimproveSealslot & msg) {
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_character = msg.m_character();
	m_star = msg.m_star();
}

Sheet_EquipimproveSealslot_s::Sheet_EquipimproveSealslot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipimproveSealslot_s::CreateInit() {
	return 0;
}

int Sheet_EquipimproveSealslot_s::ResumeInit() {
	return 0;
}

void Sheet_EquipimproveSealslot_s::write_to_pbmsg(::proto_ff::Sheet_EquipimproveSealslot & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipimproveSealslot_List.size(); ++i) {
		::proto_ff::E_EquipimproveSealslot* temp_e_equipimprovesealslot_list = msg.add_e_equipimprovesealslot_list();
		E_EquipimproveSealslot_List[i].write_to_pbmsg(*temp_e_equipimprovesealslot_list);
	}
}

void Sheet_EquipimproveSealslot_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipimproveSealslot & msg) {
	E_EquipimproveSealslot_List.resize((int)msg.e_equipimprovesealslot_list_size() > (int)E_EquipimproveSealslot_List.max_size() ? E_EquipimproveSealslot_List.max_size() : msg.e_equipimprovesealslot_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipimproveSealslot_List.size(); ++i) {
		const ::proto_ff::E_EquipimproveSealslot & temp_e_equipimprovesealslot_list = msg.e_equipimprovesealslot_list(i);
		E_EquipimproveSealslot_List[i].read_from_pbmsg(temp_e_equipimprovesealslot_list);
	}
}

E_EquipimproveSealsuitSuitDesc_s::E_EquipimproveSealsuitSuitDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipimproveSealsuitSuitDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EquipimproveSealsuitSuitDesc_s::ResumeInit() {
	return 0;
}

void E_EquipimproveSealsuitSuitDesc_s::write_to_pbmsg(::proto_ff::E_EquipimproveSealsuitSuitDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_EquipimproveSealsuitSuitDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipimproveSealsuitSuitDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_EquipimproveSealsuit_s::E_EquipimproveSealsuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipimproveSealsuit_s::CreateInit() {
	m_id = (int32_t)0;
	m_wearnum = (int32_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_EquipimproveSealsuit_s::ResumeInit() {
	return 0;
}

void E_EquipimproveSealsuit_s::write_to_pbmsg(::proto_ff::E_EquipimproveSealsuit & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_wearnum((int32_t)m_wearnum);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_position(m_position.data());
	for(int32_t i = 0; i < (int32_t)m_suit.size(); ++i) {
		::proto_ff::E_EquipimproveSealsuitSuitDesc* temp_m_suit = msg.add_m_suit();
		m_suit[i].write_to_pbmsg(*temp_m_suit);
	}
}

void E_EquipimproveSealsuit_s::read_from_pbmsg(const ::proto_ff::E_EquipimproveSealsuit & msg) {
	m_id = msg.m_id();
	m_wearnum = msg.m_wearnum();
	m_quality = msg.m_quality();
	m_position = msg.m_position();
	m_suit.resize((int)msg.m_suit_size() > (int)m_suit.max_size() ? m_suit.max_size() : msg.m_suit_size());
	for(int32_t i = 0; i < (int32_t)m_suit.size(); ++i) {
		const ::proto_ff::E_EquipimproveSealsuitSuitDesc & temp_m_suit = msg.m_suit(i);
		m_suit[i].read_from_pbmsg(temp_m_suit);
	}
}

Sheet_EquipimproveSealsuit_s::Sheet_EquipimproveSealsuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipimproveSealsuit_s::CreateInit() {
	return 0;
}

int Sheet_EquipimproveSealsuit_s::ResumeInit() {
	return 0;
}

void Sheet_EquipimproveSealsuit_s::write_to_pbmsg(::proto_ff::Sheet_EquipimproveSealsuit & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipimproveSealsuit_List.size(); ++i) {
		::proto_ff::E_EquipimproveSealsuit* temp_e_equipimprovesealsuit_list = msg.add_e_equipimprovesealsuit_list();
		E_EquipimproveSealsuit_List[i].write_to_pbmsg(*temp_e_equipimprovesealsuit_list);
	}
}

void Sheet_EquipimproveSealsuit_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipimproveSealsuit & msg) {
	E_EquipimproveSealsuit_List.resize((int)msg.e_equipimprovesealsuit_list_size() > (int)E_EquipimproveSealsuit_List.max_size() ? E_EquipimproveSealsuit_List.max_size() : msg.e_equipimprovesealsuit_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipimproveSealsuit_List.size(); ++i) {
		const ::proto_ff::E_EquipimproveSealsuit & temp_e_equipimprovesealsuit_list = msg.e_equipimprovesealsuit_list(i);
		E_EquipimproveSealsuit_List[i].read_from_pbmsg(temp_e_equipimprovesealsuit_list);
	}
}

}
