#include "title_s.h"

namespace proto_ff_s {

titletype_s::titletype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int titletype_s::CreateInit() {
	type = (int32_t)0;
	return 0;
}

int titletype_s::ResumeInit() {
	return 0;
}

void titletype_s::write_to_pbmsg(::proto_ff::titletype & msg) const {
	msg.set_type((int32_t)type);
}

void titletype_s::read_from_pbmsg(const ::proto_ff::titletype & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct titletype_s));
	type = msg.type();
}

Sheet_titletype_s::Sheet_titletype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_titletype_s::CreateInit() {
	return 0;
}

int Sheet_titletype_s::ResumeInit() {
	return 0;
}

void Sheet_titletype_s::write_to_pbmsg(::proto_ff::Sheet_titletype & msg) const {
	for(int32_t i = 0; i < (int32_t)titletype_List.GetSize() && i < titletype_List.GetMaxSize(); ++i) {
		::proto_ff::titletype* temp_titletype_list = msg.add_titletype_list();
		titletype_List[i].write_to_pbmsg(*temp_titletype_list);
	}
}

void Sheet_titletype_s::read_from_pbmsg(const ::proto_ff::Sheet_titletype & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_titletype_s));
	titletype_List.SetSize(msg.titletype_list_size() > titletype_List.GetMaxSize() ? titletype_List.GetMaxSize() : msg.titletype_list_size());
	for(int32_t i = 0; i < (int32_t)titletype_List.GetSize(); ++i) {
		const ::proto_ff::titletype & temp_titletype_list = msg.titletype_list(i);
		titletype_List[i].read_from_pbmsg(temp_titletype_list);
	}
}

titletitleattributeDesc_s::titletitleattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int titletitleattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int titletitleattributeDesc_s::ResumeInit() {
	return 0;
}

void titletitleattributeDesc_s::write_to_pbmsg(::proto_ff::titletitleattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void titletitleattributeDesc_s::read_from_pbmsg(const ::proto_ff::titletitleattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct titletitleattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

titletitle_s::titletitle_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int titletitle_s::CreateInit() {
	id = (int64_t)0;
	type = (int32_t)0;
	subType = (int32_t)0;
	addTime = (int32_t)0;
	lifeTime = (int32_t)0;
	return 0;
}

int titletitle_s::ResumeInit() {
	return 0;
}

void titletitle_s::write_to_pbmsg(::proto_ff::titletitle & msg) const {
	msg.set_id((int64_t)id);
	msg.set_name((const char*)name.Get());
	msg.set_type((int32_t)type);
	msg.set_subtype((int32_t)subType);
	msg.set_eventvalue((const char*)eventValue.Get());
	msg.set_describe((const char*)describe.Get());
	msg.set_addtime((int32_t)addTime);
	msg.set_lifetime((int32_t)lifeTime);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::titletitleattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void titletitle_s::read_from_pbmsg(const ::proto_ff::titletitle & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct titletitle_s));
	id = msg.id();
	name.Copy(msg.name());
	type = msg.type();
	subType = msg.subtype();
	eventValue.Copy(msg.eventvalue());
	describe.Copy(msg.describe());
	addTime = msg.addtime();
	lifeTime = msg.lifetime();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::titletitleattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_titletitle_s::Sheet_titletitle_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_titletitle_s::CreateInit() {
	return 0;
}

int Sheet_titletitle_s::ResumeInit() {
	return 0;
}

void Sheet_titletitle_s::write_to_pbmsg(::proto_ff::Sheet_titletitle & msg) const {
	for(int32_t i = 0; i < (int32_t)titletitle_List.GetSize() && i < titletitle_List.GetMaxSize(); ++i) {
		::proto_ff::titletitle* temp_titletitle_list = msg.add_titletitle_list();
		titletitle_List[i].write_to_pbmsg(*temp_titletitle_list);
	}
}

void Sheet_titletitle_s::read_from_pbmsg(const ::proto_ff::Sheet_titletitle & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_titletitle_s));
	titletitle_List.SetSize(msg.titletitle_list_size() > titletitle_List.GetMaxSize() ? titletitle_List.GetMaxSize() : msg.titletitle_list_size());
	for(int32_t i = 0; i < (int32_t)titletitle_List.GetSize(); ++i) {
		const ::proto_ff::titletitle & temp_titletitle_list = msg.titletitle_list(i);
		titletitle_List[i].read_from_pbmsg(temp_titletitle_list);
	}
}

}