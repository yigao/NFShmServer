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
	id = (int64_t)0;
	level = (int32_t)0;
	vipType = (int32_t)0;
	exp = (int32_t)0;
	chat = (int64_t)0;
	return 0;
}

int vipvip_s::ResumeInit() {
	return 0;
}

void vipvip_s::write_to_pbmsg(::proto_ff::vipvip & msg) const {
	msg.set_id((int64_t)id);
	msg.set_level((int32_t)level);
	msg.set_viptype((int32_t)vipType);
	msg.set_exp((int32_t)exp);
	msg.set_privilege_id((const char*)privilege_id.Get());
	msg.set_chat((int64_t)chat);
}

void vipvip_s::read_from_pbmsg(const ::proto_ff::vipvip & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct vipvip_s));
	id = msg.id();
	level = msg.level();
	vipType = msg.viptype();
	exp = msg.exp();
	privilege_id.Copy(msg.privilege_id());
	chat = msg.chat();
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
	id = (int64_t)0;
	type = (int32_t)0;
	return 0;
}

int vipprivilege_s::ResumeInit() {
	return 0;
}

void vipprivilege_s::write_to_pbmsg(::proto_ff::vipprivilege & msg) const {
	msg.set_id((int64_t)id);
	msg.set_type((int32_t)type);
	msg.set_canshustring((const char*)canshuString.Get());
	for(int32_t i = 0; i < (int32_t)canshu.GetSize() && i < canshu.GetMaxSize(); ++i) {
		msg.add_canshu((int32_t)canshu[i]);
	}
}

void vipprivilege_s::read_from_pbmsg(const ::proto_ff::vipprivilege & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct vipprivilege_s));
	id = msg.id();
	type = msg.type();
	canshuString.Copy(msg.canshustring());
	canshu.SetSize(msg.canshu_size() > canshu.GetMaxSize() ? canshu.GetMaxSize() : msg.canshu_size());
	for(int32_t i = 0; i < (int32_t)canshu.GetSize(); ++i) {
		canshu[i] = msg.canshu(i);
	}
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

vipgift_s::vipgift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int vipgift_s::CreateInit() {
	ID = (int64_t)0;
	Type = (int32_t)0;
	VipLv = (int32_t)0;
	moneyType = (int32_t)0;
	OriginalPrice = (int32_t)0;
	Price = (int32_t)0;
	boxid = (int64_t)0;
	return 0;
}

int vipgift_s::ResumeInit() {
	return 0;
}

void vipgift_s::write_to_pbmsg(::proto_ff::vipgift & msg) const {
	msg.set_id((int64_t)ID);
	msg.set_type((int32_t)Type);
	msg.set_viplv((int32_t)VipLv);
	msg.set_moneytype((int32_t)moneyType);
	msg.set_originalprice((int32_t)OriginalPrice);
	msg.set_price((int32_t)Price);
	msg.set_boxid((int64_t)boxid);
}

void vipgift_s::read_from_pbmsg(const ::proto_ff::vipgift & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct vipgift_s));
	ID = msg.id();
	Type = msg.type();
	VipLv = msg.viplv();
	moneyType = msg.moneytype();
	OriginalPrice = msg.originalprice();
	Price = msg.price();
	boxid = msg.boxid();
}

Sheet_vipgift_s::Sheet_vipgift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_vipgift_s::CreateInit() {
	return 0;
}

int Sheet_vipgift_s::ResumeInit() {
	return 0;
}

void Sheet_vipgift_s::write_to_pbmsg(::proto_ff::Sheet_vipgift & msg) const {
	for(int32_t i = 0; i < (int32_t)vipgift_List.GetSize() && i < vipgift_List.GetMaxSize(); ++i) {
		::proto_ff::vipgift* temp_vipgift_list = msg.add_vipgift_list();
		vipgift_List[i].write_to_pbmsg(*temp_vipgift_list);
	}
}

void Sheet_vipgift_s::read_from_pbmsg(const ::proto_ff::Sheet_vipgift & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_vipgift_s));
	vipgift_List.SetSize(msg.vipgift_list_size() > vipgift_List.GetMaxSize() ? vipgift_List.GetMaxSize() : msg.vipgift_list_size());
	for(int32_t i = 0; i < (int32_t)vipgift_List.GetSize(); ++i) {
		const ::proto_ff::vipgift & temp_vipgift_list = msg.vipgift_list(i);
		vipgift_List[i].read_from_pbmsg(temp_vipgift_list);
	}
}

}