#include "E_Battlepass_s.h"

namespace proto_ff_s {

E_BattlepassBattlepass_s::E_BattlepassBattlepass_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BattlepassBattlepass_s::CreateInit() {
	m_id = (int32_t)0;
	m_reward = (int32_t)0;
	m_task = (int32_t)0;
	m_freshCost = (int32_t)0;
	m_shop = (int32_t)0;
	m_shopCurrency = (int32_t)0;
	m_severOpenType = (int32_t)0;
	m_openSeverDay = (int32_t)0;
	m_closeSeverDay = (int32_t)0;
	m_priceType = (int32_t)0;
	m_price = (int32_t)0;
	m_priceP = (int32_t)0;
	m_presentExp = (int32_t)0;
	m_expCost = (int32_t)0;
	m_expPrice = (int32_t)0;
	m_expItem = (int32_t)0;
	return 0;
}

int E_BattlepassBattlepass_s::ResumeInit() {
	return 0;
}

void E_BattlepassBattlepass_s::write_to_pbmsg(::proto_ff::E_BattlepassBattlepass & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_reward((int32_t)m_reward);
	msg.set_m_task((int32_t)m_task);
	msg.set_m_tasknum(m_taskNum.data());
	msg.set_m_freshcost((int32_t)m_freshCost);
	msg.set_m_shop((int32_t)m_shop);
	msg.set_m_shopcurrency((int32_t)m_shopCurrency);
	msg.set_m_severopentype((int32_t)m_severOpenType);
	msg.set_m_openseverday((int32_t)m_openSeverDay);
	msg.set_m_closeseverday((int32_t)m_closeSeverDay);
	msg.set_m_pricetype((int32_t)m_priceType);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_pricep((int32_t)m_priceP);
	msg.set_m_presentexp((int32_t)m_presentExp);
	msg.set_m_expcost((int32_t)m_expCost);
	msg.set_m_expprice((int32_t)m_expPrice);
	msg.set_m_expitem((int32_t)m_expItem);
}

void E_BattlepassBattlepass_s::read_from_pbmsg(const ::proto_ff::E_BattlepassBattlepass & msg) {
	m_id = msg.m_id();
	m_reward = msg.m_reward();
	m_task = msg.m_task();
	m_taskNum = msg.m_tasknum();
	m_freshCost = msg.m_freshcost();
	m_shop = msg.m_shop();
	m_shopCurrency = msg.m_shopcurrency();
	m_severOpenType = msg.m_severopentype();
	m_openSeverDay = msg.m_openseverday();
	m_closeSeverDay = msg.m_closeseverday();
	m_priceType = msg.m_pricetype();
	m_price = msg.m_price();
	m_priceP = msg.m_pricep();
	m_presentExp = msg.m_presentexp();
	m_expCost = msg.m_expcost();
	m_expPrice = msg.m_expprice();
	m_expItem = msg.m_expitem();
}

Sheet_BattlepassBattlepass_s::Sheet_BattlepassBattlepass_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_BattlepassBattlepass_s::CreateInit() {
	return 0;
}

int Sheet_BattlepassBattlepass_s::ResumeInit() {
	return 0;
}

void Sheet_BattlepassBattlepass_s::write_to_pbmsg(::proto_ff::Sheet_BattlepassBattlepass & msg) const {
	for(int32_t i = 0; i < (int32_t)E_BattlepassBattlepass_List.size(); ++i) {
		::proto_ff::E_BattlepassBattlepass* temp_e_battlepassbattlepass_list = msg.add_e_battlepassbattlepass_list();
		E_BattlepassBattlepass_List[i].write_to_pbmsg(*temp_e_battlepassbattlepass_list);
	}
}

void Sheet_BattlepassBattlepass_s::read_from_pbmsg(const ::proto_ff::Sheet_BattlepassBattlepass & msg) {
	E_BattlepassBattlepass_List.resize((int)msg.e_battlepassbattlepass_list_size() > (int)E_BattlepassBattlepass_List.max_size() ? E_BattlepassBattlepass_List.max_size() : msg.e_battlepassbattlepass_list_size());
	for(int32_t i = 0; i < (int32_t)E_BattlepassBattlepass_List.size(); ++i) {
		const ::proto_ff::E_BattlepassBattlepass & temp_e_battlepassbattlepass_list = msg.e_battlepassbattlepass_list(i);
		E_BattlepassBattlepass_List[i].read_from_pbmsg(temp_e_battlepassbattlepass_list);
	}
}

E_BattlepassRewardItemDesc_s::E_BattlepassRewardItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BattlepassRewardItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_BattlepassRewardItemDesc_s::ResumeInit() {
	return 0;
}

void E_BattlepassRewardItemDesc_s::write_to_pbmsg(::proto_ff::E_BattlepassRewardItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_BattlepassRewardItemDesc_s::read_from_pbmsg(const ::proto_ff::E_BattlepassRewardItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_BattlepassRewardProitemDesc_s::E_BattlepassRewardProitemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BattlepassRewardProitemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_BattlepassRewardProitemDesc_s::ResumeInit() {
	return 0;
}

void E_BattlepassRewardProitemDesc_s::write_to_pbmsg(::proto_ff::E_BattlepassRewardProitemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_BattlepassRewardProitemDesc_s::read_from_pbmsg(const ::proto_ff::E_BattlepassRewardProitemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_BattlepassReward_s::E_BattlepassReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BattlepassReward_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupid = (int32_t)0;
	m_lv = (int32_t)0;
	m_exp = (int32_t)0;
	m_Core = (int32_t)0;
	m_buyLevel = (int32_t)0;
	m_showItem = (int32_t)0;
	return 0;
}

int E_BattlepassReward_s::ResumeInit() {
	return 0;
}

void E_BattlepassReward_s::write_to_pbmsg(::proto_ff::E_BattlepassReward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_core((int32_t)m_Core);
	msg.set_m_buylevel((int32_t)m_buyLevel);
	msg.set_m_showitem((int32_t)m_showItem);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_BattlepassRewardItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
	for(int32_t i = 0; i < (int32_t)m_proItem.size(); ++i) {
		::proto_ff::E_BattlepassRewardProitemDesc* temp_m_proitem = msg.add_m_proitem();
		m_proItem[i].write_to_pbmsg(*temp_m_proitem);
	}
}

void E_BattlepassReward_s::read_from_pbmsg(const ::proto_ff::E_BattlepassReward & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
	m_Core = msg.m_core();
	m_buyLevel = msg.m_buylevel();
	m_showItem = msg.m_showitem();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_BattlepassRewardItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
	m_proItem.resize((int)msg.m_proitem_size() > (int)m_proItem.max_size() ? m_proItem.max_size() : msg.m_proitem_size());
	for(int32_t i = 0; i < (int32_t)m_proItem.size(); ++i) {
		const ::proto_ff::E_BattlepassRewardProitemDesc & temp_m_proitem = msg.m_proitem(i);
		m_proItem[i].read_from_pbmsg(temp_m_proitem);
	}
}

Sheet_BattlepassReward_s::Sheet_BattlepassReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_BattlepassReward_s::CreateInit() {
	return 0;
}

int Sheet_BattlepassReward_s::ResumeInit() {
	return 0;
}

void Sheet_BattlepassReward_s::write_to_pbmsg(::proto_ff::Sheet_BattlepassReward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_BattlepassReward_List.size(); ++i) {
		::proto_ff::E_BattlepassReward* temp_e_battlepassreward_list = msg.add_e_battlepassreward_list();
		E_BattlepassReward_List[i].write_to_pbmsg(*temp_e_battlepassreward_list);
	}
}

void Sheet_BattlepassReward_s::read_from_pbmsg(const ::proto_ff::Sheet_BattlepassReward & msg) {
	E_BattlepassReward_List.resize((int)msg.e_battlepassreward_list_size() > (int)E_BattlepassReward_List.max_size() ? E_BattlepassReward_List.max_size() : msg.e_battlepassreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_BattlepassReward_List.size(); ++i) {
		const ::proto_ff::E_BattlepassReward & temp_e_battlepassreward_list = msg.e_battlepassreward_list(i);
		E_BattlepassReward_List[i].read_from_pbmsg(temp_e_battlepassreward_list);
	}
}

E_BattlepassTask_s::E_BattlepassTask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BattlepassTask_s::CreateInit() {
	m_id = (int32_t)0;
	m_group = (int32_t)0;
	m_taskRefresh = (int32_t)0;
	m_lv = (int32_t)0;
	m_tag = (int32_t)0;
	m_eventType = (int32_t)0;
	m_reachPrice = (int32_t)0;
	m_link = (int32_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_BattlepassTask_s::ResumeInit() {
	return 0;
}

void E_BattlepassTask_s::write_to_pbmsg(::proto_ff::E_BattlepassTask & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_taskrefresh((int32_t)m_taskRefresh);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_tag((int32_t)m_tag);
	msg.set_m_eventtype((int32_t)m_eventType);
	msg.set_m_reachprice((int32_t)m_reachPrice);
	msg.set_m_link((int32_t)m_link);
	msg.set_m_exp((int32_t)m_exp);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
}

void E_BattlepassTask_s::read_from_pbmsg(const ::proto_ff::E_BattlepassTask & msg) {
	m_id = msg.m_id();
	m_group = msg.m_group();
	m_taskRefresh = msg.m_taskrefresh();
	m_lv = msg.m_lv();
	m_tag = msg.m_tag();
	m_eventType = msg.m_eventtype();
	m_reachPrice = msg.m_reachprice();
	m_link = msg.m_link();
	m_exp = msg.m_exp();
	m_param.resize((int)msg.m_param_size() > (int)m_param.max_size() ? m_param.max_size() : msg.m_param_size());
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		m_param[i] = msg.m_param(i);
	}
}

Sheet_BattlepassTask_s::Sheet_BattlepassTask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_BattlepassTask_s::CreateInit() {
	return 0;
}

int Sheet_BattlepassTask_s::ResumeInit() {
	return 0;
}

void Sheet_BattlepassTask_s::write_to_pbmsg(::proto_ff::Sheet_BattlepassTask & msg) const {
	for(int32_t i = 0; i < (int32_t)E_BattlepassTask_List.size(); ++i) {
		::proto_ff::E_BattlepassTask* temp_e_battlepasstask_list = msg.add_e_battlepasstask_list();
		E_BattlepassTask_List[i].write_to_pbmsg(*temp_e_battlepasstask_list);
	}
}

void Sheet_BattlepassTask_s::read_from_pbmsg(const ::proto_ff::Sheet_BattlepassTask & msg) {
	E_BattlepassTask_List.resize((int)msg.e_battlepasstask_list_size() > (int)E_BattlepassTask_List.max_size() ? E_BattlepassTask_List.max_size() : msg.e_battlepasstask_list_size());
	for(int32_t i = 0; i < (int32_t)E_BattlepassTask_List.size(); ++i) {
		const ::proto_ff::E_BattlepassTask & temp_e_battlepasstask_list = msg.e_battlepasstask_list(i);
		E_BattlepassTask_List[i].read_from_pbmsg(temp_e_battlepasstask_list);
	}
}

E_BattlepassShop_s::E_BattlepassShop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BattlepassShop_s::CreateInit() {
	m_id = (int32_t)0;
	m_group = (int32_t)0;
	m_itemID = (int32_t)0;
	m_itemNum = (int32_t)0;
	m_costItem = (int32_t)0;
	m_costNum = (int32_t)0;
	m_numLimit = (int32_t)0;
	return 0;
}

int E_BattlepassShop_s::ResumeInit() {
	return 0;
}

void E_BattlepassShop_s::write_to_pbmsg(::proto_ff::E_BattlepassShop & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_itemnum((int32_t)m_itemNum);
	msg.set_m_costitem((int32_t)m_costItem);
	msg.set_m_costnum((int32_t)m_costNum);
	msg.set_m_numlimit((int32_t)m_numLimit);
}

void E_BattlepassShop_s::read_from_pbmsg(const ::proto_ff::E_BattlepassShop & msg) {
	m_id = msg.m_id();
	m_group = msg.m_group();
	m_itemID = msg.m_itemid();
	m_itemNum = msg.m_itemnum();
	m_costItem = msg.m_costitem();
	m_costNum = msg.m_costnum();
	m_numLimit = msg.m_numlimit();
}

Sheet_BattlepassShop_s::Sheet_BattlepassShop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_BattlepassShop_s::CreateInit() {
	return 0;
}

int Sheet_BattlepassShop_s::ResumeInit() {
	return 0;
}

void Sheet_BattlepassShop_s::write_to_pbmsg(::proto_ff::Sheet_BattlepassShop & msg) const {
	for(int32_t i = 0; i < (int32_t)E_BattlepassShop_List.size(); ++i) {
		::proto_ff::E_BattlepassShop* temp_e_battlepassshop_list = msg.add_e_battlepassshop_list();
		E_BattlepassShop_List[i].write_to_pbmsg(*temp_e_battlepassshop_list);
	}
}

void Sheet_BattlepassShop_s::read_from_pbmsg(const ::proto_ff::Sheet_BattlepassShop & msg) {
	E_BattlepassShop_List.resize((int)msg.e_battlepassshop_list_size() > (int)E_BattlepassShop_List.max_size() ? E_BattlepassShop_List.max_size() : msg.e_battlepassshop_list_size());
	for(int32_t i = 0; i < (int32_t)E_BattlepassShop_List.size(); ++i) {
		const ::proto_ff::E_BattlepassShop & temp_e_battlepassshop_list = msg.e_battlepassshop_list(i);
		E_BattlepassShop_List[i].read_from_pbmsg(temp_e_battlepassshop_list);
	}
}

}
