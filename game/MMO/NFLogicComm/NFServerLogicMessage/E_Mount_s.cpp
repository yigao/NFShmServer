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
	m_fragmentid = (int64_t)0;
	m_item = (int64_t)0;
	m_itemnum = (int32_t)0;
	return 0;
}

int E_MountFragment_s::ResumeInit() {
	return 0;
}

void E_MountFragment_s::write_to_pbmsg(::proto_ff::E_MountFragment & msg) const {
	msg.set_m_fragmentid((int64_t)m_fragmentid);
	msg.set_m_item((int64_t)m_item);
	msg.set_m_itemnum((int32_t)m_itemnum);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MountFragmentAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountFragment_s::read_from_pbmsg(const ::proto_ff::E_MountFragment & msg) {
	m_fragmentid = msg.m_fragmentid();
	m_item = msg.m_item();
	m_itemnum = msg.m_itemnum();
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
	m_exp = (int32_t)0;
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
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_speed((int32_t)m_speed);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MountValueAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountValue_s::read_from_pbmsg(const ::proto_ff::E_MountValue & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
	m_speed = msg.m_speed();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_MountValueAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
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
	m_uplvtype = (int32_t)0;
	m_starup = (int32_t)0;
	m_lvmax = (int32_t)0;
	return 0;
}

int E_MountDisplay_s::ResumeInit() {
	return 0;
}

void E_MountDisplay_s::write_to_pbmsg(::proto_ff::E_MountDisplay & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_speed((int32_t)m_speed);
	msg.set_m_uplvtype((int32_t)m_uplvtype);
	msg.set_m_skillid(m_skillid.data());
	msg.set_m_fxid(m_fxid.data());
	msg.set_m_starup((int32_t)m_starup);
	msg.set_m_lvmax((int32_t)m_lvmax);
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_MountDisplayMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_fragmentid.size(); ++i) {
		msg.add_m_fragmentid((int64_t)m_fragmentid[i]);
	}
}

void E_MountDisplay_s::read_from_pbmsg(const ::proto_ff::E_MountDisplay & msg) {
	m_id = msg.m_id();
	m_speed = msg.m_speed();
	m_uplvtype = msg.m_uplvtype();
	m_skillid = msg.m_skillid();
	m_fxid = msg.m_fxid();
	m_starup = msg.m_starup();
	m_lvmax = msg.m_lvmax();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_MountDisplayMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_fragmentid.resize((int)msg.m_fragmentid_size() > (int)m_fragmentid.max_size() ? m_fragmentid.max_size() : msg.m_fragmentid_size());
	for(int32_t i = 0; i < (int32_t)m_fragmentid.size(); ++i) {
		m_fragmentid[i] = msg.m_fragmentid(i);
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
	m_lv = (int32_t)0;
	m_modelid = (int32_t)0;
	return 0;
}

int E_MountUnlock_s::ResumeInit() {
	return 0;
}

void E_MountUnlock_s::write_to_pbmsg(::proto_ff::E_MountUnlock & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_modelid((int32_t)m_modelid);
	msg.set_m_name(m_name.data());
}

void E_MountUnlock_s::read_from_pbmsg(const ::proto_ff::E_MountUnlock & msg) {
	m_id = msg.m_id();
	m_lv = msg.m_lv();
	m_modelid = msg.m_modelid();
	m_name = msg.m_name();
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
	m_upvalue = (int32_t)0;
	m_upber = (int32_t)0;
	return 0;
}

int E_MountChangeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountChangeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MountChangeAttributeDesc & msg) const {
	msg.set_m_upvalue((int32_t)m_upvalue);
	msg.set_m_upber((int32_t)m_upber);
}

void E_MountChangeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountChangeAttributeDesc & msg) {
	m_upvalue = msg.m_upvalue();
	m_upber = msg.m_upber();
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
	m_uplvtype = (int32_t)0;
	m_activeskill = (int32_t)0;
	m_starmax = (int32_t)0;
	m_lvmax = (int32_t)0;
	m_modelid = (int32_t)0;
	m_activationitem = (int32_t)0;
	m_activationnum = (int32_t)0;
	m_starid = (int32_t)0;
	m_starber = (int32_t)0;
	m_upattributeid = (int32_t)0;
	return 0;
}

int E_MountChange_s::ResumeInit() {
	return 0;
}

void E_MountChange_s::write_to_pbmsg(::proto_ff::E_MountChange & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_advancename(m_advancename.data());
	msg.set_m_speed((int32_t)m_speed);
	msg.set_m_uplvtype((int32_t)m_uplvtype);
	msg.set_m_activeskill((int32_t)m_activeskill);
	msg.set_m_skillid(m_skillid.data());
	msg.set_m_fxid(m_fxid.data());
	msg.set_m_starmax((int32_t)m_starmax);
	msg.set_m_lvmax((int32_t)m_lvmax);
	msg.set_m_modelid((int32_t)m_modelid);
	msg.set_m_activationitem((int32_t)m_activationitem);
	msg.set_m_activationnum((int32_t)m_activationnum);
	msg.set_m_starid((int32_t)m_starid);
	msg.set_m_starnum(m_starnum.data());
	msg.set_m_starber((int32_t)m_starber);
	msg.set_m_upattributeid((int32_t)m_upattributeid);
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_MountChangeMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MountChangeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountChange_s::read_from_pbmsg(const ::proto_ff::E_MountChange & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_advancename = msg.m_advancename();
	m_speed = msg.m_speed();
	m_uplvtype = msg.m_uplvtype();
	m_activeskill = msg.m_activeskill();
	m_skillid = msg.m_skillid();
	m_fxid = msg.m_fxid();
	m_starmax = msg.m_starmax();
	m_lvmax = msg.m_lvmax();
	m_modelid = msg.m_modelid();
	m_activationitem = msg.m_activationitem();
	m_activationnum = msg.m_activationnum();
	m_starid = msg.m_starid();
	m_starnum = msg.m_starnum();
	m_starber = msg.m_starber();
	m_upattributeid = msg.m_upattributeid();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_MountChangeMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_MountChangeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
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
	m_upattributeid = (int32_t)0;
	m_starid = (int32_t)0;
	m_skillid = (int32_t)0;
	return 0;
}

int E_MountAdvance_s::ResumeInit() {
	return 0;
}

void E_MountAdvance_s::write_to_pbmsg(::proto_ff::E_MountAdvance & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_upattributeid((int32_t)m_upattributeid);
	msg.set_m_starid((int32_t)m_starid);
	msg.set_m_skillid((int32_t)m_skillid);
	for(int32_t i = 0; i < (int32_t)m_upattribute.size(); ++i) {
		::proto_ff::E_MountAdvanceUpattributeDesc* temp_m_upattribute = msg.add_m_upattribute();
		m_upattribute[i].write_to_pbmsg(*temp_m_upattribute);
	}
}

void E_MountAdvance_s::read_from_pbmsg(const ::proto_ff::E_MountAdvance & msg) {
	m_id = msg.m_id();
	m_upattributeid = msg.m_upattributeid();
	m_starid = msg.m_starid();
	m_skillid = msg.m_skillid();
	m_upattribute.resize((int)msg.m_upattribute_size() > (int)m_upattribute.max_size() ? m_upattribute.max_size() : msg.m_upattribute_size());
	for(int32_t i = 0; i < (int32_t)m_upattribute.size(); ++i) {
		const ::proto_ff::E_MountAdvanceUpattributeDesc & temp_m_upattribute = msg.m_upattribute(i);
		m_upattribute[i].read_from_pbmsg(temp_m_upattribute);
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
	m_itembox = (int32_t)0;
	return 0;
}

int E_MountBaby_egg_s::ResumeInit() {
	return 0;
}

void E_MountBaby_egg_s::write_to_pbmsg(::proto_ff::E_MountBaby_egg & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_item((int32_t)m_item);
	msg.set_m_time((int32_t)m_time);
	msg.set_m_itembox((int32_t)m_itembox);
}

void E_MountBaby_egg_s::read_from_pbmsg(const ::proto_ff::E_MountBaby_egg & msg) {
	m_id = msg.m_id();
	m_item = msg.m_item();
	m_time = msg.m_time();
	m_itembox = msg.m_itembox();
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
	m_upvalue = (int32_t)0;
	m_upber = (int32_t)0;
	return 0;
}

int E_MountHuakunUplvDesc_s::ResumeInit() {
	return 0;
}

void E_MountHuakunUplvDesc_s::write_to_pbmsg(::proto_ff::E_MountHuakunUplvDesc & msg) const {
	msg.set_m_upvalue((int32_t)m_upvalue);
	msg.set_m_upber((int32_t)m_upber);
}

void E_MountHuakunUplvDesc_s::read_from_pbmsg(const ::proto_ff::E_MountHuakunUplvDesc & msg) {
	m_upvalue = msg.m_upvalue();
	m_upber = msg.m_upber();
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
	m_upvalue = (int32_t)0;
	m_upber = (int32_t)0;
	return 0;
}

int E_MountHuakunAdvanceDesc_s::ResumeInit() {
	return 0;
}

void E_MountHuakunAdvanceDesc_s::write_to_pbmsg(::proto_ff::E_MountHuakunAdvanceDesc & msg) const {
	msg.set_m_upvalue((int32_t)m_upvalue);
	msg.set_m_upber((int32_t)m_upber);
}

void E_MountHuakunAdvanceDesc_s::read_from_pbmsg(const ::proto_ff::E_MountHuakunAdvanceDesc & msg) {
	m_upvalue = msg.m_upvalue();
	m_upber = msg.m_upber();
}

E_MountHuakunAttributeDesc_s::E_MountHuakunAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakunAttributeDesc_s::CreateInit() {
	m_upvalue = (int32_t)0;
	m_upber = (int32_t)0;
	return 0;
}

int E_MountHuakunAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountHuakunAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MountHuakunAttributeDesc & msg) const {
	msg.set_m_upvalue((int32_t)m_upvalue);
	msg.set_m_upber((int32_t)m_upber);
}

void E_MountHuakunAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountHuakunAttributeDesc & msg) {
	m_upvalue = msg.m_upvalue();
	m_upber = msg.m_upber();
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
	m_modelid = (int32_t)0;
	m_quality = (int32_t)0;
	m_speed = (int32_t)0;
	m_uplvtype = (int32_t)0;
	m_activateitem = (int32_t)0;
	m_activateitemnum = (int32_t)0;
	m_advancetype = (int32_t)0;
	m_starvancetype = (int32_t)0;
	m_starlimit = (int32_t)0;
	m_starber = (int32_t)0;
	m_soaringattributeid = (int32_t)0;
	m_comprehend = (int32_t)0;
	m_comprehendupitem = (int32_t)0;
	m_comprehendtype = (int32_t)0;
	m_ratio = (int32_t)0;
	m_ratiopercentage = (int32_t)0;
	m_qualitymax = (int32_t)0;
	return 0;
}

int E_MountHuakun_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_s::write_to_pbmsg(::proto_ff::E_MountHuakun & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_modelid((int32_t)m_modelid);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_speed((int32_t)m_speed);
	msg.set_m_uplvtype((int32_t)m_uplvtype);
	msg.set_m_activateitem((int32_t)m_activateitem);
	msg.set_m_activateitemnum((int32_t)m_activateitemnum);
	msg.set_m_advancetype((int32_t)m_advancetype);
	msg.set_m_starvancetype((int32_t)m_starvancetype);
	msg.set_m_starlimit((int32_t)m_starlimit);
	msg.set_m_starber((int32_t)m_starber);
	msg.set_m_skill_lg(m_skill_lg.data());
	msg.set_m_skill_bd(m_skill_bd.data());
	msg.set_m_soaringattributeid((int32_t)m_soaringattributeid);
	msg.set_m_comprehend((int32_t)m_comprehend);
	msg.set_m_exclusive(m_exclusive.data());
	msg.set_m_comprehendskill(m_comprehendskill.data());
	msg.set_m_potential(m_potential.data());
	msg.set_m_comprehendupitem((int32_t)m_comprehendupitem);
	msg.set_m_comprehendtype((int32_t)m_comprehendtype);
	msg.set_m_ratio((int32_t)m_ratio);
	msg.set_m_ratiopercentage((int32_t)m_ratiopercentage);
	msg.set_m_equipsuit(m_equipsuit.data());
	msg.set_m_qualitymax((int32_t)m_qualitymax);
	msg.set_m_lilianchangeitem(m_lilianchangeitem.data());
	for(int32_t i = 0; i < (int32_t)m_uplv.size(); ++i) {
		::proto_ff::E_MountHuakunUplvDesc* temp_m_uplv = msg.add_m_uplv();
		m_uplv[i].write_to_pbmsg(*temp_m_uplv);
	}
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_MountHuakunMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_advance.size(); ++i) {
		::proto_ff::E_MountHuakunAdvanceDesc* temp_m_advance = msg.add_m_advance();
		m_advance[i].write_to_pbmsg(*temp_m_advance);
	}
	for(int32_t i = 0; i < (int32_t)m_upstaritem.size(); ++i) {
		msg.add_m_upstaritem((int32_t)m_upstaritem[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_upstarnum.size(); ++i) {
		msg.add_m_upstarnum(m_upstarnum[i].data());
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MountHuakunAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountHuakun_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun & msg) {
	m_id = msg.m_id();
	m_modelid = msg.m_modelid();
	m_quality = msg.m_quality();
	m_speed = msg.m_speed();
	m_uplvtype = msg.m_uplvtype();
	m_activateitem = msg.m_activateitem();
	m_activateitemnum = msg.m_activateitemnum();
	m_advancetype = msg.m_advancetype();
	m_starvancetype = msg.m_starvancetype();
	m_starlimit = msg.m_starlimit();
	m_starber = msg.m_starber();
	m_skill_lg = msg.m_skill_lg();
	m_skill_bd = msg.m_skill_bd();
	m_soaringattributeid = msg.m_soaringattributeid();
	m_comprehend = msg.m_comprehend();
	m_exclusive = msg.m_exclusive();
	m_comprehendskill = msg.m_comprehendskill();
	m_potential = msg.m_potential();
	m_comprehendupitem = msg.m_comprehendupitem();
	m_comprehendtype = msg.m_comprehendtype();
	m_ratio = msg.m_ratio();
	m_ratiopercentage = msg.m_ratiopercentage();
	m_equipsuit = msg.m_equipsuit();
	m_qualitymax = msg.m_qualitymax();
	m_lilianchangeitem = msg.m_lilianchangeitem();
	m_uplv.resize((int)msg.m_uplv_size() > (int)m_uplv.max_size() ? m_uplv.max_size() : msg.m_uplv_size());
	for(int32_t i = 0; i < (int32_t)m_uplv.size(); ++i) {
		const ::proto_ff::E_MountHuakunUplvDesc & temp_m_uplv = msg.m_uplv(i);
		m_uplv[i].read_from_pbmsg(temp_m_uplv);
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
	m_upstaritem.resize((int)msg.m_upstaritem_size() > (int)m_upstaritem.max_size() ? m_upstaritem.max_size() : msg.m_upstaritem_size());
	for(int32_t i = 0; i < (int32_t)m_upstaritem.size(); ++i) {
		m_upstaritem[i] = msg.m_upstaritem(i);
	}
	m_upstarnum.resize((int)msg.m_upstarnum_size() > (int)m_upstarnum.max_size() ? m_upstarnum.max_size() : msg.m_upstarnum_size());
	for(int32_t i = 0; i < (int32_t)m_upstarnum.size(); ++i) {
		m_upstarnum[i] = msg.m_upstarnum(i);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_MountHuakunAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
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
	m_huakuntype = (int32_t)0;
	m_huakunlv = (int32_t)0;
	m_huakunexp = (int32_t)0;
	return 0;
}

int E_MountHuakun_value_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_value_s::write_to_pbmsg(::proto_ff::E_MountHuakun_value & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_huakuntype((int32_t)m_huakuntype);
	msg.set_m_huakunlv((int32_t)m_huakunlv);
	msg.set_m_huakunexp((int32_t)m_huakunexp);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MountHuakun_valueAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountHuakun_value_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_value & msg) {
	m_id = msg.m_id();
	m_huakuntype = msg.m_huakuntype();
	m_huakunlv = msg.m_huakunlv();
	m_huakunexp = msg.m_huakunexp();
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
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_MountHuakun_advancevalueItemDesc_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_advancevalueItemDesc_s::write_to_pbmsg(::proto_ff::E_MountHuakun_advancevalueItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_MountHuakun_advancevalueItemDesc_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_advancevalueItemDesc & msg) {
	m_num = msg.m_num();
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
	m_lv = (int32_t)0;
	m_advancetype = (int32_t)0;
	m_winprob = (int32_t)0;
	m_faillv = (int32_t)0;
	return 0;
}

int E_MountHuakun_advancevalue_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_advancevalue_s::write_to_pbmsg(::proto_ff::E_MountHuakun_advancevalue & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_advancetype((int32_t)m_advancetype);
	msg.set_m_winprob((int32_t)m_winprob);
	msg.set_m_faillv((int32_t)m_faillv);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_MountHuakun_advancevalueItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_MountHuakun_advancevalue_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_advancevalue & msg) {
	m_id = msg.m_id();
	m_lv = msg.m_lv();
	m_advancetype = msg.m_advancetype();
	m_winprob = msg.m_winprob();
	m_faillv = msg.m_faillv();
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
	m_upvalue = (int32_t)0;
	m_upber = (int32_t)0;
	return 0;
}

int E_MountHuakun_changeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_changeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MountHuakun_changeAttributeDesc & msg) const {
	msg.set_m_upvalue((int32_t)m_upvalue);
	msg.set_m_upber((int32_t)m_upber);
}

void E_MountHuakun_changeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_changeAttributeDesc & msg) {
	m_upvalue = msg.m_upvalue();
	m_upber = msg.m_upber();
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
	m_huakunid = (int32_t)0;
	m_speed = (int32_t)0;
	m_modelid = (int32_t)0;
	m_activationitem = (int32_t)0;
	m_activationnum = (int32_t)0;
	m_starattributeid = (int32_t)0;
	m_starmax = (int32_t)0;
	m_starid = (int32_t)0;
	m_starber = (int32_t)0;
	m_changeattributeid = (int32_t)0;
	return 0;
}

int E_MountHuakun_change_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_change_s::write_to_pbmsg(::proto_ff::E_MountHuakun_change & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_huakunid((int32_t)m_huakunid);
	msg.set_m_speed((int32_t)m_speed);
	msg.set_m_fxid(m_fxid.data());
	msg.set_m_modelid((int32_t)m_modelid);
	msg.set_m_activationitem((int32_t)m_activationitem);
	msg.set_m_activationnum((int32_t)m_activationnum);
	msg.set_m_starattributeid((int32_t)m_starattributeid);
	msg.set_m_starmax((int32_t)m_starmax);
	msg.set_m_starid((int32_t)m_starid);
	msg.set_m_starnum(m_starnum.data());
	msg.set_m_starber((int32_t)m_starber);
	msg.set_m_changeattributeid((int32_t)m_changeattributeid);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MountHuakun_changeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountHuakun_change_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_change & msg) {
	m_id = msg.m_id();
	m_huakunid = msg.m_huakunid();
	m_speed = msg.m_speed();
	m_fxid = msg.m_fxid();
	m_modelid = msg.m_modelid();
	m_activationitem = msg.m_activationitem();
	m_activationnum = msg.m_activationnum();
	m_starattributeid = msg.m_starattributeid();
	m_starmax = msg.m_starmax();
	m_starid = msg.m_starid();
	m_starnum = msg.m_starnum();
	m_starber = msg.m_starber();
	m_changeattributeid = msg.m_changeattributeid();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_MountHuakun_changeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
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
	m_upattributeid = (int32_t)0;
	m_starid = (int32_t)0;
	m_skillid = (int32_t)0;
	return 0;
}

int E_MountHuakun_advance_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_advance_s::write_to_pbmsg(::proto_ff::E_MountHuakun_advance & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_upattributeid((int32_t)m_upattributeid);
	msg.set_m_starid((int32_t)m_starid);
	msg.set_m_skillid((int32_t)m_skillid);
	for(int32_t i = 0; i < (int32_t)m_upattribute.size(); ++i) {
		::proto_ff::E_MountHuakun_advanceUpattributeDesc* temp_m_upattribute = msg.add_m_upattribute();
		m_upattribute[i].write_to_pbmsg(*temp_m_upattribute);
	}
}

void E_MountHuakun_advance_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_advance & msg) {
	m_id = msg.m_id();
	m_upattributeid = msg.m_upattributeid();
	m_starid = msg.m_starid();
	m_skillid = msg.m_skillid();
	m_upattribute.resize((int)msg.m_upattribute_size() > (int)m_upattribute.max_size() ? m_upattribute.max_size() : msg.m_upattribute_size());
	for(int32_t i = 0; i < (int32_t)m_upattribute.size(); ++i) {
		const ::proto_ff::E_MountHuakun_advanceUpattributeDesc & temp_m_upattribute = msg.m_upattribute(i);
		m_upattribute[i].read_from_pbmsg(temp_m_upattribute);
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
	m_equipid = (int32_t)0;
	m_part = (int32_t)0;
	m_quality = (int32_t)0;
	m_equipintensify = (int32_t)0;
	m_srtongup = (int32_t)0;
	m_advanceintensify = (int32_t)0;
	m_equipttop = (int32_t)0;
	m_resolve = (int32_t)0;
	m_resolvemun = (int32_t)0;
	return 0;
}

int E_MountHuakun_equip_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_equip_s::write_to_pbmsg(::proto_ff::E_MountHuakun_equip & msg) const {
	msg.set_m_equipid((int32_t)m_equipid);
	msg.set_m_part((int32_t)m_part);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_equipintensify((int32_t)m_equipintensify);
	msg.set_m_srtongup((int32_t)m_srtongup);
	msg.set_m_advanceintensify((int32_t)m_advanceintensify);
	msg.set_m_equipttop((int32_t)m_equipttop);
	msg.set_m_resolve((int32_t)m_resolve);
	msg.set_m_resolvemun((int32_t)m_resolvemun);
}

void E_MountHuakun_equip_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_equip & msg) {
	m_equipid = msg.m_equipid();
	m_part = msg.m_part();
	m_quality = msg.m_quality();
	m_equipintensify = msg.m_equipintensify();
	m_srtongup = msg.m_srtongup();
	m_advanceintensify = msg.m_advanceintensify();
	m_equipttop = msg.m_equipttop();
	m_resolve = msg.m_resolve();
	m_resolvemun = msg.m_resolvemun();
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
	m_equipintensify = (int32_t)0;
	m_equipvalue = (int32_t)0;
	m_equiplv = (int32_t)0;
	m_equipitem = (int32_t)0;
	m_equipmun = (int32_t)0;
	return 0;
}

int E_MountEquip_value_s::ResumeInit() {
	return 0;
}

void E_MountEquip_value_s::write_to_pbmsg(::proto_ff::E_MountEquip_value & msg) const {
	msg.set_m_equipintensify((int32_t)m_equipintensify);
	msg.set_m_equipvalue((int32_t)m_equipvalue);
	msg.set_m_equiplv((int32_t)m_equiplv);
	msg.set_m_equipitem((int32_t)m_equipitem);
	msg.set_m_equipmun((int32_t)m_equipmun);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MountEquip_valueAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountEquip_value_s::read_from_pbmsg(const ::proto_ff::E_MountEquip_value & msg) {
	m_equipintensify = msg.m_equipintensify();
	m_equipvalue = msg.m_equipvalue();
	m_equiplv = msg.m_equiplv();
	m_equipitem = msg.m_equipitem();
	m_equipmun = msg.m_equipmun();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_MountEquip_valueAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
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
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MountEquipsuitAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountEquipsuit_s::read_from_pbmsg(const ::proto_ff::E_MountEquipsuit & msg) {
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_piece = msg.m_piece();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_MountEquipsuitAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
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
	m_positionid = (int32_t)0;
	m_equipttop = (int32_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_MountEquiptop_s::ResumeInit() {
	return 0;
}

void E_MountEquiptop_s::write_to_pbmsg(::proto_ff::E_MountEquiptop & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_positionid((int32_t)m_positionid);
	msg.set_m_equipttop((int32_t)m_equipttop);
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
	m_positionid = msg.m_positionid();
	m_equipttop = msg.m_equipttop();
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
	m_honeopen = (int32_t)0;
	m_item = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_MountEquippart_s::ResumeInit() {
	return 0;
}

void E_MountEquippart_s::write_to_pbmsg(::proto_ff::E_MountEquippart & msg) const {
	msg.set_m_part((int32_t)m_part);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_honeopen((int32_t)m_honeopen);
	msg.set_m_item((int32_t)m_item);
	msg.set_m_num((int32_t)m_num);
}

void E_MountEquippart_s::read_from_pbmsg(const ::proto_ff::E_MountEquippart & msg) {
	m_part = msg.m_part();
	m_quality = msg.m_quality();
	m_honeopen = msg.m_honeopen();
	m_item = msg.m_item();
	m_num = msg.m_num();
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
	m_fairylandid = (int32_t)0;
	m_fairylandnextid = (int32_t)0;
	return 0;
}

int E_MountEmpowermenttour_debris_s::ResumeInit() {
	return 0;
}

void E_MountEmpowermenttour_debris_s::write_to_pbmsg(::proto_ff::E_MountEmpowermenttour_debris & msg) const {
	msg.set_m_fairylandid((int32_t)m_fairylandid);
	msg.set_m_fairylandnextid((int32_t)m_fairylandnextid);
	msg.set_m_fairylandskin(m_fairylandskin.data());
}

void E_MountEmpowermenttour_debris_s::read_from_pbmsg(const ::proto_ff::E_MountEmpowermenttour_debris & msg) {
	m_fairylandid = msg.m_fairylandid();
	m_fairylandnextid = msg.m_fairylandnextid();
	m_fairylandskin = msg.m_fairylandskin();
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
	m_tourid = (int32_t)0;
	m_fairylandid = (int32_t)0;
	m_touritem = (int32_t)0;
	m_tourdebris = (int32_t)0;
	return 0;
}

int E_MountEmpowerment_s::ResumeInit() {
	return 0;
}

void E_MountEmpowerment_s::write_to_pbmsg(::proto_ff::E_MountEmpowerment & msg) const {
	msg.set_m_tourid((int32_t)m_tourid);
	msg.set_m_fairylandid((int32_t)m_fairylandid);
	msg.set_m_touritem((int32_t)m_touritem);
	msg.set_m_tourdebris((int32_t)m_tourdebris);
	for(int32_t i = 0; i < (int32_t)m_tour.size(); ++i) {
		::proto_ff::E_MountEmpowermentTourDesc* temp_m_tour = msg.add_m_tour();
		m_tour[i].write_to_pbmsg(*temp_m_tour);
	}
}

void E_MountEmpowerment_s::read_from_pbmsg(const ::proto_ff::E_MountEmpowerment & msg) {
	m_tourid = msg.m_tourid();
	m_fairylandid = msg.m_fairylandid();
	m_touritem = msg.m_touritem();
	m_tourdebris = msg.m_tourdebris();
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
	m_empowermentslot = (int32_t)0;
	m_unlocktime = (int32_t)0;
	m_unlocknum = (int32_t)0;
	return 0;
}

int E_MountEmpowerment_position_s::ResumeInit() {
	return 0;
}

void E_MountEmpowerment_position_s::write_to_pbmsg(::proto_ff::E_MountEmpowerment_position & msg) const {
	msg.set_m_empowermentslot((int32_t)m_empowermentslot);
	msg.set_m_unlocktime((int32_t)m_unlocktime);
	msg.set_m_unlocknum((int32_t)m_unlocknum);
}

void E_MountEmpowerment_position_s::read_from_pbmsg(const ::proto_ff::E_MountEmpowerment_position & msg) {
	m_empowermentslot = msg.m_empowermentslot();
	m_unlocktime = msg.m_unlocktime();
	m_unlocknum = msg.m_unlocknum();
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
	m_dissociatelevel = (int32_t)0;
	m_dissociatetime = (int32_t)0;
	m_dissociatehour = (int32_t)0;
	m_dissociateitem = (int32_t)0;
	m_dissociatenum = (int32_t)0;
	m_dissociatebox = (int32_t)0;
	return 0;
}

int E_MountEmpowerment_slot_s::ResumeInit() {
	return 0;
}

void E_MountEmpowerment_slot_s::write_to_pbmsg(::proto_ff::E_MountEmpowerment_slot & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_dissociatelevel((int32_t)m_dissociatelevel);
	msg.set_m_dissociatetime((int32_t)m_dissociatetime);
	msg.set_m_dissociatehour((int32_t)m_dissociatehour);
	msg.set_m_dissociateitem((int32_t)m_dissociateitem);
	msg.set_m_dissociatenum((int32_t)m_dissociatenum);
	msg.set_m_eventtime(m_eventtime.data());
	msg.set_m_dissociatebox((int32_t)m_dissociatebox);
}

void E_MountEmpowerment_slot_s::read_from_pbmsg(const ::proto_ff::E_MountEmpowerment_slot & msg) {
	m_id = msg.m_id();
	m_dissociatelevel = msg.m_dissociatelevel();
	m_dissociatetime = msg.m_dissociatetime();
	m_dissociatehour = msg.m_dissociatehour();
	m_dissociateitem = msg.m_dissociateitem();
	m_dissociatenum = msg.m_dissociatenum();
	m_eventtime = msg.m_eventtime();
	m_dissociatebox = msg.m_dissociatebox();
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
	m_eventtype = (int32_t)0;
	m_weight = (int32_t)0;
	return 0;
}

int E_MountEmpowerment_event_s::ResumeInit() {
	return 0;
}

void E_MountEmpowerment_event_s::write_to_pbmsg(::proto_ff::E_MountEmpowerment_event & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_eventtype((int32_t)m_eventtype);
	msg.set_m_weight((int32_t)m_weight);
}

void E_MountEmpowerment_event_s::read_from_pbmsg(const ::proto_ff::E_MountEmpowerment_event & msg) {
	m_id = msg.m_id();
	m_eventtype = msg.m_eventtype();
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
