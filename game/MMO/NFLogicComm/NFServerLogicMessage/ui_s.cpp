#include "ui_s.h"

namespace proto_ff_s {

uieffect_s::uieffect_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int uieffect_s::CreateInit() {
	id = (int64_t)0;
	time = (int32_t)0;
	return 0;
}

int uieffect_s::ResumeInit() {
	return 0;
}

void uieffect_s::write_to_pbmsg(::proto_ff::uieffect & msg) const {
	msg.set_id((int64_t)id);
	msg.set_time((int32_t)time);
}

void uieffect_s::read_from_pbmsg(const ::proto_ff::uieffect & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct uieffect_s));
	id = msg.id();
	time = msg.time();
}

Sheet_uieffect_s::Sheet_uieffect_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_uieffect_s::CreateInit() {
	return 0;
}

int Sheet_uieffect_s::ResumeInit() {
	return 0;
}

void Sheet_uieffect_s::write_to_pbmsg(::proto_ff::Sheet_uieffect & msg) const {
	for(int32_t i = 0; i < (int32_t)uieffect_List.GetSize() && i < uieffect_List.GetMaxSize(); ++i) {
		::proto_ff::uieffect* temp_uieffect_list = msg.add_uieffect_list();
		uieffect_List[i].write_to_pbmsg(*temp_uieffect_list);
	}
}

void Sheet_uieffect_s::read_from_pbmsg(const ::proto_ff::Sheet_uieffect & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_uieffect_s));
	uieffect_List.SetSize(msg.uieffect_list_size() > uieffect_List.GetMaxSize() ? uieffect_List.GetMaxSize() : msg.uieffect_list_size());
	for(int32_t i = 0; i < (int32_t)uieffect_List.GetSize(); ++i) {
		const ::proto_ff::uieffect & temp_uieffect_list = msg.uieffect_list(i);
		uieffect_List[i].read_from_pbmsg(temp_uieffect_list);
	}
}

}