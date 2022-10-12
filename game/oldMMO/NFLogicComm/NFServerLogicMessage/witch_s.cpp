#include "witch_s.h"

namespace proto_ff_s {

witchawarditemDesc_s::witchawarditemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int witchawarditemDesc_s::CreateInit() {
	num = (int32_t)0;
	name = (int64_t)0;
	return 0;
}

int witchawarditemDesc_s::ResumeInit() {
	return 0;
}

void witchawarditemDesc_s::write_to_pbmsg(::proto_ff::witchawarditemDesc & msg) const {
	msg.set_num((int32_t)num);
	msg.set_name((int64_t)name);
}

void witchawarditemDesc_s::read_from_pbmsg(const ::proto_ff::witchawarditemDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct witchawarditemDesc_s));
	num = msg.num();
	name = msg.name();
}

witchaward_s::witchaward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int witchaward_s::CreateInit() {
	id = (int32_t)0;
	rank1 = (int32_t)0;
	rank2 = (int32_t)0;
	integral_blue_nub = (int32_t)0;
	integral_purple_nub = (int32_t)0;
	integral_red_nub = (int32_t)0;
	return 0;
}

int witchaward_s::ResumeInit() {
	return 0;
}

void witchaward_s::write_to_pbmsg(::proto_ff::witchaward & msg) const {
	msg.set_id((int32_t)id);
	msg.set_rank1((int32_t)rank1);
	msg.set_rank2((int32_t)rank2);
	msg.set_integral_blue_nub((int32_t)integral_blue_nub);
	msg.set_integral_purple_nub((int32_t)integral_purple_nub);
	msg.set_integral_red_nub((int32_t)integral_red_nub);
	for(int32_t i = 0; i < (int32_t)item.GetSize() && i < item.GetMaxSize(); ++i) {
		::proto_ff::witchawarditemDesc* temp_item = msg.add_item();
		item[i].write_to_pbmsg(*temp_item);
	}
}

void witchaward_s::read_from_pbmsg(const ::proto_ff::witchaward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct witchaward_s));
	id = msg.id();
	rank1 = msg.rank1();
	rank2 = msg.rank2();
	integral_blue_nub = msg.integral_blue_nub();
	integral_purple_nub = msg.integral_purple_nub();
	integral_red_nub = msg.integral_red_nub();
	item.SetSize(msg.item_size() > item.GetMaxSize() ? item.GetMaxSize() : msg.item_size());
	for(int32_t i = 0; i < (int32_t)item.GetSize(); ++i) {
		const ::proto_ff::witchawarditemDesc & temp_item = msg.item(i);
		item[i].read_from_pbmsg(temp_item);
	}
}

Sheet_witchaward_s::Sheet_witchaward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_witchaward_s::CreateInit() {
	return 0;
}

int Sheet_witchaward_s::ResumeInit() {
	return 0;
}

void Sheet_witchaward_s::write_to_pbmsg(::proto_ff::Sheet_witchaward & msg) const {
	for(int32_t i = 0; i < (int32_t)witchaward_List.GetSize() && i < witchaward_List.GetMaxSize(); ++i) {
		::proto_ff::witchaward* temp_witchaward_list = msg.add_witchaward_list();
		witchaward_List[i].write_to_pbmsg(*temp_witchaward_list);
	}
}

void Sheet_witchaward_s::read_from_pbmsg(const ::proto_ff::Sheet_witchaward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_witchaward_s));
	witchaward_List.SetSize(msg.witchaward_list_size() > witchaward_List.GetMaxSize() ? witchaward_List.GetMaxSize() : msg.witchaward_list_size());
	for(int32_t i = 0; i < (int32_t)witchaward_List.GetSize(); ++i) {
		const ::proto_ff::witchaward & temp_witchaward_list = msg.witchaward_list(i);
		witchaward_List[i].read_from_pbmsg(temp_witchaward_list);
	}
}

witchsummon_s::witchsummon_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int witchsummon_s::CreateInit() {
	id = (int32_t)0;
	consume = (int32_t)0;
	bossId = (int64_t)0;
	item = (int64_t)0;
	purpleDrill = (int32_t)0;
	xzhou = (int32_t)0;
	yzhou = (int32_t)0;
	zzhou = (int32_t)0;
	return 0;
}

int witchsummon_s::ResumeInit() {
	return 0;
}

void witchsummon_s::write_to_pbmsg(::proto_ff::witchsummon & msg) const {
	msg.set_id((int32_t)id);
	msg.set_consume((int32_t)consume);
	msg.set_bossid((int64_t)bossId);
	msg.set_item((int64_t)item);
	msg.set_purpledrill((int32_t)purpleDrill);
	msg.set_xzhou((int32_t)xzhou);
	msg.set_yzhou((int32_t)yzhou);
	msg.set_zzhou((int32_t)zzhou);
}

void witchsummon_s::read_from_pbmsg(const ::proto_ff::witchsummon & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct witchsummon_s));
	id = msg.id();
	consume = msg.consume();
	bossId = msg.bossid();
	item = msg.item();
	purpleDrill = msg.purpledrill();
	xzhou = msg.xzhou();
	yzhou = msg.yzhou();
	zzhou = msg.zzhou();
}

Sheet_witchsummon_s::Sheet_witchsummon_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_witchsummon_s::CreateInit() {
	return 0;
}

int Sheet_witchsummon_s::ResumeInit() {
	return 0;
}

void Sheet_witchsummon_s::write_to_pbmsg(::proto_ff::Sheet_witchsummon & msg) const {
	for(int32_t i = 0; i < (int32_t)witchsummon_List.GetSize() && i < witchsummon_List.GetMaxSize(); ++i) {
		::proto_ff::witchsummon* temp_witchsummon_list = msg.add_witchsummon_list();
		witchsummon_List[i].write_to_pbmsg(*temp_witchsummon_list);
	}
}

void Sheet_witchsummon_s::read_from_pbmsg(const ::proto_ff::Sheet_witchsummon & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_witchsummon_s));
	witchsummon_List.SetSize(msg.witchsummon_list_size() > witchsummon_List.GetMaxSize() ? witchsummon_List.GetMaxSize() : msg.witchsummon_list_size());
	for(int32_t i = 0; i < (int32_t)witchsummon_List.GetSize(); ++i) {
		const ::proto_ff::witchsummon & temp_witchsummon_list = msg.witchsummon_list(i);
		witchsummon_List[i].read_from_pbmsg(temp_witchsummon_list);
	}
}

witchrewardExp_s::witchrewardExp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int witchrewardExp_s::CreateInit() {
	lv = (int32_t)0;
	reward_Exp = (int64_t)0;
	return 0;
}

int witchrewardExp_s::ResumeInit() {
	return 0;
}

void witchrewardExp_s::write_to_pbmsg(::proto_ff::witchrewardExp & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_reward_exp((int64_t)reward_Exp);
}

void witchrewardExp_s::read_from_pbmsg(const ::proto_ff::witchrewardExp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct witchrewardExp_s));
	lv = msg.lv();
	reward_Exp = msg.reward_exp();
}

Sheet_witchrewardExp_s::Sheet_witchrewardExp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_witchrewardExp_s::CreateInit() {
	return 0;
}

int Sheet_witchrewardExp_s::ResumeInit() {
	return 0;
}

void Sheet_witchrewardExp_s::write_to_pbmsg(::proto_ff::Sheet_witchrewardExp & msg) const {
	for(int32_t i = 0; i < (int32_t)witchrewardExp_List.GetSize() && i < witchrewardExp_List.GetMaxSize(); ++i) {
		::proto_ff::witchrewardExp* temp_witchrewardexp_list = msg.add_witchrewardexp_list();
		witchrewardExp_List[i].write_to_pbmsg(*temp_witchrewardexp_list);
	}
}

void Sheet_witchrewardExp_s::read_from_pbmsg(const ::proto_ff::Sheet_witchrewardExp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_witchrewardExp_s));
	witchrewardExp_List.SetSize(msg.witchrewardexp_list_size() > witchrewardExp_List.GetMaxSize() ? witchrewardExp_List.GetMaxSize() : msg.witchrewardexp_list_size());
	for(int32_t i = 0; i < (int32_t)witchrewardExp_List.GetSize(); ++i) {
		const ::proto_ff::witchrewardExp & temp_witchrewardexp_list = msg.witchrewardexp_list(i);
		witchrewardExp_List[i].read_from_pbmsg(temp_witchrewardexp_list);
	}
}

}