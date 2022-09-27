#include "back_s.h"

namespace proto_ff_s {

backbackbackDesc_s::backbackbackDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int backbackbackDesc_s::CreateInit() {
	Expend = (int32_t)0;
	Num = (int32_t)0;
	Exp = (int32_t)0;
	return 0;
}

int backbackbackDesc_s::ResumeInit() {
	return 0;
}

void backbackbackDesc_s::write_to_pbmsg(::proto_ff::backbackbackDesc & msg) const {
	msg.set_expend((int32_t)Expend);
	msg.set_num((int32_t)Num);
	msg.set_exp((int32_t)Exp);
}

void backbackbackDesc_s::read_from_pbmsg(const ::proto_ff::backbackbackDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct backbackbackDesc_s));
	Expend = msg.expend();
	Num = msg.num();
	Exp = msg.exp();
}

backback_s::backback_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int backback_s::CreateInit() {
	id = (int32_t)0;
	type = (int32_t)0;
	backTimes = (int32_t)0;
	vipType = (int32_t)0;
	group = (int32_t)0;
	duplicateID = (int64_t)0;
	bossTypeID = (int64_t)0;
	functionUnlock = (int32_t)0;
	levelLimit = (int32_t)0;
	itemId = (int64_t)0;
	return 0;
}

int backback_s::ResumeInit() {
	return 0;
}

void backback_s::write_to_pbmsg(::proto_ff::backback & msg) const {
	msg.set_id((int32_t)id);
	msg.set_type((int32_t)type);
	msg.set_name((const char*)name.Get());
	msg.set_backtimes((int32_t)backTimes);
	msg.set_viptype((int32_t)vipType);
	msg.set_group((int32_t)group);
	msg.set_duplicateid((int64_t)duplicateID);
	msg.set_bosstypeid((int64_t)bossTypeID);
	msg.set_functionunlock((int32_t)functionUnlock);
	msg.set_levellimit((int32_t)levelLimit);
	msg.set_itemid((int64_t)itemId);
	msg.set_icon((const char*)icon.Get());
	for(int32_t i = 0; i < (int32_t)back.GetSize() && i < back.GetMaxSize(); ++i) {
		::proto_ff::backbackbackDesc* temp_back = msg.add_back();
		back[i].write_to_pbmsg(*temp_back);
	}
	for(int32_t i = 0; i < (int32_t)param.GetSize() && i < param.GetMaxSize(); ++i) {
		msg.add_param((int32_t)param[i]);
	}
}

void backback_s::read_from_pbmsg(const ::proto_ff::backback & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct backback_s));
	id = msg.id();
	type = msg.type();
	name.Copy(msg.name());
	backTimes = msg.backtimes();
	vipType = msg.viptype();
	group = msg.group();
	duplicateID = msg.duplicateid();
	bossTypeID = msg.bosstypeid();
	functionUnlock = msg.functionunlock();
	levelLimit = msg.levellimit();
	itemId = msg.itemid();
	icon.Copy(msg.icon());
	back.SetSize(msg.back_size() > back.GetMaxSize() ? back.GetMaxSize() : msg.back_size());
	for(int32_t i = 0; i < (int32_t)back.GetSize(); ++i) {
		const ::proto_ff::backbackbackDesc & temp_back = msg.back(i);
		back[i].read_from_pbmsg(temp_back);
	}
	param.SetSize(msg.param_size() > param.GetMaxSize() ? param.GetMaxSize() : msg.param_size());
	for(int32_t i = 0; i < (int32_t)param.GetSize(); ++i) {
		param[i] = msg.param(i);
	}
}

Sheet_backback_s::Sheet_backback_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_backback_s::CreateInit() {
	return 0;
}

int Sheet_backback_s::ResumeInit() {
	return 0;
}

void Sheet_backback_s::write_to_pbmsg(::proto_ff::Sheet_backback & msg) const {
	for(int32_t i = 0; i < (int32_t)backback_List.GetSize() && i < backback_List.GetMaxSize(); ++i) {
		::proto_ff::backback* temp_backback_list = msg.add_backback_list();
		backback_List[i].write_to_pbmsg(*temp_backback_list);
	}
}

void Sheet_backback_s::read_from_pbmsg(const ::proto_ff::Sheet_backback & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_backback_s));
	backback_List.SetSize(msg.backback_list_size() > backback_List.GetMaxSize() ? backback_List.GetMaxSize() : msg.backback_list_size());
	for(int32_t i = 0; i < (int32_t)backback_List.GetSize(); ++i) {
		const ::proto_ff::backback & temp_backback_list = msg.backback_list(i);
		backback_List[i].read_from_pbmsg(temp_backback_list);
	}
}

}