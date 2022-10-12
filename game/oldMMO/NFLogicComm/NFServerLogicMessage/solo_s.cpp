#include "solo_s.h"

namespace proto_ff_s {

soloduanweirewardDesc_s::soloduanweirewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int soloduanweirewardDesc_s::CreateInit() {
	num = (int32_t)0;
	duanwei = (int64_t)0;
	return 0;
}

int soloduanweirewardDesc_s::ResumeInit() {
	return 0;
}

void soloduanweirewardDesc_s::write_to_pbmsg(::proto_ff::soloduanweirewardDesc & msg) const {
	msg.set_num((int32_t)num);
	msg.set_duanwei((int64_t)duanwei);
}

void soloduanweirewardDesc_s::read_from_pbmsg(const ::proto_ff::soloduanweirewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct soloduanweirewardDesc_s));
	num = msg.num();
	duanwei = msg.duanwei();
}

soloduanweidayRewardItemDesc_s::soloduanweidayRewardItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int soloduanweidayRewardItemDesc_s::CreateInit() {
	num = (int32_t)0;
	id = (int64_t)0;
	return 0;
}

int soloduanweidayRewardItemDesc_s::ResumeInit() {
	return 0;
}

void soloduanweidayRewardItemDesc_s::write_to_pbmsg(::proto_ff::soloduanweidayRewardItemDesc & msg) const {
	msg.set_num((int32_t)num);
	msg.set_id((int64_t)id);
}

void soloduanweidayRewardItemDesc_s::read_from_pbmsg(const ::proto_ff::soloduanweidayRewardItemDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct soloduanweidayRewardItemDesc_s));
	num = msg.num();
	id = msg.id();
}

soloduanwei_s::soloduanwei_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int soloduanwei_s::CreateInit() {
	duanweiID = (int32_t)0;
	pointMin = (int32_t)0;
	pointWin = (int32_t)0;
	pointLose = (int32_t)0;
	arenaWin = (int32_t)0;
	arenaLose = (int32_t)0;
	pipeiPoint = (int32_t)0;
	dayReward = (int32_t)0;
	diamondNum = (int32_t)0;
	return 0;
}

int soloduanwei_s::ResumeInit() {
	return 0;
}

void soloduanwei_s::write_to_pbmsg(::proto_ff::soloduanwei & msg) const {
	msg.set_duanweiid((int32_t)duanweiID);
	msg.set_pointmin((int32_t)pointMin);
	msg.set_pointwin((int32_t)pointWin);
	msg.set_pointlose((int32_t)pointLose);
	msg.set_arenawin((int32_t)arenaWin);
	msg.set_arenalose((int32_t)arenaLose);
	msg.set_pipeipoint((int32_t)pipeiPoint);
	msg.set_dayreward((int32_t)dayReward);
	msg.set_diamondnum((int32_t)diamondNum);
	for(int32_t i = 0; i < (int32_t)reward.GetSize() && i < reward.GetMaxSize(); ++i) {
		::proto_ff::soloduanweirewardDesc* temp_reward = msg.add_reward();
		reward[i].write_to_pbmsg(*temp_reward);
	}
	for(int32_t i = 0; i < (int32_t)dayRewardItem.GetSize() && i < dayRewardItem.GetMaxSize(); ++i) {
		::proto_ff::soloduanweidayRewardItemDesc* temp_dayrewarditem = msg.add_dayrewarditem();
		dayRewardItem[i].write_to_pbmsg(*temp_dayrewarditem);
	}
}

void soloduanwei_s::read_from_pbmsg(const ::proto_ff::soloduanwei & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct soloduanwei_s));
	duanweiID = msg.duanweiid();
	pointMin = msg.pointmin();
	pointWin = msg.pointwin();
	pointLose = msg.pointlose();
	arenaWin = msg.arenawin();
	arenaLose = msg.arenalose();
	pipeiPoint = msg.pipeipoint();
	dayReward = msg.dayreward();
	diamondNum = msg.diamondnum();
	reward.SetSize(msg.reward_size() > reward.GetMaxSize() ? reward.GetMaxSize() : msg.reward_size());
	for(int32_t i = 0; i < (int32_t)reward.GetSize(); ++i) {
		const ::proto_ff::soloduanweirewardDesc & temp_reward = msg.reward(i);
		reward[i].read_from_pbmsg(temp_reward);
	}
	dayRewardItem.SetSize(msg.dayrewarditem_size() > dayRewardItem.GetMaxSize() ? dayRewardItem.GetMaxSize() : msg.dayrewarditem_size());
	for(int32_t i = 0; i < (int32_t)dayRewardItem.GetSize(); ++i) {
		const ::proto_ff::soloduanweidayRewardItemDesc & temp_dayrewarditem = msg.dayrewarditem(i);
		dayRewardItem[i].read_from_pbmsg(temp_dayrewarditem);
	}
}

Sheet_soloduanwei_s::Sheet_soloduanwei_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_soloduanwei_s::CreateInit() {
	return 0;
}

int Sheet_soloduanwei_s::ResumeInit() {
	return 0;
}

void Sheet_soloduanwei_s::write_to_pbmsg(::proto_ff::Sheet_soloduanwei & msg) const {
	for(int32_t i = 0; i < (int32_t)soloduanwei_List.GetSize() && i < soloduanwei_List.GetMaxSize(); ++i) {
		::proto_ff::soloduanwei* temp_soloduanwei_list = msg.add_soloduanwei_list();
		soloduanwei_List[i].write_to_pbmsg(*temp_soloduanwei_list);
	}
}

void Sheet_soloduanwei_s::read_from_pbmsg(const ::proto_ff::Sheet_soloduanwei & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_soloduanwei_s));
	soloduanwei_List.SetSize(msg.soloduanwei_list_size() > soloduanwei_List.GetMaxSize() ? soloduanwei_List.GetMaxSize() : msg.soloduanwei_list_size());
	for(int32_t i = 0; i < (int32_t)soloduanwei_List.GetSize(); ++i) {
		const ::proto_ff::soloduanwei & temp_soloduanwei_list = msg.soloduanwei_list(i);
		soloduanwei_List[i].read_from_pbmsg(temp_soloduanwei_list);
	}
}

solorankrewardDesc_s::solorankrewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int solorankrewardDesc_s::CreateInit() {
	num = (int32_t)0;
	rank = (int64_t)0;
	return 0;
}

int solorankrewardDesc_s::ResumeInit() {
	return 0;
}

void solorankrewardDesc_s::write_to_pbmsg(::proto_ff::solorankrewardDesc & msg) const {
	msg.set_num((int32_t)num);
	msg.set_rank((int64_t)rank);
}

void solorankrewardDesc_s::read_from_pbmsg(const ::proto_ff::solorankrewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct solorankrewardDesc_s));
	num = msg.num();
	rank = msg.rank();
}

solorank_s::solorank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int solorank_s::CreateInit() {
	rankID = (int32_t)0;
	maxRank = (int32_t)0;
	minRank = (int32_t)0;
	diamondNum = (int32_t)0;
	return 0;
}

int solorank_s::ResumeInit() {
	return 0;
}

void solorank_s::write_to_pbmsg(::proto_ff::solorank & msg) const {
	msg.set_rankid((int32_t)rankID);
	msg.set_maxrank((int32_t)maxRank);
	msg.set_minrank((int32_t)minRank);
	msg.set_diamondnum((int32_t)diamondNum);
	for(int32_t i = 0; i < (int32_t)reward.GetSize() && i < reward.GetMaxSize(); ++i) {
		::proto_ff::solorankrewardDesc* temp_reward = msg.add_reward();
		reward[i].write_to_pbmsg(*temp_reward);
	}
}

void solorank_s::read_from_pbmsg(const ::proto_ff::solorank & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct solorank_s));
	rankID = msg.rankid();
	maxRank = msg.maxrank();
	minRank = msg.minrank();
	diamondNum = msg.diamondnum();
	reward.SetSize(msg.reward_size() > reward.GetMaxSize() ? reward.GetMaxSize() : msg.reward_size());
	for(int32_t i = 0; i < (int32_t)reward.GetSize(); ++i) {
		const ::proto_ff::solorankrewardDesc & temp_reward = msg.reward(i);
		reward[i].read_from_pbmsg(temp_reward);
	}
}

Sheet_solorank_s::Sheet_solorank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_solorank_s::CreateInit() {
	return 0;
}

int Sheet_solorank_s::ResumeInit() {
	return 0;
}

void Sheet_solorank_s::write_to_pbmsg(::proto_ff::Sheet_solorank & msg) const {
	for(int32_t i = 0; i < (int32_t)solorank_List.GetSize() && i < solorank_List.GetMaxSize(); ++i) {
		::proto_ff::solorank* temp_solorank_list = msg.add_solorank_list();
		solorank_List[i].write_to_pbmsg(*temp_solorank_list);
	}
}

void Sheet_solorank_s::read_from_pbmsg(const ::proto_ff::Sheet_solorank & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_solorank_s));
	solorank_List.SetSize(msg.solorank_list_size() > solorank_List.GetMaxSize() ? solorank_List.GetMaxSize() : msg.solorank_list_size());
	for(int32_t i = 0; i < (int32_t)solorank_List.GetSize(); ++i) {
		const ::proto_ff::solorank & temp_solorank_list = msg.solorank_list(i);
		solorank_List[i].read_from_pbmsg(temp_solorank_list);
	}
}

solopipei_s::solopipei_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int solopipei_s::CreateInit() {
	ID = (int32_t)0;
	num = (int32_t)0;
	reward = (int64_t)0;
	return 0;
}

int solopipei_s::ResumeInit() {
	return 0;
}

void solopipei_s::write_to_pbmsg(::proto_ff::solopipei & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_num((int32_t)num);
	msg.set_reward((int64_t)reward);
}

void solopipei_s::read_from_pbmsg(const ::proto_ff::solopipei & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct solopipei_s));
	ID = msg.id();
	num = msg.num();
	reward = msg.reward();
}

Sheet_solopipei_s::Sheet_solopipei_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_solopipei_s::CreateInit() {
	return 0;
}

int Sheet_solopipei_s::ResumeInit() {
	return 0;
}

void Sheet_solopipei_s::write_to_pbmsg(::proto_ff::Sheet_solopipei & msg) const {
	for(int32_t i = 0; i < (int32_t)solopipei_List.GetSize() && i < solopipei_List.GetMaxSize(); ++i) {
		::proto_ff::solopipei* temp_solopipei_list = msg.add_solopipei_list();
		solopipei_List[i].write_to_pbmsg(*temp_solopipei_list);
	}
}

void Sheet_solopipei_s::read_from_pbmsg(const ::proto_ff::Sheet_solopipei & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_solopipei_s));
	solopipei_List.SetSize(msg.solopipei_list_size() > solopipei_List.GetMaxSize() ? solopipei_List.GetMaxSize() : msg.solopipei_list_size());
	for(int32_t i = 0; i < (int32_t)solopipei_List.GetSize(); ++i) {
		const ::proto_ff::solopipei & temp_solopipei_list = msg.solopipei_list(i);
		solopipei_List[i].read_from_pbmsg(temp_solopipei_list);
	}
}

soloconstant_s::soloconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int soloconstant_s::CreateInit() {
	ID = (int32_t)0;
	return 0;
}

int soloconstant_s::ResumeInit() {
	return 0;
}

void soloconstant_s::write_to_pbmsg(::proto_ff::soloconstant & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_constant((const char*)constant.Get());
}

void soloconstant_s::read_from_pbmsg(const ::proto_ff::soloconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct soloconstant_s));
	ID = msg.id();
	constant.Copy(msg.constant());
}

Sheet_soloconstant_s::Sheet_soloconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_soloconstant_s::CreateInit() {
	return 0;
}

int Sheet_soloconstant_s::ResumeInit() {
	return 0;
}

void Sheet_soloconstant_s::write_to_pbmsg(::proto_ff::Sheet_soloconstant & msg) const {
	for(int32_t i = 0; i < (int32_t)soloconstant_List.GetSize() && i < soloconstant_List.GetMaxSize(); ++i) {
		::proto_ff::soloconstant* temp_soloconstant_list = msg.add_soloconstant_list();
		soloconstant_List[i].write_to_pbmsg(*temp_soloconstant_list);
	}
}

void Sheet_soloconstant_s::read_from_pbmsg(const ::proto_ff::Sheet_soloconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_soloconstant_s));
	soloconstant_List.SetSize(msg.soloconstant_list_size() > soloconstant_List.GetMaxSize() ? soloconstant_List.GetMaxSize() : msg.soloconstant_list_size());
	for(int32_t i = 0; i < (int32_t)soloconstant_List.GetSize(); ++i) {
		const ::proto_ff::soloconstant & temp_soloconstant_list = msg.soloconstant_list(i);
		soloconstant_List[i].read_from_pbmsg(temp_soloconstant_list);
	}
}

}