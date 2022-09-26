#include "escort_s.h"

namespace proto_ff_s {

escortescortshuangDesc_s::escortescortshuangDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int escortescortshuangDesc_s::CreateInit() {
	duration = (int32_t)0;
	Time = (int32_t)0;
	return 0;
}

int escortescortshuangDesc_s::ResumeInit() {
	return 0;
}

void escortescortshuangDesc_s::write_to_pbmsg(::proto_ff::escortescortshuangDesc & msg) const {
	msg.set_duration((int32_t)duration);
	msg.set_time((int32_t)Time);
}

void escortescortshuangDesc_s::read_from_pbmsg(const ::proto_ff::escortescortshuangDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct escortescortshuangDesc_s));
	duration = msg.duration();
	Time = msg.time();
}

escortescort_s::escortescort_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int escortescort_s::CreateInit() {
	convoyId = (int64_t)0;
	MonsterId = (int64_t)0;
	convoyLevel = (int32_t)0;
	chance = (int32_t)0;
	tokenId = (int64_t)0;
	tokenNumber = (int32_t)0;
	dayTime = (int32_t)0;
	mapId = (int64_t)0;
	startArea = (int64_t)0;
	endArea = (int64_t)0;
	startAreaLink = (int64_t)0;
	endAreaLink = (int64_t)0;
	DistanceA = (int32_t)0;
	DistanceB = (int32_t)0;
	DistanceC = (int32_t)0;
	rewardMoney = (int32_t)0;
	timeLimit = (int32_t)0;
	return 0;
}

int escortescort_s::ResumeInit() {
	return 0;
}

void escortescort_s::write_to_pbmsg(::proto_ff::escortescort & msg) const {
	msg.set_convoyid((int64_t)convoyId);
	msg.set_convoyname((const char*)convoyName.Get());
	msg.set_monsterid((int64_t)MonsterId);
	msg.set_convoylevel((int32_t)convoyLevel);
	msg.set_chance((int32_t)chance);
	msg.set_tokenid((int64_t)tokenId);
	msg.set_tokennumber((int32_t)tokenNumber);
	msg.set_daytime((int32_t)dayTime);
	msg.set_mapid((int64_t)mapId);
	msg.set_startarea((int64_t)startArea);
	msg.set_endarea((int64_t)endArea);
	msg.set_startarealink((int64_t)startAreaLink);
	msg.set_endarealink((int64_t)endAreaLink);
	msg.set_distancea((int32_t)DistanceA);
	msg.set_distanceb((int32_t)DistanceB);
	msg.set_distancec((int32_t)DistanceC);
	msg.set_rewardmoney((int32_t)rewardMoney);
	msg.set_timelimit((int32_t)timeLimit);
	for(int32_t i = 0; i < (int32_t)shuang.GetSize() && i < shuang.GetMaxSize(); ++i) {
		::proto_ff::escortescortshuangDesc* temp_shuang = msg.add_shuang();
		shuang[i].write_to_pbmsg(*temp_shuang);
	}
}

void escortescort_s::read_from_pbmsg(const ::proto_ff::escortescort & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct escortescort_s));
	convoyId = msg.convoyid();
	convoyName.Copy(msg.convoyname());
	MonsterId = msg.monsterid();
	convoyLevel = msg.convoylevel();
	chance = msg.chance();
	tokenId = msg.tokenid();
	tokenNumber = msg.tokennumber();
	dayTime = msg.daytime();
	mapId = msg.mapid();
	startArea = msg.startarea();
	endArea = msg.endarea();
	startAreaLink = msg.startarealink();
	endAreaLink = msg.endarealink();
	DistanceA = msg.distancea();
	DistanceB = msg.distanceb();
	DistanceC = msg.distancec();
	rewardMoney = msg.rewardmoney();
	timeLimit = msg.timelimit();
	shuang.SetSize(msg.shuang_size() > shuang.GetMaxSize() ? shuang.GetMaxSize() : msg.shuang_size());
	for(int32_t i = 0; i < (int32_t)shuang.GetSize(); ++i) {
		const ::proto_ff::escortescortshuangDesc & temp_shuang = msg.shuang(i);
		shuang[i].read_from_pbmsg(temp_shuang);
	}
}

Sheet_escortescort_s::Sheet_escortescort_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_escortescort_s::CreateInit() {
	return 0;
}

int Sheet_escortescort_s::ResumeInit() {
	return 0;
}

void Sheet_escortescort_s::write_to_pbmsg(::proto_ff::Sheet_escortescort & msg) const {
	for(int32_t i = 0; i < (int32_t)escortescort_List.GetSize() && i < escortescort_List.GetMaxSize(); ++i) {
		::proto_ff::escortescort* temp_escortescort_list = msg.add_escortescort_list();
		escortescort_List[i].write_to_pbmsg(*temp_escortescort_list);
	}
}

void Sheet_escortescort_s::read_from_pbmsg(const ::proto_ff::Sheet_escortescort & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_escortescort_s));
	escortescort_List.SetSize(msg.escortescort_list_size() > escortescort_List.GetMaxSize() ? escortescort_List.GetMaxSize() : msg.escortescort_list_size());
	for(int32_t i = 0; i < (int32_t)escortescort_List.GetSize(); ++i) {
		const ::proto_ff::escortescort & temp_escortescort_list = msg.escortescort_list(i);
		escortescort_List[i].read_from_pbmsg(temp_escortescort_list);
	}
}

escortchanceescortDesc_s::escortchanceescortDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int escortchanceescortDesc_s::CreateInit() {
	chance = (int32_t)0;
	ID = (int64_t)0;
	return 0;
}

int escortchanceescortDesc_s::ResumeInit() {
	return 0;
}

void escortchanceescortDesc_s::write_to_pbmsg(::proto_ff::escortchanceescortDesc & msg) const {
	msg.set_chance((int32_t)chance);
	msg.set_id((int64_t)ID);
}

void escortchanceescortDesc_s::read_from_pbmsg(const ::proto_ff::escortchanceescortDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct escortchanceescortDesc_s));
	chance = msg.chance();
	ID = msg.id();
}

escortchance_s::escortchance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int escortchance_s::CreateInit() {
	convoyId = (int64_t)0;
	return 0;
}

int escortchance_s::ResumeInit() {
	return 0;
}

void escortchance_s::write_to_pbmsg(::proto_ff::escortchance & msg) const {
	msg.set_convoyid((int64_t)convoyId);
	for(int32_t i = 0; i < (int32_t)escort.GetSize() && i < escort.GetMaxSize(); ++i) {
		::proto_ff::escortchanceescortDesc* temp_escort = msg.add_escort();
		escort[i].write_to_pbmsg(*temp_escort);
	}
}

void escortchance_s::read_from_pbmsg(const ::proto_ff::escortchance & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct escortchance_s));
	convoyId = msg.convoyid();
	escort.SetSize(msg.escort_size() > escort.GetMaxSize() ? escort.GetMaxSize() : msg.escort_size());
	for(int32_t i = 0; i < (int32_t)escort.GetSize(); ++i) {
		const ::proto_ff::escortchanceescortDesc & temp_escort = msg.escort(i);
		escort[i].read_from_pbmsg(temp_escort);
	}
}

Sheet_escortchance_s::Sheet_escortchance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_escortchance_s::CreateInit() {
	return 0;
}

int Sheet_escortchance_s::ResumeInit() {
	return 0;
}

void Sheet_escortchance_s::write_to_pbmsg(::proto_ff::Sheet_escortchance & msg) const {
	for(int32_t i = 0; i < (int32_t)escortchance_List.GetSize() && i < escortchance_List.GetMaxSize(); ++i) {
		::proto_ff::escortchance* temp_escortchance_list = msg.add_escortchance_list();
		escortchance_List[i].write_to_pbmsg(*temp_escortchance_list);
	}
}

void Sheet_escortchance_s::read_from_pbmsg(const ::proto_ff::Sheet_escortchance & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_escortchance_s));
	escortchance_List.SetSize(msg.escortchance_list_size() > escortchance_List.GetMaxSize() ? escortchance_List.GetMaxSize() : msg.escortchance_list_size());
	for(int32_t i = 0; i < (int32_t)escortchance_List.GetSize(); ++i) {
		const ::proto_ff::escortchance & temp_escortchance_list = msg.escortchance_list(i);
		escortchance_List[i].read_from_pbmsg(temp_escortchance_list);
	}
}

escortrewardExprewardDesc_s::escortrewardExprewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int escortrewardExprewardDesc_s::CreateInit() {
	Exp = (int64_t)0;
	return 0;
}

int escortrewardExprewardDesc_s::ResumeInit() {
	return 0;
}

void escortrewardExprewardDesc_s::write_to_pbmsg(::proto_ff::escortrewardExprewardDesc & msg) const {
	msg.set_exp((int64_t)Exp);
}

void escortrewardExprewardDesc_s::read_from_pbmsg(const ::proto_ff::escortrewardExprewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct escortrewardExprewardDesc_s));
	Exp = msg.exp();
}

escortrewardExp_s::escortrewardExp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int escortrewardExp_s::CreateInit() {
	lv = (int32_t)0;
	return 0;
}

int escortrewardExp_s::ResumeInit() {
	return 0;
}

void escortrewardExp_s::write_to_pbmsg(::proto_ff::escortrewardExp & msg) const {
	msg.set_lv((int32_t)lv);
	for(int32_t i = 0; i < (int32_t)reward.GetSize() && i < reward.GetMaxSize(); ++i) {
		::proto_ff::escortrewardExprewardDesc* temp_reward = msg.add_reward();
		reward[i].write_to_pbmsg(*temp_reward);
	}
}

void escortrewardExp_s::read_from_pbmsg(const ::proto_ff::escortrewardExp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct escortrewardExp_s));
	lv = msg.lv();
	reward.SetSize(msg.reward_size() > reward.GetMaxSize() ? reward.GetMaxSize() : msg.reward_size());
	for(int32_t i = 0; i < (int32_t)reward.GetSize(); ++i) {
		const ::proto_ff::escortrewardExprewardDesc & temp_reward = msg.reward(i);
		reward[i].read_from_pbmsg(temp_reward);
	}
}

Sheet_escortrewardExp_s::Sheet_escortrewardExp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_escortrewardExp_s::CreateInit() {
	return 0;
}

int Sheet_escortrewardExp_s::ResumeInit() {
	return 0;
}

void Sheet_escortrewardExp_s::write_to_pbmsg(::proto_ff::Sheet_escortrewardExp & msg) const {
	for(int32_t i = 0; i < (int32_t)escortrewardExp_List.GetSize() && i < escortrewardExp_List.GetMaxSize(); ++i) {
		::proto_ff::escortrewardExp* temp_escortrewardexp_list = msg.add_escortrewardexp_list();
		escortrewardExp_List[i].write_to_pbmsg(*temp_escortrewardexp_list);
	}
}

void Sheet_escortrewardExp_s::read_from_pbmsg(const ::proto_ff::Sheet_escortrewardExp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_escortrewardExp_s));
	escortrewardExp_List.SetSize(msg.escortrewardexp_list_size() > escortrewardExp_List.GetMaxSize() ? escortrewardExp_List.GetMaxSize() : msg.escortrewardexp_list_size());
	for(int32_t i = 0; i < (int32_t)escortrewardExp_List.GetSize(); ++i) {
		const ::proto_ff::escortrewardExp & temp_escortrewardexp_list = msg.escortrewardexp_list(i);
		escortrewardExp_List[i].read_from_pbmsg(temp_escortrewardexp_list);
	}
}

}