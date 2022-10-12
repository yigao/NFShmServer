#include "fashion_s.h"

namespace proto_ff_s {

fashionfashionattributeDesc_s::fashionfashionattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int fashionfashionattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int fashionfashionattributeDesc_s::ResumeInit() {
	return 0;
}

void fashionfashionattributeDesc_s::write_to_pbmsg(::proto_ff::fashionfashionattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void fashionfashionattributeDesc_s::read_from_pbmsg(const ::proto_ff::fashionfashionattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct fashionfashionattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

fashionfashion_s::fashionfashion_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int fashionfashion_s::CreateInit() {
	fashionID = (int64_t)0;
	fashionType = (int32_t)0;
	quality = (int32_t)0;
	starId = (int64_t)0;
	starUp = (int32_t)0;
	starBer = (int32_t)0;
	return 0;
}

int fashionfashion_s::ResumeInit() {
	return 0;
}

void fashionfashion_s::write_to_pbmsg(::proto_ff::fashionfashion & msg) const {
	msg.set_fashionid((int64_t)fashionID);
	msg.set_fashionname((const char*)fashionName.Get());
	msg.set_fashiontype((int32_t)fashionType);
	msg.set_quality((int32_t)quality);
	msg.set_fashionzhiye((const char*)fashionZhiye.Get());
	msg.set_starid((int64_t)starId);
	msg.set_starnum((const char*)starNum.Get());
	msg.set_starup((int32_t)starUp);
	msg.set_starber((int32_t)starBer);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::fashionfashionattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void fashionfashion_s::read_from_pbmsg(const ::proto_ff::fashionfashion & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct fashionfashion_s));
	fashionID = msg.fashionid();
	fashionName.Copy(msg.fashionname());
	fashionType = msg.fashiontype();
	quality = msg.quality();
	fashionZhiye.Copy(msg.fashionzhiye());
	starId = msg.starid();
	starNum.Copy(msg.starnum());
	starUp = msg.starup();
	starBer = msg.starber();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::fashionfashionattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_fashionfashion_s::Sheet_fashionfashion_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_fashionfashion_s::CreateInit() {
	return 0;
}

int Sheet_fashionfashion_s::ResumeInit() {
	return 0;
}

void Sheet_fashionfashion_s::write_to_pbmsg(::proto_ff::Sheet_fashionfashion & msg) const {
	for(int32_t i = 0; i < (int32_t)fashionfashion_List.GetSize() && i < fashionfashion_List.GetMaxSize(); ++i) {
		::proto_ff::fashionfashion* temp_fashionfashion_list = msg.add_fashionfashion_list();
		fashionfashion_List[i].write_to_pbmsg(*temp_fashionfashion_list);
	}
}

void Sheet_fashionfashion_s::read_from_pbmsg(const ::proto_ff::Sheet_fashionfashion & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_fashionfashion_s));
	fashionfashion_List.SetSize(msg.fashionfashion_list_size() > fashionfashion_List.GetMaxSize() ? fashionfashion_List.GetMaxSize() : msg.fashionfashion_list_size());
	for(int32_t i = 0; i < (int32_t)fashionfashion_List.GetSize(); ++i) {
		const ::proto_ff::fashionfashion & temp_fashionfashion_list = msg.fashionfashion_list(i);
		fashionfashion_List[i].read_from_pbmsg(temp_fashionfashion_list);
	}
}

}