#include "E_Nickgod_s.h"

namespace proto_ff_s {

E_NickgodConstant_s::E_NickgodConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodConstant_s::CreateInit() {
	m_id = (int64_t)0;
	m_skill = (int32_t)0;
	m_time = (int32_t)0;
	m_maxUser = (int32_t)0;
	m_floorsMax = (int32_t)0;
	m_lattice = (int32_t)0;
	m_repairItem = (int32_t)0;
	m_repairNum = (int32_t)0;
	m_openItem = (int32_t)0;
	m_openNum = (int32_t)0;
	m_opentime = (int32_t)0;
	m_endtime = (int32_t)0;
	m_logMax = (int32_t)0;
	m_readyMap = (int32_t)0;
	m_readyPiont = (int32_t)0;
	m_actId = (int32_t)0;
	return 0;
}

int E_NickgodConstant_s::ResumeInit() {
	return 0;
}

void E_NickgodConstant_s::write_to_pbmsg(::proto_ff::E_NickgodConstant & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_skill((int32_t)m_skill);
	msg.set_m_time((int32_t)m_time);
	msg.set_m_maxuser((int32_t)m_maxUser);
	msg.set_m_floorsmax((int32_t)m_floorsMax);
	msg.set_m_lattice((int32_t)m_lattice);
	msg.set_m_repairitem((int32_t)m_repairItem);
	msg.set_m_repairnum((int32_t)m_repairNum);
	msg.set_m_openitem((int32_t)m_openItem);
	msg.set_m_opennum((int32_t)m_openNum);
	msg.set_m_week(m_week.data());
	msg.set_m_opentime((int32_t)m_opentime);
	msg.set_m_endtime((int32_t)m_endtime);
	msg.set_m_logmax((int32_t)m_logMax);
	msg.set_m_readymap((int32_t)m_readyMap);
	msg.set_m_readypiont((int32_t)m_readyPiont);
	msg.set_m_actid((int32_t)m_actId);
}

void E_NickgodConstant_s::read_from_pbmsg(const ::proto_ff::E_NickgodConstant & msg) {
	m_id = msg.m_id();
	m_skill = msg.m_skill();
	m_time = msg.m_time();
	m_maxUser = msg.m_maxuser();
	m_floorsMax = msg.m_floorsmax();
	m_lattice = msg.m_lattice();
	m_repairItem = msg.m_repairitem();
	m_repairNum = msg.m_repairnum();
	m_openItem = msg.m_openitem();
	m_openNum = msg.m_opennum();
	m_week = msg.m_week();
	m_opentime = msg.m_opentime();
	m_endtime = msg.m_endtime();
	m_logMax = msg.m_logmax();
	m_readyMap = msg.m_readymap();
	m_readyPiont = msg.m_readypiont();
	m_actId = msg.m_actid();
}

Sheet_NickgodConstant_s::Sheet_NickgodConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_NickgodConstant_s::CreateInit() {
	return 0;
}

int Sheet_NickgodConstant_s::ResumeInit() {
	return 0;
}

void Sheet_NickgodConstant_s::write_to_pbmsg(::proto_ff::Sheet_NickgodConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_NickgodConstant_List.size(); ++i) {
		::proto_ff::E_NickgodConstant* temp_e_nickgodconstant_list = msg.add_e_nickgodconstant_list();
		E_NickgodConstant_List[i].write_to_pbmsg(*temp_e_nickgodconstant_list);
	}
}

void Sheet_NickgodConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_NickgodConstant & msg) {
	E_NickgodConstant_List.resize((int)msg.e_nickgodconstant_list_size() > (int)E_NickgodConstant_List.max_size() ? E_NickgodConstant_List.max_size() : msg.e_nickgodconstant_list_size());
	for(int32_t i = 0; i < (int32_t)E_NickgodConstant_List.size(); ++i) {
		const ::proto_ff::E_NickgodConstant & temp_e_nickgodconstant_list = msg.e_nickgodconstant_list(i);
		E_NickgodConstant_List[i].read_from_pbmsg(temp_e_nickgodconstant_list);
	}
}

E_NickgodName_s::E_NickgodName_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodName_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_NickgodName_s::ResumeInit() {
	return 0;
}

void E_NickgodName_s::write_to_pbmsg(::proto_ff::E_NickgodName & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
}

void E_NickgodName_s::read_from_pbmsg(const ::proto_ff::E_NickgodName & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
}

Sheet_NickgodName_s::Sheet_NickgodName_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_NickgodName_s::CreateInit() {
	return 0;
}

int Sheet_NickgodName_s::ResumeInit() {
	return 0;
}

void Sheet_NickgodName_s::write_to_pbmsg(::proto_ff::Sheet_NickgodName & msg) const {
	for(int32_t i = 0; i < (int32_t)E_NickgodName_List.size(); ++i) {
		::proto_ff::E_NickgodName* temp_e_nickgodname_list = msg.add_e_nickgodname_list();
		E_NickgodName_List[i].write_to_pbmsg(*temp_e_nickgodname_list);
	}
}

void Sheet_NickgodName_s::read_from_pbmsg(const ::proto_ff::Sheet_NickgodName & msg) {
	E_NickgodName_List.resize((int)msg.e_nickgodname_list_size() > (int)E_NickgodName_List.max_size() ? E_NickgodName_List.max_size() : msg.e_nickgodname_list_size());
	for(int32_t i = 0; i < (int32_t)E_NickgodName_List.size(); ++i) {
		const ::proto_ff::E_NickgodName & temp_e_nickgodname_list = msg.e_nickgodname_list(i);
		E_NickgodName_List[i].read_from_pbmsg(temp_e_nickgodname_list);
	}
}

E_NickgodStageMosDesc_s::E_NickgodStageMosDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodStageMosDesc_s::CreateInit() {
	m_id = (int32_t)0;
	m_point = (int32_t)0;
	return 0;
}

int E_NickgodStageMosDesc_s::ResumeInit() {
	return 0;
}

void E_NickgodStageMosDesc_s::write_to_pbmsg(::proto_ff::E_NickgodStageMosDesc & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_point((int32_t)m_point);
}

void E_NickgodStageMosDesc_s::read_from_pbmsg(const ::proto_ff::E_NickgodStageMosDesc & msg) {
	m_id = msg.m_id();
	m_point = msg.m_point();
}

E_NickgodStageBossDesc_s::E_NickgodStageBossDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodStageBossDesc_s::CreateInit() {
	m_id = (int32_t)0;
	m_point = (int32_t)0;
	return 0;
}

int E_NickgodStageBossDesc_s::ResumeInit() {
	return 0;
}

void E_NickgodStageBossDesc_s::write_to_pbmsg(::proto_ff::E_NickgodStageBossDesc & msg) const {
	msg.set_m_droppreview(m_dropPreview.data());
	msg.set_m_id((int32_t)m_id);
	msg.set_m_point((int32_t)m_point);
}

void E_NickgodStageBossDesc_s::read_from_pbmsg(const ::proto_ff::E_NickgodStageBossDesc & msg) {
	m_dropPreview = msg.m_droppreview();
	m_id = msg.m_id();
	m_point = msg.m_point();
}

E_NickgodStage_s::E_NickgodStage_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodStage_s::CreateInit() {
	m_id = (int32_t)0;
	m_map = (int32_t)0;
	m_duration = (int32_t)0;
	m_mosDieRefresh = (int32_t)0;
	m_bossFirstRefresh = (int32_t)0;
	m_bossDieRefresh = (int32_t)0;
	m_playerDieDrop = (int32_t)0;
	m_sceneIntegralTime = (int32_t)0;
	m_sceneIntegral = (int32_t)0;
	m_killmosIntegral = (int32_t)0;
	m_killbossIntegral = (int32_t)0;
	m_killplayerIntegral = (int32_t)0;
	m_assistplayerIntegral = (int32_t)0;
	return 0;
}

int E_NickgodStage_s::ResumeInit() {
	return 0;
}

void E_NickgodStage_s::write_to_pbmsg(::proto_ff::E_NickgodStage & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_map((int32_t)m_map);
	msg.set_m_duration((int32_t)m_duration);
	msg.set_m_mosdierefresh((int32_t)m_mosDieRefresh);
	msg.set_m_bossfirstrefresh((int32_t)m_bossFirstRefresh);
	msg.set_m_bossdierefresh((int32_t)m_bossDieRefresh);
	msg.set_m_playerdiedrop((int32_t)m_playerDieDrop);
	msg.set_m_sceneintegraltime((int32_t)m_sceneIntegralTime);
	msg.set_m_sceneintegral((int32_t)m_sceneIntegral);
	msg.set_m_killmosintegral((int32_t)m_killmosIntegral);
	msg.set_m_killbossintegral((int32_t)m_killbossIntegral);
	msg.set_m_killplayerintegral((int32_t)m_killplayerIntegral);
	msg.set_m_assistplayerintegral((int32_t)m_assistplayerIntegral);
	for(int32_t i = 0; i < (int32_t)m_mos.size(); ++i) {
		::proto_ff::E_NickgodStageMosDesc* temp_m_mos = msg.add_m_mos();
		m_mos[i].write_to_pbmsg(*temp_m_mos);
	}
	for(int32_t i = 0; i < (int32_t)m_boss.size(); ++i) {
		::proto_ff::E_NickgodStageBossDesc* temp_m_boss = msg.add_m_boss();
		m_boss[i].write_to_pbmsg(*temp_m_boss);
	}
	for(int32_t i = 0; i < (int32_t)m_revivalPoint.size(); ++i) {
		msg.add_m_revivalpoint((int32_t)m_revivalPoint[i]);
	}
}

void E_NickgodStage_s::read_from_pbmsg(const ::proto_ff::E_NickgodStage & msg) {
	m_id = msg.m_id();
	m_map = msg.m_map();
	m_duration = msg.m_duration();
	m_mosDieRefresh = msg.m_mosdierefresh();
	m_bossFirstRefresh = msg.m_bossfirstrefresh();
	m_bossDieRefresh = msg.m_bossdierefresh();
	m_playerDieDrop = msg.m_playerdiedrop();
	m_sceneIntegralTime = msg.m_sceneintegraltime();
	m_sceneIntegral = msg.m_sceneintegral();
	m_killmosIntegral = msg.m_killmosintegral();
	m_killbossIntegral = msg.m_killbossintegral();
	m_killplayerIntegral = msg.m_killplayerintegral();
	m_assistplayerIntegral = msg.m_assistplayerintegral();
	m_mos.resize((int)msg.m_mos_size() > (int)m_mos.max_size() ? m_mos.max_size() : msg.m_mos_size());
	for(int32_t i = 0; i < (int32_t)m_mos.size(); ++i) {
		const ::proto_ff::E_NickgodStageMosDesc & temp_m_mos = msg.m_mos(i);
		m_mos[i].read_from_pbmsg(temp_m_mos);
	}
	m_boss.resize((int)msg.m_boss_size() > (int)m_boss.max_size() ? m_boss.max_size() : msg.m_boss_size());
	for(int32_t i = 0; i < (int32_t)m_boss.size(); ++i) {
		const ::proto_ff::E_NickgodStageBossDesc & temp_m_boss = msg.m_boss(i);
		m_boss[i].read_from_pbmsg(temp_m_boss);
	}
	m_revivalPoint.resize((int)msg.m_revivalpoint_size() > (int)m_revivalPoint.max_size() ? m_revivalPoint.max_size() : msg.m_revivalpoint_size());
	for(int32_t i = 0; i < (int32_t)m_revivalPoint.size(); ++i) {
		m_revivalPoint[i] = msg.m_revivalpoint(i);
	}
}

Sheet_NickgodStage_s::Sheet_NickgodStage_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_NickgodStage_s::CreateInit() {
	return 0;
}

int Sheet_NickgodStage_s::ResumeInit() {
	return 0;
}

void Sheet_NickgodStage_s::write_to_pbmsg(::proto_ff::Sheet_NickgodStage & msg) const {
	for(int32_t i = 0; i < (int32_t)E_NickgodStage_List.size(); ++i) {
		::proto_ff::E_NickgodStage* temp_e_nickgodstage_list = msg.add_e_nickgodstage_list();
		E_NickgodStage_List[i].write_to_pbmsg(*temp_e_nickgodstage_list);
	}
}

void Sheet_NickgodStage_s::read_from_pbmsg(const ::proto_ff::Sheet_NickgodStage & msg) {
	E_NickgodStage_List.resize((int)msg.e_nickgodstage_list_size() > (int)E_NickgodStage_List.max_size() ? E_NickgodStage_List.max_size() : msg.e_nickgodstage_list_size());
	for(int32_t i = 0; i < (int32_t)E_NickgodStage_List.size(); ++i) {
		const ::proto_ff::E_NickgodStage & temp_e_nickgodstage_list = msg.e_nickgodstage_list(i);
		E_NickgodStage_List[i].read_from_pbmsg(temp_e_nickgodstage_list);
	}
}

E_NickgodRewardsRewardDesc_s::E_NickgodRewardsRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodRewardsRewardDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_ID = (int64_t)0;
	return 0;
}

int E_NickgodRewardsRewardDesc_s::ResumeInit() {
	return 0;
}

void E_NickgodRewardsRewardDesc_s::write_to_pbmsg(::proto_ff::E_NickgodRewardsRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int64_t)m_ID);
}

void E_NickgodRewardsRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_NickgodRewardsRewardDesc & msg) {
	m_Num = msg.m_num();
	m_ID = msg.m_id();
}

E_NickgodRewards_s::E_NickgodRewards_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodRewards_s::CreateInit() {
	m_id = (int32_t)0;
	m_rankingMin = (int32_t)0;
	m_rankingMax = (int32_t)0;
	m_score = (int32_t)0;
	return 0;
}

int E_NickgodRewards_s::ResumeInit() {
	return 0;
}

void E_NickgodRewards_s::write_to_pbmsg(::proto_ff::E_NickgodRewards & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_rankingmin((int32_t)m_rankingMin);
	msg.set_m_rankingmax((int32_t)m_rankingMax);
	msg.set_m_score((int32_t)m_score);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_NickgodRewardsRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_NickgodRewards_s::read_from_pbmsg(const ::proto_ff::E_NickgodRewards & msg) {
	m_id = msg.m_id();
	m_rankingMin = msg.m_rankingmin();
	m_rankingMax = msg.m_rankingmax();
	m_score = msg.m_score();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_NickgodRewardsRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_NickgodRewards_s::Sheet_NickgodRewards_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_NickgodRewards_s::CreateInit() {
	return 0;
}

int Sheet_NickgodRewards_s::ResumeInit() {
	return 0;
}

void Sheet_NickgodRewards_s::write_to_pbmsg(::proto_ff::Sheet_NickgodRewards & msg) const {
	for(int32_t i = 0; i < (int32_t)E_NickgodRewards_List.size(); ++i) {
		::proto_ff::E_NickgodRewards* temp_e_nickgodrewards_list = msg.add_e_nickgodrewards_list();
		E_NickgodRewards_List[i].write_to_pbmsg(*temp_e_nickgodrewards_list);
	}
}

void Sheet_NickgodRewards_s::read_from_pbmsg(const ::proto_ff::Sheet_NickgodRewards & msg) {
	E_NickgodRewards_List.resize((int)msg.e_nickgodrewards_list_size() > (int)E_NickgodRewards_List.max_size() ? E_NickgodRewards_List.max_size() : msg.e_nickgodrewards_list_size());
	for(int32_t i = 0; i < (int32_t)E_NickgodRewards_List.size(); ++i) {
		const ::proto_ff::E_NickgodRewards & temp_e_nickgodrewards_list = msg.e_nickgodrewards_list(i);
		E_NickgodRewards_List[i].read_from_pbmsg(temp_e_nickgodrewards_list);
	}
}

E_NickgodLattice_s::E_NickgodLattice_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodLattice_s::CreateInit() {
	m_id = (int32_t)0;
	m_itemId = (int32_t)0;
	m_itemNum = (int32_t)0;
	return 0;
}

int E_NickgodLattice_s::ResumeInit() {
	return 0;
}

void E_NickgodLattice_s::write_to_pbmsg(::proto_ff::E_NickgodLattice & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_itemid((int32_t)m_itemId);
	msg.set_m_itemnum((int32_t)m_itemNum);
}

void E_NickgodLattice_s::read_from_pbmsg(const ::proto_ff::E_NickgodLattice & msg) {
	m_id = msg.m_id();
	m_itemId = msg.m_itemid();
	m_itemNum = msg.m_itemnum();
}

Sheet_NickgodLattice_s::Sheet_NickgodLattice_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_NickgodLattice_s::CreateInit() {
	return 0;
}

int Sheet_NickgodLattice_s::ResumeInit() {
	return 0;
}

void Sheet_NickgodLattice_s::write_to_pbmsg(::proto_ff::Sheet_NickgodLattice & msg) const {
	for(int32_t i = 0; i < (int32_t)E_NickgodLattice_List.size(); ++i) {
		::proto_ff::E_NickgodLattice* temp_e_nickgodlattice_list = msg.add_e_nickgodlattice_list();
		E_NickgodLattice_List[i].write_to_pbmsg(*temp_e_nickgodlattice_list);
	}
}

void Sheet_NickgodLattice_s::read_from_pbmsg(const ::proto_ff::Sheet_NickgodLattice & msg) {
	E_NickgodLattice_List.resize((int)msg.e_nickgodlattice_list_size() > (int)E_NickgodLattice_List.max_size() ? E_NickgodLattice_List.max_size() : msg.e_nickgodlattice_list_size());
	for(int32_t i = 0; i < (int32_t)E_NickgodLattice_List.size(); ++i) {
		const ::proto_ff::E_NickgodLattice & temp_e_nickgodlattice_list = msg.e_nickgodlattice_list(i);
		E_NickgodLattice_List[i].read_from_pbmsg(temp_e_nickgodlattice_list);
	}
}

E_NickgodTreasuryItemDesc_s::E_NickgodTreasuryItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodTreasuryItemDesc_s::CreateInit() {
	m_show = (int32_t)0;
	m_rand = (int32_t)0;
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_NickgodTreasuryItemDesc_s::ResumeInit() {
	return 0;
}

void E_NickgodTreasuryItemDesc_s::write_to_pbmsg(::proto_ff::E_NickgodTreasuryItemDesc & msg) const {
	msg.set_m_show((int32_t)m_show);
	msg.set_m_rand((int32_t)m_rand);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_NickgodTreasuryItemDesc_s::read_from_pbmsg(const ::proto_ff::E_NickgodTreasuryItemDesc & msg) {
	m_show = msg.m_show();
	m_rand = msg.m_rand();
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_NickgodTreasury_s::E_NickgodTreasury_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodTreasury_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_NickgodTreasury_s::ResumeInit() {
	return 0;
}

void E_NickgodTreasury_s::write_to_pbmsg(::proto_ff::E_NickgodTreasury & msg) const {
	msg.set_m_id((int32_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_NickgodTreasuryItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_NickgodTreasury_s::read_from_pbmsg(const ::proto_ff::E_NickgodTreasury & msg) {
	m_id = msg.m_id();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_NickgodTreasuryItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
}

Sheet_NickgodTreasury_s::Sheet_NickgodTreasury_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_NickgodTreasury_s::CreateInit() {
	return 0;
}

int Sheet_NickgodTreasury_s::ResumeInit() {
	return 0;
}

void Sheet_NickgodTreasury_s::write_to_pbmsg(::proto_ff::Sheet_NickgodTreasury & msg) const {
	for(int32_t i = 0; i < (int32_t)E_NickgodTreasury_List.size(); ++i) {
		::proto_ff::E_NickgodTreasury* temp_e_nickgodtreasury_list = msg.add_e_nickgodtreasury_list();
		E_NickgodTreasury_List[i].write_to_pbmsg(*temp_e_nickgodtreasury_list);
	}
}

void Sheet_NickgodTreasury_s::read_from_pbmsg(const ::proto_ff::Sheet_NickgodTreasury & msg) {
	E_NickgodTreasury_List.resize((int)msg.e_nickgodtreasury_list_size() > (int)E_NickgodTreasury_List.max_size() ? E_NickgodTreasury_List.max_size() : msg.e_nickgodtreasury_list_size());
	for(int32_t i = 0; i < (int32_t)E_NickgodTreasury_List.size(); ++i) {
		const ::proto_ff::E_NickgodTreasury & temp_e_nickgodtreasury_list = msg.e_nickgodtreasury_list(i);
		E_NickgodTreasury_List[i].read_from_pbmsg(temp_e_nickgodtreasury_list);
	}
}

E_NickgodPrivilegeRewardDesc_s::E_NickgodPrivilegeRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodPrivilegeRewardDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_ID = (int64_t)0;
	return 0;
}

int E_NickgodPrivilegeRewardDesc_s::ResumeInit() {
	return 0;
}

void E_NickgodPrivilegeRewardDesc_s::write_to_pbmsg(::proto_ff::E_NickgodPrivilegeRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int64_t)m_ID);
}

void E_NickgodPrivilegeRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_NickgodPrivilegeRewardDesc & msg) {
	m_Num = msg.m_num();
	m_ID = msg.m_id();
}

E_NickgodPrivilege_s::E_NickgodPrivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodPrivilege_s::CreateInit() {
	m_id = (int32_t)0;
	m_condition = (int32_t)0;
	m_param = (int32_t)0;
	m_open = (int32_t)0;
	return 0;
}

int E_NickgodPrivilege_s::ResumeInit() {
	return 0;
}

void E_NickgodPrivilege_s::write_to_pbmsg(::proto_ff::E_NickgodPrivilege & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_condition((int32_t)m_condition);
	msg.set_m_param((int32_t)m_param);
	msg.set_m_open((int32_t)m_open);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_NickgodPrivilegeRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_NickgodPrivilege_s::read_from_pbmsg(const ::proto_ff::E_NickgodPrivilege & msg) {
	m_id = msg.m_id();
	m_condition = msg.m_condition();
	m_param = msg.m_param();
	m_open = msg.m_open();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_NickgodPrivilegeRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_NickgodPrivilege_s::Sheet_NickgodPrivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_NickgodPrivilege_s::CreateInit() {
	return 0;
}

int Sheet_NickgodPrivilege_s::ResumeInit() {
	return 0;
}

void Sheet_NickgodPrivilege_s::write_to_pbmsg(::proto_ff::Sheet_NickgodPrivilege & msg) const {
	for(int32_t i = 0; i < (int32_t)E_NickgodPrivilege_List.size(); ++i) {
		::proto_ff::E_NickgodPrivilege* temp_e_nickgodprivilege_list = msg.add_e_nickgodprivilege_list();
		E_NickgodPrivilege_List[i].write_to_pbmsg(*temp_e_nickgodprivilege_list);
	}
}

void Sheet_NickgodPrivilege_s::read_from_pbmsg(const ::proto_ff::Sheet_NickgodPrivilege & msg) {
	E_NickgodPrivilege_List.resize((int)msg.e_nickgodprivilege_list_size() > (int)E_NickgodPrivilege_List.max_size() ? E_NickgodPrivilege_List.max_size() : msg.e_nickgodprivilege_list_size());
	for(int32_t i = 0; i < (int32_t)E_NickgodPrivilege_List.size(); ++i) {
		const ::proto_ff::E_NickgodPrivilege & temp_e_nickgodprivilege_list = msg.e_nickgodprivilege_list(i);
		E_NickgodPrivilege_List[i].read_from_pbmsg(temp_e_nickgodprivilege_list);
	}
}

E_NickgodSaleItemDesc_s::E_NickgodSaleItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodSaleItemDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_ID = (int64_t)0;
	return 0;
}

int E_NickgodSaleItemDesc_s::ResumeInit() {
	return 0;
}

void E_NickgodSaleItemDesc_s::write_to_pbmsg(::proto_ff::E_NickgodSaleItemDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int64_t)m_ID);
}

void E_NickgodSaleItemDesc_s::read_from_pbmsg(const ::proto_ff::E_NickgodSaleItemDesc & msg) {
	m_Num = msg.m_num();
	m_ID = msg.m_id();
}

E_NickgodSale_s::E_NickgodSale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodSale_s::CreateInit() {
	m_id = (int32_t)0;
	m_money = (int32_t)0;
	m_price = (int32_t)0;
	m_buyLimit = (int32_t)0;
	return 0;
}

int E_NickgodSale_s::ResumeInit() {
	return 0;
}

void E_NickgodSale_s::write_to_pbmsg(::proto_ff::E_NickgodSale & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_discount(m_discount.data());
	msg.set_m_money((int32_t)m_money);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_buylimit((int32_t)m_buyLimit);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_NickgodSaleItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_NickgodSale_s::read_from_pbmsg(const ::proto_ff::E_NickgodSale & msg) {
	m_id = msg.m_id();
	m_discount = msg.m_discount();
	m_money = msg.m_money();
	m_price = msg.m_price();
	m_buyLimit = msg.m_buylimit();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_NickgodSaleItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
}

Sheet_NickgodSale_s::Sheet_NickgodSale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_NickgodSale_s::CreateInit() {
	return 0;
}

int Sheet_NickgodSale_s::ResumeInit() {
	return 0;
}

void Sheet_NickgodSale_s::write_to_pbmsg(::proto_ff::Sheet_NickgodSale & msg) const {
	for(int32_t i = 0; i < (int32_t)E_NickgodSale_List.size(); ++i) {
		::proto_ff::E_NickgodSale* temp_e_nickgodsale_list = msg.add_e_nickgodsale_list();
		E_NickgodSale_List[i].write_to_pbmsg(*temp_e_nickgodsale_list);
	}
}

void Sheet_NickgodSale_s::read_from_pbmsg(const ::proto_ff::Sheet_NickgodSale & msg) {
	E_NickgodSale_List.resize((int)msg.e_nickgodsale_list_size() > (int)E_NickgodSale_List.max_size() ? E_NickgodSale_List.max_size() : msg.e_nickgodsale_list_size());
	for(int32_t i = 0; i < (int32_t)E_NickgodSale_List.size(); ++i) {
		const ::proto_ff::E_NickgodSale & temp_e_nickgodsale_list = msg.e_nickgodsale_list(i);
		E_NickgodSale_List[i].read_from_pbmsg(temp_e_nickgodsale_list);
	}
}

E_NickgodChargeupRewardDesc_s::E_NickgodChargeupRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodChargeupRewardDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_ID = (int64_t)0;
	return 0;
}

int E_NickgodChargeupRewardDesc_s::ResumeInit() {
	return 0;
}

void E_NickgodChargeupRewardDesc_s::write_to_pbmsg(::proto_ff::E_NickgodChargeupRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int64_t)m_ID);
}

void E_NickgodChargeupRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_NickgodChargeupRewardDesc & msg) {
	m_Num = msg.m_num();
	m_ID = msg.m_id();
}

E_NickgodChargeup_s::E_NickgodChargeup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_NickgodChargeup_s::CreateInit() {
	m_id = (int32_t)0;
	m_pay = (int32_t)0;
	return 0;
}

int E_NickgodChargeup_s::ResumeInit() {
	return 0;
}

void E_NickgodChargeup_s::write_to_pbmsg(::proto_ff::E_NickgodChargeup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_pay((int32_t)m_pay);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_NickgodChargeupRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_NickgodChargeup_s::read_from_pbmsg(const ::proto_ff::E_NickgodChargeup & msg) {
	m_id = msg.m_id();
	m_pay = msg.m_pay();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_NickgodChargeupRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_NickgodChargeup_s::Sheet_NickgodChargeup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_NickgodChargeup_s::CreateInit() {
	return 0;
}

int Sheet_NickgodChargeup_s::ResumeInit() {
	return 0;
}

void Sheet_NickgodChargeup_s::write_to_pbmsg(::proto_ff::Sheet_NickgodChargeup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_NickgodChargeup_List.size(); ++i) {
		::proto_ff::E_NickgodChargeup* temp_e_nickgodchargeup_list = msg.add_e_nickgodchargeup_list();
		E_NickgodChargeup_List[i].write_to_pbmsg(*temp_e_nickgodchargeup_list);
	}
}

void Sheet_NickgodChargeup_s::read_from_pbmsg(const ::proto_ff::Sheet_NickgodChargeup & msg) {
	E_NickgodChargeup_List.resize((int)msg.e_nickgodchargeup_list_size() > (int)E_NickgodChargeup_List.max_size() ? E_NickgodChargeup_List.max_size() : msg.e_nickgodchargeup_list_size());
	for(int32_t i = 0; i < (int32_t)E_NickgodChargeup_List.size(); ++i) {
		const ::proto_ff::E_NickgodChargeup & temp_e_nickgodchargeup_list = msg.e_nickgodchargeup_list(i);
		E_NickgodChargeup_List[i].read_from_pbmsg(temp_e_nickgodchargeup_list);
	}
}

}
