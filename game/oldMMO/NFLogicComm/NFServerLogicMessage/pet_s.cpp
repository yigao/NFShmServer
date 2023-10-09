#include "pet_s.h"

namespace proto_ff_s {

E_PetDisplayMaterialDesc_s::E_PetDisplayMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetDisplayMaterialDesc_s::CreateInit() {
	m_id = (int64_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_PetDisplayMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_PetDisplayMaterialDesc_s::write_to_pbmsg(::proto_ff::E_PetDisplayMaterialDesc & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_exp((int32_t)m_exp);
}

void E_PetDisplayMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_PetDisplayMaterialDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PetDisplayMaterialDesc_s));
	m_id = msg.m_id();
	m_exp = msg.m_exp();
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
	m_isstar = (int32_t)0;
	m_monsterid = (int64_t)0;
	m_activeskillid = (int32_t)0;
	m_activeattribute = (int32_t)0;
	m_growatt = (int32_t)0;
	m_activeparama = (float)0;
	m_growattparama = (float)0;
	m_growstandarda = (float)0;
	m_growstandardb = (float)0;
	m_growstandard = (float)0;
	m_growmin = (float)0;
	m_growmax = (float)0;
	m_growstar = (float)0;
	m_advanceattribute = (int32_t)0;
	m_advancetype = (int32_t)0;
	m_starattribute = (int32_t)0;
	m_starpercent = (int32_t)0;
	m_starllimit = (int32_t)0;
	m_staritem = (int64_t)0;
	m_starpetid = (int64_t)0;
	m_weapon = (int32_t)0;
	m_upattributeid = (int64_t)0;
	m_fettersid = (int32_t)0;
	return 0;
}

int E_PetDisplay_s::ResumeInit() {
	return 0;
}

void E_PetDisplay_s::write_to_pbmsg(::proto_ff::E_PetDisplay & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_isstar((int32_t)m_isstar);
	msg.set_m_grade((const char*)m_grade.data());
	msg.set_m_monsterid((int64_t)m_monsterid);
	msg.set_m_name((const char*)m_name.data());
	msg.set_m_activeskillid((int32_t)m_activeskillid);
	msg.set_m_exclusiveskillid((const char*)m_exclusiveskillid.data());
	msg.set_m_passiveskillid((const char*)m_passiveskillid.data());
	msg.set_m_activeattribute((int32_t)m_activeattribute);
	msg.set_m_growatt((int32_t)m_growatt);
	msg.set_m_activeparama((float)m_activeparama);
	msg.set_m_growattparama((float)m_growattparama);
	msg.set_m_growstandarda((float)m_growstandarda);
	msg.set_m_growstandardb((float)m_growstandardb);
	msg.set_m_growstandard((float)m_growstandard);
	msg.set_m_growmin((float)m_growmin);
	msg.set_m_growmax((float)m_growmax);
	msg.set_m_growstar((float)m_growstar);
	msg.set_m_advanceattribute((int32_t)m_advanceattribute);
	msg.set_m_advancetype((int32_t)m_advancetype);
	msg.set_m_pettagskill((const char*)m_pettagskill.data());
	msg.set_m_starattribute((int32_t)m_starattribute);
	msg.set_m_starpercent((int32_t)m_starpercent);
	msg.set_m_starllimit((int32_t)m_starllimit);
	msg.set_m_staritem((int64_t)m_staritem);
	msg.set_m_starnum((const char*)m_starnum.data());
	msg.set_m_starpetid((int64_t)m_starpetid);
	msg.set_m_starpetnum((const char*)m_starpetnum.data());
	msg.set_m_weapon((int32_t)m_weapon);
	msg.set_m_upattributeid((int64_t)m_upattributeid);
	msg.set_m_fettersid((int32_t)m_fettersid);
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_PetDisplayMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
}

void E_PetDisplay_s::read_from_pbmsg(const ::proto_ff::E_PetDisplay & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PetDisplay_s));
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_isstar = msg.m_isstar();
	m_grade = msg.m_grade();
	m_monsterid = msg.m_monsterid();
	m_name = msg.m_name();
	m_activeskillid = msg.m_activeskillid();
	m_exclusiveskillid = msg.m_exclusiveskillid();
	m_passiveskillid = msg.m_passiveskillid();
	m_activeattribute = msg.m_activeattribute();
	m_growatt = msg.m_growatt();
	m_activeparama = msg.m_activeparama();
	m_growattparama = msg.m_growattparama();
	m_growstandarda = msg.m_growstandarda();
	m_growstandardb = msg.m_growstandardb();
	m_growstandard = msg.m_growstandard();
	m_growmin = msg.m_growmin();
	m_growmax = msg.m_growmax();
	m_growstar = msg.m_growstar();
	m_advanceattribute = msg.m_advanceattribute();
	m_advancetype = msg.m_advancetype();
	m_pettagskill = msg.m_pettagskill();
	m_starattribute = msg.m_starattribute();
	m_starpercent = msg.m_starpercent();
	m_starllimit = msg.m_starllimit();
	m_staritem = msg.m_staritem();
	m_starnum = msg.m_starnum();
	m_starpetid = msg.m_starpetid();
	m_starpetnum = msg.m_starpetnum();
	m_weapon = msg.m_weapon();
	m_upattributeid = msg.m_upattributeid();
	m_fettersid = msg.m_fettersid();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_PetDisplay_s));
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
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_PetAttributetpyeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_PetAttributetpyeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_PetAttributetpyeAttributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_PetAttributetpyeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_PetAttributetpyeAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PetAttributetpyeAttributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PetAttributetpye_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_PetAttributetpye_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PetLvexp_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_PetLvexp_s));
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
	m_type = (int32_t)0;
	m_param = (float)0;
	return 0;
}

int E_PetAdvancelvAdvanceDesc_s::ResumeInit() {
	return 0;
}

void E_PetAdvancelvAdvanceDesc_s::write_to_pbmsg(::proto_ff::E_PetAdvancelvAdvanceDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_param((float)m_param);
}

void E_PetAdvancelvAdvanceDesc_s::read_from_pbmsg(const ::proto_ff::E_PetAdvancelvAdvanceDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PetAdvancelvAdvanceDesc_s));
	m_type = msg.m_type();
	m_param = msg.m_param();
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
	m_advanceitem = (int32_t)0;
	m_advancenum = (int32_t)0;
	return 0;
}

int E_PetAdvancelv_s::ResumeInit() {
	return 0;
}

void E_PetAdvancelv_s::write_to_pbmsg(::proto_ff::E_PetAdvancelv & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_advanceitem((int32_t)m_advanceitem);
	msg.set_m_advancenum((int32_t)m_advancenum);
	for(int32_t i = 0; i < (int32_t)m_advance.size(); ++i) {
		::proto_ff::E_PetAdvancelvAdvanceDesc* temp_m_advance = msg.add_m_advance();
		m_advance[i].write_to_pbmsg(*temp_m_advance);
	}
}

void E_PetAdvancelv_s::read_from_pbmsg(const ::proto_ff::E_PetAdvancelv & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PetAdvancelv_s));
	m_id = msg.m_id();
	m_advanceitem = msg.m_advanceitem();
	m_advancenum = msg.m_advancenum();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_PetAdvancelv_s));
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
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_PetStarupUpattributeDesc_s::ResumeInit() {
	return 0;
}

void E_PetStarupUpattributeDesc_s::write_to_pbmsg(::proto_ff::E_PetStarupUpattributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_PetStarupUpattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_PetStarupUpattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PetStarupUpattributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_PetStarup_s::E_PetStarup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PetStarup_s::CreateInit() {
	m_id = (int32_t)0;
	m_upattributeid = (int64_t)0;
	m_starid = (int32_t)0;
	m_skillid = (int32_t)0;
	m_activeskillidlv = (int32_t)0;
	return 0;
}

int E_PetStarup_s::ResumeInit() {
	return 0;
}

void E_PetStarup_s::write_to_pbmsg(::proto_ff::E_PetStarup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_upattributeid((int64_t)m_upattributeid);
	msg.set_m_starid((int32_t)m_starid);
	msg.set_m_skillid((int32_t)m_skillid);
	msg.set_m_activeskillidlv((int32_t)m_activeskillidlv);
	for(int32_t i = 0; i < (int32_t)m_upattribute.size(); ++i) {
		::proto_ff::E_PetStarupUpattributeDesc* temp_m_upattribute = msg.add_m_upattribute();
		m_upattribute[i].write_to_pbmsg(*temp_m_upattribute);
	}
}

void E_PetStarup_s::read_from_pbmsg(const ::proto_ff::E_PetStarup & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PetStarup_s));
	m_id = msg.m_id();
	m_upattributeid = msg.m_upattributeid();
	m_starid = msg.m_starid();
	m_skillid = msg.m_skillid();
	m_activeskillidlv = msg.m_activeskillidlv();
	m_upattribute.resize((int)msg.m_upattribute_size() > (int)m_upattribute.max_size() ? m_upattribute.max_size() : msg.m_upattribute_size());
	for(int32_t i = 0; i < (int32_t)m_upattribute.size(); ++i) {
		const ::proto_ff::E_PetStarupUpattributeDesc & temp_m_upattribute = msg.m_upattribute(i);
		m_upattribute[i].read_from_pbmsg(temp_m_upattribute);
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_PetStarup_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PetEggPetDesc_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PetEgg_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_PetEgg_s));
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
	m_boxid = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_PetDecomposeDecomposeDesc_s::ResumeInit() {
	return 0;
}

void E_PetDecomposeDecomposeDesc_s::write_to_pbmsg(::proto_ff::E_PetDecomposeDecomposeDesc & msg) const {
	msg.set_m_boxid((int32_t)m_boxid);
	msg.set_m_type((int32_t)m_type);
}

void E_PetDecomposeDecomposeDesc_s::read_from_pbmsg(const ::proto_ff::E_PetDecomposeDecomposeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PetDecomposeDecomposeDesc_s));
	m_boxid = msg.m_boxid();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PetDecompose_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_PetDecompose_s));
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
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_PetFettersAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_PetFettersAttributeDesc_s::write_to_pbmsg(::proto_ff::E_PetFettersAttributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_PetFettersAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_PetFettersAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PetFettersAttributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
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
	for(int32_t i = 0; i < (int32_t)m_petid.size(); ++i) {
		msg.add_m_petid((int32_t)m_petid[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_atctive_skillid.size(); ++i) {
		msg.add_m_atctive_skillid((int32_t)m_atctive_skillid[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_PetFettersAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_PetFetters_s::read_from_pbmsg(const ::proto_ff::E_PetFetters & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PetFetters_s));
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_petid.resize((int)msg.m_petid_size() > (int)m_petid.max_size() ? m_petid.max_size() : msg.m_petid_size());
	for(int32_t i = 0; i < (int32_t)m_petid.size(); ++i) {
		m_petid[i] = msg.m_petid(i);
	}
	m_atctive_skillid.resize((int)msg.m_atctive_skillid_size() > (int)m_atctive_skillid.max_size() ? m_atctive_skillid.max_size() : msg.m_atctive_skillid_size());
	for(int32_t i = 0; i < (int32_t)m_atctive_skillid.size(); ++i) {
		m_atctive_skillid[i] = msg.m_atctive_skillid(i);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_PetFettersAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_PetFetters_s));
	E_PetFetters_List.resize((int)msg.e_petfetters_list_size() > (int)E_PetFetters_List.max_size() ? E_PetFetters_List.max_size() : msg.e_petfetters_list_size());
	for(int32_t i = 0; i < (int32_t)E_PetFetters_List.size(); ++i) {
		const ::proto_ff::E_PetFetters & temp_e_petfetters_list = msg.e_petfetters_list(i);
		E_PetFetters_List[i].read_from_pbmsg(temp_e_petfetters_list);
	}
}

}