#include "E_Soul_s.h"

namespace proto_ff_s {

E_SoulOpen_s::E_SoulOpen_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulOpen_s::CreateInit() {
	m_id = (int32_t)0;
	m_lv = (int32_t)0;
	m_box = (int32_t)0;
	return 0;
}

int E_SoulOpen_s::ResumeInit() {
	return 0;
}

void E_SoulOpen_s::write_to_pbmsg(::proto_ff::E_SoulOpen & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_box((int32_t)m_box);
}

void E_SoulOpen_s::read_from_pbmsg(const ::proto_ff::E_SoulOpen & msg) {
	m_id = msg.m_id();
	m_lv = msg.m_lv();
	m_box = msg.m_box();
}

Sheet_SoulOpen_s::Sheet_SoulOpen_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulOpen_s::CreateInit() {
	return 0;
}

int Sheet_SoulOpen_s::ResumeInit() {
	return 0;
}

void Sheet_SoulOpen_s::write_to_pbmsg(::proto_ff::Sheet_SoulOpen & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulOpen_List.size(); ++i) {
		::proto_ff::E_SoulOpen* temp_e_soulopen_list = msg.add_e_soulopen_list();
		E_SoulOpen_List[i].write_to_pbmsg(*temp_e_soulopen_list);
	}
}

void Sheet_SoulOpen_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulOpen & msg) {
	E_SoulOpen_List.resize((int)msg.e_soulopen_list_size() > (int)E_SoulOpen_List.max_size() ? E_SoulOpen_List.max_size() : msg.e_soulopen_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulOpen_List.size(); ++i) {
		const ::proto_ff::E_SoulOpen & temp_e_soulopen_list = msg.e_soulopen_list(i);
		E_SoulOpen_List[i].read_from_pbmsg(temp_e_soulopen_list);
	}
}

E_SoulSoul_s::E_SoulSoul_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulSoul_s::CreateInit() {
	m_id = (int32_t)0;
	m_lvitem = (int32_t)0;
	m_advanceitem = (int32_t)0;
	m_sacrificeskill = (int32_t)0;
	return 0;
}

int E_SoulSoul_s::ResumeInit() {
	return 0;
}

void E_SoulSoul_s::write_to_pbmsg(::proto_ff::E_SoulSoul & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_lvitem((int32_t)m_lvitem);
	msg.set_m_advanceitem((int32_t)m_advanceitem);
	msg.set_m_sacrificeskill((int32_t)m_sacrificeskill);
	msg.set_m_skilllv(m_skilllv.data());
}

void E_SoulSoul_s::read_from_pbmsg(const ::proto_ff::E_SoulSoul & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_lvitem = msg.m_lvitem();
	m_advanceitem = msg.m_advanceitem();
	m_sacrificeskill = msg.m_sacrificeskill();
	m_skilllv = msg.m_skilllv();
}

Sheet_SoulSoul_s::Sheet_SoulSoul_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulSoul_s::CreateInit() {
	return 0;
}

int Sheet_SoulSoul_s::ResumeInit() {
	return 0;
}

void Sheet_SoulSoul_s::write_to_pbmsg(::proto_ff::Sheet_SoulSoul & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulSoul_List.size(); ++i) {
		::proto_ff::E_SoulSoul* temp_e_soulsoul_list = msg.add_e_soulsoul_list();
		E_SoulSoul_List[i].write_to_pbmsg(*temp_e_soulsoul_list);
	}
}

void Sheet_SoulSoul_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulSoul & msg) {
	E_SoulSoul_List.resize((int)msg.e_soulsoul_list_size() > (int)E_SoulSoul_List.max_size() ? E_SoulSoul_List.max_size() : msg.e_soulsoul_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulSoul_List.size(); ++i) {
		const ::proto_ff::E_SoulSoul & temp_e_soulsoul_list = msg.e_soulsoul_list(i);
		E_SoulSoul_List[i].read_from_pbmsg(temp_e_soulsoul_list);
	}
}

E_SoulSoulbasicAttributeDesc_s::E_SoulSoulbasicAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulSoulbasicAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_SoulSoulbasicAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_SoulSoulbasicAttributeDesc_s::write_to_pbmsg(::proto_ff::E_SoulSoulbasicAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_SoulSoulbasicAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulSoulbasicAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_SoulSoulbasic_s::E_SoulSoulbasic_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulSoulbasic_s::CreateInit() {
	m_id = (int32_t)0;
	m_soulid = (int32_t)0;
	m_soullv = (int32_t)0;
	m_soulexp = (int32_t)0;
	return 0;
}

int E_SoulSoulbasic_s::ResumeInit() {
	return 0;
}

void E_SoulSoulbasic_s::write_to_pbmsg(::proto_ff::E_SoulSoulbasic & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_soulid((int32_t)m_soulid);
	msg.set_m_soullv((int32_t)m_soullv);
	msg.set_m_soulexp((int32_t)m_soulexp);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_SoulSoulbasicAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_SoulSoulbasic_s::read_from_pbmsg(const ::proto_ff::E_SoulSoulbasic & msg) {
	m_id = msg.m_id();
	m_soulid = msg.m_soulid();
	m_soullv = msg.m_soullv();
	m_soulexp = msg.m_soulexp();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_SoulSoulbasicAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_SoulSoulbasic_s::Sheet_SoulSoulbasic_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulSoulbasic_s::CreateInit() {
	return 0;
}

int Sheet_SoulSoulbasic_s::ResumeInit() {
	return 0;
}

void Sheet_SoulSoulbasic_s::write_to_pbmsg(::proto_ff::Sheet_SoulSoulbasic & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulSoulbasic_List.size(); ++i) {
		::proto_ff::E_SoulSoulbasic* temp_e_soulsoulbasic_list = msg.add_e_soulsoulbasic_list();
		E_SoulSoulbasic_List[i].write_to_pbmsg(*temp_e_soulsoulbasic_list);
	}
}

void Sheet_SoulSoulbasic_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulSoulbasic & msg) {
	E_SoulSoulbasic_List.resize((int)msg.e_soulsoulbasic_list_size() > (int)E_SoulSoulbasic_List.max_size() ? E_SoulSoulbasic_List.max_size() : msg.e_soulsoulbasic_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulSoulbasic_List.size(); ++i) {
		const ::proto_ff::E_SoulSoulbasic & temp_e_soulsoulbasic_list = msg.e_soulsoulbasic_list(i);
		E_SoulSoulbasic_List[i].read_from_pbmsg(temp_e_soulsoulbasic_list);
	}
}

E_SoulSouladvanceAttributeDesc_s::E_SoulSouladvanceAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulSouladvanceAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_SoulSouladvanceAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_SoulSouladvanceAttributeDesc_s::write_to_pbmsg(::proto_ff::E_SoulSouladvanceAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_SoulSouladvanceAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulSouladvanceAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_SoulSouladvance_s::E_SoulSouladvance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulSouladvance_s::CreateInit() {
	m_id = (int32_t)0;
	m_soulid = (int32_t)0;
	m_advancelv = (int32_t)0;
	m_advancenum = (int32_t)0;
	return 0;
}

int E_SoulSouladvance_s::ResumeInit() {
	return 0;
}

void E_SoulSouladvance_s::write_to_pbmsg(::proto_ff::E_SoulSouladvance & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_soulid((int32_t)m_soulid);
	msg.set_m_advancelv((int32_t)m_advancelv);
	msg.set_m_advancenum((int32_t)m_advancenum);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_SoulSouladvanceAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_SoulSouladvance_s::read_from_pbmsg(const ::proto_ff::E_SoulSouladvance & msg) {
	m_id = msg.m_id();
	m_soulid = msg.m_soulid();
	m_advancelv = msg.m_advancelv();
	m_advancenum = msg.m_advancenum();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_SoulSouladvanceAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_SoulSouladvance_s::Sheet_SoulSouladvance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulSouladvance_s::CreateInit() {
	return 0;
}

int Sheet_SoulSouladvance_s::ResumeInit() {
	return 0;
}

void Sheet_SoulSouladvance_s::write_to_pbmsg(::proto_ff::Sheet_SoulSouladvance & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulSouladvance_List.size(); ++i) {
		::proto_ff::E_SoulSouladvance* temp_e_soulsouladvance_list = msg.add_e_soulsouladvance_list();
		E_SoulSouladvance_List[i].write_to_pbmsg(*temp_e_soulsouladvance_list);
	}
}

void Sheet_SoulSouladvance_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulSouladvance & msg) {
	E_SoulSouladvance_List.resize((int)msg.e_soulsouladvance_list_size() > (int)E_SoulSouladvance_List.max_size() ? E_SoulSouladvance_List.max_size() : msg.e_soulsouladvance_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulSouladvance_List.size(); ++i) {
		const ::proto_ff::E_SoulSouladvance & temp_e_soulsouladvance_list = msg.e_soulsouladvance_list(i);
		E_SoulSouladvance_List[i].read_from_pbmsg(temp_e_soulsouladvance_list);
	}
}

E_SoulBless_s::E_SoulBless_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulBless_s::CreateInit() {
	m_id = (int32_t)0;
	m_basic_exp = (int32_t)0;
	m_need_gold = (int32_t)0;
	m_open_lv = (int32_t)0;
	return 0;
}

int E_SoulBless_s::ResumeInit() {
	return 0;
}

void E_SoulBless_s::write_to_pbmsg(::proto_ff::E_SoulBless & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_basic_exp((int32_t)m_basic_exp);
	msg.set_m_need_gold((int32_t)m_need_gold);
	msg.set_m_open_lv((int32_t)m_open_lv);
}

void E_SoulBless_s::read_from_pbmsg(const ::proto_ff::E_SoulBless & msg) {
	m_id = msg.m_id();
	m_basic_exp = msg.m_basic_exp();
	m_need_gold = msg.m_need_gold();
	m_open_lv = msg.m_open_lv();
}

Sheet_SoulBless_s::Sheet_SoulBless_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulBless_s::CreateInit() {
	return 0;
}

int Sheet_SoulBless_s::ResumeInit() {
	return 0;
}

void Sheet_SoulBless_s::write_to_pbmsg(::proto_ff::Sheet_SoulBless & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulBless_List.size(); ++i) {
		::proto_ff::E_SoulBless* temp_e_soulbless_list = msg.add_e_soulbless_list();
		E_SoulBless_List[i].write_to_pbmsg(*temp_e_soulbless_list);
	}
}

void Sheet_SoulBless_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulBless & msg) {
	E_SoulBless_List.resize((int)msg.e_soulbless_list_size() > (int)E_SoulBless_List.max_size() ? E_SoulBless_List.max_size() : msg.e_soulbless_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulBless_List.size(); ++i) {
		const ::proto_ff::E_SoulBless & temp_e_soulbless_list = msg.e_soulbless_list(i);
		E_SoulBless_List[i].read_from_pbmsg(temp_e_soulbless_list);
	}
}

E_SoulPrivilegeAttributeDesc_s::E_SoulPrivilegeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulPrivilegeAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_SoulPrivilegeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_SoulPrivilegeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_SoulPrivilegeAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_SoulPrivilegeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulPrivilegeAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_SoulPrivilege_s::E_SoulPrivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulPrivilege_s::CreateInit() {
	m_id = (int32_t)0;
	m_poolup = (int32_t)0;
	m_huoyuedu_to_exp = (int32_t)0;
	m_meditation_to_exp = (int32_t)0;
	return 0;
}

int E_SoulPrivilege_s::ResumeInit() {
	return 0;
}

void E_SoulPrivilege_s::write_to_pbmsg(::proto_ff::E_SoulPrivilege & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_activate(m_activate.data());
	msg.set_m_poolup((int32_t)m_poolup);
	msg.set_m_huoyuedu_to_exp((int32_t)m_huoyuedu_to_exp);
	msg.set_m_meditation_to_exp((int32_t)m_meditation_to_exp);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_SoulPrivilegeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_SoulPrivilege_s::read_from_pbmsg(const ::proto_ff::E_SoulPrivilege & msg) {
	m_id = msg.m_id();
	m_activate = msg.m_activate();
	m_poolup = msg.m_poolup();
	m_huoyuedu_to_exp = msg.m_huoyuedu_to_exp();
	m_meditation_to_exp = msg.m_meditation_to_exp();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_SoulPrivilegeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_SoulPrivilege_s::Sheet_SoulPrivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulPrivilege_s::CreateInit() {
	return 0;
}

int Sheet_SoulPrivilege_s::ResumeInit() {
	return 0;
}

void Sheet_SoulPrivilege_s::write_to_pbmsg(::proto_ff::Sheet_SoulPrivilege & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulPrivilege_List.size(); ++i) {
		::proto_ff::E_SoulPrivilege* temp_e_soulprivilege_list = msg.add_e_soulprivilege_list();
		E_SoulPrivilege_List[i].write_to_pbmsg(*temp_e_soulprivilege_list);
	}
}

void Sheet_SoulPrivilege_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulPrivilege & msg) {
	E_SoulPrivilege_List.resize((int)msg.e_soulprivilege_list_size() > (int)E_SoulPrivilege_List.max_size() ? E_SoulPrivilege_List.max_size() : msg.e_soulprivilege_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulPrivilege_List.size(); ++i) {
		const ::proto_ff::E_SoulPrivilege & temp_e_soulprivilege_list = msg.e_soulprivilege_list(i);
		E_SoulPrivilege_List[i].read_from_pbmsg(temp_e_soulprivilege_list);
	}
}

E_SoulCrystal_s::E_SoulCrystal_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulCrystal_s::CreateInit() {
	m_equipid = (int32_t)0;
	m_crystaltype = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	m_dismantletime = (int32_t)0;
	m_dismantlenum = (int32_t)0;
	m_skill = (int32_t)0;
	m_skilllv = (int32_t)0;
	m_handbook = (int32_t)0;
	return 0;
}

int E_SoulCrystal_s::ResumeInit() {
	return 0;
}

void E_SoulCrystal_s::write_to_pbmsg(::proto_ff::E_SoulCrystal & msg) const {
	msg.set_m_equipid((int32_t)m_equipid);
	msg.set_m_name(m_name.data());
	msg.set_m_crystaltype((int32_t)m_crystaltype);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_dismantletime((int32_t)m_dismantletime);
	msg.set_m_dismantlenum((int32_t)m_dismantlenum);
	msg.set_m_skill((int32_t)m_skill);
	msg.set_m_skilllv((int32_t)m_skilllv);
	msg.set_m_handbook((int32_t)m_handbook);
}

void E_SoulCrystal_s::read_from_pbmsg(const ::proto_ff::E_SoulCrystal & msg) {
	m_equipid = msg.m_equipid();
	m_name = msg.m_name();
	m_crystaltype = msg.m_crystaltype();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_dismantletime = msg.m_dismantletime();
	m_dismantlenum = msg.m_dismantlenum();
	m_skill = msg.m_skill();
	m_skilllv = msg.m_skilllv();
	m_handbook = msg.m_handbook();
}

Sheet_SoulCrystal_s::Sheet_SoulCrystal_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulCrystal_s::CreateInit() {
	return 0;
}

int Sheet_SoulCrystal_s::ResumeInit() {
	return 0;
}

void Sheet_SoulCrystal_s::write_to_pbmsg(::proto_ff::Sheet_SoulCrystal & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulCrystal_List.size(); ++i) {
		::proto_ff::E_SoulCrystal* temp_e_soulcrystal_list = msg.add_e_soulcrystal_list();
		E_SoulCrystal_List[i].write_to_pbmsg(*temp_e_soulcrystal_list);
	}
}

void Sheet_SoulCrystal_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulCrystal & msg) {
	E_SoulCrystal_List.resize((int)msg.e_soulcrystal_list_size() > (int)E_SoulCrystal_List.max_size() ? E_SoulCrystal_List.max_size() : msg.e_soulcrystal_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulCrystal_List.size(); ++i) {
		const ::proto_ff::E_SoulCrystal & temp_e_soulcrystal_list = msg.e_soulcrystal_list(i);
		E_SoulCrystal_List[i].read_from_pbmsg(temp_e_soulcrystal_list);
	}
}

E_SoulCrystallv_s::E_SoulCrystallv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulCrystallv_s::CreateInit() {
	m_lv = (int32_t)0;
	m_wraithsitem = (int32_t)0;
	m_wraithsmun = (int32_t)0;
	return 0;
}

int E_SoulCrystallv_s::ResumeInit() {
	return 0;
}

void E_SoulCrystallv_s::write_to_pbmsg(::proto_ff::E_SoulCrystallv & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_wraithsitem((int32_t)m_wraithsitem);
	msg.set_m_wraithsmun((int32_t)m_wraithsmun);
}

void E_SoulCrystallv_s::read_from_pbmsg(const ::proto_ff::E_SoulCrystallv & msg) {
	m_lv = msg.m_lv();
	m_wraithsitem = msg.m_wraithsitem();
	m_wraithsmun = msg.m_wraithsmun();
}

Sheet_SoulCrystallv_s::Sheet_SoulCrystallv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulCrystallv_s::CreateInit() {
	return 0;
}

int Sheet_SoulCrystallv_s::ResumeInit() {
	return 0;
}

void Sheet_SoulCrystallv_s::write_to_pbmsg(::proto_ff::Sheet_SoulCrystallv & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulCrystallv_List.size(); ++i) {
		::proto_ff::E_SoulCrystallv* temp_e_soulcrystallv_list = msg.add_e_soulcrystallv_list();
		E_SoulCrystallv_List[i].write_to_pbmsg(*temp_e_soulcrystallv_list);
	}
}

void Sheet_SoulCrystallv_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulCrystallv & msg) {
	E_SoulCrystallv_List.resize((int)msg.e_soulcrystallv_list_size() > (int)E_SoulCrystallv_List.max_size() ? E_SoulCrystallv_List.max_size() : msg.e_soulcrystallv_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulCrystallv_List.size(); ++i) {
		const ::proto_ff::E_SoulCrystallv & temp_e_soulcrystallv_list = msg.e_soulcrystallv_list(i);
		E_SoulCrystallv_List[i].read_from_pbmsg(temp_e_soulcrystallv_list);
	}
}

E_SoulCrystaltopAttributeDesc_s::E_SoulCrystaltopAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulCrystaltopAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_SoulCrystaltopAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_SoulCrystaltopAttributeDesc_s::write_to_pbmsg(::proto_ff::E_SoulCrystaltopAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_SoulCrystaltopAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulCrystaltopAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_SoulCrystaltop_s::E_SoulCrystaltop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulCrystaltop_s::CreateInit() {
	m_toplv = (int32_t)0;
	m_wraithsitem = (int32_t)0;
	m_wraithsmun = (int32_t)0;
	return 0;
}

int E_SoulCrystaltop_s::ResumeInit() {
	return 0;
}

void E_SoulCrystaltop_s::write_to_pbmsg(::proto_ff::E_SoulCrystaltop & msg) const {
	msg.set_m_toplv((int32_t)m_toplv);
	msg.set_m_wraithsitem((int32_t)m_wraithsitem);
	msg.set_m_wraithsmun((int32_t)m_wraithsmun);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_SoulCrystaltopAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_SoulCrystaltop_s::read_from_pbmsg(const ::proto_ff::E_SoulCrystaltop & msg) {
	m_toplv = msg.m_toplv();
	m_wraithsitem = msg.m_wraithsitem();
	m_wraithsmun = msg.m_wraithsmun();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_SoulCrystaltopAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_SoulCrystaltop_s::Sheet_SoulCrystaltop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulCrystaltop_s::CreateInit() {
	return 0;
}

int Sheet_SoulCrystaltop_s::ResumeInit() {
	return 0;
}

void Sheet_SoulCrystaltop_s::write_to_pbmsg(::proto_ff::Sheet_SoulCrystaltop & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulCrystaltop_List.size(); ++i) {
		::proto_ff::E_SoulCrystaltop* temp_e_soulcrystaltop_list = msg.add_e_soulcrystaltop_list();
		E_SoulCrystaltop_List[i].write_to_pbmsg(*temp_e_soulcrystaltop_list);
	}
}

void Sheet_SoulCrystaltop_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulCrystaltop & msg) {
	E_SoulCrystaltop_List.resize((int)msg.e_soulcrystaltop_list_size() > (int)E_SoulCrystaltop_List.max_size() ? E_SoulCrystaltop_List.max_size() : msg.e_soulcrystaltop_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulCrystaltop_List.size(); ++i) {
		const ::proto_ff::E_SoulCrystaltop & temp_e_soulcrystaltop_list = msg.e_soulcrystaltop_list(i);
		E_SoulCrystaltop_List[i].read_from_pbmsg(temp_e_soulcrystaltop_list);
	}
}

E_SoulCrystalhole_s::E_SoulCrystalhole_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulCrystalhole_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_SoulCrystalhole_s::ResumeInit() {
	return 0;
}

void E_SoulCrystalhole_s::write_to_pbmsg(::proto_ff::E_SoulCrystalhole & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_unlock(m_unlock.data());
}

void E_SoulCrystalhole_s::read_from_pbmsg(const ::proto_ff::E_SoulCrystalhole & msg) {
	m_id = msg.m_id();
	m_unlock = msg.m_unlock();
}

Sheet_SoulCrystalhole_s::Sheet_SoulCrystalhole_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulCrystalhole_s::CreateInit() {
	return 0;
}

int Sheet_SoulCrystalhole_s::ResumeInit() {
	return 0;
}

void Sheet_SoulCrystalhole_s::write_to_pbmsg(::proto_ff::Sheet_SoulCrystalhole & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulCrystalhole_List.size(); ++i) {
		::proto_ff::E_SoulCrystalhole* temp_e_soulcrystalhole_list = msg.add_e_soulcrystalhole_list();
		E_SoulCrystalhole_List[i].write_to_pbmsg(*temp_e_soulcrystalhole_list);
	}
}

void Sheet_SoulCrystalhole_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulCrystalhole & msg) {
	E_SoulCrystalhole_List.resize((int)msg.e_soulcrystalhole_list_size() > (int)E_SoulCrystalhole_List.max_size() ? E_SoulCrystalhole_List.max_size() : msg.e_soulcrystalhole_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulCrystalhole_List.size(); ++i) {
		const ::proto_ff::E_SoulCrystalhole & temp_e_soulcrystalhole_list = msg.e_soulcrystalhole_list(i);
		E_SoulCrystalhole_List[i].read_from_pbmsg(temp_e_soulcrystalhole_list);
	}
}

E_SoulFusionFusionDesc_s::E_SoulFusionFusionDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulFusionFusionDesc_s::CreateInit() {
	m_star = (int32_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_SoulFusionFusionDesc_s::ResumeInit() {
	return 0;
}

void E_SoulFusionFusionDesc_s::write_to_pbmsg(::proto_ff::E_SoulFusionFusionDesc & msg) const {
	msg.set_m_star((int32_t)m_star);
	msg.set_m_quality((int32_t)m_quality);
}

void E_SoulFusionFusionDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulFusionFusionDesc & msg) {
	m_star = msg.m_star();
	m_quality = msg.m_quality();
}

E_SoulFusion_s::E_SoulFusion_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulFusion_s::CreateInit() {
	m_id = (int32_t)0;
	m_fusiontype = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	m_condition = (int32_t)0;
	m_qualityget = (int32_t)0;
	m_starget = (int32_t)0;
	m_attributeber = (int32_t)0;
	return 0;
}

int E_SoulFusion_s::ResumeInit() {
	return 0;
}

void E_SoulFusion_s::write_to_pbmsg(::proto_ff::E_SoulFusion & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_fusiontype((int32_t)m_fusiontype);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_condition((int32_t)m_condition);
	msg.set_m_qualityget((int32_t)m_qualityget);
	msg.set_m_starget((int32_t)m_starget);
	msg.set_m_attributeber((int32_t)m_attributeber);
	for(int32_t i = 0; i < (int32_t)m_fusion.size(); ++i) {
		::proto_ff::E_SoulFusionFusionDesc* temp_m_fusion = msg.add_m_fusion();
		m_fusion[i].write_to_pbmsg(*temp_m_fusion);
	}
}

void E_SoulFusion_s::read_from_pbmsg(const ::proto_ff::E_SoulFusion & msg) {
	m_id = msg.m_id();
	m_fusiontype = msg.m_fusiontype();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_condition = msg.m_condition();
	m_qualityget = msg.m_qualityget();
	m_starget = msg.m_starget();
	m_attributeber = msg.m_attributeber();
	m_fusion.resize((int)msg.m_fusion_size() > (int)m_fusion.max_size() ? m_fusion.max_size() : msg.m_fusion_size());
	for(int32_t i = 0; i < (int32_t)m_fusion.size(); ++i) {
		const ::proto_ff::E_SoulFusionFusionDesc & temp_m_fusion = msg.m_fusion(i);
		m_fusion[i].read_from_pbmsg(temp_m_fusion);
	}
}

Sheet_SoulFusion_s::Sheet_SoulFusion_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulFusion_s::CreateInit() {
	return 0;
}

int Sheet_SoulFusion_s::ResumeInit() {
	return 0;
}

void Sheet_SoulFusion_s::write_to_pbmsg(::proto_ff::Sheet_SoulFusion & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulFusion_List.size(); ++i) {
		::proto_ff::E_SoulFusion* temp_e_soulfusion_list = msg.add_e_soulfusion_list();
		E_SoulFusion_List[i].write_to_pbmsg(*temp_e_soulfusion_list);
	}
}

void Sheet_SoulFusion_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulFusion & msg) {
	E_SoulFusion_List.resize((int)msg.e_soulfusion_list_size() > (int)E_SoulFusion_List.max_size() ? E_SoulFusion_List.max_size() : msg.e_soulfusion_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulFusion_List.size(); ++i) {
		const ::proto_ff::E_SoulFusion & temp_e_soulfusion_list = msg.e_soulfusion_list(i);
		E_SoulFusion_List[i].read_from_pbmsg(temp_e_soulfusion_list);
	}
}

E_SoulBone_s::E_SoulBone_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulBone_s::CreateInit() {
	m_id = (int32_t)0;
	m_position = (int32_t)0;
	m_type = (int32_t)0;
	m_awakening = (int32_t)0;
	m_awakeningtime = (int32_t)0;
	m_awakeningnum = (int32_t)0;
	m_modelid = (int32_t)0;
	return 0;
}

int E_SoulBone_s::ResumeInit() {
	return 0;
}

void E_SoulBone_s::write_to_pbmsg(::proto_ff::E_SoulBone & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_awakening((int32_t)m_awakening);
	msg.set_m_awakeningtime((int32_t)m_awakeningtime);
	msg.set_m_awakeningnum((int32_t)m_awakeningnum);
	msg.set_m_modelid((int32_t)m_modelid);
}

void E_SoulBone_s::read_from_pbmsg(const ::proto_ff::E_SoulBone & msg) {
	m_id = msg.m_id();
	m_position = msg.m_position();
	m_type = msg.m_type();
	m_awakening = msg.m_awakening();
	m_awakeningtime = msg.m_awakeningtime();
	m_awakeningnum = msg.m_awakeningnum();
	m_modelid = msg.m_modelid();
}

Sheet_SoulBone_s::Sheet_SoulBone_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulBone_s::CreateInit() {
	return 0;
}

int Sheet_SoulBone_s::ResumeInit() {
	return 0;
}

void Sheet_SoulBone_s::write_to_pbmsg(::proto_ff::Sheet_SoulBone & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulBone_List.size(); ++i) {
		::proto_ff::E_SoulBone* temp_e_soulbone_list = msg.add_e_soulbone_list();
		E_SoulBone_List[i].write_to_pbmsg(*temp_e_soulbone_list);
	}
}

void Sheet_SoulBone_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulBone & msg) {
	E_SoulBone_List.resize((int)msg.e_soulbone_list_size() > (int)E_SoulBone_List.max_size() ? E_SoulBone_List.max_size() : msg.e_soulbone_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulBone_List.size(); ++i) {
		const ::proto_ff::E_SoulBone & temp_e_soulbone_list = msg.e_soulbone_list(i);
		E_SoulBone_List[i].read_from_pbmsg(temp_e_soulbone_list);
	}
}

E_SoulBoneequip_s::E_SoulBoneequip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulBoneequip_s::CreateInit() {
	m_equipid = (int32_t)0;
	m_part = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	return 0;
}

int E_SoulBoneequip_s::ResumeInit() {
	return 0;
}

void E_SoulBoneequip_s::write_to_pbmsg(::proto_ff::E_SoulBoneequip & msg) const {
	msg.set_m_equipid((int32_t)m_equipid);
	msg.set_m_name(m_name.data());
	msg.set_m_part((int32_t)m_part);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
}

void E_SoulBoneequip_s::read_from_pbmsg(const ::proto_ff::E_SoulBoneequip & msg) {
	m_equipid = msg.m_equipid();
	m_name = msg.m_name();
	m_part = msg.m_part();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
}

Sheet_SoulBoneequip_s::Sheet_SoulBoneequip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulBoneequip_s::CreateInit() {
	return 0;
}

int Sheet_SoulBoneequip_s::ResumeInit() {
	return 0;
}

void Sheet_SoulBoneequip_s::write_to_pbmsg(::proto_ff::Sheet_SoulBoneequip & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulBoneequip_List.size(); ++i) {
		::proto_ff::E_SoulBoneequip* temp_e_soulboneequip_list = msg.add_e_soulboneequip_list();
		E_SoulBoneequip_List[i].write_to_pbmsg(*temp_e_soulboneequip_list);
	}
}

void Sheet_SoulBoneequip_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulBoneequip & msg) {
	E_SoulBoneequip_List.resize((int)msg.e_soulboneequip_list_size() > (int)E_SoulBoneequip_List.max_size() ? E_SoulBoneequip_List.max_size() : msg.e_soulboneequip_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulBoneequip_List.size(); ++i) {
		const ::proto_ff::E_SoulBoneequip & temp_e_soulboneequip_list = msg.e_soulboneequip_list(i);
		E_SoulBoneequip_List[i].read_from_pbmsg(temp_e_soulboneequip_list);
	}
}

E_SoulBoneskillPassiveDesc_s::E_SoulBoneskillPassiveDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulBoneskillPassiveDesc_s::CreateInit() {
	m_lv = (int32_t)0;
	m_skill = (int32_t)0;
	return 0;
}

int E_SoulBoneskillPassiveDesc_s::ResumeInit() {
	return 0;
}

void E_SoulBoneskillPassiveDesc_s::write_to_pbmsg(::proto_ff::E_SoulBoneskillPassiveDesc & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_skill((int32_t)m_skill);
}

void E_SoulBoneskillPassiveDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulBoneskillPassiveDesc & msg) {
	m_lv = msg.m_lv();
	m_skill = msg.m_skill();
}

E_SoulBoneskill_s::E_SoulBoneskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulBoneskill_s::CreateInit() {
	m_id = (int32_t)0;
	m_boneid = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	m_activeskill = (int32_t)0;
	m_activeskilllv = (int32_t)0;
	return 0;
}

int E_SoulBoneskill_s::ResumeInit() {
	return 0;
}

void E_SoulBoneskill_s::write_to_pbmsg(::proto_ff::E_SoulBoneskill & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_boneid((int32_t)m_boneid);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_activeskill((int32_t)m_activeskill);
	msg.set_m_activeskilllv((int32_t)m_activeskilllv);
	for(int32_t i = 0; i < (int32_t)m_passive.size(); ++i) {
		::proto_ff::E_SoulBoneskillPassiveDesc* temp_m_passive = msg.add_m_passive();
		m_passive[i].write_to_pbmsg(*temp_m_passive);
	}
}

void E_SoulBoneskill_s::read_from_pbmsg(const ::proto_ff::E_SoulBoneskill & msg) {
	m_id = msg.m_id();
	m_boneid = msg.m_boneid();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_activeskill = msg.m_activeskill();
	m_activeskilllv = msg.m_activeskilllv();
	m_passive.resize((int)msg.m_passive_size() > (int)m_passive.max_size() ? m_passive.max_size() : msg.m_passive_size());
	for(int32_t i = 0; i < (int32_t)m_passive.size(); ++i) {
		const ::proto_ff::E_SoulBoneskillPassiveDesc & temp_m_passive = msg.m_passive(i);
		m_passive[i].read_from_pbmsg(temp_m_passive);
	}
}

Sheet_SoulBoneskill_s::Sheet_SoulBoneskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulBoneskill_s::CreateInit() {
	return 0;
}

int Sheet_SoulBoneskill_s::ResumeInit() {
	return 0;
}

void Sheet_SoulBoneskill_s::write_to_pbmsg(::proto_ff::Sheet_SoulBoneskill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulBoneskill_List.size(); ++i) {
		::proto_ff::E_SoulBoneskill* temp_e_soulboneskill_list = msg.add_e_soulboneskill_list();
		E_SoulBoneskill_List[i].write_to_pbmsg(*temp_e_soulboneskill_list);
	}
}

void Sheet_SoulBoneskill_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulBoneskill & msg) {
	E_SoulBoneskill_List.resize((int)msg.e_soulboneskill_list_size() > (int)E_SoulBoneskill_List.max_size() ? E_SoulBoneskill_List.max_size() : msg.e_soulboneskill_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulBoneskill_List.size(); ++i) {
		const ::proto_ff::E_SoulBoneskill & temp_e_soulboneskill_list = msg.e_soulboneskill_list(i);
		E_SoulBoneskill_List[i].read_from_pbmsg(temp_e_soulboneskill_list);
	}
}

E_SoulBonekill_s::E_SoulBonekill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulBonekill_s::CreateInit() {
	m_lv = (int32_t)0;
	m_killboss = (int32_t)0;
	return 0;
}

int E_SoulBonekill_s::ResumeInit() {
	return 0;
}

void E_SoulBonekill_s::write_to_pbmsg(::proto_ff::E_SoulBonekill & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_killboss((int32_t)m_killboss);
}

void E_SoulBonekill_s::read_from_pbmsg(const ::proto_ff::E_SoulBonekill & msg) {
	m_lv = msg.m_lv();
	m_killboss = msg.m_killboss();
}

Sheet_SoulBonekill_s::Sheet_SoulBonekill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulBonekill_s::CreateInit() {
	return 0;
}

int Sheet_SoulBonekill_s::ResumeInit() {
	return 0;
}

void Sheet_SoulBonekill_s::write_to_pbmsg(::proto_ff::Sheet_SoulBonekill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulBonekill_List.size(); ++i) {
		::proto_ff::E_SoulBonekill* temp_e_soulbonekill_list = msg.add_e_soulbonekill_list();
		E_SoulBonekill_List[i].write_to_pbmsg(*temp_e_soulbonekill_list);
	}
}

void Sheet_SoulBonekill_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulBonekill & msg) {
	E_SoulBonekill_List.resize((int)msg.e_soulbonekill_list_size() > (int)E_SoulBonekill_List.max_size() ? E_SoulBonekill_List.max_size() : msg.e_soulbonekill_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulBonekill_List.size(); ++i) {
		const ::proto_ff::E_SoulBonekill & temp_e_soulbonekill_list = msg.e_soulbonekill_list(i);
		E_SoulBonekill_List[i].read_from_pbmsg(temp_e_soulbonekill_list);
	}
}

E_SoulBonestrongTypeDesc_s::E_SoulBonestrongTypeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulBonestrongTypeDesc_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_SoulBonestrongTypeDesc_s::ResumeInit() {
	return 0;
}

void E_SoulBonestrongTypeDesc_s::write_to_pbmsg(::proto_ff::E_SoulBonestrongTypeDesc & msg) const {
	msg.set_m_num(m_num.data());
	msg.set_m_id((int32_t)m_id);
}

void E_SoulBonestrongTypeDesc_s::read_from_pbmsg(const ::proto_ff::E_SoulBonestrongTypeDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_SoulBonestrong_s::E_SoulBonestrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SoulBonestrong_s::CreateInit() {
	m_id = (int32_t)0;
	m_position = (int32_t)0;
	m_srtongup = (int32_t)0;
	return 0;
}

int E_SoulBonestrong_s::ResumeInit() {
	return 0;
}

void E_SoulBonestrong_s::write_to_pbmsg(::proto_ff::E_SoulBonestrong & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_srtongup((int32_t)m_srtongup);
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		::proto_ff::E_SoulBonestrongTypeDesc* temp_m_type = msg.add_m_type();
		m_type[i].write_to_pbmsg(*temp_m_type);
	}
}

void E_SoulBonestrong_s::read_from_pbmsg(const ::proto_ff::E_SoulBonestrong & msg) {
	m_id = msg.m_id();
	m_position = msg.m_position();
	m_srtongup = msg.m_srtongup();
	m_type.resize((int)msg.m_type_size() > (int)m_type.max_size() ? m_type.max_size() : msg.m_type_size());
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		const ::proto_ff::E_SoulBonestrongTypeDesc & temp_m_type = msg.m_type(i);
		m_type[i].read_from_pbmsg(temp_m_type);
	}
}

Sheet_SoulBonestrong_s::Sheet_SoulBonestrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SoulBonestrong_s::CreateInit() {
	return 0;
}

int Sheet_SoulBonestrong_s::ResumeInit() {
	return 0;
}

void Sheet_SoulBonestrong_s::write_to_pbmsg(::proto_ff::Sheet_SoulBonestrong & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SoulBonestrong_List.size(); ++i) {
		::proto_ff::E_SoulBonestrong* temp_e_soulbonestrong_list = msg.add_e_soulbonestrong_list();
		E_SoulBonestrong_List[i].write_to_pbmsg(*temp_e_soulbonestrong_list);
	}
}

void Sheet_SoulBonestrong_s::read_from_pbmsg(const ::proto_ff::Sheet_SoulBonestrong & msg) {
	E_SoulBonestrong_List.resize((int)msg.e_soulbonestrong_list_size() > (int)E_SoulBonestrong_List.max_size() ? E_SoulBonestrong_List.max_size() : msg.e_soulbonestrong_list_size());
	for(int32_t i = 0; i < (int32_t)E_SoulBonestrong_List.size(); ++i) {
		const ::proto_ff::E_SoulBonestrong & temp_e_soulbonestrong_list = msg.e_soulbonestrong_list(i);
		E_SoulBonestrong_List[i].read_from_pbmsg(temp_e_soulbonestrong_list);
	}
}

}
