#include "indultTask_s.h"

namespace proto_ff_s {

indultTaskindultTask_s::indultTaskindultTask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int indultTaskindultTask_s::CreateInit() {
	id = (int32_t)0;
	order = (int32_t)0;
	functionUnlock = (int32_t)0;
	boxid = (int64_t)0;
	taskNum = (int32_t)0;
	return 0;
}

int indultTaskindultTask_s::ResumeInit() {
	return 0;
}

void indultTaskindultTask_s::write_to_pbmsg(::proto_ff::indultTaskindultTask & msg) const {
	msg.set_id((int32_t)id);
	msg.set_order((int32_t)order);
	msg.set_functionunlock((int32_t)functionUnlock);
	msg.set_boxid((int64_t)boxid);
	msg.set_taskid((const char*)taskID.Get());
	msg.set_tasknum((int32_t)taskNum);
}

void indultTaskindultTask_s::read_from_pbmsg(const ::proto_ff::indultTaskindultTask & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct indultTaskindultTask_s));
	id = msg.id();
	order = msg.order();
	functionUnlock = msg.functionunlock();
	boxid = msg.boxid();
	taskID.Copy(msg.taskid());
	taskNum = msg.tasknum();
}

Sheet_indultTaskindultTask_s::Sheet_indultTaskindultTask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_indultTaskindultTask_s::CreateInit() {
	return 0;
}

int Sheet_indultTaskindultTask_s::ResumeInit() {
	return 0;
}

void Sheet_indultTaskindultTask_s::write_to_pbmsg(::proto_ff::Sheet_indultTaskindultTask & msg) const {
	for(int32_t i = 0; i < (int32_t)indultTaskindultTask_List.GetSize() && i < indultTaskindultTask_List.GetMaxSize(); ++i) {
		::proto_ff::indultTaskindultTask* temp_indulttaskindulttask_list = msg.add_indulttaskindulttask_list();
		indultTaskindultTask_List[i].write_to_pbmsg(*temp_indulttaskindulttask_list);
	}
}

void Sheet_indultTaskindultTask_s::read_from_pbmsg(const ::proto_ff::Sheet_indultTaskindultTask & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_indultTaskindultTask_s));
	indultTaskindultTask_List.SetSize(msg.indulttaskindulttask_list_size() > indultTaskindultTask_List.GetMaxSize() ? indultTaskindultTask_List.GetMaxSize() : msg.indulttaskindulttask_list_size());
	for(int32_t i = 0; i < (int32_t)indultTaskindultTask_List.GetSize(); ++i) {
		const ::proto_ff::indultTaskindultTask & temp_indulttaskindulttask_list = msg.indulttaskindulttask_list(i);
		indultTaskindultTask_List[i].read_from_pbmsg(temp_indulttaskindulttask_list);
	}
}

indultTasktask_s::indultTasktask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int indultTasktask_s::CreateInit() {
	id = (int32_t)0;
	task = (int32_t)0;
	return 0;
}

int indultTasktask_s::ResumeInit() {
	return 0;
}

void indultTasktask_s::write_to_pbmsg(::proto_ff::indultTasktask & msg) const {
	msg.set_id((int32_t)id);
	msg.set_task((int32_t)task);
	msg.set_taskparam((const char*)taskParam.Get());
}

void indultTasktask_s::read_from_pbmsg(const ::proto_ff::indultTasktask & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct indultTasktask_s));
	id = msg.id();
	task = msg.task();
	taskParam.Copy(msg.taskparam());
}

Sheet_indultTasktask_s::Sheet_indultTasktask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_indultTasktask_s::CreateInit() {
	return 0;
}

int Sheet_indultTasktask_s::ResumeInit() {
	return 0;
}

void Sheet_indultTasktask_s::write_to_pbmsg(::proto_ff::Sheet_indultTasktask & msg) const {
	for(int32_t i = 0; i < (int32_t)indultTasktask_List.GetSize() && i < indultTasktask_List.GetMaxSize(); ++i) {
		::proto_ff::indultTasktask* temp_indulttasktask_list = msg.add_indulttasktask_list();
		indultTasktask_List[i].write_to_pbmsg(*temp_indulttasktask_list);
	}
}

void Sheet_indultTasktask_s::read_from_pbmsg(const ::proto_ff::Sheet_indultTasktask & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_indultTasktask_s));
	indultTasktask_List.SetSize(msg.indulttasktask_list_size() > indultTasktask_List.GetMaxSize() ? indultTasktask_List.GetMaxSize() : msg.indulttasktask_list_size());
	for(int32_t i = 0; i < (int32_t)indultTasktask_List.GetSize(); ++i) {
		const ::proto_ff::indultTasktask & temp_indulttasktask_list = msg.indulttasktask_list(i);
		indultTasktask_List[i].read_from_pbmsg(temp_indulttasktask_list);
	}
}

}