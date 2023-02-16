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
	for(int32_t i = 0; i < (int32_t)base_attr.size(); ++i) {
		msg.add_base_attr((int32_t)base_attr[i]);
	}
	for(int32_t i = 0; i < (int32_t)star_attr.size(); ++i) {
		msg.add_star_attr((int32_t)star_attr[i]);
	}
	for(int32_t i = 0; i < (int32_t)blue_attr.size(); ++i) {
		msg.add_blue_attr((int32_t)blue_attr[i]);
	}
	for(int32_t i = 0; i < (int32_t)god_attr.size(); ++i) {
		msg.add_god_attr((int32_t)god_attr[i]);
	}
	for(int32_t i = 0; i < (int32_t)special_attr.size(); ++i) {
		msg.add_special_attr((int32_t)special_attr[i]);
	}
}

void EquipExt_s::read_from_pbmsg(const ::proto_ff::EquipExt & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct EquipExt_s));
	base_attr.resize((int)msg.base_attr_size() > (int)base_attr.max_size() ? base_attr.max_size() : msg.base_attr_size());
	for(int32_t i = 0; i < (int32_t)base_attr.size(); ++i) {
		base_attr[i] = msg.base_attr(i);
	}
	star_attr.resize((int)msg.star_attr_size() > (int)star_attr.max_size() ? star_attr.max_size() : msg.star_attr_size());
	for(int32_t i = 0; i < (int32_t)star_attr.size(); ++i) {
		star_attr[i] = msg.star_attr(i);
	}
	blue_attr.resize((int)msg.blue_attr_size() > (int)blue_attr.max_size() ? blue_attr.max_size() : msg.blue_attr_size());
	for(int32_t i = 0; i < (int32_t)blue_attr.size(); ++i) {
		blue_attr[i] = msg.blue_attr(i);
	}
	god_attr.resize((int)msg.god_attr_size() > (int)god_attr.max_size() ? god_attr.max_size() : msg.god_attr_size());
	for(int32_t i = 0; i < (int32_t)god_attr.size(); ++i) {
		god_attr[i] = msg.god_attr(i);
	}
	special_attr.resize((int)msg.special_attr_size() > (int)special_attr.max_size() ? special_attr.max_size() : msg.special_attr_size());
	for(int32_t i = 0; i < (int32_t)special_attr.size(); ++i) {
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