#include "field_s.h"

namespace proto_ff_s {

fieldfieldfieldDesc_s::fieldfieldfieldDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int fieldfieldfieldDesc_s::CreateInit() {
	att = (int32_t)0;
	num = (int32_t)0;
	return 0;
}

int fieldfieldfieldDesc_s::ResumeInit() {
	return 0;
}

void fieldfieldfieldDesc_s::write_to_pbmsg(::proto_ff::fieldfieldfieldDesc & msg) const {
	msg.set_att((int32_t)att);
	msg.set_num((int32_t)num);
}

void fieldfieldfieldDesc_s::read_from_pbmsg(const ::proto_ff::fieldfieldfieldDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct fieldfieldfieldDesc_s));
	att = msg.att();
	num = msg.num();
}

fieldfield_s::fieldfield_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int fieldfield_s::CreateInit() {
	id = (int64_t)0;
	quality = (int32_t)0;
	return 0;
}

int fieldfield_s::ResumeInit() {
	return 0;
}

void fieldfield_s::write_to_pbmsg(::proto_ff::fieldfield & msg) const {
	msg.set_id((int64_t)id);
	msg.set_name((const char*)name.Get());
	msg.set_quality((int32_t)quality);
	for(int32_t i = 0; i < (int32_t)field.GetSize() && i < field.GetMaxSize(); ++i) {
		::proto_ff::fieldfieldfieldDesc* temp_field = msg.add_field();
		field[i].write_to_pbmsg(*temp_field);
	}
		msg.add_skill((int64_t)skill[i]);
	}
		msg.add_num((int32_t)num[i]);
	}
		msg.add_pos((int32_t)pos[i]);
	}
}

void fieldfield_s::read_from_pbmsg(const ::proto_ff::fieldfield & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct fieldfield_s));
	id = msg.id();
	name.Copy(msg.name());
	quality = msg.quality();
	field.SetSize(msg.field_size() > field.GetMaxSize() ? field.GetMaxSize() : msg.field_size());
	for(int32_t i = 0; i < (int32_t)field.GetSize(); ++i) {
		const ::proto_ff::fieldfieldfieldDesc & temp_field = msg.field(i);
		field[i].read_from_pbmsg(temp_field);
	}
		skill[i] = msg.skill(i);
	}
		num[i] = msg.num(i);
	}
		pos[i] = msg.pos(i);
	}
}

Sheet_fieldfield_s::Sheet_fieldfield_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_fieldfield_s::CreateInit() {
	return 0;
}

int Sheet_fieldfield_s::ResumeInit() {
	return 0;
}

void Sheet_fieldfield_s::write_to_pbmsg(::proto_ff::Sheet_fieldfield & msg) const {
	for(int32_t i = 0; i < (int32_t)fieldfield_List.GetSize() && i < fieldfield_List.GetMaxSize(); ++i) {
		::proto_ff::fieldfield* temp_fieldfield_list = msg.add_fieldfield_list();
		fieldfield_List[i].write_to_pbmsg(*temp_fieldfield_list);
	}
}

void Sheet_fieldfield_s::read_from_pbmsg(const ::proto_ff::Sheet_fieldfield & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_fieldfield_s));
	fieldfield_List.SetSize(msg.fieldfield_list_size() > fieldfield_List.GetMaxSize() ? fieldfield_List.GetMaxSize() : msg.fieldfield_list_size());
	for(int32_t i = 0; i < (int32_t)fieldfield_List.GetSize(); ++i) {
		const ::proto_ff::fieldfield & temp_fieldfield_list = msg.fieldfield_list(i);
		fieldfield_List[i].read_from_pbmsg(temp_fieldfield_list);
	}
}

fieldreikirefineDesc_s::fieldreikirefineDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int fieldreikirefineDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int64_t)0;
	return 0;
}

int fieldreikirefineDesc_s::ResumeInit() {
	return 0;
}

void fieldreikirefineDesc_s::write_to_pbmsg(::proto_ff::fieldreikirefineDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int64_t)value);
}

void fieldreikirefineDesc_s::read_from_pbmsg(const ::proto_ff::fieldreikirefineDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct fieldreikirefineDesc_s));
	type = msg.type();
	value = msg.value();
}

fieldreiki_s::fieldreiki_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int fieldreiki_s::CreateInit() {
	id = (int64_t)0;
	quality = (int32_t)0;
	field = (int32_t)0;
	Lv = (int32_t)0;
	star = (int32_t)0;
	blueStarNum = (int32_t)0;
	exp = (int32_t)0;
	link = (int64_t)0;
	return 0;
}

int fieldreiki_s::ResumeInit() {
	return 0;
}

void fieldreiki_s::write_to_pbmsg(::proto_ff::fieldreiki & msg) const {
	msg.set_id((int64_t)id);
	msg.set_name((const char*)name.Get());
	msg.set_quality((int32_t)quality);
	msg.set_field((int32_t)field);
	msg.set_lv((int32_t)Lv);
	msg.set_star((int32_t)star);
	msg.set_refineattribute((const char*)refineAttribute.Get());
	msg.set_refineattributevalue((const char*)refineAttributeValue.Get());
	msg.set_bluestarnum((int32_t)blueStarNum);
	msg.set_bluestar_type((const char*)blueStar_type.Get());
	msg.set_bluestar_value((const char*)blueStar_value.Get());
	msg.set_exp((int32_t)exp);
	msg.set_link((int64_t)link);
	for(int32_t i = 0; i < (int32_t)refine.GetSize() && i < refine.GetMaxSize(); ++i) {
		::proto_ff::fieldreikirefineDesc* temp_refine = msg.add_refine();
		refine[i].write_to_pbmsg(*temp_refine);
	}
}

void fieldreiki_s::read_from_pbmsg(const ::proto_ff::fieldreiki & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct fieldreiki_s));
	id = msg.id();
	name.Copy(msg.name());
	quality = msg.quality();
	field = msg.field();
	Lv = msg.lv();
	star = msg.star();
	refineAttribute.Copy(msg.refineattribute());
	refineAttributeValue.Copy(msg.refineattributevalue());
	blueStarNum = msg.bluestarnum();
	blueStar_type.Copy(msg.bluestar_type());
	blueStar_value.Copy(msg.bluestar_value());
	exp = msg.exp();
	link = msg.link();
	refine.SetSize(msg.refine_size() > refine.GetMaxSize() ? refine.GetMaxSize() : msg.refine_size());
	for(int32_t i = 0; i < (int32_t)refine.GetSize(); ++i) {
		const ::proto_ff::fieldreikirefineDesc & temp_refine = msg.refine(i);
		refine[i].read_from_pbmsg(temp_refine);
	}
}

Sheet_fieldreiki_s::Sheet_fieldreiki_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_fieldreiki_s::CreateInit() {
	return 0;
}

int Sheet_fieldreiki_s::ResumeInit() {
	return 0;
}

void Sheet_fieldreiki_s::write_to_pbmsg(::proto_ff::Sheet_fieldreiki & msg) const {
	for(int32_t i = 0; i < (int32_t)fieldreiki_List.GetSize() && i < fieldreiki_List.GetMaxSize(); ++i) {
		::proto_ff::fieldreiki* temp_fieldreiki_list = msg.add_fieldreiki_list();
		fieldreiki_List[i].write_to_pbmsg(*temp_fieldreiki_list);
	}
}

void Sheet_fieldreiki_s::read_from_pbmsg(const ::proto_ff::Sheet_fieldreiki & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_fieldreiki_s));
	fieldreiki_List.SetSize(msg.fieldreiki_list_size() > fieldreiki_List.GetMaxSize() ? fieldreiki_List.GetMaxSize() : msg.fieldreiki_list_size());
	for(int32_t i = 0; i < (int32_t)fieldreiki_List.GetSize(); ++i) {
		const ::proto_ff::fieldreiki & temp_fieldreiki_list = msg.fieldreiki_list(i);
		fieldreiki_List[i].read_from_pbmsg(temp_fieldreiki_list);
	}
}

fieldexp_s::fieldexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int fieldexp_s::CreateInit() {
	lv = (int32_t)0;
	exp = (int32_t)0;
	return 0;
}

int fieldexp_s::ResumeInit() {
	return 0;
}

void fieldexp_s::write_to_pbmsg(::proto_ff::fieldexp & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_exp((int32_t)exp);
}

void fieldexp_s::read_from_pbmsg(const ::proto_ff::fieldexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct fieldexp_s));
	lv = msg.lv();
	exp = msg.exp();
}

Sheet_fieldexp_s::Sheet_fieldexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_fieldexp_s::CreateInit() {
	return 0;
}

int Sheet_fieldexp_s::ResumeInit() {
	return 0;
}

void Sheet_fieldexp_s::write_to_pbmsg(::proto_ff::Sheet_fieldexp & msg) const {
	for(int32_t i = 0; i < (int32_t)fieldexp_List.GetSize() && i < fieldexp_List.GetMaxSize(); ++i) {
		::proto_ff::fieldexp* temp_fieldexp_list = msg.add_fieldexp_list();
		fieldexp_List[i].write_to_pbmsg(*temp_fieldexp_list);
	}
}

void Sheet_fieldexp_s::read_from_pbmsg(const ::proto_ff::Sheet_fieldexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_fieldexp_s));
	fieldexp_List.SetSize(msg.fieldexp_list_size() > fieldexp_List.GetMaxSize() ? fieldexp_List.GetMaxSize() : msg.fieldexp_list_size());
	for(int32_t i = 0; i < (int32_t)fieldexp_List.GetSize(); ++i) {
		const ::proto_ff::fieldexp & temp_fieldexp_list = msg.fieldexp_list(i);
		fieldexp_List[i].read_from_pbmsg(temp_fieldexp_list);
	}
}

fieldvalue_s::fieldvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int fieldvalue_s::CreateInit() {
	id = (int64_t)0;
	return 0;
}

int fieldvalue_s::ResumeInit() {
	return 0;
}

void fieldvalue_s::write_to_pbmsg(::proto_ff::fieldvalue & msg) const {
	msg.set_id((int64_t)id);
		msg.add_lvvalue((int32_t)lvValue[i]);
	}
}

void fieldvalue_s::read_from_pbmsg(const ::proto_ff::fieldvalue & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct fieldvalue_s));
	id = msg.id();
		lvValue[i] = msg.lvvalue(i);
	}
}

Sheet_fieldvalue_s::Sheet_fieldvalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_fieldvalue_s::CreateInit() {
	return 0;
}

int Sheet_fieldvalue_s::ResumeInit() {
	return 0;
}

void Sheet_fieldvalue_s::write_to_pbmsg(::proto_ff::Sheet_fieldvalue & msg) const {
	for(int32_t i = 0; i < (int32_t)fieldvalue_List.GetSize() && i < fieldvalue_List.GetMaxSize(); ++i) {
		::proto_ff::fieldvalue* temp_fieldvalue_list = msg.add_fieldvalue_list();
		fieldvalue_List[i].write_to_pbmsg(*temp_fieldvalue_list);
	}
}

void Sheet_fieldvalue_s::read_from_pbmsg(const ::proto_ff::Sheet_fieldvalue & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_fieldvalue_s));
	fieldvalue_List.SetSize(msg.fieldvalue_list_size() > fieldvalue_List.GetMaxSize() ? fieldvalue_List.GetMaxSize() : msg.fieldvalue_list_size());
	for(int32_t i = 0; i < (int32_t)fieldvalue_List.GetSize(); ++i) {
		const ::proto_ff::fieldvalue & temp_fieldvalue_list = msg.fieldvalue_list(i);
		fieldvalue_List[i].read_from_pbmsg(temp_fieldvalue_list);
	}
}

fieldexpand_s::fieldexpand_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int fieldexpand_s::CreateInit() {
	number = (int32_t)0;
	lv = (int32_t)0;
	id = (int64_t)0;
	num = (int32_t)0;
	return 0;
}

int fieldexpand_s::ResumeInit() {
	return 0;
}

void fieldexpand_s::write_to_pbmsg(::proto_ff::fieldexpand & msg) const {
	msg.set_number((int32_t)number);
	msg.set_lv((int32_t)lv);
	msg.set_id((int64_t)id);
	msg.set_num((int32_t)num);
}

void fieldexpand_s::read_from_pbmsg(const ::proto_ff::fieldexpand & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct fieldexpand_s));
	number = msg.number();
	lv = msg.lv();
	id = msg.id();
	num = msg.num();
}

Sheet_fieldexpand_s::Sheet_fieldexpand_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_fieldexpand_s::CreateInit() {
	return 0;
}

int Sheet_fieldexpand_s::ResumeInit() {
	return 0;
}

void Sheet_fieldexpand_s::write_to_pbmsg(::proto_ff::Sheet_fieldexpand & msg) const {
	for(int32_t i = 0; i < (int32_t)fieldexpand_List.GetSize() && i < fieldexpand_List.GetMaxSize(); ++i) {
		::proto_ff::fieldexpand* temp_fieldexpand_list = msg.add_fieldexpand_list();
		fieldexpand_List[i].write_to_pbmsg(*temp_fieldexpand_list);
	}
}

void Sheet_fieldexpand_s::read_from_pbmsg(const ::proto_ff::Sheet_fieldexpand & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_fieldexpand_s));
	fieldexpand_List.SetSize(msg.fieldexpand_list_size() > fieldexpand_List.GetMaxSize() ? fieldexpand_List.GetMaxSize() : msg.fieldexpand_list_size());
	for(int32_t i = 0; i < (int32_t)fieldexpand_List.GetSize(); ++i) {
		const ::proto_ff::fieldexpand & temp_fieldexpand_list = msg.fieldexpand_list(i);
		fieldexpand_List[i].read_from_pbmsg(temp_fieldexpand_list);
	}
}

fieldstong_s::fieldstong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int fieldstong_s::CreateInit() {
	id = (int64_t)0;
	stongId = (int64_t)0;
	fenJieId = (int64_t)0;
	fenJieNum = (int32_t)0;
	return 0;
}

int fieldstong_s::ResumeInit() {
	return 0;
}

void fieldstong_s::write_to_pbmsg(::proto_ff::fieldstong & msg) const {
	msg.set_id((int64_t)id);
	msg.set_stongid((int64_t)stongId);
	msg.set_fenjieid((int64_t)fenJieId);
	msg.set_fenjienum((int32_t)fenJieNum);
}

void fieldstong_s::read_from_pbmsg(const ::proto_ff::fieldstong & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct fieldstong_s));
	id = msg.id();
	stongId = msg.stongid();
	fenJieId = msg.fenjieid();
	fenJieNum = msg.fenjienum();
}

Sheet_fieldstong_s::Sheet_fieldstong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_fieldstong_s::CreateInit() {
	return 0;
}

int Sheet_fieldstong_s::ResumeInit() {
	return 0;
}

void Sheet_fieldstong_s::write_to_pbmsg(::proto_ff::Sheet_fieldstong & msg) const {
	for(int32_t i = 0; i < (int32_t)fieldstong_List.GetSize() && i < fieldstong_List.GetMaxSize(); ++i) {
		::proto_ff::fieldstong* temp_fieldstong_list = msg.add_fieldstong_list();
		fieldstong_List[i].write_to_pbmsg(*temp_fieldstong_list);
	}
}

void Sheet_fieldstong_s::read_from_pbmsg(const ::proto_ff::Sheet_fieldstong & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_fieldstong_s));
	fieldstong_List.SetSize(msg.fieldstong_list_size() > fieldstong_List.GetMaxSize() ? fieldstong_List.GetMaxSize() : msg.fieldstong_list_size());
	for(int32_t i = 0; i < (int32_t)fieldstong_List.GetSize(); ++i) {
		const ::proto_ff::fieldstong & temp_fieldstong_list = msg.fieldstong_list(i);
		fieldstong_List[i].read_from_pbmsg(temp_fieldstong_list);
	}
}

}