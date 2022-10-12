#include "gm5Help_s.h"

namespace proto_ff_s {

gm5Helpcons_s::gm5Helpcons_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int gm5Helpcons_s::CreateInit() {
	id = (int32_t)0;
	constantdata = (int64_t)0;
	return 0;
}

int gm5Helpcons_s::ResumeInit() {
	return 0;
}

void gm5Helpcons_s::write_to_pbmsg(::proto_ff::gm5Helpcons & msg) const {
	msg.set_id((int32_t)id);
	msg.set_constantdata((int64_t)constantdata);
	msg.set_stringdata((const char*)stringdata.Get());
}

void gm5Helpcons_s::read_from_pbmsg(const ::proto_ff::gm5Helpcons & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct gm5Helpcons_s));
	id = msg.id();
	constantdata = msg.constantdata();
	stringdata.Copy(msg.stringdata());
}

Sheet_gm5Helpcons_s::Sheet_gm5Helpcons_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_gm5Helpcons_s::CreateInit() {
	return 0;
}

int Sheet_gm5Helpcons_s::ResumeInit() {
	return 0;
}

void Sheet_gm5Helpcons_s::write_to_pbmsg(::proto_ff::Sheet_gm5Helpcons & msg) const {
	for(int32_t i = 0; i < (int32_t)gm5Helpcons_List.GetSize() && i < gm5Helpcons_List.GetMaxSize(); ++i) {
		::proto_ff::gm5Helpcons* temp_gm5helpcons_list = msg.add_gm5helpcons_list();
		gm5Helpcons_List[i].write_to_pbmsg(*temp_gm5helpcons_list);
	}
}

void Sheet_gm5Helpcons_s::read_from_pbmsg(const ::proto_ff::Sheet_gm5Helpcons & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_gm5Helpcons_s));
	gm5Helpcons_List.SetSize(msg.gm5helpcons_list_size() > gm5Helpcons_List.GetMaxSize() ? gm5Helpcons_List.GetMaxSize() : msg.gm5helpcons_list_size());
	for(int32_t i = 0; i < (int32_t)gm5Helpcons_List.GetSize(); ++i) {
		const ::proto_ff::gm5Helpcons & temp_gm5helpcons_list = msg.gm5helpcons_list(i);
		gm5Helpcons_List[i].read_from_pbmsg(temp_gm5helpcons_list);
	}
}

gm5HelprewardrewardDesc_s::gm5HelprewardrewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int gm5HelprewardrewardDesc_s::CreateInit() {
	ItemId = (int64_t)0;
	num = (int32_t)0;
	return 0;
}

int gm5HelprewardrewardDesc_s::ResumeInit() {
	return 0;
}

void gm5HelprewardrewardDesc_s::write_to_pbmsg(::proto_ff::gm5HelprewardrewardDesc & msg) const {
	msg.set_itemid((int64_t)ItemId);
	msg.set_num((int32_t)num);
}

void gm5HelprewardrewardDesc_s::read_from_pbmsg(const ::proto_ff::gm5HelprewardrewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct gm5HelprewardrewardDesc_s));
	ItemId = msg.itemid();
	num = msg.num();
}

gm5Helpreward_s::gm5Helpreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int gm5Helpreward_s::CreateInit() {
	id = (int32_t)0;
	rewardType = (int32_t)0;
	getNeed = (int32_t)0;
	return 0;
}

int gm5Helpreward_s::ResumeInit() {
	return 0;
}

void gm5Helpreward_s::write_to_pbmsg(::proto_ff::gm5Helpreward & msg) const {
	msg.set_id((int32_t)id);
	msg.set_rewardtype((int32_t)rewardType);
	msg.set_getneed((int32_t)getNeed);
	for(int32_t i = 0; i < (int32_t)reward.GetSize() && i < reward.GetMaxSize(); ++i) {
		::proto_ff::gm5HelprewardrewardDesc* temp_reward = msg.add_reward();
		reward[i].write_to_pbmsg(*temp_reward);
	}
}

void gm5Helpreward_s::read_from_pbmsg(const ::proto_ff::gm5Helpreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct gm5Helpreward_s));
	id = msg.id();
	rewardType = msg.rewardtype();
	getNeed = msg.getneed();
	reward.SetSize(msg.reward_size() > reward.GetMaxSize() ? reward.GetMaxSize() : msg.reward_size());
	for(int32_t i = 0; i < (int32_t)reward.GetSize(); ++i) {
		const ::proto_ff::gm5HelprewardrewardDesc & temp_reward = msg.reward(i);
		reward[i].read_from_pbmsg(temp_reward);
	}
}

Sheet_gm5Helpreward_s::Sheet_gm5Helpreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_gm5Helpreward_s::CreateInit() {
	return 0;
}

int Sheet_gm5Helpreward_s::ResumeInit() {
	return 0;
}

void Sheet_gm5Helpreward_s::write_to_pbmsg(::proto_ff::Sheet_gm5Helpreward & msg) const {
	for(int32_t i = 0; i < (int32_t)gm5Helpreward_List.GetSize() && i < gm5Helpreward_List.GetMaxSize(); ++i) {
		::proto_ff::gm5Helpreward* temp_gm5helpreward_list = msg.add_gm5helpreward_list();
		gm5Helpreward_List[i].write_to_pbmsg(*temp_gm5helpreward_list);
	}
}

void Sheet_gm5Helpreward_s::read_from_pbmsg(const ::proto_ff::Sheet_gm5Helpreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_gm5Helpreward_s));
	gm5Helpreward_List.SetSize(msg.gm5helpreward_list_size() > gm5Helpreward_List.GetMaxSize() ? gm5Helpreward_List.GetMaxSize() : msg.gm5helpreward_list_size());
	for(int32_t i = 0; i < (int32_t)gm5Helpreward_List.GetSize(); ++i) {
		const ::proto_ff::gm5Helpreward & temp_gm5helpreward_list = msg.gm5helpreward_list(i);
		gm5Helpreward_List[i].read_from_pbmsg(temp_gm5helpreward_list);
	}
}

}