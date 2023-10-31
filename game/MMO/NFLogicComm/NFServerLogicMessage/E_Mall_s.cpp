#include "E_Mall_s.h"

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
	m_itemID = (int32_t)0;
	m_mallType = (int32_t)0;
	m_priority = (int32_t)0;
	m_moneyType = (int32_t)0;
	m_moneyItem = (int32_t)0;
	m_price = (int32_t)0;
	m_secondaryMoneyType = (int32_t)0;
	m_discount = (int32_t)0;
	m_buyLimitType = (int32_t)0;
	m_buyAmount = (int32_t)0;
	m_vipLimit = (int32_t)0;
	m_lvLimit = (int32_t)0;
	m_vipUnlock = (int32_t)0;
	m_isClose = (int32_t)0;
	m_cantBuy = (int32_t)0;
	m_isMarkBind = (int32_t)0;
	return 0;
}

int E_MallMall_s::ResumeInit() {
	return 0;
}

void E_MallMall_s::write_to_pbmsg(::proto_ff::E_MallMall & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_malltype((int32_t)m_mallType);
	msg.set_m_priority((int32_t)m_priority);
	msg.set_m_moneytype((int32_t)m_moneyType);
	msg.set_m_moneyitem((int32_t)m_moneyItem);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_secondarymoneytype((int32_t)m_secondaryMoneyType);
	msg.set_m_discount((int32_t)m_discount);
	msg.set_m_buylimittype((int32_t)m_buyLimitType);
	msg.set_m_buyamount((int32_t)m_buyAmount);
	msg.set_m_viplimit((int32_t)m_vipLimit);
	msg.set_m_lvlimit((int32_t)m_lvLimit);
	msg.set_m_vipunlock((int32_t)m_vipUnlock);
	msg.set_m_isclose((int32_t)m_isClose);
	msg.set_m_cantbuy((int32_t)m_cantBuy);
	msg.set_m_ismarkbind((int32_t)m_isMarkBind);
}

void E_MallMall_s::read_from_pbmsg(const ::proto_ff::E_MallMall & msg) {
	m_id = msg.m_id();
	m_itemID = msg.m_itemid();
	m_mallType = msg.m_malltype();
	m_priority = msg.m_priority();
	m_moneyType = msg.m_moneytype();
	m_moneyItem = msg.m_moneyitem();
	m_price = msg.m_price();
	m_secondaryMoneyType = msg.m_secondarymoneytype();
	m_discount = msg.m_discount();
	m_buyLimitType = msg.m_buylimittype();
	m_buyAmount = msg.m_buyamount();
	m_vipLimit = msg.m_viplimit();
	m_lvLimit = msg.m_lvlimit();
	m_vipUnlock = msg.m_vipunlock();
	m_isClose = msg.m_isclose();
	m_cantBuy = msg.m_cantbuy();
	m_isMarkBind = msg.m_ismarkbind();
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
	E_MallMall_List.resize((int)msg.e_mallmall_list_size() > (int)E_MallMall_List.max_size() ? E_MallMall_List.max_size() : msg.e_mallmall_list_size());
	for(int32_t i = 0; i < (int32_t)E_MallMall_List.size(); ++i) {
		const ::proto_ff::E_MallMall & temp_e_mallmall_list = msg.e_mallmall_list(i);
		E_MallMall_List[i].read_from_pbmsg(temp_e_mallmall_list);
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
	m_entrance = (int32_t)0;
	return 0;
}

int E_MallMalltype_tab_s::ResumeInit() {
	return 0;
}

void E_MallMalltype_tab_s::write_to_pbmsg(::proto_ff::E_MallMalltype_tab & msg) const {
	msg.set_m_priority((int32_t)m_priority);
	msg.set_m_functionunlock((int32_t)m_functionunlock);
	msg.set_m_entrance((int32_t)m_entrance);
}

void E_MallMalltype_tab_s::read_from_pbmsg(const ::proto_ff::E_MallMalltype_tab & msg) {
	m_priority = msg.m_priority();
	m_functionunlock = msg.m_functionunlock();
	m_entrance = msg.m_entrance();
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
	E_MallMalltype_tab_List.resize((int)msg.e_mallmalltype_tab_list_size() > (int)E_MallMalltype_tab_List.max_size() ? E_MallMalltype_tab_List.max_size() : msg.e_mallmalltype_tab_list_size());
	for(int32_t i = 0; i < (int32_t)E_MallMalltype_tab_List.size(); ++i) {
		const ::proto_ff::E_MallMalltype_tab & temp_e_mallmalltype_tab_list = msg.e_mallmalltype_tab_list(i);
		E_MallMalltype_tab_List[i].read_from_pbmsg(temp_e_mallmalltype_tab_list);
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
	m_groupType = (int32_t)0;
	m_priority = (int32_t)0;
	m_functionunlock = (int32_t)0;
	return 0;
}

int E_MallMalltype_s::ResumeInit() {
	return 0;
}

void E_MallMalltype_s::write_to_pbmsg(::proto_ff::E_MallMalltype & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_title(m_title.data());
	msg.set_m_grouptype((int32_t)m_groupType);
	msg.set_m_priority((int32_t)m_priority);
	msg.set_m_functionunlock((int32_t)m_functionunlock);
	msg.set_m_profession(m_profession.data());
}

void E_MallMalltype_s::read_from_pbmsg(const ::proto_ff::E_MallMalltype & msg) {
	m_id = msg.m_id();
	m_title = msg.m_title();
	m_groupType = msg.m_grouptype();
	m_priority = msg.m_priority();
	m_functionunlock = msg.m_functionunlock();
	m_profession = msg.m_profession();
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
	E_MallMalltype_List.resize((int)msg.e_mallmalltype_list_size() > (int)E_MallMalltype_List.max_size() ? E_MallMalltype_List.max_size() : msg.e_mallmalltype_list_size());
	for(int32_t i = 0; i < (int32_t)E_MallMalltype_List.size(); ++i) {
		const ::proto_ff::E_MallMalltype & temp_e_mallmalltype_list = msg.e_mallmalltype_list(i);
		E_MallMalltype_List[i].read_from_pbmsg(temp_e_mallmalltype_list);
	}
}

E_MallHolybeast_s::E_MallHolybeast_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MallHolybeast_s::CreateInit() {
	m_id = (int32_t)0;
	m_mountId = (int32_t)0;
	m_itemId = (int32_t)0;
	m_costId = (int32_t)0;
	m_costNum = (int32_t)0;
	return 0;
}

int E_MallHolybeast_s::ResumeInit() {
	return 0;
}

void E_MallHolybeast_s::write_to_pbmsg(::proto_ff::E_MallHolybeast & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_mountid((int32_t)m_mountId);
	msg.set_m_itemid((int32_t)m_itemId);
	msg.set_m_costid((int32_t)m_costId);
	msg.set_m_costnum((int32_t)m_costNum);
}

void E_MallHolybeast_s::read_from_pbmsg(const ::proto_ff::E_MallHolybeast & msg) {
	m_id = msg.m_id();
	m_mountId = msg.m_mountid();
	m_itemId = msg.m_itemid();
	m_costId = msg.m_costid();
	m_costNum = msg.m_costnum();
}

Sheet_MallHolybeast_s::Sheet_MallHolybeast_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MallHolybeast_s::CreateInit() {
	return 0;
}

int Sheet_MallHolybeast_s::ResumeInit() {
	return 0;
}

void Sheet_MallHolybeast_s::write_to_pbmsg(::proto_ff::Sheet_MallHolybeast & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MallHolybeast_List.size(); ++i) {
		::proto_ff::E_MallHolybeast* temp_e_mallholybeast_list = msg.add_e_mallholybeast_list();
		E_MallHolybeast_List[i].write_to_pbmsg(*temp_e_mallholybeast_list);
	}
}

void Sheet_MallHolybeast_s::read_from_pbmsg(const ::proto_ff::Sheet_MallHolybeast & msg) {
	E_MallHolybeast_List.resize((int)msg.e_mallholybeast_list_size() > (int)E_MallHolybeast_List.max_size() ? E_MallHolybeast_List.max_size() : msg.e_mallholybeast_list_size());
	for(int32_t i = 0; i < (int32_t)E_MallHolybeast_List.size(); ++i) {
		const ::proto_ff::E_MallHolybeast & temp_e_mallholybeast_list = msg.e_mallholybeast_list(i);
		E_MallHolybeast_List[i].read_from_pbmsg(temp_e_mallholybeast_list);
	}
}

}
