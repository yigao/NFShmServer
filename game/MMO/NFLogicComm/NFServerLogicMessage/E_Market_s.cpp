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
	m_itemid = (int32_t)0;
	m_type = (int32_t)0;
	m_order = (int32_t)0;
	m_readytime = (int32_t)0;
	m_sjtime = (int32_t)0;
	m_endtime = (int32_t)0;
	m_pricetype = (int32_t)0;
	m_vietype = (int32_t)0;
	m_startprice = (int32_t)0;
	m_onceprice = (int32_t)0;
	m_directprice = (int32_t)0;
	m_gztype = (int32_t)0;
	m_recoverytype = (int32_t)0;
	return 0;
}

int E_MarketMarket_s::ResumeInit() {
	return 0;
}

void E_MarketMarket_s::write_to_pbmsg(::proto_ff::E_MarketMarket & msg) const {
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_order((int32_t)m_order);
	msg.set_m_readytime((int32_t)m_readytime);
	msg.set_m_sjtime((int32_t)m_sjtime);
	msg.set_m_endtime((int32_t)m_endtime);
	msg.set_m_pricetype((int32_t)m_pricetype);
	msg.set_m_vietype((int32_t)m_vietype);
	msg.set_m_startprice((int32_t)m_startprice);
	msg.set_m_onceprice((int32_t)m_onceprice);
	msg.set_m_directprice((int32_t)m_directprice);
	msg.set_m_gztype((int32_t)m_gztype);
	msg.set_m_gztutype(m_gztutype.data());
	msg.set_m_recoverytype((int32_t)m_recoverytype);
}

void E_MarketMarket_s::read_from_pbmsg(const ::proto_ff::E_MarketMarket & msg) {
	m_itemid = msg.m_itemid();
	m_type = msg.m_type();
	m_order = msg.m_order();
	m_readytime = msg.m_readytime();
	m_sjtime = msg.m_sjtime();
	m_endtime = msg.m_endtime();
	m_pricetype = msg.m_pricetype();
	m_vietype = msg.m_vietype();
	m_startprice = msg.m_startprice();
	m_onceprice = msg.m_onceprice();
	m_directprice = msg.m_directprice();
	m_gztype = msg.m_gztype();
	m_gztutype = msg.m_gztutype();
	m_recoverytype = msg.m_recoverytype();
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
	msg.set_m_bigname(m_bigname.data());
	msg.set_m_xb((int32_t)m_xb);
}

void E_MarketBig_s::read_from_pbmsg(const ::proto_ff::E_MarketBig & msg) {
	m_id = msg.m_id();
	m_bigname = msg.m_bigname();
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
	m_openlevel = (int32_t)0;
	m_bigid = (int32_t)0;
	return 0;
}

int E_MarketSmall_s::ResumeInit() {
	return 0;
}

void E_MarketSmall_s::write_to_pbmsg(::proto_ff::E_MarketSmall & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_smallname(m_smallname.data());
	msg.set_m_openlevel((int32_t)m_openlevel);
	msg.set_m_bigid((int32_t)m_bigid);
}

void E_MarketSmall_s::read_from_pbmsg(const ::proto_ff::E_MarketSmall & msg) {
	m_id = msg.m_id();
	m_smallname = msg.m_smallname();
	m_openlevel = msg.m_openlevel();
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
	m_taxrate = (int32_t)0;
	m_bpselltime = (int32_t)0;
	m_sellnum = (int32_t)0;
	m_recyclenum = (int32_t)0;
	m_gz = (int32_t)0;
	m_dh = (int32_t)0;
	return 0;
}

int E_MarketConstant_s::ResumeInit() {
	return 0;
}

void E_MarketConstant_s::write_to_pbmsg(::proto_ff::E_MarketConstant & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_taxrate((int32_t)m_taxrate);
	msg.set_m_bpselltime((int32_t)m_bpselltime);
	msg.set_m_sellnum((int32_t)m_sellnum);
	msg.set_m_recyclenum((int32_t)m_recyclenum);
	msg.set_m_gz((int32_t)m_gz);
	msg.set_m_epackagetype(m_epackagetype.data());
	msg.set_m_dh((int32_t)m_dh);
}

void E_MarketConstant_s::read_from_pbmsg(const ::proto_ff::E_MarketConstant & msg) {
	m_id = msg.m_id();
	m_taxrate = msg.m_taxrate();
	m_bpselltime = msg.m_bpselltime();
	m_sellnum = msg.m_sellnum();
	m_recyclenum = msg.m_recyclenum();
	m_gz = msg.m_gz();
	m_epackagetype = msg.m_epackagetype();
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
