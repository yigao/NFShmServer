#include "festival_s.h"

namespace proto_ff_s {

festivalmuban_JFduihuan_s::festivalmuban_JFduihuan_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_JFduihuan_s::CreateInit() {
	tiaoJianId = (int32_t)0;
	prizeId = (int64_t)0;
	prof = (int32_t)0;
	prizeNum = (int32_t)0;
	propId = (int64_t)0;
	propNum = (int32_t)0;
	times = (int32_t)0;
	return 0;
}

int festivalmuban_JFduihuan_s::ResumeInit() {
	return 0;
}

void festivalmuban_JFduihuan_s::write_to_pbmsg(::proto_ff::festivalmuban_JFduihuan & msg) const {
	msg.set_tiaojianid((int32_t)tiaoJianId);
	msg.set_prizeid((int64_t)prizeId);
	msg.set_prof((int32_t)prof);
	msg.set_prizenum((int32_t)prizeNum);
	msg.set_propid((int64_t)propId);
	msg.set_propnum((int32_t)propNum);
	msg.set_times((int32_t)times);
}

void festivalmuban_JFduihuan_s::read_from_pbmsg(const ::proto_ff::festivalmuban_JFduihuan & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_JFduihuan_s));
	tiaoJianId = msg.tiaojianid();
	prizeId = msg.prizeid();
	prof = msg.prof();
	prizeNum = msg.prizenum();
	propId = msg.propid();
	propNum = msg.propnum();
	times = msg.times();
}

Sheet_festivalmuban_JFduihuan_s::Sheet_festivalmuban_JFduihuan_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_JFduihuan_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_JFduihuan_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_JFduihuan_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_JFduihuan & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_JFduihuan_List.GetSize() && i < festivalmuban_JFduihuan_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_JFduihuan* temp_festivalmuban_jfduihuan_list = msg.add_festivalmuban_jfduihuan_list();
		festivalmuban_JFduihuan_List[i].write_to_pbmsg(*temp_festivalmuban_jfduihuan_list);
	}
}

void Sheet_festivalmuban_JFduihuan_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_JFduihuan & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_JFduihuan_s));
	festivalmuban_JFduihuan_List.SetSize(msg.festivalmuban_jfduihuan_list_size() > festivalmuban_JFduihuan_List.GetMaxSize() ? festivalmuban_JFduihuan_List.GetMaxSize() : msg.festivalmuban_jfduihuan_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_JFduihuan_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_JFduihuan & temp_festivalmuban_jfduihuan_list = msg.festivalmuban_jfduihuan_list(i);
		festivalmuban_JFduihuan_List[i].read_from_pbmsg(temp_festivalmuban_jfduihuan_list);
	}
}

festivalmuban_dingzhi_s::festivalmuban_dingzhi_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_dingzhi_s::CreateInit() {
	id = (int32_t)0;
	mustBoxId = (int64_t)0;
	currencyType = (int32_t)0;
	price = (int32_t)0;
	times = (int32_t)0;
	return 0;
}

int festivalmuban_dingzhi_s::ResumeInit() {
	return 0;
}

void festivalmuban_dingzhi_s::write_to_pbmsg(::proto_ff::festivalmuban_dingzhi & msg) const {
	msg.set_id((int32_t)id);
	msg.set_des((const char*)des.Get());
	msg.set_mustboxid((int64_t)mustBoxId);
	msg.set_currencytype((int32_t)currencyType);
	msg.set_price((int32_t)price);
	msg.set_times((int32_t)times);
		msg.add_freeboxid((int64_t)freeBoxId[i]);
	}
		msg.add_freenum((int32_t)freeNum[i]);
	}
}

void festivalmuban_dingzhi_s::read_from_pbmsg(const ::proto_ff::festivalmuban_dingzhi & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_dingzhi_s));
	id = msg.id();
	des.Copy(msg.des());
	mustBoxId = msg.mustboxid();
	currencyType = msg.currencytype();
	price = msg.price();
	times = msg.times();
		freeBoxId[i] = msg.freeboxid(i);
	}
		freeNum[i] = msg.freenum(i);
	}
}

Sheet_festivalmuban_dingzhi_s::Sheet_festivalmuban_dingzhi_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_dingzhi_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_dingzhi_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_dingzhi_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_dingzhi & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_dingzhi_List.GetSize() && i < festivalmuban_dingzhi_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_dingzhi* temp_festivalmuban_dingzhi_list = msg.add_festivalmuban_dingzhi_list();
		festivalmuban_dingzhi_List[i].write_to_pbmsg(*temp_festivalmuban_dingzhi_list);
	}
}

void Sheet_festivalmuban_dingzhi_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_dingzhi & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_dingzhi_s));
	festivalmuban_dingzhi_List.SetSize(msg.festivalmuban_dingzhi_list_size() > festivalmuban_dingzhi_List.GetMaxSize() ? festivalmuban_dingzhi_List.GetMaxSize() : msg.festivalmuban_dingzhi_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_dingzhi_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_dingzhi & temp_festivalmuban_dingzhi_list = msg.festivalmuban_dingzhi_list(i);
		festivalmuban_dingzhi_List[i].read_from_pbmsg(temp_festivalmuban_dingzhi_list);
	}
}

festivalmuban_CZfanzuan_s::festivalmuban_CZfanzuan_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_CZfanzuan_s::CreateInit() {
	id = (int32_t)0;
	rechargeId = (int32_t)0;
	repayType = (int32_t)0;
	repayNum = (int32_t)0;
	timesLimit = (int32_t)0;
	return 0;
}

int festivalmuban_CZfanzuan_s::ResumeInit() {
	return 0;
}

void festivalmuban_CZfanzuan_s::write_to_pbmsg(::proto_ff::festivalmuban_CZfanzuan & msg) const {
	msg.set_id((int32_t)id);
	msg.set_rechargeid((int32_t)rechargeId);
	msg.set_repaytype((int32_t)repayType);
	msg.set_repaynum((int32_t)repayNum);
	msg.set_timeslimit((int32_t)timesLimit);
}

void festivalmuban_CZfanzuan_s::read_from_pbmsg(const ::proto_ff::festivalmuban_CZfanzuan & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_CZfanzuan_s));
	id = msg.id();
	rechargeId = msg.rechargeid();
	repayType = msg.repaytype();
	repayNum = msg.repaynum();
	timesLimit = msg.timeslimit();
}

Sheet_festivalmuban_CZfanzuan_s::Sheet_festivalmuban_CZfanzuan_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_CZfanzuan_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_CZfanzuan_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_CZfanzuan_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_CZfanzuan & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_CZfanzuan_List.GetSize() && i < festivalmuban_CZfanzuan_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_CZfanzuan* temp_festivalmuban_czfanzuan_list = msg.add_festivalmuban_czfanzuan_list();
		festivalmuban_CZfanzuan_List[i].write_to_pbmsg(*temp_festivalmuban_czfanzuan_list);
	}
}

void Sheet_festivalmuban_CZfanzuan_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_CZfanzuan & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_CZfanzuan_s));
	festivalmuban_CZfanzuan_List.SetSize(msg.festivalmuban_czfanzuan_list_size() > festivalmuban_CZfanzuan_List.GetMaxSize() ? festivalmuban_CZfanzuan_List.GetMaxSize() : msg.festivalmuban_czfanzuan_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_CZfanzuan_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_CZfanzuan & temp_festivalmuban_czfanzuan_list = msg.festivalmuban_czfanzuan_list(i);
		festivalmuban_CZfanzuan_List[i].read_from_pbmsg(temp_festivalmuban_czfanzuan_list);
	}
}

festivalmuban_lianxuCZ_s::festivalmuban_lianxuCZ_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_lianxuCZ_s::CreateInit() {
	id = (int32_t)0;
	Num = (int32_t)0;
	remarkId = (int32_t)0;
	jiangLi = (int64_t)0;
	return 0;
}

int festivalmuban_lianxuCZ_s::ResumeInit() {
	return 0;
}

void festivalmuban_lianxuCZ_s::write_to_pbmsg(::proto_ff::festivalmuban_lianxuCZ & msg) const {
	msg.set_id((int32_t)id);
	msg.set_num((int32_t)Num);
	msg.set_remarkid((int32_t)remarkId);
	msg.set_miaoshu((const char*)miaoshu.Get());
	msg.set_jiangli((int64_t)jiangLi);
}

void festivalmuban_lianxuCZ_s::read_from_pbmsg(const ::proto_ff::festivalmuban_lianxuCZ & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_lianxuCZ_s));
	id = msg.id();
	Num = msg.num();
	remarkId = msg.remarkid();
	miaoshu.Copy(msg.miaoshu());
	jiangLi = msg.jiangli();
}

Sheet_festivalmuban_lianxuCZ_s::Sheet_festivalmuban_lianxuCZ_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_lianxuCZ_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_lianxuCZ_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_lianxuCZ_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_lianxuCZ & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_lianxuCZ_List.GetSize() && i < festivalmuban_lianxuCZ_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_lianxuCZ* temp_festivalmuban_lianxucz_list = msg.add_festivalmuban_lianxucz_list();
		festivalmuban_lianxuCZ_List[i].write_to_pbmsg(*temp_festivalmuban_lianxucz_list);
	}
}

void Sheet_festivalmuban_lianxuCZ_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_lianxuCZ & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_lianxuCZ_s));
	festivalmuban_lianxuCZ_List.SetSize(msg.festivalmuban_lianxucz_list_size() > festivalmuban_lianxuCZ_List.GetMaxSize() ? festivalmuban_lianxuCZ_List.GetMaxSize() : msg.festivalmuban_lianxucz_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_lianxuCZ_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_lianxuCZ & temp_festivalmuban_lianxucz_list = msg.festivalmuban_lianxucz_list(i);
		festivalmuban_lianxuCZ_List[i].read_from_pbmsg(temp_festivalmuban_lianxucz_list);
	}
}

festivalmuban_prerecharge_s::festivalmuban_prerecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_prerecharge_s::CreateInit() {
	id = (int32_t)0;
	order = (int32_t)0;
	boxid = (int64_t)0;
	rechargeId = (int32_t)0;
	times = (int32_t)0;
	return 0;
}

int festivalmuban_prerecharge_s::ResumeInit() {
	return 0;
}

void festivalmuban_prerecharge_s::write_to_pbmsg(::proto_ff::festivalmuban_prerecharge & msg) const {
	msg.set_id((int32_t)id);
	msg.set_order((int32_t)order);
	msg.set_des((const char*)des.Get());
	msg.set_boxid((int64_t)boxid);
	msg.set_rechargeid((int32_t)rechargeId);
	msg.set_times((int32_t)times);
}

void festivalmuban_prerecharge_s::read_from_pbmsg(const ::proto_ff::festivalmuban_prerecharge & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_prerecharge_s));
	id = msg.id();
	order = msg.order();
	des.Copy(msg.des());
	boxid = msg.boxid();
	rechargeId = msg.rechargeid();
	times = msg.times();
}

Sheet_festivalmuban_prerecharge_s::Sheet_festivalmuban_prerecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_prerecharge_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_prerecharge_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_prerecharge_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_prerecharge & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_prerecharge_List.GetSize() && i < festivalmuban_prerecharge_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_prerecharge* temp_festivalmuban_prerecharge_list = msg.add_festivalmuban_prerecharge_list();
		festivalmuban_prerecharge_List[i].write_to_pbmsg(*temp_festivalmuban_prerecharge_list);
	}
}

void Sheet_festivalmuban_prerecharge_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_prerecharge & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_prerecharge_s));
	festivalmuban_prerecharge_List.SetSize(msg.festivalmuban_prerecharge_list_size() > festivalmuban_prerecharge_List.GetMaxSize() ? festivalmuban_prerecharge_List.GetMaxSize() : msg.festivalmuban_prerecharge_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_prerecharge_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_prerecharge & temp_festivalmuban_prerecharge_list = msg.festivalmuban_prerecharge_list(i);
		festivalmuban_prerecharge_List[i].read_from_pbmsg(temp_festivalmuban_prerecharge_list);
	}
}

festivalmuban_doubleGift_s::festivalmuban_doubleGift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_doubleGift_s::CreateInit() {
	id = (int32_t)0;
	gear = (int32_t)0;
	boxId = (int64_t)0;
	freeBox = (int64_t)0;
	return 0;
}

int festivalmuban_doubleGift_s::ResumeInit() {
	return 0;
}

void festivalmuban_doubleGift_s::write_to_pbmsg(::proto_ff::festivalmuban_doubleGift & msg) const {
	msg.set_id((int32_t)id);
	msg.set_gear((int32_t)gear);
	msg.set_boxid((int64_t)boxId);
	msg.set_freebox((int64_t)freeBox);
}

void festivalmuban_doubleGift_s::read_from_pbmsg(const ::proto_ff::festivalmuban_doubleGift & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_doubleGift_s));
	id = msg.id();
	gear = msg.gear();
	boxId = msg.boxid();
	freeBox = msg.freebox();
}

Sheet_festivalmuban_doubleGift_s::Sheet_festivalmuban_doubleGift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_doubleGift_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_doubleGift_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_doubleGift_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_doubleGift & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_doubleGift_List.GetSize() && i < festivalmuban_doubleGift_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_doubleGift* temp_festivalmuban_doublegift_list = msg.add_festivalmuban_doublegift_list();
		festivalmuban_doubleGift_List[i].write_to_pbmsg(*temp_festivalmuban_doublegift_list);
	}
}

void Sheet_festivalmuban_doubleGift_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_doubleGift & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_doubleGift_s));
	festivalmuban_doubleGift_List.SetSize(msg.festivalmuban_doublegift_list_size() > festivalmuban_doubleGift_List.GetMaxSize() ? festivalmuban_doubleGift_List.GetMaxSize() : msg.festivalmuban_doublegift_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_doubleGift_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_doubleGift & temp_festivalmuban_doublegift_list = msg.festivalmuban_doublegift_list(i);
		festivalmuban_doubleGift_List[i].read_from_pbmsg(temp_festivalmuban_doublegift_list);
	}
}

festivalbigyanhuarecharge_s::festivalbigyanhuarecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalbigyanhuarecharge_s::CreateInit() {
	num = (int32_t)0;
	recharge = (int32_t)0;
	return 0;
}

int festivalbigyanhuarecharge_s::ResumeInit() {
	return 0;
}

void festivalbigyanhuarecharge_s::write_to_pbmsg(::proto_ff::festivalbigyanhuarecharge & msg) const {
	msg.set_num((int32_t)num);
	msg.set_recharge((int32_t)recharge);
}

void festivalbigyanhuarecharge_s::read_from_pbmsg(const ::proto_ff::festivalbigyanhuarecharge & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalbigyanhuarecharge_s));
	num = msg.num();
	recharge = msg.recharge();
}

Sheet_festivalbigyanhuarecharge_s::Sheet_festivalbigyanhuarecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalbigyanhuarecharge_s::CreateInit() {
	return 0;
}

int Sheet_festivalbigyanhuarecharge_s::ResumeInit() {
	return 0;
}

void Sheet_festivalbigyanhuarecharge_s::write_to_pbmsg(::proto_ff::Sheet_festivalbigyanhuarecharge & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalbigyanhuarecharge_List.GetSize() && i < festivalbigyanhuarecharge_List.GetMaxSize(); ++i) {
		::proto_ff::festivalbigyanhuarecharge* temp_festivalbigyanhuarecharge_list = msg.add_festivalbigyanhuarecharge_list();
		festivalbigyanhuarecharge_List[i].write_to_pbmsg(*temp_festivalbigyanhuarecharge_list);
	}
}

void Sheet_festivalbigyanhuarecharge_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalbigyanhuarecharge & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalbigyanhuarecharge_s));
	festivalbigyanhuarecharge_List.SetSize(msg.festivalbigyanhuarecharge_list_size() > festivalbigyanhuarecharge_List.GetMaxSize() ? festivalbigyanhuarecharge_List.GetMaxSize() : msg.festivalbigyanhuarecharge_list_size());
	for(int32_t i = 0; i < (int32_t)festivalbigyanhuarecharge_List.GetSize(); ++i) {
		const ::proto_ff::festivalbigyanhuarecharge & temp_festivalbigyanhuarecharge_list = msg.festivalbigyanhuarecharge_list(i);
		festivalbigyanhuarecharge_List[i].read_from_pbmsg(temp_festivalbigyanhuarecharge_list);
	}
}

festivalbigyanhuacost_s::festivalbigyanhuacost_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalbigyanhuacost_s::CreateInit() {
	times = (int32_t)0;
	singleCost = (int32_t)0;
	allCost = (int32_t)0;
	return 0;
}

int festivalbigyanhuacost_s::ResumeInit() {
	return 0;
}

void festivalbigyanhuacost_s::write_to_pbmsg(::proto_ff::festivalbigyanhuacost & msg) const {
	msg.set_times((int32_t)times);
	msg.set_singlecost((int32_t)singleCost);
	msg.set_allcost((int32_t)allCost);
}

void festivalbigyanhuacost_s::read_from_pbmsg(const ::proto_ff::festivalbigyanhuacost & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalbigyanhuacost_s));
	times = msg.times();
	singleCost = msg.singlecost();
	allCost = msg.allcost();
}

Sheet_festivalbigyanhuacost_s::Sheet_festivalbigyanhuacost_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalbigyanhuacost_s::CreateInit() {
	return 0;
}

int Sheet_festivalbigyanhuacost_s::ResumeInit() {
	return 0;
}

void Sheet_festivalbigyanhuacost_s::write_to_pbmsg(::proto_ff::Sheet_festivalbigyanhuacost & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalbigyanhuacost_List.GetSize() && i < festivalbigyanhuacost_List.GetMaxSize(); ++i) {
		::proto_ff::festivalbigyanhuacost* temp_festivalbigyanhuacost_list = msg.add_festivalbigyanhuacost_list();
		festivalbigyanhuacost_List[i].write_to_pbmsg(*temp_festivalbigyanhuacost_list);
	}
}

void Sheet_festivalbigyanhuacost_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalbigyanhuacost & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalbigyanhuacost_s));
	festivalbigyanhuacost_List.SetSize(msg.festivalbigyanhuacost_list_size() > festivalbigyanhuacost_List.GetMaxSize() ? festivalbigyanhuacost_List.GetMaxSize() : msg.festivalbigyanhuacost_list_size());
	for(int32_t i = 0; i < (int32_t)festivalbigyanhuacost_List.GetSize(); ++i) {
		const ::proto_ff::festivalbigyanhuacost & temp_festivalbigyanhuacost_list = msg.festivalbigyanhuacost_list(i);
		festivalbigyanhuacost_List[i].read_from_pbmsg(temp_festivalbigyanhuacost_list);
	}
}

festivalmuban_bigyanhua_s::festivalmuban_bigyanhua_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_bigyanhua_s::CreateInit() {
	id = (int32_t)0;
	itemid = (int64_t)0;
	num = (int32_t)0;
	prof = (int32_t)0;
	type = (int32_t)0;
	order = (int32_t)0;
	probability = (int32_t)0;
	relation = (int64_t)0;
	modelid = (int64_t)0;
	modeltype = (int32_t)0;
	return 0;
}

int festivalmuban_bigyanhua_s::ResumeInit() {
	return 0;
}

void festivalmuban_bigyanhua_s::write_to_pbmsg(::proto_ff::festivalmuban_bigyanhua & msg) const {
	msg.set_id((int32_t)id);
	msg.set_itemid((int64_t)itemid);
	msg.set_num((int32_t)num);
	msg.set_prof((int32_t)prof);
	msg.set_type((int32_t)type);
	msg.set_order((int32_t)order);
	msg.set_probability((int32_t)probability);
	msg.set_relation((int64_t)relation);
	msg.set_modelid((int64_t)modelid);
	msg.set_modeltype((int32_t)modeltype);
	msg.set_scale((const char*)scale.Get());
}

void festivalmuban_bigyanhua_s::read_from_pbmsg(const ::proto_ff::festivalmuban_bigyanhua & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_bigyanhua_s));
	id = msg.id();
	itemid = msg.itemid();
	num = msg.num();
	prof = msg.prof();
	type = msg.type();
	order = msg.order();
	probability = msg.probability();
	relation = msg.relation();
	modelid = msg.modelid();
	modeltype = msg.modeltype();
	scale.Copy(msg.scale());
}

Sheet_festivalmuban_bigyanhua_s::Sheet_festivalmuban_bigyanhua_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_bigyanhua_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_bigyanhua_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_bigyanhua_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_bigyanhua & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_bigyanhua_List.GetSize() && i < festivalmuban_bigyanhua_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_bigyanhua* temp_festivalmuban_bigyanhua_list = msg.add_festivalmuban_bigyanhua_list();
		festivalmuban_bigyanhua_List[i].write_to_pbmsg(*temp_festivalmuban_bigyanhua_list);
	}
}

void Sheet_festivalmuban_bigyanhua_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_bigyanhua & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_bigyanhua_s));
	festivalmuban_bigyanhua_List.SetSize(msg.festivalmuban_bigyanhua_list_size() > festivalmuban_bigyanhua_List.GetMaxSize() ? festivalmuban_bigyanhua_List.GetMaxSize() : msg.festivalmuban_bigyanhua_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_bigyanhua_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_bigyanhua & temp_festivalmuban_bigyanhua_list = msg.festivalmuban_bigyanhua_list(i);
		festivalmuban_bigyanhua_List[i].read_from_pbmsg(temp_festivalmuban_bigyanhua_list);
	}
}

festivalfestival_s::festivalfestival_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalfestival_s::CreateInit() {
	id = (int64_t)0;
	huoDongType = (int32_t)0;
	nameId = (int32_t)0;
	servertype = (int32_t)0;
	timeType = (int32_t)0;
	Level = (int32_t)0;
	vipLevel = (int32_t)0;
	rechange = (int32_t)0;
	ifOpen = (int32_t)0;
	loginPopPriority = (int32_t)0;
	belong = (int32_t)0;
	return 0;
}

int festivalfestival_s::ResumeInit() {
	return 0;
}

void festivalfestival_s::write_to_pbmsg(::proto_ff::festivalfestival & msg) const {
	msg.set_id((int64_t)id);
	msg.set_huodongtype((int32_t)huoDongType);
	msg.set_nameid((int32_t)nameId);
	msg.set_name((const char*)name.Get());
	msg.set_servertype((int32_t)servertype);
	msg.set_timea((const char*)timeA.Get());
	msg.set_timeb((const char*)timeB.Get());
	msg.set_timetype((int32_t)timeType);
	msg.set_level((int32_t)Level);
	msg.set_viplevel((int32_t)vipLevel);
	msg.set_rechange((int32_t)rechange);
	msg.set_ifopen((int32_t)ifOpen);
	msg.set_list((const char*)list.Get());
	msg.set_icon((const char*)icon.Get());
	msg.set_loginpoppriority((int32_t)loginPopPriority);
	msg.set_belong((int32_t)belong);
}

void festivalfestival_s::read_from_pbmsg(const ::proto_ff::festivalfestival & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalfestival_s));
	id = msg.id();
	huoDongType = msg.huodongtype();
	nameId = msg.nameid();
	name.Copy(msg.name());
	servertype = msg.servertype();
	timeA.Copy(msg.timea());
	timeB.Copy(msg.timeb());
	timeType = msg.timetype();
	Level = msg.level();
	vipLevel = msg.viplevel();
	rechange = msg.rechange();
	ifOpen = msg.ifopen();
	list.Copy(msg.list());
	icon.Copy(msg.icon());
	loginPopPriority = msg.loginpoppriority();
	belong = msg.belong();
}

Sheet_festivalfestival_s::Sheet_festivalfestival_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalfestival_s::CreateInit() {
	return 0;
}

int Sheet_festivalfestival_s::ResumeInit() {
	return 0;
}

void Sheet_festivalfestival_s::write_to_pbmsg(::proto_ff::Sheet_festivalfestival & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalfestival_List.GetSize() && i < festivalfestival_List.GetMaxSize(); ++i) {
		::proto_ff::festivalfestival* temp_festivalfestival_list = msg.add_festivalfestival_list();
		festivalfestival_List[i].write_to_pbmsg(*temp_festivalfestival_list);
	}
}

void Sheet_festivalfestival_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalfestival & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalfestival_s));
	festivalfestival_List.SetSize(msg.festivalfestival_list_size() > festivalfestival_List.GetMaxSize() ? festivalfestival_List.GetMaxSize() : msg.festivalfestival_list_size());
	for(int32_t i = 0; i < (int32_t)festivalfestival_List.GetSize(); ++i) {
		const ::proto_ff::festivalfestival & temp_festivalfestival_list = msg.festivalfestival_list(i);
		festivalfestival_List[i].read_from_pbmsg(temp_festivalfestival_list);
	}
}

festivaltemplate_s::festivaltemplate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivaltemplate_s::CreateInit() {
	id = (int32_t)0;
	muBan = (int32_t)0;
	order = (int32_t)0;
	nameId = (int32_t)0;
	timeType = (int32_t)0;
	level = (int32_t)0;
	vipLevel = (int32_t)0;
	rechange = (int32_t)0;
	remarkId = (int32_t)0;
	jiangLi = (int64_t)0;
	return 0;
}

int festivaltemplate_s::ResumeInit() {
	return 0;
}

void festivaltemplate_s::write_to_pbmsg(::proto_ff::festivaltemplate & msg) const {
	msg.set_id((int32_t)id);
	msg.set_muban((int32_t)muBan);
	msg.set_order((int32_t)order);
	msg.set_list((const char*)list.Get());
	msg.set_nameid((int32_t)nameId);
	msg.set_name((const char*)Name.Get());
	msg.set_type((const char*)type.Get());
	msg.set_timea((const char*)timeA.Get());
	msg.set_timeb((const char*)timeB.Get());
	msg.set_timetype((int32_t)timeType);
	msg.set_level((int32_t)level);
	msg.set_viplevel((int32_t)vipLevel);
	msg.set_rechange((int32_t)rechange);
	msg.set_remarkid((int32_t)remarkId);
	msg.set_miaoshu((const char*)MiaoShu.Get());
	msg.set_jiangli((int64_t)jiangLi);
	msg.set_beijing((const char*)beiJing.Get());
	msg.set_title((const char*)title.Get());
	msg.set_desc((const char*)desc.Get());
}

void festivaltemplate_s::read_from_pbmsg(const ::proto_ff::festivaltemplate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivaltemplate_s));
	id = msg.id();
	muBan = msg.muban();
	order = msg.order();
	list.Copy(msg.list());
	nameId = msg.nameid();
	Name.Copy(msg.name());
	type.Copy(msg.type());
	timeA.Copy(msg.timea());
	timeB.Copy(msg.timeb());
	timeType = msg.timetype();
	level = msg.level();
	vipLevel = msg.viplevel();
	rechange = msg.rechange();
	remarkId = msg.remarkid();
	MiaoShu.Copy(msg.miaoshu());
	jiangLi = msg.jiangli();
	beiJing.Copy(msg.beijing());
	title.Copy(msg.title());
	desc.Copy(msg.desc());
}

Sheet_festivaltemplate_s::Sheet_festivaltemplate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivaltemplate_s::CreateInit() {
	return 0;
}

int Sheet_festivaltemplate_s::ResumeInit() {
	return 0;
}

void Sheet_festivaltemplate_s::write_to_pbmsg(::proto_ff::Sheet_festivaltemplate & msg) const {
	for(int32_t i = 0; i < (int32_t)festivaltemplate_List.GetSize() && i < festivaltemplate_List.GetMaxSize(); ++i) {
		::proto_ff::festivaltemplate* temp_festivaltemplate_list = msg.add_festivaltemplate_list();
		festivaltemplate_List[i].write_to_pbmsg(*temp_festivaltemplate_list);
	}
}

void Sheet_festivaltemplate_s::read_from_pbmsg(const ::proto_ff::Sheet_festivaltemplate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivaltemplate_s));
	festivaltemplate_List.SetSize(msg.festivaltemplate_list_size() > festivaltemplate_List.GetMaxSize() ? festivaltemplate_List.GetMaxSize() : msg.festivaltemplate_list_size());
	for(int32_t i = 0; i < (int32_t)festivaltemplate_List.GetSize(); ++i) {
		const ::proto_ff::festivaltemplate & temp_festivaltemplate_list = msg.festivaltemplate_list(i);
		festivaltemplate_List[i].read_from_pbmsg(temp_festivaltemplate_list);
	}
}

festivalmuban_worldboss_s::festivalmuban_worldboss_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_worldboss_s::CreateInit() {
	id = (int32_t)0;
	bossid = (int32_t)0;
	sort = (int32_t)0;
	conditionType = (int32_t)0;
	condition = (int32_t)0;
	boxId = (int64_t)0;
	return 0;
}

int festivalmuban_worldboss_s::ResumeInit() {
	return 0;
}

void festivalmuban_worldboss_s::write_to_pbmsg(::proto_ff::festivalmuban_worldboss & msg) const {
	msg.set_id((int32_t)id);
	msg.set_bossid((int32_t)bossid);
	msg.set_sort((int32_t)sort);
	msg.set_conditiontype((int32_t)conditionType);
	msg.set_condition((int32_t)condition);
	msg.set_des((const char*)des.Get());
	msg.set_boxid((int64_t)boxId);
}

void festivalmuban_worldboss_s::read_from_pbmsg(const ::proto_ff::festivalmuban_worldboss & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_worldboss_s));
	id = msg.id();
	bossid = msg.bossid();
	sort = msg.sort();
	conditionType = msg.conditiontype();
	condition = msg.condition();
	des.Copy(msg.des());
	boxId = msg.boxid();
}

Sheet_festivalmuban_worldboss_s::Sheet_festivalmuban_worldboss_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_worldboss_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_worldboss_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_worldboss_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_worldboss & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_worldboss_List.GetSize() && i < festivalmuban_worldboss_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_worldboss* temp_festivalmuban_worldboss_list = msg.add_festivalmuban_worldboss_list();
		festivalmuban_worldboss_List[i].write_to_pbmsg(*temp_festivalmuban_worldboss_list);
	}
}

void Sheet_festivalmuban_worldboss_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_worldboss & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_worldboss_s));
	festivalmuban_worldboss_List.SetSize(msg.festivalmuban_worldboss_list_size() > festivalmuban_worldboss_List.GetMaxSize() ? festivalmuban_worldboss_List.GetMaxSize() : msg.festivalmuban_worldboss_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_worldboss_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_worldboss & temp_festivalmuban_worldboss_list = msg.festivalmuban_worldboss_list(i);
		festivalmuban_worldboss_List[i].read_from_pbmsg(temp_festivalmuban_worldboss_list);
	}
}

festivalmuban_libao_s::festivalmuban_libao_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_libao_s::CreateInit() {
	id = (int32_t)0;
	boxid = (int64_t)0;
	term = (int32_t)0;
	level = (int32_t)0;
	currencyType = (int32_t)0;
	price = (int32_t)0;
	backType = (int32_t)0;
	dayBack = (int32_t)0;
	return 0;
}

int festivalmuban_libao_s::ResumeInit() {
	return 0;
}

void festivalmuban_libao_s::write_to_pbmsg(::proto_ff::festivalmuban_libao & msg) const {
	msg.set_id((int32_t)id);
	msg.set_boxid((int64_t)boxid);
	msg.set_term((int32_t)term);
	msg.set_level((int32_t)level);
	msg.set_currencytype((int32_t)currencyType);
	msg.set_price((int32_t)price);
	msg.set_backtype((int32_t)backType);
	msg.set_dayback((int32_t)dayBack);
}

void festivalmuban_libao_s::read_from_pbmsg(const ::proto_ff::festivalmuban_libao & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_libao_s));
	id = msg.id();
	boxid = msg.boxid();
	term = msg.term();
	level = msg.level();
	currencyType = msg.currencytype();
	price = msg.price();
	backType = msg.backtype();
	dayBack = msg.dayback();
}

Sheet_festivalmuban_libao_s::Sheet_festivalmuban_libao_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_libao_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_libao_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_libao_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_libao & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_libao_List.GetSize() && i < festivalmuban_libao_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_libao* temp_festivalmuban_libao_list = msg.add_festivalmuban_libao_list();
		festivalmuban_libao_List[i].write_to_pbmsg(*temp_festivalmuban_libao_list);
	}
}

void Sheet_festivalmuban_libao_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_libao & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_libao_s));
	festivalmuban_libao_List.SetSize(msg.festivalmuban_libao_list_size() > festivalmuban_libao_List.GetMaxSize() ? festivalmuban_libao_List.GetMaxSize() : msg.festivalmuban_libao_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_libao_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_libao & temp_festivalmuban_libao_list = msg.festivalmuban_libao_list(i);
		festivalmuban_libao_List[i].read_from_pbmsg(temp_festivalmuban_libao_list);
	}
}

festivalmuban_double_s::festivalmuban_double_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_double_s::CreateInit() {
	id = (int32_t)0;
	gear = (int32_t)0;
	boxId = (int64_t)0;
	return 0;
}

int festivalmuban_double_s::ResumeInit() {
	return 0;
}

void festivalmuban_double_s::write_to_pbmsg(::proto_ff::festivalmuban_double & msg) const {
	msg.set_id((int32_t)id);
	msg.set_gear((int32_t)gear);
	msg.set_boxid((int64_t)boxId);
}

void festivalmuban_double_s::read_from_pbmsg(const ::proto_ff::festivalmuban_double & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_double_s));
	id = msg.id();
	gear = msg.gear();
	boxId = msg.boxid();
}

Sheet_festivalmuban_double_s::Sheet_festivalmuban_double_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_double_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_double_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_double_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_double & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_double_List.GetSize() && i < festivalmuban_double_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_double* temp_festivalmuban_double_list = msg.add_festivalmuban_double_list();
		festivalmuban_double_List[i].write_to_pbmsg(*temp_festivalmuban_double_list);
	}
}

void Sheet_festivalmuban_double_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_double & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_double_s));
	festivalmuban_double_List.SetSize(msg.festivalmuban_double_list_size() > festivalmuban_double_List.GetMaxSize() ? festivalmuban_double_List.GetMaxSize() : msg.festivalmuban_double_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_double_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_double & temp_festivalmuban_double_list = msg.festivalmuban_double_list(i);
		festivalmuban_double_List[i].read_from_pbmsg(temp_festivalmuban_double_list);
	}
}

festivalmiaoshu_s::festivalmiaoshu_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmiaoshu_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int festivalmiaoshu_s::ResumeInit() {
	return 0;
}

void festivalmiaoshu_s::write_to_pbmsg(::proto_ff::festivalmiaoshu & msg) const {
	msg.set_id((int32_t)id);
	msg.set_wenzi((const char*)wenzi.Get());
}

void festivalmiaoshu_s::read_from_pbmsg(const ::proto_ff::festivalmiaoshu & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmiaoshu_s));
	id = msg.id();
	wenzi.Copy(msg.wenzi());
}

Sheet_festivalmiaoshu_s::Sheet_festivalmiaoshu_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmiaoshu_s::CreateInit() {
	return 0;
}

int Sheet_festivalmiaoshu_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmiaoshu_s::write_to_pbmsg(::proto_ff::Sheet_festivalmiaoshu & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmiaoshu_List.GetSize() && i < festivalmiaoshu_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmiaoshu* temp_festivalmiaoshu_list = msg.add_festivalmiaoshu_list();
		festivalmiaoshu_List[i].write_to_pbmsg(*temp_festivalmiaoshu_list);
	}
}

void Sheet_festivalmiaoshu_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmiaoshu & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmiaoshu_s));
	festivalmiaoshu_List.SetSize(msg.festivalmiaoshu_list_size() > festivalmiaoshu_List.GetMaxSize() ? festivalmiaoshu_List.GetMaxSize() : msg.festivalmiaoshu_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmiaoshu_List.GetSize(); ++i) {
		const ::proto_ff::festivalmiaoshu & temp_festivalmiaoshu_list = msg.festivalmiaoshu_list(i);
		festivalmiaoshu_List[i].read_from_pbmsg(temp_festivalmiaoshu_list);
	}
}

festivalmuban_denglu_s::festivalmuban_denglu_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_denglu_s::CreateInit() {
	id = (int32_t)0;
	Num = (int32_t)0;
	remarkId = (int32_t)0;
	jiangLi = (int64_t)0;
	return 0;
}

int festivalmuban_denglu_s::ResumeInit() {
	return 0;
}

void festivalmuban_denglu_s::write_to_pbmsg(::proto_ff::festivalmuban_denglu & msg) const {
	msg.set_id((int32_t)id);
	msg.set_num((int32_t)Num);
	msg.set_remarkid((int32_t)remarkId);
	msg.set_miaoshu((const char*)miaoshu.Get());
	msg.set_jiangli((int64_t)jiangLi);
}

void festivalmuban_denglu_s::read_from_pbmsg(const ::proto_ff::festivalmuban_denglu & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_denglu_s));
	id = msg.id();
	Num = msg.num();
	remarkId = msg.remarkid();
	miaoshu.Copy(msg.miaoshu());
	jiangLi = msg.jiangli();
}

Sheet_festivalmuban_denglu_s::Sheet_festivalmuban_denglu_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_denglu_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_denglu_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_denglu_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_denglu & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_denglu_List.GetSize() && i < festivalmuban_denglu_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_denglu* temp_festivalmuban_denglu_list = msg.add_festivalmuban_denglu_list();
		festivalmuban_denglu_List[i].write_to_pbmsg(*temp_festivalmuban_denglu_list);
	}
}

void Sheet_festivalmuban_denglu_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_denglu & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_denglu_s));
	festivalmuban_denglu_List.SetSize(msg.festivalmuban_denglu_list_size() > festivalmuban_denglu_List.GetMaxSize() ? festivalmuban_denglu_List.GetMaxSize() : msg.festivalmuban_denglu_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_denglu_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_denglu & temp_festivalmuban_denglu_list = msg.festivalmuban_denglu_list(i);
		festivalmuban_denglu_List[i].read_from_pbmsg(temp_festivalmuban_denglu_list);
	}
}

festivalmuban_touzi_s::festivalmuban_touzi_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_touzi_s::CreateInit() {
	id = (int32_t)0;
	type = (int32_t)0;
	Num = (int32_t)0;
	addNum = (int64_t)0;
	remarkId = (int32_t)0;
	jiangLi = (int64_t)0;
	linkId = (int64_t)0;
	return 0;
}

int festivalmuban_touzi_s::ResumeInit() {
	return 0;
}

void festivalmuban_touzi_s::write_to_pbmsg(::proto_ff::festivalmuban_touzi & msg) const {
	msg.set_id((int32_t)id);
	msg.set_type((int32_t)type);
	msg.set_num((int32_t)Num);
	msg.set_addnum((int64_t)addNum);
	msg.set_remarkid((int32_t)remarkId);
	msg.set_miaoshu((const char*)miaoshu.Get());
	msg.set_jiangli((int64_t)jiangLi);
	msg.set_linkid((int64_t)linkId);
}

void festivalmuban_touzi_s::read_from_pbmsg(const ::proto_ff::festivalmuban_touzi & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_touzi_s));
	id = msg.id();
	type = msg.type();
	Num = msg.num();
	addNum = msg.addnum();
	remarkId = msg.remarkid();
	miaoshu.Copy(msg.miaoshu());
	jiangLi = msg.jiangli();
	linkId = msg.linkid();
}

Sheet_festivalmuban_touzi_s::Sheet_festivalmuban_touzi_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_touzi_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_touzi_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_touzi_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_touzi & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_touzi_List.GetSize() && i < festivalmuban_touzi_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_touzi* temp_festivalmuban_touzi_list = msg.add_festivalmuban_touzi_list();
		festivalmuban_touzi_List[i].write_to_pbmsg(*temp_festivalmuban_touzi_list);
	}
}

void Sheet_festivalmuban_touzi_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_touzi & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_touzi_s));
	festivalmuban_touzi_List.SetSize(msg.festivalmuban_touzi_list_size() > festivalmuban_touzi_List.GetMaxSize() ? festivalmuban_touzi_List.GetMaxSize() : msg.festivalmuban_touzi_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_touzi_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_touzi & temp_festivalmuban_touzi_list = msg.festivalmuban_touzi_list(i);
		festivalmuban_touzi_List[i].read_from_pbmsg(temp_festivalmuban_touzi_list);
	}
}

festivalmuban_zhichong_s::festivalmuban_zhichong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_zhichong_s::CreateInit() {
	id = (int32_t)0;
	Num = (int32_t)0;
	remarkId = (int32_t)0;
	jiangLi = (int64_t)0;
	return 0;
}

int festivalmuban_zhichong_s::ResumeInit() {
	return 0;
}

void festivalmuban_zhichong_s::write_to_pbmsg(::proto_ff::festivalmuban_zhichong & msg) const {
	msg.set_id((int32_t)id);
	msg.set_num((int32_t)Num);
	msg.set_severnum((const char*)severNum.Get());
	msg.set_remarkid((int32_t)remarkId);
	msg.set_miaoshu((const char*)miaoshu.Get());
	msg.set_jiangli((int64_t)jiangLi);
}

void festivalmuban_zhichong_s::read_from_pbmsg(const ::proto_ff::festivalmuban_zhichong & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_zhichong_s));
	id = msg.id();
	Num = msg.num();
	severNum.Copy(msg.severnum());
	remarkId = msg.remarkid();
	miaoshu.Copy(msg.miaoshu());
	jiangLi = msg.jiangli();
}

Sheet_festivalmuban_zhichong_s::Sheet_festivalmuban_zhichong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_zhichong_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_zhichong_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_zhichong_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_zhichong & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_zhichong_List.GetSize() && i < festivalmuban_zhichong_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_zhichong* temp_festivalmuban_zhichong_list = msg.add_festivalmuban_zhichong_list();
		festivalmuban_zhichong_List[i].write_to_pbmsg(*temp_festivalmuban_zhichong_list);
	}
}

void Sheet_festivalmuban_zhichong_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_zhichong & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_zhichong_s));
	festivalmuban_zhichong_List.SetSize(msg.festivalmuban_zhichong_list_size() > festivalmuban_zhichong_List.GetMaxSize() ? festivalmuban_zhichong_List.GetMaxSize() : msg.festivalmuban_zhichong_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_zhichong_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_zhichong & temp_festivalmuban_zhichong_list = msg.festivalmuban_zhichong_list(i);
		festivalmuban_zhichong_List[i].read_from_pbmsg(temp_festivalmuban_zhichong_list);
	}
}

festivalmuban_leichong_s::festivalmuban_leichong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_leichong_s::CreateInit() {
	id = (int32_t)0;
	type = (int32_t)0;
	Num = (int32_t)0;
	remarkId = (int32_t)0;
	jiangLi = (int64_t)0;
	return 0;
}

int festivalmuban_leichong_s::ResumeInit() {
	return 0;
}

void festivalmuban_leichong_s::write_to_pbmsg(::proto_ff::festivalmuban_leichong & msg) const {
	msg.set_id((int32_t)id);
	msg.set_type((int32_t)type);
	msg.set_num((int32_t)Num);
	msg.set_remarkid((int32_t)remarkId);
	msg.set_miaoshu((const char*)miaoshu.Get());
	msg.set_jiangli((int64_t)jiangLi);
}

void festivalmuban_leichong_s::read_from_pbmsg(const ::proto_ff::festivalmuban_leichong & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_leichong_s));
	id = msg.id();
	type = msg.type();
	Num = msg.num();
	remarkId = msg.remarkid();
	miaoshu.Copy(msg.miaoshu());
	jiangLi = msg.jiangli();
}

Sheet_festivalmuban_leichong_s::Sheet_festivalmuban_leichong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_leichong_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_leichong_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_leichong_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_leichong & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_leichong_List.GetSize() && i < festivalmuban_leichong_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_leichong* temp_festivalmuban_leichong_list = msg.add_festivalmuban_leichong_list();
		festivalmuban_leichong_List[i].write_to_pbmsg(*temp_festivalmuban_leichong_list);
	}
}

void Sheet_festivalmuban_leichong_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_leichong & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_leichong_s));
	festivalmuban_leichong_List.SetSize(msg.festivalmuban_leichong_list_size() > festivalmuban_leichong_List.GetMaxSize() ? festivalmuban_leichong_List.GetMaxSize() : msg.festivalmuban_leichong_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_leichong_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_leichong & temp_festivalmuban_leichong_list = msg.festivalmuban_leichong_list(i);
		festivalmuban_leichong_List[i].read_from_pbmsg(temp_festivalmuban_leichong_list);
	}
}

festivalmuban_duihuan_s::festivalmuban_duihuan_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_duihuan_s::CreateInit() {
	tiaoJianId = (int32_t)0;
	prizeId = (int64_t)0;
	prof = (int32_t)0;
	prizeNum = (int32_t)0;
	propId = (int64_t)0;
	propNum = (int32_t)0;
	times = (int32_t)0;
	return 0;
}

int festivalmuban_duihuan_s::ResumeInit() {
	return 0;
}

void festivalmuban_duihuan_s::write_to_pbmsg(::proto_ff::festivalmuban_duihuan & msg) const {
	msg.set_tiaojianid((int32_t)tiaoJianId);
	msg.set_prizeid((int64_t)prizeId);
	msg.set_prof((int32_t)prof);
	msg.set_prizenum((int32_t)prizeNum);
	msg.set_propid((int64_t)propId);
	msg.set_propnum((int32_t)propNum);
	msg.set_times((int32_t)times);
}

void festivalmuban_duihuan_s::read_from_pbmsg(const ::proto_ff::festivalmuban_duihuan & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_duihuan_s));
	tiaoJianId = msg.tiaojianid();
	prizeId = msg.prizeid();
	prof = msg.prof();
	prizeNum = msg.prizenum();
	propId = msg.propid();
	propNum = msg.propnum();
	times = msg.times();
}

Sheet_festivalmuban_duihuan_s::Sheet_festivalmuban_duihuan_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_duihuan_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_duihuan_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_duihuan_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_duihuan & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_duihuan_List.GetSize() && i < festivalmuban_duihuan_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_duihuan* temp_festivalmuban_duihuan_list = msg.add_festivalmuban_duihuan_list();
		festivalmuban_duihuan_List[i].write_to_pbmsg(*temp_festivalmuban_duihuan_list);
	}
}

void Sheet_festivalmuban_duihuan_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_duihuan & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_duihuan_s));
	festivalmuban_duihuan_List.SetSize(msg.festivalmuban_duihuan_list_size() > festivalmuban_duihuan_List.GetMaxSize() ? festivalmuban_duihuan_List.GetMaxSize() : msg.festivalmuban_duihuan_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_duihuan_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_duihuan & temp_festivalmuban_duihuan_list = msg.festivalmuban_duihuan_list(i);
		festivalmuban_duihuan_List[i].read_from_pbmsg(temp_festivalmuban_duihuan_list);
	}
}

festivald_diaoluo_s::festivald_diaoluo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivald_diaoluo_s::CreateInit() {
	id = (int32_t)0;
	mixLevel = (int32_t)0;
	bossType = (int32_t)0;
	return 0;
}

int festivald_diaoluo_s::ResumeInit() {
	return 0;
}

void festivald_diaoluo_s::write_to_pbmsg(::proto_ff::festivald_diaoluo & msg) const {
	msg.set_id((int32_t)id);
	msg.set_mixlevel((int32_t)mixLevel);
	msg.set_bosstype((int32_t)bossType);
	msg.set_dropnum((const char*)dropNum.Get());
	msg.set_droprand((const char*)dropRand.Get());
}

void festivald_diaoluo_s::read_from_pbmsg(const ::proto_ff::festivald_diaoluo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivald_diaoluo_s));
	id = msg.id();
	mixLevel = msg.mixlevel();
	bossType = msg.bosstype();
	dropNum.Copy(msg.dropnum());
	dropRand.Copy(msg.droprand());
}

Sheet_festivald_diaoluo_s::Sheet_festivald_diaoluo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivald_diaoluo_s::CreateInit() {
	return 0;
}

int Sheet_festivald_diaoluo_s::ResumeInit() {
	return 0;
}

void Sheet_festivald_diaoluo_s::write_to_pbmsg(::proto_ff::Sheet_festivald_diaoluo & msg) const {
	for(int32_t i = 0; i < (int32_t)festivald_diaoluo_List.GetSize() && i < festivald_diaoluo_List.GetMaxSize(); ++i) {
		::proto_ff::festivald_diaoluo* temp_festivald_diaoluo_list = msg.add_festivald_diaoluo_list();
		festivald_diaoluo_List[i].write_to_pbmsg(*temp_festivald_diaoluo_list);
	}
}

void Sheet_festivald_diaoluo_s::read_from_pbmsg(const ::proto_ff::Sheet_festivald_diaoluo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivald_diaoluo_s));
	festivald_diaoluo_List.SetSize(msg.festivald_diaoluo_list_size() > festivald_diaoluo_List.GetMaxSize() ? festivald_diaoluo_List.GetMaxSize() : msg.festivald_diaoluo_list_size());
	for(int32_t i = 0; i < (int32_t)festivald_diaoluo_List.GetSize(); ++i) {
		const ::proto_ff::festivald_diaoluo & temp_festivald_diaoluo_list = msg.festivald_diaoluo_list(i);
		festivald_diaoluo_List[i].read_from_pbmsg(temp_festivald_diaoluo_list);
	}
}

festivalmuban_leixiao_s::festivalmuban_leixiao_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_leixiao_s::CreateInit() {
	id = (int32_t)0;
	type = (int32_t)0;
	xiaoFei = (int32_t)0;
	remarkId = (int32_t)0;
	jiangLi = (int64_t)0;
	return 0;
}

int festivalmuban_leixiao_s::ResumeInit() {
	return 0;
}

void festivalmuban_leixiao_s::write_to_pbmsg(::proto_ff::festivalmuban_leixiao & msg) const {
	msg.set_id((int32_t)id);
	msg.set_type((int32_t)type);
	msg.set_xiaofei((int32_t)xiaoFei);
	msg.set_remarkid((int32_t)remarkId);
	msg.set_miaoshu((const char*)miaoshu.Get());
	msg.set_jiangli((int64_t)jiangLi);
}

void festivalmuban_leixiao_s::read_from_pbmsg(const ::proto_ff::festivalmuban_leixiao & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_leixiao_s));
	id = msg.id();
	type = msg.type();
	xiaoFei = msg.xiaofei();
	remarkId = msg.remarkid();
	miaoshu.Copy(msg.miaoshu());
	jiangLi = msg.jiangli();
}

Sheet_festivalmuban_leixiao_s::Sheet_festivalmuban_leixiao_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_leixiao_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_leixiao_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_leixiao_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_leixiao & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_leixiao_List.GetSize() && i < festivalmuban_leixiao_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_leixiao* temp_festivalmuban_leixiao_list = msg.add_festivalmuban_leixiao_list();
		festivalmuban_leixiao_List[i].write_to_pbmsg(*temp_festivalmuban_leixiao_list);
	}
}

void Sheet_festivalmuban_leixiao_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_leixiao & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_leixiao_s));
	festivalmuban_leixiao_List.SetSize(msg.festivalmuban_leixiao_list_size() > festivalmuban_leixiao_List.GetMaxSize() ? festivalmuban_leixiao_List.GetMaxSize() : msg.festivalmuban_leixiao_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_leixiao_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_leixiao & temp_festivalmuban_leixiao_list = msg.festivalmuban_leixiao_list(i);
		festivalmuban_leixiao_List[i].read_from_pbmsg(temp_festivalmuban_leixiao_list);
	}
}

festivalmuban_shouchong_s::festivalmuban_shouchong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_shouchong_s::CreateInit() {
	id = (int32_t)0;
	jiangLi = (int64_t)0;
	return 0;
}

int festivalmuban_shouchong_s::ResumeInit() {
	return 0;
}

void festivalmuban_shouchong_s::write_to_pbmsg(::proto_ff::festivalmuban_shouchong & msg) const {
	msg.set_id((int32_t)id);
	msg.set_jiangli((int64_t)jiangLi);
}

void festivalmuban_shouchong_s::read_from_pbmsg(const ::proto_ff::festivalmuban_shouchong & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_shouchong_s));
	id = msg.id();
	jiangLi = msg.jiangli();
}

Sheet_festivalmuban_shouchong_s::Sheet_festivalmuban_shouchong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_shouchong_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_shouchong_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_shouchong_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_shouchong & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_shouchong_List.GetSize() && i < festivalmuban_shouchong_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_shouchong* temp_festivalmuban_shouchong_list = msg.add_festivalmuban_shouchong_list();
		festivalmuban_shouchong_List[i].write_to_pbmsg(*temp_festivalmuban_shouchong_list);
	}
}

void Sheet_festivalmuban_shouchong_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_shouchong & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_shouchong_s));
	festivalmuban_shouchong_List.SetSize(msg.festivalmuban_shouchong_list_size() > festivalmuban_shouchong_List.GetMaxSize() ? festivalmuban_shouchong_List.GetMaxSize() : msg.festivalmuban_shouchong_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_shouchong_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_shouchong & temp_festivalmuban_shouchong_list = msg.festivalmuban_shouchong_list(i);
		festivalmuban_shouchong_List[i].read_from_pbmsg(temp_festivalmuban_shouchong_list);
	}
}

festivalmuban_yanhua_s::festivalmuban_yanhua_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_yanhua_s::CreateInit() {
	id = (int32_t)0;
	itemid = (int64_t)0;
	num = (int32_t)0;
	prof = (int32_t)0;
	type = (int32_t)0;
	order = (int32_t)0;
	probability = (int32_t)0;
	relation = (int64_t)0;
	modelid = (int64_t)0;
	modeltype = (int32_t)0;
	return 0;
}

int festivalmuban_yanhua_s::ResumeInit() {
	return 0;
}

void festivalmuban_yanhua_s::write_to_pbmsg(::proto_ff::festivalmuban_yanhua & msg) const {
	msg.set_id((int32_t)id);
	msg.set_itemid((int64_t)itemid);
	msg.set_num((int32_t)num);
	msg.set_prof((int32_t)prof);
	msg.set_type((int32_t)type);
	msg.set_order((int32_t)order);
	msg.set_probability((int32_t)probability);
	msg.set_relation((int64_t)relation);
	msg.set_modelid((int64_t)modelid);
	msg.set_modeltype((int32_t)modeltype);
	msg.set_scale((const char*)scale.Get());
}

void festivalmuban_yanhua_s::read_from_pbmsg(const ::proto_ff::festivalmuban_yanhua & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_yanhua_s));
	id = msg.id();
	itemid = msg.itemid();
	num = msg.num();
	prof = msg.prof();
	type = msg.type();
	order = msg.order();
	probability = msg.probability();
	relation = msg.relation();
	modelid = msg.modelid();
	modeltype = msg.modeltype();
	scale.Copy(msg.scale());
}

Sheet_festivalmuban_yanhua_s::Sheet_festivalmuban_yanhua_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_yanhua_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_yanhua_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_yanhua_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_yanhua & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_yanhua_List.GetSize() && i < festivalmuban_yanhua_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_yanhua* temp_festivalmuban_yanhua_list = msg.add_festivalmuban_yanhua_list();
		festivalmuban_yanhua_List[i].write_to_pbmsg(*temp_festivalmuban_yanhua_list);
	}
}

void Sheet_festivalmuban_yanhua_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_yanhua & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_yanhua_s));
	festivalmuban_yanhua_List.SetSize(msg.festivalmuban_yanhua_list_size() > festivalmuban_yanhua_List.GetMaxSize() ? festivalmuban_yanhua_List.GetMaxSize() : msg.festivalmuban_yanhua_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_yanhua_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_yanhua & temp_festivalmuban_yanhua_list = msg.festivalmuban_yanhua_list(i);
		festivalmuban_yanhua_List[i].read_from_pbmsg(temp_festivalmuban_yanhua_list);
	}
}

festivalyanhuaConstant_s::festivalyanhuaConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalyanhuaConstant_s::CreateInit() {
	id = (int64_t)0;
	costItem = (int64_t)0;
	rewardPool = (int32_t)0;
	coinTye = (int32_t)0;
	number = (int32_t)0;
	return 0;
}

int festivalyanhuaConstant_s::ResumeInit() {
	return 0;
}

void festivalyanhuaConstant_s::write_to_pbmsg(::proto_ff::festivalyanhuaConstant & msg) const {
	msg.set_id((int64_t)id);
	msg.set_costitem((int64_t)costItem);
	msg.set_rewardpool((int32_t)rewardPool);
	msg.set_cointye((int32_t)coinTye);
	msg.set_number((int32_t)number);
}

void festivalyanhuaConstant_s::read_from_pbmsg(const ::proto_ff::festivalyanhuaConstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalyanhuaConstant_s));
	id = msg.id();
	costItem = msg.costitem();
	rewardPool = msg.rewardpool();
	coinTye = msg.cointye();
	number = msg.number();
}

Sheet_festivalyanhuaConstant_s::Sheet_festivalyanhuaConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalyanhuaConstant_s::CreateInit() {
	return 0;
}

int Sheet_festivalyanhuaConstant_s::ResumeInit() {
	return 0;
}

void Sheet_festivalyanhuaConstant_s::write_to_pbmsg(::proto_ff::Sheet_festivalyanhuaConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalyanhuaConstant_List.GetSize() && i < festivalyanhuaConstant_List.GetMaxSize(); ++i) {
		::proto_ff::festivalyanhuaConstant* temp_festivalyanhuaconstant_list = msg.add_festivalyanhuaconstant_list();
		festivalyanhuaConstant_List[i].write_to_pbmsg(*temp_festivalyanhuaconstant_list);
	}
}

void Sheet_festivalyanhuaConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalyanhuaConstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalyanhuaConstant_s));
	festivalyanhuaConstant_List.SetSize(msg.festivalyanhuaconstant_list_size() > festivalyanhuaConstant_List.GetMaxSize() ? festivalyanhuaConstant_List.GetMaxSize() : msg.festivalyanhuaconstant_list_size());
	for(int32_t i = 0; i < (int32_t)festivalyanhuaConstant_List.GetSize(); ++i) {
		const ::proto_ff::festivalyanhuaConstant & temp_festivalyanhuaconstant_list = msg.festivalyanhuaconstant_list(i);
		festivalyanhuaConstant_List[i].read_from_pbmsg(temp_festivalyanhuaconstant_list);
	}
}

festivalmuban_shop_s::festivalmuban_shop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_shop_s::CreateInit() {
	id = (int64_t)0;
	itemid = (int64_t)0;
	prof = (int32_t)0;
	priceA = (int32_t)0;
	priceB = (int32_t)0;
	currency = (int32_t)0;
	discount = (int32_t)0;
	quantity = (int32_t)0;
	return 0;
}

int festivalmuban_shop_s::ResumeInit() {
	return 0;
}

void festivalmuban_shop_s::write_to_pbmsg(::proto_ff::festivalmuban_shop & msg) const {
	msg.set_id((int64_t)id);
	msg.set_itemid((int64_t)itemid);
	msg.set_prof((int32_t)prof);
	msg.set_pricea((int32_t)priceA);
	msg.set_priceb((int32_t)priceB);
	msg.set_currency((int32_t)currency);
	msg.set_discount((int32_t)discount);
	msg.set_quantity((int32_t)quantity);
}

void festivalmuban_shop_s::read_from_pbmsg(const ::proto_ff::festivalmuban_shop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_shop_s));
	id = msg.id();
	itemid = msg.itemid();
	prof = msg.prof();
	priceA = msg.pricea();
	priceB = msg.priceb();
	currency = msg.currency();
	discount = msg.discount();
	quantity = msg.quantity();
}

Sheet_festivalmuban_shop_s::Sheet_festivalmuban_shop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_shop_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_shop_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_shop_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_shop & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_shop_List.GetSize() && i < festivalmuban_shop_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_shop* temp_festivalmuban_shop_list = msg.add_festivalmuban_shop_list();
		festivalmuban_shop_List[i].write_to_pbmsg(*temp_festivalmuban_shop_list);
	}
}

void Sheet_festivalmuban_shop_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_shop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_shop_s));
	festivalmuban_shop_List.SetSize(msg.festivalmuban_shop_list_size() > festivalmuban_shop_List.GetMaxSize() ? festivalmuban_shop_List.GetMaxSize() : msg.festivalmuban_shop_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_shop_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_shop & temp_festivalmuban_shop_list = msg.festivalmuban_shop_list(i);
		festivalmuban_shop_List[i].read_from_pbmsg(temp_festivalmuban_shop_list);
	}
}

festivalmuban_czjb_s::festivalmuban_czjb_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_czjb_s::CreateInit() {
	id = (int32_t)0;
	Perc = (int32_t)0;
	fristpresent = (int32_t)0;
	presenttype = (int32_t)0;
	Point = (int32_t)0;
	return 0;
}

int festivalmuban_czjb_s::ResumeInit() {
	return 0;
}

void festivalmuban_czjb_s::write_to_pbmsg(::proto_ff::festivalmuban_czjb & msg) const {
	msg.set_id((int32_t)id);
	msg.set_rechargepoint((const char*)RechargePoint.Get());
	msg.set_perc((int32_t)Perc);
	msg.set_fristpresent((int32_t)fristpresent);
	msg.set_presenttype((int32_t)presenttype);
	msg.set_point((int32_t)Point);
}

void festivalmuban_czjb_s::read_from_pbmsg(const ::proto_ff::festivalmuban_czjb & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_czjb_s));
	id = msg.id();
	RechargePoint.Copy(msg.rechargepoint());
	Perc = msg.perc();
	fristpresent = msg.fristpresent();
	presenttype = msg.presenttype();
	Point = msg.point();
}

Sheet_festivalmuban_czjb_s::Sheet_festivalmuban_czjb_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_czjb_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_czjb_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_czjb_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_czjb & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_czjb_List.GetSize() && i < festivalmuban_czjb_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_czjb* temp_festivalmuban_czjb_list = msg.add_festivalmuban_czjb_list();
		festivalmuban_czjb_List[i].write_to_pbmsg(*temp_festivalmuban_czjb_list);
	}
}

void Sheet_festivalmuban_czjb_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_czjb & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_czjb_s));
	festivalmuban_czjb_List.SetSize(msg.festivalmuban_czjb_list_size() > festivalmuban_czjb_List.GetMaxSize() ? festivalmuban_czjb_List.GetMaxSize() : msg.festivalmuban_czjb_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_czjb_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_czjb & temp_festivalmuban_czjb_list = msg.festivalmuban_czjb_list(i);
		festivalmuban_czjb_List[i].read_from_pbmsg(temp_festivalmuban_czjb_list);
	}
}

festivalmuban_scsb_s::festivalmuban_scsb_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_scsb_s::CreateInit() {
	id = (int32_t)0;
	fristpresent = (int32_t)0;
	presenttype = (int32_t)0;
	Point = (int32_t)0;
	return 0;
}

int festivalmuban_scsb_s::ResumeInit() {
	return 0;
}

void festivalmuban_scsb_s::write_to_pbmsg(::proto_ff::festivalmuban_scsb & msg) const {
	msg.set_id((int32_t)id);
	msg.set_rechargepoint((const char*)RechargePoint.Get());
	msg.set_fristpresent((int32_t)fristpresent);
	msg.set_presenttype((int32_t)presenttype);
	msg.set_point((int32_t)Point);
}

void festivalmuban_scsb_s::read_from_pbmsg(const ::proto_ff::festivalmuban_scsb & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_scsb_s));
	id = msg.id();
	RechargePoint.Copy(msg.rechargepoint());
	fristpresent = msg.fristpresent();
	presenttype = msg.presenttype();
	Point = msg.point();
}

Sheet_festivalmuban_scsb_s::Sheet_festivalmuban_scsb_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_scsb_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_scsb_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_scsb_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_scsb & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_scsb_List.GetSize() && i < festivalmuban_scsb_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_scsb* temp_festivalmuban_scsb_list = msg.add_festivalmuban_scsb_list();
		festivalmuban_scsb_List[i].write_to_pbmsg(*temp_festivalmuban_scsb_list);
	}
}

void Sheet_festivalmuban_scsb_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_scsb & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_scsb_s));
	festivalmuban_scsb_List.SetSize(msg.festivalmuban_scsb_list_size() > festivalmuban_scsb_List.GetMaxSize() ? festivalmuban_scsb_List.GetMaxSize() : msg.festivalmuban_scsb_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_scsb_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_scsb & temp_festivalmuban_scsb_list = msg.festivalmuban_scsb_list(i);
		festivalmuban_scsb_List[i].read_from_pbmsg(temp_festivalmuban_scsb_list);
	}
}

festivalmuban_eggs_s::festivalmuban_eggs_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_eggs_s::CreateInit() {
	id = (int32_t)0;
	itemid = (int64_t)0;
	num = (int32_t)0;
	prof = (int32_t)0;
	type = (int32_t)0;
	order = (int32_t)0;
	isnote = (int32_t)0;
	probability = (int32_t)0;
	relation = (int64_t)0;
	return 0;
}

int festivalmuban_eggs_s::ResumeInit() {
	return 0;
}

void festivalmuban_eggs_s::write_to_pbmsg(::proto_ff::festivalmuban_eggs & msg) const {
	msg.set_id((int32_t)id);
	msg.set_itemid((int64_t)itemid);
	msg.set_num((int32_t)num);
	msg.set_prof((int32_t)prof);
	msg.set_type((int32_t)type);
	msg.set_order((int32_t)order);
	msg.set_isnote((int32_t)isnote);
	msg.set_probability((int32_t)probability);
	msg.set_relation((int64_t)relation);
}

void festivalmuban_eggs_s::read_from_pbmsg(const ::proto_ff::festivalmuban_eggs & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_eggs_s));
	id = msg.id();
	itemid = msg.itemid();
	num = msg.num();
	prof = msg.prof();
	type = msg.type();
	order = msg.order();
	isnote = msg.isnote();
	probability = msg.probability();
	relation = msg.relation();
}

Sheet_festivalmuban_eggs_s::Sheet_festivalmuban_eggs_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_eggs_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_eggs_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_eggs_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_eggs & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_eggs_List.GetSize() && i < festivalmuban_eggs_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_eggs* temp_festivalmuban_eggs_list = msg.add_festivalmuban_eggs_list();
		festivalmuban_eggs_List[i].write_to_pbmsg(*temp_festivalmuban_eggs_list);
	}
}

void Sheet_festivalmuban_eggs_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_eggs & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_eggs_s));
	festivalmuban_eggs_List.SetSize(msg.festivalmuban_eggs_list_size() > festivalmuban_eggs_List.GetMaxSize() ? festivalmuban_eggs_List.GetMaxSize() : msg.festivalmuban_eggs_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_eggs_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_eggs & temp_festivalmuban_eggs_list = msg.festivalmuban_eggs_list(i);
		festivalmuban_eggs_List[i].read_from_pbmsg(temp_festivalmuban_eggs_list);
	}
}

festivaleggConstant_s::festivaleggConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivaleggConstant_s::CreateInit() {
	id = (int64_t)0;
	costItem = (int64_t)0;
	freeTime = (int32_t)0;
	specialRate = (int32_t)0;
	specialAddRate = (int32_t)0;
	limit = (int32_t)0;
	rewardPool = (int32_t)0;
	return 0;
}

int festivaleggConstant_s::ResumeInit() {
	return 0;
}

void festivaleggConstant_s::write_to_pbmsg(::proto_ff::festivaleggConstant & msg) const {
	msg.set_id((int64_t)id);
	msg.set_exreward((const char*)exReward.Get());
	msg.set_costitem((int64_t)costItem);
	msg.set_freetime((int32_t)freeTime);
	msg.set_poolchange((const char*)poolChange.Get());
	msg.set_specialrate((int32_t)specialRate);
	msg.set_specialaddrate((int32_t)specialAddRate);
	msg.set_flashcost((const char*)flashCost.Get());
	msg.set_limit((int32_t)limit);
	msg.set_rewardpool((int32_t)rewardPool);
}

void festivaleggConstant_s::read_from_pbmsg(const ::proto_ff::festivaleggConstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivaleggConstant_s));
	id = msg.id();
	exReward.Copy(msg.exreward());
	costItem = msg.costitem();
	freeTime = msg.freetime();
	poolChange.Copy(msg.poolchange());
	specialRate = msg.specialrate();
	specialAddRate = msg.specialaddrate();
	flashCost.Copy(msg.flashcost());
	limit = msg.limit();
	rewardPool = msg.rewardpool();
}

Sheet_festivaleggConstant_s::Sheet_festivaleggConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivaleggConstant_s::CreateInit() {
	return 0;
}

int Sheet_festivaleggConstant_s::ResumeInit() {
	return 0;
}

void Sheet_festivaleggConstant_s::write_to_pbmsg(::proto_ff::Sheet_festivaleggConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)festivaleggConstant_List.GetSize() && i < festivaleggConstant_List.GetMaxSize(); ++i) {
		::proto_ff::festivaleggConstant* temp_festivaleggconstant_list = msg.add_festivaleggconstant_list();
		festivaleggConstant_List[i].write_to_pbmsg(*temp_festivaleggconstant_list);
	}
}

void Sheet_festivaleggConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_festivaleggConstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivaleggConstant_s));
	festivaleggConstant_List.SetSize(msg.festivaleggconstant_list_size() > festivaleggConstant_List.GetMaxSize() ? festivaleggConstant_List.GetMaxSize() : msg.festivaleggconstant_list_size());
	for(int32_t i = 0; i < (int32_t)festivaleggConstant_List.GetSize(); ++i) {
		const ::proto_ff::festivaleggConstant & temp_festivaleggconstant_list = msg.festivaleggconstant_list(i);
		festivaleggConstant_List[i].read_from_pbmsg(temp_festivaleggconstant_list);
	}
}

festivalconstant_s::festivalconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalconstant_s::CreateInit() {
	constantid = (int64_t)0;
	constantdata = (int64_t)0;
	return 0;
}

int festivalconstant_s::ResumeInit() {
	return 0;
}

void festivalconstant_s::write_to_pbmsg(::proto_ff::festivalconstant & msg) const {
	msg.set_constantid((int64_t)constantid);
	msg.set_constantdata((int64_t)constantdata);
	msg.set_stringdata((const char*)stringdata.Get());
}

void festivalconstant_s::read_from_pbmsg(const ::proto_ff::festivalconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalconstant_s));
	constantid = msg.constantid();
	constantdata = msg.constantdata();
	stringdata.Copy(msg.stringdata());
}

Sheet_festivalconstant_s::Sheet_festivalconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalconstant_s::CreateInit() {
	return 0;
}

int Sheet_festivalconstant_s::ResumeInit() {
	return 0;
}

void Sheet_festivalconstant_s::write_to_pbmsg(::proto_ff::Sheet_festivalconstant & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalconstant_List.GetSize() && i < festivalconstant_List.GetMaxSize(); ++i) {
		::proto_ff::festivalconstant* temp_festivalconstant_list = msg.add_festivalconstant_list();
		festivalconstant_List[i].write_to_pbmsg(*temp_festivalconstant_list);
	}
}

void Sheet_festivalconstant_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalconstant_s));
	festivalconstant_List.SetSize(msg.festivalconstant_list_size() > festivalconstant_List.GetMaxSize() ? festivalconstant_List.GetMaxSize() : msg.festivalconstant_list_size());
	for(int32_t i = 0; i < (int32_t)festivalconstant_List.GetSize(); ++i) {
		const ::proto_ff::festivalconstant & temp_festivalconstant_list = msg.festivalconstant_list(i);
		festivalconstant_List[i].read_from_pbmsg(temp_festivalconstant_list);
	}
}

festivalmuban_shousha_s::festivalmuban_shousha_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_shousha_s::CreateInit() {
	id = (int32_t)0;
	bossId = (int64_t)0;
	boxId = (int64_t)0;
	linkid = (int64_t)0;
	return 0;
}

int festivalmuban_shousha_s::ResumeInit() {
	return 0;
}

void festivalmuban_shousha_s::write_to_pbmsg(::proto_ff::festivalmuban_shousha & msg) const {
	msg.set_id((int32_t)id);
	msg.set_bossid((int64_t)bossId);
	msg.set_boxid((int64_t)boxId);
	msg.set_linkid((int64_t)linkid);
}

void festivalmuban_shousha_s::read_from_pbmsg(const ::proto_ff::festivalmuban_shousha & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_shousha_s));
	id = msg.id();
	bossId = msg.bossid();
	boxId = msg.boxid();
	linkid = msg.linkid();
}

Sheet_festivalmuban_shousha_s::Sheet_festivalmuban_shousha_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_shousha_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_shousha_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_shousha_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_shousha & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_shousha_List.GetSize() && i < festivalmuban_shousha_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_shousha* temp_festivalmuban_shousha_list = msg.add_festivalmuban_shousha_list();
		festivalmuban_shousha_List[i].write_to_pbmsg(*temp_festivalmuban_shousha_list);
	}
}

void Sheet_festivalmuban_shousha_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_shousha & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_shousha_s));
	festivalmuban_shousha_List.SetSize(msg.festivalmuban_shousha_list_size() > festivalmuban_shousha_List.GetMaxSize() ? festivalmuban_shousha_List.GetMaxSize() : msg.festivalmuban_shousha_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_shousha_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_shousha & temp_festivalmuban_shousha_list = msg.festivalmuban_shousha_list(i);
		festivalmuban_shousha_List[i].read_from_pbmsg(temp_festivalmuban_shousha_list);
	}
}

festivalmuban_huoyue_s::festivalmuban_huoyue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int festivalmuban_huoyue_s::CreateInit() {
	id = (int32_t)0;
	activity = (int32_t)0;
	boxId = (int64_t)0;
	return 0;
}

int festivalmuban_huoyue_s::ResumeInit() {
	return 0;
}

void festivalmuban_huoyue_s::write_to_pbmsg(::proto_ff::festivalmuban_huoyue & msg) const {
	msg.set_id((int32_t)id);
	msg.set_activity((int32_t)activity);
	msg.set_desc((const char*)desc.Get());
	msg.set_boxid((int64_t)boxId);
}

void festivalmuban_huoyue_s::read_from_pbmsg(const ::proto_ff::festivalmuban_huoyue & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct festivalmuban_huoyue_s));
	id = msg.id();
	activity = msg.activity();
	desc.Copy(msg.desc());
	boxId = msg.boxid();
}

Sheet_festivalmuban_huoyue_s::Sheet_festivalmuban_huoyue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_festivalmuban_huoyue_s::CreateInit() {
	return 0;
}

int Sheet_festivalmuban_huoyue_s::ResumeInit() {
	return 0;
}

void Sheet_festivalmuban_huoyue_s::write_to_pbmsg(::proto_ff::Sheet_festivalmuban_huoyue & msg) const {
	for(int32_t i = 0; i < (int32_t)festivalmuban_huoyue_List.GetSize() && i < festivalmuban_huoyue_List.GetMaxSize(); ++i) {
		::proto_ff::festivalmuban_huoyue* temp_festivalmuban_huoyue_list = msg.add_festivalmuban_huoyue_list();
		festivalmuban_huoyue_List[i].write_to_pbmsg(*temp_festivalmuban_huoyue_list);
	}
}

void Sheet_festivalmuban_huoyue_s::read_from_pbmsg(const ::proto_ff::Sheet_festivalmuban_huoyue & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_festivalmuban_huoyue_s));
	festivalmuban_huoyue_List.SetSize(msg.festivalmuban_huoyue_list_size() > festivalmuban_huoyue_List.GetMaxSize() ? festivalmuban_huoyue_List.GetMaxSize() : msg.festivalmuban_huoyue_list_size());
	for(int32_t i = 0; i < (int32_t)festivalmuban_huoyue_List.GetSize(); ++i) {
		const ::proto_ff::festivalmuban_huoyue & temp_festivalmuban_huoyue_list = msg.festivalmuban_huoyue_list(i);
		festivalmuban_huoyue_List[i].read_from_pbmsg(temp_festivalmuban_huoyue_list);
	}
}

}