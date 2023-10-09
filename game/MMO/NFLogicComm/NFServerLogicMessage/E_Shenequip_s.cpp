#include "E_Shenequip_s.h"

namespace proto_ff_s {

E_ShenequipEquip_s::E_ShenequipEquip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShenequipEquip_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_grade = (int32_t)0;
	m_subtype = (int32_t)0;
	m_level = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	m_attributeid = (int32_t)0;
	m_iscanbind = (int32_t)0;
	m_istradebind = (int32_t)0;
	m_time = (int32_t)0;
	m_broadcast = (int32_t)0;
	m_exclusiveid = (int32_t)0;
	return 0;
}

int E_ShenequipEquip_s::ResumeInit() {
	return 0;
}

void E_ShenequipEquip_s::write_to_pbmsg(::proto_ff::E_ShenequipEquip & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_type((int32_t)m_type);
	msg.set_m_grade((int32_t)m_grade);
	msg.set_m_subtype((int32_t)m_subtype);
	msg.set_m_level((int32_t)m_level);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_attributeid((int32_t)m_attributeid);
	msg.set_m_decompose(m_decompose.data());
	msg.set_m_iscanbind((int32_t)m_iscanbind);
	msg.set_m_istradebind((int32_t)m_istradebind);
	msg.set_m_time((int32_t)m_time);
	msg.set_m_broadcast((int32_t)m_broadcast);
	msg.set_m_exclusiveid((int32_t)m_exclusiveid);
	msg.set_m_secretskill(m_secretskill.data());
	msg.set_m_crypticskill(m_crypticskill.data());
	msg.set_m_passiveskill(m_passiveskill.data());
}

void E_ShenequipEquip_s::read_from_pbmsg(const ::proto_ff::E_ShenequipEquip & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_type = msg.m_type();
	m_grade = msg.m_grade();
	m_subtype = msg.m_subtype();
	m_level = msg.m_level();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_attributeid = msg.m_attributeid();
	m_decompose = msg.m_decompose();
	m_iscanbind = msg.m_iscanbind();
	m_istradebind = msg.m_istradebind();
	m_time = msg.m_time();
	m_broadcast = msg.m_broadcast();
	m_exclusiveid = msg.m_exclusiveid();
	m_secretskill = msg.m_secretskill();
	m_crypticskill = msg.m_crypticskill();
	m_passiveskill = msg.m_passiveskill();
}

Sheet_ShenequipEquip_s::Sheet_ShenequipEquip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShenequipEquip_s::CreateInit() {
	return 0;
}

int Sheet_ShenequipEquip_s::ResumeInit() {
	return 0;
}

void Sheet_ShenequipEquip_s::write_to_pbmsg(::proto_ff::Sheet_ShenequipEquip & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShenequipEquip_List.size(); ++i) {
		::proto_ff::E_ShenequipEquip* temp_e_shenequipequip_list = msg.add_e_shenequipequip_list();
		E_ShenequipEquip_List[i].write_to_pbmsg(*temp_e_shenequipequip_list);
	}
}

void Sheet_ShenequipEquip_s::read_from_pbmsg(const ::proto_ff::Sheet_ShenequipEquip & msg) {
	E_ShenequipEquip_List.resize((int)msg.e_shenequipequip_list_size() > (int)E_ShenequipEquip_List.max_size() ? E_ShenequipEquip_List.max_size() : msg.e_shenequipequip_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShenequipEquip_List.size(); ++i) {
		const ::proto_ff::E_ShenequipEquip & temp_e_shenequipequip_list = msg.e_shenequipequip_list(i);
		E_ShenequipEquip_List[i].read_from_pbmsg(temp_e_shenequipequip_list);
	}
}

E_ShenequipAttAttributeDesc_s::E_ShenequipAttAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShenequipAttAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShenequipAttAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_ShenequipAttAttributeDesc_s::write_to_pbmsg(::proto_ff::E_ShenequipAttAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShenequipAttAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_ShenequipAttAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShenequipAttStarDesc_s::E_ShenequipAttStarDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShenequipAttStarDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShenequipAttStarDesc_s::ResumeInit() {
	return 0;
}

void E_ShenequipAttStarDesc_s::write_to_pbmsg(::proto_ff::E_ShenequipAttStarDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShenequipAttStarDesc_s::read_from_pbmsg(const ::proto_ff::E_ShenequipAttStarDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShenequipAtt_s::E_ShenequipAtt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShenequipAtt_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_ShenequipAtt_s::ResumeInit() {
	return 0;
}

void E_ShenequipAtt_s::write_to_pbmsg(::proto_ff::E_ShenequipAtt & msg) const {
	msg.set_m_id((int32_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_ShenequipAttAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_star.size(); ++i) {
		::proto_ff::E_ShenequipAttStarDesc* temp_m_star = msg.add_m_star();
		m_star[i].write_to_pbmsg(*temp_m_star);
	}
}

void E_ShenequipAtt_s::read_from_pbmsg(const ::proto_ff::E_ShenequipAtt & msg) {
	m_id = msg.m_id();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_ShenequipAttAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_star.resize((int)msg.m_star_size() > (int)m_star.max_size() ? m_star.max_size() : msg.m_star_size());
	for(int32_t i = 0; i < (int32_t)m_star.size(); ++i) {
		const ::proto_ff::E_ShenequipAttStarDesc & temp_m_star = msg.m_star(i);
		m_star[i].read_from_pbmsg(temp_m_star);
	}
}

Sheet_ShenequipAtt_s::Sheet_ShenequipAtt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShenequipAtt_s::CreateInit() {
	return 0;
}

int Sheet_ShenequipAtt_s::ResumeInit() {
	return 0;
}

void Sheet_ShenequipAtt_s::write_to_pbmsg(::proto_ff::Sheet_ShenequipAtt & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShenequipAtt_List.size(); ++i) {
		::proto_ff::E_ShenequipAtt* temp_e_shenequipatt_list = msg.add_e_shenequipatt_list();
		E_ShenequipAtt_List[i].write_to_pbmsg(*temp_e_shenequipatt_list);
	}
}

void Sheet_ShenequipAtt_s::read_from_pbmsg(const ::proto_ff::Sheet_ShenequipAtt & msg) {
	E_ShenequipAtt_List.resize((int)msg.e_shenequipatt_list_size() > (int)E_ShenequipAtt_List.max_size() ? E_ShenequipAtt_List.max_size() : msg.e_shenequipatt_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShenequipAtt_List.size(); ++i) {
		const ::proto_ff::E_ShenequipAtt & temp_e_shenequipatt_list = msg.e_shenequipatt_list(i);
		E_ShenequipAtt_List[i].read_from_pbmsg(temp_e_shenequipatt_list);
	}
}

E_ShenequipLvupAttributeDesc_s::E_ShenequipLvupAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShenequipLvupAttributeDesc_s::CreateInit() {
	m_stepid = (int32_t)0;
	m_lvid = (int32_t)0;
	return 0;
}

int E_ShenequipLvupAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_ShenequipLvupAttributeDesc_s::write_to_pbmsg(::proto_ff::E_ShenequipLvupAttributeDesc & msg) const {
	msg.set_m_stepid((int32_t)m_stepid);
	msg.set_m_lvid((int32_t)m_lvid);
}

void E_ShenequipLvupAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_ShenequipLvupAttributeDesc & msg) {
	m_stepid = msg.m_stepid();
	m_lvid = msg.m_lvid();
}

E_ShenequipLvup_s::E_ShenequipLvup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShenequipLvup_s::CreateInit() {
	m_id = (int32_t)0;
	m_lv = (int32_t)0;
	m_type = (int32_t)0;
	m_itemid = (int32_t)0;
	m_num = (int32_t)0;
	m_advanceitem = (int32_t)0;
	m_advancenum = (int32_t)0;
	return 0;
}

int E_ShenequipLvup_s::ResumeInit() {
	return 0;
}

void E_ShenequipLvup_s::write_to_pbmsg(::proto_ff::E_ShenequipLvup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_advanceitem((int32_t)m_advanceitem);
	msg.set_m_advancenum((int32_t)m_advancenum);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_ShenequipLvupAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_ShenequipLvup_s::read_from_pbmsg(const ::proto_ff::E_ShenequipLvup & msg) {
	m_id = msg.m_id();
	m_lv = msg.m_lv();
	m_type = msg.m_type();
	m_itemid = msg.m_itemid();
	m_num = msg.m_num();
	m_advanceitem = msg.m_advanceitem();
	m_advancenum = msg.m_advancenum();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_ShenequipLvupAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_ShenequipLvup_s::Sheet_ShenequipLvup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShenequipLvup_s::CreateInit() {
	return 0;
}

int Sheet_ShenequipLvup_s::ResumeInit() {
	return 0;
}

void Sheet_ShenequipLvup_s::write_to_pbmsg(::proto_ff::Sheet_ShenequipLvup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShenequipLvup_List.size(); ++i) {
		::proto_ff::E_ShenequipLvup* temp_e_shenequiplvup_list = msg.add_e_shenequiplvup_list();
		E_ShenequipLvup_List[i].write_to_pbmsg(*temp_e_shenequiplvup_list);
	}
}

void Sheet_ShenequipLvup_s::read_from_pbmsg(const ::proto_ff::Sheet_ShenequipLvup & msg) {
	E_ShenequipLvup_List.resize((int)msg.e_shenequiplvup_list_size() > (int)E_ShenequipLvup_List.max_size() ? E_ShenequipLvup_List.max_size() : msg.e_shenequiplvup_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShenequipLvup_List.size(); ++i) {
		const ::proto_ff::E_ShenequipLvup & temp_e_shenequiplvup_list = msg.e_shenequiplvup_list(i);
		E_ShenequipLvup_List[i].read_from_pbmsg(temp_e_shenequiplvup_list);
	}
}

E_ShenequipClear_s::E_ShenequipClear_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShenequipClear_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_lv = (int32_t)0;
	m_itemid = (int32_t)0;
	m_num = (int32_t)0;
	m_breakitem = (int32_t)0;
	m_breaknum = (int32_t)0;
	m_breakprogress = (int32_t)0;
	m_randomcounts = (int32_t)0;
	m_minus = (int32_t)0;
	m_nextid = (int32_t)0;
	return 0;
}

int E_ShenequipClear_s::ResumeInit() {
	return 0;
}

void E_ShenequipClear_s::write_to_pbmsg(::proto_ff::E_ShenequipClear & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_breakitem((int32_t)m_breakitem);
	msg.set_m_breaknum((int32_t)m_breaknum);
	msg.set_m_breakprogress((int32_t)m_breakprogress);
	msg.set_m_randomcounts((int32_t)m_randomcounts);
	msg.set_m_minus((int32_t)m_minus);
	msg.set_m_nextid((int32_t)m_nextid);
	for(int32_t i = 0; i < (int32_t)m_percent.size(); ++i) {
		msg.add_m_percent((int32_t)m_percent[i]);
	}
}

void E_ShenequipClear_s::read_from_pbmsg(const ::proto_ff::E_ShenequipClear & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_lv = msg.m_lv();
	m_itemid = msg.m_itemid();
	m_num = msg.m_num();
	m_breakitem = msg.m_breakitem();
	m_breaknum = msg.m_breaknum();
	m_breakprogress = msg.m_breakprogress();
	m_randomcounts = msg.m_randomcounts();
	m_minus = msg.m_minus();
	m_nextid = msg.m_nextid();
	m_percent.resize((int)msg.m_percent_size() > (int)m_percent.max_size() ? m_percent.max_size() : msg.m_percent_size());
	for(int32_t i = 0; i < (int32_t)m_percent.size(); ++i) {
		m_percent[i] = msg.m_percent(i);
	}
}

Sheet_ShenequipClear_s::Sheet_ShenequipClear_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShenequipClear_s::CreateInit() {
	return 0;
}

int Sheet_ShenequipClear_s::ResumeInit() {
	return 0;
}

void Sheet_ShenequipClear_s::write_to_pbmsg(::proto_ff::Sheet_ShenequipClear & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShenequipClear_List.size(); ++i) {
		::proto_ff::E_ShenequipClear* temp_e_shenequipclear_list = msg.add_e_shenequipclear_list();
		E_ShenequipClear_List[i].write_to_pbmsg(*temp_e_shenequipclear_list);
	}
}

void Sheet_ShenequipClear_s::read_from_pbmsg(const ::proto_ff::Sheet_ShenequipClear & msg) {
	E_ShenequipClear_List.resize((int)msg.e_shenequipclear_list_size() > (int)E_ShenequipClear_List.max_size() ? E_ShenequipClear_List.max_size() : msg.e_shenequipclear_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShenequipClear_List.size(); ++i) {
		const ::proto_ff::E_ShenequipClear & temp_e_shenequipclear_list = msg.e_shenequipclear_list(i);
		E_ShenequipClear_List[i].read_from_pbmsg(temp_e_shenequipclear_list);
	}
}

E_ShenequipAwakenAttributeDesc_s::E_ShenequipAwakenAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShenequipAwakenAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShenequipAwakenAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_ShenequipAwakenAttributeDesc_s::write_to_pbmsg(::proto_ff::E_ShenequipAwakenAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShenequipAwakenAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_ShenequipAwakenAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShenequipAwaken_s::E_ShenequipAwaken_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShenequipAwaken_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_lv = (int32_t)0;
	m_itemid = (int32_t)0;
	m_num = (int32_t)0;
	m_awakeskillid = (int32_t)0;
	return 0;
}

int E_ShenequipAwaken_s::ResumeInit() {
	return 0;
}

void E_ShenequipAwaken_s::write_to_pbmsg(::proto_ff::E_ShenequipAwaken & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_awakeskillid((int32_t)m_awakeskillid);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_ShenequipAwakenAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_ShenequipAwaken_s::read_from_pbmsg(const ::proto_ff::E_ShenequipAwaken & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_lv = msg.m_lv();
	m_itemid = msg.m_itemid();
	m_num = msg.m_num();
	m_awakeskillid = msg.m_awakeskillid();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_ShenequipAwakenAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_ShenequipAwaken_s::Sheet_ShenequipAwaken_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShenequipAwaken_s::CreateInit() {
	return 0;
}

int Sheet_ShenequipAwaken_s::ResumeInit() {
	return 0;
}

void Sheet_ShenequipAwaken_s::write_to_pbmsg(::proto_ff::Sheet_ShenequipAwaken & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShenequipAwaken_List.size(); ++i) {
		::proto_ff::E_ShenequipAwaken* temp_e_shenequipawaken_list = msg.add_e_shenequipawaken_list();
		E_ShenequipAwaken_List[i].write_to_pbmsg(*temp_e_shenequipawaken_list);
	}
}

void Sheet_ShenequipAwaken_s::read_from_pbmsg(const ::proto_ff::Sheet_ShenequipAwaken & msg) {
	E_ShenequipAwaken_List.resize((int)msg.e_shenequipawaken_list_size() > (int)E_ShenequipAwaken_List.max_size() ? E_ShenequipAwaken_List.max_size() : msg.e_shenequipawaken_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShenequipAwaken_List.size(); ++i) {
		const ::proto_ff::E_ShenequipAwaken & temp_e_shenequipawaken_list = msg.e_shenequipawaken_list(i);
		E_ShenequipAwaken_List[i].read_from_pbmsg(temp_e_shenequipawaken_list);
	}
}

E_ShenequipStarupMaterialDesc_s::E_ShenequipStarupMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShenequipStarupMaterialDesc_s::CreateInit() {
	m_star = (int32_t)0;
	m_quality = (int32_t)0;
	m_num = (int32_t)0;
	m_grade = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShenequipStarupMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_ShenequipStarupMaterialDesc_s::write_to_pbmsg(::proto_ff::E_ShenequipStarupMaterialDesc & msg) const {
	msg.set_m_star((int32_t)m_star);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_grade((int32_t)m_grade);
	msg.set_m_type((int32_t)m_type);
}

void E_ShenequipStarupMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_ShenequipStarupMaterialDesc & msg) {
	m_star = msg.m_star();
	m_quality = msg.m_quality();
	m_num = msg.m_num();
	m_grade = msg.m_grade();
	m_type = msg.m_type();
}

E_ShenequipStarup_s::E_ShenequipStarup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShenequipStarup_s::CreateInit() {
	m_id = (int32_t)0;
	m_grade = (int32_t)0;
	m_quality = (int32_t)0;
	m_stars = (int32_t)0;
	m_nextid = (int32_t)0;
	m_lastid = (int32_t)0;
	m_percent = (int32_t)0;
	return 0;
}

int E_ShenequipStarup_s::ResumeInit() {
	return 0;
}

void E_ShenequipStarup_s::write_to_pbmsg(::proto_ff::E_ShenequipStarup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_grade((int32_t)m_grade);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_stars((int32_t)m_stars);
	msg.set_m_nextid((int32_t)m_nextid);
	msg.set_m_lastid((int32_t)m_lastid);
	msg.set_m_percent((int32_t)m_percent);
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_ShenequipStarupMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
}

void E_ShenequipStarup_s::read_from_pbmsg(const ::proto_ff::E_ShenequipStarup & msg) {
	m_id = msg.m_id();
	m_grade = msg.m_grade();
	m_quality = msg.m_quality();
	m_stars = msg.m_stars();
	m_nextid = msg.m_nextid();
	m_lastid = msg.m_lastid();
	m_percent = msg.m_percent();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_ShenequipStarupMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
}

Sheet_ShenequipStarup_s::Sheet_ShenequipStarup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShenequipStarup_s::CreateInit() {
	return 0;
}

int Sheet_ShenequipStarup_s::ResumeInit() {
	return 0;
}

void Sheet_ShenequipStarup_s::write_to_pbmsg(::proto_ff::Sheet_ShenequipStarup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShenequipStarup_List.size(); ++i) {
		::proto_ff::E_ShenequipStarup* temp_e_shenequipstarup_list = msg.add_e_shenequipstarup_list();
		E_ShenequipStarup_List[i].write_to_pbmsg(*temp_e_shenequipstarup_list);
	}
}

void Sheet_ShenequipStarup_s::read_from_pbmsg(const ::proto_ff::Sheet_ShenequipStarup & msg) {
	E_ShenequipStarup_List.resize((int)msg.e_shenequipstarup_list_size() > (int)E_ShenequipStarup_List.max_size() ? E_ShenequipStarup_List.max_size() : msg.e_shenequipstarup_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShenequipStarup_List.size(); ++i) {
		const ::proto_ff::E_ShenequipStarup & temp_e_shenequipstarup_list = msg.e_shenequipstarup_list(i);
		E_ShenequipStarup_List[i].read_from_pbmsg(temp_e_shenequipstarup_list);
	}
}

E_ShenequipPreposeRewardDesc_s::E_ShenequipPreposeRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShenequipPreposeRewardDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_item = (int32_t)0;
	return 0;
}

int E_ShenequipPreposeRewardDesc_s::ResumeInit() {
	return 0;
}

void E_ShenequipPreposeRewardDesc_s::write_to_pbmsg(::proto_ff::E_ShenequipPreposeRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_item((int32_t)m_item);
}

void E_ShenequipPreposeRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_ShenequipPreposeRewardDesc & msg) {
	m_num = msg.m_num();
	m_item = msg.m_item();
}

E_ShenequipPrepose_s::E_ShenequipPrepose_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShenequipPrepose_s::CreateInit() {
	m_id = (int32_t)0;
	m_condition = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_ShenequipPrepose_s::ResumeInit() {
	return 0;
}

void E_ShenequipPrepose_s::write_to_pbmsg(::proto_ff::E_ShenequipPrepose & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_condition((int32_t)m_condition);
	msg.set_m_value((int32_t)m_value);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_ShenequipPreposeRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_ShenequipPrepose_s::read_from_pbmsg(const ::proto_ff::E_ShenequipPrepose & msg) {
	m_id = msg.m_id();
	m_condition = msg.m_condition();
	m_value = msg.m_value();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_ShenequipPreposeRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_ShenequipPrepose_s::Sheet_ShenequipPrepose_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShenequipPrepose_s::CreateInit() {
	return 0;
}

int Sheet_ShenequipPrepose_s::ResumeInit() {
	return 0;
}

void Sheet_ShenequipPrepose_s::write_to_pbmsg(::proto_ff::Sheet_ShenequipPrepose & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShenequipPrepose_List.size(); ++i) {
		::proto_ff::E_ShenequipPrepose* temp_e_shenequipprepose_list = msg.add_e_shenequipprepose_list();
		E_ShenequipPrepose_List[i].write_to_pbmsg(*temp_e_shenequipprepose_list);
	}
}

void Sheet_ShenequipPrepose_s::read_from_pbmsg(const ::proto_ff::Sheet_ShenequipPrepose & msg) {
	E_ShenequipPrepose_List.resize((int)msg.e_shenequipprepose_list_size() > (int)E_ShenequipPrepose_List.max_size() ? E_ShenequipPrepose_List.max_size() : msg.e_shenequipprepose_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShenequipPrepose_List.size(); ++i) {
		const ::proto_ff::E_ShenequipPrepose & temp_e_shenequipprepose_list = msg.e_shenequipprepose_list(i);
		E_ShenequipPrepose_List[i].read_from_pbmsg(temp_e_shenequipprepose_list);
	}
}

}
