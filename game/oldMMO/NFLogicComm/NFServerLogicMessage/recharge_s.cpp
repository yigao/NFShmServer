#include "recharge_s.h"

namespace proto_ff_s {

E_RechargeRechargeItemDesc_s::E_RechargeRechargeItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RechargeRechargeItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int64_t)0;
	return 0;
}

int E_RechargeRechargeItemDesc_s::ResumeInit() {
	return 0;
}

void E_RechargeRechargeItemDesc_s::write_to_pbmsg(::proto_ff::E_RechargeRechargeItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int64_t)m_id);
}

void E_RechargeRechargeItemDesc_s::read_from_pbmsg(const ::proto_ff::E_RechargeRechargeItemDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_RechargeRechargeItemDesc_s));
	m_num = msg.m_num();
	m_id = msg.m_id();
}

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
	msg.set_m_id((int32_t)m_id);
	msg.set_m_point((const char*)m_point.data());
}

void E_RechargeRechargeChannelDesc_s::read_from_pbmsg(const ::proto_ff::E_RechargeRechargeChannelDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_RechargeRechargeChannelDesc_s));
	m_id = msg.m_id();
	m_point = msg.m_point();
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
	m_itemnum = (int32_t)0;
	m_multipletimes = (int64_t)0;
	m_multiplereward = (int64_t)0;
	m_zuanshitype = (int32_t)0;
	m_vipexp = (int32_t)0;
	m_vipexplimit = (int32_t)0;
	m_activitycount = (int32_t)0;
	m_price = (int32_t)0;
	m_presentid = (int32_t)0;
	m_fristpresent = (int32_t)0;
	return 0;
}

int E_RechargeRecharge_s::ResumeInit() {
	return 0;
}

void E_RechargeRecharge_s::write_to_pbmsg(::proto_ff::E_RechargeRecharge & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name((const char*)m_name.data());
	msg.set_m_defaultpoint((const char*)m_defaultpoint.data());
	msg.set_m_type((int32_t)m_type);
	msg.set_m_unit((const char*)m_unit.data());
	msg.set_m_beizhu((const char*)m_beizhu.data());
	msg.set_m_quantity((int64_t)m_quantity);
	msg.set_m_itemnum((int32_t)m_itemnum);
	msg.set_m_multipletimes((int64_t)m_multipletimes);
	msg.set_m_multiplereward((int64_t)m_multiplereward);
	msg.set_m_zuanshitype((int32_t)m_zuanshitype);
	msg.set_m_vipexp((int32_t)m_vipexp);
	msg.set_m_vipexplimit((int32_t)m_vipexplimit);
	msg.set_m_activitycount((int32_t)m_activitycount);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_presentid((int32_t)m_presentid);
	msg.set_m_fristpresent((int32_t)m_fristpresent);
	msg.set_m_icon((const char*)m_icon.data());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_RechargeRechargeItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
	for(int32_t i = 0; i < (int32_t)m_channel.size(); ++i) {
		::proto_ff::E_RechargeRechargeChannelDesc* temp_m_channel = msg.add_m_channel();
		m_channel[i].write_to_pbmsg(*temp_m_channel);
	}
}

void E_RechargeRecharge_s::read_from_pbmsg(const ::proto_ff::E_RechargeRecharge & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_RechargeRecharge_s));
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_defaultpoint = msg.m_defaultpoint();
	m_type = msg.m_type();
	m_unit = msg.m_unit();
	m_beizhu = msg.m_beizhu();
	m_quantity = msg.m_quantity();
	m_itemnum = msg.m_itemnum();
	m_multipletimes = msg.m_multipletimes();
	m_multiplereward = msg.m_multiplereward();
	m_zuanshitype = msg.m_zuanshitype();
	m_vipexp = msg.m_vipexp();
	m_vipexplimit = msg.m_vipexplimit();
	m_activitycount = msg.m_activitycount();
	m_price = msg.m_price();
	m_presentid = msg.m_presentid();
	m_fristpresent = msg.m_fristpresent();
	m_icon = msg.m_icon();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_RechargeRechargeItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
	m_channel.resize((int)msg.m_channel_size() > (int)m_channel.max_size() ? m_channel.max_size() : msg.m_channel_size());
	for(int32_t i = 0; i < (int32_t)m_channel.size(); ++i) {
		const ::proto_ff::E_RechargeRechargeChannelDesc & temp_m_channel = msg.m_channel(i);
		m_channel[i].read_from_pbmsg(temp_m_channel);
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_RechargeRecharge_s));
	E_RechargeRecharge_List.resize((int)msg.e_rechargerecharge_list_size() > (int)E_RechargeRecharge_List.max_size() ? E_RechargeRecharge_List.max_size() : msg.e_rechargerecharge_list_size());
	for(int32_t i = 0; i < (int32_t)E_RechargeRecharge_List.size(); ++i) {
		const ::proto_ff::E_RechargeRecharge & temp_e_rechargerecharge_list = msg.e_rechargerecharge_list(i);
		E_RechargeRecharge_List[i].read_from_pbmsg(temp_e_rechargerecharge_list);
	}
}

}