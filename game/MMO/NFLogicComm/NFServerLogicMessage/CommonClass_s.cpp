#include "CommonClass_s.h"

namespace proto_ff_s {

ItemBase_s::ItemBase_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ItemBase_s::CreateInit() {
	index = (uint32_t)0;
	item_id = (uint32_t)0;
	item_num = (uint64_t)0;
	bind = (bool)0;
	level = (uint32_t)0;
	expireTime = (uint64_t)0;
	type = (uint32_t)0;
	return 0;
}

int ItemBase_s::ResumeInit() {
	return 0;
}

void ItemBase_s::write_to_pbmsg(::proto_ff::ItemBase & msg) const {
	msg.set_index((uint32_t)index);
	msg.set_item_id((uint32_t)item_id);
	msg.set_item_num((uint64_t)item_num);
	msg.set_bind((bool)bind);
	msg.set_level((uint32_t)level);
	msg.set_expiretime((uint64_t)expireTime);
	msg.set_type((uint32_t)type);
}

void ItemBase_s::read_from_pbmsg(const ::proto_ff::ItemBase & msg) {
	index = msg.index();
	item_id = msg.item_id();
	item_num = msg.item_num();
	bind = msg.bind();
	level = msg.level();
	expireTime = msg.expiretime();
	type = msg.type();
}

EquipBase_s::EquipBase_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int EquipBase_s::CreateInit() {
	base_attr_percent = (uint32_t)0;
	star_attr_percent = (uint32_t)0;
	god_attr_percent = (uint32_t)0;
	return 0;
}

int EquipBase_s::ResumeInit() {
	return 0;
}

void EquipBase_s::write_to_pbmsg(::proto_ff::EquipBase & msg) const {
	msg.set_base_attr_percent((uint32_t)base_attr_percent);
	msg.set_star_attr_percent((uint32_t)star_attr_percent);
	msg.set_god_attr_percent((uint32_t)god_attr_percent);
}

void EquipBase_s::read_from_pbmsg(const ::proto_ff::EquipBase & msg) {
	base_attr_percent = msg.base_attr_percent();
	star_attr_percent = msg.star_attr_percent();
	god_attr_percent = msg.god_attr_percent();
}

}
