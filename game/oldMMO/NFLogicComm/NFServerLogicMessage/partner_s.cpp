#include "partner_s.h"

namespace proto_ff_s {

partnerpartnerattributeDesc_s::partnerpartnerattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int partnerpartnerattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int partnerpartnerattributeDesc_s::ResumeInit() {
	return 0;
}

void partnerpartnerattributeDesc_s::write_to_pbmsg(::proto_ff::partnerpartnerattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void partnerpartnerattributeDesc_s::read_from_pbmsg(const ::proto_ff::partnerpartnerattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct partnerpartnerattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

partnerpartner_s::partnerpartner_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int partnerpartner_s::CreateInit() {
	id = (int64_t)0;
	realLevel = (int32_t)0;
	materialID = (int64_t)0;
	materialEXP = (int32_t)0;
	exp = (int32_t)0;
	BreakMaterialID = (int64_t)0;
	BreakMaterialCost = (int32_t)0;
	skillID = (int64_t)0;
	aiId = (int64_t)0;
	return 0;
}

int partnerpartner_s::ResumeInit() {
	return 0;
}

void partnerpartner_s::write_to_pbmsg(::proto_ff::partnerpartner & msg) const {
	msg.set_id((int64_t)id);
	msg.set_resource((const char*)resource.Get());
	msg.set_name((const char*)name.Get());
	msg.set_activedesc((const char*)activeDesc.Get());
	msg.set_partnerskill((const char*)partnerSkill.Get());
	msg.set_reallevel((int32_t)realLevel);
	msg.set_materialid((int64_t)materialID);
	msg.set_materialexp((int32_t)materialEXP);
	msg.set_exp((int32_t)exp);
	msg.set_breakmaterialid((int64_t)BreakMaterialID);
	msg.set_breakmaterialcost((int32_t)BreakMaterialCost);
	msg.set_skillid((int64_t)skillID);
	msg.set_aiid((int64_t)aiId);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::partnerpartnerattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
	for(int32_t i = 0; i < (int32_t)fragmentID.GetSize() && i < fragmentID.GetMaxSize(); ++i) {
		msg.add_fragmentid((int64_t)fragmentID[i]);
	}
}

void partnerpartner_s::read_from_pbmsg(const ::proto_ff::partnerpartner & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct partnerpartner_s));
	id = msg.id();
	resource.Copy(msg.resource());
	name.Copy(msg.name());
	activeDesc.Copy(msg.activedesc());
	partnerSkill.Copy(msg.partnerskill());
	realLevel = msg.reallevel();
	materialID = msg.materialid();
	materialEXP = msg.materialexp();
	exp = msg.exp();
	BreakMaterialID = msg.breakmaterialid();
	BreakMaterialCost = msg.breakmaterialcost();
	skillID = msg.skillid();
	aiId = msg.aiid();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::partnerpartnerattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
	fragmentID.SetSize(msg.fragmentid_size() > fragmentID.GetMaxSize() ? fragmentID.GetMaxSize() : msg.fragmentid_size());
	for(int32_t i = 0; i < (int32_t)fragmentID.GetSize(); ++i) {
		fragmentID[i] = msg.fragmentid(i);
	}
}

Sheet_partnerpartner_s::Sheet_partnerpartner_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_partnerpartner_s::CreateInit() {
	return 0;
}

int Sheet_partnerpartner_s::ResumeInit() {
	return 0;
}

void Sheet_partnerpartner_s::write_to_pbmsg(::proto_ff::Sheet_partnerpartner & msg) const {
	for(int32_t i = 0; i < (int32_t)partnerpartner_List.GetSize() && i < partnerpartner_List.GetMaxSize(); ++i) {
		::proto_ff::partnerpartner* temp_partnerpartner_list = msg.add_partnerpartner_list();
		partnerpartner_List[i].write_to_pbmsg(*temp_partnerpartner_list);
	}
}

void Sheet_partnerpartner_s::read_from_pbmsg(const ::proto_ff::Sheet_partnerpartner & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_partnerpartner_s));
	partnerpartner_List.SetSize(msg.partnerpartner_list_size() > partnerpartner_List.GetMaxSize() ? partnerpartner_List.GetMaxSize() : msg.partnerpartner_list_size());
	for(int32_t i = 0; i < (int32_t)partnerpartner_List.GetSize(); ++i) {
		const ::proto_ff::partnerpartner & temp_partnerpartner_list = msg.partnerpartner_list(i);
		partnerpartner_List[i].read_from_pbmsg(temp_partnerpartner_list);
	}
}

partnerchangeattributeDesc_s::partnerchangeattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int partnerchangeattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int partnerchangeattributeDesc_s::ResumeInit() {
	return 0;
}

void partnerchangeattributeDesc_s::write_to_pbmsg(::proto_ff::partnerchangeattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void partnerchangeattributeDesc_s::read_from_pbmsg(const ::proto_ff::partnerchangeattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct partnerchangeattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

partnerchange_s::partnerchange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int partnerchange_s::CreateInit() {
	id = (int64_t)0;
	quality = (int32_t)0;
	starId = (int64_t)0;
	starUp = (int32_t)0;
	starBer = (int32_t)0;
	occupation = (int64_t)0;
	aiId = (int64_t)0;
	upAttributeId = (int64_t)0;
	return 0;
}

int partnerchange_s::ResumeInit() {
	return 0;
}

void partnerchange_s::write_to_pbmsg(::proto_ff::partnerchange & msg) const {
	msg.set_id((int64_t)id);
	msg.set_resource((const char*)resource.Get());
	msg.set_name((const char*)name.Get());
	msg.set_activedesc((const char*)activeDesc.Get());
	msg.set_quality((int32_t)quality);
	msg.set_starid((int64_t)starId);
	msg.set_starnum((const char*)starNum.Get());
	msg.set_starup((int32_t)starUp);
	msg.set_partnerskill((const char*)partnerSkill.Get());
	msg.set_starber((int32_t)starBer);
	msg.set_occupation((int64_t)occupation);
	msg.set_aiid((int64_t)aiId);
	msg.set_upattributeid((int64_t)upAttributeId);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::partnerchangeattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void partnerchange_s::read_from_pbmsg(const ::proto_ff::partnerchange & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct partnerchange_s));
	id = msg.id();
	resource.Copy(msg.resource());
	name.Copy(msg.name());
	activeDesc.Copy(msg.activedesc());
	quality = msg.quality();
	starId = msg.starid();
	starNum.Copy(msg.starnum());
	starUp = msg.starup();
	partnerSkill.Copy(msg.partnerskill());
	starBer = msg.starber();
	occupation = msg.occupation();
	aiId = msg.aiid();
	upAttributeId = msg.upattributeid();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::partnerchangeattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_partnerchange_s::Sheet_partnerchange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_partnerchange_s::CreateInit() {
	return 0;
}

int Sheet_partnerchange_s::ResumeInit() {
	return 0;
}

void Sheet_partnerchange_s::write_to_pbmsg(::proto_ff::Sheet_partnerchange & msg) const {
	for(int32_t i = 0; i < (int32_t)partnerchange_List.GetSize() && i < partnerchange_List.GetMaxSize(); ++i) {
		::proto_ff::partnerchange* temp_partnerchange_list = msg.add_partnerchange_list();
		partnerchange_List[i].write_to_pbmsg(*temp_partnerchange_list);
	}
}

void Sheet_partnerchange_s::read_from_pbmsg(const ::proto_ff::Sheet_partnerchange & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_partnerchange_s));
	partnerchange_List.SetSize(msg.partnerchange_list_size() > partnerchange_List.GetMaxSize() ? partnerchange_List.GetMaxSize() : msg.partnerchange_list_size());
	for(int32_t i = 0; i < (int32_t)partnerchange_List.GetSize(); ++i) {
		const ::proto_ff::partnerchange & temp_partnerchange_list = msg.partnerchange_list(i);
		partnerchange_List[i].read_from_pbmsg(temp_partnerchange_list);
	}
}

partnerstarUpupAttributeDesc_s::partnerstarUpupAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int partnerstarUpupAttributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int partnerstarUpupAttributeDesc_s::ResumeInit() {
	return 0;
}

void partnerstarUpupAttributeDesc_s::write_to_pbmsg(::proto_ff::partnerstarUpupAttributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void partnerstarUpupAttributeDesc_s::read_from_pbmsg(const ::proto_ff::partnerstarUpupAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct partnerstarUpupAttributeDesc_s));
	type = msg.type();
	value = msg.value();
}

partnerstarUp_s::partnerstarUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int partnerstarUp_s::CreateInit() {
	ID = (int32_t)0;
	upAttributeId = (int64_t)0;
	starID = (int32_t)0;
	return 0;
}

int partnerstarUp_s::ResumeInit() {
	return 0;
}

void partnerstarUp_s::write_to_pbmsg(::proto_ff::partnerstarUp & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_upattributeid((int64_t)upAttributeId);
	msg.set_starid((int32_t)starID);
	for(int32_t i = 0; i < (int32_t)upAttribute.GetSize() && i < upAttribute.GetMaxSize(); ++i) {
		::proto_ff::partnerstarUpupAttributeDesc* temp_upattribute = msg.add_upattribute();
		upAttribute[i].write_to_pbmsg(*temp_upattribute);
	}
}

void partnerstarUp_s::read_from_pbmsg(const ::proto_ff::partnerstarUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct partnerstarUp_s));
	ID = msg.id();
	upAttributeId = msg.upattributeid();
	starID = msg.starid();
	upAttribute.SetSize(msg.upattribute_size() > upAttribute.GetMaxSize() ? upAttribute.GetMaxSize() : msg.upattribute_size());
	for(int32_t i = 0; i < (int32_t)upAttribute.GetSize(); ++i) {
		const ::proto_ff::partnerstarUpupAttributeDesc & temp_upattribute = msg.upattribute(i);
		upAttribute[i].read_from_pbmsg(temp_upattribute);
	}
}

Sheet_partnerstarUp_s::Sheet_partnerstarUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_partnerstarUp_s::CreateInit() {
	return 0;
}

int Sheet_partnerstarUp_s::ResumeInit() {
	return 0;
}

void Sheet_partnerstarUp_s::write_to_pbmsg(::proto_ff::Sheet_partnerstarUp & msg) const {
	for(int32_t i = 0; i < (int32_t)partnerstarUp_List.GetSize() && i < partnerstarUp_List.GetMaxSize(); ++i) {
		::proto_ff::partnerstarUp* temp_partnerstarup_list = msg.add_partnerstarup_list();
		partnerstarUp_List[i].write_to_pbmsg(*temp_partnerstarup_list);
	}
}

void Sheet_partnerstarUp_s::read_from_pbmsg(const ::proto_ff::Sheet_partnerstarUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_partnerstarUp_s));
	partnerstarUp_List.SetSize(msg.partnerstarup_list_size() > partnerstarUp_List.GetMaxSize() ? partnerstarUp_List.GetMaxSize() : msg.partnerstarup_list_size());
	for(int32_t i = 0; i < (int32_t)partnerstarUp_List.GetSize(); ++i) {
		const ::proto_ff::partnerstarUp & temp_partnerstarup_list = msg.partnerstarup_list(i);
		partnerstarUp_List[i].read_from_pbmsg(temp_partnerstarup_list);
	}
}

partnerfragmentattributeDesc_s::partnerfragmentattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int partnerfragmentattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int partnerfragmentattributeDesc_s::ResumeInit() {
	return 0;
}

void partnerfragmentattributeDesc_s::write_to_pbmsg(::proto_ff::partnerfragmentattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void partnerfragmentattributeDesc_s::read_from_pbmsg(const ::proto_ff::partnerfragmentattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct partnerfragmentattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

partnerfragment_s::partnerfragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int partnerfragment_s::CreateInit() {
	fragmentID = (int64_t)0;
	item = (int64_t)0;
	itemNum = (int32_t)0;
	return 0;
}

int partnerfragment_s::ResumeInit() {
	return 0;
}

void partnerfragment_s::write_to_pbmsg(::proto_ff::partnerfragment & msg) const {
	msg.set_fragmentid((int64_t)fragmentID);
	msg.set_item((int64_t)item);
	msg.set_itemnum((int32_t)itemNum);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::partnerfragmentattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void partnerfragment_s::read_from_pbmsg(const ::proto_ff::partnerfragment & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct partnerfragment_s));
	fragmentID = msg.fragmentid();
	item = msg.item();
	itemNum = msg.itemnum();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::partnerfragmentattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_partnerfragment_s::Sheet_partnerfragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_partnerfragment_s::CreateInit() {
	return 0;
}

int Sheet_partnerfragment_s::ResumeInit() {
	return 0;
}

void Sheet_partnerfragment_s::write_to_pbmsg(::proto_ff::Sheet_partnerfragment & msg) const {
	for(int32_t i = 0; i < (int32_t)partnerfragment_List.GetSize() && i < partnerfragment_List.GetMaxSize(); ++i) {
		::proto_ff::partnerfragment* temp_partnerfragment_list = msg.add_partnerfragment_list();
		partnerfragment_List[i].write_to_pbmsg(*temp_partnerfragment_list);
	}
}

void Sheet_partnerfragment_s::read_from_pbmsg(const ::proto_ff::Sheet_partnerfragment & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_partnerfragment_s));
	partnerfragment_List.SetSize(msg.partnerfragment_list_size() > partnerfragment_List.GetMaxSize() ? partnerfragment_List.GetMaxSize() : msg.partnerfragment_list_size());
	for(int32_t i = 0; i < (int32_t)partnerfragment_List.GetSize(); ++i) {
		const ::proto_ff::partnerfragment & temp_partnerfragment_list = msg.partnerfragment_list(i);
		partnerfragment_List[i].read_from_pbmsg(temp_partnerfragment_list);
	}
}

partnerattributeattributeDesc_s::partnerattributeattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int partnerattributeattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int partnerattributeattributeDesc_s::ResumeInit() {
	return 0;
}

void partnerattributeattributeDesc_s::write_to_pbmsg(::proto_ff::partnerattributeattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void partnerattributeattributeDesc_s::read_from_pbmsg(const ::proto_ff::partnerattributeattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct partnerattributeattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

partnerattribute_s::partnerattribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int partnerattribute_s::CreateInit() {
	lv = (int32_t)0;
	exp = (int64_t)0;
	return 0;
}

int partnerattribute_s::ResumeInit() {
	return 0;
}

void partnerattribute_s::write_to_pbmsg(::proto_ff::partnerattribute & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_exp((int64_t)exp);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::partnerattributeattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void partnerattribute_s::read_from_pbmsg(const ::proto_ff::partnerattribute & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct partnerattribute_s));
	lv = msg.lv();
	exp = msg.exp();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::partnerattributeattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_partnerattribute_s::Sheet_partnerattribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_partnerattribute_s::CreateInit() {
	return 0;
}

int Sheet_partnerattribute_s::ResumeInit() {
	return 0;
}

void Sheet_partnerattribute_s::write_to_pbmsg(::proto_ff::Sheet_partnerattribute & msg) const {
	for(int32_t i = 0; i < (int32_t)partnerattribute_List.GetSize() && i < partnerattribute_List.GetMaxSize(); ++i) {
		::proto_ff::partnerattribute* temp_partnerattribute_list = msg.add_partnerattribute_list();
		partnerattribute_List[i].write_to_pbmsg(*temp_partnerattribute_list);
	}
}

void Sheet_partnerattribute_s::read_from_pbmsg(const ::proto_ff::Sheet_partnerattribute & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_partnerattribute_s));
	partnerattribute_List.SetSize(msg.partnerattribute_list_size() > partnerattribute_List.GetMaxSize() ? partnerattribute_List.GetMaxSize() : msg.partnerattribute_list_size());
	for(int32_t i = 0; i < (int32_t)partnerattribute_List.GetSize(); ++i) {
		const ::proto_ff::partnerattribute & temp_partnerattribute_list = msg.partnerattribute_list(i);
		partnerattribute_List[i].read_from_pbmsg(temp_partnerattribute_list);
	}
}

partnerexp_s::partnerexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int partnerexp_s::CreateInit() {
	ID = (int32_t)0;
	exp = (int32_t)0;
	wearQuality = (int32_t)0;
	quality = (int32_t)0;
	return 0;
}

int partnerexp_s::ResumeInit() {
	return 0;
}

void partnerexp_s::write_to_pbmsg(::proto_ff::partnerexp & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_exp((int32_t)exp);
	msg.set_wearquality((int32_t)wearQuality);
	msg.set_quality((int32_t)quality);
}

void partnerexp_s::read_from_pbmsg(const ::proto_ff::partnerexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct partnerexp_s));
	ID = msg.id();
	exp = msg.exp();
	wearQuality = msg.wearquality();
	quality = msg.quality();
}

Sheet_partnerexp_s::Sheet_partnerexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_partnerexp_s::CreateInit() {
	return 0;
}

int Sheet_partnerexp_s::ResumeInit() {
	return 0;
}

void Sheet_partnerexp_s::write_to_pbmsg(::proto_ff::Sheet_partnerexp & msg) const {
	for(int32_t i = 0; i < (int32_t)partnerexp_List.GetSize() && i < partnerexp_List.GetMaxSize(); ++i) {
		::proto_ff::partnerexp* temp_partnerexp_list = msg.add_partnerexp_list();
		partnerexp_List[i].write_to_pbmsg(*temp_partnerexp_list);
	}
}

void Sheet_partnerexp_s::read_from_pbmsg(const ::proto_ff::Sheet_partnerexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_partnerexp_s));
	partnerexp_List.SetSize(msg.partnerexp_list_size() > partnerexp_List.GetMaxSize() ? partnerexp_List.GetMaxSize() : msg.partnerexp_list_size());
	for(int32_t i = 0; i < (int32_t)partnerexp_List.GetSize(); ++i) {
		const ::proto_ff::partnerexp & temp_partnerexp_list = msg.partnerexp_list(i);
		partnerexp_List[i].read_from_pbmsg(temp_partnerexp_list);
	}
}

partnerequipattributeDesc_s::partnerequipattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int partnerequipattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int partnerequipattributeDesc_s::ResumeInit() {
	return 0;
}

void partnerequipattributeDesc_s::write_to_pbmsg(::proto_ff::partnerequipattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void partnerequipattributeDesc_s::read_from_pbmsg(const ::proto_ff::partnerequipattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct partnerequipattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

partnerequip_s::partnerequip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int partnerequip_s::CreateInit() {
	id = (int64_t)0;
	position = (int32_t)0;
	refineLv = (int32_t)0;
	refineNum = (int32_t)0;
	return 0;
}

int partnerequip_s::ResumeInit() {
	return 0;
}

void partnerequip_s::write_to_pbmsg(::proto_ff::partnerequip & msg) const {
	msg.set_id((int64_t)id);
	msg.set_position((int32_t)position);
	msg.set_refinelv((int32_t)refineLv);
	msg.set_refinenum((int32_t)refineNum);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::partnerequipattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void partnerequip_s::read_from_pbmsg(const ::proto_ff::partnerequip & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct partnerequip_s));
	id = msg.id();
	position = msg.position();
	refineLv = msg.refinelv();
	refineNum = msg.refinenum();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::partnerequipattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_partnerequip_s::Sheet_partnerequip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_partnerequip_s::CreateInit() {
	return 0;
}

int Sheet_partnerequip_s::ResumeInit() {
	return 0;
}

void Sheet_partnerequip_s::write_to_pbmsg(::proto_ff::Sheet_partnerequip & msg) const {
	for(int32_t i = 0; i < (int32_t)partnerequip_List.GetSize() && i < partnerequip_List.GetMaxSize(); ++i) {
		::proto_ff::partnerequip* temp_partnerequip_list = msg.add_partnerequip_list();
		partnerequip_List[i].write_to_pbmsg(*temp_partnerequip_list);
	}
}

void Sheet_partnerequip_s::read_from_pbmsg(const ::proto_ff::Sheet_partnerequip & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_partnerequip_s));
	partnerequip_List.SetSize(msg.partnerequip_list_size() > partnerequip_List.GetMaxSize() ? partnerequip_List.GetMaxSize() : msg.partnerequip_list_size());
	for(int32_t i = 0; i < (int32_t)partnerequip_List.GetSize(); ++i) {
		const ::proto_ff::partnerequip & temp_partnerequip_list = msg.partnerequip_list(i);
		partnerequip_List[i].read_from_pbmsg(temp_partnerequip_list);
	}
}

partnerrefine_s::partnerrefine_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int partnerrefine_s::CreateInit() {
	id = (int32_t)0;
	refineId = (int64_t)0;
	refineNum = (int32_t)0;
	return 0;
}

int partnerrefine_s::ResumeInit() {
	return 0;
}

void partnerrefine_s::write_to_pbmsg(::proto_ff::partnerrefine & msg) const {
	msg.set_id((int32_t)id);
	msg.set_refineid((int64_t)refineId);
	msg.set_refinenum((int32_t)refineNum);
}

void partnerrefine_s::read_from_pbmsg(const ::proto_ff::partnerrefine & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct partnerrefine_s));
	id = msg.id();
	refineId = msg.refineid();
	refineNum = msg.refinenum();
}

Sheet_partnerrefine_s::Sheet_partnerrefine_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_partnerrefine_s::CreateInit() {
	return 0;
}

int Sheet_partnerrefine_s::ResumeInit() {
	return 0;
}

void Sheet_partnerrefine_s::write_to_pbmsg(::proto_ff::Sheet_partnerrefine & msg) const {
	for(int32_t i = 0; i < (int32_t)partnerrefine_List.GetSize() && i < partnerrefine_List.GetMaxSize(); ++i) {
		::proto_ff::partnerrefine* temp_partnerrefine_list = msg.add_partnerrefine_list();
		partnerrefine_List[i].write_to_pbmsg(*temp_partnerrefine_list);
	}
}

void Sheet_partnerrefine_s::read_from_pbmsg(const ::proto_ff::Sheet_partnerrefine & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_partnerrefine_s));
	partnerrefine_List.SetSize(msg.partnerrefine_list_size() > partnerrefine_List.GetMaxSize() ? partnerrefine_List.GetMaxSize() : msg.partnerrefine_list_size());
	for(int32_t i = 0; i < (int32_t)partnerrefine_List.GetSize(); ++i) {
		const ::proto_ff::partnerrefine & temp_partnerrefine_list = msg.partnerrefine_list(i);
		partnerrefine_List[i].read_from_pbmsg(temp_partnerrefine_list);
	}
}

partnerslot_s::partnerslot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int partnerslot_s::CreateInit() {
	position = (int32_t)0;
	refineLv = (int32_t)0;
	refineNum = (int32_t)0;
	return 0;
}

int partnerslot_s::ResumeInit() {
	return 0;
}

void partnerslot_s::write_to_pbmsg(::proto_ff::partnerslot & msg) const {
	msg.set_position((int32_t)position);
	msg.set_refinelv((int32_t)refineLv);
	msg.set_refinenum((int32_t)refineNum);
}

void partnerslot_s::read_from_pbmsg(const ::proto_ff::partnerslot & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct partnerslot_s));
	position = msg.position();
	refineLv = msg.refinelv();
	refineNum = msg.refinenum();
}

Sheet_partnerslot_s::Sheet_partnerslot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_partnerslot_s::CreateInit() {
	return 0;
}

int Sheet_partnerslot_s::ResumeInit() {
	return 0;
}

void Sheet_partnerslot_s::write_to_pbmsg(::proto_ff::Sheet_partnerslot & msg) const {
	for(int32_t i = 0; i < (int32_t)partnerslot_List.GetSize() && i < partnerslot_List.GetMaxSize(); ++i) {
		::proto_ff::partnerslot* temp_partnerslot_list = msg.add_partnerslot_list();
		partnerslot_List[i].write_to_pbmsg(*temp_partnerslot_list);
	}
}

void Sheet_partnerslot_s::read_from_pbmsg(const ::proto_ff::Sheet_partnerslot & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_partnerslot_s));
	partnerslot_List.SetSize(msg.partnerslot_list_size() > partnerslot_List.GetMaxSize() ? partnerslot_List.GetMaxSize() : msg.partnerslot_list_size());
	for(int32_t i = 0; i < (int32_t)partnerslot_List.GetSize(); ++i) {
		const ::proto_ff::partnerslot & temp_partnerslot_list = msg.partnerslot_list(i);
		partnerslot_List[i].read_from_pbmsg(temp_partnerslot_list);
	}
}

}