#include "item_s.h"

namespace proto_ff_s {

itemitem_s::itemitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int itemitem_s::CreateInit() {
	id = (int64_t)0;
	itemType = (int32_t)0;
	subType = (int32_t)0;
	functionType = (int32_t)0;
	level = (int32_t)0;
	quality = (int32_t)0;
	levelRequest = (int32_t)0;
	bindType = (int32_t)0;
	isTradeBind = (int32_t)0;
	stackLimit = (int32_t)0;
	sellPrice = (int32_t)0;
	sellBox = (int64_t)0;
	broadcast = (int32_t)0;
	isCanBatchUse = (int32_t)0;
	dayUse = (int32_t)0;
	outTime = (int32_t)0;
	dayOutTime = (int32_t)0;
	blessing = (int32_t)0;
	invest = (int32_t)0;
	exchange = (int64_t)0;
	return 0;
}

int itemitem_s::ResumeInit() {
	return 0;
}

void itemitem_s::write_to_pbmsg(::proto_ff::itemitem & msg) const {
	msg.set_id((int64_t)id);
	msg.set_name((const char*)name.Get());
	msg.set_itemtype((int32_t)itemType);
	msg.set_subtype((int32_t)subType);
	msg.set_functiontype((int32_t)functionType);
	msg.set_functionvalue((const char*)functionValue.Get());
	msg.set_usecondition((const char*)usecondition.Get());
	msg.set_level((int32_t)level);
	msg.set_quality((int32_t)quality);
	msg.set_levelrequest((int32_t)levelRequest);
	msg.set_profession((const char*)profession.Get());
	msg.set_bindtype((int32_t)bindType);
	msg.set_istradebind((int32_t)isTradeBind);
	msg.set_stacklimit((int32_t)stackLimit);
	msg.set_sellprice((int32_t)sellPrice);
	msg.set_sellbox((int64_t)sellBox);
	msg.set_broadcast((int32_t)broadcast);
	msg.set_iscanbatchuse((int32_t)isCanBatchUse);
	msg.set_dayuse((int32_t)dayUse);
	msg.set_outtime((int32_t)outTime);
	msg.set_dayouttime((int32_t)dayOutTime);
	msg.set_uselimit((const char*)useLimit.Get());
	msg.set_blessing((int32_t)blessing);
	msg.set_invest((int32_t)invest);
	msg.set_exchange((int64_t)exchange);
}

void itemitem_s::read_from_pbmsg(const ::proto_ff::itemitem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct itemitem_s));
	id = msg.id();
	name.Copy(msg.name());
	itemType = msg.itemtype();
	subType = msg.subtype();
	functionType = msg.functiontype();
	functionValue.Copy(msg.functionvalue());
	usecondition.Copy(msg.usecondition());
	level = msg.level();
	quality = msg.quality();
	levelRequest = msg.levelrequest();
	profession.Copy(msg.profession());
	bindType = msg.bindtype();
	isTradeBind = msg.istradebind();
	stackLimit = msg.stacklimit();
	sellPrice = msg.sellprice();
	sellBox = msg.sellbox();
	broadcast = msg.broadcast();
	isCanBatchUse = msg.iscanbatchuse();
	dayUse = msg.dayuse();
	outTime = msg.outtime();
	dayOutTime = msg.dayouttime();
	useLimit.Copy(msg.uselimit());
	blessing = msg.blessing();
	invest = msg.invest();
	exchange = msg.exchange();
}

Sheet_itemitem_s::Sheet_itemitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_itemitem_s::CreateInit() {
	return 0;
}

int Sheet_itemitem_s::ResumeInit() {
	return 0;
}

void Sheet_itemitem_s::write_to_pbmsg(::proto_ff::Sheet_itemitem & msg) const {
	for(int32_t i = 0; i < (int32_t)itemitem_List.GetSize() && i < itemitem_List.GetMaxSize(); ++i) {
		::proto_ff::itemitem* temp_itemitem_list = msg.add_itemitem_list();
		itemitem_List[i].write_to_pbmsg(*temp_itemitem_list);
	}
}

void Sheet_itemitem_s::read_from_pbmsg(const ::proto_ff::Sheet_itemitem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_itemitem_s));
	itemitem_List.SetSize(msg.itemitem_list_size() > itemitem_List.GetMaxSize() ? itemitem_List.GetMaxSize() : msg.itemitem_list_size());
	for(int32_t i = 0; i < (int32_t)itemitem_List.GetSize(); ++i) {
		const ::proto_ff::itemitem & temp_itemitem_list = msg.itemitem_list(i);
		itemitem_List[i].read_from_pbmsg(temp_itemitem_list);
	}
}

}