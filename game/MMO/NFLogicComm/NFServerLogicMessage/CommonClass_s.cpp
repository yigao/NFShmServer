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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GridItemBase_s));
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
	return 0;
}

int EquipExt_s::ResumeInit() {
	return 0;
}

void EquipExt_s::write_to_pbmsg(::proto_ff::EquipExt & msg) const {
	for(int32_t i = 0; i < (int32_t)base_attr.GetSize() && i < base_attr.GetMaxSize(); ++i) {
		msg.add_base_attr((int32_t)base_attr[i]);
	}
	for(int32_t i = 0; i < (int32_t)star_attr.GetSize() && i < star_attr.GetMaxSize(); ++i) {
		msg.add_star_attr((int32_t)star_attr[i]);
	}
	for(int32_t i = 0; i < (int32_t)blue_attr.GetSize() && i < blue_attr.GetMaxSize(); ++i) {
		msg.add_blue_attr((int32_t)blue_attr[i]);
	}
	for(int32_t i = 0; i < (int32_t)god_attr.GetSize() && i < god_attr.GetMaxSize(); ++i) {
		msg.add_god_attr((int32_t)god_attr[i]);
	}
	for(int32_t i = 0; i < (int32_t)special_attr.GetSize() && i < special_attr.GetMaxSize(); ++i) {
		msg.add_special_attr((int32_t)special_attr[i]);
	}
}

void EquipExt_s::read_from_pbmsg(const ::proto_ff::EquipExt & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct EquipExt_s));
	base_attr.SetSize(msg.base_attr_size() > base_attr.GetMaxSize() ? base_attr.GetMaxSize() : msg.base_attr_size());
	for(int32_t i = 0; i < (int32_t)base_attr.GetSize(); ++i) {
		base_attr[i] = msg.base_attr(i);
	}
	star_attr.SetSize(msg.star_attr_size() > star_attr.GetMaxSize() ? star_attr.GetMaxSize() : msg.star_attr_size());
	for(int32_t i = 0; i < (int32_t)star_attr.GetSize(); ++i) {
		star_attr[i] = msg.star_attr(i);
	}
	blue_attr.SetSize(msg.blue_attr_size() > blue_attr.GetMaxSize() ? blue_attr.GetMaxSize() : msg.blue_attr_size());
	for(int32_t i = 0; i < (int32_t)blue_attr.GetSize(); ++i) {
		blue_attr[i] = msg.blue_attr(i);
	}
	god_attr.SetSize(msg.god_attr_size() > god_attr.GetMaxSize() ? god_attr.GetMaxSize() : msg.god_attr_size());
	for(int32_t i = 0; i < (int32_t)god_attr.GetSize(); ++i) {
		god_attr[i] = msg.god_attr(i);
	}
	special_attr.SetSize(msg.special_attr_size() > special_attr.GetMaxSize() ? special_attr.GetMaxSize() : msg.special_attr_size());
	for(int32_t i = 0; i < (int32_t)special_attr.GetSize(); ++i) {
		special_attr[i] = msg.special_attr(i);
	}
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ItemGridCSData_s));
	const ::proto_ff::GridItemBase & temp_base = msg.base();
	base.read_from_pbmsg(temp_base);
	const ::proto_ff::EquipExt & temp_equip_data = msg.equip_data();
	equip_data.read_from_pbmsg(temp_equip_data);
}

}