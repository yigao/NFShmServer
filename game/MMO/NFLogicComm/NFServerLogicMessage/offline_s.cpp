#include "offline_s.h"

namespace proto_ff_s {

offlineoffline_s::offlineoffline_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int offlineoffline_s::CreateInit() {
	lv = (int32_t)0;
	offlineExp = (int64_t)0;
	return 0;
}

int offlineoffline_s::ResumeInit() {
	return 0;
}

void offlineoffline_s::write_to_pbmsg(::proto_ff::offlineoffline & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_offlineexp((int64_t)offlineExp);
}

void offlineoffline_s::read_from_pbmsg(const ::proto_ff::offlineoffline & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct offlineoffline_s));
	lv = msg.lv();
	offlineExp = msg.offlineexp();
}

Sheet_offlineoffline_s::Sheet_offlineoffline_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_offlineoffline_s::CreateInit() {
	return 0;
}

int Sheet_offlineoffline_s::ResumeInit() {
	return 0;
}

void Sheet_offlineoffline_s::write_to_pbmsg(::proto_ff::Sheet_offlineoffline & msg) const {
	for(int32_t i = 0; i < (int32_t)offlineoffline_List.GetSize() && i < offlineoffline_List.GetMaxSize(); ++i) {
		::proto_ff::offlineoffline* temp_offlineoffline_list = msg.add_offlineoffline_list();
		offlineoffline_List[i].write_to_pbmsg(*temp_offlineoffline_list);
	}
}

void Sheet_offlineoffline_s::read_from_pbmsg(const ::proto_ff::Sheet_offlineoffline & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_offlineoffline_s));
	offlineoffline_List.SetSize(msg.offlineoffline_list_size() > offlineoffline_List.GetMaxSize() ? offlineoffline_List.GetMaxSize() : msg.offlineoffline_list_size());
	for(int32_t i = 0; i < (int32_t)offlineoffline_List.GetSize(); ++i) {
		const ::proto_ff::offlineoffline & temp_offlineoffline_list = msg.offlineoffline_list(i);
		offlineoffline_List[i].read_from_pbmsg(temp_offlineoffline_list);
	}
}

offlineitemlistitemDesc_s::offlineitemlistitemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int offlineitemlistitemDesc_s::CreateInit() {
	Num = (int32_t)0;
	Vle = (int32_t)0;
	ID = (int64_t)0;
	return 0;
}

int offlineitemlistitemDesc_s::ResumeInit() {
	return 0;
}

void offlineitemlistitemDesc_s::write_to_pbmsg(::proto_ff::offlineitemlistitemDesc & msg) const {
	msg.set_num((int32_t)Num);
	msg.set_vle((int32_t)Vle);
	msg.set_id((int64_t)ID);
}

void offlineitemlistitemDesc_s::read_from_pbmsg(const ::proto_ff::offlineitemlistitemDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct offlineitemlistitemDesc_s));
	Num = msg.num();
	Vle = msg.vle();
	ID = msg.id();
}

offlineitemlist_s::offlineitemlist_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int offlineitemlist_s::CreateInit() {
	id = (int32_t)0;
	Lvdown = (int32_t)0;
	Lvup = (int32_t)0;
	daoju = (int32_t)0;
	return 0;
}

int offlineitemlist_s::ResumeInit() {
	return 0;
}

void offlineitemlist_s::write_to_pbmsg(::proto_ff::offlineitemlist & msg) const {
	msg.set_id((int32_t)id);
	msg.set_lvdown((int32_t)Lvdown);
	msg.set_lvup((int32_t)Lvup);
	msg.set_daoju((int32_t)daoju);
	for(int32_t i = 0; i < (int32_t)item.GetSize() && i < item.GetMaxSize(); ++i) {
		::proto_ff::offlineitemlistitemDesc* temp_item = msg.add_item();
		item[i].write_to_pbmsg(*temp_item);
	}
}

void offlineitemlist_s::read_from_pbmsg(const ::proto_ff::offlineitemlist & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct offlineitemlist_s));
	id = msg.id();
	Lvdown = msg.lvdown();
	Lvup = msg.lvup();
	daoju = msg.daoju();
	item.SetSize(msg.item_size() > item.GetMaxSize() ? item.GetMaxSize() : msg.item_size());
	for(int32_t i = 0; i < (int32_t)item.GetSize(); ++i) {
		const ::proto_ff::offlineitemlistitemDesc & temp_item = msg.item(i);
		item[i].read_from_pbmsg(temp_item);
	}
}

Sheet_offlineitemlist_s::Sheet_offlineitemlist_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_offlineitemlist_s::CreateInit() {
	return 0;
}

int Sheet_offlineitemlist_s::ResumeInit() {
	return 0;
}

void Sheet_offlineitemlist_s::write_to_pbmsg(::proto_ff::Sheet_offlineitemlist & msg) const {
	for(int32_t i = 0; i < (int32_t)offlineitemlist_List.GetSize() && i < offlineitemlist_List.GetMaxSize(); ++i) {
		::proto_ff::offlineitemlist* temp_offlineitemlist_list = msg.add_offlineitemlist_list();
		offlineitemlist_List[i].write_to_pbmsg(*temp_offlineitemlist_list);
	}
}

void Sheet_offlineitemlist_s::read_from_pbmsg(const ::proto_ff::Sheet_offlineitemlist & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_offlineitemlist_s));
	offlineitemlist_List.SetSize(msg.offlineitemlist_list_size() > offlineitemlist_List.GetMaxSize() ? offlineitemlist_List.GetMaxSize() : msg.offlineitemlist_list_size());
	for(int32_t i = 0; i < (int32_t)offlineitemlist_List.GetSize(); ++i) {
		const ::proto_ff::offlineitemlist & temp_offlineitemlist_list = msg.offlineitemlist_list(i);
		offlineitemlist_List[i].read_from_pbmsg(temp_offlineitemlist_list);
	}
}

}