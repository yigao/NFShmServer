#include "area_s.h"

namespace proto_ff_s {

areaarea_s::areaarea_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int areaarea_s::CreateInit() {
	id = (int64_t)0;
	subType = (int32_t)0;
	belongToSceneID = (int64_t)0;
	shapeType = (int32_t)0;
	isNotice = (int32_t)0;
	return 0;
}

int areaarea_s::ResumeInit() {
	return 0;
}

void areaarea_s::write_to_pbmsg(::proto_ff::areaarea & msg) const {
	msg.set_id((int64_t)id);
	msg.set_subtype((int32_t)subType);
	msg.set_belongtosceneid((int64_t)belongToSceneID);
	msg.set_shapetype((int32_t)shapeType);
	msg.set_isnotice((int32_t)isNotice);
}

void areaarea_s::read_from_pbmsg(const ::proto_ff::areaarea & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct areaarea_s));
	id = msg.id();
	subType = msg.subtype();
	belongToSceneID = msg.belongtosceneid();
	shapeType = msg.shapetype();
	isNotice = msg.isnotice();
}

Sheet_areaarea_s::Sheet_areaarea_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_areaarea_s::CreateInit() {
	return 0;
}

int Sheet_areaarea_s::ResumeInit() {
	return 0;
}

void Sheet_areaarea_s::write_to_pbmsg(::proto_ff::Sheet_areaarea & msg) const {
	for(int32_t i = 0; i < (int32_t)areaarea_List.GetSize() && i < areaarea_List.GetMaxSize(); ++i) {
		::proto_ff::areaarea* temp_areaarea_list = msg.add_areaarea_list();
		areaarea_List[i].write_to_pbmsg(*temp_areaarea_list);
	}
}

void Sheet_areaarea_s::read_from_pbmsg(const ::proto_ff::Sheet_areaarea & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_areaarea_s));
	areaarea_List.SetSize(msg.areaarea_list_size() > areaarea_List.GetMaxSize() ? areaarea_List.GetMaxSize() : msg.areaarea_list_size());
	for(int32_t i = 0; i < (int32_t)areaarea_List.GetSize(); ++i) {
		const ::proto_ff::areaarea & temp_areaarea_list = msg.areaarea_list(i);
		areaarea_List[i].read_from_pbmsg(temp_areaarea_list);
	}
}

}