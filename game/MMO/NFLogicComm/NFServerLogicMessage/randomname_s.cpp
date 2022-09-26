#include "randomname_s.h"

namespace proto_ff_s {

randomnamemanfirst_s::randomnamemanfirst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int randomnamemanfirst_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int randomnamemanfirst_s::ResumeInit() {
	return 0;
}

void randomnamemanfirst_s::write_to_pbmsg(::proto_ff::randomnamemanfirst & msg) const {
	msg.set_id((int32_t)id);
	msg.set_name((const char*)name.Get());
}

void randomnamemanfirst_s::read_from_pbmsg(const ::proto_ff::randomnamemanfirst & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct randomnamemanfirst_s));
	id = msg.id();
	name.Copy(msg.name());
}

Sheet_randomnamemanfirst_s::Sheet_randomnamemanfirst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_randomnamemanfirst_s::CreateInit() {
	return 0;
}

int Sheet_randomnamemanfirst_s::ResumeInit() {
	return 0;
}

void Sheet_randomnamemanfirst_s::write_to_pbmsg(::proto_ff::Sheet_randomnamemanfirst & msg) const {
	for(int32_t i = 0; i < (int32_t)randomnamemanfirst_List.GetSize() && i < randomnamemanfirst_List.GetMaxSize(); ++i) {
		::proto_ff::randomnamemanfirst* temp_randomnamemanfirst_list = msg.add_randomnamemanfirst_list();
		randomnamemanfirst_List[i].write_to_pbmsg(*temp_randomnamemanfirst_list);
	}
}

void Sheet_randomnamemanfirst_s::read_from_pbmsg(const ::proto_ff::Sheet_randomnamemanfirst & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_randomnamemanfirst_s));
	randomnamemanfirst_List.SetSize(msg.randomnamemanfirst_list_size() > randomnamemanfirst_List.GetMaxSize() ? randomnamemanfirst_List.GetMaxSize() : msg.randomnamemanfirst_list_size());
	for(int32_t i = 0; i < (int32_t)randomnamemanfirst_List.GetSize(); ++i) {
		const ::proto_ff::randomnamemanfirst & temp_randomnamemanfirst_list = msg.randomnamemanfirst_list(i);
		randomnamemanfirst_List[i].read_from_pbmsg(temp_randomnamemanfirst_list);
	}
}

randomnamemansecond_s::randomnamemansecond_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int randomnamemansecond_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int randomnamemansecond_s::ResumeInit() {
	return 0;
}

void randomnamemansecond_s::write_to_pbmsg(::proto_ff::randomnamemansecond & msg) const {
	msg.set_id((int32_t)id);
	msg.set_name((const char*)name.Get());
}

void randomnamemansecond_s::read_from_pbmsg(const ::proto_ff::randomnamemansecond & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct randomnamemansecond_s));
	id = msg.id();
	name.Copy(msg.name());
}

Sheet_randomnamemansecond_s::Sheet_randomnamemansecond_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_randomnamemansecond_s::CreateInit() {
	return 0;
}

int Sheet_randomnamemansecond_s::ResumeInit() {
	return 0;
}

void Sheet_randomnamemansecond_s::write_to_pbmsg(::proto_ff::Sheet_randomnamemansecond & msg) const {
	for(int32_t i = 0; i < (int32_t)randomnamemansecond_List.GetSize() && i < randomnamemansecond_List.GetMaxSize(); ++i) {
		::proto_ff::randomnamemansecond* temp_randomnamemansecond_list = msg.add_randomnamemansecond_list();
		randomnamemansecond_List[i].write_to_pbmsg(*temp_randomnamemansecond_list);
	}
}

void Sheet_randomnamemansecond_s::read_from_pbmsg(const ::proto_ff::Sheet_randomnamemansecond & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_randomnamemansecond_s));
	randomnamemansecond_List.SetSize(msg.randomnamemansecond_list_size() > randomnamemansecond_List.GetMaxSize() ? randomnamemansecond_List.GetMaxSize() : msg.randomnamemansecond_list_size());
	for(int32_t i = 0; i < (int32_t)randomnamemansecond_List.GetSize(); ++i) {
		const ::proto_ff::randomnamemansecond & temp_randomnamemansecond_list = msg.randomnamemansecond_list(i);
		randomnamemansecond_List[i].read_from_pbmsg(temp_randomnamemansecond_list);
	}
}

randomnamemanthird_s::randomnamemanthird_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int randomnamemanthird_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int randomnamemanthird_s::ResumeInit() {
	return 0;
}

void randomnamemanthird_s::write_to_pbmsg(::proto_ff::randomnamemanthird & msg) const {
	msg.set_id((int32_t)id);
	msg.set_name((const char*)name.Get());
}

void randomnamemanthird_s::read_from_pbmsg(const ::proto_ff::randomnamemanthird & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct randomnamemanthird_s));
	id = msg.id();
	name.Copy(msg.name());
}

Sheet_randomnamemanthird_s::Sheet_randomnamemanthird_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_randomnamemanthird_s::CreateInit() {
	return 0;
}

int Sheet_randomnamemanthird_s::ResumeInit() {
	return 0;
}

void Sheet_randomnamemanthird_s::write_to_pbmsg(::proto_ff::Sheet_randomnamemanthird & msg) const {
	for(int32_t i = 0; i < (int32_t)randomnamemanthird_List.GetSize() && i < randomnamemanthird_List.GetMaxSize(); ++i) {
		::proto_ff::randomnamemanthird* temp_randomnamemanthird_list = msg.add_randomnamemanthird_list();
		randomnamemanthird_List[i].write_to_pbmsg(*temp_randomnamemanthird_list);
	}
}

void Sheet_randomnamemanthird_s::read_from_pbmsg(const ::proto_ff::Sheet_randomnamemanthird & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_randomnamemanthird_s));
	randomnamemanthird_List.SetSize(msg.randomnamemanthird_list_size() > randomnamemanthird_List.GetMaxSize() ? randomnamemanthird_List.GetMaxSize() : msg.randomnamemanthird_list_size());
	for(int32_t i = 0; i < (int32_t)randomnamemanthird_List.GetSize(); ++i) {
		const ::proto_ff::randomnamemanthird & temp_randomnamemanthird_list = msg.randomnamemanthird_list(i);
		randomnamemanthird_List[i].read_from_pbmsg(temp_randomnamemanthird_list);
	}
}

randomnamewomanfirst_s::randomnamewomanfirst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int randomnamewomanfirst_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int randomnamewomanfirst_s::ResumeInit() {
	return 0;
}

void randomnamewomanfirst_s::write_to_pbmsg(::proto_ff::randomnamewomanfirst & msg) const {
	msg.set_id((int32_t)id);
	msg.set_name((const char*)name.Get());
}

void randomnamewomanfirst_s::read_from_pbmsg(const ::proto_ff::randomnamewomanfirst & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct randomnamewomanfirst_s));
	id = msg.id();
	name.Copy(msg.name());
}

Sheet_randomnamewomanfirst_s::Sheet_randomnamewomanfirst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_randomnamewomanfirst_s::CreateInit() {
	return 0;
}

int Sheet_randomnamewomanfirst_s::ResumeInit() {
	return 0;
}

void Sheet_randomnamewomanfirst_s::write_to_pbmsg(::proto_ff::Sheet_randomnamewomanfirst & msg) const {
	for(int32_t i = 0; i < (int32_t)randomnamewomanfirst_List.GetSize() && i < randomnamewomanfirst_List.GetMaxSize(); ++i) {
		::proto_ff::randomnamewomanfirst* temp_randomnamewomanfirst_list = msg.add_randomnamewomanfirst_list();
		randomnamewomanfirst_List[i].write_to_pbmsg(*temp_randomnamewomanfirst_list);
	}
}

void Sheet_randomnamewomanfirst_s::read_from_pbmsg(const ::proto_ff::Sheet_randomnamewomanfirst & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_randomnamewomanfirst_s));
	randomnamewomanfirst_List.SetSize(msg.randomnamewomanfirst_list_size() > randomnamewomanfirst_List.GetMaxSize() ? randomnamewomanfirst_List.GetMaxSize() : msg.randomnamewomanfirst_list_size());
	for(int32_t i = 0; i < (int32_t)randomnamewomanfirst_List.GetSize(); ++i) {
		const ::proto_ff::randomnamewomanfirst & temp_randomnamewomanfirst_list = msg.randomnamewomanfirst_list(i);
		randomnamewomanfirst_List[i].read_from_pbmsg(temp_randomnamewomanfirst_list);
	}
}

randomnamewomansecond_s::randomnamewomansecond_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int randomnamewomansecond_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int randomnamewomansecond_s::ResumeInit() {
	return 0;
}

void randomnamewomansecond_s::write_to_pbmsg(::proto_ff::randomnamewomansecond & msg) const {
	msg.set_id((int32_t)id);
	msg.set_name((const char*)name.Get());
}

void randomnamewomansecond_s::read_from_pbmsg(const ::proto_ff::randomnamewomansecond & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct randomnamewomansecond_s));
	id = msg.id();
	name.Copy(msg.name());
}

Sheet_randomnamewomansecond_s::Sheet_randomnamewomansecond_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_randomnamewomansecond_s::CreateInit() {
	return 0;
}

int Sheet_randomnamewomansecond_s::ResumeInit() {
	return 0;
}

void Sheet_randomnamewomansecond_s::write_to_pbmsg(::proto_ff::Sheet_randomnamewomansecond & msg) const {
	for(int32_t i = 0; i < (int32_t)randomnamewomansecond_List.GetSize() && i < randomnamewomansecond_List.GetMaxSize(); ++i) {
		::proto_ff::randomnamewomansecond* temp_randomnamewomansecond_list = msg.add_randomnamewomansecond_list();
		randomnamewomansecond_List[i].write_to_pbmsg(*temp_randomnamewomansecond_list);
	}
}

void Sheet_randomnamewomansecond_s::read_from_pbmsg(const ::proto_ff::Sheet_randomnamewomansecond & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_randomnamewomansecond_s));
	randomnamewomansecond_List.SetSize(msg.randomnamewomansecond_list_size() > randomnamewomansecond_List.GetMaxSize() ? randomnamewomansecond_List.GetMaxSize() : msg.randomnamewomansecond_list_size());
	for(int32_t i = 0; i < (int32_t)randomnamewomansecond_List.GetSize(); ++i) {
		const ::proto_ff::randomnamewomansecond & temp_randomnamewomansecond_list = msg.randomnamewomansecond_list(i);
		randomnamewomansecond_List[i].read_from_pbmsg(temp_randomnamewomansecond_list);
	}
}

randomnamewomanthird_s::randomnamewomanthird_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int randomnamewomanthird_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int randomnamewomanthird_s::ResumeInit() {
	return 0;
}

void randomnamewomanthird_s::write_to_pbmsg(::proto_ff::randomnamewomanthird & msg) const {
	msg.set_id((int32_t)id);
	msg.set_name((const char*)name.Get());
}

void randomnamewomanthird_s::read_from_pbmsg(const ::proto_ff::randomnamewomanthird & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct randomnamewomanthird_s));
	id = msg.id();
	name.Copy(msg.name());
}

Sheet_randomnamewomanthird_s::Sheet_randomnamewomanthird_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_randomnamewomanthird_s::CreateInit() {
	return 0;
}

int Sheet_randomnamewomanthird_s::ResumeInit() {
	return 0;
}

void Sheet_randomnamewomanthird_s::write_to_pbmsg(::proto_ff::Sheet_randomnamewomanthird & msg) const {
	for(int32_t i = 0; i < (int32_t)randomnamewomanthird_List.GetSize() && i < randomnamewomanthird_List.GetMaxSize(); ++i) {
		::proto_ff::randomnamewomanthird* temp_randomnamewomanthird_list = msg.add_randomnamewomanthird_list();
		randomnamewomanthird_List[i].write_to_pbmsg(*temp_randomnamewomanthird_list);
	}
}

void Sheet_randomnamewomanthird_s::read_from_pbmsg(const ::proto_ff::Sheet_randomnamewomanthird & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_randomnamewomanthird_s));
	randomnamewomanthird_List.SetSize(msg.randomnamewomanthird_list_size() > randomnamewomanthird_List.GetMaxSize() ? randomnamewomanthird_List.GetMaxSize() : msg.randomnamewomanthird_list_size());
	for(int32_t i = 0; i < (int32_t)randomnamewomanthird_List.GetSize(); ++i) {
		const ::proto_ff::randomnamewomanthird & temp_randomnamewomanthird_list = msg.randomnamewomanthird_list(i);
		randomnamewomanthird_List[i].read_from_pbmsg(temp_randomnamewomanthird_list);
	}
}

}