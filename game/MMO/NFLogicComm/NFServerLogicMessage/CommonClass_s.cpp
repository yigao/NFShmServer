#include "CommonClass_s.h"

namespace proto_ff_s {

GridItemBase_s::GridItemBase_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GridItemBase_s::CreateInit() {
	index = (uint64_t)0;
	item_id = (uint64_t)0;
	item_num = (uint64_t)0;
	bind = (bool)0;
	level = (uint32_t)0;
	expireTime = (uint64_t)0;
	type = (uint32_t)0;
	return 0;
}

int GridItemBase_s::ResumeInit() {
	return 0;
}

void GridItemBase_s::write_to_pbmsg(::proto_ff::GridItemBase & msg) const {
	msg.set_index((uint64_t)index);
	msg.set_item_id((uint64_t)item_id);
	msg.set_item_num((uint64_t)item_num);
	msg.set_bind((bool)bind);
	msg.set_level((uint32_t)level);
	msg.set_expiretime((uint64_t)expireTime);
	msg.set_type((uint32_t)type);
}

void GridItemBase_s::read_from_pbmsg(const ::proto_ff::GridItemBase & msg) {
	index = msg.index();
	item_id = msg.item_id();
	item_num = msg.item_num();
	bind = msg.bind();
	level = msg.level();
	expireTime = msg.expiretime();
	type = msg.type();
}

EquipExt_s::EquipExt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int EquipExt_s::CreateInit() {
	strong_lv = (int32_t)0;
	strong_wear_quality = (int32_t)0;
	return 0;
}

int EquipExt_s::ResumeInit() {
	return 0;
}

void EquipExt_s::write_to_pbmsg(::proto_ff::EquipExt & msg) const {
	for(int32_t i = 0; i < (int32_t)base.size(); ++i) {
		::proto_ff::Attr* temp_base = msg.add_base();
		base[i].write_to_pbmsg(*temp_base);
	}
	for(int32_t i = 0; i < (int32_t)refine.size(); ++i) {
		::proto_ff::Attr* temp_refine = msg.add_refine();
		refine[i].write_to_pbmsg(*temp_refine);
	}
	for(int32_t i = 0; i < (int32_t)blue.size(); ++i) {
		::proto_ff::BlueStarAttr* temp_blue = msg.add_blue();
		blue[i].write_to_pbmsg(*temp_blue);
	}
	for(int32_t i = 0; i < (int32_t)god.size(); ++i) {
		::proto_ff::Attr* temp_god = msg.add_god();
		god[i].write_to_pbmsg(*temp_god);
	}
	for(int32_t i = 0; i < (int32_t)special.size(); ++i) {
		::proto_ff::Attr* temp_special = msg.add_special();
		special[i].write_to_pbmsg(*temp_special);
	}
	msg.set_strong_lv((int32_t)strong_lv);
	msg.set_strong_wear_quality((int32_t)strong_wear_quality);
}

void EquipExt_s::read_from_pbmsg(const ::proto_ff::EquipExt & msg) {
	base.resize((int)msg.base_size() > (int)base.max_size() ? base.max_size() : msg.base_size());
	for(int32_t i = 0; i < (int32_t)base.size(); ++i) {
		const ::proto_ff::Attr & temp_base = msg.base(i);
		base[i].read_from_pbmsg(temp_base);
	}
	refine.resize((int)msg.refine_size() > (int)refine.max_size() ? refine.max_size() : msg.refine_size());
	for(int32_t i = 0; i < (int32_t)refine.size(); ++i) {
		const ::proto_ff::Attr & temp_refine = msg.refine(i);
		refine[i].read_from_pbmsg(temp_refine);
	}
	blue.resize((int)msg.blue_size() > (int)blue.max_size() ? blue.max_size() : msg.blue_size());
	for(int32_t i = 0; i < (int32_t)blue.size(); ++i) {
		const ::proto_ff::BlueStarAttr & temp_blue = msg.blue(i);
		blue[i].read_from_pbmsg(temp_blue);
	}
	god.resize((int)msg.god_size() > (int)god.max_size() ? god.max_size() : msg.god_size());
	for(int32_t i = 0; i < (int32_t)god.size(); ++i) {
		const ::proto_ff::Attr & temp_god = msg.god(i);
		god[i].read_from_pbmsg(temp_god);
	}
	special.resize((int)msg.special_size() > (int)special.max_size() ? special.max_size() : msg.special_size());
	for(int32_t i = 0; i < (int32_t)special.size(); ++i) {
		const ::proto_ff::Attr & temp_special = msg.special(i);
		special[i].read_from_pbmsg(temp_special);
	}
	strong_lv = msg.strong_lv();
	strong_wear_quality = msg.strong_wear_quality();
}

ItemGridCSData_s::ItemGridCSData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ItemGridCSData_s::CreateInit() {
	return 0;
}

int ItemGridCSData_s::ResumeInit() {
	return 0;
}

void ItemGridCSData_s::write_to_pbmsg(::proto_ff::ItemGridCSData & msg) const {
	::proto_ff::GridItemBase* temp_base = msg.mutable_base();
	base.write_to_pbmsg(*temp_base);
	::proto_ff::EquipExt* temp_equip_data = msg.mutable_equip_data();
	equip_data.write_to_pbmsg(*temp_equip_data);
}

void ItemGridCSData_s::read_from_pbmsg(const ::proto_ff::ItemGridCSData & msg) {
	const ::proto_ff::GridItemBase & temp_base = msg.base();
	base.read_from_pbmsg(temp_base);
	const ::proto_ff::EquipExt & temp_equip_data = msg.equip_data();
	equip_data.read_from_pbmsg(temp_equip_data);
}

}
