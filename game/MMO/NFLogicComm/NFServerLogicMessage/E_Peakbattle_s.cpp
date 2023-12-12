#include "E_Peakbattle_s.h"

namespace proto_ff_s {

E_PeakbattleConstant_s::E_PeakbattleConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PeakbattleConstant_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_PeakbattleConstant_s::ResumeInit() {
	return 0;
}

void E_PeakbattleConstant_s::write_to_pbmsg(::proto_ff::E_PeakbattleConstant & msg) const {
	msg.set_m_id((int32_t)m_id);
}

void E_PeakbattleConstant_s::read_from_pbmsg(const ::proto_ff::E_PeakbattleConstant & msg) {
	m_id = msg.m_id();
}

Sheet_PeakbattleConstant_s::Sheet_PeakbattleConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PeakbattleConstant_s::CreateInit() {
	return 0;
}

int Sheet_PeakbattleConstant_s::ResumeInit() {
	return 0;
}

void Sheet_PeakbattleConstant_s::write_to_pbmsg(::proto_ff::Sheet_PeakbattleConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PeakbattleConstant_List.size(); ++i) {
		::proto_ff::E_PeakbattleConstant* temp_e_peakbattleconstant_list = msg.add_e_peakbattleconstant_list();
		E_PeakbattleConstant_List[i].write_to_pbmsg(*temp_e_peakbattleconstant_list);
	}
}

void Sheet_PeakbattleConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_PeakbattleConstant & msg) {
	E_PeakbattleConstant_List.resize((int)msg.e_peakbattleconstant_list_size() > (int)E_PeakbattleConstant_List.max_size() ? E_PeakbattleConstant_List.max_size() : msg.e_peakbattleconstant_list_size());
	for(int32_t i = 0; i < (int32_t)E_PeakbattleConstant_List.size(); ++i) {
		const ::proto_ff::E_PeakbattleConstant & temp_e_peakbattleconstant_list = msg.e_peakbattleconstant_list(i);
		E_PeakbattleConstant_List[i].read_from_pbmsg(temp_e_peakbattleconstant_list);
	}
}

E_PeakbattleAwardAwardDesc_s::E_PeakbattleAwardAwardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PeakbattleAwardAwardDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_time = (int32_t)0;
	return 0;
}

int E_PeakbattleAwardAwardDesc_s::ResumeInit() {
	return 0;
}

void E_PeakbattleAwardAwardDesc_s::write_to_pbmsg(::proto_ff::E_PeakbattleAwardAwardDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_time((int32_t)m_time);
}

void E_PeakbattleAwardAwardDesc_s::read_from_pbmsg(const ::proto_ff::E_PeakbattleAwardAwardDesc & msg) {
	m_num = msg.m_num();
	m_time = msg.m_time();
}

E_PeakbattleAward_s::E_PeakbattleAward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PeakbattleAward_s::CreateInit() {
	m_awardId = (int32_t)0;
	m_type = (int32_t)0;
	m_condition = (int32_t)0;
	return 0;
}

int E_PeakbattleAward_s::ResumeInit() {
	return 0;
}

void E_PeakbattleAward_s::write_to_pbmsg(::proto_ff::E_PeakbattleAward & msg) const {
	msg.set_m_awardid((int32_t)m_awardId);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_condition((int32_t)m_condition);
	for(int32_t i = 0; i < (int32_t)m_award.size(); ++i) {
		::proto_ff::E_PeakbattleAwardAwardDesc* temp_m_award = msg.add_m_award();
		m_award[i].write_to_pbmsg(*temp_m_award);
	}
}

void E_PeakbattleAward_s::read_from_pbmsg(const ::proto_ff::E_PeakbattleAward & msg) {
	m_awardId = msg.m_awardid();
	m_type = msg.m_type();
	m_condition = msg.m_condition();
	m_award.resize((int)msg.m_award_size() > (int)m_award.max_size() ? m_award.max_size() : msg.m_award_size());
	for(int32_t i = 0; i < (int32_t)m_award.size(); ++i) {
		const ::proto_ff::E_PeakbattleAwardAwardDesc & temp_m_award = msg.m_award(i);
		m_award[i].read_from_pbmsg(temp_m_award);
	}
}

Sheet_PeakbattleAward_s::Sheet_PeakbattleAward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PeakbattleAward_s::CreateInit() {
	return 0;
}

int Sheet_PeakbattleAward_s::ResumeInit() {
	return 0;
}

void Sheet_PeakbattleAward_s::write_to_pbmsg(::proto_ff::Sheet_PeakbattleAward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PeakbattleAward_List.size(); ++i) {
		::proto_ff::E_PeakbattleAward* temp_e_peakbattleaward_list = msg.add_e_peakbattleaward_list();
		E_PeakbattleAward_List[i].write_to_pbmsg(*temp_e_peakbattleaward_list);
	}
}

void Sheet_PeakbattleAward_s::read_from_pbmsg(const ::proto_ff::Sheet_PeakbattleAward & msg) {
	E_PeakbattleAward_List.resize((int)msg.e_peakbattleaward_list_size() > (int)E_PeakbattleAward_List.max_size() ? E_PeakbattleAward_List.max_size() : msg.e_peakbattleaward_list_size());
	for(int32_t i = 0; i < (int32_t)E_PeakbattleAward_List.size(); ++i) {
		const ::proto_ff::E_PeakbattleAward & temp_e_peakbattleaward_list = msg.e_peakbattleaward_list(i);
		E_PeakbattleAward_List[i].read_from_pbmsg(temp_e_peakbattleaward_list);
	}
}

E_PeakbattleGuess_s::E_PeakbattleGuess_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PeakbattleGuess_s::CreateInit() {
	m_id = (int32_t)0;
	m_clock = (int32_t)0;
	m_item = (int32_t)0;
	m_num = (int32_t)0;
	m_max = (int32_t)0;
	return 0;
}

int E_PeakbattleGuess_s::ResumeInit() {
	return 0;
}

void E_PeakbattleGuess_s::write_to_pbmsg(::proto_ff::E_PeakbattleGuess & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_clock((int32_t)m_clock);
	msg.set_m_item((int32_t)m_item);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_max((int32_t)m_max);
}

void E_PeakbattleGuess_s::read_from_pbmsg(const ::proto_ff::E_PeakbattleGuess & msg) {
	m_id = msg.m_id();
	m_clock = msg.m_clock();
	m_item = msg.m_item();
	m_num = msg.m_num();
	m_max = msg.m_max();
}

Sheet_PeakbattleGuess_s::Sheet_PeakbattleGuess_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PeakbattleGuess_s::CreateInit() {
	return 0;
}

int Sheet_PeakbattleGuess_s::ResumeInit() {
	return 0;
}

void Sheet_PeakbattleGuess_s::write_to_pbmsg(::proto_ff::Sheet_PeakbattleGuess & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PeakbattleGuess_List.size(); ++i) {
		::proto_ff::E_PeakbattleGuess* temp_e_peakbattleguess_list = msg.add_e_peakbattleguess_list();
		E_PeakbattleGuess_List[i].write_to_pbmsg(*temp_e_peakbattleguess_list);
	}
}

void Sheet_PeakbattleGuess_s::read_from_pbmsg(const ::proto_ff::Sheet_PeakbattleGuess & msg) {
	E_PeakbattleGuess_List.resize((int)msg.e_peakbattleguess_list_size() > (int)E_PeakbattleGuess_List.max_size() ? E_PeakbattleGuess_List.max_size() : msg.e_peakbattleguess_list_size());
	for(int32_t i = 0; i < (int32_t)E_PeakbattleGuess_List.size(); ++i) {
		const ::proto_ff::E_PeakbattleGuess & temp_e_peakbattleguess_list = msg.e_peakbattleguess_list(i);
		E_PeakbattleGuess_List[i].read_from_pbmsg(temp_e_peakbattleguess_list);
	}
}

}
