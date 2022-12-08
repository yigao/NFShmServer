#include "footprint_s.h"

namespace proto_ff_s {

footprintfootprintattributeDesc_s::footprintfootprintattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int footprintfootprintattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int footprintfootprintattributeDesc_s::ResumeInit() {
	return 0;
}

void footprintfootprintattributeDesc_s::write_to_pbmsg(::proto_ff::footprintfootprintattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void footprintfootprintattributeDesc_s::read_from_pbmsg(const ::proto_ff::footprintfootprintattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct footprintfootprintattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

footprintfootprintActiveAttributeDesc_s::footprintfootprintActiveAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int footprintfootprintActiveAttributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int footprintfootprintActiveAttributeDesc_s::ResumeInit() {
	return 0;
}

void footprintfootprintActiveAttributeDesc_s::write_to_pbmsg(::proto_ff::footprintfootprintActiveAttributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void footprintfootprintActiveAttributeDesc_s::read_from_pbmsg(const ::proto_ff::footprintfootprintActiveAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct footprintfootprintActiveAttributeDesc_s));
	type = msg.type();
	value = msg.value();
}

footprintfootprint_s::footprintfootprint_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int footprintfootprint_s::CreateInit() {
	ID = (int64_t)0;
	type = (int32_t)0;
	quality = (int32_t)0;
	activationItem = (int64_t)0;
	activationNum = (int32_t)0;
	starId = (int64_t)0;
	starUp = (int32_t)0;
	starBer = (int32_t)0;
	return 0;
}

int footprintfootprint_s::ResumeInit() {
	return 0;
}

void footprintfootprint_s::write_to_pbmsg(::proto_ff::footprintfootprint & msg) const {
	msg.set_id((int64_t)ID);
	msg.set_name((const char*)name.Get());
	msg.set_type((int32_t)type);
	msg.set_quality((int32_t)quality);
	msg.set_professionlimit((const char*)professionLimit.Get());
	msg.set_activationitem((int64_t)activationItem);
	msg.set_activationnum((int32_t)activationNum);
	msg.set_starid((int64_t)starId);
	msg.set_starnum((const char*)starNum.Get());
	msg.set_starup((int32_t)starUp);
	msg.set_starber((int32_t)starBer);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::footprintfootprintattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
	for(int32_t i = 0; i < (int32_t)ActiveAttribute.GetSize() && i < ActiveAttribute.GetMaxSize(); ++i) {
		::proto_ff::footprintfootprintActiveAttributeDesc* temp_activeattribute = msg.add_activeattribute();
		ActiveAttribute[i].write_to_pbmsg(*temp_activeattribute);
	}
}

void footprintfootprint_s::read_from_pbmsg(const ::proto_ff::footprintfootprint & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct footprintfootprint_s));
	ID = msg.id();
	name.Copy(msg.name());
	type = msg.type();
	quality = msg.quality();
	professionLimit.Copy(msg.professionlimit());
	activationItem = msg.activationitem();
	activationNum = msg.activationnum();
	starId = msg.starid();
	starNum.Copy(msg.starnum());
	starUp = msg.starup();
	starBer = msg.starber();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::footprintfootprintattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
	ActiveAttribute.SetSize(msg.activeattribute_size() > ActiveAttribute.GetMaxSize() ? ActiveAttribute.GetMaxSize() : msg.activeattribute_size());
	for(int32_t i = 0; i < (int32_t)ActiveAttribute.GetSize(); ++i) {
		const ::proto_ff::footprintfootprintActiveAttributeDesc & temp_activeattribute = msg.activeattribute(i);
		ActiveAttribute[i].read_from_pbmsg(temp_activeattribute);
	}
}

Sheet_footprintfootprint_s::Sheet_footprintfootprint_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_footprintfootprint_s::CreateInit() {
	return 0;
}

int Sheet_footprintfootprint_s::ResumeInit() {
	return 0;
}

void Sheet_footprintfootprint_s::write_to_pbmsg(::proto_ff::Sheet_footprintfootprint & msg) const {
	for(int32_t i = 0; i < (int32_t)footprintfootprint_List.GetSize() && i < footprintfootprint_List.GetMaxSize(); ++i) {
		::proto_ff::footprintfootprint* temp_footprintfootprint_list = msg.add_footprintfootprint_list();
		footprintfootprint_List[i].write_to_pbmsg(*temp_footprintfootprint_list);
	}
}

void Sheet_footprintfootprint_s::read_from_pbmsg(const ::proto_ff::Sheet_footprintfootprint & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_footprintfootprint_s));
	footprintfootprint_List.SetSize(msg.footprintfootprint_list_size() > footprintfootprint_List.GetMaxSize() ? footprintfootprint_List.GetMaxSize() : msg.footprintfootprint_list_size());
	for(int32_t i = 0; i < (int32_t)footprintfootprint_List.GetSize(); ++i) {
		const ::proto_ff::footprintfootprint & temp_footprintfootprint_list = msg.footprintfootprint_list(i);
		footprintfootprint_List[i].read_from_pbmsg(temp_footprintfootprint_list);
	}
}

}