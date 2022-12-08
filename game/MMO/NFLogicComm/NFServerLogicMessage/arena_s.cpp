#include "arena_s.h"

namespace proto_ff_s {

arenarobotattrDesc_s::arenarobotattrDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int arenarobotattrDesc_s::CreateInit() {
	type = (int32_t)0;
	val = (int32_t)0;
	return 0;
}

int arenarobotattrDesc_s::ResumeInit() {
	return 0;
}

void arenarobotattrDesc_s::write_to_pbmsg(::proto_ff::arenarobotattrDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_val((int32_t)val);
}

void arenarobotattrDesc_s::read_from_pbmsg(const ::proto_ff::arenarobotattrDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct arenarobotattrDesc_s));
	type = msg.type();
	val = msg.val();
}

arenarobot_s::arenarobot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int arenarobot_s::CreateInit() {
	arenaId = (int32_t)0;
	aiId = (int32_t)0;
	rankId = (int32_t)0;
	robotProfession = (int32_t)0;
	robotLv = (int32_t)0;
	sword = (int32_t)0;
	occupationID = (int32_t)0;
	return 0;
}

int arenarobot_s::ResumeInit() {
	return 0;
}

void arenarobot_s::write_to_pbmsg(::proto_ff::arenarobot & msg) const {
	msg.set_arenaid((int32_t)arenaId);
	msg.set_robotname((const char*)robotname.Get());
	msg.set_aiid((int32_t)aiId);
	msg.set_rankid((int32_t)rankId);
	msg.set_robotprofession((int32_t)robotProfession);
	msg.set_robotlv((int32_t)robotLv);
	msg.set_sword((int32_t)sword);
	msg.set_occupationid((int32_t)occupationID);
	for(int32_t i = 0; i < (int32_t)attr.GetSize() && i < attr.GetMaxSize(); ++i) {
		::proto_ff::arenarobotattrDesc* temp_attr = msg.add_attr();
		attr[i].write_to_pbmsg(*temp_attr);
	}
}

void arenarobot_s::read_from_pbmsg(const ::proto_ff::arenarobot & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct arenarobot_s));
	arenaId = msg.arenaid();
	robotname.Copy(msg.robotname());
	aiId = msg.aiid();
	rankId = msg.rankid();
	robotProfession = msg.robotprofession();
	robotLv = msg.robotlv();
	sword = msg.sword();
	occupationID = msg.occupationid();
	attr.SetSize(msg.attr_size() > attr.GetMaxSize() ? attr.GetMaxSize() : msg.attr_size());
	for(int32_t i = 0; i < (int32_t)attr.GetSize(); ++i) {
		const ::proto_ff::arenarobotattrDesc & temp_attr = msg.attr(i);
		attr[i].read_from_pbmsg(temp_attr);
	}
}

Sheet_arenarobot_s::Sheet_arenarobot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_arenarobot_s::CreateInit() {
	return 0;
}

int Sheet_arenarobot_s::ResumeInit() {
	return 0;
}

void Sheet_arenarobot_s::write_to_pbmsg(::proto_ff::Sheet_arenarobot & msg) const {
	for(int32_t i = 0; i < (int32_t)arenarobot_List.GetSize() && i < arenarobot_List.GetMaxSize(); ++i) {
		::proto_ff::arenarobot* temp_arenarobot_list = msg.add_arenarobot_list();
		arenarobot_List[i].write_to_pbmsg(*temp_arenarobot_list);
	}
}

void Sheet_arenarobot_s::read_from_pbmsg(const ::proto_ff::Sheet_arenarobot & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_arenarobot_s));
	arenarobot_List.SetSize(msg.arenarobot_list_size() > arenarobot_List.GetMaxSize() ? arenarobot_List.GetMaxSize() : msg.arenarobot_list_size());
	for(int32_t i = 0; i < (int32_t)arenarobot_List.GetSize(); ++i) {
		const ::proto_ff::arenarobot & temp_arenarobot_list = msg.arenarobot_list(i);
		arenarobot_List[i].read_from_pbmsg(temp_arenarobot_list);
	}
}

arenaarenAwardRewardDesc_s::arenaarenAwardRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int arenaarenAwardRewardDesc_s::CreateInit() {
	ID = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int arenaarenAwardRewardDesc_s::ResumeInit() {
	return 0;
}

void arenaarenAwardRewardDesc_s::write_to_pbmsg(::proto_ff::arenaarenAwardRewardDesc & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_value((int32_t)Value);
}

void arenaarenAwardRewardDesc_s::read_from_pbmsg(const ::proto_ff::arenaarenAwardRewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct arenaarenAwardRewardDesc_s));
	ID = msg.id();
	Value = msg.value();
}

arenaarenAward_s::arenaarenAward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int arenaarenAward_s::CreateInit() {
	id = (int32_t)0;
	lvDown = (int32_t)0;
	lvUp = (int32_t)0;
	return 0;
}

int arenaarenAward_s::ResumeInit() {
	return 0;
}

void arenaarenAward_s::write_to_pbmsg(::proto_ff::arenaarenAward & msg) const {
	msg.set_id((int32_t)id);
	msg.set_lvdown((int32_t)lvDown);
	msg.set_lvup((int32_t)lvUp);
	for(int32_t i = 0; i < (int32_t)Reward.GetSize() && i < Reward.GetMaxSize(); ++i) {
		::proto_ff::arenaarenAwardRewardDesc* temp_reward = msg.add_reward();
		Reward[i].write_to_pbmsg(*temp_reward);
	}
}

void arenaarenAward_s::read_from_pbmsg(const ::proto_ff::arenaarenAward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct arenaarenAward_s));
	id = msg.id();
	lvDown = msg.lvdown();
	lvUp = msg.lvup();
	Reward.SetSize(msg.reward_size() > Reward.GetMaxSize() ? Reward.GetMaxSize() : msg.reward_size());
	for(int32_t i = 0; i < (int32_t)Reward.GetSize(); ++i) {
		const ::proto_ff::arenaarenAwardRewardDesc & temp_reward = msg.reward(i);
		Reward[i].read_from_pbmsg(temp_reward);
	}
}

Sheet_arenaarenAward_s::Sheet_arenaarenAward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_arenaarenAward_s::CreateInit() {
	return 0;
}

int Sheet_arenaarenAward_s::ResumeInit() {
	return 0;
}

void Sheet_arenaarenAward_s::write_to_pbmsg(::proto_ff::Sheet_arenaarenAward & msg) const {
	for(int32_t i = 0; i < (int32_t)arenaarenAward_List.GetSize() && i < arenaarenAward_List.GetMaxSize(); ++i) {
		::proto_ff::arenaarenAward* temp_arenaarenaward_list = msg.add_arenaarenaward_list();
		arenaarenAward_List[i].write_to_pbmsg(*temp_arenaarenaward_list);
	}
}

void Sheet_arenaarenAward_s::read_from_pbmsg(const ::proto_ff::Sheet_arenaarenAward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_arenaarenAward_s));
	arenaarenAward_List.SetSize(msg.arenaarenaward_list_size() > arenaarenAward_List.GetMaxSize() ? arenaarenAward_List.GetMaxSize() : msg.arenaarenaward_list_size());
	for(int32_t i = 0; i < (int32_t)arenaarenAward_List.GetSize(); ++i) {
		const ::proto_ff::arenaarenAward & temp_arenaarenaward_list = msg.arenaarenaward_list(i);
		arenaarenAward_List[i].read_from_pbmsg(temp_arenaarenaward_list);
	}
}

arenarankawardRewardDesc_s::arenarankawardRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int arenarankawardRewardDesc_s::CreateInit() {
	ID = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int arenarankawardRewardDesc_s::ResumeInit() {
	return 0;
}

void arenarankawardRewardDesc_s::write_to_pbmsg(::proto_ff::arenarankawardRewardDesc & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_value((int32_t)Value);
}

void arenarankawardRewardDesc_s::read_from_pbmsg(const ::proto_ff::arenarankawardRewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct arenarankawardRewardDesc_s));
	ID = msg.id();
	Value = msg.value();
}

arenarankaward_s::arenarankaward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int arenarankaward_s::CreateInit() {
	PrizeId = (int32_t)0;
	arenaDown = (int32_t)0;
	arenaUp = (int32_t)0;
	return 0;
}

int arenarankaward_s::ResumeInit() {
	return 0;
}

void arenarankaward_s::write_to_pbmsg(::proto_ff::arenarankaward & msg) const {
	msg.set_prizeid((int32_t)PrizeId);
	msg.set_arenadown((int32_t)arenaDown);
	msg.set_arenaup((int32_t)arenaUp);
	for(int32_t i = 0; i < (int32_t)Reward.GetSize() && i < Reward.GetMaxSize(); ++i) {
		::proto_ff::arenarankawardRewardDesc* temp_reward = msg.add_reward();
		Reward[i].write_to_pbmsg(*temp_reward);
	}
}

void arenarankaward_s::read_from_pbmsg(const ::proto_ff::arenarankaward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct arenarankaward_s));
	PrizeId = msg.prizeid();
	arenaDown = msg.arenadown();
	arenaUp = msg.arenaup();
	Reward.SetSize(msg.reward_size() > Reward.GetMaxSize() ? Reward.GetMaxSize() : msg.reward_size());
	for(int32_t i = 0; i < (int32_t)Reward.GetSize(); ++i) {
		const ::proto_ff::arenarankawardRewardDesc & temp_reward = msg.reward(i);
		Reward[i].read_from_pbmsg(temp_reward);
	}
}

Sheet_arenarankaward_s::Sheet_arenarankaward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_arenarankaward_s::CreateInit() {
	return 0;
}

int Sheet_arenarankaward_s::ResumeInit() {
	return 0;
}

void Sheet_arenarankaward_s::write_to_pbmsg(::proto_ff::Sheet_arenarankaward & msg) const {
	for(int32_t i = 0; i < (int32_t)arenarankaward_List.GetSize() && i < arenarankaward_List.GetMaxSize(); ++i) {
		::proto_ff::arenarankaward* temp_arenarankaward_list = msg.add_arenarankaward_list();
		arenarankaward_List[i].write_to_pbmsg(*temp_arenarankaward_list);
	}
}

void Sheet_arenarankaward_s::read_from_pbmsg(const ::proto_ff::Sheet_arenarankaward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_arenarankaward_s));
	arenarankaward_List.SetSize(msg.arenarankaward_list_size() > arenarankaward_List.GetMaxSize() ? arenarankaward_List.GetMaxSize() : msg.arenarankaward_list_size());
	for(int32_t i = 0; i < (int32_t)arenarankaward_List.GetSize(); ++i) {
		const ::proto_ff::arenarankaward & temp_arenarankaward_list = msg.arenarankaward_list(i);
		arenarankaward_List[i].read_from_pbmsg(temp_arenarankaward_list);
	}
}

arenafirstrankRewardDesc_s::arenafirstrankRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int arenafirstrankRewardDesc_s::CreateInit() {
	ID = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int arenafirstrankRewardDesc_s::ResumeInit() {
	return 0;
}

void arenafirstrankRewardDesc_s::write_to_pbmsg(::proto_ff::arenafirstrankRewardDesc & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_value((int32_t)Value);
}

void arenafirstrankRewardDesc_s::read_from_pbmsg(const ::proto_ff::arenafirstrankRewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct arenafirstrankRewardDesc_s));
	ID = msg.id();
	Value = msg.value();
}

arenafirstrank_s::arenafirstrank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int arenafirstrank_s::CreateInit() {
	id = (int32_t)0;
	rankDown = (int32_t)0;
	rankUp = (int32_t)0;
	return 0;
}

int arenafirstrank_s::ResumeInit() {
	return 0;
}

void arenafirstrank_s::write_to_pbmsg(::proto_ff::arenafirstrank & msg) const {
	msg.set_id((int32_t)id);
	msg.set_rankdown((int32_t)rankDown);
	msg.set_rankup((int32_t)rankUp);
	for(int32_t i = 0; i < (int32_t)Reward.GetSize() && i < Reward.GetMaxSize(); ++i) {
		::proto_ff::arenafirstrankRewardDesc* temp_reward = msg.add_reward();
		Reward[i].write_to_pbmsg(*temp_reward);
	}
}

void arenafirstrank_s::read_from_pbmsg(const ::proto_ff::arenafirstrank & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct arenafirstrank_s));
	id = msg.id();
	rankDown = msg.rankdown();
	rankUp = msg.rankup();
	Reward.SetSize(msg.reward_size() > Reward.GetMaxSize() ? Reward.GetMaxSize() : msg.reward_size());
	for(int32_t i = 0; i < (int32_t)Reward.GetSize(); ++i) {
		const ::proto_ff::arenafirstrankRewardDesc & temp_reward = msg.reward(i);
		Reward[i].read_from_pbmsg(temp_reward);
	}
}

Sheet_arenafirstrank_s::Sheet_arenafirstrank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_arenafirstrank_s::CreateInit() {
	return 0;
}

int Sheet_arenafirstrank_s::ResumeInit() {
	return 0;
}

void Sheet_arenafirstrank_s::write_to_pbmsg(::proto_ff::Sheet_arenafirstrank & msg) const {
	for(int32_t i = 0; i < (int32_t)arenafirstrank_List.GetSize() && i < arenafirstrank_List.GetMaxSize(); ++i) {
		::proto_ff::arenafirstrank* temp_arenafirstrank_list = msg.add_arenafirstrank_list();
		arenafirstrank_List[i].write_to_pbmsg(*temp_arenafirstrank_list);
	}
}

void Sheet_arenafirstrank_s::read_from_pbmsg(const ::proto_ff::Sheet_arenafirstrank & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_arenafirstrank_s));
	arenafirstrank_List.SetSize(msg.arenafirstrank_list_size() > arenafirstrank_List.GetMaxSize() ? arenafirstrank_List.GetMaxSize() : msg.arenafirstrank_list_size());
	for(int32_t i = 0; i < (int32_t)arenafirstrank_List.GetSize(); ++i) {
		const ::proto_ff::arenafirstrank & temp_arenafirstrank_list = msg.arenafirstrank_list(i);
		arenafirstrank_List[i].read_from_pbmsg(temp_arenafirstrank_list);
	}
}

arenabuychallenge_s::arenabuychallenge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int arenabuychallenge_s::CreateInit() {
	count = (int32_t)0;
	costType = (int32_t)0;
	cost = (int32_t)0;
	return 0;
}

int arenabuychallenge_s::ResumeInit() {
	return 0;
}

void arenabuychallenge_s::write_to_pbmsg(::proto_ff::arenabuychallenge & msg) const {
	msg.set_count((int32_t)count);
	msg.set_costtype((int32_t)costType);
	msg.set_cost((int32_t)cost);
}

void arenabuychallenge_s::read_from_pbmsg(const ::proto_ff::arenabuychallenge & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct arenabuychallenge_s));
	count = msg.count();
	costType = msg.costtype();
	cost = msg.cost();
}

Sheet_arenabuychallenge_s::Sheet_arenabuychallenge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_arenabuychallenge_s::CreateInit() {
	return 0;
}

int Sheet_arenabuychallenge_s::ResumeInit() {
	return 0;
}

void Sheet_arenabuychallenge_s::write_to_pbmsg(::proto_ff::Sheet_arenabuychallenge & msg) const {
	for(int32_t i = 0; i < (int32_t)arenabuychallenge_List.GetSize() && i < arenabuychallenge_List.GetMaxSize(); ++i) {
		::proto_ff::arenabuychallenge* temp_arenabuychallenge_list = msg.add_arenabuychallenge_list();
		arenabuychallenge_List[i].write_to_pbmsg(*temp_arenabuychallenge_list);
	}
}

void Sheet_arenabuychallenge_s::read_from_pbmsg(const ::proto_ff::Sheet_arenabuychallenge & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_arenabuychallenge_s));
	arenabuychallenge_List.SetSize(msg.arenabuychallenge_list_size() > arenabuychallenge_List.GetMaxSize() ? arenabuychallenge_List.GetMaxSize() : msg.arenabuychallenge_list_size());
	for(int32_t i = 0; i < (int32_t)arenabuychallenge_List.GetSize(); ++i) {
		const ::proto_ff::arenabuychallenge & temp_arenabuychallenge_list = msg.arenabuychallenge_list(i);
		arenabuychallenge_List[i].read_from_pbmsg(temp_arenabuychallenge_list);
	}
}

}