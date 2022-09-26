#include "auction_s.h"

namespace proto_ff_s {

auctionacquisition_s::auctionacquisition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int auctionacquisition_s::CreateInit() {
	Id = (int64_t)0;
	profession = (int32_t)0;
	position = (int32_t)0;
	num = (int32_t)0;
	return 0;
}

int auctionacquisition_s::ResumeInit() {
	return 0;
}

void auctionacquisition_s::write_to_pbmsg(::proto_ff::auctionacquisition & msg) const {
	msg.set_id((int64_t)Id);
	msg.set_profession((int32_t)profession);
	msg.set_position((int32_t)position);
	msg.set_name((const char*)name.Get());
	msg.set_icon((const char*)icon.Get());
	msg.set_num((int32_t)num);
}

void auctionacquisition_s::read_from_pbmsg(const ::proto_ff::auctionacquisition & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct auctionacquisition_s));
	Id = msg.id();
	profession = msg.profession();
	position = msg.position();
	name.Copy(msg.name());
	icon.Copy(msg.icon());
	num = msg.num();
}

Sheet_auctionacquisition_s::Sheet_auctionacquisition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_auctionacquisition_s::CreateInit() {
	return 0;
}

int Sheet_auctionacquisition_s::ResumeInit() {
	return 0;
}

void Sheet_auctionacquisition_s::write_to_pbmsg(::proto_ff::Sheet_auctionacquisition & msg) const {
	for(int32_t i = 0; i < (int32_t)auctionacquisition_List.GetSize() && i < auctionacquisition_List.GetMaxSize(); ++i) {
		::proto_ff::auctionacquisition* temp_auctionacquisition_list = msg.add_auctionacquisition_list();
		auctionacquisition_List[i].write_to_pbmsg(*temp_auctionacquisition_list);
	}
}

void Sheet_auctionacquisition_s::read_from_pbmsg(const ::proto_ff::Sheet_auctionacquisition & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_auctionacquisition_s));
	auctionacquisition_List.SetSize(msg.auctionacquisition_list_size() > auctionacquisition_List.GetMaxSize() ? auctionacquisition_List.GetMaxSize() : msg.auctionacquisition_list_size());
	for(int32_t i = 0; i < (int32_t)auctionacquisition_List.GetSize(); ++i) {
		const ::proto_ff::auctionacquisition & temp_auctionacquisition_list = msg.auctionacquisition_list(i);
		auctionacquisition_List[i].read_from_pbmsg(temp_auctionacquisition_list);
	}
}

auctionpurchase_s::auctionpurchase_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int auctionpurchase_s::CreateInit() {
	Id = (int64_t)0;
	type = (int32_t)0;
	subType = (int32_t)0;
	return 0;
}

int auctionpurchase_s::ResumeInit() {
	return 0;
}

void auctionpurchase_s::write_to_pbmsg(::proto_ff::auctionpurchase & msg) const {
	msg.set_id((int64_t)Id);
	msg.set_type((int32_t)type);
	msg.set_subtype((int32_t)subType);
	msg.set_name((const char*)name.Get());
	msg.set_itemname((const char*)itemName.Get());
	msg.set_itemid((const char*)itemId.Get());
}

void auctionpurchase_s::read_from_pbmsg(const ::proto_ff::auctionpurchase & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct auctionpurchase_s));
	Id = msg.id();
	type = msg.type();
	subType = msg.subtype();
	name.Copy(msg.name());
	itemName.Copy(msg.itemname());
	itemId.Copy(msg.itemid());
}

Sheet_auctionpurchase_s::Sheet_auctionpurchase_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_auctionpurchase_s::CreateInit() {
	return 0;
}

int Sheet_auctionpurchase_s::ResumeInit() {
	return 0;
}

void Sheet_auctionpurchase_s::write_to_pbmsg(::proto_ff::Sheet_auctionpurchase & msg) const {
	for(int32_t i = 0; i < (int32_t)auctionpurchase_List.GetSize() && i < auctionpurchase_List.GetMaxSize(); ++i) {
		::proto_ff::auctionpurchase* temp_auctionpurchase_list = msg.add_auctionpurchase_list();
		auctionpurchase_List[i].write_to_pbmsg(*temp_auctionpurchase_list);
	}
}

void Sheet_auctionpurchase_s::read_from_pbmsg(const ::proto_ff::Sheet_auctionpurchase & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_auctionpurchase_s));
	auctionpurchase_List.SetSize(msg.auctionpurchase_list_size() > auctionpurchase_List.GetMaxSize() ? auctionpurchase_List.GetMaxSize() : msg.auctionpurchase_list_size());
	for(int32_t i = 0; i < (int32_t)auctionpurchase_List.GetSize(); ++i) {
		const ::proto_ff::auctionpurchase & temp_auctionpurchase_list = msg.auctionpurchase_list(i);
		auctionpurchase_List[i].read_from_pbmsg(temp_auctionpurchase_list);
	}
}

}