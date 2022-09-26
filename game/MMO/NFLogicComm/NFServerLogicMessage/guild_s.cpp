#include "guild_s.h"

namespace proto_ff_s {

guildconstant_s::guildconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int guildconstant_s::CreateInit() {
	constantid = (int64_t)0;
	setDiamond = (int32_t)0;
	offlineTime = (int32_t)0;
	EditRequireLV = (int32_t)0;
	leaveCoolingtime = (int32_t)0;
	houseLimit = (int32_t)0;
	expID = (int64_t)0;
	houseScore = (int32_t)0;
	giftCD = (int32_t)0;
	autoCleanCellNum = (int32_t)0;
	dismiss = (int32_t)0;
	transferGuild = (int32_t)0;
	return 0;
}

int guildconstant_s::ResumeInit() {
	return 0;
}

void guildconstant_s::write_to_pbmsg(::proto_ff::guildconstant & msg) const {
	msg.set_constantid((int64_t)constantid);
	msg.set_setdiamond((int32_t)setDiamond);
	msg.set_offlinetime((int32_t)offlineTime);
	msg.set_editrequirelv((int32_t)EditRequireLV);
	msg.set_leavecoolingtime((int32_t)leaveCoolingtime);
	msg.set_houselimit((int32_t)houseLimit);
	msg.set_expid((int64_t)expID);
	msg.set_housescore((int32_t)houseScore);
	msg.set_giftcd((int32_t)giftCD);
	msg.set_autocleancellnum((int32_t)autoCleanCellNum);
	msg.set_dismiss((int32_t)dismiss);
	msg.set_transferguild((int32_t)transferGuild);
	for(int32_t i = 0; i < (int32_t)initialAutoCleanQS.GetSize() && i < initialAutoCleanQS.GetMaxSize(); ++i) {
		msg.add_initialautocleanqs((const char*)initialAutoCleanQS[i].Get());
	}
}

void guildconstant_s::read_from_pbmsg(const ::proto_ff::guildconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct guildconstant_s));
	constantid = msg.constantid();
	setDiamond = msg.setdiamond();
	offlineTime = msg.offlinetime();
	EditRequireLV = msg.editrequirelv();
	leaveCoolingtime = msg.leavecoolingtime();
	houseLimit = msg.houselimit();
	expID = msg.expid();
	houseScore = msg.housescore();
	giftCD = msg.giftcd();
	autoCleanCellNum = msg.autocleancellnum();
	dismiss = msg.dismiss();
	transferGuild = msg.transferguild();
	initialAutoCleanQS.SetSize(msg.initialautocleanqs_size() > initialAutoCleanQS.GetMaxSize() ? initialAutoCleanQS.GetMaxSize() : msg.initialautocleanqs_size());
	for(int32_t i = 0; i < (int32_t)initialAutoCleanQS.GetSize(); ++i) {
		initialAutoCleanQS[i].Copy(msg.initialautocleanqs(i));
	}
}

Sheet_guildconstant_s::Sheet_guildconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_guildconstant_s::CreateInit() {
	return 0;
}

int Sheet_guildconstant_s::ResumeInit() {
	return 0;
}

void Sheet_guildconstant_s::write_to_pbmsg(::proto_ff::Sheet_guildconstant & msg) const {
	for(int32_t i = 0; i < (int32_t)guildconstant_List.GetSize() && i < guildconstant_List.GetMaxSize(); ++i) {
		::proto_ff::guildconstant* temp_guildconstant_list = msg.add_guildconstant_list();
		guildconstant_List[i].write_to_pbmsg(*temp_guildconstant_list);
	}
}

void Sheet_guildconstant_s::read_from_pbmsg(const ::proto_ff::Sheet_guildconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_guildconstant_s));
	guildconstant_List.SetSize(msg.guildconstant_list_size() > guildconstant_List.GetMaxSize() ? guildconstant_List.GetMaxSize() : msg.guildconstant_list_size());
	for(int32_t i = 0; i < (int32_t)guildconstant_List.GetSize(); ++i) {
		const ::proto_ff::guildconstant & temp_guildconstant_list = msg.guildconstant_list(i);
		guildconstant_List[i].read_from_pbmsg(temp_guildconstant_list);
	}
}

guildlevel_s::guildlevel_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int guildlevel_s::CreateInit() {
	guildLevel = (int32_t)0;
	guildLevel_EXP = (int32_t)0;
	guildLevel_member = (int32_t)0;
	guildLevel_VP = (int32_t)0;
	guildLevel_NP = (int32_t)0;
	return 0;
}

int guildlevel_s::ResumeInit() {
	return 0;
}

void guildlevel_s::write_to_pbmsg(::proto_ff::guildlevel & msg) const {
	msg.set_guildlevel((int32_t)guildLevel);
	msg.set_guildlevel_exp((int32_t)guildLevel_EXP);
	msg.set_guildlevel_member((int32_t)guildLevel_member);
	msg.set_guildlevel_vp((int32_t)guildLevel_VP);
	msg.set_guildlevel_np((int32_t)guildLevel_NP);
}

void guildlevel_s::read_from_pbmsg(const ::proto_ff::guildlevel & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct guildlevel_s));
	guildLevel = msg.guildlevel();
	guildLevel_EXP = msg.guildlevel_exp();
	guildLevel_member = msg.guildlevel_member();
	guildLevel_VP = msg.guildlevel_vp();
	guildLevel_NP = msg.guildlevel_np();
}

Sheet_guildlevel_s::Sheet_guildlevel_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_guildlevel_s::CreateInit() {
	return 0;
}

int Sheet_guildlevel_s::ResumeInit() {
	return 0;
}

void Sheet_guildlevel_s::write_to_pbmsg(::proto_ff::Sheet_guildlevel & msg) const {
	for(int32_t i = 0; i < (int32_t)guildlevel_List.GetSize() && i < guildlevel_List.GetMaxSize(); ++i) {
		::proto_ff::guildlevel* temp_guildlevel_list = msg.add_guildlevel_list();
		guildlevel_List[i].write_to_pbmsg(*temp_guildlevel_list);
	}
}

void Sheet_guildlevel_s::read_from_pbmsg(const ::proto_ff::Sheet_guildlevel & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_guildlevel_s));
	guildlevel_List.SetSize(msg.guildlevel_list_size() > guildlevel_List.GetMaxSize() ? guildlevel_List.GetMaxSize() : msg.guildlevel_list_size());
	for(int32_t i = 0; i < (int32_t)guildlevel_List.GetSize(); ++i) {
		const ::proto_ff::guildlevel & temp_guildlevel_list = msg.guildlevel_list(i);
		guildlevel_List[i].read_from_pbmsg(temp_guildlevel_list);
	}
}

guildcollege_s::guildcollege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int guildcollege_s::CreateInit() {
	practiceId = (int64_t)0;
	practiceType = (int32_t)0;
	learningNeed = (int32_t)0;
	practiceLevel = (int32_t)0;
	playerLevelLimit = (int32_t)0;
	attributeId = (int32_t)0;
	attributeGain = (int32_t)0;
	CostContribute = (int32_t)0;
	return 0;
}

int guildcollege_s::ResumeInit() {
	return 0;
}

void guildcollege_s::write_to_pbmsg(::proto_ff::guildcollege & msg) const {
	msg.set_practiceid((int64_t)practiceId);
	msg.set_practicetype((int32_t)practiceType);
	msg.set_learningneed((int32_t)learningNeed);
	msg.set_practicelevel((int32_t)practiceLevel);
	msg.set_playerlevellimit((int32_t)playerLevelLimit);
	msg.set_attributeid((int32_t)attributeId);
	msg.set_attributegain((int32_t)attributeGain);
	msg.set_costcontribute((int32_t)CostContribute);
}

void guildcollege_s::read_from_pbmsg(const ::proto_ff::guildcollege & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct guildcollege_s));
	practiceId = msg.practiceid();
	practiceType = msg.practicetype();
	learningNeed = msg.learningneed();
	practiceLevel = msg.practicelevel();
	playerLevelLimit = msg.playerlevellimit();
	attributeId = msg.attributeid();
	attributeGain = msg.attributegain();
	CostContribute = msg.costcontribute();
}

Sheet_guildcollege_s::Sheet_guildcollege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_guildcollege_s::CreateInit() {
	return 0;
}

int Sheet_guildcollege_s::ResumeInit() {
	return 0;
}

void Sheet_guildcollege_s::write_to_pbmsg(::proto_ff::Sheet_guildcollege & msg) const {
	for(int32_t i = 0; i < (int32_t)guildcollege_List.GetSize() && i < guildcollege_List.GetMaxSize(); ++i) {
		::proto_ff::guildcollege* temp_guildcollege_list = msg.add_guildcollege_list();
		guildcollege_List[i].write_to_pbmsg(*temp_guildcollege_list);
	}
}

void Sheet_guildcollege_s::read_from_pbmsg(const ::proto_ff::Sheet_guildcollege & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_guildcollege_s));
	guildcollege_List.SetSize(msg.guildcollege_list_size() > guildcollege_List.GetMaxSize() ? guildcollege_List.GetMaxSize() : msg.guildcollege_list_size());
	for(int32_t i = 0; i < (int32_t)guildcollege_List.GetSize(); ++i) {
		const ::proto_ff::guildcollege & temp_guildcollege_list = msg.guildcollege_list(i);
		guildcollege_List[i].read_from_pbmsg(temp_guildcollege_list);
	}
}

guildposition_s::guildposition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int guildposition_s::CreateInit() {
	positionId = (int64_t)0;
	positionType = (int32_t)0;
	allotMaterials = (int32_t)0;
	admitNewcomer = (int32_t)0;
	appointAndRemoveVP = (int32_t)0;
	appointAndRemoveElder = (int32_t)0;
	expelVP = (int32_t)0;
	expelElder = (int32_t)0;
	expelMass = (int32_t)0;
	announcementEditing = (int32_t)0;
	joinCondition = (int32_t)0;
	guildActivity = (int32_t)0;
	dissolveAssignGuild = (int32_t)0;
	clear = (int32_t)0;
	changeName = (int32_t)0;
	automaticCleanDisplay = (int32_t)0;
	return 0;
}

int guildposition_s::ResumeInit() {
	return 0;
}

void guildposition_s::write_to_pbmsg(::proto_ff::guildposition & msg) const {
	msg.set_positionid((int64_t)positionId);
	msg.set_positiontype((int32_t)positionType);
	msg.set_allotmaterials((int32_t)allotMaterials);
	msg.set_admitnewcomer((int32_t)admitNewcomer);
	msg.set_appointandremovevp((int32_t)appointAndRemoveVP);
	msg.set_appointandremoveelder((int32_t)appointAndRemoveElder);
	msg.set_expelvp((int32_t)expelVP);
	msg.set_expelelder((int32_t)expelElder);
	msg.set_expelmass((int32_t)expelMass);
	msg.set_announcementediting((int32_t)announcementEditing);
	msg.set_joincondition((int32_t)joinCondition);
	msg.set_guildactivity((int32_t)guildActivity);
	msg.set_dissolveassignguild((int32_t)dissolveAssignGuild);
	msg.set_clear((int32_t)clear);
	msg.set_changename((int32_t)changeName);
	msg.set_automaticcleandisplay((int32_t)automaticCleanDisplay);
}

void guildposition_s::read_from_pbmsg(const ::proto_ff::guildposition & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct guildposition_s));
	positionId = msg.positionid();
	positionType = msg.positiontype();
	allotMaterials = msg.allotmaterials();
	admitNewcomer = msg.admitnewcomer();
	appointAndRemoveVP = msg.appointandremovevp();
	appointAndRemoveElder = msg.appointandremoveelder();
	expelVP = msg.expelvp();
	expelElder = msg.expelelder();
	expelMass = msg.expelmass();
	announcementEditing = msg.announcementediting();
	joinCondition = msg.joincondition();
	guildActivity = msg.guildactivity();
	dissolveAssignGuild = msg.dissolveassignguild();
	clear = msg.clear();
	changeName = msg.changename();
	automaticCleanDisplay = msg.automaticcleandisplay();
}

Sheet_guildposition_s::Sheet_guildposition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_guildposition_s::CreateInit() {
	return 0;
}

int Sheet_guildposition_s::ResumeInit() {
	return 0;
}

void Sheet_guildposition_s::write_to_pbmsg(::proto_ff::Sheet_guildposition & msg) const {
	for(int32_t i = 0; i < (int32_t)guildposition_List.GetSize() && i < guildposition_List.GetMaxSize(); ++i) {
		::proto_ff::guildposition* temp_guildposition_list = msg.add_guildposition_list();
		guildposition_List[i].write_to_pbmsg(*temp_guildposition_list);
	}
}

void Sheet_guildposition_s::read_from_pbmsg(const ::proto_ff::Sheet_guildposition & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_guildposition_s));
	guildposition_List.SetSize(msg.guildposition_list_size() > guildposition_List.GetMaxSize() ? guildposition_List.GetMaxSize() : msg.guildposition_list_size());
	for(int32_t i = 0; i < (int32_t)guildposition_List.GetSize(); ++i) {
		const ::proto_ff::guildposition & temp_guildposition_list = msg.guildposition_list(i);
		guildposition_List[i].read_from_pbmsg(temp_guildposition_list);
	}
}

guildhouse_s::guildhouse_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int guildhouse_s::CreateInit() {
	ID = (int64_t)0;
	wearQuality = (int32_t)0;
	quality = (int32_t)0;
	houseScore = (int32_t)0;
	return 0;
}

int guildhouse_s::ResumeInit() {
	return 0;
}

void guildhouse_s::write_to_pbmsg(::proto_ff::guildhouse & msg) const {
	msg.set_id((int64_t)ID);
	msg.set_wearquality((int32_t)wearQuality);
	msg.set_quality((int32_t)quality);
	msg.set_housescore((int32_t)houseScore);
}

void guildhouse_s::read_from_pbmsg(const ::proto_ff::guildhouse & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct guildhouse_s));
	ID = msg.id();
	wearQuality = msg.wearquality();
	quality = msg.quality();
	houseScore = msg.housescore();
}

Sheet_guildhouse_s::Sheet_guildhouse_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_guildhouse_s::CreateInit() {
	return 0;
}

int Sheet_guildhouse_s::ResumeInit() {
	return 0;
}

void Sheet_guildhouse_s::write_to_pbmsg(::proto_ff::Sheet_guildhouse & msg) const {
	for(int32_t i = 0; i < (int32_t)guildhouse_List.GetSize() && i < guildhouse_List.GetMaxSize(); ++i) {
		::proto_ff::guildhouse* temp_guildhouse_list = msg.add_guildhouse_list();
		guildhouse_List[i].write_to_pbmsg(*temp_guildhouse_list);
	}
}

void Sheet_guildhouse_s::read_from_pbmsg(const ::proto_ff::Sheet_guildhouse & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_guildhouse_s));
	guildhouse_List.SetSize(msg.guildhouse_list_size() > guildhouse_List.GetMaxSize() ? guildhouse_List.GetMaxSize() : msg.guildhouse_list_size());
	for(int32_t i = 0; i < (int32_t)guildhouse_List.GetSize(); ++i) {
		const ::proto_ff::guildhouse & temp_guildhouse_list = msg.guildhouse_list(i);
		guildhouse_List[i].read_from_pbmsg(temp_guildhouse_list);
	}
}

guildgift_s::guildgift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int guildgift_s::CreateInit() {
	ID = (int64_t)0;
	type = (int32_t)0;
	money = (int32_t)0;
	num = (int32_t)0;
	return 0;
}

int guildgift_s::ResumeInit() {
	return 0;
}

void guildgift_s::write_to_pbmsg(::proto_ff::guildgift & msg) const {
	msg.set_id((int64_t)ID);
	msg.set_type((int32_t)type);
	msg.set_money((int32_t)money);
	msg.set_num((int32_t)num);
}

void guildgift_s::read_from_pbmsg(const ::proto_ff::guildgift & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct guildgift_s));
	ID = msg.id();
	type = msg.type();
	money = msg.money();
	num = msg.num();
}

Sheet_guildgift_s::Sheet_guildgift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_guildgift_s::CreateInit() {
	return 0;
}

int Sheet_guildgift_s::ResumeInit() {
	return 0;
}

void Sheet_guildgift_s::write_to_pbmsg(::proto_ff::Sheet_guildgift & msg) const {
	for(int32_t i = 0; i < (int32_t)guildgift_List.GetSize() && i < guildgift_List.GetMaxSize(); ++i) {
		::proto_ff::guildgift* temp_guildgift_list = msg.add_guildgift_list();
		guildgift_List[i].write_to_pbmsg(*temp_guildgift_list);
	}
}

void Sheet_guildgift_s::read_from_pbmsg(const ::proto_ff::Sheet_guildgift & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_guildgift_s));
	guildgift_List.SetSize(msg.guildgift_list_size() > guildgift_List.GetMaxSize() ? guildgift_List.GetMaxSize() : msg.guildgift_list_size());
	for(int32_t i = 0; i < (int32_t)guildgift_List.GetSize(); ++i) {
		const ::proto_ff::guildgift & temp_guildgift_list = msg.guildgift_list(i);
		guildgift_List[i].read_from_pbmsg(temp_guildgift_list);
	}
}

guildguildance_s::guildguildance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int guildguildance_s::CreateInit() {
	guidanceId = (int32_t)0;
	guidanceType = (int32_t)0;
	levelLimit = (int32_t)0;
	triggerTpye = (int32_t)0;
	cognateNpcId = (int32_t)0;
	cognateUI = (int32_t)0;
	cognateActiveId = (int32_t)0;
	return 0;
}

int guildguildance_s::ResumeInit() {
	return 0;
}

void guildguildance_s::write_to_pbmsg(::proto_ff::guildguildance & msg) const {
	msg.set_guidanceid((int32_t)guidanceId);
	msg.set_guidancetype((int32_t)guidanceType);
	msg.set_levellimit((int32_t)levelLimit);
	msg.set_triggertpye((int32_t)triggerTpye);
	msg.set_cognatenpcid((int32_t)cognateNpcId);
	msg.set_cognateui((int32_t)cognateUI);
	msg.set_cognateactiveid((int32_t)cognateActiveId);
}

void guildguildance_s::read_from_pbmsg(const ::proto_ff::guildguildance & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct guildguildance_s));
	guidanceId = msg.guidanceid();
	guidanceType = msg.guidancetype();
	levelLimit = msg.levellimit();
	triggerTpye = msg.triggertpye();
	cognateNpcId = msg.cognatenpcid();
	cognateUI = msg.cognateui();
	cognateActiveId = msg.cognateactiveid();
}

Sheet_guildguildance_s::Sheet_guildguildance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_guildguildance_s::CreateInit() {
	return 0;
}

int Sheet_guildguildance_s::ResumeInit() {
	return 0;
}

void Sheet_guildguildance_s::write_to_pbmsg(::proto_ff::Sheet_guildguildance & msg) const {
	for(int32_t i = 0; i < (int32_t)guildguildance_List.GetSize() && i < guildguildance_List.GetMaxSize(); ++i) {
		::proto_ff::guildguildance* temp_guildguildance_list = msg.add_guildguildance_list();
		guildguildance_List[i].write_to_pbmsg(*temp_guildguildance_list);
	}
}

void Sheet_guildguildance_s::read_from_pbmsg(const ::proto_ff::Sheet_guildguildance & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_guildguildance_s));
	guildguildance_List.SetSize(msg.guildguildance_list_size() > guildguildance_List.GetMaxSize() ? guildguildance_List.GetMaxSize() : msg.guildguildance_list_size());
	for(int32_t i = 0; i < (int32_t)guildguildance_List.GetSize(); ++i) {
		const ::proto_ff::guildguildance & temp_guildguildance_list = msg.guildguildance_list(i);
		guildguildance_List[i].read_from_pbmsg(temp_guildguildance_list);
	}
}

guildwarconstant_s::guildwarconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int guildwarconstant_s::CreateInit() {
	warid = (int64_t)0;
	signopenCycle = (int32_t)0;
	signclosedCycle = (int32_t)0;
	guildPosition = (int32_t)0;
	guildNum = (int32_t)0;
	guildLevel = (int32_t)0;
	enteropenCycle = (int32_t)0;
	enterclosedCycle = (int32_t)0;
	guildwarBaseScore = (int32_t)0;
	guildwarWinScore = (int32_t)0;
	guildwarLoseScore = (int32_t)0;
	guildwarDrawScore = (int32_t)0;
	maxMaterial = (int32_t)0;
	soldierCostMaterial = (int32_t)0;
	soldierNum = (int32_t)0;
	soldierCD = (int32_t)0;
	renewBaseCost = (int32_t)0;
	renewBaseHP = (int32_t)0;
	renewBaseCD = (int32_t)0;
	reviveCD = (int32_t)0;
	guildwarWinItem = (int64_t)0;
	guildwarWinNum = (int32_t)0;
	guildwarLoseItem = (int64_t)0;
	guildwarLoseNum = (int32_t)0;
	guildwarDrawItem = (int64_t)0;
	guildwarDrawNum = (int32_t)0;
	MaterialId = (int64_t)0;
	MaterialConversion = (int32_t)0;
	GuildWarExp = (int32_t)0;
	return 0;
}

int guildwarconstant_s::ResumeInit() {
	return 0;
}

void guildwarconstant_s::write_to_pbmsg(::proto_ff::guildwarconstant & msg) const {
	msg.set_warid((int64_t)warid);
	msg.set_signopencycle((int32_t)signopenCycle);
	msg.set_signopentime((const char*)signopenTime.Get());
	msg.set_signclosedcycle((int32_t)signclosedCycle);
	msg.set_signclosedtime((const char*)signclosedTime.Get());
	msg.set_guildposition((int32_t)guildPosition);
	msg.set_guildnum((int32_t)guildNum);
	msg.set_guildlevel((int32_t)guildLevel);
	msg.set_enteropencycle((int32_t)enteropenCycle);
	msg.set_enteropentime((const char*)enteropenTime.Get());
	msg.set_enterclosedcycle((int32_t)enterclosedCycle);
	msg.set_enterclosedtime((const char*)enterclosedTime.Get());
	msg.set_guildwarbasescore((int32_t)guildwarBaseScore);
	msg.set_guildwarwinscore((int32_t)guildwarWinScore);
	msg.set_guildwarlosescore((int32_t)guildwarLoseScore);
	msg.set_guildwardrawscore((int32_t)guildwarDrawScore);
	msg.set_maxmaterial((int32_t)maxMaterial);
	msg.set_soldiercostmaterial((int32_t)soldierCostMaterial);
	msg.set_soldiernum((int32_t)soldierNum);
	msg.set_soldiercd((int32_t)soldierCD);
	msg.set_renewbasecost((int32_t)renewBaseCost);
	msg.set_renewbasehp((int32_t)renewBaseHP);
	msg.set_renewbasecd((int32_t)renewBaseCD);
	msg.set_revivecd((int32_t)reviveCD);
	msg.set_guildwarwinitem((int64_t)guildwarWinItem);
	msg.set_guildwarwinnum((int32_t)guildwarWinNum);
	msg.set_guildwarloseitem((int64_t)guildwarLoseItem);
	msg.set_guildwarlosenum((int32_t)guildwarLoseNum);
	msg.set_guildwardrawitem((int64_t)guildwarDrawItem);
	msg.set_guildwardrawnum((int32_t)guildwarDrawNum);
	msg.set_materialid((int64_t)MaterialId);
	msg.set_materialconversion((int32_t)MaterialConversion);
	msg.set_guildwarexp((int32_t)GuildWarExp);
}

void guildwarconstant_s::read_from_pbmsg(const ::proto_ff::guildwarconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct guildwarconstant_s));
	warid = msg.warid();
	signopenCycle = msg.signopencycle();
	signopenTime.Copy(msg.signopentime());
	signclosedCycle = msg.signclosedcycle();
	signclosedTime.Copy(msg.signclosedtime());
	guildPosition = msg.guildposition();
	guildNum = msg.guildnum();
	guildLevel = msg.guildlevel();
	enteropenCycle = msg.enteropencycle();
	enteropenTime.Copy(msg.enteropentime());
	enterclosedCycle = msg.enterclosedcycle();
	enterclosedTime.Copy(msg.enterclosedtime());
	guildwarBaseScore = msg.guildwarbasescore();
	guildwarWinScore = msg.guildwarwinscore();
	guildwarLoseScore = msg.guildwarlosescore();
	guildwarDrawScore = msg.guildwardrawscore();
	maxMaterial = msg.maxmaterial();
	soldierCostMaterial = msg.soldiercostmaterial();
	soldierNum = msg.soldiernum();
	soldierCD = msg.soldiercd();
	renewBaseCost = msg.renewbasecost();
	renewBaseHP = msg.renewbasehp();
	renewBaseCD = msg.renewbasecd();
	reviveCD = msg.revivecd();
	guildwarWinItem = msg.guildwarwinitem();
	guildwarWinNum = msg.guildwarwinnum();
	guildwarLoseItem = msg.guildwarloseitem();
	guildwarLoseNum = msg.guildwarlosenum();
	guildwarDrawItem = msg.guildwardrawitem();
	guildwarDrawNum = msg.guildwardrawnum();
	MaterialId = msg.materialid();
	MaterialConversion = msg.materialconversion();
	GuildWarExp = msg.guildwarexp();
}

Sheet_guildwarconstant_s::Sheet_guildwarconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_guildwarconstant_s::CreateInit() {
	return 0;
}

int Sheet_guildwarconstant_s::ResumeInit() {
	return 0;
}

void Sheet_guildwarconstant_s::write_to_pbmsg(::proto_ff::Sheet_guildwarconstant & msg) const {
	for(int32_t i = 0; i < (int32_t)guildwarconstant_List.GetSize() && i < guildwarconstant_List.GetMaxSize(); ++i) {
		::proto_ff::guildwarconstant* temp_guildwarconstant_list = msg.add_guildwarconstant_list();
		guildwarconstant_List[i].write_to_pbmsg(*temp_guildwarconstant_list);
	}
}

void Sheet_guildwarconstant_s::read_from_pbmsg(const ::proto_ff::Sheet_guildwarconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_guildwarconstant_s));
	guildwarconstant_List.SetSize(msg.guildwarconstant_list_size() > guildwarconstant_List.GetMaxSize() ? guildwarconstant_List.GetMaxSize() : msg.guildwarconstant_list_size());
	for(int32_t i = 0; i < (int32_t)guildwarconstant_List.GetSize(); ++i) {
		const ::proto_ff::guildwarconstant & temp_guildwarconstant_list = msg.guildwarconstant_list(i);
		guildwarconstant_List[i].read_from_pbmsg(temp_guildwarconstant_list);
	}
}

guildwarmorale_s::guildwarmorale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int guildwarmorale_s::CreateInit() {
	moraleLevel = (int64_t)0;
	costMaterial = (int32_t)0;
	skillId = (int64_t)0;
	skillLevel = (int32_t)0;
	return 0;
}

int guildwarmorale_s::ResumeInit() {
	return 0;
}

void guildwarmorale_s::write_to_pbmsg(::proto_ff::guildwarmorale & msg) const {
	msg.set_moralelevel((int64_t)moraleLevel);
	msg.set_costmaterial((int32_t)costMaterial);
	msg.set_skillid((int64_t)skillId);
	msg.set_skilllevel((int32_t)skillLevel);
}

void guildwarmorale_s::read_from_pbmsg(const ::proto_ff::guildwarmorale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct guildwarmorale_s));
	moraleLevel = msg.moralelevel();
	costMaterial = msg.costmaterial();
	skillId = msg.skillid();
	skillLevel = msg.skilllevel();
}

Sheet_guildwarmorale_s::Sheet_guildwarmorale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_guildwarmorale_s::CreateInit() {
	return 0;
}

int Sheet_guildwarmorale_s::ResumeInit() {
	return 0;
}

void Sheet_guildwarmorale_s::write_to_pbmsg(::proto_ff::Sheet_guildwarmorale & msg) const {
	for(int32_t i = 0; i < (int32_t)guildwarmorale_List.GetSize() && i < guildwarmorale_List.GetMaxSize(); ++i) {
		::proto_ff::guildwarmorale* temp_guildwarmorale_list = msg.add_guildwarmorale_list();
		guildwarmorale_List[i].write_to_pbmsg(*temp_guildwarmorale_list);
	}
}

void Sheet_guildwarmorale_s::read_from_pbmsg(const ::proto_ff::Sheet_guildwarmorale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_guildwarmorale_s));
	guildwarmorale_List.SetSize(msg.guildwarmorale_list_size() > guildwarmorale_List.GetMaxSize() ? guildwarmorale_List.GetMaxSize() : msg.guildwarmorale_list_size());
	for(int32_t i = 0; i < (int32_t)guildwarmorale_List.GetSize(); ++i) {
		const ::proto_ff::guildwarmorale & temp_guildwarmorale_list = msg.guildwarmorale_list(i);
		guildwarmorale_List[i].read_from_pbmsg(temp_guildwarmorale_list);
	}
}

guildwarrevive_s::guildwarrevive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int guildwarrevive_s::CreateInit() {
	reviveNum = (int32_t)0;
	reviveCost = (int32_t)0;
	return 0;
}

int guildwarrevive_s::ResumeInit() {
	return 0;
}

void guildwarrevive_s::write_to_pbmsg(::proto_ff::guildwarrevive & msg) const {
	msg.set_revivenum((int32_t)reviveNum);
	msg.set_revivecost((int32_t)reviveCost);
}

void guildwarrevive_s::read_from_pbmsg(const ::proto_ff::guildwarrevive & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct guildwarrevive_s));
	reviveNum = msg.revivenum();
	reviveCost = msg.revivecost();
}

Sheet_guildwarrevive_s::Sheet_guildwarrevive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_guildwarrevive_s::CreateInit() {
	return 0;
}

int Sheet_guildwarrevive_s::ResumeInit() {
	return 0;
}

void Sheet_guildwarrevive_s::write_to_pbmsg(::proto_ff::Sheet_guildwarrevive & msg) const {
	for(int32_t i = 0; i < (int32_t)guildwarrevive_List.GetSize() && i < guildwarrevive_List.GetMaxSize(); ++i) {
		::proto_ff::guildwarrevive* temp_guildwarrevive_list = msg.add_guildwarrevive_list();
		guildwarrevive_List[i].write_to_pbmsg(*temp_guildwarrevive_list);
	}
}

void Sheet_guildwarrevive_s::read_from_pbmsg(const ::proto_ff::Sheet_guildwarrevive & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_guildwarrevive_s));
	guildwarrevive_List.SetSize(msg.guildwarrevive_list_size() > guildwarrevive_List.GetMaxSize() ? guildwarrevive_List.GetMaxSize() : msg.guildwarrevive_list_size());
	for(int32_t i = 0; i < (int32_t)guildwarrevive_List.GetSize(); ++i) {
		const ::proto_ff::guildwarrevive & temp_guildwarrevive_list = msg.guildwarrevive_list(i);
		guildwarrevive_List[i].read_from_pbmsg(temp_guildwarrevive_list);
	}
}

}