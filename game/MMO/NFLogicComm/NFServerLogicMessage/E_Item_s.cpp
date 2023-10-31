#include "E_Item_s.h"

namespace proto_ff_s {

E_ItemItem_s::E_ItemItem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ItemItem_s::CreateInit() {
	m_id = (int32_t)0;
	m_itemType = (int32_t)0;
	m_subType = (int32_t)0;
	m_functionType = (int32_t)0;
	m_waiguanLink = (int64_t)0;
	m_level = (int32_t)0;
	m_quality = (int32_t)0;
	m_levelRequest = (int32_t)0;
	m_bindType = (int32_t)0;
	m_isTradeBind = (int32_t)0;
	m_dropNum = (int32_t)0;
	m_stackLimit = (int32_t)0;
	m_sellPrice = (int32_t)0;
	m_sellBox = (int64_t)0;
	m_broadcast = (int32_t)0;
	m_isCanBatchUse = (int32_t)0;
	m_dayUse = (int32_t)0;
	m_time = (int32_t)0;
	return 0;
}

int E_ItemItem_s::ResumeInit() {
	return 0;
}

void E_ItemItem_s::write_to_pbmsg(::proto_ff::E_ItemItem & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_itemtype((int32_t)m_itemType);
	msg.set_m_subtype((int32_t)m_subType);
	msg.set_m_functiontype((int32_t)m_functionType);
	msg.set_m_functionvalue(m_functionValue.data());
	msg.set_m_usecondition(m_usecondition.data());
	msg.set_m_waiguanlink((int64_t)m_waiguanLink);
	msg.set_m_level((int32_t)m_level);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_levelrequest((int32_t)m_levelRequest);
	msg.set_m_profession(m_profession.data());
	msg.set_m_bindtype((int32_t)m_bindType);
	msg.set_m_istradebind((int32_t)m_isTradeBind);
	msg.set_m_dropnum((int32_t)m_dropNum);
	msg.set_m_stacklimit((int32_t)m_stackLimit);
	msg.set_m_sellprice((int32_t)m_sellPrice);
	msg.set_m_sellbox((int64_t)m_sellBox);
	msg.set_m_broadcast((int32_t)m_broadcast);
	msg.set_m_iscanbatchuse((int32_t)m_isCanBatchUse);
	msg.set_m_dayuse((int32_t)m_dayUse);
	msg.set_m_time((int32_t)m_time);
	msg.set_m_uselimit(m_useLimit.data());
}

void E_ItemItem_s::read_from_pbmsg(const ::proto_ff::E_ItemItem & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_itemType = msg.m_itemtype();
	m_subType = msg.m_subtype();
	m_functionType = msg.m_functiontype();
	m_functionValue = msg.m_functionvalue();
	m_usecondition = msg.m_usecondition();
	m_waiguanLink = msg.m_waiguanlink();
	m_level = msg.m_level();
	m_quality = msg.m_quality();
	m_levelRequest = msg.m_levelrequest();
	m_profession = msg.m_profession();
	m_bindType = msg.m_bindtype();
	m_isTradeBind = msg.m_istradebind();
	m_dropNum = msg.m_dropnum();
	m_stackLimit = msg.m_stacklimit();
	m_sellPrice = msg.m_sellprice();
	m_sellBox = msg.m_sellbox();
	m_broadcast = msg.m_broadcast();
	m_isCanBatchUse = msg.m_iscanbatchuse();
	m_dayUse = msg.m_dayuse();
	m_time = msg.m_time();
	m_useLimit = msg.m_uselimit();
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
	E_ItemItem_List.resize((int)msg.e_itemitem_list_size() > (int)E_ItemItem_List.max_size() ? E_ItemItem_List.max_size() : msg.e_itemitem_list_size());
	for(int32_t i = 0; i < (int32_t)E_ItemItem_List.size(); ++i) {
		const ::proto_ff::E_ItemItem & temp_e_itemitem_list = msg.e_itemitem_list(i);
		E_ItemItem_List[i].read_from_pbmsg(temp_e_itemitem_list);
	}
}

}
