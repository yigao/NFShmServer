#include "Com_s.h"

namespace proto_ff_s {

EmptyMessage_s::EmptyMessage_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int EmptyMessage_s::CreateInit() {
	return 0;
}

int EmptyMessage_s::ResumeInit() {
	return 0;
}

void EmptyMessage_s::write_to_pbmsg(::proto_ff::EmptyMessage & msg) const {
}

void EmptyMessage_s::read_from_pbmsg(const ::proto_ff::EmptyMessage & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct EmptyMessage_s));
}

ComPair_s::ComPair_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComPair_s::CreateInit() {
	key = (uint32_t)0;
	value = (uint32_t)0;
	return 0;
}

int ComPair_s::ResumeInit() {
	return 0;
}

void ComPair_s::write_to_pbmsg(::proto_ff::ComPair & msg) const {
	msg.set_key((uint32_t)key);
	msg.set_value((uint32_t)value);
}

void ComPair_s::read_from_pbmsg(const ::proto_ff::ComPair & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComPair_s));
	key = msg.key();
	value = msg.value();
}

ComPair64_s::ComPair64_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComPair64_s::CreateInit() {
	key = (uint64_t)0;
	value = (uint64_t)0;
	return 0;
}

int ComPair64_s::ResumeInit() {
	return 0;
}

void ComPair64_s::write_to_pbmsg(::proto_ff::ComPair64 & msg) const {
	msg.set_key((uint64_t)key);
	msg.set_value((uint64_t)value);
}

void ComPair64_s::read_from_pbmsg(const ::proto_ff::ComPair64 & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComPair64_s));
	key = msg.key();
	value = msg.value();
}

ComPairBool_s::ComPairBool_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComPairBool_s::CreateInit() {
	key = (uint32_t)0;
	value = (bool)0;
	return 0;
}

int ComPairBool_s::ResumeInit() {
	return 0;
}

void ComPairBool_s::write_to_pbmsg(::proto_ff::ComPairBool & msg) const {
	msg.set_key((uint32_t)key);
	msg.set_value((bool)value);
}

void ComPairBool_s::read_from_pbmsg(const ::proto_ff::ComPairBool & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComPairBool_s));
	key = msg.key();
	value = msg.value();
}

ComItem_s::ComItem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComItem_s::CreateInit() {
	item_id = (uint64_t)0;
	item_num = (uint64_t)0;
	return 0;
}

int ComItem_s::ResumeInit() {
	return 0;
}

void ComItem_s::write_to_pbmsg(::proto_ff::ComItem & msg) const {
	msg.set_item_id((uint64_t)item_id);
	msg.set_item_num((uint64_t)item_num);
}

void ComItem_s::read_from_pbmsg(const ::proto_ff::ComItem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComItem_s));
	item_id = msg.item_id();
	item_num = msg.item_num();
}

ComItemWithType_s::ComItemWithType_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComItemWithType_s::CreateInit() {
	item_id = (uint64_t)0;
	item_num = (uint64_t)0;
	type = (uint32_t)0;
	return 0;
}

int ComItemWithType_s::ResumeInit() {
	return 0;
}

void ComItemWithType_s::write_to_pbmsg(::proto_ff::ComItemWithType & msg) const {
	msg.set_item_id((uint64_t)item_id);
	msg.set_item_num((uint64_t)item_num);
	msg.set_type((uint32_t)type);
}

void ComItemWithType_s::read_from_pbmsg(const ::proto_ff::ComItemWithType & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComItemWithType_s));
	item_id = msg.item_id();
	item_num = msg.item_num();
	type = msg.type();
}

Vector3PB_s::Vector3PB_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Vector3PB_s::CreateInit() {
	x = (float)0;
	y = (float)0;
	z = (float)0;
	return 0;
}

int Vector3PB_s::ResumeInit() {
	return 0;
}

void Vector3PB_s::write_to_pbmsg(::proto_ff::Vector3PB & msg) const {
	msg.set_x((float)x);
	msg.set_y((float)y);
	msg.set_z((float)z);
}

void Vector3PB_s::read_from_pbmsg(const ::proto_ff::Vector3PB & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Vector3PB_s));
	x = msg.x();
	y = msg.y();
	z = msg.z();
}

Vector2PB_s::Vector2PB_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Vector2PB_s::CreateInit() {
	x = (float)0;
	y = (float)0;
	return 0;
}

int Vector2PB_s::ResumeInit() {
	return 0;
}

void Vector2PB_s::write_to_pbmsg(::proto_ff::Vector2PB & msg) const {
	msg.set_x((float)x);
	msg.set_y((float)y);
}

void Vector2PB_s::read_from_pbmsg(const ::proto_ff::Vector2PB & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Vector2PB_s));
	x = msg.x();
	y = msg.y();
}

Attr64_s::Attr64_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Attr64_s::CreateInit() {
	id = (uint32_t)0;
	value = (int64_t)0;
	return 0;
}

int Attr64_s::ResumeInit() {
	return 0;
}

void Attr64_s::write_to_pbmsg(::proto_ff::Attr64 & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_value((int64_t)value);
}

void Attr64_s::read_from_pbmsg(const ::proto_ff::Attr64 & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Attr64_s));
	id = msg.id();
	value = msg.value();
}

}