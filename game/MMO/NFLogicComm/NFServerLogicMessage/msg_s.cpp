#include "msg_s.h"

namespace proto_ff_s {

msgphpmsg_s::msgphpmsg_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int msgphpmsg_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int msgphpmsg_s::ResumeInit() {
	return 0;
}

void msgphpmsg_s::write_to_pbmsg(::proto_ff::msgphpmsg & msg) const {
	msg.set_id((int32_t)id);
	msg.set_content((const char*)content.Get());
	msg.set_note((const char*)note.Get());
}

void msgphpmsg_s::read_from_pbmsg(const ::proto_ff::msgphpmsg & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct msgphpmsg_s));
	id = msg.id();
	content.Copy(msg.content());
	note.Copy(msg.note());
}

Sheet_msgphpmsg_s::Sheet_msgphpmsg_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_msgphpmsg_s::CreateInit() {
	return 0;
}

int Sheet_msgphpmsg_s::ResumeInit() {
	return 0;
}

void Sheet_msgphpmsg_s::write_to_pbmsg(::proto_ff::Sheet_msgphpmsg & msg) const {
	for(int32_t i = 0; i < (int32_t)msgphpmsg_List.GetSize() && i < msgphpmsg_List.GetMaxSize(); ++i) {
		::proto_ff::msgphpmsg* temp_msgphpmsg_list = msg.add_msgphpmsg_list();
		msgphpmsg_List[i].write_to_pbmsg(*temp_msgphpmsg_list);
	}
}

void Sheet_msgphpmsg_s::read_from_pbmsg(const ::proto_ff::Sheet_msgphpmsg & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_msgphpmsg_s));
	msgphpmsg_List.SetSize(msg.msgphpmsg_list_size() > msgphpmsg_List.GetMaxSize() ? msgphpmsg_List.GetMaxSize() : msg.msgphpmsg_list_size());
	for(int32_t i = 0; i < (int32_t)msgphpmsg_List.GetSize(); ++i) {
		const ::proto_ff::msgphpmsg & temp_msgphpmsg_list = msg.msgphpmsg_list(i);
		msgphpmsg_List[i].read_from_pbmsg(temp_msgphpmsg_list);
	}
}

}