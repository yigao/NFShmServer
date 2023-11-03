#include "E_Mount_s.h"

namespace proto_ff_s {

E_MountFragmentAttributeDesc_s::E_MountFragmentAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountFragmentAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MountFragmentAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountFragmentAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MountFragmentAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MountFragmentAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountFragmentAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MountFragment_s::E_MountFragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountFragment_s::CreateInit() {
	m_fragmentID = (int64_t)0;
	m_item = (int64_t)0;
	m_itemNum = (int32_t)0;
	return 0;
}

int E_MountFragment_s::ResumeInit() {
	return 0;
}

void E_MountFragment_s::write_to_pbmsg(::proto_ff::E_MountFragment & msg) const {
	msg.set_m_fragmentid((int64_t)m_fragmentID);
	msg.set_m_item((int64_t)m_item);
	msg.set_m_itemnum((int32_t)m_itemNum);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MountFragmentAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountFragment_s::read_from_pbmsg(const ::proto_ff::E_MountFragment & msg) {
	m_fragmentID = msg.m_fragmentid();
	m_item = msg.m_item();
	m_itemNum = msg.m_itemnum();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_MountFragmentAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_MountFragment_s::Sheet_MountFragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountFragment_s::CreateInit() {
	return 0;
}

int Sheet_MountFragment_s::ResumeInit() {
	return 0;
}

void Sheet_MountFragment_s::write_to_pbmsg(::proto_ff::Sheet_MountFragment & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountFragment_List.size(); ++i) {
		::proto_ff::E_MountFragment* temp_e_mountfragment_list = msg.add_e_mountfragment_list();
		E_MountFragment_List[i].write_to_pbmsg(*temp_e_mountfragment_list);
	}
}

void Sheet_MountFragment_s::read_from_pbmsg(const ::proto_ff::Sheet_MountFragment & msg) {
	E_MountFragment_List.resize((int)msg.e_mountfragment_list_size() > (int)E_MountFragment_List.max_size() ? E_MountFragment_List.max_size() : msg.e_mountfragment_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountFragment_List.size(); ++i) {
		const ::proto_ff::E_MountFragment & temp_e_mountfragment_list = msg.e_mountfragment_list(i);
		E_MountFragment_List[i].read_from_pbmsg(temp_e_mountfragment_list);
	}
}

E_MountValueAttributeDesc_s::E_MountValueAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountValueAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MountValueAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountValueAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MountValueAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MountValueAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountValueAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MountValue_s::E_MountValue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountValue_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_lv = (int32_t)0;
	m_Exp = (int32_t)0;
	m_speed = (int32_t)0;
	return 0;
}

int E_MountValue_s::ResumeInit() {
	return 0;
}

void E_MountValue_s::write_to_pbmsg(::proto_ff::E_MountValue & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int32_t)m_Exp);
	msg.set_m_speed((int32_t)m_speed);
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_MountValueAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountValue_s::read_from_pbmsg(const ::proto_ff::E_MountValue & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_lv = msg.m_lv();
	m_Exp = msg.m_exp();
	m_speed = msg.m_speed();
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_MountValueAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_MountValue_s::Sheet_MountValue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountValue_s::CreateInit() {
	return 0;
}

int Sheet_MountValue_s::ResumeInit() {
	return 0;
}

void Sheet_MountValue_s::write_to_pbmsg(::proto_ff::Sheet_MountValue & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountValue_List.size(); ++i) {
		::proto_ff::E_MountValue* temp_e_mountvalue_list = msg.add_e_mountvalue_list();
		E_MountValue_List[i].write_to_pbmsg(*temp_e_mountvalue_list);
	}
}

void Sheet_MountValue_s::read_from_pbmsg(const ::proto_ff::Sheet_MountValue & msg) {
	E_MountValue_List.resize((int)msg.e_mountvalue_list_size() > (int)E_MountValue_List.max_size() ? E_MountValue_List.max_size() : msg.e_mountvalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountValue_List.size(); ++i) {
		const ::proto_ff::E_MountValue & temp_e_mountvalue_list = msg.e_mountvalue_list(i);
		E_MountValue_List[i].read_from_pbmsg(temp_e_mountvalue_list);
	}
}

E_MountDisplayMaterialDesc_s::E_MountDisplayMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountDisplayMaterialDesc_s::CreateInit() {
	m_exp = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_MountDisplayMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_MountDisplayMaterialDesc_s::write_to_pbmsg(::proto_ff::E_MountDisplayMaterialDesc & msg) const {
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_id((int32_t)m_id);
}

void E_MountDisplayMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_MountDisplayMaterialDesc & msg) {
	m_exp = msg.m_exp();
	m_id = msg.m_id();
}

E_MountDisplay_s::E_MountDisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountDisplay_s::CreateInit() {
	m_id = (int32_t)0;
	m_speed = (int32_t)0;
	m_UpLvType = (int32_t)0;
	m_starUp = (int32_t)0;
	m_LvMax = (int32_t)0;
	return 0;
}

int E_MountDisplay_s::ResumeInit() {
	return 0;
}

void E_MountDisplay_s::write_to_pbmsg(::proto_ff::E_MountDisplay & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_speed((int32_t)m_speed);
	msg.set_m_uplvtype((int32_t)m_UpLvType);
	msg.set_m_skillid(m_skillID.data());
	msg.set_m_fxid(m_fxID.data());
	msg.set_m_starup((int32_t)m_starUp);
	msg.set_m_lvmax((int32_t)m_LvMax);
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_MountDisplayMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_fragmentID.size(); ++i) {
		msg.add_m_fragmentid((int64_t)m_fragmentID[i]);
	}
}

void E_MountDisplay_s::read_from_pbmsg(const ::proto_ff::E_MountDisplay & msg) {
	m_id = msg.m_id();
	m_speed = msg.m_speed();
	m_UpLvType = msg.m_uplvtype();
	m_skillID = msg.m_skillid();
	m_fxID = msg.m_fxid();
	m_starUp = msg.m_starup();
	m_LvMax = msg.m_lvmax();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_MountDisplayMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_fragmentID.resize((int)msg.m_fragmentid_size() > (int)m_fragmentID.max_size() ? m_fragmentID.max_size() : msg.m_fragmentid_size());
	for(int32_t i = 0; i < (int32_t)m_fragmentID.size(); ++i) {
		m_fragmentID[i] = msg.m_fragmentid(i);
	}
}

Sheet_MountDisplay_s::Sheet_MountDisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountDisplay_s::CreateInit() {
	return 0;
}

int Sheet_MountDisplay_s::ResumeInit() {
	return 0;
}

void Sheet_MountDisplay_s::write_to_pbmsg(::proto_ff::Sheet_MountDisplay & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountDisplay_List.size(); ++i) {
		::proto_ff::E_MountDisplay* temp_e_mountdisplay_list = msg.add_e_mountdisplay_list();
		E_MountDisplay_List[i].write_to_pbmsg(*temp_e_mountdisplay_list);
	}
}

void Sheet_MountDisplay_s::read_from_pbmsg(const ::proto_ff::Sheet_MountDisplay & msg) {
	E_MountDisplay_List.resize((int)msg.e_mountdisplay_list_size() > (int)E_MountDisplay_List.max_size() ? E_MountDisplay_List.max_size() : msg.e_mountdisplay_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountDisplay_List.size(); ++i) {
		const ::proto_ff::E_MountDisplay & temp_e_mountdisplay_list = msg.e_mountdisplay_list(i);
		E_MountDisplay_List[i].read_from_pbmsg(temp_e_mountdisplay_list);
	}
}

E_MountUnlock_s::E_MountUnlock_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountUnlock_s::CreateInit() {
	m_id = (int32_t)0;
	m_Lv = (int32_t)0;
	m_ModelID = (int32_t)0;
	return 0;
}

int E_MountUnlock_s::ResumeInit() {
	return 0;
}

void E_MountUnlock_s::write_to_pbmsg(::proto_ff::E_MountUnlock & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lv((int32_t)m_Lv);
	msg.set_m_modelid((int32_t)m_ModelID);
	msg.set_m_name(m_Name.data());
}

void E_MountUnlock_s::read_from_pbmsg(const ::proto_ff::E_MountUnlock & msg) {
	m_id = msg.m_id();
	m_Lv = msg.m_lv();
	m_ModelID = msg.m_modelid();
	m_Name = msg.m_name();
}

Sheet_MountUnlock_s::Sheet_MountUnlock_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountUnlock_s::CreateInit() {
	return 0;
}

int Sheet_MountUnlock_s::ResumeInit() {
	return 0;
}

void Sheet_MountUnlock_s::write_to_pbmsg(::proto_ff::Sheet_MountUnlock & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountUnlock_List.size(); ++i) {
		::proto_ff::E_MountUnlock* temp_e_mountunlock_list = msg.add_e_mountunlock_list();
		E_MountUnlock_List[i].write_to_pbmsg(*temp_e_mountunlock_list);
	}
}

void Sheet_MountUnlock_s::read_from_pbmsg(const ::proto_ff::Sheet_MountUnlock & msg) {
	E_MountUnlock_List.resize((int)msg.e_mountunlock_list_size() > (int)E_MountUnlock_List.max_size() ? E_MountUnlock_List.max_size() : msg.e_mountunlock_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountUnlock_List.size(); ++i) {
		const ::proto_ff::E_MountUnlock & temp_e_mountunlock_list = msg.e_mountunlock_list(i);
		E_MountUnlock_List[i].read_from_pbmsg(temp_e_mountunlock_list);
	}
}

E_MountChangeMaterialDesc_s::E_MountChangeMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountChangeMaterialDesc_s::CreateInit() {
	m_exp = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_MountChangeMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_MountChangeMaterialDesc_s::write_to_pbmsg(::proto_ff::E_MountChangeMaterialDesc & msg) const {
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_id((int32_t)m_id);
}

void E_MountChangeMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_MountChangeMaterialDesc & msg) {
	m_exp = msg.m_exp();
	m_id = msg.m_id();
}

E_MountChangeAttributeDesc_s::E_MountChangeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountChangeAttributeDesc_s::CreateInit() {
	m_UpValue = (int32_t)0;
	m_UpBer = (int32_t)0;
	return 0;
}

int E_MountChangeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountChangeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MountChangeAttributeDesc & msg) const {
	msg.set_m_upvalue((int32_t)m_UpValue);
	msg.set_m_upber((int32_t)m_UpBer);
}

void E_MountChangeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountChangeAttributeDesc & msg) {
	m_UpValue = msg.m_upvalue();
	m_UpBer = msg.m_upber();
}

E_MountChange_s::E_MountChange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountChange_s::CreateInit() {
	m_id = (int32_t)0;
	m_speed = (int32_t)0;
	m_UpLvType = (int32_t)0;
	m_activeSkill = (int32_t)0;
	m_starMax = (int32_t)0;
	m_LvMax = (int32_t)0;
	m_ModelID = (int32_t)0;
	m_activationItem = (int32_t)0;
	m_activationNum = (int32_t)0;
	m_starId = (int32_t)0;
	m_starBer = (int32_t)0;
	m_upAttributeId = (int32_t)0;
	return 0;
}

int E_MountChange_s::ResumeInit() {
	return 0;
}

void E_MountChange_s::write_to_pbmsg(::proto_ff::E_MountChange & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_advancename(m_advanceName.data());
	msg.set_m_speed((int32_t)m_speed);
	msg.set_m_uplvtype((int32_t)m_UpLvType);
	msg.set_m_activeskill((int32_t)m_activeSkill);
	msg.set_m_skillid(m_skillID.data());
	msg.set_m_fxid(m_fxID.data());
	msg.set_m_starmax((int32_t)m_starMax);
	msg.set_m_lvmax((int32_t)m_LvMax);
	msg.set_m_modelid((int32_t)m_ModelID);
	msg.set_m_activationitem((int32_t)m_activationItem);
	msg.set_m_activationnum((int32_t)m_activationNum);
	msg.set_m_starid((int32_t)m_starId);
	msg.set_m_starnum(m_starNum.data());
	msg.set_m_starber((int32_t)m_starBer);
	msg.set_m_upattributeid((int32_t)m_upAttributeId);
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_MountChangeMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_MountChangeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountChange_s::read_from_pbmsg(const ::proto_ff::E_MountChange & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_advanceName = msg.m_advancename();
	m_speed = msg.m_speed();
	m_UpLvType = msg.m_uplvtype();
	m_activeSkill = msg.m_activeskill();
	m_skillID = msg.m_skillid();
	m_fxID = msg.m_fxid();
	m_starMax = msg.m_starmax();
	m_LvMax = msg.m_lvmax();
	m_ModelID = msg.m_modelid();
	m_activationItem = msg.m_activationitem();
	m_activationNum = msg.m_activationnum();
	m_starId = msg.m_starid();
	m_starNum = msg.m_starnum();
	m_starBer = msg.m_starber();
	m_upAttributeId = msg.m_upattributeid();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_MountChangeMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_MountChangeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_MountChange_s::Sheet_MountChange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountChange_s::CreateInit() {
	return 0;
}

int Sheet_MountChange_s::ResumeInit() {
	return 0;
}

void Sheet_MountChange_s::write_to_pbmsg(::proto_ff::Sheet_MountChange & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountChange_List.size(); ++i) {
		::proto_ff::E_MountChange* temp_e_mountchange_list = msg.add_e_mountchange_list();
		E_MountChange_List[i].write_to_pbmsg(*temp_e_mountchange_list);
	}
}

void Sheet_MountChange_s::read_from_pbmsg(const ::proto_ff::Sheet_MountChange & msg) {
	E_MountChange_List.resize((int)msg.e_mountchange_list_size() > (int)E_MountChange_List.max_size() ? E_MountChange_List.max_size() : msg.e_mountchange_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountChange_List.size(); ++i) {
		const ::proto_ff::E_MountChange & temp_e_mountchange_list = msg.e_mountchange_list(i);
		E_MountChange_List[i].read_from_pbmsg(temp_e_mountchange_list);
	}
}

E_MountAdvanceUpattributeDesc_s::E_MountAdvanceUpattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountAdvanceUpattributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MountAdvanceUpattributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountAdvanceUpattributeDesc_s::write_to_pbmsg(::proto_ff::E_MountAdvanceUpattributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MountAdvanceUpattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountAdvanceUpattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MountAdvance_s::E_MountAdvance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountAdvance_s::CreateInit() {
	m_id = (int32_t)0;
	m_upAttributeId = (int32_t)0;
	m_starID = (int32_t)0;
	m_skillID = (int32_t)0;
	return 0;
}

int E_MountAdvance_s::ResumeInit() {
	return 0;
}

void E_MountAdvance_s::write_to_pbmsg(::proto_ff::E_MountAdvance & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_upattributeid((int32_t)m_upAttributeId);
	msg.set_m_starid((int32_t)m_starID);
	msg.set_m_skillid((int32_t)m_skillID);
	for(int32_t i = 0; i < (int32_t)m_upAttribute.size(); ++i) {
		::proto_ff::E_MountAdvanceUpattributeDesc* temp_m_upattribute = msg.add_m_upattribute();
		m_upAttribute[i].write_to_pbmsg(*temp_m_upattribute);
	}
}

void E_MountAdvance_s::read_from_pbmsg(const ::proto_ff::E_MountAdvance & msg) {
	m_id = msg.m_id();
	m_upAttributeId = msg.m_upattributeid();
	m_starID = msg.m_starid();
	m_skillID = msg.m_skillid();
	m_upAttribute.resize((int)msg.m_upattribute_size() > (int)m_upAttribute.max_size() ? m_upAttribute.max_size() : msg.m_upattribute_size());
	for(int32_t i = 0; i < (int32_t)m_upAttribute.size(); ++i) {
		const ::proto_ff::E_MountAdvanceUpattributeDesc & temp_m_upattribute = msg.m_upattribute(i);
		m_upAttribute[i].read_from_pbmsg(temp_m_upattribute);
	}
}

Sheet_MountAdvance_s::Sheet_MountAdvance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountAdvance_s::CreateInit() {
	return 0;
}

int Sheet_MountAdvance_s::ResumeInit() {
	return 0;
}

void Sheet_MountAdvance_s::write_to_pbmsg(::proto_ff::Sheet_MountAdvance & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountAdvance_List.size(); ++i) {
		::proto_ff::E_MountAdvance* temp_e_mountadvance_list = msg.add_e_mountadvance_list();
		E_MountAdvance_List[i].write_to_pbmsg(*temp_e_mountadvance_list);
	}
}

void Sheet_MountAdvance_s::read_from_pbmsg(const ::proto_ff::Sheet_MountAdvance & msg) {
	E_MountAdvance_List.resize((int)msg.e_mountadvance_list_size() > (int)E_MountAdvance_List.max_size() ? E_MountAdvance_List.max_size() : msg.e_mountadvance_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountAdvance_List.size(); ++i) {
		const ::proto_ff::E_MountAdvance & temp_e_mountadvance_list = msg.e_mountadvance_list(i);
		E_MountAdvance_List[i].read_from_pbmsg(temp_e_mountadvance_list);
	}
}

E_MountBaby_egg_s::E_MountBaby_egg_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountBaby_egg_s::CreateInit() {
	m_id = (int32_t)0;
	m_item = (int32_t)0;
	m_time = (int32_t)0;
	m_itemBox = (int32_t)0;
	return 0;
}

int E_MountBaby_egg_s::ResumeInit() {
	return 0;
}

void E_MountBaby_egg_s::write_to_pbmsg(::proto_ff::E_MountBaby_egg & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_item((int32_t)m_item);
	msg.set_m_time((int32_t)m_time);
	msg.set_m_itembox((int32_t)m_itemBox);
}

void E_MountBaby_egg_s::read_from_pbmsg(const ::proto_ff::E_MountBaby_egg & msg) {
	m_id = msg.m_id();
	m_item = msg.m_item();
	m_time = msg.m_time();
	m_itemBox = msg.m_itembox();
}

Sheet_MountBaby_egg_s::Sheet_MountBaby_egg_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountBaby_egg_s::CreateInit() {
	return 0;
}

int Sheet_MountBaby_egg_s::ResumeInit() {
	return 0;
}

void Sheet_MountBaby_egg_s::write_to_pbmsg(::proto_ff::Sheet_MountBaby_egg & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountBaby_egg_List.size(); ++i) {
		::proto_ff::E_MountBaby_egg* temp_e_mountbaby_egg_list = msg.add_e_mountbaby_egg_list();
		E_MountBaby_egg_List[i].write_to_pbmsg(*temp_e_mountbaby_egg_list);
	}
}

void Sheet_MountBaby_egg_s::read_from_pbmsg(const ::proto_ff::Sheet_MountBaby_egg & msg) {
	E_MountBaby_egg_List.resize((int)msg.e_mountbaby_egg_list_size() > (int)E_MountBaby_egg_List.max_size() ? E_MountBaby_egg_List.max_size() : msg.e_mountbaby_egg_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountBaby_egg_List.size(); ++i) {
		const ::proto_ff::E_MountBaby_egg & temp_e_mountbaby_egg_list = msg.e_mountbaby_egg_list(i);
		E_MountBaby_egg_List[i].read_from_pbmsg(temp_e_mountbaby_egg_list);
	}
}

E_MountHuakunUplvDesc_s::E_MountHuakunUplvDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakunUplvDesc_s::CreateInit() {
	m_UpValue = (int32_t)0;
	m_UpBer = (int32_t)0;
	return 0;
}

int E_MountHuakunUplvDesc_s::ResumeInit() {
	return 0;
}

void E_MountHuakunUplvDesc_s::write_to_pbmsg(::proto_ff::E_MountHuakunUplvDesc & msg) const {
	msg.set_m_upvalue((int32_t)m_UpValue);
	msg.set_m_upber((int32_t)m_UpBer);
}

void E_MountHuakunUplvDesc_s::read_from_pbmsg(const ::proto_ff::E_MountHuakunUplvDesc & msg) {
	m_UpValue = msg.m_upvalue();
	m_UpBer = msg.m_upber();
}

E_MountHuakunMaterialDesc_s::E_MountHuakunMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakunMaterialDesc_s::CreateInit() {
	m_exp = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_MountHuakunMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_MountHuakunMaterialDesc_s::write_to_pbmsg(::proto_ff::E_MountHuakunMaterialDesc & msg) const {
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_id((int32_t)m_id);
}

void E_MountHuakunMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_MountHuakunMaterialDesc & msg) {
	m_exp = msg.m_exp();
	m_id = msg.m_id();
}

E_MountHuakunAdvanceDesc_s::E_MountHuakunAdvanceDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakunAdvanceDesc_s::CreateInit() {
	m_UpValue = (int32_t)0;
	m_UpBer = (int32_t)0;
	return 0;
}

int E_MountHuakunAdvanceDesc_s::ResumeInit() {
	return 0;
}

void E_MountHuakunAdvanceDesc_s::write_to_pbmsg(::proto_ff::E_MountHuakunAdvanceDesc & msg) const {
	msg.set_m_upvalue((int32_t)m_UpValue);
	msg.set_m_upber((int32_t)m_UpBer);
}

void E_MountHuakunAdvanceDesc_s::read_from_pbmsg(const ::proto_ff::E_MountHuakunAdvanceDesc & msg) {
	m_UpValue = msg.m_upvalue();
	m_UpBer = msg.m_upber();
}

E_MountHuakunAttributeDesc_s::E_MountHuakunAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakunAttributeDesc_s::CreateInit() {
	m_UpValue = (int32_t)0;
	m_UpBer = (int32_t)0;
	return 0;
}

int E_MountHuakunAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountHuakunAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MountHuakunAttributeDesc & msg) const {
	msg.set_m_upvalue((int32_t)m_UpValue);
	msg.set_m_upber((int32_t)m_UpBer);
}

void E_MountHuakunAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountHuakunAttributeDesc & msg) {
	m_UpValue = msg.m_upvalue();
	m_UpBer = msg.m_upber();
}

E_MountHuakun_s::E_MountHuakun_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakun_s::CreateInit() {
	m_id = (int32_t)0;
	m_ModelID = (int32_t)0;
	m_quality = (int32_t)0;
	m_speed = (int32_t)0;
	m_UpLvType = (int32_t)0;
	m_activateItem = (int32_t)0;
	m_activateItemNum = (int32_t)0;
	m_advanceType = (int32_t)0;
	m_starvanceType = (int32_t)0;
	m_starLimit = (int32_t)0;
	m_starBer = (int32_t)0;
	m_soaringAttributeId = (int32_t)0;
	m_comprehend = (int32_t)0;
	m_comprehendUpItem = (int32_t)0;
	m_comprehendType = (int32_t)0;
	m_ratio = (int32_t)0;
	m_ratioPercentage = (int32_t)0;
	m_qualityMax = (int32_t)0;
	return 0;
}

int E_MountHuakun_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_s::write_to_pbmsg(::proto_ff::E_MountHuakun & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_modelid((int32_t)m_ModelID);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_speed((int32_t)m_speed);
	msg.set_m_uplvtype((int32_t)m_UpLvType);
	msg.set_m_activateitem((int32_t)m_activateItem);
	msg.set_m_activateitemnum((int32_t)m_activateItemNum);
	msg.set_m_advancetype((int32_t)m_advanceType);
	msg.set_m_starvancetype((int32_t)m_starvanceType);
	msg.set_m_starlimit((int32_t)m_starLimit);
	msg.set_m_starber((int32_t)m_starBer);
	msg.set_m_skill_lg(m_skill_LG.data());
	msg.set_m_skill_bd(m_skill_BD.data());
	msg.set_m_soaringattributeid((int32_t)m_soaringAttributeId);
	msg.set_m_comprehend((int32_t)m_comprehend);
	msg.set_m_exclusive(m_exclusive.data());
	msg.set_m_comprehendskill(m_comprehendSkill.data());
	msg.set_m_potential(m_potential.data());
	msg.set_m_comprehendupitem((int32_t)m_comprehendUpItem);
	msg.set_m_comprehendtype((int32_t)m_comprehendType);
	msg.set_m_ratio((int32_t)m_ratio);
	msg.set_m_ratiopercentage((int32_t)m_ratioPercentage);
	msg.set_m_equipsuit(m_equipSuit.data());
	msg.set_m_qualitymax((int32_t)m_qualityMax);
	msg.set_m_lilianchangeitem(m_liLianChangeItem.data());
	for(int32_t i = 0; i < (int32_t)m_UpLv.size(); ++i) {
		::proto_ff::E_MountHuakunUplvDesc* temp_m_uplv = msg.add_m_uplv();
		m_UpLv[i].write_to_pbmsg(*temp_m_uplv);
	}
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_MountHuakunMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_advance.size(); ++i) {
		::proto_ff::E_MountHuakunAdvanceDesc* temp_m_advance = msg.add_m_advance();
		m_advance[i].write_to_pbmsg(*temp_m_advance);
	}
	for(int32_t i = 0; i < (int32_t)m_UpStarItem.size(); ++i) {
		msg.add_m_upstaritem((int32_t)m_UpStarItem[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_UpStarNum.size(); ++i) {
		msg.add_m_upstarnum(m_UpStarNum[i].data());
	}
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_MountHuakunAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountHuakun_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun & msg) {
	m_id = msg.m_id();
	m_ModelID = msg.m_modelid();
	m_quality = msg.m_quality();
	m_speed = msg.m_speed();
	m_UpLvType = msg.m_uplvtype();
	m_activateItem = msg.m_activateitem();
	m_activateItemNum = msg.m_activateitemnum();
	m_advanceType = msg.m_advancetype();
	m_starvanceType = msg.m_starvancetype();
	m_starLimit = msg.m_starlimit();
	m_starBer = msg.m_starber();
	m_skill_LG = msg.m_skill_lg();
	m_skill_BD = msg.m_skill_bd();
	m_soaringAttributeId = msg.m_soaringattributeid();
	m_comprehend = msg.m_comprehend();
	m_exclusive = msg.m_exclusive();
	m_comprehendSkill = msg.m_comprehendskill();
	m_potential = msg.m_potential();
	m_comprehendUpItem = msg.m_comprehendupitem();
	m_comprehendType = msg.m_comprehendtype();
	m_ratio = msg.m_ratio();
	m_ratioPercentage = msg.m_ratiopercentage();
	m_equipSuit = msg.m_equipsuit();
	m_qualityMax = msg.m_qualitymax();
	m_liLianChangeItem = msg.m_lilianchangeitem();
	m_UpLv.resize((int)msg.m_uplv_size() > (int)m_UpLv.max_size() ? m_UpLv.max_size() : msg.m_uplv_size());
	for(int32_t i = 0; i < (int32_t)m_UpLv.size(); ++i) {
		const ::proto_ff::E_MountHuakunUplvDesc & temp_m_uplv = msg.m_uplv(i);
		m_UpLv[i].read_from_pbmsg(temp_m_uplv);
	}
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_MountHuakunMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_advance.resize((int)msg.m_advance_size() > (int)m_advance.max_size() ? m_advance.max_size() : msg.m_advance_size());
	for(int32_t i = 0; i < (int32_t)m_advance.size(); ++i) {
		const ::proto_ff::E_MountHuakunAdvanceDesc & temp_m_advance = msg.m_advance(i);
		m_advance[i].read_from_pbmsg(temp_m_advance);
	}
	m_UpStarItem.resize((int)msg.m_upstaritem_size() > (int)m_UpStarItem.max_size() ? m_UpStarItem.max_size() : msg.m_upstaritem_size());
	for(int32_t i = 0; i < (int32_t)m_UpStarItem.size(); ++i) {
		m_UpStarItem[i] = msg.m_upstaritem(i);
	}
	m_UpStarNum.resize((int)msg.m_upstarnum_size() > (int)m_UpStarNum.max_size() ? m_UpStarNum.max_size() : msg.m_upstarnum_size());
	for(int32_t i = 0; i < (int32_t)m_UpStarNum.size(); ++i) {
		m_UpStarNum[i] = msg.m_upstarnum(i);
	}
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_MountHuakunAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_MountHuakun_s::Sheet_MountHuakun_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountHuakun_s::CreateInit() {
	return 0;
}

int Sheet_MountHuakun_s::ResumeInit() {
	return 0;
}

void Sheet_MountHuakun_s::write_to_pbmsg(::proto_ff::Sheet_MountHuakun & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountHuakun_List.size(); ++i) {
		::proto_ff::E_MountHuakun* temp_e_mounthuakun_list = msg.add_e_mounthuakun_list();
		E_MountHuakun_List[i].write_to_pbmsg(*temp_e_mounthuakun_list);
	}
}

void Sheet_MountHuakun_s::read_from_pbmsg(const ::proto_ff::Sheet_MountHuakun & msg) {
	E_MountHuakun_List.resize((int)msg.e_mounthuakun_list_size() > (int)E_MountHuakun_List.max_size() ? E_MountHuakun_List.max_size() : msg.e_mounthuakun_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountHuakun_List.size(); ++i) {
		const ::proto_ff::E_MountHuakun & temp_e_mounthuakun_list = msg.e_mounthuakun_list(i);
		E_MountHuakun_List[i].read_from_pbmsg(temp_e_mounthuakun_list);
	}
}

E_MountHuakun_valueAttributeDesc_s::E_MountHuakun_valueAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakun_valueAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MountHuakun_valueAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_valueAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MountHuakun_valueAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MountHuakun_valueAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_valueAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MountHuakun_value_s::E_MountHuakun_value_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakun_value_s::CreateInit() {
	m_id = (int64_t)0;
	m_huaKunType = (int32_t)0;
	m_huaKunLv = (int32_t)0;
	m_huaKunExp = (int32_t)0;
	return 0;
}

int E_MountHuakun_value_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_value_s::write_to_pbmsg(::proto_ff::E_MountHuakun_value & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_huakuntype((int32_t)m_huaKunType);
	msg.set_m_huakunlv((int32_t)m_huaKunLv);
	msg.set_m_huakunexp((int32_t)m_huaKunExp);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MountHuakun_valueAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountHuakun_value_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_value & msg) {
	m_id = msg.m_id();
	m_huaKunType = msg.m_huakuntype();
	m_huaKunLv = msg.m_huakunlv();
	m_huaKunExp = msg.m_huakunexp();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_MountHuakun_valueAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_MountHuakun_value_s::Sheet_MountHuakun_value_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountHuakun_value_s::CreateInit() {
	return 0;
}

int Sheet_MountHuakun_value_s::ResumeInit() {
	return 0;
}

void Sheet_MountHuakun_value_s::write_to_pbmsg(::proto_ff::Sheet_MountHuakun_value & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountHuakun_value_List.size(); ++i) {
		::proto_ff::E_MountHuakun_value* temp_e_mounthuakun_value_list = msg.add_e_mounthuakun_value_list();
		E_MountHuakun_value_List[i].write_to_pbmsg(*temp_e_mounthuakun_value_list);
	}
}

void Sheet_MountHuakun_value_s::read_from_pbmsg(const ::proto_ff::Sheet_MountHuakun_value & msg) {
	E_MountHuakun_value_List.resize((int)msg.e_mounthuakun_value_list_size() > (int)E_MountHuakun_value_List.max_size() ? E_MountHuakun_value_List.max_size() : msg.e_mounthuakun_value_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountHuakun_value_List.size(); ++i) {
		const ::proto_ff::E_MountHuakun_value & temp_e_mounthuakun_value_list = msg.e_mounthuakun_value_list(i);
		E_MountHuakun_value_List[i].read_from_pbmsg(temp_e_mounthuakun_value_list);
	}
}

E_MountHuakun_advancevalueItemDesc_s::E_MountHuakun_advancevalueItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakun_advancevalueItemDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_MountHuakun_advancevalueItemDesc_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_advancevalueItemDesc_s::write_to_pbmsg(::proto_ff::E_MountHuakun_advancevalueItemDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int32_t)m_id);
}

void E_MountHuakun_advancevalueItemDesc_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_advancevalueItemDesc & msg) {
	m_Num = msg.m_num();
	m_id = msg.m_id();
}

E_MountHuakun_advancevalue_s::E_MountHuakun_advancevalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakun_advancevalue_s::CreateInit() {
	m_id = (int32_t)0;
	m_Lv = (int32_t)0;
	m_advanceType = (int32_t)0;
	m_winProb = (int32_t)0;
	m_failLv = (int32_t)0;
	return 0;
}

int E_MountHuakun_advancevalue_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_advancevalue_s::write_to_pbmsg(::proto_ff::E_MountHuakun_advancevalue & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lv((int32_t)m_Lv);
	msg.set_m_advancetype((int32_t)m_advanceType);
	msg.set_m_winprob((int32_t)m_winProb);
	msg.set_m_faillv((int32_t)m_failLv);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_MountHuakun_advancevalueItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_MountHuakun_advancevalue_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_advancevalue & msg) {
	m_id = msg.m_id();
	m_Lv = msg.m_lv();
	m_advanceType = msg.m_advancetype();
	m_winProb = msg.m_winprob();
	m_failLv = msg.m_faillv();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_MountHuakun_advancevalueItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
}

Sheet_MountHuakun_advancevalue_s::Sheet_MountHuakun_advancevalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountHuakun_advancevalue_s::CreateInit() {
	return 0;
}

int Sheet_MountHuakun_advancevalue_s::ResumeInit() {
	return 0;
}

void Sheet_MountHuakun_advancevalue_s::write_to_pbmsg(::proto_ff::Sheet_MountHuakun_advancevalue & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountHuakun_advancevalue_List.size(); ++i) {
		::proto_ff::E_MountHuakun_advancevalue* temp_e_mounthuakun_advancevalue_list = msg.add_e_mounthuakun_advancevalue_list();
		E_MountHuakun_advancevalue_List[i].write_to_pbmsg(*temp_e_mounthuakun_advancevalue_list);
	}
}

void Sheet_MountHuakun_advancevalue_s::read_from_pbmsg(const ::proto_ff::Sheet_MountHuakun_advancevalue & msg) {
	E_MountHuakun_advancevalue_List.resize((int)msg.e_mounthuakun_advancevalue_list_size() > (int)E_MountHuakun_advancevalue_List.max_size() ? E_MountHuakun_advancevalue_List.max_size() : msg.e_mounthuakun_advancevalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountHuakun_advancevalue_List.size(); ++i) {
		const ::proto_ff::E_MountHuakun_advancevalue & temp_e_mounthuakun_advancevalue_list = msg.e_mounthuakun_advancevalue_list(i);
		E_MountHuakun_advancevalue_List[i].read_from_pbmsg(temp_e_mounthuakun_advancevalue_list);
	}
}

E_MountHuakun_changeAttributeDesc_s::E_MountHuakun_changeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakun_changeAttributeDesc_s::CreateInit() {
	m_UpValue = (int32_t)0;
	m_UpBer = (int32_t)0;
	return 0;
}

int E_MountHuakun_changeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_changeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MountHuakun_changeAttributeDesc & msg) const {
	msg.set_m_upvalue((int32_t)m_UpValue);
	msg.set_m_upber((int32_t)m_UpBer);
}

void E_MountHuakun_changeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_changeAttributeDesc & msg) {
	m_UpValue = msg.m_upvalue();
	m_UpBer = msg.m_upber();
}

E_MountHuakun_change_s::E_MountHuakun_change_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakun_change_s::CreateInit() {
	m_id = (int32_t)0;
	m_huaKunId = (int32_t)0;
	m_speed = (int32_t)0;
	m_ModelID = (int32_t)0;
	m_activationItem = (int32_t)0;
	m_activationNum = (int32_t)0;
	m_starAttributeId = (int32_t)0;
	m_starMax = (int32_t)0;
	m_starId = (int32_t)0;
	m_starBer = (int32_t)0;
	m_changeAttributeId = (int32_t)0;
	return 0;
}

int E_MountHuakun_change_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_change_s::write_to_pbmsg(::proto_ff::E_MountHuakun_change & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_huakunid((int32_t)m_huaKunId);
	msg.set_m_speed((int32_t)m_speed);
	msg.set_m_fxid(m_fxID.data());
	msg.set_m_modelid((int32_t)m_ModelID);
	msg.set_m_activationitem((int32_t)m_activationItem);
	msg.set_m_activationnum((int32_t)m_activationNum);
	msg.set_m_starattributeid((int32_t)m_starAttributeId);
	msg.set_m_starmax((int32_t)m_starMax);
	msg.set_m_starid((int32_t)m_starId);
	msg.set_m_starnum(m_starNum.data());
	msg.set_m_starber((int32_t)m_starBer);
	msg.set_m_changeattributeid((int32_t)m_changeAttributeId);
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_MountHuakun_changeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountHuakun_change_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_change & msg) {
	m_id = msg.m_id();
	m_huaKunId = msg.m_huakunid();
	m_speed = msg.m_speed();
	m_fxID = msg.m_fxid();
	m_ModelID = msg.m_modelid();
	m_activationItem = msg.m_activationitem();
	m_activationNum = msg.m_activationnum();
	m_starAttributeId = msg.m_starattributeid();
	m_starMax = msg.m_starmax();
	m_starId = msg.m_starid();
	m_starNum = msg.m_starnum();
	m_starBer = msg.m_starber();
	m_changeAttributeId = msg.m_changeattributeid();
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_MountHuakun_changeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_MountHuakun_change_s::Sheet_MountHuakun_change_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountHuakun_change_s::CreateInit() {
	return 0;
}

int Sheet_MountHuakun_change_s::ResumeInit() {
	return 0;
}

void Sheet_MountHuakun_change_s::write_to_pbmsg(::proto_ff::Sheet_MountHuakun_change & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountHuakun_change_List.size(); ++i) {
		::proto_ff::E_MountHuakun_change* temp_e_mounthuakun_change_list = msg.add_e_mounthuakun_change_list();
		E_MountHuakun_change_List[i].write_to_pbmsg(*temp_e_mounthuakun_change_list);
	}
}

void Sheet_MountHuakun_change_s::read_from_pbmsg(const ::proto_ff::Sheet_MountHuakun_change & msg) {
	E_MountHuakun_change_List.resize((int)msg.e_mounthuakun_change_list_size() > (int)E_MountHuakun_change_List.max_size() ? E_MountHuakun_change_List.max_size() : msg.e_mounthuakun_change_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountHuakun_change_List.size(); ++i) {
		const ::proto_ff::E_MountHuakun_change & temp_e_mounthuakun_change_list = msg.e_mounthuakun_change_list(i);
		E_MountHuakun_change_List[i].read_from_pbmsg(temp_e_mounthuakun_change_list);
	}
}

E_MountHuakun_advanceUpattributeDesc_s::E_MountHuakun_advanceUpattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakun_advanceUpattributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MountHuakun_advanceUpattributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_advanceUpattributeDesc_s::write_to_pbmsg(::proto_ff::E_MountHuakun_advanceUpattributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MountHuakun_advanceUpattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_advanceUpattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MountHuakun_advance_s::E_MountHuakun_advance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakun_advance_s::CreateInit() {
	m_id = (int32_t)0;
	m_upAttributeId = (int32_t)0;
	m_starID = (int32_t)0;
	m_skillID = (int32_t)0;
	return 0;
}

int E_MountHuakun_advance_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_advance_s::write_to_pbmsg(::proto_ff::E_MountHuakun_advance & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_upattributeid((int32_t)m_upAttributeId);
	msg.set_m_starid((int32_t)m_starID);
	msg.set_m_skillid((int32_t)m_skillID);
	for(int32_t i = 0; i < (int32_t)m_upAttribute.size(); ++i) {
		::proto_ff::E_MountHuakun_advanceUpattributeDesc* temp_m_upattribute = msg.add_m_upattribute();
		m_upAttribute[i].write_to_pbmsg(*temp_m_upattribute);
	}
}

void E_MountHuakun_advance_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_advance & msg) {
	m_id = msg.m_id();
	m_upAttributeId = msg.m_upattributeid();
	m_starID = msg.m_starid();
	m_skillID = msg.m_skillid();
	m_upAttribute.resize((int)msg.m_upattribute_size() > (int)m_upAttribute.max_size() ? m_upAttribute.max_size() : msg.m_upattribute_size());
	for(int32_t i = 0; i < (int32_t)m_upAttribute.size(); ++i) {
		const ::proto_ff::E_MountHuakun_advanceUpattributeDesc & temp_m_upattribute = msg.m_upattribute(i);
		m_upAttribute[i].read_from_pbmsg(temp_m_upattribute);
	}
}

Sheet_MountHuakun_advance_s::Sheet_MountHuakun_advance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountHuakun_advance_s::CreateInit() {
	return 0;
}

int Sheet_MountHuakun_advance_s::ResumeInit() {
	return 0;
}

void Sheet_MountHuakun_advance_s::write_to_pbmsg(::proto_ff::Sheet_MountHuakun_advance & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountHuakun_advance_List.size(); ++i) {
		::proto_ff::E_MountHuakun_advance* temp_e_mounthuakun_advance_list = msg.add_e_mounthuakun_advance_list();
		E_MountHuakun_advance_List[i].write_to_pbmsg(*temp_e_mounthuakun_advance_list);
	}
}

void Sheet_MountHuakun_advance_s::read_from_pbmsg(const ::proto_ff::Sheet_MountHuakun_advance & msg) {
	E_MountHuakun_advance_List.resize((int)msg.e_mounthuakun_advance_list_size() > (int)E_MountHuakun_advance_List.max_size() ? E_MountHuakun_advance_List.max_size() : msg.e_mounthuakun_advance_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountHuakun_advance_List.size(); ++i) {
		const ::proto_ff::E_MountHuakun_advance & temp_e_mounthuakun_advance_list = msg.e_mounthuakun_advance_list(i);
		E_MountHuakun_advance_List[i].read_from_pbmsg(temp_e_mounthuakun_advance_list);
	}
}

E_MountBloodAttributeDesc_s::E_MountBloodAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountBloodAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MountBloodAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountBloodAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MountBloodAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MountBloodAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountBloodAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MountBlood_s::E_MountBlood_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountBlood_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_MountBlood_s::ResumeInit() {
	return 0;
}

void E_MountBlood_s::write_to_pbmsg(::proto_ff::E_MountBlood & msg) const {
	msg.set_m_id((int32_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MountBloodAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountBlood_s::read_from_pbmsg(const ::proto_ff::E_MountBlood & msg) {
	m_id = msg.m_id();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_MountBloodAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_MountBlood_s::Sheet_MountBlood_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountBlood_s::CreateInit() {
	return 0;
}

int Sheet_MountBlood_s::ResumeInit() {
	return 0;
}

void Sheet_MountBlood_s::write_to_pbmsg(::proto_ff::Sheet_MountBlood & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountBlood_List.size(); ++i) {
		::proto_ff::E_MountBlood* temp_e_mountblood_list = msg.add_e_mountblood_list();
		E_MountBlood_List[i].write_to_pbmsg(*temp_e_mountblood_list);
	}
}

void Sheet_MountBlood_s::read_from_pbmsg(const ::proto_ff::Sheet_MountBlood & msg) {
	E_MountBlood_List.resize((int)msg.e_mountblood_list_size() > (int)E_MountBlood_List.max_size() ? E_MountBlood_List.max_size() : msg.e_mountblood_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountBlood_List.size(); ++i) {
		const ::proto_ff::E_MountBlood & temp_e_mountblood_list = msg.e_mountblood_list(i);
		E_MountBlood_List[i].read_from_pbmsg(temp_e_mountblood_list);
	}
}

E_MountHuakun_equip_s::E_MountHuakun_equip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakun_equip_s::CreateInit() {
	m_equipId = (int32_t)0;
	m_part = (int32_t)0;
	m_quality = (int32_t)0;
	m_equipIntensify = (int32_t)0;
	m_srtongUp = (int32_t)0;
	m_advanceIntensify = (int32_t)0;
	m_equipTtop = (int32_t)0;
	m_resolve = (int32_t)0;
	m_resolveMun = (int32_t)0;
	return 0;
}

int E_MountHuakun_equip_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_equip_s::write_to_pbmsg(::proto_ff::E_MountHuakun_equip & msg) const {
	msg.set_m_equipid((int32_t)m_equipId);
	msg.set_m_part((int32_t)m_part);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_equipintensify((int32_t)m_equipIntensify);
	msg.set_m_srtongup((int32_t)m_srtongUp);
	msg.set_m_advanceintensify((int32_t)m_advanceIntensify);
	msg.set_m_equipttop((int32_t)m_equipTtop);
	msg.set_m_resolve((int32_t)m_resolve);
	msg.set_m_resolvemun((int32_t)m_resolveMun);
}

void E_MountHuakun_equip_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_equip & msg) {
	m_equipId = msg.m_equipid();
	m_part = msg.m_part();
	m_quality = msg.m_quality();
	m_equipIntensify = msg.m_equipintensify();
	m_srtongUp = msg.m_srtongup();
	m_advanceIntensify = msg.m_advanceintensify();
	m_equipTtop = msg.m_equipttop();
	m_resolve = msg.m_resolve();
	m_resolveMun = msg.m_resolvemun();
}

Sheet_MountHuakun_equip_s::Sheet_MountHuakun_equip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountHuakun_equip_s::CreateInit() {
	return 0;
}

int Sheet_MountHuakun_equip_s::ResumeInit() {
	return 0;
}

void Sheet_MountHuakun_equip_s::write_to_pbmsg(::proto_ff::Sheet_MountHuakun_equip & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountHuakun_equip_List.size(); ++i) {
		::proto_ff::E_MountHuakun_equip* temp_e_mounthuakun_equip_list = msg.add_e_mounthuakun_equip_list();
		E_MountHuakun_equip_List[i].write_to_pbmsg(*temp_e_mounthuakun_equip_list);
	}
}

void Sheet_MountHuakun_equip_s::read_from_pbmsg(const ::proto_ff::Sheet_MountHuakun_equip & msg) {
	E_MountHuakun_equip_List.resize((int)msg.e_mounthuakun_equip_list_size() > (int)E_MountHuakun_equip_List.max_size() ? E_MountHuakun_equip_List.max_size() : msg.e_mounthuakun_equip_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountHuakun_equip_List.size(); ++i) {
		const ::proto_ff::E_MountHuakun_equip & temp_e_mounthuakun_equip_list = msg.e_mounthuakun_equip_list(i);
		E_MountHuakun_equip_List[i].read_from_pbmsg(temp_e_mounthuakun_equip_list);
	}
}

E_MountEquip_valueAttributeDesc_s::E_MountEquip_valueAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountEquip_valueAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MountEquip_valueAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountEquip_valueAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MountEquip_valueAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MountEquip_valueAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountEquip_valueAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MountEquip_value_s::E_MountEquip_value_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountEquip_value_s::CreateInit() {
	m_equipIntensify = (int32_t)0;
	m_equipValue = (int32_t)0;
	m_equipLv = (int32_t)0;
	m_equipItem = (int32_t)0;
	m_equipMun = (int32_t)0;
	return 0;
}

int E_MountEquip_value_s::ResumeInit() {
	return 0;
}

void E_MountEquip_value_s::write_to_pbmsg(::proto_ff::E_MountEquip_value & msg) const {
	msg.set_m_equipintensify((int32_t)m_equipIntensify);
	msg.set_m_equipvalue((int32_t)m_equipValue);
	msg.set_m_equiplv((int32_t)m_equipLv);
	msg.set_m_equipitem((int32_t)m_equipItem);
	msg.set_m_equipmun((int32_t)m_equipMun);
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_MountEquip_valueAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountEquip_value_s::read_from_pbmsg(const ::proto_ff::E_MountEquip_value & msg) {
	m_equipIntensify = msg.m_equipintensify();
	m_equipValue = msg.m_equipvalue();
	m_equipLv = msg.m_equiplv();
	m_equipItem = msg.m_equipitem();
	m_equipMun = msg.m_equipmun();
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_MountEquip_valueAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_MountEquip_value_s::Sheet_MountEquip_value_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountEquip_value_s::CreateInit() {
	return 0;
}

int Sheet_MountEquip_value_s::ResumeInit() {
	return 0;
}

void Sheet_MountEquip_value_s::write_to_pbmsg(::proto_ff::Sheet_MountEquip_value & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountEquip_value_List.size(); ++i) {
		::proto_ff::E_MountEquip_value* temp_e_mountequip_value_list = msg.add_e_mountequip_value_list();
		E_MountEquip_value_List[i].write_to_pbmsg(*temp_e_mountequip_value_list);
	}
}

void Sheet_MountEquip_value_s::read_from_pbmsg(const ::proto_ff::Sheet_MountEquip_value & msg) {
	E_MountEquip_value_List.resize((int)msg.e_mountequip_value_list_size() > (int)E_MountEquip_value_List.max_size() ? E_MountEquip_value_List.max_size() : msg.e_mountequip_value_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountEquip_value_List.size(); ++i) {
		const ::proto_ff::E_MountEquip_value & temp_e_mountequip_value_list = msg.e_mountequip_value_list(i);
		E_MountEquip_value_List[i].read_from_pbmsg(temp_e_mountequip_value_list);
	}
}

E_MountEquipsuitAttributeDesc_s::E_MountEquipsuitAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountEquipsuitAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MountEquipsuitAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountEquipsuitAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MountEquipsuitAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MountEquipsuitAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountEquipsuitAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MountEquipsuit_s::E_MountEquipsuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountEquipsuit_s::CreateInit() {
	m_id = (int32_t)0;
	m_quality = (int32_t)0;
	m_piece = (int32_t)0;
	return 0;
}

int E_MountEquipsuit_s::ResumeInit() {
	return 0;
}

void E_MountEquipsuit_s::write_to_pbmsg(::proto_ff::E_MountEquipsuit & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_piece((int32_t)m_piece);
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		::proto_ff::E_MountEquipsuitAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_Attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountEquipsuit_s::read_from_pbmsg(const ::proto_ff::E_MountEquipsuit & msg) {
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_piece = msg.m_piece();
	m_Attribute.resize((int)msg.m_attribute_size() > (int)m_Attribute.max_size() ? m_Attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_Attribute.size(); ++i) {
		const ::proto_ff::E_MountEquipsuitAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_Attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_MountEquipsuit_s::Sheet_MountEquipsuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountEquipsuit_s::CreateInit() {
	return 0;
}

int Sheet_MountEquipsuit_s::ResumeInit() {
	return 0;
}

void Sheet_MountEquipsuit_s::write_to_pbmsg(::proto_ff::Sheet_MountEquipsuit & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountEquipsuit_List.size(); ++i) {
		::proto_ff::E_MountEquipsuit* temp_e_mountequipsuit_list = msg.add_e_mountequipsuit_list();
		E_MountEquipsuit_List[i].write_to_pbmsg(*temp_e_mountequipsuit_list);
	}
}

void Sheet_MountEquipsuit_s::read_from_pbmsg(const ::proto_ff::Sheet_MountEquipsuit & msg) {
	E_MountEquipsuit_List.resize((int)msg.e_mountequipsuit_list_size() > (int)E_MountEquipsuit_List.max_size() ? E_MountEquipsuit_List.max_size() : msg.e_mountequipsuit_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountEquipsuit_List.size(); ++i) {
		const ::proto_ff::E_MountEquipsuit & temp_e_mountequipsuit_list = msg.e_mountequipsuit_list(i);
		E_MountEquipsuit_List[i].read_from_pbmsg(temp_e_mountequipsuit_list);
	}
}

E_MountEquiptopTopDesc_s::E_MountEquiptopTopDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountEquiptopTopDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MountEquiptopTopDesc_s::ResumeInit() {
	return 0;
}

void E_MountEquiptopTopDesc_s::write_to_pbmsg(::proto_ff::E_MountEquiptopTopDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MountEquiptopTopDesc_s::read_from_pbmsg(const ::proto_ff::E_MountEquiptopTopDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MountEquiptopPercentDesc_s::E_MountEquiptopPercentDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountEquiptopPercentDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MountEquiptopPercentDesc_s::ResumeInit() {
	return 0;
}

void E_MountEquiptopPercentDesc_s::write_to_pbmsg(::proto_ff::E_MountEquiptopPercentDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MountEquiptopPercentDesc_s::read_from_pbmsg(const ::proto_ff::E_MountEquiptopPercentDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MountEquiptop_s::E_MountEquiptop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountEquiptop_s::CreateInit() {
	m_id = (int32_t)0;
	m_positionId = (int32_t)0;
	m_equipTtop = (int32_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_MountEquiptop_s::ResumeInit() {
	return 0;
}

void E_MountEquiptop_s::write_to_pbmsg(::proto_ff::E_MountEquiptop & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_positionid((int32_t)m_positionId);
	msg.set_m_equipttop((int32_t)m_equipTtop);
	msg.set_m_quality((int32_t)m_quality);
	for(int32_t i = 0; i < (int32_t)m_top.size(); ++i) {
		::proto_ff::E_MountEquiptopTopDesc* temp_m_top = msg.add_m_top();
		m_top[i].write_to_pbmsg(*temp_m_top);
	}
	for(int32_t i = 0; i < (int32_t)m_percent.size(); ++i) {
		::proto_ff::E_MountEquiptopPercentDesc* temp_m_percent = msg.add_m_percent();
		m_percent[i].write_to_pbmsg(*temp_m_percent);
	}
}

void E_MountEquiptop_s::read_from_pbmsg(const ::proto_ff::E_MountEquiptop & msg) {
	m_id = msg.m_id();
	m_positionId = msg.m_positionid();
	m_equipTtop = msg.m_equipttop();
	m_quality = msg.m_quality();
	m_top.resize((int)msg.m_top_size() > (int)m_top.max_size() ? m_top.max_size() : msg.m_top_size());
	for(int32_t i = 0; i < (int32_t)m_top.size(); ++i) {
		const ::proto_ff::E_MountEquiptopTopDesc & temp_m_top = msg.m_top(i);
		m_top[i].read_from_pbmsg(temp_m_top);
	}
	m_percent.resize((int)msg.m_percent_size() > (int)m_percent.max_size() ? m_percent.max_size() : msg.m_percent_size());
	for(int32_t i = 0; i < (int32_t)m_percent.size(); ++i) {
		const ::proto_ff::E_MountEquiptopPercentDesc & temp_m_percent = msg.m_percent(i);
		m_percent[i].read_from_pbmsg(temp_m_percent);
	}
}

Sheet_MountEquiptop_s::Sheet_MountEquiptop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountEquiptop_s::CreateInit() {
	return 0;
}

int Sheet_MountEquiptop_s::ResumeInit() {
	return 0;
}

void Sheet_MountEquiptop_s::write_to_pbmsg(::proto_ff::Sheet_MountEquiptop & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountEquiptop_List.size(); ++i) {
		::proto_ff::E_MountEquiptop* temp_e_mountequiptop_list = msg.add_e_mountequiptop_list();
		E_MountEquiptop_List[i].write_to_pbmsg(*temp_e_mountequiptop_list);
	}
}

void Sheet_MountEquiptop_s::read_from_pbmsg(const ::proto_ff::Sheet_MountEquiptop & msg) {
	E_MountEquiptop_List.resize((int)msg.e_mountequiptop_list_size() > (int)E_MountEquiptop_List.max_size() ? E_MountEquiptop_List.max_size() : msg.e_mountequiptop_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountEquiptop_List.size(); ++i) {
		const ::proto_ff::E_MountEquiptop & temp_e_mountequiptop_list = msg.e_mountequiptop_list(i);
		E_MountEquiptop_List[i].read_from_pbmsg(temp_e_mountequiptop_list);
	}
}

E_MountEquiptopvalue_s::E_MountEquiptopvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountEquiptopvalue_s::CreateInit() {
	m_id = (int32_t)0;
	m_quality = (int32_t)0;
	m_top = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_MountEquiptopvalue_s::ResumeInit() {
	return 0;
}

void E_MountEquiptopvalue_s::write_to_pbmsg(::proto_ff::E_MountEquiptopvalue & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_top((int32_t)m_top);
	msg.set_m_value((int32_t)m_value);
}

void E_MountEquiptopvalue_s::read_from_pbmsg(const ::proto_ff::E_MountEquiptopvalue & msg) {
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_top = msg.m_top();
	m_value = msg.m_value();
}

Sheet_MountEquiptopvalue_s::Sheet_MountEquiptopvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountEquiptopvalue_s::CreateInit() {
	return 0;
}

int Sheet_MountEquiptopvalue_s::ResumeInit() {
	return 0;
}

void Sheet_MountEquiptopvalue_s::write_to_pbmsg(::proto_ff::Sheet_MountEquiptopvalue & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountEquiptopvalue_List.size(); ++i) {
		::proto_ff::E_MountEquiptopvalue* temp_e_mountequiptopvalue_list = msg.add_e_mountequiptopvalue_list();
		E_MountEquiptopvalue_List[i].write_to_pbmsg(*temp_e_mountequiptopvalue_list);
	}
}

void Sheet_MountEquiptopvalue_s::read_from_pbmsg(const ::proto_ff::Sheet_MountEquiptopvalue & msg) {
	E_MountEquiptopvalue_List.resize((int)msg.e_mountequiptopvalue_list_size() > (int)E_MountEquiptopvalue_List.max_size() ? E_MountEquiptopvalue_List.max_size() : msg.e_mountequiptopvalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountEquiptopvalue_List.size(); ++i) {
		const ::proto_ff::E_MountEquiptopvalue & temp_e_mountequiptopvalue_list = msg.e_mountequiptopvalue_list(i);
		E_MountEquiptopvalue_List[i].read_from_pbmsg(temp_e_mountequiptopvalue_list);
	}
}

E_MountEquippart_s::E_MountEquippart_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountEquippart_s::CreateInit() {
	m_part = (int32_t)0;
	m_quality = (int32_t)0;
	m_honeOpen = (int32_t)0;
	m_item = (int32_t)0;
	m_num = (int32_t)0;
	m_itemTips = (int32_t)0;
	return 0;
}

int E_MountEquippart_s::ResumeInit() {
	return 0;
}

void E_MountEquippart_s::write_to_pbmsg(::proto_ff::E_MountEquippart & msg) const {
	msg.set_m_part((int32_t)m_part);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_honeopen((int32_t)m_honeOpen);
	msg.set_m_item((int32_t)m_item);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_itemtips((int32_t)m_itemTips);
}

void E_MountEquippart_s::read_from_pbmsg(const ::proto_ff::E_MountEquippart & msg) {
	m_part = msg.m_part();
	m_quality = msg.m_quality();
	m_honeOpen = msg.m_honeopen();
	m_item = msg.m_item();
	m_num = msg.m_num();
	m_itemTips = msg.m_itemtips();
}

Sheet_MountEquippart_s::Sheet_MountEquippart_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountEquippart_s::CreateInit() {
	return 0;
}

int Sheet_MountEquippart_s::ResumeInit() {
	return 0;
}

void Sheet_MountEquippart_s::write_to_pbmsg(::proto_ff::Sheet_MountEquippart & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountEquippart_List.size(); ++i) {
		::proto_ff::E_MountEquippart* temp_e_mountequippart_list = msg.add_e_mountequippart_list();
		E_MountEquippart_List[i].write_to_pbmsg(*temp_e_mountequippart_list);
	}
}

void Sheet_MountEquippart_s::read_from_pbmsg(const ::proto_ff::Sheet_MountEquippart & msg) {
	E_MountEquippart_List.resize((int)msg.e_mountequippart_list_size() > (int)E_MountEquippart_List.max_size() ? E_MountEquippart_List.max_size() : msg.e_mountequippart_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountEquippart_List.size(); ++i) {
		const ::proto_ff::E_MountEquippart & temp_e_mountequippart_list = msg.e_mountequippart_list(i);
		E_MountEquippart_List[i].read_from_pbmsg(temp_e_mountequippart_list);
	}
}

E_MountEmpowermenttour_debris_s::E_MountEmpowermenttour_debris_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountEmpowermenttour_debris_s::CreateInit() {
	m_fairylandId = (int32_t)0;
	m_fairylandNextId = (int32_t)0;
	return 0;
}

int E_MountEmpowermenttour_debris_s::ResumeInit() {
	return 0;
}

void E_MountEmpowermenttour_debris_s::write_to_pbmsg(::proto_ff::E_MountEmpowermenttour_debris & msg) const {
	msg.set_m_fairylandid((int32_t)m_fairylandId);
	msg.set_m_fairylandnextid((int32_t)m_fairylandNextId);
	msg.set_m_fairylandskin(m_fairylandSkin.data());
}

void E_MountEmpowermenttour_debris_s::read_from_pbmsg(const ::proto_ff::E_MountEmpowermenttour_debris & msg) {
	m_fairylandId = msg.m_fairylandid();
	m_fairylandNextId = msg.m_fairylandnextid();
	m_fairylandSkin = msg.m_fairylandskin();
}

Sheet_MountEmpowermenttour_debris_s::Sheet_MountEmpowermenttour_debris_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountEmpowermenttour_debris_s::CreateInit() {
	return 0;
}

int Sheet_MountEmpowermenttour_debris_s::ResumeInit() {
	return 0;
}

void Sheet_MountEmpowermenttour_debris_s::write_to_pbmsg(::proto_ff::Sheet_MountEmpowermenttour_debris & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountEmpowermenttour_debris_List.size(); ++i) {
		::proto_ff::E_MountEmpowermenttour_debris* temp_e_mountempowermenttour_debris_list = msg.add_e_mountempowermenttour_debris_list();
		E_MountEmpowermenttour_debris_List[i].write_to_pbmsg(*temp_e_mountempowermenttour_debris_list);
	}
}

void Sheet_MountEmpowermenttour_debris_s::read_from_pbmsg(const ::proto_ff::Sheet_MountEmpowermenttour_debris & msg) {
	E_MountEmpowermenttour_debris_List.resize((int)msg.e_mountempowermenttour_debris_list_size() > (int)E_MountEmpowermenttour_debris_List.max_size() ? E_MountEmpowermenttour_debris_List.max_size() : msg.e_mountempowermenttour_debris_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountEmpowermenttour_debris_List.size(); ++i) {
		const ::proto_ff::E_MountEmpowermenttour_debris & temp_e_mountempowermenttour_debris_list = msg.e_mountempowermenttour_debris_list(i);
		E_MountEmpowermenttour_debris_List[i].read_from_pbmsg(temp_e_mountempowermenttour_debris_list);
	}
}

E_MountEmpowermentTourDesc_s::E_MountEmpowermentTourDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountEmpowermentTourDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MountEmpowermentTourDesc_s::ResumeInit() {
	return 0;
}

void E_MountEmpowermentTourDesc_s::write_to_pbmsg(::proto_ff::E_MountEmpowermentTourDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MountEmpowermentTourDesc_s::read_from_pbmsg(const ::proto_ff::E_MountEmpowermentTourDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MountEmpowerment_s::E_MountEmpowerment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountEmpowerment_s::CreateInit() {
	m_tourId = (int32_t)0;
	m_fairylandId = (int32_t)0;
	m_tourItem = (int32_t)0;
	m_tourDebris = (int32_t)0;
	return 0;
}

int E_MountEmpowerment_s::ResumeInit() {
	return 0;
}

void E_MountEmpowerment_s::write_to_pbmsg(::proto_ff::E_MountEmpowerment & msg) const {
	msg.set_m_tourid((int32_t)m_tourId);
	msg.set_m_fairylandid((int32_t)m_fairylandId);
	msg.set_m_touritem((int32_t)m_tourItem);
	msg.set_m_tourdebris((int32_t)m_tourDebris);
	for(int32_t i = 0; i < (int32_t)m_tour.size(); ++i) {
		::proto_ff::E_MountEmpowermentTourDesc* temp_m_tour = msg.add_m_tour();
		m_tour[i].write_to_pbmsg(*temp_m_tour);
	}
}

void E_MountEmpowerment_s::read_from_pbmsg(const ::proto_ff::E_MountEmpowerment & msg) {
	m_tourId = msg.m_tourid();
	m_fairylandId = msg.m_fairylandid();
	m_tourItem = msg.m_touritem();
	m_tourDebris = msg.m_tourdebris();
	m_tour.resize((int)msg.m_tour_size() > (int)m_tour.max_size() ? m_tour.max_size() : msg.m_tour_size());
	for(int32_t i = 0; i < (int32_t)m_tour.size(); ++i) {
		const ::proto_ff::E_MountEmpowermentTourDesc & temp_m_tour = msg.m_tour(i);
		m_tour[i].read_from_pbmsg(temp_m_tour);
	}
}

Sheet_MountEmpowerment_s::Sheet_MountEmpowerment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountEmpowerment_s::CreateInit() {
	return 0;
}

int Sheet_MountEmpowerment_s::ResumeInit() {
	return 0;
}

void Sheet_MountEmpowerment_s::write_to_pbmsg(::proto_ff::Sheet_MountEmpowerment & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountEmpowerment_List.size(); ++i) {
		::proto_ff::E_MountEmpowerment* temp_e_mountempowerment_list = msg.add_e_mountempowerment_list();
		E_MountEmpowerment_List[i].write_to_pbmsg(*temp_e_mountempowerment_list);
	}
}

void Sheet_MountEmpowerment_s::read_from_pbmsg(const ::proto_ff::Sheet_MountEmpowerment & msg) {
	E_MountEmpowerment_List.resize((int)msg.e_mountempowerment_list_size() > (int)E_MountEmpowerment_List.max_size() ? E_MountEmpowerment_List.max_size() : msg.e_mountempowerment_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountEmpowerment_List.size(); ++i) {
		const ::proto_ff::E_MountEmpowerment & temp_e_mountempowerment_list = msg.e_mountempowerment_list(i);
		E_MountEmpowerment_List[i].read_from_pbmsg(temp_e_mountempowerment_list);
	}
}

E_MountEmpowerment_position_s::E_MountEmpowerment_position_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountEmpowerment_position_s::CreateInit() {
	m_empowermentSlot = (int32_t)0;
	m_unlockTime = (int32_t)0;
	m_unlockNum = (int32_t)0;
	return 0;
}

int E_MountEmpowerment_position_s::ResumeInit() {
	return 0;
}

void E_MountEmpowerment_position_s::write_to_pbmsg(::proto_ff::E_MountEmpowerment_position & msg) const {
	msg.set_m_empowermentslot((int32_t)m_empowermentSlot);
	msg.set_m_unlocktime((int32_t)m_unlockTime);
	msg.set_m_unlocknum((int32_t)m_unlockNum);
}

void E_MountEmpowerment_position_s::read_from_pbmsg(const ::proto_ff::E_MountEmpowerment_position & msg) {
	m_empowermentSlot = msg.m_empowermentslot();
	m_unlockTime = msg.m_unlocktime();
	m_unlockNum = msg.m_unlocknum();
}

Sheet_MountEmpowerment_position_s::Sheet_MountEmpowerment_position_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountEmpowerment_position_s::CreateInit() {
	return 0;
}

int Sheet_MountEmpowerment_position_s::ResumeInit() {
	return 0;
}

void Sheet_MountEmpowerment_position_s::write_to_pbmsg(::proto_ff::Sheet_MountEmpowerment_position & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountEmpowerment_position_List.size(); ++i) {
		::proto_ff::E_MountEmpowerment_position* temp_e_mountempowerment_position_list = msg.add_e_mountempowerment_position_list();
		E_MountEmpowerment_position_List[i].write_to_pbmsg(*temp_e_mountempowerment_position_list);
	}
}

void Sheet_MountEmpowerment_position_s::read_from_pbmsg(const ::proto_ff::Sheet_MountEmpowerment_position & msg) {
	E_MountEmpowerment_position_List.resize((int)msg.e_mountempowerment_position_list_size() > (int)E_MountEmpowerment_position_List.max_size() ? E_MountEmpowerment_position_List.max_size() : msg.e_mountempowerment_position_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountEmpowerment_position_List.size(); ++i) {
		const ::proto_ff::E_MountEmpowerment_position & temp_e_mountempowerment_position_list = msg.e_mountempowerment_position_list(i);
		E_MountEmpowerment_position_List[i].read_from_pbmsg(temp_e_mountempowerment_position_list);
	}
}

E_MountEmpowerment_slot_s::E_MountEmpowerment_slot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountEmpowerment_slot_s::CreateInit() {
	m_id = (int32_t)0;
	m_dissociateLevel = (int32_t)0;
	m_dissociateTime = (int32_t)0;
	m_dissociateHour = (int32_t)0;
	m_dissociateItem = (int32_t)0;
	m_dissociateNum = (int32_t)0;
	m_dissociateBox = (int32_t)0;
	return 0;
}

int E_MountEmpowerment_slot_s::ResumeInit() {
	return 0;
}

void E_MountEmpowerment_slot_s::write_to_pbmsg(::proto_ff::E_MountEmpowerment_slot & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_dissociatelevel((int32_t)m_dissociateLevel);
	msg.set_m_dissociatetime((int32_t)m_dissociateTime);
	msg.set_m_dissociatehour((int32_t)m_dissociateHour);
	msg.set_m_dissociateitem((int32_t)m_dissociateItem);
	msg.set_m_dissociatenum((int32_t)m_dissociateNum);
	msg.set_m_eventtime(m_eventTime.data());
	msg.set_m_dissociatebox((int32_t)m_dissociateBox);
}

void E_MountEmpowerment_slot_s::read_from_pbmsg(const ::proto_ff::E_MountEmpowerment_slot & msg) {
	m_id = msg.m_id();
	m_dissociateLevel = msg.m_dissociatelevel();
	m_dissociateTime = msg.m_dissociatetime();
	m_dissociateHour = msg.m_dissociatehour();
	m_dissociateItem = msg.m_dissociateitem();
	m_dissociateNum = msg.m_dissociatenum();
	m_eventTime = msg.m_eventtime();
	m_dissociateBox = msg.m_dissociatebox();
}

Sheet_MountEmpowerment_slot_s::Sheet_MountEmpowerment_slot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountEmpowerment_slot_s::CreateInit() {
	return 0;
}

int Sheet_MountEmpowerment_slot_s::ResumeInit() {
	return 0;
}

void Sheet_MountEmpowerment_slot_s::write_to_pbmsg(::proto_ff::Sheet_MountEmpowerment_slot & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountEmpowerment_slot_List.size(); ++i) {
		::proto_ff::E_MountEmpowerment_slot* temp_e_mountempowerment_slot_list = msg.add_e_mountempowerment_slot_list();
		E_MountEmpowerment_slot_List[i].write_to_pbmsg(*temp_e_mountempowerment_slot_list);
	}
}

void Sheet_MountEmpowerment_slot_s::read_from_pbmsg(const ::proto_ff::Sheet_MountEmpowerment_slot & msg) {
	E_MountEmpowerment_slot_List.resize((int)msg.e_mountempowerment_slot_list_size() > (int)E_MountEmpowerment_slot_List.max_size() ? E_MountEmpowerment_slot_List.max_size() : msg.e_mountempowerment_slot_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountEmpowerment_slot_List.size(); ++i) {
		const ::proto_ff::E_MountEmpowerment_slot & temp_e_mountempowerment_slot_list = msg.e_mountempowerment_slot_list(i);
		E_MountEmpowerment_slot_List[i].read_from_pbmsg(temp_e_mountempowerment_slot_list);
	}
}

E_MountEmpowerment_event_s::E_MountEmpowerment_event_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountEmpowerment_event_s::CreateInit() {
	m_id = (int32_t)0;
	m_eventType = (int32_t)0;
	m_weight = (int32_t)0;
	return 0;
}

int E_MountEmpowerment_event_s::ResumeInit() {
	return 0;
}

void E_MountEmpowerment_event_s::write_to_pbmsg(::proto_ff::E_MountEmpowerment_event & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_eventtype((int32_t)m_eventType);
	msg.set_m_weight((int32_t)m_weight);
}

void E_MountEmpowerment_event_s::read_from_pbmsg(const ::proto_ff::E_MountEmpowerment_event & msg) {
	m_id = msg.m_id();
	m_eventType = msg.m_eventtype();
	m_weight = msg.m_weight();
}

Sheet_MountEmpowerment_event_s::Sheet_MountEmpowerment_event_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MountEmpowerment_event_s::CreateInit() {
	return 0;
}

int Sheet_MountEmpowerment_event_s::ResumeInit() {
	return 0;
}

void Sheet_MountEmpowerment_event_s::write_to_pbmsg(::proto_ff::Sheet_MountEmpowerment_event & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MountEmpowerment_event_List.size(); ++i) {
		::proto_ff::E_MountEmpowerment_event* temp_e_mountempowerment_event_list = msg.add_e_mountempowerment_event_list();
		E_MountEmpowerment_event_List[i].write_to_pbmsg(*temp_e_mountempowerment_event_list);
	}
}

void Sheet_MountEmpowerment_event_s::read_from_pbmsg(const ::proto_ff::Sheet_MountEmpowerment_event & msg) {
	E_MountEmpowerment_event_List.resize((int)msg.e_mountempowerment_event_list_size() > (int)E_MountEmpowerment_event_List.max_size() ? E_MountEmpowerment_event_List.max_size() : msg.e_mountempowerment_event_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountEmpowerment_event_List.size(); ++i) {
		const ::proto_ff::E_MountEmpowerment_event & temp_e_mountempowerment_event_list = msg.e_mountempowerment_event_list(i);
		E_MountEmpowerment_event_List[i].read_from_pbmsg(temp_e_mountempowerment_event_list);
	}
}

}
