#include "E_Yanglong_s.h"

namespace proto_ff_s {

E_YanglongYanglong_s::E_YanglongYanglong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_YanglongYanglong_s::CreateInit() {
	m_projectid = (int32_t)0;
	m_groupid = (int32_t)0;
	m_dupid = (int32_t)0;
	return 0;
}

int E_YanglongYanglong_s::ResumeInit() {
	return 0;
}

void E_YanglongYanglong_s::write_to_pbmsg(::proto_ff::E_YanglongYanglong & msg) const {
	msg.set_m_projectid((int32_t)m_projectid);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_dupid((int32_t)m_dupid);
}

void E_YanglongYanglong_s::read_from_pbmsg(const ::proto_ff::E_YanglongYanglong & msg) {
	m_projectid = msg.m_projectid();
	m_groupid = msg.m_groupid();
	m_dupid = msg.m_dupid();
}

Sheet_YanglongYanglong_s::Sheet_YanglongYanglong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_YanglongYanglong_s::CreateInit() {
	return 0;
}

int Sheet_YanglongYanglong_s::ResumeInit() {
	return 0;
}

void Sheet_YanglongYanglong_s::write_to_pbmsg(::proto_ff::Sheet_YanglongYanglong & msg) const {
	for(int32_t i = 0; i < (int32_t)E_YanglongYanglong_List.size(); ++i) {
		::proto_ff::E_YanglongYanglong* temp_e_yanglongyanglong_list = msg.add_e_yanglongyanglong_list();
		E_YanglongYanglong_List[i].write_to_pbmsg(*temp_e_yanglongyanglong_list);
	}
}

void Sheet_YanglongYanglong_s::read_from_pbmsg(const ::proto_ff::Sheet_YanglongYanglong & msg) {
	E_YanglongYanglong_List.resize((int)msg.e_yanglongyanglong_list_size() > (int)E_YanglongYanglong_List.max_size() ? E_YanglongYanglong_List.max_size() : msg.e_yanglongyanglong_list_size());
	for(int32_t i = 0; i < (int32_t)E_YanglongYanglong_List.size(); ++i) {
		const ::proto_ff::E_YanglongYanglong & temp_e_yanglongyanglong_list = msg.e_yanglongyanglong_list(i);
		E_YanglongYanglong_List[i].read_from_pbmsg(temp_e_yanglongyanglong_list);
	}
}

E_YanglongZadan_s::E_YanglongZadan_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_YanglongZadan_s::CreateInit() {
	m_taskid = (int64_t)0;
	m_achievementsubtype = (int32_t)0;
	m_bosstype = (int32_t)0;
	m_reachprice = (int32_t)0;
	m_reward = (int32_t)0;
	m_reward_value = (int32_t)0;
	m_linkid = (int32_t)0;
	return 0;
}

int E_YanglongZadan_s::ResumeInit() {
	return 0;
}

void E_YanglongZadan_s::write_to_pbmsg(::proto_ff::E_YanglongZadan & msg) const {
	msg.set_m_taskid((int64_t)m_taskid);
	msg.set_m_achievementsubtype((int32_t)m_achievementsubtype);
	msg.set_m_bosstype((int32_t)m_bosstype);
	msg.set_m_reachprice((int32_t)m_reachprice);
	msg.set_m_reward((int32_t)m_reward);
	msg.set_m_reward_value((int32_t)m_reward_value);
	msg.set_m_linkid((int32_t)m_linkid);
}

void E_YanglongZadan_s::read_from_pbmsg(const ::proto_ff::E_YanglongZadan & msg) {
	m_taskid = msg.m_taskid();
	m_achievementsubtype = msg.m_achievementsubtype();
	m_bosstype = msg.m_bosstype();
	m_reachprice = msg.m_reachprice();
	m_reward = msg.m_reward();
	m_reward_value = msg.m_reward_value();
	m_linkid = msg.m_linkid();
}

Sheet_YanglongZadan_s::Sheet_YanglongZadan_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_YanglongZadan_s::CreateInit() {
	return 0;
}

int Sheet_YanglongZadan_s::ResumeInit() {
	return 0;
}

void Sheet_YanglongZadan_s::write_to_pbmsg(::proto_ff::Sheet_YanglongZadan & msg) const {
	for(int32_t i = 0; i < (int32_t)E_YanglongZadan_List.size(); ++i) {
		::proto_ff::E_YanglongZadan* temp_e_yanglongzadan_list = msg.add_e_yanglongzadan_list();
		E_YanglongZadan_List[i].write_to_pbmsg(*temp_e_yanglongzadan_list);
	}
}

void Sheet_YanglongZadan_s::read_from_pbmsg(const ::proto_ff::Sheet_YanglongZadan & msg) {
	E_YanglongZadan_List.resize((int)msg.e_yanglongzadan_list_size() > (int)E_YanglongZadan_List.max_size() ? E_YanglongZadan_List.max_size() : msg.e_yanglongzadan_list_size());
	for(int32_t i = 0; i < (int32_t)E_YanglongZadan_List.size(); ++i) {
		const ::proto_ff::E_YanglongZadan & temp_e_yanglongzadan_list = msg.e_yanglongzadan_list(i);
		E_YanglongZadan_List[i].read_from_pbmsg(temp_e_yanglongzadan_list);
	}
}

E_YanglongRanking_s::E_YanglongRanking_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_YanglongRanking_s::CreateInit() {
	m_rankingid = (int32_t)0;
	m_rank = (int32_t)0;
	m_boxid = (int32_t)0;
	return 0;
}

int E_YanglongRanking_s::ResumeInit() {
	return 0;
}

void E_YanglongRanking_s::write_to_pbmsg(::proto_ff::E_YanglongRanking & msg) const {
	msg.set_m_rankingid((int32_t)m_rankingid);
	msg.set_m_rank((int32_t)m_rank);
	msg.set_m_boxid((int32_t)m_boxid);
}

void E_YanglongRanking_s::read_from_pbmsg(const ::proto_ff::E_YanglongRanking & msg) {
	m_rankingid = msg.m_rankingid();
	m_rank = msg.m_rank();
	m_boxid = msg.m_boxid();
}

Sheet_YanglongRanking_s::Sheet_YanglongRanking_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_YanglongRanking_s::CreateInit() {
	return 0;
}

int Sheet_YanglongRanking_s::ResumeInit() {
	return 0;
}

void Sheet_YanglongRanking_s::write_to_pbmsg(::proto_ff::Sheet_YanglongRanking & msg) const {
	for(int32_t i = 0; i < (int32_t)E_YanglongRanking_List.size(); ++i) {
		::proto_ff::E_YanglongRanking* temp_e_yanglongranking_list = msg.add_e_yanglongranking_list();
		E_YanglongRanking_List[i].write_to_pbmsg(*temp_e_yanglongranking_list);
	}
}

void Sheet_YanglongRanking_s::read_from_pbmsg(const ::proto_ff::Sheet_YanglongRanking & msg) {
	E_YanglongRanking_List.resize((int)msg.e_yanglongranking_list_size() > (int)E_YanglongRanking_List.max_size() ? E_YanglongRanking_List.max_size() : msg.e_yanglongranking_list_size());
	for(int32_t i = 0; i < (int32_t)E_YanglongRanking_List.size(); ++i) {
		const ::proto_ff::E_YanglongRanking & temp_e_yanglongranking_list = msg.e_yanglongranking_list(i);
		E_YanglongRanking_List[i].read_from_pbmsg(temp_e_yanglongranking_list);
	}
}

}
