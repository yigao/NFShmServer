#include "constant_s.h"

namespace proto_ff_s {

constantconstant_s::constantconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int constantconstant_s::CreateInit() {
	constantid = (int32_t)0;
	constantdata = (int64_t)0;
	return 0;
}

int constantconstant_s::ResumeInit() {
	return 0;
}

void constantconstant_s::write_to_pbmsg(::proto_ff::constantconstant & msg) const {
	msg.set_constantid((int32_t)constantid);
	msg.set_constantdata((int64_t)constantdata);
	msg.set_stringdata((const char*)stringdata.Get());
}

void constantconstant_s::read_from_pbmsg(const ::proto_ff::constantconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct constantconstant_s));
	constantid = msg.constantid();
	constantdata = msg.constantdata();
	stringdata.Copy(msg.stringdata());
}

Sheet_constantconstant_s::Sheet_constantconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_constantconstant_s::CreateInit() {
	return 0;
}

int Sheet_constantconstant_s::ResumeInit() {
	return 0;
}

void Sheet_constantconstant_s::write_to_pbmsg(::proto_ff::Sheet_constantconstant & msg) const {
	for(int32_t i = 0; i < (int32_t)constantconstant_List.GetSize() && i < constantconstant_List.GetMaxSize(); ++i) {
		::proto_ff::constantconstant* temp_constantconstant_list = msg.add_constantconstant_list();
		constantconstant_List[i].write_to_pbmsg(*temp_constantconstant_list);
	}
}

void Sheet_constantconstant_s::read_from_pbmsg(const ::proto_ff::Sheet_constantconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_constantconstant_s));
	constantconstant_List.SetSize(msg.constantconstant_list_size() > constantconstant_List.GetMaxSize() ? constantconstant_List.GetMaxSize() : msg.constantconstant_list_size());
	for(int32_t i = 0; i < (int32_t)constantconstant_List.GetSize(); ++i) {
		const ::proto_ff::constantconstant & temp_constantconstant_list = msg.constantconstant_list(i);
		constantconstant_List[i].read_from_pbmsg(temp_constantconstant_list);
	}
}

}