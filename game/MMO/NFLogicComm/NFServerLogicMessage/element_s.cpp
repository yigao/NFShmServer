#include "element_s.h"

namespace proto_ff_s {

elementelement_s::elementelement_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int elementelement_s::CreateInit() {
	ID = (int64_t)0;
	type = (int32_t)0;
	level = (int32_t)0;
	exp = (int32_t)0;
	skillID = (int64_t)0;
	return 0;
}

int elementelement_s::ResumeInit() {
	return 0;
}

void elementelement_s::write_to_pbmsg(::proto_ff::elementelement & msg) const {
	msg.set_id((int64_t)ID);
	msg.set_resource((const char*)resource.Get());
	msg.set_type((int32_t)type);
	msg.set_level((int32_t)level);
	msg.set_exp((int32_t)exp);
	msg.set_skillid((int64_t)skillID);
	for(int32_t i = 0; i < (int32_t)attribute_type.GetSize() && i < attribute_type.GetMaxSize(); ++i) {
		msg.add_attribute_type((int32_t)attribute_type[i]);
	}
	for(int32_t i = 0; i < (int32_t)material_exp.GetSize() && i < material_exp.GetMaxSize(); ++i) {
		msg.add_material_exp((int32_t)material_exp[i]);
	}
	for(int32_t i = 0; i < (int32_t)fragmentID.GetSize() && i < fragmentID.GetMaxSize(); ++i) {
		msg.add_fragmentid((int64_t)fragmentID[i]);
	}
	for(int32_t i = 0; i < (int32_t)material_id.GetSize() && i < material_id.GetMaxSize(); ++i) {
		msg.add_material_id((int64_t)material_id[i]);
	}
	for(int32_t i = 0; i < (int32_t)attribute_value.GetSize() && i < attribute_value.GetMaxSize(); ++i) {
		msg.add_attribute_value((int32_t)attribute_value[i]);
	}
}

void elementelement_s::read_from_pbmsg(const ::proto_ff::elementelement & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct elementelement_s));
	ID = msg.id();
	resource.Copy(msg.resource());
	type = msg.type();
	level = msg.level();
	exp = msg.exp();
	skillID = msg.skillid();
	attribute_type.SetSize(msg.attribute_type_size() > attribute_type.GetMaxSize() ? attribute_type.GetMaxSize() : msg.attribute_type_size());
	for(int32_t i = 0; i < (int32_t)attribute_type.GetSize(); ++i) {
		attribute_type[i] = msg.attribute_type(i);
	}
	material_exp.SetSize(msg.material_exp_size() > material_exp.GetMaxSize() ? material_exp.GetMaxSize() : msg.material_exp_size());
	for(int32_t i = 0; i < (int32_t)material_exp.GetSize(); ++i) {
		material_exp[i] = msg.material_exp(i);
	}
	fragmentID.SetSize(msg.fragmentid_size() > fragmentID.GetMaxSize() ? fragmentID.GetMaxSize() : msg.fragmentid_size());
	for(int32_t i = 0; i < (int32_t)fragmentID.GetSize(); ++i) {
		fragmentID[i] = msg.fragmentid(i);
	}
	material_id.SetSize(msg.material_id_size() > material_id.GetMaxSize() ? material_id.GetMaxSize() : msg.material_id_size());
	for(int32_t i = 0; i < (int32_t)material_id.GetSize(); ++i) {
		material_id[i] = msg.material_id(i);
	}
	attribute_value.SetSize(msg.attribute_value_size() > attribute_value.GetMaxSize() ? attribute_value.GetMaxSize() : msg.attribute_value_size());
	for(int32_t i = 0; i < (int32_t)attribute_value.GetSize(); ++i) {
		attribute_value[i] = msg.attribute_value(i);
	}
}

Sheet_elementelement_s::Sheet_elementelement_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_elementelement_s::CreateInit() {
	return 0;
}

int Sheet_elementelement_s::ResumeInit() {
	return 0;
}

void Sheet_elementelement_s::write_to_pbmsg(::proto_ff::Sheet_elementelement & msg) const {
	for(int32_t i = 0; i < (int32_t)elementelement_List.GetSize() && i < elementelement_List.GetMaxSize(); ++i) {
		::proto_ff::elementelement* temp_elementelement_list = msg.add_elementelement_list();
		elementelement_List[i].write_to_pbmsg(*temp_elementelement_list);
	}
}

void Sheet_elementelement_s::read_from_pbmsg(const ::proto_ff::Sheet_elementelement & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_elementelement_s));
	elementelement_List.SetSize(msg.elementelement_list_size() > elementelement_List.GetMaxSize() ? elementelement_List.GetMaxSize() : msg.elementelement_list_size());
	for(int32_t i = 0; i < (int32_t)elementelement_List.GetSize(); ++i) {
		const ::proto_ff::elementelement & temp_elementelement_list = msg.elementelement_list(i);
		elementelement_List[i].read_from_pbmsg(temp_elementelement_list);
	}
}

elementfragment_s::elementfragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int elementfragment_s::CreateInit() {
	ID = (int64_t)0;
	itemID = (int64_t)0;
	itemNum = (int32_t)0;
	return 0;
}

int elementfragment_s::ResumeInit() {
	return 0;
}

void elementfragment_s::write_to_pbmsg(::proto_ff::elementfragment & msg) const {
	msg.set_id((int64_t)ID);
	msg.set_itemid((int64_t)itemID);
	msg.set_itemnum((int32_t)itemNum);
	for(int32_t i = 0; i < (int32_t)attribute_type.GetSize() && i < attribute_type.GetMaxSize(); ++i) {
		msg.add_attribute_type((int32_t)attribute_type[i]);
	}
	for(int32_t i = 0; i < (int32_t)attribute_value.GetSize() && i < attribute_value.GetMaxSize(); ++i) {
		msg.add_attribute_value((int32_t)attribute_value[i]);
	}
}

void elementfragment_s::read_from_pbmsg(const ::proto_ff::elementfragment & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct elementfragment_s));
	ID = msg.id();
	itemID = msg.itemid();
	itemNum = msg.itemnum();
	attribute_type.SetSize(msg.attribute_type_size() > attribute_type.GetMaxSize() ? attribute_type.GetMaxSize() : msg.attribute_type_size());
	for(int32_t i = 0; i < (int32_t)attribute_type.GetSize(); ++i) {
		attribute_type[i] = msg.attribute_type(i);
	}
	attribute_value.SetSize(msg.attribute_value_size() > attribute_value.GetMaxSize() ? attribute_value.GetMaxSize() : msg.attribute_value_size());
	for(int32_t i = 0; i < (int32_t)attribute_value.GetSize(); ++i) {
		attribute_value[i] = msg.attribute_value(i);
	}
}

Sheet_elementfragment_s::Sheet_elementfragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_elementfragment_s::CreateInit() {
	return 0;
}

int Sheet_elementfragment_s::ResumeInit() {
	return 0;
}

void Sheet_elementfragment_s::write_to_pbmsg(::proto_ff::Sheet_elementfragment & msg) const {
	for(int32_t i = 0; i < (int32_t)elementfragment_List.GetSize() && i < elementfragment_List.GetMaxSize(); ++i) {
		::proto_ff::elementfragment* temp_elementfragment_list = msg.add_elementfragment_list();
		elementfragment_List[i].write_to_pbmsg(*temp_elementfragment_list);
	}
}

void Sheet_elementfragment_s::read_from_pbmsg(const ::proto_ff::Sheet_elementfragment & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_elementfragment_s));
	elementfragment_List.SetSize(msg.elementfragment_list_size() > elementfragment_List.GetMaxSize() ? elementfragment_List.GetMaxSize() : msg.elementfragment_list_size());
	for(int32_t i = 0; i < (int32_t)elementfragment_List.GetSize(); ++i) {
		const ::proto_ff::elementfragment & temp_elementfragment_list = msg.elementfragment_list(i);
		elementfragment_List[i].read_from_pbmsg(temp_elementfragment_list);
	}
}

elementelementUI_s::elementelementUI_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int elementelementUI_s::CreateInit() {
	type = (int32_t)0;
	return 0;
}

int elementelementUI_s::ResumeInit() {
	return 0;
}

void elementelementUI_s::write_to_pbmsg(::proto_ff::elementelementUI & msg) const {
	msg.set_type((int32_t)type);
	msg.set_name((const char*)name.Get());
}

void elementelementUI_s::read_from_pbmsg(const ::proto_ff::elementelementUI & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct elementelementUI_s));
	type = msg.type();
	name.Copy(msg.name());
}

Sheet_elementelementUI_s::Sheet_elementelementUI_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_elementelementUI_s::CreateInit() {
	return 0;
}

int Sheet_elementelementUI_s::ResumeInit() {
	return 0;
}

void Sheet_elementelementUI_s::write_to_pbmsg(::proto_ff::Sheet_elementelementUI & msg) const {
	for(int32_t i = 0; i < (int32_t)elementelementUI_List.GetSize() && i < elementelementUI_List.GetMaxSize(); ++i) {
		::proto_ff::elementelementUI* temp_elementelementui_list = msg.add_elementelementui_list();
		elementelementUI_List[i].write_to_pbmsg(*temp_elementelementui_list);
	}
}

void Sheet_elementelementUI_s::read_from_pbmsg(const ::proto_ff::Sheet_elementelementUI & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_elementelementUI_s));
	elementelementUI_List.SetSize(msg.elementelementui_list_size() > elementelementUI_List.GetMaxSize() ? elementelementUI_List.GetMaxSize() : msg.elementelementui_list_size());
	for(int32_t i = 0; i < (int32_t)elementelementUI_List.GetSize(); ++i) {
		const ::proto_ff::elementelementUI & temp_elementelementui_list = msg.elementelementui_list(i);
		elementelementUI_List[i].read_from_pbmsg(temp_elementelementui_list);
	}
}

}