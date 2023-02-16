#include "mall_s.h"

namespace proto_ff_s {

E_MallMall_s::E_MallMall_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MallMall_s::CreateInit() {
	m_id = (int32_t)0;
	m_itemid = (int32_t)0;
	m_malltype = (int32_t)0;
	m_priority = (int32_t)0;
	m_moneytype = (int32_t)0;
	m_price = (int32_t)0;
	m_secondarymoneytype = (int32_t)0;
	m_discount = (int32_t)0;
	m_buylimittype = (int32_t)0;
	m_buyamount = (int32_t)0;
	m_viplimit = (int32_t)0;
	m_lvlimit = (int32_t)0;
	m_vipunlock = (int32_t)0;
	m_isclose = (int32_t)0;
	m_cantbuy = (int32_t)0;
	m_ismarkbind = (int32_t)0;
	return 0;
}

int E_MallMall_s::ResumeInit() {
	return 0;
}

void E_MallMall_s::write_to_pbmsg(::proto_ff::E_MallMall & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_malltype((int32_t)m_malltype);
	msg.set_m_priority((int32_t)m_priority);
	msg.set_m_moneytype((int32_t)m_moneytype);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_secondarymoneytype((int32_t)m_secondarymoneytype);
	msg.set_m_discount((int32_t)m_discount);
	msg.set_m_buylimittype((int32_t)m_buylimittype);
	msg.set_m_buyamount((int32_t)m_buyamount);
	msg.set_m_viplimit((int32_t)m_viplimit);
	msg.set_m_lvlimit((int32_t)m_lvlimit);
	msg.set_m_vipunlock((int32_t)m_vipunlock);
	msg.set_m_isclose((int32_t)m_isclose);
	msg.set_m_cantbuy((int32_t)m_cantbuy);
	msg.set_m_ismarkbind((int32_t)m_ismarkbind);
}

void E_MallMall_s::read_from_pbmsg(const ::proto_ff::E_MallMall & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MallMall_s));
	m_id = msg.m_id();
	m_itemid = msg.m_itemid();
	m_malltype = msg.m_malltype();
	m_priority = msg.m_priority();
	m_moneytype = msg.m_moneytype();
	m_price = msg.m_price();
	m_secondarymoneytype = msg.m_secondarymoneytype();
	m_discount = msg.m_discount();
	m_buylimittype = msg.m_buylimittype();
	m_buyamount = msg.m_buyamount();
	m_viplimit = msg.m_viplimit();
	m_lvlimit = msg.m_lvlimit();
	m_vipunlock = msg.m_vipunlock();
	m_isclose = msg.m_isclose();
	m_cantbuy = msg.m_cantbuy();
	m_ismarkbind = msg.m_ismarkbind();
}

Sheet_MallMall_s::Sheet_MallMall_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MallMall_s::CreateInit() {
	return 0;
}

int Sheet_MallMall_s::ResumeInit() {
	return 0;
}

void Sheet_MallMall_s::write_to_pbmsg(::proto_ff::Sheet_MallMall & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MallMall_List.size(); ++i) {
		::proto_ff::E_MallMall* temp_e_mallmall_list = msg.add_e_mallmall_list();
		E_MallMall_List[i].write_to_pbmsg(*temp_e_mallmall_list);
	}
}

void Sheet_MallMall_s::read_from_pbmsg(const ::proto_ff::Sheet_MallMall & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MallMall_s));
	E_MallMall_List.resize((int)msg.e_mallmall_list_size() > (int)E_MallMall_List.max_size() ? E_MallMall_List.max_size() : msg.e_mallmall_list_size());
	for(int32_t i = 0; i < (int32_t)E_MallMall_List.size(); ++i) {
		const ::proto_ff::E_MallMall & temp_e_mallmall_list = msg.e_mallmall_list(i);
		E_MallMall_List[i].read_from_pbmsg(temp_e_mallmall_list);
	}
}

E_MallMalltype_s::E_MallMalltype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MallMalltype_s::CreateInit() {
	m_id = (int64_t)0;
	m_grouptype = (int32_t)0;
	m_priority = (int32_t)0;
	m_functionunlock = (int32_t)0;
	return 0;
}

int E_MallMalltype_s::ResumeInit() {
	return 0;
}

void E_MallMalltype_s::write_to_pbmsg(::proto_ff::E_MallMalltype & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_title((const char*)m_title.data());
	msg.set_m_grouptype((int32_t)m_grouptype);
	msg.set_m_priority((int32_t)m_priority);
	msg.set_m_functionunlock((int32_t)m_functionunlock);
}

void E_MallMalltype_s::read_from_pbmsg(const ::proto_ff::E_MallMalltype & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MallMalltype_s));
	m_id = msg.m_id();
	m_title = msg.m_title();
	m_grouptype = msg.m_grouptype();
	m_priority = msg.m_priority();
	m_functionunlock = msg.m_functionunlock();
}

Sheet_MallMalltype_s::Sheet_MallMalltype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MallMalltype_s::CreateInit() {
	return 0;
}

int Sheet_MallMalltype_s::ResumeInit() {
	return 0;
}

void Sheet_MallMalltype_s::write_to_pbmsg(::proto_ff::Sheet_MallMalltype & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MallMalltype_List.size(); ++i) {
		::proto_ff::E_MallMalltype* temp_e_mallmalltype_list = msg.add_e_mallmalltype_list();
		E_MallMalltype_List[i].write_to_pbmsg(*temp_e_mallmalltype_list);
	}
}

void Sheet_MallMalltype_s::read_from_pbmsg(const ::proto_ff::Sheet_MallMalltype & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MallMalltype_s));
	E_MallMalltype_List.resize((int)msg.e_mallmalltype_list_size() > (int)E_MallMalltype_List.max_size() ? E_MallMalltype_List.max_size() : msg.e_mallmalltype_list_size());
	for(int32_t i = 0; i < (int32_t)E_MallMalltype_List.size(); ++i) {
		const ::proto_ff::E_MallMalltype & temp_e_mallmalltype_list = msg.e_mallmalltype_list(i);
		E_MallMalltype_List[i].read_from_pbmsg(temp_e_mallmalltype_list);
	}
}

E_MallMalltype_tab_s::E_MallMalltype_tab_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MallMalltype_tab_s::CreateInit() {
	m_priority = (int32_t)0;
	m_functionunlock = (int32_t)0;
	return 0;
}

int E_MallMalltype_tab_s::ResumeInit() {
	return 0;
}

void E_MallMalltype_tab_s::write_to_pbmsg(::proto_ff::E_MallMalltype_tab & msg) const {
	msg.set_m_priority((int32_t)m_priority);
	msg.set_m_functionunlock((int32_t)m_functionunlock);
}

void E_MallMalltype_tab_s::read_from_pbmsg(const ::proto_ff::E_MallMalltype_tab & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MallMalltype_tab_s));
	m_priority = msg.m_priority();
	m_functionunlock = msg.m_functionunlock();
}

Sheet_MallMalltype_tab_s::Sheet_MallMalltype_tab_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MallMalltype_tab_s::CreateInit() {
	return 0;
}

int Sheet_MallMalltype_tab_s::ResumeInit() {
	return 0;
}

void Sheet_MallMalltype_tab_s::write_to_pbmsg(::proto_ff::Sheet_MallMalltype_tab & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MallMalltype_tab_List.size(); ++i) {
		::proto_ff::E_MallMalltype_tab* temp_e_mallmalltype_tab_list = msg.add_e_mallmalltype_tab_list();
		E_MallMalltype_tab_List[i].write_to_pbmsg(*temp_e_mallmalltype_tab_list);
	}
}

void Sheet_MallMalltype_tab_s::read_from_pbmsg(const ::proto_ff::Sheet_MallMalltype_tab & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MallMalltype_tab_s));
	E_MallMalltype_tab_List.resize((int)msg.e_mallmalltype_tab_list_size() > (int)E_MallMalltype_tab_List.max_size() ? E_MallMalltype_tab_List.max_size() : msg.e_mallmalltype_tab_list_size());
	for(int32_t i = 0; i < (int32_t)E_MallMalltype_tab_List.size(); ++i) {
		const ::proto_ff::E_MallMalltype_tab & temp_e_mallmalltype_tab_list = msg.e_mallmalltype_tab_list(i);
		E_MallMalltype_tab_List[i].read_from_pbmsg(temp_e_mallmalltype_tab_list);
	}
}

}