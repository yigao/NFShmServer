#include "E_Dragonsoul_s.h"

namespace proto_ff_s {

E_DragonsoulHole_s::E_DragonsoulHole_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonsoulHole_s::CreateInit() {
	m_number = (int32_t)0;
	m_type = (int32_t)0;
	m_lv = (int32_t)0;
	m_id = (int64_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_DragonsoulHole_s::ResumeInit() {
	return 0;
}

void E_DragonsoulHole_s::write_to_pbmsg(::proto_ff::E_DragonsoulHole & msg) const {
	msg.set_m_number((int32_t)m_number);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_position(m_position.data());
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_id((int64_t)m_id);
	msg.set_m_num((int32_t)m_num);
}

void E_DragonsoulHole_s::read_from_pbmsg(const ::proto_ff::E_DragonsoulHole & msg) {
	m_number = msg.m_number();
	m_type = msg.m_type();
	m_position = msg.m_position();
	m_lv = msg.m_lv();
	m_id = msg.m_id();
	m_num = msg.m_num();
}

Sheet_DragonsoulHole_s::Sheet_DragonsoulHole_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DragonsoulHole_s::CreateInit() {
	return 0;
}

int Sheet_DragonsoulHole_s::ResumeInit() {
	return 0;
}

void Sheet_DragonsoulHole_s::write_to_pbmsg(::proto_ff::Sheet_DragonsoulHole & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DragonsoulHole_List.size(); ++i) {
		::proto_ff::E_DragonsoulHole* temp_e_dragonsoulhole_list = msg.add_e_dragonsoulhole_list();
		E_DragonsoulHole_List[i].write_to_pbmsg(*temp_e_dragonsoulhole_list);
	}
}

void Sheet_DragonsoulHole_s::read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulHole & msg) {
	E_DragonsoulHole_List.resize((int)msg.e_dragonsoulhole_list_size() > (int)E_DragonsoulHole_List.max_size() ? E_DragonsoulHole_List.max_size() : msg.e_dragonsoulhole_list_size());
	for(int32_t i = 0; i < (int32_t)E_DragonsoulHole_List.size(); ++i) {
		const ::proto_ff::E_DragonsoulHole & temp_e_dragonsoulhole_list = msg.e_dragonsoulhole_list(i);
		E_DragonsoulHole_List[i].read_from_pbmsg(temp_e_dragonsoulhole_list);
	}
}

E_DragonsoulOfferexpQualityDesc_s::E_DragonsoulOfferexpQualityDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonsoulOfferexpQualityDesc_s::CreateInit() {
	m_exp = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_DragonsoulOfferexpQualityDesc_s::ResumeInit() {
	return 0;
}

void E_DragonsoulOfferexpQualityDesc_s::write_to_pbmsg(::proto_ff::E_DragonsoulOfferexpQualityDesc & msg) const {
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_type((int32_t)m_type);
}

void E_DragonsoulOfferexpQualityDesc_s::read_from_pbmsg(const ::proto_ff::E_DragonsoulOfferexpQualityDesc & msg) {
	m_exp = msg.m_exp();
	m_type = msg.m_type();
}

E_DragonsoulOfferexp_s::E_DragonsoulOfferexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonsoulOfferexp_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_itemid = (int32_t)0;
	m_itemexp = (int32_t)0;
	return 0;
}

int E_DragonsoulOfferexp_s::ResumeInit() {
	return 0;
}

void E_DragonsoulOfferexp_s::write_to_pbmsg(::proto_ff::E_DragonsoulOfferexp & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_position(m_position.data());
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_itemexp((int32_t)m_itemexp);
	for(int32_t i = 0; i < (int32_t)m_quality.size(); ++i) {
		::proto_ff::E_DragonsoulOfferexpQualityDesc* temp_m_quality = msg.add_m_quality();
		m_quality[i].write_to_pbmsg(*temp_m_quality);
	}
}

void E_DragonsoulOfferexp_s::read_from_pbmsg(const ::proto_ff::E_DragonsoulOfferexp & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_position = msg.m_position();
	m_itemid = msg.m_itemid();
	m_itemexp = msg.m_itemexp();
	m_quality.resize((int)msg.m_quality_size() > (int)m_quality.max_size() ? m_quality.max_size() : msg.m_quality_size());
	for(int32_t i = 0; i < (int32_t)m_quality.size(); ++i) {
		const ::proto_ff::E_DragonsoulOfferexpQualityDesc & temp_m_quality = msg.m_quality(i);
		m_quality[i].read_from_pbmsg(temp_m_quality);
	}
}

Sheet_DragonsoulOfferexp_s::Sheet_DragonsoulOfferexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DragonsoulOfferexp_s::CreateInit() {
	return 0;
}

int Sheet_DragonsoulOfferexp_s::ResumeInit() {
	return 0;
}

void Sheet_DragonsoulOfferexp_s::write_to_pbmsg(::proto_ff::Sheet_DragonsoulOfferexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DragonsoulOfferexp_List.size(); ++i) {
		::proto_ff::E_DragonsoulOfferexp* temp_e_dragonsoulofferexp_list = msg.add_e_dragonsoulofferexp_list();
		E_DragonsoulOfferexp_List[i].write_to_pbmsg(*temp_e_dragonsoulofferexp_list);
	}
}

void Sheet_DragonsoulOfferexp_s::read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulOfferexp & msg) {
	E_DragonsoulOfferexp_List.resize((int)msg.e_dragonsoulofferexp_list_size() > (int)E_DragonsoulOfferexp_List.max_size() ? E_DragonsoulOfferexp_List.max_size() : msg.e_dragonsoulofferexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_DragonsoulOfferexp_List.size(); ++i) {
		const ::proto_ff::E_DragonsoulOfferexp & temp_e_dragonsoulofferexp_list = msg.e_dragonsoulofferexp_list(i);
		E_DragonsoulOfferexp_List[i].read_from_pbmsg(temp_e_dragonsoulofferexp_list);
	}
}

E_DragonsoulStrongexp_s::E_DragonsoulStrongexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonsoulStrongexp_s::CreateInit() {
	m_lv = (int32_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_DragonsoulStrongexp_s::ResumeInit() {
	return 0;
}

void E_DragonsoulStrongexp_s::write_to_pbmsg(::proto_ff::E_DragonsoulStrongexp & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int32_t)m_exp);
}

void E_DragonsoulStrongexp_s::read_from_pbmsg(const ::proto_ff::E_DragonsoulStrongexp & msg) {
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
}

Sheet_DragonsoulStrongexp_s::Sheet_DragonsoulStrongexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DragonsoulStrongexp_s::CreateInit() {
	return 0;
}

int Sheet_DragonsoulStrongexp_s::ResumeInit() {
	return 0;
}

void Sheet_DragonsoulStrongexp_s::write_to_pbmsg(::proto_ff::Sheet_DragonsoulStrongexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DragonsoulStrongexp_List.size(); ++i) {
		::proto_ff::E_DragonsoulStrongexp* temp_e_dragonsoulstrongexp_list = msg.add_e_dragonsoulstrongexp_list();
		E_DragonsoulStrongexp_List[i].write_to_pbmsg(*temp_e_dragonsoulstrongexp_list);
	}
}

void Sheet_DragonsoulStrongexp_s::read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulStrongexp & msg) {
	E_DragonsoulStrongexp_List.resize((int)msg.e_dragonsoulstrongexp_list_size() > (int)E_DragonsoulStrongexp_List.max_size() ? E_DragonsoulStrongexp_List.max_size() : msg.e_dragonsoulstrongexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_DragonsoulStrongexp_List.size(); ++i) {
		const ::proto_ff::E_DragonsoulStrongexp & temp_e_dragonsoulstrongexp_list = msg.e_dragonsoulstrongexp_list(i);
		E_DragonsoulStrongexp_List[i].read_from_pbmsg(temp_e_dragonsoulstrongexp_list);
	}
}

E_DragonsoulFlyexp_s::E_DragonsoulFlyexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonsoulFlyexp_s::CreateInit() {
	m_lv = (int32_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_DragonsoulFlyexp_s::ResumeInit() {
	return 0;
}

void E_DragonsoulFlyexp_s::write_to_pbmsg(::proto_ff::E_DragonsoulFlyexp & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int32_t)m_exp);
}

void E_DragonsoulFlyexp_s::read_from_pbmsg(const ::proto_ff::E_DragonsoulFlyexp & msg) {
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
}

Sheet_DragonsoulFlyexp_s::Sheet_DragonsoulFlyexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DragonsoulFlyexp_s::CreateInit() {
	return 0;
}

int Sheet_DragonsoulFlyexp_s::ResumeInit() {
	return 0;
}

void Sheet_DragonsoulFlyexp_s::write_to_pbmsg(::proto_ff::Sheet_DragonsoulFlyexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DragonsoulFlyexp_List.size(); ++i) {
		::proto_ff::E_DragonsoulFlyexp* temp_e_dragonsoulflyexp_list = msg.add_e_dragonsoulflyexp_list();
		E_DragonsoulFlyexp_List[i].write_to_pbmsg(*temp_e_dragonsoulflyexp_list);
	}
}

void Sheet_DragonsoulFlyexp_s::read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulFlyexp & msg) {
	E_DragonsoulFlyexp_List.resize((int)msg.e_dragonsoulflyexp_list_size() > (int)E_DragonsoulFlyexp_List.max_size() ? E_DragonsoulFlyexp_List.max_size() : msg.e_dragonsoulflyexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_DragonsoulFlyexp_List.size(); ++i) {
		const ::proto_ff::E_DragonsoulFlyexp & temp_e_dragonsoulflyexp_list = msg.e_dragonsoulflyexp_list(i);
		E_DragonsoulFlyexp_List[i].read_from_pbmsg(temp_e_dragonsoulflyexp_list);
	}
}

E_DragonsoulFlyatt_s::E_DragonsoulFlyatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonsoulFlyatt_s::CreateInit() {
	m_id = (int64_t)0;
	m_attid = (int64_t)0;
	m_count = (int32_t)0;
	m_atttype = (int32_t)0;
	return 0;
}

int E_DragonsoulFlyatt_s::ResumeInit() {
	return 0;
}

void E_DragonsoulFlyatt_s::write_to_pbmsg(::proto_ff::E_DragonsoulFlyatt & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_attid((int64_t)m_attid);
	msg.set_m_count((int32_t)m_count);
	msg.set_m_atttype((int32_t)m_atttype);
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		msg.add_m_att((int32_t)m_att[i]);
	}
}

void E_DragonsoulFlyatt_s::read_from_pbmsg(const ::proto_ff::E_DragonsoulFlyatt & msg) {
	m_id = msg.m_id();
	m_attid = msg.m_attid();
	m_count = msg.m_count();
	m_atttype = msg.m_atttype();
	m_att.resize((int)msg.m_att_size() > (int)m_att.max_size() ? m_att.max_size() : msg.m_att_size());
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		m_att[i] = msg.m_att(i);
	}
}

Sheet_DragonsoulFlyatt_s::Sheet_DragonsoulFlyatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DragonsoulFlyatt_s::CreateInit() {
	return 0;
}

int Sheet_DragonsoulFlyatt_s::ResumeInit() {
	return 0;
}

void Sheet_DragonsoulFlyatt_s::write_to_pbmsg(::proto_ff::Sheet_DragonsoulFlyatt & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DragonsoulFlyatt_List.size(); ++i) {
		::proto_ff::E_DragonsoulFlyatt* temp_e_dragonsoulflyatt_list = msg.add_e_dragonsoulflyatt_list();
		E_DragonsoulFlyatt_List[i].write_to_pbmsg(*temp_e_dragonsoulflyatt_list);
	}
}

void Sheet_DragonsoulFlyatt_s::read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulFlyatt & msg) {
	E_DragonsoulFlyatt_List.resize((int)msg.e_dragonsoulflyatt_list_size() > (int)E_DragonsoulFlyatt_List.max_size() ? E_DragonsoulFlyatt_List.max_size() : msg.e_dragonsoulflyatt_list_size());
	for(int32_t i = 0; i < (int32_t)E_DragonsoulFlyatt_List.size(); ++i) {
		const ::proto_ff::E_DragonsoulFlyatt & temp_e_dragonsoulflyatt_list = msg.e_dragonsoulflyatt_list(i);
		E_DragonsoulFlyatt_List[i].read_from_pbmsg(temp_e_dragonsoulflyatt_list);
	}
}

E_DragonsoulFlyTypeDesc_s::E_DragonsoulFlyTypeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonsoulFlyTypeDesc_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_DragonsoulFlyTypeDesc_s::ResumeInit() {
	return 0;
}

void E_DragonsoulFlyTypeDesc_s::write_to_pbmsg(::proto_ff::E_DragonsoulFlyTypeDesc & msg) const {
	msg.set_m_num(m_num.data());
	msg.set_m_id((int32_t)m_id);
}

void E_DragonsoulFlyTypeDesc_s::read_from_pbmsg(const ::proto_ff::E_DragonsoulFlyTypeDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_DragonsoulFly_s::E_DragonsoulFly_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonsoulFly_s::CreateInit() {
	m_id = (int64_t)0;
	m_position = (int32_t)0;
	m_offerexp = (int32_t)0;
	m_quality = (int32_t)0;
	m_srtongup = (int32_t)0;
	return 0;
}

int E_DragonsoulFly_s::ResumeInit() {
	return 0;
}

void E_DragonsoulFly_s::write_to_pbmsg(::proto_ff::E_DragonsoulFly & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_offerexp((int32_t)m_offerexp);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_srtongup((int32_t)m_srtongup);
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		::proto_ff::E_DragonsoulFlyTypeDesc* temp_m_type = msg.add_m_type();
		m_type[i].write_to_pbmsg(*temp_m_type);
	}
	for(int32_t i = 0; i < (int32_t)m_flyatt.size(); ++i) {
		msg.add_m_flyatt((int32_t)m_flyatt[i]);
	}
}

void E_DragonsoulFly_s::read_from_pbmsg(const ::proto_ff::E_DragonsoulFly & msg) {
	m_id = msg.m_id();
	m_position = msg.m_position();
	m_offerexp = msg.m_offerexp();
	m_quality = msg.m_quality();
	m_srtongup = msg.m_srtongup();
	m_type.resize((int)msg.m_type_size() > (int)m_type.max_size() ? m_type.max_size() : msg.m_type_size());
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		const ::proto_ff::E_DragonsoulFlyTypeDesc & temp_m_type = msg.m_type(i);
		m_type[i].read_from_pbmsg(temp_m_type);
	}
	m_flyatt.resize((int)msg.m_flyatt_size() > (int)m_flyatt.max_size() ? m_flyatt.max_size() : msg.m_flyatt_size());
	for(int32_t i = 0; i < (int32_t)m_flyatt.size(); ++i) {
		m_flyatt[i] = msg.m_flyatt(i);
	}
}

Sheet_DragonsoulFly_s::Sheet_DragonsoulFly_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DragonsoulFly_s::CreateInit() {
	return 0;
}

int Sheet_DragonsoulFly_s::ResumeInit() {
	return 0;
}

void Sheet_DragonsoulFly_s::write_to_pbmsg(::proto_ff::Sheet_DragonsoulFly & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DragonsoulFly_List.size(); ++i) {
		::proto_ff::E_DragonsoulFly* temp_e_dragonsoulfly_list = msg.add_e_dragonsoulfly_list();
		E_DragonsoulFly_List[i].write_to_pbmsg(*temp_e_dragonsoulfly_list);
	}
}

void Sheet_DragonsoulFly_s::read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulFly & msg) {
	E_DragonsoulFly_List.resize((int)msg.e_dragonsoulfly_list_size() > (int)E_DragonsoulFly_List.max_size() ? E_DragonsoulFly_List.max_size() : msg.e_dragonsoulfly_list_size());
	for(int32_t i = 0; i < (int32_t)E_DragonsoulFly_List.size(); ++i) {
		const ::proto_ff::E_DragonsoulFly & temp_e_dragonsoulfly_list = msg.e_dragonsoulfly_list(i);
		E_DragonsoulFly_List[i].read_from_pbmsg(temp_e_dragonsoulfly_list);
	}
}

E_DragonsoulAwakeAwakeDesc_s::E_DragonsoulAwakeAwakeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonsoulAwakeAwakeDesc_s::CreateInit() {
	m_flyaddratio = (int32_t)0;
	m_lvaddratio = (int32_t)0;
	m_value = (int32_t)0;
	m_att = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_DragonsoulAwakeAwakeDesc_s::ResumeInit() {
	return 0;
}

void E_DragonsoulAwakeAwakeDesc_s::write_to_pbmsg(::proto_ff::E_DragonsoulAwakeAwakeDesc & msg) const {
	msg.set_m_flyaddratio((int32_t)m_flyaddratio);
	msg.set_m_lvaddratio((int32_t)m_lvaddratio);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_att((int32_t)m_att);
	msg.set_m_num((int32_t)m_num);
}

void E_DragonsoulAwakeAwakeDesc_s::read_from_pbmsg(const ::proto_ff::E_DragonsoulAwakeAwakeDesc & msg) {
	m_flyaddratio = msg.m_flyaddratio();
	m_lvaddratio = msg.m_lvaddratio();
	m_value = msg.m_value();
	m_att = msg.m_att();
	m_num = msg.m_num();
}

E_DragonsoulAwake_s::E_DragonsoulAwake_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonsoulAwake_s::CreateInit() {
	m_position = (int32_t)0;
	m_awakeitem = (int32_t)0;
	m_awaketoplimit = (int32_t)0;
	return 0;
}

int E_DragonsoulAwake_s::ResumeInit() {
	return 0;
}

void E_DragonsoulAwake_s::write_to_pbmsg(::proto_ff::E_DragonsoulAwake & msg) const {
	msg.set_m_position((int32_t)m_position);
	msg.set_m_awakeitem((int32_t)m_awakeitem);
	msg.set_m_awaketoplimit((int32_t)m_awaketoplimit);
	for(int32_t i = 0; i < (int32_t)m_awake.size(); ++i) {
		::proto_ff::E_DragonsoulAwakeAwakeDesc* temp_m_awake = msg.add_m_awake();
		m_awake[i].write_to_pbmsg(*temp_m_awake);
	}
}

void E_DragonsoulAwake_s::read_from_pbmsg(const ::proto_ff::E_DragonsoulAwake & msg) {
	m_position = msg.m_position();
	m_awakeitem = msg.m_awakeitem();
	m_awaketoplimit = msg.m_awaketoplimit();
	m_awake.resize((int)msg.m_awake_size() > (int)m_awake.max_size() ? m_awake.max_size() : msg.m_awake_size());
	for(int32_t i = 0; i < (int32_t)m_awake.size(); ++i) {
		const ::proto_ff::E_DragonsoulAwakeAwakeDesc & temp_m_awake = msg.m_awake(i);
		m_awake[i].read_from_pbmsg(temp_m_awake);
	}
}

Sheet_DragonsoulAwake_s::Sheet_DragonsoulAwake_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DragonsoulAwake_s::CreateInit() {
	return 0;
}

int Sheet_DragonsoulAwake_s::ResumeInit() {
	return 0;
}

void Sheet_DragonsoulAwake_s::write_to_pbmsg(::proto_ff::Sheet_DragonsoulAwake & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DragonsoulAwake_List.size(); ++i) {
		::proto_ff::E_DragonsoulAwake* temp_e_dragonsoulawake_list = msg.add_e_dragonsoulawake_list();
		E_DragonsoulAwake_List[i].write_to_pbmsg(*temp_e_dragonsoulawake_list);
	}
}

void Sheet_DragonsoulAwake_s::read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulAwake & msg) {
	E_DragonsoulAwake_List.resize((int)msg.e_dragonsoulawake_list_size() > (int)E_DragonsoulAwake_List.max_size() ? E_DragonsoulAwake_List.max_size() : msg.e_dragonsoulawake_list_size());
	for(int32_t i = 0; i < (int32_t)E_DragonsoulAwake_List.size(); ++i) {
		const ::proto_ff::E_DragonsoulAwake & temp_e_dragonsoulawake_list = msg.e_dragonsoulawake_list(i);
		E_DragonsoulAwake_List[i].read_from_pbmsg(temp_e_dragonsoulawake_list);
	}
}

E_DragonsoulName_s::E_DragonsoulName_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonsoulName_s::CreateInit() {
	m_id = (int32_t)0;
	m_functionid = (int32_t)0;
	return 0;
}

int E_DragonsoulName_s::ResumeInit() {
	return 0;
}

void E_DragonsoulName_s::write_to_pbmsg(::proto_ff::E_DragonsoulName & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_functionid((int32_t)m_functionid);
}

void E_DragonsoulName_s::read_from_pbmsg(const ::proto_ff::E_DragonsoulName & msg) {
	m_id = msg.m_id();
	m_functionid = msg.m_functionid();
}

Sheet_DragonsoulName_s::Sheet_DragonsoulName_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DragonsoulName_s::CreateInit() {
	return 0;
}

int Sheet_DragonsoulName_s::ResumeInit() {
	return 0;
}

void Sheet_DragonsoulName_s::write_to_pbmsg(::proto_ff::Sheet_DragonsoulName & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DragonsoulName_List.size(); ++i) {
		::proto_ff::E_DragonsoulName* temp_e_dragonsoulname_list = msg.add_e_dragonsoulname_list();
		E_DragonsoulName_List[i].write_to_pbmsg(*temp_e_dragonsoulname_list);
	}
}

void Sheet_DragonsoulName_s::read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulName & msg) {
	E_DragonsoulName_List.resize((int)msg.e_dragonsoulname_list_size() > (int)E_DragonsoulName_List.max_size() ? E_DragonsoulName_List.max_size() : msg.e_dragonsoulname_list_size());
	for(int32_t i = 0; i < (int32_t)E_DragonsoulName_List.size(); ++i) {
		const ::proto_ff::E_DragonsoulName & temp_e_dragonsoulname_list = msg.e_dragonsoulname_list(i);
		E_DragonsoulName_List[i].read_from_pbmsg(temp_e_dragonsoulname_list);
	}
}

E_DragonsoulStarcollectAttributeDesc_s::E_DragonsoulStarcollectAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonsoulStarcollectAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_DragonsoulStarcollectAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_DragonsoulStarcollectAttributeDesc_s::write_to_pbmsg(::proto_ff::E_DragonsoulStarcollectAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_DragonsoulStarcollectAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_DragonsoulStarcollectAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_DragonsoulStarcollect_s::E_DragonsoulStarcollect_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DragonsoulStarcollect_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_DragonsoulStarcollect_s::ResumeInit() {
	return 0;
}

void E_DragonsoulStarcollect_s::write_to_pbmsg(::proto_ff::E_DragonsoulStarcollect & msg) const {
	msg.set_m_id((int32_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_DragonsoulStarcollectAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_DragonsoulStarcollect_s::read_from_pbmsg(const ::proto_ff::E_DragonsoulStarcollect & msg) {
	m_id = msg.m_id();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_DragonsoulStarcollectAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_DragonsoulStarcollect_s::Sheet_DragonsoulStarcollect_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DragonsoulStarcollect_s::CreateInit() {
	return 0;
}

int Sheet_DragonsoulStarcollect_s::ResumeInit() {
	return 0;
}

void Sheet_DragonsoulStarcollect_s::write_to_pbmsg(::proto_ff::Sheet_DragonsoulStarcollect & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DragonsoulStarcollect_List.size(); ++i) {
		::proto_ff::E_DragonsoulStarcollect* temp_e_dragonsoulstarcollect_list = msg.add_e_dragonsoulstarcollect_list();
		E_DragonsoulStarcollect_List[i].write_to_pbmsg(*temp_e_dragonsoulstarcollect_list);
	}
}

void Sheet_DragonsoulStarcollect_s::read_from_pbmsg(const ::proto_ff::Sheet_DragonsoulStarcollect & msg) {
	E_DragonsoulStarcollect_List.resize((int)msg.e_dragonsoulstarcollect_list_size() > (int)E_DragonsoulStarcollect_List.max_size() ? E_DragonsoulStarcollect_List.max_size() : msg.e_dragonsoulstarcollect_list_size());
	for(int32_t i = 0; i < (int32_t)E_DragonsoulStarcollect_List.size(); ++i) {
		const ::proto_ff::E_DragonsoulStarcollect & temp_e_dragonsoulstarcollect_list = msg.e_dragonsoulstarcollect_list(i);
		E_DragonsoulStarcollect_List[i].read_from_pbmsg(temp_e_dragonsoulstarcollect_list);
	}
}

}
