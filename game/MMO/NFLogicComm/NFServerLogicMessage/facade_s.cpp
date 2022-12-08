#include "facade_s.h"

namespace proto_ff_s {

facadedisplaymaterialDesc_s::facadedisplaymaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadedisplaymaterialDesc_s::CreateInit() {
	id = (int64_t)0;
	exp = (int32_t)0;
	return 0;
}

int facadedisplaymaterialDesc_s::ResumeInit() {
	return 0;
}

void facadedisplaymaterialDesc_s::write_to_pbmsg(::proto_ff::facadedisplaymaterialDesc & msg) const {
	msg.set_id((int64_t)id);
	msg.set_exp((int32_t)exp);
}

void facadedisplaymaterialDesc_s::read_from_pbmsg(const ::proto_ff::facadedisplaymaterialDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadedisplaymaterialDesc_s));
	id = msg.id();
	exp = msg.exp();
}

facadedisplay_s::facadedisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadedisplay_s::CreateInit() {
	id = (int64_t)0;
	type = (int32_t)0;
	soulItemID = (int32_t)0;
	return 0;
}

int facadedisplay_s::ResumeInit() {
	return 0;
}

void facadedisplay_s::write_to_pbmsg(::proto_ff::facadedisplay & msg) const {
	msg.set_id((int64_t)id);
	msg.set_type((int32_t)type);
	msg.set_resource((const char*)resource.Get());
	msg.set_name((const char*)name.Get());
	msg.set_activedesc((const char*)activeDesc.Get());
	msg.set_professionid((const char*)professionID.Get());
	msg.set_skillid((const char*)skillID.Get());
	msg.set_soulitemid((int32_t)soulItemID);
	for(int32_t i = 0; i < (int32_t)material.GetSize() && i < material.GetMaxSize(); ++i) {
		::proto_ff::facadedisplaymaterialDesc* temp_material = msg.add_material();
		material[i].write_to_pbmsg(*temp_material);
	}
	for(int32_t i = 0; i < (int32_t)fragmentID.GetSize() && i < fragmentID.GetMaxSize(); ++i) {
		msg.add_fragmentid((int64_t)fragmentID[i]);
	}
}

void facadedisplay_s::read_from_pbmsg(const ::proto_ff::facadedisplay & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadedisplay_s));
	id = msg.id();
	type = msg.type();
	resource.Copy(msg.resource());
	name.Copy(msg.name());
	activeDesc.Copy(msg.activedesc());
	professionID.Copy(msg.professionid());
	skillID.Copy(msg.skillid());
	soulItemID = msg.soulitemid();
	material.SetSize(msg.material_size() > material.GetMaxSize() ? material.GetMaxSize() : msg.material_size());
	for(int32_t i = 0; i < (int32_t)material.GetSize(); ++i) {
		const ::proto_ff::facadedisplaymaterialDesc & temp_material = msg.material(i);
		material[i].read_from_pbmsg(temp_material);
	}
	fragmentID.SetSize(msg.fragmentid_size() > fragmentID.GetMaxSize() ? fragmentID.GetMaxSize() : msg.fragmentid_size());
	for(int32_t i = 0; i < (int32_t)fragmentID.GetSize(); ++i) {
		fragmentID[i] = msg.fragmentid(i);
	}
}

Sheet_facadedisplay_s::Sheet_facadedisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_facadedisplay_s::CreateInit() {
	return 0;
}

int Sheet_facadedisplay_s::ResumeInit() {
	return 0;
}

void Sheet_facadedisplay_s::write_to_pbmsg(::proto_ff::Sheet_facadedisplay & msg) const {
	for(int32_t i = 0; i < (int32_t)facadedisplay_List.GetSize() && i < facadedisplay_List.GetMaxSize(); ++i) {
		::proto_ff::facadedisplay* temp_facadedisplay_list = msg.add_facadedisplay_list();
		facadedisplay_List[i].write_to_pbmsg(*temp_facadedisplay_list);
	}
}

void Sheet_facadedisplay_s::read_from_pbmsg(const ::proto_ff::Sheet_facadedisplay & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_facadedisplay_s));
	facadedisplay_List.SetSize(msg.facadedisplay_list_size() > facadedisplay_List.GetMaxSize() ? facadedisplay_List.GetMaxSize() : msg.facadedisplay_list_size());
	for(int32_t i = 0; i < (int32_t)facadedisplay_List.GetSize(); ++i) {
		const ::proto_ff::facadedisplay & temp_facadedisplay_list = msg.facadedisplay_list(i);
		facadedisplay_List[i].read_from_pbmsg(temp_facadedisplay_list);
	}
}

facadevaluetreasureAttributeDesc_s::facadevaluetreasureAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadevaluetreasureAttributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int facadevaluetreasureAttributeDesc_s::ResumeInit() {
	return 0;
}

void facadevaluetreasureAttributeDesc_s::write_to_pbmsg(::proto_ff::facadevaluetreasureAttributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void facadevaluetreasureAttributeDesc_s::read_from_pbmsg(const ::proto_ff::facadevaluetreasureAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadevaluetreasureAttributeDesc_s));
	type = msg.type();
	value = msg.value();
}

facadevalueArtifactAttributeDesc_s::facadevalueArtifactAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadevalueArtifactAttributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int facadevalueArtifactAttributeDesc_s::ResumeInit() {
	return 0;
}

void facadevalueArtifactAttributeDesc_s::write_to_pbmsg(::proto_ff::facadevalueArtifactAttributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void facadevalueArtifactAttributeDesc_s::read_from_pbmsg(const ::proto_ff::facadevalueArtifactAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadevalueArtifactAttributeDesc_s));
	type = msg.type();
	value = msg.value();
}

facadevalueBladeAttributeDesc_s::facadevalueBladeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadevalueBladeAttributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int facadevalueBladeAttributeDesc_s::ResumeInit() {
	return 0;
}

void facadevalueBladeAttributeDesc_s::write_to_pbmsg(::proto_ff::facadevalueBladeAttributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void facadevalueBladeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::facadevalueBladeAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadevalueBladeAttributeDesc_s));
	type = msg.type();
	value = msg.value();
}

facadevaluewingAttributeDesc_s::facadevaluewingAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadevaluewingAttributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int facadevaluewingAttributeDesc_s::ResumeInit() {
	return 0;
}

void facadevaluewingAttributeDesc_s::write_to_pbmsg(::proto_ff::facadevaluewingAttributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void facadevaluewingAttributeDesc_s::read_from_pbmsg(const ::proto_ff::facadevaluewingAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadevaluewingAttributeDesc_s));
	type = msg.type();
	value = msg.value();
}

facadevalue_s::facadevalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadevalue_s::CreateInit() {
	lv = (int32_t)0;
	wingExp = (int64_t)0;
	treasureExp = (int64_t)0;
	ArtifactExp = (int64_t)0;
	BladeExp = (int64_t)0;
	return 0;
}

int facadevalue_s::ResumeInit() {
	return 0;
}

void facadevalue_s::write_to_pbmsg(::proto_ff::facadevalue & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_wingexp((int64_t)wingExp);
	msg.set_treasureexp((int64_t)treasureExp);
	msg.set_artifactexp((int64_t)ArtifactExp);
	msg.set_bladeexp((int64_t)BladeExp);
	for(int32_t i = 0; i < (int32_t)treasureAttribute.GetSize() && i < treasureAttribute.GetMaxSize(); ++i) {
		::proto_ff::facadevaluetreasureAttributeDesc* temp_treasureattribute = msg.add_treasureattribute();
		treasureAttribute[i].write_to_pbmsg(*temp_treasureattribute);
	}
	for(int32_t i = 0; i < (int32_t)ArtifactAttribute.GetSize() && i < ArtifactAttribute.GetMaxSize(); ++i) {
		::proto_ff::facadevalueArtifactAttributeDesc* temp_artifactattribute = msg.add_artifactattribute();
		ArtifactAttribute[i].write_to_pbmsg(*temp_artifactattribute);
	}
	for(int32_t i = 0; i < (int32_t)BladeAttribute.GetSize() && i < BladeAttribute.GetMaxSize(); ++i) {
		::proto_ff::facadevalueBladeAttributeDesc* temp_bladeattribute = msg.add_bladeattribute();
		BladeAttribute[i].write_to_pbmsg(*temp_bladeattribute);
	}
	for(int32_t i = 0; i < (int32_t)wingAttribute.GetSize() && i < wingAttribute.GetMaxSize(); ++i) {
		::proto_ff::facadevaluewingAttributeDesc* temp_wingattribute = msg.add_wingattribute();
		wingAttribute[i].write_to_pbmsg(*temp_wingattribute);
	}
}

void facadevalue_s::read_from_pbmsg(const ::proto_ff::facadevalue & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadevalue_s));
	lv = msg.lv();
	wingExp = msg.wingexp();
	treasureExp = msg.treasureexp();
	ArtifactExp = msg.artifactexp();
	BladeExp = msg.bladeexp();
	treasureAttribute.SetSize(msg.treasureattribute_size() > treasureAttribute.GetMaxSize() ? treasureAttribute.GetMaxSize() : msg.treasureattribute_size());
	for(int32_t i = 0; i < (int32_t)treasureAttribute.GetSize(); ++i) {
		const ::proto_ff::facadevaluetreasureAttributeDesc & temp_treasureattribute = msg.treasureattribute(i);
		treasureAttribute[i].read_from_pbmsg(temp_treasureattribute);
	}
	ArtifactAttribute.SetSize(msg.artifactattribute_size() > ArtifactAttribute.GetMaxSize() ? ArtifactAttribute.GetMaxSize() : msg.artifactattribute_size());
	for(int32_t i = 0; i < (int32_t)ArtifactAttribute.GetSize(); ++i) {
		const ::proto_ff::facadevalueArtifactAttributeDesc & temp_artifactattribute = msg.artifactattribute(i);
		ArtifactAttribute[i].read_from_pbmsg(temp_artifactattribute);
	}
	BladeAttribute.SetSize(msg.bladeattribute_size() > BladeAttribute.GetMaxSize() ? BladeAttribute.GetMaxSize() : msg.bladeattribute_size());
	for(int32_t i = 0; i < (int32_t)BladeAttribute.GetSize(); ++i) {
		const ::proto_ff::facadevalueBladeAttributeDesc & temp_bladeattribute = msg.bladeattribute(i);
		BladeAttribute[i].read_from_pbmsg(temp_bladeattribute);
	}
	wingAttribute.SetSize(msg.wingattribute_size() > wingAttribute.GetMaxSize() ? wingAttribute.GetMaxSize() : msg.wingattribute_size());
	for(int32_t i = 0; i < (int32_t)wingAttribute.GetSize(); ++i) {
		const ::proto_ff::facadevaluewingAttributeDesc & temp_wingattribute = msg.wingattribute(i);
		wingAttribute[i].read_from_pbmsg(temp_wingattribute);
	}
}

Sheet_facadevalue_s::Sheet_facadevalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_facadevalue_s::CreateInit() {
	return 0;
}

int Sheet_facadevalue_s::ResumeInit() {
	return 0;
}

void Sheet_facadevalue_s::write_to_pbmsg(::proto_ff::Sheet_facadevalue & msg) const {
	for(int32_t i = 0; i < (int32_t)facadevalue_List.GetSize() && i < facadevalue_List.GetMaxSize(); ++i) {
		::proto_ff::facadevalue* temp_facadevalue_list = msg.add_facadevalue_list();
		facadevalue_List[i].write_to_pbmsg(*temp_facadevalue_list);
	}
}

void Sheet_facadevalue_s::read_from_pbmsg(const ::proto_ff::Sheet_facadevalue & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_facadevalue_s));
	facadevalue_List.SetSize(msg.facadevalue_list_size() > facadevalue_List.GetMaxSize() ? facadevalue_List.GetMaxSize() : msg.facadevalue_list_size());
	for(int32_t i = 0; i < (int32_t)facadevalue_List.GetSize(); ++i) {
		const ::proto_ff::facadevalue & temp_facadevalue_list = msg.facadevalue_list(i);
		facadevalue_List[i].read_from_pbmsg(temp_facadevalue_list);
	}
}

facadetype_s::facadetype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadetype_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int facadetype_s::ResumeInit() {
	return 0;
}

void facadetype_s::write_to_pbmsg(::proto_ff::facadetype & msg) const {
	msg.set_id((int32_t)id);
	msg.set_soucename((const char*)souceName.Get());
}

void facadetype_s::read_from_pbmsg(const ::proto_ff::facadetype & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadetype_s));
	id = msg.id();
	souceName.Copy(msg.soucename());
}

Sheet_facadetype_s::Sheet_facadetype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_facadetype_s::CreateInit() {
	return 0;
}

int Sheet_facadetype_s::ResumeInit() {
	return 0;
}

void Sheet_facadetype_s::write_to_pbmsg(::proto_ff::Sheet_facadetype & msg) const {
	for(int32_t i = 0; i < (int32_t)facadetype_List.GetSize() && i < facadetype_List.GetMaxSize(); ++i) {
		::proto_ff::facadetype* temp_facadetype_list = msg.add_facadetype_list();
		facadetype_List[i].write_to_pbmsg(*temp_facadetype_list);
	}
}

void Sheet_facadetype_s::read_from_pbmsg(const ::proto_ff::Sheet_facadetype & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_facadetype_s));
	facadetype_List.SetSize(msg.facadetype_list_size() > facadetype_List.GetMaxSize() ? facadetype_List.GetMaxSize() : msg.facadetype_list_size());
	for(int32_t i = 0; i < (int32_t)facadetype_List.GetSize(); ++i) {
		const ::proto_ff::facadetype & temp_facadetype_list = msg.facadetype_list(i);
		facadetype_List[i].read_from_pbmsg(temp_facadetype_list);
	}
}

facadefragmentattributeDesc_s::facadefragmentattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadefragmentattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int facadefragmentattributeDesc_s::ResumeInit() {
	return 0;
}

void facadefragmentattributeDesc_s::write_to_pbmsg(::proto_ff::facadefragmentattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void facadefragmentattributeDesc_s::read_from_pbmsg(const ::proto_ff::facadefragmentattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadefragmentattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

facadefragment_s::facadefragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadefragment_s::CreateInit() {
	fragmentID = (int64_t)0;
	item = (int64_t)0;
	itemNum = (int32_t)0;
	return 0;
}

int facadefragment_s::ResumeInit() {
	return 0;
}

void facadefragment_s::write_to_pbmsg(::proto_ff::facadefragment & msg) const {
	msg.set_fragmentid((int64_t)fragmentID);
	msg.set_item((int64_t)item);
	msg.set_itemnum((int32_t)itemNum);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::facadefragmentattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void facadefragment_s::read_from_pbmsg(const ::proto_ff::facadefragment & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadefragment_s));
	fragmentID = msg.fragmentid();
	item = msg.item();
	itemNum = msg.itemnum();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::facadefragmentattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_facadefragment_s::Sheet_facadefragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_facadefragment_s::CreateInit() {
	return 0;
}

int Sheet_facadefragment_s::ResumeInit() {
	return 0;
}

void Sheet_facadefragment_s::write_to_pbmsg(::proto_ff::Sheet_facadefragment & msg) const {
	for(int32_t i = 0; i < (int32_t)facadefragment_List.GetSize() && i < facadefragment_List.GetMaxSize(); ++i) {
		::proto_ff::facadefragment* temp_facadefragment_list = msg.add_facadefragment_list();
		facadefragment_List[i].write_to_pbmsg(*temp_facadefragment_list);
	}
}

void Sheet_facadefragment_s::read_from_pbmsg(const ::proto_ff::Sheet_facadefragment & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_facadefragment_s));
	facadefragment_List.SetSize(msg.facadefragment_list_size() > facadefragment_List.GetMaxSize() ? facadefragment_List.GetMaxSize() : msg.facadefragment_list_size());
	for(int32_t i = 0; i < (int32_t)facadefragment_List.GetSize(); ++i) {
		const ::proto_ff::facadefragment & temp_facadefragment_list = msg.facadefragment_list(i);
		facadefragment_List[i].read_from_pbmsg(temp_facadefragment_list);
	}
}

facadechangeattributeDesc_s::facadechangeattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadechangeattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int facadechangeattributeDesc_s::ResumeInit() {
	return 0;
}

void facadechangeattributeDesc_s::write_to_pbmsg(::proto_ff::facadechangeattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void facadechangeattributeDesc_s::read_from_pbmsg(const ::proto_ff::facadechangeattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadechangeattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

facadechangeActiveAttributeDesc_s::facadechangeActiveAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadechangeActiveAttributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int facadechangeActiveAttributeDesc_s::ResumeInit() {
	return 0;
}

void facadechangeActiveAttributeDesc_s::write_to_pbmsg(::proto_ff::facadechangeActiveAttributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void facadechangeActiveAttributeDesc_s::read_from_pbmsg(const ::proto_ff::facadechangeActiveAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadechangeActiveAttributeDesc_s));
	type = msg.type();
	value = msg.value();
}

facadechange_s::facadechange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadechange_s::CreateInit() {
	id = (int64_t)0;
	type = (int32_t)0;
	quality = (int32_t)0;
	activationItem = (int64_t)0;
	activationNum = (int32_t)0;
	starId = (int64_t)0;
	starUp = (int32_t)0;
	starBer = (int32_t)0;
	upAttributeId = (int64_t)0;
	activeSkill = (int32_t)0;
	return 0;
}

int facadechange_s::ResumeInit() {
	return 0;
}

void facadechange_s::write_to_pbmsg(::proto_ff::facadechange & msg) const {
	msg.set_id((int64_t)id);
	msg.set_type((int32_t)type);
	msg.set_resource((const char*)resource.Get());
	msg.set_professionid((const char*)professionID.Get());
	msg.set_name((const char*)name.Get());
	msg.set_activedesc((const char*)activeDesc.Get());
	msg.set_quality((int32_t)quality);
	msg.set_activationitem((int64_t)activationItem);
	msg.set_activationnum((int32_t)activationNum);
	msg.set_starid((int64_t)starId);
	msg.set_starnum((const char*)starNum.Get());
	msg.set_starup((int32_t)starUp);
	msg.set_starber((int32_t)starBer);
	msg.set_upattributeid((int64_t)upAttributeId);
	msg.set_activeskill((int32_t)activeSkill);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::facadechangeattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
	for(int32_t i = 0; i < (int32_t)ActiveAttribute.GetSize() && i < ActiveAttribute.GetMaxSize(); ++i) {
		::proto_ff::facadechangeActiveAttributeDesc* temp_activeattribute = msg.add_activeattribute();
		ActiveAttribute[i].write_to_pbmsg(*temp_activeattribute);
	}
}

void facadechange_s::read_from_pbmsg(const ::proto_ff::facadechange & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadechange_s));
	id = msg.id();
	type = msg.type();
	resource.Copy(msg.resource());
	professionID.Copy(msg.professionid());
	name.Copy(msg.name());
	activeDesc.Copy(msg.activedesc());
	quality = msg.quality();
	activationItem = msg.activationitem();
	activationNum = msg.activationnum();
	starId = msg.starid();
	starNum.Copy(msg.starnum());
	starUp = msg.starup();
	starBer = msg.starber();
	upAttributeId = msg.upattributeid();
	activeSkill = msg.activeskill();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::facadechangeattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
	ActiveAttribute.SetSize(msg.activeattribute_size() > ActiveAttribute.GetMaxSize() ? ActiveAttribute.GetMaxSize() : msg.activeattribute_size());
	for(int32_t i = 0; i < (int32_t)ActiveAttribute.GetSize(); ++i) {
		const ::proto_ff::facadechangeActiveAttributeDesc & temp_activeattribute = msg.activeattribute(i);
		ActiveAttribute[i].read_from_pbmsg(temp_activeattribute);
	}
}

Sheet_facadechange_s::Sheet_facadechange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_facadechange_s::CreateInit() {
	return 0;
}

int Sheet_facadechange_s::ResumeInit() {
	return 0;
}

void Sheet_facadechange_s::write_to_pbmsg(::proto_ff::Sheet_facadechange & msg) const {
	for(int32_t i = 0; i < (int32_t)facadechange_List.GetSize() && i < facadechange_List.GetMaxSize(); ++i) {
		::proto_ff::facadechange* temp_facadechange_list = msg.add_facadechange_list();
		facadechange_List[i].write_to_pbmsg(*temp_facadechange_list);
	}
}

void Sheet_facadechange_s::read_from_pbmsg(const ::proto_ff::Sheet_facadechange & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_facadechange_s));
	facadechange_List.SetSize(msg.facadechange_list_size() > facadechange_List.GetMaxSize() ? facadechange_List.GetMaxSize() : msg.facadechange_list_size());
	for(int32_t i = 0; i < (int32_t)facadechange_List.GetSize(); ++i) {
		const ::proto_ff::facadechange & temp_facadechange_list = msg.facadechange_list(i);
		facadechange_List[i].read_from_pbmsg(temp_facadechange_list);
	}
}

facadestarUpupAttributeDesc_s::facadestarUpupAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadestarUpupAttributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int facadestarUpupAttributeDesc_s::ResumeInit() {
	return 0;
}

void facadestarUpupAttributeDesc_s::write_to_pbmsg(::proto_ff::facadestarUpupAttributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void facadestarUpupAttributeDesc_s::read_from_pbmsg(const ::proto_ff::facadestarUpupAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadestarUpupAttributeDesc_s));
	type = msg.type();
	value = msg.value();
}

facadestarUp_s::facadestarUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadestarUp_s::CreateInit() {
	ID = (int32_t)0;
	upAttributeId = (int64_t)0;
	starID = (int32_t)0;
	skillID = (int32_t)0;
	return 0;
}

int facadestarUp_s::ResumeInit() {
	return 0;
}

void facadestarUp_s::write_to_pbmsg(::proto_ff::facadestarUp & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_upattributeid((int64_t)upAttributeId);
	msg.set_starid((int32_t)starID);
	msg.set_skillid((int32_t)skillID);
	for(int32_t i = 0; i < (int32_t)upAttribute.GetSize() && i < upAttribute.GetMaxSize(); ++i) {
		::proto_ff::facadestarUpupAttributeDesc* temp_upattribute = msg.add_upattribute();
		upAttribute[i].write_to_pbmsg(*temp_upattribute);
	}
}

void facadestarUp_s::read_from_pbmsg(const ::proto_ff::facadestarUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadestarUp_s));
	ID = msg.id();
	upAttributeId = msg.upattributeid();
	starID = msg.starid();
	skillID = msg.skillid();
	upAttribute.SetSize(msg.upattribute_size() > upAttribute.GetMaxSize() ? upAttribute.GetMaxSize() : msg.upattribute_size());
	for(int32_t i = 0; i < (int32_t)upAttribute.GetSize(); ++i) {
		const ::proto_ff::facadestarUpupAttributeDesc & temp_upattribute = msg.upattribute(i);
		upAttribute[i].read_from_pbmsg(temp_upattribute);
	}
}

Sheet_facadestarUp_s::Sheet_facadestarUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_facadestarUp_s::CreateInit() {
	return 0;
}

int Sheet_facadestarUp_s::ResumeInit() {
	return 0;
}

void Sheet_facadestarUp_s::write_to_pbmsg(::proto_ff::Sheet_facadestarUp & msg) const {
	for(int32_t i = 0; i < (int32_t)facadestarUp_List.GetSize() && i < facadestarUp_List.GetMaxSize(); ++i) {
		::proto_ff::facadestarUp* temp_facadestarup_list = msg.add_facadestarup_list();
		facadestarUp_List[i].write_to_pbmsg(*temp_facadestarup_list);
	}
}

void Sheet_facadestarUp_s::read_from_pbmsg(const ::proto_ff::Sheet_facadestarUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_facadestarUp_s));
	facadestarUp_List.SetSize(msg.facadestarup_list_size() > facadestarUp_List.GetMaxSize() ? facadestarUp_List.GetMaxSize() : msg.facadestarup_list_size());
	for(int32_t i = 0; i < (int32_t)facadestarUp_List.GetSize(); ++i) {
		const ::proto_ff::facadestarUp & temp_facadestarup_list = msg.facadestarup_list(i);
		facadestarUp_List[i].read_from_pbmsg(temp_facadestarup_list);
	}
}

facadesoulattributeDesc_s::facadesoulattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadesoulattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int facadesoulattributeDesc_s::ResumeInit() {
	return 0;
}

void facadesoulattributeDesc_s::write_to_pbmsg(::proto_ff::facadesoulattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void facadesoulattributeDesc_s::read_from_pbmsg(const ::proto_ff::facadesoulattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadesoulattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

facadesoul_s::facadesoul_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadesoul_s::CreateInit() {
	id = (int64_t)0;
	rechargeID = (int32_t)0;
	mainSkill = (int32_t)0;
	return 0;
}

int facadesoul_s::ResumeInit() {
	return 0;
}

void facadesoul_s::write_to_pbmsg(::proto_ff::facadesoul & msg) const {
	msg.set_id((int64_t)id);
	msg.set_rechargeid((int32_t)rechargeID);
	msg.set_mainskill((int32_t)mainSkill);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::facadesoulattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
	for(int32_t i = 0; i < (int32_t)minorSkill.GetSize() && i < minorSkill.GetMaxSize(); ++i) {
		msg.add_minorskill((int32_t)minorSkill[i]);
	}
}

void facadesoul_s::read_from_pbmsg(const ::proto_ff::facadesoul & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadesoul_s));
	id = msg.id();
	rechargeID = msg.rechargeid();
	mainSkill = msg.mainskill();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::facadesoulattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
	minorSkill.SetSize(msg.minorskill_size() > minorSkill.GetMaxSize() ? minorSkill.GetMaxSize() : msg.minorskill_size());
	for(int32_t i = 0; i < (int32_t)minorSkill.GetSize(); ++i) {
		minorSkill[i] = msg.minorskill(i);
	}
}

Sheet_facadesoul_s::Sheet_facadesoul_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_facadesoul_s::CreateInit() {
	return 0;
}

int Sheet_facadesoul_s::ResumeInit() {
	return 0;
}

void Sheet_facadesoul_s::write_to_pbmsg(::proto_ff::Sheet_facadesoul & msg) const {
	for(int32_t i = 0; i < (int32_t)facadesoul_List.GetSize() && i < facadesoul_List.GetMaxSize(); ++i) {
		::proto_ff::facadesoul* temp_facadesoul_list = msg.add_facadesoul_list();
		facadesoul_List[i].write_to_pbmsg(*temp_facadesoul_list);
	}
}

void Sheet_facadesoul_s::read_from_pbmsg(const ::proto_ff::Sheet_facadesoul & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_facadesoul_s));
	facadesoul_List.SetSize(msg.facadesoul_list_size() > facadesoul_List.GetMaxSize() ? facadesoul_List.GetMaxSize() : msg.facadesoul_list_size());
	for(int32_t i = 0; i < (int32_t)facadesoul_List.GetSize(); ++i) {
		const ::proto_ff::facadesoul & temp_facadesoul_list = msg.facadesoul_list(i);
		facadesoul_List[i].read_from_pbmsg(temp_facadesoul_list);
	}
}

facadesoulActive_s::facadesoulActive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadesoulActive_s::CreateInit() {
	id = (int64_t)0;
	return 0;
}

int facadesoulActive_s::ResumeInit() {
	return 0;
}

void facadesoulActive_s::write_to_pbmsg(::proto_ff::facadesoulActive & msg) const {
	msg.set_id((int64_t)id);
	for(int32_t i = 0; i < (int32_t)parama.GetSize() && i < parama.GetMaxSize(); ++i) {
		msg.add_parama((const char*)parama[i].Get());
	}
	for(int32_t i = 0; i < (int32_t)condition.GetSize() && i < condition.GetMaxSize(); ++i) {
		msg.add_condition((int32_t)condition[i]);
	}
}

void facadesoulActive_s::read_from_pbmsg(const ::proto_ff::facadesoulActive & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadesoulActive_s));
	id = msg.id();
	parama.SetSize(msg.parama_size() > parama.GetMaxSize() ? parama.GetMaxSize() : msg.parama_size());
	for(int32_t i = 0; i < (int32_t)parama.GetSize(); ++i) {
		parama[i].Copy(msg.parama(i));
	}
	condition.SetSize(msg.condition_size() > condition.GetMaxSize() ? condition.GetMaxSize() : msg.condition_size());
	for(int32_t i = 0; i < (int32_t)condition.GetSize(); ++i) {
		condition[i] = msg.condition(i);
	}
}

Sheet_facadesoulActive_s::Sheet_facadesoulActive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_facadesoulActive_s::CreateInit() {
	return 0;
}

int Sheet_facadesoulActive_s::ResumeInit() {
	return 0;
}

void Sheet_facadesoulActive_s::write_to_pbmsg(::proto_ff::Sheet_facadesoulActive & msg) const {
	for(int32_t i = 0; i < (int32_t)facadesoulActive_List.GetSize() && i < facadesoulActive_List.GetMaxSize(); ++i) {
		::proto_ff::facadesoulActive* temp_facadesoulactive_list = msg.add_facadesoulactive_list();
		facadesoulActive_List[i].write_to_pbmsg(*temp_facadesoulactive_list);
	}
}

void Sheet_facadesoulActive_s::read_from_pbmsg(const ::proto_ff::Sheet_facadesoulActive & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_facadesoulActive_s));
	facadesoulActive_List.SetSize(msg.facadesoulactive_list_size() > facadesoulActive_List.GetMaxSize() ? facadesoulActive_List.GetMaxSize() : msg.facadesoulactive_list_size());
	for(int32_t i = 0; i < (int32_t)facadesoulActive_List.GetSize(); ++i) {
		const ::proto_ff::facadesoulActive & temp_facadesoulactive_list = msg.facadesoulactive_list(i);
		facadesoulActive_List[i].read_from_pbmsg(temp_facadesoulactive_list);
	}
}

facadesoulLvattributeDesc_s::facadesoulLvattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadesoulLvattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int facadesoulLvattributeDesc_s::ResumeInit() {
	return 0;
}

void facadesoulLvattributeDesc_s::write_to_pbmsg(::proto_ff::facadesoulLvattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void facadesoulLvattributeDesc_s::read_from_pbmsg(const ::proto_ff::facadesoulLvattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadesoulLvattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

facadesoulLv_s::facadesoulLv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadesoulLv_s::CreateInit() {
	id = (int64_t)0;
	soulID = (int32_t)0;
	itemID = (int32_t)0;
	num = (int32_t)0;
	successRate = (int32_t)0;
	downLv = (int32_t)0;
	return 0;
}

int facadesoulLv_s::ResumeInit() {
	return 0;
}

void facadesoulLv_s::write_to_pbmsg(::proto_ff::facadesoulLv & msg) const {
	msg.set_id((int64_t)id);
	msg.set_soulid((int32_t)soulID);
	msg.set_itemid((int32_t)itemID);
	msg.set_num((int32_t)num);
	msg.set_successrate((int32_t)successRate);
	msg.set_downlv((int32_t)downLv);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::facadesoulLvattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void facadesoulLv_s::read_from_pbmsg(const ::proto_ff::facadesoulLv & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadesoulLv_s));
	id = msg.id();
	soulID = msg.soulid();
	itemID = msg.itemid();
	num = msg.num();
	successRate = msg.successrate();
	downLv = msg.downlv();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::facadesoulLvattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_facadesoulLv_s::Sheet_facadesoulLv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_facadesoulLv_s::CreateInit() {
	return 0;
}

int Sheet_facadesoulLv_s::ResumeInit() {
	return 0;
}

void Sheet_facadesoulLv_s::write_to_pbmsg(::proto_ff::Sheet_facadesoulLv & msg) const {
	for(int32_t i = 0; i < (int32_t)facadesoulLv_List.GetSize() && i < facadesoulLv_List.GetMaxSize(); ++i) {
		::proto_ff::facadesoulLv* temp_facadesoullv_list = msg.add_facadesoullv_list();
		facadesoulLv_List[i].write_to_pbmsg(*temp_facadesoullv_list);
	}
}

void Sheet_facadesoulLv_s::read_from_pbmsg(const ::proto_ff::Sheet_facadesoulLv & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_facadesoulLv_s));
	facadesoulLv_List.SetSize(msg.facadesoullv_list_size() > facadesoulLv_List.GetMaxSize() ? facadesoulLv_List.GetMaxSize() : msg.facadesoullv_list_size());
	for(int32_t i = 0; i < (int32_t)facadesoulLv_List.GetSize(); ++i) {
		const ::proto_ff::facadesoulLv & temp_facadesoullv_list = msg.facadesoullv_list(i);
		facadesoulLv_List[i].read_from_pbmsg(temp_facadesoullv_list);
	}
}

facadesoulAchievement_s::facadesoulAchievement_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int facadesoulAchievement_s::CreateInit() {
	id = (int64_t)0;
	soulID = (int32_t)0;
	type = (int32_t)0;
	parama = (int32_t)0;
	itemID = (int32_t)0;
	num = (int32_t)0;
	return 0;
}

int facadesoulAchievement_s::ResumeInit() {
	return 0;
}

void facadesoulAchievement_s::write_to_pbmsg(::proto_ff::facadesoulAchievement & msg) const {
	msg.set_id((int64_t)id);
	msg.set_soulid((int32_t)soulID);
	msg.set_type((int32_t)type);
	msg.set_parama((int32_t)parama);
	msg.set_itemid((int32_t)itemID);
	msg.set_num((int32_t)num);
}

void facadesoulAchievement_s::read_from_pbmsg(const ::proto_ff::facadesoulAchievement & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct facadesoulAchievement_s));
	id = msg.id();
	soulID = msg.soulid();
	type = msg.type();
	parama = msg.parama();
	itemID = msg.itemid();
	num = msg.num();
}

Sheet_facadesoulAchievement_s::Sheet_facadesoulAchievement_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_facadesoulAchievement_s::CreateInit() {
	return 0;
}

int Sheet_facadesoulAchievement_s::ResumeInit() {
	return 0;
}

void Sheet_facadesoulAchievement_s::write_to_pbmsg(::proto_ff::Sheet_facadesoulAchievement & msg) const {
	for(int32_t i = 0; i < (int32_t)facadesoulAchievement_List.GetSize() && i < facadesoulAchievement_List.GetMaxSize(); ++i) {
		::proto_ff::facadesoulAchievement* temp_facadesoulachievement_list = msg.add_facadesoulachievement_list();
		facadesoulAchievement_List[i].write_to_pbmsg(*temp_facadesoulachievement_list);
	}
}

void Sheet_facadesoulAchievement_s::read_from_pbmsg(const ::proto_ff::Sheet_facadesoulAchievement & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_facadesoulAchievement_s));
	facadesoulAchievement_List.SetSize(msg.facadesoulachievement_list_size() > facadesoulAchievement_List.GetMaxSize() ? facadesoulAchievement_List.GetMaxSize() : msg.facadesoulachievement_list_size());
	for(int32_t i = 0; i < (int32_t)facadesoulAchievement_List.GetSize(); ++i) {
		const ::proto_ff::facadesoulAchievement & temp_facadesoulachievement_list = msg.facadesoulachievement_list(i);
		facadesoulAchievement_List[i].read_from_pbmsg(temp_facadesoulachievement_list);
	}
}

}