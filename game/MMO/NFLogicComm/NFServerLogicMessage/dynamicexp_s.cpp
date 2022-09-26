#include "dynamicexp_s.h"

namespace proto_ff_s {

dynamicexpdynamicexpdynamicDesc_s::dynamicexpdynamicexpdynamicDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dynamicexpdynamicexpdynamicDesc_s::CreateInit() {
	exp = (int64_t)0;
	return 0;
}

int dynamicexpdynamicexpdynamicDesc_s::ResumeInit() {
	return 0;
}

void dynamicexpdynamicexpdynamicDesc_s::write_to_pbmsg(::proto_ff::dynamicexpdynamicexpdynamicDesc & msg) const {
	msg.set_exp((int64_t)exp);
}

void dynamicexpdynamicexpdynamicDesc_s::read_from_pbmsg(const ::proto_ff::dynamicexpdynamicexpdynamicDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dynamicexpdynamicexpdynamicDesc_s));
	exp = msg.exp();
}

dynamicexpdynamicexp_s::dynamicexpdynamicexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dynamicexpdynamicexp_s::CreateInit() {
	lv = (int32_t)0;
	return 0;
}

int dynamicexpdynamicexp_s::ResumeInit() {
	return 0;
}

void dynamicexpdynamicexp_s::write_to_pbmsg(::proto_ff::dynamicexpdynamicexp & msg) const {
	msg.set_lv((int32_t)lv);
	for(int32_t i = 0; i < (int32_t)dynamic.GetSize() && i < dynamic.GetMaxSize(); ++i) {
		::proto_ff::dynamicexpdynamicexpdynamicDesc* temp_dynamic = msg.add_dynamic();
		dynamic[i].write_to_pbmsg(*temp_dynamic);
	}
}

void dynamicexpdynamicexp_s::read_from_pbmsg(const ::proto_ff::dynamicexpdynamicexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dynamicexpdynamicexp_s));
	lv = msg.lv();
	dynamic.SetSize(msg.dynamic_size() > dynamic.GetMaxSize() ? dynamic.GetMaxSize() : msg.dynamic_size());
	for(int32_t i = 0; i < (int32_t)dynamic.GetSize(); ++i) {
		const ::proto_ff::dynamicexpdynamicexpdynamicDesc & temp_dynamic = msg.dynamic(i);
		dynamic[i].read_from_pbmsg(temp_dynamic);
	}
}

Sheet_dynamicexpdynamicexp_s::Sheet_dynamicexpdynamicexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_dynamicexpdynamicexp_s::CreateInit() {
	return 0;
}

int Sheet_dynamicexpdynamicexp_s::ResumeInit() {
	return 0;
}

void Sheet_dynamicexpdynamicexp_s::write_to_pbmsg(::proto_ff::Sheet_dynamicexpdynamicexp & msg) const {
	for(int32_t i = 0; i < (int32_t)dynamicexpdynamicexp_List.GetSize() && i < dynamicexpdynamicexp_List.GetMaxSize(); ++i) {
		::proto_ff::dynamicexpdynamicexp* temp_dynamicexpdynamicexp_list = msg.add_dynamicexpdynamicexp_list();
		dynamicexpdynamicexp_List[i].write_to_pbmsg(*temp_dynamicexpdynamicexp_list);
	}
}

void Sheet_dynamicexpdynamicexp_s::read_from_pbmsg(const ::proto_ff::Sheet_dynamicexpdynamicexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_dynamicexpdynamicexp_s));
	dynamicexpdynamicexp_List.SetSize(msg.dynamicexpdynamicexp_list_size() > dynamicexpdynamicexp_List.GetMaxSize() ? dynamicexpdynamicexp_List.GetMaxSize() : msg.dynamicexpdynamicexp_list_size());
	for(int32_t i = 0; i < (int32_t)dynamicexpdynamicexp_List.GetSize(); ++i) {
		const ::proto_ff::dynamicexpdynamicexp & temp_dynamicexpdynamicexp_list = msg.dynamicexpdynamicexp_list(i);
		dynamicexpdynamicexp_List[i].read_from_pbmsg(temp_dynamicexpdynamicexp_list);
	}
}

}