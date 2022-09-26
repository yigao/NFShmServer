#include "GMtools_s.h"

namespace proto_ff_s {

GMtoolsGMTools_s::GMtoolsGMTools_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GMtoolsGMTools_s::CreateInit() {
	id = (int32_t)0;
	type = (int32_t)0;
	return 0;
}

int GMtoolsGMTools_s::ResumeInit() {
	return 0;
}

void GMtoolsGMTools_s::write_to_pbmsg(::proto_ff::GMtoolsGMTools & msg) const {
	msg.set_id((int32_t)id);
	msg.set_type((int32_t)type);
	msg.set_typeprarm((const char*)typePrarm.Get());
}

void GMtoolsGMTools_s::read_from_pbmsg(const ::proto_ff::GMtoolsGMTools & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GMtoolsGMTools_s));
	id = msg.id();
	type = msg.type();
	typePrarm.Copy(msg.typeprarm());
}

Sheet_GMtoolsGMTools_s::Sheet_GMtoolsGMTools_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GMtoolsGMTools_s::CreateInit() {
	return 0;
}

int Sheet_GMtoolsGMTools_s::ResumeInit() {
	return 0;
}

void Sheet_GMtoolsGMTools_s::write_to_pbmsg(::proto_ff::Sheet_GMtoolsGMTools & msg) const {
	for(int32_t i = 0; i < (int32_t)GMtoolsGMTools_List.GetSize() && i < GMtoolsGMTools_List.GetMaxSize(); ++i) {
		::proto_ff::GMtoolsGMTools* temp_gmtoolsgmtools_list = msg.add_gmtoolsgmtools_list();
		GMtoolsGMTools_List[i].write_to_pbmsg(*temp_gmtoolsgmtools_list);
	}
}

void Sheet_GMtoolsGMTools_s::read_from_pbmsg(const ::proto_ff::Sheet_GMtoolsGMTools & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GMtoolsGMTools_s));
	GMtoolsGMTools_List.SetSize(msg.gmtoolsgmtools_list_size() > GMtoolsGMTools_List.GetMaxSize() ? GMtoolsGMTools_List.GetMaxSize() : msg.gmtoolsgmtools_list_size());
	for(int32_t i = 0; i < (int32_t)GMtoolsGMTools_List.GetSize(); ++i) {
		const ::proto_ff::GMtoolsGMTools & temp_gmtoolsgmtools_list = msg.gmtoolsgmtools_list(i);
		GMtoolsGMTools_List[i].read_from_pbmsg(temp_gmtoolsgmtools_list);
	}
}

GMtoolsrecharge_s::GMtoolsrecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GMtoolsrecharge_s::CreateInit() {
	id = (int32_t)0;
	cost = (int32_t)0;
	rechaarge = (int32_t)0;
	return 0;
}

int GMtoolsrecharge_s::ResumeInit() {
	return 0;
}

void GMtoolsrecharge_s::write_to_pbmsg(::proto_ff::GMtoolsrecharge & msg) const {
	msg.set_id((int32_t)id);
	msg.set_cost((int32_t)cost);
	msg.set_rechaarge((int32_t)rechaarge);
}

void GMtoolsrecharge_s::read_from_pbmsg(const ::proto_ff::GMtoolsrecharge & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GMtoolsrecharge_s));
	id = msg.id();
	cost = msg.cost();
	rechaarge = msg.rechaarge();
}

Sheet_GMtoolsrecharge_s::Sheet_GMtoolsrecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GMtoolsrecharge_s::CreateInit() {
	return 0;
}

int Sheet_GMtoolsrecharge_s::ResumeInit() {
	return 0;
}

void Sheet_GMtoolsrecharge_s::write_to_pbmsg(::proto_ff::Sheet_GMtoolsrecharge & msg) const {
	for(int32_t i = 0; i < (int32_t)GMtoolsrecharge_List.GetSize() && i < GMtoolsrecharge_List.GetMaxSize(); ++i) {
		::proto_ff::GMtoolsrecharge* temp_gmtoolsrecharge_list = msg.add_gmtoolsrecharge_list();
		GMtoolsrecharge_List[i].write_to_pbmsg(*temp_gmtoolsrecharge_list);
	}
}

void Sheet_GMtoolsrecharge_s::read_from_pbmsg(const ::proto_ff::Sheet_GMtoolsrecharge & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GMtoolsrecharge_s));
	GMtoolsrecharge_List.SetSize(msg.gmtoolsrecharge_list_size() > GMtoolsrecharge_List.GetMaxSize() ? GMtoolsrecharge_List.GetMaxSize() : msg.gmtoolsrecharge_list_size());
	for(int32_t i = 0; i < (int32_t)GMtoolsrecharge_List.GetSize(); ++i) {
		const ::proto_ff::GMtoolsrecharge & temp_gmtoolsrecharge_list = msg.gmtoolsrecharge_list(i);
		GMtoolsrecharge_List[i].read_from_pbmsg(temp_gmtoolsrecharge_list);
	}
}

GMtoolsgift_s::GMtoolsgift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GMtoolsgift_s::CreateInit() {
	id = (int32_t)0;
	upperLimit = (int32_t)0;
	cost = (int32_t)0;
	daily = (int32_t)0;
	boxid = (int64_t)0;
	return 0;
}

int GMtoolsgift_s::ResumeInit() {
	return 0;
}

void GMtoolsgift_s::write_to_pbmsg(::proto_ff::GMtoolsgift & msg) const {
	msg.set_id((int32_t)id);
	msg.set_upperlimit((int32_t)upperLimit);
	msg.set_condition((const char*)condition.Get());
	msg.set_cost((int32_t)cost);
	msg.set_daily((int32_t)daily);
	msg.set_boxid((int64_t)boxid);
}

void GMtoolsgift_s::read_from_pbmsg(const ::proto_ff::GMtoolsgift & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GMtoolsgift_s));
	id = msg.id();
	upperLimit = msg.upperlimit();
	condition.Copy(msg.condition());
	cost = msg.cost();
	daily = msg.daily();
	boxid = msg.boxid();
}

Sheet_GMtoolsgift_s::Sheet_GMtoolsgift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GMtoolsgift_s::CreateInit() {
	return 0;
}

int Sheet_GMtoolsgift_s::ResumeInit() {
	return 0;
}

void Sheet_GMtoolsgift_s::write_to_pbmsg(::proto_ff::Sheet_GMtoolsgift & msg) const {
	for(int32_t i = 0; i < (int32_t)GMtoolsgift_List.GetSize() && i < GMtoolsgift_List.GetMaxSize(); ++i) {
		::proto_ff::GMtoolsgift* temp_gmtoolsgift_list = msg.add_gmtoolsgift_list();
		GMtoolsgift_List[i].write_to_pbmsg(*temp_gmtoolsgift_list);
	}
}

void Sheet_GMtoolsgift_s::read_from_pbmsg(const ::proto_ff::Sheet_GMtoolsgift & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GMtoolsgift_s));
	GMtoolsgift_List.SetSize(msg.gmtoolsgift_list_size() > GMtoolsgift_List.GetMaxSize() ? GMtoolsgift_List.GetMaxSize() : msg.gmtoolsgift_list_size());
	for(int32_t i = 0; i < (int32_t)GMtoolsgift_List.GetSize(); ++i) {
		const ::proto_ff::GMtoolsgift & temp_gmtoolsgift_list = msg.gmtoolsgift_list(i);
		GMtoolsgift_List[i].read_from_pbmsg(temp_gmtoolsgift_list);
	}
}

GMtoolsunlimit_s::GMtoolsunlimit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GMtoolsunlimit_s::CreateInit() {
	id = (int32_t)0;
	upperLimit = (int32_t)0;
	cost = (int32_t)0;
	boxid = (int64_t)0;
	dailyNum = (int32_t)0;
	return 0;
}

int GMtoolsunlimit_s::ResumeInit() {
	return 0;
}

void GMtoolsunlimit_s::write_to_pbmsg(::proto_ff::GMtoolsunlimit & msg) const {
	msg.set_id((int32_t)id);
	msg.set_upperlimit((int32_t)upperLimit);
	msg.set_cost((int32_t)cost);
	msg.set_boxid((int64_t)boxid);
	msg.set_dailynum((int32_t)dailyNum);
}

void GMtoolsunlimit_s::read_from_pbmsg(const ::proto_ff::GMtoolsunlimit & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GMtoolsunlimit_s));
	id = msg.id();
	upperLimit = msg.upperlimit();
	cost = msg.cost();
	boxid = msg.boxid();
	dailyNum = msg.dailynum();
}

Sheet_GMtoolsunlimit_s::Sheet_GMtoolsunlimit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GMtoolsunlimit_s::CreateInit() {
	return 0;
}

int Sheet_GMtoolsunlimit_s::ResumeInit() {
	return 0;
}

void Sheet_GMtoolsunlimit_s::write_to_pbmsg(::proto_ff::Sheet_GMtoolsunlimit & msg) const {
	for(int32_t i = 0; i < (int32_t)GMtoolsunlimit_List.GetSize() && i < GMtoolsunlimit_List.GetMaxSize(); ++i) {
		::proto_ff::GMtoolsunlimit* temp_gmtoolsunlimit_list = msg.add_gmtoolsunlimit_list();
		GMtoolsunlimit_List[i].write_to_pbmsg(*temp_gmtoolsunlimit_list);
	}
}

void Sheet_GMtoolsunlimit_s::read_from_pbmsg(const ::proto_ff::Sheet_GMtoolsunlimit & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GMtoolsunlimit_s));
	GMtoolsunlimit_List.SetSize(msg.gmtoolsunlimit_list_size() > GMtoolsunlimit_List.GetMaxSize() ? GMtoolsunlimit_List.GetMaxSize() : msg.gmtoolsunlimit_list_size());
	for(int32_t i = 0; i < (int32_t)GMtoolsunlimit_List.GetSize(); ++i) {
		const ::proto_ff::GMtoolsunlimit & temp_gmtoolsunlimit_list = msg.gmtoolsunlimit_list(i);
		GMtoolsunlimit_List[i].read_from_pbmsg(temp_gmtoolsunlimit_list);
	}
}

GMtoolsupperLimit_s::GMtoolsupperLimit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GMtoolsupperLimit_s::CreateInit() {
	id = (int32_t)0;
	type = (int32_t)0;
	param = (int32_t)0;
	return 0;
}

int GMtoolsupperLimit_s::ResumeInit() {
	return 0;
}

void GMtoolsupperLimit_s::write_to_pbmsg(::proto_ff::GMtoolsupperLimit & msg) const {
	msg.set_id((int32_t)id);
	msg.set_type((int32_t)type);
	msg.set_param((int32_t)param);
}

void GMtoolsupperLimit_s::read_from_pbmsg(const ::proto_ff::GMtoolsupperLimit & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GMtoolsupperLimit_s));
	id = msg.id();
	type = msg.type();
	param = msg.param();
}

Sheet_GMtoolsupperLimit_s::Sheet_GMtoolsupperLimit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GMtoolsupperLimit_s::CreateInit() {
	return 0;
}

int Sheet_GMtoolsupperLimit_s::ResumeInit() {
	return 0;
}

void Sheet_GMtoolsupperLimit_s::write_to_pbmsg(::proto_ff::Sheet_GMtoolsupperLimit & msg) const {
	for(int32_t i = 0; i < (int32_t)GMtoolsupperLimit_List.GetSize() && i < GMtoolsupperLimit_List.GetMaxSize(); ++i) {
		::proto_ff::GMtoolsupperLimit* temp_gmtoolsupperlimit_list = msg.add_gmtoolsupperlimit_list();
		GMtoolsupperLimit_List[i].write_to_pbmsg(*temp_gmtoolsupperlimit_list);
	}
}

void Sheet_GMtoolsupperLimit_s::read_from_pbmsg(const ::proto_ff::Sheet_GMtoolsupperLimit & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GMtoolsupperLimit_s));
	GMtoolsupperLimit_List.SetSize(msg.gmtoolsupperlimit_list_size() > GMtoolsupperLimit_List.GetMaxSize() ? GMtoolsupperLimit_List.GetMaxSize() : msg.gmtoolsupperlimit_list_size());
	for(int32_t i = 0; i < (int32_t)GMtoolsupperLimit_List.GetSize(); ++i) {
		const ::proto_ff::GMtoolsupperLimit & temp_gmtoolsupperlimit_list = msg.gmtoolsupperlimit_list(i);
		GMtoolsupperLimit_List[i].read_from_pbmsg(temp_gmtoolsupperlimit_list);
	}
}

}