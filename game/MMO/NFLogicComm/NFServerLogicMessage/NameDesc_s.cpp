#include "NameDesc_s.h"

namespace proto_ff_s {

NameDesc_s::NameDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int NameDesc_s::CreateInit() {
	id = (uint64_t)0;
	return 0;
}

int NameDesc_s::ResumeInit() {
	return 0;
}

void NameDesc_s::write_to_pbmsg(::proto_ff::NameDesc & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_name((const char*)name.Get());
}

void NameDesc_s::read_from_pbmsg(const ::proto_ff::NameDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct NameDesc_s));
	id = msg.id();
	name.Copy(msg.name());
}

Sheet_NameDesc_s::Sheet_NameDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_NameDesc_s::CreateInit() {
	return 0;
}

int Sheet_NameDesc_s::ResumeInit() {
	return 0;
}

void Sheet_NameDesc_s::write_to_pbmsg(::proto_ff::Sheet_NameDesc & msg) const {
	for(int32_t i = 0; i < (int32_t)NameDesc_List.GetSize() && i < NameDesc_List.GetMaxSize(); ++i) {
		::proto_ff::NameDesc* temp_namedesc_list = msg.add_namedesc_list();
		NameDesc_List[i].write_to_pbmsg(*temp_namedesc_list);
	}
}

void Sheet_NameDesc_s::read_from_pbmsg(const ::proto_ff::Sheet_NameDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_NameDesc_s));
	NameDesc_List.SetSize(msg.namedesc_list_size() > NameDesc_List.GetMaxSize() ? NameDesc_List.GetMaxSize() : msg.namedesc_list_size());
	for(int32_t i = 0; i < (int32_t)NameDesc_List.GetSize(); ++i) {
		const ::proto_ff::NameDesc & temp_namedesc_list = msg.namedesc_list(i);
		NameDesc_List[i].read_from_pbmsg(temp_namedesc_list);
	}
}

}