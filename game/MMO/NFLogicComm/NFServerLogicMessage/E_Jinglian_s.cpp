#include "E_Jinglian_s.h"

namespace proto_ff_s {

E_JinglianSimple_s::E_JinglianSimple_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_JinglianSimple_s::CreateInit() {
	m_position = (int32_t)0;
	m_groupId = (int32_t)0;
	m_openlv = (int32_t)0;
	m_default_attrs = (int32_t)0;
	return 0;
}

int E_JinglianSimple_s::ResumeInit() {
	return 0;
}

void E_JinglianSimple_s::write_to_pbmsg(::proto_ff::E_JinglianSimple & msg) const {
	msg.set_m_position((int32_t)m_position);
	msg.set_m_groupid((int32_t)m_groupId);
	msg.set_m_openlv((int32_t)m_openlv);
	msg.set_m_default_attrs((int32_t)m_default_attrs);
	for(int32_t i = 0; i < (int32_t)m_open_attr.size(); ++i) {
		msg.add_m_open_attr((int32_t)m_open_attr[i]);
	}
}

void E_JinglianSimple_s::read_from_pbmsg(const ::proto_ff::E_JinglianSimple & msg) {
	m_position = msg.m_position();
	m_groupId = msg.m_groupid();
	m_openlv = msg.m_openlv();
	m_default_attrs = msg.m_default_attrs();
	m_open_attr.resize((int)msg.m_open_attr_size() > (int)m_open_attr.max_size() ? m_open_attr.max_size() : msg.m_open_attr_size());
	for(int32_t i = 0; i < (int32_t)m_open_attr.size(); ++i) {
		m_open_attr[i] = msg.m_open_attr(i);
	}
}

Sheet_JinglianSimple_s::Sheet_JinglianSimple_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_JinglianSimple_s::CreateInit() {
	return 0;
}

int Sheet_JinglianSimple_s::ResumeInit() {
	return 0;
}

void Sheet_JinglianSimple_s::write_to_pbmsg(::proto_ff::Sheet_JinglianSimple & msg) const {
	for(int32_t i = 0; i < (int32_t)E_JinglianSimple_List.size(); ++i) {
		::proto_ff::E_JinglianSimple* temp_e_jingliansimple_list = msg.add_e_jingliansimple_list();
		E_JinglianSimple_List[i].write_to_pbmsg(*temp_e_jingliansimple_list);
	}
}

void Sheet_JinglianSimple_s::read_from_pbmsg(const ::proto_ff::Sheet_JinglianSimple & msg) {
	E_JinglianSimple_List.resize((int)msg.e_jingliansimple_list_size() > (int)E_JinglianSimple_List.max_size() ? E_JinglianSimple_List.max_size() : msg.e_jingliansimple_list_size());
	for(int32_t i = 0; i < (int32_t)E_JinglianSimple_List.size(); ++i) {
		const ::proto_ff::E_JinglianSimple & temp_e_jingliansimple_list = msg.e_jingliansimple_list(i);
		E_JinglianSimple_List[i].read_from_pbmsg(temp_e_jingliansimple_list);
	}
}

E_JinglianLvCostDesc_s::E_JinglianLvCostDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_JinglianLvCostDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_item = (int32_t)0;
	return 0;
}

int E_JinglianLvCostDesc_s::ResumeInit() {
	return 0;
}

void E_JinglianLvCostDesc_s::write_to_pbmsg(::proto_ff::E_JinglianLvCostDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_item((int32_t)m_item);
}

void E_JinglianLvCostDesc_s::read_from_pbmsg(const ::proto_ff::E_JinglianLvCostDesc & msg) {
	m_num = msg.m_num();
	m_item = msg.m_item();
}

E_JinglianLvAttrDesc_s::E_JinglianLvAttrDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_JinglianLvAttrDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_JinglianLvAttrDesc_s::ResumeInit() {
	return 0;
}

void E_JinglianLvAttrDesc_s::write_to_pbmsg(::proto_ff::E_JinglianLvAttrDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_id((int32_t)m_id);
}

void E_JinglianLvAttrDesc_s::read_from_pbmsg(const ::proto_ff::E_JinglianLvAttrDesc & msg) {
	m_value = msg.m_value();
	m_id = msg.m_id();
}

E_JinglianLv_s::E_JinglianLv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_JinglianLv_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupId = (int32_t)0;
	m_lv = (int32_t)0;
	return 0;
}

int E_JinglianLv_s::ResumeInit() {
	return 0;
}

void E_JinglianLv_s::write_to_pbmsg(::proto_ff::E_JinglianLv & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupId);
	msg.set_m_lv((int32_t)m_lv);
	for(int32_t i = 0; i < (int32_t)m_cost.size(); ++i) {
		::proto_ff::E_JinglianLvCostDesc* temp_m_cost = msg.add_m_cost();
		m_cost[i].write_to_pbmsg(*temp_m_cost);
	}
	for(int32_t i = 0; i < (int32_t)m_attr.size(); ++i) {
		::proto_ff::E_JinglianLvAttrDesc* temp_m_attr = msg.add_m_attr();
		m_attr[i].write_to_pbmsg(*temp_m_attr);
	}
}

void E_JinglianLv_s::read_from_pbmsg(const ::proto_ff::E_JinglianLv & msg) {
	m_id = msg.m_id();
	m_groupId = msg.m_groupid();
	m_lv = msg.m_lv();
	m_cost.resize((int)msg.m_cost_size() > (int)m_cost.max_size() ? m_cost.max_size() : msg.m_cost_size());
	for(int32_t i = 0; i < (int32_t)m_cost.size(); ++i) {
		const ::proto_ff::E_JinglianLvCostDesc & temp_m_cost = msg.m_cost(i);
		m_cost[i].read_from_pbmsg(temp_m_cost);
	}
	m_attr.resize((int)msg.m_attr_size() > (int)m_attr.max_size() ? m_attr.max_size() : msg.m_attr_size());
	for(int32_t i = 0; i < (int32_t)m_attr.size(); ++i) {
		const ::proto_ff::E_JinglianLvAttrDesc & temp_m_attr = msg.m_attr(i);
		m_attr[i].read_from_pbmsg(temp_m_attr);
	}
}

Sheet_JinglianLv_s::Sheet_JinglianLv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_JinglianLv_s::CreateInit() {
	return 0;
}

int Sheet_JinglianLv_s::ResumeInit() {
	return 0;
}

void Sheet_JinglianLv_s::write_to_pbmsg(::proto_ff::Sheet_JinglianLv & msg) const {
	for(int32_t i = 0; i < (int32_t)E_JinglianLv_List.size(); ++i) {
		::proto_ff::E_JinglianLv* temp_e_jinglianlv_list = msg.add_e_jinglianlv_list();
		E_JinglianLv_List[i].write_to_pbmsg(*temp_e_jinglianlv_list);
	}
}

void Sheet_JinglianLv_s::read_from_pbmsg(const ::proto_ff::Sheet_JinglianLv & msg) {
	E_JinglianLv_List.resize((int)msg.e_jinglianlv_list_size() > (int)E_JinglianLv_List.max_size() ? E_JinglianLv_List.max_size() : msg.e_jinglianlv_list_size());
	for(int32_t i = 0; i < (int32_t)E_JinglianLv_List.size(); ++i) {
		const ::proto_ff::E_JinglianLv & temp_e_jinglianlv_list = msg.e_jinglianlv_list(i);
		E_JinglianLv_List[i].read_from_pbmsg(temp_e_jinglianlv_list);
	}
}

E_JinglianRace_s::E_JinglianRace_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_JinglianRace_s::CreateInit() {
	m_quality = (int32_t)0;
	m_min = (int32_t)0;
	m_max = (int32_t)0;
	m_quanz = (int32_t)0;
	m_min_1 = (int32_t)0;
	m_max_1 = (int32_t)0;
	m_quanz_1 = (int32_t)0;
	return 0;
}

int E_JinglianRace_s::ResumeInit() {
	return 0;
}

void E_JinglianRace_s::write_to_pbmsg(::proto_ff::E_JinglianRace & msg) const {
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_min((int32_t)m_min);
	msg.set_m_max((int32_t)m_max);
	msg.set_m_quanz((int32_t)m_quanz);
	msg.set_m_min_1((int32_t)m_min_1);
	msg.set_m_max_1((int32_t)m_max_1);
	msg.set_m_quanz_1((int32_t)m_quanz_1);
}

void E_JinglianRace_s::read_from_pbmsg(const ::proto_ff::E_JinglianRace & msg) {
	m_quality = msg.m_quality();
	m_min = msg.m_min();
	m_max = msg.m_max();
	m_quanz = msg.m_quanz();
	m_min_1 = msg.m_min_1();
	m_max_1 = msg.m_max_1();
	m_quanz_1 = msg.m_quanz_1();
}

Sheet_JinglianRace_s::Sheet_JinglianRace_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_JinglianRace_s::CreateInit() {
	return 0;
}

int Sheet_JinglianRace_s::ResumeInit() {
	return 0;
}

void Sheet_JinglianRace_s::write_to_pbmsg(::proto_ff::Sheet_JinglianRace & msg) const {
	for(int32_t i = 0; i < (int32_t)E_JinglianRace_List.size(); ++i) {
		::proto_ff::E_JinglianRace* temp_e_jinglianrace_list = msg.add_e_jinglianrace_list();
		E_JinglianRace_List[i].write_to_pbmsg(*temp_e_jinglianrace_list);
	}
}

void Sheet_JinglianRace_s::read_from_pbmsg(const ::proto_ff::Sheet_JinglianRace & msg) {
	E_JinglianRace_List.resize((int)msg.e_jinglianrace_list_size() > (int)E_JinglianRace_List.max_size() ? E_JinglianRace_List.max_size() : msg.e_jinglianrace_list_size());
	for(int32_t i = 0; i < (int32_t)E_JinglianRace_List.size(); ++i) {
		const ::proto_ff::E_JinglianRace & temp_e_jinglianrace_list = msg.e_jinglianrace_list(i);
		E_JinglianRace_List[i].read_from_pbmsg(temp_e_jinglianrace_list);
	}
}

E_JinglianCostCostDesc_s::E_JinglianCostCostDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_JinglianCostCostDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_item = (int32_t)0;
	return 0;
}

int E_JinglianCostCostDesc_s::ResumeInit() {
	return 0;
}

void E_JinglianCostCostDesc_s::write_to_pbmsg(::proto_ff::E_JinglianCostCostDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_item((int32_t)m_item);
}

void E_JinglianCostCostDesc_s::read_from_pbmsg(const ::proto_ff::E_JinglianCostCostDesc & msg) {
	m_num = msg.m_num();
	m_item = msg.m_item();
}

E_JinglianCost_s::E_JinglianCost_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_JinglianCost_s::CreateInit() {
	m_lockid = (int32_t)0;
	return 0;
}

int E_JinglianCost_s::ResumeInit() {
	return 0;
}

void E_JinglianCost_s::write_to_pbmsg(::proto_ff::E_JinglianCost & msg) const {
	msg.set_m_lockid((int32_t)m_lockid);
	for(int32_t i = 0; i < (int32_t)m_cost.size(); ++i) {
		::proto_ff::E_JinglianCostCostDesc* temp_m_cost = msg.add_m_cost();
		m_cost[i].write_to_pbmsg(*temp_m_cost);
	}
}

void E_JinglianCost_s::read_from_pbmsg(const ::proto_ff::E_JinglianCost & msg) {
	m_lockid = msg.m_lockid();
	m_cost.resize((int)msg.m_cost_size() > (int)m_cost.max_size() ? m_cost.max_size() : msg.m_cost_size());
	for(int32_t i = 0; i < (int32_t)m_cost.size(); ++i) {
		const ::proto_ff::E_JinglianCostCostDesc & temp_m_cost = msg.m_cost(i);
		m_cost[i].read_from_pbmsg(temp_m_cost);
	}
}

Sheet_JinglianCost_s::Sheet_JinglianCost_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_JinglianCost_s::CreateInit() {
	return 0;
}

int Sheet_JinglianCost_s::ResumeInit() {
	return 0;
}

void Sheet_JinglianCost_s::write_to_pbmsg(::proto_ff::Sheet_JinglianCost & msg) const {
	for(int32_t i = 0; i < (int32_t)E_JinglianCost_List.size(); ++i) {
		::proto_ff::E_JinglianCost* temp_e_jingliancost_list = msg.add_e_jingliancost_list();
		E_JinglianCost_List[i].write_to_pbmsg(*temp_e_jingliancost_list);
	}
}

void Sheet_JinglianCost_s::read_from_pbmsg(const ::proto_ff::Sheet_JinglianCost & msg) {
	E_JinglianCost_List.resize((int)msg.e_jingliancost_list_size() > (int)E_JinglianCost_List.max_size() ? E_JinglianCost_List.max_size() : msg.e_jingliancost_list_size());
	for(int32_t i = 0; i < (int32_t)E_JinglianCost_List.size(); ++i) {
		const ::proto_ff::E_JinglianCost & temp_e_jingliancost_list = msg.e_jingliancost_list(i);
		E_JinglianCost_List[i].read_from_pbmsg(temp_e_jingliancost_list);
	}
}

E_JinglianGm_s::E_JinglianGm_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_JinglianGm_s::CreateInit() {
	m_lv = (int32_t)0;
	m_lock_num = (int32_t)0;
	m_lock_quality = (int32_t)0;
	m_addval = (int32_t)0;
	return 0;
}

int E_JinglianGm_s::ResumeInit() {
	return 0;
}

void E_JinglianGm_s::write_to_pbmsg(::proto_ff::E_JinglianGm & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_lock_num((int32_t)m_lock_num);
	msg.set_m_lock_quality((int32_t)m_lock_quality);
	msg.set_m_addval((int32_t)m_addval);
}

void E_JinglianGm_s::read_from_pbmsg(const ::proto_ff::E_JinglianGm & msg) {
	m_lv = msg.m_lv();
	m_lock_num = msg.m_lock_num();
	m_lock_quality = msg.m_lock_quality();
	m_addval = msg.m_addval();
}

Sheet_JinglianGm_s::Sheet_JinglianGm_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_JinglianGm_s::CreateInit() {
	return 0;
}

int Sheet_JinglianGm_s::ResumeInit() {
	return 0;
}

void Sheet_JinglianGm_s::write_to_pbmsg(::proto_ff::Sheet_JinglianGm & msg) const {
	for(int32_t i = 0; i < (int32_t)E_JinglianGm_List.size(); ++i) {
		::proto_ff::E_JinglianGm* temp_e_jingliangm_list = msg.add_e_jingliangm_list();
		E_JinglianGm_List[i].write_to_pbmsg(*temp_e_jingliangm_list);
	}
}

void Sheet_JinglianGm_s::read_from_pbmsg(const ::proto_ff::Sheet_JinglianGm & msg) {
	E_JinglianGm_List.resize((int)msg.e_jingliangm_list_size() > (int)E_JinglianGm_List.max_size() ? E_JinglianGm_List.max_size() : msg.e_jingliangm_list_size());
	for(int32_t i = 0; i < (int32_t)E_JinglianGm_List.size(); ++i) {
		const ::proto_ff::E_JinglianGm & temp_e_jingliangm_list = msg.e_jingliangm_list(i);
		E_JinglianGm_List[i].read_from_pbmsg(temp_e_jingliangm_list);
	}
}

}
