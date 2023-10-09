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
	m_fragmentid = (int64_t)0;
	m_item = (int64_t)0;
	m_itemnum = (int32_t)0;
	return 0;
}

int E_AvatarFragment_s::ResumeInit() {
	return 0;
}

void E_AvatarFragment_s::write_to_pbmsg(::proto_ff::E_AvatarFragment & msg) const {
	msg.set_m_fragmentid((int64_t)m_fragmentid);
	msg.set_m_item((int64_t)m_item);
	msg.set_m_itemnum((int32_t)m_itemnum);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_AvatarFragmentAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AvatarFragment_s::read_from_pbmsg(const ::proto_ff::E_AvatarFragment & msg) {
	m_fragmentid = msg.m_fragmentid();
	m_item = msg.m_item();
	m_itemnum = msg.m_itemnum();
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
	m_exp = (int32_t)0;
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
	msg.set_m_exp((int32_t)m_exp);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_AvatarValueAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AvatarValue_s::read_from_pbmsg(const ::proto_ff::E_AvatarValue & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_lv = msg.m_lv();
	m_cost = msg.m_cost();
	m_exp = msg.m_exp();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_AvatarValueAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
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
	m_uplvtype = (int32_t)0;
	return 0;
}

int E_AvatarDisplay_s::ResumeInit() {
	return 0;
}

void E_AvatarDisplay_s::write_to_pbmsg(::proto_ff::E_AvatarDisplay & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_uplvtype((int32_t)m_uplvtype);
	msg.set_m_skillid(m_skillid.data());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_AvatarDisplayMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_fragmentid.size(); ++i) {
		msg.add_m_fragmentid((int64_t)m_fragmentid[i]);
	}
}

void E_AvatarDisplay_s::read_from_pbmsg(const ::proto_ff::E_AvatarDisplay & msg) {
	m_id = msg.m_id();
	m_uplvtype = msg.m_uplvtype();
	m_skillid = msg.m_skillid();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_AvatarDisplayMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_fragmentid.resize((int)msg.m_fragmentid_size() > (int)m_fragmentid.max_size() ? m_fragmentid.max_size() : msg.m_fragmentid_size());
	for(int32_t i = 0; i < (int32_t)m_fragmentid.size(); ++i) {
		m_fragmentid[i] = msg.m_fragmentid(i);
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
	m_upvalue = (int32_t)0;
	m_upber = (int32_t)0;
	return 0;
}

int E_AvatarChangeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_AvatarChangeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_AvatarChangeAttributeDesc & msg) const {
	msg.set_m_upvalue((int32_t)m_upvalue);
	msg.set_m_upber((int32_t)m_upber);
}

void E_AvatarChangeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_AvatarChangeAttributeDesc & msg) {
	m_upvalue = msg.m_upvalue();
	m_upber = msg.m_upber();
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
	m_uplvtype = (int32_t)0;
	m_avatarskill = (int64_t)0;
	m_avatarcd = (int32_t)0;
	m_avatartime = (int32_t)0;
	m_avatarshield = (int32_t)0;
	m_starmax = (int32_t)0;
	m_lvmax = (int32_t)0;
	m_modelid = (int32_t)0;
	m_advance = (int32_t)0;
	m_activationitem = (int32_t)0;
	m_activationnum = (int32_t)0;
	m_starid = (int32_t)0;
	m_starupattributeid = (int32_t)0;
	m_fununlock = (int32_t)0;
	m_maxequip = (int32_t)0;
	m_equipsuit = (int32_t)0;
	m_starber = (int32_t)0;
	return 0;
}

int E_AvatarChange_s::ResumeInit() {
	return 0;
}

void E_AvatarChange_s::write_to_pbmsg(::proto_ff::E_AvatarChange & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_uplvtype((int32_t)m_uplvtype);
	msg.set_m_avatarskill((int64_t)m_avatarskill);
	msg.set_m_avatarcd((int32_t)m_avatarcd);
	msg.set_m_avatartime((int32_t)m_avatartime);
	msg.set_m_avatarshield((int32_t)m_avatarshield);
	msg.set_m_skillid(m_skillid.data());
	msg.set_m_starmax((int32_t)m_starmax);
	msg.set_m_lvmax((int32_t)m_lvmax);
	msg.set_m_modelid((int32_t)m_modelid);
	msg.set_m_advance((int32_t)m_advance);
	msg.set_m_activationitem((int32_t)m_activationitem);
	msg.set_m_activationnum((int32_t)m_activationnum);
	msg.set_m_starid((int32_t)m_starid);
	msg.set_m_starnum(m_starnum.data());
	msg.set_m_starupattributeid((int32_t)m_starupattributeid);
	msg.set_m_fununlock((int32_t)m_fununlock);
	msg.set_m_maxequip((int32_t)m_maxequip);
	msg.set_m_equipsuit((int32_t)m_equipsuit);
	msg.set_m_starber((int32_t)m_starber);
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_AvatarChangeMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_initiativeskill.size(); ++i) {
		msg.add_m_initiativeskill((int64_t)m_initiativeskill[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_AvatarChangeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AvatarChange_s::read_from_pbmsg(const ::proto_ff::E_AvatarChange & msg) {
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_uplvtype = msg.m_uplvtype();
	m_avatarskill = msg.m_avatarskill();
	m_avatarcd = msg.m_avatarcd();
	m_avatartime = msg.m_avatartime();
	m_avatarshield = msg.m_avatarshield();
	m_skillid = msg.m_skillid();
	m_starmax = msg.m_starmax();
	m_lvmax = msg.m_lvmax();
	m_modelid = msg.m_modelid();
	m_advance = msg.m_advance();
	m_activationitem = msg.m_activationitem();
	m_activationnum = msg.m_activationnum();
	m_starid = msg.m_starid();
	m_starnum = msg.m_starnum();
	m_starupattributeid = msg.m_starupattributeid();
	m_fununlock = msg.m_fununlock();
	m_maxequip = msg.m_maxequip();
	m_equipsuit = msg.m_equipsuit();
	m_starber = msg.m_starber();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_AvatarChangeMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_initiativeskill.resize((int)msg.m_initiativeskill_size() > (int)m_initiativeskill.max_size() ? m_initiativeskill.max_size() : msg.m_initiativeskill_size());
	for(int32_t i = 0; i < (int32_t)m_initiativeskill.size(); ++i) {
		m_initiativeskill[i] = msg.m_initiativeskill(i);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_AvatarChangeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
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
	m_tabid = (int32_t)0;
	return 0;
}

int E_AvatarChangetab_s::ResumeInit() {
	return 0;
}

void E_AvatarChangetab_s::write_to_pbmsg(::proto_ff::E_AvatarChangetab & msg) const {
	msg.set_m_tabid((int32_t)m_tabid);
}

void E_AvatarChangetab_s::read_from_pbmsg(const ::proto_ff::E_AvatarChangetab & msg) {
	m_tabid = msg.m_tabid();
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
	m_upattributeid = (int32_t)0;
	m_starid = (int32_t)0;
	m_skillid = (int32_t)0;
	return 0;
}

int E_AvatarAdvance_s::ResumeInit() {
	return 0;
}

void E_AvatarAdvance_s::write_to_pbmsg(::proto_ff::E_AvatarAdvance & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_upattributeid((int32_t)m_upattributeid);
	msg.set_m_starid((int32_t)m_starid);
	msg.set_m_skillid((int32_t)m_skillid);
	for(int32_t i = 0; i < (int32_t)m_upattribute.size(); ++i) {
		::proto_ff::E_AvatarAdvanceUpattributeDesc* temp_m_upattribute = msg.add_m_upattribute();
		m_upattribute[i].write_to_pbmsg(*temp_m_upattribute);
	}
}

void E_AvatarAdvance_s::read_from_pbmsg(const ::proto_ff::E_AvatarAdvance & msg) {
	m_id = msg.m_id();
	m_upattributeid = msg.m_upattributeid();
	m_starid = msg.m_starid();
	m_skillid = msg.m_skillid();
	m_upattribute.resize((int)msg.m_upattribute_size() > (int)m_upattribute.max_size() ? m_upattribute.max_size() : msg.m_upattribute_size());
	for(int32_t i = 0; i < (int32_t)m_upattribute.size(); ++i) {
		const ::proto_ff::E_AvatarAdvanceUpattributeDesc & temp_m_upattribute = msg.m_upattribute(i);
		m_upattribute[i].read_from_pbmsg(temp_m_upattribute);
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
	m_groupid = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	return 0;
}

int E_AvatarEquipsuit_s::ResumeInit() {
	return 0;
}

void E_AvatarEquipsuit_s::write_to_pbmsg(::proto_ff::E_AvatarEquipsuit & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_AvatarEquipsuitAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_AvatarEquipsuit_s::read_from_pbmsg(const ::proto_ff::E_AvatarEquipsuit & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_AvatarEquipsuitAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
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

}
