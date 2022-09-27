#include "activity_s.h"

namespace proto_ff_s {

activitydaily_s::activitydaily_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitydaily_s::CreateInit() {
	activeId = (int64_t)0;
	typeId = (int32_t)0;
	Descriptiontype = (int32_t)0;
	typeArgs = (int64_t)0;
	minlevel = (int32_t)0;
	openingTime = (int32_t)0;
	advanceTime = (int32_t)0;
	intervalTime = (int32_t)0;
	isCross = (int32_t)0;
	serverTime = (int32_t)0;
	serverdelayTime = (int32_t)0;
	forwordEnterTime = (int32_t)0;
	return 0;
}

int activitydaily_s::ResumeInit() {
	return 0;
}

void activitydaily_s::write_to_pbmsg(::proto_ff::activitydaily & msg) const {
	msg.set_activeid((int64_t)activeId);
	msg.set_activename((const char*)activeName.Get());
	msg.set_typeid_((int32_t)typeId);
	msg.set_descriptiontype((int32_t)Descriptiontype);
	msg.set_typeargs((int64_t)typeArgs);
	msg.set_involvemap((const char*)involveMap.Get());
	msg.set_minlevel((int32_t)minlevel);
	msg.set_opencycle((const char*)openCycle.Get());
	msg.set_opentime((const char*)openTime.Get());
	msg.set_pushtime((const char*)pushTime.Get());
	msg.set_openingtime((int32_t)openingTime);
	msg.set_advancetime((int32_t)advanceTime);
	msg.set_intervaltime((int32_t)intervalTime);
	msg.set_opeday((const char*)opeDay.Get());
	msg.set_closeday((const char*)closeDay.Get());
	msg.set_iscross((int32_t)isCross);
	msg.set_servertime((int32_t)serverTime);
	msg.set_serverdelaytime((int32_t)serverdelayTime);
	msg.set_forwordentertime((int32_t)forwordEnterTime);
}

void activitydaily_s::read_from_pbmsg(const ::proto_ff::activitydaily & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitydaily_s));
	activeId = msg.activeid();
	activeName.Copy(msg.activename());
	typeId = msg.typeid_();
	Descriptiontype = msg.descriptiontype();
	typeArgs = msg.typeargs();
	involveMap.Copy(msg.involvemap());
	minlevel = msg.minlevel();
	openCycle.Copy(msg.opencycle());
	openTime.Copy(msg.opentime());
	pushTime.Copy(msg.pushtime());
	openingTime = msg.openingtime();
	advanceTime = msg.advancetime();
	intervalTime = msg.intervaltime();
	opeDay.Copy(msg.opeday());
	closeDay.Copy(msg.closeday());
	isCross = msg.iscross();
	serverTime = msg.servertime();
	serverdelayTime = msg.serverdelaytime();
	forwordEnterTime = msg.forwordentertime();
}

Sheet_activitydaily_s::Sheet_activitydaily_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activitydaily_s::CreateInit() {
	return 0;
}

int Sheet_activitydaily_s::ResumeInit() {
	return 0;
}

void Sheet_activitydaily_s::write_to_pbmsg(::proto_ff::Sheet_activitydaily & msg) const {
	for(int32_t i = 0; i < (int32_t)activitydaily_List.GetSize() && i < activitydaily_List.GetMaxSize(); ++i) {
		::proto_ff::activitydaily* temp_activitydaily_list = msg.add_activitydaily_list();
		activitydaily_List[i].write_to_pbmsg(*temp_activitydaily_list);
	}
}

void Sheet_activitydaily_s::read_from_pbmsg(const ::proto_ff::Sheet_activitydaily & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activitydaily_s));
	activitydaily_List.SetSize(msg.activitydaily_list_size() > activitydaily_List.GetMaxSize() ? activitydaily_List.GetMaxSize() : msg.activitydaily_list_size());
	for(int32_t i = 0; i < (int32_t)activitydaily_List.GetSize(); ++i) {
		const ::proto_ff::activitydaily & temp_activitydaily_list = msg.activitydaily_list(i);
		activitydaily_List[i].read_from_pbmsg(temp_activitydaily_list);
	}
}

activityactivitynotice_s::activityactivitynotice_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activityactivitynotice_s::CreateInit() {
	activeId = (int64_t)0;
	return 0;
}

int activityactivitynotice_s::ResumeInit() {
	return 0;
}

void activityactivitynotice_s::write_to_pbmsg(::proto_ff::activityactivitynotice & msg) const {
	msg.set_activeid((int64_t)activeId);
}

void activityactivitynotice_s::read_from_pbmsg(const ::proto_ff::activityactivitynotice & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activityactivitynotice_s));
	activeId = msg.activeid();
}

Sheet_activityactivitynotice_s::Sheet_activityactivitynotice_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activityactivitynotice_s::CreateInit() {
	return 0;
}

int Sheet_activityactivitynotice_s::ResumeInit() {
	return 0;
}

void Sheet_activityactivitynotice_s::write_to_pbmsg(::proto_ff::Sheet_activityactivitynotice & msg) const {
	for(int32_t i = 0; i < (int32_t)activityactivitynotice_List.GetSize() && i < activityactivitynotice_List.GetMaxSize(); ++i) {
		::proto_ff::activityactivitynotice* temp_activityactivitynotice_list = msg.add_activityactivitynotice_list();
		activityactivitynotice_List[i].write_to_pbmsg(*temp_activityactivitynotice_list);
	}
}

void Sheet_activityactivitynotice_s::read_from_pbmsg(const ::proto_ff::Sheet_activityactivitynotice & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activityactivitynotice_s));
	activityactivitynotice_List.SetSize(msg.activityactivitynotice_list_size() > activityactivitynotice_List.GetMaxSize() ? activityactivitynotice_List.GetMaxSize() : msg.activityactivitynotice_list_size());
	for(int32_t i = 0; i < (int32_t)activityactivitynotice_List.GetSize(); ++i) {
		const ::proto_ff::activityactivitynotice & temp_activityactivitynotice_list = msg.activityactivitynotice_list(i);
		activityactivitynotice_List[i].read_from_pbmsg(temp_activityactivitynotice_list);
	}
}

activityscufflerewardDesc_s::activityscufflerewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activityscufflerewardDesc_s::CreateInit() {
	Num = (int64_t)0;
	ID = (int64_t)0;
	return 0;
}

int activityscufflerewardDesc_s::ResumeInit() {
	return 0;
}

void activityscufflerewardDesc_s::write_to_pbmsg(::proto_ff::activityscufflerewardDesc & msg) const {
	msg.set_num((int64_t)Num);
	msg.set_id((int64_t)ID);
}

void activityscufflerewardDesc_s::read_from_pbmsg(const ::proto_ff::activityscufflerewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activityscufflerewardDesc_s));
	Num = msg.num();
	ID = msg.id();
}

activityscuffle_s::activityscuffle_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activityscuffle_s::CreateInit() {
	id = (int64_t)0;
	typeArgs = (int32_t)0;
	level = (int32_t)0;
	stage = (int32_t)0;
	mapID = (int64_t)0;
	nextID = (int64_t)0;
	maxPoints = (int32_t)0;
	pvePoints = (int32_t)0;
	pvpPoints = (int32_t)0;
	pvpHelpPoints = (int32_t)0;
	return 0;
}

int activityscuffle_s::ResumeInit() {
	return 0;
}

void activityscuffle_s::write_to_pbmsg(::proto_ff::activityscuffle & msg) const {
	msg.set_id((int64_t)id);
	msg.set_typeargs((int32_t)typeArgs);
	msg.set_level((int32_t)level);
	msg.set_stage((int32_t)stage);
	msg.set_mapid((int64_t)mapID);
	msg.set_nextid((int64_t)nextID);
	msg.set_maxpoints((int32_t)maxPoints);
	msg.set_pvepoints((int32_t)pvePoints);
	msg.set_pvppoints((int32_t)pvpPoints);
	msg.set_pvphelppoints((int32_t)pvpHelpPoints);
	for(int32_t i = 0; i < (int32_t)reward.GetSize() && i < reward.GetMaxSize(); ++i) {
		::proto_ff::activityscufflerewardDesc* temp_reward = msg.add_reward();
		reward[i].write_to_pbmsg(*temp_reward);
	}
}

void activityscuffle_s::read_from_pbmsg(const ::proto_ff::activityscuffle & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activityscuffle_s));
	id = msg.id();
	typeArgs = msg.typeargs();
	level = msg.level();
	stage = msg.stage();
	mapID = msg.mapid();
	nextID = msg.nextid();
	maxPoints = msg.maxpoints();
	pvePoints = msg.pvepoints();
	pvpPoints = msg.pvppoints();
	pvpHelpPoints = msg.pvphelppoints();
	reward.SetSize(msg.reward_size() > reward.GetMaxSize() ? reward.GetMaxSize() : msg.reward_size());
	for(int32_t i = 0; i < (int32_t)reward.GetSize(); ++i) {
		const ::proto_ff::activityscufflerewardDesc & temp_reward = msg.reward(i);
		reward[i].read_from_pbmsg(temp_reward);
	}
}

Sheet_activityscuffle_s::Sheet_activityscuffle_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activityscuffle_s::CreateInit() {
	return 0;
}

int Sheet_activityscuffle_s::ResumeInit() {
	return 0;
}

void Sheet_activityscuffle_s::write_to_pbmsg(::proto_ff::Sheet_activityscuffle & msg) const {
	for(int32_t i = 0; i < (int32_t)activityscuffle_List.GetSize() && i < activityscuffle_List.GetMaxSize(); ++i) {
		::proto_ff::activityscuffle* temp_activityscuffle_list = msg.add_activityscuffle_list();
		activityscuffle_List[i].write_to_pbmsg(*temp_activityscuffle_list);
	}
}

void Sheet_activityscuffle_s::read_from_pbmsg(const ::proto_ff::Sheet_activityscuffle & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activityscuffle_s));
	activityscuffle_List.SetSize(msg.activityscuffle_list_size() > activityscuffle_List.GetMaxSize() ? activityscuffle_List.GetMaxSize() : msg.activityscuffle_list_size());
	for(int32_t i = 0; i < (int32_t)activityscuffle_List.GetSize(); ++i) {
		const ::proto_ff::activityscuffle & temp_activityscuffle_list = msg.activityscuffle_list(i);
		activityscuffle_List[i].read_from_pbmsg(temp_activityscuffle_list);
	}
}

activitychaosDragonsrewardDesc_s::activitychaosDragonsrewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitychaosDragonsrewardDesc_s::CreateInit() {
	Num = (int64_t)0;
	ID = (int64_t)0;
	return 0;
}

int activitychaosDragonsrewardDesc_s::ResumeInit() {
	return 0;
}

void activitychaosDragonsrewardDesc_s::write_to_pbmsg(::proto_ff::activitychaosDragonsrewardDesc & msg) const {
	msg.set_num((int64_t)Num);
	msg.set_id((int64_t)ID);
}

void activitychaosDragonsrewardDesc_s::read_from_pbmsg(const ::proto_ff::activitychaosDragonsrewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitychaosDragonsrewardDesc_s));
	Num = msg.num();
	ID = msg.id();
}

activitychaosDragons_s::activitychaosDragons_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitychaosDragons_s::CreateInit() {
	id = (int32_t)0;
	reward_type = (int32_t)0;
	reward_param = (int32_t)0;
	rankmin = (int32_t)0;
	rankmax = (int32_t)0;
	getPoint = (int64_t)0;
	return 0;
}

int activitychaosDragons_s::ResumeInit() {
	return 0;
}

void activitychaosDragons_s::write_to_pbmsg(::proto_ff::activitychaosDragons & msg) const {
	msg.set_id((int32_t)id);
	msg.set_reward_type((int32_t)reward_type);
	msg.set_reward_param((int32_t)reward_param);
	msg.set_rankmin((int32_t)rankmin);
	msg.set_rankmax((int32_t)rankmax);
	msg.set_getpoint((int64_t)getPoint);
	for(int32_t i = 0; i < (int32_t)reward.GetSize() && i < reward.GetMaxSize(); ++i) {
		::proto_ff::activitychaosDragonsrewardDesc* temp_reward = msg.add_reward();
		reward[i].write_to_pbmsg(*temp_reward);
	}
}

void activitychaosDragons_s::read_from_pbmsg(const ::proto_ff::activitychaosDragons & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitychaosDragons_s));
	id = msg.id();
	reward_type = msg.reward_type();
	reward_param = msg.reward_param();
	rankmin = msg.rankmin();
	rankmax = msg.rankmax();
	getPoint = msg.getpoint();
	reward.SetSize(msg.reward_size() > reward.GetMaxSize() ? reward.GetMaxSize() : msg.reward_size());
	for(int32_t i = 0; i < (int32_t)reward.GetSize(); ++i) {
		const ::proto_ff::activitychaosDragonsrewardDesc & temp_reward = msg.reward(i);
		reward[i].read_from_pbmsg(temp_reward);
	}
}

Sheet_activitychaosDragons_s::Sheet_activitychaosDragons_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activitychaosDragons_s::CreateInit() {
	return 0;
}

int Sheet_activitychaosDragons_s::ResumeInit() {
	return 0;
}

void Sheet_activitychaosDragons_s::write_to_pbmsg(::proto_ff::Sheet_activitychaosDragons & msg) const {
	for(int32_t i = 0; i < (int32_t)activitychaosDragons_List.GetSize() && i < activitychaosDragons_List.GetMaxSize(); ++i) {
		::proto_ff::activitychaosDragons* temp_activitychaosdragons_list = msg.add_activitychaosdragons_list();
		activitychaosDragons_List[i].write_to_pbmsg(*temp_activitychaosdragons_list);
	}
}

void Sheet_activitychaosDragons_s::read_from_pbmsg(const ::proto_ff::Sheet_activitychaosDragons & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activitychaosDragons_s));
	activitychaosDragons_List.SetSize(msg.activitychaosdragons_list_size() > activitychaosDragons_List.GetMaxSize() ? activitychaosDragons_List.GetMaxSize() : msg.activitychaosdragons_list_size());
	for(int32_t i = 0; i < (int32_t)activitychaosDragons_List.GetSize(); ++i) {
		const ::proto_ff::activitychaosDragons & temp_activitychaosdragons_list = msg.activitychaosdragons_list(i);
		activitychaosDragons_List[i].read_from_pbmsg(temp_activitychaosdragons_list);
	}
}

activitycircus_s::activitycircus_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitycircus_s::CreateInit() {
	circusID = (int64_t)0;
	powerLow = (int64_t)0;
	powerUp = (int64_t)0;
	return 0;
}

int activitycircus_s::ResumeInit() {
	return 0;
}

void activitycircus_s::write_to_pbmsg(::proto_ff::activitycircus & msg) const {
	msg.set_circusid((int64_t)circusID);
	msg.set_powerlow((int64_t)powerLow);
	msg.set_powerup((int64_t)powerUp);
	for(int32_t i = 0; i < (int32_t)circus_a.GetSize() && i < circus_a.GetMaxSize(); ++i) {
		msg.add_circus_a((int32_t)circus_a[i]);
	}
	for(int32_t i = 0; i < (int32_t)circus_b.GetSize() && i < circus_b.GetMaxSize(); ++i) {
		msg.add_circus_b((int64_t)circus_b[i]);
	}
}

void activitycircus_s::read_from_pbmsg(const ::proto_ff::activitycircus & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitycircus_s));
	circusID = msg.circusid();
	powerLow = msg.powerlow();
	powerUp = msg.powerup();
	circus_a.SetSize(msg.circus_a_size() > circus_a.GetMaxSize() ? circus_a.GetMaxSize() : msg.circus_a_size());
	for(int32_t i = 0; i < (int32_t)circus_a.GetSize(); ++i) {
		circus_a[i] = msg.circus_a(i);
	}
	circus_b.SetSize(msg.circus_b_size() > circus_b.GetMaxSize() ? circus_b.GetMaxSize() : msg.circus_b_size());
	for(int32_t i = 0; i < (int32_t)circus_b.GetSize(); ++i) {
		circus_b[i] = msg.circus_b(i);
	}
}

Sheet_activitycircus_s::Sheet_activitycircus_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activitycircus_s::CreateInit() {
	return 0;
}

int Sheet_activitycircus_s::ResumeInit() {
	return 0;
}

void Sheet_activitycircus_s::write_to_pbmsg(::proto_ff::Sheet_activitycircus & msg) const {
	for(int32_t i = 0; i < (int32_t)activitycircus_List.GetSize() && i < activitycircus_List.GetMaxSize(); ++i) {
		::proto_ff::activitycircus* temp_activitycircus_list = msg.add_activitycircus_list();
		activitycircus_List[i].write_to_pbmsg(*temp_activitycircus_list);
	}
}

void Sheet_activitycircus_s::read_from_pbmsg(const ::proto_ff::Sheet_activitycircus & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activitycircus_s));
	activitycircus_List.SetSize(msg.activitycircus_list_size() > activitycircus_List.GetMaxSize() ? activitycircus_List.GetMaxSize() : msg.activitycircus_list_size());
	for(int32_t i = 0; i < (int32_t)activitycircus_List.GetSize(); ++i) {
		const ::proto_ff::activitycircus & temp_activitycircus_list = msg.activitycircus_list(i);
		activitycircus_List[i].read_from_pbmsg(temp_activitycircus_list);
	}
}

activitycircusNumitemDesc_s::activitycircusNumitemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitycircusNumitemDesc_s::CreateInit() {
	Num = (int32_t)0;
	Id = (int64_t)0;
	return 0;
}

int activitycircusNumitemDesc_s::ResumeInit() {
	return 0;
}

void activitycircusNumitemDesc_s::write_to_pbmsg(::proto_ff::activitycircusNumitemDesc & msg) const {
	msg.set_num((int32_t)Num);
	msg.set_id((int64_t)Id);
}

void activitycircusNumitemDesc_s::read_from_pbmsg(const ::proto_ff::activitycircusNumitemDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitycircusNumitemDesc_s));
	Num = msg.num();
	Id = msg.id();
}

activitycircusNum_s::activitycircusNum_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitycircusNum_s::CreateInit() {
	RankID = (int32_t)0;
	return 0;
}

int activitycircusNum_s::ResumeInit() {
	return 0;
}

void activitycircusNum_s::write_to_pbmsg(::proto_ff::activitycircusNum & msg) const {
	msg.set_rankid((int32_t)RankID);
	for(int32_t i = 0; i < (int32_t)item.GetSize() && i < item.GetMaxSize(); ++i) {
		::proto_ff::activitycircusNumitemDesc* temp_item = msg.add_item();
		item[i].write_to_pbmsg(*temp_item);
	}
}

void activitycircusNum_s::read_from_pbmsg(const ::proto_ff::activitycircusNum & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitycircusNum_s));
	RankID = msg.rankid();
	item.SetSize(msg.item_size() > item.GetMaxSize() ? item.GetMaxSize() : msg.item_size());
	for(int32_t i = 0; i < (int32_t)item.GetSize(); ++i) {
		const ::proto_ff::activitycircusNumitemDesc & temp_item = msg.item(i);
		item[i].read_from_pbmsg(temp_item);
	}
}

Sheet_activitycircusNum_s::Sheet_activitycircusNum_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activitycircusNum_s::CreateInit() {
	return 0;
}

int Sheet_activitycircusNum_s::ResumeInit() {
	return 0;
}

void Sheet_activitycircusNum_s::write_to_pbmsg(::proto_ff::Sheet_activitycircusNum & msg) const {
	for(int32_t i = 0; i < (int32_t)activitycircusNum_List.GetSize() && i < activitycircusNum_List.GetMaxSize(); ++i) {
		::proto_ff::activitycircusNum* temp_activitycircusnum_list = msg.add_activitycircusnum_list();
		activitycircusNum_List[i].write_to_pbmsg(*temp_activitycircusnum_list);
	}
}

void Sheet_activitycircusNum_s::read_from_pbmsg(const ::proto_ff::Sheet_activitycircusNum & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activitycircusNum_s));
	activitycircusNum_List.SetSize(msg.activitycircusnum_list_size() > activitycircusNum_List.GetMaxSize() ? activitycircusNum_List.GetMaxSize() : msg.activitycircusnum_list_size());
	for(int32_t i = 0; i < (int32_t)activitycircusNum_List.GetSize(); ++i) {
		const ::proto_ff::activitycircusNum & temp_activitycircusnum_list = msg.activitycircusnum_list(i);
		activitycircusNum_List[i].read_from_pbmsg(temp_activitycircusnum_list);
	}
}

activitycircusDanitemDesc_s::activitycircusDanitemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitycircusDanitemDesc_s::CreateInit() {
	Num = (int32_t)0;
	Id = (int64_t)0;
	return 0;
}

int activitycircusDanitemDesc_s::ResumeInit() {
	return 0;
}

void activitycircusDanitemDesc_s::write_to_pbmsg(::proto_ff::activitycircusDanitemDesc & msg) const {
	msg.set_num((int32_t)Num);
	msg.set_id((int64_t)Id);
}

void activitycircusDanitemDesc_s::read_from_pbmsg(const ::proto_ff::activitycircusDanitemDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitycircusDanitemDesc_s));
	Num = msg.num();
	Id = msg.id();
}

activitycircusDancircusDesc_s::activitycircusDancircusDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitycircusDancircusDesc_s::CreateInit() {
	Num = (int32_t)0;
	Id = (int64_t)0;
	return 0;
}

int activitycircusDancircusDesc_s::ResumeInit() {
	return 0;
}

void activitycircusDancircusDesc_s::write_to_pbmsg(::proto_ff::activitycircusDancircusDesc & msg) const {
	msg.set_num((int32_t)Num);
	msg.set_id((int64_t)Id);
}

void activitycircusDancircusDesc_s::read_from_pbmsg(const ::proto_ff::activitycircusDancircusDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitycircusDancircusDesc_s));
	Num = msg.num();
	Id = msg.id();
}

activitycircusDan_s::activitycircusDan_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitycircusDan_s::CreateInit() {
	changCiID = (int32_t)0;
	return 0;
}

int activitycircusDan_s::ResumeInit() {
	return 0;
}

void activitycircusDan_s::write_to_pbmsg(::proto_ff::activitycircusDan & msg) const {
	msg.set_changciid((int32_t)changCiID);
	for(int32_t i = 0; i < (int32_t)item.GetSize() && i < item.GetMaxSize(); ++i) {
		::proto_ff::activitycircusDanitemDesc* temp_item = msg.add_item();
		item[i].write_to_pbmsg(*temp_item);
	}
	for(int32_t i = 0; i < (int32_t)circus.GetSize() && i < circus.GetMaxSize(); ++i) {
		::proto_ff::activitycircusDancircusDesc* temp_circus = msg.add_circus();
		circus[i].write_to_pbmsg(*temp_circus);
	}
}

void activitycircusDan_s::read_from_pbmsg(const ::proto_ff::activitycircusDan & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitycircusDan_s));
	changCiID = msg.changciid();
	item.SetSize(msg.item_size() > item.GetMaxSize() ? item.GetMaxSize() : msg.item_size());
	for(int32_t i = 0; i < (int32_t)item.GetSize(); ++i) {
		const ::proto_ff::activitycircusDanitemDesc & temp_item = msg.item(i);
		item[i].read_from_pbmsg(temp_item);
	}
	circus.SetSize(msg.circus_size() > circus.GetMaxSize() ? circus.GetMaxSize() : msg.circus_size());
	for(int32_t i = 0; i < (int32_t)circus.GetSize(); ++i) {
		const ::proto_ff::activitycircusDancircusDesc & temp_circus = msg.circus(i);
		circus[i].read_from_pbmsg(temp_circus);
	}
}

Sheet_activitycircusDan_s::Sheet_activitycircusDan_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activitycircusDan_s::CreateInit() {
	return 0;
}

int Sheet_activitycircusDan_s::ResumeInit() {
	return 0;
}

void Sheet_activitycircusDan_s::write_to_pbmsg(::proto_ff::Sheet_activitycircusDan & msg) const {
	for(int32_t i = 0; i < (int32_t)activitycircusDan_List.GetSize() && i < activitycircusDan_List.GetMaxSize(); ++i) {
		::proto_ff::activitycircusDan* temp_activitycircusdan_list = msg.add_activitycircusdan_list();
		activitycircusDan_List[i].write_to_pbmsg(*temp_activitycircusdan_list);
	}
}

void Sheet_activitycircusDan_s::read_from_pbmsg(const ::proto_ff::Sheet_activitycircusDan & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activitycircusDan_s));
	activitycircusDan_List.SetSize(msg.activitycircusdan_list_size() > activitycircusDan_List.GetMaxSize() ? activitycircusDan_List.GetMaxSize() : msg.activitycircusdan_list_size());
	for(int32_t i = 0; i < (int32_t)activitycircusDan_List.GetSize(); ++i) {
		const ::proto_ff::activitycircusDan & temp_activitycircusdan_list = msg.activitycircusdan_list(i);
		activitycircusDan_List[i].read_from_pbmsg(temp_activitycircusdan_list);
	}
}

activitymathrule_s::activitymathrule_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitymathrule_s::CreateInit() {
	activeId = (int64_t)0;
	type = (int32_t)0;
	mapId = (int64_t)0;
	duplicateId = (int64_t)0;
	time = (int32_t)0;
	winnerPoints = (int32_t)0;
	loserPoints = (int32_t)0;
	drawPoints = (int32_t)0;
	rewardtype = (int32_t)0;
	return 0;
}

int activitymathrule_s::ResumeInit() {
	return 0;
}

void activitymathrule_s::write_to_pbmsg(::proto_ff::activitymathrule & msg) const {
	msg.set_activeid((int64_t)activeId);
	msg.set_type((int32_t)type);
	msg.set_mapid((int64_t)mapId);
	msg.set_duplicateid((int64_t)duplicateId);
	msg.set_time((int32_t)time);
	msg.set_winnerpoints((int32_t)winnerPoints);
	msg.set_loserpoints((int32_t)loserPoints);
	msg.set_drawpoints((int32_t)drawPoints);
	msg.set_rewardtype((int32_t)rewardtype);
}

void activitymathrule_s::read_from_pbmsg(const ::proto_ff::activitymathrule & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitymathrule_s));
	activeId = msg.activeid();
	type = msg.type();
	mapId = msg.mapid();
	duplicateId = msg.duplicateid();
	time = msg.time();
	winnerPoints = msg.winnerpoints();
	loserPoints = msg.loserpoints();
	drawPoints = msg.drawpoints();
	rewardtype = msg.rewardtype();
}

Sheet_activitymathrule_s::Sheet_activitymathrule_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activitymathrule_s::CreateInit() {
	return 0;
}

int Sheet_activitymathrule_s::ResumeInit() {
	return 0;
}

void Sheet_activitymathrule_s::write_to_pbmsg(::proto_ff::Sheet_activitymathrule & msg) const {
	for(int32_t i = 0; i < (int32_t)activitymathrule_List.GetSize() && i < activitymathrule_List.GetMaxSize(); ++i) {
		::proto_ff::activitymathrule* temp_activitymathrule_list = msg.add_activitymathrule_list();
		activitymathrule_List[i].write_to_pbmsg(*temp_activitymathrule_list);
	}
}

void Sheet_activitymathrule_s::read_from_pbmsg(const ::proto_ff::Sheet_activitymathrule & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activitymathrule_s));
	activitymathrule_List.SetSize(msg.activitymathrule_list_size() > activitymathrule_List.GetMaxSize() ? activitymathrule_List.GetMaxSize() : msg.activitymathrule_list_size());
	for(int32_t i = 0; i < (int32_t)activitymathrule_List.GetSize(); ++i) {
		const ::proto_ff::activitymathrule & temp_activitymathrule_list = msg.activitymathrule_list(i);
		activitymathrule_List[i].read_from_pbmsg(temp_activitymathrule_list);
	}
}

activitymathrewardrewardDesc_s::activitymathrewardrewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitymathrewardrewardDesc_s::CreateInit() {
	Num = (int32_t)0;
	return 0;
}

int activitymathrewardrewardDesc_s::ResumeInit() {
	return 0;
}

void activitymathrewardrewardDesc_s::write_to_pbmsg(::proto_ff::activitymathrewardrewardDesc & msg) const {
	msg.set_num((int32_t)Num);
}

void activitymathrewardrewardDesc_s::read_from_pbmsg(const ::proto_ff::activitymathrewardrewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitymathrewardrewardDesc_s));
	Num = msg.num();
}

activitymathreward_s::activitymathreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitymathreward_s::CreateInit() {
	ID = (int32_t)0;
	rewardtype = (int32_t)0;
	rewardlevel = (int32_t)0;
	return 0;
}

int activitymathreward_s::ResumeInit() {
	return 0;
}

void activitymathreward_s::write_to_pbmsg(::proto_ff::activitymathreward & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_rewardtype((int32_t)rewardtype);
	msg.set_rewardlevel((int32_t)rewardlevel);
	for(int32_t i = 0; i < (int32_t)reward.GetSize() && i < reward.GetMaxSize(); ++i) {
		::proto_ff::activitymathrewardrewardDesc* temp_reward = msg.add_reward();
		reward[i].write_to_pbmsg(*temp_reward);
	}
	for(int32_t i = 0; i < (int32_t)reward_ID.GetSize() && i < reward_ID.GetMaxSize(); ++i) {
		msg.add_reward_id((int64_t)reward_ID[i]);
	}
}

void activitymathreward_s::read_from_pbmsg(const ::proto_ff::activitymathreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitymathreward_s));
	ID = msg.id();
	rewardtype = msg.rewardtype();
	rewardlevel = msg.rewardlevel();
	reward.SetSize(msg.reward_size() > reward.GetMaxSize() ? reward.GetMaxSize() : msg.reward_size());
	for(int32_t i = 0; i < (int32_t)reward.GetSize(); ++i) {
		const ::proto_ff::activitymathrewardrewardDesc & temp_reward = msg.reward(i);
		reward[i].read_from_pbmsg(temp_reward);
	}
	reward_ID.SetSize(msg.reward_id_size() > reward_ID.GetMaxSize() ? reward_ID.GetMaxSize() : msg.reward_id_size());
	for(int32_t i = 0; i < (int32_t)reward_ID.GetSize(); ++i) {
		reward_ID[i] = msg.reward_id(i);
	}
}

Sheet_activitymathreward_s::Sheet_activitymathreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activitymathreward_s::CreateInit() {
	return 0;
}

int Sheet_activitymathreward_s::ResumeInit() {
	return 0;
}

void Sheet_activitymathreward_s::write_to_pbmsg(::proto_ff::Sheet_activitymathreward & msg) const {
	for(int32_t i = 0; i < (int32_t)activitymathreward_List.GetSize() && i < activitymathreward_List.GetMaxSize(); ++i) {
		::proto_ff::activitymathreward* temp_activitymathreward_list = msg.add_activitymathreward_list();
		activitymathreward_List[i].write_to_pbmsg(*temp_activitymathreward_list);
	}
}

void Sheet_activitymathreward_s::read_from_pbmsg(const ::proto_ff::Sheet_activitymathreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activitymathreward_s));
	activitymathreward_List.SetSize(msg.activitymathreward_list_size() > activitymathreward_List.GetMaxSize() ? activitymathreward_List.GetMaxSize() : msg.activitymathreward_list_size());
	for(int32_t i = 0; i < (int32_t)activitymathreward_List.GetSize(); ++i) {
		const ::proto_ff::activitymathreward & temp_activitymathreward_list = msg.activitymathreward_list(i);
		activitymathreward_List[i].read_from_pbmsg(temp_activitymathreward_list);
	}
}

activitygvgConst_s::activitygvgConst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitygvgConst_s::CreateInit() {
	id = (int32_t)0;
	constantdata = (int64_t)0;
	return 0;
}

int activitygvgConst_s::ResumeInit() {
	return 0;
}

void activitygvgConst_s::write_to_pbmsg(::proto_ff::activitygvgConst & msg) const {
	msg.set_id((int32_t)id);
	msg.set_constantdata((int64_t)constantdata);
	msg.set_stringdata((const char*)stringdata.Get());
}

void activitygvgConst_s::read_from_pbmsg(const ::proto_ff::activitygvgConst & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitygvgConst_s));
	id = msg.id();
	constantdata = msg.constantdata();
	stringdata.Copy(msg.stringdata());
}

Sheet_activitygvgConst_s::Sheet_activitygvgConst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activitygvgConst_s::CreateInit() {
	return 0;
}

int Sheet_activitygvgConst_s::ResumeInit() {
	return 0;
}

void Sheet_activitygvgConst_s::write_to_pbmsg(::proto_ff::Sheet_activitygvgConst & msg) const {
	for(int32_t i = 0; i < (int32_t)activitygvgConst_List.GetSize() && i < activitygvgConst_List.GetMaxSize(); ++i) {
		::proto_ff::activitygvgConst* temp_activitygvgconst_list = msg.add_activitygvgconst_list();
		activitygvgConst_List[i].write_to_pbmsg(*temp_activitygvgconst_list);
	}
}

void Sheet_activitygvgConst_s::read_from_pbmsg(const ::proto_ff::Sheet_activitygvgConst & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activitygvgConst_s));
	activitygvgConst_List.SetSize(msg.activitygvgconst_list_size() > activitygvgConst_List.GetMaxSize() ? activitygvgConst_List.GetMaxSize() : msg.activitygvgconst_list_size());
	for(int32_t i = 0; i < (int32_t)activitygvgConst_List.GetSize(); ++i) {
		const ::proto_ff::activitygvgConst & temp_activitygvgconst_list = msg.activitygvgconst_list(i);
		activitygvgConst_List[i].read_from_pbmsg(temp_activitygvgconst_list);
	}
}

activitygvgRankRewardgMemberrewardDesc_s::activitygvgRankRewardgMemberrewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitygvgRankRewardgMemberrewardDesc_s::CreateInit() {
	Num = (int32_t)0;
	id = (int64_t)0;
	return 0;
}

int activitygvgRankRewardgMemberrewardDesc_s::ResumeInit() {
	return 0;
}

void activitygvgRankRewardgMemberrewardDesc_s::write_to_pbmsg(::proto_ff::activitygvgRankRewardgMemberrewardDesc & msg) const {
	msg.set_num((int32_t)Num);
	msg.set_id((int64_t)id);
}

void activitygvgRankRewardgMemberrewardDesc_s::read_from_pbmsg(const ::proto_ff::activitygvgRankRewardgMemberrewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitygvgRankRewardgMemberrewardDesc_s));
	Num = msg.num();
	id = msg.id();
}

activitygvgRankRewardgLeaderrewardDesc_s::activitygvgRankRewardgLeaderrewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitygvgRankRewardgLeaderrewardDesc_s::CreateInit() {
	Num = (int32_t)0;
	id = (int64_t)0;
	return 0;
}

int activitygvgRankRewardgLeaderrewardDesc_s::ResumeInit() {
	return 0;
}

void activitygvgRankRewardgLeaderrewardDesc_s::write_to_pbmsg(::proto_ff::activitygvgRankRewardgLeaderrewardDesc & msg) const {
	msg.set_num((int32_t)Num);
	msg.set_id((int64_t)id);
}

void activitygvgRankRewardgLeaderrewardDesc_s::read_from_pbmsg(const ::proto_ff::activitygvgRankRewardgLeaderrewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitygvgRankRewardgLeaderrewardDesc_s));
	Num = msg.num();
	id = msg.id();
}

activitygvgRankReward_s::activitygvgRankReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitygvgRankReward_s::CreateInit() {
	id = (int32_t)0;
	gLeaderId = (int64_t)0;
	return 0;
}

int activitygvgRankReward_s::ResumeInit() {
	return 0;
}

void activitygvgRankReward_s::write_to_pbmsg(::proto_ff::activitygvgRankReward & msg) const {
	msg.set_id((int32_t)id);
	msg.set_gleaderid((int64_t)gLeaderId);
	for(int32_t i = 0; i < (int32_t)gMemberreward.GetSize() && i < gMemberreward.GetMaxSize(); ++i) {
		::proto_ff::activitygvgRankRewardgMemberrewardDesc* temp_gmemberreward = msg.add_gmemberreward();
		gMemberreward[i].write_to_pbmsg(*temp_gmemberreward);
	}
	for(int32_t i = 0; i < (int32_t)gLeaderreward.GetSize() && i < gLeaderreward.GetMaxSize(); ++i) {
		::proto_ff::activitygvgRankRewardgLeaderrewardDesc* temp_gleaderreward = msg.add_gleaderreward();
		gLeaderreward[i].write_to_pbmsg(*temp_gleaderreward);
	}
}

void activitygvgRankReward_s::read_from_pbmsg(const ::proto_ff::activitygvgRankReward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitygvgRankReward_s));
	id = msg.id();
	gLeaderId = msg.gleaderid();
	gMemberreward.SetSize(msg.gmemberreward_size() > gMemberreward.GetMaxSize() ? gMemberreward.GetMaxSize() : msg.gmemberreward_size());
	for(int32_t i = 0; i < (int32_t)gMemberreward.GetSize(); ++i) {
		const ::proto_ff::activitygvgRankRewardgMemberrewardDesc & temp_gmemberreward = msg.gmemberreward(i);
		gMemberreward[i].read_from_pbmsg(temp_gmemberreward);
	}
	gLeaderreward.SetSize(msg.gleaderreward_size() > gLeaderreward.GetMaxSize() ? gLeaderreward.GetMaxSize() : msg.gleaderreward_size());
	for(int32_t i = 0; i < (int32_t)gLeaderreward.GetSize(); ++i) {
		const ::proto_ff::activitygvgRankRewardgLeaderrewardDesc & temp_gleaderreward = msg.gleaderreward(i);
		gLeaderreward[i].read_from_pbmsg(temp_gleaderreward);
	}
}

Sheet_activitygvgRankReward_s::Sheet_activitygvgRankReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activitygvgRankReward_s::CreateInit() {
	return 0;
}

int Sheet_activitygvgRankReward_s::ResumeInit() {
	return 0;
}

void Sheet_activitygvgRankReward_s::write_to_pbmsg(::proto_ff::Sheet_activitygvgRankReward & msg) const {
	for(int32_t i = 0; i < (int32_t)activitygvgRankReward_List.GetSize() && i < activitygvgRankReward_List.GetMaxSize(); ++i) {
		::proto_ff::activitygvgRankReward* temp_activitygvgrankreward_list = msg.add_activitygvgrankreward_list();
		activitygvgRankReward_List[i].write_to_pbmsg(*temp_activitygvgrankreward_list);
	}
}

void Sheet_activitygvgRankReward_s::read_from_pbmsg(const ::proto_ff::Sheet_activitygvgRankReward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activitygvgRankReward_s));
	activitygvgRankReward_List.SetSize(msg.activitygvgrankreward_list_size() > activitygvgRankReward_List.GetMaxSize() ? activitygvgRankReward_List.GetMaxSize() : msg.activitygvgrankreward_list_size());
	for(int32_t i = 0; i < (int32_t)activitygvgRankReward_List.GetSize(); ++i) {
		const ::proto_ff::activitygvgRankReward & temp_activitygvgrankreward_list = msg.activitygvgrankreward_list(i);
		activitygvgRankReward_List[i].read_from_pbmsg(temp_activitygvgrankreward_list);
	}
}

activitygvgRewardrewardDesc_s::activitygvgRewardrewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitygvgRewardrewardDesc_s::CreateInit() {
	Num = (int32_t)0;
	return 0;
}

int activitygvgRewardrewardDesc_s::ResumeInit() {
	return 0;
}

void activitygvgRewardrewardDesc_s::write_to_pbmsg(::proto_ff::activitygvgRewardrewardDesc & msg) const {
	msg.set_num((int32_t)Num);
}

void activitygvgRewardrewardDesc_s::read_from_pbmsg(const ::proto_ff::activitygvgRewardrewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitygvgRewardrewardDesc_s));
	Num = msg.num();
}

activitygvgRewardfinalityDesc_s::activitygvgRewardfinalityDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitygvgRewardfinalityDesc_s::CreateInit() {
	Num = (int32_t)0;
	return 0;
}

int activitygvgRewardfinalityDesc_s::ResumeInit() {
	return 0;
}

void activitygvgRewardfinalityDesc_s::write_to_pbmsg(::proto_ff::activitygvgRewardfinalityDesc & msg) const {
	msg.set_num((int32_t)Num);
}

void activitygvgRewardfinalityDesc_s::read_from_pbmsg(const ::proto_ff::activitygvgRewardfinalityDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitygvgRewardfinalityDesc_s));
	Num = msg.num();
}

activitygvgReward_s::activitygvgReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitygvgReward_s::CreateInit() {
	id = (int32_t)0;
	finalityskill = (int64_t)0;
	return 0;
}

int activitygvgReward_s::ResumeInit() {
	return 0;
}

void activitygvgReward_s::write_to_pbmsg(::proto_ff::activitygvgReward & msg) const {
	msg.set_id((int32_t)id);
	msg.set_finalityskill((int64_t)finalityskill);
	for(int32_t i = 0; i < (int32_t)reward.GetSize() && i < reward.GetMaxSize(); ++i) {
		::proto_ff::activitygvgRewardrewardDesc* temp_reward = msg.add_reward();
		reward[i].write_to_pbmsg(*temp_reward);
	}
	for(int32_t i = 0; i < (int32_t)finality.GetSize() && i < finality.GetMaxSize(); ++i) {
		::proto_ff::activitygvgRewardfinalityDesc* temp_finality = msg.add_finality();
		finality[i].write_to_pbmsg(*temp_finality);
	}
	for(int32_t i = 0; i < (int32_t)reward_id.GetSize() && i < reward_id.GetMaxSize(); ++i) {
		msg.add_reward_id((int64_t)reward_id[i]);
	}
	for(int32_t i = 0; i < (int32_t)finality_id.GetSize() && i < finality_id.GetMaxSize(); ++i) {
		msg.add_finality_id((int64_t)finality_id[i]);
	}
}

void activitygvgReward_s::read_from_pbmsg(const ::proto_ff::activitygvgReward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitygvgReward_s));
	id = msg.id();
	finalityskill = msg.finalityskill();
	reward.SetSize(msg.reward_size() > reward.GetMaxSize() ? reward.GetMaxSize() : msg.reward_size());
	for(int32_t i = 0; i < (int32_t)reward.GetSize(); ++i) {
		const ::proto_ff::activitygvgRewardrewardDesc & temp_reward = msg.reward(i);
		reward[i].read_from_pbmsg(temp_reward);
	}
	finality.SetSize(msg.finality_size() > finality.GetMaxSize() ? finality.GetMaxSize() : msg.finality_size());
	for(int32_t i = 0; i < (int32_t)finality.GetSize(); ++i) {
		const ::proto_ff::activitygvgRewardfinalityDesc & temp_finality = msg.finality(i);
		finality[i].read_from_pbmsg(temp_finality);
	}
	reward_id.SetSize(msg.reward_id_size() > reward_id.GetMaxSize() ? reward_id.GetMaxSize() : msg.reward_id_size());
	for(int32_t i = 0; i < (int32_t)reward_id.GetSize(); ++i) {
		reward_id[i] = msg.reward_id(i);
	}
	finality_id.SetSize(msg.finality_id_size() > finality_id.GetMaxSize() ? finality_id.GetMaxSize() : msg.finality_id_size());
	for(int32_t i = 0; i < (int32_t)finality_id.GetSize(); ++i) {
		finality_id[i] = msg.finality_id(i);
	}
}

Sheet_activitygvgReward_s::Sheet_activitygvgReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activitygvgReward_s::CreateInit() {
	return 0;
}

int Sheet_activitygvgReward_s::ResumeInit() {
	return 0;
}

void Sheet_activitygvgReward_s::write_to_pbmsg(::proto_ff::Sheet_activitygvgReward & msg) const {
	for(int32_t i = 0; i < (int32_t)activitygvgReward_List.GetSize() && i < activitygvgReward_List.GetMaxSize(); ++i) {
		::proto_ff::activitygvgReward* temp_activitygvgreward_list = msg.add_activitygvgreward_list();
		activitygvgReward_List[i].write_to_pbmsg(*temp_activitygvgreward_list);
	}
}

void Sheet_activitygvgReward_s::read_from_pbmsg(const ::proto_ff::Sheet_activitygvgReward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activitygvgReward_s));
	activitygvgReward_List.SetSize(msg.activitygvgreward_list_size() > activitygvgReward_List.GetMaxSize() ? activitygvgReward_List.GetMaxSize() : msg.activitygvgreward_list_size());
	for(int32_t i = 0; i < (int32_t)activitygvgReward_List.GetSize(); ++i) {
		const ::proto_ff::activitygvgReward & temp_activitygvgreward_list = msg.activitygvgreward_list(i);
		activitygvgReward_List[i].read_from_pbmsg(temp_activitygvgreward_list);
	}
}

activityworldTreasureConst_s::activityworldTreasureConst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activityworldTreasureConst_s::CreateInit() {
	id = (int32_t)0;
	constantdata = (int64_t)0;
	return 0;
}

int activityworldTreasureConst_s::ResumeInit() {
	return 0;
}

void activityworldTreasureConst_s::write_to_pbmsg(::proto_ff::activityworldTreasureConst & msg) const {
	msg.set_id((int32_t)id);
	msg.set_constantdata((int64_t)constantdata);
}

void activityworldTreasureConst_s::read_from_pbmsg(const ::proto_ff::activityworldTreasureConst & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activityworldTreasureConst_s));
	id = msg.id();
	constantdata = msg.constantdata();
}

Sheet_activityworldTreasureConst_s::Sheet_activityworldTreasureConst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activityworldTreasureConst_s::CreateInit() {
	return 0;
}

int Sheet_activityworldTreasureConst_s::ResumeInit() {
	return 0;
}

void Sheet_activityworldTreasureConst_s::write_to_pbmsg(::proto_ff::Sheet_activityworldTreasureConst & msg) const {
	for(int32_t i = 0; i < (int32_t)activityworldTreasureConst_List.GetSize() && i < activityworldTreasureConst_List.GetMaxSize(); ++i) {
		::proto_ff::activityworldTreasureConst* temp_activityworldtreasureconst_list = msg.add_activityworldtreasureconst_list();
		activityworldTreasureConst_List[i].write_to_pbmsg(*temp_activityworldtreasureconst_list);
	}
}

void Sheet_activityworldTreasureConst_s::read_from_pbmsg(const ::proto_ff::Sheet_activityworldTreasureConst & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activityworldTreasureConst_s));
	activityworldTreasureConst_List.SetSize(msg.activityworldtreasureconst_list_size() > activityworldTreasureConst_List.GetMaxSize() ? activityworldTreasureConst_List.GetMaxSize() : msg.activityworldtreasureconst_list_size());
	for(int32_t i = 0; i < (int32_t)activityworldTreasureConst_List.GetSize(); ++i) {
		const ::proto_ff::activityworldTreasureConst & temp_activityworldtreasureconst_list = msg.activityworldtreasureconst_list(i);
		activityworldTreasureConst_List[i].read_from_pbmsg(temp_activityworldtreasureconst_list);
	}
}

activityworldTreasureMap_s::activityworldTreasureMap_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activityworldTreasureMap_s::CreateInit() {
	mapID = (int64_t)0;
	return 0;
}

int activityworldTreasureMap_s::ResumeInit() {
	return 0;
}

void activityworldTreasureMap_s::write_to_pbmsg(::proto_ff::activityworldTreasureMap & msg) const {
	msg.set_mapid((int64_t)mapID);
	msg.set_pathid((const char*)pathID.Get());
}

void activityworldTreasureMap_s::read_from_pbmsg(const ::proto_ff::activityworldTreasureMap & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activityworldTreasureMap_s));
	mapID = msg.mapid();
	pathID.Copy(msg.pathid());
}

Sheet_activityworldTreasureMap_s::Sheet_activityworldTreasureMap_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activityworldTreasureMap_s::CreateInit() {
	return 0;
}

int Sheet_activityworldTreasureMap_s::ResumeInit() {
	return 0;
}

void Sheet_activityworldTreasureMap_s::write_to_pbmsg(::proto_ff::Sheet_activityworldTreasureMap & msg) const {
	for(int32_t i = 0; i < (int32_t)activityworldTreasureMap_List.GetSize() && i < activityworldTreasureMap_List.GetMaxSize(); ++i) {
		::proto_ff::activityworldTreasureMap* temp_activityworldtreasuremap_list = msg.add_activityworldtreasuremap_list();
		activityworldTreasureMap_List[i].write_to_pbmsg(*temp_activityworldtreasuremap_list);
	}
}

void Sheet_activityworldTreasureMap_s::read_from_pbmsg(const ::proto_ff::Sheet_activityworldTreasureMap & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activityworldTreasureMap_s));
	activityworldTreasureMap_List.SetSize(msg.activityworldtreasuremap_list_size() > activityworldTreasureMap_List.GetMaxSize() ? activityworldTreasureMap_List.GetMaxSize() : msg.activityworldtreasuremap_list_size());
	for(int32_t i = 0; i < (int32_t)activityworldTreasureMap_List.GetSize(); ++i) {
		const ::proto_ff::activityworldTreasureMap & temp_activityworldtreasuremap_list = msg.activityworldtreasuremap_list(i);
		activityworldTreasureMap_List[i].read_from_pbmsg(temp_activityworldtreasuremap_list);
	}
}

activityworldTreasureMonster_s::activityworldTreasureMonster_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activityworldTreasureMonster_s::CreateInit() {
	ID = (int32_t)0;
	monsterID = (int64_t)0;
	appearWeight = (int32_t)0;
	skillId = (int64_t)0;
	return 0;
}

int activityworldTreasureMonster_s::ResumeInit() {
	return 0;
}

void activityworldTreasureMonster_s::write_to_pbmsg(::proto_ff::activityworldTreasureMonster & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_monsterid((int64_t)monsterID);
	msg.set_appearweight((int32_t)appearWeight);
	msg.set_skillid((int64_t)skillId);
}

void activityworldTreasureMonster_s::read_from_pbmsg(const ::proto_ff::activityworldTreasureMonster & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activityworldTreasureMonster_s));
	ID = msg.id();
	monsterID = msg.monsterid();
	appearWeight = msg.appearweight();
	skillId = msg.skillid();
}

Sheet_activityworldTreasureMonster_s::Sheet_activityworldTreasureMonster_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activityworldTreasureMonster_s::CreateInit() {
	return 0;
}

int Sheet_activityworldTreasureMonster_s::ResumeInit() {
	return 0;
}

void Sheet_activityworldTreasureMonster_s::write_to_pbmsg(::proto_ff::Sheet_activityworldTreasureMonster & msg) const {
	for(int32_t i = 0; i < (int32_t)activityworldTreasureMonster_List.GetSize() && i < activityworldTreasureMonster_List.GetMaxSize(); ++i) {
		::proto_ff::activityworldTreasureMonster* temp_activityworldtreasuremonster_list = msg.add_activityworldtreasuremonster_list();
		activityworldTreasureMonster_List[i].write_to_pbmsg(*temp_activityworldtreasuremonster_list);
	}
}

void Sheet_activityworldTreasureMonster_s::read_from_pbmsg(const ::proto_ff::Sheet_activityworldTreasureMonster & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activityworldTreasureMonster_s));
	activityworldTreasureMonster_List.SetSize(msg.activityworldtreasuremonster_list_size() > activityworldTreasureMonster_List.GetMaxSize() ? activityworldTreasureMonster_List.GetMaxSize() : msg.activityworldtreasuremonster_list_size());
	for(int32_t i = 0; i < (int32_t)activityworldTreasureMonster_List.GetSize(); ++i) {
		const ::proto_ff::activityworldTreasureMonster & temp_activityworldtreasuremonster_list = msg.activityworldtreasuremonster_list(i);
		activityworldTreasureMonster_List[i].read_from_pbmsg(temp_activityworldtreasuremonster_list);
	}
}

activitylosttempleConstant_s::activitylosttempleConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int activitylosttempleConstant_s::CreateInit() {
	id = (int32_t)0;
	constantdata = (int64_t)0;
	return 0;
}

int activitylosttempleConstant_s::ResumeInit() {
	return 0;
}

void activitylosttempleConstant_s::write_to_pbmsg(::proto_ff::activitylosttempleConstant & msg) const {
	msg.set_id((int32_t)id);
	msg.set_constantdata((int64_t)constantdata);
	msg.set_stringdata((const char*)stringdata.Get());
}

void activitylosttempleConstant_s::read_from_pbmsg(const ::proto_ff::activitylosttempleConstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct activitylosttempleConstant_s));
	id = msg.id();
	constantdata = msg.constantdata();
	stringdata.Copy(msg.stringdata());
}

Sheet_activitylosttempleConstant_s::Sheet_activitylosttempleConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_activitylosttempleConstant_s::CreateInit() {
	return 0;
}

int Sheet_activitylosttempleConstant_s::ResumeInit() {
	return 0;
}

void Sheet_activitylosttempleConstant_s::write_to_pbmsg(::proto_ff::Sheet_activitylosttempleConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)activitylosttempleConstant_List.GetSize() && i < activitylosttempleConstant_List.GetMaxSize(); ++i) {
		::proto_ff::activitylosttempleConstant* temp_activitylosttempleconstant_list = msg.add_activitylosttempleconstant_list();
		activitylosttempleConstant_List[i].write_to_pbmsg(*temp_activitylosttempleconstant_list);
	}
}

void Sheet_activitylosttempleConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_activitylosttempleConstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_activitylosttempleConstant_s));
	activitylosttempleConstant_List.SetSize(msg.activitylosttempleconstant_list_size() > activitylosttempleConstant_List.GetMaxSize() ? activitylosttempleConstant_List.GetMaxSize() : msg.activitylosttempleconstant_list_size());
	for(int32_t i = 0; i < (int32_t)activitylosttempleConstant_List.GetSize(); ++i) {
		const ::proto_ff::activitylosttempleConstant & temp_activitylosttempleconstant_list = msg.activitylosttempleconstant_list(i);
		activitylosttempleConstant_List[i].read_from_pbmsg(temp_activitylosttempleconstant_list);
	}
}

}