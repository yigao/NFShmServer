#include "handbook_s.h"

namespace proto_ff_s {

handbookhandbookattributeDesc_s::handbookhandbookattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int handbookhandbookattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int64_t)0;
	return 0;
}

int handbookhandbookattributeDesc_s::ResumeInit() {
	return 0;
}

void handbookhandbookattributeDesc_s::write_to_pbmsg(::proto_ff::handbookhandbookattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int64_t)value);
}

void handbookhandbookattributeDesc_s::read_from_pbmsg(const ::proto_ff::handbookhandbookattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct handbookhandbookattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

handbookhandbook_s::handbookhandbook_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int handbookhandbook_s::CreateInit() {
	handbookID = (int64_t)0;
	itemId = (int64_t)0;
	handbookType = (int32_t)0;
	handbookQuality = (int32_t)0;
	handbookLv = (int32_t)0;
	handZ = (int32_t)0;
	starId = (int64_t)0;
	return 0;
}

int handbookhandbook_s::ResumeInit() {
	return 0;
}

void handbookhandbook_s::write_to_pbmsg(::proto_ff::handbookhandbook & msg) const {
	msg.set_handbookid((int64_t)handbookID);
	msg.set_itemid((int64_t)itemId);
	msg.set_handbookname((const char*)handbookName.Get());
	msg.set_handbooktype((int32_t)handbookType);
	msg.set_handbookquality((int32_t)handbookQuality);
	msg.set_handbooklv((int32_t)handbookLv);
	msg.set_handz((int32_t)handZ);
	msg.set_starid((int64_t)starId);
	msg.set_starnum((const char*)starNum.Get());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::handbookhandbookattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void handbookhandbook_s::read_from_pbmsg(const ::proto_ff::handbookhandbook & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct handbookhandbook_s));
	handbookID = msg.handbookid();
	itemId = msg.itemid();
	handbookName.Copy(msg.handbookname());
	handbookType = msg.handbooktype();
	handbookQuality = msg.handbookquality();
	handbookLv = msg.handbooklv();
	handZ = msg.handz();
	starId = msg.starid();
	starNum.Copy(msg.starnum());
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::handbookhandbookattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_handbookhandbook_s::Sheet_handbookhandbook_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_handbookhandbook_s::CreateInit() {
	return 0;
}

int Sheet_handbookhandbook_s::ResumeInit() {
	return 0;
}

void Sheet_handbookhandbook_s::write_to_pbmsg(::proto_ff::Sheet_handbookhandbook & msg) const {
	for(int32_t i = 0; i < (int32_t)handbookhandbook_List.GetSize() && i < handbookhandbook_List.GetMaxSize(); ++i) {
		::proto_ff::handbookhandbook* temp_handbookhandbook_list = msg.add_handbookhandbook_list();
		handbookhandbook_List[i].write_to_pbmsg(*temp_handbookhandbook_list);
	}
}

void Sheet_handbookhandbook_s::read_from_pbmsg(const ::proto_ff::Sheet_handbookhandbook & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_handbookhandbook_s));
	handbookhandbook_List.SetSize(msg.handbookhandbook_list_size() > handbookhandbook_List.GetMaxSize() ? handbookhandbook_List.GetMaxSize() : msg.handbookhandbook_list_size());
	for(int32_t i = 0; i < (int32_t)handbookhandbook_List.GetSize(); ++i) {
		const ::proto_ff::handbookhandbook & temp_handbookhandbook_list = msg.handbookhandbook_list(i);
		handbookhandbook_List[i].read_from_pbmsg(temp_handbookhandbook_list);
	}
}

handbookfateattributeDesc_s::handbookfateattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int handbookfateattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int64_t)0;
	return 0;
}

int handbookfateattributeDesc_s::ResumeInit() {
	return 0;
}

void handbookfateattributeDesc_s::write_to_pbmsg(::proto_ff::handbookfateattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int64_t)value);
}

void handbookfateattributeDesc_s::read_from_pbmsg(const ::proto_ff::handbookfateattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct handbookfateattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

handbookfate_s::handbookfate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int handbookfate_s::CreateInit() {
	fateID = (int64_t)0;
	starLv = (int32_t)0;
	return 0;
}

int handbookfate_s::ResumeInit() {
	return 0;
}

void handbookfate_s::write_to_pbmsg(::proto_ff::handbookfate & msg) const {
	msg.set_fateid((int64_t)fateID);
	msg.set_fatename((const char*)fateName.Get());
	msg.set_starlv((int32_t)starLv);
	for(int32_t i = 0; i < (int32_t)fateHand.GetSize() && i < fateHand.GetMaxSize(); ++i) {
		msg.add_fatehand((int64_t)fateHand[i]);
	}
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::handbookfateattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void handbookfate_s::read_from_pbmsg(const ::proto_ff::handbookfate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct handbookfate_s));
	fateID = msg.fateid();
	fateName.Copy(msg.fatename());
	starLv = msg.starlv();
	fateHand.SetSize(msg.fatehand_size() > fateHand.GetMaxSize() ? fateHand.GetMaxSize() : msg.fatehand_size());
	for(int32_t i = 0; i < (int32_t)fateHand.GetSize(); ++i) {
		fateHand[i] = msg.fatehand(i);
	}
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::handbookfateattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_handbookfate_s::Sheet_handbookfate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_handbookfate_s::CreateInit() {
	return 0;
}

int Sheet_handbookfate_s::ResumeInit() {
	return 0;
}

void Sheet_handbookfate_s::write_to_pbmsg(::proto_ff::Sheet_handbookfate & msg) const {
	for(int32_t i = 0; i < (int32_t)handbookfate_List.GetSize() && i < handbookfate_List.GetMaxSize(); ++i) {
		::proto_ff::handbookfate* temp_handbookfate_list = msg.add_handbookfate_list();
		handbookfate_List[i].write_to_pbmsg(*temp_handbookfate_list);
	}
}

void Sheet_handbookfate_s::read_from_pbmsg(const ::proto_ff::Sheet_handbookfate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_handbookfate_s));
	handbookfate_List.SetSize(msg.handbookfate_list_size() > handbookfate_List.GetMaxSize() ? handbookfate_List.GetMaxSize() : msg.handbookfate_list_size());
	for(int32_t i = 0; i < (int32_t)handbookfate_List.GetSize(); ++i) {
		const ::proto_ff::handbookfate & temp_handbookfate_list = msg.handbookfate_list(i);
		handbookfate_List[i].read_from_pbmsg(temp_handbookfate_list);
	}
}

handbookattr_s::handbookattr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int handbookattr_s::CreateInit() {
	attID = (int64_t)0;
	return 0;
}

int handbookattr_s::ResumeInit() {
	return 0;
}

void handbookattr_s::write_to_pbmsg(::proto_ff::handbookattr & msg) const {
	msg.set_attid((int64_t)attID);
	for(int32_t i = 0; i < (int32_t)att.GetSize() && i < att.GetMaxSize(); ++i) {
		msg.add_att((int32_t)att[i]);
	}
}

void handbookattr_s::read_from_pbmsg(const ::proto_ff::handbookattr & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct handbookattr_s));
	attID = msg.attid();
	att.SetSize(msg.att_size() > att.GetMaxSize() ? att.GetMaxSize() : msg.att_size());
	for(int32_t i = 0; i < (int32_t)att.GetSize(); ++i) {
		att[i] = msg.att(i);
	}
}

Sheet_handbookattr_s::Sheet_handbookattr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_handbookattr_s::CreateInit() {
	return 0;
}

int Sheet_handbookattr_s::ResumeInit() {
	return 0;
}

void Sheet_handbookattr_s::write_to_pbmsg(::proto_ff::Sheet_handbookattr & msg) const {
	for(int32_t i = 0; i < (int32_t)handbookattr_List.GetSize() && i < handbookattr_List.GetMaxSize(); ++i) {
		::proto_ff::handbookattr* temp_handbookattr_list = msg.add_handbookattr_list();
		handbookattr_List[i].write_to_pbmsg(*temp_handbookattr_list);
	}
}

void Sheet_handbookattr_s::read_from_pbmsg(const ::proto_ff::Sheet_handbookattr & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_handbookattr_s));
	handbookattr_List.SetSize(msg.handbookattr_list_size() > handbookattr_List.GetMaxSize() ? handbookattr_List.GetMaxSize() : msg.handbookattr_list_size());
	for(int32_t i = 0; i < (int32_t)handbookattr_List.GetSize(); ++i) {
		const ::proto_ff::handbookattr & temp_handbookattr_list = msg.handbookattr_list(i);
		handbookattr_List[i].read_from_pbmsg(temp_handbookattr_list);
	}
}

}