#include "E_Task_s.h"

namespace proto_ff_s {

E_TaskTask_s::E_TaskTask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TaskTask_s::CreateInit() {
	m_id = (int32_t)0;
	m_minlv = (int32_t)0;
	m_truelv = (int32_t)0;
	m_type = (int32_t)0;
	m_weights = (int32_t)0;
	m_nexttask = (int32_t)0;
	m_subnpc = (int32_t)0;
	m_subaward = (int32_t)0;
	return 0;
}

int E_TaskTask_s::ResumeInit() {
	return 0;
}

void E_TaskTask_s::write_to_pbmsg(::proto_ff::E_TaskTask & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_minlv((int32_t)m_minlv);
	msg.set_m_truelv((int32_t)m_truelv);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_showtype(m_showtype.data());
	msg.set_m_weights((int32_t)m_weights);
	msg.set_m_name(m_name.data());
	msg.set_m_rececond(m_rececond.data());
	msg.set_m_receadd(m_receadd.data());
	msg.set_m_comcond(m_comcond.data());
	msg.set_m_nexttask((int32_t)m_nexttask);
	msg.set_m_tracker(m_tracker.data());
	msg.set_m_subtype(m_subtype.data());
	msg.set_m_subnpc((int32_t)m_subnpc);
	msg.set_m_subaward((int32_t)m_subaward);
}

void E_TaskTask_s::read_from_pbmsg(const ::proto_ff::E_TaskTask & msg) {
	m_id = msg.m_id();
	m_minlv = msg.m_minlv();
	m_truelv = msg.m_truelv();
	m_type = msg.m_type();
	m_showtype = msg.m_showtype();
	m_weights = msg.m_weights();
	m_name = msg.m_name();
	m_rececond = msg.m_rececond();
	m_receadd = msg.m_receadd();
	m_comcond = msg.m_comcond();
	m_nexttask = msg.m_nexttask();
	m_tracker = msg.m_tracker();
	m_subtype = msg.m_subtype();
	m_subnpc = msg.m_subnpc();
	m_subaward = msg.m_subaward();
}

Sheet_TaskTask_s::Sheet_TaskTask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TaskTask_s::CreateInit() {
	return 0;
}

int Sheet_TaskTask_s::ResumeInit() {
	return 0;
}

void Sheet_TaskTask_s::write_to_pbmsg(::proto_ff::Sheet_TaskTask & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TaskTask_List.size(); ++i) {
		::proto_ff::E_TaskTask* temp_e_tasktask_list = msg.add_e_tasktask_list();
		E_TaskTask_List[i].write_to_pbmsg(*temp_e_tasktask_list);
	}
}

void Sheet_TaskTask_s::read_from_pbmsg(const ::proto_ff::Sheet_TaskTask & msg) {
	E_TaskTask_List.resize((int)msg.e_tasktask_list_size() > (int)E_TaskTask_List.max_size() ? E_TaskTask_List.max_size() : msg.e_tasktask_list_size());
	for(int32_t i = 0; i < (int32_t)E_TaskTask_List.size(); ++i) {
		const ::proto_ff::E_TaskTask & temp_e_tasktask_list = msg.e_tasktask_list(i);
		E_TaskTask_List[i].read_from_pbmsg(temp_e_tasktask_list);
	}
}

}
