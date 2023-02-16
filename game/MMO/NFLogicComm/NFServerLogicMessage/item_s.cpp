#include "item_s.h"

namespace proto_ff_s {

E_ItemItem_s::E_ItemItem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ItemItem_s::CreateInit() {
	m_id = (int64_t)0;
	m_itemtype = (int32_t)0;
	m_subtype = (int32_t)0;
	m_functiontype = (int32_t)0;
	m_level = (int32_t)0;
	m_quality = (int32_t)0;
	m_levelrequest = (int32_t)0;
	m_bindtype = (int32_t)0;
	m_istradebind = (int32_t)0;
	m_dropnum = (int32_t)0;
	m_stacklimit = (int32_t)0;
	m_sellprice = (int32_t)0;
	m_sellbox = (int64_t)0;
	m_broadcast = (int32_t)0;
	m_iscanbatchuse = (int32_t)0;
	m_dayuse = (int32_t)0;
	m_time = (int32_t)0;
	m_blessing = (int32_t)0;
	m_invest = (int32_t)0;
	m_exchange = (int32_t)0;
	return 0;
}

int E_ItemItem_s::ResumeInit() {
	return 0;
}

void E_ItemItem_s::write_to_pbmsg(::proto_ff::E_ItemItem & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_name((const char*)m_name.data());
	msg.set_m_itemtype((int32_t)m_itemtype);
	msg.set_m_subtype((int32_t)m_subtype);
	msg.set_m_functiontype((int32_t)m_functiontype);
	msg.set_m_functionvalue((const char*)m_functionvalue.data());
	msg.set_m_usecondition((const char*)m_usecondition.data());
	msg.set_m_level((int32_t)m_level);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_levelrequest((int32_t)m_levelrequest);
	msg.set_m_profession((const char*)m_profession.data());
	msg.set_m_bindtype((int32_t)m_bindtype);
	msg.set_m_istradebind((int32_t)m_istradebind);
	msg.set_m_dropnum((int32_t)m_dropnum);
	msg.set_m_stacklimit((int32_t)m_stacklimit);
	msg.set_m_sellprice((int32_t)m_sellprice);
	msg.set_m_sellbox((int64_t)m_sellbox);
	msg.set_m_broadcast((int32_t)m_broadcast);
	msg.set_m_iscanbatchuse((int32_t)m_iscanbatchuse);
	msg.set_m_dayuse((int32_t)m_dayuse);
	msg.set_m_time((int32_t)m_time);
	msg.set_m_uselimit((const char*)m_uselimit.data());
	msg.set_m_blessing((int32_t)m_blessing);
	msg.set_m_invest((int32_t)m_invest);
	msg.set_m_exchange((int32_t)m_exchange);
}

void E_ItemItem_s::read_from_pbmsg(const ::proto_ff::E_ItemItem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ItemItem_s));
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_itemtype = msg.m_itemtype();
	m_subtype = msg.m_subtype();
	m_functiontype = msg.m_functiontype();
	m_functionvalue = msg.m_functionvalue();
	m_usecondition = msg.m_usecondition();
	m_level = msg.m_level();
	m_quality = msg.m_quality();
	m_levelrequest = msg.m_levelrequest();
	m_profession = msg.m_profession();
	m_bindtype = msg.m_bindtype();
	m_istradebind = msg.m_istradebind();
	m_dropnum = msg.m_dropnum();
	m_stacklimit = msg.m_stacklimit();
	m_sellprice = msg.m_sellprice();
	m_sellbox = msg.m_sellbox();
	m_broadcast = msg.m_broadcast();
	m_iscanbatchuse = msg.m_iscanbatchuse();
	m_dayuse = msg.m_dayuse();
	m_time = msg.m_time();
	m_uselimit = msg.m_uselimit();
	m_blessing = msg.m_blessing();
	m_invest = msg.m_invest();
	m_exchange = msg.m_exchange();
}

Sheet_ItemItem_s::Sheet_ItemItem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ItemItem_s::CreateInit() {
	return 0;
}

int Sheet_ItemItem_s::ResumeInit() {
	return 0;
}

void Sheet_ItemItem_s::write_to_pbmsg(::proto_ff::Sheet_ItemItem & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ItemItem_List.size(); ++i) {
		::proto_ff::E_ItemItem* temp_e_itemitem_list = msg.add_e_itemitem_list();
		E_ItemItem_List[i].write_to_pbmsg(*temp_e_itemitem_list);
	}
}

void Sheet_ItemItem_s::read_from_pbmsg(const ::proto_ff::Sheet_ItemItem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_ItemItem_s));
	E_ItemItem_List.resize((int)msg.e_itemitem_list_size() > (int)E_ItemItem_List.max_size() ? E_ItemItem_List.max_size() : msg.e_itemitem_list_size());
	for(int32_t i = 0; i < (int32_t)E_ItemItem_List.size(); ++i) {
		const ::proto_ff::E_ItemItem & temp_e_itemitem_list = msg.e_itemitem_list(i);
		E_ItemItem_List[i].read_from_pbmsg(temp_e_itemitem_list);
	}
}

}