#include "E_Gift_s.h"

namespace proto_ff_s {

E_GiftFree_s::E_GiftFree_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GiftFree_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_costid = (int32_t)0;
	m_price = (int32_t)0;
	m_freeday = (int32_t)0;
	m_boxid = (int32_t)0;
	return 0;
}

int E_GiftFree_s::ResumeInit() {
	return 0;
}

void E_GiftFree_s::write_to_pbmsg(::proto_ff::E_GiftFree & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_costid((int32_t)m_costid);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_freeday((int32_t)m_freeday);
	msg.set_m_boxid((int32_t)m_boxid);
}

void E_GiftFree_s::read_from_pbmsg(const ::proto_ff::E_GiftFree & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_costid = msg.m_costid();
	m_price = msg.m_price();
	m_freeday = msg.m_freeday();
	m_boxid = msg.m_boxid();
}

Sheet_GiftFree_s::Sheet_GiftFree_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GiftFree_s::CreateInit() {
	return 0;
}

int Sheet_GiftFree_s::ResumeInit() {
	return 0;
}

void Sheet_GiftFree_s::write_to_pbmsg(::proto_ff::Sheet_GiftFree & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GiftFree_List.size(); ++i) {
		::proto_ff::E_GiftFree* temp_e_giftfree_list = msg.add_e_giftfree_list();
		E_GiftFree_List[i].write_to_pbmsg(*temp_e_giftfree_list);
	}
}

void Sheet_GiftFree_s::read_from_pbmsg(const ::proto_ff::Sheet_GiftFree & msg) {
	E_GiftFree_List.resize((int)msg.e_giftfree_list_size() > (int)E_GiftFree_List.max_size() ? E_GiftFree_List.max_size() : msg.e_giftfree_list_size());
	for(int32_t i = 0; i < (int32_t)E_GiftFree_List.size(); ++i) {
		const ::proto_ff::E_GiftFree & temp_e_giftfree_list = msg.e_giftfree_list(i);
		E_GiftFree_List[i].read_from_pbmsg(temp_e_giftfree_list);
	}
}

E_GiftCondition_s::E_GiftCondition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GiftCondition_s::CreateInit() {
	m_id = (int32_t)0;
	m_conditiontype = (int32_t)0;
	m_arg = (int32_t)0;
	m_time = (int32_t)0;
	m_pricetype = (int32_t)0;
	m_price = (int32_t)0;
	m_boxid = (int32_t)0;
	return 0;
}

int E_GiftCondition_s::ResumeInit() {
	return 0;
}

void E_GiftCondition_s::write_to_pbmsg(::proto_ff::E_GiftCondition & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_conditiontype((int32_t)m_conditiontype);
	msg.set_m_arg((int32_t)m_arg);
	msg.set_m_time((int32_t)m_time);
	msg.set_m_pricetype((int32_t)m_pricetype);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_boxid((int32_t)m_boxid);
}

void E_GiftCondition_s::read_from_pbmsg(const ::proto_ff::E_GiftCondition & msg) {
	m_id = msg.m_id();
	m_conditiontype = msg.m_conditiontype();
	m_arg = msg.m_arg();
	m_time = msg.m_time();
	m_pricetype = msg.m_pricetype();
	m_price = msg.m_price();
	m_boxid = msg.m_boxid();
}

Sheet_GiftCondition_s::Sheet_GiftCondition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GiftCondition_s::CreateInit() {
	return 0;
}

int Sheet_GiftCondition_s::ResumeInit() {
	return 0;
}

void Sheet_GiftCondition_s::write_to_pbmsg(::proto_ff::Sheet_GiftCondition & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GiftCondition_List.size(); ++i) {
		::proto_ff::E_GiftCondition* temp_e_giftcondition_list = msg.add_e_giftcondition_list();
		E_GiftCondition_List[i].write_to_pbmsg(*temp_e_giftcondition_list);
	}
}

void Sheet_GiftCondition_s::read_from_pbmsg(const ::proto_ff::Sheet_GiftCondition & msg) {
	E_GiftCondition_List.resize((int)msg.e_giftcondition_list_size() > (int)E_GiftCondition_List.max_size() ? E_GiftCondition_List.max_size() : msg.e_giftcondition_list_size());
	for(int32_t i = 0; i < (int32_t)E_GiftCondition_List.size(); ++i) {
		const ::proto_ff::E_GiftCondition & temp_e_giftcondition_list = msg.e_giftcondition_list(i);
		E_GiftCondition_List[i].read_from_pbmsg(temp_e_giftcondition_list);
	}
}

E_GiftMust_s::E_GiftMust_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GiftMust_s::CreateInit() {
	m_id = (int32_t)0;
	m_boxid = (int32_t)0;
	m_original = (int32_t)0;
	m_pricetype = (int32_t)0;
	m_price = (int32_t)0;
	return 0;
}

int E_GiftMust_s::ResumeInit() {
	return 0;
}

void E_GiftMust_s::write_to_pbmsg(::proto_ff::E_GiftMust & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_boxid((int32_t)m_boxid);
	msg.set_m_original((int32_t)m_original);
	msg.set_m_pricetype((int32_t)m_pricetype);
	msg.set_m_price((int32_t)m_price);
}

void E_GiftMust_s::read_from_pbmsg(const ::proto_ff::E_GiftMust & msg) {
	m_id = msg.m_id();
	m_boxid = msg.m_boxid();
	m_original = msg.m_original();
	m_pricetype = msg.m_pricetype();
	m_price = msg.m_price();
}

Sheet_GiftMust_s::Sheet_GiftMust_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GiftMust_s::CreateInit() {
	return 0;
}

int Sheet_GiftMust_s::ResumeInit() {
	return 0;
}

void Sheet_GiftMust_s::write_to_pbmsg(::proto_ff::Sheet_GiftMust & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GiftMust_List.size(); ++i) {
		::proto_ff::E_GiftMust* temp_e_giftmust_list = msg.add_e_giftmust_list();
		E_GiftMust_List[i].write_to_pbmsg(*temp_e_giftmust_list);
	}
}

void Sheet_GiftMust_s::read_from_pbmsg(const ::proto_ff::Sheet_GiftMust & msg) {
	E_GiftMust_List.resize((int)msg.e_giftmust_list_size() > (int)E_GiftMust_List.max_size() ? E_GiftMust_List.max_size() : msg.e_giftmust_list_size());
	for(int32_t i = 0; i < (int32_t)E_GiftMust_List.size(); ++i) {
		const ::proto_ff::E_GiftMust & temp_e_giftmust_list = msg.e_giftmust_list(i);
		E_GiftMust_List[i].read_from_pbmsg(temp_e_giftmust_list);
	}
}

}
