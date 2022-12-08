#include "task_s.h"

namespace proto_ff_s {

tasktask_s::tasktask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tasktask_s::CreateInit() {
	id = (int32_t)0;
	minlv = (int32_t)0;
	truelv = (int32_t)0;
	type = (int32_t)0;
	weights = (int32_t)0;
	nexttask = (int32_t)0;
	subnpc = (int32_t)0;
	subaward = (int32_t)0;
	return 0;
}

int tasktask_s::ResumeInit() {
	return 0;
}

void tasktask_s::write_to_pbmsg(::proto_ff::tasktask & msg) const {
	msg.set_id((int32_t)id);
	msg.set_minlv((int32_t)minlv);
	msg.set_truelv((int32_t)truelv);
	msg.set_type((int32_t)type);
	msg.set_showtype((const char*)showtype.Get());
	msg.set_weights((int32_t)weights);
	msg.set_name((const char*)name.Get());
	msg.set_rececond((const char*)rececond.Get());
	msg.set_receadd((const char*)receadd.Get());
	msg.set_comcond((const char*)comcond.Get());
	msg.set_nexttask((int32_t)nexttask);
	msg.set_tracker((const char*)tracker.Get());
	msg.set_subtype((const char*)subtype.Get());
	msg.set_subnpc((int32_t)subnpc);
	msg.set_subdesc((const char*)subdesc.Get());
	msg.set_subaward((int32_t)subaward);
	for(int32_t i = 0; i < (int32_t)submsg.GetSize() && i < submsg.GetMaxSize(); ++i) {
		msg.add_submsg((const char*)submsg[i].Get());
	}
}

void tasktask_s::read_from_pbmsg(const ::proto_ff::tasktask & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct tasktask_s));
	id = msg.id();
	minlv = msg.minlv();
	truelv = msg.truelv();
	type = msg.type();
	showtype.Copy(msg.showtype());
	weights = msg.weights();
	name.Copy(msg.name());
	rececond.Copy(msg.rececond());
	receadd.Copy(msg.receadd());
	comcond.Copy(msg.comcond());
	nexttask = msg.nexttask();
	tracker.Copy(msg.tracker());
	subtype.Copy(msg.subtype());
	subnpc = msg.subnpc();
	subdesc.Copy(msg.subdesc());
	subaward = msg.subaward();
	submsg.SetSize(msg.submsg_size() > submsg.GetMaxSize() ? submsg.GetMaxSize() : msg.submsg_size());
	for(int32_t i = 0; i < (int32_t)submsg.GetSize(); ++i) {
		submsg[i].Copy(msg.submsg(i));
	}
}

Sheet_tasktask_s::Sheet_tasktask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_tasktask_s::CreateInit() {
	return 0;
}

int Sheet_tasktask_s::ResumeInit() {
	return 0;
}

void Sheet_tasktask_s::write_to_pbmsg(::proto_ff::Sheet_tasktask & msg) const {
	for(int32_t i = 0; i < (int32_t)tasktask_List.GetSize() && i < tasktask_List.GetMaxSize(); ++i) {
		::proto_ff::tasktask* temp_tasktask_list = msg.add_tasktask_list();
		tasktask_List[i].write_to_pbmsg(*temp_tasktask_list);
	}
}

void Sheet_tasktask_s::read_from_pbmsg(const ::proto_ff::Sheet_tasktask & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_tasktask_s));
	tasktask_List.SetSize(msg.tasktask_list_size() > tasktask_List.GetMaxSize() ? tasktask_List.GetMaxSize() : msg.tasktask_list_size());
	for(int32_t i = 0; i < (int32_t)tasktask_List.GetSize(); ++i) {
		const ::proto_ff::tasktask & temp_tasktask_list = msg.tasktask_list(i);
		tasktask_List[i].read_from_pbmsg(temp_tasktask_list);
	}
}

}