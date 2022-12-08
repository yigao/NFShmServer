#include "taskreward_s.h"

namespace proto_ff_s {

taskrewardtaskrewarditemDesc_s::taskrewardtaskrewarditemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int taskrewardtaskrewarditemDesc_s::CreateInit() {
	bind = (int32_t)0;
	id = (int64_t)0;
	val = (int32_t)0;
	prof = (int32_t)0;
	return 0;
}

int taskrewardtaskrewarditemDesc_s::ResumeInit() {
	return 0;
}

void taskrewardtaskrewarditemDesc_s::write_to_pbmsg(::proto_ff::taskrewardtaskrewarditemDesc & msg) const {
	msg.set_bind((int32_t)bind);
	msg.set_id((int64_t)id);
	msg.set_val((int32_t)val);
	msg.set_prof((int32_t)prof);
}

void taskrewardtaskrewarditemDesc_s::read_from_pbmsg(const ::proto_ff::taskrewardtaskrewarditemDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct taskrewardtaskrewarditemDesc_s));
	bind = msg.bind();
	id = msg.id();
	val = msg.val();
	prof = msg.prof();
}

taskrewardtaskrewardattrDesc_s::taskrewardtaskrewardattrDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int taskrewardtaskrewardattrDesc_s::CreateInit() {
	id = (int64_t)0;
	val = (int64_t)0;
	return 0;
}

int taskrewardtaskrewardattrDesc_s::ResumeInit() {
	return 0;
}

void taskrewardtaskrewardattrDesc_s::write_to_pbmsg(::proto_ff::taskrewardtaskrewardattrDesc & msg) const {
	msg.set_id((int64_t)id);
	msg.set_val((int64_t)val);
}

void taskrewardtaskrewardattrDesc_s::read_from_pbmsg(const ::proto_ff::taskrewardtaskrewardattrDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct taskrewardtaskrewardattrDesc_s));
	id = msg.id();
	val = msg.val();
}

taskrewardtaskreward_s::taskrewardtaskreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int taskrewardtaskreward_s::CreateInit() {
	id = (int64_t)0;
	taskType = (int32_t)0;
	lv = (int32_t)0;
	guildExp = (int32_t)0;
	guildPoint = (int32_t)0;
	skillId = (int32_t)0;
	return 0;
}

int taskrewardtaskreward_s::ResumeInit() {
	return 0;
}

void taskrewardtaskreward_s::write_to_pbmsg(::proto_ff::taskrewardtaskreward & msg) const {
	msg.set_id((int64_t)id);
	msg.set_tasktype((int32_t)taskType);
	msg.set_lv((int32_t)lv);
	msg.set_guildexp((int32_t)guildExp);
	msg.set_guildpoint((int32_t)guildPoint);
	msg.set_skillid((int32_t)skillId);
	for(int32_t i = 0; i < (int32_t)item.GetSize() && i < item.GetMaxSize(); ++i) {
		::proto_ff::taskrewardtaskrewarditemDesc* temp_item = msg.add_item();
		item[i].write_to_pbmsg(*temp_item);
	}
	for(int32_t i = 0; i < (int32_t)attr.GetSize() && i < attr.GetMaxSize(); ++i) {
		::proto_ff::taskrewardtaskrewardattrDesc* temp_attr = msg.add_attr();
		attr[i].write_to_pbmsg(*temp_attr);
	}
}

void taskrewardtaskreward_s::read_from_pbmsg(const ::proto_ff::taskrewardtaskreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct taskrewardtaskreward_s));
	id = msg.id();
	taskType = msg.tasktype();
	lv = msg.lv();
	guildExp = msg.guildexp();
	guildPoint = msg.guildpoint();
	skillId = msg.skillid();
	item.SetSize(msg.item_size() > item.GetMaxSize() ? item.GetMaxSize() : msg.item_size());
	for(int32_t i = 0; i < (int32_t)item.GetSize(); ++i) {
		const ::proto_ff::taskrewardtaskrewarditemDesc & temp_item = msg.item(i);
		item[i].read_from_pbmsg(temp_item);
	}
	attr.SetSize(msg.attr_size() > attr.GetMaxSize() ? attr.GetMaxSize() : msg.attr_size());
	for(int32_t i = 0; i < (int32_t)attr.GetSize(); ++i) {
		const ::proto_ff::taskrewardtaskrewardattrDesc & temp_attr = msg.attr(i);
		attr[i].read_from_pbmsg(temp_attr);
	}
}

Sheet_taskrewardtaskreward_s::Sheet_taskrewardtaskreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_taskrewardtaskreward_s::CreateInit() {
	return 0;
}

int Sheet_taskrewardtaskreward_s::ResumeInit() {
	return 0;
}

void Sheet_taskrewardtaskreward_s::write_to_pbmsg(::proto_ff::Sheet_taskrewardtaskreward & msg) const {
	for(int32_t i = 0; i < (int32_t)taskrewardtaskreward_List.GetSize() && i < taskrewardtaskreward_List.GetMaxSize(); ++i) {
		::proto_ff::taskrewardtaskreward* temp_taskrewardtaskreward_list = msg.add_taskrewardtaskreward_list();
		taskrewardtaskreward_List[i].write_to_pbmsg(*temp_taskrewardtaskreward_list);
	}
}

void Sheet_taskrewardtaskreward_s::read_from_pbmsg(const ::proto_ff::Sheet_taskrewardtaskreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_taskrewardtaskreward_s));
	taskrewardtaskreward_List.SetSize(msg.taskrewardtaskreward_list_size() > taskrewardtaskreward_List.GetMaxSize() ? taskrewardtaskreward_List.GetMaxSize() : msg.taskrewardtaskreward_list_size());
	for(int32_t i = 0; i < (int32_t)taskrewardtaskreward_List.GetSize(); ++i) {
		const ::proto_ff::taskrewardtaskreward & temp_taskrewardtaskreward_list = msg.taskrewardtaskreward_list(i);
		taskrewardtaskreward_List[i].read_from_pbmsg(temp_taskrewardtaskreward_list);
	}
}

taskrewardtasktype_s::taskrewardtasktype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int taskrewardtasktype_s::CreateInit() {
	taskType = (int32_t)0;
	return 0;
}

int taskrewardtasktype_s::ResumeInit() {
	return 0;
}

void taskrewardtasktype_s::write_to_pbmsg(::proto_ff::taskrewardtasktype & msg) const {
	msg.set_tasktype((int32_t)taskType);
}

void taskrewardtasktype_s::read_from_pbmsg(const ::proto_ff::taskrewardtasktype & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct taskrewardtasktype_s));
	taskType = msg.tasktype();
}

Sheet_taskrewardtasktype_s::Sheet_taskrewardtasktype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_taskrewardtasktype_s::CreateInit() {
	return 0;
}

int Sheet_taskrewardtasktype_s::ResumeInit() {
	return 0;
}

void Sheet_taskrewardtasktype_s::write_to_pbmsg(::proto_ff::Sheet_taskrewardtasktype & msg) const {
	for(int32_t i = 0; i < (int32_t)taskrewardtasktype_List.GetSize() && i < taskrewardtasktype_List.GetMaxSize(); ++i) {
		::proto_ff::taskrewardtasktype* temp_taskrewardtasktype_list = msg.add_taskrewardtasktype_list();
		taskrewardtasktype_List[i].write_to_pbmsg(*temp_taskrewardtasktype_list);
	}
}

void Sheet_taskrewardtasktype_s::read_from_pbmsg(const ::proto_ff::Sheet_taskrewardtasktype & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_taskrewardtasktype_s));
	taskrewardtasktype_List.SetSize(msg.taskrewardtasktype_list_size() > taskrewardtasktype_List.GetMaxSize() ? taskrewardtasktype_List.GetMaxSize() : msg.taskrewardtasktype_list_size());
	for(int32_t i = 0; i < (int32_t)taskrewardtasktype_List.GetSize(); ++i) {
		const ::proto_ff::taskrewardtasktype & temp_taskrewardtasktype_list = msg.taskrewardtasktype_list(i);
		taskrewardtasktype_List[i].read_from_pbmsg(temp_taskrewardtasktype_list);
	}
}

}