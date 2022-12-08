#include "point_s.h"

namespace proto_ff_s {

pointpoint_s::pointpoint_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int pointpoint_s::CreateInit() {
	id = (int64_t)0;
	belongToSceneID = (int64_t)0;
	return 0;
}

int pointpoint_s::ResumeInit() {
	return 0;
}

void pointpoint_s::write_to_pbmsg(::proto_ff::pointpoint & msg) const {
	msg.set_id((int64_t)id);
	msg.set_belongtosceneid((int64_t)belongToSceneID);
}

void pointpoint_s::read_from_pbmsg(const ::proto_ff::pointpoint & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct pointpoint_s));
	id = msg.id();
	belongToSceneID = msg.belongtosceneid();
}

Sheet_pointpoint_s::Sheet_pointpoint_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_pointpoint_s::CreateInit() {
	return 0;
}

int Sheet_pointpoint_s::ResumeInit() {
	return 0;
}

void Sheet_pointpoint_s::write_to_pbmsg(::proto_ff::Sheet_pointpoint & msg) const {
	for(int32_t i = 0; i < (int32_t)pointpoint_List.GetSize() && i < pointpoint_List.GetMaxSize(); ++i) {
		::proto_ff::pointpoint* temp_pointpoint_list = msg.add_pointpoint_list();
		pointpoint_List[i].write_to_pbmsg(*temp_pointpoint_list);
	}
}

void Sheet_pointpoint_s::read_from_pbmsg(const ::proto_ff::Sheet_pointpoint & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_pointpoint_s));
	pointpoint_List.SetSize(msg.pointpoint_list_size() > pointpoint_List.GetMaxSize() ? pointpoint_List.GetMaxSize() : msg.pointpoint_list_size());
	for(int32_t i = 0; i < (int32_t)pointpoint_List.GetSize(); ++i) {
		const ::proto_ff::pointpoint & temp_pointpoint_list = msg.pointpoint_list(i);
		pointpoint_List[i].read_from_pbmsg(temp_pointpoint_list);
	}
}

}