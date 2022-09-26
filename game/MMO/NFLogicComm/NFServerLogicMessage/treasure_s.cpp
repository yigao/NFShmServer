#include "treasure_s.h"

namespace proto_ff_s {

treasuretreasureattributeDesc_s::treasuretreasureattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int treasuretreasureattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int treasuretreasureattributeDesc_s::ResumeInit() {
	return 0;
}

void treasuretreasureattributeDesc_s::write_to_pbmsg(::proto_ff::treasuretreasureattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void treasuretreasureattributeDesc_s::read_from_pbmsg(const ::proto_ff::treasuretreasureattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct treasuretreasureattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

treasuretreasure_s::treasuretreasure_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int treasuretreasure_s::CreateInit() {
	id = (int64_t)0;
	realLevel = (int32_t)0;
	materialID = (int64_t)0;
	materialEXP = (int32_t)0;
	exp = (int32_t)0;
	BreakMaterialID = (int64_t)0;
	BreakMaterialCost = (int32_t)0;
	skill = (int64_t)0;
	skillID = (int64_t)0;
	return 0;
}

int treasuretreasure_s::ResumeInit() {
	return 0;
}

void treasuretreasure_s::write_to_pbmsg(::proto_ff::treasuretreasure & msg) const {
	msg.set_id((int64_t)id);
	msg.set_resource((const char*)resource.Get());
	msg.set_name((const char*)name.Get());
	msg.set_activedesc((const char*)activeDesc.Get());
	msg.set_reallevel((int32_t)realLevel);
	msg.set_materialid((int64_t)materialID);
	msg.set_materialexp((int32_t)materialEXP);
	msg.set_exp((int32_t)exp);
	msg.set_breakmaterialid((int64_t)BreakMaterialID);
	msg.set_breakmaterialcost((int32_t)BreakMaterialCost);
	msg.set_skill((int64_t)skill);
	msg.set_skillid((int64_t)skillID);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::treasuretreasureattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
		msg.add_fragmentid((int64_t)fragmentID[i]);
	}
}

void treasuretreasure_s::read_from_pbmsg(const ::proto_ff::treasuretreasure & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct treasuretreasure_s));
	id = msg.id();
	resource.Copy(msg.resource());
	name.Copy(msg.name());
	activeDesc.Copy(msg.activedesc());
	realLevel = msg.reallevel();
	materialID = msg.materialid();
	materialEXP = msg.materialexp();
	exp = msg.exp();
	BreakMaterialID = msg.breakmaterialid();
	BreakMaterialCost = msg.breakmaterialcost();
	skill = msg.skill();
	skillID = msg.skillid();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::treasuretreasureattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
		fragmentID[i] = msg.fragmentid(i);
	}
}

Sheet_treasuretreasure_s::Sheet_treasuretreasure_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_treasuretreasure_s::CreateInit() {
	return 0;
}

int Sheet_treasuretreasure_s::ResumeInit() {
	return 0;
}

void Sheet_treasuretreasure_s::write_to_pbmsg(::proto_ff::Sheet_treasuretreasure & msg) const {
	for(int32_t i = 0; i < (int32_t)treasuretreasure_List.GetSize() && i < treasuretreasure_List.GetMaxSize(); ++i) {
		::proto_ff::treasuretreasure* temp_treasuretreasure_list = msg.add_treasuretreasure_list();
		treasuretreasure_List[i].write_to_pbmsg(*temp_treasuretreasure_list);
	}
}

void Sheet_treasuretreasure_s::read_from_pbmsg(const ::proto_ff::Sheet_treasuretreasure & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_treasuretreasure_s));
	treasuretreasure_List.SetSize(msg.treasuretreasure_list_size() > treasuretreasure_List.GetMaxSize() ? treasuretreasure_List.GetMaxSize() : msg.treasuretreasure_list_size());
	for(int32_t i = 0; i < (int32_t)treasuretreasure_List.GetSize(); ++i) {
		const ::proto_ff::treasuretreasure & temp_treasuretreasure_list = msg.treasuretreasure_list(i);
		treasuretreasure_List[i].read_from_pbmsg(temp_treasuretreasure_list);
	}
}

treasurechangeattributeDesc_s::treasurechangeattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int treasurechangeattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int treasurechangeattributeDesc_s::ResumeInit() {
	return 0;
}

void treasurechangeattributeDesc_s::write_to_pbmsg(::proto_ff::treasurechangeattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void treasurechangeattributeDesc_s::read_from_pbmsg(const ::proto_ff::treasurechangeattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct treasurechangeattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

treasurechange_s::treasurechange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int treasurechange_s::CreateInit() {
	id = (int64_t)0;
	quality = (int32_t)0;
	starId = (int64_t)0;
	starUp = (int32_t)0;
	starBer = (int32_t)0;
	occupation = (int64_t)0;
	skill = (int64_t)0;
	upAttributeId = (int64_t)0;
	return 0;
}

int treasurechange_s::ResumeInit() {
	return 0;
}

void treasurechange_s::write_to_pbmsg(::proto_ff::treasurechange & msg) const {
	msg.set_id((int64_t)id);
	msg.set_resource((const char*)resource.Get());
	msg.set_name((const char*)name.Get());
	msg.set_activedesc((const char*)activeDesc.Get());
	msg.set_quality((int32_t)quality);
	msg.set_starid((int64_t)starId);
	msg.set_starnum((const char*)starNum.Get());
	msg.set_starup((int32_t)starUp);
	msg.set_starber((int32_t)starBer);
	msg.set_occupation((int64_t)occupation);
	msg.set_skill((int64_t)skill);
	msg.set_upattributeid((int64_t)upAttributeId);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::treasurechangeattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void treasurechange_s::read_from_pbmsg(const ::proto_ff::treasurechange & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct treasurechange_s));
	id = msg.id();
	resource.Copy(msg.resource());
	name.Copy(msg.name());
	activeDesc.Copy(msg.activedesc());
	quality = msg.quality();
	starId = msg.starid();
	starNum.Copy(msg.starnum());
	starUp = msg.starup();
	starBer = msg.starber();
	occupation = msg.occupation();
	skill = msg.skill();
	upAttributeId = msg.upattributeid();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::treasurechangeattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_treasurechange_s::Sheet_treasurechange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_treasurechange_s::CreateInit() {
	return 0;
}

int Sheet_treasurechange_s::ResumeInit() {
	return 0;
}

void Sheet_treasurechange_s::write_to_pbmsg(::proto_ff::Sheet_treasurechange & msg) const {
	for(int32_t i = 0; i < (int32_t)treasurechange_List.GetSize() && i < treasurechange_List.GetMaxSize(); ++i) {
		::proto_ff::treasurechange* temp_treasurechange_list = msg.add_treasurechange_list();
		treasurechange_List[i].write_to_pbmsg(*temp_treasurechange_list);
	}
}

void Sheet_treasurechange_s::read_from_pbmsg(const ::proto_ff::Sheet_treasurechange & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_treasurechange_s));
	treasurechange_List.SetSize(msg.treasurechange_list_size() > treasurechange_List.GetMaxSize() ? treasurechange_List.GetMaxSize() : msg.treasurechange_list_size());
	for(int32_t i = 0; i < (int32_t)treasurechange_List.GetSize(); ++i) {
		const ::proto_ff::treasurechange & temp_treasurechange_list = msg.treasurechange_list(i);
		treasurechange_List[i].read_from_pbmsg(temp_treasurechange_list);
	}
}

treasurestarUpupAttributeDesc_s::treasurestarUpupAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int treasurestarUpupAttributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int treasurestarUpupAttributeDesc_s::ResumeInit() {
	return 0;
}

void treasurestarUpupAttributeDesc_s::write_to_pbmsg(::proto_ff::treasurestarUpupAttributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void treasurestarUpupAttributeDesc_s::read_from_pbmsg(const ::proto_ff::treasurestarUpupAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct treasurestarUpupAttributeDesc_s));
	type = msg.type();
	value = msg.value();
}

treasurestarUp_s::treasurestarUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int treasurestarUp_s::CreateInit() {
	ID = (int32_t)0;
	upAttributeId = (int64_t)0;
	starID = (int32_t)0;
	return 0;
}

int treasurestarUp_s::ResumeInit() {
	return 0;
}

void treasurestarUp_s::write_to_pbmsg(::proto_ff::treasurestarUp & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_upattributeid((int64_t)upAttributeId);
	msg.set_starid((int32_t)starID);
	for(int32_t i = 0; i < (int32_t)upAttribute.GetSize() && i < upAttribute.GetMaxSize(); ++i) {
		::proto_ff::treasurestarUpupAttributeDesc* temp_upattribute = msg.add_upattribute();
		upAttribute[i].write_to_pbmsg(*temp_upattribute);
	}
}

void treasurestarUp_s::read_from_pbmsg(const ::proto_ff::treasurestarUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct treasurestarUp_s));
	ID = msg.id();
	upAttributeId = msg.upattributeid();
	starID = msg.starid();
	upAttribute.SetSize(msg.upattribute_size() > upAttribute.GetMaxSize() ? upAttribute.GetMaxSize() : msg.upattribute_size());
	for(int32_t i = 0; i < (int32_t)upAttribute.GetSize(); ++i) {
		const ::proto_ff::treasurestarUpupAttributeDesc & temp_upattribute = msg.upattribute(i);
		upAttribute[i].read_from_pbmsg(temp_upattribute);
	}
}

Sheet_treasurestarUp_s::Sheet_treasurestarUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_treasurestarUp_s::CreateInit() {
	return 0;
}

int Sheet_treasurestarUp_s::ResumeInit() {
	return 0;
}

void Sheet_treasurestarUp_s::write_to_pbmsg(::proto_ff::Sheet_treasurestarUp & msg) const {
	for(int32_t i = 0; i < (int32_t)treasurestarUp_List.GetSize() && i < treasurestarUp_List.GetMaxSize(); ++i) {
		::proto_ff::treasurestarUp* temp_treasurestarup_list = msg.add_treasurestarup_list();
		treasurestarUp_List[i].write_to_pbmsg(*temp_treasurestarup_list);
	}
}

void Sheet_treasurestarUp_s::read_from_pbmsg(const ::proto_ff::Sheet_treasurestarUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_treasurestarUp_s));
	treasurestarUp_List.SetSize(msg.treasurestarup_list_size() > treasurestarUp_List.GetMaxSize() ? treasurestarUp_List.GetMaxSize() : msg.treasurestarup_list_size());
	for(int32_t i = 0; i < (int32_t)treasurestarUp_List.GetSize(); ++i) {
		const ::proto_ff::treasurestarUp & temp_treasurestarup_list = msg.treasurestarup_list(i);
		treasurestarUp_List[i].read_from_pbmsg(temp_treasurestarup_list);
	}
}

treasurefragmentattributeDesc_s::treasurefragmentattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int treasurefragmentattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int treasurefragmentattributeDesc_s::ResumeInit() {
	return 0;
}

void treasurefragmentattributeDesc_s::write_to_pbmsg(::proto_ff::treasurefragmentattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void treasurefragmentattributeDesc_s::read_from_pbmsg(const ::proto_ff::treasurefragmentattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct treasurefragmentattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

treasurefragment_s::treasurefragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int treasurefragment_s::CreateInit() {
	fragmentID = (int64_t)0;
	item = (int64_t)0;
	itemNum = (int32_t)0;
	return 0;
}

int treasurefragment_s::ResumeInit() {
	return 0;
}

void treasurefragment_s::write_to_pbmsg(::proto_ff::treasurefragment & msg) const {
	msg.set_fragmentid((int64_t)fragmentID);
	msg.set_item((int64_t)item);
	msg.set_itemnum((int32_t)itemNum);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::treasurefragmentattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void treasurefragment_s::read_from_pbmsg(const ::proto_ff::treasurefragment & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct treasurefragment_s));
	fragmentID = msg.fragmentid();
	item = msg.item();
	itemNum = msg.itemnum();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::treasurefragmentattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_treasurefragment_s::Sheet_treasurefragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_treasurefragment_s::CreateInit() {
	return 0;
}

int Sheet_treasurefragment_s::ResumeInit() {
	return 0;
}

void Sheet_treasurefragment_s::write_to_pbmsg(::proto_ff::Sheet_treasurefragment & msg) const {
	for(int32_t i = 0; i < (int32_t)treasurefragment_List.GetSize() && i < treasurefragment_List.GetMaxSize(); ++i) {
		::proto_ff::treasurefragment* temp_treasurefragment_list = msg.add_treasurefragment_list();
		treasurefragment_List[i].write_to_pbmsg(*temp_treasurefragment_list);
	}
}

void Sheet_treasurefragment_s::read_from_pbmsg(const ::proto_ff::Sheet_treasurefragment & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_treasurefragment_s));
	treasurefragment_List.SetSize(msg.treasurefragment_list_size() > treasurefragment_List.GetMaxSize() ? treasurefragment_List.GetMaxSize() : msg.treasurefragment_list_size());
	for(int32_t i = 0; i < (int32_t)treasurefragment_List.GetSize(); ++i) {
		const ::proto_ff::treasurefragment & temp_treasurefragment_list = msg.treasurefragment_list(i);
		treasurefragment_List[i].read_from_pbmsg(temp_treasurefragment_list);
	}
}

treasureequipattributeDesc_s::treasureequipattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int treasureequipattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int treasureequipattributeDesc_s::ResumeInit() {
	return 0;
}

void treasureequipattributeDesc_s::write_to_pbmsg(::proto_ff::treasureequipattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void treasureequipattributeDesc_s::read_from_pbmsg(const ::proto_ff::treasureequipattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct treasureequipattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

treasureequip_s::treasureequip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int treasureequip_s::CreateInit() {
	id = (int64_t)0;
	position = (int32_t)0;
	return 0;
}

int treasureequip_s::ResumeInit() {
	return 0;
}

void treasureequip_s::write_to_pbmsg(::proto_ff::treasureequip & msg) const {
	msg.set_id((int64_t)id);
	msg.set_position((int32_t)position);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::treasureequipattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void treasureequip_s::read_from_pbmsg(const ::proto_ff::treasureequip & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct treasureequip_s));
	id = msg.id();
	position = msg.position();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::treasureequipattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_treasureequip_s::Sheet_treasureequip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_treasureequip_s::CreateInit() {
	return 0;
}

int Sheet_treasureequip_s::ResumeInit() {
	return 0;
}

void Sheet_treasureequip_s::write_to_pbmsg(::proto_ff::Sheet_treasureequip & msg) const {
	for(int32_t i = 0; i < (int32_t)treasureequip_List.GetSize() && i < treasureequip_List.GetMaxSize(); ++i) {
		::proto_ff::treasureequip* temp_treasureequip_list = msg.add_treasureequip_list();
		treasureequip_List[i].write_to_pbmsg(*temp_treasureequip_list);
	}
}

void Sheet_treasureequip_s::read_from_pbmsg(const ::proto_ff::Sheet_treasureequip & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_treasureequip_s));
	treasureequip_List.SetSize(msg.treasureequip_list_size() > treasureequip_List.GetMaxSize() ? treasureequip_List.GetMaxSize() : msg.treasureequip_list_size());
	for(int32_t i = 0; i < (int32_t)treasureequip_List.GetSize(); ++i) {
		const ::proto_ff::treasureequip & temp_treasureequip_list = msg.treasureequip_list(i);
		treasureequip_List[i].read_from_pbmsg(temp_treasureequip_list);
	}
}

treasureslot_s::treasureslot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int treasureslot_s::CreateInit() {
	position = (int32_t)0;
	refineLv = (int32_t)0;
	refineNum = (int32_t)0;
	return 0;
}

int treasureslot_s::ResumeInit() {
	return 0;
}

void treasureslot_s::write_to_pbmsg(::proto_ff::treasureslot & msg) const {
	msg.set_position((int32_t)position);
	msg.set_refinelv((int32_t)refineLv);
	msg.set_refinenum((int32_t)refineNum);
}

void treasureslot_s::read_from_pbmsg(const ::proto_ff::treasureslot & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct treasureslot_s));
	position = msg.position();
	refineLv = msg.refinelv();
	refineNum = msg.refinenum();
}

Sheet_treasureslot_s::Sheet_treasureslot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_treasureslot_s::CreateInit() {
	return 0;
}

int Sheet_treasureslot_s::ResumeInit() {
	return 0;
}

void Sheet_treasureslot_s::write_to_pbmsg(::proto_ff::Sheet_treasureslot & msg) const {
	for(int32_t i = 0; i < (int32_t)treasureslot_List.GetSize() && i < treasureslot_List.GetMaxSize(); ++i) {
		::proto_ff::treasureslot* temp_treasureslot_list = msg.add_treasureslot_list();
		treasureslot_List[i].write_to_pbmsg(*temp_treasureslot_list);
	}
}

void Sheet_treasureslot_s::read_from_pbmsg(const ::proto_ff::Sheet_treasureslot & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_treasureslot_s));
	treasureslot_List.SetSize(msg.treasureslot_list_size() > treasureslot_List.GetMaxSize() ? treasureslot_List.GetMaxSize() : msg.treasureslot_list_size());
	for(int32_t i = 0; i < (int32_t)treasureslot_List.GetSize(); ++i) {
		const ::proto_ff::treasureslot & temp_treasureslot_list = msg.treasureslot_list(i);
		treasureslot_List[i].read_from_pbmsg(temp_treasureslot_list);
	}
}

treasurerefine_s::treasurerefine_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int treasurerefine_s::CreateInit() {
	id = (int32_t)0;
	refineId = (int64_t)0;
	refineNum = (int32_t)0;
	return 0;
}

int treasurerefine_s::ResumeInit() {
	return 0;
}

void treasurerefine_s::write_to_pbmsg(::proto_ff::treasurerefine & msg) const {
	msg.set_id((int32_t)id);
	msg.set_refineid((int64_t)refineId);
	msg.set_refinenum((int32_t)refineNum);
}

void treasurerefine_s::read_from_pbmsg(const ::proto_ff::treasurerefine & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct treasurerefine_s));
	id = msg.id();
	refineId = msg.refineid();
	refineNum = msg.refinenum();
}

Sheet_treasurerefine_s::Sheet_treasurerefine_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_treasurerefine_s::CreateInit() {
	return 0;
}

int Sheet_treasurerefine_s::ResumeInit() {
	return 0;
}

void Sheet_treasurerefine_s::write_to_pbmsg(::proto_ff::Sheet_treasurerefine & msg) const {
	for(int32_t i = 0; i < (int32_t)treasurerefine_List.GetSize() && i < treasurerefine_List.GetMaxSize(); ++i) {
		::proto_ff::treasurerefine* temp_treasurerefine_list = msg.add_treasurerefine_list();
		treasurerefine_List[i].write_to_pbmsg(*temp_treasurerefine_list);
	}
}

void Sheet_treasurerefine_s::read_from_pbmsg(const ::proto_ff::Sheet_treasurerefine & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_treasurerefine_s));
	treasurerefine_List.SetSize(msg.treasurerefine_list_size() > treasurerefine_List.GetMaxSize() ? treasurerefine_List.GetMaxSize() : msg.treasurerefine_list_size());
	for(int32_t i = 0; i < (int32_t)treasurerefine_List.GetSize(); ++i) {
		const ::proto_ff::treasurerefine & temp_treasurerefine_list = msg.treasurerefine_list(i);
		treasurerefine_List[i].read_from_pbmsg(temp_treasurerefine_list);
	}
}

}