#include "E_Pet_s.h"

namespace proto_ff_s {

E_PetDisplayMaterialDesc_s::E_PetDisplayMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetDisplayMaterialDesc_s::CreateInit() {
	m_exp = (int32_t)0;
	m_id = (int64_t)0;
	return 0;
}

int E_PetDisplayMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_PetDisplayMaterialDesc_s::write_to_pbmsg(::proto_ff::E_PetDisplayMaterialDesc & msg) const {
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_id((int64_t)m_id);
}

void E_PetDisplayMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_PetDisplayMaterialDesc & msg) {
	m_exp = msg.m_exp();
	m_id = msg.m_id();
}

E_PetDisplay_s::E_PetDisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetDisplay_s::CreateInit() {
	m_id = (int64_t)0;
	m_quality = (int32_t)0;
	m_isStar = (int32_t)0;
	m_monsterId = (int64_t)0;
	m_activeSkillID = (int32_t)0;
	m_activeAttribute = (int32_t)0;
	m_growAtt = (int32_t)0;
	m_activeParama = (float)0;
	m_growAttParama = (float)0;
	m_growStandardA = (float)0;
	m_growStandardB = (float)0;
	m_growStandard = (float)0;
	m_growMin = (float)0;
	m_growMax = (float)0;
	m_growStar = (float)0;
	m_advanceAttribute = (int32_t)0;
	m_advanceType = (int32_t)0;
	m_petTag = (int32_t)0;
	m_starAttribute = (int32_t)0;
	m_starPercent = (int32_t)0;
	m_starLlimit = (int32_t)0;
	m_starItem = (int64_t)0;
	m_starPetID = (int64_t)0;
	m_weapon = (int32_t)0;
	m_upAttributeId = (int64_t)0;
	m_fettersID = (int32_t)0;
	return 0;
}

int E_PetDisplay_s::ResumeInit() {
	return 0;
}

void E_PetDisplay_s::write_to_pbmsg(::proto_ff::E_PetDisplay & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_isstar((int32_t)m_isStar);
	msg.set_m_grade(m_grade.data());
	msg.set_m_monsterid((int64_t)m_monsterId);
	msg.set_m_activeskillid((int32_t)m_activeSkillID);
	msg.set_m_exclusiveskillid(m_exclusiveSkillID.data());
	msg.set_m_passiveskillid(m_passiveSkillID.data());
	msg.set_m_activeattribute((int32_t)m_activeAttribute);
	msg.set_m_growatt((int32_t)m_growAtt);
	msg.set_m_activeparama((float)m_activeParama);
	msg.set_m_growattparama((float)m_growAttParama);
	msg.set_m_growstandarda((float)m_growStandardA);
	msg.set_m_growstandardb((float)m_growStandardB);
	msg.set_m_growstandard((float)m_growStandard);
	msg.set_m_growmin((float)m_growMin);
	msg.set_m_growmax((float)m_growMax);
	msg.set_m_growstar((float)m_growStar);
	msg.set_m_advanceattribute((int32_t)m_advanceAttribute);
	msg.set_m_advancetype((int32_t)m_advanceType);
	msg.set_m_pettag((int32_t)m_petTag);
	msg.set_m_pettagskill(m_petTagSkill.data());
	msg.set_m_starattribute((int32_t)m_starAttribute);
	msg.set_m_starpercent((int32_t)m_starPercent);
	msg.set_m_starllimit((int32_t)m_starLlimit);
	msg.set_m_staritem((int64_t)m_starItem);
	msg.set_m_starnum(m_starNum.data());
	msg.set_m_starpetid((int64_t)m_starPetID);
	msg.set_m_starpetnum(m_starPetNum.data());
	msg.set_m_weapon((int32_t)m_weapon);
	msg.set_m_upattributeid((int64_t)m_upAttributeId);
	msg.set_m_fettersid((int32_t)m_fettersID);
	msg.set_m_suit(m_suit.data());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_PetDisplayMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
}

void E_PetDisplay_s::read_from_pbmsg(const ::proto_ff::E_PetDisplay & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_quality = msg.m_quality();
	m_isStar = msg.m_isstar();
	m_grade = msg.m_grade();
	m_monsterId = msg.m_monsterid();
	m_activeSkillID = msg.m_activeskillid();
	m_exclusiveSkillID = msg.m_exclusiveskillid();
	m_passiveSkillID = msg.m_passiveskillid();
	m_activeAttribute = msg.m_activeattribute();
	m_growAtt = msg.m_growatt();
	m_activeParama = msg.m_activeparama();
	m_growAttParama = msg.m_growattparama();
	m_growStandardA = msg.m_growstandarda();
	m_growStandardB = msg.m_growstandardb();
	m_growStandard = msg.m_growstandard();
	m_growMin = msg.m_growmin();
	m_growMax = msg.m_growmax();
	m_growStar = msg.m_growstar();
	m_advanceAttribute = msg.m_advanceattribute();
	m_advanceType = msg.m_advancetype();
	m_petTag = msg.m_pettag();
	m_petTagSkill = msg.m_pettagskill();
	m_starAttribute = msg.m_starattribute();
	m_starPercent = msg.m_starpercent();
	m_starLlimit = msg.m_starllimit();
	m_starItem = msg.m_staritem();
	m_starNum = msg.m_starnum();
	m_starPetID = msg.m_starpetid();
	m_starPetNum = msg.m_starpetnum();
	m_weapon = msg.m_weapon();
	m_upAttributeId = msg.m_upattributeid();
	m_fettersID = msg.m_fettersid();
	m_suit = msg.m_suit();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_PetDisplayMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
}

Sheet_PetDisplay_s::Sheet_PetDisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetDisplay_s::CreateInit() {
	return 0;
}

int Sheet_PetDisplay_s::ResumeInit() {
	return 0;
}

void Sheet_PetDisplay_s::write_to_pbmsg(::proto_ff::Sheet_PetDisplay & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetDisplay_List.size(); ++i) {
		::proto_ff::E_PetDisplay* temp_e_petdisplay_list = msg.add_e_petdisplay_list();
		E_PetDisplay_List[i].write_to_pbmsg(*temp_e_petdisplay_list);
	}
}

void Sheet_PetDisplay_s::read_from_pbmsg(const ::proto_ff::Sheet_PetDisplay & msg) {
	E_PetDisplay_List.resize((int)msg.e_petdisplay_list_size() > (int)E_PetDisplay_List.max_size() ? E_PetDisplay_List.max_size() : msg.e_petdisplay_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetDisplay_List.size(); ++i) {
		const ::proto_ff::E_PetDisplay & temp_e_petdisplay_list = msg.e_petdisplay_list(i);
		E_PetDisplay_List[i].read_from_pbmsg(temp_e_petdisplay_list);
	}
}

E_PetAttributetpyeAttributeDesc_s::E_PetAttributetpyeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetAttributetpyeAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_PetAttributetpyeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_PetAttributetpyeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_PetAttributetpyeAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_PetAttributetpyeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_PetAttributetpyeAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_PetAttributetpye_s::E_PetAttributetpye_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetAttributetpye_s::CreateInit() {
	m_id = (int64_t)0;
	m_tpye = (int32_t)0;
	return 0;
}

int E_PetAttributetpye_s::ResumeInit() {
	return 0;
}

void E_PetAttributetpye_s::write_to_pbmsg(::proto_ff::E_PetAttributetpye & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_tpye((int32_t)m_tpye);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_PetAttributetpyeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_PetAttributetpye_s::read_from_pbmsg(const ::proto_ff::E_PetAttributetpye & msg) {
	m_id = msg.m_id();
	m_tpye = msg.m_tpye();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_PetAttributetpyeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_PetAttributetpye_s::Sheet_PetAttributetpye_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetAttributetpye_s::CreateInit() {
	return 0;
}

int Sheet_PetAttributetpye_s::ResumeInit() {
	return 0;
}

void Sheet_PetAttributetpye_s::write_to_pbmsg(::proto_ff::Sheet_PetAttributetpye & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetAttributetpye_List.size(); ++i) {
		::proto_ff::E_PetAttributetpye* temp_e_petattributetpye_list = msg.add_e_petattributetpye_list();
		E_PetAttributetpye_List[i].write_to_pbmsg(*temp_e_petattributetpye_list);
	}
}

void Sheet_PetAttributetpye_s::read_from_pbmsg(const ::proto_ff::Sheet_PetAttributetpye & msg) {
	E_PetAttributetpye_List.resize((int)msg.e_petattributetpye_list_size() > (int)E_PetAttributetpye_List.max_size() ? E_PetAttributetpye_List.max_size() : msg.e_petattributetpye_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetAttributetpye_List.size(); ++i) {
		const ::proto_ff::E_PetAttributetpye & temp_e_petattributetpye_list = msg.e_petattributetpye_list(i);
		E_PetAttributetpye_List[i].read_from_pbmsg(temp_e_petattributetpye_list);
	}
}

E_PetLvexp_s::E_PetLvexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetLvexp_s::CreateInit() {
	m_id = (int32_t)0;
	m_exp = (int64_t)0;
	return 0;
}

int E_PetLvexp_s::ResumeInit() {
	return 0;
}

void E_PetLvexp_s::write_to_pbmsg(::proto_ff::E_PetLvexp & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_exp((int64_t)m_exp);
}

void E_PetLvexp_s::read_from_pbmsg(const ::proto_ff::E_PetLvexp & msg) {
	m_id = msg.m_id();
	m_exp = msg.m_exp();
}

Sheet_PetLvexp_s::Sheet_PetLvexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetLvexp_s::CreateInit() {
	return 0;
}

int Sheet_PetLvexp_s::ResumeInit() {
	return 0;
}

void Sheet_PetLvexp_s::write_to_pbmsg(::proto_ff::Sheet_PetLvexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetLvexp_List.size(); ++i) {
		::proto_ff::E_PetLvexp* temp_e_petlvexp_list = msg.add_e_petlvexp_list();
		E_PetLvexp_List[i].write_to_pbmsg(*temp_e_petlvexp_list);
	}
}

void Sheet_PetLvexp_s::read_from_pbmsg(const ::proto_ff::Sheet_PetLvexp & msg) {
	E_PetLvexp_List.resize((int)msg.e_petlvexp_list_size() > (int)E_PetLvexp_List.max_size() ? E_PetLvexp_List.max_size() : msg.e_petlvexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetLvexp_List.size(); ++i) {
		const ::proto_ff::E_PetLvexp & temp_e_petlvexp_list = msg.e_petlvexp_list(i);
		E_PetLvexp_List[i].read_from_pbmsg(temp_e_petlvexp_list);
	}
}

E_PetAdvancelvAdvanceDesc_s::E_PetAdvancelvAdvanceDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetAdvancelvAdvanceDesc_s::CreateInit() {
	m_param = (float)0;
	m_type = (int32_t)0;
	return 0;
}

int E_PetAdvancelvAdvanceDesc_s::ResumeInit() {
	return 0;
}

void E_PetAdvancelvAdvanceDesc_s::write_to_pbmsg(::proto_ff::E_PetAdvancelvAdvanceDesc & msg) const {
	msg.set_m_param((float)m_param);
	msg.set_m_type((int32_t)m_type);
}

void E_PetAdvancelvAdvanceDesc_s::read_from_pbmsg(const ::proto_ff::E_PetAdvancelvAdvanceDesc & msg) {
	m_param = msg.m_param();
	m_type = msg.m_type();
}

E_PetAdvancelv_s::E_PetAdvancelv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetAdvancelv_s::CreateInit() {
	m_id = (int32_t)0;
	m_advanceItem = (int32_t)0;
	m_advanceNum = (int32_t)0;
	return 0;
}

int E_PetAdvancelv_s::ResumeInit() {
	return 0;
}

void E_PetAdvancelv_s::write_to_pbmsg(::proto_ff::E_PetAdvancelv & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_advanceitem((int32_t)m_advanceItem);
	msg.set_m_advancenum((int32_t)m_advanceNum);
	for(int32_t i = 0; i < (int32_t)m_advance.size(); ++i) {
		::proto_ff::E_PetAdvancelvAdvanceDesc* temp_m_advance = msg.add_m_advance();
		m_advance[i].write_to_pbmsg(*temp_m_advance);
	}
}

void E_PetAdvancelv_s::read_from_pbmsg(const ::proto_ff::E_PetAdvancelv & msg) {
	m_id = msg.m_id();
	m_advanceItem = msg.m_advanceitem();
	m_advanceNum = msg.m_advancenum();
	m_advance.resize((int)msg.m_advance_size() > (int)m_advance.max_size() ? m_advance.max_size() : msg.m_advance_size());
	for(int32_t i = 0; i < (int32_t)m_advance.size(); ++i) {
		const ::proto_ff::E_PetAdvancelvAdvanceDesc & temp_m_advance = msg.m_advance(i);
		m_advance[i].read_from_pbmsg(temp_m_advance);
	}
}

Sheet_PetAdvancelv_s::Sheet_PetAdvancelv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetAdvancelv_s::CreateInit() {
	return 0;
}

int Sheet_PetAdvancelv_s::ResumeInit() {
	return 0;
}

void Sheet_PetAdvancelv_s::write_to_pbmsg(::proto_ff::Sheet_PetAdvancelv & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetAdvancelv_List.size(); ++i) {
		::proto_ff::E_PetAdvancelv* temp_e_petadvancelv_list = msg.add_e_petadvancelv_list();
		E_PetAdvancelv_List[i].write_to_pbmsg(*temp_e_petadvancelv_list);
	}
}

void Sheet_PetAdvancelv_s::read_from_pbmsg(const ::proto_ff::Sheet_PetAdvancelv & msg) {
	E_PetAdvancelv_List.resize((int)msg.e_petadvancelv_list_size() > (int)E_PetAdvancelv_List.max_size() ? E_PetAdvancelv_List.max_size() : msg.e_petadvancelv_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetAdvancelv_List.size(); ++i) {
		const ::proto_ff::E_PetAdvancelv & temp_e_petadvancelv_list = msg.e_petadvancelv_list(i);
		E_PetAdvancelv_List[i].read_from_pbmsg(temp_e_petadvancelv_list);
	}
}

E_PetStarupUpattributeDesc_s::E_PetStarupUpattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetStarupUpattributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_PetStarupUpattributeDesc_s::ResumeInit() {
	return 0;
}

void E_PetStarupUpattributeDesc_s::write_to_pbmsg(::proto_ff::E_PetStarupUpattributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_PetStarupUpattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_PetStarupUpattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_PetStarup_s::E_PetStarup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetStarup_s::CreateInit() {
	m_ID = (int32_t)0;
	m_upAttributeId = (int64_t)0;
	m_starID = (int32_t)0;
	m_skillID = (int32_t)0;
	m_activeSkillIDLv = (int32_t)0;
	return 0;
}

int E_PetStarup_s::ResumeInit() {
	return 0;
}

void E_PetStarup_s::write_to_pbmsg(::proto_ff::E_PetStarup & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_upattributeid((int64_t)m_upAttributeId);
	msg.set_m_starid((int32_t)m_starID);
	msg.set_m_skillid((int32_t)m_skillID);
	msg.set_m_activeskillidlv((int32_t)m_activeSkillIDLv);
	for(int32_t i = 0; i < (int32_t)m_upAttribute.size(); ++i) {
		::proto_ff::E_PetStarupUpattributeDesc* temp_m_upattribute = msg.add_m_upattribute();
		m_upAttribute[i].write_to_pbmsg(*temp_m_upattribute);
	}
}

void E_PetStarup_s::read_from_pbmsg(const ::proto_ff::E_PetStarup & msg) {
	m_ID = msg.m_id();
	m_upAttributeId = msg.m_upattributeid();
	m_starID = msg.m_starid();
	m_skillID = msg.m_skillid();
	m_activeSkillIDLv = msg.m_activeskillidlv();
	m_upAttribute.resize((int)msg.m_upattribute_size() > (int)m_upAttribute.max_size() ? m_upAttribute.max_size() : msg.m_upattribute_size());
	for(int32_t i = 0; i < (int32_t)m_upAttribute.size(); ++i) {
		const ::proto_ff::E_PetStarupUpattributeDesc & temp_m_upattribute = msg.m_upattribute(i);
		m_upAttribute[i].read_from_pbmsg(temp_m_upattribute);
	}
}

Sheet_PetStarup_s::Sheet_PetStarup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetStarup_s::CreateInit() {
	return 0;
}

int Sheet_PetStarup_s::ResumeInit() {
	return 0;
}

void Sheet_PetStarup_s::write_to_pbmsg(::proto_ff::Sheet_PetStarup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetStarup_List.size(); ++i) {
		::proto_ff::E_PetStarup* temp_e_petstarup_list = msg.add_e_petstarup_list();
		E_PetStarup_List[i].write_to_pbmsg(*temp_e_petstarup_list);
	}
}

void Sheet_PetStarup_s::read_from_pbmsg(const ::proto_ff::Sheet_PetStarup & msg) {
	E_PetStarup_List.resize((int)msg.e_petstarup_list_size() > (int)E_PetStarup_List.max_size() ? E_PetStarup_List.max_size() : msg.e_petstarup_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetStarup_List.size(); ++i) {
		const ::proto_ff::E_PetStarup & temp_e_petstarup_list = msg.e_petstarup_list(i);
		E_PetStarup_List[i].read_from_pbmsg(temp_e_petstarup_list);
	}
}

E_PetEggPetDesc_s::E_PetEggPetDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetEggPetDesc_s::CreateInit() {
	m_rand = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_PetEggPetDesc_s::ResumeInit() {
	return 0;
}

void E_PetEggPetDesc_s::write_to_pbmsg(::proto_ff::E_PetEggPetDesc & msg) const {
	msg.set_m_rand((int32_t)m_rand);
	msg.set_m_id((int32_t)m_id);
}

void E_PetEggPetDesc_s::read_from_pbmsg(const ::proto_ff::E_PetEggPetDesc & msg) {
	m_rand = msg.m_rand();
	m_id = msg.m_id();
}

E_PetEgg_s::E_PetEgg_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetEgg_s::CreateInit() {
	m_id = (int32_t)0;
	m_time = (int32_t)0;
	return 0;
}

int E_PetEgg_s::ResumeInit() {
	return 0;
}

void E_PetEgg_s::write_to_pbmsg(::proto_ff::E_PetEgg & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_time((int32_t)m_time);
	for(int32_t i = 0; i < (int32_t)m_pet.size(); ++i) {
		::proto_ff::E_PetEggPetDesc* temp_m_pet = msg.add_m_pet();
		m_pet[i].write_to_pbmsg(*temp_m_pet);
	}
}

void E_PetEgg_s::read_from_pbmsg(const ::proto_ff::E_PetEgg & msg) {
	m_id = msg.m_id();
	m_time = msg.m_time();
	m_pet.resize((int)msg.m_pet_size() > (int)m_pet.max_size() ? m_pet.max_size() : msg.m_pet_size());
	for(int32_t i = 0; i < (int32_t)m_pet.size(); ++i) {
		const ::proto_ff::E_PetEggPetDesc & temp_m_pet = msg.m_pet(i);
		m_pet[i].read_from_pbmsg(temp_m_pet);
	}
}

Sheet_PetEgg_s::Sheet_PetEgg_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetEgg_s::CreateInit() {
	return 0;
}

int Sheet_PetEgg_s::ResumeInit() {
	return 0;
}

void Sheet_PetEgg_s::write_to_pbmsg(::proto_ff::Sheet_PetEgg & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetEgg_List.size(); ++i) {
		::proto_ff::E_PetEgg* temp_e_petegg_list = msg.add_e_petegg_list();
		E_PetEgg_List[i].write_to_pbmsg(*temp_e_petegg_list);
	}
}

void Sheet_PetEgg_s::read_from_pbmsg(const ::proto_ff::Sheet_PetEgg & msg) {
	E_PetEgg_List.resize((int)msg.e_petegg_list_size() > (int)E_PetEgg_List.max_size() ? E_PetEgg_List.max_size() : msg.e_petegg_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetEgg_List.size(); ++i) {
		const ::proto_ff::E_PetEgg & temp_e_petegg_list = msg.e_petegg_list(i);
		E_PetEgg_List[i].read_from_pbmsg(temp_e_petegg_list);
	}
}

E_PetDecomposeDecomposeDesc_s::E_PetDecomposeDecomposeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetDecomposeDecomposeDesc_s::CreateInit() {
	m_boxID = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_PetDecomposeDecomposeDesc_s::ResumeInit() {
	return 0;
}

void E_PetDecomposeDecomposeDesc_s::write_to_pbmsg(::proto_ff::E_PetDecomposeDecomposeDesc & msg) const {
	msg.set_m_boxid((int32_t)m_boxID);
	msg.set_m_type((int32_t)m_type);
}

void E_PetDecomposeDecomposeDesc_s::read_from_pbmsg(const ::proto_ff::E_PetDecomposeDecomposeDesc & msg) {
	m_boxID = msg.m_boxid();
	m_type = msg.m_type();
}

E_PetDecompose_s::E_PetDecompose_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetDecompose_s::CreateInit() {
	m_id = (int32_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_PetDecompose_s::ResumeInit() {
	return 0;
}

void E_PetDecompose_s::write_to_pbmsg(::proto_ff::E_PetDecompose & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_quality((int32_t)m_quality);
	for(int32_t i = 0; i < (int32_t)m_decompose.size(); ++i) {
		::proto_ff::E_PetDecomposeDecomposeDesc* temp_m_decompose = msg.add_m_decompose();
		m_decompose[i].write_to_pbmsg(*temp_m_decompose);
	}
}

void E_PetDecompose_s::read_from_pbmsg(const ::proto_ff::E_PetDecompose & msg) {
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_decompose.resize((int)msg.m_decompose_size() > (int)m_decompose.max_size() ? m_decompose.max_size() : msg.m_decompose_size());
	for(int32_t i = 0; i < (int32_t)m_decompose.size(); ++i) {
		const ::proto_ff::E_PetDecomposeDecomposeDesc & temp_m_decompose = msg.m_decompose(i);
		m_decompose[i].read_from_pbmsg(temp_m_decompose);
	}
}

Sheet_PetDecompose_s::Sheet_PetDecompose_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetDecompose_s::CreateInit() {
	return 0;
}

int Sheet_PetDecompose_s::ResumeInit() {
	return 0;
}

void Sheet_PetDecompose_s::write_to_pbmsg(::proto_ff::Sheet_PetDecompose & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetDecompose_List.size(); ++i) {
		::proto_ff::E_PetDecompose* temp_e_petdecompose_list = msg.add_e_petdecompose_list();
		E_PetDecompose_List[i].write_to_pbmsg(*temp_e_petdecompose_list);
	}
}

void Sheet_PetDecompose_s::read_from_pbmsg(const ::proto_ff::Sheet_PetDecompose & msg) {
	E_PetDecompose_List.resize((int)msg.e_petdecompose_list_size() > (int)E_PetDecompose_List.max_size() ? E_PetDecompose_List.max_size() : msg.e_petdecompose_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetDecompose_List.size(); ++i) {
		const ::proto_ff::E_PetDecompose & temp_e_petdecompose_list = msg.e_petdecompose_list(i);
		E_PetDecompose_List[i].read_from_pbmsg(temp_e_petdecompose_list);
	}
}

E_PetFettersAttributeDesc_s::E_PetFettersAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetFettersAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_PetFettersAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_PetFettersAttributeDesc_s::write_to_pbmsg(::proto_ff::E_PetFettersAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_PetFettersAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_PetFettersAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_PetFetters_s::E_PetFetters_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetFetters_s::CreateInit() {
	m_id = (int32_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_PetFetters_s::ResumeInit() {
	return 0;
}

void E_PetFetters_s::write_to_pbmsg(::proto_ff::E_PetFetters & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_quality((int32_t)m_quality);
	for(int32_t i = 0; i < (int32_t)m_petID.size(); ++i) {
		msg.add_m_petid((int32_t)m_petID[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_PetFettersAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_atctive_skillID.size(); ++i) {
		msg.add_m_atctive_skillid((int32_t)m_atctive_skillID[i]);
	}
}

void E_PetFetters_s::read_from_pbmsg(const ::proto_ff::E_PetFetters & msg) {
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_petID.resize((int)msg.m_petid_size() > (int)m_petID.max_size() ? m_petID.max_size() : msg.m_petid_size());
	for(int32_t i = 0; i < (int32_t)m_petID.size(); ++i) {
		m_petID[i] = msg.m_petid(i);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_PetFettersAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_atctive_skillID.resize((int)msg.m_atctive_skillid_size() > (int)m_atctive_skillID.max_size() ? m_atctive_skillID.max_size() : msg.m_atctive_skillid_size());
	for(int32_t i = 0; i < (int32_t)m_atctive_skillID.size(); ++i) {
		m_atctive_skillID[i] = msg.m_atctive_skillid(i);
	}
}

Sheet_PetFetters_s::Sheet_PetFetters_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetFetters_s::CreateInit() {
	return 0;
}

int Sheet_PetFetters_s::ResumeInit() {
	return 0;
}

void Sheet_PetFetters_s::write_to_pbmsg(::proto_ff::Sheet_PetFetters & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetFetters_List.size(); ++i) {
		::proto_ff::E_PetFetters* temp_e_petfetters_list = msg.add_e_petfetters_list();
		E_PetFetters_List[i].write_to_pbmsg(*temp_e_petfetters_list);
	}
}

void Sheet_PetFetters_s::read_from_pbmsg(const ::proto_ff::Sheet_PetFetters & msg) {
	E_PetFetters_List.resize((int)msg.e_petfetters_list_size() > (int)E_PetFetters_List.max_size() ? E_PetFetters_List.max_size() : msg.e_petfetters_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetFetters_List.size(); ++i) {
		const ::proto_ff::E_PetFetters & temp_e_petfetters_list = msg.e_petfetters_list(i);
		E_PetFetters_List[i].read_from_pbmsg(temp_e_petfetters_list);
	}
}

E_PetPetequipActDesc_s::E_PetPetequipActDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetPetequipActDesc_s::CreateInit() {
	m_Mun = (int32_t)0;
	m_Time = (int32_t)0;
	return 0;
}

int E_PetPetequipActDesc_s::ResumeInit() {
	return 0;
}

void E_PetPetequipActDesc_s::write_to_pbmsg(::proto_ff::E_PetPetequipActDesc & msg) const {
	msg.set_m_mun((int32_t)m_Mun);
	msg.set_m_time((int32_t)m_Time);
}

void E_PetPetequipActDesc_s::read_from_pbmsg(const ::proto_ff::E_PetPetequipActDesc & msg) {
	m_Mun = msg.m_mun();
	m_Time = msg.m_time();
}

E_PetPetequip_s::E_PetPetequip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetPetequip_s::CreateInit() {
	m_pet = (int32_t)0;
	m_orderId = (int32_t)0;
	m_qeuidItem = (int32_t)0;
	m_equipQualityMin = (int32_t)0;
	m_equipModelId = (int32_t)0;
	m_forging = (int32_t)0;
	m_star = (int32_t)0;
	return 0;
}

int E_PetPetequip_s::ResumeInit() {
	return 0;
}

void E_PetPetequip_s::write_to_pbmsg(::proto_ff::E_PetPetequip & msg) const {
	msg.set_m_pet((int32_t)m_pet);
	msg.set_m_orderid((int32_t)m_orderId);
	msg.set_m_name(m_name.data());
	msg.set_m_qeuiditem((int32_t)m_qeuidItem);
	msg.set_m_equipqualitymin((int32_t)m_equipQualityMin);
	msg.set_m_equipmodelid((int32_t)m_equipModelId);
	msg.set_m_forging((int32_t)m_forging);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_skill(m_skill.data());
	for(int32_t i = 0; i < (int32_t)m_act.size(); ++i) {
		::proto_ff::E_PetPetequipActDesc* temp_m_act = msg.add_m_act();
		m_act[i].write_to_pbmsg(*temp_m_act);
	}
}

void E_PetPetequip_s::read_from_pbmsg(const ::proto_ff::E_PetPetequip & msg) {
	m_pet = msg.m_pet();
	m_orderId = msg.m_orderid();
	m_name = msg.m_name();
	m_qeuidItem = msg.m_qeuiditem();
	m_equipQualityMin = msg.m_equipqualitymin();
	m_equipModelId = msg.m_equipmodelid();
	m_forging = msg.m_forging();
	m_star = msg.m_star();
	m_skill = msg.m_skill();
	m_act.resize((int)msg.m_act_size() > (int)m_act.max_size() ? m_act.max_size() : msg.m_act_size());
	for(int32_t i = 0; i < (int32_t)m_act.size(); ++i) {
		const ::proto_ff::E_PetPetequipActDesc & temp_m_act = msg.m_act(i);
		m_act[i].read_from_pbmsg(temp_m_act);
	}
}

Sheet_PetPetequip_s::Sheet_PetPetequip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetPetequip_s::CreateInit() {
	return 0;
}

int Sheet_PetPetequip_s::ResumeInit() {
	return 0;
}

void Sheet_PetPetequip_s::write_to_pbmsg(::proto_ff::Sheet_PetPetequip & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetPetequip_List.size(); ++i) {
		::proto_ff::E_PetPetequip* temp_e_petpetequip_list = msg.add_e_petpetequip_list();
		E_PetPetequip_List[i].write_to_pbmsg(*temp_e_petpetequip_list);
	}
}

void Sheet_PetPetequip_s::read_from_pbmsg(const ::proto_ff::Sheet_PetPetequip & msg) {
	E_PetPetequip_List.resize((int)msg.e_petpetequip_list_size() > (int)E_PetPetequip_List.max_size() ? E_PetPetequip_List.max_size() : msg.e_petpetequip_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetPetequip_List.size(); ++i) {
		const ::proto_ff::E_PetPetequip & temp_e_petpetequip_list = msg.e_petpetequip_list(i);
		E_PetPetequip_List[i].read_from_pbmsg(temp_e_petpetequip_list);
	}
}

E_PetEquipvalueAttributeDesc_s::E_PetEquipvalueAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetEquipvalueAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_PetEquipvalueAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_PetEquipvalueAttributeDesc_s::write_to_pbmsg(::proto_ff::E_PetEquipvalueAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_PetEquipvalueAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_PetEquipvalueAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_PetEquipvalueExtraDesc_s::E_PetEquipvalueExtraDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetEquipvalueExtraDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_PetEquipvalueExtraDesc_s::ResumeInit() {
	return 0;
}

void E_PetEquipvalueExtraDesc_s::write_to_pbmsg(::proto_ff::E_PetEquipvalueExtraDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_PetEquipvalueExtraDesc_s::read_from_pbmsg(const ::proto_ff::E_PetEquipvalueExtraDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_PetEquipvalue_s::E_PetEquipvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetEquipvalue_s::CreateInit() {
	m_id = (int32_t)0;
	m_equipValue = (int32_t)0;
	m_equipLv = (int32_t)0;
	m_item = (int32_t)0;
	m_winProb = (int32_t)0;
	m_equipItem = (int32_t)0;
	m_equipMun = (int32_t)0;
	m_failMax = (int32_t)0;
	return 0;
}

int E_PetEquipvalue_s::ResumeInit() {
	return 0;
}

void E_PetEquipvalue_s::write_to_pbmsg(::proto_ff::E_PetEquipvalue & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_equipvalue((int32_t)m_equipValue);
	msg.set_m_equiplv((int32_t)m_equipLv);
	msg.set_m_item((int32_t)m_item);
	msg.set_m_winprob((int32_t)m_winProb);
	msg.set_m_equipitem((int32_t)m_equipItem);
	msg.set_m_equipmun((int32_t)m_equipMun);
	msg.set_m_failmax((int32_t)m_failMax);
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_PetEquipvalueAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_extra.size(); ++i) {
		::proto_ff::E_PetEquipvalueExtraDesc* temp_m_extra = msg.add_m_extra();
		m_extra[i].write_to_pbmsg(*temp_m_extra);
	}
}

void E_PetEquipvalue_s::read_from_pbmsg(const ::proto_ff::E_PetEquipvalue & msg) {
	m_id = msg.m_id();
	m_equipValue = msg.m_equipvalue();
	m_equipLv = msg.m_equiplv();
	m_item = msg.m_item();
	m_winProb = msg.m_winprob();
	m_equipItem = msg.m_equipitem();
	m_equipMun = msg.m_equipmun();
	m_failMax = msg.m_failmax();
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_PetEquipvalueAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_extra.resize((int)msg.m_extra_size() > (int)m_extra.max_size() ? m_extra.max_size() : msg.m_extra_size());
	for(int32_t i = 0; i < (int32_t)m_extra.size(); ++i) {
		const ::proto_ff::E_PetEquipvalueExtraDesc & temp_m_extra = msg.m_extra(i);
		m_extra[i].read_from_pbmsg(temp_m_extra);
	}
}

Sheet_PetEquipvalue_s::Sheet_PetEquipvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetEquipvalue_s::CreateInit() {
	return 0;
}

int Sheet_PetEquipvalue_s::ResumeInit() {
	return 0;
}

void Sheet_PetEquipvalue_s::write_to_pbmsg(::proto_ff::Sheet_PetEquipvalue & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetEquipvalue_List.size(); ++i) {
		::proto_ff::E_PetEquipvalue* temp_e_petequipvalue_list = msg.add_e_petequipvalue_list();
		E_PetEquipvalue_List[i].write_to_pbmsg(*temp_e_petequipvalue_list);
	}
}

void Sheet_PetEquipvalue_s::read_from_pbmsg(const ::proto_ff::Sheet_PetEquipvalue & msg) {
	E_PetEquipvalue_List.resize((int)msg.e_petequipvalue_list_size() > (int)E_PetEquipvalue_List.max_size() ? E_PetEquipvalue_List.max_size() : msg.e_petequipvalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetEquipvalue_List.size(); ++i) {
		const ::proto_ff::E_PetEquipvalue & temp_e_petequipvalue_list = msg.e_petequipvalue_list(i);
		E_PetEquipvalue_List[i].read_from_pbmsg(temp_e_petequipvalue_list);
	}
}

E_PetStarvalueAttributeDesc_s::E_PetStarvalueAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetStarvalueAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_PetStarvalueAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_PetStarvalueAttributeDesc_s::write_to_pbmsg(::proto_ff::E_PetStarvalueAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_PetStarvalueAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_PetStarvalueAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_PetStarvalueEquipDesc_s::E_PetStarvalueEquipDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetStarvalueEquipDesc_s::CreateInit() {
	m_Mun = (int32_t)0;
	m_Item = (int32_t)0;
	return 0;
}

int E_PetStarvalueEquipDesc_s::ResumeInit() {
	return 0;
}

void E_PetStarvalueEquipDesc_s::write_to_pbmsg(::proto_ff::E_PetStarvalueEquipDesc & msg) const {
	msg.set_m_mun((int32_t)m_Mun);
	msg.set_m_item((int32_t)m_Item);
}

void E_PetStarvalueEquipDesc_s::read_from_pbmsg(const ::proto_ff::E_PetStarvalueEquipDesc & msg) {
	m_Mun = msg.m_mun();
	m_Item = msg.m_item();
}

E_PetStarvalue_s::E_PetStarvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetStarvalue_s::CreateInit() {
	m_id = (int32_t)0;
	m_starValue = (int32_t)0;
	m_starLv = (int32_t)0;
	return 0;
}

int E_PetStarvalue_s::ResumeInit() {
	return 0;
}

void E_PetStarvalue_s::write_to_pbmsg(::proto_ff::E_PetStarvalue & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_starvalue((int32_t)m_starValue);
	msg.set_m_starlv((int32_t)m_starLv);
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_PetStarvalueAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_advance_Type.size(); ++i) {
		msg.add_m_advance_type(m_advance_Type[i].data());
	}
	for(int32_t i = 0; i < (int32_t)m_equip.size(); ++i) {
		::proto_ff::E_PetStarvalueEquipDesc* temp_m_equip = msg.add_m_equip();
		m_equip[i].write_to_pbmsg(*temp_m_equip);
	}
}

void E_PetStarvalue_s::read_from_pbmsg(const ::proto_ff::E_PetStarvalue & msg) {
	m_id = msg.m_id();
	m_starValue = msg.m_starvalue();
	m_starLv = msg.m_starlv();
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_PetStarvalueAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_advance_Type.resize((int)msg.m_advance_type_size() > (int)m_advance_Type.max_size() ? m_advance_Type.max_size() : msg.m_advance_type_size());
	for(int32_t i = 0; i < (int32_t)m_advance_Type.size(); ++i) {
		m_advance_Type[i] = msg.m_advance_type(i);
	}
	m_equip.resize((int)msg.m_equip_size() > (int)m_equip.max_size() ? m_equip.max_size() : msg.m_equip_size());
	for(int32_t i = 0; i < (int32_t)m_equip.size(); ++i) {
		const ::proto_ff::E_PetStarvalueEquipDesc & temp_m_equip = msg.m_equip(i);
		m_equip[i].read_from_pbmsg(temp_m_equip);
	}
}

Sheet_PetStarvalue_s::Sheet_PetStarvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetStarvalue_s::CreateInit() {
	return 0;
}

int Sheet_PetStarvalue_s::ResumeInit() {
	return 0;
}

void Sheet_PetStarvalue_s::write_to_pbmsg(::proto_ff::Sheet_PetStarvalue & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetStarvalue_List.size(); ++i) {
		::proto_ff::E_PetStarvalue* temp_e_petstarvalue_list = msg.add_e_petstarvalue_list();
		E_PetStarvalue_List[i].write_to_pbmsg(*temp_e_petstarvalue_list);
	}
}

void Sheet_PetStarvalue_s::read_from_pbmsg(const ::proto_ff::Sheet_PetStarvalue & msg) {
	E_PetStarvalue_List.resize((int)msg.e_petstarvalue_list_size() > (int)E_PetStarvalue_List.max_size() ? E_PetStarvalue_List.max_size() : msg.e_petstarvalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetStarvalue_List.size(); ++i) {
		const ::proto_ff::E_PetStarvalue & temp_e_petstarvalue_list = msg.e_petstarvalue_list(i);
		E_PetStarvalue_List[i].read_from_pbmsg(temp_e_petstarvalue_list);
	}
}

E_PetWraithsAttributeDesc_s::E_PetWraithsAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetWraithsAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_PetWraithsAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_PetWraithsAttributeDesc_s::write_to_pbmsg(::proto_ff::E_PetWraithsAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_PetWraithsAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_PetWraithsAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_PetWraithsAttributebctDesc_s::E_PetWraithsAttributebctDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetWraithsAttributebctDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_PetWraithsAttributebctDesc_s::ResumeInit() {
	return 0;
}

void E_PetWraithsAttributebctDesc_s::write_to_pbmsg(::proto_ff::E_PetWraithsAttributebctDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_PetWraithsAttributebctDesc_s::read_from_pbmsg(const ::proto_ff::E_PetWraithsAttributebctDesc & msg) {
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_PetWraiths_s::E_PetWraiths_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetWraiths_s::CreateInit() {
	m_id = (int32_t)0;
	m_name = (int32_t)0;
	m_affix = (int32_t)0;
	m_position = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	m_propertyLv = (int32_t)0;
	m_propertyTop = (int32_t)0;
	return 0;
}

int E_PetWraiths_s::ResumeInit() {
	return 0;
}

void E_PetWraiths_s::write_to_pbmsg(::proto_ff::E_PetWraiths & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name((int32_t)m_name);
	msg.set_m_affix((int32_t)m_affix);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_propertylv((int32_t)m_propertyLv);
	msg.set_m_propertytop((int32_t)m_propertyTop);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_PetWraithsAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_attributeBct.size(); ++i) {
		::proto_ff::E_PetWraithsAttributebctDesc* temp_m_attributebct = msg.add_m_attributebct();
		m_attributeBct[i].write_to_pbmsg(*temp_m_attributebct);
	}
}

void E_PetWraiths_s::read_from_pbmsg(const ::proto_ff::E_PetWraiths & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_affix = msg.m_affix();
	m_position = msg.m_position();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_propertyLv = msg.m_propertylv();
	m_propertyTop = msg.m_propertytop();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_PetWraithsAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_attributeBct.resize((int)msg.m_attributebct_size() > (int)m_attributeBct.max_size() ? m_attributeBct.max_size() : msg.m_attributebct_size());
	for(int32_t i = 0; i < (int32_t)m_attributeBct.size(); ++i) {
		const ::proto_ff::E_PetWraithsAttributebctDesc & temp_m_attributebct = msg.m_attributebct(i);
		m_attributeBct[i].read_from_pbmsg(temp_m_attributebct);
	}
}

Sheet_PetWraiths_s::Sheet_PetWraiths_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetWraiths_s::CreateInit() {
	return 0;
}

int Sheet_PetWraiths_s::ResumeInit() {
	return 0;
}

void Sheet_PetWraiths_s::write_to_pbmsg(::proto_ff::Sheet_PetWraiths & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetWraiths_List.size(); ++i) {
		::proto_ff::E_PetWraiths* temp_e_petwraiths_list = msg.add_e_petwraiths_list();
		E_PetWraiths_List[i].write_to_pbmsg(*temp_e_petwraiths_list);
	}
}

void Sheet_PetWraiths_s::read_from_pbmsg(const ::proto_ff::Sheet_PetWraiths & msg) {
	E_PetWraiths_List.resize((int)msg.e_petwraiths_list_size() > (int)E_PetWraiths_List.max_size() ? E_PetWraiths_List.max_size() : msg.e_petwraiths_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetWraiths_List.size(); ++i) {
		const ::proto_ff::E_PetWraiths & temp_e_petwraiths_list = msg.e_petwraiths_list(i);
		E_PetWraiths_List[i].read_from_pbmsg(temp_e_petwraiths_list);
	}
}

E_PetWraithslvAttributeDesc_s::E_PetWraithslvAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetWraithslvAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_PetWraithslvAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_PetWraithslvAttributeDesc_s::write_to_pbmsg(::proto_ff::E_PetWraithslvAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_PetWraithslvAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_PetWraithslvAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_PetWraithslv_s::E_PetWraithslv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetWraithslv_s::CreateInit() {
	m_id = (int32_t)0;
	m_value = (int32_t)0;
	m_advanceLv = (int32_t)0;
	m_lv = (int32_t)0;
	m_wraithsItem = (int32_t)0;
	m_wraithsMun = (int32_t)0;
	m_lvExp = (int32_t)0;
	return 0;
}

int E_PetWraithslv_s::ResumeInit() {
	return 0;
}

void E_PetWraithslv_s::write_to_pbmsg(::proto_ff::E_PetWraithslv & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_advancelv((int32_t)m_advanceLv);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_wraithsitem((int32_t)m_wraithsItem);
	msg.set_m_wraithsmun((int32_t)m_wraithsMun);
	msg.set_m_lvexp((int32_t)m_lvExp);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_PetWraithslvAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_PetWraithslv_s::read_from_pbmsg(const ::proto_ff::E_PetWraithslv & msg) {
	m_id = msg.m_id();
	m_value = msg.m_value();
	m_advanceLv = msg.m_advancelv();
	m_lv = msg.m_lv();
	m_wraithsItem = msg.m_wraithsitem();
	m_wraithsMun = msg.m_wraithsmun();
	m_lvExp = msg.m_lvexp();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_PetWraithslvAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_PetWraithslv_s::Sheet_PetWraithslv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetWraithslv_s::CreateInit() {
	return 0;
}

int Sheet_PetWraithslv_s::ResumeInit() {
	return 0;
}

void Sheet_PetWraithslv_s::write_to_pbmsg(::proto_ff::Sheet_PetWraithslv & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetWraithslv_List.size(); ++i) {
		::proto_ff::E_PetWraithslv* temp_e_petwraithslv_list = msg.add_e_petwraithslv_list();
		E_PetWraithslv_List[i].write_to_pbmsg(*temp_e_petwraithslv_list);
	}
}

void Sheet_PetWraithslv_s::read_from_pbmsg(const ::proto_ff::Sheet_PetWraithslv & msg) {
	E_PetWraithslv_List.resize((int)msg.e_petwraithslv_list_size() > (int)E_PetWraithslv_List.max_size() ? E_PetWraithslv_List.max_size() : msg.e_petwraithslv_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetWraithslv_List.size(); ++i) {
		const ::proto_ff::E_PetWraithslv & temp_e_petwraithslv_list = msg.e_petwraithslv_list(i);
		E_PetWraithslv_List[i].read_from_pbmsg(temp_e_petwraithslv_list);
	}
}

E_PetSmeltItemDesc_s::E_PetSmeltItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetSmeltItemDesc_s::CreateInit() {
	m_maxNum = (int32_t)0;
	m_minNum = (int32_t)0;
	m_rarerand = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_PetSmeltItemDesc_s::ResumeInit() {
	return 0;
}

void E_PetSmeltItemDesc_s::write_to_pbmsg(::proto_ff::E_PetSmeltItemDesc & msg) const {
	msg.set_m_maxnum((int32_t)m_maxNum);
	msg.set_m_minnum((int32_t)m_minNum);
	msg.set_m_rarerand((int32_t)m_rarerand);
	msg.set_m_id((int32_t)m_id);
}

void E_PetSmeltItemDesc_s::read_from_pbmsg(const ::proto_ff::E_PetSmeltItemDesc & msg) {
	m_maxNum = msg.m_maxnum();
	m_minNum = msg.m_minnum();
	m_rarerand = msg.m_rarerand();
	m_id = msg.m_id();
}

E_PetSmelt_s::E_PetSmelt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetSmelt_s::CreateInit() {
	m_id = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	m_putMun = (int32_t)0;
	m_smeltExp = (int32_t)0;
	m_monsterNum = (int32_t)0;
	return 0;
}

int E_PetSmelt_s::ResumeInit() {
	return 0;
}

void E_PetSmelt_s::write_to_pbmsg(::proto_ff::E_PetSmelt & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_putmun((int32_t)m_putMun);
	msg.set_m_smeltexp((int32_t)m_smeltExp);
	msg.set_m_monsternum((int32_t)m_monsterNum);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_PetSmeltItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_PetSmelt_s::read_from_pbmsg(const ::proto_ff::E_PetSmelt & msg) {
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_putMun = msg.m_putmun();
	m_smeltExp = msg.m_smeltexp();
	m_monsterNum = msg.m_monsternum();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_PetSmeltItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
}

Sheet_PetSmelt_s::Sheet_PetSmelt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetSmelt_s::CreateInit() {
	return 0;
}

int Sheet_PetSmelt_s::ResumeInit() {
	return 0;
}

void Sheet_PetSmelt_s::write_to_pbmsg(::proto_ff::Sheet_PetSmelt & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetSmelt_List.size(); ++i) {
		::proto_ff::E_PetSmelt* temp_e_petsmelt_list = msg.add_e_petsmelt_list();
		E_PetSmelt_List[i].write_to_pbmsg(*temp_e_petsmelt_list);
	}
}

void Sheet_PetSmelt_s::read_from_pbmsg(const ::proto_ff::Sheet_PetSmelt & msg) {
	E_PetSmelt_List.resize((int)msg.e_petsmelt_list_size() > (int)E_PetSmelt_List.max_size() ? E_PetSmelt_List.max_size() : msg.e_petsmelt_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetSmelt_List.size(); ++i) {
		const ::proto_ff::E_PetSmelt & temp_e_petsmelt_list = msg.e_petsmelt_list(i);
		E_PetSmelt_List[i].read_from_pbmsg(temp_e_petsmelt_list);
	}
}

E_PetRefineconversion_s::E_PetRefineconversion_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetRefineconversion_s::CreateInit() {
	m_itemid = (int32_t)0;
	m_group = (int32_t)0;
	m_num = (int32_t)0;
	m_condition = (int32_t)0;
	return 0;
}

int E_PetRefineconversion_s::ResumeInit() {
	return 0;
}

void E_PetRefineconversion_s::write_to_pbmsg(::proto_ff::E_PetRefineconversion & msg) const {
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_condition((int32_t)m_condition);
}

void E_PetRefineconversion_s::read_from_pbmsg(const ::proto_ff::E_PetRefineconversion & msg) {
	m_itemid = msg.m_itemid();
	m_group = msg.m_group();
	m_num = msg.m_num();
	m_condition = msg.m_condition();
}

Sheet_PetRefineconversion_s::Sheet_PetRefineconversion_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetRefineconversion_s::CreateInit() {
	return 0;
}

int Sheet_PetRefineconversion_s::ResumeInit() {
	return 0;
}

void Sheet_PetRefineconversion_s::write_to_pbmsg(::proto_ff::Sheet_PetRefineconversion & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetRefineconversion_List.size(); ++i) {
		::proto_ff::E_PetRefineconversion* temp_e_petrefineconversion_list = msg.add_e_petrefineconversion_list();
		E_PetRefineconversion_List[i].write_to_pbmsg(*temp_e_petrefineconversion_list);
	}
}

void Sheet_PetRefineconversion_s::read_from_pbmsg(const ::proto_ff::Sheet_PetRefineconversion & msg) {
	E_PetRefineconversion_List.resize((int)msg.e_petrefineconversion_list_size() > (int)E_PetRefineconversion_List.max_size() ? E_PetRefineconversion_List.max_size() : msg.e_petrefineconversion_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetRefineconversion_List.size(); ++i) {
		const ::proto_ff::E_PetRefineconversion & temp_e_petrefineconversion_list = msg.e_petrefineconversion_list(i);
		E_PetRefineconversion_List[i].read_from_pbmsg(temp_e_petrefineconversion_list);
	}
}

E_PetStoveStoveDesc_s::E_PetStoveStoveDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetStoveStoveDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_PetStoveStoveDesc_s::ResumeInit() {
	return 0;
}

void E_PetStoveStoveDesc_s::write_to_pbmsg(::proto_ff::E_PetStoveStoveDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_value((int32_t)m_value);
}

void E_PetStoveStoveDesc_s::read_from_pbmsg(const ::proto_ff::E_PetStoveStoveDesc & msg) {
	m_num = msg.m_num();
	m_value = msg.m_value();
}

E_PetStove_s::E_PetStove_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetStove_s::CreateInit() {
	m_lv = (int32_t)0;
	m_exp = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	return 0;
}

int E_PetStove_s::ResumeInit() {
	return 0;
}

void E_PetStove_s::write_to_pbmsg(::proto_ff::E_PetStove & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	for(int32_t i = 0; i < (int32_t)m_stove.size(); ++i) {
		::proto_ff::E_PetStoveStoveDesc* temp_m_stove = msg.add_m_stove();
		m_stove[i].write_to_pbmsg(*temp_m_stove);
	}
}

void E_PetStove_s::read_from_pbmsg(const ::proto_ff::E_PetStove & msg) {
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_stove.resize((int)msg.m_stove_size() > (int)m_stove.max_size() ? m_stove.max_size() : msg.m_stove_size());
	for(int32_t i = 0; i < (int32_t)m_stove.size(); ++i) {
		const ::proto_ff::E_PetStoveStoveDesc & temp_m_stove = msg.m_stove(i);
		m_stove[i].read_from_pbmsg(temp_m_stove);
	}
}

Sheet_PetStove_s::Sheet_PetStove_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetStove_s::CreateInit() {
	return 0;
}

int Sheet_PetStove_s::ResumeInit() {
	return 0;
}

void Sheet_PetStove_s::write_to_pbmsg(::proto_ff::Sheet_PetStove & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetStove_List.size(); ++i) {
		::proto_ff::E_PetStove* temp_e_petstove_list = msg.add_e_petstove_list();
		E_PetStove_List[i].write_to_pbmsg(*temp_e_petstove_list);
	}
}

void Sheet_PetStove_s::read_from_pbmsg(const ::proto_ff::Sheet_PetStove & msg) {
	E_PetStove_List.resize((int)msg.e_petstove_list_size() > (int)E_PetStove_List.max_size() ? E_PetStove_List.max_size() : msg.e_petstove_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetStove_List.size(); ++i) {
		const ::proto_ff::E_PetStove & temp_e_petstove_list = msg.e_petstove_list(i);
		E_PetStove_List[i].read_from_pbmsg(temp_e_petstove_list);
	}
}

E_PetSuitAttributeDesc_s::E_PetSuitAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetSuitAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_PetSuitAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_PetSuitAttributeDesc_s::write_to_pbmsg(::proto_ff::E_PetSuitAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_PetSuitAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_PetSuitAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_PetSuit_s::E_PetSuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetSuit_s::CreateInit() {
	m_id = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	m_wraithsQuality = (int32_t)0;
	m_piece = (int32_t)0;
	m_resonanceType = (int32_t)0;
	m_resonanceValue = (int32_t)0;
	return 0;
}

int E_PetSuit_s::ResumeInit() {
	return 0;
}

void E_PetSuit_s::write_to_pbmsg(::proto_ff::E_PetSuit & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_wraithsquality((int32_t)m_wraithsQuality);
	msg.set_m_piece((int32_t)m_piece);
	msg.set_m_resonancetype((int32_t)m_resonanceType);
	msg.set_m_resonancevalue((int32_t)m_resonanceValue);
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_PetSuitAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_PetSuit_s::read_from_pbmsg(const ::proto_ff::E_PetSuit & msg) {
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_wraithsQuality = msg.m_wraithsquality();
	m_piece = msg.m_piece();
	m_resonanceType = msg.m_resonancetype();
	m_resonanceValue = msg.m_resonancevalue();
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_PetSuitAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_PetSuit_s::Sheet_PetSuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetSuit_s::CreateInit() {
	return 0;
}

int Sheet_PetSuit_s::ResumeInit() {
	return 0;
}

void Sheet_PetSuit_s::write_to_pbmsg(::proto_ff::Sheet_PetSuit & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetSuit_List.size(); ++i) {
		::proto_ff::E_PetSuit* temp_e_petsuit_list = msg.add_e_petsuit_list();
		E_PetSuit_List[i].write_to_pbmsg(*temp_e_petsuit_list);
	}
}

void Sheet_PetSuit_s::read_from_pbmsg(const ::proto_ff::Sheet_PetSuit & msg) {
	E_PetSuit_List.resize((int)msg.e_petsuit_list_size() > (int)E_PetSuit_List.max_size() ? E_PetSuit_List.max_size() : msg.e_petsuit_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetSuit_List.size(); ++i) {
		const ::proto_ff::E_PetSuit & temp_e_petsuit_list = msg.e_petsuit_list(i);
		E_PetSuit_List[i].read_from_pbmsg(temp_e_petsuit_list);
	}
}

E_PetConstMaterialDesc_s::E_PetConstMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetConstMaterialDesc_s::CreateInit() {
	m_exp = (int32_t)0;
	m_item = (int32_t)0;
	return 0;
}

int E_PetConstMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_PetConstMaterialDesc_s::write_to_pbmsg(::proto_ff::E_PetConstMaterialDesc & msg) const {
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_item((int32_t)m_item);
}

void E_PetConstMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_PetConstMaterialDesc & msg) {
	m_exp = msg.m_exp();
	m_item = msg.m_item();
}

E_PetConst_s::E_PetConst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetConst_s::CreateInit() {
	m_id = (int32_t)0;
	m_open = (int32_t)0;
	m_solt = (int32_t)0;
	m_item = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_PetConst_s::ResumeInit() {
	return 0;
}

void E_PetConst_s::write_to_pbmsg(::proto_ff::E_PetConst & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_open((int32_t)m_open);
	msg.set_m_solt((int32_t)m_solt);
	msg.set_m_item((int32_t)m_item);
	msg.set_m_num((int32_t)m_num);
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_PetConstMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
}

void E_PetConst_s::read_from_pbmsg(const ::proto_ff::E_PetConst & msg) {
	m_id = msg.m_id();
	m_open = msg.m_open();
	m_solt = msg.m_solt();
	m_item = msg.m_item();
	m_num = msg.m_num();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_PetConstMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
}

Sheet_PetConst_s::Sheet_PetConst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetConst_s::CreateInit() {
	return 0;
}

int Sheet_PetConst_s::ResumeInit() {
	return 0;
}

void Sheet_PetConst_s::write_to_pbmsg(::proto_ff::Sheet_PetConst & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetConst_List.size(); ++i) {
		::proto_ff::E_PetConst* temp_e_petconst_list = msg.add_e_petconst_list();
		E_PetConst_List[i].write_to_pbmsg(*temp_e_petconst_list);
	}
}

void Sheet_PetConst_s::read_from_pbmsg(const ::proto_ff::Sheet_PetConst & msg) {
	E_PetConst_List.resize((int)msg.e_petconst_list_size() > (int)E_PetConst_List.max_size() ? E_PetConst_List.max_size() : msg.e_petconst_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetConst_List.size(); ++i) {
		const ::proto_ff::E_PetConst & temp_e_petconst_list = msg.e_petconst_list(i);
		E_PetConst_List[i].read_from_pbmsg(temp_e_petconst_list);
	}
}

E_PetTopAttributeDesc_s::E_PetTopAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetTopAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_PetTopAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_PetTopAttributeDesc_s::write_to_pbmsg(::proto_ff::E_PetTopAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_PetTopAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_PetTopAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_PetTopStarattDesc_s::E_PetTopStarattDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetTopStarattDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_PetTopStarattDesc_s::ResumeInit() {
	return 0;
}

void E_PetTopStarattDesc_s::write_to_pbmsg(::proto_ff::E_PetTopStarattDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_PetTopStarattDesc_s::read_from_pbmsg(const ::proto_ff::E_PetTopStarattDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_PetTop_s::E_PetTop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetTop_s::CreateInit() {
	m_topType = (int32_t)0;
	return 0;
}

int E_PetTop_s::ResumeInit() {
	return 0;
}

void E_PetTop_s::write_to_pbmsg(::proto_ff::E_PetTop & msg) const {
	msg.set_m_toptype((int32_t)m_topType);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_PetTopAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_starAtt.size(); ++i) {
		::proto_ff::E_PetTopStarattDesc* temp_m_staratt = msg.add_m_staratt();
		m_starAtt[i].write_to_pbmsg(*temp_m_staratt);
	}
}

void E_PetTop_s::read_from_pbmsg(const ::proto_ff::E_PetTop & msg) {
	m_topType = msg.m_toptype();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_PetTopAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_starAtt.resize((int)msg.m_staratt_size() > (int)m_starAtt.max_size() ? m_starAtt.max_size() : msg.m_staratt_size());
	for(int32_t i = 0; i < (int32_t)m_starAtt.size(); ++i) {
		const ::proto_ff::E_PetTopStarattDesc & temp_m_staratt = msg.m_staratt(i);
		m_starAtt[i].read_from_pbmsg(temp_m_staratt);
	}
}

Sheet_PetTop_s::Sheet_PetTop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetTop_s::CreateInit() {
	return 0;
}

int Sheet_PetTop_s::ResumeInit() {
	return 0;
}

void Sheet_PetTop_s::write_to_pbmsg(::proto_ff::Sheet_PetTop & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetTop_List.size(); ++i) {
		::proto_ff::E_PetTop* temp_e_pettop_list = msg.add_e_pettop_list();
		E_PetTop_List[i].write_to_pbmsg(*temp_e_pettop_list);
	}
}

void Sheet_PetTop_s::read_from_pbmsg(const ::proto_ff::Sheet_PetTop & msg) {
	E_PetTop_List.resize((int)msg.e_pettop_list_size() > (int)E_PetTop_List.max_size() ? E_PetTop_List.max_size() : msg.e_pettop_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetTop_List.size(); ++i) {
		const ::proto_ff::E_PetTop & temp_e_pettop_list = msg.e_pettop_list(i);
		E_PetTop_List[i].read_from_pbmsg(temp_e_pettop_list);
	}
}

E_PetTopitem_s::E_PetTopitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetTopitem_s::CreateInit() {
	m_lv = (int32_t)0;
	m_item = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_PetTopitem_s::ResumeInit() {
	return 0;
}

void E_PetTopitem_s::write_to_pbmsg(::proto_ff::E_PetTopitem & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_item((int32_t)m_item);
	msg.set_m_num((int32_t)m_num);
}

void E_PetTopitem_s::read_from_pbmsg(const ::proto_ff::E_PetTopitem & msg) {
	m_lv = msg.m_lv();
	m_item = msg.m_item();
	m_num = msg.m_num();
}

Sheet_PetTopitem_s::Sheet_PetTopitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetTopitem_s::CreateInit() {
	return 0;
}

int Sheet_PetTopitem_s::ResumeInit() {
	return 0;
}

void Sheet_PetTopitem_s::write_to_pbmsg(::proto_ff::Sheet_PetTopitem & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetTopitem_List.size(); ++i) {
		::proto_ff::E_PetTopitem* temp_e_pettopitem_list = msg.add_e_pettopitem_list();
		E_PetTopitem_List[i].write_to_pbmsg(*temp_e_pettopitem_list);
	}
}

void Sheet_PetTopitem_s::read_from_pbmsg(const ::proto_ff::Sheet_PetTopitem & msg) {
	E_PetTopitem_List.resize((int)msg.e_pettopitem_list_size() > (int)E_PetTopitem_List.max_size() ? E_PetTopitem_List.max_size() : msg.e_pettopitem_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetTopitem_List.size(); ++i) {
		const ::proto_ff::E_PetTopitem & temp_e_pettopitem_list = msg.e_pettopitem_list(i);
		E_PetTopitem_List[i].read_from_pbmsg(temp_e_pettopitem_list);
	}
}

E_PetPrivilegePrivilegeDesc_s::E_PetPrivilegePrivilegeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetPrivilegePrivilegeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_att = (int32_t)0;
	return 0;
}

int E_PetPrivilegePrivilegeDesc_s::ResumeInit() {
	return 0;
}

void E_PetPrivilegePrivilegeDesc_s::write_to_pbmsg(::proto_ff::E_PetPrivilegePrivilegeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_att((int32_t)m_att);
}

void E_PetPrivilegePrivilegeDesc_s::read_from_pbmsg(const ::proto_ff::E_PetPrivilegePrivilegeDesc & msg) {
	m_value = msg.m_value();
	m_att = msg.m_att();
}

E_PetPrivilege_s::E_PetPrivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetPrivilege_s::CreateInit() {
	m_id = (int32_t)0;
	m_doubleItem = (int32_t)0;
	m_experienceExp = (int32_t)0;
	return 0;
}

int E_PetPrivilege_s::ResumeInit() {
	return 0;
}

void E_PetPrivilege_s::write_to_pbmsg(::proto_ff::E_PetPrivilege & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_activate(m_activate.data());
	msg.set_m_doubleitem((int32_t)m_doubleItem);
	msg.set_m_experienceexp((int32_t)m_experienceExp);
	for(int32_t i = 0; i < (int32_t)m_privilege.size(); ++i) {
		::proto_ff::E_PetPrivilegePrivilegeDesc* temp_m_privilege = msg.add_m_privilege();
		m_privilege[i].write_to_pbmsg(*temp_m_privilege);
	}
}

void E_PetPrivilege_s::read_from_pbmsg(const ::proto_ff::E_PetPrivilege & msg) {
	m_id = msg.m_id();
	m_activate = msg.m_activate();
	m_doubleItem = msg.m_doubleitem();
	m_experienceExp = msg.m_experienceexp();
	m_privilege.resize((int)msg.m_privilege_size() > (int)m_privilege.max_size() ? m_privilege.max_size() : msg.m_privilege_size());
	for(int32_t i = 0; i < (int32_t)m_privilege.size(); ++i) {
		const ::proto_ff::E_PetPrivilegePrivilegeDesc & temp_m_privilege = msg.m_privilege(i);
		m_privilege[i].read_from_pbmsg(temp_m_privilege);
	}
}

Sheet_PetPrivilege_s::Sheet_PetPrivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PetPrivilege_s::CreateInit() {
	return 0;
}

int Sheet_PetPrivilege_s::ResumeInit() {
	return 0;
}

void Sheet_PetPrivilege_s::write_to_pbmsg(::proto_ff::Sheet_PetPrivilege & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PetPrivilege_List.size(); ++i) {
		::proto_ff::E_PetPrivilege* temp_e_petprivilege_list = msg.add_e_petprivilege_list();
		E_PetPrivilege_List[i].write_to_pbmsg(*temp_e_petprivilege_list);
	}
}

void Sheet_PetPrivilege_s::read_from_pbmsg(const ::proto_ff::Sheet_PetPrivilege & msg) {
	E_PetPrivilege_List.resize((int)msg.e_petprivilege_list_size() > (int)E_PetPrivilege_List.max_size() ? E_PetPrivilege_List.max_size() : msg.e_petprivilege_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetPrivilege_List.size(); ++i) {
		const ::proto_ff::E_PetPrivilege & temp_e_petprivilege_list = msg.e_petprivilege_list(i);
		E_PetPrivilege_List[i].read_from_pbmsg(temp_e_petprivilege_list);
	}
}

}
