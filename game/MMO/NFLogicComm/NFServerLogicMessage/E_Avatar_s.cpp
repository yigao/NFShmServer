#include "E_Avatar_s.h"

namespace proto_ff_s {

E_AvatarFragmentAttributeDesc_s::E_AvatarFragmentAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarFragmentAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AvatarFragmentAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AvatarFragmentAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AvatarFragmentAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_AvatarFragmentAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AvatarFragmentAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_AvatarFragment_s::E_AvatarFragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarFragment_s::CreateInit() {
	m_fragmentID = (int64_t)0;
	m_item = (int64_t)0;
	m_itemNum = (int32_t)0;
	return 0;
}

int E_AvatarFragment_s::ResumeInit() {
	return 0;
}

void E_AvatarFragment_s::write_to_pbmsg(::proto_ff::E_AvatarFragment & msg) const {
	msg.set_m_fragmentid((int64_t)m_fragmentID);
	msg.set_m_item((int64_t)m_item);
	msg.set_m_itemnum((int32_t)m_itemNum);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_AvatarFragmentAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AvatarFragment_s::read_from_pbmsg(const ::proto_ff::E_AvatarFragment & msg) {
	m_fragmentID = msg.m_fragmentid();
	m_item = msg.m_item();
	m_itemNum = msg.m_itemnum();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_AvatarFragmentAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AvatarFragment_s::Sheet_AvatarFragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarFragment_s::CreateInit() {
	return 0;
}

int Sheet_AvatarFragment_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarFragment_s::write_to_pbmsg(::proto_ff::Sheet_AvatarFragment & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarFragment_List.size(); ++i) {
		::proto_ff::E_AvatarFragment* temp_e_avatarfragment_list = msg.add_e_avatarfragment_list();
		E_AvatarFragment_List[i].write_to_pbmsg(*temp_e_avatarfragment_list);
	}
}

void Sheet_AvatarFragment_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarFragment & msg) {
	E_AvatarFragment_List.resize((int)msg.e_avatarfragment_list_size() > (int)E_AvatarFragment_List.max_size() ? E_AvatarFragment_List.max_size() : msg.e_avatarfragment_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarFragment_List.size(); ++i) {
		const ::proto_ff::E_AvatarFragment & temp_e_avatarfragment_list = msg.e_avatarfragment_list(i);
		E_AvatarFragment_List[i].read_from_pbmsg(temp_e_avatarfragment_list);
	}
}

E_AvatarValueAttributeDesc_s::E_AvatarValueAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarValueAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AvatarValueAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AvatarValueAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AvatarValueAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_AvatarValueAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AvatarValueAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_AvatarValue_s::E_AvatarValue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarValue_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_lv = (int32_t)0;
	m_cost = (int32_t)0;
	m_Exp = (int32_t)0;
	return 0;
}

int E_AvatarValue_s::ResumeInit() {
	return 0;
}

void E_AvatarValue_s::write_to_pbmsg(::proto_ff::E_AvatarValue & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_cost((int32_t)m_cost);
	msg.set_m_exp((int32_t)m_Exp);
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_AvatarValueAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AvatarValue_s::read_from_pbmsg(const ::proto_ff::E_AvatarValue & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_lv = msg.m_lv();
	m_cost = msg.m_cost();
	m_Exp = msg.m_exp();
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_AvatarValueAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AvatarValue_s::Sheet_AvatarValue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarValue_s::CreateInit() {
	return 0;
}

int Sheet_AvatarValue_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarValue_s::write_to_pbmsg(::proto_ff::Sheet_AvatarValue & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarValue_List.size(); ++i) {
		::proto_ff::E_AvatarValue* temp_e_avatarvalue_list = msg.add_e_avatarvalue_list();
		E_AvatarValue_List[i].write_to_pbmsg(*temp_e_avatarvalue_list);
	}
}

void Sheet_AvatarValue_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarValue & msg) {
	E_AvatarValue_List.resize((int)msg.e_avatarvalue_list_size() > (int)E_AvatarValue_List.max_size() ? E_AvatarValue_List.max_size() : msg.e_avatarvalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarValue_List.size(); ++i) {
		const ::proto_ff::E_AvatarValue & temp_e_avatarvalue_list = msg.e_avatarvalue_list(i);
		E_AvatarValue_List[i].read_from_pbmsg(temp_e_avatarvalue_list);
	}
}

E_AvatarDisplayMaterialDesc_s::E_AvatarDisplayMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarDisplayMaterialDesc_s::CreateInit() {
	m_exp = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_AvatarDisplayMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_AvatarDisplayMaterialDesc_s::write_to_pbmsg(::proto_ff::E_AvatarDisplayMaterialDesc & msg) const {
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_id((int32_t)m_id);
}

void E_AvatarDisplayMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_AvatarDisplayMaterialDesc & msg) {
	m_exp = msg.m_exp();
	m_id = msg.m_id();
}

E_AvatarDisplay_s::E_AvatarDisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarDisplay_s::CreateInit() {
	m_id = (int32_t)0;
	m_UpLvType = (int32_t)0;
	return 0;
}

int E_AvatarDisplay_s::ResumeInit() {
	return 0;
}

void E_AvatarDisplay_s::write_to_pbmsg(::proto_ff::E_AvatarDisplay & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_uplvtype((int32_t)m_UpLvType);
	msg.set_m_skillid(m_skillID.data());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_AvatarDisplayMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_fragmentID.size(); ++i) {
		msg.add_m_fragmentid((int64_t)m_fragmentID[i]);
	}
}

void E_AvatarDisplay_s::read_from_pbmsg(const ::proto_ff::E_AvatarDisplay & msg) {
	m_id = msg.m_id();
	m_UpLvType = msg.m_uplvtype();
	m_skillID = msg.m_skillid();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_AvatarDisplayMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_fragmentID.resize((int)msg.m_fragmentid_size() > (int)m_fragmentID.max_size() ? m_fragmentID.max_size() : msg.m_fragmentid_size());
	for(int32_t i = 0; i < (int32_t)m_fragmentID.size(); ++i) {
		m_fragmentID[i] = msg.m_fragmentid(i);
	}
}

Sheet_AvatarDisplay_s::Sheet_AvatarDisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarDisplay_s::CreateInit() {
	return 0;
}

int Sheet_AvatarDisplay_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarDisplay_s::write_to_pbmsg(::proto_ff::Sheet_AvatarDisplay & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarDisplay_List.size(); ++i) {
		::proto_ff::E_AvatarDisplay* temp_e_avatardisplay_list = msg.add_e_avatardisplay_list();
		E_AvatarDisplay_List[i].write_to_pbmsg(*temp_e_avatardisplay_list);
	}
}

void Sheet_AvatarDisplay_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarDisplay & msg) {
	E_AvatarDisplay_List.resize((int)msg.e_avatardisplay_list_size() > (int)E_AvatarDisplay_List.max_size() ? E_AvatarDisplay_List.max_size() : msg.e_avatardisplay_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarDisplay_List.size(); ++i) {
		const ::proto_ff::E_AvatarDisplay & temp_e_avatardisplay_list = msg.e_avatardisplay_list(i);
		E_AvatarDisplay_List[i].read_from_pbmsg(temp_e_avatardisplay_list);
	}
}

E_AvatarChangeMaterialDesc_s::E_AvatarChangeMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarChangeMaterialDesc_s::CreateInit() {
	m_exp = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_AvatarChangeMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_AvatarChangeMaterialDesc_s::write_to_pbmsg(::proto_ff::E_AvatarChangeMaterialDesc & msg) const {
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_id((int32_t)m_id);
}

void E_AvatarChangeMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_AvatarChangeMaterialDesc & msg) {
	m_exp = msg.m_exp();
	m_id = msg.m_id();
}

E_AvatarChangeAttributeDesc_s::E_AvatarChangeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarChangeAttributeDesc_s::CreateInit() {
	m_UpValue = (int32_t)0;
	m_UpBer = (int32_t)0;
	return 0;
}

int E_AvatarChangeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AvatarChangeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AvatarChangeAttributeDesc & msg) const {
	msg.set_m_upvalue((int32_t)m_UpValue);
	msg.set_m_upber((int32_t)m_UpBer);
}

void E_AvatarChangeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AvatarChangeAttributeDesc & msg) {
	m_UpValue = msg.m_upvalue();
	m_UpBer = msg.m_upber();
}

E_AvatarChange_s::E_AvatarChange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarChange_s::CreateInit() {
	m_id = (int32_t)0;
	m_quality = (int32_t)0;
	m_UpLvType = (int32_t)0;
	m_avatarSkill = (int64_t)0;
	m_avatarCD = (int32_t)0;
	m_avatarTime = (int32_t)0;
	m_avatarShield = (int32_t)0;
	m_starMax = (int32_t)0;
	m_LvMax = (int32_t)0;
	m_ModelID = (int32_t)0;
	m_advance = (int32_t)0;
	m_activationItem = (int32_t)0;
	m_activationNum = (int32_t)0;
	m_starId = (int32_t)0;
	m_starUpAttributeId = (int32_t)0;
	m_funUnlock = (int32_t)0;
	m_maxEquip = (int32_t)0;
	m_equipSuit = (int32_t)0;
	m_starBer = (int32_t)0;
	m_mythID = (int32_t)0;
	m_mythWayID = (int32_t)0;
	m_mythCoreID = (int32_t)0;
	return 0;
}

int E_AvatarChange_s::ResumeInit() {
	return 0;
}

void E_AvatarChange_s::write_to_pbmsg(::proto_ff::E_AvatarChange & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_uplvtype((int32_t)m_UpLvType);
	msg.set_m_avatarskill((int64_t)m_avatarSkill);
	msg.set_m_avatarcd((int32_t)m_avatarCD);
	msg.set_m_avatartime((int32_t)m_avatarTime);
	msg.set_m_avatarshield((int32_t)m_avatarShield);
	msg.set_m_skillid(m_skillID.data());
	msg.set_m_starmax((int32_t)m_starMax);
	msg.set_m_lvmax((int32_t)m_LvMax);
	msg.set_m_modelid((int32_t)m_ModelID);
	msg.set_m_advance((int32_t)m_advance);
	msg.set_m_activationitem((int32_t)m_activationItem);
	msg.set_m_activationnum((int32_t)m_activationNum);
	msg.set_m_starid((int32_t)m_starId);
	msg.set_m_starnum(m_starNum.data());
	msg.set_m_starupattributeid((int32_t)m_starUpAttributeId);
	msg.set_m_fununlock((int32_t)m_funUnlock);
	msg.set_m_maxequip((int32_t)m_maxEquip);
	msg.set_m_equipsuit((int32_t)m_equipSuit);
	msg.set_m_starber((int32_t)m_starBer);
	msg.set_m_mythskill(m_mythSkill.data());
	msg.set_m_mythspskill(m_mythSPSkill.data());
	msg.set_m_mythid((int32_t)m_mythID);
	msg.set_m_mythwayid((int32_t)m_mythWayID);
	msg.set_m_mythcoreid((int32_t)m_mythCoreID);
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_AvatarChangeMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_InitiativeSkill.size(); ++i) {
		msg.add_m_initiativeskill((int64_t)m_InitiativeSkill[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_AvatarChangeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AvatarChange_s::read_from_pbmsg(const ::proto_ff::E_AvatarChange & msg) {
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_UpLvType = msg.m_uplvtype();
	m_avatarSkill = msg.m_avatarskill();
	m_avatarCD = msg.m_avatarcd();
	m_avatarTime = msg.m_avatartime();
	m_avatarShield = msg.m_avatarshield();
	m_skillID = msg.m_skillid();
	m_starMax = msg.m_starmax();
	m_LvMax = msg.m_lvmax();
	m_ModelID = msg.m_modelid();
	m_advance = msg.m_advance();
	m_activationItem = msg.m_activationitem();
	m_activationNum = msg.m_activationnum();
	m_starId = msg.m_starid();
	m_starNum = msg.m_starnum();
	m_starUpAttributeId = msg.m_starupattributeid();
	m_funUnlock = msg.m_fununlock();
	m_maxEquip = msg.m_maxequip();
	m_equipSuit = msg.m_equipsuit();
	m_starBer = msg.m_starber();
	m_mythSkill = msg.m_mythskill();
	m_mythSPSkill = msg.m_mythspskill();
	m_mythID = msg.m_mythid();
	m_mythWayID = msg.m_mythwayid();
	m_mythCoreID = msg.m_mythcoreid();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_AvatarChangeMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_InitiativeSkill.resize((int)msg.m_initiativeskill_size() > (int)m_InitiativeSkill.max_size() ? m_InitiativeSkill.max_size() : msg.m_initiativeskill_size());
	for(int32_t i = 0; i < (int32_t)m_InitiativeSkill.size(); ++i) {
		m_InitiativeSkill[i] = msg.m_initiativeskill(i);
	}
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_AvatarChangeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AvatarChange_s::Sheet_AvatarChange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarChange_s::CreateInit() {
	return 0;
}

int Sheet_AvatarChange_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarChange_s::write_to_pbmsg(::proto_ff::Sheet_AvatarChange & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarChange_List.size(); ++i) {
		::proto_ff::E_AvatarChange* temp_e_avatarchange_list = msg.add_e_avatarchange_list();
		E_AvatarChange_List[i].write_to_pbmsg(*temp_e_avatarchange_list);
	}
}

void Sheet_AvatarChange_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarChange & msg) {
	E_AvatarChange_List.resize((int)msg.e_avatarchange_list_size() > (int)E_AvatarChange_List.max_size() ? E_AvatarChange_List.max_size() : msg.e_avatarchange_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarChange_List.size(); ++i) {
		const ::proto_ff::E_AvatarChange & temp_e_avatarchange_list = msg.e_avatarchange_list(i);
		E_AvatarChange_List[i].read_from_pbmsg(temp_e_avatarchange_list);
	}
}

E_AvatarChangetab_s::E_AvatarChangetab_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarChangetab_s::CreateInit() {
	m_tabID = (int32_t)0;
	return 0;
}

int E_AvatarChangetab_s::ResumeInit() {
	return 0;
}

void E_AvatarChangetab_s::write_to_pbmsg(::proto_ff::E_AvatarChangetab & msg) const {
	msg.set_m_tabid((int32_t)m_tabID);
}

void E_AvatarChangetab_s::read_from_pbmsg(const ::proto_ff::E_AvatarChangetab & msg) {
	m_tabID = msg.m_tabid();
}

Sheet_AvatarChangetab_s::Sheet_AvatarChangetab_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarChangetab_s::CreateInit() {
	return 0;
}

int Sheet_AvatarChangetab_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarChangetab_s::write_to_pbmsg(::proto_ff::Sheet_AvatarChangetab & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarChangetab_List.size(); ++i) {
		::proto_ff::E_AvatarChangetab* temp_e_avatarchangetab_list = msg.add_e_avatarchangetab_list();
		E_AvatarChangetab_List[i].write_to_pbmsg(*temp_e_avatarchangetab_list);
	}
}

void Sheet_AvatarChangetab_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarChangetab & msg) {
	E_AvatarChangetab_List.resize((int)msg.e_avatarchangetab_list_size() > (int)E_AvatarChangetab_List.max_size() ? E_AvatarChangetab_List.max_size() : msg.e_avatarchangetab_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarChangetab_List.size(); ++i) {
		const ::proto_ff::E_AvatarChangetab & temp_e_avatarchangetab_list = msg.e_avatarchangetab_list(i);
		E_AvatarChangetab_List[i].read_from_pbmsg(temp_e_avatarchangetab_list);
	}
}

E_AvatarBattleslot_s::E_AvatarBattleslot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarBattleslot_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AvatarBattleslot_s::ResumeInit() {
	return 0;
}

void E_AvatarBattleslot_s::write_to_pbmsg(::proto_ff::E_AvatarBattleslot & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_arg(m_arg.data());
}

void E_AvatarBattleslot_s::read_from_pbmsg(const ::proto_ff::E_AvatarBattleslot & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_arg = msg.m_arg();
}

Sheet_AvatarBattleslot_s::Sheet_AvatarBattleslot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarBattleslot_s::CreateInit() {
	return 0;
}

int Sheet_AvatarBattleslot_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarBattleslot_s::write_to_pbmsg(::proto_ff::Sheet_AvatarBattleslot & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarBattleslot_List.size(); ++i) {
		::proto_ff::E_AvatarBattleslot* temp_e_avatarbattleslot_list = msg.add_e_avatarbattleslot_list();
		E_AvatarBattleslot_List[i].write_to_pbmsg(*temp_e_avatarbattleslot_list);
	}
}

void Sheet_AvatarBattleslot_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarBattleslot & msg) {
	E_AvatarBattleslot_List.resize((int)msg.e_avatarbattleslot_list_size() > (int)E_AvatarBattleslot_List.max_size() ? E_AvatarBattleslot_List.max_size() : msg.e_avatarbattleslot_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarBattleslot_List.size(); ++i) {
		const ::proto_ff::E_AvatarBattleslot & temp_e_avatarbattleslot_list = msg.e_avatarbattleslot_list(i);
		E_AvatarBattleslot_List[i].read_from_pbmsg(temp_e_avatarbattleslot_list);
	}
}

E_AvatarAdvanceUpattributeDesc_s::E_AvatarAdvanceUpattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarAdvanceUpattributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AvatarAdvanceUpattributeDesc_s::ResumeInit() {
	return 0;
}

void E_AvatarAdvanceUpattributeDesc_s::write_to_pbmsg(::proto_ff::E_AvatarAdvanceUpattributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_AvatarAdvanceUpattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AvatarAdvanceUpattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_AvatarAdvance_s::E_AvatarAdvance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarAdvance_s::CreateInit() {
	m_id = (int32_t)0;
	m_upAttributeId = (int32_t)0;
	m_starID = (int32_t)0;
	m_skillID = (int32_t)0;
	return 0;
}

int E_AvatarAdvance_s::ResumeInit() {
	return 0;
}

void E_AvatarAdvance_s::write_to_pbmsg(::proto_ff::E_AvatarAdvance & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_upattributeid((int32_t)m_upAttributeId);
	msg.set_m_starid((int32_t)m_starID);
	msg.set_m_skillid((int32_t)m_skillID);
	for(int32_t i = 0; i < (int32_t)m_upAttribute.size(); ++i) {
		::proto_ff::E_AvatarAdvanceUpattributeDesc* temp_m_upattribute = msg.add_m_upattribute();
		m_upAttribute[i].write_to_pbmsg(*temp_m_upattribute);
	}
}

void E_AvatarAdvance_s::read_from_pbmsg(const ::proto_ff::E_AvatarAdvance & msg) {
	m_id = msg.m_id();
	m_upAttributeId = msg.m_upattributeid();
	m_starID = msg.m_starid();
	m_skillID = msg.m_skillid();
	m_upAttribute.resize((int)msg.m_upattribute_size() > (int)m_upAttribute.max_size() ? m_upAttribute.max_size() : msg.m_upattribute_size());
	for(int32_t i = 0; i < (int32_t)m_upAttribute.size(); ++i) {
		const ::proto_ff::E_AvatarAdvanceUpattributeDesc & temp_m_upattribute = msg.m_upattribute(i);
		m_upAttribute[i].read_from_pbmsg(temp_m_upattribute);
	}
}

Sheet_AvatarAdvance_s::Sheet_AvatarAdvance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarAdvance_s::CreateInit() {
	return 0;
}

int Sheet_AvatarAdvance_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarAdvance_s::write_to_pbmsg(::proto_ff::Sheet_AvatarAdvance & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarAdvance_List.size(); ++i) {
		::proto_ff::E_AvatarAdvance* temp_e_avataradvance_list = msg.add_e_avataradvance_list();
		E_AvatarAdvance_List[i].write_to_pbmsg(*temp_e_avataradvance_list);
	}
}

void Sheet_AvatarAdvance_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarAdvance & msg) {
	E_AvatarAdvance_List.resize((int)msg.e_avataradvance_list_size() > (int)E_AvatarAdvance_List.max_size() ? E_AvatarAdvance_List.max_size() : msg.e_avataradvance_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarAdvance_List.size(); ++i) {
		const ::proto_ff::E_AvatarAdvance & temp_e_avataradvance_list = msg.e_avataradvance_list(i);
		E_AvatarAdvance_List[i].read_from_pbmsg(temp_e_avataradvance_list);
	}
}

E_AvatarSkill_s::E_AvatarSkill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarSkill_s::CreateInit() {
	m_id = (int32_t)0;
	m_belong = (int32_t)0;
	m_order = (int32_t)0;
	m_skillid = (int32_t)0;
	return 0;
}

int E_AvatarSkill_s::ResumeInit() {
	return 0;
}

void E_AvatarSkill_s::write_to_pbmsg(::proto_ff::E_AvatarSkill & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_belong((int32_t)m_belong);
	msg.set_m_order((int32_t)m_order);
	msg.set_m_skillid((int32_t)m_skillid);
}

void E_AvatarSkill_s::read_from_pbmsg(const ::proto_ff::E_AvatarSkill & msg) {
	m_id = msg.m_id();
	m_belong = msg.m_belong();
	m_order = msg.m_order();
	m_skillid = msg.m_skillid();
}

Sheet_AvatarSkill_s::Sheet_AvatarSkill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarSkill_s::CreateInit() {
	return 0;
}

int Sheet_AvatarSkill_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarSkill_s::write_to_pbmsg(::proto_ff::Sheet_AvatarSkill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarSkill_List.size(); ++i) {
		::proto_ff::E_AvatarSkill* temp_e_avatarskill_list = msg.add_e_avatarskill_list();
		E_AvatarSkill_List[i].write_to_pbmsg(*temp_e_avatarskill_list);
	}
}

void Sheet_AvatarSkill_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarSkill & msg) {
	E_AvatarSkill_List.resize((int)msg.e_avatarskill_list_size() > (int)E_AvatarSkill_List.max_size() ? E_AvatarSkill_List.max_size() : msg.e_avatarskill_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarSkill_List.size(); ++i) {
		const ::proto_ff::E_AvatarSkill & temp_e_avatarskill_list = msg.e_avatarskill_list(i);
		E_AvatarSkill_List[i].read_from_pbmsg(temp_e_avatarskill_list);
	}
}

E_AvatarEquipsuitAttributeDesc_s::E_AvatarEquipsuitAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarEquipsuitAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AvatarEquipsuitAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AvatarEquipsuitAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AvatarEquipsuitAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_AvatarEquipsuitAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AvatarEquipsuitAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_AvatarEquipsuit_s::E_AvatarEquipsuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarEquipsuit_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	return 0;
}

int E_AvatarEquipsuit_s::ResumeInit() {
	return 0;
}

void E_AvatarEquipsuit_s::write_to_pbmsg(::proto_ff::E_AvatarEquipsuit & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_AvatarEquipsuitAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AvatarEquipsuit_s::read_from_pbmsg(const ::proto_ff::E_AvatarEquipsuit & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_AvatarEquipsuitAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AvatarEquipsuit_s::Sheet_AvatarEquipsuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarEquipsuit_s::CreateInit() {
	return 0;
}

int Sheet_AvatarEquipsuit_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarEquipsuit_s::write_to_pbmsg(::proto_ff::Sheet_AvatarEquipsuit & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarEquipsuit_List.size(); ++i) {
		::proto_ff::E_AvatarEquipsuit* temp_e_avatarequipsuit_list = msg.add_e_avatarequipsuit_list();
		E_AvatarEquipsuit_List[i].write_to_pbmsg(*temp_e_avatarequipsuit_list);
	}
}

void Sheet_AvatarEquipsuit_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarEquipsuit & msg) {
	E_AvatarEquipsuit_List.resize((int)msg.e_avatarequipsuit_list_size() > (int)E_AvatarEquipsuit_List.max_size() ? E_AvatarEquipsuit_List.max_size() : msg.e_avatarequipsuit_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarEquipsuit_List.size(); ++i) {
		const ::proto_ff::E_AvatarEquipsuit & temp_e_avatarequipsuit_list = msg.e_avatarequipsuit_list(i);
		E_AvatarEquipsuit_List[i].read_from_pbmsg(temp_e_avatarequipsuit_list);
	}
}

E_AvatarMythAttributeDesc_s::E_AvatarMythAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarMythAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AvatarMythAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AvatarMythAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AvatarMythAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_AvatarMythAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AvatarMythAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_AvatarMyth_s::E_AvatarMyth_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarMyth_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_stage = (int32_t)0;
	return 0;
}

int E_AvatarMyth_s::ResumeInit() {
	return 0;
}

void E_AvatarMyth_s::write_to_pbmsg(::proto_ff::E_AvatarMyth & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_stage((int32_t)m_stage);
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_AvatarMythAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AvatarMyth_s::read_from_pbmsg(const ::proto_ff::E_AvatarMyth & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_stage = msg.m_stage();
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_AvatarMythAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AvatarMyth_s::Sheet_AvatarMyth_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarMyth_s::CreateInit() {
	return 0;
}

int Sheet_AvatarMyth_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarMyth_s::write_to_pbmsg(::proto_ff::Sheet_AvatarMyth & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarMyth_List.size(); ++i) {
		::proto_ff::E_AvatarMyth* temp_e_avatarmyth_list = msg.add_e_avatarmyth_list();
		E_AvatarMyth_List[i].write_to_pbmsg(*temp_e_avatarmyth_list);
	}
}

void Sheet_AvatarMyth_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarMyth & msg) {
	E_AvatarMyth_List.resize((int)msg.e_avatarmyth_list_size() > (int)E_AvatarMyth_List.max_size() ? E_AvatarMyth_List.max_size() : msg.e_avatarmyth_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarMyth_List.size(); ++i) {
		const ::proto_ff::E_AvatarMyth & temp_e_avatarmyth_list = msg.e_avatarmyth_list(i);
		E_AvatarMyth_List[i].read_from_pbmsg(temp_e_avatarmyth_list);
	}
}

E_AvatarMythwayAttributeDesc_s::E_AvatarMythwayAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarMythwayAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AvatarMythwayAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AvatarMythwayAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AvatarMythwayAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_AvatarMythwayAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AvatarMythwayAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_AvatarMythway_s::E_AvatarMythway_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarMythway_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_stage = (int32_t)0;
	m_star = (int32_t)0;
	m_showStar = (int32_t)0;
	m_mythCoreCondition = (int32_t)0;
	m_posX = (int32_t)0;
	m_posY = (int32_t)0;
	return 0;
}

int E_AvatarMythway_s::ResumeInit() {
	return 0;
}

void E_AvatarMythway_s::write_to_pbmsg(::proto_ff::E_AvatarMythway & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_stage((int32_t)m_stage);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_showstar((int32_t)m_showStar);
	msg.set_m_mythcorecondition((int32_t)m_mythCoreCondition);
	msg.set_m_posx((int32_t)m_posX);
	msg.set_m_posy((int32_t)m_posY);
	for(int32_t i = 0; i < (int32_t)m_equipID.size(); ++i) {
		msg.add_m_equipid((int32_t)m_equipID[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_specialID.size(); ++i) {
		msg.add_m_specialid((int32_t)m_specialID[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_AvatarMythwayAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AvatarMythway_s::read_from_pbmsg(const ::proto_ff::E_AvatarMythway & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_stage = msg.m_stage();
	m_star = msg.m_star();
	m_showStar = msg.m_showstar();
	m_mythCoreCondition = msg.m_mythcorecondition();
	m_posX = msg.m_posx();
	m_posY = msg.m_posy();
	m_equipID.resize((int)msg.m_equipid_size() > (int)m_equipID.max_size() ? m_equipID.max_size() : msg.m_equipid_size());
	for(int32_t i = 0; i < (int32_t)m_equipID.size(); ++i) {
		m_equipID[i] = msg.m_equipid(i);
	}
	m_specialID.resize((int)msg.m_specialid_size() > (int)m_specialID.max_size() ? m_specialID.max_size() : msg.m_specialid_size());
	for(int32_t i = 0; i < (int32_t)m_specialID.size(); ++i) {
		m_specialID[i] = msg.m_specialid(i);
	}
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_AvatarMythwayAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AvatarMythway_s::Sheet_AvatarMythway_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarMythway_s::CreateInit() {
	return 0;
}

int Sheet_AvatarMythway_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarMythway_s::write_to_pbmsg(::proto_ff::Sheet_AvatarMythway & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarMythway_List.size(); ++i) {
		::proto_ff::E_AvatarMythway* temp_e_avatarmythway_list = msg.add_e_avatarmythway_list();
		E_AvatarMythway_List[i].write_to_pbmsg(*temp_e_avatarmythway_list);
	}
}

void Sheet_AvatarMythway_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarMythway & msg) {
	E_AvatarMythway_List.resize((int)msg.e_avatarmythway_list_size() > (int)E_AvatarMythway_List.max_size() ? E_AvatarMythway_List.max_size() : msg.e_avatarmythway_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarMythway_List.size(); ++i) {
		const ::proto_ff::E_AvatarMythway & temp_e_avatarmythway_list = msg.e_avatarmythway_list(i);
		E_AvatarMythway_List[i].read_from_pbmsg(temp_e_avatarmythway_list);
	}
}

E_AvatarMythcoreAttributeDesc_s::E_AvatarMythcoreAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarMythcoreAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AvatarMythcoreAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AvatarMythcoreAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AvatarMythcoreAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_AvatarMythcoreAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AvatarMythcoreAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_AvatarMythcore_s::E_AvatarMythcore_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarMythcore_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_LV = (int32_t)0;
	m_costID = (int32_t)0;
	m_costNum = (int32_t)0;
	m_success = (int32_t)0;
	return 0;
}

int E_AvatarMythcore_s::ResumeInit() {
	return 0;
}

void E_AvatarMythcore_s::write_to_pbmsg(::proto_ff::E_AvatarMythcore & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_lv((int32_t)m_LV);
	msg.set_m_costid((int32_t)m_costID);
	msg.set_m_costnum((int32_t)m_costNum);
	msg.set_m_success((int32_t)m_success);
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_AvatarMythcoreAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AvatarMythcore_s::read_from_pbmsg(const ::proto_ff::E_AvatarMythcore & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_LV = msg.m_lv();
	m_costID = msg.m_costid();
	m_costNum = msg.m_costnum();
	m_success = msg.m_success();
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_AvatarMythcoreAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AvatarMythcore_s::Sheet_AvatarMythcore_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarMythcore_s::CreateInit() {
	return 0;
}

int Sheet_AvatarMythcore_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarMythcore_s::write_to_pbmsg(::proto_ff::Sheet_AvatarMythcore & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarMythcore_List.size(); ++i) {
		::proto_ff::E_AvatarMythcore* temp_e_avatarmythcore_list = msg.add_e_avatarmythcore_list();
		E_AvatarMythcore_List[i].write_to_pbmsg(*temp_e_avatarmythcore_list);
	}
}

void Sheet_AvatarMythcore_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarMythcore & msg) {
	E_AvatarMythcore_List.resize((int)msg.e_avatarmythcore_list_size() > (int)E_AvatarMythcore_List.max_size() ? E_AvatarMythcore_List.max_size() : msg.e_avatarmythcore_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarMythcore_List.size(); ++i) {
		const ::proto_ff::E_AvatarMythcore & temp_e_avatarmythcore_list = msg.e_avatarmythcore_list(i);
		E_AvatarMythcore_List[i].read_from_pbmsg(temp_e_avatarmythcore_list);
	}
}

E_AvatarMythequipAttributeDesc_s::E_AvatarMythequipAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarMythequipAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AvatarMythequipAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AvatarMythequipAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AvatarMythequipAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_AvatarMythequipAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AvatarMythequipAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_AvatarMythequip_s::E_AvatarMythequip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarMythequip_s::CreateInit() {
	m_itemID = (int32_t)0;
	m_star = (int32_t)0;
	return 0;
}

int E_AvatarMythequip_s::ResumeInit() {
	return 0;
}

void E_AvatarMythequip_s::write_to_pbmsg(::proto_ff::E_AvatarMythequip & msg) const {
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_star((int32_t)m_star);
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_AvatarMythequipAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AvatarMythequip_s::read_from_pbmsg(const ::proto_ff::E_AvatarMythequip & msg) {
	m_itemID = msg.m_itemid();
	m_star = msg.m_star();
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_AvatarMythequipAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AvatarMythequip_s::Sheet_AvatarMythequip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarMythequip_s::CreateInit() {
	return 0;
}

int Sheet_AvatarMythequip_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarMythequip_s::write_to_pbmsg(::proto_ff::Sheet_AvatarMythequip & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarMythequip_List.size(); ++i) {
		::proto_ff::E_AvatarMythequip* temp_e_avatarmythequip_list = msg.add_e_avatarmythequip_list();
		E_AvatarMythequip_List[i].write_to_pbmsg(*temp_e_avatarmythequip_list);
	}
}

void Sheet_AvatarMythequip_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarMythequip & msg) {
	E_AvatarMythequip_List.resize((int)msg.e_avatarmythequip_list_size() > (int)E_AvatarMythequip_List.max_size() ? E_AvatarMythequip_List.max_size() : msg.e_avatarmythequip_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarMythequip_List.size(); ++i) {
		const ::proto_ff::E_AvatarMythequip & temp_e_avatarmythequip_list = msg.e_avatarmythequip_list(i);
		E_AvatarMythequip_List[i].read_from_pbmsg(temp_e_avatarmythequip_list);
	}
}

E_AvatarArtifactAttributeDesc_s::E_AvatarArtifactAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarArtifactAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_times = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AvatarArtifactAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AvatarArtifactAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AvatarArtifactAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_times((int32_t)m_times);
	msg.set_m_type((int32_t)m_type);
}

void E_AvatarArtifactAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AvatarArtifactAttributeDesc & msg) {
	m_value = msg.m_value();
	m_times = msg.m_times();
	m_type = msg.m_type();
}

E_AvatarArtifact_s::E_AvatarArtifact_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarArtifact_s::CreateInit() {
	m_changeID = (int32_t)0;
	m_starGroupID = (int32_t)0;
	m_strGroupID = (int32_t)0;
	m_EncGroupID = (int32_t)0;
	m_activeADDtime = (int32_t)0;
	m_costItem = (int32_t)0;
	m_costNum = (int32_t)0;
	return 0;
}

int E_AvatarArtifact_s::ResumeInit() {
	return 0;
}

void E_AvatarArtifact_s::write_to_pbmsg(::proto_ff::E_AvatarArtifact & msg) const {
	msg.set_m_changeid((int32_t)m_changeID);
	msg.set_m_stargroupid((int32_t)m_starGroupID);
	msg.set_m_strgroupid((int32_t)m_strGroupID);
	msg.set_m_encgroupid((int32_t)m_EncGroupID);
	msg.set_m_activeaddtime((int32_t)m_activeADDtime);
	msg.set_m_costitem((int32_t)m_costItem);
	msg.set_m_costnum((int32_t)m_costNum);
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_AvatarArtifactAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AvatarArtifact_s::read_from_pbmsg(const ::proto_ff::E_AvatarArtifact & msg) {
	m_changeID = msg.m_changeid();
	m_starGroupID = msg.m_stargroupid();
	m_strGroupID = msg.m_strgroupid();
	m_EncGroupID = msg.m_encgroupid();
	m_activeADDtime = msg.m_activeaddtime();
	m_costItem = msg.m_costitem();
	m_costNum = msg.m_costnum();
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_AvatarArtifactAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AvatarArtifact_s::Sheet_AvatarArtifact_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarArtifact_s::CreateInit() {
	return 0;
}

int Sheet_AvatarArtifact_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarArtifact_s::write_to_pbmsg(::proto_ff::Sheet_AvatarArtifact & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarArtifact_List.size(); ++i) {
		::proto_ff::E_AvatarArtifact* temp_e_avatarartifact_list = msg.add_e_avatarartifact_list();
		E_AvatarArtifact_List[i].write_to_pbmsg(*temp_e_avatarartifact_list);
	}
}

void Sheet_AvatarArtifact_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarArtifact & msg) {
	E_AvatarArtifact_List.resize((int)msg.e_avatarartifact_list_size() > (int)E_AvatarArtifact_List.max_size() ? E_AvatarArtifact_List.max_size() : msg.e_avatarartifact_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarArtifact_List.size(); ++i) {
		const ::proto_ff::E_AvatarArtifact & temp_e_avatarartifact_list = msg.e_avatarartifact_list(i);
		E_AvatarArtifact_List[i].read_from_pbmsg(temp_e_avatarartifact_list);
	}
}

E_AvatarArtifact_facade_s::E_AvatarArtifact_facade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarArtifact_facade_s::CreateInit() {
	m_ID = (int32_t)0;
	m_changeID = (int32_t)0;
	m_starGroupID = (int32_t)0;
	m_costItem = (int32_t)0;
	m_costNum = (int32_t)0;
	m_activeReduceCD = (int32_t)0;
	return 0;
}

int E_AvatarArtifact_facade_s::ResumeInit() {
	return 0;
}

void E_AvatarArtifact_facade_s::write_to_pbmsg(::proto_ff::E_AvatarArtifact_facade & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_changeid((int32_t)m_changeID);
	msg.set_m_stargroupid((int32_t)m_starGroupID);
	msg.set_m_costitem((int32_t)m_costItem);
	msg.set_m_costnum((int32_t)m_costNum);
	msg.set_m_activereducecd((int32_t)m_activeReduceCD);
}

void E_AvatarArtifact_facade_s::read_from_pbmsg(const ::proto_ff::E_AvatarArtifact_facade & msg) {
	m_ID = msg.m_id();
	m_changeID = msg.m_changeid();
	m_starGroupID = msg.m_stargroupid();
	m_costItem = msg.m_costitem();
	m_costNum = msg.m_costnum();
	m_activeReduceCD = msg.m_activereducecd();
}

Sheet_AvatarArtifact_facade_s::Sheet_AvatarArtifact_facade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarArtifact_facade_s::CreateInit() {
	return 0;
}

int Sheet_AvatarArtifact_facade_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarArtifact_facade_s::write_to_pbmsg(::proto_ff::Sheet_AvatarArtifact_facade & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarArtifact_facade_List.size(); ++i) {
		::proto_ff::E_AvatarArtifact_facade* temp_e_avatarartifact_facade_list = msg.add_e_avatarartifact_facade_list();
		E_AvatarArtifact_facade_List[i].write_to_pbmsg(*temp_e_avatarartifact_facade_list);
	}
}

void Sheet_AvatarArtifact_facade_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarArtifact_facade & msg) {
	E_AvatarArtifact_facade_List.resize((int)msg.e_avatarartifact_facade_list_size() > (int)E_AvatarArtifact_facade_List.max_size() ? E_AvatarArtifact_facade_List.max_size() : msg.e_avatarartifact_facade_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarArtifact_facade_List.size(); ++i) {
		const ::proto_ff::E_AvatarArtifact_facade & temp_e_avatarartifact_facade_list = msg.e_avatarartifact_facade_list(i);
		E_AvatarArtifact_facade_List[i].read_from_pbmsg(temp_e_avatarartifact_facade_list);
	}
}

E_AvatarArtifact_starAttributeDesc_s::E_AvatarArtifact_starAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarArtifact_starAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AvatarArtifact_starAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AvatarArtifact_starAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AvatarArtifact_starAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_AvatarArtifact_starAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AvatarArtifact_starAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_AvatarArtifact_star_s::E_AvatarArtifact_star_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarArtifact_star_s::CreateInit() {
	m_ID = (int32_t)0;
	m_groupID = (int32_t)0;
	m_star = (int32_t)0;
	m_costItem = (int32_t)0;
	m_costNum = (int32_t)0;
	m_EnchantMaxADD = (int32_t)0;
	return 0;
}

int E_AvatarArtifact_star_s::ResumeInit() {
	return 0;
}

void E_AvatarArtifact_star_s::write_to_pbmsg(::proto_ff::E_AvatarArtifact_star & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_costitem((int32_t)m_costItem);
	msg.set_m_costnum((int32_t)m_costNum);
	msg.set_m_enchantmaxadd((int32_t)m_EnchantMaxADD);
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_AvatarArtifact_starAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AvatarArtifact_star_s::read_from_pbmsg(const ::proto_ff::E_AvatarArtifact_star & msg) {
	m_ID = msg.m_id();
	m_groupID = msg.m_groupid();
	m_star = msg.m_star();
	m_costItem = msg.m_costitem();
	m_costNum = msg.m_costnum();
	m_EnchantMaxADD = msg.m_enchantmaxadd();
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_AvatarArtifact_starAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AvatarArtifact_star_s::Sheet_AvatarArtifact_star_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarArtifact_star_s::CreateInit() {
	return 0;
}

int Sheet_AvatarArtifact_star_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarArtifact_star_s::write_to_pbmsg(::proto_ff::Sheet_AvatarArtifact_star & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarArtifact_star_List.size(); ++i) {
		::proto_ff::E_AvatarArtifact_star* temp_e_avatarartifact_star_list = msg.add_e_avatarartifact_star_list();
		E_AvatarArtifact_star_List[i].write_to_pbmsg(*temp_e_avatarartifact_star_list);
	}
}

void Sheet_AvatarArtifact_star_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarArtifact_star & msg) {
	E_AvatarArtifact_star_List.resize((int)msg.e_avatarartifact_star_list_size() > (int)E_AvatarArtifact_star_List.max_size() ? E_AvatarArtifact_star_List.max_size() : msg.e_avatarartifact_star_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarArtifact_star_List.size(); ++i) {
		const ::proto_ff::E_AvatarArtifact_star & temp_e_avatarartifact_star_list = msg.e_avatarartifact_star_list(i);
		E_AvatarArtifact_star_List[i].read_from_pbmsg(temp_e_avatarartifact_star_list);
	}
}

E_AvatarArtifact_strengthenAttributeDesc_s::E_AvatarArtifact_strengthenAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarArtifact_strengthenAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_AvatarArtifact_strengthenAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AvatarArtifact_strengthenAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AvatarArtifact_strengthenAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_AvatarArtifact_strengthenAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AvatarArtifact_strengthenAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_AvatarArtifact_strengthen_s::E_AvatarArtifact_strengthen_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarArtifact_strengthen_s::CreateInit() {
	m_ID = (int32_t)0;
	m_groupID = (int32_t)0;
	m_lv = (int32_t)0;
	m_costItem = (int32_t)0;
	m_costNum = (int32_t)0;
	m_star = (int32_t)0;
	return 0;
}

int E_AvatarArtifact_strengthen_s::ResumeInit() {
	return 0;
}

void E_AvatarArtifact_strengthen_s::write_to_pbmsg(::proto_ff::E_AvatarArtifact_strengthen & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_costitem((int32_t)m_costItem);
	msg.set_m_costnum((int32_t)m_costNum);
	msg.set_m_star((int32_t)m_star);
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_AvatarArtifact_strengthenAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AvatarArtifact_strengthen_s::read_from_pbmsg(const ::proto_ff::E_AvatarArtifact_strengthen & msg) {
	m_ID = msg.m_id();
	m_groupID = msg.m_groupid();
	m_lv = msg.m_lv();
	m_costItem = msg.m_costitem();
	m_costNum = msg.m_costnum();
	m_star = msg.m_star();
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_AvatarArtifact_strengthenAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_AvatarArtifact_strengthen_s::Sheet_AvatarArtifact_strengthen_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarArtifact_strengthen_s::CreateInit() {
	return 0;
}

int Sheet_AvatarArtifact_strengthen_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarArtifact_strengthen_s::write_to_pbmsg(::proto_ff::Sheet_AvatarArtifact_strengthen & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarArtifact_strengthen_List.size(); ++i) {
		::proto_ff::E_AvatarArtifact_strengthen* temp_e_avatarartifact_strengthen_list = msg.add_e_avatarartifact_strengthen_list();
		E_AvatarArtifact_strengthen_List[i].write_to_pbmsg(*temp_e_avatarartifact_strengthen_list);
	}
}

void Sheet_AvatarArtifact_strengthen_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarArtifact_strengthen & msg) {
	E_AvatarArtifact_strengthen_List.resize((int)msg.e_avatarartifact_strengthen_list_size() > (int)E_AvatarArtifact_strengthen_List.max_size() ? E_AvatarArtifact_strengthen_List.max_size() : msg.e_avatarartifact_strengthen_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarArtifact_strengthen_List.size(); ++i) {
		const ::proto_ff::E_AvatarArtifact_strengthen & temp_e_avatarartifact_strengthen_list = msg.e_avatarartifact_strengthen_list(i);
		E_AvatarArtifact_strengthen_List[i].read_from_pbmsg(temp_e_avatarartifact_strengthen_list);
	}
}

E_AvatarArtifact_enchant_s::E_AvatarArtifact_enchant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarArtifact_enchant_s::CreateInit() {
	m_ID = (int32_t)0;
	m_groupID = (int32_t)0;
	m_lv = (int32_t)0;
	m_costItem = (int32_t)0;
	m_costNum = (int32_t)0;
	m_upValue = (int32_t)0;
	return 0;
}

int E_AvatarArtifact_enchant_s::ResumeInit() {
	return 0;
}

void E_AvatarArtifact_enchant_s::write_to_pbmsg(::proto_ff::E_AvatarArtifact_enchant & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_costitem((int32_t)m_costItem);
	msg.set_m_costnum((int32_t)m_costNum);
	msg.set_m_upvalue((int32_t)m_upValue);
}

void E_AvatarArtifact_enchant_s::read_from_pbmsg(const ::proto_ff::E_AvatarArtifact_enchant & msg) {
	m_ID = msg.m_id();
	m_groupID = msg.m_groupid();
	m_lv = msg.m_lv();
	m_costItem = msg.m_costitem();
	m_costNum = msg.m_costnum();
	m_upValue = msg.m_upvalue();
}

Sheet_AvatarArtifact_enchant_s::Sheet_AvatarArtifact_enchant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarArtifact_enchant_s::CreateInit() {
	return 0;
}

int Sheet_AvatarArtifact_enchant_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarArtifact_enchant_s::write_to_pbmsg(::proto_ff::Sheet_AvatarArtifact_enchant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarArtifact_enchant_List.size(); ++i) {
		::proto_ff::E_AvatarArtifact_enchant* temp_e_avatarartifact_enchant_list = msg.add_e_avatarartifact_enchant_list();
		E_AvatarArtifact_enchant_List[i].write_to_pbmsg(*temp_e_avatarartifact_enchant_list);
	}
}

void Sheet_AvatarArtifact_enchant_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarArtifact_enchant & msg) {
	E_AvatarArtifact_enchant_List.resize((int)msg.e_avatarartifact_enchant_list_size() > (int)E_AvatarArtifact_enchant_List.max_size() ? E_AvatarArtifact_enchant_List.max_size() : msg.e_avatarartifact_enchant_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarArtifact_enchant_List.size(); ++i) {
		const ::proto_ff::E_AvatarArtifact_enchant & temp_e_avatarartifact_enchant_list = msg.e_avatarartifact_enchant_list(i);
		E_AvatarArtifact_enchant_List[i].read_from_pbmsg(temp_e_avatarartifact_enchant_list);
	}
}

E_AvatarArtifact_decompose_s::E_AvatarArtifact_decompose_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AvatarArtifact_decompose_s::CreateInit() {
	m_itemID = (int32_t)0;
	m_decomposeItem = (int32_t)0;
	m_decomposeNum = (int32_t)0;
	return 0;
}

int E_AvatarArtifact_decompose_s::ResumeInit() {
	return 0;
}

void E_AvatarArtifact_decompose_s::write_to_pbmsg(::proto_ff::E_AvatarArtifact_decompose & msg) const {
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_decomposeitem((int32_t)m_decomposeItem);
	msg.set_m_decomposenum((int32_t)m_decomposeNum);
}

void E_AvatarArtifact_decompose_s::read_from_pbmsg(const ::proto_ff::E_AvatarArtifact_decompose & msg) {
	m_itemID = msg.m_itemid();
	m_decomposeItem = msg.m_decomposeitem();
	m_decomposeNum = msg.m_decomposenum();
}

Sheet_AvatarArtifact_decompose_s::Sheet_AvatarArtifact_decompose_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AvatarArtifact_decompose_s::CreateInit() {
	return 0;
}

int Sheet_AvatarArtifact_decompose_s::ResumeInit() {
	return 0;
}

void Sheet_AvatarArtifact_decompose_s::write_to_pbmsg(::proto_ff::Sheet_AvatarArtifact_decompose & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AvatarArtifact_decompose_List.size(); ++i) {
		::proto_ff::E_AvatarArtifact_decompose* temp_e_avatarartifact_decompose_list = msg.add_e_avatarartifact_decompose_list();
		E_AvatarArtifact_decompose_List[i].write_to_pbmsg(*temp_e_avatarartifact_decompose_list);
	}
}

void Sheet_AvatarArtifact_decompose_s::read_from_pbmsg(const ::proto_ff::Sheet_AvatarArtifact_decompose & msg) {
	E_AvatarArtifact_decompose_List.resize((int)msg.e_avatarartifact_decompose_list_size() > (int)E_AvatarArtifact_decompose_List.max_size() ? E_AvatarArtifact_decompose_List.max_size() : msg.e_avatarartifact_decompose_list_size());
	for(int32_t i = 0; i < (int32_t)E_AvatarArtifact_decompose_List.size(); ++i) {
		const ::proto_ff::E_AvatarArtifact_decompose & temp_e_avatarartifact_decompose_list = msg.e_avatarartifact_decompose_list(i);
		E_AvatarArtifact_decompose_List[i].read_from_pbmsg(temp_e_avatarartifact_decompose_list);
	}
}

}
