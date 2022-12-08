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

equipequipgodAttributeDesc_s::equipequipgodAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipequipgodAttributeDesc_s::CreateInit() {
	valueMin = (int32_t)0;
	type = (int32_t)0;
	valueMax = (int32_t)0;
	return 0;
}

int equipequipgodAttributeDesc_s::ResumeInit() {
	return 0;
}

void equipequipgodAttributeDesc_s::write_to_pbmsg(::proto_ff::equipequipgodAttributeDesc & msg) const {
	msg.set_valuemin((int32_t)valueMin);
	msg.set_type((int32_t)type);
	msg.set_valuemax((int32_t)valueMax);
}

void equipequipgodAttributeDesc_s::read_from_pbmsg(const ::proto_ff::equipequipgodAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipequipgodAttributeDesc_s));
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
	broadcast = (int32_t)0;
	specialAttributeDown = (int32_t)0;
	specialAttributeUp = (int32_t)0;
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
	msg.set_broadcast((int32_t)broadcast);
	msg.set_meltingresult((const char*)meltingResult.Get());
	msg.set_specialattributedown((int32_t)specialAttributeDown);
	msg.set_specialattributeup((int32_t)specialAttributeUp);
	msg.set_specialattribute_typelibrary((const char*)specialAttribute_typeLibrary.Get());
	msg.set_specialattribute_valuemin((const char*)specialAttribute_valueMin.Get());
	msg.set_specialattribute_valuemax((const char*)specialAttribute_valueMax.Get());
	msg.set_skillid((const char*)skillId.Get());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::equipequipattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
	for(int32_t i = 0; i < (int32_t)godAttribute.GetSize() && i < godAttribute.GetMaxSize(); ++i) {
		::proto_ff::equipequipgodAttributeDesc* temp_godattribute = msg.add_godattribute();
		godAttribute[i].write_to_pbmsg(*temp_godattribute);
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
	broadcast = msg.broadcast();
	meltingResult.Copy(msg.meltingresult());
	specialAttributeDown = msg.specialattributedown();
	specialAttributeUp = msg.specialattributeup();
	specialAttribute_typeLibrary.Copy(msg.specialattribute_typelibrary());
	specialAttribute_valueMin.Copy(msg.specialattribute_valuemin());
	specialAttribute_valueMax.Copy(msg.specialattribute_valuemax());
	skillId.Copy(msg.skillid());
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::equipequipattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
	godAttribute.SetSize(msg.godattribute_size() > godAttribute.GetMaxSize() ? godAttribute.GetMaxSize() : msg.godattribute_size());
	for(int32_t i = 0; i < (int32_t)godAttribute.GetSize(); ++i) {
		const ::proto_ff::equipequipgodAttributeDesc & temp_godattribute = msg.godattribute(i);
		godAttribute[i].read_from_pbmsg(temp_godattribute);
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
	return 0;
}

int equipstrongexp_s::ResumeInit() {
	return 0;
}

void equipstrongexp_s::write_to_pbmsg(::proto_ff::equipstrongexp & msg) const {
	msg.set_lv((int32_t)Lv);
	msg.set_gold((int32_t)gold);
	for(int32_t i = 0; i < (int32_t)costItem.GetSize() && i < costItem.GetMaxSize(); ++i) {
		msg.add_costitem((int32_t)costItem[i]);
	}
	for(int32_t i = 0; i < (int32_t)positionType.GetSize() && i < positionType.GetMaxSize(); ++i) {
		msg.add_positiontype((const char*)positionType[i].Get());
	}
	for(int32_t i = 0; i < (int32_t)costNum.GetSize() && i < costNum.GetMaxSize(); ++i) {
		msg.add_costnum((int32_t)costNum[i]);
	}
}

void equipstrongexp_s::read_from_pbmsg(const ::proto_ff::equipstrongexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipstrongexp_s));
	Lv = msg.lv();
	gold = msg.gold();
	costItem.SetSize(msg.costitem_size() > costItem.GetMaxSize() ? costItem.GetMaxSize() : msg.costitem_size());
	for(int32_t i = 0; i < (int32_t)costItem.GetSize(); ++i) {
		costItem[i] = msg.costitem(i);
	}
	positionType.SetSize(msg.positiontype_size() > positionType.GetMaxSize() ? positionType.GetMaxSize() : msg.positiontype_size());
	for(int32_t i = 0; i < (int32_t)positionType.GetSize(); ++i) {
		positionType[i].Copy(msg.positiontype(i));
	}
	costNum.SetSize(msg.costnum_size() > costNum.GetMaxSize() ? costNum.GetMaxSize() : msg.costnum_size());
	for(int32_t i = 0; i < (int32_t)costNum.GetSize(); ++i) {
		costNum[i] = msg.costnum(i);
	}
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

equipstrongtotalattributeDesc_s::equipstrongtotalattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipstrongtotalattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int equipstrongtotalattributeDesc_s::ResumeInit() {
	return 0;
}

void equipstrongtotalattributeDesc_s::write_to_pbmsg(::proto_ff::equipstrongtotalattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void equipstrongtotalattributeDesc_s::read_from_pbmsg(const ::proto_ff::equipstrongtotalattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipstrongtotalattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

equipstrongtotal_s::equipstrongtotal_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipstrongtotal_s::CreateInit() {
	id = (int64_t)0;
	idType = (int32_t)0;
	idNum = (int32_t)0;
	return 0;
}

int equipstrongtotal_s::ResumeInit() {
	return 0;
}

void equipstrongtotal_s::write_to_pbmsg(::proto_ff::equipstrongtotal & msg) const {
	msg.set_id((int64_t)id);
	msg.set_idtype((int32_t)idType);
	msg.set_idnum((int32_t)idNum);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::equipstrongtotalattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void equipstrongtotal_s::read_from_pbmsg(const ::proto_ff::equipstrongtotal & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipstrongtotal_s));
	id = msg.id();
	idType = msg.idtype();
	idNum = msg.idnum();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::equipstrongtotalattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_equipstrongtotal_s::Sheet_equipstrongtotal_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipstrongtotal_s::CreateInit() {
	return 0;
}

int Sheet_equipstrongtotal_s::ResumeInit() {
	return 0;
}

void Sheet_equipstrongtotal_s::write_to_pbmsg(::proto_ff::Sheet_equipstrongtotal & msg) const {
	for(int32_t i = 0; i < (int32_t)equipstrongtotal_List.GetSize() && i < equipstrongtotal_List.GetMaxSize(); ++i) {
		::proto_ff::equipstrongtotal* temp_equipstrongtotal_list = msg.add_equipstrongtotal_list();
		equipstrongtotal_List[i].write_to_pbmsg(*temp_equipstrongtotal_list);
	}
}

void Sheet_equipstrongtotal_s::read_from_pbmsg(const ::proto_ff::Sheet_equipstrongtotal & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipstrongtotal_s));
	equipstrongtotal_List.SetSize(msg.equipstrongtotal_list_size() > equipstrongtotal_List.GetMaxSize() ? equipstrongtotal_List.GetMaxSize() : msg.equipstrongtotal_list_size());
	for(int32_t i = 0; i < (int32_t)equipstrongtotal_List.GetSize(); ++i) {
		const ::proto_ff::equipstrongtotal & temp_equipstrongtotal_list = msg.equipstrongtotal_list(i);
		equipstrongtotal_List[i].read_from_pbmsg(temp_equipstrongtotal_list);
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
	speciallyGemType = (int32_t)0;
	payUnlockItem = (int32_t)0;
	payUnlockNnm = (int32_t)0;
	return 0;
}

int equipgem_s::ResumeInit() {
	return 0;
}

void equipgem_s::write_to_pbmsg(::proto_ff::equipgem & msg) const {
	msg.set_position((int32_t)position);
	msg.set_gemtype((const char*)gemType.Get());
	msg.set_speciallygemtype((int32_t)speciallyGemType);
	msg.set_payunlockitem((int32_t)payUnlockItem);
	msg.set_payunlocknnm((int32_t)payUnlockNnm);
	for(int32_t i = 0; i < (int32_t)gemUnlock.GetSize() && i < gemUnlock.GetMaxSize(); ++i) {
		msg.add_gemunlock((int32_t)gemUnlock[i]);
	}
}

void equipgem_s::read_from_pbmsg(const ::proto_ff::equipgem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipgem_s));
	position = msg.position();
	gemType.Copy(msg.gemtype());
	speciallyGemType = msg.speciallygemtype();
	payUnlockItem = msg.payunlockitem();
	payUnlockNnm = msg.payunlocknnm();
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

equipstoveattattributeDesc_s::equipstoveattattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipstoveattattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int equipstoveattattributeDesc_s::ResumeInit() {
	return 0;
}

void equipstoveattattributeDesc_s::write_to_pbmsg(::proto_ff::equipstoveattattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void equipstoveattattributeDesc_s::read_from_pbmsg(const ::proto_ff::equipstoveattattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipstoveattattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

equipstoveatt_s::equipstoveatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipstoveatt_s::CreateInit() {
	lv = (int32_t)0;
	exp = (int64_t)0;
	return 0;
}

int equipstoveatt_s::ResumeInit() {
	return 0;
}

void equipstoveatt_s::write_to_pbmsg(::proto_ff::equipstoveatt & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_exp((int64_t)exp);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::equipstoveattattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void equipstoveatt_s::read_from_pbmsg(const ::proto_ff::equipstoveatt & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipstoveatt_s));
	lv = msg.lv();
	exp = msg.exp();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::equipstoveattattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_equipstoveatt_s::Sheet_equipstoveatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipstoveatt_s::CreateInit() {
	return 0;
}

int Sheet_equipstoveatt_s::ResumeInit() {
	return 0;
}

void Sheet_equipstoveatt_s::write_to_pbmsg(::proto_ff::Sheet_equipstoveatt & msg) const {
	for(int32_t i = 0; i < (int32_t)equipstoveatt_List.GetSize() && i < equipstoveatt_List.GetMaxSize(); ++i) {
		::proto_ff::equipstoveatt* temp_equipstoveatt_list = msg.add_equipstoveatt_list();
		equipstoveatt_List[i].write_to_pbmsg(*temp_equipstoveatt_list);
	}
}

void Sheet_equipstoveatt_s::read_from_pbmsg(const ::proto_ff::Sheet_equipstoveatt & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipstoveatt_s));
	equipstoveatt_List.SetSize(msg.equipstoveatt_list_size() > equipstoveatt_List.GetMaxSize() ? equipstoveatt_List.GetMaxSize() : msg.equipstoveatt_list_size());
	for(int32_t i = 0; i < (int32_t)equipstoveatt_List.GetSize(); ++i) {
		const ::proto_ff::equipstoveatt & temp_equipstoveatt_list = msg.equipstoveatt_list(i);
		equipstoveatt_List[i].read_from_pbmsg(temp_equipstoveatt_list);
	}
}

equipstoveexp_s::equipstoveexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipstoveexp_s::CreateInit() {
	ID = (int32_t)0;
	exp = (int32_t)0;
	wearQuality = (int32_t)0;
	quality = (int32_t)0;
	return 0;
}

int equipstoveexp_s::ResumeInit() {
	return 0;
}

void equipstoveexp_s::write_to_pbmsg(::proto_ff::equipstoveexp & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_exp((int32_t)exp);
	msg.set_wearquality((int32_t)wearQuality);
	msg.set_quality((int32_t)quality);
}

void equipstoveexp_s::read_from_pbmsg(const ::proto_ff::equipstoveexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipstoveexp_s));
	ID = msg.id();
	exp = msg.exp();
	wearQuality = msg.wearquality();
	quality = msg.quality();
}

Sheet_equipstoveexp_s::Sheet_equipstoveexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipstoveexp_s::CreateInit() {
	return 0;
}

int Sheet_equipstoveexp_s::ResumeInit() {
	return 0;
}

void Sheet_equipstoveexp_s::write_to_pbmsg(::proto_ff::Sheet_equipstoveexp & msg) const {
	for(int32_t i = 0; i < (int32_t)equipstoveexp_List.GetSize() && i < equipstoveexp_List.GetMaxSize(); ++i) {
		::proto_ff::equipstoveexp* temp_equipstoveexp_list = msg.add_equipstoveexp_list();
		equipstoveexp_List[i].write_to_pbmsg(*temp_equipstoveexp_list);
	}
}

void Sheet_equipstoveexp_s::read_from_pbmsg(const ::proto_ff::Sheet_equipstoveexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipstoveexp_s));
	equipstoveexp_List.SetSize(msg.equipstoveexp_list_size() > equipstoveexp_List.GetMaxSize() ? equipstoveexp_List.GetMaxSize() : msg.equipstoveexp_list_size());
	for(int32_t i = 0; i < (int32_t)equipstoveexp_List.GetSize(); ++i) {
		const ::proto_ff::equipstoveexp & temp_equipstoveexp_list = msg.equipstoveexp_list(i);
		equipstoveexp_List[i].read_from_pbmsg(temp_equipstoveexp_list);
	}
}

equipgrade_s::equipgrade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int equipgrade_s::CreateInit() {
	ID = (int32_t)0;
	return 0;
}

int equipgrade_s::ResumeInit() {
	return 0;
}

void equipgrade_s::write_to_pbmsg(::proto_ff::equipgrade & msg) const {
	msg.set_id((int32_t)ID);
}

void equipgrade_s::read_from_pbmsg(const ::proto_ff::equipgrade & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct equipgrade_s));
	ID = msg.id();
}

Sheet_equipgrade_s::Sheet_equipgrade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_equipgrade_s::CreateInit() {
	return 0;
}

int Sheet_equipgrade_s::ResumeInit() {
	return 0;
}

void Sheet_equipgrade_s::write_to_pbmsg(::proto_ff::Sheet_equipgrade & msg) const {
	for(int32_t i = 0; i < (int32_t)equipgrade_List.GetSize() && i < equipgrade_List.GetMaxSize(); ++i) {
		::proto_ff::equipgrade* temp_equipgrade_list = msg.add_equipgrade_list();
		equipgrade_List[i].write_to_pbmsg(*temp_equipgrade_list);
	}
}

void Sheet_equipgrade_s::read_from_pbmsg(const ::proto_ff::Sheet_equipgrade & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_equipgrade_s));
	equipgrade_List.SetSize(msg.equipgrade_list_size() > equipgrade_List.GetMaxSize() ? equipgrade_List.GetMaxSize() : msg.equipgrade_list_size());
	for(int32_t i = 0; i < (int32_t)equipgrade_List.GetSize(); ++i) {
		const ::proto_ff::equipgrade & temp_equipgrade_list = msg.equipgrade_list(i);
		equipgrade_List[i].read_from_pbmsg(temp_equipgrade_list);
	}
}

}