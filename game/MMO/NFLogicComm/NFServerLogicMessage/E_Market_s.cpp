#include "E_Market_s.h"

namespace proto_ff_s {

E_MarketMarket_s::E_MarketMarket_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarketMarket_s::CreateInit() {
	m_itemId = (int32_t)0;
	m_type = (int32_t)0;
	m_order = (int32_t)0;
	m_readyTime = (int32_t)0;
	m_sjTime = (int32_t)0;
	m_endTime = (int32_t)0;
	m_priceType = (int32_t)0;
	m_vieType = (int32_t)0;
	m_startPrice = (int32_t)0;
	m_oncePrice = (int32_t)0;
	m_directPrice = (int32_t)0;
	m_gzType = (int32_t)0;
	m_recoveryType = (int32_t)0;
	return 0;
}

int E_MarketMarket_s::ResumeInit() {
	return 0;
}

void E_MarketMarket_s::write_to_pbmsg(::proto_ff::E_MarketMarket & msg) const {
	msg.set_m_itemid((int32_t)m_itemId);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_order((int32_t)m_order);
	msg.set_m_readytime((int32_t)m_readyTime);
	msg.set_m_sjtime((int32_t)m_sjTime);
	msg.set_m_endtime((int32_t)m_endTime);
	msg.set_m_pricetype((int32_t)m_priceType);
	msg.set_m_vietype((int32_t)m_vieType);
	msg.set_m_startprice((int32_t)m_startPrice);
	msg.set_m_onceprice((int32_t)m_oncePrice);
	msg.set_m_directprice((int32_t)m_directPrice);
	msg.set_m_gztype((int32_t)m_gzType);
	msg.set_m_gztutype(m_gztuType.data());
	msg.set_m_recoverytype((int32_t)m_recoveryType);
}

void E_MarketMarket_s::read_from_pbmsg(const ::proto_ff::E_MarketMarket & msg) {
	m_itemId = msg.m_itemid();
	m_type = msg.m_type();
	m_order = msg.m_order();
	m_readyTime = msg.m_readytime();
	m_sjTime = msg.m_sjtime();
	m_endTime = msg.m_endtime();
	m_priceType = msg.m_pricetype();
	m_vieType = msg.m_vietype();
	m_startPrice = msg.m_startprice();
	m_oncePrice = msg.m_onceprice();
	m_directPrice = msg.m_directprice();
	m_gzType = msg.m_gztype();
	m_gztuType = msg.m_gztutype();
	m_recoveryType = msg.m_recoverytype();
}

Sheet_MarketMarket_s::Sheet_MarketMarket_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarketMarket_s::CreateInit() {
	return 0;
}

int Sheet_MarketMarket_s::ResumeInit() {
	return 0;
}

void Sheet_MarketMarket_s::write_to_pbmsg(::proto_ff::Sheet_MarketMarket & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarketMarket_List.size(); ++i) {
		::proto_ff::E_MarketMarket* temp_e_marketmarket_list = msg.add_e_marketmarket_list();
		E_MarketMarket_List[i].write_to_pbmsg(*temp_e_marketmarket_list);
	}
}

void Sheet_MarketMarket_s::read_from_pbmsg(const ::proto_ff::Sheet_MarketMarket & msg) {
	E_MarketMarket_List.resize((int)msg.e_marketmarket_list_size() > (int)E_MarketMarket_List.max_size() ? E_MarketMarket_List.max_size() : msg.e_marketmarket_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarketMarket_List.size(); ++i) {
		const ::proto_ff::E_MarketMarket & temp_e_marketmarket_list = msg.e_marketmarket_list(i);
		E_MarketMarket_List[i].read_from_pbmsg(temp_e_marketmarket_list);
	}
}

E_MarketBig_s::E_MarketBig_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarketBig_s::CreateInit() {
	m_id = (int32_t)0;
	m_xb = (int32_t)0;
	return 0;
}

int E_MarketBig_s::ResumeInit() {
	return 0;
}

void E_MarketBig_s::write_to_pbmsg(::proto_ff::E_MarketBig & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_bigname(m_bigName.data());
	msg.set_m_xb((int32_t)m_xb);
}

void E_MarketBig_s::read_from_pbmsg(const ::proto_ff::E_MarketBig & msg) {
	m_id = msg.m_id();
	m_bigName = msg.m_bigname();
	m_xb = msg.m_xb();
}

Sheet_MarketBig_s::Sheet_MarketBig_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarketBig_s::CreateInit() {
	return 0;
}

int Sheet_MarketBig_s::ResumeInit() {
	return 0;
}

void Sheet_MarketBig_s::write_to_pbmsg(::proto_ff::Sheet_MarketBig & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarketBig_List.size(); ++i) {
		::proto_ff::E_MarketBig* temp_e_marketbig_list = msg.add_e_marketbig_list();
		E_MarketBig_List[i].write_to_pbmsg(*temp_e_marketbig_list);
	}
}

void Sheet_MarketBig_s::read_from_pbmsg(const ::proto_ff::Sheet_MarketBig & msg) {
	E_MarketBig_List.resize((int)msg.e_marketbig_list_size() > (int)E_MarketBig_List.max_size() ? E_MarketBig_List.max_size() : msg.e_marketbig_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarketBig_List.size(); ++i) {
		const ::proto_ff::E_MarketBig & temp_e_marketbig_list = msg.e_marketbig_list(i);
		E_MarketBig_List[i].read_from_pbmsg(temp_e_marketbig_list);
	}
}

E_MarketSmall_s::E_MarketSmall_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarketSmall_s::CreateInit() {
	m_id = (int32_t)0;
	m_openLevel = (int32_t)0;
	m_bigid = (int32_t)0;
	return 0;
}

int E_MarketSmall_s::ResumeInit() {
	return 0;
}

void E_MarketSmall_s::write_to_pbmsg(::proto_ff::E_MarketSmall & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_smallname(m_smallName.data());
	msg.set_m_openlevel((int32_t)m_openLevel);
	msg.set_m_bigid((int32_t)m_bigid);
}

void E_MarketSmall_s::read_from_pbmsg(const ::proto_ff::E_MarketSmall & msg) {
	m_id = msg.m_id();
	m_smallName = msg.m_smallname();
	m_openLevel = msg.m_openlevel();
	m_bigid = msg.m_bigid();
}

Sheet_MarketSmall_s::Sheet_MarketSmall_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarketSmall_s::CreateInit() {
	return 0;
}

int Sheet_MarketSmall_s::ResumeInit() {
	return 0;
}

void Sheet_MarketSmall_s::write_to_pbmsg(::proto_ff::Sheet_MarketSmall & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarketSmall_List.size(); ++i) {
		::proto_ff::E_MarketSmall* temp_e_marketsmall_list = msg.add_e_marketsmall_list();
		E_MarketSmall_List[i].write_to_pbmsg(*temp_e_marketsmall_list);
	}
}

void Sheet_MarketSmall_s::read_from_pbmsg(const ::proto_ff::Sheet_MarketSmall & msg) {
	E_MarketSmall_List.resize((int)msg.e_marketsmall_list_size() > (int)E_MarketSmall_List.max_size() ? E_MarketSmall_List.max_size() : msg.e_marketsmall_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarketSmall_List.size(); ++i) {
		const ::proto_ff::E_MarketSmall & temp_e_marketsmall_list = msg.e_marketsmall_list(i);
		E_MarketSmall_List[i].read_from_pbmsg(temp_e_marketsmall_list);
	}
}

E_MarketConstant_s::E_MarketConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarketConstant_s::CreateInit() {
	m_id = (int32_t)0;
	m_taxRate = (int32_t)0;
	m_BPsellTime = (int32_t)0;
	m_sellNum = (int32_t)0;
	m_recycleNum = (int32_t)0;
	m_gz = (int32_t)0;
	m_dh = (int32_t)0;
	return 0;
}

int E_MarketConstant_s::ResumeInit() {
	return 0;
}

void E_MarketConstant_s::write_to_pbmsg(::proto_ff::E_MarketConstant & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_taxrate((int32_t)m_taxRate);
	msg.set_m_bpselltime((int32_t)m_BPsellTime);
	msg.set_m_sellnum((int32_t)m_sellNum);
	msg.set_m_recyclenum((int32_t)m_recycleNum);
	msg.set_m_gz((int32_t)m_gz);
	msg.set_m_epackagetype(m_EpackageType.data());
	msg.set_m_dh((int32_t)m_dh);
}

void E_MarketConstant_s::read_from_pbmsg(const ::proto_ff::E_MarketConstant & msg) {
	m_id = msg.m_id();
	m_taxRate = msg.m_taxrate();
	m_BPsellTime = msg.m_bpselltime();
	m_sellNum = msg.m_sellnum();
	m_recycleNum = msg.m_recyclenum();
	m_gz = msg.m_gz();
	m_EpackageType = msg.m_epackagetype();
	m_dh = msg.m_dh();
}

Sheet_MarketConstant_s::Sheet_MarketConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarketConstant_s::CreateInit() {
	return 0;
}

int Sheet_MarketConstant_s::ResumeInit() {
	return 0;
}

void Sheet_MarketConstant_s::write_to_pbmsg(::proto_ff::Sheet_MarketConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarketConstant_List.size(); ++i) {
		::proto_ff::E_MarketConstant* temp_e_marketconstant_list = msg.add_e_marketconstant_list();
		E_MarketConstant_List[i].write_to_pbmsg(*temp_e_marketconstant_list);
	}
}

void Sheet_MarketConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_MarketConstant & msg) {
	E_MarketConstant_List.resize((int)msg.e_marketconstant_list_size() > (int)E_MarketConstant_List.max_size() ? E_MarketConstant_List.max_size() : msg.e_marketconstant_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarketConstant_List.size(); ++i) {
		const ::proto_ff::E_MarketConstant & temp_e_marketconstant_list = msg.e_marketconstant_list(i);
		E_MarketConstant_List[i].read_from_pbmsg(temp_e_marketconstant_list);
	}
}

}
