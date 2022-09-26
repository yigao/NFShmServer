#include "snowballWar_s.h"

namespace proto_ff_s {

snowballWarcons_s::snowballWarcons_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int snowballWarcons_s::CreateInit() {
	ID = (int32_t)0;
	valuedata = (int64_t)0;
	return 0;
}

int snowballWarcons_s::ResumeInit() {
	return 0;
}

void snowballWarcons_s::write_to_pbmsg(::proto_ff::snowballWarcons & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_valuedata((int64_t)valuedata);
	msg.set_stringdata((const char*)stringdata.Get());
}

void snowballWarcons_s::read_from_pbmsg(const ::proto_ff::snowballWarcons & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct snowballWarcons_s));
	ID = msg.id();
	valuedata = msg.valuedata();
	stringdata.Copy(msg.stringdata());
}

Sheet_snowballWarcons_s::Sheet_snowballWarcons_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_snowballWarcons_s::CreateInit() {
	return 0;
}

int Sheet_snowballWarcons_s::ResumeInit() {
	return 0;
}

void Sheet_snowballWarcons_s::write_to_pbmsg(::proto_ff::Sheet_snowballWarcons & msg) const {
	for(int32_t i = 0; i < (int32_t)snowballWarcons_List.GetSize() && i < snowballWarcons_List.GetMaxSize(); ++i) {
		::proto_ff::snowballWarcons* temp_snowballwarcons_list = msg.add_snowballwarcons_list();
		snowballWarcons_List[i].write_to_pbmsg(*temp_snowballwarcons_list);
	}
}

void Sheet_snowballWarcons_s::read_from_pbmsg(const ::proto_ff::Sheet_snowballWarcons & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_snowballWarcons_s));
	snowballWarcons_List.SetSize(msg.snowballwarcons_list_size() > snowballWarcons_List.GetMaxSize() ? snowballWarcons_List.GetMaxSize() : msg.snowballwarcons_list_size());
	for(int32_t i = 0; i < (int32_t)snowballWarcons_List.GetSize(); ++i) {
		const ::proto_ff::snowballWarcons & temp_snowballwarcons_list = msg.snowballwarcons_list(i);
		snowballWarcons_List[i].read_from_pbmsg(temp_snowballwarcons_list);
	}
}

}