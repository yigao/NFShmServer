#include "E_Cloudpeak_s.h"

namespace proto_ff_s {

E_CloudpeakRankrewards_s::E_CloudpeakRankrewards_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloudpeakRankrewards_s::CreateInit() {
	m_id = (int32_t)0;
	m_rewarditem = (int32_t)0;
	m_itemnum = (int64_t)0;
	return 0;
}

int E_CloudpeakRankrewards_s::ResumeInit() {
	return 0;
}

void E_CloudpeakRankrewards_s::write_to_pbmsg(::proto_ff::E_CloudpeakRankrewards & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_rewarditem((int32_t)m_rewarditem);
	msg.set_m_itemnum((int64_t)m_itemnum);
}

void E_CloudpeakRankrewards_s::read_from_pbmsg(const ::proto_ff::E_CloudpeakRankrewards & msg) {
	m_id = msg.m_id();
	m_rewarditem = msg.m_rewarditem();
	m_itemnum = msg.m_itemnum();
}

Sheet_CloudpeakRankrewards_s::Sheet_CloudpeakRankrewards_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CloudpeakRankrewards_s::CreateInit() {
	return 0;
}

int Sheet_CloudpeakRankrewards_s::ResumeInit() {
	return 0;
}

void Sheet_CloudpeakRankrewards_s::write_to_pbmsg(::proto_ff::Sheet_CloudpeakRankrewards & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CloudpeakRankrewards_List.size(); ++i) {
		::proto_ff::E_CloudpeakRankrewards* temp_e_cloudpeakrankrewards_list = msg.add_e_cloudpeakrankrewards_list();
		E_CloudpeakRankrewards_List[i].write_to_pbmsg(*temp_e_cloudpeakrankrewards_list);
	}
}

void Sheet_CloudpeakRankrewards_s::read_from_pbmsg(const ::proto_ff::Sheet_CloudpeakRankrewards & msg) {
	E_CloudpeakRankrewards_List.resize((int)msg.e_cloudpeakrankrewards_list_size() > (int)E_CloudpeakRankrewards_List.max_size() ? E_CloudpeakRankrewards_List.max_size() : msg.e_cloudpeakrankrewards_list_size());
	for(int32_t i = 0; i < (int32_t)E_CloudpeakRankrewards_List.size(); ++i) {
		const ::proto_ff::E_CloudpeakRankrewards & temp_e_cloudpeakrankrewards_list = msg.e_cloudpeakrankrewards_list(i);
		E_CloudpeakRankrewards_List[i].read_from_pbmsg(temp_e_cloudpeakrankrewards_list);
	}
}

E_CloudpeakConstantBuffDesc_s::E_CloudpeakConstantBuffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloudpeakConstantBuffDesc_s::CreateInit() {
	m_position = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_CloudpeakConstantBuffDesc_s::ResumeInit() {
	return 0;
}

void E_CloudpeakConstantBuffDesc_s::write_to_pbmsg(::proto_ff::E_CloudpeakConstantBuffDesc & msg) const {
	msg.set_m_position((int32_t)m_position);
	msg.set_m_type((int32_t)m_type);
}

void E_CloudpeakConstantBuffDesc_s::read_from_pbmsg(const ::proto_ff::E_CloudpeakConstantBuffDesc & msg) {
	m_position = msg.m_position();
	m_type = msg.m_type();
}

E_CloudpeakConstant_s::E_CloudpeakConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloudpeakConstant_s::CreateInit() {
	m_id = (int32_t)0;
	m_revivalbuff = (int32_t)0;
	m_refresh = (int32_t)0;
	m_victoryreward = (int32_t)0;
	m_failurereward = (int32_t)0;
	m_round = (int32_t)0;
	m_roundtime = (int32_t)0;
	m_initialscoring = (int32_t)0;
	m_getscoring = (int32_t)0;
	m_assistscoring = (int32_t)0;
	m_matchtime = (int32_t)0;
	m_matchentry = (int32_t)0;
	m_mapid = (int64_t)0;
	m_playersmax = (int32_t)0;
	m_rebotid = (int32_t)0;
	m_rebotcount = (int32_t)0;
	m_actid = (int32_t)0;
	return 0;
}

int E_CloudpeakConstant_s::ResumeInit() {
	return 0;
}

void E_CloudpeakConstant_s::write_to_pbmsg(::proto_ff::E_CloudpeakConstant & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_revivalbuff((int32_t)m_revivalbuff);
	msg.set_m_refresh((int32_t)m_refresh);
	msg.set_m_victoryreward((int32_t)m_victoryreward);
	msg.set_m_failurereward((int32_t)m_failurereward);
	msg.set_m_round((int32_t)m_round);
	msg.set_m_roundtime((int32_t)m_roundtime);
	msg.set_m_initialscoring((int32_t)m_initialscoring);
	msg.set_m_getscoring((int32_t)m_getscoring);
	msg.set_m_assistscoring((int32_t)m_assistscoring);
	msg.set_m_matchtime((int32_t)m_matchtime);
	msg.set_m_matchentry((int32_t)m_matchentry);
	msg.set_m_mapid((int64_t)m_mapid);
	msg.set_m_playersmax((int32_t)m_playersmax);
	msg.set_m_rebotid((int32_t)m_rebotid);
	msg.set_m_rebotcount((int32_t)m_rebotcount);
	msg.set_m_actid((int32_t)m_actid);
	for(int32_t i = 0; i < (int32_t)m_revivalpoint.size(); ++i) {
		msg.add_m_revivalpoint((int32_t)m_revivalpoint[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_buff.size(); ++i) {
		::proto_ff::E_CloudpeakConstantBuffDesc* temp_m_buff = msg.add_m_buff();
		m_buff[i].write_to_pbmsg(*temp_m_buff);
	}
	for(int32_t i = 0; i < (int32_t)m_rebot_id.size(); ++i) {
		msg.add_m_rebot_id((int32_t)m_rebot_id[i]);
	}
}

void E_CloudpeakConstant_s::read_from_pbmsg(const ::proto_ff::E_CloudpeakConstant & msg) {
	m_id = msg.m_id();
	m_revivalbuff = msg.m_revivalbuff();
	m_refresh = msg.m_refresh();
	m_victoryreward = msg.m_victoryreward();
	m_failurereward = msg.m_failurereward();
	m_round = msg.m_round();
	m_roundtime = msg.m_roundtime();
	m_initialscoring = msg.m_initialscoring();
	m_getscoring = msg.m_getscoring();
	m_assistscoring = msg.m_assistscoring();
	m_matchtime = msg.m_matchtime();
	m_matchentry = msg.m_matchentry();
	m_mapid = msg.m_mapid();
	m_playersmax = msg.m_playersmax();
	m_rebotid = msg.m_rebotid();
	m_rebotcount = msg.m_rebotcount();
	m_actid = msg.m_actid();
	m_revivalpoint.resize((int)msg.m_revivalpoint_size() > (int)m_revivalpoint.max_size() ? m_revivalpoint.max_size() : msg.m_revivalpoint_size());
	for(int32_t i = 0; i < (int32_t)m_revivalpoint.size(); ++i) {
		m_revivalpoint[i] = msg.m_revivalpoint(i);
	}
	m_buff.resize((int)msg.m_buff_size() > (int)m_buff.max_size() ? m_buff.max_size() : msg.m_buff_size());
	for(int32_t i = 0; i < (int32_t)m_buff.size(); ++i) {
		const ::proto_ff::E_CloudpeakConstantBuffDesc & temp_m_buff = msg.m_buff(i);
		m_buff[i].read_from_pbmsg(temp_m_buff);
	}
	m_rebot_id.resize((int)msg.m_rebot_id_size() > (int)m_rebot_id.max_size() ? m_rebot_id.max_size() : msg.m_rebot_id_size());
	for(int32_t i = 0; i < (int32_t)m_rebot_id.size(); ++i) {
		m_rebot_id[i] = msg.m_rebot_id(i);
	}
}

Sheet_CloudpeakConstant_s::Sheet_CloudpeakConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CloudpeakConstant_s::CreateInit() {
	return 0;
}

int Sheet_CloudpeakConstant_s::ResumeInit() {
	return 0;
}

void Sheet_CloudpeakConstant_s::write_to_pbmsg(::proto_ff::Sheet_CloudpeakConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CloudpeakConstant_List.size(); ++i) {
		::proto_ff::E_CloudpeakConstant* temp_e_cloudpeakconstant_list = msg.add_e_cloudpeakconstant_list();
		E_CloudpeakConstant_List[i].write_to_pbmsg(*temp_e_cloudpeakconstant_list);
	}
}

void Sheet_CloudpeakConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_CloudpeakConstant & msg) {
	E_CloudpeakConstant_List.resize((int)msg.e_cloudpeakconstant_list_size() > (int)E_CloudpeakConstant_List.max_size() ? E_CloudpeakConstant_List.max_size() : msg.e_cloudpeakconstant_list_size());
	for(int32_t i = 0; i < (int32_t)E_CloudpeakConstant_List.size(); ++i) {
		const ::proto_ff::E_CloudpeakConstant & temp_e_cloudpeakconstant_list = msg.e_cloudpeakconstant_list(i);
		E_CloudpeakConstant_List[i].read_from_pbmsg(temp_e_cloudpeakconstant_list);
	}
}

E_CloudpeakExp_s::E_CloudpeakExp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloudpeakExp_s::CreateInit() {
	m_lv = (int32_t)0;
	m_getexp = (int32_t)0;
	return 0;
}

int E_CloudpeakExp_s::ResumeInit() {
	return 0;
}

void E_CloudpeakExp_s::write_to_pbmsg(::proto_ff::E_CloudpeakExp & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_getexp((int32_t)m_getexp);
}

void E_CloudpeakExp_s::read_from_pbmsg(const ::proto_ff::E_CloudpeakExp & msg) {
	m_lv = msg.m_lv();
	m_getexp = msg.m_getexp();
}

Sheet_CloudpeakExp_s::Sheet_CloudpeakExp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CloudpeakExp_s::CreateInit() {
	return 0;
}

int Sheet_CloudpeakExp_s::ResumeInit() {
	return 0;
}

void Sheet_CloudpeakExp_s::write_to_pbmsg(::proto_ff::Sheet_CloudpeakExp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CloudpeakExp_List.size(); ++i) {
		::proto_ff::E_CloudpeakExp* temp_e_cloudpeakexp_list = msg.add_e_cloudpeakexp_list();
		E_CloudpeakExp_List[i].write_to_pbmsg(*temp_e_cloudpeakexp_list);
	}
}

void Sheet_CloudpeakExp_s::read_from_pbmsg(const ::proto_ff::Sheet_CloudpeakExp & msg) {
	E_CloudpeakExp_List.resize((int)msg.e_cloudpeakexp_list_size() > (int)E_CloudpeakExp_List.max_size() ? E_CloudpeakExp_List.max_size() : msg.e_cloudpeakexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_CloudpeakExp_List.size(); ++i) {
		const ::proto_ff::E_CloudpeakExp & temp_e_cloudpeakexp_list = msg.e_cloudpeakexp_list(i);
		E_CloudpeakExp_List[i].read_from_pbmsg(temp_e_cloudpeakexp_list);
	}
}

}
