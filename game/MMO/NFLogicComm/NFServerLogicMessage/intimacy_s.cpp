#include "intimacy_s.h"

namespace proto_ff_s {

intimacyintimacyattributeDesc_s::intimacyintimacyattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int intimacyintimacyattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int intimacyintimacyattributeDesc_s::ResumeInit() {
	return 0;
}

void intimacyintimacyattributeDesc_s::write_to_pbmsg(::proto_ff::intimacyintimacyattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void intimacyintimacyattributeDesc_s::read_from_pbmsg(const ::proto_ff::intimacyintimacyattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct intimacyintimacyattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

intimacyintimacy_s::intimacyintimacy_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int intimacyintimacy_s::CreateInit() {
	lv = (int32_t)0;
	intimacyMin = (int32_t)0;
	intimacyMax = (int32_t)0;
	return 0;
}

int intimacyintimacy_s::ResumeInit() {
	return 0;
}

void intimacyintimacy_s::write_to_pbmsg(::proto_ff::intimacyintimacy & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_intimacymin((int32_t)intimacyMin);
	msg.set_intimacymax((int32_t)intimacyMax);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::intimacyintimacyattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void intimacyintimacy_s::read_from_pbmsg(const ::proto_ff::intimacyintimacy & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct intimacyintimacy_s));
	lv = msg.lv();
	intimacyMin = msg.intimacymin();
	intimacyMax = msg.intimacymax();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::intimacyintimacyattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_intimacyintimacy_s::Sheet_intimacyintimacy_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_intimacyintimacy_s::CreateInit() {
	return 0;
}

int Sheet_intimacyintimacy_s::ResumeInit() {
	return 0;
}

void Sheet_intimacyintimacy_s::write_to_pbmsg(::proto_ff::Sheet_intimacyintimacy & msg) const {
	for(int32_t i = 0; i < (int32_t)intimacyintimacy_List.GetSize() && i < intimacyintimacy_List.GetMaxSize(); ++i) {
		::proto_ff::intimacyintimacy* temp_intimacyintimacy_list = msg.add_intimacyintimacy_list();
		intimacyintimacy_List[i].write_to_pbmsg(*temp_intimacyintimacy_list);
	}
}

void Sheet_intimacyintimacy_s::read_from_pbmsg(const ::proto_ff::Sheet_intimacyintimacy & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_intimacyintimacy_s));
	intimacyintimacy_List.SetSize(msg.intimacyintimacy_list_size() > intimacyintimacy_List.GetMaxSize() ? intimacyintimacy_List.GetMaxSize() : msg.intimacyintimacy_list_size());
	for(int32_t i = 0; i < (int32_t)intimacyintimacy_List.GetSize(); ++i) {
		const ::proto_ff::intimacyintimacy & temp_intimacyintimacy_list = msg.intimacyintimacy_list(i);
		intimacyintimacy_List[i].read_from_pbmsg(temp_intimacyintimacy_list);
	}
}

intimacygift_s::intimacygift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int intimacygift_s::CreateInit() {
	id = (int64_t)0;
	moneyType = (int32_t)0;
	price = (int32_t)0;
	intimacy = (int32_t)0;
	return 0;
}

int intimacygift_s::ResumeInit() {
	return 0;
}

void intimacygift_s::write_to_pbmsg(::proto_ff::intimacygift & msg) const {
	msg.set_id((int64_t)id);
	msg.set_moneytype((int32_t)moneyType);
	msg.set_price((int32_t)price);
	msg.set_intimacy((int32_t)intimacy);
}

void intimacygift_s::read_from_pbmsg(const ::proto_ff::intimacygift & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct intimacygift_s));
	id = msg.id();
	moneyType = msg.moneytype();
	price = msg.price();
	intimacy = msg.intimacy();
}

Sheet_intimacygift_s::Sheet_intimacygift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_intimacygift_s::CreateInit() {
	return 0;
}

int Sheet_intimacygift_s::ResumeInit() {
	return 0;
}

void Sheet_intimacygift_s::write_to_pbmsg(::proto_ff::Sheet_intimacygift & msg) const {
	for(int32_t i = 0; i < (int32_t)intimacygift_List.GetSize() && i < intimacygift_List.GetMaxSize(); ++i) {
		::proto_ff::intimacygift* temp_intimacygift_list = msg.add_intimacygift_list();
		intimacygift_List[i].write_to_pbmsg(*temp_intimacygift_list);
	}
}

void Sheet_intimacygift_s::read_from_pbmsg(const ::proto_ff::Sheet_intimacygift & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_intimacygift_s));
	intimacygift_List.SetSize(msg.intimacygift_list_size() > intimacygift_List.GetMaxSize() ? intimacygift_List.GetMaxSize() : msg.intimacygift_list_size());
	for(int32_t i = 0; i < (int32_t)intimacygift_List.GetSize(); ++i) {
		const ::proto_ff::intimacygift & temp_intimacygift_list = msg.intimacygift_list(i);
		intimacygift_List[i].read_from_pbmsg(temp_intimacygift_list);
	}
}

}