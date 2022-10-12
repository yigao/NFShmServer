#include "closetest_s.h"

namespace proto_ff_s {

closetestActivity_s::closetestActivity_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int closetestActivity_s::CreateInit() {
	ID = (int32_t)0;
	Type = (int32_t)0;
	TypeParam = (int32_t)0;
	BoxId = (int64_t)0;
	return 0;
}

int closetestActivity_s::ResumeInit() {
	return 0;
}

void closetestActivity_s::write_to_pbmsg(::proto_ff::closetestActivity & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_type((int32_t)Type);
	msg.set_typeparam((int32_t)TypeParam);
	msg.set_boxid((int64_t)BoxId);
}

void closetestActivity_s::read_from_pbmsg(const ::proto_ff::closetestActivity & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct closetestActivity_s));
	ID = msg.id();
	Type = msg.type();
	TypeParam = msg.typeparam();
	BoxId = msg.boxid();
}

Sheet_closetestActivity_s::Sheet_closetestActivity_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_closetestActivity_s::CreateInit() {
	return 0;
}

int Sheet_closetestActivity_s::ResumeInit() {
	return 0;
}

void Sheet_closetestActivity_s::write_to_pbmsg(::proto_ff::Sheet_closetestActivity & msg) const {
	for(int32_t i = 0; i < (int32_t)closetestActivity_List.GetSize() && i < closetestActivity_List.GetMaxSize(); ++i) {
		::proto_ff::closetestActivity* temp_closetestactivity_list = msg.add_closetestactivity_list();
		closetestActivity_List[i].write_to_pbmsg(*temp_closetestactivity_list);
	}
}

void Sheet_closetestActivity_s::read_from_pbmsg(const ::proto_ff::Sheet_closetestActivity & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_closetestActivity_s));
	closetestActivity_List.SetSize(msg.closetestactivity_list_size() > closetestActivity_List.GetMaxSize() ? closetestActivity_List.GetMaxSize() : msg.closetestactivity_list_size());
	for(int32_t i = 0; i < (int32_t)closetestActivity_List.GetSize(); ++i) {
		const ::proto_ff::closetestActivity & temp_closetestactivity_list = msg.closetestactivity_list(i);
		closetestActivity_List[i].read_from_pbmsg(temp_closetestactivity_list);
	}
}

closetestRebate_s::closetestRebate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int closetestRebate_s::CreateInit() {
	Day = (int32_t)0;
	ReturnParamA = (int32_t)0;
	ReturnParamB = (int32_t)0;
	return 0;
}

int closetestRebate_s::ResumeInit() {
	return 0;
}

void closetestRebate_s::write_to_pbmsg(::proto_ff::closetestRebate & msg) const {
	msg.set_day((int32_t)Day);
	msg.set_returnparama((int32_t)ReturnParamA);
	msg.set_returnparamb((int32_t)ReturnParamB);
}

void closetestRebate_s::read_from_pbmsg(const ::proto_ff::closetestRebate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct closetestRebate_s));
	Day = msg.day();
	ReturnParamA = msg.returnparama();
	ReturnParamB = msg.returnparamb();
}

Sheet_closetestRebate_s::Sheet_closetestRebate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_closetestRebate_s::CreateInit() {
	return 0;
}

int Sheet_closetestRebate_s::ResumeInit() {
	return 0;
}

void Sheet_closetestRebate_s::write_to_pbmsg(::proto_ff::Sheet_closetestRebate & msg) const {
	for(int32_t i = 0; i < (int32_t)closetestRebate_List.GetSize() && i < closetestRebate_List.GetMaxSize(); ++i) {
		::proto_ff::closetestRebate* temp_closetestrebate_list = msg.add_closetestrebate_list();
		closetestRebate_List[i].write_to_pbmsg(*temp_closetestrebate_list);
	}
}

void Sheet_closetestRebate_s::read_from_pbmsg(const ::proto_ff::Sheet_closetestRebate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_closetestRebate_s));
	closetestRebate_List.SetSize(msg.closetestrebate_list_size() > closetestRebate_List.GetMaxSize() ? closetestRebate_List.GetMaxSize() : msg.closetestrebate_list_size());
	for(int32_t i = 0; i < (int32_t)closetestRebate_List.GetSize(); ++i) {
		const ::proto_ff::closetestRebate & temp_closetestrebate_list = msg.closetestrebate_list(i);
		closetestRebate_List[i].read_from_pbmsg(temp_closetestrebate_list);
	}
}

}