#include "E_Qunxiongzhulu_s.h"

namespace proto_ff_s {

E_QunxiongzhuluConstant_s::E_QunxiongzhuluConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_QunxiongzhuluConstant_s::CreateInit() {
	m_id = (int32_t)0;
	m_thisMap = (int32_t)0;
	m_thisBossId = (int32_t)0;
	m_thisBossPonit = (int32_t)0;
	m_gateMonster = (int32_t)0;
	m_gatePoint = (int32_t)0;
	m_thisPickupLimit = (int32_t)0;
	m_crossMap = (int32_t)0;
	m_crossBossId = (int32_t)0;
	m_crossBossPoint = (int32_t)0;
	m_crossPickupLimit = (int32_t)0;
	m_carId = (int32_t)0;
	m_preview = (int32_t)0;
	m_actId = (int32_t)0;
	return 0;
}

int E_QunxiongzhuluConstant_s::ResumeInit() {
	return 0;
}

void E_QunxiongzhuluConstant_s::write_to_pbmsg(::proto_ff::E_QunxiongzhuluConstant & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_thismap((int32_t)m_thisMap);
	msg.set_m_thisbossid((int32_t)m_thisBossId);
	msg.set_m_thisbossponit((int32_t)m_thisBossPonit);
	msg.set_m_gatemonster((int32_t)m_gateMonster);
	msg.set_m_gatepoint((int32_t)m_gatePoint);
	msg.set_m_thispickuplimit((int32_t)m_thisPickupLimit);
	msg.set_m_crossmap((int32_t)m_crossMap);
	msg.set_m_crossbossid((int32_t)m_crossBossId);
	msg.set_m_crossbosspoint((int32_t)m_crossBossPoint);
	msg.set_m_crosspickuplimit((int32_t)m_crossPickupLimit);
	msg.set_m_carid((int32_t)m_carId);
	msg.set_m_preview((int32_t)m_preview);
	msg.set_m_actid((int32_t)m_actId);
	for(int32_t i = 0; i < (int32_t)m_crossPoint.size(); ++i) {
		msg.add_m_crosspoint((int32_t)m_crossPoint[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_carPoint.size(); ++i) {
		msg.add_m_carpoint((int32_t)m_carPoint[i]);
	}
}

void E_QunxiongzhuluConstant_s::read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluConstant & msg) {
	m_id = msg.m_id();
	m_thisMap = msg.m_thismap();
	m_thisBossId = msg.m_thisbossid();
	m_thisBossPonit = msg.m_thisbossponit();
	m_gateMonster = msg.m_gatemonster();
	m_gatePoint = msg.m_gatepoint();
	m_thisPickupLimit = msg.m_thispickuplimit();
	m_crossMap = msg.m_crossmap();
	m_crossBossId = msg.m_crossbossid();
	m_crossBossPoint = msg.m_crossbosspoint();
	m_crossPickupLimit = msg.m_crosspickuplimit();
	m_carId = msg.m_carid();
	m_preview = msg.m_preview();
	m_actId = msg.m_actid();
	m_crossPoint.resize((int)msg.m_crosspoint_size() > (int)m_crossPoint.max_size() ? m_crossPoint.max_size() : msg.m_crosspoint_size());
	for(int32_t i = 0; i < (int32_t)m_crossPoint.size(); ++i) {
		m_crossPoint[i] = msg.m_crosspoint(i);
	}
	m_carPoint.resize((int)msg.m_carpoint_size() > (int)m_carPoint.max_size() ? m_carPoint.max_size() : msg.m_carpoint_size());
	for(int32_t i = 0; i < (int32_t)m_carPoint.size(); ++i) {
		m_carPoint[i] = msg.m_carpoint(i);
	}
}

Sheet_QunxiongzhuluConstant_s::Sheet_QunxiongzhuluConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_QunxiongzhuluConstant_s::CreateInit() {
	return 0;
}

int Sheet_QunxiongzhuluConstant_s::ResumeInit() {
	return 0;
}

void Sheet_QunxiongzhuluConstant_s::write_to_pbmsg(::proto_ff::Sheet_QunxiongzhuluConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_QunxiongzhuluConstant_List.size(); ++i) {
		::proto_ff::E_QunxiongzhuluConstant* temp_e_qunxiongzhuluconstant_list = msg.add_e_qunxiongzhuluconstant_list();
		E_QunxiongzhuluConstant_List[i].write_to_pbmsg(*temp_e_qunxiongzhuluconstant_list);
	}
}

void Sheet_QunxiongzhuluConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_QunxiongzhuluConstant & msg) {
	E_QunxiongzhuluConstant_List.resize((int)msg.e_qunxiongzhuluconstant_list_size() > (int)E_QunxiongzhuluConstant_List.max_size() ? E_QunxiongzhuluConstant_List.max_size() : msg.e_qunxiongzhuluconstant_list_size());
	for(int32_t i = 0; i < (int32_t)E_QunxiongzhuluConstant_List.size(); ++i) {
		const ::proto_ff::E_QunxiongzhuluConstant & temp_e_qunxiongzhuluconstant_list = msg.e_qunxiongzhuluconstant_list(i);
		E_QunxiongzhuluConstant_List[i].read_from_pbmsg(temp_e_qunxiongzhuluconstant_list);
	}
}

E_QunxiongzhuluSkill_s::E_QunxiongzhuluSkill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_QunxiongzhuluSkill_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_QunxiongzhuluSkill_s::ResumeInit() {
	return 0;
}

void E_QunxiongzhuluSkill_s::write_to_pbmsg(::proto_ff::E_QunxiongzhuluSkill & msg) const {
	msg.set_m_id((int32_t)m_id);
}

void E_QunxiongzhuluSkill_s::read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluSkill & msg) {
	m_id = msg.m_id();
}

Sheet_QunxiongzhuluSkill_s::Sheet_QunxiongzhuluSkill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_QunxiongzhuluSkill_s::CreateInit() {
	return 0;
}

int Sheet_QunxiongzhuluSkill_s::ResumeInit() {
	return 0;
}

void Sheet_QunxiongzhuluSkill_s::write_to_pbmsg(::proto_ff::Sheet_QunxiongzhuluSkill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_QunxiongzhuluSkill_List.size(); ++i) {
		::proto_ff::E_QunxiongzhuluSkill* temp_e_qunxiongzhuluskill_list = msg.add_e_qunxiongzhuluskill_list();
		E_QunxiongzhuluSkill_List[i].write_to_pbmsg(*temp_e_qunxiongzhuluskill_list);
	}
}

void Sheet_QunxiongzhuluSkill_s::read_from_pbmsg(const ::proto_ff::Sheet_QunxiongzhuluSkill & msg) {
	E_QunxiongzhuluSkill_List.resize((int)msg.e_qunxiongzhuluskill_list_size() > (int)E_QunxiongzhuluSkill_List.max_size() ? E_QunxiongzhuluSkill_List.max_size() : msg.e_qunxiongzhuluskill_list_size());
	for(int32_t i = 0; i < (int32_t)E_QunxiongzhuluSkill_List.size(); ++i) {
		const ::proto_ff::E_QunxiongzhuluSkill & temp_e_qunxiongzhuluskill_list = msg.e_qunxiongzhuluskill_list(i);
		E_QunxiongzhuluSkill_List[i].read_from_pbmsg(temp_e_qunxiongzhuluskill_list);
	}
}

E_QunxiongzhuluServerrankItemDesc_s::E_QunxiongzhuluServerrankItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_QunxiongzhuluServerrankItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_QunxiongzhuluServerrankItemDesc_s::ResumeInit() {
	return 0;
}

void E_QunxiongzhuluServerrankItemDesc_s::write_to_pbmsg(::proto_ff::E_QunxiongzhuluServerrankItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_QunxiongzhuluServerrankItemDesc_s::read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluServerrankItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_QunxiongzhuluServerrank_s::E_QunxiongzhuluServerrank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_QunxiongzhuluServerrank_s::CreateInit() {
	m_id = (int32_t)0;
	m_rankMax = (int32_t)0;
	m_rankMin = (int32_t)0;
	return 0;
}

int E_QunxiongzhuluServerrank_s::ResumeInit() {
	return 0;
}

void E_QunxiongzhuluServerrank_s::write_to_pbmsg(::proto_ff::E_QunxiongzhuluServerrank & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_rankmax((int32_t)m_rankMax);
	msg.set_m_rankmin((int32_t)m_rankMin);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_QunxiongzhuluServerrankItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_QunxiongzhuluServerrank_s::read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluServerrank & msg) {
	m_id = msg.m_id();
	m_rankMax = msg.m_rankmax();
	m_rankMin = msg.m_rankmin();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_QunxiongzhuluServerrankItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
}

Sheet_QunxiongzhuluServerrank_s::Sheet_QunxiongzhuluServerrank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_QunxiongzhuluServerrank_s::CreateInit() {
	return 0;
}

int Sheet_QunxiongzhuluServerrank_s::ResumeInit() {
	return 0;
}

void Sheet_QunxiongzhuluServerrank_s::write_to_pbmsg(::proto_ff::Sheet_QunxiongzhuluServerrank & msg) const {
	for(int32_t i = 0; i < (int32_t)E_QunxiongzhuluServerrank_List.size(); ++i) {
		::proto_ff::E_QunxiongzhuluServerrank* temp_e_qunxiongzhuluserverrank_list = msg.add_e_qunxiongzhuluserverrank_list();
		E_QunxiongzhuluServerrank_List[i].write_to_pbmsg(*temp_e_qunxiongzhuluserverrank_list);
	}
}

void Sheet_QunxiongzhuluServerrank_s::read_from_pbmsg(const ::proto_ff::Sheet_QunxiongzhuluServerrank & msg) {
	E_QunxiongzhuluServerrank_List.resize((int)msg.e_qunxiongzhuluserverrank_list_size() > (int)E_QunxiongzhuluServerrank_List.max_size() ? E_QunxiongzhuluServerrank_List.max_size() : msg.e_qunxiongzhuluserverrank_list_size());
	for(int32_t i = 0; i < (int32_t)E_QunxiongzhuluServerrank_List.size(); ++i) {
		const ::proto_ff::E_QunxiongzhuluServerrank & temp_e_qunxiongzhuluserverrank_list = msg.e_qunxiongzhuluserverrank_list(i);
		E_QunxiongzhuluServerrank_List[i].read_from_pbmsg(temp_e_qunxiongzhuluserverrank_list);
	}
}

E_QunxiongzhuluWorldrankItemDesc_s::E_QunxiongzhuluWorldrankItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_QunxiongzhuluWorldrankItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_QunxiongzhuluWorldrankItemDesc_s::ResumeInit() {
	return 0;
}

void E_QunxiongzhuluWorldrankItemDesc_s::write_to_pbmsg(::proto_ff::E_QunxiongzhuluWorldrankItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_QunxiongzhuluWorldrankItemDesc_s::read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluWorldrankItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_QunxiongzhuluWorldrank_s::E_QunxiongzhuluWorldrank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_QunxiongzhuluWorldrank_s::CreateInit() {
	m_id = (int32_t)0;
	m_rankMax = (int32_t)0;
	m_rankMin = (int32_t)0;
	return 0;
}

int E_QunxiongzhuluWorldrank_s::ResumeInit() {
	return 0;
}

void E_QunxiongzhuluWorldrank_s::write_to_pbmsg(::proto_ff::E_QunxiongzhuluWorldrank & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_rankmax((int32_t)m_rankMax);
	msg.set_m_rankmin((int32_t)m_rankMin);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_QunxiongzhuluWorldrankItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_QunxiongzhuluWorldrank_s::read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluWorldrank & msg) {
	m_id = msg.m_id();
	m_rankMax = msg.m_rankmax();
	m_rankMin = msg.m_rankmin();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_QunxiongzhuluWorldrankItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
}

Sheet_QunxiongzhuluWorldrank_s::Sheet_QunxiongzhuluWorldrank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_QunxiongzhuluWorldrank_s::CreateInit() {
	return 0;
}

int Sheet_QunxiongzhuluWorldrank_s::ResumeInit() {
	return 0;
}

void Sheet_QunxiongzhuluWorldrank_s::write_to_pbmsg(::proto_ff::Sheet_QunxiongzhuluWorldrank & msg) const {
	for(int32_t i = 0; i < (int32_t)E_QunxiongzhuluWorldrank_List.size(); ++i) {
		::proto_ff::E_QunxiongzhuluWorldrank* temp_e_qunxiongzhuluworldrank_list = msg.add_e_qunxiongzhuluworldrank_list();
		E_QunxiongzhuluWorldrank_List[i].write_to_pbmsg(*temp_e_qunxiongzhuluworldrank_list);
	}
}

void Sheet_QunxiongzhuluWorldrank_s::read_from_pbmsg(const ::proto_ff::Sheet_QunxiongzhuluWorldrank & msg) {
	E_QunxiongzhuluWorldrank_List.resize((int)msg.e_qunxiongzhuluworldrank_list_size() > (int)E_QunxiongzhuluWorldrank_List.max_size() ? E_QunxiongzhuluWorldrank_List.max_size() : msg.e_qunxiongzhuluworldrank_list_size());
	for(int32_t i = 0; i < (int32_t)E_QunxiongzhuluWorldrank_List.size(); ++i) {
		const ::proto_ff::E_QunxiongzhuluWorldrank & temp_e_qunxiongzhuluworldrank_list = msg.e_qunxiongzhuluworldrank_list(i);
		E_QunxiongzhuluWorldrank_List[i].read_from_pbmsg(temp_e_qunxiongzhuluworldrank_list);
	}
}

E_QunxiongzhuluLocalrankItemDesc_s::E_QunxiongzhuluLocalrankItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_QunxiongzhuluLocalrankItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_QunxiongzhuluLocalrankItemDesc_s::ResumeInit() {
	return 0;
}

void E_QunxiongzhuluLocalrankItemDesc_s::write_to_pbmsg(::proto_ff::E_QunxiongzhuluLocalrankItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_QunxiongzhuluLocalrankItemDesc_s::read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluLocalrankItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_QunxiongzhuluLocalrank_s::E_QunxiongzhuluLocalrank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_QunxiongzhuluLocalrank_s::CreateInit() {
	m_id = (int32_t)0;
	m_rankMax = (int32_t)0;
	m_rankMin = (int32_t)0;
	return 0;
}

int E_QunxiongzhuluLocalrank_s::ResumeInit() {
	return 0;
}

void E_QunxiongzhuluLocalrank_s::write_to_pbmsg(::proto_ff::E_QunxiongzhuluLocalrank & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_rankmax((int32_t)m_rankMax);
	msg.set_m_rankmin((int32_t)m_rankMin);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_QunxiongzhuluLocalrankItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_QunxiongzhuluLocalrank_s::read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluLocalrank & msg) {
	m_id = msg.m_id();
	m_rankMax = msg.m_rankmax();
	m_rankMin = msg.m_rankmin();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_QunxiongzhuluLocalrankItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
}

Sheet_QunxiongzhuluLocalrank_s::Sheet_QunxiongzhuluLocalrank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_QunxiongzhuluLocalrank_s::CreateInit() {
	return 0;
}

int Sheet_QunxiongzhuluLocalrank_s::ResumeInit() {
	return 0;
}

void Sheet_QunxiongzhuluLocalrank_s::write_to_pbmsg(::proto_ff::Sheet_QunxiongzhuluLocalrank & msg) const {
	for(int32_t i = 0; i < (int32_t)E_QunxiongzhuluLocalrank_List.size(); ++i) {
		::proto_ff::E_QunxiongzhuluLocalrank* temp_e_qunxiongzhululocalrank_list = msg.add_e_qunxiongzhululocalrank_list();
		E_QunxiongzhuluLocalrank_List[i].write_to_pbmsg(*temp_e_qunxiongzhululocalrank_list);
	}
}

void Sheet_QunxiongzhuluLocalrank_s::read_from_pbmsg(const ::proto_ff::Sheet_QunxiongzhuluLocalrank & msg) {
	E_QunxiongzhuluLocalrank_List.resize((int)msg.e_qunxiongzhululocalrank_list_size() > (int)E_QunxiongzhuluLocalrank_List.max_size() ? E_QunxiongzhuluLocalrank_List.max_size() : msg.e_qunxiongzhululocalrank_list_size());
	for(int32_t i = 0; i < (int32_t)E_QunxiongzhuluLocalrank_List.size(); ++i) {
		const ::proto_ff::E_QunxiongzhuluLocalrank & temp_e_qunxiongzhululocalrank_list = msg.e_qunxiongzhululocalrank_list(i);
		E_QunxiongzhuluLocalrank_List[i].read_from_pbmsg(temp_e_qunxiongzhululocalrank_list);
	}
}

E_QunxiongzhuluBossrewardItemDesc_s::E_QunxiongzhuluBossrewardItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_QunxiongzhuluBossrewardItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_QunxiongzhuluBossrewardItemDesc_s::ResumeInit() {
	return 0;
}

void E_QunxiongzhuluBossrewardItemDesc_s::write_to_pbmsg(::proto_ff::E_QunxiongzhuluBossrewardItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_QunxiongzhuluBossrewardItemDesc_s::read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluBossrewardItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_QunxiongzhuluBossreward_s::E_QunxiongzhuluBossreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_QunxiongzhuluBossreward_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_QunxiongzhuluBossreward_s::ResumeInit() {
	return 0;
}

void E_QunxiongzhuluBossreward_s::write_to_pbmsg(::proto_ff::E_QunxiongzhuluBossreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_QunxiongzhuluBossrewardItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_QunxiongzhuluBossreward_s::read_from_pbmsg(const ::proto_ff::E_QunxiongzhuluBossreward & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_QunxiongzhuluBossrewardItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
}

Sheet_QunxiongzhuluBossreward_s::Sheet_QunxiongzhuluBossreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_QunxiongzhuluBossreward_s::CreateInit() {
	return 0;
}

int Sheet_QunxiongzhuluBossreward_s::ResumeInit() {
	return 0;
}

void Sheet_QunxiongzhuluBossreward_s::write_to_pbmsg(::proto_ff::Sheet_QunxiongzhuluBossreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_QunxiongzhuluBossreward_List.size(); ++i) {
		::proto_ff::E_QunxiongzhuluBossreward* temp_e_qunxiongzhulubossreward_list = msg.add_e_qunxiongzhulubossreward_list();
		E_QunxiongzhuluBossreward_List[i].write_to_pbmsg(*temp_e_qunxiongzhulubossreward_list);
	}
}

void Sheet_QunxiongzhuluBossreward_s::read_from_pbmsg(const ::proto_ff::Sheet_QunxiongzhuluBossreward & msg) {
	E_QunxiongzhuluBossreward_List.resize((int)msg.e_qunxiongzhulubossreward_list_size() > (int)E_QunxiongzhuluBossreward_List.max_size() ? E_QunxiongzhuluBossreward_List.max_size() : msg.e_qunxiongzhulubossreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_QunxiongzhuluBossreward_List.size(); ++i) {
		const ::proto_ff::E_QunxiongzhuluBossreward & temp_e_qunxiongzhulubossreward_list = msg.e_qunxiongzhulubossreward_list(i);
		E_QunxiongzhuluBossreward_List[i].read_from_pbmsg(temp_e_qunxiongzhulubossreward_list);
	}
}

}
