#include "taskreward_s.h"

namespace proto_ff_s {

taskrewardtaskrewardattrDesc_s::taskrewardtaskrewardattrDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int taskrewardtaskrewardattrDesc_s::CreateInit() {
	id = (int64_t)0;
	return 0;
}

int taskrewardtaskrewardattrDesc_s::ResumeInit() {
	return 0;
}

void taskrewardtaskrewardattrDesc_s::write_to_pbmsg(::proto_ff::taskrewardtaskrewardattrDesc & msg) const {
	msg.set_id((int64_t)id);
}

void taskrewardtaskrewardattrDesc_s::read_from_pbmsg(const ::proto_ff::taskrewardtaskrewardattrDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct taskrewardtaskrewardattrDesc_s));
	id = msg.id();
}

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
	for(int32_t i = 0; i < (int32_t)attr_val.GetSize() && i < attr_val.GetMaxSize(); ++i) {
		msg.add_attr_val((int64_t)attr_val[i]);
	}
	for(int32_t i = 0; i < (int32_t)attr.GetSize() && i < attr.GetMaxSize(); ++i) {
		::proto_ff::taskrewardtaskrewardattrDesc* temp_attr = msg.add_attr();
		attr[i].write_to_pbmsg(*temp_attr);
	}
	for(int32_t i = 0; i < (int32_t)item.GetSize() && i < item.GetMaxSize(); ++i) {
		::proto_ff::taskrewardtaskrewarditemDesc* temp_item = msg.add_item();
		item[i].write_to_pbmsg(*temp_item);
	}
}

void taskrewardtaskreward_s::read_from_pbmsg(const ::proto_ff::taskrewardtaskreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct taskrewardtaskreward_s));
	id = msg.id();
	taskType = msg.tasktype();
	lv = msg.lv();
	guildExp = msg.guildexp();
	guildPoint = msg.guildpoint();
	attr_val.SetSize(msg.attr_val_size() > attr_val.GetMaxSize() ? attr_val.GetMaxSize() : msg.attr_val_size());
	for(int32_t i = 0; i < (int32_t)attr_val.GetSize(); ++i) {
		attr_val[i] = msg.attr_val(i);
	}
	attr.SetSize(msg.attr_size() > attr.GetMaxSize() ? attr.GetMaxSize() : msg.attr_size());
	for(int32_t i = 0; i < (int32_t)attr.GetSize(); ++i) {
		const ::proto_ff::taskrewardtaskrewardattrDesc & temp_attr = msg.attr(i);
		attr[i].read_from_pbmsg(temp_attr);
	}
	item.SetSize(msg.item_size() > item.GetMaxSize() ? item.GetMaxSize() : msg.item_size());
	for(int32_t i = 0; i < (int32_t)item.GetSize(); ++i) {
		const ::proto_ff::taskrewardtaskrewarditemDesc & temp_item = msg.item(i);
		item[i].read_from_pbmsg(temp_item);
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

}