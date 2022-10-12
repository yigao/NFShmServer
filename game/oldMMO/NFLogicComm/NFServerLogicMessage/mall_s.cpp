#include "mall_s.h"

namespace proto_ff_s {

mallmall_s::mallmall_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int mallmall_s::CreateInit() {
	id = (int64_t)0;
	itemID = (int64_t)0;
	num = (int32_t)0;
	mallType = (int64_t)0;
	subType = (int32_t)0;
	priority = (int32_t)0;
	moneyType = (int32_t)0;
	price = (int32_t)0;
	discount = (int32_t)0;
	daily = (int32_t)0;
	isClose = (int32_t)0;
	cantBuy = (int32_t)0;
	isMarkBind = (int32_t)0;
	roleLimit = (int32_t)0;
	functionUnlock = (int32_t)0;
	return 0;
}

int mallmall_s::ResumeInit() {
	return 0;
}

void mallmall_s::write_to_pbmsg(::proto_ff::mallmall & msg) const {
	msg.set_id((int64_t)id);
	msg.set_itemid((int64_t)itemID);
	msg.set_num((int32_t)num);
	msg.set_malltype((int64_t)mallType);
	msg.set_subtype((int32_t)subType);
	msg.set_priority((int32_t)priority);
	msg.set_moneytype((int32_t)moneyType);
	msg.set_price((int32_t)price);
	msg.set_discount((int32_t)discount);
	msg.set_daily((int32_t)daily);
	msg.set_buyamount((const char*)buyAmount.Get());
	msg.set_viplimit((const char*)vipLimit.Get());
	msg.set_isclose((int32_t)isClose);
	msg.set_cantbuy((int32_t)cantBuy);
	msg.set_ismarkbind((int32_t)isMarkBind);
	msg.set_rolelimit((int32_t)roleLimit);
	msg.set_functionunlock((int32_t)functionUnlock);
}

void mallmall_s::read_from_pbmsg(const ::proto_ff::mallmall & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct mallmall_s));
	id = msg.id();
	itemID = msg.itemid();
	num = msg.num();
	mallType = msg.malltype();
	subType = msg.subtype();
	priority = msg.priority();
	moneyType = msg.moneytype();
	price = msg.price();
	discount = msg.discount();
	daily = msg.daily();
	buyAmount.Copy(msg.buyamount());
	vipLimit.Copy(msg.viplimit());
	isClose = msg.isclose();
	cantBuy = msg.cantbuy();
	isMarkBind = msg.ismarkbind();
	roleLimit = msg.rolelimit();
	functionUnlock = msg.functionunlock();
}

Sheet_mallmall_s::Sheet_mallmall_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_mallmall_s::CreateInit() {
	return 0;
}

int Sheet_mallmall_s::ResumeInit() {
	return 0;
}

void Sheet_mallmall_s::write_to_pbmsg(::proto_ff::Sheet_mallmall & msg) const {
	for(int32_t i = 0; i < (int32_t)mallmall_List.GetSize() && i < mallmall_List.GetMaxSize(); ++i) {
		::proto_ff::mallmall* temp_mallmall_list = msg.add_mallmall_list();
		mallmall_List[i].write_to_pbmsg(*temp_mallmall_list);
	}
}

void Sheet_mallmall_s::read_from_pbmsg(const ::proto_ff::Sheet_mallmall & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_mallmall_s));
	mallmall_List.SetSize(msg.mallmall_list_size() > mallmall_List.GetMaxSize() ? mallmall_List.GetMaxSize() : msg.mallmall_list_size());
	for(int32_t i = 0; i < (int32_t)mallmall_List.GetSize(); ++i) {
		const ::proto_ff::mallmall & temp_mallmall_list = msg.mallmall_list(i);
		mallmall_List[i].read_from_pbmsg(temp_mallmall_list);
	}
}

mallmalltype_s::mallmalltype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int mallmalltype_s::CreateInit() {
	id = (int64_t)0;
	groupType = (int32_t)0;
	priority = (int32_t)0;
	logicType = (int32_t)0;
	functionunlock = (int32_t)0;
	return 0;
}

int mallmalltype_s::ResumeInit() {
	return 0;
}

void mallmalltype_s::write_to_pbmsg(::proto_ff::mallmalltype & msg) const {
	msg.set_id((int64_t)id);
	msg.set_title((const char*)title.Get());
	msg.set_tab((const char*)tab.Get());
	msg.set_grouptype((int32_t)groupType);
	msg.set_priority((int32_t)priority);
	msg.set_logictype((int32_t)logicType);
	msg.set_functionunlock((int32_t)functionunlock);
}

void mallmalltype_s::read_from_pbmsg(const ::proto_ff::mallmalltype & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct mallmalltype_s));
	id = msg.id();
	title.Copy(msg.title());
	tab.Copy(msg.tab());
	groupType = msg.grouptype();
	priority = msg.priority();
	logicType = msg.logictype();
	functionunlock = msg.functionunlock();
}

Sheet_mallmalltype_s::Sheet_mallmalltype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_mallmalltype_s::CreateInit() {
	return 0;
}

int Sheet_mallmalltype_s::ResumeInit() {
	return 0;
}

void Sheet_mallmalltype_s::write_to_pbmsg(::proto_ff::Sheet_mallmalltype & msg) const {
	for(int32_t i = 0; i < (int32_t)mallmalltype_List.GetSize() && i < mallmalltype_List.GetMaxSize(); ++i) {
		::proto_ff::mallmalltype* temp_mallmalltype_list = msg.add_mallmalltype_list();
		mallmalltype_List[i].write_to_pbmsg(*temp_mallmalltype_list);
	}
}

void Sheet_mallmalltype_s::read_from_pbmsg(const ::proto_ff::Sheet_mallmalltype & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_mallmalltype_s));
	mallmalltype_List.SetSize(msg.mallmalltype_list_size() > mallmalltype_List.GetMaxSize() ? mallmalltype_List.GetMaxSize() : msg.mallmalltype_list_size());
	for(int32_t i = 0; i < (int32_t)mallmalltype_List.GetSize(); ++i) {
		const ::proto_ff::mallmalltype & temp_mallmalltype_list = msg.mallmalltype_list(i);
		mallmalltype_List[i].read_from_pbmsg(temp_mallmalltype_list);
	}
}

}