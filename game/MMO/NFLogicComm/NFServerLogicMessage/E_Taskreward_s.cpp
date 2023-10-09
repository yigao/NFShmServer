#include "E_Taskreward_s.h"

namespace proto_ff_s {

E_TaskrewardTaskrewardAttrDesc_s::E_TaskrewardTaskrewardAttrDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TaskrewardTaskrewardAttrDesc_s::CreateInit() {
	m_val = (int64_t)0;
	m_id = (int64_t)0;
	return 0;
}

int E_TaskrewardTaskrewardAttrDesc_s::ResumeInit() {
	return 0;
}

void E_TaskrewardTaskrewardAttrDesc_s::write_to_pbmsg(::proto_ff::E_TaskrewardTaskrewardAttrDesc & msg) const {
	msg.set_m_val((int64_t)m_val);
	msg.set_m_id((int64_t)m_id);
}

void E_TaskrewardTaskrewardAttrDesc_s::read_from_pbmsg(const ::proto_ff::E_TaskrewardTaskrewardAttrDesc & msg) {
	m_val = msg.m_val();
	m_id = msg.m_id();
}

E_TaskrewardTaskrewardItemDesc_s::E_TaskrewardTaskrewardItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TaskrewardTaskrewardItemDesc_s::CreateInit() {
	m_prof = (int32_t)0;
	m_bind = (int32_t)0;
	m_val = (int32_t)0;
	m_id = (int64_t)0;
	return 0;
}

int E_TaskrewardTaskrewardItemDesc_s::ResumeInit() {
	return 0;
}

void E_TaskrewardTaskrewardItemDesc_s::write_to_pbmsg(::proto_ff::E_TaskrewardTaskrewardItemDesc & msg) const {
	msg.set_m_prof((int32_t)m_prof);
	msg.set_m_bind((int32_t)m_bind);
	msg.set_m_val((int32_t)m_val);
	msg.set_m_id((int64_t)m_id);
}

void E_TaskrewardTaskrewardItemDesc_s::read_from_pbmsg(const ::proto_ff::E_TaskrewardTaskrewardItemDesc & msg) {
	m_prof = msg.m_prof();
	m_bind = msg.m_bind();
	m_val = msg.m_val();
	m_id = msg.m_id();
}

E_TaskrewardTaskreward_s::E_TaskrewardTaskreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TaskrewardTaskreward_s::CreateInit() {
	m_id = (int64_t)0;
	m_tasktype = (int32_t)0;
	m_lv = (int32_t)0;
	m_guildexp = (int32_t)0;
	m_guildpoint = (int32_t)0;
	m_skillid = (int32_t)0;
	return 0;
}

int E_TaskrewardTaskreward_s::ResumeInit() {
	return 0;
}

void E_TaskrewardTaskreward_s::write_to_pbmsg(::proto_ff::E_TaskrewardTaskreward & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_tasktype((int32_t)m_tasktype);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_guildexp((int32_t)m_guildexp);
	msg.set_m_guildpoint((int32_t)m_guildpoint);
	msg.set_m_skillid((int32_t)m_skillid);
	for(int32_t i = 0; i < (int32_t)m_attr.size(); ++i) {
		::proto_ff::E_TaskrewardTaskrewardAttrDesc* temp_m_attr = msg.add_m_attr();
		m_attr[i].write_to_pbmsg(*temp_m_attr);
	}
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_TaskrewardTaskrewardItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_TaskrewardTaskreward_s::read_from_pbmsg(const ::proto_ff::E_TaskrewardTaskreward & msg) {
	m_id = msg.m_id();
	m_tasktype = msg.m_tasktype();
	m_lv = msg.m_lv();
	m_guildexp = msg.m_guildexp();
	m_guildpoint = msg.m_guildpoint();
	m_skillid = msg.m_skillid();
	m_attr.resize((int)msg.m_attr_size() > (int)m_attr.max_size() ? m_attr.max_size() : msg.m_attr_size());
	for(int32_t i = 0; i < (int32_t)m_attr.size(); ++i) {
		const ::proto_ff::E_TaskrewardTaskrewardAttrDesc & temp_m_attr = msg.m_attr(i);
		m_attr[i].read_from_pbmsg(temp_m_attr);
	}
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_TaskrewardTaskrewardItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
}

Sheet_TaskrewardTaskreward_s::Sheet_TaskrewardTaskreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TaskrewardTaskreward_s::CreateInit() {
	return 0;
}

int Sheet_TaskrewardTaskreward_s::ResumeInit() {
	return 0;
}

void Sheet_TaskrewardTaskreward_s::write_to_pbmsg(::proto_ff::Sheet_TaskrewardTaskreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TaskrewardTaskreward_List.size(); ++i) {
		::proto_ff::E_TaskrewardTaskreward* temp_e_taskrewardtaskreward_list = msg.add_e_taskrewardtaskreward_list();
		E_TaskrewardTaskreward_List[i].write_to_pbmsg(*temp_e_taskrewardtaskreward_list);
	}
}

void Sheet_TaskrewardTaskreward_s::read_from_pbmsg(const ::proto_ff::Sheet_TaskrewardTaskreward & msg) {
	E_TaskrewardTaskreward_List.resize((int)msg.e_taskrewardtaskreward_list_size() > (int)E_TaskrewardTaskreward_List.max_size() ? E_TaskrewardTaskreward_List.max_size() : msg.e_taskrewardtaskreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_TaskrewardTaskreward_List.size(); ++i) {
		const ::proto_ff::E_TaskrewardTaskreward & temp_e_taskrewardtaskreward_list = msg.e_taskrewardtaskreward_list(i);
		E_TaskrewardTaskreward_List[i].read_from_pbmsg(temp_e_taskrewardtaskreward_list);
	}
}

E_TaskrewardTasktype_s::E_TaskrewardTasktype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TaskrewardTasktype_s::CreateInit() {
	m_tasktype = (int32_t)0;
	return 0;
}

int E_TaskrewardTasktype_s::ResumeInit() {
	return 0;
}

void E_TaskrewardTasktype_s::write_to_pbmsg(::proto_ff::E_TaskrewardTasktype & msg) const {
	msg.set_m_tasktype((int32_t)m_tasktype);
}

void E_TaskrewardTasktype_s::read_from_pbmsg(const ::proto_ff::E_TaskrewardTasktype & msg) {
	m_tasktype = msg.m_tasktype();
}

Sheet_TaskrewardTasktype_s::Sheet_TaskrewardTasktype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TaskrewardTasktype_s::CreateInit() {
	return 0;
}

int Sheet_TaskrewardTasktype_s::ResumeInit() {
	return 0;
}

void Sheet_TaskrewardTasktype_s::write_to_pbmsg(::proto_ff::Sheet_TaskrewardTasktype & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TaskrewardTasktype_List.size(); ++i) {
		::proto_ff::E_TaskrewardTasktype* temp_e_taskrewardtasktype_list = msg.add_e_taskrewardtasktype_list();
		E_TaskrewardTasktype_List[i].write_to_pbmsg(*temp_e_taskrewardtasktype_list);
	}
}

void Sheet_TaskrewardTasktype_s::read_from_pbmsg(const ::proto_ff::Sheet_TaskrewardTasktype & msg) {
	E_TaskrewardTasktype_List.resize((int)msg.e_taskrewardtasktype_list_size() > (int)E_TaskrewardTasktype_List.max_size() ? E_TaskrewardTasktype_List.max_size() : msg.e_taskrewardtasktype_list_size());
	for(int32_t i = 0; i < (int32_t)E_TaskrewardTasktype_List.size(); ++i) {
		const ::proto_ff::E_TaskrewardTasktype & temp_e_taskrewardtasktype_list = msg.e_taskrewardtasktype_list(i);
		E_TaskrewardTasktype_List[i].read_from_pbmsg(temp_e_taskrewardtasktype_list);
	}
}

}
