#include "meditation_s.h"

namespace proto_ff_s {

meditationmeditationattributeDesc_s::meditationmeditationattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int meditationmeditationattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int meditationmeditationattributeDesc_s::ResumeInit() {
	return 0;
}

void meditationmeditationattributeDesc_s::write_to_pbmsg(::proto_ff::meditationmeditationattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void meditationmeditationattributeDesc_s::read_from_pbmsg(const ::proto_ff::meditationmeditationattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct meditationmeditationattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

meditationmeditationActiveAttributeDesc_s::meditationmeditationActiveAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int meditationmeditationActiveAttributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int meditationmeditationActiveAttributeDesc_s::ResumeInit() {
	return 0;
}

void meditationmeditationActiveAttributeDesc_s::write_to_pbmsg(::proto_ff::meditationmeditationActiveAttributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void meditationmeditationActiveAttributeDesc_s::read_from_pbmsg(const ::proto_ff::meditationmeditationActiveAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct meditationmeditationActiveAttributeDesc_s));
	type = msg.type();
	value = msg.value();
}

meditationmeditation_s::meditationmeditation_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int meditationmeditation_s::CreateInit() {
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

int meditationmeditation_s::ResumeInit() {
	return 0;
}

void meditationmeditation_s::write_to_pbmsg(::proto_ff::meditationmeditation & msg) const {
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
		::proto_ff::meditationmeditationattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
	for(int32_t i = 0; i < (int32_t)ActiveAttribute.GetSize() && i < ActiveAttribute.GetMaxSize(); ++i) {
		::proto_ff::meditationmeditationActiveAttributeDesc* temp_activeattribute = msg.add_activeattribute();
		ActiveAttribute[i].write_to_pbmsg(*temp_activeattribute);
	}
}

void meditationmeditation_s::read_from_pbmsg(const ::proto_ff::meditationmeditation & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct meditationmeditation_s));
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
		const ::proto_ff::meditationmeditationattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
	ActiveAttribute.SetSize(msg.activeattribute_size() > ActiveAttribute.GetMaxSize() ? ActiveAttribute.GetMaxSize() : msg.activeattribute_size());
	for(int32_t i = 0; i < (int32_t)ActiveAttribute.GetSize(); ++i) {
		const ::proto_ff::meditationmeditationActiveAttributeDesc & temp_activeattribute = msg.activeattribute(i);
		ActiveAttribute[i].read_from_pbmsg(temp_activeattribute);
	}
}

Sheet_meditationmeditation_s::Sheet_meditationmeditation_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_meditationmeditation_s::CreateInit() {
	return 0;
}

int Sheet_meditationmeditation_s::ResumeInit() {
	return 0;
}

void Sheet_meditationmeditation_s::write_to_pbmsg(::proto_ff::Sheet_meditationmeditation & msg) const {
	for(int32_t i = 0; i < (int32_t)meditationmeditation_List.GetSize() && i < meditationmeditation_List.GetMaxSize(); ++i) {
		::proto_ff::meditationmeditation* temp_meditationmeditation_list = msg.add_meditationmeditation_list();
		meditationmeditation_List[i].write_to_pbmsg(*temp_meditationmeditation_list);
	}
}

void Sheet_meditationmeditation_s::read_from_pbmsg(const ::proto_ff::Sheet_meditationmeditation & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_meditationmeditation_s));
	meditationmeditation_List.SetSize(msg.meditationmeditation_list_size() > meditationmeditation_List.GetMaxSize() ? meditationmeditation_List.GetMaxSize() : msg.meditationmeditation_list_size());
	for(int32_t i = 0; i < (int32_t)meditationmeditation_List.GetSize(); ++i) {
		const ::proto_ff::meditationmeditation & temp_meditationmeditation_list = msg.meditationmeditation_list(i);
		meditationmeditation_List[i].read_from_pbmsg(temp_meditationmeditation_list);
	}
}

}