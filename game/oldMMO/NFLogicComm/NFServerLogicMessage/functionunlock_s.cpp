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

}