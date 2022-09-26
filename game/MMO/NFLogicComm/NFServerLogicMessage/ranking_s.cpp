#include "ranking_s.h"

namespace proto_ff_s {

rankingranking_s::rankingranking_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rankingranking_s::CreateInit() {
	rankingID = (int32_t)0;
	save = (int32_t)0;
	capacity = (int32_t)0;
	showSize = (int32_t)0;
	rankModule = (int32_t)0;
	return 0;
}

int rankingranking_s::ResumeInit() {
	return 0;
}

void rankingranking_s::write_to_pbmsg(::proto_ff::rankingranking & msg) const {
	msg.set_rankingid((int32_t)rankingID);
	msg.set_rankingname((const char*)rankingName.Get());
	msg.set_save((int32_t)save);
	msg.set_capacity((int32_t)capacity);
	msg.set_showsize((int32_t)showSize);
	msg.set_rankmodule((int32_t)rankModule);
		msg.add_dateid((int32_t)dateID[i]);
	}
}

void rankingranking_s::read_from_pbmsg(const ::proto_ff::rankingranking & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rankingranking_s));
	rankingID = msg.rankingid();
	rankingName.Copy(msg.rankingname());
	save = msg.save();
	capacity = msg.capacity();
	showSize = msg.showsize();
	rankModule = msg.rankmodule();
		dateID[i] = msg.dateid(i);
	}
}

Sheet_rankingranking_s::Sheet_rankingranking_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_rankingranking_s::CreateInit() {
	return 0;
}

int Sheet_rankingranking_s::ResumeInit() {
	return 0;
}

void Sheet_rankingranking_s::write_to_pbmsg(::proto_ff::Sheet_rankingranking & msg) const {
	for(int32_t i = 0; i < (int32_t)rankingranking_List.GetSize() && i < rankingranking_List.GetMaxSize(); ++i) {
		::proto_ff::rankingranking* temp_rankingranking_list = msg.add_rankingranking_list();
		rankingranking_List[i].write_to_pbmsg(*temp_rankingranking_list);
	}
}

void Sheet_rankingranking_s::read_from_pbmsg(const ::proto_ff::Sheet_rankingranking & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_rankingranking_s));
	rankingranking_List.SetSize(msg.rankingranking_list_size() > rankingranking_List.GetMaxSize() ? rankingranking_List.GetMaxSize() : msg.rankingranking_list_size());
	for(int32_t i = 0; i < (int32_t)rankingranking_List.GetSize(); ++i) {
		const ::proto_ff::rankingranking & temp_rankingranking_list = msg.rankingranking_list(i);
		rankingranking_List[i].read_from_pbmsg(temp_rankingranking_list);
	}
}

rankingdate_s::rankingdate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rankingdate_s::CreateInit() {
	dateID = (int32_t)0;
	return 0;
}

int rankingdate_s::ResumeInit() {
	return 0;
}

void rankingdate_s::write_to_pbmsg(::proto_ff::rankingdate & msg) const {
	msg.set_dateid((int32_t)dateID);
	msg.set_datename((const char*)dateName.Get());
}

void rankingdate_s::read_from_pbmsg(const ::proto_ff::rankingdate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rankingdate_s));
	dateID = msg.dateid();
	dateName.Copy(msg.datename());
}

Sheet_rankingdate_s::Sheet_rankingdate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_rankingdate_s::CreateInit() {
	return 0;
}

int Sheet_rankingdate_s::ResumeInit() {
	return 0;
}

void Sheet_rankingdate_s::write_to_pbmsg(::proto_ff::Sheet_rankingdate & msg) const {
	for(int32_t i = 0; i < (int32_t)rankingdate_List.GetSize() && i < rankingdate_List.GetMaxSize(); ++i) {
		::proto_ff::rankingdate* temp_rankingdate_list = msg.add_rankingdate_list();
		rankingdate_List[i].write_to_pbmsg(*temp_rankingdate_list);
	}
}

void Sheet_rankingdate_s::read_from_pbmsg(const ::proto_ff::Sheet_rankingdate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_rankingdate_s));
	rankingdate_List.SetSize(msg.rankingdate_list_size() > rankingdate_List.GetMaxSize() ? rankingdate_List.GetMaxSize() : msg.rankingdate_list_size());
	for(int32_t i = 0; i < (int32_t)rankingdate_List.GetSize(); ++i) {
		const ::proto_ff::rankingdate & temp_rankingdate_list = msg.rankingdate_list(i);
		rankingdate_List[i].read_from_pbmsg(temp_rankingdate_list);
	}
}

rankingpkcons_s::rankingpkcons_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rankingpkcons_s::CreateInit() {
	ID = (int32_t)0;
	valuedata = (int32_t)0;
	return 0;
}

int rankingpkcons_s::ResumeInit() {
	return 0;
}

void rankingpkcons_s::write_to_pbmsg(::proto_ff::rankingpkcons & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_valuedata((int32_t)valuedata);
	msg.set_stringdata((const char*)stringdata.Get());
}

void rankingpkcons_s::read_from_pbmsg(const ::proto_ff::rankingpkcons & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rankingpkcons_s));
	ID = msg.id();
	valuedata = msg.valuedata();
	stringdata.Copy(msg.stringdata());
}

Sheet_rankingpkcons_s::Sheet_rankingpkcons_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_rankingpkcons_s::CreateInit() {
	return 0;
}

int Sheet_rankingpkcons_s::ResumeInit() {
	return 0;
}

void Sheet_rankingpkcons_s::write_to_pbmsg(::proto_ff::Sheet_rankingpkcons & msg) const {
	for(int32_t i = 0; i < (int32_t)rankingpkcons_List.GetSize() && i < rankingpkcons_List.GetMaxSize(); ++i) {
		::proto_ff::rankingpkcons* temp_rankingpkcons_list = msg.add_rankingpkcons_list();
		rankingpkcons_List[i].write_to_pbmsg(*temp_rankingpkcons_list);
	}
}

void Sheet_rankingpkcons_s::read_from_pbmsg(const ::proto_ff::Sheet_rankingpkcons & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_rankingpkcons_s));
	rankingpkcons_List.SetSize(msg.rankingpkcons_list_size() > rankingpkcons_List.GetMaxSize() ? rankingpkcons_List.GetMaxSize() : msg.rankingpkcons_list_size());
	for(int32_t i = 0; i < (int32_t)rankingpkcons_List.GetSize(); ++i) {
		const ::proto_ff::rankingpkcons & temp_rankingpkcons_list = msg.rankingpkcons_list(i);
		rankingpkcons_List[i].read_from_pbmsg(temp_rankingpkcons_list);
	}
}

}