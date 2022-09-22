#include "ConstDesc_s.h"

namespace proto_ff_s {

ConstDesc_s::ConstDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ConstDesc_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int ConstDesc_s::ResumeInit() {
	return 0;
}

void ConstDesc_s::write_to_pbmsg(::proto_ff::ConstDesc & msg) const {
	msg.set_id((int32_t)id);
	msg.set_value((const char*)value.Get());
}

void ConstDesc_s::read_from_pbmsg(const ::proto_ff::ConstDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ConstDesc_s));
	id = msg.id();
	value.Copy(msg.value());
}

Sheet_ConstDesc_s::Sheet_ConstDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ConstDesc_s::CreateInit() {
	return 0;
}

int Sheet_ConstDesc_s::ResumeInit() {
	return 0;
}

void Sheet_ConstDesc_s::write_to_pbmsg(::proto_ff::Sheet_ConstDesc & msg) const {
	for(int32_t i = 0; i < (int32_t)ConstDesc_List.GetSize() && i < ConstDesc_List.GetMaxSize(); ++i) {
		::proto_ff::ConstDesc* temp_constdesc_list = msg.add_constdesc_list();
		ConstDesc_List[i].write_to_pbmsg(*temp_constdesc_list);
	}
}

void Sheet_ConstDesc_s::read_from_pbmsg(const ::proto_ff::Sheet_ConstDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_ConstDesc_s));
	ConstDesc_List.SetSize(msg.constdesc_list_size() > ConstDesc_List.GetMaxSize() ? ConstDesc_List.GetMaxSize() : msg.constdesc_list_size());
	for(int32_t i = 0; i < (int32_t)ConstDesc_List.GetSize(); ++i) {
		const ::proto_ff::ConstDesc & temp_constdesc_list = msg.constdesc_list(i);
		ConstDesc_List[i].read_from_pbmsg(temp_constdesc_list);
	}
}

}