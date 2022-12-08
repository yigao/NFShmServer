#include "decorate_s.h"

namespace proto_ff_s {

decoratedecorateattributeDesc_s::decoratedecorateattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int decoratedecorateattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int decoratedecorateattributeDesc_s::ResumeInit() {
	return 0;
}

void decoratedecorateattributeDesc_s::write_to_pbmsg(::proto_ff::decoratedecorateattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void decoratedecorateattributeDesc_s::read_from_pbmsg(const ::proto_ff::decoratedecorateattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct decoratedecorateattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

decoratedecorateActiveAttributeDesc_s::decoratedecorateActiveAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int decoratedecorateActiveAttributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int decoratedecorateActiveAttributeDesc_s::ResumeInit() {
	return 0;
}

void decoratedecorateActiveAttributeDesc_s::write_to_pbmsg(::proto_ff::decoratedecorateActiveAttributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void decoratedecorateActiveAttributeDesc_s::read_from_pbmsg(const ::proto_ff::decoratedecorateActiveAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct decoratedecorateActiveAttributeDesc_s));
	type = msg.type();
	value = msg.value();
}

decoratedecorate_s::decoratedecorate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int decoratedecorate_s::CreateInit() {
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

int decoratedecorate_s::ResumeInit() {
	return 0;
}

void decoratedecorate_s::write_to_pbmsg(::proto_ff::decoratedecorate & msg) const {
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
		::proto_ff::decoratedecorateattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
	for(int32_t i = 0; i < (int32_t)ActiveAttribute.GetSize() && i < ActiveAttribute.GetMaxSize(); ++i) {
		::proto_ff::decoratedecorateActiveAttributeDesc* temp_activeattribute = msg.add_activeattribute();
		ActiveAttribute[i].write_to_pbmsg(*temp_activeattribute);
	}
}

void decoratedecorate_s::read_from_pbmsg(const ::proto_ff::decoratedecorate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct decoratedecorate_s));
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
		const ::proto_ff::decoratedecorateattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
	ActiveAttribute.SetSize(msg.activeattribute_size() > ActiveAttribute.GetMaxSize() ? ActiveAttribute.GetMaxSize() : msg.activeattribute_size());
	for(int32_t i = 0; i < (int32_t)ActiveAttribute.GetSize(); ++i) {
		const ::proto_ff::decoratedecorateActiveAttributeDesc & temp_activeattribute = msg.activeattribute(i);
		ActiveAttribute[i].read_from_pbmsg(temp_activeattribute);
	}
}

Sheet_decoratedecorate_s::Sheet_decoratedecorate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_decoratedecorate_s::CreateInit() {
	return 0;
}

int Sheet_decoratedecorate_s::ResumeInit() {
	return 0;
}

void Sheet_decoratedecorate_s::write_to_pbmsg(::proto_ff::Sheet_decoratedecorate & msg) const {
	for(int32_t i = 0; i < (int32_t)decoratedecorate_List.GetSize() && i < decoratedecorate_List.GetMaxSize(); ++i) {
		::proto_ff::decoratedecorate* temp_decoratedecorate_list = msg.add_decoratedecorate_list();
		decoratedecorate_List[i].write_to_pbmsg(*temp_decoratedecorate_list);
	}
}

void Sheet_decoratedecorate_s::read_from_pbmsg(const ::proto_ff::Sheet_decoratedecorate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_decoratedecorate_s));
	decoratedecorate_List.SetSize(msg.decoratedecorate_list_size() > decoratedecorate_List.GetMaxSize() ? decoratedecorate_List.GetMaxSize() : msg.decoratedecorate_list_size());
	for(int32_t i = 0; i < (int32_t)decoratedecorate_List.GetSize(); ++i) {
		const ::proto_ff::decoratedecorate & temp_decoratedecorate_list = msg.decoratedecorate_list(i);
		decoratedecorate_List[i].read_from_pbmsg(temp_decoratedecorate_list);
	}
}

}