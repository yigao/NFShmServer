#include "rechargeReturn_s.h"

namespace proto_ff_s {

rechargeReturnrechargeReturn_s::rechargeReturnrechargeReturn_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rechargeReturnrechargeReturn_s::CreateInit() {
	id = (int32_t)0;
	group = (int32_t)0;
	minLine = (int32_t)0;
	diamondRRatio = (int32_t)0;
	timeID = (int32_t)0;
	mailID = (int64_t)0;
	return 0;
}

int rechargeReturnrechargeReturn_s::ResumeInit() {
	return 0;
}

void rechargeReturnrechargeReturn_s::write_to_pbmsg(::proto_ff::rechargeReturnrechargeReturn & msg) const {
	msg.set_id((int32_t)id);
	msg.set_group((int32_t)group);
	msg.set_minline((int32_t)minLine);
	msg.set_diamondrratio((int32_t)diamondRRatio);
	msg.set_timeid((int32_t)timeID);
	msg.set_mailid((int64_t)mailID);
}

void rechargeReturnrechargeReturn_s::read_from_pbmsg(const ::proto_ff::rechargeReturnrechargeReturn & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rechargeReturnrechargeReturn_s));
	id = msg.id();
	group = msg.group();
	minLine = msg.minline();
	diamondRRatio = msg.diamondrratio();
	timeID = msg.timeid();
	mailID = msg.mailid();
}

Sheet_rechargeReturnrechargeReturn_s::Sheet_rechargeReturnrechargeReturn_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_rechargeReturnrechargeReturn_s::CreateInit() {
	return 0;
}

int Sheet_rechargeReturnrechargeReturn_s::ResumeInit() {
	return 0;
}

void Sheet_rechargeReturnrechargeReturn_s::write_to_pbmsg(::proto_ff::Sheet_rechargeReturnrechargeReturn & msg) const {
	for(int32_t i = 0; i < (int32_t)rechargeReturnrechargeReturn_List.GetSize() && i < rechargeReturnrechargeReturn_List.GetMaxSize(); ++i) {
		::proto_ff::rechargeReturnrechargeReturn* temp_rechargereturnrechargereturn_list = msg.add_rechargereturnrechargereturn_list();
		rechargeReturnrechargeReturn_List[i].write_to_pbmsg(*temp_rechargereturnrechargereturn_list);
	}
}

void Sheet_rechargeReturnrechargeReturn_s::read_from_pbmsg(const ::proto_ff::Sheet_rechargeReturnrechargeReturn & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_rechargeReturnrechargeReturn_s));
	rechargeReturnrechargeReturn_List.SetSize(msg.rechargereturnrechargereturn_list_size() > rechargeReturnrechargeReturn_List.GetMaxSize() ? rechargeReturnrechargeReturn_List.GetMaxSize() : msg.rechargereturnrechargereturn_list_size());
	for(int32_t i = 0; i < (int32_t)rechargeReturnrechargeReturn_List.GetSize(); ++i) {
		const ::proto_ff::rechargeReturnrechargeReturn & temp_rechargereturnrechargereturn_list = msg.rechargereturnrechargereturn_list(i);
		rechargeReturnrechargeReturn_List[i].read_from_pbmsg(temp_rechargereturnrechargereturn_list);
	}
}

rechargeReturntime_s::rechargeReturntime_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rechargeReturntime_s::CreateInit() {
	id = (int32_t)0;
	timeType = (int32_t)0;
	return 0;
}

int rechargeReturntime_s::ResumeInit() {
	return 0;
}

void rechargeReturntime_s::write_to_pbmsg(::proto_ff::rechargeReturntime & msg) const {
	msg.set_id((int32_t)id);
	msg.set_timetype((int32_t)timeType);
	msg.set_timea((const char*)timeA.Get());
	msg.set_timeb((const char*)timeB.Get());
}

void rechargeReturntime_s::read_from_pbmsg(const ::proto_ff::rechargeReturntime & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rechargeReturntime_s));
	id = msg.id();
	timeType = msg.timetype();
	timeA.Copy(msg.timea());
	timeB.Copy(msg.timeb());
}

Sheet_rechargeReturntime_s::Sheet_rechargeReturntime_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_rechargeReturntime_s::CreateInit() {
	return 0;
}

int Sheet_rechargeReturntime_s::ResumeInit() {
	return 0;
}

void Sheet_rechargeReturntime_s::write_to_pbmsg(::proto_ff::Sheet_rechargeReturntime & msg) const {
	for(int32_t i = 0; i < (int32_t)rechargeReturntime_List.GetSize() && i < rechargeReturntime_List.GetMaxSize(); ++i) {
		::proto_ff::rechargeReturntime* temp_rechargereturntime_list = msg.add_rechargereturntime_list();
		rechargeReturntime_List[i].write_to_pbmsg(*temp_rechargereturntime_list);
	}
}

void Sheet_rechargeReturntime_s::read_from_pbmsg(const ::proto_ff::Sheet_rechargeReturntime & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_rechargeReturntime_s));
	rechargeReturntime_List.SetSize(msg.rechargereturntime_list_size() > rechargeReturntime_List.GetMaxSize() ? rechargeReturntime_List.GetMaxSize() : msg.rechargereturntime_list_size());
	for(int32_t i = 0; i < (int32_t)rechargeReturntime_List.GetSize(); ++i) {
		const ::proto_ff::rechargeReturntime & temp_rechargereturntime_list = msg.rechargereturntime_list(i);
		rechargeReturntime_List[i].read_from_pbmsg(temp_rechargereturntime_list);
	}
}

rechargeReturncontinuousReturn_s::rechargeReturncontinuousReturn_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rechargeReturncontinuousReturn_s::CreateInit() {
	Gear = (int32_t)0;
	boxid = (int64_t)0;
	return 0;
}

int rechargeReturncontinuousReturn_s::ResumeInit() {
	return 0;
}

void rechargeReturncontinuousReturn_s::write_to_pbmsg(::proto_ff::rechargeReturncontinuousReturn & msg) const {
	msg.set_gear((int32_t)Gear);
	msg.set_boxid((int64_t)boxid);
}

void rechargeReturncontinuousReturn_s::read_from_pbmsg(const ::proto_ff::rechargeReturncontinuousReturn & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rechargeReturncontinuousReturn_s));
	Gear = msg.gear();
	boxid = msg.boxid();
}

Sheet_rechargeReturncontinuousReturn_s::Sheet_rechargeReturncontinuousReturn_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_rechargeReturncontinuousReturn_s::CreateInit() {
	return 0;
}

int Sheet_rechargeReturncontinuousReturn_s::ResumeInit() {
	return 0;
}

void Sheet_rechargeReturncontinuousReturn_s::write_to_pbmsg(::proto_ff::Sheet_rechargeReturncontinuousReturn & msg) const {
	for(int32_t i = 0; i < (int32_t)rechargeReturncontinuousReturn_List.GetSize() && i < rechargeReturncontinuousReturn_List.GetMaxSize(); ++i) {
		::proto_ff::rechargeReturncontinuousReturn* temp_rechargereturncontinuousreturn_list = msg.add_rechargereturncontinuousreturn_list();
		rechargeReturncontinuousReturn_List[i].write_to_pbmsg(*temp_rechargereturncontinuousreturn_list);
	}
}

void Sheet_rechargeReturncontinuousReturn_s::read_from_pbmsg(const ::proto_ff::Sheet_rechargeReturncontinuousReturn & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_rechargeReturncontinuousReturn_s));
	rechargeReturncontinuousReturn_List.SetSize(msg.rechargereturncontinuousreturn_list_size() > rechargeReturncontinuousReturn_List.GetMaxSize() ? rechargeReturncontinuousReturn_List.GetMaxSize() : msg.rechargereturncontinuousreturn_list_size());
	for(int32_t i = 0; i < (int32_t)rechargeReturncontinuousReturn_List.GetSize(); ++i) {
		const ::proto_ff::rechargeReturncontinuousReturn & temp_rechargereturncontinuousreturn_list = msg.rechargereturncontinuousreturn_list(i);
		rechargeReturncontinuousReturn_List[i].read_from_pbmsg(temp_rechargereturncontinuousreturn_list);
	}
}

rechargeReturnrechargeTrigger_s::rechargeReturnrechargeTrigger_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rechargeReturnrechargeTrigger_s::CreateInit() {
	id = (int32_t)0;
	timeType = (int32_t)0;
	reset = (int32_t)0;
	triggerType = (int32_t)0;
	boxId = (int64_t)0;
	mailId = (int64_t)0;
	return 0;
}

int rechargeReturnrechargeTrigger_s::ResumeInit() {
	return 0;
}

void rechargeReturnrechargeTrigger_s::write_to_pbmsg(::proto_ff::rechargeReturnrechargeTrigger & msg) const {
	msg.set_id((int32_t)id);
	msg.set_timetype((int32_t)timeType);
	msg.set_timea((const char*)timeA.Get());
	msg.set_timeb((const char*)timeB.Get());
	msg.set_reset((int32_t)reset);
	msg.set_triggertype((int32_t)triggerType);
	msg.set_triggervalue((const char*)TriggerValue.Get());
	msg.set_boxid((int64_t)boxId);
	msg.set_mailid((int64_t)mailId);
}

void rechargeReturnrechargeTrigger_s::read_from_pbmsg(const ::proto_ff::rechargeReturnrechargeTrigger & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rechargeReturnrechargeTrigger_s));
	id = msg.id();
	timeType = msg.timetype();
	timeA.Copy(msg.timea());
	timeB.Copy(msg.timeb());
	reset = msg.reset();
	triggerType = msg.triggertype();
	TriggerValue.Copy(msg.triggervalue());
	boxId = msg.boxid();
	mailId = msg.mailid();
}

Sheet_rechargeReturnrechargeTrigger_s::Sheet_rechargeReturnrechargeTrigger_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_rechargeReturnrechargeTrigger_s::CreateInit() {
	return 0;
}

int Sheet_rechargeReturnrechargeTrigger_s::ResumeInit() {
	return 0;
}

void Sheet_rechargeReturnrechargeTrigger_s::write_to_pbmsg(::proto_ff::Sheet_rechargeReturnrechargeTrigger & msg) const {
	for(int32_t i = 0; i < (int32_t)rechargeReturnrechargeTrigger_List.GetSize() && i < rechargeReturnrechargeTrigger_List.GetMaxSize(); ++i) {
		::proto_ff::rechargeReturnrechargeTrigger* temp_rechargereturnrechargetrigger_list = msg.add_rechargereturnrechargetrigger_list();
		rechargeReturnrechargeTrigger_List[i].write_to_pbmsg(*temp_rechargereturnrechargetrigger_list);
	}
}

void Sheet_rechargeReturnrechargeTrigger_s::read_from_pbmsg(const ::proto_ff::Sheet_rechargeReturnrechargeTrigger & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_rechargeReturnrechargeTrigger_s));
	rechargeReturnrechargeTrigger_List.SetSize(msg.rechargereturnrechargetrigger_list_size() > rechargeReturnrechargeTrigger_List.GetMaxSize() ? rechargeReturnrechargeTrigger_List.GetMaxSize() : msg.rechargereturnrechargetrigger_list_size());
	for(int32_t i = 0; i < (int32_t)rechargeReturnrechargeTrigger_List.GetSize(); ++i) {
		const ::proto_ff::rechargeReturnrechargeTrigger & temp_rechargereturnrechargetrigger_list = msg.rechargereturnrechargetrigger_list(i);
		rechargeReturnrechargeTrigger_List[i].read_from_pbmsg(temp_rechargereturnrechargetrigger_list);
	}
}

rechargeReturnconstant_s::rechargeReturnconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rechargeReturnconstant_s::CreateInit() {
	constantid = (int64_t)0;
	constantdata = (int64_t)0;
	return 0;
}

int rechargeReturnconstant_s::ResumeInit() {
	return 0;
}

void rechargeReturnconstant_s::write_to_pbmsg(::proto_ff::rechargeReturnconstant & msg) const {
	msg.set_constantid((int64_t)constantid);
	msg.set_constantdata((int64_t)constantdata);
	msg.set_stringdata((const char*)stringdata.Get());
}

void rechargeReturnconstant_s::read_from_pbmsg(const ::proto_ff::rechargeReturnconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rechargeReturnconstant_s));
	constantid = msg.constantid();
	constantdata = msg.constantdata();
	stringdata.Copy(msg.stringdata());
}

Sheet_rechargeReturnconstant_s::Sheet_rechargeReturnconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_rechargeReturnconstant_s::CreateInit() {
	return 0;
}

int Sheet_rechargeReturnconstant_s::ResumeInit() {
	return 0;
}

void Sheet_rechargeReturnconstant_s::write_to_pbmsg(::proto_ff::Sheet_rechargeReturnconstant & msg) const {
	for(int32_t i = 0; i < (int32_t)rechargeReturnconstant_List.GetSize() && i < rechargeReturnconstant_List.GetMaxSize(); ++i) {
		::proto_ff::rechargeReturnconstant* temp_rechargereturnconstant_list = msg.add_rechargereturnconstant_list();
		rechargeReturnconstant_List[i].write_to_pbmsg(*temp_rechargereturnconstant_list);
	}
}

void Sheet_rechargeReturnconstant_s::read_from_pbmsg(const ::proto_ff::Sheet_rechargeReturnconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_rechargeReturnconstant_s));
	rechargeReturnconstant_List.SetSize(msg.rechargereturnconstant_list_size() > rechargeReturnconstant_List.GetMaxSize() ? rechargeReturnconstant_List.GetMaxSize() : msg.rechargereturnconstant_list_size());
	for(int32_t i = 0; i < (int32_t)rechargeReturnconstant_List.GetSize(); ++i) {
		const ::proto_ff::rechargeReturnconstant & temp_rechargereturnconstant_list = msg.rechargereturnconstant_list(i);
		rechargeReturnconstant_List[i].read_from_pbmsg(temp_rechargereturnconstant_list);
	}
}

}