#include "godRelics_s.h"

namespace proto_ff_s {

godRelicsgodRelics_s::godRelicsgodRelics_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int godRelicsgodRelics_s::CreateInit() {
	id = (int32_t)0;
	functionId = (int32_t)0;
	group = (int32_t)0;
	skillID = (int32_t)0;
	return 0;
}

int godRelicsgodRelics_s::ResumeInit() {
	return 0;
}

void godRelicsgodRelics_s::write_to_pbmsg(::proto_ff::godRelicsgodRelics & msg) const {
	msg.set_id((int32_t)id);
	msg.set_functionid((int32_t)functionId);
	msg.set_group((int32_t)group);
	msg.set_skillid((int32_t)skillID);
}

void godRelicsgodRelics_s::read_from_pbmsg(const ::proto_ff::godRelicsgodRelics & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct godRelicsgodRelics_s));
	id = msg.id();
	functionId = msg.functionid();
	group = msg.group();
	skillID = msg.skillid();
}

Sheet_godRelicsgodRelics_s::Sheet_godRelicsgodRelics_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_godRelicsgodRelics_s::CreateInit() {
	return 0;
}

int Sheet_godRelicsgodRelics_s::ResumeInit() {
	return 0;
}

void Sheet_godRelicsgodRelics_s::write_to_pbmsg(::proto_ff::Sheet_godRelicsgodRelics & msg) const {
	for(int32_t i = 0; i < (int32_t)godRelicsgodRelics_List.GetSize() && i < godRelicsgodRelics_List.GetMaxSize(); ++i) {
		::proto_ff::godRelicsgodRelics* temp_godrelicsgodrelics_list = msg.add_godrelicsgodrelics_list();
		godRelicsgodRelics_List[i].write_to_pbmsg(*temp_godrelicsgodrelics_list);
	}
}

void Sheet_godRelicsgodRelics_s::read_from_pbmsg(const ::proto_ff::Sheet_godRelicsgodRelics & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_godRelicsgodRelics_s));
	godRelicsgodRelics_List.SetSize(msg.godrelicsgodrelics_list_size() > godRelicsgodRelics_List.GetMaxSize() ? godRelicsgodRelics_List.GetMaxSize() : msg.godrelicsgodrelics_list_size());
	for(int32_t i = 0; i < (int32_t)godRelicsgodRelics_List.GetSize(); ++i) {
		const ::proto_ff::godRelicsgodRelics & temp_godrelicsgodrelics_list = msg.godrelicsgodrelics_list(i);
		godRelicsgodRelics_List[i].read_from_pbmsg(temp_godrelicsgodrelics_list);
	}
}

godRelicscondition_s::godRelicscondition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int godRelicscondition_s::CreateInit() {
	id = (int32_t)0;
	group = (int32_t)0;
	conditon = (int32_t)0;
	count = (int32_t)0;
	rewardItem = (int32_t)0;
	rewardNumber = (int32_t)0;
	return 0;
}

int godRelicscondition_s::ResumeInit() {
	return 0;
}

void godRelicscondition_s::write_to_pbmsg(::proto_ff::godRelicscondition & msg) const {
	msg.set_id((int32_t)id);
	msg.set_group((int32_t)group);
	msg.set_conditon((int32_t)conditon);
	msg.set_parama((const char*)parama.Get());
	msg.set_count((int32_t)count);
	msg.set_rewarditem((int32_t)rewardItem);
	msg.set_rewardnumber((int32_t)rewardNumber);
}

void godRelicscondition_s::read_from_pbmsg(const ::proto_ff::godRelicscondition & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct godRelicscondition_s));
	id = msg.id();
	group = msg.group();
	conditon = msg.conditon();
	parama.Copy(msg.parama());
	count = msg.count();
	rewardItem = msg.rewarditem();
	rewardNumber = msg.rewardnumber();
}

Sheet_godRelicscondition_s::Sheet_godRelicscondition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_godRelicscondition_s::CreateInit() {
	return 0;
}

int Sheet_godRelicscondition_s::ResumeInit() {
	return 0;
}

void Sheet_godRelicscondition_s::write_to_pbmsg(::proto_ff::Sheet_godRelicscondition & msg) const {
	for(int32_t i = 0; i < (int32_t)godRelicscondition_List.GetSize() && i < godRelicscondition_List.GetMaxSize(); ++i) {
		::proto_ff::godRelicscondition* temp_godrelicscondition_list = msg.add_godrelicscondition_list();
		godRelicscondition_List[i].write_to_pbmsg(*temp_godrelicscondition_list);
	}
}

void Sheet_godRelicscondition_s::read_from_pbmsg(const ::proto_ff::Sheet_godRelicscondition & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_godRelicscondition_s));
	godRelicscondition_List.SetSize(msg.godrelicscondition_list_size() > godRelicscondition_List.GetMaxSize() ? godRelicscondition_List.GetMaxSize() : msg.godrelicscondition_list_size());
	for(int32_t i = 0; i < (int32_t)godRelicscondition_List.GetSize(); ++i) {
		const ::proto_ff::godRelicscondition & temp_godrelicscondition_list = msg.godrelicscondition_list(i);
		godRelicscondition_List[i].read_from_pbmsg(temp_godrelicscondition_list);
	}
}

}