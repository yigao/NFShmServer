#include "E_Marry_s.h"

namespace proto_ff_s {

E_MarryMarriage_s::E_MarryMarriage_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryMarriage_s::CreateInit() {
	m_id = (int32_t)0;
	m_banquet = (int32_t)0;
	m_cruise = (int32_t)0;
	m_money = (int32_t)0;
	m_price = (int32_t)0;
	m_firstboxid = (int32_t)0;
	m_firstaddpower = (int32_t)0;
	m_repeatboxid = (int32_t)0;
	m_repeataddpower = (int32_t)0;
	m_titleid = (int32_t)0;
	m_equip = (int32_t)0;
	m_freeprice = (int32_t)0;
	return 0;
}

int E_MarryMarriage_s::ResumeInit() {
	return 0;
}

void E_MarryMarriage_s::write_to_pbmsg(::proto_ff::E_MarryMarriage & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_weddingname(m_weddingname.data());
	msg.set_m_banquet((int32_t)m_banquet);
	msg.set_m_cruise((int32_t)m_cruise);
	msg.set_m_money((int32_t)m_money);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_firstboxid((int32_t)m_firstboxid);
	msg.set_m_firstaddpower((int32_t)m_firstaddpower);
	msg.set_m_repeatboxid((int32_t)m_repeatboxid);
	msg.set_m_repeataddpower((int32_t)m_repeataddpower);
	msg.set_m_titleid((int32_t)m_titleid);
	msg.set_m_equip((int32_t)m_equip);
	msg.set_m_freeprice((int32_t)m_freeprice);
}

void E_MarryMarriage_s::read_from_pbmsg(const ::proto_ff::E_MarryMarriage & msg) {
	m_id = msg.m_id();
	m_weddingname = msg.m_weddingname();
	m_banquet = msg.m_banquet();
	m_cruise = msg.m_cruise();
	m_money = msg.m_money();
	m_price = msg.m_price();
	m_firstboxid = msg.m_firstboxid();
	m_firstaddpower = msg.m_firstaddpower();
	m_repeatboxid = msg.m_repeatboxid();
	m_repeataddpower = msg.m_repeataddpower();
	m_titleid = msg.m_titleid();
	m_equip = msg.m_equip();
	m_freeprice = msg.m_freeprice();
}

Sheet_MarryMarriage_s::Sheet_MarryMarriage_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarryMarriage_s::CreateInit() {
	return 0;
}

int Sheet_MarryMarriage_s::ResumeInit() {
	return 0;
}

void Sheet_MarryMarriage_s::write_to_pbmsg(::proto_ff::Sheet_MarryMarriage & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarryMarriage_List.size(); ++i) {
		::proto_ff::E_MarryMarriage* temp_e_marrymarriage_list = msg.add_e_marrymarriage_list();
		E_MarryMarriage_List[i].write_to_pbmsg(*temp_e_marrymarriage_list);
	}
}

void Sheet_MarryMarriage_s::read_from_pbmsg(const ::proto_ff::Sheet_MarryMarriage & msg) {
	E_MarryMarriage_List.resize((int)msg.e_marrymarriage_list_size() > (int)E_MarryMarriage_List.max_size() ? E_MarryMarriage_List.max_size() : msg.e_marrymarriage_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarryMarriage_List.size(); ++i) {
		const ::proto_ff::E_MarryMarriage & temp_e_marrymarriage_list = msg.e_marrymarriage_list(i);
		E_MarryMarriage_List[i].read_from_pbmsg(temp_e_marrymarriage_list);
	}
}

E_MarryBanquet_s::E_MarryBanquet_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryBanquet_s::CreateInit() {
	m_id = (int32_t)0;
	m_pre_broad_sec = (int32_t)0;
	m_broad_inter_sec = (int32_t)0;
	return 0;
}

int E_MarryBanquet_s::ResumeInit() {
	return 0;
}

void E_MarryBanquet_s::write_to_pbmsg(::proto_ff::E_MarryBanquet & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_begintime(m_begintime.data());
	msg.set_m_finishtime(m_finishtime.data());
	msg.set_m_pre_broad_sec((int32_t)m_pre_broad_sec);
	msg.set_m_broad_inter_sec((int32_t)m_broad_inter_sec);
}

void E_MarryBanquet_s::read_from_pbmsg(const ::proto_ff::E_MarryBanquet & msg) {
	m_id = msg.m_id();
	m_begintime = msg.m_begintime();
	m_finishtime = msg.m_finishtime();
	m_pre_broad_sec = msg.m_pre_broad_sec();
	m_broad_inter_sec = msg.m_broad_inter_sec();
}

Sheet_MarryBanquet_s::Sheet_MarryBanquet_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarryBanquet_s::CreateInit() {
	return 0;
}

int Sheet_MarryBanquet_s::ResumeInit() {
	return 0;
}

void Sheet_MarryBanquet_s::write_to_pbmsg(::proto_ff::Sheet_MarryBanquet & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarryBanquet_List.size(); ++i) {
		::proto_ff::E_MarryBanquet* temp_e_marrybanquet_list = msg.add_e_marrybanquet_list();
		E_MarryBanquet_List[i].write_to_pbmsg(*temp_e_marrybanquet_list);
	}
}

void Sheet_MarryBanquet_s::read_from_pbmsg(const ::proto_ff::Sheet_MarryBanquet & msg) {
	E_MarryBanquet_List.resize((int)msg.e_marrybanquet_list_size() > (int)E_MarryBanquet_List.max_size() ? E_MarryBanquet_List.max_size() : msg.e_marrybanquet_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarryBanquet_List.size(); ++i) {
		const ::proto_ff::E_MarryBanquet & temp_e_marrybanquet_list = msg.e_marrybanquet_list(i);
		E_MarryBanquet_List[i].read_from_pbmsg(temp_e_marrybanquet_list);
	}
}

E_MarryLocklvAttributeDesc_s::E_MarryLocklvAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryLocklvAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MarryLocklvAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MarryLocklvAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MarryLocklvAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MarryLocklvAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MarryLocklvAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MarryLocklvSkillDesc_s::E_MarryLocklvSkillDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryLocklvSkillDesc_s::CreateInit() {
	m_lv = (int32_t)0;
	m_skill = (int32_t)0;
	return 0;
}

int E_MarryLocklvSkillDesc_s::ResumeInit() {
	return 0;
}

void E_MarryLocklvSkillDesc_s::write_to_pbmsg(::proto_ff::E_MarryLocklvSkillDesc & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_skill((int32_t)m_skill);
}

void E_MarryLocklvSkillDesc_s::read_from_pbmsg(const ::proto_ff::E_MarryLocklvSkillDesc & msg) {
	m_lv = msg.m_lv();
	m_skill = msg.m_skill();
}

E_MarryLocklv_s::E_MarryLocklv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryLocklv_s::CreateInit() {
	m_id = (int32_t)0;
	m_lv = (int32_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_MarryLocklv_s::ResumeInit() {
	return 0;
}

void E_MarryLocklv_s::write_to_pbmsg(::proto_ff::E_MarryLocklv & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int32_t)m_exp);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MarryLocklvAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		::proto_ff::E_MarryLocklvSkillDesc* temp_m_skill = msg.add_m_skill();
		m_skill[i].write_to_pbmsg(*temp_m_skill);
	}
}

void E_MarryLocklv_s::read_from_pbmsg(const ::proto_ff::E_MarryLocklv & msg) {
	m_id = msg.m_id();
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_MarryLocklvAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_skill.resize((int)msg.m_skill_size() > (int)m_skill.max_size() ? m_skill.max_size() : msg.m_skill_size());
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		const ::proto_ff::E_MarryLocklvSkillDesc & temp_m_skill = msg.m_skill(i);
		m_skill[i].read_from_pbmsg(temp_m_skill);
	}
}

Sheet_MarryLocklv_s::Sheet_MarryLocklv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarryLocklv_s::CreateInit() {
	return 0;
}

int Sheet_MarryLocklv_s::ResumeInit() {
	return 0;
}

void Sheet_MarryLocklv_s::write_to_pbmsg(::proto_ff::Sheet_MarryLocklv & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarryLocklv_List.size(); ++i) {
		::proto_ff::E_MarryLocklv* temp_e_marrylocklv_list = msg.add_e_marrylocklv_list();
		E_MarryLocklv_List[i].write_to_pbmsg(*temp_e_marrylocklv_list);
	}
}

void Sheet_MarryLocklv_s::read_from_pbmsg(const ::proto_ff::Sheet_MarryLocklv & msg) {
	E_MarryLocklv_List.resize((int)msg.e_marrylocklv_list_size() > (int)E_MarryLocklv_List.max_size() ? E_MarryLocklv_List.max_size() : msg.e_marrylocklv_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarryLocklv_List.size(); ++i) {
		const ::proto_ff::E_MarryLocklv & temp_e_marrylocklv_list = msg.e_marrylocklv_list(i);
		E_MarryLocklv_List[i].read_from_pbmsg(temp_e_marrylocklv_list);
	}
}

E_MarryLockskillSkillDesc_s::E_MarryLockskillSkillDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryLockskillSkillDesc_s::CreateInit() {
	m_grade = (int32_t)0;
	m_lv = (int32_t)0;
	return 0;
}

int E_MarryLockskillSkillDesc_s::ResumeInit() {
	return 0;
}

void E_MarryLockskillSkillDesc_s::write_to_pbmsg(::proto_ff::E_MarryLockskillSkillDesc & msg) const {
	msg.set_m_grade((int32_t)m_grade);
	msg.set_m_lv((int32_t)m_lv);
}

void E_MarryLockskillSkillDesc_s::read_from_pbmsg(const ::proto_ff::E_MarryLockskillSkillDesc & msg) {
	m_grade = msg.m_grade();
	m_lv = msg.m_lv();
}

E_MarryLockskill_s::E_MarryLockskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryLockskill_s::CreateInit() {
	m_id = (int32_t)0;
	m_order = (int32_t)0;
	m_skillid = (int32_t)0;
	return 0;
}

int E_MarryLockskill_s::ResumeInit() {
	return 0;
}

void E_MarryLockskill_s::write_to_pbmsg(::proto_ff::E_MarryLockskill & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_order((int32_t)m_order);
	msg.set_m_skillid((int32_t)m_skillid);
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		::proto_ff::E_MarryLockskillSkillDesc* temp_m_skill = msg.add_m_skill();
		m_skill[i].write_to_pbmsg(*temp_m_skill);
	}
}

void E_MarryLockskill_s::read_from_pbmsg(const ::proto_ff::E_MarryLockskill & msg) {
	m_id = msg.m_id();
	m_order = msg.m_order();
	m_skillid = msg.m_skillid();
	m_skill.resize((int)msg.m_skill_size() > (int)m_skill.max_size() ? m_skill.max_size() : msg.m_skill_size());
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		const ::proto_ff::E_MarryLockskillSkillDesc & temp_m_skill = msg.m_skill(i);
		m_skill[i].read_from_pbmsg(temp_m_skill);
	}
}

Sheet_MarryLockskill_s::Sheet_MarryLockskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarryLockskill_s::CreateInit() {
	return 0;
}

int Sheet_MarryLockskill_s::ResumeInit() {
	return 0;
}

void Sheet_MarryLockskill_s::write_to_pbmsg(::proto_ff::Sheet_MarryLockskill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarryLockskill_List.size(); ++i) {
		::proto_ff::E_MarryLockskill* temp_e_marrylockskill_list = msg.add_e_marrylockskill_list();
		E_MarryLockskill_List[i].write_to_pbmsg(*temp_e_marrylockskill_list);
	}
}

void Sheet_MarryLockskill_s::read_from_pbmsg(const ::proto_ff::Sheet_MarryLockskill & msg) {
	E_MarryLockskill_List.resize((int)msg.e_marrylockskill_list_size() > (int)E_MarryLockskill_List.max_size() ? E_MarryLockskill_List.max_size() : msg.e_marrylockskill_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarryLockskill_List.size(); ++i) {
		const ::proto_ff::E_MarryLockskill & temp_e_marrylockskill_list = msg.e_marrylockskill_list(i);
		E_MarryLockskill_List[i].read_from_pbmsg(temp_e_marrylockskill_list);
	}
}

E_MarryChildAttributeDesc_s::E_MarryChildAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryChildAttributeDesc_s::CreateInit() {
	m_value = (int64_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MarryChildAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MarryChildAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MarryChildAttributeDesc & msg) const {
	msg.set_m_value((int64_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MarryChildAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MarryChildAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MarryChildStariattributeDesc_s::E_MarryChildStariattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryChildStariattributeDesc_s::CreateInit() {
	m_value = (int64_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MarryChildStariattributeDesc_s::ResumeInit() {
	return 0;
}

void E_MarryChildStariattributeDesc_s::write_to_pbmsg(::proto_ff::E_MarryChildStariattributeDesc & msg) const {
	msg.set_m_value((int64_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MarryChildStariattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MarryChildStariattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MarryChild_s::E_MarryChild_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryChild_s::CreateInit() {
	m_childid = (int64_t)0;
	m_itemid = (int64_t)0;
	m_childquality = (int32_t)0;
	m_handz = (int32_t)0;
	m_starid = (int64_t)0;
	return 0;
}

int E_MarryChild_s::ResumeInit() {
	return 0;
}

void E_MarryChild_s::write_to_pbmsg(::proto_ff::E_MarryChild & msg) const {
	msg.set_m_childid((int64_t)m_childid);
	msg.set_m_itemid((int64_t)m_itemid);
	msg.set_m_childname(m_childname.data());
	msg.set_m_childquality((int32_t)m_childquality);
	msg.set_m_handz((int32_t)m_handz);
	msg.set_m_handzname(m_handzname.data());
	msg.set_m_skillid(m_skillid.data());
	msg.set_m_starid((int64_t)m_starid);
	msg.set_m_starnum(m_starnum.data());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MarryChildAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_stariattribute.size(); ++i) {
		::proto_ff::E_MarryChildStariattributeDesc* temp_m_stariattribute = msg.add_m_stariattribute();
		m_stariattribute[i].write_to_pbmsg(*temp_m_stariattribute);
	}
}

void E_MarryChild_s::read_from_pbmsg(const ::proto_ff::E_MarryChild & msg) {
	m_childid = msg.m_childid();
	m_itemid = msg.m_itemid();
	m_childname = msg.m_childname();
	m_childquality = msg.m_childquality();
	m_handz = msg.m_handz();
	m_handzname = msg.m_handzname();
	m_skillid = msg.m_skillid();
	m_starid = msg.m_starid();
	m_starnum = msg.m_starnum();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_MarryChildAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_stariattribute.resize((int)msg.m_stariattribute_size() > (int)m_stariattribute.max_size() ? m_stariattribute.max_size() : msg.m_stariattribute_size());
	for(int32_t i = 0; i < (int32_t)m_stariattribute.size(); ++i) {
		const ::proto_ff::E_MarryChildStariattributeDesc & temp_m_stariattribute = msg.m_stariattribute(i);
		m_stariattribute[i].read_from_pbmsg(temp_m_stariattribute);
	}
}

Sheet_MarryChild_s::Sheet_MarryChild_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarryChild_s::CreateInit() {
	return 0;
}

int Sheet_MarryChild_s::ResumeInit() {
	return 0;
}

void Sheet_MarryChild_s::write_to_pbmsg(::proto_ff::Sheet_MarryChild & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarryChild_List.size(); ++i) {
		::proto_ff::E_MarryChild* temp_e_marrychild_list = msg.add_e_marrychild_list();
		E_MarryChild_List[i].write_to_pbmsg(*temp_e_marrychild_list);
	}
}

void Sheet_MarryChild_s::read_from_pbmsg(const ::proto_ff::Sheet_MarryChild & msg) {
	E_MarryChild_List.resize((int)msg.e_marrychild_list_size() > (int)E_MarryChild_List.max_size() ? E_MarryChild_List.max_size() : msg.e_marrychild_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarryChild_List.size(); ++i) {
		const ::proto_ff::E_MarryChild & temp_e_marrychild_list = msg.e_marrychild_list(i);
		E_MarryChild_List[i].read_from_pbmsg(temp_e_marrychild_list);
	}
}

E_MarryChildvalue_s::E_MarryChildvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryChildvalue_s::CreateInit() {
	m_id = (int64_t)0;
	return 0;
}

int E_MarryChildvalue_s::ResumeInit() {
	return 0;
}

void E_MarryChildvalue_s::write_to_pbmsg(::proto_ff::E_MarryChildvalue & msg) const {
	msg.set_m_id((int64_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_lvvalue.size(); ++i) {
		msg.add_m_lvvalue((int32_t)m_lvvalue[i]);
	}
}

void E_MarryChildvalue_s::read_from_pbmsg(const ::proto_ff::E_MarryChildvalue & msg) {
	m_id = msg.m_id();
	m_lvvalue.resize((int)msg.m_lvvalue_size() > (int)m_lvvalue.max_size() ? m_lvvalue.max_size() : msg.m_lvvalue_size());
	for(int32_t i = 0; i < (int32_t)m_lvvalue.size(); ++i) {
		m_lvvalue[i] = msg.m_lvvalue(i);
	}
}

Sheet_MarryChildvalue_s::Sheet_MarryChildvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarryChildvalue_s::CreateInit() {
	return 0;
}

int Sheet_MarryChildvalue_s::ResumeInit() {
	return 0;
}

void Sheet_MarryChildvalue_s::write_to_pbmsg(::proto_ff::Sheet_MarryChildvalue & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarryChildvalue_List.size(); ++i) {
		::proto_ff::E_MarryChildvalue* temp_e_marrychildvalue_list = msg.add_e_marrychildvalue_list();
		E_MarryChildvalue_List[i].write_to_pbmsg(*temp_e_marrychildvalue_list);
	}
}

void Sheet_MarryChildvalue_s::read_from_pbmsg(const ::proto_ff::Sheet_MarryChildvalue & msg) {
	E_MarryChildvalue_List.resize((int)msg.e_marrychildvalue_list_size() > (int)E_MarryChildvalue_List.max_size() ? E_MarryChildvalue_List.max_size() : msg.e_marrychildvalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarryChildvalue_List.size(); ++i) {
		const ::proto_ff::E_MarryChildvalue & temp_e_marrychildvalue_list = msg.e_marrychildvalue_list(i);
		E_MarryChildvalue_List[i].read_from_pbmsg(temp_e_marrychildvalue_list);
	}
}

E_MarryChildexpGradeDesc_s::E_MarryChildexpGradeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryChildexpGradeDesc_s::CreateInit() {
	m_exp = (int32_t)0;
	m_lv = (int32_t)0;
	return 0;
}

int E_MarryChildexpGradeDesc_s::ResumeInit() {
	return 0;
}

void E_MarryChildexpGradeDesc_s::write_to_pbmsg(::proto_ff::E_MarryChildexpGradeDesc & msg) const {
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_lv((int32_t)m_lv);
}

void E_MarryChildexpGradeDesc_s::read_from_pbmsg(const ::proto_ff::E_MarryChildexpGradeDesc & msg) {
	m_exp = msg.m_exp();
	m_lv = msg.m_lv();
}

E_MarryChildexp_s::E_MarryChildexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryChildexp_s::CreateInit() {
	m_lv = (int32_t)0;
	return 0;
}

int E_MarryChildexp_s::ResumeInit() {
	return 0;
}

void E_MarryChildexp_s::write_to_pbmsg(::proto_ff::E_MarryChildexp & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	for(int32_t i = 0; i < (int32_t)m_grade.size(); ++i) {
		::proto_ff::E_MarryChildexpGradeDesc* temp_m_grade = msg.add_m_grade();
		m_grade[i].write_to_pbmsg(*temp_m_grade);
	}
}

void E_MarryChildexp_s::read_from_pbmsg(const ::proto_ff::E_MarryChildexp & msg) {
	m_lv = msg.m_lv();
	m_grade.resize((int)msg.m_grade_size() > (int)m_grade.max_size() ? m_grade.max_size() : msg.m_grade_size());
	for(int32_t i = 0; i < (int32_t)m_grade.size(); ++i) {
		const ::proto_ff::E_MarryChildexpGradeDesc & temp_m_grade = msg.m_grade(i);
		m_grade[i].read_from_pbmsg(temp_m_grade);
	}
}

Sheet_MarryChildexp_s::Sheet_MarryChildexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarryChildexp_s::CreateInit() {
	return 0;
}

int Sheet_MarryChildexp_s::ResumeInit() {
	return 0;
}

void Sheet_MarryChildexp_s::write_to_pbmsg(::proto_ff::Sheet_MarryChildexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarryChildexp_List.size(); ++i) {
		::proto_ff::E_MarryChildexp* temp_e_marrychildexp_list = msg.add_e_marrychildexp_list();
		E_MarryChildexp_List[i].write_to_pbmsg(*temp_e_marrychildexp_list);
	}
}

void Sheet_MarryChildexp_s::read_from_pbmsg(const ::proto_ff::Sheet_MarryChildexp & msg) {
	E_MarryChildexp_List.resize((int)msg.e_marrychildexp_list_size() > (int)E_MarryChildexp_List.max_size() ? E_MarryChildexp_List.max_size() : msg.e_marrychildexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarryChildexp_List.size(); ++i) {
		const ::proto_ff::E_MarryChildexp & temp_e_marrychildexp_list = msg.e_marrychildexp_list(i);
		E_MarryChildexp_List[i].read_from_pbmsg(temp_e_marrychildexp_list);
	}
}

E_MarryExpressAttributeDesc_s::E_MarryExpressAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryExpressAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MarryExpressAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_MarryExpressAttributeDesc_s::write_to_pbmsg(::proto_ff::E_MarryExpressAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MarryExpressAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_MarryExpressAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MarryExpress_s::E_MarryExpress_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryExpress_s::CreateInit() {
	m_lv = (int32_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_MarryExpress_s::ResumeInit() {
	return 0;
}

void E_MarryExpress_s::write_to_pbmsg(::proto_ff::E_MarryExpress & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int32_t)m_exp);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_MarryExpressAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_MarryExpress_s::read_from_pbmsg(const ::proto_ff::E_MarryExpress & msg) {
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_MarryExpressAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_MarryExpress_s::Sheet_MarryExpress_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarryExpress_s::CreateInit() {
	return 0;
}

int Sheet_MarryExpress_s::ResumeInit() {
	return 0;
}

void Sheet_MarryExpress_s::write_to_pbmsg(::proto_ff::Sheet_MarryExpress & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarryExpress_List.size(); ++i) {
		::proto_ff::E_MarryExpress* temp_e_marryexpress_list = msg.add_e_marryexpress_list();
		E_MarryExpress_List[i].write_to_pbmsg(*temp_e_marryexpress_list);
	}
}

void Sheet_MarryExpress_s::read_from_pbmsg(const ::proto_ff::Sheet_MarryExpress & msg) {
	E_MarryExpress_List.resize((int)msg.e_marryexpress_list_size() > (int)E_MarryExpress_List.max_size() ? E_MarryExpress_List.max_size() : msg.e_marryexpress_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarryExpress_List.size(); ++i) {
		const ::proto_ff::E_MarryExpress & temp_e_marryexpress_list = msg.e_marryexpress_list(i);
		E_MarryExpress_List[i].read_from_pbmsg(temp_e_marryexpress_list);
	}
}

E_MarryExpresslanguage_s::E_MarryExpresslanguage_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryExpresslanguage_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_MarryExpresslanguage_s::ResumeInit() {
	return 0;
}

void E_MarryExpresslanguage_s::write_to_pbmsg(::proto_ff::E_MarryExpresslanguage & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_language(m_language.data());
}

void E_MarryExpresslanguage_s::read_from_pbmsg(const ::proto_ff::E_MarryExpresslanguage & msg) {
	m_id = msg.m_id();
	m_language = msg.m_language();
}

Sheet_MarryExpresslanguage_s::Sheet_MarryExpresslanguage_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarryExpresslanguage_s::CreateInit() {
	return 0;
}

int Sheet_MarryExpresslanguage_s::ResumeInit() {
	return 0;
}

void Sheet_MarryExpresslanguage_s::write_to_pbmsg(::proto_ff::Sheet_MarryExpresslanguage & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarryExpresslanguage_List.size(); ++i) {
		::proto_ff::E_MarryExpresslanguage* temp_e_marryexpresslanguage_list = msg.add_e_marryexpresslanguage_list();
		E_MarryExpresslanguage_List[i].write_to_pbmsg(*temp_e_marryexpresslanguage_list);
	}
}

void Sheet_MarryExpresslanguage_s::read_from_pbmsg(const ::proto_ff::Sheet_MarryExpresslanguage & msg) {
	E_MarryExpresslanguage_List.resize((int)msg.e_marryexpresslanguage_list_size() > (int)E_MarryExpresslanguage_List.max_size() ? E_MarryExpresslanguage_List.max_size() : msg.e_marryexpresslanguage_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarryExpresslanguage_List.size(); ++i) {
		const ::proto_ff::E_MarryExpresslanguage & temp_e_marryexpresslanguage_list = msg.e_marryexpresslanguage_list(i);
		E_MarryExpresslanguage_List[i].read_from_pbmsg(temp_e_marryexpresslanguage_list);
	}
}

E_MarryExpressshop_s::E_MarryExpressshop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryExpressshop_s::CreateInit() {
	m_exitem = (int32_t)0;
	m_mallid = (int32_t)0;
	m_exp = (int32_t)0;
	m_expto = (int32_t)0;
	m_broadcastid = (int32_t)0;
	return 0;
}

int E_MarryExpressshop_s::ResumeInit() {
	return 0;
}

void E_MarryExpressshop_s::write_to_pbmsg(::proto_ff::E_MarryExpressshop & msg) const {
	msg.set_m_exitem((int32_t)m_exitem);
	msg.set_m_mallid((int32_t)m_mallid);
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_expto((int32_t)m_expto);
	msg.set_m_broadcastid((int32_t)m_broadcastid);
}

void E_MarryExpressshop_s::read_from_pbmsg(const ::proto_ff::E_MarryExpressshop & msg) {
	m_exitem = msg.m_exitem();
	m_mallid = msg.m_mallid();
	m_exp = msg.m_exp();
	m_expto = msg.m_expto();
	m_broadcastid = msg.m_broadcastid();
}

Sheet_MarryExpressshop_s::Sheet_MarryExpressshop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarryExpressshop_s::CreateInit() {
	return 0;
}

int Sheet_MarryExpressshop_s::ResumeInit() {
	return 0;
}

void Sheet_MarryExpressshop_s::write_to_pbmsg(::proto_ff::Sheet_MarryExpressshop & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarryExpressshop_List.size(); ++i) {
		::proto_ff::E_MarryExpressshop* temp_e_marryexpressshop_list = msg.add_e_marryexpressshop_list();
		E_MarryExpressshop_List[i].write_to_pbmsg(*temp_e_marryexpressshop_list);
	}
}

void Sheet_MarryExpressshop_s::read_from_pbmsg(const ::proto_ff::Sheet_MarryExpressshop & msg) {
	E_MarryExpressshop_List.resize((int)msg.e_marryexpressshop_list_size() > (int)E_MarryExpressshop_List.max_size() ? E_MarryExpressshop_List.max_size() : msg.e_marryexpressshop_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarryExpressshop_List.size(); ++i) {
		const ::proto_ff::E_MarryExpressshop & temp_e_marryexpressshop_list = msg.e_marryexpressshop_list(i);
		E_MarryExpressshop_List[i].read_from_pbmsg(temp_e_marryexpressshop_list);
	}
}

E_MarryConstantTourmonsterDesc_s::E_MarryConstantTourmonsterDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryConstantTourmonsterDesc_s::CreateInit() {
	m_pathid = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_MarryConstantTourmonsterDesc_s::ResumeInit() {
	return 0;
}

void E_MarryConstantTourmonsterDesc_s::write_to_pbmsg(::proto_ff::E_MarryConstantTourmonsterDesc & msg) const {
	msg.set_m_pathid((int32_t)m_pathid);
	msg.set_m_id((int32_t)m_id);
}

void E_MarryConstantTourmonsterDesc_s::read_from_pbmsg(const ::proto_ff::E_MarryConstantTourmonsterDesc & msg) {
	m_pathid = msg.m_pathid();
	m_id = msg.m_id();
}

E_MarryConstant_s::E_MarryConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryConstant_s::CreateInit() {
	m_id = (int32_t)0;
	m_money = (int32_t)0;
	m_price = (int32_t)0;
	m_buyitem = (int32_t)0;
	m_dailyitem = (int32_t)0;
	m_boxitme = (int32_t)0;
	m_interval = (int32_t)0;
	m_lifetime = (int32_t)0;
	m_scale = (int32_t)0;
	m_giveboy = (int32_t)0;
	m_givegirl = (int32_t)0;
	m_xytime = (int32_t)0;
	m_free = (int32_t)0;
	m_buynum = (int32_t)0;
	m_consume = (int32_t)0;
	m_consumenum = (int32_t)0;
	m_marrylv = (int32_t)0;
	m_childtime = (int32_t)0;
	m_lockitem = (int32_t)0;
	m_lockitemexp = (int32_t)0;
	m_childitem = (int32_t)0;
	m_childitemexp = (int32_t)0;
	m_guestprice = (int32_t)0;
	m_guestpricenum = (int32_t)0;
	m_asklimit = (int32_t)0;
	m_hyreward = (int32_t)0;
	m_toursceneid = (int32_t)0;
	m_tourfollowindex = (int32_t)0;
	m_redbagnum = (int32_t)0;
	m_redmoney = (int32_t)0;
	m_redprice = (int32_t)0;
	m_sendredreward = (int32_t)0;
	m_sendrednum = (int32_t)0;
	m_redcollect = (int32_t)0;
	m_redcollectnum = (int32_t)0;
	return 0;
}

int E_MarryConstant_s::ResumeInit() {
	return 0;
}

void E_MarryConstant_s::write_to_pbmsg(::proto_ff::E_MarryConstant & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_money((int32_t)m_money);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_buyitem((int32_t)m_buyitem);
	msg.set_m_dailyitem((int32_t)m_dailyitem);
	msg.set_m_boxitme((int32_t)m_boxitme);
	msg.set_m_interval((int32_t)m_interval);
	msg.set_m_lifetime((int32_t)m_lifetime);
	msg.set_m_scale((int32_t)m_scale);
	msg.set_m_giveboy((int32_t)m_giveboy);
	msg.set_m_givegirl((int32_t)m_givegirl);
	msg.set_m_xytime((int32_t)m_xytime);
	msg.set_m_free((int32_t)m_free);
	msg.set_m_buynum((int32_t)m_buynum);
	msg.set_m_consume((int32_t)m_consume);
	msg.set_m_consumenum((int32_t)m_consumenum);
	msg.set_m_marrylv((int32_t)m_marrylv);
	msg.set_m_childtime((int32_t)m_childtime);
	msg.set_m_lockitem((int32_t)m_lockitem);
	msg.set_m_lockitemexp((int32_t)m_lockitemexp);
	msg.set_m_childitem((int32_t)m_childitem);
	msg.set_m_childitemexp((int32_t)m_childitemexp);
	msg.set_m_guestprice((int32_t)m_guestprice);
	msg.set_m_guestpricenum((int32_t)m_guestpricenum);
	msg.set_m_asklimit((int32_t)m_asklimit);
	msg.set_m_hyreward((int32_t)m_hyreward);
	msg.set_m_toursceneid((int32_t)m_toursceneid);
	msg.set_m_tourfollowindex((int32_t)m_tourfollowindex);
	msg.set_m_hyicon(m_hyicon.data());
	msg.set_m_hyname(m_hyname.data());
	msg.set_m_xyicon(m_xyicon.data());
	msg.set_m_xyname(m_xyname.data());
	msg.set_m_redbagnum((int32_t)m_redbagnum);
	msg.set_m_redmoney((int32_t)m_redmoney);
	msg.set_m_redprice((int32_t)m_redprice);
	msg.set_m_sendredreward((int32_t)m_sendredreward);
	msg.set_m_sendrednum((int32_t)m_sendrednum);
	msg.set_m_redcollect((int32_t)m_redcollect);
	msg.set_m_redcollectnum((int32_t)m_redcollectnum);
	for(int32_t i = 0; i < (int32_t)m_tourmonster.size(); ++i) {
		::proto_ff::E_MarryConstantTourmonsterDesc* temp_m_tourmonster = msg.add_m_tourmonster();
		m_tourmonster[i].write_to_pbmsg(*temp_m_tourmonster);
	}
}

void E_MarryConstant_s::read_from_pbmsg(const ::proto_ff::E_MarryConstant & msg) {
	m_id = msg.m_id();
	m_money = msg.m_money();
	m_price = msg.m_price();
	m_buyitem = msg.m_buyitem();
	m_dailyitem = msg.m_dailyitem();
	m_boxitme = msg.m_boxitme();
	m_interval = msg.m_interval();
	m_lifetime = msg.m_lifetime();
	m_scale = msg.m_scale();
	m_giveboy = msg.m_giveboy();
	m_givegirl = msg.m_givegirl();
	m_xytime = msg.m_xytime();
	m_free = msg.m_free();
	m_buynum = msg.m_buynum();
	m_consume = msg.m_consume();
	m_consumenum = msg.m_consumenum();
	m_marrylv = msg.m_marrylv();
	m_childtime = msg.m_childtime();
	m_lockitem = msg.m_lockitem();
	m_lockitemexp = msg.m_lockitemexp();
	m_childitem = msg.m_childitem();
	m_childitemexp = msg.m_childitemexp();
	m_guestprice = msg.m_guestprice();
	m_guestpricenum = msg.m_guestpricenum();
	m_asklimit = msg.m_asklimit();
	m_hyreward = msg.m_hyreward();
	m_toursceneid = msg.m_toursceneid();
	m_tourfollowindex = msg.m_tourfollowindex();
	m_hyicon = msg.m_hyicon();
	m_hyname = msg.m_hyname();
	m_xyicon = msg.m_xyicon();
	m_xyname = msg.m_xyname();
	m_redbagnum = msg.m_redbagnum();
	m_redmoney = msg.m_redmoney();
	m_redprice = msg.m_redprice();
	m_sendredreward = msg.m_sendredreward();
	m_sendrednum = msg.m_sendrednum();
	m_redcollect = msg.m_redcollect();
	m_redcollectnum = msg.m_redcollectnum();
	m_tourmonster.resize((int)msg.m_tourmonster_size() > (int)m_tourmonster.max_size() ? m_tourmonster.max_size() : msg.m_tourmonster_size());
	for(int32_t i = 0; i < (int32_t)m_tourmonster.size(); ++i) {
		const ::proto_ff::E_MarryConstantTourmonsterDesc & temp_m_tourmonster = msg.m_tourmonster(i);
		m_tourmonster[i].read_from_pbmsg(temp_m_tourmonster);
	}
}

Sheet_MarryConstant_s::Sheet_MarryConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarryConstant_s::CreateInit() {
	return 0;
}

int Sheet_MarryConstant_s::ResumeInit() {
	return 0;
}

void Sheet_MarryConstant_s::write_to_pbmsg(::proto_ff::Sheet_MarryConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarryConstant_List.size(); ++i) {
		::proto_ff::E_MarryConstant* temp_e_marryconstant_list = msg.add_e_marryconstant_list();
		E_MarryConstant_List[i].write_to_pbmsg(*temp_e_marryconstant_list);
	}
}

void Sheet_MarryConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_MarryConstant & msg) {
	E_MarryConstant_List.resize((int)msg.e_marryconstant_list_size() > (int)E_MarryConstant_List.max_size() ? E_MarryConstant_List.max_size() : msg.e_marryconstant_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarryConstant_List.size(); ++i) {
		const ::proto_ff::E_MarryConstant & temp_e_marryconstant_list = msg.e_marryconstant_list(i);
		E_MarryConstant_List[i].read_from_pbmsg(temp_e_marryconstant_list);
	}
}

E_MarryCommon_s::E_MarryCommon_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryCommon_s::CreateInit() {
	m_lv = (int32_t)0;
	return 0;
}

int E_MarryCommon_s::ResumeInit() {
	return 0;
}

void E_MarryCommon_s::write_to_pbmsg(::proto_ff::E_MarryCommon & msg) const {
	msg.set_m_lv((int32_t)m_lv);
}

void E_MarryCommon_s::read_from_pbmsg(const ::proto_ff::E_MarryCommon & msg) {
	m_lv = msg.m_lv();
}

Sheet_MarryCommon_s::Sheet_MarryCommon_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarryCommon_s::CreateInit() {
	return 0;
}

int Sheet_MarryCommon_s::ResumeInit() {
	return 0;
}

void Sheet_MarryCommon_s::write_to_pbmsg(::proto_ff::Sheet_MarryCommon & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarryCommon_List.size(); ++i) {
		::proto_ff::E_MarryCommon* temp_e_marrycommon_list = msg.add_e_marrycommon_list();
		E_MarryCommon_List[i].write_to_pbmsg(*temp_e_marrycommon_list);
	}
}

void Sheet_MarryCommon_s::read_from_pbmsg(const ::proto_ff::Sheet_MarryCommon & msg) {
	E_MarryCommon_List.resize((int)msg.e_marrycommon_list_size() > (int)E_MarryCommon_List.max_size() ? E_MarryCommon_List.max_size() : msg.e_marrycommon_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarryCommon_List.size(); ++i) {
		const ::proto_ff::E_MarryCommon & temp_e_marrycommon_list = msg.e_marrycommon_list(i);
		E_MarryCommon_List[i].read_from_pbmsg(temp_e_marrycommon_list);
	}
}

E_MarryWeddingStageDesc_s::E_MarryWeddingStageDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryWeddingStageDesc_s::CreateInit() {
	m_num = (int32_t)0;
	return 0;
}

int E_MarryWeddingStageDesc_s::ResumeInit() {
	return 0;
}

void E_MarryWeddingStageDesc_s::write_to_pbmsg(::proto_ff::E_MarryWeddingStageDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
}

void E_MarryWeddingStageDesc_s::read_from_pbmsg(const ::proto_ff::E_MarryWeddingStageDesc & msg) {
	m_num = msg.m_num();
}

E_MarryWeddingFireDesc_s::E_MarryWeddingFireDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryWeddingFireDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MarryWeddingFireDesc_s::ResumeInit() {
	return 0;
}

void E_MarryWeddingFireDesc_s::write_to_pbmsg(::proto_ff::E_MarryWeddingFireDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_MarryWeddingFireDesc_s::read_from_pbmsg(const ::proto_ff::E_MarryWeddingFireDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_MarryWeddingMoodDesc_s::E_MarryWeddingMoodDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryWeddingMoodDesc_s::CreateInit() {
	m_reward = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_MarryWeddingMoodDesc_s::ResumeInit() {
	return 0;
}

void E_MarryWeddingMoodDesc_s::write_to_pbmsg(::proto_ff::E_MarryWeddingMoodDesc & msg) const {
	msg.set_m_reward((int32_t)m_reward);
	msg.set_m_value((int32_t)m_value);
}

void E_MarryWeddingMoodDesc_s::read_from_pbmsg(const ::proto_ff::E_MarryWeddingMoodDesc & msg) {
	m_reward = msg.m_reward();
	m_value = msg.m_value();
}

E_MarryWedding_s::E_MarryWedding_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryWedding_s::CreateInit() {
	m_id = (int32_t)0;
	m_signreward = (int32_t)0;
	m_signdaynum = (int32_t)0;
	m_cakereftime = (int32_t)0;
	m_cakenum = (int32_t)0;
	m_cake = (int32_t)0;
	m_modeltime = (int32_t)0;
	m_cakereward = (int32_t)0;
	m_signcakenum = (int32_t)0;
	m_monster = (int32_t)0;
	m_monsternum = (int32_t)0;
	m_monstertime = (int32_t)0;
	m_npcid = (int32_t)0;
	m_npcnum = (int32_t)0;
	m_monsterreward = (int32_t)0;
	m_monsterdaynum = (int32_t)0;
	m_feastid = (int32_t)0;
	m_feastreward = (int32_t)0;
	m_feastnum = (int32_t)0;
	m_interval = (int32_t)0;
	m_skillid = (int32_t)0;
	return 0;
}

int E_MarryWedding_s::ResumeInit() {
	return 0;
}

void E_MarryWedding_s::write_to_pbmsg(::proto_ff::E_MarryWedding & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_signreward((int32_t)m_signreward);
	msg.set_m_signdaynum((int32_t)m_signdaynum);
	msg.set_m_cakereftime((int32_t)m_cakereftime);
	msg.set_m_cakenum((int32_t)m_cakenum);
	msg.set_m_cake((int32_t)m_cake);
	msg.set_m_model(m_model.data());
	msg.set_m_modeltime((int32_t)m_modeltime);
	msg.set_m_cakereward((int32_t)m_cakereward);
	msg.set_m_signcakenum((int32_t)m_signcakenum);
	msg.set_m_monster((int32_t)m_monster);
	msg.set_m_monsternum((int32_t)m_monsternum);
	msg.set_m_monstertime((int32_t)m_monstertime);
	msg.set_m_npcid((int32_t)m_npcid);
	msg.set_m_npcnum((int32_t)m_npcnum);
	msg.set_m_monsterreward((int32_t)m_monsterreward);
	msg.set_m_monsterdaynum((int32_t)m_monsterdaynum);
	msg.set_m_feastid((int32_t)m_feastid);
	msg.set_m_feastreward((int32_t)m_feastreward);
	msg.set_m_feastnum((int32_t)m_feastnum);
	msg.set_m_interval((int32_t)m_interval);
	msg.set_m_skillid((int32_t)m_skillid);
	for(int32_t i = 0; i < (int32_t)m_stage.size(); ++i) {
		::proto_ff::E_MarryWeddingStageDesc* temp_m_stage = msg.add_m_stage();
		m_stage[i].write_to_pbmsg(*temp_m_stage);
	}
	for(int32_t i = 0; i < (int32_t)m_fire.size(); ++i) {
		::proto_ff::E_MarryWeddingFireDesc* temp_m_fire = msg.add_m_fire();
		m_fire[i].write_to_pbmsg(*temp_m_fire);
	}
	for(int32_t i = 0; i < (int32_t)m_mood.size(); ++i) {
		::proto_ff::E_MarryWeddingMoodDesc* temp_m_mood = msg.add_m_mood();
		m_mood[i].write_to_pbmsg(*temp_m_mood);
	}
}

void E_MarryWedding_s::read_from_pbmsg(const ::proto_ff::E_MarryWedding & msg) {
	m_id = msg.m_id();
	m_signreward = msg.m_signreward();
	m_signdaynum = msg.m_signdaynum();
	m_cakereftime = msg.m_cakereftime();
	m_cakenum = msg.m_cakenum();
	m_cake = msg.m_cake();
	m_model = msg.m_model();
	m_modeltime = msg.m_modeltime();
	m_cakereward = msg.m_cakereward();
	m_signcakenum = msg.m_signcakenum();
	m_monster = msg.m_monster();
	m_monsternum = msg.m_monsternum();
	m_monstertime = msg.m_monstertime();
	m_npcid = msg.m_npcid();
	m_npcnum = msg.m_npcnum();
	m_monsterreward = msg.m_monsterreward();
	m_monsterdaynum = msg.m_monsterdaynum();
	m_feastid = msg.m_feastid();
	m_feastreward = msg.m_feastreward();
	m_feastnum = msg.m_feastnum();
	m_interval = msg.m_interval();
	m_skillid = msg.m_skillid();
	m_stage.resize((int)msg.m_stage_size() > (int)m_stage.max_size() ? m_stage.max_size() : msg.m_stage_size());
	for(int32_t i = 0; i < (int32_t)m_stage.size(); ++i) {
		const ::proto_ff::E_MarryWeddingStageDesc & temp_m_stage = msg.m_stage(i);
		m_stage[i].read_from_pbmsg(temp_m_stage);
	}
	m_fire.resize((int)msg.m_fire_size() > (int)m_fire.max_size() ? m_fire.max_size() : msg.m_fire_size());
	for(int32_t i = 0; i < (int32_t)m_fire.size(); ++i) {
		const ::proto_ff::E_MarryWeddingFireDesc & temp_m_fire = msg.m_fire(i);
		m_fire[i].read_from_pbmsg(temp_m_fire);
	}
	m_mood.resize((int)msg.m_mood_size() > (int)m_mood.max_size() ? m_mood.max_size() : msg.m_mood_size());
	for(int32_t i = 0; i < (int32_t)m_mood.size(); ++i) {
		const ::proto_ff::E_MarryWeddingMoodDesc & temp_m_mood = msg.m_mood(i);
		m_mood[i].read_from_pbmsg(temp_m_mood);
	}
}

Sheet_MarryWedding_s::Sheet_MarryWedding_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarryWedding_s::CreateInit() {
	return 0;
}

int Sheet_MarryWedding_s::ResumeInit() {
	return 0;
}

void Sheet_MarryWedding_s::write_to_pbmsg(::proto_ff::Sheet_MarryWedding & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarryWedding_List.size(); ++i) {
		::proto_ff::E_MarryWedding* temp_e_marrywedding_list = msg.add_e_marrywedding_list();
		E_MarryWedding_List[i].write_to_pbmsg(*temp_e_marrywedding_list);
	}
}

void Sheet_MarryWedding_s::read_from_pbmsg(const ::proto_ff::Sheet_MarryWedding & msg) {
	E_MarryWedding_List.resize((int)msg.e_marrywedding_list_size() > (int)E_MarryWedding_List.max_size() ? E_MarryWedding_List.max_size() : msg.e_marrywedding_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarryWedding_List.size(); ++i) {
		const ::proto_ff::E_MarryWedding & temp_e_marrywedding_list = msg.e_marrywedding_list(i);
		E_MarryWedding_List[i].read_from_pbmsg(temp_e_marrywedding_list);
	}
}

E_MarryExp_s::E_MarryExp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MarryExp_s::CreateInit() {
	m_lv = (int32_t)0;
	m_weddingexp = (int32_t)0;
	m_dayexpmax = (int32_t)0;
	return 0;
}

int E_MarryExp_s::ResumeInit() {
	return 0;
}

void E_MarryExp_s::write_to_pbmsg(::proto_ff::E_MarryExp & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_weddingexp((int32_t)m_weddingexp);
	msg.set_m_dayexpmax((int32_t)m_dayexpmax);
}

void E_MarryExp_s::read_from_pbmsg(const ::proto_ff::E_MarryExp & msg) {
	m_lv = msg.m_lv();
	m_weddingexp = msg.m_weddingexp();
	m_dayexpmax = msg.m_dayexpmax();
}

Sheet_MarryExp_s::Sheet_MarryExp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MarryExp_s::CreateInit() {
	return 0;
}

int Sheet_MarryExp_s::ResumeInit() {
	return 0;
}

void Sheet_MarryExp_s::write_to_pbmsg(::proto_ff::Sheet_MarryExp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MarryExp_List.size(); ++i) {
		::proto_ff::E_MarryExp* temp_e_marryexp_list = msg.add_e_marryexp_list();
		E_MarryExp_List[i].write_to_pbmsg(*temp_e_marryexp_list);
	}
}

void Sheet_MarryExp_s::read_from_pbmsg(const ::proto_ff::Sheet_MarryExp & msg) {
	E_MarryExp_List.resize((int)msg.e_marryexp_list_size() > (int)E_MarryExp_List.max_size() ? E_MarryExp_List.max_size() : msg.e_marryexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_MarryExp_List.size(); ++i) {
		const ::proto_ff::E_MarryExp & temp_e_marryexp_list = msg.e_marryexp_list(i);
		E_MarryExp_List[i].read_from_pbmsg(temp_e_marryexp_list);
	}
}

}
