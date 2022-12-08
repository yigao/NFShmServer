#include "back_s.h"

namespace proto_ff_s {

backback_s::backback_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int backback_s::CreateInit() {
	id = (int32_t)0;
	type = (int32_t)0;
	typeParam = (int32_t)0;
	group = (int32_t)0;
	functionUnlock = (int32_t)0;
	levelLimit = (int32_t)0;
	PboxId = (int64_t)0;
	boxId = (int64_t)0;
	backDay = (int32_t)0;
	costItemID = (int32_t)0;
	costNum = (int32_t)0;
	PcostItemID = (int32_t)0;
	PcostNum = (int32_t)0;
	AcostItemID = (int32_t)0;
	AcostNum = (int32_t)0;
	return 0;
}

int backback_s::ResumeInit() {
	return 0;
}

void backback_s::write_to_pbmsg(::proto_ff::backback & msg) const {
	msg.set_id((int32_t)id);
	msg.set_type((int32_t)type);
	msg.set_typeparam((int32_t)typeParam);
	msg.set_name((const char*)name.Get());
	msg.set_group((int32_t)group);
	msg.set_functionunlock((int32_t)functionUnlock);
	msg.set_levellimit((int32_t)levelLimit);
	msg.set_pboxid((int64_t)PboxId);
	msg.set_boxid((int64_t)boxId);
	msg.set_backday((int32_t)backDay);
	msg.set_costitemid((int32_t)costItemID);
	msg.set_costnum((int32_t)costNum);
	msg.set_pcostitemid((int32_t)PcostItemID);
	msg.set_pcostnum((int32_t)PcostNum);
	msg.set_acostitemid((int32_t)AcostItemID);
	msg.set_acostnum((int32_t)AcostNum);
	for(int32_t i = 0; i < (int32_t)param.GetSize() && i < param.GetMaxSize(); ++i) {
		msg.add_param((int32_t)param[i]);
	}
}

void backback_s::read_from_pbmsg(const ::proto_ff::backback & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct backback_s));
	id = msg.id();
	type = msg.type();
	typeParam = msg.typeparam();
	name.Copy(msg.name());
	group = msg.group();
	functionUnlock = msg.functionunlock();
	levelLimit = msg.levellimit();
	PboxId = msg.pboxid();
	boxId = msg.boxid();
	backDay = msg.backday();
	costItemID = msg.costitemid();
	costNum = msg.costnum();
	PcostItemID = msg.pcostitemid();
	PcostNum = msg.pcostnum();
	AcostItemID = msg.acostitemid();
	AcostNum = msg.acostnum();
	param.SetSize(msg.param_size() > param.GetMaxSize() ? param.GetMaxSize() : msg.param_size());
	for(int32_t i = 0; i < (int32_t)param.GetSize(); ++i) {
		param[i] = msg.param(i);
	}
}

Sheet_backback_s::Sheet_backback_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_backback_s::CreateInit() {
	return 0;
}

int Sheet_backback_s::ResumeInit() {
	return 0;
}

void Sheet_backback_s::write_to_pbmsg(::proto_ff::Sheet_backback & msg) const {
	for(int32_t i = 0; i < (int32_t)backback_List.GetSize() && i < backback_List.GetMaxSize(); ++i) {
		::proto_ff::backback* temp_backback_list = msg.add_backback_list();
		backback_List[i].write_to_pbmsg(*temp_backback_list);
	}
}

void Sheet_backback_s::read_from_pbmsg(const ::proto_ff::Sheet_backback & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_backback_s));
	backback_List.SetSize(msg.backback_list_size() > backback_List.GetMaxSize() ? backback_List.GetMaxSize() : msg.backback_list_size());
	for(int32_t i = 0; i < (int32_t)backback_List.GetSize(); ++i) {
		const ::proto_ff::backback & temp_backback_list = msg.backback_list(i);
		backback_List[i].read_from_pbmsg(temp_backback_list);
	}
}

}