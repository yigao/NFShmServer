#include "box_s.h"

namespace proto_ff_s {

boxboxboxdataDesc_s::boxboxboxdataDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int boxboxboxdataDesc_s::CreateInit() {
	maxTimes = (int32_t)0;
	id = (int64_t)0;
	weight = (int32_t)0;
	minTimes = (int32_t)0;
	return 0;
}

int boxboxboxdataDesc_s::ResumeInit() {
	return 0;
}

void boxboxboxdataDesc_s::write_to_pbmsg(::proto_ff::boxboxboxdataDesc & msg) const {
	msg.set_maxtimes((int32_t)maxTimes);
	msg.set_id((int64_t)id);
	msg.set_weight((int32_t)weight);
	msg.set_mintimes((int32_t)minTimes);
}

void boxboxboxdataDesc_s::read_from_pbmsg(const ::proto_ff::boxboxboxdataDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct boxboxboxdataDesc_s));
	maxTimes = msg.maxtimes();
	id = msg.id();
	weight = msg.weight();
	minTimes = msg.mintimes();
}

boxbox_s::boxbox_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int boxbox_s::CreateInit() {
	id = (int64_t)0;
	type = (int32_t)0;
	Rate = (int32_t)0;
	Mask = (int32_t)0;
	minTimes = (int32_t)0;
	maxTimes = (int32_t)0;
	return 0;
}

int boxbox_s::ResumeInit() {
	return 0;
}

void boxbox_s::write_to_pbmsg(::proto_ff::boxbox & msg) const {
	msg.set_id((int64_t)id);
	msg.set_type((int32_t)type);
	msg.set_rate((int32_t)Rate);
	msg.set_mask((int32_t)Mask);
	msg.set_mintimes((int32_t)minTimes);
	msg.set_maxtimes((int32_t)maxTimes);
	for(int32_t i = 0; i < (int32_t)boxdata.GetSize() && i < boxdata.GetMaxSize(); ++i) {
		::proto_ff::boxboxboxdataDesc* temp_boxdata = msg.add_boxdata();
		boxdata[i].write_to_pbmsg(*temp_boxdata);
	}
}

void boxbox_s::read_from_pbmsg(const ::proto_ff::boxbox & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct boxbox_s));
	id = msg.id();
	type = msg.type();
	Rate = msg.rate();
	Mask = msg.mask();
	minTimes = msg.mintimes();
	maxTimes = msg.maxtimes();
	boxdata.SetSize(msg.boxdata_size() > boxdata.GetMaxSize() ? boxdata.GetMaxSize() : msg.boxdata_size());
	for(int32_t i = 0; i < (int32_t)boxdata.GetSize(); ++i) {
		const ::proto_ff::boxboxboxdataDesc & temp_boxdata = msg.boxdata(i);
		boxdata[i].read_from_pbmsg(temp_boxdata);
	}
}

Sheet_boxbox_s::Sheet_boxbox_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_boxbox_s::CreateInit() {
	return 0;
}

int Sheet_boxbox_s::ResumeInit() {
	return 0;
}

void Sheet_boxbox_s::write_to_pbmsg(::proto_ff::Sheet_boxbox & msg) const {
	for(int32_t i = 0; i < (int32_t)boxbox_List.GetSize() && i < boxbox_List.GetMaxSize(); ++i) {
		::proto_ff::boxbox* temp_boxbox_list = msg.add_boxbox_list();
		boxbox_List[i].write_to_pbmsg(*temp_boxbox_list);
	}
}

void Sheet_boxbox_s::read_from_pbmsg(const ::proto_ff::Sheet_boxbox & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_boxbox_s));
	boxbox_List.SetSize(msg.boxbox_list_size() > boxbox_List.GetMaxSize() ? boxbox_List.GetMaxSize() : msg.boxbox_list_size());
	for(int32_t i = 0; i < (int32_t)boxbox_List.GetSize(); ++i) {
		const ::proto_ff::boxbox & temp_boxbox_list = msg.boxbox_list(i);
		boxbox_List[i].read_from_pbmsg(temp_boxbox_list);
	}
}

boxboxdataequipDesc_s::boxboxdataequipDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int boxboxdataequipDesc_s::CreateInit() {
	rand = (int32_t)0;
	minNum = (int32_t)0;
	isbind = (int32_t)0;
	maxNum = (int32_t)0;
	return 0;
}

int boxboxdataequipDesc_s::ResumeInit() {
	return 0;
}

void boxboxdataequipDesc_s::write_to_pbmsg(::proto_ff::boxboxdataequipDesc & msg) const {
	msg.set_rand((int32_t)rand);
	msg.set_minnum((int32_t)minNum);
	msg.set_isbind((int32_t)isbind);
	msg.set_maxnum((int32_t)maxNum);
	msg.set_id((const char*)id.Get());
}

void boxboxdataequipDesc_s::read_from_pbmsg(const ::proto_ff::boxboxdataequipDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct boxboxdataequipDesc_s));
	rand = msg.rand();
	minNum = msg.minnum();
	isbind = msg.isbind();
	maxNum = msg.maxnum();
	id.Copy(msg.id());
}

boxboxdataitemDesc_s::boxboxdataitemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int boxboxdataitemDesc_s::CreateInit() {
	maxNum = (int32_t)0;
	rarerand = (int32_t)0;
	minNum = (int32_t)0;
	return 0;
}

int boxboxdataitemDesc_s::ResumeInit() {
	return 0;
}

void boxboxdataitemDesc_s::write_to_pbmsg(::proto_ff::boxboxdataitemDesc & msg) const {
	msg.set_rand((const char*)rand.Get());
	msg.set_maxnum((int32_t)maxNum);
	msg.set_rarerand((int32_t)rarerand);
	msg.set_minnum((int32_t)minNum);
	msg.set_isbind((const char*)isbind.Get());
	msg.set_id((const char*)id.Get());
}

void boxboxdataitemDesc_s::read_from_pbmsg(const ::proto_ff::boxboxdataitemDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct boxboxdataitemDesc_s));
	rand.Copy(msg.rand());
	maxNum = msg.maxnum();
	rarerand = msg.rarerand();
	minNum = msg.minnum();
	isbind.Copy(msg.isbind());
	id.Copy(msg.id());
}

boxboxdata_s::boxboxdata_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int boxboxdata_s::CreateInit() {
	id = (int64_t)0;
	drop_type = (int32_t)0;
	goldminNum = (int32_t)0;
	goldmaxNum = (int32_t)0;
	goldrand = (int32_t)0;
	bindjewelminNum = (int32_t)0;
	bindjewelmaxNum = (int32_t)0;
	bindjewelrand = (int32_t)0;
	jewelminNum = (int32_t)0;
	jewelmaxNum = (int32_t)0;
	jewelrand = (int32_t)0;
	return 0;
}

int boxboxdata_s::ResumeInit() {
	return 0;
}

void boxboxdata_s::write_to_pbmsg(::proto_ff::boxboxdata & msg) const {
	msg.set_id((int64_t)id);
	msg.set_drop_type((int32_t)drop_type);
	msg.set_goldminnum((int32_t)goldminNum);
	msg.set_goldmaxnum((int32_t)goldmaxNum);
	msg.set_goldrand((int32_t)goldrand);
	msg.set_bindjewelminnum((int32_t)bindjewelminNum);
	msg.set_bindjewelmaxnum((int32_t)bindjewelmaxNum);
	msg.set_bindjewelrand((int32_t)bindjewelrand);
	msg.set_jewelminnum((int32_t)jewelminNum);
	msg.set_jewelmaxnum((int32_t)jewelmaxNum);
	msg.set_jewelrand((int32_t)jewelrand);
	msg.set_eq_profession((const char*)eq_profession.Get());
	for(int32_t i = 0; i < (int32_t)equip.GetSize() && i < equip.GetMaxSize(); ++i) {
		::proto_ff::boxboxdataequipDesc* temp_equip = msg.add_equip();
		equip[i].write_to_pbmsg(*temp_equip);
	}
	for(int32_t i = 0; i < (int32_t)item.GetSize() && i < item.GetMaxSize(); ++i) {
		::proto_ff::boxboxdataitemDesc* temp_item = msg.add_item();
		item[i].write_to_pbmsg(*temp_item);
	}
}

void boxboxdata_s::read_from_pbmsg(const ::proto_ff::boxboxdata & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct boxboxdata_s));
	id = msg.id();
	drop_type = msg.drop_type();
	goldminNum = msg.goldminnum();
	goldmaxNum = msg.goldmaxnum();
	goldrand = msg.goldrand();
	bindjewelminNum = msg.bindjewelminnum();
	bindjewelmaxNum = msg.bindjewelmaxnum();
	bindjewelrand = msg.bindjewelrand();
	jewelminNum = msg.jewelminnum();
	jewelmaxNum = msg.jewelmaxnum();
	jewelrand = msg.jewelrand();
	eq_profession.Copy(msg.eq_profession());
	equip.SetSize(msg.equip_size() > equip.GetMaxSize() ? equip.GetMaxSize() : msg.equip_size());
	for(int32_t i = 0; i < (int32_t)equip.GetSize(); ++i) {
		const ::proto_ff::boxboxdataequipDesc & temp_equip = msg.equip(i);
		equip[i].read_from_pbmsg(temp_equip);
	}
	item.SetSize(msg.item_size() > item.GetMaxSize() ? item.GetMaxSize() : msg.item_size());
	for(int32_t i = 0; i < (int32_t)item.GetSize(); ++i) {
		const ::proto_ff::boxboxdataitemDesc & temp_item = msg.item(i);
		item[i].read_from_pbmsg(temp_item);
	}
}

Sheet_boxboxdata_s::Sheet_boxboxdata_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_boxboxdata_s::CreateInit() {
	return 0;
}

int Sheet_boxboxdata_s::ResumeInit() {
	return 0;
}

void Sheet_boxboxdata_s::write_to_pbmsg(::proto_ff::Sheet_boxboxdata & msg) const {
	for(int32_t i = 0; i < (int32_t)boxboxdata_List.GetSize() && i < boxboxdata_List.GetMaxSize(); ++i) {
		::proto_ff::boxboxdata* temp_boxboxdata_list = msg.add_boxboxdata_list();
		boxboxdata_List[i].write_to_pbmsg(*temp_boxboxdata_list);
	}
}

void Sheet_boxboxdata_s::read_from_pbmsg(const ::proto_ff::Sheet_boxboxdata & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_boxboxdata_s));
	boxboxdata_List.SetSize(msg.boxboxdata_list_size() > boxboxdata_List.GetMaxSize() ? boxboxdata_List.GetMaxSize() : msg.boxboxdata_list_size());
	for(int32_t i = 0; i < (int32_t)boxboxdata_List.GetSize(); ++i) {
		const ::proto_ff::boxboxdata & temp_boxboxdata_list = msg.boxboxdata_list(i);
		boxboxdata_List[i].read_from_pbmsg(temp_boxboxdata_list);
	}
}

}