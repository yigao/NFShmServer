#include "marry_s.h"

namespace proto_ff_s {

marryconst_s::marryconst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int marryconst_s::CreateInit() {
	id = (int32_t)0;
	constantdata = (int64_t)0;
	return 0;
}

int marryconst_s::ResumeInit() {
	return 0;
}

void marryconst_s::write_to_pbmsg(::proto_ff::marryconst & msg) const {
	msg.set_id((int32_t)id);
	msg.set_constantdata((int64_t)constantdata);
	msg.set_stringdata((const char*)stringdata.Get());
}

void marryconst_s::read_from_pbmsg(const ::proto_ff::marryconst & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct marryconst_s));
	id = msg.id();
	constantdata = msg.constantdata();
	stringdata.Copy(msg.stringdata());
}

Sheet_marryconst_s::Sheet_marryconst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_marryconst_s::CreateInit() {
	return 0;
}

int Sheet_marryconst_s::ResumeInit() {
	return 0;
}

void Sheet_marryconst_s::write_to_pbmsg(::proto_ff::Sheet_marryconst & msg) const {
	for(int32_t i = 0; i < (int32_t)marryconst_List.GetSize() && i < marryconst_List.GetMaxSize(); ++i) {
		::proto_ff::marryconst* temp_marryconst_list = msg.add_marryconst_list();
		marryconst_List[i].write_to_pbmsg(*temp_marryconst_list);
	}
}

void Sheet_marryconst_s::read_from_pbmsg(const ::proto_ff::Sheet_marryconst & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_marryconst_s));
	marryconst_List.SetSize(msg.marryconst_list_size() > marryconst_List.GetMaxSize() ? marryconst_List.GetMaxSize() : msg.marryconst_list_size());
	for(int32_t i = 0; i < (int32_t)marryconst_List.GetSize(); ++i) {
		const ::proto_ff::marryconst & temp_marryconst_list = msg.marryconst_list(i);
		marryconst_List[i].read_from_pbmsg(temp_marryconst_list);
	}
}

marrybanquetfireworkDesc_s::marrybanquetfireworkDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int marrybanquetfireworkDesc_s::CreateInit() {
	Item = (int64_t)0;
	Price = (int32_t)0;
	Efc = (int64_t)0;
	Warm = (int32_t)0;
	return 0;
}

int marrybanquetfireworkDesc_s::ResumeInit() {
	return 0;
}

void marrybanquetfireworkDesc_s::write_to_pbmsg(::proto_ff::marrybanquetfireworkDesc & msg) const {
	msg.set_item((int64_t)Item);
	msg.set_price((int32_t)Price);
	msg.set_efc((int64_t)Efc);
	msg.set_warm((int32_t)Warm);
}

void marrybanquetfireworkDesc_s::read_from_pbmsg(const ::proto_ff::marrybanquetfireworkDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct marrybanquetfireworkDesc_s));
	Item = msg.item();
	Price = msg.price();
	Efc = msg.efc();
	Warm = msg.warm();
}

marrybanquet_s::marrybanquet_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int marrybanquet_s::CreateInit() {
	id = (int32_t)0;
	orderItem = (int64_t)0;
	orderNum = (int32_t)0;
	banquetReward = (int64_t)0;
	rewardNum = (int32_t)0;
	makeLoveWarmValue = (int32_t)0;
	inviteNum = (int32_t)0;
	strangerNum = (int32_t)0;
	preludeTime = (int32_t)0;
	banquetTime = (int32_t)0;
	makeLoveEfc = (int64_t)0;
	warmValue = (int32_t)0;
	warmCycle = (int32_t)0;
	duplcateId = (int64_t)0;
	return 0;
}

int marrybanquet_s::ResumeInit() {
	return 0;
}

void marrybanquet_s::write_to_pbmsg(::proto_ff::marrybanquet & msg) const {
	msg.set_id((int32_t)id);
	msg.set_orderitem((int64_t)orderItem);
	msg.set_ordernum((int32_t)orderNum);
	msg.set_banquetreward((int64_t)banquetReward);
	msg.set_rewardnum((int32_t)rewardNum);
	msg.set_makelovewarmvalue((int32_t)makeLoveWarmValue);
	msg.set_invitenum((int32_t)inviteNum);
	msg.set_strangernum((int32_t)strangerNum);
	msg.set_preludetime((int32_t)preludeTime);
	msg.set_banquettime((int32_t)banquetTime);
	msg.set_makeloveefc((int64_t)makeLoveEfc);
	msg.set_warmvalue((int32_t)warmValue);
	msg.set_warmcycle((int32_t)warmCycle);
	msg.set_duplcateid((int64_t)duplcateId);
	for(int32_t i = 0; i < (int32_t)firework.GetSize() && i < firework.GetMaxSize(); ++i) {
		::proto_ff::marrybanquetfireworkDesc* temp_firework = msg.add_firework();
		firework[i].write_to_pbmsg(*temp_firework);
	}
}

void marrybanquet_s::read_from_pbmsg(const ::proto_ff::marrybanquet & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct marrybanquet_s));
	id = msg.id();
	orderItem = msg.orderitem();
	orderNum = msg.ordernum();
	banquetReward = msg.banquetreward();
	rewardNum = msg.rewardnum();
	makeLoveWarmValue = msg.makelovewarmvalue();
	inviteNum = msg.invitenum();
	strangerNum = msg.strangernum();
	preludeTime = msg.preludetime();
	banquetTime = msg.banquettime();
	makeLoveEfc = msg.makeloveefc();
	warmValue = msg.warmvalue();
	warmCycle = msg.warmcycle();
	duplcateId = msg.duplcateid();
	firework.SetSize(msg.firework_size() > firework.GetMaxSize() ? firework.GetMaxSize() : msg.firework_size());
	for(int32_t i = 0; i < (int32_t)firework.GetSize(); ++i) {
		const ::proto_ff::marrybanquetfireworkDesc & temp_firework = msg.firework(i);
		firework[i].read_from_pbmsg(temp_firework);
	}
}

Sheet_marrybanquet_s::Sheet_marrybanquet_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_marrybanquet_s::CreateInit() {
	return 0;
}

int Sheet_marrybanquet_s::ResumeInit() {
	return 0;
}

void Sheet_marrybanquet_s::write_to_pbmsg(::proto_ff::Sheet_marrybanquet & msg) const {
	for(int32_t i = 0; i < (int32_t)marrybanquet_List.GetSize() && i < marrybanquet_List.GetMaxSize(); ++i) {
		::proto_ff::marrybanquet* temp_marrybanquet_list = msg.add_marrybanquet_list();
		marrybanquet_List[i].write_to_pbmsg(*temp_marrybanquet_list);
	}
}

void Sheet_marrybanquet_s::read_from_pbmsg(const ::proto_ff::Sheet_marrybanquet & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_marrybanquet_s));
	marrybanquet_List.SetSize(msg.marrybanquet_list_size() > marrybanquet_List.GetMaxSize() ? marrybanquet_List.GetMaxSize() : msg.marrybanquet_list_size());
	for(int32_t i = 0; i < (int32_t)marrybanquet_List.GetSize(); ++i) {
		const ::proto_ff::marrybanquet & temp_marrybanquet_list = msg.marrybanquet_list(i);
		marrybanquet_List[i].read_from_pbmsg(temp_marrybanquet_list);
	}
}

marrygear_s::marrygear_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int marrygear_s::CreateInit() {
	id = (int32_t)0;
	title = (int64_t)0;
	item = (int64_t)0;
	initiate = (int64_t)0;
	usetype = (int32_t)0;
	useprice = (int32_t)0;
	AAPrice = (int32_t)0;
	weddingEffect = (int64_t)0;
	return 0;
}

int marrygear_s::ResumeInit() {
	return 0;
}

void marrygear_s::write_to_pbmsg(::proto_ff::marrygear & msg) const {
	msg.set_id((int32_t)id);
	msg.set_title((int64_t)title);
	msg.set_item((int64_t)item);
	msg.set_nickname((const char*)nickName.Get());
	msg.set_initiate((int64_t)initiate);
	msg.set_usetype((int32_t)usetype);
	msg.set_useprice((int32_t)useprice);
	msg.set_aaprice((int32_t)AAPrice);
	msg.set_preset((const char*)preset.Get());
	msg.set_weddingeffect((int64_t)weddingEffect);
}

void marrygear_s::read_from_pbmsg(const ::proto_ff::marrygear & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct marrygear_s));
	id = msg.id();
	title = msg.title();
	item = msg.item();
	nickName.Copy(msg.nickname());
	initiate = msg.initiate();
	usetype = msg.usetype();
	useprice = msg.useprice();
	AAPrice = msg.aaprice();
	preset.Copy(msg.preset());
	weddingEffect = msg.weddingeffect();
}

Sheet_marrygear_s::Sheet_marrygear_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_marrygear_s::CreateInit() {
	return 0;
}

int Sheet_marrygear_s::ResumeInit() {
	return 0;
}

void Sheet_marrygear_s::write_to_pbmsg(::proto_ff::Sheet_marrygear & msg) const {
	for(int32_t i = 0; i < (int32_t)marrygear_List.GetSize() && i < marrygear_List.GetMaxSize(); ++i) {
		::proto_ff::marrygear* temp_marrygear_list = msg.add_marrygear_list();
		marrygear_List[i].write_to_pbmsg(*temp_marrygear_list);
	}
}

void Sheet_marrygear_s::read_from_pbmsg(const ::proto_ff::Sheet_marrygear & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_marrygear_s));
	marrygear_List.SetSize(msg.marrygear_list_size() > marrygear_List.GetMaxSize() ? marrygear_List.GetMaxSize() : msg.marrygear_list_size());
	for(int32_t i = 0; i < (int32_t)marrygear_List.GetSize(); ++i) {
		const ::proto_ff::marrygear & temp_marrygear_list = msg.marrygear_list(i);
		marrygear_List[i].read_from_pbmsg(temp_marrygear_list);
	}
}

marrytimes_s::marrytimes_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int marrytimes_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int marrytimes_s::ResumeInit() {
	return 0;
}

void marrytimes_s::write_to_pbmsg(::proto_ff::marrytimes & msg) const {
	msg.set_id((int32_t)id);
	msg.set_starttime((const char*)startTime.Get());
	msg.set_endtime((const char*)endTime.Get());
	msg.set_limit((const char*)limit.Get());
}

void marrytimes_s::read_from_pbmsg(const ::proto_ff::marrytimes & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct marrytimes_s));
	id = msg.id();
	startTime.Copy(msg.starttime());
	endTime.Copy(msg.endtime());
	limit.Copy(msg.limit());
}

Sheet_marrytimes_s::Sheet_marrytimes_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_marrytimes_s::CreateInit() {
	return 0;
}

int Sheet_marrytimes_s::ResumeInit() {
	return 0;
}

void Sheet_marrytimes_s::write_to_pbmsg(::proto_ff::Sheet_marrytimes & msg) const {
	for(int32_t i = 0; i < (int32_t)marrytimes_List.GetSize() && i < marrytimes_List.GetMaxSize(); ++i) {
		::proto_ff::marrytimes* temp_marrytimes_list = msg.add_marrytimes_list();
		marrytimes_List[i].write_to_pbmsg(*temp_marrytimes_list);
	}
}

void Sheet_marrytimes_s::read_from_pbmsg(const ::proto_ff::Sheet_marrytimes & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_marrytimes_s));
	marrytimes_List.SetSize(msg.marrytimes_list_size() > marrytimes_List.GetMaxSize() ? marrytimes_List.GetMaxSize() : msg.marrytimes_list_size());
	for(int32_t i = 0; i < (int32_t)marrytimes_List.GetSize(); ++i) {
		const ::proto_ff::marrytimes & temp_marrytimes_list = msg.marrytimes_list(i);
		marrytimes_List[i].read_from_pbmsg(temp_marrytimes_list);
	}
}

marrywarm_s::marrywarm_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int marrywarm_s::CreateInit() {
	id = (int32_t)0;
	warmValue = (int32_t)0;
	monsterId = (int64_t)0;
	monsterFlashCycle = (int32_t)0;
	warmExpValue = (int32_t)0;
	warmExpCycle = (int32_t)0;
	warmGetNum = (int32_t)0;
	return 0;
}

int marrywarm_s::ResumeInit() {
	return 0;
}

void marrywarm_s::write_to_pbmsg(::proto_ff::marrywarm & msg) const {
	msg.set_id((int32_t)id);
	msg.set_warmvalue((int32_t)warmValue);
	msg.set_monsterid((int64_t)monsterId);
	msg.set_monsterflashcycle((int32_t)monsterFlashCycle);
	msg.set_warmexpvalue((int32_t)warmExpValue);
	msg.set_warmexpcycle((int32_t)warmExpCycle);
	msg.set_warmgetnum((int32_t)warmGetNum);
}

void marrywarm_s::read_from_pbmsg(const ::proto_ff::marrywarm & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct marrywarm_s));
	id = msg.id();
	warmValue = msg.warmvalue();
	monsterId = msg.monsterid();
	monsterFlashCycle = msg.monsterflashcycle();
	warmExpValue = msg.warmexpvalue();
	warmExpCycle = msg.warmexpcycle();
	warmGetNum = msg.warmgetnum();
}

Sheet_marrywarm_s::Sheet_marrywarm_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_marrywarm_s::CreateInit() {
	return 0;
}

int Sheet_marrywarm_s::ResumeInit() {
	return 0;
}

void Sheet_marrywarm_s::write_to_pbmsg(::proto_ff::Sheet_marrywarm & msg) const {
	for(int32_t i = 0; i < (int32_t)marrywarm_List.GetSize() && i < marrywarm_List.GetMaxSize(); ++i) {
		::proto_ff::marrywarm* temp_marrywarm_list = msg.add_marrywarm_list();
		marrywarm_List[i].write_to_pbmsg(*temp_marrywarm_list);
	}
}

void Sheet_marrywarm_s::read_from_pbmsg(const ::proto_ff::Sheet_marrywarm & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_marrywarm_s));
	marrywarm_List.SetSize(msg.marrywarm_list_size() > marrywarm_List.GetMaxSize() ? marrywarm_List.GetMaxSize() : msg.marrywarm_list_size());
	for(int32_t i = 0; i < (int32_t)marrywarm_List.GetSize(); ++i) {
		const ::proto_ff::marrywarm & temp_marrywarm_list = msg.marrywarm_list(i);
		marrywarm_List[i].read_from_pbmsg(temp_marrywarm_list);
	}
}

marrylevelexpwarmDesc_s::marrylevelexpwarmDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int marrylevelexpwarmDesc_s::CreateInit() {
	Id = (int32_t)0;
	Exp = (int64_t)0;
	return 0;
}

int marrylevelexpwarmDesc_s::ResumeInit() {
	return 0;
}

void marrylevelexpwarmDesc_s::write_to_pbmsg(::proto_ff::marrylevelexpwarmDesc & msg) const {
	msg.set_id((int32_t)Id);
	msg.set_exp((int64_t)Exp);
}

void marrylevelexpwarmDesc_s::read_from_pbmsg(const ::proto_ff::marrylevelexpwarmDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct marrylevelexpwarmDesc_s));
	Id = msg.id();
	Exp = msg.exp();
}

marrylevelexp_s::marrylevelexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int marrylevelexp_s::CreateInit() {
	level = (int32_t)0;
	return 0;
}

int marrylevelexp_s::ResumeInit() {
	return 0;
}

void marrylevelexp_s::write_to_pbmsg(::proto_ff::marrylevelexp & msg) const {
	msg.set_level((int32_t)level);
	for(int32_t i = 0; i < (int32_t)warm.GetSize() && i < warm.GetMaxSize(); ++i) {
		::proto_ff::marrylevelexpwarmDesc* temp_warm = msg.add_warm();
		warm[i].write_to_pbmsg(*temp_warm);
	}
}

void marrylevelexp_s::read_from_pbmsg(const ::proto_ff::marrylevelexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct marrylevelexp_s));
	level = msg.level();
	warm.SetSize(msg.warm_size() > warm.GetMaxSize() ? warm.GetMaxSize() : msg.warm_size());
	for(int32_t i = 0; i < (int32_t)warm.GetSize(); ++i) {
		const ::proto_ff::marrylevelexpwarmDesc & temp_warm = msg.warm(i);
		warm[i].read_from_pbmsg(temp_warm);
	}
}

Sheet_marrylevelexp_s::Sheet_marrylevelexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_marrylevelexp_s::CreateInit() {
	return 0;
}

int Sheet_marrylevelexp_s::ResumeInit() {
	return 0;
}

void Sheet_marrylevelexp_s::write_to_pbmsg(::proto_ff::Sheet_marrylevelexp & msg) const {
	for(int32_t i = 0; i < (int32_t)marrylevelexp_List.GetSize() && i < marrylevelexp_List.GetMaxSize(); ++i) {
		::proto_ff::marrylevelexp* temp_marrylevelexp_list = msg.add_marrylevelexp_list();
		marrylevelexp_List[i].write_to_pbmsg(*temp_marrylevelexp_list);
	}
}

void Sheet_marrylevelexp_s::read_from_pbmsg(const ::proto_ff::Sheet_marrylevelexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_marrylevelexp_s));
	marrylevelexp_List.SetSize(msg.marrylevelexp_list_size() > marrylevelexp_List.GetMaxSize() ? marrylevelexp_List.GetMaxSize() : msg.marrylevelexp_list_size());
	for(int32_t i = 0; i < (int32_t)marrylevelexp_List.GetSize(); ++i) {
		const ::proto_ff::marrylevelexp & temp_marrylevelexp_list = msg.marrylevelexp_list(i);
		marrylevelexp_List[i].read_from_pbmsg(temp_marrylevelexp_list);
	}
}

}