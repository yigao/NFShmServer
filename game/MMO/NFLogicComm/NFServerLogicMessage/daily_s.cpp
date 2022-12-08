#include "daily_s.h"

namespace proto_ff_s {

dailydaily_s::dailydaily_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dailydaily_s::CreateInit() {
	id = (int64_t)0;
	type = (int32_t)0;
	args = (int32_t)0;
	playType = (int32_t)0;
	playArgs = (int32_t)0;
	funciontID = (int64_t)0;
	number = (int32_t)0;
	viptype = (int32_t)0;
	otherNum = (int32_t)0;
	eachScore = (int32_t)0;
	cycle = (int32_t)0;
	regReward = (int32_t)0;
	return 0;
}

int dailydaily_s::ResumeInit() {
	return 0;
}

void dailydaily_s::write_to_pbmsg(::proto_ff::dailydaily & msg) const {
	msg.set_id((int64_t)id);
	msg.set_name((const char*)name.Get());
	msg.set_type((int32_t)type);
	msg.set_args((int32_t)args);
	msg.set_playtype((int32_t)playType);
	msg.set_playargs((int32_t)playArgs);
	msg.set_funciontid((int64_t)funciontID);
	msg.set_number((int32_t)number);
	msg.set_viptype((int32_t)viptype);
	msg.set_othernum((int32_t)otherNum);
	msg.set_eachscore((int32_t)eachScore);
	msg.set_cycle((int32_t)cycle);
	msg.set_regreward((int32_t)regReward);
}

void dailydaily_s::read_from_pbmsg(const ::proto_ff::dailydaily & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dailydaily_s));
	id = msg.id();
	name.Copy(msg.name());
	type = msg.type();
	args = msg.args();
	playType = msg.playtype();
	playArgs = msg.playargs();
	funciontID = msg.funciontid();
	number = msg.number();
	viptype = msg.viptype();
	otherNum = msg.othernum();
	eachScore = msg.eachscore();
	cycle = msg.cycle();
	regReward = msg.regreward();
}

Sheet_dailydaily_s::Sheet_dailydaily_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_dailydaily_s::CreateInit() {
	return 0;
}

int Sheet_dailydaily_s::ResumeInit() {
	return 0;
}

void Sheet_dailydaily_s::write_to_pbmsg(::proto_ff::Sheet_dailydaily & msg) const {
	for(int32_t i = 0; i < (int32_t)dailydaily_List.GetSize() && i < dailydaily_List.GetMaxSize(); ++i) {
		::proto_ff::dailydaily* temp_dailydaily_list = msg.add_dailydaily_list();
		dailydaily_List[i].write_to_pbmsg(*temp_dailydaily_list);
	}
}

void Sheet_dailydaily_s::read_from_pbmsg(const ::proto_ff::Sheet_dailydaily & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_dailydaily_s));
	dailydaily_List.SetSize(msg.dailydaily_list_size() > dailydaily_List.GetMaxSize() ? dailydaily_List.GetMaxSize() : msg.dailydaily_list_size());
	for(int32_t i = 0; i < (int32_t)dailydaily_List.GetSize(); ++i) {
		const ::proto_ff::dailydaily & temp_dailydaily_list = msg.dailydaily_list(i);
		dailydaily_List[i].read_from_pbmsg(temp_dailydaily_list);
	}
}

dailyreward_s::dailyreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dailyreward_s::CreateInit() {
	id = (int32_t)0;
	type = (int32_t)0;
	activeScore = (int32_t)0;
	rewardId = (int64_t)0;
	rewardNum = (int32_t)0;
	return 0;
}

int dailyreward_s::ResumeInit() {
	return 0;
}

void dailyreward_s::write_to_pbmsg(::proto_ff::dailyreward & msg) const {
	msg.set_id((int32_t)id);
	msg.set_type((int32_t)type);
	msg.set_activescore((int32_t)activeScore);
	msg.set_rewardid((int64_t)rewardId);
	msg.set_rewardnum((int32_t)rewardNum);
}

void dailyreward_s::read_from_pbmsg(const ::proto_ff::dailyreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dailyreward_s));
	id = msg.id();
	type = msg.type();
	activeScore = msg.activescore();
	rewardId = msg.rewardid();
	rewardNum = msg.rewardnum();
}

Sheet_dailyreward_s::Sheet_dailyreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_dailyreward_s::CreateInit() {
	return 0;
}

int Sheet_dailyreward_s::ResumeInit() {
	return 0;
}

void Sheet_dailyreward_s::write_to_pbmsg(::proto_ff::Sheet_dailyreward & msg) const {
	for(int32_t i = 0; i < (int32_t)dailyreward_List.GetSize() && i < dailyreward_List.GetMaxSize(); ++i) {
		::proto_ff::dailyreward* temp_dailyreward_list = msg.add_dailyreward_list();
		dailyreward_List[i].write_to_pbmsg(*temp_dailyreward_list);
	}
}

void Sheet_dailyreward_s::read_from_pbmsg(const ::proto_ff::Sheet_dailyreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_dailyreward_s));
	dailyreward_List.SetSize(msg.dailyreward_list_size() > dailyreward_List.GetMaxSize() ? dailyreward_List.GetMaxSize() : msg.dailyreward_list_size());
	for(int32_t i = 0; i < (int32_t)dailyreward_List.GetSize(); ++i) {
		const ::proto_ff::dailyreward & temp_dailyreward_list = msg.dailyreward_list(i);
		dailyreward_List[i].read_from_pbmsg(temp_dailyreward_list);
	}
}

dailycultivateattributeDesc_s::dailycultivateattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dailycultivateattributeDesc_s::CreateInit() {
	ID = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int dailycultivateattributeDesc_s::ResumeInit() {
	return 0;
}

void dailycultivateattributeDesc_s::write_to_pbmsg(::proto_ff::dailycultivateattributeDesc & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_value((int32_t)Value);
}

void dailycultivateattributeDesc_s::read_from_pbmsg(const ::proto_ff::dailycultivateattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dailycultivateattributeDesc_s));
	ID = msg.id();
	Value = msg.value();
}

dailycultivate_s::dailycultivate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dailycultivate_s::CreateInit() {
	ID = (int32_t)0;
	lv = (int32_t)0;
	exp = (int32_t)0;
	return 0;
}

int dailycultivate_s::ResumeInit() {
	return 0;
}

void dailycultivate_s::write_to_pbmsg(::proto_ff::dailycultivate & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_lv((int32_t)lv);
	msg.set_exp((int32_t)exp);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::dailycultivateattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void dailycultivate_s::read_from_pbmsg(const ::proto_ff::dailycultivate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dailycultivate_s));
	ID = msg.id();
	lv = msg.lv();
	exp = msg.exp();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::dailycultivateattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_dailycultivate_s::Sheet_dailycultivate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_dailycultivate_s::CreateInit() {
	return 0;
}

int Sheet_dailycultivate_s::ResumeInit() {
	return 0;
}

void Sheet_dailycultivate_s::write_to_pbmsg(::proto_ff::Sheet_dailycultivate & msg) const {
	for(int32_t i = 0; i < (int32_t)dailycultivate_List.GetSize() && i < dailycultivate_List.GetMaxSize(); ++i) {
		::proto_ff::dailycultivate* temp_dailycultivate_list = msg.add_dailycultivate_list();
		dailycultivate_List[i].write_to_pbmsg(*temp_dailycultivate_list);
	}
}

void Sheet_dailycultivate_s::read_from_pbmsg(const ::proto_ff::Sheet_dailycultivate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_dailycultivate_s));
	dailycultivate_List.SetSize(msg.dailycultivate_list_size() > dailycultivate_List.GetMaxSize() ? dailycultivate_List.GetMaxSize() : msg.dailycultivate_list_size());
	for(int32_t i = 0; i < (int32_t)dailycultivate_List.GetSize(); ++i) {
		const ::proto_ff::dailycultivate & temp_dailycultivate_list = msg.dailycultivate_list(i);
		dailycultivate_List[i].read_from_pbmsg(temp_dailycultivate_list);
	}
}

}