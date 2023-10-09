#include "arena_s.h"

namespace proto_ff_s {

E_ArenaRobotAttrDesc_s::E_ArenaRobotAttrDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ArenaRobotAttrDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_val = (int32_t)0;
	return 0;
}

int E_ArenaRobotAttrDesc_s::ResumeInit() {
	return 0;
}

void E_ArenaRobotAttrDesc_s::write_to_pbmsg(::proto_ff::E_ArenaRobotAttrDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_val((int32_t)m_val);
}

void E_ArenaRobotAttrDesc_s::read_from_pbmsg(const ::proto_ff::E_ArenaRobotAttrDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ArenaRobotAttrDesc_s));
	m_type = msg.m_type();
	m_val = msg.m_val();
}

E_ArenaRobot_s::E_ArenaRobot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ArenaRobot_s::CreateInit() {
	m_arenaid = (int32_t)0;
	m_aiid = (int32_t)0;
	m_rankid = (int32_t)0;
	m_robotprofession = (int32_t)0;
	m_robotlv = (int32_t)0;
	m_sword = (int32_t)0;
	m_facadeid = (int32_t)0;
	m_occupationid = (int32_t)0;
	return 0;
}

int E_ArenaRobot_s::ResumeInit() {
	return 0;
}

void E_ArenaRobot_s::write_to_pbmsg(::proto_ff::E_ArenaRobot & msg) const {
	msg.set_m_arenaid((int32_t)m_arenaid);
	msg.set_m_robotname((const char*)m_robotname.data());
	msg.set_m_aiid((int32_t)m_aiid);
	msg.set_m_rankid((int32_t)m_rankid);
	msg.set_m_robotprofession((int32_t)m_robotprofession);
	msg.set_m_robotlv((int32_t)m_robotlv);
	msg.set_m_sword((int32_t)m_sword);
	msg.set_m_facadeid((int32_t)m_facadeid);
	msg.set_m_occupationid((int32_t)m_occupationid);
	for(int32_t i = 0; i < (int32_t)m_attr.size(); ++i) {
		::proto_ff::E_ArenaRobotAttrDesc* temp_m_attr = msg.add_m_attr();
		m_attr[i].write_to_pbmsg(*temp_m_attr);
	}
}

void E_ArenaRobot_s::read_from_pbmsg(const ::proto_ff::E_ArenaRobot & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ArenaRobot_s));
	m_arenaid = msg.m_arenaid();
	m_robotname = msg.m_robotname();
	m_aiid = msg.m_aiid();
	m_rankid = msg.m_rankid();
	m_robotprofession = msg.m_robotprofession();
	m_robotlv = msg.m_robotlv();
	m_sword = msg.m_sword();
	m_facadeid = msg.m_facadeid();
	m_occupationid = msg.m_occupationid();
	m_attr.resize((int)msg.m_attr_size() > (int)m_attr.max_size() ? m_attr.max_size() : msg.m_attr_size());
	for(int32_t i = 0; i < (int32_t)m_attr.size(); ++i) {
		const ::proto_ff::E_ArenaRobotAttrDesc & temp_m_attr = msg.m_attr(i);
		m_attr[i].read_from_pbmsg(temp_m_attr);
	}
}

Sheet_ArenaRobot_s::Sheet_ArenaRobot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ArenaRobot_s::CreateInit() {
	return 0;
}

int Sheet_ArenaRobot_s::ResumeInit() {
	return 0;
}

void Sheet_ArenaRobot_s::write_to_pbmsg(::proto_ff::Sheet_ArenaRobot & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ArenaRobot_List.size(); ++i) {
		::proto_ff::E_ArenaRobot* temp_e_arenarobot_list = msg.add_e_arenarobot_list();
		E_ArenaRobot_List[i].write_to_pbmsg(*temp_e_arenarobot_list);
	}
}

void Sheet_ArenaRobot_s::read_from_pbmsg(const ::proto_ff::Sheet_ArenaRobot & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_ArenaRobot_s));
	E_ArenaRobot_List.resize((int)msg.e_arenarobot_list_size() > (int)E_ArenaRobot_List.max_size() ? E_ArenaRobot_List.max_size() : msg.e_arenarobot_list_size());
	for(int32_t i = 0; i < (int32_t)E_ArenaRobot_List.size(); ++i) {
		const ::proto_ff::E_ArenaRobot & temp_e_arenarobot_list = msg.e_arenarobot_list(i);
		E_ArenaRobot_List[i].read_from_pbmsg(temp_e_arenarobot_list);
	}
}

E_ArenaRobotfacadeFacadeDesc_s::E_ArenaRobotfacadeFacadeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ArenaRobotfacadeFacadeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_ArenaRobotfacadeFacadeDesc_s::ResumeInit() {
	return 0;
}

void E_ArenaRobotfacadeFacadeDesc_s::write_to_pbmsg(::proto_ff::E_ArenaRobotfacadeFacadeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_ArenaRobotfacadeFacadeDesc_s::read_from_pbmsg(const ::proto_ff::E_ArenaRobotfacadeFacadeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ArenaRobotfacadeFacadeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_ArenaRobotfacade_s::E_ArenaRobotfacade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ArenaRobotfacade_s::CreateInit() {
	m_id = (int32_t)0;
	m_color = (int32_t)0;
	return 0;
}

int E_ArenaRobotfacade_s::ResumeInit() {
	return 0;
}

void E_ArenaRobotfacade_s::write_to_pbmsg(::proto_ff::E_ArenaRobotfacade & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_color((int32_t)m_color);
	for(int32_t i = 0; i < (int32_t)m_facade.size(); ++i) {
		::proto_ff::E_ArenaRobotfacadeFacadeDesc* temp_m_facade = msg.add_m_facade();
		m_facade[i].write_to_pbmsg(*temp_m_facade);
	}
}

void E_ArenaRobotfacade_s::read_from_pbmsg(const ::proto_ff::E_ArenaRobotfacade & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ArenaRobotfacade_s));
	m_id = msg.m_id();
	m_color = msg.m_color();
	m_facade.resize((int)msg.m_facade_size() > (int)m_facade.max_size() ? m_facade.max_size() : msg.m_facade_size());
	for(int32_t i = 0; i < (int32_t)m_facade.size(); ++i) {
		const ::proto_ff::E_ArenaRobotfacadeFacadeDesc & temp_m_facade = msg.m_facade(i);
		m_facade[i].read_from_pbmsg(temp_m_facade);
	}
}

Sheet_ArenaRobotfacade_s::Sheet_ArenaRobotfacade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ArenaRobotfacade_s::CreateInit() {
	return 0;
}

int Sheet_ArenaRobotfacade_s::ResumeInit() {
	return 0;
}

void Sheet_ArenaRobotfacade_s::write_to_pbmsg(::proto_ff::Sheet_ArenaRobotfacade & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ArenaRobotfacade_List.size(); ++i) {
		::proto_ff::E_ArenaRobotfacade* temp_e_arenarobotfacade_list = msg.add_e_arenarobotfacade_list();
		E_ArenaRobotfacade_List[i].write_to_pbmsg(*temp_e_arenarobotfacade_list);
	}
}

void Sheet_ArenaRobotfacade_s::read_from_pbmsg(const ::proto_ff::Sheet_ArenaRobotfacade & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_ArenaRobotfacade_s));
	E_ArenaRobotfacade_List.resize((int)msg.e_arenarobotfacade_list_size() > (int)E_ArenaRobotfacade_List.max_size() ? E_ArenaRobotfacade_List.max_size() : msg.e_arenarobotfacade_list_size());
	for(int32_t i = 0; i < (int32_t)E_ArenaRobotfacade_List.size(); ++i) {
		const ::proto_ff::E_ArenaRobotfacade & temp_e_arenarobotfacade_list = msg.e_arenarobotfacade_list(i);
		E_ArenaRobotfacade_List[i].read_from_pbmsg(temp_e_arenarobotfacade_list);
	}
}

E_ArenaArenawardRewardDesc_s::E_ArenaArenawardRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ArenaArenawardRewardDesc_s::CreateInit() {
	m_id = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_ArenaArenawardRewardDesc_s::ResumeInit() {
	return 0;
}

void E_ArenaArenawardRewardDesc_s::write_to_pbmsg(::proto_ff::E_ArenaArenawardRewardDesc & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_value((int32_t)m_value);
}

void E_ArenaArenawardRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_ArenaArenawardRewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ArenaArenawardRewardDesc_s));
	m_id = msg.m_id();
	m_value = msg.m_value();
}

E_ArenaArenaward_s::E_ArenaArenaward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ArenaArenaward_s::CreateInit() {
	m_id = (int32_t)0;
	m_lvdown = (int32_t)0;
	m_lvup = (int32_t)0;
	return 0;
}

int E_ArenaArenaward_s::ResumeInit() {
	return 0;
}

void E_ArenaArenaward_s::write_to_pbmsg(::proto_ff::E_ArenaArenaward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lvdown((int32_t)m_lvdown);
	msg.set_m_lvup((int32_t)m_lvup);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_ArenaArenawardRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_ArenaArenaward_s::read_from_pbmsg(const ::proto_ff::E_ArenaArenaward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ArenaArenaward_s));
	m_id = msg.m_id();
	m_lvdown = msg.m_lvdown();
	m_lvup = msg.m_lvup();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_ArenaArenawardRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_ArenaArenaward_s::Sheet_ArenaArenaward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ArenaArenaward_s::CreateInit() {
	return 0;
}

int Sheet_ArenaArenaward_s::ResumeInit() {
	return 0;
}

void Sheet_ArenaArenaward_s::write_to_pbmsg(::proto_ff::Sheet_ArenaArenaward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ArenaArenaward_List.size(); ++i) {
		::proto_ff::E_ArenaArenaward* temp_e_arenaarenaward_list = msg.add_e_arenaarenaward_list();
		E_ArenaArenaward_List[i].write_to_pbmsg(*temp_e_arenaarenaward_list);
	}
}

void Sheet_ArenaArenaward_s::read_from_pbmsg(const ::proto_ff::Sheet_ArenaArenaward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_ArenaArenaward_s));
	E_ArenaArenaward_List.resize((int)msg.e_arenaarenaward_list_size() > (int)E_ArenaArenaward_List.max_size() ? E_ArenaArenaward_List.max_size() : msg.e_arenaarenaward_list_size());
	for(int32_t i = 0; i < (int32_t)E_ArenaArenaward_List.size(); ++i) {
		const ::proto_ff::E_ArenaArenaward & temp_e_arenaarenaward_list = msg.e_arenaarenaward_list(i);
		E_ArenaArenaward_List[i].read_from_pbmsg(temp_e_arenaarenaward_list);
	}
}

E_ArenaRankawardRewardDesc_s::E_ArenaRankawardRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ArenaRankawardRewardDesc_s::CreateInit() {
	m_id = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_ArenaRankawardRewardDesc_s::ResumeInit() {
	return 0;
}

void E_ArenaRankawardRewardDesc_s::write_to_pbmsg(::proto_ff::E_ArenaRankawardRewardDesc & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_value((int32_t)m_value);
}

void E_ArenaRankawardRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_ArenaRankawardRewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ArenaRankawardRewardDesc_s));
	m_id = msg.m_id();
	m_value = msg.m_value();
}

E_ArenaRankaward_s::E_ArenaRankaward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ArenaRankaward_s::CreateInit() {
	m_prizeid = (int32_t)0;
	m_arenadown = (int32_t)0;
	m_arenaup = (int32_t)0;
	return 0;
}

int E_ArenaRankaward_s::ResumeInit() {
	return 0;
}

void E_ArenaRankaward_s::write_to_pbmsg(::proto_ff::E_ArenaRankaward & msg) const {
	msg.set_m_prizeid((int32_t)m_prizeid);
	msg.set_m_arenadown((int32_t)m_arenadown);
	msg.set_m_arenaup((int32_t)m_arenaup);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_ArenaRankawardRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_ArenaRankaward_s::read_from_pbmsg(const ::proto_ff::E_ArenaRankaward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ArenaRankaward_s));
	m_prizeid = msg.m_prizeid();
	m_arenadown = msg.m_arenadown();
	m_arenaup = msg.m_arenaup();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_ArenaRankawardRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_ArenaRankaward_s::Sheet_ArenaRankaward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ArenaRankaward_s::CreateInit() {
	return 0;
}

int Sheet_ArenaRankaward_s::ResumeInit() {
	return 0;
}

void Sheet_ArenaRankaward_s::write_to_pbmsg(::proto_ff::Sheet_ArenaRankaward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ArenaRankaward_List.size(); ++i) {
		::proto_ff::E_ArenaRankaward* temp_e_arenarankaward_list = msg.add_e_arenarankaward_list();
		E_ArenaRankaward_List[i].write_to_pbmsg(*temp_e_arenarankaward_list);
	}
}

void Sheet_ArenaRankaward_s::read_from_pbmsg(const ::proto_ff::Sheet_ArenaRankaward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_ArenaRankaward_s));
	E_ArenaRankaward_List.resize((int)msg.e_arenarankaward_list_size() > (int)E_ArenaRankaward_List.max_size() ? E_ArenaRankaward_List.max_size() : msg.e_arenarankaward_list_size());
	for(int32_t i = 0; i < (int32_t)E_ArenaRankaward_List.size(); ++i) {
		const ::proto_ff::E_ArenaRankaward & temp_e_arenarankaward_list = msg.e_arenarankaward_list(i);
		E_ArenaRankaward_List[i].read_from_pbmsg(temp_e_arenarankaward_list);
	}
}

E_ArenaFirstrankRewardDesc_s::E_ArenaFirstrankRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ArenaFirstrankRewardDesc_s::CreateInit() {
	m_id = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_ArenaFirstrankRewardDesc_s::ResumeInit() {
	return 0;
}

void E_ArenaFirstrankRewardDesc_s::write_to_pbmsg(::proto_ff::E_ArenaFirstrankRewardDesc & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_value((int32_t)m_value);
}

void E_ArenaFirstrankRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_ArenaFirstrankRewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ArenaFirstrankRewardDesc_s));
	m_id = msg.m_id();
	m_value = msg.m_value();
}

E_ArenaFirstrank_s::E_ArenaFirstrank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ArenaFirstrank_s::CreateInit() {
	m_id = (int32_t)0;
	m_rankdown = (int32_t)0;
	m_rankup = (int32_t)0;
	return 0;
}

int E_ArenaFirstrank_s::ResumeInit() {
	return 0;
}

void E_ArenaFirstrank_s::write_to_pbmsg(::proto_ff::E_ArenaFirstrank & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_rankdown((int32_t)m_rankdown);
	msg.set_m_rankup((int32_t)m_rankup);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_ArenaFirstrankRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_ArenaFirstrank_s::read_from_pbmsg(const ::proto_ff::E_ArenaFirstrank & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ArenaFirstrank_s));
	m_id = msg.m_id();
	m_rankdown = msg.m_rankdown();
	m_rankup = msg.m_rankup();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_ArenaFirstrankRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_ArenaFirstrank_s::Sheet_ArenaFirstrank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ArenaFirstrank_s::CreateInit() {
	return 0;
}

int Sheet_ArenaFirstrank_s::ResumeInit() {
	return 0;
}

void Sheet_ArenaFirstrank_s::write_to_pbmsg(::proto_ff::Sheet_ArenaFirstrank & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ArenaFirstrank_List.size(); ++i) {
		::proto_ff::E_ArenaFirstrank* temp_e_arenafirstrank_list = msg.add_e_arenafirstrank_list();
		E_ArenaFirstrank_List[i].write_to_pbmsg(*temp_e_arenafirstrank_list);
	}
}

void Sheet_ArenaFirstrank_s::read_from_pbmsg(const ::proto_ff::Sheet_ArenaFirstrank & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_ArenaFirstrank_s));
	E_ArenaFirstrank_List.resize((int)msg.e_arenafirstrank_list_size() > (int)E_ArenaFirstrank_List.max_size() ? E_ArenaFirstrank_List.max_size() : msg.e_arenafirstrank_list_size());
	for(int32_t i = 0; i < (int32_t)E_ArenaFirstrank_List.size(); ++i) {
		const ::proto_ff::E_ArenaFirstrank & temp_e_arenafirstrank_list = msg.e_arenafirstrank_list(i);
		E_ArenaFirstrank_List[i].read_from_pbmsg(temp_e_arenafirstrank_list);
	}
}

E_ArenaBuychallenge_s::E_ArenaBuychallenge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ArenaBuychallenge_s::CreateInit() {
	m_count = (int32_t)0;
	m_costtype = (int32_t)0;
	m_cost = (int32_t)0;
	return 0;
}

int E_ArenaBuychallenge_s::ResumeInit() {
	return 0;
}

void E_ArenaBuychallenge_s::write_to_pbmsg(::proto_ff::E_ArenaBuychallenge & msg) const {
	msg.set_m_count((int32_t)m_count);
	msg.set_m_costtype((int32_t)m_costtype);
	msg.set_m_cost((int32_t)m_cost);
}

void E_ArenaBuychallenge_s::read_from_pbmsg(const ::proto_ff::E_ArenaBuychallenge & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_ArenaBuychallenge_s));
	m_count = msg.m_count();
	m_costtype = msg.m_costtype();
	m_cost = msg.m_cost();
}

Sheet_ArenaBuychallenge_s::Sheet_ArenaBuychallenge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ArenaBuychallenge_s::CreateInit() {
	return 0;
}

int Sheet_ArenaBuychallenge_s::ResumeInit() {
	return 0;
}

void Sheet_ArenaBuychallenge_s::write_to_pbmsg(::proto_ff::Sheet_ArenaBuychallenge & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ArenaBuychallenge_List.size(); ++i) {
		::proto_ff::E_ArenaBuychallenge* temp_e_arenabuychallenge_list = msg.add_e_arenabuychallenge_list();
		E_ArenaBuychallenge_List[i].write_to_pbmsg(*temp_e_arenabuychallenge_list);
	}
}

void Sheet_ArenaBuychallenge_s::read_from_pbmsg(const ::proto_ff::Sheet_ArenaBuychallenge & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_ArenaBuychallenge_s));
	E_ArenaBuychallenge_List.resize((int)msg.e_arenabuychallenge_list_size() > (int)E_ArenaBuychallenge_List.max_size() ? E_ArenaBuychallenge_List.max_size() : msg.e_arenabuychallenge_list_size());
	for(int32_t i = 0; i < (int32_t)E_ArenaBuychallenge_List.size(); ++i) {
		const ::proto_ff::E_ArenaBuychallenge & temp_e_arenabuychallenge_list = msg.e_arenabuychallenge_list(i);
		E_ArenaBuychallenge_List[i].read_from_pbmsg(temp_e_arenabuychallenge_list);
	}
}

}