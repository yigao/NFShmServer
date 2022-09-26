#include "godpower_s.h"

namespace proto_ff_s {

godpowergodpower_s::godpowergodpower_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int godpowergodpower_s::CreateInit() {
	id = (int32_t)0;
	boxid = (int64_t)0;
	price = (int32_t)0;
	times = (int32_t)0;
	unlock = (int32_t)0;
	return 0;
}

int godpowergodpower_s::ResumeInit() {
	return 0;
}

void godpowergodpower_s::write_to_pbmsg(::proto_ff::godpowergodpower & msg) const {
	msg.set_id((int32_t)id);
	msg.set_boxid((int64_t)boxid);
	msg.set_price((int32_t)price);
	msg.set_times((int32_t)times);
	msg.set_unlock((int32_t)unlock);
}

void godpowergodpower_s::read_from_pbmsg(const ::proto_ff::godpowergodpower & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct godpowergodpower_s));
	id = msg.id();
	boxid = msg.boxid();
	price = msg.price();
	times = msg.times();
	unlock = msg.unlock();
}

Sheet_godpowergodpower_s::Sheet_godpowergodpower_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_godpowergodpower_s::CreateInit() {
	return 0;
}

int Sheet_godpowergodpower_s::ResumeInit() {
	return 0;
}

void Sheet_godpowergodpower_s::write_to_pbmsg(::proto_ff::Sheet_godpowergodpower & msg) const {
	for(int32_t i = 0; i < (int32_t)godpowergodpower_List.GetSize() && i < godpowergodpower_List.GetMaxSize(); ++i) {
		::proto_ff::godpowergodpower* temp_godpowergodpower_list = msg.add_godpowergodpower_list();
		godpowergodpower_List[i].write_to_pbmsg(*temp_godpowergodpower_list);
	}
}

void Sheet_godpowergodpower_s::read_from_pbmsg(const ::proto_ff::Sheet_godpowergodpower & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_godpowergodpower_s));
	godpowergodpower_List.SetSize(msg.godpowergodpower_list_size() > godpowergodpower_List.GetMaxSize() ? godpowergodpower_List.GetMaxSize() : msg.godpowergodpower_list_size());
	for(int32_t i = 0; i < (int32_t)godpowergodpower_List.GetSize(); ++i) {
		const ::proto_ff::godpowergodpower & temp_godpowergodpower_list = msg.godpowergodpower_list(i);
		godpowergodpower_List[i].read_from_pbmsg(temp_godpowergodpower_list);
	}
}

godpowerskillupdateattributeDesc_s::godpowerskillupdateattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int godpowerskillupdateattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int64_t)0;
	return 0;
}

int godpowerskillupdateattributeDesc_s::ResumeInit() {
	return 0;
}

void godpowerskillupdateattributeDesc_s::write_to_pbmsg(::proto_ff::godpowerskillupdateattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int64_t)value);
}

void godpowerskillupdateattributeDesc_s::read_from_pbmsg(const ::proto_ff::godpowerskillupdateattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct godpowerskillupdateattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

godpowerskillupdate_s::godpowerskillupdate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int godpowerskillupdate_s::CreateInit() {
	id = (int32_t)0;
	tableID = (int32_t)0;
	lv = (int32_t)0;
	itemID = (int64_t)0;
	itemNum = (int32_t)0;
	skillID = (int64_t)0;
	isBreak = (int32_t)0;
	unlock = (int32_t)0;
	return 0;
}

int godpowerskillupdate_s::ResumeInit() {
	return 0;
}

void godpowerskillupdate_s::write_to_pbmsg(::proto_ff::godpowerskillupdate & msg) const {
	msg.set_id((int32_t)id);
	msg.set_tableid((int32_t)tableID);
	msg.set_lv((int32_t)lv);
	msg.set_itemid((int64_t)itemID);
	msg.set_itemnum((int32_t)itemNum);
	msg.set_skillid((int64_t)skillID);
	msg.set_isbreak((int32_t)isBreak);
	msg.set_unlock((int32_t)unlock);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::godpowerskillupdateattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void godpowerskillupdate_s::read_from_pbmsg(const ::proto_ff::godpowerskillupdate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct godpowerskillupdate_s));
	id = msg.id();
	tableID = msg.tableid();
	lv = msg.lv();
	itemID = msg.itemid();
	itemNum = msg.itemnum();
	skillID = msg.skillid();
	isBreak = msg.isbreak();
	unlock = msg.unlock();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::godpowerskillupdateattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_godpowerskillupdate_s::Sheet_godpowerskillupdate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_godpowerskillupdate_s::CreateInit() {
	return 0;
}

int Sheet_godpowerskillupdate_s::ResumeInit() {
	return 0;
}

void Sheet_godpowerskillupdate_s::write_to_pbmsg(::proto_ff::Sheet_godpowerskillupdate & msg) const {
	for(int32_t i = 0; i < (int32_t)godpowerskillupdate_List.GetSize() && i < godpowerskillupdate_List.GetMaxSize(); ++i) {
		::proto_ff::godpowerskillupdate* temp_godpowerskillupdate_list = msg.add_godpowerskillupdate_list();
		godpowerskillupdate_List[i].write_to_pbmsg(*temp_godpowerskillupdate_list);
	}
}

void Sheet_godpowerskillupdate_s::read_from_pbmsg(const ::proto_ff::Sheet_godpowerskillupdate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_godpowerskillupdate_s));
	godpowerskillupdate_List.SetSize(msg.godpowerskillupdate_list_size() > godpowerskillupdate_List.GetMaxSize() ? godpowerskillupdate_List.GetMaxSize() : msg.godpowerskillupdate_list_size());
	for(int32_t i = 0; i < (int32_t)godpowerskillupdate_List.GetSize(); ++i) {
		const ::proto_ff::godpowerskillupdate & temp_godpowerskillupdate_list = msg.godpowerskillupdate_list(i);
		godpowerskillupdate_List[i].read_from_pbmsg(temp_godpowerskillupdate_list);
	}
}

}