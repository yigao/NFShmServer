#include "E_Offline_s.h"

namespace proto_ff_s {

E_OfflineOffline_s::E_OfflineOffline_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_OfflineOffline_s::CreateInit() {
	m_lv = (int32_t)0;
	m_offlineexp = (int64_t)0;
	return 0;
}

int E_OfflineOffline_s::ResumeInit() {
	return 0;
}

void E_OfflineOffline_s::write_to_pbmsg(::proto_ff::E_OfflineOffline & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_offlineexp((int64_t)m_offlineexp);
}

void E_OfflineOffline_s::read_from_pbmsg(const ::proto_ff::E_OfflineOffline & msg) {
	m_lv = msg.m_lv();
	m_offlineexp = msg.m_offlineexp();
}

Sheet_OfflineOffline_s::Sheet_OfflineOffline_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_OfflineOffline_s::CreateInit() {
	return 0;
}

int Sheet_OfflineOffline_s::ResumeInit() {
	return 0;
}

void Sheet_OfflineOffline_s::write_to_pbmsg(::proto_ff::Sheet_OfflineOffline & msg) const {
	for(int32_t i = 0; i < (int32_t)E_OfflineOffline_List.size(); ++i) {
		::proto_ff::E_OfflineOffline* temp_e_offlineoffline_list = msg.add_e_offlineoffline_list();
		E_OfflineOffline_List[i].write_to_pbmsg(*temp_e_offlineoffline_list);
	}
}

void Sheet_OfflineOffline_s::read_from_pbmsg(const ::proto_ff::Sheet_OfflineOffline & msg) {
	E_OfflineOffline_List.resize((int)msg.e_offlineoffline_list_size() > (int)E_OfflineOffline_List.max_size() ? E_OfflineOffline_List.max_size() : msg.e_offlineoffline_list_size());
	for(int32_t i = 0; i < (int32_t)E_OfflineOffline_List.size(); ++i) {
		const ::proto_ff::E_OfflineOffline & temp_e_offlineoffline_list = msg.e_offlineoffline_list(i);
		E_OfflineOffline_List[i].read_from_pbmsg(temp_e_offlineoffline_list);
	}
}

E_OfflineItemlistItemDesc_s::E_OfflineItemlistItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_OfflineItemlistItemDesc_s::CreateInit() {
	m_vle = (int32_t)0;
	m_num = (int32_t)0;
	m_id = (int64_t)0;
	return 0;
}

int E_OfflineItemlistItemDesc_s::ResumeInit() {
	return 0;
}

void E_OfflineItemlistItemDesc_s::write_to_pbmsg(::proto_ff::E_OfflineItemlistItemDesc & msg) const {
	msg.set_m_vle((int32_t)m_vle);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int64_t)m_id);
}

void E_OfflineItemlistItemDesc_s::read_from_pbmsg(const ::proto_ff::E_OfflineItemlistItemDesc & msg) {
	m_vle = msg.m_vle();
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_OfflineItemlist_s::E_OfflineItemlist_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_OfflineItemlist_s::CreateInit() {
	m_id = (int32_t)0;
	m_lvdown = (int32_t)0;
	m_lvup = (int32_t)0;
	m_daoju = (int32_t)0;
	return 0;
}

int E_OfflineItemlist_s::ResumeInit() {
	return 0;
}

void E_OfflineItemlist_s::write_to_pbmsg(::proto_ff::E_OfflineItemlist & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lvdown((int32_t)m_lvdown);
	msg.set_m_lvup((int32_t)m_lvup);
	msg.set_m_daoju((int32_t)m_daoju);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_OfflineItemlistItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_OfflineItemlist_s::read_from_pbmsg(const ::proto_ff::E_OfflineItemlist & msg) {
	m_id = msg.m_id();
	m_lvdown = msg.m_lvdown();
	m_lvup = msg.m_lvup();
	m_daoju = msg.m_daoju();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_OfflineItemlistItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
}

Sheet_OfflineItemlist_s::Sheet_OfflineItemlist_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_OfflineItemlist_s::CreateInit() {
	return 0;
}

int Sheet_OfflineItemlist_s::ResumeInit() {
	return 0;
}

void Sheet_OfflineItemlist_s::write_to_pbmsg(::proto_ff::Sheet_OfflineItemlist & msg) const {
	for(int32_t i = 0; i < (int32_t)E_OfflineItemlist_List.size(); ++i) {
		::proto_ff::E_OfflineItemlist* temp_e_offlineitemlist_list = msg.add_e_offlineitemlist_list();
		E_OfflineItemlist_List[i].write_to_pbmsg(*temp_e_offlineitemlist_list);
	}
}

void Sheet_OfflineItemlist_s::read_from_pbmsg(const ::proto_ff::Sheet_OfflineItemlist & msg) {
	E_OfflineItemlist_List.resize((int)msg.e_offlineitemlist_list_size() > (int)E_OfflineItemlist_List.max_size() ? E_OfflineItemlist_List.max_size() : msg.e_offlineitemlist_list_size());
	for(int32_t i = 0; i < (int32_t)E_OfflineItemlist_List.size(); ++i) {
		const ::proto_ff::E_OfflineItemlist & temp_e_offlineitemlist_list = msg.e_offlineitemlist_list(i);
		E_OfflineItemlist_List[i].read_from_pbmsg(temp_e_offlineitemlist_list);
	}
}

}
