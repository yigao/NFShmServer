#include "E_Recharge_s.h"

namespace proto_ff_s {

E_RechargeRechargeChannelDesc_s::E_RechargeRechargeChannelDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RechargeRechargeChannelDesc_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_RechargeRechargeChannelDesc_s::ResumeInit() {
	return 0;
}

void E_RechargeRechargeChannelDesc_s::write_to_pbmsg(::proto_ff::E_RechargeRechargeChannelDesc & msg) const {
	msg.set_m_point(m_point.data());
	msg.set_m_id((int32_t)m_id);
}

void E_RechargeRechargeChannelDesc_s::read_from_pbmsg(const ::proto_ff::E_RechargeRechargeChannelDesc & msg) {
	m_point = msg.m_point();
	m_id = msg.m_id();
}

E_RechargeRechargeItemDesc_s::E_RechargeRechargeItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RechargeRechargeItemDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_Id = (int64_t)0;
	return 0;
}

int E_RechargeRechargeItemDesc_s::ResumeInit() {
	return 0;
}

void E_RechargeRechargeItemDesc_s::write_to_pbmsg(::proto_ff::E_RechargeRechargeItemDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int64_t)m_Id);
}

void E_RechargeRechargeItemDesc_s::read_from_pbmsg(const ::proto_ff::E_RechargeRechargeItemDesc & msg) {
	m_Num = msg.m_num();
	m_Id = msg.m_id();
}

E_RechargeRecharge_s::E_RechargeRecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RechargeRecharge_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_quantity = (int64_t)0;
	m_itemNum = (int32_t)0;
	m_multipleTimes = (int64_t)0;
	m_multipleReward = (int64_t)0;
	m_zuanshitype = (int32_t)0;
	m_vipExp = (int32_t)0;
	m_vipExpLimit = (int32_t)0;
	m_activityCount = (int32_t)0;
	m_price = (int32_t)0;
	m_presentID = (int32_t)0;
	m_fristpresent = (int32_t)0;
	return 0;
}

int E_RechargeRecharge_s::ResumeInit() {
	return 0;
}

void E_RechargeRecharge_s::write_to_pbmsg(::proto_ff::E_RechargeRecharge & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_defaultpoint(m_defaultPoint.data());
	msg.set_m_type((int32_t)m_type);
	msg.set_m_unit(m_unit.data());
	msg.set_m_beizhu(m_beizhu.data());
	msg.set_m_quantity((int64_t)m_quantity);
	msg.set_m_itemnum((int32_t)m_itemNum);
	msg.set_m_multipletimes((int64_t)m_multipleTimes);
	msg.set_m_multiplereward((int64_t)m_multipleReward);
	msg.set_m_zuanshitype((int32_t)m_zuanshitype);
	msg.set_m_vipexp((int32_t)m_vipExp);
	msg.set_m_vipexplimit((int32_t)m_vipExpLimit);
	msg.set_m_activitycount((int32_t)m_activityCount);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_presentid((int32_t)m_presentID);
	msg.set_m_fristpresent((int32_t)m_fristpresent);
	msg.set_m_icon(m_icon.data());
	for(int32_t i = 0; i < (int32_t)m_channel.size(); ++i) {
		::proto_ff::E_RechargeRechargeChannelDesc* temp_m_channel = msg.add_m_channel();
		m_channel[i].write_to_pbmsg(*temp_m_channel);
	}
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_RechargeRechargeItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_RechargeRecharge_s::read_from_pbmsg(const ::proto_ff::E_RechargeRecharge & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_defaultPoint = msg.m_defaultpoint();
	m_type = msg.m_type();
	m_unit = msg.m_unit();
	m_beizhu = msg.m_beizhu();
	m_quantity = msg.m_quantity();
	m_itemNum = msg.m_itemnum();
	m_multipleTimes = msg.m_multipletimes();
	m_multipleReward = msg.m_multiplereward();
	m_zuanshitype = msg.m_zuanshitype();
	m_vipExp = msg.m_vipexp();
	m_vipExpLimit = msg.m_vipexplimit();
	m_activityCount = msg.m_activitycount();
	m_price = msg.m_price();
	m_presentID = msg.m_presentid();
	m_fristpresent = msg.m_fristpresent();
	m_icon = msg.m_icon();
	m_channel.resize((int)msg.m_channel_size() > (int)m_channel.max_size() ? m_channel.max_size() : msg.m_channel_size());
	for(int32_t i = 0; i < (int32_t)m_channel.size(); ++i) {
		const ::proto_ff::E_RechargeRechargeChannelDesc & temp_m_channel = msg.m_channel(i);
		m_channel[i].read_from_pbmsg(temp_m_channel);
	}
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_RechargeRechargeItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
}

Sheet_RechargeRecharge_s::Sheet_RechargeRecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RechargeRecharge_s::CreateInit() {
	return 0;
}

int Sheet_RechargeRecharge_s::ResumeInit() {
	return 0;
}

void Sheet_RechargeRecharge_s::write_to_pbmsg(::proto_ff::Sheet_RechargeRecharge & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RechargeRecharge_List.size(); ++i) {
		::proto_ff::E_RechargeRecharge* temp_e_rechargerecharge_list = msg.add_e_rechargerecharge_list();
		E_RechargeRecharge_List[i].write_to_pbmsg(*temp_e_rechargerecharge_list);
	}
}

void Sheet_RechargeRecharge_s::read_from_pbmsg(const ::proto_ff::Sheet_RechargeRecharge & msg) {
	E_RechargeRecharge_List.resize((int)msg.e_rechargerecharge_list_size() > (int)E_RechargeRecharge_List.max_size() ? E_RechargeRecharge_List.max_size() : msg.e_rechargerecharge_list_size());
	for(int32_t i = 0; i < (int32_t)E_RechargeRecharge_List.size(); ++i) {
		const ::proto_ff::E_RechargeRecharge & temp_e_rechargerecharge_list = msg.e_rechargerecharge_list(i);
		E_RechargeRecharge_List[i].read_from_pbmsg(temp_e_rechargerecharge_list);
	}
}

E_RechargeOneclickbuyAllbuyDesc_s::E_RechargeOneclickbuyAllbuyDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RechargeOneclickbuyAllbuyDesc_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_RechargeOneclickbuyAllbuyDesc_s::ResumeInit() {
	return 0;
}

void E_RechargeOneclickbuyAllbuyDesc_s::write_to_pbmsg(::proto_ff::E_RechargeOneclickbuyAllbuyDesc & msg) const {
	msg.set_m_id((int32_t)m_id);
}

void E_RechargeOneclickbuyAllbuyDesc_s::read_from_pbmsg(const ::proto_ff::E_RechargeOneclickbuyAllbuyDesc & msg) {
	m_id = msg.m_id();
}

E_RechargeOneclickbuy_s::E_RechargeOneclickbuy_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RechargeOneclickbuy_s::CreateInit() {
	m_id = (int32_t)0;
	m_discount = (int32_t)0;
	m_rechargeid = (int32_t)0;
	return 0;
}

int E_RechargeOneclickbuy_s::ResumeInit() {
	return 0;
}

void E_RechargeOneclickbuy_s::write_to_pbmsg(::proto_ff::E_RechargeOneclickbuy & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_allowid(m_allowid.data());
	msg.set_m_num_limit(m_num_limit.data());
	msg.set_m_discount((int32_t)m_discount);
	msg.set_m_rechargeid((int32_t)m_rechargeid);
	for(int32_t i = 0; i < (int32_t)m_allbuy.size(); ++i) {
		::proto_ff::E_RechargeOneclickbuyAllbuyDesc* temp_m_allbuy = msg.add_m_allbuy();
		m_allbuy[i].write_to_pbmsg(*temp_m_allbuy);
	}
}

void E_RechargeOneclickbuy_s::read_from_pbmsg(const ::proto_ff::E_RechargeOneclickbuy & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_allowid = msg.m_allowid();
	m_num_limit = msg.m_num_limit();
	m_discount = msg.m_discount();
	m_rechargeid = msg.m_rechargeid();
	m_allbuy.resize((int)msg.m_allbuy_size() > (int)m_allbuy.max_size() ? m_allbuy.max_size() : msg.m_allbuy_size());
	for(int32_t i = 0; i < (int32_t)m_allbuy.size(); ++i) {
		const ::proto_ff::E_RechargeOneclickbuyAllbuyDesc & temp_m_allbuy = msg.m_allbuy(i);
		m_allbuy[i].read_from_pbmsg(temp_m_allbuy);
	}
}

Sheet_RechargeOneclickbuy_s::Sheet_RechargeOneclickbuy_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RechargeOneclickbuy_s::CreateInit() {
	return 0;
}

int Sheet_RechargeOneclickbuy_s::ResumeInit() {
	return 0;
}

void Sheet_RechargeOneclickbuy_s::write_to_pbmsg(::proto_ff::Sheet_RechargeOneclickbuy & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RechargeOneclickbuy_List.size(); ++i) {
		::proto_ff::E_RechargeOneclickbuy* temp_e_rechargeoneclickbuy_list = msg.add_e_rechargeoneclickbuy_list();
		E_RechargeOneclickbuy_List[i].write_to_pbmsg(*temp_e_rechargeoneclickbuy_list);
	}
}

void Sheet_RechargeOneclickbuy_s::read_from_pbmsg(const ::proto_ff::Sheet_RechargeOneclickbuy & msg) {
	E_RechargeOneclickbuy_List.resize((int)msg.e_rechargeoneclickbuy_list_size() > (int)E_RechargeOneclickbuy_List.max_size() ? E_RechargeOneclickbuy_List.max_size() : msg.e_rechargeoneclickbuy_list_size());
	for(int32_t i = 0; i < (int32_t)E_RechargeOneclickbuy_List.size(); ++i) {
		const ::proto_ff::E_RechargeOneclickbuy & temp_e_rechargeoneclickbuy_list = msg.e_rechargeoneclickbuy_list(i);
		E_RechargeOneclickbuy_List[i].read_from_pbmsg(temp_e_rechargeoneclickbuy_list);
	}
}

}
