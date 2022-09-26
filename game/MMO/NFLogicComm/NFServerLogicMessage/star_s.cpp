#include "star_s.h"

namespace proto_ff_s {

starpoint_s::starpoint_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int starpoint_s::CreateInit() {
	starID = (int32_t)0;
	starNum = (int32_t)0;
	return 0;
}

int starpoint_s::ResumeInit() {
	return 0;
}

void starpoint_s::write_to_pbmsg(::proto_ff::starpoint & msg) const {
	msg.set_starid((int32_t)starID);
	msg.set_starnum((int32_t)starNum);
}

void starpoint_s::read_from_pbmsg(const ::proto_ff::starpoint & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct starpoint_s));
	starID = msg.starid();
	starNum = msg.starnum();
}

Sheet_starpoint_s::Sheet_starpoint_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_starpoint_s::CreateInit() {
	return 0;
}

int Sheet_starpoint_s::ResumeInit() {
	return 0;
}

void Sheet_starpoint_s::write_to_pbmsg(::proto_ff::Sheet_starpoint & msg) const {
	for(int32_t i = 0; i < (int32_t)starpoint_List.GetSize() && i < starpoint_List.GetMaxSize(); ++i) {
		::proto_ff::starpoint* temp_starpoint_list = msg.add_starpoint_list();
		starpoint_List[i].write_to_pbmsg(*temp_starpoint_list);
	}
}

void Sheet_starpoint_s::read_from_pbmsg(const ::proto_ff::Sheet_starpoint & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_starpoint_s));
	starpoint_List.SetSize(msg.starpoint_list_size() > starpoint_List.GetMaxSize() ? starpoint_List.GetMaxSize() : msg.starpoint_list_size());
	for(int32_t i = 0; i < (int32_t)starpoint_List.GetSize(); ++i) {
		const ::proto_ff::starpoint & temp_starpoint_list = msg.starpoint_list(i);
		starpoint_List[i].read_from_pbmsg(temp_starpoint_list);
	}
}

starstarstarDesc_s::starstarstarDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int starstarstarDesc_s::CreateInit() {
	Att = (int32_t)0;
	Attnum = (int32_t)0;
	return 0;
}

int starstarstarDesc_s::ResumeInit() {
	return 0;
}

void starstarstarDesc_s::write_to_pbmsg(::proto_ff::starstarstarDesc & msg) const {
	msg.set_att((int32_t)Att);
	msg.set_attnum((int32_t)Attnum);
}

void starstarstarDesc_s::read_from_pbmsg(const ::proto_ff::starstarstarDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct starstarstarDesc_s));
	Att = msg.att();
	Attnum = msg.attnum();
}

starstar_s::starstar_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int starstar_s::CreateInit() {
	starID = (int64_t)0;
	starQuality = (int32_t)0;
	starNum = (int32_t)0;
	change = (int32_t)0;
	LvUp = (int32_t)0;
	starSq = (int32_t)0;
	starDs = (int32_t)0;
	rock = (int32_t)0;
	exp = (int32_t)0;
	starType = (int32_t)0;
	return 0;
}

int starstar_s::ResumeInit() {
	return 0;
}

void starstar_s::write_to_pbmsg(::proto_ff::starstar & msg) const {
	msg.set_starid((int64_t)starID);
	msg.set_starname((const char*)starName.Get());
	msg.set_starquality((int32_t)starQuality);
	msg.set_starnum((int32_t)starNum);
	msg.set_change((int32_t)change);
	msg.set_lvup((int32_t)LvUp);
	msg.set_starsq((int32_t)starSq);
	msg.set_stards((int32_t)starDs);
	msg.set_rock((int32_t)rock);
	msg.set_exp((int32_t)exp);
	msg.set_startype((int32_t)starType);
	for(int32_t i = 0; i < (int32_t)LvAdd.GetSize() && i < LvAdd.GetMaxSize(); ++i) {
		msg.add_lvadd((const char*)LvAdd[i].Get());
	}
	for(int32_t i = 0; i < (int32_t)star.GetSize() && i < star.GetMaxSize(); ++i) {
		::proto_ff::starstarstarDesc* temp_star = msg.add_star();
		star[i].write_to_pbmsg(*temp_star);
	}
}

void starstar_s::read_from_pbmsg(const ::proto_ff::starstar & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct starstar_s));
	starID = msg.starid();
	starName.Copy(msg.starname());
	starQuality = msg.starquality();
	starNum = msg.starnum();
	change = msg.change();
	LvUp = msg.lvup();
	starSq = msg.starsq();
	starDs = msg.stards();
	rock = msg.rock();
	exp = msg.exp();
	starType = msg.startype();
	LvAdd.SetSize(msg.lvadd_size() > LvAdd.GetMaxSize() ? LvAdd.GetMaxSize() : msg.lvadd_size());
	for(int32_t i = 0; i < (int32_t)LvAdd.GetSize(); ++i) {
		LvAdd[i].Copy(msg.lvadd(i));
	}
	star.SetSize(msg.star_size() > star.GetMaxSize() ? star.GetMaxSize() : msg.star_size());
	for(int32_t i = 0; i < (int32_t)star.GetSize(); ++i) {
		const ::proto_ff::starstarstarDesc & temp_star = msg.star(i);
		star[i].read_from_pbmsg(temp_star);
	}
}

Sheet_starstar_s::Sheet_starstar_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_starstar_s::CreateInit() {
	return 0;
}

int Sheet_starstar_s::ResumeInit() {
	return 0;
}

void Sheet_starstar_s::write_to_pbmsg(::proto_ff::Sheet_starstar & msg) const {
	for(int32_t i = 0; i < (int32_t)starstar_List.GetSize() && i < starstar_List.GetMaxSize(); ++i) {
		::proto_ff::starstar* temp_starstar_list = msg.add_starstar_list();
		starstar_List[i].write_to_pbmsg(*temp_starstar_list);
	}
}

void Sheet_starstar_s::read_from_pbmsg(const ::proto_ff::Sheet_starstar & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_starstar_s));
	starstar_List.SetSize(msg.starstar_list_size() > starstar_List.GetMaxSize() ? starstar_List.GetMaxSize() : msg.starstar_list_size());
	for(int32_t i = 0; i < (int32_t)starstar_List.GetSize(); ++i) {
		const ::proto_ff::starstar & temp_starstar_list = msg.starstar_list(i);
		starstar_List[i].read_from_pbmsg(temp_starstar_list);
	}
}

starexp_s::starexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int starexp_s::CreateInit() {
	id = (int64_t)0;
	starDs = (int32_t)0;
	starQuality = (int32_t)0;
	starLv = (int32_t)0;
	exp = (int32_t)0;
	return 0;
}

int starexp_s::ResumeInit() {
	return 0;
}

void starexp_s::write_to_pbmsg(::proto_ff::starexp & msg) const {
	msg.set_id((int64_t)id);
	msg.set_stards((int32_t)starDs);
	msg.set_starquality((int32_t)starQuality);
	msg.set_starlv((int32_t)starLv);
	msg.set_exp((int32_t)exp);
}

void starexp_s::read_from_pbmsg(const ::proto_ff::starexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct starexp_s));
	id = msg.id();
	starDs = msg.stards();
	starQuality = msg.starquality();
	starLv = msg.starlv();
	exp = msg.exp();
}

Sheet_starexp_s::Sheet_starexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_starexp_s::CreateInit() {
	return 0;
}

int Sheet_starexp_s::ResumeInit() {
	return 0;
}

void Sheet_starexp_s::write_to_pbmsg(::proto_ff::Sheet_starexp & msg) const {
	for(int32_t i = 0; i < (int32_t)starexp_List.GetSize() && i < starexp_List.GetMaxSize(); ++i) {
		::proto_ff::starexp* temp_starexp_list = msg.add_starexp_list();
		starexp_List[i].write_to_pbmsg(*temp_starexp_list);
	}
}

void Sheet_starexp_s::read_from_pbmsg(const ::proto_ff::Sheet_starexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_starexp_s));
	starexp_List.SetSize(msg.starexp_list_size() > starexp_List.GetMaxSize() ? starexp_List.GetMaxSize() : msg.starexp_list_size());
	for(int32_t i = 0; i < (int32_t)starexp_List.GetSize(); ++i) {
		const ::proto_ff::starexp & temp_starexp_list = msg.starexp_list(i);
		starexp_List[i].read_from_pbmsg(temp_starexp_list);
	}
}

starastrology_s::starastrology_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int starastrology_s::CreateInit() {
	astrology = (int32_t)0;
	itemId = (int64_t)0;
	itemNum = (int32_t)0;
	fragment = (int32_t)0;
	essence = (int32_t)0;
	time = (int32_t)0;
	coinTye = (int32_t)0;
	number = (int32_t)0;
	return 0;
}

int starastrology_s::ResumeInit() {
	return 0;
}

void starastrology_s::write_to_pbmsg(::proto_ff::starastrology & msg) const {
	msg.set_astrology((int32_t)astrology);
	msg.set_itemid((int64_t)itemId);
	msg.set_itemnum((int32_t)itemNum);
	msg.set_fragment((int32_t)fragment);
	msg.set_essence((int32_t)essence);
	msg.set_time((int32_t)time);
	msg.set_cointye((int32_t)coinTye);
	msg.set_number((int32_t)number);
		msg.add_gailv((int32_t)gailv[i]);
	}
		msg.add_probability((int32_t)probability[i]);
	}
}

void starastrology_s::read_from_pbmsg(const ::proto_ff::starastrology & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct starastrology_s));
	astrology = msg.astrology();
	itemId = msg.itemid();
	itemNum = msg.itemnum();
	fragment = msg.fragment();
	essence = msg.essence();
	time = msg.time();
	coinTye = msg.cointye();
	number = msg.number();
		gailv[i] = msg.gailv(i);
	}
		probability[i] = msg.probability(i);
	}
}

Sheet_starastrology_s::Sheet_starastrology_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_starastrology_s::CreateInit() {
	return 0;
}

int Sheet_starastrology_s::ResumeInit() {
	return 0;
}

void Sheet_starastrology_s::write_to_pbmsg(::proto_ff::Sheet_starastrology & msg) const {
	for(int32_t i = 0; i < (int32_t)starastrology_List.GetSize() && i < starastrology_List.GetMaxSize(); ++i) {
		::proto_ff::starastrology* temp_starastrology_list = msg.add_starastrology_list();
		starastrology_List[i].write_to_pbmsg(*temp_starastrology_list);
	}
}

void Sheet_starastrology_s::read_from_pbmsg(const ::proto_ff::Sheet_starastrology & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_starastrology_s));
	starastrology_List.SetSize(msg.starastrology_list_size() > starastrology_List.GetMaxSize() ? starastrology_List.GetMaxSize() : msg.starastrology_list_size());
	for(int32_t i = 0; i < (int32_t)starastrology_List.GetSize(); ++i) {
		const ::proto_ff::starastrology & temp_starastrology_list = msg.starastrology_list(i);
		starastrology_List[i].read_from_pbmsg(temp_starastrology_list);
	}
}

}