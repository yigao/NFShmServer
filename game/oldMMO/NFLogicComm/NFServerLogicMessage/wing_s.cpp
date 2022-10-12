#include "wing_s.h"

namespace proto_ff_s {

wingwingattributeDesc_s::wingwingattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int wingwingattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int wingwingattributeDesc_s::ResumeInit() {
	return 0;
}

void wingwingattributeDesc_s::write_to_pbmsg(::proto_ff::wingwingattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void wingwingattributeDesc_s::read_from_pbmsg(const ::proto_ff::wingwingattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct wingwingattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

wingwing_s::wingwing_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int wingwing_s::CreateInit() {
	id = (int64_t)0;
	realLevel = (int32_t)0;
	materialID = (int64_t)0;
	materialEXP = (int32_t)0;
	exp = (int32_t)0;
	skillID = (int64_t)0;
	BreakMaterialID = (int64_t)0;
	BreakMaterialCost = (int32_t)0;
	return 0;
}

int wingwing_s::ResumeInit() {
	return 0;
}

void wingwing_s::write_to_pbmsg(::proto_ff::wingwing & msg) const {
	msg.set_id((int64_t)id);
	msg.set_resource((const char*)resource.Get());
	msg.set_name((const char*)name.Get());
	msg.set_activedesc((const char*)activeDesc.Get());
	msg.set_reallevel((int32_t)realLevel);
	msg.set_materialid((int64_t)materialID);
	msg.set_materialexp((int32_t)materialEXP);
	msg.set_exp((int32_t)exp);
	msg.set_skillid((int64_t)skillID);
	msg.set_breakmaterialid((int64_t)BreakMaterialID);
	msg.set_breakmaterialcost((int32_t)BreakMaterialCost);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::wingwingattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
	for(int32_t i = 0; i < (int32_t)fragmentID.GetSize() && i < fragmentID.GetMaxSize(); ++i) {
		msg.add_fragmentid((int64_t)fragmentID[i]);
	}
}

void wingwing_s::read_from_pbmsg(const ::proto_ff::wingwing & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct wingwing_s));
	id = msg.id();
	resource.Copy(msg.resource());
	name.Copy(msg.name());
	activeDesc.Copy(msg.activedesc());
	realLevel = msg.reallevel();
	materialID = msg.materialid();
	materialEXP = msg.materialexp();
	exp = msg.exp();
	skillID = msg.skillid();
	BreakMaterialID = msg.breakmaterialid();
	BreakMaterialCost = msg.breakmaterialcost();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::wingwingattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
	fragmentID.SetSize(msg.fragmentid_size() > fragmentID.GetMaxSize() ? fragmentID.GetMaxSize() : msg.fragmentid_size());
	for(int32_t i = 0; i < (int32_t)fragmentID.GetSize(); ++i) {
		fragmentID[i] = msg.fragmentid(i);
	}
}

Sheet_wingwing_s::Sheet_wingwing_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_wingwing_s::CreateInit() {
	return 0;
}

int Sheet_wingwing_s::ResumeInit() {
	return 0;
}

void Sheet_wingwing_s::write_to_pbmsg(::proto_ff::Sheet_wingwing & msg) const {
	for(int32_t i = 0; i < (int32_t)wingwing_List.GetSize() && i < wingwing_List.GetMaxSize(); ++i) {
		::proto_ff::wingwing* temp_wingwing_list = msg.add_wingwing_list();
		wingwing_List[i].write_to_pbmsg(*temp_wingwing_list);
	}
}

void Sheet_wingwing_s::read_from_pbmsg(const ::proto_ff::Sheet_wingwing & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_wingwing_s));
	wingwing_List.SetSize(msg.wingwing_list_size() > wingwing_List.GetMaxSize() ? wingwing_List.GetMaxSize() : msg.wingwing_list_size());
	for(int32_t i = 0; i < (int32_t)wingwing_List.GetSize(); ++i) {
		const ::proto_ff::wingwing & temp_wingwing_list = msg.wingwing_list(i);
		wingwing_List[i].read_from_pbmsg(temp_wingwing_list);
	}
}

wingchangeattributeDesc_s::wingchangeattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int wingchangeattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int wingchangeattributeDesc_s::ResumeInit() {
	return 0;
}

void wingchangeattributeDesc_s::write_to_pbmsg(::proto_ff::wingchangeattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void wingchangeattributeDesc_s::read_from_pbmsg(const ::proto_ff::wingchangeattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct wingchangeattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

wingchange_s::wingchange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int wingchange_s::CreateInit() {
	id = (int64_t)0;
	quality = (int32_t)0;
	starId = (int64_t)0;
	starUp = (int32_t)0;
	starBer = (int32_t)0;
	upAttributeId = (int64_t)0;
	return 0;
}

int wingchange_s::ResumeInit() {
	return 0;
}

void wingchange_s::write_to_pbmsg(::proto_ff::wingchange & msg) const {
	msg.set_id((int64_t)id);
	msg.set_resource((const char*)resource.Get());
	msg.set_name((const char*)name.Get());
	msg.set_activedesc((const char*)activeDesc.Get());
	msg.set_quality((int32_t)quality);
	msg.set_starid((int64_t)starId);
	msg.set_starnum((const char*)starNum.Get());
	msg.set_starup((int32_t)starUp);
	msg.set_starber((int32_t)starBer);
	msg.set_upattributeid((int64_t)upAttributeId);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::wingchangeattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void wingchange_s::read_from_pbmsg(const ::proto_ff::wingchange & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct wingchange_s));
	id = msg.id();
	resource.Copy(msg.resource());
	name.Copy(msg.name());
	activeDesc.Copy(msg.activedesc());
	quality = msg.quality();
	starId = msg.starid();
	starNum.Copy(msg.starnum());
	starUp = msg.starup();
	starBer = msg.starber();
	upAttributeId = msg.upattributeid();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::wingchangeattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_wingchange_s::Sheet_wingchange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_wingchange_s::CreateInit() {
	return 0;
}

int Sheet_wingchange_s::ResumeInit() {
	return 0;
}

void Sheet_wingchange_s::write_to_pbmsg(::proto_ff::Sheet_wingchange & msg) const {
	for(int32_t i = 0; i < (int32_t)wingchange_List.GetSize() && i < wingchange_List.GetMaxSize(); ++i) {
		::proto_ff::wingchange* temp_wingchange_list = msg.add_wingchange_list();
		wingchange_List[i].write_to_pbmsg(*temp_wingchange_list);
	}
}

void Sheet_wingchange_s::read_from_pbmsg(const ::proto_ff::Sheet_wingchange & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_wingchange_s));
	wingchange_List.SetSize(msg.wingchange_list_size() > wingchange_List.GetMaxSize() ? wingchange_List.GetMaxSize() : msg.wingchange_list_size());
	for(int32_t i = 0; i < (int32_t)wingchange_List.GetSize(); ++i) {
		const ::proto_ff::wingchange & temp_wingchange_list = msg.wingchange_list(i);
		wingchange_List[i].read_from_pbmsg(temp_wingchange_list);
	}
}

wingfragmentattributeDesc_s::wingfragmentattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int wingfragmentattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int wingfragmentattributeDesc_s::ResumeInit() {
	return 0;
}

void wingfragmentattributeDesc_s::write_to_pbmsg(::proto_ff::wingfragmentattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void wingfragmentattributeDesc_s::read_from_pbmsg(const ::proto_ff::wingfragmentattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct wingfragmentattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

wingfragment_s::wingfragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int wingfragment_s::CreateInit() {
	fragmentID = (int64_t)0;
	item = (int64_t)0;
	itemNum = (int32_t)0;
	return 0;
}

int wingfragment_s::ResumeInit() {
	return 0;
}

void wingfragment_s::write_to_pbmsg(::proto_ff::wingfragment & msg) const {
	msg.set_fragmentid((int64_t)fragmentID);
	msg.set_item((int64_t)item);
	msg.set_itemnum((int32_t)itemNum);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::wingfragmentattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void wingfragment_s::read_from_pbmsg(const ::proto_ff::wingfragment & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct wingfragment_s));
	fragmentID = msg.fragmentid();
	item = msg.item();
	itemNum = msg.itemnum();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::wingfragmentattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_wingfragment_s::Sheet_wingfragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_wingfragment_s::CreateInit() {
	return 0;
}

int Sheet_wingfragment_s::ResumeInit() {
	return 0;
}

void Sheet_wingfragment_s::write_to_pbmsg(::proto_ff::Sheet_wingfragment & msg) const {
	for(int32_t i = 0; i < (int32_t)wingfragment_List.GetSize() && i < wingfragment_List.GetMaxSize(); ++i) {
		::proto_ff::wingfragment* temp_wingfragment_list = msg.add_wingfragment_list();
		wingfragment_List[i].write_to_pbmsg(*temp_wingfragment_list);
	}
}

void Sheet_wingfragment_s::read_from_pbmsg(const ::proto_ff::Sheet_wingfragment & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_wingfragment_s));
	wingfragment_List.SetSize(msg.wingfragment_list_size() > wingfragment_List.GetMaxSize() ? wingfragment_List.GetMaxSize() : msg.wingfragment_list_size());
	for(int32_t i = 0; i < (int32_t)wingfragment_List.GetSize(); ++i) {
		const ::proto_ff::wingfragment & temp_wingfragment_list = msg.wingfragment_list(i);
		wingfragment_List[i].read_from_pbmsg(temp_wingfragment_list);
	}
}

wingstarUpupAttributeDesc_s::wingstarUpupAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int wingstarUpupAttributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int wingstarUpupAttributeDesc_s::ResumeInit() {
	return 0;
}

void wingstarUpupAttributeDesc_s::write_to_pbmsg(::proto_ff::wingstarUpupAttributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void wingstarUpupAttributeDesc_s::read_from_pbmsg(const ::proto_ff::wingstarUpupAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct wingstarUpupAttributeDesc_s));
	type = msg.type();
	value = msg.value();
}

wingstarUp_s::wingstarUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int wingstarUp_s::CreateInit() {
	ID = (int32_t)0;
	upAttributeId = (int64_t)0;
	starID = (int32_t)0;
	return 0;
}

int wingstarUp_s::ResumeInit() {
	return 0;
}

void wingstarUp_s::write_to_pbmsg(::proto_ff::wingstarUp & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_upattributeid((int64_t)upAttributeId);
	msg.set_starid((int32_t)starID);
	for(int32_t i = 0; i < (int32_t)upAttribute.GetSize() && i < upAttribute.GetMaxSize(); ++i) {
		::proto_ff::wingstarUpupAttributeDesc* temp_upattribute = msg.add_upattribute();
		upAttribute[i].write_to_pbmsg(*temp_upattribute);
	}
}

void wingstarUp_s::read_from_pbmsg(const ::proto_ff::wingstarUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct wingstarUp_s));
	ID = msg.id();
	upAttributeId = msg.upattributeid();
	starID = msg.starid();
	upAttribute.SetSize(msg.upattribute_size() > upAttribute.GetMaxSize() ? upAttribute.GetMaxSize() : msg.upattribute_size());
	for(int32_t i = 0; i < (int32_t)upAttribute.GetSize(); ++i) {
		const ::proto_ff::wingstarUpupAttributeDesc & temp_upattribute = msg.upattribute(i);
		upAttribute[i].read_from_pbmsg(temp_upattribute);
	}
}

Sheet_wingstarUp_s::Sheet_wingstarUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_wingstarUp_s::CreateInit() {
	return 0;
}

int Sheet_wingstarUp_s::ResumeInit() {
	return 0;
}

void Sheet_wingstarUp_s::write_to_pbmsg(::proto_ff::Sheet_wingstarUp & msg) const {
	for(int32_t i = 0; i < (int32_t)wingstarUp_List.GetSize() && i < wingstarUp_List.GetMaxSize(); ++i) {
		::proto_ff::wingstarUp* temp_wingstarup_list = msg.add_wingstarup_list();
		wingstarUp_List[i].write_to_pbmsg(*temp_wingstarup_list);
	}
}

void Sheet_wingstarUp_s::read_from_pbmsg(const ::proto_ff::Sheet_wingstarUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_wingstarUp_s));
	wingstarUp_List.SetSize(msg.wingstarup_list_size() > wingstarUp_List.GetMaxSize() ? wingstarUp_List.GetMaxSize() : msg.wingstarup_list_size());
	for(int32_t i = 0; i < (int32_t)wingstarUp_List.GetSize(); ++i) {
		const ::proto_ff::wingstarUp & temp_wingstarup_list = msg.wingstarup_list(i);
		wingstarUp_List[i].read_from_pbmsg(temp_wingstarup_list);
	}
}

}