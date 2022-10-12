#include "colPoints_s.h"

namespace proto_ff_s {

colPointscolPoints_s::colPointscolPoints_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int colPointscolPoints_s::CreateInit() {
	id = (int32_t)0;
	weight = (int32_t)0;
	boxid = (int64_t)0;
	beginPoint = (int32_t)0;
	targetPoint = (int32_t)0;
	return 0;
}

int colPointscolPoints_s::ResumeInit() {
	return 0;
}

void colPointscolPoints_s::write_to_pbmsg(::proto_ff::colPointscolPoints & msg) const {
	msg.set_id((int32_t)id);
	msg.set_weight((int32_t)weight);
	msg.set_boxid((int64_t)boxid);
	msg.set_beginpoint((int32_t)beginPoint);
	msg.set_targetpoint((int32_t)targetPoint);
	msg.set_taskid((const char*)taskID.Get());
}

void colPointscolPoints_s::read_from_pbmsg(const ::proto_ff::colPointscolPoints & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct colPointscolPoints_s));
	id = msg.id();
	weight = msg.weight();
	boxid = msg.boxid();
	beginPoint = msg.beginpoint();
	targetPoint = msg.targetpoint();
	taskID.Copy(msg.taskid());
}

Sheet_colPointscolPoints_s::Sheet_colPointscolPoints_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_colPointscolPoints_s::CreateInit() {
	return 0;
}

int Sheet_colPointscolPoints_s::ResumeInit() {
	return 0;
}

void Sheet_colPointscolPoints_s::write_to_pbmsg(::proto_ff::Sheet_colPointscolPoints & msg) const {
	for(int32_t i = 0; i < (int32_t)colPointscolPoints_List.GetSize() && i < colPointscolPoints_List.GetMaxSize(); ++i) {
		::proto_ff::colPointscolPoints* temp_colpointscolpoints_list = msg.add_colpointscolpoints_list();
		colPointscolPoints_List[i].write_to_pbmsg(*temp_colpointscolpoints_list);
	}
}

void Sheet_colPointscolPoints_s::read_from_pbmsg(const ::proto_ff::Sheet_colPointscolPoints & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_colPointscolPoints_s));
	colPointscolPoints_List.SetSize(msg.colpointscolpoints_list_size() > colPointscolPoints_List.GetMaxSize() ? colPointscolPoints_List.GetMaxSize() : msg.colpointscolpoints_list_size());
	for(int32_t i = 0; i < (int32_t)colPointscolPoints_List.GetSize(); ++i) {
		const ::proto_ff::colPointscolPoints & temp_colpointscolpoints_list = msg.colpointscolpoints_list(i);
		colPointscolPoints_List[i].read_from_pbmsg(temp_colpointscolpoints_list);
	}
}

colPointstask_s::colPointstask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int colPointstask_s::CreateInit() {
	id = (int32_t)0;
	point = (int32_t)0;
	num = (int32_t)0;
	task = (int32_t)0;
	return 0;
}

int colPointstask_s::ResumeInit() {
	return 0;
}

void colPointstask_s::write_to_pbmsg(::proto_ff::colPointstask & msg) const {
	msg.set_id((int32_t)id);
	msg.set_point((int32_t)point);
	msg.set_num((int32_t)num);
	msg.set_task((int32_t)task);
	msg.set_taskparam((const char*)taskParam.Get());
}

void colPointstask_s::read_from_pbmsg(const ::proto_ff::colPointstask & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct colPointstask_s));
	id = msg.id();
	point = msg.point();
	num = msg.num();
	task = msg.task();
	taskParam.Copy(msg.taskparam());
}

Sheet_colPointstask_s::Sheet_colPointstask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_colPointstask_s::CreateInit() {
	return 0;
}

int Sheet_colPointstask_s::ResumeInit() {
	return 0;
}

void Sheet_colPointstask_s::write_to_pbmsg(::proto_ff::Sheet_colPointstask & msg) const {
	for(int32_t i = 0; i < (int32_t)colPointstask_List.GetSize() && i < colPointstask_List.GetMaxSize(); ++i) {
		::proto_ff::colPointstask* temp_colpointstask_list = msg.add_colpointstask_list();
		colPointstask_List[i].write_to_pbmsg(*temp_colpointstask_list);
	}
}

void Sheet_colPointstask_s::read_from_pbmsg(const ::proto_ff::Sheet_colPointstask & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_colPointstask_s));
	colPointstask_List.SetSize(msg.colpointstask_list_size() > colPointstask_List.GetMaxSize() ? colPointstask_List.GetMaxSize() : msg.colpointstask_list_size());
	for(int32_t i = 0; i < (int32_t)colPointstask_List.GetSize(); ++i) {
		const ::proto_ff::colPointstask & temp_colpointstask_list = msg.colpointstask_list(i);
		colPointstask_List[i].read_from_pbmsg(temp_colpointstask_list);
	}
}

}