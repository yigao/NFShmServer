#include "mount_s.h"

namespace proto_ff_s {

E_MountFragmentAttributeDesc_s::E_MountFragmentAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountFragmentAttributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_MountFragmentAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountFragmentAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MountFragmentAttributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_MountFragmentAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountFragmentAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountFragmentAttributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountFragment_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MountFragment_s));
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
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_MountValueAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountValueAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MountValueAttributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_MountValueAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountValueAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountValueAttributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountValue_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MountValue_s));
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
	m_id = (int32_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_MountDisplayMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_MountDisplayMaterialDesc_s::write_to_pbmsg(::proto_ff::E_MountDisplayMaterialDesc & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_exp((int32_t)m_exp);
}

void E_MountDisplayMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_MountDisplayMaterialDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountDisplayMaterialDesc_s));
	m_id = msg.m_id();
	m_exp = msg.m_exp();
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
	msg.set_m_skillid((const char*)m_skillid.data());
	msg.set_m_fxid((const char*)m_fxid.data());
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountDisplay_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MountDisplay_s));
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
}

void E_MountUnlock_s::read_from_pbmsg(const ::proto_ff::E_MountUnlock & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountUnlock_s));
	m_id = msg.m_id();
	m_lv = msg.m_lv();
	m_modelid = msg.m_modelid();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MountUnlock_s));
	E_MountUnlock_List.resize((int)msg.e_mountunlock_list_size() > (int)E_MountUnlock_List.max_size() ? E_MountUnlock_List.max_size() : msg.e_mountunlock_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountUnlock_List.size(); ++i) {
		const ::proto_ff::E_MountUnlock & temp_e_mountunlock_list = msg.e_mountunlock_list(i);
		E_MountUnlock_List[i].read_from_pbmsg(temp_e_mountunlock_list);
	}
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountChangeAttributeDesc_s));
	m_upvalue = msg.m_upvalue();
	m_upber = msg.m_upber();
}

E_MountChangeMaterialDesc_s::E_MountChangeMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountChangeMaterialDesc_s::CreateInit() {
	m_id = (int32_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_MountChangeMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_MountChangeMaterialDesc_s::write_to_pbmsg(::proto_ff::E_MountChangeMaterialDesc & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_exp((int32_t)m_exp);
}

void E_MountChangeMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_MountChangeMaterialDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountChangeMaterialDesc_s));
	m_id = msg.m_id();
	m_exp = msg.m_exp();
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
	msg.set_m_speed((int32_t)m_speed);
	msg.set_m_uplvtype((int32_t)m_uplvtype);
	msg.set_m_activeskill((int32_t)m_activeskill);
	msg.set_m_skillid((const char*)m_skillid.data());
	msg.set_m_fxid((const char*)m_fxid.data());
	msg.set_m_starmax((int32_t)m_starmax);
	msg.set_m_lvmax((int32_t)m_lvmax);
	msg.set_m_modelid((int32_t)m_modelid);
	msg.set_m_activationitem((int32_t)m_activationitem);
	msg.set_m_activationnum((int32_t)m_activationnum);
	msg.set_m_starid((int32_t)m_starid);
	msg.set_m_starnum((const char*)m_starnum.data());
	msg.set_m_starber((int32_t)m_starber);
	msg.set_m_upattributeid((int32_t)m_upattributeid);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MountChangeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_MountChangeMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
}

void E_MountChange_s::read_from_pbmsg(const ::proto_ff::E_MountChange & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountChange_s));
	m_id = msg.m_id();
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
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_MountChangeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_MountChangeMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MountChange_s));
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
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_MountAdvanceUpattributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountAdvanceUpattributeDesc_s::write_to_pbmsg(::proto_ff::E_MountAdvanceUpattributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_MountAdvanceUpattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountAdvanceUpattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountAdvanceUpattributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountAdvance_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MountAdvance_s));
	E_MountAdvance_List.resize((int)msg.e_mountadvance_list_size() > (int)E_MountAdvance_List.max_size() ? E_MountAdvance_List.max_size() : msg.e_mountadvance_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountAdvance_List.size(); ++i) {
		const ::proto_ff::E_MountAdvance & temp_e_mountadvance_list = msg.e_mountadvance_list(i);
		E_MountAdvance_List[i].read_from_pbmsg(temp_e_mountadvance_list);
	}
}

E_MountHuakunMaterialDesc_s::E_MountHuakunMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountHuakunMaterialDesc_s::CreateInit() {
	m_id = (int32_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_MountHuakunMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_MountHuakunMaterialDesc_s::write_to_pbmsg(::proto_ff::E_MountHuakunMaterialDesc & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_exp((int32_t)m_exp);
}

void E_MountHuakunMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_MountHuakunMaterialDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountHuakunMaterialDesc_s));
	m_id = msg.m_id();
	m_exp = msg.m_exp();
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
	m_advancetype = (int32_t)0;
	m_starmax = (int32_t)0;
	m_starnumber = (int32_t)0;
	m_activateitem = (int32_t)0;
	m_activateitemnum = (int32_t)0;
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
	msg.set_m_advancetype((int32_t)m_advancetype);
	msg.set_m_starmax((int32_t)m_starmax);
	msg.set_m_upstarnum((const char*)m_upstarnum.data());
	msg.set_m_starnumber((int32_t)m_starnumber);
	msg.set_m_upstarbertype((const char*)m_upstarbertype.data());
	msg.set_m_activateitem((int32_t)m_activateitem);
	msg.set_m_activateitemnum((int32_t)m_activateitemnum);
	msg.set_m_skill_lg((const char*)m_skill_lg.data());
	msg.set_m_skill_bd((const char*)m_skill_bd.data());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_MountHuakunMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_upstaritem.size(); ++i) {
		msg.add_m_upstaritem((int32_t)m_upstaritem[i]);
	}
}

void E_MountHuakun_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountHuakun_s));
	m_id = msg.m_id();
	m_modelid = msg.m_modelid();
	m_quality = msg.m_quality();
	m_speed = msg.m_speed();
	m_uplvtype = msg.m_uplvtype();
	m_advancetype = msg.m_advancetype();
	m_starmax = msg.m_starmax();
	m_upstarnum = msg.m_upstarnum();
	m_starnumber = msg.m_starnumber();
	m_upstarbertype = msg.m_upstarbertype();
	m_activateitem = msg.m_activateitem();
	m_activateitemnum = msg.m_activateitemnum();
	m_skill_lg = msg.m_skill_lg();
	m_skill_bd = msg.m_skill_bd();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_MountHuakunMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_upstaritem.resize((int)msg.m_upstaritem_size() > (int)m_upstaritem.max_size() ? m_upstaritem.max_size() : msg.m_upstaritem_size());
	for(int32_t i = 0; i < (int32_t)m_upstaritem.size(); ++i) {
		m_upstaritem[i] = msg.m_upstaritem(i);
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MountHuakun_s));
	E_MountHuakun_List.resize((int)msg.e_mounthuakun_list_size() > (int)E_MountHuakun_List.max_size() ? E_MountHuakun_List.max_size() : msg.e_mounthuakun_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountHuakun_List.size(); ++i) {
		const ::proto_ff::E_MountHuakun & temp_e_mounthuakun_list = msg.e_mounthuakun_list(i);
		E_MountHuakun_List[i].read_from_pbmsg(temp_e_mounthuakun_list);
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountHuakun_advancevalueItemDesc_s));
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
	m_lvtype = (int32_t)0;
	m_advancetype = (int32_t)0;
	m_winprob = (int32_t)0;
	return 0;
}

int E_MountHuakun_advancevalue_s::ResumeInit() {
	return 0;
}

void E_MountHuakun_advancevalue_s::write_to_pbmsg(::proto_ff::E_MountHuakun_advancevalue & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_lvtype((int32_t)m_lvtype);
	msg.set_m_advancetype((int32_t)m_advancetype);
	msg.set_m_winprob((int32_t)m_winprob);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_MountHuakun_advancevalueItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_MountHuakun_advancevalue_s::read_from_pbmsg(const ::proto_ff::E_MountHuakun_advancevalue & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountHuakun_advancevalue_s));
	m_id = msg.m_id();
	m_lv = msg.m_lv();
	m_lvtype = msg.m_lvtype();
	m_advancetype = msg.m_advancetype();
	m_winprob = msg.m_winprob();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MountHuakun_advancevalue_s));
	E_MountHuakun_advancevalue_List.resize((int)msg.e_mounthuakun_advancevalue_list_size() > (int)E_MountHuakun_advancevalue_List.max_size() ? E_MountHuakun_advancevalue_List.max_size() : msg.e_mounthuakun_advancevalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountHuakun_advancevalue_List.size(); ++i) {
		const ::proto_ff::E_MountHuakun_advancevalue & temp_e_mounthuakun_advancevalue_list = msg.e_mounthuakun_advancevalue_list(i);
		E_MountHuakun_advancevalue_List[i].read_from_pbmsg(temp_e_mounthuakun_advancevalue_list);
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
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_MountBloodAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MountBloodAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MountBloodAttributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_MountBloodAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MountBloodAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountBloodAttributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_MountBlood_s::E_MountBlood_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MountBlood_s::CreateInit() {
	m_num = (int32_t)0;
	return 0;
}

int E_MountBlood_s::ResumeInit() {
	return 0;
}

void E_MountBlood_s::write_to_pbmsg(::proto_ff::E_MountBlood & msg) const {
	msg.set_m_num((int32_t)m_num);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MountBloodAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MountBlood_s::read_from_pbmsg(const ::proto_ff::E_MountBlood & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountBlood_s));
	m_num = msg.m_num();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MountBlood_s));
	E_MountBlood_List.resize((int)msg.e_mountblood_list_size() > (int)E_MountBlood_List.max_size() ? E_MountBlood_List.max_size() : msg.e_mountblood_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountBlood_List.size(); ++i) {
		const ::proto_ff::E_MountBlood & temp_e_mountblood_list = msg.e_mountblood_list(i);
		E_MountBlood_List[i].read_from_pbmsg(temp_e_mountblood_list);
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MountBaby_egg_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MountBaby_egg_s));
	E_MountBaby_egg_List.resize((int)msg.e_mountbaby_egg_list_size() > (int)E_MountBaby_egg_List.max_size() ? E_MountBaby_egg_List.max_size() : msg.e_mountbaby_egg_list_size());
	for(int32_t i = 0; i < (int32_t)E_MountBaby_egg_List.size(); ++i) {
		const ::proto_ff::E_MountBaby_egg & temp_e_mountbaby_egg_list = msg.e_mountbaby_egg_list(i);
		E_MountBaby_egg_List[i].read_from_pbmsg(temp_e_mountbaby_egg_list);
	}
}

}