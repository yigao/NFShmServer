#include "button_s.h"

namespace proto_ff_s {

buttonbutton_s::buttonbutton_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int buttonbutton_s::CreateInit() {
	id = (int64_t)0;
	time = (int32_t)0;
	return 0;
}

int buttonbutton_s::ResumeInit() {
	return 0;
}

void buttonbutton_s::write_to_pbmsg(::proto_ff::buttonbutton & msg) const {
	msg.set_id((int64_t)id);
	msg.set_time((int32_t)time);
}

void buttonbutton_s::read_from_pbmsg(const ::proto_ff::buttonbutton & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct buttonbutton_s));
	id = msg.id();
	time = msg.time();
}

Sheet_buttonbutton_s::Sheet_buttonbutton_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_buttonbutton_s::CreateInit() {
	return 0;
}

int Sheet_buttonbutton_s::ResumeInit() {
	return 0;
}

void Sheet_buttonbutton_s::write_to_pbmsg(::proto_ff::Sheet_buttonbutton & msg) const {
	for(int32_t i = 0; i < (int32_t)buttonbutton_List.GetSize() && i < buttonbutton_List.GetMaxSize(); ++i) {
		::proto_ff::buttonbutton* temp_buttonbutton_list = msg.add_buttonbutton_list();
		buttonbutton_List[i].write_to_pbmsg(*temp_buttonbutton_list);
	}
}

void Sheet_buttonbutton_s::read_from_pbmsg(const ::proto_ff::Sheet_buttonbutton & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_buttonbutton_s));
	buttonbutton_List.SetSize(msg.buttonbutton_list_size() > buttonbutton_List.GetMaxSize() ? buttonbutton_List.GetMaxSize() : msg.buttonbutton_list_size());
	for(int32_t i = 0; i < (int32_t)buttonbutton_List.GetSize(); ++i) {
		const ::proto_ff::buttonbutton & temp_buttonbutton_list = msg.buttonbutton_list(i);
		buttonbutton_List[i].read_from_pbmsg(temp_buttonbutton_list);
	}
}

}