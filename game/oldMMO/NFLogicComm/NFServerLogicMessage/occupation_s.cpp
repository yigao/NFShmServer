#include "occupation_s.h"

namespace proto_ff_s {

E_OccupationOccupation_s::E_OccupationOccupation_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_OccupationOccupation_s::CreateInit() {
	m_id = (int64_t)0;
	m_professionid = (int32_t)0;
	m_grade = (int32_t)0;
	m_level = (int32_t)0;
	m_skill_id = (int64_t)0;
	return 0;
}

int E_OccupationOccupation_s::ResumeInit() {
	return 0;
}

void E_OccupationOccupation_s::write_to_pbmsg(::proto_ff::E_OccupationOccupation & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_professionid((int32_t)m_professionid);
	msg.set_m_grade((int32_t)m_grade);
	msg.set_m_equip((const char*)m_equip.data());
	msg.set_m_modelid((const char*)m_modelid.data());
	msg.set_m_activedesc((const char*)m_activedesc.data());
	msg.set_m_level((int32_t)m_level);
	msg.set_m_skill_id((int64_t)m_skill_id);
	msg.set_m_itemids((const char*)m_itemids.data());
}

void E_OccupationOccupation_s::read_from_pbmsg(const ::proto_ff::E_OccupationOccupation & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_OccupationOccupation_s));
	m_id = msg.m_id();
	m_professionid = msg.m_professionid();
	m_grade = msg.m_grade();
	m_equip = msg.m_equip();
	m_modelid = msg.m_modelid();
	m_activedesc = msg.m_activedesc();
	m_level = msg.m_level();
	m_skill_id = msg.m_skill_id();
	m_itemids = msg.m_itemids();
}

Sheet_OccupationOccupation_s::Sheet_OccupationOccupation_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_OccupationOccupation_s::CreateInit() {
	return 0;
}

int Sheet_OccupationOccupation_s::ResumeInit() {
	return 0;
}

void Sheet_OccupationOccupation_s::write_to_pbmsg(::proto_ff::Sheet_OccupationOccupation & msg) const {
	for(int32_t i = 0; i < (int32_t)E_OccupationOccupation_List.size(); ++i) {
		::proto_ff::E_OccupationOccupation* temp_e_occupationoccupation_list = msg.add_e_occupationoccupation_list();
		E_OccupationOccupation_List[i].write_to_pbmsg(*temp_e_occupationoccupation_list);
	}
}

void Sheet_OccupationOccupation_s::read_from_pbmsg(const ::proto_ff::Sheet_OccupationOccupation & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_OccupationOccupation_s));
	E_OccupationOccupation_List.resize((int)msg.e_occupationoccupation_list_size() > (int)E_OccupationOccupation_List.max_size() ? E_OccupationOccupation_List.max_size() : msg.e_occupationoccupation_list_size());
	for(int32_t i = 0; i < (int32_t)E_OccupationOccupation_List.size(); ++i) {
		const ::proto_ff::E_OccupationOccupation & temp_e_occupationoccupation_list = msg.e_occupationoccupation_list(i);
		E_OccupationOccupation_List[i].read_from_pbmsg(temp_e_occupationoccupation_list);
	}
}

E_OccupationStage_s::E_OccupationStage_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_OccupationStage_s::CreateInit() {
	m_id = (int32_t)0;
	m_grade = (int32_t)0;
	m_lv = (int32_t)0;
	m_stgaeattshow = (int32_t)0;
	m_stgaeatt = (int32_t)0;
	m_taskid = (int32_t)0;
	m_battle = (int32_t)0;
	m_skillid = (int32_t)0;
	m_soultpye = (int32_t)0;
	m_itemid = (int32_t)0;
	return 0;
}

int E_OccupationStage_s::ResumeInit() {
	return 0;
}

void E_OccupationStage_s::write_to_pbmsg(::proto_ff::E_OccupationStage & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_grade((int32_t)m_grade);
	msg.set_m_stgae((const char*)m_stgae.data());
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_stgaeattshow((int32_t)m_stgaeattshow);
	msg.set_m_stgaeatt((int32_t)m_stgaeatt);
	msg.set_m_taskid((int32_t)m_taskid);
	msg.set_m_battle((int32_t)m_battle);
	msg.set_m_skillid((int32_t)m_skillid);
	msg.set_m_lightsoul((const char*)m_lightsoul.data());
	msg.set_m_soultpye((int32_t)m_soultpye);
	msg.set_m_itemid((int32_t)m_itemid);
}

void E_OccupationStage_s::read_from_pbmsg(const ::proto_ff::E_OccupationStage & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_OccupationStage_s));
	m_id = msg.m_id();
	m_grade = msg.m_grade();
	m_stgae = msg.m_stgae();
	m_lv = msg.m_lv();
	m_stgaeattshow = msg.m_stgaeattshow();
	m_stgaeatt = msg.m_stgaeatt();
	m_taskid = msg.m_taskid();
	m_battle = msg.m_battle();
	m_skillid = msg.m_skillid();
	m_lightsoul = msg.m_lightsoul();
	m_soultpye = msg.m_soultpye();
	m_itemid = msg.m_itemid();
}

Sheet_OccupationStage_s::Sheet_OccupationStage_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_OccupationStage_s::CreateInit() {
	return 0;
}

int Sheet_OccupationStage_s::ResumeInit() {
	return 0;
}

void Sheet_OccupationStage_s::write_to_pbmsg(::proto_ff::Sheet_OccupationStage & msg) const {
	for(int32_t i = 0; i < (int32_t)E_OccupationStage_List.size(); ++i) {
		::proto_ff::E_OccupationStage* temp_e_occupationstage_list = msg.add_e_occupationstage_list();
		E_OccupationStage_List[i].write_to_pbmsg(*temp_e_occupationstage_list);
	}
}

void Sheet_OccupationStage_s::read_from_pbmsg(const ::proto_ff::Sheet_OccupationStage & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_OccupationStage_s));
	E_OccupationStage_List.resize((int)msg.e_occupationstage_list_size() > (int)E_OccupationStage_List.max_size() ? E_OccupationStage_List.max_size() : msg.e_occupationstage_list_size());
	for(int32_t i = 0; i < (int32_t)E_OccupationStage_List.size(); ++i) {
		const ::proto_ff::E_OccupationStage & temp_e_occupationstage_list = msg.e_occupationstage_list(i);
		E_OccupationStage_List[i].read_from_pbmsg(temp_e_occupationstage_list);
	}
}

E_OccupationAttributeAttributeDesc_s::E_OccupationAttributeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_OccupationAttributeAttributeDesc_s::CreateInit() {
	m_item = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_OccupationAttributeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_OccupationAttributeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_OccupationAttributeAttributeDesc & msg) const {
	msg.set_m_item((int32_t)m_item);
	msg.set_m_value((int32_t)m_value);
}

void E_OccupationAttributeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_OccupationAttributeAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_OccupationAttributeAttributeDesc_s));
	m_item = msg.m_item();
	m_value = msg.m_value();
}

E_OccupationAttribute_s::E_OccupationAttribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_OccupationAttribute_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_OccupationAttribute_s::ResumeInit() {
	return 0;
}

void E_OccupationAttribute_s::write_to_pbmsg(::proto_ff::E_OccupationAttribute & msg) const {
	msg.set_m_id((int32_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_OccupationAttributeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_OccupationAttribute_s::read_from_pbmsg(const ::proto_ff::E_OccupationAttribute & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_OccupationAttribute_s));
	m_id = msg.m_id();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_OccupationAttributeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_OccupationAttribute_s::Sheet_OccupationAttribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_OccupationAttribute_s::CreateInit() {
	return 0;
}

int Sheet_OccupationAttribute_s::ResumeInit() {
	return 0;
}

void Sheet_OccupationAttribute_s::write_to_pbmsg(::proto_ff::Sheet_OccupationAttribute & msg) const {
	for(int32_t i = 0; i < (int32_t)E_OccupationAttribute_List.size(); ++i) {
		::proto_ff::E_OccupationAttribute* temp_e_occupationattribute_list = msg.add_e_occupationattribute_list();
		E_OccupationAttribute_List[i].write_to_pbmsg(*temp_e_occupationattribute_list);
	}
}

void Sheet_OccupationAttribute_s::read_from_pbmsg(const ::proto_ff::Sheet_OccupationAttribute & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_OccupationAttribute_s));
	E_OccupationAttribute_List.resize((int)msg.e_occupationattribute_list_size() > (int)E_OccupationAttribute_List.max_size() ? E_OccupationAttribute_List.max_size() : msg.e_occupationattribute_list_size());
	for(int32_t i = 0; i < (int32_t)E_OccupationAttribute_List.size(); ++i) {
		const ::proto_ff::E_OccupationAttribute & temp_e_occupationattribute_list = msg.e_occupationattribute_list(i);
		E_OccupationAttribute_List[i].read_from_pbmsg(temp_e_occupationattribute_list);
	}
}

E_OccupationSoulAttributeDesc_s::E_OccupationSoulAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_OccupationSoulAttributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_OccupationSoulAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_OccupationSoulAttributeDesc_s::write_to_pbmsg(::proto_ff::E_OccupationSoulAttributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_OccupationSoulAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_OccupationSoulAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_OccupationSoulAttributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_OccupationSoul_s::E_OccupationSoul_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_OccupationSoul_s::CreateInit() {
	m_id = (int32_t)0;
	m_soultpye = (int32_t)0;
	m_position = (int32_t)0;
	return 0;
}

int E_OccupationSoul_s::ResumeInit() {
	return 0;
}

void E_OccupationSoul_s::write_to_pbmsg(::proto_ff::E_OccupationSoul & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_soultpye((int32_t)m_soultpye);
	msg.set_m_position((int32_t)m_position);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_OccupationSoulAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_OccupationSoul_s::read_from_pbmsg(const ::proto_ff::E_OccupationSoul & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_OccupationSoul_s));
	m_id = msg.m_id();
	m_soultpye = msg.m_soultpye();
	m_position = msg.m_position();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_OccupationSoulAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_OccupationSoul_s::Sheet_OccupationSoul_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_OccupationSoul_s::CreateInit() {
	return 0;
}

int Sheet_OccupationSoul_s::ResumeInit() {
	return 0;
}

void Sheet_OccupationSoul_s::write_to_pbmsg(::proto_ff::Sheet_OccupationSoul & msg) const {
	for(int32_t i = 0; i < (int32_t)E_OccupationSoul_List.size(); ++i) {
		::proto_ff::E_OccupationSoul* temp_e_occupationsoul_list = msg.add_e_occupationsoul_list();
		E_OccupationSoul_List[i].write_to_pbmsg(*temp_e_occupationsoul_list);
	}
}

void Sheet_OccupationSoul_s::read_from_pbmsg(const ::proto_ff::Sheet_OccupationSoul & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_OccupationSoul_s));
	E_OccupationSoul_List.resize((int)msg.e_occupationsoul_list_size() > (int)E_OccupationSoul_List.max_size() ? E_OccupationSoul_List.max_size() : msg.e_occupationsoul_list_size());
	for(int32_t i = 0; i < (int32_t)E_OccupationSoul_List.size(); ++i) {
		const ::proto_ff::E_OccupationSoul & temp_e_occupationsoul_list = msg.e_occupationsoul_list(i);
		E_OccupationSoul_List[i].read_from_pbmsg(temp_e_occupationsoul_list);
	}
}

}