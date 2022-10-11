#include "equip_s.h"

namespace proto_ff_s {

equipequipattributeDesc_s::equipequipattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipequipattributeDesc_s::CreateInit() {
	valueMin = (int32_t)0;
	type = (int32_t)0;
	valueMax = (int32_t)0;
	return 0;
}

int equipequipattributeDesc_s::ResumeInit() {
	return 0;
}

void equipequipattributeDesc_s::write_to_pbmsg(::proto_ff::equipequipattributeDesc & msg) const {
	msg.set_valuemin((int32_t)valueMin);
	msg.set_type((int32_t)type);
	msg.set_valuemax((int32_t)valueMax);
}

void equipequipattributeDesc_s::read_from_pbmsg(const ::proto_ff::equipequipattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipequipattributeDesc_s));
	valueMin = msg.valuemin();
	type = msg.type();
	valueMax = msg.valuemax();
}

equipequip_s::equipequip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipequip_s::CreateInit() {
	id = (int64_t)0;
	wearQuality = (int32_t)0;
	position = (int32_t)0;
	professionLv = (int32_t)0;
	level = (int32_t)0;
	quality = (int32_t)0;
	star = (int32_t)0;
	refineAttributeDown = (int32_t)0;
	refineAttributeUp = (int32_t)0;
	blueStarNum = (int32_t)0;
	isCanbind = (int32_t)0;
	isTradeBind = (int32_t)0;
	sellPrice = (int32_t)0;
	time = (int32_t)0;
	Combat = (int32_t)0;
	broadcast = (int32_t)0;
	return 0;
}

int equipequip_s::ResumeInit() {
	return 0;
}

void equipequip_s::write_to_pbmsg(::proto_ff::equipequip & msg) const {
	msg.set_id((int64_t)id);
	msg.set_name((const char*)name.Get());
	msg.set_wearquality((int32_t)wearQuality);
	msg.set_position((int32_t)position);
	msg.set_profession((const char*)profession.Get());
	msg.set_professionlv((int32_t)professionLv);
	msg.set_level((int32_t)level);
	msg.set_quality((int32_t)quality);
	msg.set_star((int32_t)star);
	msg.set_refineattributedown((int32_t)refineAttributeDown);
	msg.set_refineattributeup((int32_t)refineAttributeUp);
	msg.set_refineattribute_typelibrary((const char*)refineAttribute_typeLibrary.Get());
	msg.set_refineattribute_valuemin((const char*)refineAttribute_valueMin.Get());
	msg.set_refineattribute_valuemax((const char*)refineAttribute_valueMax.Get());
	msg.set_bluestarnum((int32_t)blueStarNum);
	msg.set_bluestar_type((const char*)blueStar_type.Get());
	msg.set_bluestar_lv((const char*)blueStar_lv.Get());
	msg.set_bluestar_number((const char*)blueStar_number.Get());
	msg.set_iscanbind((int32_t)isCanbind);
	msg.set_istradebind((int32_t)isTradeBind);
	msg.set_sellprice((int32_t)sellPrice);
	msg.set_icon((const char*)icon.Get());
	msg.set_time((int32_t)time);
	msg.set_combat((int32_t)Combat);
	msg.set_broadcast((int32_t)broadcast);
	msg.set_meltingresult((const char*)meltingResult.Get());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::equipequipattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void equipequip_s::read_from_pbmsg(const ::proto_ff::equipequip & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipequip_s));
	id = msg.id();
	name.Copy(msg.name());
	wearQuality = msg.wearquality();
	position = msg.position();
	profession.Copy(msg.profession());
	professionLv = msg.professionlv();
	level = msg.level();
	quality = msg.quality();
	star = msg.star();
	refineAttributeDown = msg.refineattributedown();
	refineAttributeUp = msg.refineattributeup();
	refineAttribute_typeLibrary.Copy(msg.refineattribute_typelibrary());
	refineAttribute_valueMin.Copy(msg.refineattribute_valuemin());
	refineAttribute_valueMax.Copy(msg.refineattribute_valuemax());
	blueStarNum = msg.bluestarnum();
	blueStar_type.Copy(msg.bluestar_type());
	blueStar_lv.Copy(msg.bluestar_lv());
	blueStar_number.Copy(msg.bluestar_number());
	isCanbind = msg.iscanbind();
	isTradeBind = msg.istradebind();
	sellPrice = msg.sellprice();
	icon.Copy(msg.icon());
	time = msg.time();
	Combat = msg.combat();
	broadcast = msg.broadcast();
	meltingResult.Copy(msg.meltingresult());
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::equipequipattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_equipequip_s::Sheet_equipequip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipequip_s::CreateInit() {
	return 0;
}

int Sheet_equipequip_s::ResumeInit() {
	return 0;
}

void Sheet_equipequip_s::write_to_pbmsg(::proto_ff::Sheet_equipequip & msg) const {
	for(int32_t i = 0; i < (int32_t)equipequip_List.GetSize() && i < equipequip_List.GetMaxSize(); ++i) {
		::proto_ff::equipequip* temp_equipequip_list = msg.add_equipequip_list();
		equipequip_List[i].write_to_pbmsg(*temp_equipequip_list);
	}
}

void Sheet_equipequip_s::read_from_pbmsg(const ::proto_ff::Sheet_equipequip & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipequip_s));
	equipequip_List.SetSize(msg.equipequip_list_size() > equipequip_List.GetMaxSize() ? equipequip_List.GetMaxSize() : msg.equipequip_list_size());
	for(int32_t i = 0; i < (int32_t)equipequip_List.GetSize(); ++i) {
		const ::proto_ff::equipequip & temp_equipequip_list = msg.equipequip_list(i);
		equipequip_List[i].read_from_pbmsg(temp_equipequip_list);
	}
}

}