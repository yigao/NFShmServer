#include "condition_s.h"

namespace proto_ff_s {

conditionconditionconditionDesc_s::conditionconditionconditionDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int conditionconditionconditionDesc_s::CreateInit() {
	Type = (int32_t)0;
	Param = (int32_t)0;
	return 0;
}

int conditionconditionconditionDesc_s::ResumeInit() {
	return 0;
}

void conditionconditionconditionDesc_s::write_to_pbmsg(::proto_ff::conditionconditionconditionDesc & msg) const {
	msg.set_type((int32_t)Type);
	msg.set_param((int32_t)Param);
}

void conditionconditionconditionDesc_s::read_from_pbmsg(const ::proto_ff::conditionconditionconditionDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct conditionconditionconditionDesc_s));
	Type = msg.type();
	Param = msg.param();
}

conditioncondition_s::conditioncondition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int conditioncondition_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int conditioncondition_s::ResumeInit() {
	return 0;
}

void conditioncondition_s::write_to_pbmsg(::proto_ff::conditioncondition & msg) const {
	msg.set_id((int32_t)id);
	for(int32_t i = 0; i < (int32_t)condition.GetSize() && i < condition.GetMaxSize(); ++i) {
		::proto_ff::conditionconditionconditionDesc* temp_condition = msg.add_condition();
		condition[i].write_to_pbmsg(*temp_condition);
	}
}

void conditioncondition_s::read_from_pbmsg(const ::proto_ff::conditioncondition & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct conditioncondition_s));
	id = msg.id();
	condition.SetSize(msg.condition_size() > condition.GetMaxSize() ? condition.GetMaxSize() : msg.condition_size());
	for(int32_t i = 0; i < (int32_t)condition.GetSize(); ++i) {
		const ::proto_ff::conditionconditionconditionDesc & temp_condition = msg.condition(i);
		condition[i].read_from_pbmsg(temp_condition);
	}
}

Sheet_conditioncondition_s::Sheet_conditioncondition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_conditioncondition_s::CreateInit() {
	return 0;
}

int Sheet_conditioncondition_s::ResumeInit() {
	return 0;
}

void Sheet_conditioncondition_s::write_to_pbmsg(::proto_ff::Sheet_conditioncondition & msg) const {
	for(int32_t i = 0; i < (int32_t)conditioncondition_List.GetSize() && i < conditioncondition_List.GetMaxSize(); ++i) {
		::proto_ff::conditioncondition* temp_conditioncondition_list = msg.add_conditioncondition_list();
		conditioncondition_List[i].write_to_pbmsg(*temp_conditioncondition_list);
	}
}

void Sheet_conditioncondition_s::read_from_pbmsg(const ::proto_ff::Sheet_conditioncondition & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_conditioncondition_s));
	conditioncondition_List.SetSize(msg.conditioncondition_list_size() > conditioncondition_List.GetMaxSize() ? conditioncondition_List.GetMaxSize() : msg.conditioncondition_list_size());
	for(int32_t i = 0; i < (int32_t)conditioncondition_List.GetSize(); ++i) {
		const ::proto_ff::conditioncondition & temp_conditioncondition_list = msg.conditioncondition_list(i);
		conditioncondition_List[i].read_from_pbmsg(temp_conditioncondition_list);
	}
}

}