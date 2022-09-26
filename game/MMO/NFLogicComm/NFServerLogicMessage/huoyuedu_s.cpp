#include "huoyuedu_s.h"

namespace proto_ff_s {

huoyuedureward_s::huoyuedureward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int huoyuedureward_s::CreateInit() {
	id = (int32_t)0;
	type = (int32_t)0;
	activeScore = (int32_t)0;
	rewardId = (int64_t)0;
	rewardNum = (int32_t)0;
	return 0;
}

int huoyuedureward_s::ResumeInit() {
	return 0;
}

void huoyuedureward_s::write_to_pbmsg(::proto_ff::huoyuedureward & msg) const {
	msg.set_id((int32_t)id);
	msg.set_type((int32_t)type);
	msg.set_activescore((int32_t)activeScore);
	msg.set_rewardid((int64_t)rewardId);
	msg.set_rewardnum((int32_t)rewardNum);
}

void huoyuedureward_s::read_from_pbmsg(const ::proto_ff::huoyuedureward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct huoyuedureward_s));
	id = msg.id();
	type = msg.type();
	activeScore = msg.activescore();
	rewardId = msg.rewardid();
	rewardNum = msg.rewardnum();
}

Sheet_huoyuedureward_s::Sheet_huoyuedureward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_huoyuedureward_s::CreateInit() {
	return 0;
}

int Sheet_huoyuedureward_s::ResumeInit() {
	return 0;
}

void Sheet_huoyuedureward_s::write_to_pbmsg(::proto_ff::Sheet_huoyuedureward & msg) const {
	for(int32_t i = 0; i < (int32_t)huoyuedureward_List.GetSize() && i < huoyuedureward_List.GetMaxSize(); ++i) {
		::proto_ff::huoyuedureward* temp_huoyuedureward_list = msg.add_huoyuedureward_list();
		huoyuedureward_List[i].write_to_pbmsg(*temp_huoyuedureward_list);
	}
}

void Sheet_huoyuedureward_s::read_from_pbmsg(const ::proto_ff::Sheet_huoyuedureward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_huoyuedureward_s));
	huoyuedureward_List.SetSize(msg.huoyuedureward_list_size() > huoyuedureward_List.GetMaxSize() ? huoyuedureward_List.GetMaxSize() : msg.huoyuedureward_list_size());
	for(int32_t i = 0; i < (int32_t)huoyuedureward_List.GetSize(); ++i) {
		const ::proto_ff::huoyuedureward & temp_huoyuedureward_list = msg.huoyuedureward_list(i);
		huoyuedureward_List[i].read_from_pbmsg(temp_huoyuedureward_list);
	}
}

huoyueduactive_s::huoyueduactive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int huoyueduactive_s::CreateInit() {
	id = (int64_t)0;
	type = (int32_t)0;
	funciontID = (int64_t)0;
	countRule = (int32_t)0;
	number = (int32_t)0;
	viptype = (int32_t)0;
	otherNum = (int32_t)0;
	eachScore = (int32_t)0;
	activityNum = (int32_t)0;
	cycle = (int32_t)0;
	return 0;
}

int huoyueduactive_s::ResumeInit() {
	return 0;
}

void huoyueduactive_s::write_to_pbmsg(::proto_ff::huoyueduactive & msg) const {
	msg.set_id((int64_t)id);
	msg.set_name((const char*)name.Get());
	msg.set_type((int32_t)type);
	msg.set_args((const char*)args.Get());
	msg.set_funciontid((int64_t)funciontID);
	msg.set_countrule((int32_t)countRule);
	msg.set_countparam((const char*)countParam.Get());
	msg.set_number((int32_t)number);
	msg.set_viptype((int32_t)viptype);
	msg.set_othernum((int32_t)otherNum);
	msg.set_eachscore((int32_t)eachScore);
	msg.set_activitynum((int32_t)activityNum);
	msg.set_cycle((int32_t)cycle);
}

void huoyueduactive_s::read_from_pbmsg(const ::proto_ff::huoyueduactive & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct huoyueduactive_s));
	id = msg.id();
	name.Copy(msg.name());
	type = msg.type();
	args.Copy(msg.args());
	funciontID = msg.funciontid();
	countRule = msg.countrule();
	countParam.Copy(msg.countparam());
	number = msg.number();
	viptype = msg.viptype();
	otherNum = msg.othernum();
	eachScore = msg.eachscore();
	activityNum = msg.activitynum();
	cycle = msg.cycle();
}

Sheet_huoyueduactive_s::Sheet_huoyueduactive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_huoyueduactive_s::CreateInit() {
	return 0;
}

int Sheet_huoyueduactive_s::ResumeInit() {
	return 0;
}

void Sheet_huoyueduactive_s::write_to_pbmsg(::proto_ff::Sheet_huoyueduactive & msg) const {
	for(int32_t i = 0; i < (int32_t)huoyueduactive_List.GetSize() && i < huoyueduactive_List.GetMaxSize(); ++i) {
		::proto_ff::huoyueduactive* temp_huoyueduactive_list = msg.add_huoyueduactive_list();
		huoyueduactive_List[i].write_to_pbmsg(*temp_huoyueduactive_list);
	}
}

void Sheet_huoyueduactive_s::read_from_pbmsg(const ::proto_ff::Sheet_huoyueduactive & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_huoyueduactive_s));
	huoyueduactive_List.SetSize(msg.huoyueduactive_list_size() > huoyueduactive_List.GetMaxSize() ? huoyueduactive_List.GetMaxSize() : msg.huoyueduactive_list_size());
	for(int32_t i = 0; i < (int32_t)huoyueduactive_List.GetSize(); ++i) {
		const ::proto_ff::huoyueduactive & temp_huoyueduactive_list = msg.huoyueduactive_list(i);
		huoyueduactive_List[i].read_from_pbmsg(temp_huoyueduactive_list);
	}
}

}