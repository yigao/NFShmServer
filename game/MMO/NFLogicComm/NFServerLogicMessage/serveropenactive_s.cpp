#include "serveropenactive_s.h"

namespace proto_ff_s {

serveropenactiveserviceActivity_s::serveropenactiveserviceActivity_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int serveropenactiveserviceActivity_s::CreateInit() {
	id = (int64_t)0;
	servertype = (int32_t)0;
	timeA = (int32_t)0;
	timeB = (int32_t)0;
	return 0;
}

int serveropenactiveserviceActivity_s::ResumeInit() {
	return 0;
}

void serveropenactiveserviceActivity_s::write_to_pbmsg(::proto_ff::serveropenactiveserviceActivity & msg) const {
	msg.set_id((int64_t)id);
	msg.set_servertype((int32_t)servertype);
	msg.set_timea((int32_t)timeA);
	msg.set_timeb((int32_t)timeB);
	msg.set_pageid((const char*)pageId.Get());
}

void serveropenactiveserviceActivity_s::read_from_pbmsg(const ::proto_ff::serveropenactiveserviceActivity & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct serveropenactiveserviceActivity_s));
	id = msg.id();
	servertype = msg.servertype();
	timeA = msg.timea();
	timeB = msg.timeb();
	pageId.Copy(msg.pageid());
}

Sheet_serveropenactiveserviceActivity_s::Sheet_serveropenactiveserviceActivity_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_serveropenactiveserviceActivity_s::CreateInit() {
	return 0;
}

int Sheet_serveropenactiveserviceActivity_s::ResumeInit() {
	return 0;
}

void Sheet_serveropenactiveserviceActivity_s::write_to_pbmsg(::proto_ff::Sheet_serveropenactiveserviceActivity & msg) const {
	for(int32_t i = 0; i < (int32_t)serveropenactiveserviceActivity_List.GetSize() && i < serveropenactiveserviceActivity_List.GetMaxSize(); ++i) {
		::proto_ff::serveropenactiveserviceActivity* temp_serveropenactiveserviceactivity_list = msg.add_serveropenactiveserviceactivity_list();
		serveropenactiveserviceActivity_List[i].write_to_pbmsg(*temp_serveropenactiveserviceactivity_list);
	}
}

void Sheet_serveropenactiveserviceActivity_s::read_from_pbmsg(const ::proto_ff::Sheet_serveropenactiveserviceActivity & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_serveropenactiveserviceActivity_s));
	serveropenactiveserviceActivity_List.SetSize(msg.serveropenactiveserviceactivity_list_size() > serveropenactiveserviceActivity_List.GetMaxSize() ? serveropenactiveserviceActivity_List.GetMaxSize() : msg.serveropenactiveserviceactivity_list_size());
	for(int32_t i = 0; i < (int32_t)serveropenactiveserviceActivity_List.GetSize(); ++i) {
		const ::proto_ff::serveropenactiveserviceActivity & temp_serveropenactiveserviceactivity_list = msg.serveropenactiveserviceactivity_list(i);
		serveropenactiveserviceActivity_List[i].read_from_pbmsg(temp_serveropenactiveserviceactivity_list);
	}
}

serveropenactivepageBook_s::serveropenactivepageBook_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int serveropenactivepageBook_s::CreateInit() {
	Id = (int32_t)0;
	return 0;
}

int serveropenactivepageBook_s::ResumeInit() {
	return 0;
}

void serveropenactivepageBook_s::write_to_pbmsg(::proto_ff::serveropenactivepageBook & msg) const {
	msg.set_id((int32_t)Id);
}

void serveropenactivepageBook_s::read_from_pbmsg(const ::proto_ff::serveropenactivepageBook & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct serveropenactivepageBook_s));
	Id = msg.id();
}

Sheet_serveropenactivepageBook_s::Sheet_serveropenactivepageBook_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_serveropenactivepageBook_s::CreateInit() {
	return 0;
}

int Sheet_serveropenactivepageBook_s::ResumeInit() {
	return 0;
}

void Sheet_serveropenactivepageBook_s::write_to_pbmsg(::proto_ff::Sheet_serveropenactivepageBook & msg) const {
	for(int32_t i = 0; i < (int32_t)serveropenactivepageBook_List.GetSize() && i < serveropenactivepageBook_List.GetMaxSize(); ++i) {
		::proto_ff::serveropenactivepageBook* temp_serveropenactivepagebook_list = msg.add_serveropenactivepagebook_list();
		serveropenactivepageBook_List[i].write_to_pbmsg(*temp_serveropenactivepagebook_list);
	}
}

void Sheet_serveropenactivepageBook_s::read_from_pbmsg(const ::proto_ff::Sheet_serveropenactivepageBook & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_serveropenactivepageBook_s));
	serveropenactivepageBook_List.SetSize(msg.serveropenactivepagebook_list_size() > serveropenactivepageBook_List.GetMaxSize() ? serveropenactivepageBook_List.GetMaxSize() : msg.serveropenactivepagebook_list_size());
	for(int32_t i = 0; i < (int32_t)serveropenactivepageBook_List.GetSize(); ++i) {
		const ::proto_ff::serveropenactivepageBook & temp_serveropenactivepagebook_list = msg.serveropenactivepagebook_list(i);
		serveropenactivepageBook_List[i].read_from_pbmsg(temp_serveropenactivepagebook_list);
	}
}

serveropenactivepage_s::serveropenactivepage_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int serveropenactivepage_s::CreateInit() {
	Id = (int64_t)0;
	mType = (int32_t)0;
	mCanshu = (int32_t)0;
	mailid = (int64_t)0;
	youjianid = (int64_t)0;
	nonstandardmailid = (int64_t)0;
	return 0;
}

int serveropenactivepage_s::ResumeInit() {
	return 0;
}

void serveropenactivepage_s::write_to_pbmsg(::proto_ff::serveropenactivepage & msg) const {
	msg.set_id((int64_t)Id);
	msg.set_mtype((int32_t)mType);
	msg.set_mcanshu((int32_t)mCanshu);
	msg.set_start((const char*)start.Get());
	msg.set_finish((const char*)finish.Get());
	msg.set_miaoshu((const char*)miaoshu.Get());
	msg.set_tiaojianid((const char*)tiaojianId.Get());
	msg.set_mailid((int64_t)mailid);
	msg.set_youjianid((int64_t)youjianid);
	msg.set_nonstandardmailid((int64_t)nonstandardmailid);
}

void serveropenactivepage_s::read_from_pbmsg(const ::proto_ff::serveropenactivepage & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct serveropenactivepage_s));
	Id = msg.id();
	mType = msg.mtype();
	mCanshu = msg.mcanshu();
	start.Copy(msg.start());
	finish.Copy(msg.finish());
	miaoshu.Copy(msg.miaoshu());
	tiaojianId.Copy(msg.tiaojianid());
	mailid = msg.mailid();
	youjianid = msg.youjianid();
	nonstandardmailid = msg.nonstandardmailid();
}

Sheet_serveropenactivepage_s::Sheet_serveropenactivepage_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_serveropenactivepage_s::CreateInit() {
	return 0;
}

int Sheet_serveropenactivepage_s::ResumeInit() {
	return 0;
}

void Sheet_serveropenactivepage_s::write_to_pbmsg(::proto_ff::Sheet_serveropenactivepage & msg) const {
	for(int32_t i = 0; i < (int32_t)serveropenactivepage_List.GetSize() && i < serveropenactivepage_List.GetMaxSize(); ++i) {
		::proto_ff::serveropenactivepage* temp_serveropenactivepage_list = msg.add_serveropenactivepage_list();
		serveropenactivepage_List[i].write_to_pbmsg(*temp_serveropenactivepage_list);
	}
}

void Sheet_serveropenactivepage_s::read_from_pbmsg(const ::proto_ff::Sheet_serveropenactivepage & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_serveropenactivepage_s));
	serveropenactivepage_List.SetSize(msg.serveropenactivepage_list_size() > serveropenactivepage_List.GetMaxSize() ? serveropenactivepage_List.GetMaxSize() : msg.serveropenactivepage_list_size());
	for(int32_t i = 0; i < (int32_t)serveropenactivepage_List.GetSize(); ++i) {
		const ::proto_ff::serveropenactivepage & temp_serveropenactivepage_list = msg.serveropenactivepage_list(i);
		serveropenactivepage_List[i].read_from_pbmsg(temp_serveropenactivepage_list);
	}
}

serveropenactivemRank_s::serveropenactivemRank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int serveropenactivemRank_s::CreateInit() {
	id = (int32_t)0;
	randtype = (int32_t)0;
	boxid = (int64_t)0;
	return 0;
}

int serveropenactivemRank_s::ResumeInit() {
	return 0;
}

void serveropenactivemRank_s::write_to_pbmsg(::proto_ff::serveropenactivemRank & msg) const {
	msg.set_id((int32_t)id);
	msg.set_randtype((int32_t)randtype);
	msg.set_miaoshu((const char*)miaoshu.Get());
	msg.set_boxid((int64_t)boxid);
		msg.add_canshu((int32_t)canshu[i]);
	}
}

void serveropenactivemRank_s::read_from_pbmsg(const ::proto_ff::serveropenactivemRank & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct serveropenactivemRank_s));
	id = msg.id();
	randtype = msg.randtype();
	miaoshu.Copy(msg.miaoshu());
	boxid = msg.boxid();
		canshu[i] = msg.canshu(i);
	}
}

Sheet_serveropenactivemRank_s::Sheet_serveropenactivemRank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_serveropenactivemRank_s::CreateInit() {
	return 0;
}

int Sheet_serveropenactivemRank_s::ResumeInit() {
	return 0;
}

void Sheet_serveropenactivemRank_s::write_to_pbmsg(::proto_ff::Sheet_serveropenactivemRank & msg) const {
	for(int32_t i = 0; i < (int32_t)serveropenactivemRank_List.GetSize() && i < serveropenactivemRank_List.GetMaxSize(); ++i) {
		::proto_ff::serveropenactivemRank* temp_serveropenactivemrank_list = msg.add_serveropenactivemrank_list();
		serveropenactivemRank_List[i].write_to_pbmsg(*temp_serveropenactivemrank_list);
	}
}

void Sheet_serveropenactivemRank_s::read_from_pbmsg(const ::proto_ff::Sheet_serveropenactivemRank & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_serveropenactivemRank_s));
	serveropenactivemRank_List.SetSize(msg.serveropenactivemrank_list_size() > serveropenactivemRank_List.GetMaxSize() ? serveropenactivemRank_List.GetMaxSize() : msg.serveropenactivemrank_list_size());
	for(int32_t i = 0; i < (int32_t)serveropenactivemRank_List.GetSize(); ++i) {
		const ::proto_ff::serveropenactivemRank & temp_serveropenactivemrank_list = msg.serveropenactivemrank_list(i);
		serveropenactivemRank_List[i].read_from_pbmsg(temp_serveropenactivemrank_list);
	}
}

serveropenactivemAdvanced_s::serveropenactivemAdvanced_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int serveropenactivemAdvanced_s::CreateInit() {
	id = (int32_t)0;
	advancedType = (int32_t)0;
	num = (int64_t)0;
	parameter = (int64_t)0;
	jiangLi = (int64_t)0;
	return 0;
}

int serveropenactivemAdvanced_s::ResumeInit() {
	return 0;
}

void serveropenactivemAdvanced_s::write_to_pbmsg(::proto_ff::serveropenactivemAdvanced & msg) const {
	msg.set_id((int32_t)id);
	msg.set_advancedtype((int32_t)advancedType);
	msg.set_num((int64_t)num);
	msg.set_parameter((int64_t)parameter);
	msg.set_miaoshu((const char*)miaoshu.Get());
	msg.set_jiangli((int64_t)jiangLi);
}

void serveropenactivemAdvanced_s::read_from_pbmsg(const ::proto_ff::serveropenactivemAdvanced & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct serveropenactivemAdvanced_s));
	id = msg.id();
	advancedType = msg.advancedtype();
	num = msg.num();
	parameter = msg.parameter();
	miaoshu.Copy(msg.miaoshu());
	jiangLi = msg.jiangli();
}

Sheet_serveropenactivemAdvanced_s::Sheet_serveropenactivemAdvanced_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_serveropenactivemAdvanced_s::CreateInit() {
	return 0;
}

int Sheet_serveropenactivemAdvanced_s::ResumeInit() {
	return 0;
}

void Sheet_serveropenactivemAdvanced_s::write_to_pbmsg(::proto_ff::Sheet_serveropenactivemAdvanced & msg) const {
	for(int32_t i = 0; i < (int32_t)serveropenactivemAdvanced_List.GetSize() && i < serveropenactivemAdvanced_List.GetMaxSize(); ++i) {
		::proto_ff::serveropenactivemAdvanced* temp_serveropenactivemadvanced_list = msg.add_serveropenactivemadvanced_list();
		serveropenactivemAdvanced_List[i].write_to_pbmsg(*temp_serveropenactivemadvanced_list);
	}
}

void Sheet_serveropenactivemAdvanced_s::read_from_pbmsg(const ::proto_ff::Sheet_serveropenactivemAdvanced & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_serveropenactivemAdvanced_s));
	serveropenactivemAdvanced_List.SetSize(msg.serveropenactivemadvanced_list_size() > serveropenactivemAdvanced_List.GetMaxSize() ? serveropenactivemAdvanced_List.GetMaxSize() : msg.serveropenactivemadvanced_list_size());
	for(int32_t i = 0; i < (int32_t)serveropenactivemAdvanced_List.GetSize(); ++i) {
		const ::proto_ff::serveropenactivemAdvanced & temp_serveropenactivemadvanced_list = msg.serveropenactivemadvanced_list(i);
		serveropenactivemAdvanced_List[i].read_from_pbmsg(temp_serveropenactivemadvanced_list);
	}
}

serveropenactivemRecharge_s::serveropenactivemRecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int serveropenactivemRecharge_s::CreateInit() {
	id = (int32_t)0;
	numType = (int32_t)0;
	num = (int32_t)0;
	jiangLi = (int64_t)0;
	return 0;
}

int serveropenactivemRecharge_s::ResumeInit() {
	return 0;
}

void serveropenactivemRecharge_s::write_to_pbmsg(::proto_ff::serveropenactivemRecharge & msg) const {
	msg.set_id((int32_t)id);
	msg.set_numtype((int32_t)numType);
	msg.set_num((int32_t)num);
	msg.set_miaoshu((const char*)miaoshu.Get());
	msg.set_jiangli((int64_t)jiangLi);
}

void serveropenactivemRecharge_s::read_from_pbmsg(const ::proto_ff::serveropenactivemRecharge & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct serveropenactivemRecharge_s));
	id = msg.id();
	numType = msg.numtype();
	num = msg.num();
	miaoshu.Copy(msg.miaoshu());
	jiangLi = msg.jiangli();
}

Sheet_serveropenactivemRecharge_s::Sheet_serveropenactivemRecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_serveropenactivemRecharge_s::CreateInit() {
	return 0;
}

int Sheet_serveropenactivemRecharge_s::ResumeInit() {
	return 0;
}

void Sheet_serveropenactivemRecharge_s::write_to_pbmsg(::proto_ff::Sheet_serveropenactivemRecharge & msg) const {
	for(int32_t i = 0; i < (int32_t)serveropenactivemRecharge_List.GetSize() && i < serveropenactivemRecharge_List.GetMaxSize(); ++i) {
		::proto_ff::serveropenactivemRecharge* temp_serveropenactivemrecharge_list = msg.add_serveropenactivemrecharge_list();
		serveropenactivemRecharge_List[i].write_to_pbmsg(*temp_serveropenactivemrecharge_list);
	}
}

void Sheet_serveropenactivemRecharge_s::read_from_pbmsg(const ::proto_ff::Sheet_serveropenactivemRecharge & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_serveropenactivemRecharge_s));
	serveropenactivemRecharge_List.SetSize(msg.serveropenactivemrecharge_list_size() > serveropenactivemRecharge_List.GetMaxSize() ? serveropenactivemRecharge_List.GetMaxSize() : msg.serveropenactivemrecharge_list_size());
	for(int32_t i = 0; i < (int32_t)serveropenactivemRecharge_List.GetSize(); ++i) {
		const ::proto_ff::serveropenactivemRecharge & temp_serveropenactivemrecharge_list = msg.serveropenactivemrecharge_list(i);
		serveropenactivemRecharge_List[i].read_from_pbmsg(temp_serveropenactivemrecharge_list);
	}
}

serveropenactivemGoods_s::serveropenactivemGoods_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int serveropenactivemGoods_s::CreateInit() {
	id = (int64_t)0;
	itemid = (int64_t)0;
	currency = (int32_t)0;
	priceA = (int32_t)0;
	priceB = (int32_t)0;
	quantity = (int32_t)0;
	return 0;
}

int serveropenactivemGoods_s::ResumeInit() {
	return 0;
}

void serveropenactivemGoods_s::write_to_pbmsg(::proto_ff::serveropenactivemGoods & msg) const {
	msg.set_id((int64_t)id);
	msg.set_itemid((int64_t)itemid);
	msg.set_currency((int32_t)currency);
	msg.set_pricea((int32_t)priceA);
	msg.set_priceb((int32_t)priceB);
	msg.set_quantity((int32_t)quantity);
}

void serveropenactivemGoods_s::read_from_pbmsg(const ::proto_ff::serveropenactivemGoods & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct serveropenactivemGoods_s));
	id = msg.id();
	itemid = msg.itemid();
	currency = msg.currency();
	priceA = msg.pricea();
	priceB = msg.priceb();
	quantity = msg.quantity();
}

Sheet_serveropenactivemGoods_s::Sheet_serveropenactivemGoods_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_serveropenactivemGoods_s::CreateInit() {
	return 0;
}

int Sheet_serveropenactivemGoods_s::ResumeInit() {
	return 0;
}

void Sheet_serveropenactivemGoods_s::write_to_pbmsg(::proto_ff::Sheet_serveropenactivemGoods & msg) const {
	for(int32_t i = 0; i < (int32_t)serveropenactivemGoods_List.GetSize() && i < serveropenactivemGoods_List.GetMaxSize(); ++i) {
		::proto_ff::serveropenactivemGoods* temp_serveropenactivemgoods_list = msg.add_serveropenactivemgoods_list();
		serveropenactivemGoods_List[i].write_to_pbmsg(*temp_serveropenactivemgoods_list);
	}
}

void Sheet_serveropenactivemGoods_s::read_from_pbmsg(const ::proto_ff::Sheet_serveropenactivemGoods & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_serveropenactivemGoods_s));
	serveropenactivemGoods_List.SetSize(msg.serveropenactivemgoods_list_size() > serveropenactivemGoods_List.GetMaxSize() ? serveropenactivemGoods_List.GetMaxSize() : msg.serveropenactivemgoods_list_size());
	for(int32_t i = 0; i < (int32_t)serveropenactivemGoods_List.GetSize(); ++i) {
		const ::proto_ff::serveropenactivemGoods & temp_serveropenactivemgoods_list = msg.serveropenactivemgoods_list(i);
		serveropenactivemGoods_List[i].read_from_pbmsg(temp_serveropenactivemgoods_list);
	}
}

}