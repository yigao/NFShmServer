#include "godHood_s.h"

namespace proto_ff_s {

godHoodgodHoodattributeDesc_s::godHoodgodHoodattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int godHoodgodHoodattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	up = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int godHoodgodHoodattributeDesc_s::ResumeInit() {
	return 0;
}

void godHoodgodHoodattributeDesc_s::write_to_pbmsg(::proto_ff::godHoodgodHoodattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_up((int32_t)up);
	msg.set_value((int32_t)value);
}

void godHoodgodHoodattributeDesc_s::read_from_pbmsg(const ::proto_ff::godHoodgodHoodattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct godHoodgodHoodattributeDesc_s));
	type = msg.type();
	up = msg.up();
	value = msg.value();
}

godHoodgodHood_s::godHoodgodHood_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int godHoodgodHood_s::CreateInit() {
	id = (int64_t)0;
	type = (int32_t)0;
	attrNum = (int32_t)0;
	quality = (int32_t)0;
	lvUp = (int32_t)0;
	basicsExp = (int32_t)0;
	return 0;
}

int godHoodgodHood_s::ResumeInit() {
	return 0;
}

void godHoodgodHood_s::write_to_pbmsg(::proto_ff::godHoodgodHood & msg) const {
	msg.set_id((int64_t)id);
	msg.set_type((int32_t)type);
	msg.set_attrnum((int32_t)attrNum);
	msg.set_quality((int32_t)quality);
	msg.set_lvup((int32_t)lvUp);
	msg.set_basicsexp((int32_t)basicsExp);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::godHoodgodHoodattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void godHoodgodHood_s::read_from_pbmsg(const ::proto_ff::godHoodgodHood & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct godHoodgodHood_s));
	id = msg.id();
	type = msg.type();
	attrNum = msg.attrnum();
	quality = msg.quality();
	lvUp = msg.lvup();
	basicsExp = msg.basicsexp();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::godHoodgodHoodattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_godHoodgodHood_s::Sheet_godHoodgodHood_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_godHoodgodHood_s::CreateInit() {
	return 0;
}

int Sheet_godHoodgodHood_s::ResumeInit() {
	return 0;
}

void Sheet_godHoodgodHood_s::write_to_pbmsg(::proto_ff::Sheet_godHoodgodHood & msg) const {
	for(int32_t i = 0; i < (int32_t)godHoodgodHood_List.GetSize() && i < godHoodgodHood_List.GetMaxSize(); ++i) {
		::proto_ff::godHoodgodHood* temp_godhoodgodhood_list = msg.add_godhoodgodhood_list();
		godHoodgodHood_List[i].write_to_pbmsg(*temp_godhoodgodhood_list);
	}
}

void Sheet_godHoodgodHood_s::read_from_pbmsg(const ::proto_ff::Sheet_godHoodgodHood & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_godHoodgodHood_s));
	godHoodgodHood_List.SetSize(msg.godhoodgodhood_list_size() > godHoodgodHood_List.GetMaxSize() ? godHoodgodHood_List.GetMaxSize() : msg.godhoodgodhood_list_size());
	for(int32_t i = 0; i < (int32_t)godHoodgodHood_List.GetSize(); ++i) {
		const ::proto_ff::godHoodgodHood & temp_godhoodgodhood_list = msg.godhoodgodhood_list(i);
		godHoodgodHood_List[i].read_from_pbmsg(temp_godhoodgodhood_list);
	}
}

godHoodexp_s::godHoodexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int godHoodexp_s::CreateInit() {
	lv = (int32_t)0;
	exp = (int32_t)0;
	return 0;
}

int godHoodexp_s::ResumeInit() {
	return 0;
}

void godHoodexp_s::write_to_pbmsg(::proto_ff::godHoodexp & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_exp((int32_t)exp);
}

void godHoodexp_s::read_from_pbmsg(const ::proto_ff::godHoodexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct godHoodexp_s));
	lv = msg.lv();
	exp = msg.exp();
}

Sheet_godHoodexp_s::Sheet_godHoodexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_godHoodexp_s::CreateInit() {
	return 0;
}

int Sheet_godHoodexp_s::ResumeInit() {
	return 0;
}

void Sheet_godHoodexp_s::write_to_pbmsg(::proto_ff::Sheet_godHoodexp & msg) const {
	for(int32_t i = 0; i < (int32_t)godHoodexp_List.GetSize() && i < godHoodexp_List.GetMaxSize(); ++i) {
		::proto_ff::godHoodexp* temp_godhoodexp_list = msg.add_godhoodexp_list();
		godHoodexp_List[i].write_to_pbmsg(*temp_godhoodexp_list);
	}
}

void Sheet_godHoodexp_s::read_from_pbmsg(const ::proto_ff::Sheet_godHoodexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_godHoodexp_s));
	godHoodexp_List.SetSize(msg.godhoodexp_list_size() > godHoodexp_List.GetMaxSize() ? godHoodexp_List.GetMaxSize() : msg.godhoodexp_list_size());
	for(int32_t i = 0; i < (int32_t)godHoodexp_List.GetSize(); ++i) {
		const ::proto_ff::godHoodexp & temp_godhoodexp_list = msg.godhoodexp_list(i);
		godHoodexp_List[i].read_from_pbmsg(temp_godhoodexp_list);
	}
}

}