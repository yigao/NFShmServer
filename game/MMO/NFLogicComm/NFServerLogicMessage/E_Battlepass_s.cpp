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
	m_freshcost = (int32_t)0;
	m_shop = (int32_t)0;
	m_shopcurrency = (int32_t)0;
	m_severopentype = (int32_t)0;
	m_openseverday = (int32_t)0;
	m_closeseverday = (int32_t)0;
	m_pricetype = (int32_t)0;
	m_price = (int32_t)0;
	m_pricep = (int32_t)0;
	m_presentexp = (int32_t)0;
	m_expcost = (int32_t)0;
	m_expprice = (int32_t)0;
	m_expitem = (int32_t)0;
	return 0;
}

int E_BattlepassBattlepass_s::ResumeInit() {
	return 0;
}

void E_BattlepassBattlepass_s::write_to_pbmsg(::proto_ff::E_BattlepassBattlepass & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_reward((int32_t)m_reward);
	msg.set_m_task((int32_t)m_task);
	msg.set_m_tasknum(m_tasknum.data());
	msg.set_m_freshcost((int32_t)m_freshcost);
	msg.set_m_shop((int32_t)m_shop);
	msg.set_m_shopcurrency((int32_t)m_shopcurrency);
	msg.set_m_severopentype((int32_t)m_severopentype);
	msg.set_m_openseverday((int32_t)m_openseverday);
	msg.set_m_closeseverday((int32_t)m_closeseverday);
	msg.set_m_pricetype((int32_t)m_pricetype);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_pricep((int32_t)m_pricep);
	msg.set_m_presentexp((int32_t)m_presentexp);
	msg.set_m_expcost((int32_t)m_expcost);
	msg.set_m_expprice((int32_t)m_expprice);
	msg.set_m_expitem((int32_t)m_expitem);
}

void E_BattlepassBattlepass_s::read_from_pbmsg(const ::proto_ff::E_BattlepassBattlepass & msg) {
	m_id = msg.m_id();
	m_reward = msg.m_reward();
	m_task = msg.m_task();
	m_tasknum = msg.m_tasknum();
	m_freshcost = msg.m_freshcost();
	m_shop = msg.m_shop();
	m_shopcurrency = msg.m_shopcurrency();
	m_severopentype = msg.m_severopentype();
	m_openseverday = msg.m_openseverday();
	m_closeseverday = msg.m_closeseverday();
	m_pricetype = msg.m_pricetype();
	m_price = msg.m_price();
	m_pricep = msg.m_pricep();
	m_presentexp = msg.m_presentexp();
	m_expcost = msg.m_expcost();
	m_expprice = msg.m_expprice();
	m_expitem = msg.m_expitem();
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
	m_core = (int32_t)0;
	m_buylevel = (int32_t)0;
	m_showitem = (int32_t)0;
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
	msg.set_m_core((int32_t)m_core);
	msg.set_m_buylevel((int32_t)m_buylevel);
	msg.set_m_showitem((int32_t)m_showitem);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_BattlepassRewardItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
	for(int32_t i = 0; i < (int32_t)m_proitem.size(); ++i) {
		::proto_ff::E_BattlepassRewardProitemDesc* temp_m_proitem = msg.add_m_proitem();
		m_proitem[i].write_to_pbmsg(*temp_m_proitem);
	}
}

void E_BattlepassReward_s::read_from_pbmsg(const ::proto_ff::E_BattlepassReward & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
	m_core = msg.m_core();
	m_buylevel = msg.m_buylevel();
	m_showitem = msg.m_showitem();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_BattlepassRewardItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
	m_proitem.resize((int)msg.m_proitem_size() > (int)m_proitem.max_size() ? m_proitem.max_size() : msg.m_proitem_size());
	for(int32_t i = 0; i < (int32_t)m_proitem.size(); ++i) {
		const ::proto_ff::E_BattlepassRewardProitemDesc & temp_m_proitem = msg.m_proitem(i);
		m_proitem[i].read_from_pbmsg(temp_m_proitem);
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
	m_taskrefresh = (int32_t)0;
	m_lv = (int32_t)0;
	m_tag = (int32_t)0;
	m_eventtype = (int32_t)0;
	m_reachprice = (int32_t)0;
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
	msg.set_m_taskrefresh((int32_t)m_taskrefresh);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_tag((int32_t)m_tag);
	msg.set_m_eventtype((int32_t)m_eventtype);
	msg.set_m_reachprice((int32_t)m_reachprice);
	msg.set_m_link((int32_t)m_link);
	msg.set_m_exp((int32_t)m_exp);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
}

void E_BattlepassTask_s::read_from_pbmsg(const ::proto_ff::E_BattlepassTask & msg) {
	m_id = msg.m_id();
	m_group = msg.m_group();
	m_taskrefresh = msg.m_taskrefresh();
	m_lv = msg.m_lv();
	m_tag = msg.m_tag();
	m_eventtype = msg.m_eventtype();
	m_reachprice = msg.m_reachprice();
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
	m_itemid = (int32_t)0;
	m_itemnum = (int32_t)0;
	m_costitem = (int32_t)0;
	m_costnum = (int32_t)0;
	m_numlimit = (int32_t)0;
	return 0;
}

int E_BattlepassShop_s::ResumeInit() {
	return 0;
}

void E_BattlepassShop_s::write_to_pbmsg(::proto_ff::E_BattlepassShop & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_itemnum((int32_t)m_itemnum);
	msg.set_m_costitem((int32_t)m_costitem);
	msg.set_m_costnum((int32_t)m_costnum);
	msg.set_m_numlimit((int32_t)m_numlimit);
}

void E_BattlepassShop_s::read_from_pbmsg(const ::proto_ff::E_BattlepassShop & msg) {
	m_id = msg.m_id();
	m_group = msg.m_group();
	m_itemid = msg.m_itemid();
	m_itemnum = msg.m_itemnum();
	m_costitem = msg.m_costitem();
	m_costnum = msg.m_costnum();
	m_numlimit = msg.m_numlimit();
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
