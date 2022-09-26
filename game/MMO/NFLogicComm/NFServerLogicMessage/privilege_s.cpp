#include "privilege_s.h"

namespace proto_ff_s {

privilegeprivilege_s::privilegeprivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int privilegeprivilege_s::CreateInit() {
	id = (int64_t)0;
	showType = (int32_t)0;
	type = (int32_t)0;
	param = (int32_t)0;
	openReward = (int64_t)0;
	dailyReward = (int64_t)0;
	resourceLimit = (int32_t)0;
	skillid = (int64_t)0;
	return 0;
}

int privilegeprivilege_s::ResumeInit() {
	return 0;
}

void privilegeprivilege_s::write_to_pbmsg(::proto_ff::privilegeprivilege & msg) const {
	msg.set_id((int64_t)id);
	msg.set_showtype((int32_t)showType);
	msg.set_type((int32_t)type);
	msg.set_param((int32_t)param);
	msg.set_severparam((const char*)severParam.Get());
	msg.set_openreward((int64_t)openReward);
	msg.set_dailyreward((int64_t)dailyReward);
	msg.set_resourcelimit((int32_t)resourceLimit);
	msg.set_skillid((int64_t)skillid);
	msg.set_privilege_id((const char*)privilege_id.Get());
}

void privilegeprivilege_s::read_from_pbmsg(const ::proto_ff::privilegeprivilege & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct privilegeprivilege_s));
	id = msg.id();
	showType = msg.showtype();
	type = msg.type();
	param = msg.param();
	severParam.Copy(msg.severparam());
	openReward = msg.openreward();
	dailyReward = msg.dailyreward();
	resourceLimit = msg.resourcelimit();
	skillid = msg.skillid();
	privilege_id.Copy(msg.privilege_id());
}

Sheet_privilegeprivilege_s::Sheet_privilegeprivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_privilegeprivilege_s::CreateInit() {
	return 0;
}

int Sheet_privilegeprivilege_s::ResumeInit() {
	return 0;
}

void Sheet_privilegeprivilege_s::write_to_pbmsg(::proto_ff::Sheet_privilegeprivilege & msg) const {
	for(int32_t i = 0; i < (int32_t)privilegeprivilege_List.GetSize() && i < privilegeprivilege_List.GetMaxSize(); ++i) {
		::proto_ff::privilegeprivilege* temp_privilegeprivilege_list = msg.add_privilegeprivilege_list();
		privilegeprivilege_List[i].write_to_pbmsg(*temp_privilegeprivilege_list);
	}
}

void Sheet_privilegeprivilege_s::read_from_pbmsg(const ::proto_ff::Sheet_privilegeprivilege & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_privilegeprivilege_s));
	privilegeprivilege_List.SetSize(msg.privilegeprivilege_list_size() > privilegeprivilege_List.GetMaxSize() ? privilegeprivilege_List.GetMaxSize() : msg.privilegeprivilege_list_size());
	for(int32_t i = 0; i < (int32_t)privilegeprivilege_List.GetSize(); ++i) {
		const ::proto_ff::privilegeprivilege & temp_privilegeprivilege_list = msg.privilegeprivilege_list(i);
		privilegeprivilege_List[i].read_from_pbmsg(temp_privilegeprivilege_list);
	}
}

}