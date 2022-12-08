#include "functionunlock_s.h"

namespace proto_ff_s {

functionunlockfunctionUnlock_s::functionunlockfunctionUnlock_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int functionunlockfunctionUnlock_s::CreateInit() {
	functionId = (int32_t)0;
	openDaily = (int32_t)0;
	openType = (int32_t)0;
	openVal = (int64_t)0;
	iconOpenVal = (int32_t)0;
	belong = (int32_t)0;
	return 0;
}

int functionunlockfunctionUnlock_s::ResumeInit() {
	return 0;
}

void functionunlockfunctionUnlock_s::write_to_pbmsg(::proto_ff::functionunlockfunctionUnlock & msg) const {
	msg.set_functionid((int32_t)functionId);
	msg.set_opendaily((int32_t)openDaily);
	msg.set_opentype((int32_t)openType);
	msg.set_openval((int64_t)openVal);
	msg.set_iconopenval((int32_t)iconOpenVal);
	msg.set_belong((int32_t)belong);
}

void functionunlockfunctionUnlock_s::read_from_pbmsg(const ::proto_ff::functionunlockfunctionUnlock & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct functionunlockfunctionUnlock_s));
	functionId = msg.functionid();
	openDaily = msg.opendaily();
	openType = msg.opentype();
	openVal = msg.openval();
	iconOpenVal = msg.iconopenval();
	belong = msg.belong();
}

Sheet_functionunlockfunctionUnlock_s::Sheet_functionunlockfunctionUnlock_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_functionunlockfunctionUnlock_s::CreateInit() {
	return 0;
}

int Sheet_functionunlockfunctionUnlock_s::ResumeInit() {
	return 0;
}

void Sheet_functionunlockfunctionUnlock_s::write_to_pbmsg(::proto_ff::Sheet_functionunlockfunctionUnlock & msg) const {
	for(int32_t i = 0; i < (int32_t)functionunlockfunctionUnlock_List.GetSize() && i < functionunlockfunctionUnlock_List.GetMaxSize(); ++i) {
		::proto_ff::functionunlockfunctionUnlock* temp_functionunlockfunctionunlock_list = msg.add_functionunlockfunctionunlock_list();
		functionunlockfunctionUnlock_List[i].write_to_pbmsg(*temp_functionunlockfunctionunlock_list);
	}
}

void Sheet_functionunlockfunctionUnlock_s::read_from_pbmsg(const ::proto_ff::Sheet_functionunlockfunctionUnlock & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_functionunlockfunctionUnlock_s));
	functionunlockfunctionUnlock_List.SetSize(msg.functionunlockfunctionunlock_list_size() > functionunlockfunctionUnlock_List.GetMaxSize() ? functionunlockfunctionUnlock_List.GetMaxSize() : msg.functionunlockfunctionunlock_list_size());
	for(int32_t i = 0; i < (int32_t)functionunlockfunctionUnlock_List.GetSize(); ++i) {
		const ::proto_ff::functionunlockfunctionUnlock & temp_functionunlockfunctionunlock_list = msg.functionunlockfunctionunlock_list(i);
		functionunlockfunctionUnlock_List[i].read_from_pbmsg(temp_functionunlockfunctionunlock_list);
	}
}

functionunlockpreview_s::functionunlockpreview_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int functionunlockpreview_s::CreateInit() {
	functionId = (int32_t)0;
	rewardItem = (int32_t)0;
	rewardNum = (int32_t)0;
	return 0;
}

int functionunlockpreview_s::ResumeInit() {
	return 0;
}

void functionunlockpreview_s::write_to_pbmsg(::proto_ff::functionunlockpreview & msg) const {
	msg.set_functionid((int32_t)functionId);
	msg.set_rewarditem((int32_t)rewardItem);
	msg.set_rewardnum((int32_t)rewardNum);
}

void functionunlockpreview_s::read_from_pbmsg(const ::proto_ff::functionunlockpreview & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct functionunlockpreview_s));
	functionId = msg.functionid();
	rewardItem = msg.rewarditem();
	rewardNum = msg.rewardnum();
}

Sheet_functionunlockpreview_s::Sheet_functionunlockpreview_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_functionunlockpreview_s::CreateInit() {
	return 0;
}

int Sheet_functionunlockpreview_s::ResumeInit() {
	return 0;
}

void Sheet_functionunlockpreview_s::write_to_pbmsg(::proto_ff::Sheet_functionunlockpreview & msg) const {
	for(int32_t i = 0; i < (int32_t)functionunlockpreview_List.GetSize() && i < functionunlockpreview_List.GetMaxSize(); ++i) {
		::proto_ff::functionunlockpreview* temp_functionunlockpreview_list = msg.add_functionunlockpreview_list();
		functionunlockpreview_List[i].write_to_pbmsg(*temp_functionunlockpreview_list);
	}
}

void Sheet_functionunlockpreview_s::read_from_pbmsg(const ::proto_ff::Sheet_functionunlockpreview & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_functionunlockpreview_s));
	functionunlockpreview_List.SetSize(msg.functionunlockpreview_list_size() > functionunlockpreview_List.GetMaxSize() ? functionunlockpreview_List.GetMaxSize() : msg.functionunlockpreview_list_size());
	for(int32_t i = 0; i < (int32_t)functionunlockpreview_List.GetSize(); ++i) {
		const ::proto_ff::functionunlockpreview & temp_functionunlockpreview_list = msg.functionunlockpreview_list(i);
		functionunlockpreview_List[i].read_from_pbmsg(temp_functionunlockpreview_list);
	}
}

}