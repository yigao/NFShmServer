#include "E_Taskdynamic_s.h"

namespace proto_ff_s {

E_TaskdynamicTaskdynamic_s::E_TaskdynamicTaskdynamic_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TaskdynamicTaskdynamic_s::CreateInit() {
	m_taskID = (int64_t)0;
	m_taskType = (int32_t)0;
	m_weights = (int32_t)0;
	m_minlv = (int32_t)0;
	m_maxlv = (int32_t)0;
	m_receCount = (int32_t)0;
	return 0;
}

int E_TaskdynamicTaskdynamic_s::ResumeInit() {
	return 0;
}

void E_TaskdynamicTaskdynamic_s::write_to_pbmsg(::proto_ff::E_TaskdynamicTaskdynamic & msg) const {
	msg.set_m_taskid((int64_t)m_taskID);
	msg.set_m_remark(m_remark.data());
	msg.set_m_tasktype((int32_t)m_taskType);
	msg.set_m_weights((int32_t)m_weights);
	msg.set_m_minlv((int32_t)m_minlv);
	msg.set_m_maxlv((int32_t)m_maxlv);
	msg.set_m_rececount((int32_t)m_receCount);
	msg.set_m_idlist(m_idList.data());
}

void E_TaskdynamicTaskdynamic_s::read_from_pbmsg(const ::proto_ff::E_TaskdynamicTaskdynamic & msg) {
	m_taskID = msg.m_taskid();
	m_remark = msg.m_remark();
	m_taskType = msg.m_tasktype();
	m_weights = msg.m_weights();
	m_minlv = msg.m_minlv();
	m_maxlv = msg.m_maxlv();
	m_receCount = msg.m_rececount();
	m_idList = msg.m_idlist();
}

Sheet_TaskdynamicTaskdynamic_s::Sheet_TaskdynamicTaskdynamic_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TaskdynamicTaskdynamic_s::CreateInit() {
	return 0;
}

int Sheet_TaskdynamicTaskdynamic_s::ResumeInit() {
	return 0;
}

void Sheet_TaskdynamicTaskdynamic_s::write_to_pbmsg(::proto_ff::Sheet_TaskdynamicTaskdynamic & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TaskdynamicTaskdynamic_List.size(); ++i) {
		::proto_ff::E_TaskdynamicTaskdynamic* temp_e_taskdynamictaskdynamic_list = msg.add_e_taskdynamictaskdynamic_list();
		E_TaskdynamicTaskdynamic_List[i].write_to_pbmsg(*temp_e_taskdynamictaskdynamic_list);
	}
}

void Sheet_TaskdynamicTaskdynamic_s::read_from_pbmsg(const ::proto_ff::Sheet_TaskdynamicTaskdynamic & msg) {
	E_TaskdynamicTaskdynamic_List.resize((int)msg.e_taskdynamictaskdynamic_list_size() > (int)E_TaskdynamicTaskdynamic_List.max_size() ? E_TaskdynamicTaskdynamic_List.max_size() : msg.e_taskdynamictaskdynamic_list_size());
	for(int32_t i = 0; i < (int32_t)E_TaskdynamicTaskdynamic_List.size(); ++i) {
		const ::proto_ff::E_TaskdynamicTaskdynamic & temp_e_taskdynamictaskdynamic_list = msg.e_taskdynamictaskdynamic_list(i);
		E_TaskdynamicTaskdynamic_List[i].read_from_pbmsg(temp_e_taskdynamictaskdynamic_list);
	}
}

E_TaskdynamicTaskcomcond_s::E_TaskdynamicTaskcomcond_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TaskdynamicTaskcomcond_s::CreateInit() {
	m_comcondID = (int64_t)0;
	m_comcondType = (int32_t)0;
	m_param1 = (int64_t)0;
	m_param2 = (int64_t)0;
	m_param3 = (int64_t)0;
	m_param4 = (int64_t)0;
	m_param5 = (int64_t)0;
	m_comcondRandomValue = (int32_t)0;
	return 0;
}

int E_TaskdynamicTaskcomcond_s::ResumeInit() {
	return 0;
}

void E_TaskdynamicTaskcomcond_s::write_to_pbmsg(::proto_ff::E_TaskdynamicTaskcomcond & msg) const {
	msg.set_m_comcondid((int64_t)m_comcondID);
	msg.set_m_comcondtype((int32_t)m_comcondType);
	msg.set_m_param1((int64_t)m_param1);
	msg.set_m_param2((int64_t)m_param2);
	msg.set_m_param3((int64_t)m_param3);
	msg.set_m_param4((int64_t)m_param4);
	msg.set_m_param5((int64_t)m_param5);
	msg.set_m_comcondrandomvalue((int32_t)m_comcondRandomValue);
}

void E_TaskdynamicTaskcomcond_s::read_from_pbmsg(const ::proto_ff::E_TaskdynamicTaskcomcond & msg) {
	m_comcondID = msg.m_comcondid();
	m_comcondType = msg.m_comcondtype();
	m_param1 = msg.m_param1();
	m_param2 = msg.m_param2();
	m_param3 = msg.m_param3();
	m_param4 = msg.m_param4();
	m_param5 = msg.m_param5();
	m_comcondRandomValue = msg.m_comcondrandomvalue();
}

Sheet_TaskdynamicTaskcomcond_s::Sheet_TaskdynamicTaskcomcond_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TaskdynamicTaskcomcond_s::CreateInit() {
	return 0;
}

int Sheet_TaskdynamicTaskcomcond_s::ResumeInit() {
	return 0;
}

void Sheet_TaskdynamicTaskcomcond_s::write_to_pbmsg(::proto_ff::Sheet_TaskdynamicTaskcomcond & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TaskdynamicTaskcomcond_List.size(); ++i) {
		::proto_ff::E_TaskdynamicTaskcomcond* temp_e_taskdynamictaskcomcond_list = msg.add_e_taskdynamictaskcomcond_list();
		E_TaskdynamicTaskcomcond_List[i].write_to_pbmsg(*temp_e_taskdynamictaskcomcond_list);
	}
}

void Sheet_TaskdynamicTaskcomcond_s::read_from_pbmsg(const ::proto_ff::Sheet_TaskdynamicTaskcomcond & msg) {
	E_TaskdynamicTaskcomcond_List.resize((int)msg.e_taskdynamictaskcomcond_list_size() > (int)E_TaskdynamicTaskcomcond_List.max_size() ? E_TaskdynamicTaskcomcond_List.max_size() : msg.e_taskdynamictaskcomcond_list_size());
	for(int32_t i = 0; i < (int32_t)E_TaskdynamicTaskcomcond_List.size(); ++i) {
		const ::proto_ff::E_TaskdynamicTaskcomcond & temp_e_taskdynamictaskcomcond_list = msg.e_taskdynamictaskcomcond_list(i);
		E_TaskdynamicTaskcomcond_List[i].read_from_pbmsg(temp_e_taskdynamictaskcomcond_list);
	}
}

E_TaskdynamicTasktext_s::E_TaskdynamicTasktext_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TaskdynamicTasktext_s::CreateInit() {
	m_textID = (int64_t)0;
	m_comcondType = (int32_t)0;
	return 0;
}

int E_TaskdynamicTasktext_s::ResumeInit() {
	return 0;
}

void E_TaskdynamicTasktext_s::write_to_pbmsg(::proto_ff::E_TaskdynamicTasktext & msg) const {
	msg.set_m_textid((int64_t)m_textID);
	msg.set_m_tasktype(m_taskType.data());
	msg.set_m_comcondtype((int32_t)m_comcondType);
}

void E_TaskdynamicTasktext_s::read_from_pbmsg(const ::proto_ff::E_TaskdynamicTasktext & msg) {
	m_textID = msg.m_textid();
	m_taskType = msg.m_tasktype();
	m_comcondType = msg.m_comcondtype();
}

Sheet_TaskdynamicTasktext_s::Sheet_TaskdynamicTasktext_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TaskdynamicTasktext_s::CreateInit() {
	return 0;
}

int Sheet_TaskdynamicTasktext_s::ResumeInit() {
	return 0;
}

void Sheet_TaskdynamicTasktext_s::write_to_pbmsg(::proto_ff::Sheet_TaskdynamicTasktext & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TaskdynamicTasktext_List.size(); ++i) {
		::proto_ff::E_TaskdynamicTasktext* temp_e_taskdynamictasktext_list = msg.add_e_taskdynamictasktext_list();
		E_TaskdynamicTasktext_List[i].write_to_pbmsg(*temp_e_taskdynamictasktext_list);
	}
}

void Sheet_TaskdynamicTasktext_s::read_from_pbmsg(const ::proto_ff::Sheet_TaskdynamicTasktext & msg) {
	E_TaskdynamicTasktext_List.resize((int)msg.e_taskdynamictasktext_list_size() > (int)E_TaskdynamicTasktext_List.max_size() ? E_TaskdynamicTasktext_List.max_size() : msg.e_taskdynamictasktext_list_size());
	for(int32_t i = 0; i < (int32_t)E_TaskdynamicTasktext_List.size(); ++i) {
		const ::proto_ff::E_TaskdynamicTasktext & temp_e_taskdynamictasktext_list = msg.e_taskdynamictasktext_list(i);
		E_TaskdynamicTasktext_List[i].read_from_pbmsg(temp_e_taskdynamictasktext_list);
	}
}

}
