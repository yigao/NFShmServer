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
	valueMax = (int32_t)0;
	return 0;
}

int equipequipattributeDesc_s::ResumeInit() {
	return 0;
}

void equipequipattributeDesc_s::write_to_pbmsg(::proto_ff::equipequipattributeDesc & msg) const {
	msg.set_valuemin((int32_t)valueMin);
	msg.set_valuemax((int32_t)valueMax);
}

void equipequipattributeDesc_s::read_from_pbmsg(const ::proto_ff::equipequipattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipequipattributeDesc_s));
	valueMin = msg.valuemin();
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
	for(int32_t i = 0; i < (int32_t)attribute_type.GetSize() && i < attribute_type.GetMaxSize(); ++i) {
		msg.add_attribute_type((int32_t)attribute_type[i]);
	}
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
	attribute_type.SetSize(msg.attribute_type_size() > attribute_type.GetMaxSize() ? attribute_type.GetMaxSize() : msg.attribute_type_size());
	for(int32_t i = 0; i < (int32_t)attribute_type.GetSize(); ++i) {
		attribute_type[i] = msg.attribute_type(i);
	}
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

equipstrongtypeDesc_s::equipstrongtypeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipstrongtypeDesc_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int equipstrongtypeDesc_s::ResumeInit() {
	return 0;
}

void equipstrongtypeDesc_s::write_to_pbmsg(::proto_ff::equipstrongtypeDesc & msg) const {
	msg.set_num((const char*)num.Get());
	msg.set_id((int32_t)id);
}

void equipstrongtypeDesc_s::read_from_pbmsg(const ::proto_ff::equipstrongtypeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipstrongtypeDesc_s));
	num.Copy(msg.num());
	id = msg.id();
}

equipstrong_s::equipstrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipstrong_s::CreateInit() {
	id = (int64_t)0;
	position = (int32_t)0;
	wearQuality = (int32_t)0;
	srtongUp = (int32_t)0;
	return 0;
}

int equipstrong_s::ResumeInit() {
	return 0;
}

void equipstrong_s::write_to_pbmsg(::proto_ff::equipstrong & msg) const {
	msg.set_id((int64_t)id);
	msg.set_position((int32_t)position);
	msg.set_wearquality((int32_t)wearQuality);
	msg.set_srtongup((int32_t)srtongUp);
	for(int32_t i = 0; i < (int32_t)type.GetSize() && i < type.GetMaxSize(); ++i) {
		::proto_ff::equipstrongtypeDesc* temp_type = msg.add_type();
		type[i].write_to_pbmsg(*temp_type);
	}
}

void equipstrong_s::read_from_pbmsg(const ::proto_ff::equipstrong & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipstrong_s));
	id = msg.id();
	position = msg.position();
	wearQuality = msg.wearquality();
	srtongUp = msg.srtongup();
	type.SetSize(msg.type_size() > type.GetMaxSize() ? type.GetMaxSize() : msg.type_size());
	for(int32_t i = 0; i < (int32_t)type.GetSize(); ++i) {
		const ::proto_ff::equipstrongtypeDesc & temp_type = msg.type(i);
		type[i].read_from_pbmsg(temp_type);
	}
}

Sheet_equipstrong_s::Sheet_equipstrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipstrong_s::CreateInit() {
	return 0;
}

int Sheet_equipstrong_s::ResumeInit() {
	return 0;
}

void Sheet_equipstrong_s::write_to_pbmsg(::proto_ff::Sheet_equipstrong & msg) const {
	for(int32_t i = 0; i < (int32_t)equipstrong_List.GetSize() && i < equipstrong_List.GetMaxSize(); ++i) {
		::proto_ff::equipstrong* temp_equipstrong_list = msg.add_equipstrong_list();
		equipstrong_List[i].write_to_pbmsg(*temp_equipstrong_list);
	}
}

void Sheet_equipstrong_s::read_from_pbmsg(const ::proto_ff::Sheet_equipstrong & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipstrong_s));
	equipstrong_List.SetSize(msg.equipstrong_list_size() > equipstrong_List.GetMaxSize() ? equipstrong_List.GetMaxSize() : msg.equipstrong_list_size());
	for(int32_t i = 0; i < (int32_t)equipstrong_List.GetSize(); ++i) {
		const ::proto_ff::equipstrong & temp_equipstrong_list = msg.equipstrong_list(i);
		equipstrong_List[i].read_from_pbmsg(temp_equipstrong_list);
	}
}

equipgemfinedateDesc_s::equipgemfinedateDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipgemfinedateDesc_s::CreateInit() {
	Num = (int32_t)0;
	Id = (int64_t)0;
	return 0;
}

int equipgemfinedateDesc_s::ResumeInit() {
	return 0;
}

void equipgemfinedateDesc_s::write_to_pbmsg(::proto_ff::equipgemfinedateDesc & msg) const {
	msg.set_num((int32_t)Num);
	msg.set_id((int64_t)Id);
}

void equipgemfinedateDesc_s::read_from_pbmsg(const ::proto_ff::equipgemfinedateDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipgemfinedateDesc_s));
	Num = msg.num();
	Id = msg.id();
}

equipgemfine_s::equipgemfine_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipgemfine_s::CreateInit() {
	id = (int64_t)0;
	position = (int32_t)0;
	wearQuality = (int32_t)0;
	gemUp = (int32_t)0;
	gemNumber = (int32_t)0;
	return 0;
}

int equipgemfine_s::ResumeInit() {
	return 0;
}

void equipgemfine_s::write_to_pbmsg(::proto_ff::equipgemfine & msg) const {
	msg.set_id((int64_t)id);
	msg.set_position((int32_t)position);
	msg.set_wearquality((int32_t)wearQuality);
	msg.set_gemup((int32_t)gemUp);
	msg.set_gemnumber((int32_t)gemNumber);
	for(int32_t i = 0; i < (int32_t)date.GetSize() && i < date.GetMaxSize(); ++i) {
		::proto_ff::equipgemfinedateDesc* temp_date = msg.add_date();
		date[i].write_to_pbmsg(*temp_date);
	}
}

void equipgemfine_s::read_from_pbmsg(const ::proto_ff::equipgemfine & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipgemfine_s));
	id = msg.id();
	position = msg.position();
	wearQuality = msg.wearquality();
	gemUp = msg.gemup();
	gemNumber = msg.gemnumber();
	date.SetSize(msg.date_size() > date.GetMaxSize() ? date.GetMaxSize() : msg.date_size());
	for(int32_t i = 0; i < (int32_t)date.GetSize(); ++i) {
		const ::proto_ff::equipgemfinedateDesc & temp_date = msg.date(i);
		date[i].read_from_pbmsg(temp_date);
	}
}

Sheet_equipgemfine_s::Sheet_equipgemfine_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipgemfine_s::CreateInit() {
	return 0;
}

int Sheet_equipgemfine_s::ResumeInit() {
	return 0;
}

void Sheet_equipgemfine_s::write_to_pbmsg(::proto_ff::Sheet_equipgemfine & msg) const {
	for(int32_t i = 0; i < (int32_t)equipgemfine_List.GetSize() && i < equipgemfine_List.GetMaxSize(); ++i) {
		::proto_ff::equipgemfine* temp_equipgemfine_list = msg.add_equipgemfine_list();
		equipgemfine_List[i].write_to_pbmsg(*temp_equipgemfine_list);
	}
}

void Sheet_equipgemfine_s::read_from_pbmsg(const ::proto_ff::Sheet_equipgemfine & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipgemfine_s));
	equipgemfine_List.SetSize(msg.equipgemfine_list_size() > equipgemfine_List.GetMaxSize() ? equipgemfine_List.GetMaxSize() : msg.equipgemfine_list_size());
	for(int32_t i = 0; i < (int32_t)equipgemfine_List.GetSize(); ++i) {
		const ::proto_ff::equipgemfine & temp_equipgemfine_list = msg.equipgemfine_list(i);
		equipgemfine_List[i].read_from_pbmsg(temp_equipgemfine_list);
	}
}

equipgem_s::equipgem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipgem_s::CreateInit() {
	position = (int32_t)0;
	gemType = (int32_t)0;
	VipUnlock = (int32_t)0;
	return 0;
}

int equipgem_s::ResumeInit() {
	return 0;
}

void equipgem_s::write_to_pbmsg(::proto_ff::equipgem & msg) const {
	msg.set_position((int32_t)position);
	msg.set_gemtype((int32_t)gemType);
	msg.set_vipunlock((int32_t)VipUnlock);
	for(int32_t i = 0; i < (int32_t)gemUnlock.GetSize() && i < gemUnlock.GetMaxSize(); ++i) {
		msg.add_gemunlock((int32_t)gemUnlock[i]);
	}
}

void equipgem_s::read_from_pbmsg(const ::proto_ff::equipgem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipgem_s));
	position = msg.position();
	gemType = msg.gemtype();
	VipUnlock = msg.vipunlock();
	gemUnlock.SetSize(msg.gemunlock_size() > gemUnlock.GetMaxSize() ? gemUnlock.GetMaxSize() : msg.gemunlock_size());
	for(int32_t i = 0; i < (int32_t)gemUnlock.GetSize(); ++i) {
		gemUnlock[i] = msg.gemunlock(i);
	}
}

Sheet_equipgem_s::Sheet_equipgem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipgem_s::CreateInit() {
	return 0;
}

int Sheet_equipgem_s::ResumeInit() {
	return 0;
}

void Sheet_equipgem_s::write_to_pbmsg(::proto_ff::Sheet_equipgem & msg) const {
	for(int32_t i = 0; i < (int32_t)equipgem_List.GetSize() && i < equipgem_List.GetMaxSize(); ++i) {
		::proto_ff::equipgem* temp_equipgem_list = msg.add_equipgem_list();
		equipgem_List[i].write_to_pbmsg(*temp_equipgem_list);
	}
}

void Sheet_equipgem_s::read_from_pbmsg(const ::proto_ff::Sheet_equipgem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipgem_s));
	equipgem_List.SetSize(msg.equipgem_list_size() > equipgem_List.GetMaxSize() ? equipgem_List.GetMaxSize() : msg.equipgem_list_size());
	for(int32_t i = 0; i < (int32_t)equipgem_List.GetSize(); ++i) {
		const ::proto_ff::equipgem & temp_equipgem_list = msg.equipgem_list(i);
		equipgem_List[i].read_from_pbmsg(temp_equipgem_list);
	}
}

equipatt_s::equipatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipatt_s::CreateInit() {
	id = (int64_t)0;
	idType = (int32_t)0;
	idNum = (int32_t)0;
	return 0;
}

int equipatt_s::ResumeInit() {
	return 0;
}

void equipatt_s::write_to_pbmsg(::proto_ff::equipatt & msg) const {
	msg.set_id((int64_t)id);
	msg.set_idtype((int32_t)idType);
	msg.set_idnum((int32_t)idNum);
	msg.set_att((const char*)att.Get());
}

void equipatt_s::read_from_pbmsg(const ::proto_ff::equipatt & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipatt_s));
	id = msg.id();
	idType = msg.idtype();
	idNum = msg.idnum();
	att.Copy(msg.att());
}

Sheet_equipatt_s::Sheet_equipatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipatt_s::CreateInit() {
	return 0;
}

int Sheet_equipatt_s::ResumeInit() {
	return 0;
}

void Sheet_equipatt_s::write_to_pbmsg(::proto_ff::Sheet_equipatt & msg) const {
	for(int32_t i = 0; i < (int32_t)equipatt_List.GetSize() && i < equipatt_List.GetMaxSize(); ++i) {
		::proto_ff::equipatt* temp_equipatt_list = msg.add_equipatt_list();
		equipatt_List[i].write_to_pbmsg(*temp_equipatt_list);
	}
}

void Sheet_equipatt_s::read_from_pbmsg(const ::proto_ff::Sheet_equipatt & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipatt_s));
	equipatt_List.SetSize(msg.equipatt_list_size() > equipatt_List.GetMaxSize() ? equipatt_List.GetMaxSize() : msg.equipatt_list_size());
	for(int32_t i = 0; i < (int32_t)equipatt_List.GetSize(); ++i) {
		const ::proto_ff::equipatt & temp_equipatt_list = msg.equipatt_list(i);
		equipatt_List[i].read_from_pbmsg(temp_equipatt_list);
	}
}

equipsuitattributeDesc_s::equipsuitattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipsuitattributeDesc_s::CreateInit() {
	sctivation = (int32_t)0;
	return 0;
}

int equipsuitattributeDesc_s::ResumeInit() {
	return 0;
}

void equipsuitattributeDesc_s::write_to_pbmsg(::proto_ff::equipsuitattributeDesc & msg) const {
	msg.set_sctivation((int32_t)sctivation);
}

void equipsuitattributeDesc_s::read_from_pbmsg(const ::proto_ff::equipsuitattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipsuitattributeDesc_s));
	sctivation = msg.sctivation();
}

equipsuit_s::equipsuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipsuit_s::CreateInit() {
	id = (int64_t)0;
	suitLv = (int32_t)0;
	level = (int32_t)0;
	colour = (int32_t)0;
	suiteValue = (int32_t)0;
	return 0;
}

int equipsuit_s::ResumeInit() {
	return 0;
}

void equipsuit_s::write_to_pbmsg(::proto_ff::equipsuit & msg) const {
	msg.set_id((int64_t)id);
	msg.set_profession((const char*)profession.Get());
	msg.set_suitlv((int32_t)suitLv);
	msg.set_level((int32_t)level);
	msg.set_colour((int32_t)colour);
	msg.set_aftername((const char*)afterName.Get());
	msg.set_suitevalue((int32_t)suiteValue);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::equipsuitattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
	for(int32_t i = 0; i < (int32_t)position.GetSize() && i < position.GetMaxSize(); ++i) {
		msg.add_position((const char*)position[i].Get());
	}
}

void equipsuit_s::read_from_pbmsg(const ::proto_ff::equipsuit & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipsuit_s));
	id = msg.id();
	profession.Copy(msg.profession());
	suitLv = msg.suitlv();
	level = msg.level();
	colour = msg.colour();
	afterName.Copy(msg.aftername());
	suiteValue = msg.suitevalue();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::equipsuitattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
	position.SetSize(msg.position_size() > position.GetMaxSize() ? position.GetMaxSize() : msg.position_size());
	for(int32_t i = 0; i < (int32_t)position.GetSize(); ++i) {
		position[i].Copy(msg.position(i));
	}
}

Sheet_equipsuit_s::Sheet_equipsuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipsuit_s::CreateInit() {
	return 0;
}

int Sheet_equipsuit_s::ResumeInit() {
	return 0;
}

void Sheet_equipsuit_s::write_to_pbmsg(::proto_ff::Sheet_equipsuit & msg) const {
	for(int32_t i = 0; i < (int32_t)equipsuit_List.GetSize() && i < equipsuit_List.GetMaxSize(); ++i) {
		::proto_ff::equipsuit* temp_equipsuit_list = msg.add_equipsuit_list();
		equipsuit_List[i].write_to_pbmsg(*temp_equipsuit_list);
	}
}

void Sheet_equipsuit_s::read_from_pbmsg(const ::proto_ff::Sheet_equipsuit & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipsuit_s));
	equipsuit_List.SetSize(msg.equipsuit_list_size() > equipsuit_List.GetMaxSize() ? equipsuit_List.GetMaxSize() : msg.equipsuit_list_size());
	for(int32_t i = 0; i < (int32_t)equipsuit_List.GetSize(); ++i) {
		const ::proto_ff::equipsuit & temp_equipsuit_list = msg.equipsuit_list(i);
		equipsuit_List[i].read_from_pbmsg(temp_equipsuit_list);
	}
}

equipclear_s::equipclear_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipclear_s::CreateInit() {
	id = (int64_t)0;
	position = (int32_t)0;
	Lv = (int32_t)0;
	return 0;
}

int equipclear_s::ResumeInit() {
	return 0;
}

void equipclear_s::write_to_pbmsg(::proto_ff::equipclear & msg) const {
	msg.set_id((int64_t)id);
	msg.set_position((int32_t)position);
	msg.set_lv((int32_t)Lv);
	msg.set_value((const char*)value.Get());
	for(int32_t i = 0; i < (int32_t)teamId.GetSize() && i < teamId.GetMaxSize(); ++i) {
		msg.add_teamid((int64_t)teamId[i]);
	}
}

void equipclear_s::read_from_pbmsg(const ::proto_ff::equipclear & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipclear_s));
	id = msg.id();
	position = msg.position();
	Lv = msg.lv();
	value.Copy(msg.value());
	teamId.SetSize(msg.teamid_size() > teamId.GetMaxSize() ? teamId.GetMaxSize() : msg.teamid_size());
	for(int32_t i = 0; i < (int32_t)teamId.GetSize(); ++i) {
		teamId[i] = msg.teamid(i);
	}
}

Sheet_equipclear_s::Sheet_equipclear_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipclear_s::CreateInit() {
	return 0;
}

int Sheet_equipclear_s::ResumeInit() {
	return 0;
}

void Sheet_equipclear_s::write_to_pbmsg(::proto_ff::Sheet_equipclear & msg) const {
	for(int32_t i = 0; i < (int32_t)equipclear_List.GetSize() && i < equipclear_List.GetMaxSize(); ++i) {
		::proto_ff::equipclear* temp_equipclear_list = msg.add_equipclear_list();
		equipclear_List[i].write_to_pbmsg(*temp_equipclear_list);
	}
}

void Sheet_equipclear_s::read_from_pbmsg(const ::proto_ff::Sheet_equipclear & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipclear_s));
	equipclear_List.SetSize(msg.equipclear_list_size() > equipclear_List.GetMaxSize() ? equipclear_List.GetMaxSize() : msg.equipclear_list_size());
	for(int32_t i = 0; i < (int32_t)equipclear_List.GetSize(); ++i) {
		const ::proto_ff::equipclear & temp_equipclear_list = msg.equipclear_list(i);
		equipclear_List[i].read_from_pbmsg(temp_equipclear_list);
	}
}

equipstrongexp_s::equipstrongexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipstrongexp_s::CreateInit() {
	Lv = (int32_t)0;
	gold = (int32_t)0;
	exp = (int32_t)0;
	expUp = (int64_t)0;
	return 0;
}

int equipstrongexp_s::ResumeInit() {
	return 0;
}

void equipstrongexp_s::write_to_pbmsg(::proto_ff::equipstrongexp & msg) const {
	msg.set_lv((int32_t)Lv);
	msg.set_gold((int32_t)gold);
	msg.set_exp((int32_t)exp);
	msg.set_expup((int64_t)expUp);
}

void equipstrongexp_s::read_from_pbmsg(const ::proto_ff::equipstrongexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipstrongexp_s));
	Lv = msg.lv();
	gold = msg.gold();
	exp = msg.exp();
	expUp = msg.expup();
}

Sheet_equipstrongexp_s::Sheet_equipstrongexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipstrongexp_s::CreateInit() {
	return 0;
}

int Sheet_equipstrongexp_s::ResumeInit() {
	return 0;
}

void Sheet_equipstrongexp_s::write_to_pbmsg(::proto_ff::Sheet_equipstrongexp & msg) const {
	for(int32_t i = 0; i < (int32_t)equipstrongexp_List.GetSize() && i < equipstrongexp_List.GetMaxSize(); ++i) {
		::proto_ff::equipstrongexp* temp_equipstrongexp_list = msg.add_equipstrongexp_list();
		equipstrongexp_List[i].write_to_pbmsg(*temp_equipstrongexp_list);
	}
}

void Sheet_equipstrongexp_s::read_from_pbmsg(const ::proto_ff::Sheet_equipstrongexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipstrongexp_s));
	equipstrongexp_List.SetSize(msg.equipstrongexp_list_size() > equipstrongexp_List.GetMaxSize() ? equipstrongexp_List.GetMaxSize() : msg.equipstrongexp_list_size());
	for(int32_t i = 0; i < (int32_t)equipstrongexp_List.GetSize(); ++i) {
		const ::proto_ff::equipstrongexp & temp_equipstrongexp_list = msg.equipstrongexp_list(i);
		equipstrongexp_List[i].read_from_pbmsg(temp_equipstrongexp_list);
	}
}

equipgemfineexp_s::equipgemfineexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipgemfineexp_s::CreateInit() {
	Lv = (int32_t)0;
	expUp = (int64_t)0;
	return 0;
}

int equipgemfineexp_s::ResumeInit() {
	return 0;
}

void equipgemfineexp_s::write_to_pbmsg(::proto_ff::equipgemfineexp & msg) const {
	msg.set_lv((int32_t)Lv);
	msg.set_expup((int64_t)expUp);
}

void equipgemfineexp_s::read_from_pbmsg(const ::proto_ff::equipgemfineexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipgemfineexp_s));
	Lv = msg.lv();
	expUp = msg.expup();
}

Sheet_equipgemfineexp_s::Sheet_equipgemfineexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipgemfineexp_s::CreateInit() {
	return 0;
}

int Sheet_equipgemfineexp_s::ResumeInit() {
	return 0;
}

void Sheet_equipgemfineexp_s::write_to_pbmsg(::proto_ff::Sheet_equipgemfineexp & msg) const {
	for(int32_t i = 0; i < (int32_t)equipgemfineexp_List.GetSize() && i < equipgemfineexp_List.GetMaxSize(); ++i) {
		::proto_ff::equipgemfineexp* temp_equipgemfineexp_list = msg.add_equipgemfineexp_list();
		equipgemfineexp_List[i].write_to_pbmsg(*temp_equipgemfineexp_list);
	}
}

void Sheet_equipgemfineexp_s::read_from_pbmsg(const ::proto_ff::Sheet_equipgemfineexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipgemfineexp_s));
	equipgemfineexp_List.SetSize(msg.equipgemfineexp_list_size() > equipgemfineexp_List.GetMaxSize() ? equipgemfineexp_List.GetMaxSize() : msg.equipgemfineexp_list_size());
	for(int32_t i = 0; i < (int32_t)equipgemfineexp_List.GetSize(); ++i) {
		const ::proto_ff::equipgemfineexp & temp_equipgemfineexp_list = msg.equipgemfineexp_list(i);
		equipgemfineexp_List[i].read_from_pbmsg(temp_equipgemfineexp_list);
	}
}

equipclearteamSectionDesc_s::equipclearteamSectionDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipclearteamSectionDesc_s::CreateInit() {
	p = (int32_t)0;
	return 0;
}

int equipclearteamSectionDesc_s::ResumeInit() {
	return 0;
}

void equipclearteamSectionDesc_s::write_to_pbmsg(::proto_ff::equipclearteamSectionDesc & msg) const {
	msg.set_down((const char*)down.Get());
	msg.set_p((int32_t)p);
	msg.set_type((const char*)type.Get());
	msg.set_up((const char*)up.Get());
	msg.set_g((const char*)g.Get());
}

void equipclearteamSectionDesc_s::read_from_pbmsg(const ::proto_ff::equipclearteamSectionDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipclearteamSectionDesc_s));
	down.Copy(msg.down());
	p = msg.p();
	type.Copy(msg.type());
	up.Copy(msg.up());
	g.Copy(msg.g());
}

equipclearteam_s::equipclearteam_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipclearteam_s::CreateInit() {
	id = (int64_t)0;
	combat = (int64_t)0;
	shengId = (int64_t)0;
	shengNum = (int32_t)0;
	consumeId = (int64_t)0;
	return 0;
}

int equipclearteam_s::ResumeInit() {
	return 0;
}

void equipclearteam_s::write_to_pbmsg(::proto_ff::equipclearteam & msg) const {
	msg.set_id((int64_t)id);
	msg.set_combat((int64_t)combat);
	msg.set_shengid((int64_t)shengId);
	msg.set_shengnum((int32_t)shengNum);
	msg.set_consumeid((int64_t)consumeId);
	msg.set_consumenum((const char*)consumeNum.Get());
	msg.set_lockingid((const char*)lockingId.Get());
	msg.set_lockingnum((const char*)lockingNum.Get());
	for(int32_t i = 0; i < (int32_t)Section.GetSize() && i < Section.GetMaxSize(); ++i) {
		::proto_ff::equipclearteamSectionDesc* temp_section = msg.add_section();
		Section[i].write_to_pbmsg(*temp_section);
	}
}

void equipclearteam_s::read_from_pbmsg(const ::proto_ff::equipclearteam & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipclearteam_s));
	id = msg.id();
	combat = msg.combat();
	shengId = msg.shengid();
	shengNum = msg.shengnum();
	consumeId = msg.consumeid();
	consumeNum.Copy(msg.consumenum());
	lockingId.Copy(msg.lockingid());
	lockingNum.Copy(msg.lockingnum());
	Section.SetSize(msg.section_size() > Section.GetMaxSize() ? Section.GetMaxSize() : msg.section_size());
	for(int32_t i = 0; i < (int32_t)Section.GetSize(); ++i) {
		const ::proto_ff::equipclearteamSectionDesc & temp_section = msg.section(i);
		Section[i].read_from_pbmsg(temp_section);
	}
}

Sheet_equipclearteam_s::Sheet_equipclearteam_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipclearteam_s::CreateInit() {
	return 0;
}

int Sheet_equipclearteam_s::ResumeInit() {
	return 0;
}

void Sheet_equipclearteam_s::write_to_pbmsg(::proto_ff::Sheet_equipclearteam & msg) const {
	for(int32_t i = 0; i < (int32_t)equipclearteam_List.GetSize() && i < equipclearteam_List.GetMaxSize(); ++i) {
		::proto_ff::equipclearteam* temp_equipclearteam_list = msg.add_equipclearteam_list();
		equipclearteam_List[i].write_to_pbmsg(*temp_equipclearteam_list);
	}
}

void Sheet_equipclearteam_s::read_from_pbmsg(const ::proto_ff::Sheet_equipclearteam & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipclearteam_s));
	equipclearteam_List.SetSize(msg.equipclearteam_list_size() > equipclearteam_List.GetMaxSize() ? equipclearteam_List.GetMaxSize() : msg.equipclearteam_list_size());
	for(int32_t i = 0; i < (int32_t)equipclearteam_List.GetSize(); ++i) {
		const ::proto_ff::equipclearteam & temp_equipclearteam_list = msg.equipclearteam_list(i);
		equipclearteam_List[i].read_from_pbmsg(temp_equipclearteam_list);
	}
}

equipawakeningawakenDesc_s::equipawakeningawakenDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipawakeningawakenDesc_s::CreateInit() {
	Item = (int64_t)0;
	Num = (int32_t)0;
	return 0;
}

int equipawakeningawakenDesc_s::ResumeInit() {
	return 0;
}

void equipawakeningawakenDesc_s::write_to_pbmsg(::proto_ff::equipawakeningawakenDesc & msg) const {
	msg.set_item((int64_t)Item);
	msg.set_num((int32_t)Num);
}

void equipawakeningawakenDesc_s::read_from_pbmsg(const ::proto_ff::equipawakeningawakenDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipawakeningawakenDesc_s));
	Item = msg.item();
	Num = msg.num();
}

equipawakening_s::equipawakening_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipawakening_s::CreateInit() {
	id = (int64_t)0;
	position = (int32_t)0;
	awakenLv = (int32_t)0;
	needWearQuality = (int32_t)0;
	strong = (int32_t)0;
	attribute = (int32_t)0;
	return 0;
}

int equipawakening_s::ResumeInit() {
	return 0;
}

void equipawakening_s::write_to_pbmsg(::proto_ff::equipawakening & msg) const {
	msg.set_id((int64_t)id);
	msg.set_position((int32_t)position);
	msg.set_awakenlv((int32_t)awakenLv);
	msg.set_needwearquality((int32_t)needWearQuality);
	msg.set_strong((int32_t)strong);
	msg.set_attribute((int32_t)attribute);
	for(int32_t i = 0; i < (int32_t)awaken.GetSize() && i < awaken.GetMaxSize(); ++i) {
		::proto_ff::equipawakeningawakenDesc* temp_awaken = msg.add_awaken();
		awaken[i].write_to_pbmsg(*temp_awaken);
	}
}

void equipawakening_s::read_from_pbmsg(const ::proto_ff::equipawakening & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipawakening_s));
	id = msg.id();
	position = msg.position();
	awakenLv = msg.awakenlv();
	needWearQuality = msg.needwearquality();
	strong = msg.strong();
	attribute = msg.attribute();
	awaken.SetSize(msg.awaken_size() > awaken.GetMaxSize() ? awaken.GetMaxSize() : msg.awaken_size());
	for(int32_t i = 0; i < (int32_t)awaken.GetSize(); ++i) {
		const ::proto_ff::equipawakeningawakenDesc & temp_awaken = msg.awaken(i);
		awaken[i].read_from_pbmsg(temp_awaken);
	}
}

Sheet_equipawakening_s::Sheet_equipawakening_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipawakening_s::CreateInit() {
	return 0;
}

int Sheet_equipawakening_s::ResumeInit() {
	return 0;
}

void Sheet_equipawakening_s::write_to_pbmsg(::proto_ff::Sheet_equipawakening & msg) const {
	for(int32_t i = 0; i < (int32_t)equipawakening_List.GetSize() && i < equipawakening_List.GetMaxSize(); ++i) {
		::proto_ff::equipawakening* temp_equipawakening_list = msg.add_equipawakening_list();
		equipawakening_List[i].write_to_pbmsg(*temp_equipawakening_list);
	}
}

void Sheet_equipawakening_s::read_from_pbmsg(const ::proto_ff::Sheet_equipawakening & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipawakening_s));
	equipawakening_List.SetSize(msg.equipawakening_list_size() > equipawakening_List.GetMaxSize() ? equipawakening_List.GetMaxSize() : msg.equipawakening_list_size());
	for(int32_t i = 0; i < (int32_t)equipawakening_List.GetSize(); ++i) {
		const ::proto_ff::equipawakening & temp_equipawakening_list = msg.equipawakening_list(i);
		equipawakening_List[i].read_from_pbmsg(temp_equipawakening_list);
	}
}

equipenchantingtypeDesc_s::equipenchantingtypeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipenchantingtypeDesc_s::CreateInit() {
	num = (int32_t)0;
	id = (int32_t)0;
	return 0;
}

int equipenchantingtypeDesc_s::ResumeInit() {
	return 0;
}

void equipenchantingtypeDesc_s::write_to_pbmsg(::proto_ff::equipenchantingtypeDesc & msg) const {
	msg.set_num((int32_t)num);
	msg.set_id((int32_t)id);
}

void equipenchantingtypeDesc_s::read_from_pbmsg(const ::proto_ff::equipenchantingtypeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipenchantingtypeDesc_s));
	num = msg.num();
	id = msg.id();
}

equipenchantingenchantDesc_s::equipenchantingenchantDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipenchantingenchantDesc_s::CreateInit() {
	Item = (int64_t)0;
	Num = (int32_t)0;
	return 0;
}

int equipenchantingenchantDesc_s::ResumeInit() {
	return 0;
}

void equipenchantingenchantDesc_s::write_to_pbmsg(::proto_ff::equipenchantingenchantDesc & msg) const {
	msg.set_item((int64_t)Item);
	msg.set_num((int32_t)Num);
}

void equipenchantingenchantDesc_s::read_from_pbmsg(const ::proto_ff::equipenchantingenchantDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipenchantingenchantDesc_s));
	Item = msg.item();
	Num = msg.num();
}

equipenchanting_s::equipenchanting_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipenchanting_s::CreateInit() {
	id = (int64_t)0;
	position = (int32_t)0;
	enchantLv = (int32_t)0;
	needWearQuality = (int32_t)0;
	equip = (int32_t)0;
	return 0;
}

int equipenchanting_s::ResumeInit() {
	return 0;
}

void equipenchanting_s::write_to_pbmsg(::proto_ff::equipenchanting & msg) const {
	msg.set_id((int64_t)id);
	msg.set_position((int32_t)position);
	msg.set_enchantlv((int32_t)enchantLv);
	msg.set_needwearquality((int32_t)needWearQuality);
	msg.set_equip((int32_t)equip);
	for(int32_t i = 0; i < (int32_t)type.GetSize() && i < type.GetMaxSize(); ++i) {
		::proto_ff::equipenchantingtypeDesc* temp_type = msg.add_type();
		type[i].write_to_pbmsg(*temp_type);
	}
	for(int32_t i = 0; i < (int32_t)enchant.GetSize() && i < enchant.GetMaxSize(); ++i) {
		::proto_ff::equipenchantingenchantDesc* temp_enchant = msg.add_enchant();
		enchant[i].write_to_pbmsg(*temp_enchant);
	}
}

void equipenchanting_s::read_from_pbmsg(const ::proto_ff::equipenchanting & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipenchanting_s));
	id = msg.id();
	position = msg.position();
	enchantLv = msg.enchantlv();
	needWearQuality = msg.needwearquality();
	equip = msg.equip();
	type.SetSize(msg.type_size() > type.GetMaxSize() ? type.GetMaxSize() : msg.type_size());
	for(int32_t i = 0; i < (int32_t)type.GetSize(); ++i) {
		const ::proto_ff::equipenchantingtypeDesc & temp_type = msg.type(i);
		type[i].read_from_pbmsg(temp_type);
	}
	enchant.SetSize(msg.enchant_size() > enchant.GetMaxSize() ? enchant.GetMaxSize() : msg.enchant_size());
	for(int32_t i = 0; i < (int32_t)enchant.GetSize(); ++i) {
		const ::proto_ff::equipenchantingenchantDesc & temp_enchant = msg.enchant(i);
		enchant[i].read_from_pbmsg(temp_enchant);
	}
}

Sheet_equipenchanting_s::Sheet_equipenchanting_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipenchanting_s::CreateInit() {
	return 0;
}

int Sheet_equipenchanting_s::ResumeInit() {
	return 0;
}

void Sheet_equipenchanting_s::write_to_pbmsg(::proto_ff::Sheet_equipenchanting & msg) const {
	for(int32_t i = 0; i < (int32_t)equipenchanting_List.GetSize() && i < equipenchanting_List.GetMaxSize(); ++i) {
		::proto_ff::equipenchanting* temp_equipenchanting_list = msg.add_equipenchanting_list();
		equipenchanting_List[i].write_to_pbmsg(*temp_equipenchanting_list);
	}
}

void Sheet_equipenchanting_s::read_from_pbmsg(const ::proto_ff::Sheet_equipenchanting & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipenchanting_s));
	equipenchanting_List.SetSize(msg.equipenchanting_list_size() > equipenchanting_List.GetMaxSize() ? equipenchanting_List.GetMaxSize() : msg.equipenchanting_list_size());
	for(int32_t i = 0; i < (int32_t)equipenchanting_List.GetSize(); ++i) {
		const ::proto_ff::equipenchanting & temp_equipenchanting_list = msg.equipenchanting_list(i);
		equipenchanting_List[i].read_from_pbmsg(temp_equipenchanting_list);
	}
}

equipmarryattributeDesc_s::equipmarryattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipmarryattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int equipmarryattributeDesc_s::ResumeInit() {
	return 0;
}

void equipmarryattributeDesc_s::write_to_pbmsg(::proto_ff::equipmarryattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void equipmarryattributeDesc_s::read_from_pbmsg(const ::proto_ff::equipmarryattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipmarryattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

equipmarry_s::equipmarry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipmarry_s::CreateInit() {
	id = (int32_t)0;
	lv = (int32_t)0;
	position = (int32_t)0;
	type = (int32_t)0;
	materialID = (int64_t)0;
	materialEXP = (int32_t)0;
	need = (int32_t)0;
	return 0;
}

int equipmarry_s::ResumeInit() {
	return 0;
}

void equipmarry_s::write_to_pbmsg(::proto_ff::equipmarry & msg) const {
	msg.set_id((int32_t)id);
	msg.set_lv((int32_t)lv);
	msg.set_position((int32_t)position);
	msg.set_type((int32_t)type);
	msg.set_materialid((int64_t)materialID);
	msg.set_materialexp((int32_t)materialEXP);
	msg.set_need((int32_t)need);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::equipmarryattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void equipmarry_s::read_from_pbmsg(const ::proto_ff::equipmarry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipmarry_s));
	id = msg.id();
	lv = msg.lv();
	position = msg.position();
	type = msg.type();
	materialID = msg.materialid();
	materialEXP = msg.materialexp();
	need = msg.need();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::equipmarryattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_equipmarry_s::Sheet_equipmarry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipmarry_s::CreateInit() {
	return 0;
}

int Sheet_equipmarry_s::ResumeInit() {
	return 0;
}

void Sheet_equipmarry_s::write_to_pbmsg(::proto_ff::Sheet_equipmarry & msg) const {
	for(int32_t i = 0; i < (int32_t)equipmarry_List.GetSize() && i < equipmarry_List.GetMaxSize(); ++i) {
		::proto_ff::equipmarry* temp_equipmarry_list = msg.add_equipmarry_list();
		equipmarry_List[i].write_to_pbmsg(*temp_equipmarry_list);
	}
}

void Sheet_equipmarry_s::read_from_pbmsg(const ::proto_ff::Sheet_equipmarry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipmarry_s));
	equipmarry_List.SetSize(msg.equipmarry_list_size() > equipmarry_List.GetMaxSize() ? equipmarry_List.GetMaxSize() : msg.equipmarry_list_size());
	for(int32_t i = 0; i < (int32_t)equipmarry_List.GetSize(); ++i) {
		const ::proto_ff::equipmarry & temp_equipmarry_list = msg.equipmarry_list(i);
		equipmarry_List[i].read_from_pbmsg(temp_equipmarry_list);
	}
}

}