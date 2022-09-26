#include "tasktracker_s.h"

namespace proto_ff_s {

tasktrackertasktracker_s::tasktrackertasktracker_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tasktrackertasktracker_s::CreateInit() {
	comID = (int32_t)0;
	trueID = (int32_t)0;
	return 0;
}

int tasktrackertasktracker_s::ResumeInit() {
	return 0;
}

void tasktrackertasktracker_s::write_to_pbmsg(::proto_ff::tasktrackertasktracker & msg) const {
	msg.set_comid((int32_t)comID);
	msg.set_trueid((int32_t)trueID);
}

void tasktrackertasktracker_s::read_from_pbmsg(const ::proto_ff::tasktrackertasktracker & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct tasktrackertasktracker_s));
	comID = msg.comid();
	trueID = msg.trueid();
}

Sheet_tasktrackertasktracker_s::Sheet_tasktrackertasktracker_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_tasktrackertasktracker_s::CreateInit() {
	return 0;
}

int Sheet_tasktrackertasktracker_s::ResumeInit() {
	return 0;
}

void Sheet_tasktrackertasktracker_s::write_to_pbmsg(::proto_ff::Sheet_tasktrackertasktracker & msg) const {
	for(int32_t i = 0; i < (int32_t)tasktrackertasktracker_List.GetSize() && i < tasktrackertasktracker_List.GetMaxSize(); ++i) {
		::proto_ff::tasktrackertasktracker* temp_tasktrackertasktracker_list = msg.add_tasktrackertasktracker_list();
		tasktrackertasktracker_List[i].write_to_pbmsg(*temp_tasktrackertasktracker_list);
	}
}

void Sheet_tasktrackertasktracker_s::read_from_pbmsg(const ::proto_ff::Sheet_tasktrackertasktracker & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_tasktrackertasktracker_s));
	tasktrackertasktracker_List.SetSize(msg.tasktrackertasktracker_list_size() > tasktrackertasktracker_List.GetMaxSize() ? tasktrackertasktracker_List.GetMaxSize() : msg.tasktrackertasktracker_list_size());
	for(int32_t i = 0; i < (int32_t)tasktrackertasktracker_List.GetSize(); ++i) {
		const ::proto_ff::tasktrackertasktracker & temp_tasktrackertasktracker_list = msg.tasktrackertasktracker_list(i);
		tasktrackertasktracker_List[i].read_from_pbmsg(temp_tasktrackertasktracker_list);
	}
}

}