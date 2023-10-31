#include "E_Personalshop_s.h"

namespace proto_ff_s {

E_PersonalshopShopitems_s::E_PersonalshopShopitems_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PersonalshopShopitems_s::CreateInit() {
	m_id = (int32_t)0;
	m_shopId = (int32_t)0;
	m_itemID = (int32_t)0;
	m_amount = (int32_t)0;
	m_currency = (int32_t)0;
	m_price = (int32_t)0;
	m_discount = (int32_t)0;
	m_lvLimit = (int32_t)0;
	m_weight = (int32_t)0;
	return 0;
}

int E_PersonalshopShopitems_s::ResumeInit() {
	return 0;
}

void E_PersonalshopShopitems_s::write_to_pbmsg(::proto_ff::E_PersonalshopShopitems & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_shopid((int32_t)m_shopId);
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_amount((int32_t)m_amount);
	msg.set_m_currency((int32_t)m_currency);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_discount((int32_t)m_discount);
	msg.set_m_lvlimit((int32_t)m_lvLimit);
	msg.set_m_weight((int32_t)m_weight);
}

void E_PersonalshopShopitems_s::read_from_pbmsg(const ::proto_ff::E_PersonalshopShopitems & msg) {
	m_id = msg.m_id();
	m_shopId = msg.m_shopid();
	m_itemID = msg.m_itemid();
	m_amount = msg.m_amount();
	m_currency = msg.m_currency();
	m_price = msg.m_price();
	m_discount = msg.m_discount();
	m_lvLimit = msg.m_lvlimit();
	m_weight = msg.m_weight();
}

Sheet_PersonalshopShopitems_s::Sheet_PersonalshopShopitems_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PersonalshopShopitems_s::CreateInit() {
	return 0;
}

int Sheet_PersonalshopShopitems_s::ResumeInit() {
	return 0;
}

void Sheet_PersonalshopShopitems_s::write_to_pbmsg(::proto_ff::Sheet_PersonalshopShopitems & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PersonalshopShopitems_List.size(); ++i) {
		::proto_ff::E_PersonalshopShopitems* temp_e_personalshopshopitems_list = msg.add_e_personalshopshopitems_list();
		E_PersonalshopShopitems_List[i].write_to_pbmsg(*temp_e_personalshopshopitems_list);
	}
}

void Sheet_PersonalshopShopitems_s::read_from_pbmsg(const ::proto_ff::Sheet_PersonalshopShopitems & msg) {
	E_PersonalshopShopitems_List.resize((int)msg.e_personalshopshopitems_list_size() > (int)E_PersonalshopShopitems_List.max_size() ? E_PersonalshopShopitems_List.max_size() : msg.e_personalshopshopitems_list_size());
	for(int32_t i = 0; i < (int32_t)E_PersonalshopShopitems_List.size(); ++i) {
		const ::proto_ff::E_PersonalshopShopitems & temp_e_personalshopshopitems_list = msg.e_personalshopshopitems_list(i);
		E_PersonalshopShopitems_List[i].read_from_pbmsg(temp_e_personalshopshopitems_list);
	}
}

E_PersonalshopShops_s::E_PersonalshopShops_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PersonalshopShops_s::CreateInit() {
	m_id = (int32_t)0;
	m_keepTime = (int32_t)0;
	m_freeTimes = (int32_t)0;
	m_refreshMoney = (int32_t)0;
	m_refreshPrice = (int32_t)0;
	m_saleListCount = (int32_t)0;
	m_addType = (int32_t)0;
	m_addTypeValue = (int32_t)0;
	return 0;
}

int E_PersonalshopShops_s::ResumeInit() {
	return 0;
}

void E_PersonalshopShops_s::write_to_pbmsg(::proto_ff::E_PersonalshopShops & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_keeptime((int32_t)m_keepTime);
	msg.set_m_freetimes((int32_t)m_freeTimes);
	msg.set_m_refreshmoney((int32_t)m_refreshMoney);
	msg.set_m_refreshprice((int32_t)m_refreshPrice);
	msg.set_m_salelistcount((int32_t)m_saleListCount);
	msg.set_m_addtype((int32_t)m_addType);
	msg.set_m_addtypevalue((int32_t)m_addTypeValue);
}

void E_PersonalshopShops_s::read_from_pbmsg(const ::proto_ff::E_PersonalshopShops & msg) {
	m_id = msg.m_id();
	m_keepTime = msg.m_keeptime();
	m_freeTimes = msg.m_freetimes();
	m_refreshMoney = msg.m_refreshmoney();
	m_refreshPrice = msg.m_refreshprice();
	m_saleListCount = msg.m_salelistcount();
	m_addType = msg.m_addtype();
	m_addTypeValue = msg.m_addtypevalue();
}

Sheet_PersonalshopShops_s::Sheet_PersonalshopShops_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PersonalshopShops_s::CreateInit() {
	return 0;
}

int Sheet_PersonalshopShops_s::ResumeInit() {
	return 0;
}

void Sheet_PersonalshopShops_s::write_to_pbmsg(::proto_ff::Sheet_PersonalshopShops & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PersonalshopShops_List.size(); ++i) {
		::proto_ff::E_PersonalshopShops* temp_e_personalshopshops_list = msg.add_e_personalshopshops_list();
		E_PersonalshopShops_List[i].write_to_pbmsg(*temp_e_personalshopshops_list);
	}
}

void Sheet_PersonalshopShops_s::read_from_pbmsg(const ::proto_ff::Sheet_PersonalshopShops & msg) {
	E_PersonalshopShops_List.resize((int)msg.e_personalshopshops_list_size() > (int)E_PersonalshopShops_List.max_size() ? E_PersonalshopShops_List.max_size() : msg.e_personalshopshops_list_size());
	for(int32_t i = 0; i < (int32_t)E_PersonalshopShops_List.size(); ++i) {
		const ::proto_ff::E_PersonalshopShops & temp_e_personalshopshops_list = msg.e_personalshopshops_list(i);
		E_PersonalshopShops_List[i].read_from_pbmsg(temp_e_personalshopshops_list);
	}
}

}
