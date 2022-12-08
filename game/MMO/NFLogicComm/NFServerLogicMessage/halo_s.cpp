#include "halo_s.h"

namespace proto_ff_s {

halohaloattributeDesc_s::halohaloattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int halohaloattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int halohaloattributeDesc_s::ResumeInit() {
	return 0;
}

void halohaloattributeDesc_s::write_to_pbmsg(::proto_ff::halohaloattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void halohaloattributeDesc_s::read_from_pbmsg(const ::proto_ff::halohaloattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct halohaloattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

halohaloActiveAttributeDesc_s::halohaloActiveAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int halohaloActiveAttributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int halohaloActiveAttributeDesc_s::ResumeInit() {
	return 0;
}

void halohaloActiveAttributeDesc_s::write_to_pbmsg(::proto_ff::halohaloActiveAttributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void halohaloActiveAttributeDesc_s::read_from_pbmsg(const ::proto_ff::halohaloActiveAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct halohaloActiveAttributeDesc_s));
	type = msg.type();
	value = msg.value();
}

halohalo_s::halohalo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int halohalo_s::CreateInit() {
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

int halohalo_s::ResumeInit() {
	return 0;
}

void halohalo_s::write_to_pbmsg(::proto_ff::halohalo & msg) const {
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
		::proto_ff::halohaloattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
	for(int32_t i = 0; i < (int32_t)ActiveAttribute.GetSize() && i < ActiveAttribute.GetMaxSize(); ++i) {
		::proto_ff::halohaloActiveAttributeDesc* temp_activeattribute = msg.add_activeattribute();
		ActiveAttribute[i].write_to_pbmsg(*temp_activeattribute);
	}
}

void halohalo_s::read_from_pbmsg(const ::proto_ff::halohalo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct halohalo_s));
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
		const ::proto_ff::halohaloattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
	ActiveAttribute.SetSize(msg.activeattribute_size() > ActiveAttribute.GetMaxSize() ? ActiveAttribute.GetMaxSize() : msg.activeattribute_size());
	for(int32_t i = 0; i < (int32_t)ActiveAttribute.GetSize(); ++i) {
		const ::proto_ff::halohaloActiveAttributeDesc & temp_activeattribute = msg.activeattribute(i);
		ActiveAttribute[i].read_from_pbmsg(temp_activeattribute);
	}
}

Sheet_halohalo_s::Sheet_halohalo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_halohalo_s::CreateInit() {
	return 0;
}

int Sheet_halohalo_s::ResumeInit() {
	return 0;
}

void Sheet_halohalo_s::write_to_pbmsg(::proto_ff::Sheet_halohalo & msg) const {
	for(int32_t i = 0; i < (int32_t)halohalo_List.GetSize() && i < halohalo_List.GetMaxSize(); ++i) {
		::proto_ff::halohalo* temp_halohalo_list = msg.add_halohalo_list();
		halohalo_List[i].write_to_pbmsg(*temp_halohalo_list);
	}
}

void Sheet_halohalo_s::read_from_pbmsg(const ::proto_ff::Sheet_halohalo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_halohalo_s));
	halohalo_List.SetSize(msg.halohalo_list_size() > halohalo_List.GetMaxSize() ? halohalo_List.GetMaxSize() : msg.halohalo_list_size());
	for(int32_t i = 0; i < (int32_t)halohalo_List.GetSize(); ++i) {
		const ::proto_ff::halohalo & temp_halohalo_list = msg.halohalo_list(i);
		halohalo_List[i].read_from_pbmsg(temp_halohalo_list);
	}
}

}