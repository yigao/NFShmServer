#include "E_Encyclopedia_s.h"

namespace proto_ff_s {

E_EncyclopediaHandbookLviattributeDesc_s::E_EncyclopediaHandbookLviattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaHandbookLviattributeDesc_s::CreateInit() {
	m_value = (int64_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EncyclopediaHandbookLviattributeDesc_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaHandbookLviattributeDesc_s::write_to_pbmsg(::proto_ff::E_EncyclopediaHandbookLviattributeDesc & msg) const {
	msg.set_m_value((int64_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_EncyclopediaHandbookLviattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbookLviattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_EncyclopediaHandbookStariattributeDesc_s::E_EncyclopediaHandbookStariattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaHandbookStariattributeDesc_s::CreateInit() {
	m_value = (int64_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EncyclopediaHandbookStariattributeDesc_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaHandbookStariattributeDesc_s::write_to_pbmsg(::proto_ff::E_EncyclopediaHandbookStariattributeDesc & msg) const {
	msg.set_m_value((int64_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_EncyclopediaHandbookStariattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbookStariattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_EncyclopediaHandbook_s::E_EncyclopediaHandbook_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaHandbook_s::CreateInit() {
	m_handbookid = (int64_t)0;
	m_itemid = (int64_t)0;
	m_handbookquality = (int32_t)0;
	m_handbooktype = (int32_t)0;
	m_handz = (int32_t)0;
	m_handbooklv = (int32_t)0;
	m_lvid = (int64_t)0;
	m_starid = (int64_t)0;
	return 0;
}

int E_EncyclopediaHandbook_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaHandbook_s::write_to_pbmsg(::proto_ff::E_EncyclopediaHandbook & msg) const {
	msg.set_m_handbookid((int64_t)m_handbookid);
	msg.set_m_itemid((int64_t)m_itemid);
	msg.set_m_handbookname(m_handbookname.data());
	msg.set_m_handbookquality((int32_t)m_handbookquality);
	msg.set_m_handbooktype((int32_t)m_handbooktype);
	msg.set_m_handbooktype_name(m_handbooktype_name.data());
	msg.set_m_handz((int32_t)m_handz);
	msg.set_m_handzname(m_handzname.data());
	msg.set_m_handbooklv((int32_t)m_handbooklv);
	msg.set_m_lvid((int64_t)m_lvid);
	msg.set_m_lvnum(m_lvnum.data());
	msg.set_m_starid((int64_t)m_starid);
	msg.set_m_starnum(m_starnum.data());
	for(int32_t i = 0; i < (int32_t)m_lviattribute.size(); ++i) {
		::proto_ff::E_EncyclopediaHandbookLviattributeDesc* temp_m_lviattribute = msg.add_m_lviattribute();
		m_lviattribute[i].write_to_pbmsg(*temp_m_lviattribute);
	}
	for(int32_t i = 0; i < (int32_t)m_awakeskill.size(); ++i) {
		msg.add_m_awakeskill((int32_t)m_awakeskill[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_stariattribute.size(); ++i) {
		::proto_ff::E_EncyclopediaHandbookStariattributeDesc* temp_m_stariattribute = msg.add_m_stariattribute();
		m_stariattribute[i].write_to_pbmsg(*temp_m_stariattribute);
	}
}

void E_EncyclopediaHandbook_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbook & msg) {
	m_handbookid = msg.m_handbookid();
	m_itemid = msg.m_itemid();
	m_handbookname = msg.m_handbookname();
	m_handbookquality = msg.m_handbookquality();
	m_handbooktype = msg.m_handbooktype();
	m_handbooktype_name = msg.m_handbooktype_name();
	m_handz = msg.m_handz();
	m_handzname = msg.m_handzname();
	m_handbooklv = msg.m_handbooklv();
	m_lvid = msg.m_lvid();
	m_lvnum = msg.m_lvnum();
	m_starid = msg.m_starid();
	m_starnum = msg.m_starnum();
	m_lviattribute.resize((int)msg.m_lviattribute_size() > (int)m_lviattribute.max_size() ? m_lviattribute.max_size() : msg.m_lviattribute_size());
	for(int32_t i = 0; i < (int32_t)m_lviattribute.size(); ++i) {
		const ::proto_ff::E_EncyclopediaHandbookLviattributeDesc & temp_m_lviattribute = msg.m_lviattribute(i);
		m_lviattribute[i].read_from_pbmsg(temp_m_lviattribute);
	}
	m_awakeskill.resize((int)msg.m_awakeskill_size() > (int)m_awakeskill.max_size() ? m_awakeskill.max_size() : msg.m_awakeskill_size());
	for(int32_t i = 0; i < (int32_t)m_awakeskill.size(); ++i) {
		m_awakeskill[i] = msg.m_awakeskill(i);
	}
	m_stariattribute.resize((int)msg.m_stariattribute_size() > (int)m_stariattribute.max_size() ? m_stariattribute.max_size() : msg.m_stariattribute_size());
	for(int32_t i = 0; i < (int32_t)m_stariattribute.size(); ++i) {
		const ::proto_ff::E_EncyclopediaHandbookStariattributeDesc & temp_m_stariattribute = msg.m_stariattribute(i);
		m_stariattribute[i].read_from_pbmsg(temp_m_stariattribute);
	}
}

Sheet_EncyclopediaHandbook_s::Sheet_EncyclopediaHandbook_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EncyclopediaHandbook_s::CreateInit() {
	return 0;
}

int Sheet_EncyclopediaHandbook_s::ResumeInit() {
	return 0;
}

void Sheet_EncyclopediaHandbook_s::write_to_pbmsg(::proto_ff::Sheet_EncyclopediaHandbook & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaHandbook_List.size(); ++i) {
		::proto_ff::E_EncyclopediaHandbook* temp_e_encyclopediahandbook_list = msg.add_e_encyclopediahandbook_list();
		E_EncyclopediaHandbook_List[i].write_to_pbmsg(*temp_e_encyclopediahandbook_list);
	}
}

void Sheet_EncyclopediaHandbook_s::read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaHandbook & msg) {
	E_EncyclopediaHandbook_List.resize((int)msg.e_encyclopediahandbook_list_size() > (int)E_EncyclopediaHandbook_List.max_size() ? E_EncyclopediaHandbook_List.max_size() : msg.e_encyclopediahandbook_list_size());
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaHandbook_List.size(); ++i) {
		const ::proto_ff::E_EncyclopediaHandbook & temp_e_encyclopediahandbook_list = msg.e_encyclopediahandbook_list(i);
		E_EncyclopediaHandbook_List[i].read_from_pbmsg(temp_e_encyclopediahandbook_list);
	}
}

E_EncyclopediaHandbookfateAttributeDesc_s::E_EncyclopediaHandbookfateAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaHandbookfateAttributeDesc_s::CreateInit() {
	m_value = (int64_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EncyclopediaHandbookfateAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaHandbookfateAttributeDesc_s::write_to_pbmsg(::proto_ff::E_EncyclopediaHandbookfateAttributeDesc & msg) const {
	msg.set_m_value((int64_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_EncyclopediaHandbookfateAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbookfateAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_EncyclopediaHandbookfate_s::E_EncyclopediaHandbookfate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaHandbookfate_s::CreateInit() {
	m_fateid = (int64_t)0;
	m_fatequality = (int32_t)0;
	return 0;
}

int E_EncyclopediaHandbookfate_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaHandbookfate_s::write_to_pbmsg(::proto_ff::E_EncyclopediaHandbookfate & msg) const {
	msg.set_m_fateid((int64_t)m_fateid);
	msg.set_m_fatename(m_fatename.data());
	msg.set_m_fatequality((int32_t)m_fatequality);
	for(int32_t i = 0; i < (int32_t)m_fatehand.size(); ++i) {
		msg.add_m_fatehand((int64_t)m_fatehand[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_EncyclopediaHandbookfateAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_EncyclopediaHandbookfate_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbookfate & msg) {
	m_fateid = msg.m_fateid();
	m_fatename = msg.m_fatename();
	m_fatequality = msg.m_fatequality();
	m_fatehand.resize((int)msg.m_fatehand_size() > (int)m_fatehand.max_size() ? m_fatehand.max_size() : msg.m_fatehand_size());
	for(int32_t i = 0; i < (int32_t)m_fatehand.size(); ++i) {
		m_fatehand[i] = msg.m_fatehand(i);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_EncyclopediaHandbookfateAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_EncyclopediaHandbookfate_s::Sheet_EncyclopediaHandbookfate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EncyclopediaHandbookfate_s::CreateInit() {
	return 0;
}

int Sheet_EncyclopediaHandbookfate_s::ResumeInit() {
	return 0;
}

void Sheet_EncyclopediaHandbookfate_s::write_to_pbmsg(::proto_ff::Sheet_EncyclopediaHandbookfate & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaHandbookfate_List.size(); ++i) {
		::proto_ff::E_EncyclopediaHandbookfate* temp_e_encyclopediahandbookfate_list = msg.add_e_encyclopediahandbookfate_list();
		E_EncyclopediaHandbookfate_List[i].write_to_pbmsg(*temp_e_encyclopediahandbookfate_list);
	}
}

void Sheet_EncyclopediaHandbookfate_s::read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaHandbookfate & msg) {
	E_EncyclopediaHandbookfate_List.resize((int)msg.e_encyclopediahandbookfate_list_size() > (int)E_EncyclopediaHandbookfate_List.max_size() ? E_EncyclopediaHandbookfate_List.max_size() : msg.e_encyclopediahandbookfate_list_size());
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaHandbookfate_List.size(); ++i) {
		const ::proto_ff::E_EncyclopediaHandbookfate & temp_e_encyclopediahandbookfate_list = msg.e_encyclopediahandbookfate_list(i);
		E_EncyclopediaHandbookfate_List[i].read_from_pbmsg(temp_e_encyclopediahandbookfate_list);
	}
}

E_EncyclopediaHandbookresolve_s::E_EncyclopediaHandbookresolve_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaHandbookresolve_s::CreateInit() {
	m_handbookquality = (int32_t)0;
	m_resolveitem = (int32_t)0;
	m_resolvenum = (int32_t)0;
	return 0;
}

int E_EncyclopediaHandbookresolve_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaHandbookresolve_s::write_to_pbmsg(::proto_ff::E_EncyclopediaHandbookresolve & msg) const {
	msg.set_m_handbookquality((int32_t)m_handbookquality);
	msg.set_m_resolveitem((int32_t)m_resolveitem);
	msg.set_m_resolvenum((int32_t)m_resolvenum);
}

void E_EncyclopediaHandbookresolve_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbookresolve & msg) {
	m_handbookquality = msg.m_handbookquality();
	m_resolveitem = msg.m_resolveitem();
	m_resolvenum = msg.m_resolvenum();
}

Sheet_EncyclopediaHandbookresolve_s::Sheet_EncyclopediaHandbookresolve_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EncyclopediaHandbookresolve_s::CreateInit() {
	return 0;
}

int Sheet_EncyclopediaHandbookresolve_s::ResumeInit() {
	return 0;
}

void Sheet_EncyclopediaHandbookresolve_s::write_to_pbmsg(::proto_ff::Sheet_EncyclopediaHandbookresolve & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaHandbookresolve_List.size(); ++i) {
		::proto_ff::E_EncyclopediaHandbookresolve* temp_e_encyclopediahandbookresolve_list = msg.add_e_encyclopediahandbookresolve_list();
		E_EncyclopediaHandbookresolve_List[i].write_to_pbmsg(*temp_e_encyclopediahandbookresolve_list);
	}
}

void Sheet_EncyclopediaHandbookresolve_s::read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaHandbookresolve & msg) {
	E_EncyclopediaHandbookresolve_List.resize((int)msg.e_encyclopediahandbookresolve_list_size() > (int)E_EncyclopediaHandbookresolve_List.max_size() ? E_EncyclopediaHandbookresolve_List.max_size() : msg.e_encyclopediahandbookresolve_list_size());
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaHandbookresolve_List.size(); ++i) {
		const ::proto_ff::E_EncyclopediaHandbookresolve & temp_e_encyclopediahandbookresolve_list = msg.e_encyclopediahandbookresolve_list(i);
		E_EncyclopediaHandbookresolve_List[i].read_from_pbmsg(temp_e_encyclopediahandbookresolve_list);
	}
}

E_EncyclopediaHandbooklv_attr_s::E_EncyclopediaHandbooklv_attr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaHandbooklv_attr_s::CreateInit() {
	m_attid = (int64_t)0;
	return 0;
}

int E_EncyclopediaHandbooklv_attr_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaHandbooklv_attr_s::write_to_pbmsg(::proto_ff::E_EncyclopediaHandbooklv_attr & msg) const {
	msg.set_m_attid((int64_t)m_attid);
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		msg.add_m_att((int32_t)m_att[i]);
	}
}

void E_EncyclopediaHandbooklv_attr_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbooklv_attr & msg) {
	m_attid = msg.m_attid();
	m_att.resize((int)msg.m_att_size() > (int)m_att.max_size() ? m_att.max_size() : msg.m_att_size());
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		m_att[i] = msg.m_att(i);
	}
}

Sheet_EncyclopediaHandbooklv_attr_s::Sheet_EncyclopediaHandbooklv_attr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EncyclopediaHandbooklv_attr_s::CreateInit() {
	return 0;
}

int Sheet_EncyclopediaHandbooklv_attr_s::ResumeInit() {
	return 0;
}

void Sheet_EncyclopediaHandbooklv_attr_s::write_to_pbmsg(::proto_ff::Sheet_EncyclopediaHandbooklv_attr & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaHandbooklv_attr_List.size(); ++i) {
		::proto_ff::E_EncyclopediaHandbooklv_attr* temp_e_encyclopediahandbooklv_attr_list = msg.add_e_encyclopediahandbooklv_attr_list();
		E_EncyclopediaHandbooklv_attr_List[i].write_to_pbmsg(*temp_e_encyclopediahandbooklv_attr_list);
	}
}

void Sheet_EncyclopediaHandbooklv_attr_s::read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaHandbooklv_attr & msg) {
	E_EncyclopediaHandbooklv_attr_List.resize((int)msg.e_encyclopediahandbooklv_attr_list_size() > (int)E_EncyclopediaHandbooklv_attr_List.max_size() ? E_EncyclopediaHandbooklv_attr_List.max_size() : msg.e_encyclopediahandbooklv_attr_list_size());
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaHandbooklv_attr_List.size(); ++i) {
		const ::proto_ff::E_EncyclopediaHandbooklv_attr & temp_e_encyclopediahandbooklv_attr_list = msg.e_encyclopediahandbooklv_attr_list(i);
		E_EncyclopediaHandbooklv_attr_List[i].read_from_pbmsg(temp_e_encyclopediahandbooklv_attr_list);
	}
}

E_EncyclopediaHandbookstar_attr_s::E_EncyclopediaHandbookstar_attr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaHandbookstar_attr_s::CreateInit() {
	m_attid = (int64_t)0;
	return 0;
}

int E_EncyclopediaHandbookstar_attr_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaHandbookstar_attr_s::write_to_pbmsg(::proto_ff::E_EncyclopediaHandbookstar_attr & msg) const {
	msg.set_m_attid((int64_t)m_attid);
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		msg.add_m_att((int32_t)m_att[i]);
	}
}

void E_EncyclopediaHandbookstar_attr_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaHandbookstar_attr & msg) {
	m_attid = msg.m_attid();
	m_att.resize((int)msg.m_att_size() > (int)m_att.max_size() ? m_att.max_size() : msg.m_att_size());
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		m_att[i] = msg.m_att(i);
	}
}

Sheet_EncyclopediaHandbookstar_attr_s::Sheet_EncyclopediaHandbookstar_attr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EncyclopediaHandbookstar_attr_s::CreateInit() {
	return 0;
}

int Sheet_EncyclopediaHandbookstar_attr_s::ResumeInit() {
	return 0;
}

void Sheet_EncyclopediaHandbookstar_attr_s::write_to_pbmsg(::proto_ff::Sheet_EncyclopediaHandbookstar_attr & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaHandbookstar_attr_List.size(); ++i) {
		::proto_ff::E_EncyclopediaHandbookstar_attr* temp_e_encyclopediahandbookstar_attr_list = msg.add_e_encyclopediahandbookstar_attr_list();
		E_EncyclopediaHandbookstar_attr_List[i].write_to_pbmsg(*temp_e_encyclopediahandbookstar_attr_list);
	}
}

void Sheet_EncyclopediaHandbookstar_attr_s::read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaHandbookstar_attr & msg) {
	E_EncyclopediaHandbookstar_attr_List.resize((int)msg.e_encyclopediahandbookstar_attr_list_size() > (int)E_EncyclopediaHandbookstar_attr_List.max_size() ? E_EncyclopediaHandbookstar_attr_List.max_size() : msg.e_encyclopediahandbookstar_attr_list_size());
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaHandbookstar_attr_List.size(); ++i) {
		const ::proto_ff::E_EncyclopediaHandbookstar_attr & temp_e_encyclopediahandbookstar_attr_list = msg.e_encyclopediahandbookstar_attr_list(i);
		E_EncyclopediaHandbookstar_attr_List[i].read_from_pbmsg(temp_e_encyclopediahandbookstar_attr_list);
	}
}

E_EncyclopediaBeastBeastDesc_s::E_EncyclopediaBeastBeastDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaBeastBeastDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_att = (int32_t)0;
	return 0;
}

int E_EncyclopediaBeastBeastDesc_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaBeastBeastDesc_s::write_to_pbmsg(::proto_ff::E_EncyclopediaBeastBeastDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_att((int32_t)m_att);
}

void E_EncyclopediaBeastBeastDesc_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaBeastBeastDesc & msg) {
	m_num = msg.m_num();
	m_att = msg.m_att();
}

E_EncyclopediaBeast_s::E_EncyclopediaBeast_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaBeast_s::CreateInit() {
	m_id = (int64_t)0;
	return 0;
}

int E_EncyclopediaBeast_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaBeast_s::write_to_pbmsg(::proto_ff::E_EncyclopediaBeast & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_name(m_name.data());
	for(int32_t i = 0; i < (int32_t)m_pos.size(); ++i) {
		msg.add_m_pos((int32_t)m_pos[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_beast.size(); ++i) {
		::proto_ff::E_EncyclopediaBeastBeastDesc* temp_m_beast = msg.add_m_beast();
		m_beast[i].write_to_pbmsg(*temp_m_beast);
	}
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		msg.add_m_skill((int64_t)m_skill[i]);
	}
}

void E_EncyclopediaBeast_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaBeast & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_pos.resize((int)msg.m_pos_size() > (int)m_pos.max_size() ? m_pos.max_size() : msg.m_pos_size());
	for(int32_t i = 0; i < (int32_t)m_pos.size(); ++i) {
		m_pos[i] = msg.m_pos(i);
	}
	m_beast.resize((int)msg.m_beast_size() > (int)m_beast.max_size() ? m_beast.max_size() : msg.m_beast_size());
	for(int32_t i = 0; i < (int32_t)m_beast.size(); ++i) {
		const ::proto_ff::E_EncyclopediaBeastBeastDesc & temp_m_beast = msg.m_beast(i);
		m_beast[i].read_from_pbmsg(temp_m_beast);
	}
	m_skill.resize((int)msg.m_skill_size() > (int)m_skill.max_size() ? m_skill.max_size() : msg.m_skill_size());
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		m_skill[i] = msg.m_skill(i);
	}
}

Sheet_EncyclopediaBeast_s::Sheet_EncyclopediaBeast_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EncyclopediaBeast_s::CreateInit() {
	return 0;
}

int Sheet_EncyclopediaBeast_s::ResumeInit() {
	return 0;
}

void Sheet_EncyclopediaBeast_s::write_to_pbmsg(::proto_ff::Sheet_EncyclopediaBeast & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaBeast_List.size(); ++i) {
		::proto_ff::E_EncyclopediaBeast* temp_e_encyclopediabeast_list = msg.add_e_encyclopediabeast_list();
		E_EncyclopediaBeast_List[i].write_to_pbmsg(*temp_e_encyclopediabeast_list);
	}
}

void Sheet_EncyclopediaBeast_s::read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaBeast & msg) {
	E_EncyclopediaBeast_List.resize((int)msg.e_encyclopediabeast_list_size() > (int)E_EncyclopediaBeast_List.max_size() ? E_EncyclopediaBeast_List.max_size() : msg.e_encyclopediabeast_list_size());
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaBeast_List.size(); ++i) {
		const ::proto_ff::E_EncyclopediaBeast & temp_e_encyclopediabeast_list = msg.e_encyclopediabeast_list(i);
		E_EncyclopediaBeast_List[i].read_from_pbmsg(temp_e_encyclopediabeast_list);
	}
}

E_EncyclopediaEquipexpvalue_s::E_EncyclopediaEquipexpvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaEquipexpvalue_s::CreateInit() {
	m_id = (int64_t)0;
	m_type = (int64_t)0;
	m_exp = (int32_t)0;
	m_link = (int64_t)0;
	return 0;
}

int E_EncyclopediaEquipexpvalue_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaEquipexpvalue_s::write_to_pbmsg(::proto_ff::E_EncyclopediaEquipexpvalue & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_type((int64_t)m_type);
	msg.set_m_name(m_name.data());
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_link((int64_t)m_link);
}

void E_EncyclopediaEquipexpvalue_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaEquipexpvalue & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_name = msg.m_name();
	m_exp = msg.m_exp();
	m_link = msg.m_link();
}

Sheet_EncyclopediaEquipexpvalue_s::Sheet_EncyclopediaEquipexpvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EncyclopediaEquipexpvalue_s::CreateInit() {
	return 0;
}

int Sheet_EncyclopediaEquipexpvalue_s::ResumeInit() {
	return 0;
}

void Sheet_EncyclopediaEquipexpvalue_s::write_to_pbmsg(::proto_ff::Sheet_EncyclopediaEquipexpvalue & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaEquipexpvalue_List.size(); ++i) {
		::proto_ff::E_EncyclopediaEquipexpvalue* temp_e_encyclopediaequipexpvalue_list = msg.add_e_encyclopediaequipexpvalue_list();
		E_EncyclopediaEquipexpvalue_List[i].write_to_pbmsg(*temp_e_encyclopediaequipexpvalue_list);
	}
}

void Sheet_EncyclopediaEquipexpvalue_s::read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaEquipexpvalue & msg) {
	E_EncyclopediaEquipexpvalue_List.resize((int)msg.e_encyclopediaequipexpvalue_list_size() > (int)E_EncyclopediaEquipexpvalue_List.max_size() ? E_EncyclopediaEquipexpvalue_List.max_size() : msg.e_encyclopediaequipexpvalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaEquipexpvalue_List.size(); ++i) {
		const ::proto_ff::E_EncyclopediaEquipexpvalue & temp_e_encyclopediaequipexpvalue_list = msg.e_encyclopediaequipexpvalue_list(i);
		E_EncyclopediaEquipexpvalue_List[i].read_from_pbmsg(temp_e_encyclopediaequipexpvalue_list);
	}
}

E_EncyclopediaBeastexp_s::E_EncyclopediaBeastexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaBeastexp_s::CreateInit() {
	m_lv = (int32_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_EncyclopediaBeastexp_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaBeastexp_s::write_to_pbmsg(::proto_ff::E_EncyclopediaBeastexp & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int32_t)m_exp);
}

void E_EncyclopediaBeastexp_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaBeastexp & msg) {
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
}

Sheet_EncyclopediaBeastexp_s::Sheet_EncyclopediaBeastexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EncyclopediaBeastexp_s::CreateInit() {
	return 0;
}

int Sheet_EncyclopediaBeastexp_s::ResumeInit() {
	return 0;
}

void Sheet_EncyclopediaBeastexp_s::write_to_pbmsg(::proto_ff::Sheet_EncyclopediaBeastexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaBeastexp_List.size(); ++i) {
		::proto_ff::E_EncyclopediaBeastexp* temp_e_encyclopediabeastexp_list = msg.add_e_encyclopediabeastexp_list();
		E_EncyclopediaBeastexp_List[i].write_to_pbmsg(*temp_e_encyclopediabeastexp_list);
	}
}

void Sheet_EncyclopediaBeastexp_s::read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaBeastexp & msg) {
	E_EncyclopediaBeastexp_List.resize((int)msg.e_encyclopediabeastexp_list_size() > (int)E_EncyclopediaBeastexp_List.max_size() ? E_EncyclopediaBeastexp_List.max_size() : msg.e_encyclopediabeastexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaBeastexp_List.size(); ++i) {
		const ::proto_ff::E_EncyclopediaBeastexp & temp_e_encyclopediabeastexp_list = msg.e_encyclopediabeastexp_list(i);
		E_EncyclopediaBeastexp_List[i].read_from_pbmsg(temp_e_encyclopediabeastexp_list);
	}
}

E_EncyclopediaBeastexpand_s::E_EncyclopediaBeastexpand_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaBeastexpand_s::CreateInit() {
	m_number = (int32_t)0;
	m_lv = (int32_t)0;
	m_id = (int64_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_EncyclopediaBeastexpand_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaBeastexpand_s::write_to_pbmsg(::proto_ff::E_EncyclopediaBeastexpand & msg) const {
	msg.set_m_number((int32_t)m_number);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_id((int64_t)m_id);
	msg.set_m_num((int32_t)m_num);
}

void E_EncyclopediaBeastexpand_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaBeastexpand & msg) {
	m_number = msg.m_number();
	m_lv = msg.m_lv();
	m_id = msg.m_id();
	m_num = msg.m_num();
}

Sheet_EncyclopediaBeastexpand_s::Sheet_EncyclopediaBeastexpand_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EncyclopediaBeastexpand_s::CreateInit() {
	return 0;
}

int Sheet_EncyclopediaBeastexpand_s::ResumeInit() {
	return 0;
}

void Sheet_EncyclopediaBeastexpand_s::write_to_pbmsg(::proto_ff::Sheet_EncyclopediaBeastexpand & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaBeastexpand_List.size(); ++i) {
		::proto_ff::E_EncyclopediaBeastexpand* temp_e_encyclopediabeastexpand_list = msg.add_e_encyclopediabeastexpand_list();
		E_EncyclopediaBeastexpand_List[i].write_to_pbmsg(*temp_e_encyclopediabeastexpand_list);
	}
}

void Sheet_EncyclopediaBeastexpand_s::read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaBeastexpand & msg) {
	E_EncyclopediaBeastexpand_List.resize((int)msg.e_encyclopediabeastexpand_list_size() > (int)E_EncyclopediaBeastexpand_List.max_size() ? E_EncyclopediaBeastexpand_List.max_size() : msg.e_encyclopediabeastexpand_list_size());
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaBeastexpand_List.size(); ++i) {
		const ::proto_ff::E_EncyclopediaBeastexpand & temp_e_encyclopediabeastexpand_list = msg.e_encyclopediabeastexpand_list(i);
		E_EncyclopediaBeastexpand_List[i].read_from_pbmsg(temp_e_encyclopediabeastexpand_list);
	}
}

E_EncyclopediaBeastprivilegeAttributeDesc_s::E_EncyclopediaBeastprivilegeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaBeastprivilegeAttributeDesc_s::CreateInit() {
	m_value = (int64_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EncyclopediaBeastprivilegeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaBeastprivilegeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_EncyclopediaBeastprivilegeAttributeDesc & msg) const {
	msg.set_m_value((int64_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_EncyclopediaBeastprivilegeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaBeastprivilegeAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_EncyclopediaBeastprivilege_s::E_EncyclopediaBeastprivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaBeastprivilege_s::CreateInit() {
	m_privilegetype = (int32_t)0;
	m_price = (int32_t)0;
	m_expaddition = (int64_t)0;
	return 0;
}

int E_EncyclopediaBeastprivilege_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaBeastprivilege_s::write_to_pbmsg(::proto_ff::E_EncyclopediaBeastprivilege & msg) const {
	msg.set_m_privilegetype((int32_t)m_privilegetype);
	msg.set_m_name(m_name.data());
	msg.set_m_price((int32_t)m_price);
	msg.set_m_expaddition((int64_t)m_expaddition);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_EncyclopediaBeastprivilegeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_EncyclopediaBeastprivilege_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaBeastprivilege & msg) {
	m_privilegetype = msg.m_privilegetype();
	m_name = msg.m_name();
	m_price = msg.m_price();
	m_expaddition = msg.m_expaddition();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_EncyclopediaBeastprivilegeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_EncyclopediaBeastprivilege_s::Sheet_EncyclopediaBeastprivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EncyclopediaBeastprivilege_s::CreateInit() {
	return 0;
}

int Sheet_EncyclopediaBeastprivilege_s::ResumeInit() {
	return 0;
}

void Sheet_EncyclopediaBeastprivilege_s::write_to_pbmsg(::proto_ff::Sheet_EncyclopediaBeastprivilege & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaBeastprivilege_List.size(); ++i) {
		::proto_ff::E_EncyclopediaBeastprivilege* temp_e_encyclopediabeastprivilege_list = msg.add_e_encyclopediabeastprivilege_list();
		E_EncyclopediaBeastprivilege_List[i].write_to_pbmsg(*temp_e_encyclopediabeastprivilege_list);
	}
}

void Sheet_EncyclopediaBeastprivilege_s::read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaBeastprivilege & msg) {
	E_EncyclopediaBeastprivilege_List.resize((int)msg.e_encyclopediabeastprivilege_list_size() > (int)E_EncyclopediaBeastprivilege_List.max_size() ? E_EncyclopediaBeastprivilege_List.max_size() : msg.e_encyclopediabeastprivilege_list_size());
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaBeastprivilege_List.size(); ++i) {
		const ::proto_ff::E_EncyclopediaBeastprivilege & temp_e_encyclopediabeastprivilege_list = msg.e_encyclopediabeastprivilege_list(i);
		E_EncyclopediaBeastprivilege_List[i].read_from_pbmsg(temp_e_encyclopediabeastprivilege_list);
	}
}

E_EncyclopediaEmployLviattributeDesc_s::E_EncyclopediaEmployLviattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaEmployLviattributeDesc_s::CreateInit() {
	m_value = (int64_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EncyclopediaEmployLviattributeDesc_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaEmployLviattributeDesc_s::write_to_pbmsg(::proto_ff::E_EncyclopediaEmployLviattributeDesc & msg) const {
	msg.set_m_value((int64_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_EncyclopediaEmployLviattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaEmployLviattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_EncyclopediaEmploy_s::E_EncyclopediaEmploy_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaEmploy_s::CreateInit() {
	m_employid = (int64_t)0;
	m_type = (int64_t)0;
	m_itemid = (int64_t)0;
	m_employquality = (int32_t)0;
	m_employtype = (int32_t)0;
	m_employz = (int32_t)0;
	return 0;
}

int E_EncyclopediaEmploy_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaEmploy_s::write_to_pbmsg(::proto_ff::E_EncyclopediaEmploy & msg) const {
	msg.set_m_employid((int64_t)m_employid);
	msg.set_m_type((int64_t)m_type);
	msg.set_m_itemid((int64_t)m_itemid);
	msg.set_m_employname(m_employname.data());
	msg.set_m_employquality((int32_t)m_employquality);
	msg.set_m_employtype((int32_t)m_employtype);
	msg.set_m_employtype_name(m_employtype_name.data());
	msg.set_m_employz((int32_t)m_employz);
	msg.set_m_employzname(m_employzname.data());
	for(int32_t i = 0; i < (int32_t)m_lviattribute.size(); ++i) {
		::proto_ff::E_EncyclopediaEmployLviattributeDesc* temp_m_lviattribute = msg.add_m_lviattribute();
		m_lviattribute[i].write_to_pbmsg(*temp_m_lviattribute);
	}
}

void E_EncyclopediaEmploy_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaEmploy & msg) {
	m_employid = msg.m_employid();
	m_type = msg.m_type();
	m_itemid = msg.m_itemid();
	m_employname = msg.m_employname();
	m_employquality = msg.m_employquality();
	m_employtype = msg.m_employtype();
	m_employtype_name = msg.m_employtype_name();
	m_employz = msg.m_employz();
	m_employzname = msg.m_employzname();
	m_lviattribute.resize((int)msg.m_lviattribute_size() > (int)m_lviattribute.max_size() ? m_lviattribute.max_size() : msg.m_lviattribute_size());
	for(int32_t i = 0; i < (int32_t)m_lviattribute.size(); ++i) {
		const ::proto_ff::E_EncyclopediaEmployLviattributeDesc & temp_m_lviattribute = msg.m_lviattribute(i);
		m_lviattribute[i].read_from_pbmsg(temp_m_lviattribute);
	}
}

Sheet_EncyclopediaEmploy_s::Sheet_EncyclopediaEmploy_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EncyclopediaEmploy_s::CreateInit() {
	return 0;
}

int Sheet_EncyclopediaEmploy_s::ResumeInit() {
	return 0;
}

void Sheet_EncyclopediaEmploy_s::write_to_pbmsg(::proto_ff::Sheet_EncyclopediaEmploy & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaEmploy_List.size(); ++i) {
		::proto_ff::E_EncyclopediaEmploy* temp_e_encyclopediaemploy_list = msg.add_e_encyclopediaemploy_list();
		E_EncyclopediaEmploy_List[i].write_to_pbmsg(*temp_e_encyclopediaemploy_list);
	}
}

void Sheet_EncyclopediaEmploy_s::read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaEmploy & msg) {
	E_EncyclopediaEmploy_List.resize((int)msg.e_encyclopediaemploy_list_size() > (int)E_EncyclopediaEmploy_List.max_size() ? E_EncyclopediaEmploy_List.max_size() : msg.e_encyclopediaemploy_list_size());
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaEmploy_List.size(); ++i) {
		const ::proto_ff::E_EncyclopediaEmploy & temp_e_encyclopediaemploy_list = msg.e_encyclopediaemploy_list(i);
		E_EncyclopediaEmploy_List[i].read_from_pbmsg(temp_e_encyclopediaemploy_list);
	}
}

E_EncyclopediaTableLviattributeDesc_s::E_EncyclopediaTableLviattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaTableLviattributeDesc_s::CreateInit() {
	m_value = (int64_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EncyclopediaTableLviattributeDesc_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaTableLviattributeDesc_s::write_to_pbmsg(::proto_ff::E_EncyclopediaTableLviattributeDesc & msg) const {
	msg.set_m_value((int64_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_EncyclopediaTableLviattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaTableLviattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_EncyclopediaTable_s::E_EncyclopediaTable_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EncyclopediaTable_s::CreateInit() {
	m_id = (int64_t)0;
	m_tableid = (int64_t)0;
	return 0;
}

int E_EncyclopediaTable_s::ResumeInit() {
	return 0;
}

void E_EncyclopediaTable_s::write_to_pbmsg(::proto_ff::E_EncyclopediaTable & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_tableid((int64_t)m_tableid);
	msg.set_m_tablename(m_tablename.data());
	for(int32_t i = 0; i < (int32_t)m_lviattribute.size(); ++i) {
		::proto_ff::E_EncyclopediaTableLviattributeDesc* temp_m_lviattribute = msg.add_m_lviattribute();
		m_lviattribute[i].write_to_pbmsg(*temp_m_lviattribute);
	}
}

void E_EncyclopediaTable_s::read_from_pbmsg(const ::proto_ff::E_EncyclopediaTable & msg) {
	m_id = msg.m_id();
	m_tableid = msg.m_tableid();
	m_tablename = msg.m_tablename();
	m_lviattribute.resize((int)msg.m_lviattribute_size() > (int)m_lviattribute.max_size() ? m_lviattribute.max_size() : msg.m_lviattribute_size());
	for(int32_t i = 0; i < (int32_t)m_lviattribute.size(); ++i) {
		const ::proto_ff::E_EncyclopediaTableLviattributeDesc & temp_m_lviattribute = msg.m_lviattribute(i);
		m_lviattribute[i].read_from_pbmsg(temp_m_lviattribute);
	}
}

Sheet_EncyclopediaTable_s::Sheet_EncyclopediaTable_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EncyclopediaTable_s::CreateInit() {
	return 0;
}

int Sheet_EncyclopediaTable_s::ResumeInit() {
	return 0;
}

void Sheet_EncyclopediaTable_s::write_to_pbmsg(::proto_ff::Sheet_EncyclopediaTable & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaTable_List.size(); ++i) {
		::proto_ff::E_EncyclopediaTable* temp_e_encyclopediatable_list = msg.add_e_encyclopediatable_list();
		E_EncyclopediaTable_List[i].write_to_pbmsg(*temp_e_encyclopediatable_list);
	}
}

void Sheet_EncyclopediaTable_s::read_from_pbmsg(const ::proto_ff::Sheet_EncyclopediaTable & msg) {
	E_EncyclopediaTable_List.resize((int)msg.e_encyclopediatable_list_size() > (int)E_EncyclopediaTable_List.max_size() ? E_EncyclopediaTable_List.max_size() : msg.e_encyclopediatable_list_size());
	for(int32_t i = 0; i < (int32_t)E_EncyclopediaTable_List.size(); ++i) {
		const ::proto_ff::E_EncyclopediaTable & temp_e_encyclopediatable_list = msg.e_encyclopediatable_list(i);
		E_EncyclopediaTable_List[i].read_from_pbmsg(temp_e_encyclopediatable_list);
	}
}

}
