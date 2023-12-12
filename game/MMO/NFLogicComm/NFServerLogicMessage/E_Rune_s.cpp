#include "E_Rune_s.h"

namespace proto_ff_s {

E_RuneConst_s::E_RuneConst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneConst_s::CreateInit() {
	m_id = (int32_t)0;
	m_costItem = (int32_t)0;
	m_lokCostNum = (int32_t)0;
	m_mallID = (int32_t)0;
	m_quenching_max = (int32_t)0;
	return 0;
}

int E_RuneConst_s::ResumeInit() {
	return 0;
}

void E_RuneConst_s::write_to_pbmsg(::proto_ff::E_RuneConst & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_costitem((int32_t)m_costItem);
	msg.set_m_lokcostnum((int32_t)m_lokCostNum);
	msg.set_m_mallid((int32_t)m_mallID);
	msg.set_m_quenching_max((int32_t)m_quenching_max);
}

void E_RuneConst_s::read_from_pbmsg(const ::proto_ff::E_RuneConst & msg) {
	m_id = msg.m_id();
	m_costItem = msg.m_costitem();
	m_lokCostNum = msg.m_lokcostnum();
	m_mallID = msg.m_mallid();
	m_quenching_max = msg.m_quenching_max();
}

Sheet_RuneConst_s::Sheet_RuneConst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RuneConst_s::CreateInit() {
	return 0;
}

int Sheet_RuneConst_s::ResumeInit() {
	return 0;
}

void Sheet_RuneConst_s::write_to_pbmsg(::proto_ff::Sheet_RuneConst & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RuneConst_List.size(); ++i) {
		::proto_ff::E_RuneConst* temp_e_runeconst_list = msg.add_e_runeconst_list();
		E_RuneConst_List[i].write_to_pbmsg(*temp_e_runeconst_list);
	}
}

void Sheet_RuneConst_s::read_from_pbmsg(const ::proto_ff::Sheet_RuneConst & msg) {
	E_RuneConst_List.resize((int)msg.e_runeconst_list_size() > (int)E_RuneConst_List.max_size() ? E_RuneConst_List.max_size() : msg.e_runeconst_list_size());
	for(int32_t i = 0; i < (int32_t)E_RuneConst_List.size(); ++i) {
		const ::proto_ff::E_RuneConst & temp_e_runeconst_list = msg.e_runeconst_list(i);
		E_RuneConst_List[i].read_from_pbmsg(temp_e_runeconst_list);
	}
}

E_RuneRuneAttributeDesc_s::E_RuneRuneAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneRuneAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_RuneRuneAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_RuneRuneAttributeDesc_s::write_to_pbmsg(::proto_ff::E_RuneRuneAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_RuneRuneAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_RuneRuneAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_RuneRune_s::E_RuneRune_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneRune_s::CreateInit() {
	m_id = (int32_t)0;
	m_positionType = (int32_t)0;
	m_attributeType = (int32_t)0;
	m_subType = (int32_t)0;
	m_quality = (int32_t)0;
	m_level = (int32_t)0;
	m_quenchingLminit = (int32_t)0;
	m_disassemble = (int32_t)0;
	m_disassembleId = (int32_t)0;
	m_disassembleNum = (int32_t)0;
	return 0;
}

int E_RuneRune_s::ResumeInit() {
	return 0;
}

void E_RuneRune_s::write_to_pbmsg(::proto_ff::E_RuneRune & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_positiontype((int32_t)m_positionType);
	msg.set_m_attributetype((int32_t)m_attributeType);
	msg.set_m_subtype((int32_t)m_subType);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_level((int32_t)m_level);
	msg.set_m_quenchinglminit((int32_t)m_quenchingLminit);
	msg.set_m_disassemble((int32_t)m_disassemble);
	msg.set_m_disassembleid((int32_t)m_disassembleId);
	msg.set_m_disassemblenum((int32_t)m_disassembleNum);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_RuneRuneAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_RuneRune_s::read_from_pbmsg(const ::proto_ff::E_RuneRune & msg) {
	m_id = msg.m_id();
	m_positionType = msg.m_positiontype();
	m_attributeType = msg.m_attributetype();
	m_subType = msg.m_subtype();
	m_quality = msg.m_quality();
	m_level = msg.m_level();
	m_quenchingLminit = msg.m_quenchinglminit();
	m_disassemble = msg.m_disassemble();
	m_disassembleId = msg.m_disassembleid();
	m_disassembleNum = msg.m_disassemblenum();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_RuneRuneAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_RuneRune_s::Sheet_RuneRune_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RuneRune_s::CreateInit() {
	return 0;
}

int Sheet_RuneRune_s::ResumeInit() {
	return 0;
}

void Sheet_RuneRune_s::write_to_pbmsg(::proto_ff::Sheet_RuneRune & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RuneRune_List.size(); ++i) {
		::proto_ff::E_RuneRune* temp_e_runerune_list = msg.add_e_runerune_list();
		E_RuneRune_List[i].write_to_pbmsg(*temp_e_runerune_list);
	}
}

void Sheet_RuneRune_s::read_from_pbmsg(const ::proto_ff::Sheet_RuneRune & msg) {
	E_RuneRune_List.resize((int)msg.e_runerune_list_size() > (int)E_RuneRune_List.max_size() ? E_RuneRune_List.max_size() : msg.e_runerune_list_size());
	for(int32_t i = 0; i < (int32_t)E_RuneRune_List.size(); ++i) {
		const ::proto_ff::E_RuneRune & temp_e_runerune_list = msg.e_runerune_list(i);
		E_RuneRune_List[i].read_from_pbmsg(temp_e_runerune_list);
	}
}

E_RuneRunewords_s::E_RuneRunewords_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneRunewords_s::CreateInit() {
	m_id = (int32_t)0;
	m_skill = (int32_t)0;
	m_quenchingLminit = (int32_t)0;
	m_disassembleId = (int32_t)0;
	m_disassembleNum = (int32_t)0;
	m_starLvMax = (int32_t)0;
	m_costItem = (int32_t)0;
	m_costNum = (int32_t)0;
	return 0;
}

int E_RuneRunewords_s::ResumeInit() {
	return 0;
}

void E_RuneRunewords_s::write_to_pbmsg(::proto_ff::E_RuneRunewords & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_skill((int32_t)m_skill);
	msg.set_m_quenchinglminit((int32_t)m_quenchingLminit);
	msg.set_m_disassembleid((int32_t)m_disassembleId);
	msg.set_m_disassemblenum((int32_t)m_disassembleNum);
	msg.set_m_starlvmax((int32_t)m_starLvMax);
	msg.set_m_costitem((int32_t)m_costItem);
	msg.set_m_costnum((int32_t)m_costNum);
}

void E_RuneRunewords_s::read_from_pbmsg(const ::proto_ff::E_RuneRunewords & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_skill = msg.m_skill();
	m_quenchingLminit = msg.m_quenchinglminit();
	m_disassembleId = msg.m_disassembleid();
	m_disassembleNum = msg.m_disassemblenum();
	m_starLvMax = msg.m_starlvmax();
	m_costItem = msg.m_costitem();
	m_costNum = msg.m_costnum();
}

Sheet_RuneRunewords_s::Sheet_RuneRunewords_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RuneRunewords_s::CreateInit() {
	return 0;
}

int Sheet_RuneRunewords_s::ResumeInit() {
	return 0;
}

void Sheet_RuneRunewords_s::write_to_pbmsg(::proto_ff::Sheet_RuneRunewords & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RuneRunewords_List.size(); ++i) {
		::proto_ff::E_RuneRunewords* temp_e_runerunewords_list = msg.add_e_runerunewords_list();
		E_RuneRunewords_List[i].write_to_pbmsg(*temp_e_runerunewords_list);
	}
}

void Sheet_RuneRunewords_s::read_from_pbmsg(const ::proto_ff::Sheet_RuneRunewords & msg) {
	E_RuneRunewords_List.resize((int)msg.e_runerunewords_list_size() > (int)E_RuneRunewords_List.max_size() ? E_RuneRunewords_List.max_size() : msg.e_runerunewords_list_size());
	for(int32_t i = 0; i < (int32_t)E_RuneRunewords_List.size(); ++i) {
		const ::proto_ff::E_RuneRunewords & temp_e_runerunewords_list = msg.e_runerunewords_list(i);
		E_RuneRunewords_List[i].read_from_pbmsg(temp_e_runerunewords_list);
	}
}

E_RuneQuenching_s::E_RuneQuenching_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneQuenching_s::CreateInit() {
	m_id = (int32_t)0;
	m_expandProb = (int32_t)0;
	m_qualityLimit = (int32_t)0;
	return 0;
}

int E_RuneQuenching_s::ResumeInit() {
	return 0;
}

void E_RuneQuenching_s::write_to_pbmsg(::proto_ff::E_RuneQuenching & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_expandprob((int32_t)m_expandProb);
	msg.set_m_qualitylimit((int32_t)m_qualityLimit);
}

void E_RuneQuenching_s::read_from_pbmsg(const ::proto_ff::E_RuneQuenching & msg) {
	m_id = msg.m_id();
	m_expandProb = msg.m_expandprob();
	m_qualityLimit = msg.m_qualitylimit();
}

Sheet_RuneQuenching_s::Sheet_RuneQuenching_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RuneQuenching_s::CreateInit() {
	return 0;
}

int Sheet_RuneQuenching_s::ResumeInit() {
	return 0;
}

void Sheet_RuneQuenching_s::write_to_pbmsg(::proto_ff::Sheet_RuneQuenching & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RuneQuenching_List.size(); ++i) {
		::proto_ff::E_RuneQuenching* temp_e_runequenching_list = msg.add_e_runequenching_list();
		E_RuneQuenching_List[i].write_to_pbmsg(*temp_e_runequenching_list);
	}
}

void Sheet_RuneQuenching_s::read_from_pbmsg(const ::proto_ff::Sheet_RuneQuenching & msg) {
	E_RuneQuenching_List.resize((int)msg.e_runequenching_list_size() > (int)E_RuneQuenching_List.max_size() ? E_RuneQuenching_List.max_size() : msg.e_runequenching_list_size());
	for(int32_t i = 0; i < (int32_t)E_RuneQuenching_List.size(); ++i) {
		const ::proto_ff::E_RuneQuenching & temp_e_runequenching_list = msg.e_runequenching_list(i);
		E_RuneQuenching_List[i].read_from_pbmsg(temp_e_runequenching_list);
	}
}

E_RuneCompare_s::E_RuneCompare_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneCompare_s::CreateInit() {
	m_id = (int32_t)0;
	m_positionType = (int32_t)0;
	m_attributeType = (int32_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_RuneCompare_s::ResumeInit() {
	return 0;
}

void E_RuneCompare_s::write_to_pbmsg(::proto_ff::E_RuneCompare & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_positiontype((int32_t)m_positionType);
	msg.set_m_attributetype((int32_t)m_attributeType);
	msg.set_m_quality((int32_t)m_quality);
}

void E_RuneCompare_s::read_from_pbmsg(const ::proto_ff::E_RuneCompare & msg) {
	m_id = msg.m_id();
	m_positionType = msg.m_positiontype();
	m_attributeType = msg.m_attributetype();
	m_quality = msg.m_quality();
}

Sheet_RuneCompare_s::Sheet_RuneCompare_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RuneCompare_s::CreateInit() {
	return 0;
}

int Sheet_RuneCompare_s::ResumeInit() {
	return 0;
}

void Sheet_RuneCompare_s::write_to_pbmsg(::proto_ff::Sheet_RuneCompare & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RuneCompare_List.size(); ++i) {
		::proto_ff::E_RuneCompare* temp_e_runecompare_list = msg.add_e_runecompare_list();
		E_RuneCompare_List[i].write_to_pbmsg(*temp_e_runecompare_list);
	}
}

void Sheet_RuneCompare_s::read_from_pbmsg(const ::proto_ff::Sheet_RuneCompare & msg) {
	E_RuneCompare_List.resize((int)msg.e_runecompare_list_size() > (int)E_RuneCompare_List.max_size() ? E_RuneCompare_List.max_size() : msg.e_runecompare_list_size());
	for(int32_t i = 0; i < (int32_t)E_RuneCompare_List.size(); ++i) {
		const ::proto_ff::E_RuneCompare & temp_e_runecompare_list = msg.e_runecompare_list(i);
		E_RuneCompare_List[i].read_from_pbmsg(temp_e_runecompare_list);
	}
}

E_RuneStuntskillActivateDesc_s::E_RuneStuntskillActivateDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneStuntskillActivateDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_quality = (int32_t)0;
	m_attributeType = (int32_t)0;
	m_positionType = (int32_t)0;
	return 0;
}

int E_RuneStuntskillActivateDesc_s::ResumeInit() {
	return 0;
}

void E_RuneStuntskillActivateDesc_s::write_to_pbmsg(::proto_ff::E_RuneStuntskillActivateDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_attributetype((int32_t)m_attributeType);
	msg.set_m_positiontype((int32_t)m_positionType);
}

void E_RuneStuntskillActivateDesc_s::read_from_pbmsg(const ::proto_ff::E_RuneStuntskillActivateDesc & msg) {
	m_num = msg.m_num();
	m_quality = msg.m_quality();
	m_attributeType = msg.m_attributetype();
	m_positionType = msg.m_positiontype();
}

E_RuneStuntskill_s::E_RuneStuntskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneStuntskill_s::CreateInit() {
	m_skillId = (int32_t)0;
	m_position = (int32_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_RuneStuntskill_s::ResumeInit() {
	return 0;
}

void E_RuneStuntskill_s::write_to_pbmsg(::proto_ff::E_RuneStuntskill & msg) const {
	msg.set_m_skillid((int32_t)m_skillId);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_quality((int32_t)m_quality);
	for(int32_t i = 0; i < (int32_t)m_activate.size(); ++i) {
		::proto_ff::E_RuneStuntskillActivateDesc* temp_m_activate = msg.add_m_activate();
		m_activate[i].write_to_pbmsg(*temp_m_activate);
	}
}

void E_RuneStuntskill_s::read_from_pbmsg(const ::proto_ff::E_RuneStuntskill & msg) {
	m_skillId = msg.m_skillid();
	m_position = msg.m_position();
	m_quality = msg.m_quality();
	m_activate.resize((int)msg.m_activate_size() > (int)m_activate.max_size() ? m_activate.max_size() : msg.m_activate_size());
	for(int32_t i = 0; i < (int32_t)m_activate.size(); ++i) {
		const ::proto_ff::E_RuneStuntskillActivateDesc & temp_m_activate = msg.m_activate(i);
		m_activate[i].read_from_pbmsg(temp_m_activate);
	}
}

Sheet_RuneStuntskill_s::Sheet_RuneStuntskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RuneStuntskill_s::CreateInit() {
	return 0;
}

int Sheet_RuneStuntskill_s::ResumeInit() {
	return 0;
}

void Sheet_RuneStuntskill_s::write_to_pbmsg(::proto_ff::Sheet_RuneStuntskill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RuneStuntskill_List.size(); ++i) {
		::proto_ff::E_RuneStuntskill* temp_e_runestuntskill_list = msg.add_e_runestuntskill_list();
		E_RuneStuntskill_List[i].write_to_pbmsg(*temp_e_runestuntskill_list);
	}
}

void Sheet_RuneStuntskill_s::read_from_pbmsg(const ::proto_ff::Sheet_RuneStuntskill & msg) {
	E_RuneStuntskill_List.resize((int)msg.e_runestuntskill_list_size() > (int)E_RuneStuntskill_List.max_size() ? E_RuneStuntskill_List.max_size() : msg.e_runestuntskill_list_size());
	for(int32_t i = 0; i < (int32_t)E_RuneStuntskill_List.size(); ++i) {
		const ::proto_ff::E_RuneStuntskill & temp_e_runestuntskill_list = msg.e_runestuntskill_list(i);
		E_RuneStuntskill_List[i].read_from_pbmsg(temp_e_runestuntskill_list);
	}
}

E_RunePassiveskillTypeDesc_s::E_RunePassiveskillTypeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RunePassiveskillTypeDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_RunePassiveskillTypeDesc_s::ResumeInit() {
	return 0;
}

void E_RunePassiveskillTypeDesc_s::write_to_pbmsg(::proto_ff::E_RunePassiveskillTypeDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_RunePassiveskillTypeDesc_s::read_from_pbmsg(const ::proto_ff::E_RunePassiveskillTypeDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_RunePassiveskill_s::E_RunePassiveskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RunePassiveskill_s::CreateInit() {
	m_id = (int32_t)0;
	m_position = (int32_t)0;
	m_lv = (int32_t)0;
	m_quality = (int32_t)0;
	m_activateQuality = (int32_t)0;
	m_activateNum = (int32_t)0;
	return 0;
}

int E_RunePassiveskill_s::ResumeInit() {
	return 0;
}

void E_RunePassiveskill_s::write_to_pbmsg(::proto_ff::E_RunePassiveskill & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_activatequality((int32_t)m_activateQuality);
	msg.set_m_activatenum((int32_t)m_activateNum);
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		::proto_ff::E_RunePassiveskillTypeDesc* temp_m_type = msg.add_m_type();
		m_type[i].write_to_pbmsg(*temp_m_type);
	}
}

void E_RunePassiveskill_s::read_from_pbmsg(const ::proto_ff::E_RunePassiveskill & msg) {
	m_id = msg.m_id();
	m_position = msg.m_position();
	m_lv = msg.m_lv();
	m_quality = msg.m_quality();
	m_activateQuality = msg.m_activatequality();
	m_activateNum = msg.m_activatenum();
	m_type.resize((int)msg.m_type_size() > (int)m_type.max_size() ? m_type.max_size() : msg.m_type_size());
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		const ::proto_ff::E_RunePassiveskillTypeDesc & temp_m_type = msg.m_type(i);
		m_type[i].read_from_pbmsg(temp_m_type);
	}
}

Sheet_RunePassiveskill_s::Sheet_RunePassiveskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RunePassiveskill_s::CreateInit() {
	return 0;
}

int Sheet_RunePassiveskill_s::ResumeInit() {
	return 0;
}

void Sheet_RunePassiveskill_s::write_to_pbmsg(::proto_ff::Sheet_RunePassiveskill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RunePassiveskill_List.size(); ++i) {
		::proto_ff::E_RunePassiveskill* temp_e_runepassiveskill_list = msg.add_e_runepassiveskill_list();
		E_RunePassiveskill_List[i].write_to_pbmsg(*temp_e_runepassiveskill_list);
	}
}

void Sheet_RunePassiveskill_s::read_from_pbmsg(const ::proto_ff::Sheet_RunePassiveskill & msg) {
	E_RunePassiveskill_List.resize((int)msg.e_runepassiveskill_list_size() > (int)E_RunePassiveskill_List.max_size() ? E_RunePassiveskill_List.max_size() : msg.e_runepassiveskill_list_size());
	for(int32_t i = 0; i < (int32_t)E_RunePassiveskill_List.size(); ++i) {
		const ::proto_ff::E_RunePassiveskill & temp_e_runepassiveskill_list = msg.e_runepassiveskill_list(i);
		E_RunePassiveskill_List[i].read_from_pbmsg(temp_e_runepassiveskill_list);
	}
}

E_RuneUpgradeTypeDesc_s::E_RuneUpgradeTypeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneUpgradeTypeDesc_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_RuneUpgradeTypeDesc_s::ResumeInit() {
	return 0;
}

void E_RuneUpgradeTypeDesc_s::write_to_pbmsg(::proto_ff::E_RuneUpgradeTypeDesc & msg) const {
	msg.set_m_num(m_num.data());
	msg.set_m_id((int32_t)m_id);
}

void E_RuneUpgradeTypeDesc_s::read_from_pbmsg(const ::proto_ff::E_RuneUpgradeTypeDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_RuneUpgrade_s::E_RuneUpgrade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneUpgrade_s::CreateInit() {
	m_runeId = (int32_t)0;
	m_upgradeUp = (int32_t)0;
	return 0;
}

int E_RuneUpgrade_s::ResumeInit() {
	return 0;
}

void E_RuneUpgrade_s::write_to_pbmsg(::proto_ff::E_RuneUpgrade & msg) const {
	msg.set_m_runeid((int32_t)m_runeId);
	msg.set_m_upgradeup((int32_t)m_upgradeUp);
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		::proto_ff::E_RuneUpgradeTypeDesc* temp_m_type = msg.add_m_type();
		m_type[i].write_to_pbmsg(*temp_m_type);
	}
}

void E_RuneUpgrade_s::read_from_pbmsg(const ::proto_ff::E_RuneUpgrade & msg) {
	m_runeId = msg.m_runeid();
	m_upgradeUp = msg.m_upgradeup();
	m_type.resize((int)msg.m_type_size() > (int)m_type.max_size() ? m_type.max_size() : msg.m_type_size());
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		const ::proto_ff::E_RuneUpgradeTypeDesc & temp_m_type = msg.m_type(i);
		m_type[i].read_from_pbmsg(temp_m_type);
	}
}

Sheet_RuneUpgrade_s::Sheet_RuneUpgrade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RuneUpgrade_s::CreateInit() {
	return 0;
}

int Sheet_RuneUpgrade_s::ResumeInit() {
	return 0;
}

void Sheet_RuneUpgrade_s::write_to_pbmsg(::proto_ff::Sheet_RuneUpgrade & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RuneUpgrade_List.size(); ++i) {
		::proto_ff::E_RuneUpgrade* temp_e_runeupgrade_list = msg.add_e_runeupgrade_list();
		E_RuneUpgrade_List[i].write_to_pbmsg(*temp_e_runeupgrade_list);
	}
}

void Sheet_RuneUpgrade_s::read_from_pbmsg(const ::proto_ff::Sheet_RuneUpgrade & msg) {
	E_RuneUpgrade_List.resize((int)msg.e_runeupgrade_list_size() > (int)E_RuneUpgrade_List.max_size() ? E_RuneUpgrade_List.max_size() : msg.e_runeupgrade_list_size());
	for(int32_t i = 0; i < (int32_t)E_RuneUpgrade_List.size(); ++i) {
		const ::proto_ff::E_RuneUpgrade & temp_e_runeupgrade_list = msg.e_runeupgrade_list(i);
		E_RuneUpgrade_List[i].read_from_pbmsg(temp_e_runeupgrade_list);
	}
}

E_RuneUpgradeexp_s::E_RuneUpgradeexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneUpgradeexp_s::CreateInit() {
	m_Lv = (int32_t)0;
	m_costItem = (int32_t)0;
	m_costNum = (int32_t)0;
	return 0;
}

int E_RuneUpgradeexp_s::ResumeInit() {
	return 0;
}

void E_RuneUpgradeexp_s::write_to_pbmsg(::proto_ff::E_RuneUpgradeexp & msg) const {
	msg.set_m_lv((int32_t)m_Lv);
	msg.set_m_costitem((int32_t)m_costItem);
	msg.set_m_costnum((int32_t)m_costNum);
}

void E_RuneUpgradeexp_s::read_from_pbmsg(const ::proto_ff::E_RuneUpgradeexp & msg) {
	m_Lv = msg.m_lv();
	m_costItem = msg.m_costitem();
	m_costNum = msg.m_costnum();
}

Sheet_RuneUpgradeexp_s::Sheet_RuneUpgradeexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RuneUpgradeexp_s::CreateInit() {
	return 0;
}

int Sheet_RuneUpgradeexp_s::ResumeInit() {
	return 0;
}

void Sheet_RuneUpgradeexp_s::write_to_pbmsg(::proto_ff::Sheet_RuneUpgradeexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RuneUpgradeexp_List.size(); ++i) {
		::proto_ff::E_RuneUpgradeexp* temp_e_runeupgradeexp_list = msg.add_e_runeupgradeexp_list();
		E_RuneUpgradeexp_List[i].write_to_pbmsg(*temp_e_runeupgradeexp_list);
	}
}

void Sheet_RuneUpgradeexp_s::read_from_pbmsg(const ::proto_ff::Sheet_RuneUpgradeexp & msg) {
	E_RuneUpgradeexp_List.resize((int)msg.e_runeupgradeexp_list_size() > (int)E_RuneUpgradeexp_List.max_size() ? E_RuneUpgradeexp_List.max_size() : msg.e_runeupgradeexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_RuneUpgradeexp_List.size(); ++i) {
		const ::proto_ff::E_RuneUpgradeexp & temp_e_runeupgradeexp_list = msg.e_runeupgradeexp_list(i);
		E_RuneUpgradeexp_List[i].read_from_pbmsg(temp_e_runeupgradeexp_list);
	}
}

E_RuneAdvancedAttributeDesc_s::E_RuneAdvancedAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneAdvancedAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_RuneAdvancedAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_RuneAdvancedAttributeDesc_s::write_to_pbmsg(::proto_ff::E_RuneAdvancedAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_RuneAdvancedAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_RuneAdvancedAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_RuneAdvanced_s::E_RuneAdvanced_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneAdvanced_s::CreateInit() {
	m_id = (int32_t)0;
	m_wearQuality = (int32_t)0;
	m_runeId = (int32_t)0;
	m_costItem = (int32_t)0;
	m_costNum = (int32_t)0;
	return 0;
}

int E_RuneAdvanced_s::ResumeInit() {
	return 0;
}

void E_RuneAdvanced_s::write_to_pbmsg(::proto_ff::E_RuneAdvanced & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_wearquality((int32_t)m_wearQuality);
	msg.set_m_runeid((int32_t)m_runeId);
	msg.set_m_costitem((int32_t)m_costItem);
	msg.set_m_costnum((int32_t)m_costNum);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_RuneAdvancedAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_RuneAdvanced_s::read_from_pbmsg(const ::proto_ff::E_RuneAdvanced & msg) {
	m_id = msg.m_id();
	m_wearQuality = msg.m_wearquality();
	m_runeId = msg.m_runeid();
	m_costItem = msg.m_costitem();
	m_costNum = msg.m_costnum();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_RuneAdvancedAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_RuneAdvanced_s::Sheet_RuneAdvanced_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RuneAdvanced_s::CreateInit() {
	return 0;
}

int Sheet_RuneAdvanced_s::ResumeInit() {
	return 0;
}

void Sheet_RuneAdvanced_s::write_to_pbmsg(::proto_ff::Sheet_RuneAdvanced & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RuneAdvanced_List.size(); ++i) {
		::proto_ff::E_RuneAdvanced* temp_e_runeadvanced_list = msg.add_e_runeadvanced_list();
		E_RuneAdvanced_List[i].write_to_pbmsg(*temp_e_runeadvanced_list);
	}
}

void Sheet_RuneAdvanced_s::read_from_pbmsg(const ::proto_ff::Sheet_RuneAdvanced & msg) {
	E_RuneAdvanced_List.resize((int)msg.e_runeadvanced_list_size() > (int)E_RuneAdvanced_List.max_size() ? E_RuneAdvanced_List.max_size() : msg.e_runeadvanced_list_size());
	for(int32_t i = 0; i < (int32_t)E_RuneAdvanced_List.size(); ++i) {
		const ::proto_ff::E_RuneAdvanced & temp_e_runeadvanced_list = msg.e_runeadvanced_list(i);
		E_RuneAdvanced_List[i].read_from_pbmsg(temp_e_runeadvanced_list);
	}
}

E_RuneSoaringAttributeDesc_s::E_RuneSoaringAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneSoaringAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_RuneSoaringAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_RuneSoaringAttributeDesc_s::write_to_pbmsg(::proto_ff::E_RuneSoaringAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_RuneSoaringAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_RuneSoaringAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_RuneSoaring_s::E_RuneSoaring_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneSoaring_s::CreateInit() {
	m_id = (int32_t)0;
	m_lvId = (int32_t)0;
	m_wearQuality = (int32_t)0;
	m_runeId = (int32_t)0;
	return 0;
}

int E_RuneSoaring_s::ResumeInit() {
	return 0;
}

void E_RuneSoaring_s::write_to_pbmsg(::proto_ff::E_RuneSoaring & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lvid((int32_t)m_lvId);
	msg.set_m_wearquality((int32_t)m_wearQuality);
	msg.set_m_runeid((int32_t)m_runeId);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_RuneSoaringAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_RuneSoaring_s::read_from_pbmsg(const ::proto_ff::E_RuneSoaring & msg) {
	m_id = msg.m_id();
	m_lvId = msg.m_lvid();
	m_wearQuality = msg.m_wearquality();
	m_runeId = msg.m_runeid();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_RuneSoaringAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_RuneSoaring_s::Sheet_RuneSoaring_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RuneSoaring_s::CreateInit() {
	return 0;
}

int Sheet_RuneSoaring_s::ResumeInit() {
	return 0;
}

void Sheet_RuneSoaring_s::write_to_pbmsg(::proto_ff::Sheet_RuneSoaring & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RuneSoaring_List.size(); ++i) {
		::proto_ff::E_RuneSoaring* temp_e_runesoaring_list = msg.add_e_runesoaring_list();
		E_RuneSoaring_List[i].write_to_pbmsg(*temp_e_runesoaring_list);
	}
}

void Sheet_RuneSoaring_s::read_from_pbmsg(const ::proto_ff::Sheet_RuneSoaring & msg) {
	E_RuneSoaring_List.resize((int)msg.e_runesoaring_list_size() > (int)E_RuneSoaring_List.max_size() ? E_RuneSoaring_List.max_size() : msg.e_runesoaring_list_size());
	for(int32_t i = 0; i < (int32_t)E_RuneSoaring_List.size(); ++i) {
		const ::proto_ff::E_RuneSoaring & temp_e_runesoaring_list = msg.e_runesoaring_list(i);
		E_RuneSoaring_List[i].read_from_pbmsg(temp_e_runesoaring_list);
	}
}

E_RuneHandbook_s::E_RuneHandbook_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RuneHandbook_s::CreateInit() {
	m_id = (int32_t)0;
	m_lvId = (int32_t)0;
	m_rank = (int32_t)0;
	m_type = (int32_t)0;
	m_subType = (int32_t)0;
	return 0;
}

int E_RuneHandbook_s::ResumeInit() {
	return 0;
}

void E_RuneHandbook_s::write_to_pbmsg(::proto_ff::E_RuneHandbook & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lvid((int32_t)m_lvId);
	msg.set_m_rank((int32_t)m_rank);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_typename(m_typeName.data());
	msg.set_m_subtype((int32_t)m_subType);
	msg.set_m_subtypename(m_subTypeName.data());
}

void E_RuneHandbook_s::read_from_pbmsg(const ::proto_ff::E_RuneHandbook & msg) {
	m_id = msg.m_id();
	m_lvId = msg.m_lvid();
	m_rank = msg.m_rank();
	m_type = msg.m_type();
	m_typeName = msg.m_typename();
	m_subType = msg.m_subtype();
	m_subTypeName = msg.m_subtypename();
}

Sheet_RuneHandbook_s::Sheet_RuneHandbook_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RuneHandbook_s::CreateInit() {
	return 0;
}

int Sheet_RuneHandbook_s::ResumeInit() {
	return 0;
}

void Sheet_RuneHandbook_s::write_to_pbmsg(::proto_ff::Sheet_RuneHandbook & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RuneHandbook_List.size(); ++i) {
		::proto_ff::E_RuneHandbook* temp_e_runehandbook_list = msg.add_e_runehandbook_list();
		E_RuneHandbook_List[i].write_to_pbmsg(*temp_e_runehandbook_list);
	}
}

void Sheet_RuneHandbook_s::read_from_pbmsg(const ::proto_ff::Sheet_RuneHandbook & msg) {
	E_RuneHandbook_List.resize((int)msg.e_runehandbook_list_size() > (int)E_RuneHandbook_List.max_size() ? E_RuneHandbook_List.max_size() : msg.e_runehandbook_list_size());
	for(int32_t i = 0; i < (int32_t)E_RuneHandbook_List.size(); ++i) {
		const ::proto_ff::E_RuneHandbook & temp_e_runehandbook_list = msg.e_runehandbook_list(i);
		E_RuneHandbook_List[i].read_from_pbmsg(temp_e_runehandbook_list);
	}
}

}
