#include "drop_s.h"

namespace proto_ff_s {

dropdropitemDesc_s::dropdropitemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dropdropitemDesc_s::CreateInit() {
	rand = (int32_t)0;
	maxNum = (int32_t)0;
	minNum = (int32_t)0;
	return 0;
}

int dropdropitemDesc_s::ResumeInit() {
	return 0;
}

void dropdropitemDesc_s::write_to_pbmsg(::proto_ff::dropdropitemDesc & msg) const {
	msg.set_bd((const char*)bd.Get());
	msg.set_rand((int32_t)rand);
	msg.set_maxnum((int32_t)maxNum);
	msg.set_qz((const char*)QZ.Get());
	msg.set_minnum((int32_t)minNum);
	msg.set_id((const char*)id.Get());
}

void dropdropitemDesc_s::read_from_pbmsg(const ::proto_ff::dropdropitemDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dropdropitemDesc_s));
	bd.Copy(msg.bd());
	rand = msg.rand();
	maxNum = msg.maxnum();
	QZ.Copy(msg.qz());
	minNum = msg.minnum();
	id.Copy(msg.id());
}

dropdropitemTeamDesc_s::dropdropitemTeamDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dropdropitemTeamDesc_s::CreateInit() {
	rand = (int32_t)0;
	maxNum = (int32_t)0;
	minNum = (int32_t)0;
	return 0;
}

int dropdropitemTeamDesc_s::ResumeInit() {
	return 0;
}

void dropdropitemTeamDesc_s::write_to_pbmsg(::proto_ff::dropdropitemTeamDesc & msg) const {
	msg.set_bd((const char*)bd.Get());
	msg.set_rand((int32_t)rand);
	msg.set_maxnum((int32_t)maxNum);
	msg.set_qz((const char*)QZ.Get());
	msg.set_minnum((int32_t)minNum);
	msg.set_id((const char*)id.Get());
}

void dropdropitemTeamDesc_s::read_from_pbmsg(const ::proto_ff::dropdropitemTeamDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dropdropitemTeamDesc_s));
	bd.Copy(msg.bd());
	rand = msg.rand();
	maxNum = msg.maxnum();
	QZ.Copy(msg.qz());
	minNum = msg.minnum();
	id.Copy(msg.id());
}

dropdropequipDesc_s::dropdropequipDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dropdropequipDesc_s::CreateInit() {
	rand = (int32_t)0;
	maxNum = (int32_t)0;
	minNum = (int32_t)0;
	return 0;
}

int dropdropequipDesc_s::ResumeInit() {
	return 0;
}

void dropdropequipDesc_s::write_to_pbmsg(::proto_ff::dropdropequipDesc & msg) const {
	msg.set_rand((int32_t)rand);
	msg.set_maxnum((int32_t)maxNum);
	msg.set_weight((const char*)weight.Get());
	msg.set_minnum((int32_t)minNum);
	msg.set_isbind((const char*)isbind.Get());
	msg.set_prof((const char*)prof.Get());
	msg.set_id((const char*)id.Get());
}

void dropdropequipDesc_s::read_from_pbmsg(const ::proto_ff::dropdropequipDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dropdropequipDesc_s));
	rand = msg.rand();
	maxNum = msg.maxnum();
	weight.Copy(msg.weight());
	minNum = msg.minnum();
	isbind.Copy(msg.isbind());
	prof.Copy(msg.prof());
	id.Copy(msg.id());
}

dropdrop_s::dropdrop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dropdrop_s::CreateInit() {
	id = (int64_t)0;
	goldlow = (int32_t)0;
	goldup = (int32_t)0;
	gold_heapMin = (int32_t)0;
	gold_heapMax = (int32_t)0;
	gold_rand = (int32_t)0;
	return 0;
}

int dropdrop_s::ResumeInit() {
	return 0;
}

void dropdrop_s::write_to_pbmsg(::proto_ff::dropdrop & msg) const {
	msg.set_id((int64_t)id);
	msg.set_goldlow((int32_t)goldlow);
	msg.set_goldup((int32_t)goldup);
	msg.set_gold_heapmin((int32_t)gold_heapMin);
	msg.set_gold_heapmax((int32_t)gold_heapMax);
	msg.set_gold_rand((int32_t)gold_rand);
	for(int32_t i = 0; i < (int32_t)item.GetSize() && i < item.GetMaxSize(); ++i) {
		::proto_ff::dropdropitemDesc* temp_item = msg.add_item();
		item[i].write_to_pbmsg(*temp_item);
	}
	for(int32_t i = 0; i < (int32_t)itemTeam.GetSize() && i < itemTeam.GetMaxSize(); ++i) {
		::proto_ff::dropdropitemTeamDesc* temp_itemteam = msg.add_itemteam();
		itemTeam[i].write_to_pbmsg(*temp_itemteam);
	}
	for(int32_t i = 0; i < (int32_t)equip.GetSize() && i < equip.GetMaxSize(); ++i) {
		::proto_ff::dropdropequipDesc* temp_equip = msg.add_equip();
		equip[i].write_to_pbmsg(*temp_equip);
	}
}

void dropdrop_s::read_from_pbmsg(const ::proto_ff::dropdrop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dropdrop_s));
	id = msg.id();
	goldlow = msg.goldlow();
	goldup = msg.goldup();
	gold_heapMin = msg.gold_heapmin();
	gold_heapMax = msg.gold_heapmax();
	gold_rand = msg.gold_rand();
	item.SetSize(msg.item_size() > item.GetMaxSize() ? item.GetMaxSize() : msg.item_size());
	for(int32_t i = 0; i < (int32_t)item.GetSize(); ++i) {
		const ::proto_ff::dropdropitemDesc & temp_item = msg.item(i);
		item[i].read_from_pbmsg(temp_item);
	}
	itemTeam.SetSize(msg.itemteam_size() > itemTeam.GetMaxSize() ? itemTeam.GetMaxSize() : msg.itemteam_size());
	for(int32_t i = 0; i < (int32_t)itemTeam.GetSize(); ++i) {
		const ::proto_ff::dropdropitemTeamDesc & temp_itemteam = msg.itemteam(i);
		itemTeam[i].read_from_pbmsg(temp_itemteam);
	}
	equip.SetSize(msg.equip_size() > equip.GetMaxSize() ? equip.GetMaxSize() : msg.equip_size());
	for(int32_t i = 0; i < (int32_t)equip.GetSize(); ++i) {
		const ::proto_ff::dropdropequipDesc & temp_equip = msg.equip(i);
		equip[i].read_from_pbmsg(temp_equip);
	}
}

Sheet_dropdrop_s::Sheet_dropdrop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_dropdrop_s::CreateInit() {
	return 0;
}

int Sheet_dropdrop_s::ResumeInit() {
	return 0;
}

void Sheet_dropdrop_s::write_to_pbmsg(::proto_ff::Sheet_dropdrop & msg) const {
	for(int32_t i = 0; i < (int32_t)dropdrop_List.GetSize() && i < dropdrop_List.GetMaxSize(); ++i) {
		::proto_ff::dropdrop* temp_dropdrop_list = msg.add_dropdrop_list();
		dropdrop_List[i].write_to_pbmsg(*temp_dropdrop_list);
	}
}

void Sheet_dropdrop_s::read_from_pbmsg(const ::proto_ff::Sheet_dropdrop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_dropdrop_s));
	dropdrop_List.SetSize(msg.dropdrop_list_size() > dropdrop_List.GetMaxSize() ? dropdrop_List.GetMaxSize() : msg.dropdrop_list_size());
	for(int32_t i = 0; i < (int32_t)dropdrop_List.GetSize(); ++i) {
		const ::proto_ff::dropdrop & temp_dropdrop_list = msg.dropdrop_list(i);
		dropdrop_List[i].read_from_pbmsg(temp_dropdrop_list);
	}
}

}