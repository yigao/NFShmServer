#include "vip_s.h"

namespace proto_ff_s {

vipvip_s::vipvip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int vipvip_s::CreateInit() {
	id = (int32_t)0;
	level = (int32_t)0;
	exp = (int32_t)0;
	privilege_group = (int32_t)0;
	return 0;
}

int vipvip_s::ResumeInit() {
	return 0;
}

void vipvip_s::write_to_pbmsg(::proto_ff::vipvip & msg) const {
	msg.set_id((int32_t)id);
	msg.set_level((int32_t)level);
	msg.set_exp((int32_t)exp);
	msg.set_privilege_group((int32_t)privilege_group);
}

void vipvip_s::read_from_pbmsg(const ::proto_ff::vipvip & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct vipvip_s));
	id = msg.id();
	level = msg.level();
	exp = msg.exp();
	privilege_group = msg.privilege_group();
}

Sheet_vipvip_s::Sheet_vipvip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_vipvip_s::CreateInit() {
	return 0;
}

int Sheet_vipvip_s::ResumeInit() {
	return 0;
}

void Sheet_vipvip_s::write_to_pbmsg(::proto_ff::Sheet_vipvip & msg) const {
	for(int32_t i = 0; i < (int32_t)vipvip_List.GetSize() && i < vipvip_List.GetMaxSize(); ++i) {
		::proto_ff::vipvip* temp_vipvip_list = msg.add_vipvip_list();
		vipvip_List[i].write_to_pbmsg(*temp_vipvip_list);
	}
}

void Sheet_vipvip_s::read_from_pbmsg(const ::proto_ff::Sheet_vipvip & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_vipvip_s));
	vipvip_List.SetSize(msg.vipvip_list_size() > vipvip_List.GetMaxSize() ? vipvip_List.GetMaxSize() : msg.vipvip_list_size());
	for(int32_t i = 0; i < (int32_t)vipvip_List.GetSize(); ++i) {
		const ::proto_ff::vipvip & temp_vipvip_list = msg.vipvip_list(i);
		vipvip_List[i].read_from_pbmsg(temp_vipvip_list);
	}
}

vipprivilege_s::vipprivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int vipprivilege_s::CreateInit() {
	id = (int32_t)0;
	group = (int32_t)0;
	type = (int32_t)0;
	arg = (int32_t)0;
	return 0;
}

int vipprivilege_s::ResumeInit() {
	return 0;
}

void vipprivilege_s::write_to_pbmsg(::proto_ff::vipprivilege & msg) const {
	msg.set_id((int32_t)id);
	msg.set_group((int32_t)group);
	msg.set_type((int32_t)type);
	msg.set_arg((int32_t)arg);
	msg.set_args((const char*)args.Get());
}

void vipprivilege_s::read_from_pbmsg(const ::proto_ff::vipprivilege & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct vipprivilege_s));
	id = msg.id();
	group = msg.group();
	type = msg.type();
	arg = msg.arg();
	args.Copy(msg.args());
}

Sheet_vipprivilege_s::Sheet_vipprivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_vipprivilege_s::CreateInit() {
	return 0;
}

int Sheet_vipprivilege_s::ResumeInit() {
	return 0;
}

void Sheet_vipprivilege_s::write_to_pbmsg(::proto_ff::Sheet_vipprivilege & msg) const {
	for(int32_t i = 0; i < (int32_t)vipprivilege_List.GetSize() && i < vipprivilege_List.GetMaxSize(); ++i) {
		::proto_ff::vipprivilege* temp_vipprivilege_list = msg.add_vipprivilege_list();
		vipprivilege_List[i].write_to_pbmsg(*temp_vipprivilege_list);
	}
}

void Sheet_vipprivilege_s::read_from_pbmsg(const ::proto_ff::Sheet_vipprivilege & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_vipprivilege_s));
	vipprivilege_List.SetSize(msg.vipprivilege_list_size() > vipprivilege_List.GetMaxSize() ? vipprivilege_List.GetMaxSize() : msg.vipprivilege_list_size());
	for(int32_t i = 0; i < (int32_t)vipprivilege_List.GetSize(); ++i) {
		const ::proto_ff::vipprivilege & temp_vipprivilege_list = msg.vipprivilege_list(i);
		vipprivilege_List[i].read_from_pbmsg(temp_vipprivilege_list);
	}
}

}