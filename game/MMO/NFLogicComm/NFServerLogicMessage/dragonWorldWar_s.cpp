#include "dragonWorldWar_s.h"

namespace proto_ff_s {

dragonWorldWarconstants_s::dragonWorldWarconstants_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dragonWorldWarconstants_s::CreateInit() {
	ID = (int32_t)0;
	valuedata = (int32_t)0;
	return 0;
}

int dragonWorldWarconstants_s::ResumeInit() {
	return 0;
}

void dragonWorldWarconstants_s::write_to_pbmsg(::proto_ff::dragonWorldWarconstants & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_valuedata((int32_t)valuedata);
	msg.set_stringdata((const char*)stringdata.Get());
}

void dragonWorldWarconstants_s::read_from_pbmsg(const ::proto_ff::dragonWorldWarconstants & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dragonWorldWarconstants_s));
	ID = msg.id();
	valuedata = msg.valuedata();
	stringdata.Copy(msg.stringdata());
}

Sheet_dragonWorldWarconstants_s::Sheet_dragonWorldWarconstants_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_dragonWorldWarconstants_s::CreateInit() {
	return 0;
}

int Sheet_dragonWorldWarconstants_s::ResumeInit() {
	return 0;
}

void Sheet_dragonWorldWarconstants_s::write_to_pbmsg(::proto_ff::Sheet_dragonWorldWarconstants & msg) const {
	for(int32_t i = 0; i < (int32_t)dragonWorldWarconstants_List.GetSize() && i < dragonWorldWarconstants_List.GetMaxSize(); ++i) {
		::proto_ff::dragonWorldWarconstants* temp_dragonworldwarconstants_list = msg.add_dragonworldwarconstants_list();
		dragonWorldWarconstants_List[i].write_to_pbmsg(*temp_dragonworldwarconstants_list);
	}
}

void Sheet_dragonWorldWarconstants_s::read_from_pbmsg(const ::proto_ff::Sheet_dragonWorldWarconstants & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_dragonWorldWarconstants_s));
	dragonWorldWarconstants_List.SetSize(msg.dragonworldwarconstants_list_size() > dragonWorldWarconstants_List.GetMaxSize() ? dragonWorldWarconstants_List.GetMaxSize() : msg.dragonworldwarconstants_list_size());
	for(int32_t i = 0; i < (int32_t)dragonWorldWarconstants_List.GetSize(); ++i) {
		const ::proto_ff::dragonWorldWarconstants & temp_dragonworldwarconstants_list = msg.dragonworldwarconstants_list(i);
		dragonWorldWarconstants_List[i].read_from_pbmsg(temp_dragonworldwarconstants_list);
	}
}

dragonWorldWargoldskill_s::dragonWorldWargoldskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dragonWorldWargoldskill_s::CreateInit() {
	ID = (int32_t)0;
	type = (int32_t)0;
	goldmin = (int32_t)0;
	skillId = (int64_t)0;
	return 0;
}

int dragonWorldWargoldskill_s::ResumeInit() {
	return 0;
}

void dragonWorldWargoldskill_s::write_to_pbmsg(::proto_ff::dragonWorldWargoldskill & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_type((int32_t)type);
	msg.set_goldmin((int32_t)goldmin);
	msg.set_skillid((int64_t)skillId);
}

void dragonWorldWargoldskill_s::read_from_pbmsg(const ::proto_ff::dragonWorldWargoldskill & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dragonWorldWargoldskill_s));
	ID = msg.id();
	type = msg.type();
	goldmin = msg.goldmin();
	skillId = msg.skillid();
}

Sheet_dragonWorldWargoldskill_s::Sheet_dragonWorldWargoldskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_dragonWorldWargoldskill_s::CreateInit() {
	return 0;
}

int Sheet_dragonWorldWargoldskill_s::ResumeInit() {
	return 0;
}

void Sheet_dragonWorldWargoldskill_s::write_to_pbmsg(::proto_ff::Sheet_dragonWorldWargoldskill & msg) const {
	for(int32_t i = 0; i < (int32_t)dragonWorldWargoldskill_List.GetSize() && i < dragonWorldWargoldskill_List.GetMaxSize(); ++i) {
		::proto_ff::dragonWorldWargoldskill* temp_dragonworldwargoldskill_list = msg.add_dragonworldwargoldskill_list();
		dragonWorldWargoldskill_List[i].write_to_pbmsg(*temp_dragonworldwargoldskill_list);
	}
}

void Sheet_dragonWorldWargoldskill_s::read_from_pbmsg(const ::proto_ff::Sheet_dragonWorldWargoldskill & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_dragonWorldWargoldskill_s));
	dragonWorldWargoldskill_List.SetSize(msg.dragonworldwargoldskill_list_size() > dragonWorldWargoldskill_List.GetMaxSize() ? dragonWorldWargoldskill_List.GetMaxSize() : msg.dragonworldwargoldskill_list_size());
	for(int32_t i = 0; i < (int32_t)dragonWorldWargoldskill_List.GetSize(); ++i) {
		const ::proto_ff::dragonWorldWargoldskill & temp_dragonworldwargoldskill_list = msg.dragonworldwargoldskill_list(i);
		dragonWorldWargoldskill_List[i].read_from_pbmsg(temp_dragonworldwargoldskill_list);
	}
}

dragonWorldWargoldShop_s::dragonWorldWargoldShop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dragonWorldWargoldShop_s::CreateInit() {
	ID = (int32_t)0;
	itemId = (int64_t)0;
	itemNum = (int32_t)0;
	itemPrice = (int32_t)0;
	weight = (int32_t)0;
	return 0;
}

int dragonWorldWargoldShop_s::ResumeInit() {
	return 0;
}

void dragonWorldWargoldShop_s::write_to_pbmsg(::proto_ff::dragonWorldWargoldShop & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_itemid((int64_t)itemId);
	msg.set_itemnum((int32_t)itemNum);
	msg.set_itemprice((int32_t)itemPrice);
	msg.set_weight((int32_t)weight);
}

void dragonWorldWargoldShop_s::read_from_pbmsg(const ::proto_ff::dragonWorldWargoldShop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dragonWorldWargoldShop_s));
	ID = msg.id();
	itemId = msg.itemid();
	itemNum = msg.itemnum();
	itemPrice = msg.itemprice();
	weight = msg.weight();
}

Sheet_dragonWorldWargoldShop_s::Sheet_dragonWorldWargoldShop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_dragonWorldWargoldShop_s::CreateInit() {
	return 0;
}

int Sheet_dragonWorldWargoldShop_s::ResumeInit() {
	return 0;
}

void Sheet_dragonWorldWargoldShop_s::write_to_pbmsg(::proto_ff::Sheet_dragonWorldWargoldShop & msg) const {
	for(int32_t i = 0; i < (int32_t)dragonWorldWargoldShop_List.GetSize() && i < dragonWorldWargoldShop_List.GetMaxSize(); ++i) {
		::proto_ff::dragonWorldWargoldShop* temp_dragonworldwargoldshop_list = msg.add_dragonworldwargoldshop_list();
		dragonWorldWargoldShop_List[i].write_to_pbmsg(*temp_dragonworldwargoldshop_list);
	}
}

void Sheet_dragonWorldWargoldShop_s::read_from_pbmsg(const ::proto_ff::Sheet_dragonWorldWargoldShop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_dragonWorldWargoldShop_s));
	dragonWorldWargoldShop_List.SetSize(msg.dragonworldwargoldshop_list_size() > dragonWorldWargoldShop_List.GetMaxSize() ? dragonWorldWargoldShop_List.GetMaxSize() : msg.dragonworldwargoldshop_list_size());
	for(int32_t i = 0; i < (int32_t)dragonWorldWargoldShop_List.GetSize(); ++i) {
		const ::proto_ff::dragonWorldWargoldShop & temp_dragonworldwargoldshop_list = msg.dragonworldwargoldshop_list(i);
		dragonWorldWargoldShop_List[i].read_from_pbmsg(temp_dragonworldwargoldshop_list);
	}
}

}