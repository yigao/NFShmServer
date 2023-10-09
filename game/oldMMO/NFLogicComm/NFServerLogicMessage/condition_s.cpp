#include "condition_s.h"

namespace proto_ff_s {

E_ConditionConditionConditionDesc_s::E_ConditionConditionConditionDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConditionConditionConditionDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_param = (int32_t)0;
	return 0;
}

int E_ConditionConditionConditionDesc_s::ResumeInit() {
	return 0;
}

void E_ConditionConditionConditionDesc_s::write_to_pbmsg(::proto_ff::E_ConditionConditionConditionDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_param((int32_t)m_param);
}

void E_ConditionConditionConditionDesc_s::read_from_pbmsg(const ::proto_ff::E_ConditionConditionConditionDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ConditionConditionConditionDesc_s));
	m_type = msg.m_type();
	m_param = msg.m_param();
}

E_ConditionCondition_s::E_ConditionCondition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConditionCondition_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_ConditionCondition_s::ResumeInit() {
	return 0;
}

void E_ConditionCondition_s::write_to_pbmsg(::proto_ff::E_ConditionCondition & msg) const {
	msg.set_m_id((int32_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_condition.size(); ++i) {
		::proto_ff::E_ConditionConditionConditionDesc* temp_m_condition = msg.add_m_condition();
		m_condition[i].write_to_pbmsg(*temp_m_condition);
	}
}

void E_ConditionCondition_s::read_from_pbmsg(const ::proto_ff::E_ConditionCondition & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ConditionCondition_s));
	m_id = msg.m_id();
	m_condition.resize((int)msg.m_condition_size() > (int)m_condition.max_size() ? m_condition.max_size() : msg.m_condition_size());
	for(int32_t i = 0; i < (int32_t)m_condition.size(); ++i) {
		const ::proto_ff::E_ConditionConditionConditionDesc & temp_m_condition = msg.m_condition(i);
		m_condition[i].read_from_pbmsg(temp_m_condition);
	}
}

Sheet_ConditionCondition_s::Sheet_ConditionCondition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ConditionCondition_s::CreateInit() {
	return 0;
}

int Sheet_ConditionCondition_s::ResumeInit() {
	return 0;
}

void Sheet_ConditionCondition_s::write_to_pbmsg(::proto_ff::Sheet_ConditionCondition & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ConditionCondition_List.size(); ++i) {
		::proto_ff::E_ConditionCondition* temp_e_conditioncondition_list = msg.add_e_conditioncondition_list();
		E_ConditionCondition_List[i].write_to_pbmsg(*temp_e_conditioncondition_list);
	}
}

void Sheet_ConditionCondition_s::read_from_pbmsg(const ::proto_ff::Sheet_ConditionCondition & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_ConditionCondition_s));
	E_ConditionCondition_List.resize((int)msg.e_conditioncondition_list_size() > (int)E_ConditionCondition_List.max_size() ? E_ConditionCondition_List.max_size() : msg.e_conditioncondition_list_size());
	for(int32_t i = 0; i < (int32_t)E_ConditionCondition_List.size(); ++i) {
		const ::proto_ff::E_ConditionCondition & temp_e_conditioncondition_list = msg.e_conditioncondition_list(i);
		E_ConditionCondition_List[i].read_from_pbmsg(temp_e_conditioncondition_list);
	}
}

}