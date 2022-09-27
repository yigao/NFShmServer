#include "operate_s.h"

namespace proto_ff_s {

operateoperate_s::operateoperate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operateoperate_s::CreateInit() {
	id = (int64_t)0;
	huoDong = (int32_t)0;
	nameId = (int32_t)0;
	servertype = (int32_t)0;
	timeType = (int32_t)0;
	ifOpen = (int32_t)0;
	return 0;
}

int operateoperate_s::ResumeInit() {
	return 0;
}

void operateoperate_s::write_to_pbmsg(::proto_ff::operateoperate & msg) const {
	msg.set_id((int64_t)id);
	msg.set_huodong((int32_t)huoDong);
	msg.set_name((const char*)name.Get());
	msg.set_nameid((int32_t)nameId);
	msg.set_tiaojian((const char*)tiaoJian.Get());
	msg.set_servertype((int32_t)servertype);
	msg.set_timea((const char*)timeA.Get());
	msg.set_timeb((const char*)timeB.Get());
	msg.set_timetype((int32_t)timeType);
	msg.set_miaosu((const char*)miaoSu.Get());
	msg.set_ifopen((int32_t)ifOpen);
}

void operateoperate_s::read_from_pbmsg(const ::proto_ff::operateoperate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operateoperate_s));
	id = msg.id();
	huoDong = msg.huodong();
	name.Copy(msg.name());
	nameId = msg.nameid();
	tiaoJian.Copy(msg.tiaojian());
	servertype = msg.servertype();
	timeA.Copy(msg.timea());
	timeB.Copy(msg.timeb());
	timeType = msg.timetype();
	miaoSu.Copy(msg.miaosu());
	ifOpen = msg.ifopen();
}

Sheet_operateoperate_s::Sheet_operateoperate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operateoperate_s::CreateInit() {
	return 0;
}

int Sheet_operateoperate_s::ResumeInit() {
	return 0;
}

void Sheet_operateoperate_s::write_to_pbmsg(::proto_ff::Sheet_operateoperate & msg) const {
	for(int32_t i = 0; i < (int32_t)operateoperate_List.GetSize() && i < operateoperate_List.GetMaxSize(); ++i) {
		::proto_ff::operateoperate* temp_operateoperate_list = msg.add_operateoperate_list();
		operateoperate_List[i].write_to_pbmsg(*temp_operateoperate_list);
	}
}

void Sheet_operateoperate_s::read_from_pbmsg(const ::proto_ff::Sheet_operateoperate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operateoperate_s));
	operateoperate_List.SetSize(msg.operateoperate_list_size() > operateoperate_List.GetMaxSize() ? operateoperate_List.GetMaxSize() : msg.operateoperate_list_size());
	for(int32_t i = 0; i < (int32_t)operateoperate_List.GetSize(); ++i) {
		const ::proto_ff::operateoperate & temp_operateoperate_list = msg.operateoperate_list(i);
		operateoperate_List[i].read_from_pbmsg(temp_operateoperate_list);
	}
}

operatetutor_s::operatetutor_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operatetutor_s::CreateInit() {
	id = (int32_t)0;
	type = (int32_t)0;
	condition = (int32_t)0;
	conditionParam1 = (int64_t)0;
	conditionParam2 = (int64_t)0;
	boxId = (int64_t)0;
	teach = (int32_t)0;
	return 0;
}

int operatetutor_s::ResumeInit() {
	return 0;
}

void operatetutor_s::write_to_pbmsg(::proto_ff::operatetutor & msg) const {
	msg.set_id((int32_t)id);
	msg.set_type((int32_t)type);
	msg.set_condition((int32_t)condition);
	msg.set_conditionparam1((int64_t)conditionParam1);
	msg.set_conditionparam2((int64_t)conditionParam2);
	msg.set_boxid((int64_t)boxId);
	msg.set_teach((int32_t)teach);
}

void operatetutor_s::read_from_pbmsg(const ::proto_ff::operatetutor & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operatetutor_s));
	id = msg.id();
	type = msg.type();
	condition = msg.condition();
	conditionParam1 = msg.conditionparam1();
	conditionParam2 = msg.conditionparam2();
	boxId = msg.boxid();
	teach = msg.teach();
}

Sheet_operatetutor_s::Sheet_operatetutor_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operatetutor_s::CreateInit() {
	return 0;
}

int Sheet_operatetutor_s::ResumeInit() {
	return 0;
}

void Sheet_operatetutor_s::write_to_pbmsg(::proto_ff::Sheet_operatetutor & msg) const {
	for(int32_t i = 0; i < (int32_t)operatetutor_List.GetSize() && i < operatetutor_List.GetMaxSize(); ++i) {
		::proto_ff::operatetutor* temp_operatetutor_list = msg.add_operatetutor_list();
		operatetutor_List[i].write_to_pbmsg(*temp_operatetutor_list);
	}
}

void Sheet_operatetutor_s::read_from_pbmsg(const ::proto_ff::Sheet_operatetutor & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operatetutor_s));
	operatetutor_List.SetSize(msg.operatetutor_list_size() > operatetutor_List.GetMaxSize() ? operatetutor_List.GetMaxSize() : msg.operatetutor_list_size());
	for(int32_t i = 0; i < (int32_t)operatetutor_List.GetSize(); ++i) {
		const ::proto_ff::operatetutor & temp_operatetutor_list = msg.operatetutor_list(i);
		operatetutor_List[i].read_from_pbmsg(temp_operatetutor_list);
	}
}

operatejiangli_s::operatejiangli_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operatejiangli_s::CreateInit() {
	tiaoJianId = (int64_t)0;
	boxId = (int64_t)0;
	sdboxid = (int64_t)0;
	return 0;
}

int operatejiangli_s::ResumeInit() {
	return 0;
}

void operatejiangli_s::write_to_pbmsg(::proto_ff::operatejiangli & msg) const {
	msg.set_tiaojianid((int64_t)tiaoJianId);
	msg.set_huodong((const char*)huoDong.Get());
	msg.set_downnu((const char*)downNu.Get());
	msg.set_upnu((const char*)upNu.Get());
	msg.set_miaoshu((const char*)miaoshu.Get());
	msg.set_miaoshuadd((const char*)miaoshuAdd.Get());
	msg.set_tiaojian((const char*)tiaoJian.Get());
	msg.set_boxid((int64_t)boxId);
	msg.set_sdboxid((int64_t)sdboxid);
}

void operatejiangli_s::read_from_pbmsg(const ::proto_ff::operatejiangli & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operatejiangli_s));
	tiaoJianId = msg.tiaojianid();
	huoDong.Copy(msg.huodong());
	downNu.Copy(msg.downnu());
	upNu.Copy(msg.upnu());
	miaoshu.Copy(msg.miaoshu());
	miaoshuAdd.Copy(msg.miaoshuadd());
	tiaoJian.Copy(msg.tiaojian());
	boxId = msg.boxid();
	sdboxid = msg.sdboxid();
}

Sheet_operatejiangli_s::Sheet_operatejiangli_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operatejiangli_s::CreateInit() {
	return 0;
}

int Sheet_operatejiangli_s::ResumeInit() {
	return 0;
}

void Sheet_operatejiangli_s::write_to_pbmsg(::proto_ff::Sheet_operatejiangli & msg) const {
	for(int32_t i = 0; i < (int32_t)operatejiangli_List.GetSize() && i < operatejiangli_List.GetMaxSize(); ++i) {
		::proto_ff::operatejiangli* temp_operatejiangli_list = msg.add_operatejiangli_list();
		operatejiangli_List[i].write_to_pbmsg(*temp_operatejiangli_list);
	}
}

void Sheet_operatejiangli_s::read_from_pbmsg(const ::proto_ff::Sheet_operatejiangli & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operatejiangli_s));
	operatejiangli_List.SetSize(msg.operatejiangli_list_size() > operatejiangli_List.GetMaxSize() ? operatejiangli_List.GetMaxSize() : msg.operatejiangli_list_size());
	for(int32_t i = 0; i < (int32_t)operatejiangli_List.GetSize(); ++i) {
		const ::proto_ff::operatejiangli & temp_operatejiangli_list = msg.operatejiangli_list(i);
		operatejiangli_List[i].read_from_pbmsg(temp_operatejiangli_list);
	}
}

operatehoroscope_s::operatehoroscope_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operatehoroscope_s::CreateInit() {
	id = (int32_t)0;
	daojuId = (int64_t)0;
	daojuPrice = (int32_t)0;
	cycle = (int32_t)0;
	wheelTime = (int32_t)0;
	luckid = (int64_t)0;
	return 0;
}

int operatehoroscope_s::ResumeInit() {
	return 0;
}

void operatehoroscope_s::write_to_pbmsg(::proto_ff::operatehoroscope & msg) const {
	msg.set_id((int32_t)id);
	msg.set_daojuid((int64_t)daojuId);
	msg.set_daojuprice((int32_t)daojuPrice);
	msg.set_cycle((int32_t)cycle);
	msg.set_poolid((const char*)poolid.Get());
	msg.set_wheeltime((int32_t)wheelTime);
	msg.set_exchangegroupid((const char*)ExchangeGroupID.Get());
	msg.set_boxid((const char*)boxid.Get());
	msg.set_luckid((int64_t)luckid);
	msg.set_fateid((const char*)fateid.Get());
	msg.set_felicityid((const char*)felicityid.Get());
}

void operatehoroscope_s::read_from_pbmsg(const ::proto_ff::operatehoroscope & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operatehoroscope_s));
	id = msg.id();
	daojuId = msg.daojuid();
	daojuPrice = msg.daojuprice();
	cycle = msg.cycle();
	poolid.Copy(msg.poolid());
	wheelTime = msg.wheeltime();
	ExchangeGroupID.Copy(msg.exchangegroupid());
	boxid.Copy(msg.boxid());
	luckid = msg.luckid();
	fateid.Copy(msg.fateid());
	felicityid.Copy(msg.felicityid());
}

Sheet_operatehoroscope_s::Sheet_operatehoroscope_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operatehoroscope_s::CreateInit() {
	return 0;
}

int Sheet_operatehoroscope_s::ResumeInit() {
	return 0;
}

void Sheet_operatehoroscope_s::write_to_pbmsg(::proto_ff::Sheet_operatehoroscope & msg) const {
	for(int32_t i = 0; i < (int32_t)operatehoroscope_List.GetSize() && i < operatehoroscope_List.GetMaxSize(); ++i) {
		::proto_ff::operatehoroscope* temp_operatehoroscope_list = msg.add_operatehoroscope_list();
		operatehoroscope_List[i].write_to_pbmsg(*temp_operatehoroscope_list);
	}
}

void Sheet_operatehoroscope_s::read_from_pbmsg(const ::proto_ff::Sheet_operatehoroscope & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operatehoroscope_s));
	operatehoroscope_List.SetSize(msg.operatehoroscope_list_size() > operatehoroscope_List.GetMaxSize() ? operatehoroscope_List.GetMaxSize() : msg.operatehoroscope_list_size());
	for(int32_t i = 0; i < (int32_t)operatehoroscope_List.GetSize(); ++i) {
		const ::proto_ff::operatehoroscope & temp_operatehoroscope_list = msg.operatehoroscope_list(i);
		operatehoroscope_List[i].read_from_pbmsg(temp_operatehoroscope_list);
	}
}

operatehoroscopePool_s::operatehoroscopePool_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operatehoroscopePool_s::CreateInit() {
	id = (int32_t)0;
	itemid = (int64_t)0;
	num = (int32_t)0;
	prof = (int32_t)0;
	levelLimitA = (int32_t)0;
	levelLimitB = (int32_t)0;
	type = (int32_t)0;
	typeParma = (int32_t)0;
	probability = (int32_t)0;
	groupID = (int64_t)0;
	order = (int32_t)0;
	return 0;
}

int operatehoroscopePool_s::ResumeInit() {
	return 0;
}

void operatehoroscopePool_s::write_to_pbmsg(::proto_ff::operatehoroscopePool & msg) const {
	msg.set_id((int32_t)id);
	msg.set_itemid((int64_t)itemid);
	msg.set_num((int32_t)num);
	msg.set_prof((int32_t)prof);
	msg.set_levellimita((int32_t)levelLimitA);
	msg.set_levellimitb((int32_t)levelLimitB);
	msg.set_type((int32_t)type);
	msg.set_typeparma((int32_t)typeParma);
	msg.set_probability((int32_t)probability);
	msg.set_groupid((int64_t)groupID);
	msg.set_order((int32_t)order);
}

void operatehoroscopePool_s::read_from_pbmsg(const ::proto_ff::operatehoroscopePool & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operatehoroscopePool_s));
	id = msg.id();
	itemid = msg.itemid();
	num = msg.num();
	prof = msg.prof();
	levelLimitA = msg.levellimita();
	levelLimitB = msg.levellimitb();
	type = msg.type();
	typeParma = msg.typeparma();
	probability = msg.probability();
	groupID = msg.groupid();
	order = msg.order();
}

Sheet_operatehoroscopePool_s::Sheet_operatehoroscopePool_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operatehoroscopePool_s::CreateInit() {
	return 0;
}

int Sheet_operatehoroscopePool_s::ResumeInit() {
	return 0;
}

void Sheet_operatehoroscopePool_s::write_to_pbmsg(::proto_ff::Sheet_operatehoroscopePool & msg) const {
	for(int32_t i = 0; i < (int32_t)operatehoroscopePool_List.GetSize() && i < operatehoroscopePool_List.GetMaxSize(); ++i) {
		::proto_ff::operatehoroscopePool* temp_operatehoroscopepool_list = msg.add_operatehoroscopepool_list();
		operatehoroscopePool_List[i].write_to_pbmsg(*temp_operatehoroscopepool_list);
	}
}

void Sheet_operatehoroscopePool_s::read_from_pbmsg(const ::proto_ff::Sheet_operatehoroscopePool & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operatehoroscopePool_s));
	operatehoroscopePool_List.SetSize(msg.operatehoroscopepool_list_size() > operatehoroscopePool_List.GetMaxSize() ? operatehoroscopePool_List.GetMaxSize() : msg.operatehoroscopepool_list_size());
	for(int32_t i = 0; i < (int32_t)operatehoroscopePool_List.GetSize(); ++i) {
		const ::proto_ff::operatehoroscopePool & temp_operatehoroscopepool_list = msg.operatehoroscopepool_list(i);
		operatehoroscopePool_List[i].read_from_pbmsg(temp_operatehoroscopepool_list);
	}
}

operatehoroscopeExchange_s::operatehoroscopeExchange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operatehoroscopeExchange_s::CreateInit() {
	ID = (int32_t)0;
	horoscopeId = (int32_t)0;
	prizeId = (int64_t)0;
	prof = (int32_t)0;
	prizeNum = (int32_t)0;
	luckNeed = (int32_t)0;
	times = (int32_t)0;
	return 0;
}

int operatehoroscopeExchange_s::ResumeInit() {
	return 0;
}

void operatehoroscopeExchange_s::write_to_pbmsg(::proto_ff::operatehoroscopeExchange & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_horoscopeid((int32_t)horoscopeId);
	msg.set_prizeid((int64_t)prizeId);
	msg.set_prof((int32_t)prof);
	msg.set_prizenum((int32_t)prizeNum);
	msg.set_luckneed((int32_t)luckNeed);
	msg.set_times((int32_t)times);
}

void operatehoroscopeExchange_s::read_from_pbmsg(const ::proto_ff::operatehoroscopeExchange & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operatehoroscopeExchange_s));
	ID = msg.id();
	horoscopeId = msg.horoscopeid();
	prizeId = msg.prizeid();
	prof = msg.prof();
	prizeNum = msg.prizenum();
	luckNeed = msg.luckneed();
	times = msg.times();
}

Sheet_operatehoroscopeExchange_s::Sheet_operatehoroscopeExchange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operatehoroscopeExchange_s::CreateInit() {
	return 0;
}

int Sheet_operatehoroscopeExchange_s::ResumeInit() {
	return 0;
}

void Sheet_operatehoroscopeExchange_s::write_to_pbmsg(::proto_ff::Sheet_operatehoroscopeExchange & msg) const {
	for(int32_t i = 0; i < (int32_t)operatehoroscopeExchange_List.GetSize() && i < operatehoroscopeExchange_List.GetMaxSize(); ++i) {
		::proto_ff::operatehoroscopeExchange* temp_operatehoroscopeexchange_list = msg.add_operatehoroscopeexchange_list();
		operatehoroscopeExchange_List[i].write_to_pbmsg(*temp_operatehoroscopeexchange_list);
	}
}

void Sheet_operatehoroscopeExchange_s::read_from_pbmsg(const ::proto_ff::Sheet_operatehoroscopeExchange & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operatehoroscopeExchange_s));
	operatehoroscopeExchange_List.SetSize(msg.operatehoroscopeexchange_list_size() > operatehoroscopeExchange_List.GetMaxSize() ? operatehoroscopeExchange_List.GetMaxSize() : msg.operatehoroscopeexchange_list_size());
	for(int32_t i = 0; i < (int32_t)operatehoroscopeExchange_List.GetSize(); ++i) {
		const ::proto_ff::operatehoroscopeExchange & temp_operatehoroscopeexchange_list = msg.operatehoroscopeexchange_list(i);
		operatehoroscopeExchange_List[i].read_from_pbmsg(temp_operatehoroscopeexchange_list);
	}
}

operateconst_s::operateconst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operateconst_s::CreateInit() {
	constantid = (int64_t)0;
	constantdata = (int64_t)0;
	return 0;
}

int operateconst_s::ResumeInit() {
	return 0;
}

void operateconst_s::write_to_pbmsg(::proto_ff::operateconst & msg) const {
	msg.set_constantid((int64_t)constantid);
	msg.set_constantdata((int64_t)constantdata);
	msg.set_stringdata((const char*)stringdata.Get());
}

void operateconst_s::read_from_pbmsg(const ::proto_ff::operateconst & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operateconst_s));
	constantid = msg.constantid();
	constantdata = msg.constantdata();
	stringdata.Copy(msg.stringdata());
}

Sheet_operateconst_s::Sheet_operateconst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operateconst_s::CreateInit() {
	return 0;
}

int Sheet_operateconst_s::ResumeInit() {
	return 0;
}

void Sheet_operateconst_s::write_to_pbmsg(::proto_ff::Sheet_operateconst & msg) const {
	for(int32_t i = 0; i < (int32_t)operateconst_List.GetSize() && i < operateconst_List.GetMaxSize(); ++i) {
		::proto_ff::operateconst* temp_operateconst_list = msg.add_operateconst_list();
		operateconst_List[i].write_to_pbmsg(*temp_operateconst_list);
	}
}

void Sheet_operateconst_s::read_from_pbmsg(const ::proto_ff::Sheet_operateconst & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operateconst_s));
	operateconst_List.SetSize(msg.operateconst_list_size() > operateconst_List.GetMaxSize() ? operateconst_List.GetMaxSize() : msg.operateconst_list_size());
	for(int32_t i = 0; i < (int32_t)operateconst_List.GetSize(); ++i) {
		const ::proto_ff::operateconst & temp_operateconst_list = msg.operateconst_list(i);
		operateconst_List[i].read_from_pbmsg(temp_operateconst_list);
	}
}

operateunlimited_s::operateunlimited_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operateunlimited_s::CreateInit() {
	ID = (int32_t)0;
	price = (int32_t)0;
	itemId = (int64_t)0;
	num = (int64_t)0;
	return 0;
}

int operateunlimited_s::ResumeInit() {
	return 0;
}

void operateunlimited_s::write_to_pbmsg(::proto_ff::operateunlimited & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_price((int32_t)price);
	msg.set_severprice((const char*)severPrice.Get());
	msg.set_itemid((int64_t)itemId);
	msg.set_num((int64_t)num);
}

void operateunlimited_s::read_from_pbmsg(const ::proto_ff::operateunlimited & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operateunlimited_s));
	ID = msg.id();
	price = msg.price();
	severPrice.Copy(msg.severprice());
	itemId = msg.itemid();
	num = msg.num();
}

Sheet_operateunlimited_s::Sheet_operateunlimited_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operateunlimited_s::CreateInit() {
	return 0;
}

int Sheet_operateunlimited_s::ResumeInit() {
	return 0;
}

void Sheet_operateunlimited_s::write_to_pbmsg(::proto_ff::Sheet_operateunlimited & msg) const {
	for(int32_t i = 0; i < (int32_t)operateunlimited_List.GetSize() && i < operateunlimited_List.GetMaxSize(); ++i) {
		::proto_ff::operateunlimited* temp_operateunlimited_list = msg.add_operateunlimited_list();
		operateunlimited_List[i].write_to_pbmsg(*temp_operateunlimited_list);
	}
}

void Sheet_operateunlimited_s::read_from_pbmsg(const ::proto_ff::Sheet_operateunlimited & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operateunlimited_s));
	operateunlimited_List.SetSize(msg.operateunlimited_list_size() > operateunlimited_List.GetMaxSize() ? operateunlimited_List.GetMaxSize() : msg.operateunlimited_list_size());
	for(int32_t i = 0; i < (int32_t)operateunlimited_List.GetSize(); ++i) {
		const ::proto_ff::operateunlimited & temp_operateunlimited_list = msg.operateunlimited_list(i);
		operateunlimited_List[i].read_from_pbmsg(temp_operateunlimited_list);
	}
}

operaterand_s::operaterand_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operaterand_s::CreateInit() {
	id = (int32_t)0;
	randtype = (int32_t)0;
	boxid = (int64_t)0;
	return 0;
}

int operaterand_s::ResumeInit() {
	return 0;
}

void operaterand_s::write_to_pbmsg(::proto_ff::operaterand & msg) const {
	msg.set_id((int32_t)id);
	msg.set_randtype((int32_t)randtype);
	msg.set_boxid((int64_t)boxid);
	for(int32_t i = 0; i < (int32_t)canshu.GetSize() && i < canshu.GetMaxSize(); ++i) {
		msg.add_canshu((const char*)canshu[i].Get());
	}
}

void operaterand_s::read_from_pbmsg(const ::proto_ff::operaterand & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operaterand_s));
	id = msg.id();
	randtype = msg.randtype();
	boxid = msg.boxid();
	canshu.SetSize(msg.canshu_size() > canshu.GetMaxSize() ? canshu.GetMaxSize() : msg.canshu_size());
	for(int32_t i = 0; i < (int32_t)canshu.GetSize(); ++i) {
		canshu[i].Copy(msg.canshu(i));
	}
}

Sheet_operaterand_s::Sheet_operaterand_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operaterand_s::CreateInit() {
	return 0;
}

int Sheet_operaterand_s::ResumeInit() {
	return 0;
}

void Sheet_operaterand_s::write_to_pbmsg(::proto_ff::Sheet_operaterand & msg) const {
	for(int32_t i = 0; i < (int32_t)operaterand_List.GetSize() && i < operaterand_List.GetMaxSize(); ++i) {
		::proto_ff::operaterand* temp_operaterand_list = msg.add_operaterand_list();
		operaterand_List[i].write_to_pbmsg(*temp_operaterand_list);
	}
}

void Sheet_operaterand_s::read_from_pbmsg(const ::proto_ff::Sheet_operaterand & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operaterand_s));
	operaterand_List.SetSize(msg.operaterand_list_size() > operaterand_List.GetMaxSize() ? operaterand_List.GetMaxSize() : msg.operaterand_list_size());
	for(int32_t i = 0; i < (int32_t)operaterand_List.GetSize(); ++i) {
		const ::proto_ff::operaterand & temp_operaterand_list = msg.operaterand_list(i);
		operaterand_List[i].read_from_pbmsg(temp_operaterand_list);
	}
}

operatemooncard_s::operatemooncard_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operatemooncard_s::CreateInit() {
	dayNum = (int32_t)0;
	payBack = (int32_t)0;
	return 0;
}

int operatemooncard_s::ResumeInit() {
	return 0;
}

void operatemooncard_s::write_to_pbmsg(::proto_ff::operatemooncard & msg) const {
	msg.set_daynum((int32_t)dayNum);
	msg.set_payback((int32_t)payBack);
}

void operatemooncard_s::read_from_pbmsg(const ::proto_ff::operatemooncard & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operatemooncard_s));
	dayNum = msg.daynum();
	payBack = msg.payback();
}

Sheet_operatemooncard_s::Sheet_operatemooncard_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operatemooncard_s::CreateInit() {
	return 0;
}

int Sheet_operatemooncard_s::ResumeInit() {
	return 0;
}

void Sheet_operatemooncard_s::write_to_pbmsg(::proto_ff::Sheet_operatemooncard & msg) const {
	for(int32_t i = 0; i < (int32_t)operatemooncard_List.GetSize() && i < operatemooncard_List.GetMaxSize(); ++i) {
		::proto_ff::operatemooncard* temp_operatemooncard_list = msg.add_operatemooncard_list();
		operatemooncard_List[i].write_to_pbmsg(*temp_operatemooncard_list);
	}
}

void Sheet_operatemooncard_s::read_from_pbmsg(const ::proto_ff::Sheet_operatemooncard & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operatemooncard_s));
	operatemooncard_List.SetSize(msg.operatemooncard_list_size() > operatemooncard_List.GetMaxSize() ? operatemooncard_List.GetMaxSize() : msg.operatemooncard_list_size());
	for(int32_t i = 0; i < (int32_t)operatemooncard_List.GetSize(); ++i) {
		const ::proto_ff::operatemooncard & temp_operatemooncard_list = msg.operatemooncard_list(i);
		operatemooncard_List[i].read_from_pbmsg(temp_operatemooncard_list);
	}
}

operatefund_s::operatefund_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operatefund_s::CreateInit() {
	id = (int32_t)0;
	level = (int32_t)0;
	rebateS = (int32_t)0;
	rebateL = (int32_t)0;
	return 0;
}

int operatefund_s::ResumeInit() {
	return 0;
}

void operatefund_s::write_to_pbmsg(::proto_ff::operatefund & msg) const {
	msg.set_id((int32_t)id);
	msg.set_level((int32_t)level);
	msg.set_rebates((int32_t)rebateS);
	msg.set_rebatel((int32_t)rebateL);
}

void operatefund_s::read_from_pbmsg(const ::proto_ff::operatefund & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operatefund_s));
	id = msg.id();
	level = msg.level();
	rebateS = msg.rebates();
	rebateL = msg.rebatel();
}

Sheet_operatefund_s::Sheet_operatefund_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operatefund_s::CreateInit() {
	return 0;
}

int Sheet_operatefund_s::ResumeInit() {
	return 0;
}

void Sheet_operatefund_s::write_to_pbmsg(::proto_ff::Sheet_operatefund & msg) const {
	for(int32_t i = 0; i < (int32_t)operatefund_List.GetSize() && i < operatefund_List.GetMaxSize(); ++i) {
		::proto_ff::operatefund* temp_operatefund_list = msg.add_operatefund_list();
		operatefund_List[i].write_to_pbmsg(*temp_operatefund_list);
	}
}

void Sheet_operatefund_s::read_from_pbmsg(const ::proto_ff::Sheet_operatefund & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operatefund_s));
	operatefund_List.SetSize(msg.operatefund_list_size() > operatefund_List.GetMaxSize() ? operatefund_List.GetMaxSize() : msg.operatefund_list_size());
	for(int32_t i = 0; i < (int32_t)operatefund_List.GetSize(); ++i) {
		const ::proto_ff::operatefund & temp_operatefund_list = msg.operatefund_list(i);
		operatefund_List[i].read_from_pbmsg(temp_operatefund_list);
	}
}

operatetask_s::operatetask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operatetask_s::CreateInit() {
	id = (int32_t)0;
	taskNan = (int32_t)0;
	taskType = (int32_t)0;
	return 0;
}

int operatetask_s::ResumeInit() {
	return 0;
}

void operatetask_s::write_to_pbmsg(::proto_ff::operatetask & msg) const {
	msg.set_id((int32_t)id);
	msg.set_tasknan((int32_t)taskNan);
	msg.set_tasktype((int32_t)taskType);
	msg.set_num((const char*)num.Get());
}

void operatetask_s::read_from_pbmsg(const ::proto_ff::operatetask & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operatetask_s));
	id = msg.id();
	taskNan = msg.tasknan();
	taskType = msg.tasktype();
	num.Copy(msg.num());
}

Sheet_operatetask_s::Sheet_operatetask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operatetask_s::CreateInit() {
	return 0;
}

int Sheet_operatetask_s::ResumeInit() {
	return 0;
}

void Sheet_operatetask_s::write_to_pbmsg(::proto_ff::Sheet_operatetask & msg) const {
	for(int32_t i = 0; i < (int32_t)operatetask_List.GetSize() && i < operatetask_List.GetMaxSize(); ++i) {
		::proto_ff::operatetask* temp_operatetask_list = msg.add_operatetask_list();
		operatetask_List[i].write_to_pbmsg(*temp_operatetask_list);
	}
}

void Sheet_operatetask_s::read_from_pbmsg(const ::proto_ff::Sheet_operatetask & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operatetask_s));
	operatetask_List.SetSize(msg.operatetask_list_size() > operatetask_List.GetMaxSize() ? operatetask_List.GetMaxSize() : msg.operatetask_list_size());
	for(int32_t i = 0; i < (int32_t)operatetask_List.GetSize(); ++i) {
		const ::proto_ff::operatetask & temp_operatetask_list = msg.operatetask_list(i);
		operatetask_List[i].read_from_pbmsg(temp_operatetask_list);
	}
}

operateshop_s::operateshop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operateshop_s::CreateInit() {
	id = (int32_t)0;
	itemid = (int64_t)0;
	price = (int32_t)0;
	dPrice = (int32_t)0;
	moneyType = (int32_t)0;
	times = (int32_t)0;
	timeLimit = (int32_t)0;
	return 0;
}

int operateshop_s::ResumeInit() {
	return 0;
}

void operateshop_s::write_to_pbmsg(::proto_ff::operateshop & msg) const {
	msg.set_id((int32_t)id);
	msg.set_itemid((int64_t)itemid);
	msg.set_price((int32_t)price);
	msg.set_dprice((int32_t)dPrice);
	msg.set_moneytype((int32_t)moneyType);
	msg.set_times((int32_t)times);
	msg.set_timelimit((int32_t)timeLimit);
}

void operateshop_s::read_from_pbmsg(const ::proto_ff::operateshop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operateshop_s));
	id = msg.id();
	itemid = msg.itemid();
	price = msg.price();
	dPrice = msg.dprice();
	moneyType = msg.moneytype();
	times = msg.times();
	timeLimit = msg.timelimit();
}

Sheet_operateshop_s::Sheet_operateshop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operateshop_s::CreateInit() {
	return 0;
}

int Sheet_operateshop_s::ResumeInit() {
	return 0;
}

void Sheet_operateshop_s::write_to_pbmsg(::proto_ff::Sheet_operateshop & msg) const {
	for(int32_t i = 0; i < (int32_t)operateshop_List.GetSize() && i < operateshop_List.GetMaxSize(); ++i) {
		::proto_ff::operateshop* temp_operateshop_list = msg.add_operateshop_list();
		operateshop_List[i].write_to_pbmsg(*temp_operateshop_list);
	}
}

void Sheet_operateshop_s::read_from_pbmsg(const ::proto_ff::Sheet_operateshop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operateshop_s));
	operateshop_List.SetSize(msg.operateshop_list_size() > operateshop_List.GetMaxSize() ? operateshop_List.GetMaxSize() : msg.operateshop_list_size());
	for(int32_t i = 0; i < (int32_t)operateshop_List.GetSize(); ++i) {
		const ::proto_ff::operateshop & temp_operateshop_list = msg.operateshop_list(i);
		operateshop_List[i].read_from_pbmsg(temp_operateshop_list);
	}
}

operatewish_s::operatewish_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operatewish_s::CreateInit() {
	level = (int32_t)0;
	exp = (int64_t)0;
	return 0;
}

int operatewish_s::ResumeInit() {
	return 0;
}

void operatewish_s::write_to_pbmsg(::proto_ff::operatewish & msg) const {
	msg.set_level((int32_t)level);
	msg.set_exp((int64_t)exp);
}

void operatewish_s::read_from_pbmsg(const ::proto_ff::operatewish & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operatewish_s));
	level = msg.level();
	exp = msg.exp();
}

Sheet_operatewish_s::Sheet_operatewish_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operatewish_s::CreateInit() {
	return 0;
}

int Sheet_operatewish_s::ResumeInit() {
	return 0;
}

void Sheet_operatewish_s::write_to_pbmsg(::proto_ff::Sheet_operatewish & msg) const {
	for(int32_t i = 0; i < (int32_t)operatewish_List.GetSize() && i < operatewish_List.GetMaxSize(); ++i) {
		::proto_ff::operatewish* temp_operatewish_list = msg.add_operatewish_list();
		operatewish_List[i].write_to_pbmsg(*temp_operatewish_list);
	}
}

void Sheet_operatewish_s::read_from_pbmsg(const ::proto_ff::Sheet_operatewish & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operatewish_s));
	operatewish_List.SetSize(msg.operatewish_list_size() > operatewish_List.GetMaxSize() ? operatewish_List.GetMaxSize() : msg.operatewish_list_size());
	for(int32_t i = 0; i < (int32_t)operatewish_List.GetSize(); ++i) {
		const ::proto_ff::operatewish & temp_operatewish_list = msg.operatewish_list(i);
		operatewish_List[i].read_from_pbmsg(temp_operatewish_list);
	}
}

operateturntable_s::operateturntable_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operateturntable_s::CreateInit() {
	id = (int32_t)0;
	itemId = (int64_t)0;
	count = (int32_t)0;
	prof = (int32_t)0;
	prizeLevel = (int32_t)0;
	weight = (int32_t)0;
	broadcast = (int32_t)0;
	order = (int32_t)0;
	relation = (int64_t)0;
	return 0;
}

int operateturntable_s::ResumeInit() {
	return 0;
}

void operateturntable_s::write_to_pbmsg(::proto_ff::operateturntable & msg) const {
	msg.set_id((int32_t)id);
	msg.set_itemid((int64_t)itemId);
	msg.set_count((int32_t)count);
	msg.set_prof((int32_t)prof);
	msg.set_prizelevel((int32_t)prizeLevel);
	msg.set_weight((int32_t)weight);
	msg.set_broadcast((int32_t)broadcast);
	msg.set_order((int32_t)order);
	msg.set_relation((int64_t)relation);
}

void operateturntable_s::read_from_pbmsg(const ::proto_ff::operateturntable & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operateturntable_s));
	id = msg.id();
	itemId = msg.itemid();
	count = msg.count();
	prof = msg.prof();
	prizeLevel = msg.prizelevel();
	weight = msg.weight();
	broadcast = msg.broadcast();
	order = msg.order();
	relation = msg.relation();
}

Sheet_operateturntable_s::Sheet_operateturntable_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operateturntable_s::CreateInit() {
	return 0;
}

int Sheet_operateturntable_s::ResumeInit() {
	return 0;
}

void Sheet_operateturntable_s::write_to_pbmsg(::proto_ff::Sheet_operateturntable & msg) const {
	for(int32_t i = 0; i < (int32_t)operateturntable_List.GetSize() && i < operateturntable_List.GetMaxSize(); ++i) {
		::proto_ff::operateturntable* temp_operateturntable_list = msg.add_operateturntable_list();
		operateturntable_List[i].write_to_pbmsg(*temp_operateturntable_list);
	}
}

void Sheet_operateturntable_s::read_from_pbmsg(const ::proto_ff::Sheet_operateturntable & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operateturntable_s));
	operateturntable_List.SetSize(msg.operateturntable_list_size() > operateturntable_List.GetMaxSize() ? operateturntable_List.GetMaxSize() : msg.operateturntable_list_size());
	for(int32_t i = 0; i < (int32_t)operateturntable_List.GetSize(); ++i) {
		const ::proto_ff::operateturntable & temp_operateturntable_list = msg.operateturntable_list(i);
		operateturntable_List[i].read_from_pbmsg(temp_operateturntable_list);
	}
}

operateturntableTask_s::operateturntableTask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int operateturntableTask_s::CreateInit() {
	id = (int32_t)0;
	taskType = (int32_t)0;
	taskParam = (int32_t)0;
	itemId = (int64_t)0;
	itemCount = (int32_t)0;
	return 0;
}

int operateturntableTask_s::ResumeInit() {
	return 0;
}

void operateturntableTask_s::write_to_pbmsg(::proto_ff::operateturntableTask & msg) const {
	msg.set_id((int32_t)id);
	msg.set_tasktype((int32_t)taskType);
	msg.set_taskparam((int32_t)taskParam);
	msg.set_itemid((int64_t)itemId);
	msg.set_itemcount((int32_t)itemCount);
}

void operateturntableTask_s::read_from_pbmsg(const ::proto_ff::operateturntableTask & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct operateturntableTask_s));
	id = msg.id();
	taskType = msg.tasktype();
	taskParam = msg.taskparam();
	itemId = msg.itemid();
	itemCount = msg.itemcount();
}

Sheet_operateturntableTask_s::Sheet_operateturntableTask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_operateturntableTask_s::CreateInit() {
	return 0;
}

int Sheet_operateturntableTask_s::ResumeInit() {
	return 0;
}

void Sheet_operateturntableTask_s::write_to_pbmsg(::proto_ff::Sheet_operateturntableTask & msg) const {
	for(int32_t i = 0; i < (int32_t)operateturntableTask_List.GetSize() && i < operateturntableTask_List.GetMaxSize(); ++i) {
		::proto_ff::operateturntableTask* temp_operateturntabletask_list = msg.add_operateturntabletask_list();
		operateturntableTask_List[i].write_to_pbmsg(*temp_operateturntabletask_list);
	}
}

void Sheet_operateturntableTask_s::read_from_pbmsg(const ::proto_ff::Sheet_operateturntableTask & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_operateturntableTask_s));
	operateturntableTask_List.SetSize(msg.operateturntabletask_list_size() > operateturntableTask_List.GetMaxSize() ? operateturntableTask_List.GetMaxSize() : msg.operateturntabletask_list_size());
	for(int32_t i = 0; i < (int32_t)operateturntableTask_List.GetSize(); ++i) {
		const ::proto_ff::operateturntableTask & temp_operateturntabletask_list = msg.operateturntabletask_list(i);
		operateturntableTask_List[i].read_from_pbmsg(temp_operateturntabletask_list);
	}
}

}