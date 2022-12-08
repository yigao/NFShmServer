#include "path_s.h"

namespace proto_ff_s {

pathpath_s::pathpath_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int pathpath_s::CreateInit() {
	id = (int64_t)0;
	belongToSceneID = (int64_t)0;
	return 0;
}

int pathpath_s::ResumeInit() {
	return 0;
}

void pathpath_s::write_to_pbmsg(::proto_ff::pathpath & msg) const {
	msg.set_id((int64_t)id);
	msg.set_belongtosceneid((int64_t)belongToSceneID);
}

void pathpath_s::read_from_pbmsg(const ::proto_ff::pathpath & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct pathpath_s));
	id = msg.id();
	belongToSceneID = msg.belongtosceneid();
}

Sheet_pathpath_s::Sheet_pathpath_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_pathpath_s::CreateInit() {
	return 0;
}

int Sheet_pathpath_s::ResumeInit() {
	return 0;
}

void Sheet_pathpath_s::write_to_pbmsg(::proto_ff::Sheet_pathpath & msg) const {
	for(int32_t i = 0; i < (int32_t)pathpath_List.GetSize() && i < pathpath_List.GetMaxSize(); ++i) {
		::proto_ff::pathpath* temp_pathpath_list = msg.add_pathpath_list();
		pathpath_List[i].write_to_pbmsg(*temp_pathpath_list);
	}
}

void Sheet_pathpath_s::read_from_pbmsg(const ::proto_ff::Sheet_pathpath & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_pathpath_s));
	pathpath_List.SetSize(msg.pathpath_list_size() > pathpath_List.GetMaxSize() ? pathpath_List.GetMaxSize() : msg.pathpath_list_size());
	for(int32_t i = 0; i < (int32_t)pathpath_List.GetSize(); ++i) {
		const ::proto_ff::pathpath & temp_pathpath_list = msg.pathpath_list(i);
		pathpath_List[i].read_from_pbmsg(temp_pathpath_list);
	}
}

}