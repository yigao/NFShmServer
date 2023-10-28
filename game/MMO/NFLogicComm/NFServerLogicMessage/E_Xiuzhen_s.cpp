#include "E_Xiuzhen_s.h"

namespace proto_ff_s {

E_XiuzhenStagesItemDesc_s::E_XiuzhenStagesItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenStagesItemDesc_s::CreateInit() {
	m_num = (int64_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenStagesItemDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenStagesItemDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenStagesItemDesc & msg) const {
	msg.set_m_num((int64_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenStagesItemDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenStagesItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_XiuzhenStagesSkillDesc_s::E_XiuzhenStagesSkillDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenStagesSkillDesc_s::CreateInit() {
	m_lv = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenStagesSkillDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenStagesSkillDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenStagesSkillDesc & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenStagesSkillDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenStagesSkillDesc & msg) {
	m_lv = msg.m_lv();
	m_id = msg.m_id();
}

E_XiuzhenStagesAttributeDesc_s::E_XiuzhenStagesAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenStagesAttributeDesc_s::CreateInit() {
	m_value = (int64_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenStagesAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenStagesAttributeDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenStagesAttributeDesc & msg) const {
	msg.set_m_value((int64_t)m_value);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenStagesAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenStagesAttributeDesc & msg) {
	m_value = msg.m_value();
	m_id = msg.m_id();
}

E_XiuzhenStages_s::E_XiuzhenStages_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenStages_s::CreateInit() {
	m_id = (int32_t)0;
	m_success_rate = (int32_t)0;
	m_blessing = (int32_t)0;
	return 0;
}

int E_XiuzhenStages_s::ResumeInit() {
	return 0;
}

void E_XiuzhenStages_s::write_to_pbmsg(::proto_ff::E_XiuzhenStages & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_success_rate((int32_t)m_success_rate);
	msg.set_m_blessing((int32_t)m_blessing);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_XiuzhenStagesItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		::proto_ff::E_XiuzhenStagesSkillDesc* temp_m_skill = msg.add_m_skill();
		m_skill[i].write_to_pbmsg(*temp_m_skill);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_XiuzhenStagesAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_XiuzhenStages_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenStages & msg) {
	m_id = msg.m_id();
	m_success_rate = msg.m_success_rate();
	m_blessing = msg.m_blessing();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_XiuzhenStagesItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
	m_skill.resize((int)msg.m_skill_size() > (int)m_skill.max_size() ? m_skill.max_size() : msg.m_skill_size());
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		const ::proto_ff::E_XiuzhenStagesSkillDesc & temp_m_skill = msg.m_skill(i);
		m_skill[i].read_from_pbmsg(temp_m_skill);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_XiuzhenStagesAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_XiuzhenStages_s::Sheet_XiuzhenStages_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenStages_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenStages_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenStages_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenStages & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenStages_List.size(); ++i) {
		::proto_ff::E_XiuzhenStages* temp_e_xiuzhenstages_list = msg.add_e_xiuzhenstages_list();
		E_XiuzhenStages_List[i].write_to_pbmsg(*temp_e_xiuzhenstages_list);
	}
}

void Sheet_XiuzhenStages_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenStages & msg) {
	E_XiuzhenStages_List.resize((int)msg.e_xiuzhenstages_list_size() > (int)E_XiuzhenStages_List.max_size() ? E_XiuzhenStages_List.max_size() : msg.e_xiuzhenstages_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenStages_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenStages & temp_e_xiuzhenstages_list = msg.e_xiuzhenstages_list(i);
		E_XiuzhenStages_List[i].read_from_pbmsg(temp_e_xiuzhenstages_list);
	}
}

E_XiuzhenGb_areas_s::E_XiuzhenGb_areas_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenGb_areas_s::CreateInit() {
	m_id = (int32_t)0;
	m_body_lv = (int32_t)0;
	m_enter_item = (int32_t)0;
	m_enter_item_num = (int32_t)0;
	m_enter_rate = (int32_t)0;
	m_energy_addmin = (int32_t)0;
	m_energy_addmax = (int32_t)0;
	m_energy_min = (int32_t)0;
	m_energy_max = (int32_t)0;
	m_eventrate = (int32_t)0;
	m_eventrateenergyadd = (int32_t)0;
	m_eventgetitemsrate = (int32_t)0;
	return 0;
}

int E_XiuzhenGb_areas_s::ResumeInit() {
	return 0;
}

void E_XiuzhenGb_areas_s::write_to_pbmsg(::proto_ff::E_XiuzhenGb_areas & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_subarea(m_subarea.data());
	msg.set_m_body_lv((int32_t)m_body_lv);
	msg.set_m_enter_item((int32_t)m_enter_item);
	msg.set_m_enter_item_num((int32_t)m_enter_item_num);
	msg.set_m_enter_rate((int32_t)m_enter_rate);
	msg.set_m_energy_addmin((int32_t)m_energy_addmin);
	msg.set_m_energy_addmax((int32_t)m_energy_addmax);
	msg.set_m_energy_min((int32_t)m_energy_min);
	msg.set_m_energy_max((int32_t)m_energy_max);
	msg.set_m_eventrate((int32_t)m_eventrate);
	msg.set_m_eventrateenergyadd((int32_t)m_eventrateenergyadd);
	msg.set_m_eventgetitemsrate((int32_t)m_eventgetitemsrate);
}

void E_XiuzhenGb_areas_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenGb_areas & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_subarea = msg.m_subarea();
	m_body_lv = msg.m_body_lv();
	m_enter_item = msg.m_enter_item();
	m_enter_item_num = msg.m_enter_item_num();
	m_enter_rate = msg.m_enter_rate();
	m_energy_addmin = msg.m_energy_addmin();
	m_energy_addmax = msg.m_energy_addmax();
	m_energy_min = msg.m_energy_min();
	m_energy_max = msg.m_energy_max();
	m_eventrate = msg.m_eventrate();
	m_eventrateenergyadd = msg.m_eventrateenergyadd();
	m_eventgetitemsrate = msg.m_eventgetitemsrate();
}

Sheet_XiuzhenGb_areas_s::Sheet_XiuzhenGb_areas_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenGb_areas_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenGb_areas_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenGb_areas_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenGb_areas & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenGb_areas_List.size(); ++i) {
		::proto_ff::E_XiuzhenGb_areas* temp_e_xiuzhengb_areas_list = msg.add_e_xiuzhengb_areas_list();
		E_XiuzhenGb_areas_List[i].write_to_pbmsg(*temp_e_xiuzhengb_areas_list);
	}
}

void Sheet_XiuzhenGb_areas_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenGb_areas & msg) {
	E_XiuzhenGb_areas_List.resize((int)msg.e_xiuzhengb_areas_list_size() > (int)E_XiuzhenGb_areas_List.max_size() ? E_XiuzhenGb_areas_List.max_size() : msg.e_xiuzhengb_areas_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenGb_areas_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenGb_areas & temp_e_xiuzhengb_areas_list = msg.e_xiuzhengb_areas_list(i);
		E_XiuzhenGb_areas_List[i].read_from_pbmsg(temp_e_xiuzhengb_areas_list);
	}
}

E_XiuzhenGb_area_eventsItemDesc_s::E_XiuzhenGb_area_eventsItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenGb_area_eventsItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int64_t)0;
	return 0;
}

int E_XiuzhenGb_area_eventsItemDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenGb_area_eventsItemDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenGb_area_eventsItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int64_t)m_id);
}

void E_XiuzhenGb_area_eventsItemDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenGb_area_eventsItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_XiuzhenGb_area_events_s::E_XiuzhenGb_area_events_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenGb_area_events_s::CreateInit() {
	m_id = (int64_t)0;
	m_areaid = (int64_t)0;
	m_rate = (int32_t)0;
	m_type = (int32_t)0;
	m_bodylvl = (int32_t)0;
	m_energyadd = (int32_t)0;
	return 0;
}

int E_XiuzhenGb_area_events_s::ResumeInit() {
	return 0;
}

void E_XiuzhenGb_area_events_s::write_to_pbmsg(::proto_ff::E_XiuzhenGb_area_events & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_areaid((int64_t)m_areaid);
	msg.set_m_rate((int32_t)m_rate);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_bodylvl((int32_t)m_bodylvl);
	msg.set_m_chattitle(m_chattitle.data());
	msg.set_m_chats(m_chats.data());
	msg.set_m_chatbgf(m_chatbgf.data());
	msg.set_m_chatbgm(m_chatbgm.data());
	msg.set_m_energyadd((int32_t)m_energyadd);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_XiuzhenGb_area_eventsItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_XiuzhenGb_area_events_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenGb_area_events & msg) {
	m_id = msg.m_id();
	m_areaid = msg.m_areaid();
	m_rate = msg.m_rate();
	m_type = msg.m_type();
	m_bodylvl = msg.m_bodylvl();
	m_chattitle = msg.m_chattitle();
	m_chats = msg.m_chats();
	m_chatbgf = msg.m_chatbgf();
	m_chatbgm = msg.m_chatbgm();
	m_energyadd = msg.m_energyadd();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_XiuzhenGb_area_eventsItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
}

Sheet_XiuzhenGb_area_events_s::Sheet_XiuzhenGb_area_events_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenGb_area_events_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenGb_area_events_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenGb_area_events_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenGb_area_events & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenGb_area_events_List.size(); ++i) {
		::proto_ff::E_XiuzhenGb_area_events* temp_e_xiuzhengb_area_events_list = msg.add_e_xiuzhengb_area_events_list();
		E_XiuzhenGb_area_events_List[i].write_to_pbmsg(*temp_e_xiuzhengb_area_events_list);
	}
}

void Sheet_XiuzhenGb_area_events_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenGb_area_events & msg) {
	E_XiuzhenGb_area_events_List.resize((int)msg.e_xiuzhengb_area_events_list_size() > (int)E_XiuzhenGb_area_events_List.max_size() ? E_XiuzhenGb_area_events_List.max_size() : msg.e_xiuzhengb_area_events_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenGb_area_events_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenGb_area_events & temp_e_xiuzhengb_area_events_list = msg.e_xiuzhengb_area_events_list(i);
		E_XiuzhenGb_area_events_List[i].read_from_pbmsg(temp_e_xiuzhengb_area_events_list);
	}
}

E_XiuzhenGb_lvlupItemDesc_s::E_XiuzhenGb_lvlupItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenGb_lvlupItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenGb_lvlupItemDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenGb_lvlupItemDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenGb_lvlupItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenGb_lvlupItemDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenGb_lvlupItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_XiuzhenGb_lvlupAttributeDesc_s::E_XiuzhenGb_lvlupAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenGb_lvlupAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenGb_lvlupAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenGb_lvlupAttributeDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenGb_lvlupAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenGb_lvlupAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenGb_lvlupAttributeDesc & msg) {
	m_value = msg.m_value();
	m_id = msg.m_id();
}

E_XiuzhenGb_lvlup_s::E_XiuzhenGb_lvlup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenGb_lvlup_s::CreateInit() {
	m_id = (int32_t)0;
	m_needenergy = (int32_t)0;
	return 0;
}

int E_XiuzhenGb_lvlup_s::ResumeInit() {
	return 0;
}

void E_XiuzhenGb_lvlup_s::write_to_pbmsg(::proto_ff::E_XiuzhenGb_lvlup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_needenergy((int32_t)m_needenergy);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_XiuzhenGb_lvlupItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_XiuzhenGb_lvlupAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_XiuzhenGb_lvlup_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenGb_lvlup & msg) {
	m_id = msg.m_id();
	m_needenergy = msg.m_needenergy();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_XiuzhenGb_lvlupItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_XiuzhenGb_lvlupAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_XiuzhenGb_lvlup_s::Sheet_XiuzhenGb_lvlup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenGb_lvlup_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenGb_lvlup_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenGb_lvlup_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenGb_lvlup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenGb_lvlup_List.size(); ++i) {
		::proto_ff::E_XiuzhenGb_lvlup* temp_e_xiuzhengb_lvlup_list = msg.add_e_xiuzhengb_lvlup_list();
		E_XiuzhenGb_lvlup_List[i].write_to_pbmsg(*temp_e_xiuzhengb_lvlup_list);
	}
}

void Sheet_XiuzhenGb_lvlup_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenGb_lvlup & msg) {
	E_XiuzhenGb_lvlup_List.resize((int)msg.e_xiuzhengb_lvlup_list_size() > (int)E_XiuzhenGb_lvlup_List.max_size() ? E_XiuzhenGb_lvlup_List.max_size() : msg.e_xiuzhengb_lvlup_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenGb_lvlup_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenGb_lvlup & temp_e_xiuzhengb_lvlup_list = msg.e_xiuzhengb_lvlup_list(i);
		E_XiuzhenGb_lvlup_List[i].read_from_pbmsg(temp_e_xiuzhengb_lvlup_list);
	}
}

E_XiuzhenEvolveItemDesc_s::E_XiuzhenEvolveItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenEvolveItemDesc_s::CreateInit() {
	m_num = (int64_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenEvolveItemDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenEvolveItemDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenEvolveItemDesc & msg) const {
	msg.set_m_num((int64_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenEvolveItemDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenEvolveItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_XiuzhenEvolveAttributeDesc_s::E_XiuzhenEvolveAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenEvolveAttributeDesc_s::CreateInit() {
	m_value = (int64_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenEvolveAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenEvolveAttributeDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenEvolveAttributeDesc & msg) const {
	msg.set_m_value((int64_t)m_value);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenEvolveAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenEvolveAttributeDesc & msg) {
	m_value = msg.m_value();
	m_id = msg.m_id();
}

E_XiuzhenEvolve_s::E_XiuzhenEvolve_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenEvolve_s::CreateInit() {
	m_id = (int32_t)0;
	m_needxw = (int64_t)0;
	m_success_rate = (int32_t)0;
	m_blessing = (int32_t)0;
	m_specialattriid = (int32_t)0;
	m_specialattrivalue = (int64_t)0;
	m_linggen = (int32_t)0;
	return 0;
}

int E_XiuzhenEvolve_s::ResumeInit() {
	return 0;
}

void E_XiuzhenEvolve_s::write_to_pbmsg(::proto_ff::E_XiuzhenEvolve & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_needxw((int64_t)m_needxw);
	msg.set_m_success_rate((int32_t)m_success_rate);
	msg.set_m_blessing((int32_t)m_blessing);
	msg.set_m_specialattriid((int32_t)m_specialattriid);
	msg.set_m_specialattrivalue((int64_t)m_specialattrivalue);
	msg.set_m_linggen((int32_t)m_linggen);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_XiuzhenEvolveItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_XiuzhenEvolveAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_XiuzhenEvolve_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenEvolve & msg) {
	m_id = msg.m_id();
	m_needxw = msg.m_needxw();
	m_success_rate = msg.m_success_rate();
	m_blessing = msg.m_blessing();
	m_specialattriid = msg.m_specialattriid();
	m_specialattrivalue = msg.m_specialattrivalue();
	m_linggen = msg.m_linggen();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_XiuzhenEvolveItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_XiuzhenEvolveAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_XiuzhenEvolve_s::Sheet_XiuzhenEvolve_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenEvolve_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenEvolve_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenEvolve_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenEvolve & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenEvolve_List.size(); ++i) {
		::proto_ff::E_XiuzhenEvolve* temp_e_xiuzhenevolve_list = msg.add_e_xiuzhenevolve_list();
		E_XiuzhenEvolve_List[i].write_to_pbmsg(*temp_e_xiuzhenevolve_list);
	}
}

void Sheet_XiuzhenEvolve_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenEvolve & msg) {
	E_XiuzhenEvolve_List.resize((int)msg.e_xiuzhenevolve_list_size() > (int)E_XiuzhenEvolve_List.max_size() ? E_XiuzhenEvolve_List.max_size() : msg.e_xiuzhenevolve_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenEvolve_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenEvolve & temp_e_xiuzhenevolve_list = msg.e_xiuzhenevolve_list(i);
		E_XiuzhenEvolve_List[i].read_from_pbmsg(temp_e_xiuzhenevolve_list);
	}
}

E_XiuzhenLgtypesAttriDesc_s::E_XiuzhenLgtypesAttriDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenLgtypesAttriDesc_s::CreateInit() {
	m_epa = (int32_t)0;
	m_np = (int32_t)0;
	m_value = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenLgtypesAttriDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenLgtypesAttriDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenLgtypesAttriDesc & msg) const {
	msg.set_m_epa((int32_t)m_epa);
	msg.set_m_np((int32_t)m_np);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenLgtypesAttriDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenLgtypesAttriDesc & msg) {
	m_epa = msg.m_epa();
	m_np = msg.m_np();
	m_value = msg.m_value();
	m_id = msg.m_id();
}

E_XiuzhenLgtypesLgattDesc_s::E_XiuzhenLgtypesLgattDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenLgtypesLgattDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_lim = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_XiuzhenLgtypesLgattDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenLgtypesLgattDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenLgtypesLgattDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_lim((int32_t)m_lim);
	msg.set_m_type((int32_t)m_type);
}

void E_XiuzhenLgtypesLgattDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenLgtypesLgattDesc & msg) {
	m_value = msg.m_value();
	m_lim = msg.m_lim();
	m_type = msg.m_type();
}

E_XiuzhenLgtypes_s::E_XiuzhenLgtypes_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenLgtypes_s::CreateInit() {
	m_id = (int32_t)0;
	m_unlockbook = (int32_t)0;
	m_bookcount = (int32_t)0;
	m_addpoints = (int32_t)0;
	return 0;
}

int E_XiuzhenLgtypes_s::ResumeInit() {
	return 0;
}

void E_XiuzhenLgtypes_s::write_to_pbmsg(::proto_ff::E_XiuzhenLgtypes & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_shortname(m_shortname.data());
	msg.set_m_namecolor(m_namecolor.data());
	msg.set_m_bookmodel(m_bookmodel.data());
	msg.set_m_bodymodel(m_bodymodel.data());
	msg.set_m_unlockbook((int32_t)m_unlockbook);
	msg.set_m_bookcount((int32_t)m_bookcount);
	msg.set_m_addpoints((int32_t)m_addpoints);
	for(int32_t i = 0; i < (int32_t)m_attri.size(); ++i) {
		::proto_ff::E_XiuzhenLgtypesAttriDesc* temp_m_attri = msg.add_m_attri();
		m_attri[i].write_to_pbmsg(*temp_m_attri);
	}
	for(int32_t i = 0; i < (int32_t)m_lgatt.size(); ++i) {
		::proto_ff::E_XiuzhenLgtypesLgattDesc* temp_m_lgatt = msg.add_m_lgatt();
		m_lgatt[i].write_to_pbmsg(*temp_m_lgatt);
	}
}

void E_XiuzhenLgtypes_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenLgtypes & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_shortname = msg.m_shortname();
	m_namecolor = msg.m_namecolor();
	m_bookmodel = msg.m_bookmodel();
	m_bodymodel = msg.m_bodymodel();
	m_unlockbook = msg.m_unlockbook();
	m_bookcount = msg.m_bookcount();
	m_addpoints = msg.m_addpoints();
	m_attri.resize((int)msg.m_attri_size() > (int)m_attri.max_size() ? m_attri.max_size() : msg.m_attri_size());
	for(int32_t i = 0; i < (int32_t)m_attri.size(); ++i) {
		const ::proto_ff::E_XiuzhenLgtypesAttriDesc & temp_m_attri = msg.m_attri(i);
		m_attri[i].read_from_pbmsg(temp_m_attri);
	}
	m_lgatt.resize((int)msg.m_lgatt_size() > (int)m_lgatt.max_size() ? m_lgatt.max_size() : msg.m_lgatt_size());
	for(int32_t i = 0; i < (int32_t)m_lgatt.size(); ++i) {
		const ::proto_ff::E_XiuzhenLgtypesLgattDesc & temp_m_lgatt = msg.m_lgatt(i);
		m_lgatt[i].read_from_pbmsg(temp_m_lgatt);
	}
}

Sheet_XiuzhenLgtypes_s::Sheet_XiuzhenLgtypes_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenLgtypes_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenLgtypes_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenLgtypes_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenLgtypes & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenLgtypes_List.size(); ++i) {
		::proto_ff::E_XiuzhenLgtypes* temp_e_xiuzhenlgtypes_list = msg.add_e_xiuzhenlgtypes_list();
		E_XiuzhenLgtypes_List[i].write_to_pbmsg(*temp_e_xiuzhenlgtypes_list);
	}
}

void Sheet_XiuzhenLgtypes_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenLgtypes & msg) {
	E_XiuzhenLgtypes_List.resize((int)msg.e_xiuzhenlgtypes_list_size() > (int)E_XiuzhenLgtypes_List.max_size() ? E_XiuzhenLgtypes_List.max_size() : msg.e_xiuzhenlgtypes_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenLgtypes_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenLgtypes & temp_e_xiuzhenlgtypes_list = msg.e_xiuzhenlgtypes_list(i);
		E_XiuzhenLgtypes_List[i].read_from_pbmsg(temp_e_xiuzhenlgtypes_list);
	}
}

E_XiuzhenLglvlup_s::E_XiuzhenLglvlup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenLglvlup_s::CreateInit() {
	m_id = (int32_t)0;
	m_needxw = (int64_t)0;
	return 0;
}

int E_XiuzhenLglvlup_s::ResumeInit() {
	return 0;
}

void E_XiuzhenLglvlup_s::write_to_pbmsg(::proto_ff::E_XiuzhenLglvlup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_needxw((int64_t)m_needxw);
}

void E_XiuzhenLglvlup_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenLglvlup & msg) {
	m_id = msg.m_id();
	m_needxw = msg.m_needxw();
}

Sheet_XiuzhenLglvlup_s::Sheet_XiuzhenLglvlup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenLglvlup_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenLglvlup_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenLglvlup_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenLglvlup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenLglvlup_List.size(); ++i) {
		::proto_ff::E_XiuzhenLglvlup* temp_e_xiuzhenlglvlup_list = msg.add_e_xiuzhenlglvlup_list();
		E_XiuzhenLglvlup_List[i].write_to_pbmsg(*temp_e_xiuzhenlglvlup_list);
	}
}

void Sheet_XiuzhenLglvlup_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenLglvlup & msg) {
	E_XiuzhenLglvlup_List.resize((int)msg.e_xiuzhenlglvlup_list_size() > (int)E_XiuzhenLglvlup_List.max_size() ? E_XiuzhenLglvlup_List.max_size() : msg.e_xiuzhenlglvlup_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenLglvlup_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenLglvlup & temp_e_xiuzhenlglvlup_list = msg.e_xiuzhenlglvlup_list(i);
		E_XiuzhenLglvlup_List[i].read_from_pbmsg(temp_e_xiuzhenlglvlup_list);
	}
}

E_XiuzhenLgpotionsLgDesc_s::E_XiuzhenLgpotionsLgDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenLgpotionsLgDesc_s::CreateInit() {
	m_value = (int64_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_XiuzhenLgpotionsLgDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenLgpotionsLgDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenLgpotionsLgDesc & msg) const {
	msg.set_m_value((int64_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_XiuzhenLgpotionsLgDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenLgpotionsLgDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_XiuzhenLgpotions_s::E_XiuzhenLgpotions_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenLgpotions_s::CreateInit() {
	m_id = (int64_t)0;
	return 0;
}

int E_XiuzhenLgpotions_s::ResumeInit() {
	return 0;
}

void E_XiuzhenLgpotions_s::write_to_pbmsg(::proto_ff::E_XiuzhenLgpotions & msg) const {
	msg.set_m_id((int64_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_lg.size(); ++i) {
		::proto_ff::E_XiuzhenLgpotionsLgDesc* temp_m_lg = msg.add_m_lg();
		m_lg[i].write_to_pbmsg(*temp_m_lg);
	}
}

void E_XiuzhenLgpotions_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenLgpotions & msg) {
	m_id = msg.m_id();
	m_lg.resize((int)msg.m_lg_size() > (int)m_lg.max_size() ? m_lg.max_size() : msg.m_lg_size());
	for(int32_t i = 0; i < (int32_t)m_lg.size(); ++i) {
		const ::proto_ff::E_XiuzhenLgpotionsLgDesc & temp_m_lg = msg.m_lg(i);
		m_lg[i].read_from_pbmsg(temp_m_lg);
	}
}

Sheet_XiuzhenLgpotions_s::Sheet_XiuzhenLgpotions_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenLgpotions_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenLgpotions_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenLgpotions_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenLgpotions & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenLgpotions_List.size(); ++i) {
		::proto_ff::E_XiuzhenLgpotions* temp_e_xiuzhenlgpotions_list = msg.add_e_xiuzhenlgpotions_list();
		E_XiuzhenLgpotions_List[i].write_to_pbmsg(*temp_e_xiuzhenlgpotions_list);
	}
}

void Sheet_XiuzhenLgpotions_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenLgpotions & msg) {
	E_XiuzhenLgpotions_List.resize((int)msg.e_xiuzhenlgpotions_list_size() > (int)E_XiuzhenLgpotions_List.max_size() ? E_XiuzhenLgpotions_List.max_size() : msg.e_xiuzhenlgpotions_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenLgpotions_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenLgpotions & temp_e_xiuzhenlgpotions_list = msg.e_xiuzhenlgpotions_list(i);
		E_XiuzhenLgpotions_List[i].read_from_pbmsg(temp_e_xiuzhenlgpotions_list);
	}
}

E_XiuzhenGftypes_s::E_XiuzhenGftypes_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenGftypes_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_activationitem = (int32_t)0;
	m_itemnum = (int32_t)0;
	m_buylv = (int32_t)0;
	m_rechargeid = (int32_t)0;
	return 0;
}

int E_XiuzhenGftypes_s::ResumeInit() {
	return 0;
}

void E_XiuzhenGftypes_s::write_to_pbmsg(::proto_ff::E_XiuzhenGftypes & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_name(m_name.data());
	msg.set_m_icon(m_icon.data());
	msg.set_m_activationitem((int32_t)m_activationitem);
	msg.set_m_itemnum((int32_t)m_itemnum);
	msg.set_m_buylv((int32_t)m_buylv);
	msg.set_m_rechargeid((int32_t)m_rechargeid);
	msg.set_m_bookmodel(m_bookmodel.data());
}

void E_XiuzhenGftypes_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenGftypes & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_name = msg.m_name();
	m_icon = msg.m_icon();
	m_activationitem = msg.m_activationitem();
	m_itemnum = msg.m_itemnum();
	m_buylv = msg.m_buylv();
	m_rechargeid = msg.m_rechargeid();
	m_bookmodel = msg.m_bookmodel();
}

Sheet_XiuzhenGftypes_s::Sheet_XiuzhenGftypes_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenGftypes_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenGftypes_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenGftypes_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenGftypes & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenGftypes_List.size(); ++i) {
		::proto_ff::E_XiuzhenGftypes* temp_e_xiuzhengftypes_list = msg.add_e_xiuzhengftypes_list();
		E_XiuzhenGftypes_List[i].write_to_pbmsg(*temp_e_xiuzhengftypes_list);
	}
}

void Sheet_XiuzhenGftypes_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenGftypes & msg) {
	E_XiuzhenGftypes_List.resize((int)msg.e_xiuzhengftypes_list_size() > (int)E_XiuzhenGftypes_List.max_size() ? E_XiuzhenGftypes_List.max_size() : msg.e_xiuzhengftypes_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenGftypes_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenGftypes & temp_e_xiuzhengftypes_list = msg.e_xiuzhengftypes_list(i);
		E_XiuzhenGftypes_List[i].read_from_pbmsg(temp_e_xiuzhengftypes_list);
	}
}

E_XiuzhenGflvlupAttributeDesc_s::E_XiuzhenGflvlupAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenGflvlupAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenGflvlupAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenGflvlupAttributeDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenGflvlupAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenGflvlupAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenGflvlupAttributeDesc & msg) {
	m_value = msg.m_value();
	m_id = msg.m_id();
}

E_XiuzhenGflvlup_s::E_XiuzhenGflvlup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenGflvlup_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_first_level = (int32_t)0;
	m_middle_level = (int32_t)0;
	m_high_level = (int32_t)0;
	m_roushen_level = (int32_t)0;
	m_itemid = (int32_t)0;
	m_itemnum = (int32_t)0;
	m_xw = (int32_t)0;
	m_awakeskill = (int32_t)0;
	m_awakeskilllvl = (int32_t)0;
	m_specialattriid = (int32_t)0;
	m_specialattrivalue = (int32_t)0;
	return 0;
}

int E_XiuzhenGflvlup_s::ResumeInit() {
	return 0;
}

void E_XiuzhenGflvlup_s::write_to_pbmsg(::proto_ff::E_XiuzhenGflvlup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_first_level((int32_t)m_first_level);
	msg.set_m_middle_level((int32_t)m_middle_level);
	msg.set_m_high_level((int32_t)m_high_level);
	msg.set_m_roushen_level((int32_t)m_roushen_level);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_itemnum((int32_t)m_itemnum);
	msg.set_m_xw((int32_t)m_xw);
	msg.set_m_awakeskill((int32_t)m_awakeskill);
	msg.set_m_awakeskilllvl((int32_t)m_awakeskilllvl);
	msg.set_m_specialattriid((int32_t)m_specialattriid);
	msg.set_m_specialattrivalue((int32_t)m_specialattrivalue);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_XiuzhenGflvlupAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_XiuzhenGflvlup_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenGflvlup & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_first_level = msg.m_first_level();
	m_middle_level = msg.m_middle_level();
	m_high_level = msg.m_high_level();
	m_roushen_level = msg.m_roushen_level();
	m_itemid = msg.m_itemid();
	m_itemnum = msg.m_itemnum();
	m_xw = msg.m_xw();
	m_awakeskill = msg.m_awakeskill();
	m_awakeskilllvl = msg.m_awakeskilllvl();
	m_specialattriid = msg.m_specialattriid();
	m_specialattrivalue = msg.m_specialattrivalue();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_XiuzhenGflvlupAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_XiuzhenGflvlup_s::Sheet_XiuzhenGflvlup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenGflvlup_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenGflvlup_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenGflvlup_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenGflvlup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenGflvlup_List.size(); ++i) {
		::proto_ff::E_XiuzhenGflvlup* temp_e_xiuzhengflvlup_list = msg.add_e_xiuzhengflvlup_list();
		E_XiuzhenGflvlup_List[i].write_to_pbmsg(*temp_e_xiuzhengflvlup_list);
	}
}

void Sheet_XiuzhenGflvlup_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenGflvlup & msg) {
	E_XiuzhenGflvlup_List.resize((int)msg.e_xiuzhengflvlup_list_size() > (int)E_XiuzhenGflvlup_List.max_size() ? E_XiuzhenGflvlup_List.max_size() : msg.e_xiuzhengflvlup_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenGflvlup_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenGflvlup & temp_e_xiuzhengflvlup_list = msg.e_xiuzhengflvlup_list(i);
		E_XiuzhenGflvlup_List[i].read_from_pbmsg(temp_e_xiuzhengflvlup_list);
	}
}

E_XiuzhenGfstageupAttributeDesc_s::E_XiuzhenGfstageupAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenGfstageupAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenGfstageupAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenGfstageupAttributeDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenGfstageupAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenGfstageupAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenGfstageupAttributeDesc & msg) {
	m_value = msg.m_value();
	m_id = msg.m_id();
}

E_XiuzhenGfstageup_s::E_XiuzhenGfstageup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenGfstageup_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_high_level = (int32_t)0;
	m_itemid = (int32_t)0;
	m_itemnum = (int32_t)0;
	m_awakeskill1 = (int32_t)0;
	m_awakeskilllvl1 = (int32_t)0;
	m_awakeskill2 = (int32_t)0;
	m_awakeskilllvl2 = (int32_t)0;
	return 0;
}

int E_XiuzhenGfstageup_s::ResumeInit() {
	return 0;
}

void E_XiuzhenGfstageup_s::write_to_pbmsg(::proto_ff::E_XiuzhenGfstageup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_high_level((int32_t)m_high_level);
	msg.set_m_highlevel_icon(m_highlevel_icon.data());
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_itemnum((int32_t)m_itemnum);
	msg.set_m_awakeskill1((int32_t)m_awakeskill1);
	msg.set_m_awakeskilllvl1((int32_t)m_awakeskilllvl1);
	msg.set_m_awakeskill2((int32_t)m_awakeskill2);
	msg.set_m_awakeskilllvl2((int32_t)m_awakeskilllvl2);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_XiuzhenGfstageupAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_XiuzhenGfstageup_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenGfstageup & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_high_level = msg.m_high_level();
	m_highlevel_icon = msg.m_highlevel_icon();
	m_itemid = msg.m_itemid();
	m_itemnum = msg.m_itemnum();
	m_awakeskill1 = msg.m_awakeskill1();
	m_awakeskilllvl1 = msg.m_awakeskilllvl1();
	m_awakeskill2 = msg.m_awakeskill2();
	m_awakeskilllvl2 = msg.m_awakeskilllvl2();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_XiuzhenGfstageupAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_XiuzhenGfstageup_s::Sheet_XiuzhenGfstageup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenGfstageup_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenGfstageup_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenGfstageup_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenGfstageup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenGfstageup_List.size(); ++i) {
		::proto_ff::E_XiuzhenGfstageup* temp_e_xiuzhengfstageup_list = msg.add_e_xiuzhengfstageup_list();
		E_XiuzhenGfstageup_List[i].write_to_pbmsg(*temp_e_xiuzhengfstageup_list);
	}
}

void Sheet_XiuzhenGfstageup_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenGfstageup & msg) {
	E_XiuzhenGfstageup_List.resize((int)msg.e_xiuzhengfstageup_list_size() > (int)E_XiuzhenGfstageup_List.max_size() ? E_XiuzhenGfstageup_List.max_size() : msg.e_xiuzhengfstageup_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenGfstageup_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenGfstageup & temp_e_xiuzhengfstageup_list = msg.e_xiuzhengfstageup_list(i);
		E_XiuzhenGfstageup_List[i].read_from_pbmsg(temp_e_xiuzhengfstageup_list);
	}
}

E_XiuzhenJmtypes_s::E_XiuzhenJmtypes_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenJmtypes_s::CreateInit() {
	m_id = (int32_t)0;
	m_gongfa = (int32_t)0;
	return 0;
}

int E_XiuzhenJmtypes_s::ResumeInit() {
	return 0;
}

void E_XiuzhenJmtypes_s::write_to_pbmsg(::proto_ff::E_XiuzhenJmtypes & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_gongfa((int32_t)m_gongfa);
}

void E_XiuzhenJmtypes_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenJmtypes & msg) {
	m_id = msg.m_id();
	m_gongfa = msg.m_gongfa();
}

Sheet_XiuzhenJmtypes_s::Sheet_XiuzhenJmtypes_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenJmtypes_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenJmtypes_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenJmtypes_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenJmtypes & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenJmtypes_List.size(); ++i) {
		::proto_ff::E_XiuzhenJmtypes* temp_e_xiuzhenjmtypes_list = msg.add_e_xiuzhenjmtypes_list();
		E_XiuzhenJmtypes_List[i].write_to_pbmsg(*temp_e_xiuzhenjmtypes_list);
	}
}

void Sheet_XiuzhenJmtypes_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenJmtypes & msg) {
	E_XiuzhenJmtypes_List.resize((int)msg.e_xiuzhenjmtypes_list_size() > (int)E_XiuzhenJmtypes_List.max_size() ? E_XiuzhenJmtypes_List.max_size() : msg.e_xiuzhenjmtypes_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenJmtypes_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenJmtypes & temp_e_xiuzhenjmtypes_list = msg.e_xiuzhenjmtypes_list(i);
		E_XiuzhenJmtypes_List[i].read_from_pbmsg(temp_e_xiuzhenjmtypes_list);
	}
}

E_XiuzhenJmlvlupItemDesc_s::E_XiuzhenJmlvlupItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenJmlvlupItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenJmlvlupItemDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenJmlvlupItemDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenJmlvlupItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenJmlvlupItemDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenJmlvlupItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_XiuzhenJmlvlupAttributeDesc_s::E_XiuzhenJmlvlupAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenJmlvlupAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenJmlvlupAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenJmlvlupAttributeDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenJmlvlupAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenJmlvlupAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenJmlvlupAttributeDesc & msg) {
	m_value = msg.m_value();
	m_id = msg.m_id();
}

E_XiuzhenJmlvlup_s::E_XiuzhenJmlvlup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenJmlvlup_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_lvl = (int32_t)0;
	m_needxw = (int64_t)0;
	m_success_rate = (int32_t)0;
	m_specialattriid = (int32_t)0;
	m_specialattrivalue = (int32_t)0;
	return 0;
}

int E_XiuzhenJmlvlup_s::ResumeInit() {
	return 0;
}

void E_XiuzhenJmlvlup_s::write_to_pbmsg(::proto_ff::E_XiuzhenJmlvlup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_lvl((int32_t)m_lvl);
	msg.set_m_needxw((int64_t)m_needxw);
	msg.set_m_success_rate((int32_t)m_success_rate);
	msg.set_m_specialattriid((int32_t)m_specialattriid);
	msg.set_m_specialattrivalue((int32_t)m_specialattrivalue);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_XiuzhenJmlvlupItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_XiuzhenJmlvlupAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_XiuzhenJmlvlup_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenJmlvlup & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_lvl = msg.m_lvl();
	m_needxw = msg.m_needxw();
	m_success_rate = msg.m_success_rate();
	m_specialattriid = msg.m_specialattriid();
	m_specialattrivalue = msg.m_specialattrivalue();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_XiuzhenJmlvlupItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_XiuzhenJmlvlupAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_XiuzhenJmlvlup_s::Sheet_XiuzhenJmlvlup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenJmlvlup_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenJmlvlup_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenJmlvlup_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenJmlvlup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenJmlvlup_List.size(); ++i) {
		::proto_ff::E_XiuzhenJmlvlup* temp_e_xiuzhenjmlvlup_list = msg.add_e_xiuzhenjmlvlup_list();
		E_XiuzhenJmlvlup_List[i].write_to_pbmsg(*temp_e_xiuzhenjmlvlup_list);
	}
}

void Sheet_XiuzhenJmlvlup_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenJmlvlup & msg) {
	E_XiuzhenJmlvlup_List.resize((int)msg.e_xiuzhenjmlvlup_list_size() > (int)E_XiuzhenJmlvlup_List.max_size() ? E_XiuzhenJmlvlup_List.max_size() : msg.e_xiuzhenjmlvlup_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenJmlvlup_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenJmlvlup & temp_e_xiuzhenjmlvlup_list = msg.e_xiuzhenjmlvlup_list(i);
		E_XiuzhenJmlvlup_List[i].read_from_pbmsg(temp_e_xiuzhenjmlvlup_list);
	}
}

E_XiuzhenJmstageupItemDesc_s::E_XiuzhenJmstageupItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenJmstageupItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenJmstageupItemDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenJmstageupItemDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenJmstageupItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenJmstageupItemDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenJmstageupItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_XiuzhenJmstageupAttributeDesc_s::E_XiuzhenJmstageupAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenJmstageupAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenJmstageupAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenJmstageupAttributeDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenJmstageupAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenJmstageupAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenJmstageupAttributeDesc & msg) {
	m_value = msg.m_value();
	m_id = msg.m_id();
}

E_XiuzhenJmstageup_s::E_XiuzhenJmstageup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenJmstageup_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_stage = (int32_t)0;
	m_needgfunlock = (int32_t)0;
	m_success_rate = (int32_t)0;
	m_blessing = (int32_t)0;
	m_awakeskillid = (int32_t)0;
	m_awakeskilllvl = (int32_t)0;
	return 0;
}

int E_XiuzhenJmstageup_s::ResumeInit() {
	return 0;
}

void E_XiuzhenJmstageup_s::write_to_pbmsg(::proto_ff::E_XiuzhenJmstageup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_stage((int32_t)m_stage);
	msg.set_m_name(m_name.data());
	msg.set_m_needgfunlock((int32_t)m_needgfunlock);
	msg.set_m_success_rate((int32_t)m_success_rate);
	msg.set_m_blessing((int32_t)m_blessing);
	msg.set_m_awakeskillid((int32_t)m_awakeskillid);
	msg.set_m_awakeskilllvl((int32_t)m_awakeskilllvl);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_XiuzhenJmstageupItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_XiuzhenJmstageupAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_XiuzhenJmstageup_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenJmstageup & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_stage = msg.m_stage();
	m_name = msg.m_name();
	m_needgfunlock = msg.m_needgfunlock();
	m_success_rate = msg.m_success_rate();
	m_blessing = msg.m_blessing();
	m_awakeskillid = msg.m_awakeskillid();
	m_awakeskilllvl = msg.m_awakeskilllvl();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_XiuzhenJmstageupItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_XiuzhenJmstageupAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_XiuzhenJmstageup_s::Sheet_XiuzhenJmstageup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenJmstageup_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenJmstageup_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenJmstageup_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenJmstageup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenJmstageup_List.size(); ++i) {
		::proto_ff::E_XiuzhenJmstageup* temp_e_xiuzhenjmstageup_list = msg.add_e_xiuzhenjmstageup_list();
		E_XiuzhenJmstageup_List[i].write_to_pbmsg(*temp_e_xiuzhenjmstageup_list);
	}
}

void Sheet_XiuzhenJmstageup_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenJmstageup & msg) {
	E_XiuzhenJmstageup_List.resize((int)msg.e_xiuzhenjmstageup_list_size() > (int)E_XiuzhenJmstageup_List.max_size() ? E_XiuzhenJmstageup_List.max_size() : msg.e_xiuzhenjmstageup_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenJmstageup_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenJmstageup & temp_e_xiuzhenjmstageup_list = msg.e_xiuzhenjmstageup_list(i);
		E_XiuzhenJmstageup_List[i].read_from_pbmsg(temp_e_xiuzhenjmstageup_list);
	}
}

E_XiuzhenJmmergeupCsDesc_s::E_XiuzhenJmmergeupCsDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenJmmergeupCsDesc_s::CreateInit() {
	m_stage = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_XiuzhenJmmergeupCsDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenJmmergeupCsDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenJmmergeupCsDesc & msg) const {
	msg.set_m_stage((int32_t)m_stage);
	msg.set_m_type((int32_t)m_type);
}

void E_XiuzhenJmmergeupCsDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenJmmergeupCsDesc & msg) {
	m_stage = msg.m_stage();
	m_type = msg.m_type();
}

E_XiuzhenJmmergeupAttributeDesc_s::E_XiuzhenJmmergeupAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenJmmergeupAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenJmmergeupAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenJmmergeupAttributeDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenJmmergeupAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenJmmergeupAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenJmmergeupAttributeDesc & msg) {
	m_value = msg.m_value();
	m_id = msg.m_id();
}

E_XiuzhenJmmergeup_s::E_XiuzhenJmmergeup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenJmmergeup_s::CreateInit() {
	m_id = (int32_t)0;
	m_gf_type = (int32_t)0;
	m_awakeskillid = (int32_t)0;
	m_awakeskilllvl = (int32_t)0;
	return 0;
}

int E_XiuzhenJmmergeup_s::ResumeInit() {
	return 0;
}

void E_XiuzhenJmmergeup_s::write_to_pbmsg(::proto_ff::E_XiuzhenJmmergeup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_gf_type((int32_t)m_gf_type);
	msg.set_m_awakeskillid((int32_t)m_awakeskillid);
	msg.set_m_awakeskilllvl((int32_t)m_awakeskilllvl);
	for(int32_t i = 0; i < (int32_t)m_cs.size(); ++i) {
		::proto_ff::E_XiuzhenJmmergeupCsDesc* temp_m_cs = msg.add_m_cs();
		m_cs[i].write_to_pbmsg(*temp_m_cs);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_XiuzhenJmmergeupAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_XiuzhenJmmergeup_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenJmmergeup & msg) {
	m_id = msg.m_id();
	m_gf_type = msg.m_gf_type();
	m_awakeskillid = msg.m_awakeskillid();
	m_awakeskilllvl = msg.m_awakeskilllvl();
	m_cs.resize((int)msg.m_cs_size() > (int)m_cs.max_size() ? m_cs.max_size() : msg.m_cs_size());
	for(int32_t i = 0; i < (int32_t)m_cs.size(); ++i) {
		const ::proto_ff::E_XiuzhenJmmergeupCsDesc & temp_m_cs = msg.m_cs(i);
		m_cs[i].read_from_pbmsg(temp_m_cs);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_XiuzhenJmmergeupAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_XiuzhenJmmergeup_s::Sheet_XiuzhenJmmergeup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenJmmergeup_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenJmmergeup_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenJmmergeup_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenJmmergeup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenJmmergeup_List.size(); ++i) {
		::proto_ff::E_XiuzhenJmmergeup* temp_e_xiuzhenjmmergeup_list = msg.add_e_xiuzhenjmmergeup_list();
		E_XiuzhenJmmergeup_List[i].write_to_pbmsg(*temp_e_xiuzhenjmmergeup_list);
	}
}

void Sheet_XiuzhenJmmergeup_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenJmmergeup & msg) {
	E_XiuzhenJmmergeup_List.resize((int)msg.e_xiuzhenjmmergeup_list_size() > (int)E_XiuzhenJmmergeup_List.max_size() ? E_XiuzhenJmmergeup_List.max_size() : msg.e_xiuzhenjmmergeup_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenJmmergeup_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenJmmergeup & temp_e_xiuzhenjmmergeup_list = msg.e_xiuzhenjmmergeup_list(i);
		E_XiuzhenJmmergeup_List[i].read_from_pbmsg(temp_e_xiuzhenjmmergeup_list);
	}
}

E_XiuzhenPrivilegePtaddDesc_s::E_XiuzhenPrivilegePtaddDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenPrivilegePtaddDesc_s::CreateInit() {
	m_v = (int32_t)0;
	m_t = (int32_t)0;
	return 0;
}

int E_XiuzhenPrivilegePtaddDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenPrivilegePtaddDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenPrivilegePtaddDesc & msg) const {
	msg.set_m_v((int32_t)m_v);
	msg.set_m_n(m_n.data());
	msg.set_m_t((int32_t)m_t);
}

void E_XiuzhenPrivilegePtaddDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenPrivilegePtaddDesc & msg) {
	m_v = msg.m_v();
	m_n = msg.m_n();
	m_t = msg.m_t();
}

E_XiuzhenPrivilegeAttriDesc_s::E_XiuzhenPrivilegeAttriDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenPrivilegeAttriDesc_s::CreateInit() {
	m_v = (int64_t)0;
	m_t = (int32_t)0;
	return 0;
}

int E_XiuzhenPrivilegeAttriDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenPrivilegeAttriDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenPrivilegeAttriDesc & msg) const {
	msg.set_m_v((int64_t)m_v);
	msg.set_m_t((int32_t)m_t);
}

void E_XiuzhenPrivilegeAttriDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenPrivilegeAttriDesc & msg) {
	m_v = msg.m_v();
	m_t = msg.m_t();
}

E_XiuzhenPrivilege_s::E_XiuzhenPrivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenPrivilege_s::CreateInit() {
	m_id = (int32_t)0;
	m_price = (int32_t)0;
	m_activeavatar = (int32_t)0;
	return 0;
}

int E_XiuzhenPrivilege_s::ResumeInit() {
	return 0;
}

void E_XiuzhenPrivilege_s::write_to_pbmsg(::proto_ff::E_XiuzhenPrivilege & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_activeavatar((int32_t)m_activeavatar);
	msg.set_m_avatarname(m_avatarname.data());
	for(int32_t i = 0; i < (int32_t)m_ptadd.size(); ++i) {
		::proto_ff::E_XiuzhenPrivilegePtaddDesc* temp_m_ptadd = msg.add_m_ptadd();
		m_ptadd[i].write_to_pbmsg(*temp_m_ptadd);
	}
	for(int32_t i = 0; i < (int32_t)m_attri.size(); ++i) {
		::proto_ff::E_XiuzhenPrivilegeAttriDesc* temp_m_attri = msg.add_m_attri();
		m_attri[i].write_to_pbmsg(*temp_m_attri);
	}
}

void E_XiuzhenPrivilege_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenPrivilege & msg) {
	m_id = msg.m_id();
	m_price = msg.m_price();
	m_activeavatar = msg.m_activeavatar();
	m_avatarname = msg.m_avatarname();
	m_ptadd.resize((int)msg.m_ptadd_size() > (int)m_ptadd.max_size() ? m_ptadd.max_size() : msg.m_ptadd_size());
	for(int32_t i = 0; i < (int32_t)m_ptadd.size(); ++i) {
		const ::proto_ff::E_XiuzhenPrivilegePtaddDesc & temp_m_ptadd = msg.m_ptadd(i);
		m_ptadd[i].read_from_pbmsg(temp_m_ptadd);
	}
	m_attri.resize((int)msg.m_attri_size() > (int)m_attri.max_size() ? m_attri.max_size() : msg.m_attri_size());
	for(int32_t i = 0; i < (int32_t)m_attri.size(); ++i) {
		const ::proto_ff::E_XiuzhenPrivilegeAttriDesc & temp_m_attri = msg.m_attri(i);
		m_attri[i].read_from_pbmsg(temp_m_attri);
	}
}

Sheet_XiuzhenPrivilege_s::Sheet_XiuzhenPrivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenPrivilege_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenPrivilege_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenPrivilege_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenPrivilege & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenPrivilege_List.size(); ++i) {
		::proto_ff::E_XiuzhenPrivilege* temp_e_xiuzhenprivilege_list = msg.add_e_xiuzhenprivilege_list();
		E_XiuzhenPrivilege_List[i].write_to_pbmsg(*temp_e_xiuzhenprivilege_list);
	}
}

void Sheet_XiuzhenPrivilege_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenPrivilege & msg) {
	E_XiuzhenPrivilege_List.resize((int)msg.e_xiuzhenprivilege_list_size() > (int)E_XiuzhenPrivilege_List.max_size() ? E_XiuzhenPrivilege_List.max_size() : msg.e_xiuzhenprivilege_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenPrivilege_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenPrivilege & temp_e_xiuzhenprivilege_list = msg.e_xiuzhenprivilege_list(i);
		E_XiuzhenPrivilege_List[i].read_from_pbmsg(temp_e_xiuzhenprivilege_list);
	}
}

}
