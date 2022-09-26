#include "chooseGift_s.h"

namespace proto_ff_s {

chooseGiftchooseGiftrechargeDesc_s::chooseGiftchooseGiftrechargeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int chooseGiftchooseGiftrechargeDesc_s::CreateInit() {
	Box = (int64_t)0;
	Id = (int32_t)0;
	return 0;
}

int chooseGiftchooseGiftrechargeDesc_s::ResumeInit() {
	return 0;
}

void chooseGiftchooseGiftrechargeDesc_s::write_to_pbmsg(::proto_ff::chooseGiftchooseGiftrechargeDesc & msg) const {
	msg.set_box((int64_t)Box);
	msg.set_id((int32_t)Id);
}

void chooseGiftchooseGiftrechargeDesc_s::read_from_pbmsg(const ::proto_ff::chooseGiftchooseGiftrechargeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct chooseGiftchooseGiftrechargeDesc_s));
	Box = msg.box();
	Id = msg.id();
}

chooseGiftchooseGift_s::chooseGiftchooseGift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int chooseGiftchooseGift_s::CreateInit() {
	id = (int32_t)0;
	box = (int64_t)0;
	switchTime = (int32_t)0;
	return 0;
}

int chooseGiftchooseGift_s::ResumeInit() {
	return 0;
}

void chooseGiftchooseGift_s::write_to_pbmsg(::proto_ff::chooseGiftchooseGift & msg) const {
	msg.set_id((int32_t)id);
	msg.set_box((int64_t)box);
	msg.set_switchtime((int32_t)switchTime);
	for(int32_t i = 0; i < (int32_t)recharge.GetSize() && i < recharge.GetMaxSize(); ++i) {
		::proto_ff::chooseGiftchooseGiftrechargeDesc* temp_recharge = msg.add_recharge();
		recharge[i].write_to_pbmsg(*temp_recharge);
	}
}

void chooseGiftchooseGift_s::read_from_pbmsg(const ::proto_ff::chooseGiftchooseGift & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct chooseGiftchooseGift_s));
	id = msg.id();
	box = msg.box();
	switchTime = msg.switchtime();
	recharge.SetSize(msg.recharge_size() > recharge.GetMaxSize() ? recharge.GetMaxSize() : msg.recharge_size());
	for(int32_t i = 0; i < (int32_t)recharge.GetSize(); ++i) {
		const ::proto_ff::chooseGiftchooseGiftrechargeDesc & temp_recharge = msg.recharge(i);
		recharge[i].read_from_pbmsg(temp_recharge);
	}
}

Sheet_chooseGiftchooseGift_s::Sheet_chooseGiftchooseGift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_chooseGiftchooseGift_s::CreateInit() {
	return 0;
}

int Sheet_chooseGiftchooseGift_s::ResumeInit() {
	return 0;
}

void Sheet_chooseGiftchooseGift_s::write_to_pbmsg(::proto_ff::Sheet_chooseGiftchooseGift & msg) const {
	for(int32_t i = 0; i < (int32_t)chooseGiftchooseGift_List.GetSize() && i < chooseGiftchooseGift_List.GetMaxSize(); ++i) {
		::proto_ff::chooseGiftchooseGift* temp_choosegiftchoosegift_list = msg.add_choosegiftchoosegift_list();
		chooseGiftchooseGift_List[i].write_to_pbmsg(*temp_choosegiftchoosegift_list);
	}
}

void Sheet_chooseGiftchooseGift_s::read_from_pbmsg(const ::proto_ff::Sheet_chooseGiftchooseGift & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_chooseGiftchooseGift_s));
	chooseGiftchooseGift_List.SetSize(msg.choosegiftchoosegift_list_size() > chooseGiftchooseGift_List.GetMaxSize() ? chooseGiftchooseGift_List.GetMaxSize() : msg.choosegiftchoosegift_list_size());
	for(int32_t i = 0; i < (int32_t)chooseGiftchooseGift_List.GetSize(); ++i) {
		const ::proto_ff::chooseGiftchooseGift & temp_choosegiftchoosegift_list = msg.choosegiftchoosegift_list(i);
		chooseGiftchooseGift_List[i].read_from_pbmsg(temp_choosegiftchoosegift_list);
	}
}

}