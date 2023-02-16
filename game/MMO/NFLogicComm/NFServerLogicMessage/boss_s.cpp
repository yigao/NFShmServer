#include "boss_s.h"

namespace proto_ff_s {

E_BossRareitem_s::E_BossRareitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BossRareitem_s::CreateInit() {
	m_itemid = (int64_t)0;
	m_top = (int32_t)0;
	return 0;
}

int E_BossRareitem_s::ResumeInit() {
	return 0;
}

void E_BossRareitem_s::write_to_pbmsg(::proto_ff::E_BossRareitem & msg) const {
	msg.set_m_itemid((int64_t)m_itemid);
	msg.set_m_top((int32_t)m_top);
}

void E_BossRareitem_s::read_from_pbmsg(const ::proto_ff::E_BossRareitem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_BossRareitem_s));
	m_itemid = msg.m_itemid();
	m_top = msg.m_top();
}

Sheet_BossRareitem_s::Sheet_BossRareitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_BossRareitem_s::CreateInit() {
	return 0;
}

int Sheet_BossRareitem_s::ResumeInit() {
	return 0;
}

void Sheet_BossRareitem_s::write_to_pbmsg(::proto_ff::Sheet_BossRareitem & msg) const {
	for(int32_t i = 0; i < (int32_t)E_BossRareitem_List.size(); ++i) {
		::proto_ff::E_BossRareitem* temp_e_bossrareitem_list = msg.add_e_bossrareitem_list();
		E_BossRareitem_List[i].write_to_pbmsg(*temp_e_bossrareitem_list);
	}
}

void Sheet_BossRareitem_s::read_from_pbmsg(const ::proto_ff::Sheet_BossRareitem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_BossRareitem_s));
	E_BossRareitem_List.resize((int)msg.e_bossrareitem_list_size() > (int)E_BossRareitem_List.max_size() ? E_BossRareitem_List.max_size() : msg.e_bossrareitem_list_size());
	for(int32_t i = 0; i < (int32_t)E_BossRareitem_List.size(); ++i) {
		const ::proto_ff::E_BossRareitem & temp_e_bossrareitem_list = msg.e_bossrareitem_list(i);
		E_BossRareitem_List[i].read_from_pbmsg(temp_e_bossrareitem_list);
	}
}

E_BossBoss_s::E_BossBoss_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BossBoss_s::CreateInit() {
	m_id = (int32_t)0;
	m_bosstype = (int32_t)0;
	m_monsterid = (int32_t)0;
	m_classorder = (int32_t)0;
	m_sceneorder = (int32_t)0;
	m_duplicateid = (int32_t)0;
	m_peacemask = (int32_t)0;
	m_pointid = (int32_t)0;
	m_group_type = (int32_t)0;
	m_flashtime = (int32_t)0;
	m_retrievegiftid = (int32_t)0;
	m_notimes = (int32_t)0;
	m_assistprestige = (int32_t)0;
	return 0;
}

int E_BossBoss_s::ResumeInit() {
	return 0;
}

void E_BossBoss_s::write_to_pbmsg(::proto_ff::E_BossBoss & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_bosstype((int32_t)m_bosstype);
	msg.set_m_monsterid((int32_t)m_monsterid);
	msg.set_m_classorder((int32_t)m_classorder);
	msg.set_m_sceneorder((int32_t)m_sceneorder);
	msg.set_m_duplicateid((int32_t)m_duplicateid);
	msg.set_m_peacemask((int32_t)m_peacemask);
	msg.set_m_pointid((int32_t)m_pointid);
	msg.set_m_group_type((int32_t)m_group_type);
	msg.set_m_flashtime((int32_t)m_flashtime);
	msg.set_m_retrievegiftid((int32_t)m_retrievegiftid);
	msg.set_m_notimes((int32_t)m_notimes);
	msg.set_m_assistprestige((int32_t)m_assistprestige);
}

void E_BossBoss_s::read_from_pbmsg(const ::proto_ff::E_BossBoss & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_BossBoss_s));
	m_id = msg.m_id();
	m_bosstype = msg.m_bosstype();
	m_monsterid = msg.m_monsterid();
	m_classorder = msg.m_classorder();
	m_sceneorder = msg.m_sceneorder();
	m_duplicateid = msg.m_duplicateid();
	m_peacemask = msg.m_peacemask();
	m_pointid = msg.m_pointid();
	m_group_type = msg.m_group_type();
	m_flashtime = msg.m_flashtime();
	m_retrievegiftid = msg.m_retrievegiftid();
	m_notimes = msg.m_notimes();
	m_assistprestige = msg.m_assistprestige();
}

Sheet_BossBoss_s::Sheet_BossBoss_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_BossBoss_s::CreateInit() {
	return 0;
}

int Sheet_BossBoss_s::ResumeInit() {
	return 0;
}

void Sheet_BossBoss_s::write_to_pbmsg(::proto_ff::Sheet_BossBoss & msg) const {
	for(int32_t i = 0; i < (int32_t)E_BossBoss_List.size(); ++i) {
		::proto_ff::E_BossBoss* temp_e_bossboss_list = msg.add_e_bossboss_list();
		E_BossBoss_List[i].write_to_pbmsg(*temp_e_bossboss_list);
	}
}

void Sheet_BossBoss_s::read_from_pbmsg(const ::proto_ff::Sheet_BossBoss & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_BossBoss_s));
	E_BossBoss_List.resize((int)msg.e_bossboss_list_size() > (int)E_BossBoss_List.max_size() ? E_BossBoss_List.max_size() : msg.e_bossboss_list_size());
	for(int32_t i = 0; i < (int32_t)E_BossBoss_List.size(); ++i) {
		const ::proto_ff::E_BossBoss & temp_e_bossboss_list = msg.e_bossboss_list(i);
		E_BossBoss_List[i].read_from_pbmsg(temp_e_bossboss_list);
	}
}

E_BossBosstypeGroupDesc_s::E_BossBosstypeGroupDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BossBosstypeGroupDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_times = (int32_t)0;
	return 0;
}

int E_BossBosstypeGroupDesc_s::ResumeInit() {
	return 0;
}

void E_BossBosstypeGroupDesc_s::write_to_pbmsg(::proto_ff::E_BossBosstypeGroupDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_times((int32_t)m_times);
}

void E_BossBosstypeGroupDesc_s::read_from_pbmsg(const ::proto_ff::E_BossBosstypeGroupDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_BossBosstypeGroupDesc_s));
	m_type = msg.m_type();
	m_times = msg.m_times();
}

E_BossBosstype_s::E_BossBosstype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BossBosstype_s::CreateInit() {
	m_bosstype = (int32_t)0;
	m_maptype = (int32_t)0;
	m_functionid = (int32_t)0;
	m_duplicategroupid = (int32_t)0;
	m_privilegetype = (int32_t)0;
	m_callingcardid = (int64_t)0;
	m_entertimes = (int32_t)0;
	m_costitem = (int32_t)0;
	m_bosstimes = (int32_t)0;
	m_additemid = (int32_t)0;
	m_canhelp = (int32_t)0;
	m_qkill = (int32_t)0;
	m_retrieveddays = (int32_t)0;
	m_skill = (int32_t)0;
	return 0;
}

int E_BossBosstype_s::ResumeInit() {
	return 0;
}

void E_BossBosstype_s::write_to_pbmsg(::proto_ff::E_BossBosstype & msg) const {
	msg.set_m_bosstype((int32_t)m_bosstype);
	msg.set_m_maptype((int32_t)m_maptype);
	msg.set_m_functionid((int32_t)m_functionid);
	msg.set_m_duplicategroupid((int32_t)m_duplicategroupid);
	msg.set_m_privilegetype((int32_t)m_privilegetype);
	msg.set_m_callingcardid((int64_t)m_callingcardid);
	msg.set_m_entertimes((int32_t)m_entertimes);
	msg.set_m_costitem((int32_t)m_costitem);
	msg.set_m_costnum((const char*)m_costnum.data());
	msg.set_m_bosstimes((int32_t)m_bosstimes);
	msg.set_m_additemid((int32_t)m_additemid);
	msg.set_m_canhelp((int32_t)m_canhelp);
	msg.set_m_qkill((int32_t)m_qkill);
	msg.set_m_retrieveddays((int32_t)m_retrieveddays);
	msg.set_m_skill((int32_t)m_skill);
	for(int32_t i = 0; i < (int32_t)m_group.size(); ++i) {
		::proto_ff::E_BossBosstypeGroupDesc* temp_m_group = msg.add_m_group();
		m_group[i].write_to_pbmsg(*temp_m_group);
	}
}

void E_BossBosstype_s::read_from_pbmsg(const ::proto_ff::E_BossBosstype & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_BossBosstype_s));
	m_bosstype = msg.m_bosstype();
	m_maptype = msg.m_maptype();
	m_functionid = msg.m_functionid();
	m_duplicategroupid = msg.m_duplicategroupid();
	m_privilegetype = msg.m_privilegetype();
	m_callingcardid = msg.m_callingcardid();
	m_entertimes = msg.m_entertimes();
	m_costitem = msg.m_costitem();
	m_costnum = msg.m_costnum();
	m_bosstimes = msg.m_bosstimes();
	m_additemid = msg.m_additemid();
	m_canhelp = msg.m_canhelp();
	m_qkill = msg.m_qkill();
	m_retrieveddays = msg.m_retrieveddays();
	m_skill = msg.m_skill();
	m_group.resize((int)msg.m_group_size() > (int)m_group.max_size() ? m_group.max_size() : msg.m_group_size());
	for(int32_t i = 0; i < (int32_t)m_group.size(); ++i) {
		const ::proto_ff::E_BossBosstypeGroupDesc & temp_m_group = msg.m_group(i);
		m_group[i].read_from_pbmsg(temp_m_group);
	}
}

Sheet_BossBosstype_s::Sheet_BossBosstype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_BossBosstype_s::CreateInit() {
	return 0;
}

int Sheet_BossBosstype_s::ResumeInit() {
	return 0;
}

void Sheet_BossBosstype_s::write_to_pbmsg(::proto_ff::Sheet_BossBosstype & msg) const {
	for(int32_t i = 0; i < (int32_t)E_BossBosstype_List.size(); ++i) {
		::proto_ff::E_BossBosstype* temp_e_bossbosstype_list = msg.add_e_bossbosstype_list();
		E_BossBosstype_List[i].write_to_pbmsg(*temp_e_bossbosstype_list);
	}
}

void Sheet_BossBosstype_s::read_from_pbmsg(const ::proto_ff::Sheet_BossBosstype & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_BossBosstype_s));
	E_BossBosstype_List.resize((int)msg.e_bossbosstype_list_size() > (int)E_BossBosstype_List.max_size() ? E_BossBosstype_List.max_size() : msg.e_bossbosstype_list_size());
	for(int32_t i = 0; i < (int32_t)E_BossBosstype_List.size(); ++i) {
		const ::proto_ff::E_BossBosstype & temp_e_bossbosstype_list = msg.e_bossbosstype_list(i);
		E_BossBosstype_List[i].read_from_pbmsg(temp_e_bossbosstype_list);
	}
}

E_BossLayer_s::E_BossLayer_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BossLayer_s::CreateInit() {
	m_id = (int32_t)0;
	m_bosstype = (int32_t)0;
	m_order = (int32_t)0;
	m_mapid = (int32_t)0;
	return 0;
}

int E_BossLayer_s::ResumeInit() {
	return 0;
}

void E_BossLayer_s::write_to_pbmsg(::proto_ff::E_BossLayer & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_bosstype((int32_t)m_bosstype);
	msg.set_m_order((int32_t)m_order);
	msg.set_m_name((const char*)m_name.data());
	msg.set_m_entercondition((const char*)m_entercondition.data());
	msg.set_m_unlockcondition((const char*)m_unlockcondition.data());
	msg.set_m_mapid((int32_t)m_mapid);
}

void E_BossLayer_s::read_from_pbmsg(const ::proto_ff::E_BossLayer & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_BossLayer_s));
	m_id = msg.m_id();
	m_bosstype = msg.m_bosstype();
	m_order = msg.m_order();
	m_name = msg.m_name();
	m_entercondition = msg.m_entercondition();
	m_unlockcondition = msg.m_unlockcondition();
	m_mapid = msg.m_mapid();
}

Sheet_BossLayer_s::Sheet_BossLayer_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_BossLayer_s::CreateInit() {
	return 0;
}

int Sheet_BossLayer_s::ResumeInit() {
	return 0;
}

void Sheet_BossLayer_s::write_to_pbmsg(::proto_ff::Sheet_BossLayer & msg) const {
	for(int32_t i = 0; i < (int32_t)E_BossLayer_List.size(); ++i) {
		::proto_ff::E_BossLayer* temp_e_bosslayer_list = msg.add_e_bosslayer_list();
		E_BossLayer_List[i].write_to_pbmsg(*temp_e_bosslayer_list);
	}
}

void Sheet_BossLayer_s::read_from_pbmsg(const ::proto_ff::Sheet_BossLayer & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_BossLayer_s));
	E_BossLayer_List.resize((int)msg.e_bosslayer_list_size() > (int)E_BossLayer_List.max_size() ? E_BossLayer_List.max_size() : msg.e_bosslayer_list_size());
	for(int32_t i = 0; i < (int32_t)E_BossLayer_List.size(); ++i) {
		const ::proto_ff::E_BossLayer & temp_e_bosslayer_list = msg.e_bosslayer_list(i);
		E_BossLayer_List[i].read_from_pbmsg(temp_e_bosslayer_list);
	}
}

}