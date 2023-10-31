#include "E_Dragon_s.h"

namespace proto_ff_s {

E_DragonFragmentAttributeDesc_s::E_DragonFragmentAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonFragmentAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_DragonFragmentAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_DragonFragmentAttributeDesc_s::write_to_pbmsg(::proto_ff::E_DragonFragmentAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_DragonFragmentAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_DragonFragmentAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_DragonFragment_s::E_DragonFragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonFragment_s::CreateInit() {
	m_fragmentID = (int64_t)0;
	m_item = (int64_t)0;
	m_itemNum = (int32_t)0;
	return 0;
}

int E_DragonFragment_s::ResumeInit() {
	return 0;
}

void E_DragonFragment_s::write_to_pbmsg(::proto_ff::E_DragonFragment & msg) const {
	msg.set_m_fragmentid((int64_t)m_fragmentID);
	msg.set_m_item((int64_t)m_item);
	msg.set_m_itemnum((int32_t)m_itemNum);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_DragonFragmentAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_DragonFragment_s::read_from_pbmsg(const ::proto_ff::E_DragonFragment & msg) {
	m_fragmentID = msg.m_fragmentid();
	m_item = msg.m_item();
	m_itemNum = msg.m_itemnum();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_DragonFragmentAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_DragonFragment_s::Sheet_DragonFragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DragonFragment_s::CreateInit() {
	return 0;
}

int Sheet_DragonFragment_s::ResumeInit() {
	return 0;
}

void Sheet_DragonFragment_s::write_to_pbmsg(::proto_ff::Sheet_DragonFragment & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DragonFragment_List.size(); ++i) {
		::proto_ff::E_DragonFragment* temp_e_dragonfragment_list = msg.add_e_dragonfragment_list();
		E_DragonFragment_List[i].write_to_pbmsg(*temp_e_dragonfragment_list);
	}
}

void Sheet_DragonFragment_s::read_from_pbmsg(const ::proto_ff::Sheet_DragonFragment & msg) {
	E_DragonFragment_List.resize((int)msg.e_dragonfragment_list_size() > (int)E_DragonFragment_List.max_size() ? E_DragonFragment_List.max_size() : msg.e_dragonfragment_list_size());
	for(int32_t i = 0; i < (int32_t)E_DragonFragment_List.size(); ++i) {
		const ::proto_ff::E_DragonFragment & temp_e_dragonfragment_list = msg.e_dragonfragment_list(i);
		E_DragonFragment_List[i].read_from_pbmsg(temp_e_dragonfragment_list);
	}
}

E_DragonDisplayMaterialDesc_s::E_DragonDisplayMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonDisplayMaterialDesc_s::CreateInit() {
	m_exp = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_DragonDisplayMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_DragonDisplayMaterialDesc_s::write_to_pbmsg(::proto_ff::E_DragonDisplayMaterialDesc & msg) const {
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_id((int32_t)m_id);
}

void E_DragonDisplayMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_DragonDisplayMaterialDesc & msg) {
	m_exp = msg.m_exp();
	m_id = msg.m_id();
}

E_DragonDisplay_s::E_DragonDisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonDisplay_s::CreateInit() {
	m_id = (int32_t)0;
	m_funId = (int32_t)0;
	m_UpLvType = (int32_t)0;
	m_LvMax = (int32_t)0;
	m_starItem = (int32_t)0;
	m_UpStarType = (int32_t)0;
	m_starUp = (int32_t)0;
	m_luck = (int32_t)0;
	return 0;
}

int E_DragonDisplay_s::ResumeInit() {
	return 0;
}

void E_DragonDisplay_s::write_to_pbmsg(::proto_ff::E_DragonDisplay & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_funid((int32_t)m_funId);
	msg.set_m_uplvtype((int32_t)m_UpLvType);
	msg.set_m_lvmax((int32_t)m_LvMax);
	msg.set_m_skillid(m_skillID.data());
	msg.set_m_exskillid(m_exSkillID.data());
	msg.set_m_staritem((int32_t)m_starItem);
	msg.set_m_upstartype((int32_t)m_UpStarType);
	msg.set_m_starup((int32_t)m_starUp);
	msg.set_m_luck((int32_t)m_luck);
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_DragonDisplayMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_fragmentID.size(); ++i) {
		msg.add_m_fragmentid((int64_t)m_fragmentID[i]);
	}
}

void E_DragonDisplay_s::read_from_pbmsg(const ::proto_ff::E_DragonDisplay & msg) {
	m_id = msg.m_id();
	m_funId = msg.m_funid();
	m_UpLvType = msg.m_uplvtype();
	m_LvMax = msg.m_lvmax();
	m_skillID = msg.m_skillid();
	m_exSkillID = msg.m_exskillid();
	m_starItem = msg.m_staritem();
	m_UpStarType = msg.m_upstartype();
	m_starUp = msg.m_starup();
	m_luck = msg.m_luck();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_DragonDisplayMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_fragmentID.resize((int)msg.m_fragmentid_size() > (int)m_fragmentID.max_size() ? m_fragmentID.max_size() : msg.m_fragmentid_size());
	for(int32_t i = 0; i < (int32_t)m_fragmentID.size(); ++i) {
		m_fragmentID[i] = msg.m_fragmentid(i);
	}
}

Sheet_DragonDisplay_s::Sheet_DragonDisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DragonDisplay_s::CreateInit() {
	return 0;
}

int Sheet_DragonDisplay_s::ResumeInit() {
	return 0;
}

void Sheet_DragonDisplay_s::write_to_pbmsg(::proto_ff::Sheet_DragonDisplay & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DragonDisplay_List.size(); ++i) {
		::proto_ff::E_DragonDisplay* temp_e_dragondisplay_list = msg.add_e_dragondisplay_list();
		E_DragonDisplay_List[i].write_to_pbmsg(*temp_e_dragondisplay_list);
	}
}

void Sheet_DragonDisplay_s::read_from_pbmsg(const ::proto_ff::Sheet_DragonDisplay & msg) {
	E_DragonDisplay_List.resize((int)msg.e_dragondisplay_list_size() > (int)E_DragonDisplay_List.max_size() ? E_DragonDisplay_List.max_size() : msg.e_dragondisplay_list_size());
	for(int32_t i = 0; i < (int32_t)E_DragonDisplay_List.size(); ++i) {
		const ::proto_ff::E_DragonDisplay & temp_e_dragondisplay_list = msg.e_dragondisplay_list(i);
		E_DragonDisplay_List[i].read_from_pbmsg(temp_e_dragondisplay_list);
	}
}

E_DragonChange_s::E_DragonChange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonChange_s::CreateInit() {
	m_id = (int32_t)0;
	m_funid = (int32_t)0;
	m_starMax = (int32_t)0;
	m_starType = (int32_t)0;
	m_activationItem = (int32_t)0;
	m_activationNum = (int32_t)0;
	m_starId = (int32_t)0;
	return 0;
}

int E_DragonChange_s::ResumeInit() {
	return 0;
}

void E_DragonChange_s::write_to_pbmsg(::proto_ff::E_DragonChange & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_funid((int32_t)m_funid);
	msg.set_m_skillid(m_skillID.data());
	msg.set_m_exskillid(m_exSkillID.data());
	msg.set_m_fxid(m_fxID.data());
	msg.set_m_starmax((int32_t)m_starMax);
	msg.set_m_startype((int32_t)m_starType);
	msg.set_m_activationitem((int32_t)m_activationItem);
	msg.set_m_activationnum((int32_t)m_activationNum);
	msg.set_m_starid((int32_t)m_starId);
}

void E_DragonChange_s::read_from_pbmsg(const ::proto_ff::E_DragonChange & msg) {
	m_id = msg.m_id();
	m_funid = msg.m_funid();
	m_skillID = msg.m_skillid();
	m_exSkillID = msg.m_exskillid();
	m_fxID = msg.m_fxid();
	m_starMax = msg.m_starmax();
	m_starType = msg.m_startype();
	m_activationItem = msg.m_activationitem();
	m_activationNum = msg.m_activationnum();
	m_starId = msg.m_starid();
}

Sheet_DragonChange_s::Sheet_DragonChange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DragonChange_s::CreateInit() {
	return 0;
}

int Sheet_DragonChange_s::ResumeInit() {
	return 0;
}

void Sheet_DragonChange_s::write_to_pbmsg(::proto_ff::Sheet_DragonChange & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DragonChange_List.size(); ++i) {
		::proto_ff::E_DragonChange* temp_e_dragonchange_list = msg.add_e_dragonchange_list();
		E_DragonChange_List[i].write_to_pbmsg(*temp_e_dragonchange_list);
	}
}

void Sheet_DragonChange_s::read_from_pbmsg(const ::proto_ff::Sheet_DragonChange & msg) {
	E_DragonChange_List.resize((int)msg.e_dragonchange_list_size() > (int)E_DragonChange_List.max_size() ? E_DragonChange_List.max_size() : msg.e_dragonchange_list_size());
	for(int32_t i = 0; i < (int32_t)E_DragonChange_List.size(); ++i) {
		const ::proto_ff::E_DragonChange & temp_e_dragonchange_list = msg.e_dragonchange_list(i);
		E_DragonChange_List[i].read_from_pbmsg(temp_e_dragonchange_list);
	}
}

E_DragonLvvalueAttributeDesc_s::E_DragonLvvalueAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonLvvalueAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_DragonLvvalueAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_DragonLvvalueAttributeDesc_s::write_to_pbmsg(::proto_ff::E_DragonLvvalueAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_DragonLvvalueAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_DragonLvvalueAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_DragonLvvalue_s::E_DragonLvvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonLvvalue_s::CreateInit() {
	m_lv = (int32_t)0;
	m_Exp = (int32_t)0;
	m_gold = (int32_t)0;
	m_starLimit = (int32_t)0;
	return 0;
}

int E_DragonLvvalue_s::ResumeInit() {
	return 0;
}

void E_DragonLvvalue_s::write_to_pbmsg(::proto_ff::E_DragonLvvalue & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int32_t)m_Exp);
	msg.set_m_gold((int32_t)m_gold);
	msg.set_m_starlimit((int32_t)m_starLimit);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_DragonLvvalueAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_DragonLvvalue_s::read_from_pbmsg(const ::proto_ff::E_DragonLvvalue & msg) {
	m_lv = msg.m_lv();
	m_Exp = msg.m_exp();
	m_gold = msg.m_gold();
	m_starLimit = msg.m_starlimit();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_DragonLvvalueAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_DragonLvvalue_s::Sheet_DragonLvvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DragonLvvalue_s::CreateInit() {
	return 0;
}

int Sheet_DragonLvvalue_s::ResumeInit() {
	return 0;
}

void Sheet_DragonLvvalue_s::write_to_pbmsg(::proto_ff::Sheet_DragonLvvalue & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DragonLvvalue_List.size(); ++i) {
		::proto_ff::E_DragonLvvalue* temp_e_dragonlvvalue_list = msg.add_e_dragonlvvalue_list();
		E_DragonLvvalue_List[i].write_to_pbmsg(*temp_e_dragonlvvalue_list);
	}
}

void Sheet_DragonLvvalue_s::read_from_pbmsg(const ::proto_ff::Sheet_DragonLvvalue & msg) {
	E_DragonLvvalue_List.resize((int)msg.e_dragonlvvalue_list_size() > (int)E_DragonLvvalue_List.max_size() ? E_DragonLvvalue_List.max_size() : msg.e_dragonlvvalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_DragonLvvalue_List.size(); ++i) {
		const ::proto_ff::E_DragonLvvalue & temp_e_dragonlvvalue_list = msg.e_dragonlvvalue_list(i);
		E_DragonLvvalue_List[i].read_from_pbmsg(temp_e_dragonlvvalue_list);
	}
}

E_DragonStarvalueAttributeDesc_s::E_DragonStarvalueAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonStarvalueAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_DragonStarvalueAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_DragonStarvalueAttributeDesc_s::write_to_pbmsg(::proto_ff::E_DragonStarvalueAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_DragonStarvalueAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_DragonStarvalueAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_DragonStarvalue_s::E_DragonStarvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonStarvalue_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_star = (int32_t)0;
	m_gold = (int32_t)0;
	m_starNum = (int32_t)0;
	m_sucess = (int32_t)0;
	m_luckMax = (int32_t)0;
	m_failluck = (int32_t)0;
	m_model = (int32_t)0;
	return 0;
}

int E_DragonStarvalue_s::ResumeInit() {
	return 0;
}

void E_DragonStarvalue_s::write_to_pbmsg(::proto_ff::E_DragonStarvalue & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_gold((int32_t)m_gold);
	msg.set_m_starnum((int32_t)m_starNum);
	msg.set_m_sucess((int32_t)m_sucess);
	msg.set_m_luckmax((int32_t)m_luckMax);
	msg.set_m_failluck((int32_t)m_failluck);
	msg.set_m_model((int32_t)m_model);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_DragonStarvalueAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_DragonStarvalue_s::read_from_pbmsg(const ::proto_ff::E_DragonStarvalue & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_star = msg.m_star();
	m_gold = msg.m_gold();
	m_starNum = msg.m_starnum();
	m_sucess = msg.m_sucess();
	m_luckMax = msg.m_luckmax();
	m_failluck = msg.m_failluck();
	m_model = msg.m_model();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_DragonStarvalueAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_DragonStarvalue_s::Sheet_DragonStarvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DragonStarvalue_s::CreateInit() {
	return 0;
}

int Sheet_DragonStarvalue_s::ResumeInit() {
	return 0;
}

void Sheet_DragonStarvalue_s::write_to_pbmsg(::proto_ff::Sheet_DragonStarvalue & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DragonStarvalue_List.size(); ++i) {
		::proto_ff::E_DragonStarvalue* temp_e_dragonstarvalue_list = msg.add_e_dragonstarvalue_list();
		E_DragonStarvalue_List[i].write_to_pbmsg(*temp_e_dragonstarvalue_list);
	}
}

void Sheet_DragonStarvalue_s::read_from_pbmsg(const ::proto_ff::Sheet_DragonStarvalue & msg) {
	E_DragonStarvalue_List.resize((int)msg.e_dragonstarvalue_list_size() > (int)E_DragonStarvalue_List.max_size() ? E_DragonStarvalue_List.max_size() : msg.e_dragonstarvalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_DragonStarvalue_List.size(); ++i) {
		const ::proto_ff::E_DragonStarvalue & temp_e_dragonstarvalue_list = msg.e_dragonstarvalue_list(i);
		E_DragonStarvalue_List[i].read_from_pbmsg(temp_e_dragonstarvalue_list);
	}
}

}
