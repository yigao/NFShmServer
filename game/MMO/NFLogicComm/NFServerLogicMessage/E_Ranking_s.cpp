#include "E_Ranking_s.h"

namespace proto_ff_s {

E_RankingRanking_s::E_RankingRanking_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RankingRanking_s::CreateInit() {
	m_rankingID = (int32_t)0;
	m_capacity = (int32_t)0;
	m_showSize = (int32_t)0;
	m_rankHide = (int32_t)0;
	return 0;
}

int E_RankingRanking_s::ResumeInit() {
	return 0;
}

void E_RankingRanking_s::write_to_pbmsg(::proto_ff::E_RankingRanking & msg) const {
	msg.set_m_rankingid((int32_t)m_rankingID);
	msg.set_m_rankingname(m_rankingName.data());
	msg.set_m_title(m_title.data());
	msg.set_m_capacity((int32_t)m_capacity);
	msg.set_m_showsize((int32_t)m_showSize);
	msg.set_m_rankhide((int32_t)m_rankHide);
	for(int32_t i = 0; i < (int32_t)m_dateID.size(); ++i) {
		msg.add_m_dateid((int32_t)m_dateID[i]);
	}
}

void E_RankingRanking_s::read_from_pbmsg(const ::proto_ff::E_RankingRanking & msg) {
	m_rankingID = msg.m_rankingid();
	m_rankingName = msg.m_rankingname();
	m_title = msg.m_title();
	m_capacity = msg.m_capacity();
	m_showSize = msg.m_showsize();
	m_rankHide = msg.m_rankhide();
	m_dateID.resize((int)msg.m_dateid_size() > (int)m_dateID.max_size() ? m_dateID.max_size() : msg.m_dateid_size());
	for(int32_t i = 0; i < (int32_t)m_dateID.size(); ++i) {
		m_dateID[i] = msg.m_dateid(i);
	}
}

Sheet_RankingRanking_s::Sheet_RankingRanking_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RankingRanking_s::CreateInit() {
	return 0;
}

int Sheet_RankingRanking_s::ResumeInit() {
	return 0;
}

void Sheet_RankingRanking_s::write_to_pbmsg(::proto_ff::Sheet_RankingRanking & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RankingRanking_List.size(); ++i) {
		::proto_ff::E_RankingRanking* temp_e_rankingranking_list = msg.add_e_rankingranking_list();
		E_RankingRanking_List[i].write_to_pbmsg(*temp_e_rankingranking_list);
	}
}

void Sheet_RankingRanking_s::read_from_pbmsg(const ::proto_ff::Sheet_RankingRanking & msg) {
	E_RankingRanking_List.resize((int)msg.e_rankingranking_list_size() > (int)E_RankingRanking_List.max_size() ? E_RankingRanking_List.max_size() : msg.e_rankingranking_list_size());
	for(int32_t i = 0; i < (int32_t)E_RankingRanking_List.size(); ++i) {
		const ::proto_ff::E_RankingRanking & temp_e_rankingranking_list = msg.e_rankingranking_list(i);
		E_RankingRanking_List[i].read_from_pbmsg(temp_e_rankingranking_list);
	}
}

E_RankingDate_s::E_RankingDate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RankingDate_s::CreateInit() {
	m_dateID = (int32_t)0;
	return 0;
}

int E_RankingDate_s::ResumeInit() {
	return 0;
}

void E_RankingDate_s::write_to_pbmsg(::proto_ff::E_RankingDate & msg) const {
	msg.set_m_dateid((int32_t)m_dateID);
	msg.set_m_datename(m_dateName.data());
}

void E_RankingDate_s::read_from_pbmsg(const ::proto_ff::E_RankingDate & msg) {
	m_dateID = msg.m_dateid();
	m_dateName = msg.m_datename();
}

Sheet_RankingDate_s::Sheet_RankingDate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RankingDate_s::CreateInit() {
	return 0;
}

int Sheet_RankingDate_s::ResumeInit() {
	return 0;
}

void Sheet_RankingDate_s::write_to_pbmsg(::proto_ff::Sheet_RankingDate & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RankingDate_List.size(); ++i) {
		::proto_ff::E_RankingDate* temp_e_rankingdate_list = msg.add_e_rankingdate_list();
		E_RankingDate_List[i].write_to_pbmsg(*temp_e_rankingdate_list);
	}
}

void Sheet_RankingDate_s::read_from_pbmsg(const ::proto_ff::Sheet_RankingDate & msg) {
	E_RankingDate_List.resize((int)msg.e_rankingdate_list_size() > (int)E_RankingDate_List.max_size() ? E_RankingDate_List.max_size() : msg.e_rankingdate_list_size());
	for(int32_t i = 0; i < (int32_t)E_RankingDate_List.size(); ++i) {
		const ::proto_ff::E_RankingDate & temp_e_rankingdate_list = msg.e_rankingdate_list(i);
		E_RankingDate_List[i].read_from_pbmsg(temp_e_rankingdate_list);
	}
}

E_RankingButton_s::E_RankingButton_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RankingButton_s::CreateInit() {
	m_buttonID = (int32_t)0;
	m_display = (int32_t)0;
	return 0;
}

int E_RankingButton_s::ResumeInit() {
	return 0;
}

void E_RankingButton_s::write_to_pbmsg(::proto_ff::E_RankingButton & msg) const {
	msg.set_m_buttonid((int32_t)m_buttonID);
	msg.set_m_buttonname(m_buttonName.data());
	msg.set_m_display((int32_t)m_display);
}

void E_RankingButton_s::read_from_pbmsg(const ::proto_ff::E_RankingButton & msg) {
	m_buttonID = msg.m_buttonid();
	m_buttonName = msg.m_buttonname();
	m_display = msg.m_display();
}

Sheet_RankingButton_s::Sheet_RankingButton_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RankingButton_s::CreateInit() {
	return 0;
}

int Sheet_RankingButton_s::ResumeInit() {
	return 0;
}

void Sheet_RankingButton_s::write_to_pbmsg(::proto_ff::Sheet_RankingButton & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RankingButton_List.size(); ++i) {
		::proto_ff::E_RankingButton* temp_e_rankingbutton_list = msg.add_e_rankingbutton_list();
		E_RankingButton_List[i].write_to_pbmsg(*temp_e_rankingbutton_list);
	}
}

void Sheet_RankingButton_s::read_from_pbmsg(const ::proto_ff::Sheet_RankingButton & msg) {
	E_RankingButton_List.resize((int)msg.e_rankingbutton_list_size() > (int)E_RankingButton_List.max_size() ? E_RankingButton_List.max_size() : msg.e_rankingbutton_list_size());
	for(int32_t i = 0; i < (int32_t)E_RankingButton_List.size(); ++i) {
		const ::proto_ff::E_RankingButton & temp_e_rankingbutton_list = msg.e_rankingbutton_list(i);
		E_RankingButton_List[i].read_from_pbmsg(temp_e_rankingbutton_list);
	}
}

}
