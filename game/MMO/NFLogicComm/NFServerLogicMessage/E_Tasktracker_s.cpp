#include "E_Tasktracker_s.h"

namespace proto_ff_s {

E_TasktrackerTasktracker_s::E_TasktrackerTasktracker_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TasktrackerTasktracker_s::CreateInit() {
	m_comID = (int32_t)0;
	m_trueID = (int32_t)0;
	return 0;
}

int E_TasktrackerTasktracker_s::ResumeInit() {
	return 0;
}

void E_TasktrackerTasktracker_s::write_to_pbmsg(::proto_ff::E_TasktrackerTasktracker & msg) const {
	msg.set_m_comid((int32_t)m_comID);
	msg.set_m_trueid((int32_t)m_trueID);
}

void E_TasktrackerTasktracker_s::read_from_pbmsg(const ::proto_ff::E_TasktrackerTasktracker & msg) {
	m_comID = msg.m_comid();
	m_trueID = msg.m_trueid();
}

Sheet_TasktrackerTasktracker_s::Sheet_TasktrackerTasktracker_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TasktrackerTasktracker_s::CreateInit() {
	return 0;
}

int Sheet_TasktrackerTasktracker_s::ResumeInit() {
	return 0;
}

void Sheet_TasktrackerTasktracker_s::write_to_pbmsg(::proto_ff::Sheet_TasktrackerTasktracker & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TasktrackerTasktracker_List.size(); ++i) {
		::proto_ff::E_TasktrackerTasktracker* temp_e_tasktrackertasktracker_list = msg.add_e_tasktrackertasktracker_list();
		E_TasktrackerTasktracker_List[i].write_to_pbmsg(*temp_e_tasktrackertasktracker_list);
	}
}

void Sheet_TasktrackerTasktracker_s::read_from_pbmsg(const ::proto_ff::Sheet_TasktrackerTasktracker & msg) {
	E_TasktrackerTasktracker_List.resize((int)msg.e_tasktrackertasktracker_list_size() > (int)E_TasktrackerTasktracker_List.max_size() ? E_TasktrackerTasktracker_List.max_size() : msg.e_tasktrackertasktracker_list_size());
	for(int32_t i = 0; i < (int32_t)E_TasktrackerTasktracker_List.size(); ++i) {
		const ::proto_ff::E_TasktrackerTasktracker & temp_e_tasktrackertasktracker_list = msg.e_tasktrackertasktracker_list(i);
		E_TasktrackerTasktracker_List[i].read_from_pbmsg(temp_e_tasktrackertasktracker_list);
	}
}

}
