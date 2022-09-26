#include "conditionshop_s.h"

namespace proto_ff_s {

conditionshopconditionshop_s::conditionshopconditionshop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int conditionshopconditionshop_s::CreateInit() {
	Id = (int32_t)0;
	Type = (int32_t)0;
	Time = (int32_t)0;
	boxId = (int64_t)0;
	type = (int32_t)0;
	DiscountPrice = (int32_t)0;
	return 0;
}

int conditionshopconditionshop_s::ResumeInit() {
	return 0;
}

void conditionshopconditionshop_s::write_to_pbmsg(::proto_ff::conditionshopconditionshop & msg) const {
	msg.set_id((int32_t)Id);
	msg.set_type((int32_t)Type);
	msg.set_time((int32_t)Time);
	msg.set_boxid((int64_t)boxId);
	msg.set_itemid((const char*)itemId.Get());
	msg.set_type((int32_t)type);
	msg.set_discountprice((int32_t)DiscountPrice);
	for(int32_t i = 0; i < (int32_t)ConditionParam.GetSize() && i < ConditionParam.GetMaxSize(); ++i) {
		msg.add_conditionparam((const char*)ConditionParam[i].Get());
	}
	for(int32_t i = 0; i < (int32_t)ConditionType.GetSize() && i < ConditionType.GetMaxSize(); ++i) {
		msg.add_conditiontype((int32_t)ConditionType[i]);
	}
}

void conditionshopconditionshop_s::read_from_pbmsg(const ::proto_ff::conditionshopconditionshop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct conditionshopconditionshop_s));
	Id = msg.id();
	Type = msg.type();
	Time = msg.time();
	boxId = msg.boxid();
	itemId.Copy(msg.itemid());
	type = msg.type();
	DiscountPrice = msg.discountprice();
	ConditionParam.SetSize(msg.conditionparam_size() > ConditionParam.GetMaxSize() ? ConditionParam.GetMaxSize() : msg.conditionparam_size());
	for(int32_t i = 0; i < (int32_t)ConditionParam.GetSize(); ++i) {
		ConditionParam[i].Copy(msg.conditionparam(i));
	}
	ConditionType.SetSize(msg.conditiontype_size() > ConditionType.GetMaxSize() ? ConditionType.GetMaxSize() : msg.conditiontype_size());
	for(int32_t i = 0; i < (int32_t)ConditionType.GetSize(); ++i) {
		ConditionType[i] = msg.conditiontype(i);
	}
}

Sheet_conditionshopconditionshop_s::Sheet_conditionshopconditionshop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_conditionshopconditionshop_s::CreateInit() {
	return 0;
}

int Sheet_conditionshopconditionshop_s::ResumeInit() {
	return 0;
}

void Sheet_conditionshopconditionshop_s::write_to_pbmsg(::proto_ff::Sheet_conditionshopconditionshop & msg) const {
	for(int32_t i = 0; i < (int32_t)conditionshopconditionshop_List.GetSize() && i < conditionshopconditionshop_List.GetMaxSize(); ++i) {
		::proto_ff::conditionshopconditionshop* temp_conditionshopconditionshop_list = msg.add_conditionshopconditionshop_list();
		conditionshopconditionshop_List[i].write_to_pbmsg(*temp_conditionshopconditionshop_list);
	}
}

void Sheet_conditionshopconditionshop_s::read_from_pbmsg(const ::proto_ff::Sheet_conditionshopconditionshop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_conditionshopconditionshop_s));
	conditionshopconditionshop_List.SetSize(msg.conditionshopconditionshop_list_size() > conditionshopconditionshop_List.GetMaxSize() ? conditionshopconditionshop_List.GetMaxSize() : msg.conditionshopconditionshop_list_size());
	for(int32_t i = 0; i < (int32_t)conditionshopconditionshop_List.GetSize(); ++i) {
		const ::proto_ff::conditionshopconditionshop & temp_conditionshopconditionshop_list = msg.conditionshopconditionshop_list(i);
		conditionshopconditionshop_List[i].read_from_pbmsg(temp_conditionshopconditionshop_list);
	}
}

}