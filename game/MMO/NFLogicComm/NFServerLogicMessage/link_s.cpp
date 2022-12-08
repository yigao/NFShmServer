#include "link_s.h"

namespace proto_ff_s {

linklink_s::linklink_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int linklink_s::CreateInit() {
	id = (int64_t)0;
	functionUnlock = (int32_t)0;
	return 0;
}

int linklink_s::ResumeInit() {
	return 0;
}

void linklink_s::write_to_pbmsg(::proto_ff::linklink & msg) const {
	msg.set_id((int64_t)id);
	msg.set_icon((const char*)icon.Get());
	msg.set_dbargs((const char*)dbArgs.Get());
	msg.set_argsm((const char*)argsm.Get());
	msg.set_functionunlock((int32_t)functionUnlock);
	msg.set_linknpc((const char*)linkNpc.Get());
}

void linklink_s::read_from_pbmsg(const ::proto_ff::linklink & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct linklink_s));
	id = msg.id();
	icon.Copy(msg.icon());
	dbArgs.Copy(msg.dbargs());
	argsm.Copy(msg.argsm());
	functionUnlock = msg.functionunlock();
	linkNpc.Copy(msg.linknpc());
}

Sheet_linklink_s::Sheet_linklink_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_linklink_s::CreateInit() {
	return 0;
}

int Sheet_linklink_s::ResumeInit() {
	return 0;
}

void Sheet_linklink_s::write_to_pbmsg(::proto_ff::Sheet_linklink & msg) const {
	for(int32_t i = 0; i < (int32_t)linklink_List.GetSize() && i < linklink_List.GetMaxSize(); ++i) {
		::proto_ff::linklink* temp_linklink_list = msg.add_linklink_list();
		linklink_List[i].write_to_pbmsg(*temp_linklink_list);
	}
}

void Sheet_linklink_s::read_from_pbmsg(const ::proto_ff::Sheet_linklink & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_linklink_s));
	linklink_List.SetSize(msg.linklink_list_size() > linklink_List.GetMaxSize() ? linklink_List.GetMaxSize() : msg.linklink_list_size());
	for(int32_t i = 0; i < (int32_t)linklink_List.GetSize(); ++i) {
		const ::proto_ff::linklink & temp_linklink_list = msg.linklink_list(i);
		linklink_List[i].read_from_pbmsg(temp_linklink_list);
	}
}

}