#include "taskdynamic_s.h"

namespace proto_ff_s {

taskdynamictaskdynamic_s::taskdynamictaskdynamic_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int taskdynamictaskdynamic_s::CreateInit() {
	taskID = (int64_t)0;
	taskType = (int32_t)0;
	minlv = (int32_t)0;
	maxlv = (int32_t)0;
	receCount = (int32_t)0;
	return 0;
}

int taskdynamictaskdynamic_s::ResumeInit() {
	return 0;
}

void taskdynamictaskdynamic_s::write_to_pbmsg(::proto_ff::taskdynamictaskdynamic & msg) const {
	msg.set_taskid((int64_t)taskID);
	msg.set_remark((const char*)remark.Get());
	msg.set_tasktype((int32_t)taskType);
	msg.set_minlv((int32_t)minlv);
	msg.set_maxlv((int32_t)maxlv);
	msg.set_rececount((int32_t)receCount);
	msg.set_idlist((const char*)idList.Get());
}

void taskdynamictaskdynamic_s::read_from_pbmsg(const ::proto_ff::taskdynamictaskdynamic & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct taskdynamictaskdynamic_s));
	taskID = msg.taskid();
	remark.Copy(msg.remark());
	taskType = msg.tasktype();
	minlv = msg.minlv();
	maxlv = msg.maxlv();
	receCount = msg.rececount();
	idList.Copy(msg.idlist());
}

Sheet_taskdynamictaskdynamic_s::Sheet_taskdynamictaskdynamic_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_taskdynamictaskdynamic_s::CreateInit() {
	return 0;
}

int Sheet_taskdynamictaskdynamic_s::ResumeInit() {
	return 0;
}

void Sheet_taskdynamictaskdynamic_s::write_to_pbmsg(::proto_ff::Sheet_taskdynamictaskdynamic & msg) const {
	for(int32_t i = 0; i < (int32_t)taskdynamictaskdynamic_List.GetSize() && i < taskdynamictaskdynamic_List.GetMaxSize(); ++i) {
		::proto_ff::taskdynamictaskdynamic* temp_taskdynamictaskdynamic_list = msg.add_taskdynamictaskdynamic_list();
		taskdynamictaskdynamic_List[i].write_to_pbmsg(*temp_taskdynamictaskdynamic_list);
	}
}

void Sheet_taskdynamictaskdynamic_s::read_from_pbmsg(const ::proto_ff::Sheet_taskdynamictaskdynamic & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_taskdynamictaskdynamic_s));
	taskdynamictaskdynamic_List.SetSize(msg.taskdynamictaskdynamic_list_size() > taskdynamictaskdynamic_List.GetMaxSize() ? taskdynamictaskdynamic_List.GetMaxSize() : msg.taskdynamictaskdynamic_list_size());
	for(int32_t i = 0; i < (int32_t)taskdynamictaskdynamic_List.GetSize(); ++i) {
		const ::proto_ff::taskdynamictaskdynamic & temp_taskdynamictaskdynamic_list = msg.taskdynamictaskdynamic_list(i);
		taskdynamictaskdynamic_List[i].read_from_pbmsg(temp_taskdynamictaskdynamic_list);
	}
}

taskdynamictaskcomcond_s::taskdynamictaskcomcond_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int taskdynamictaskcomcond_s::CreateInit() {
	comcondID = (int64_t)0;
	comcondType = (int32_t)0;
	param1 = (int64_t)0;
	param2 = (int64_t)0;
	param3 = (int64_t)0;
	param4 = (int64_t)0;
	param5 = (int64_t)0;
	comcondRandomValue = (int32_t)0;
	return 0;
}

int taskdynamictaskcomcond_s::ResumeInit() {
	return 0;
}

void taskdynamictaskcomcond_s::write_to_pbmsg(::proto_ff::taskdynamictaskcomcond & msg) const {
	msg.set_comcondid((int64_t)comcondID);
	msg.set_comcondtype((int32_t)comcondType);
	msg.set_param1((int64_t)param1);
	msg.set_param2((int64_t)param2);
	msg.set_param3((int64_t)param3);
	msg.set_param4((int64_t)param4);
	msg.set_param5((int64_t)param5);
	msg.set_comcondrandomvalue((int32_t)comcondRandomValue);
}

void taskdynamictaskcomcond_s::read_from_pbmsg(const ::proto_ff::taskdynamictaskcomcond & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct taskdynamictaskcomcond_s));
	comcondID = msg.comcondid();
	comcondType = msg.comcondtype();
	param1 = msg.param1();
	param2 = msg.param2();
	param3 = msg.param3();
	param4 = msg.param4();
	param5 = msg.param5();
	comcondRandomValue = msg.comcondrandomvalue();
}

Sheet_taskdynamictaskcomcond_s::Sheet_taskdynamictaskcomcond_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_taskdynamictaskcomcond_s::CreateInit() {
	return 0;
}

int Sheet_taskdynamictaskcomcond_s::ResumeInit() {
	return 0;
}

void Sheet_taskdynamictaskcomcond_s::write_to_pbmsg(::proto_ff::Sheet_taskdynamictaskcomcond & msg) const {
	for(int32_t i = 0; i < (int32_t)taskdynamictaskcomcond_List.GetSize() && i < taskdynamictaskcomcond_List.GetMaxSize(); ++i) {
		::proto_ff::taskdynamictaskcomcond* temp_taskdynamictaskcomcond_list = msg.add_taskdynamictaskcomcond_list();
		taskdynamictaskcomcond_List[i].write_to_pbmsg(*temp_taskdynamictaskcomcond_list);
	}
}

void Sheet_taskdynamictaskcomcond_s::read_from_pbmsg(const ::proto_ff::Sheet_taskdynamictaskcomcond & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_taskdynamictaskcomcond_s));
	taskdynamictaskcomcond_List.SetSize(msg.taskdynamictaskcomcond_list_size() > taskdynamictaskcomcond_List.GetMaxSize() ? taskdynamictaskcomcond_List.GetMaxSize() : msg.taskdynamictaskcomcond_list_size());
	for(int32_t i = 0; i < (int32_t)taskdynamictaskcomcond_List.GetSize(); ++i) {
		const ::proto_ff::taskdynamictaskcomcond & temp_taskdynamictaskcomcond_list = msg.taskdynamictaskcomcond_list(i);
		taskdynamictaskcomcond_List[i].read_from_pbmsg(temp_taskdynamictaskcomcond_list);
	}
}

taskdynamictasktext_s::taskdynamictasktext_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int taskdynamictasktext_s::CreateInit() {
	textID = (int64_t)0;
	comcondType = (int32_t)0;
	return 0;
}

int taskdynamictasktext_s::ResumeInit() {
	return 0;
}

void taskdynamictasktext_s::write_to_pbmsg(::proto_ff::taskdynamictasktext & msg) const {
	msg.set_textid((int64_t)textID);
	msg.set_tasktype((const char*)taskType.Get());
	msg.set_comcondtype((int32_t)comcondType);
}

void taskdynamictasktext_s::read_from_pbmsg(const ::proto_ff::taskdynamictasktext & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct taskdynamictasktext_s));
	textID = msg.textid();
	taskType.Copy(msg.tasktype());
	comcondType = msg.comcondtype();
}

Sheet_taskdynamictasktext_s::Sheet_taskdynamictasktext_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_taskdynamictasktext_s::CreateInit() {
	return 0;
}

int Sheet_taskdynamictasktext_s::ResumeInit() {
	return 0;
}

void Sheet_taskdynamictasktext_s::write_to_pbmsg(::proto_ff::Sheet_taskdynamictasktext & msg) const {
	for(int32_t i = 0; i < (int32_t)taskdynamictasktext_List.GetSize() && i < taskdynamictasktext_List.GetMaxSize(); ++i) {
		::proto_ff::taskdynamictasktext* temp_taskdynamictasktext_list = msg.add_taskdynamictasktext_list();
		taskdynamictasktext_List[i].write_to_pbmsg(*temp_taskdynamictasktext_list);
	}
}

void Sheet_taskdynamictasktext_s::read_from_pbmsg(const ::proto_ff::Sheet_taskdynamictasktext & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_taskdynamictasktext_s));
	taskdynamictasktext_List.SetSize(msg.taskdynamictasktext_list_size() > taskdynamictasktext_List.GetMaxSize() ? taskdynamictasktext_List.GetMaxSize() : msg.taskdynamictasktext_list_size());
	for(int32_t i = 0; i < (int32_t)taskdynamictasktext_List.GetSize(); ++i) {
		const ::proto_ff::taskdynamictasktext & temp_taskdynamictasktext_list = msg.taskdynamictasktext_list(i);
		taskdynamictasktext_List[i].read_from_pbmsg(temp_taskdynamictasktext_list);
	}
}

}