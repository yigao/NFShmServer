#include "monster_s.h"

namespace proto_ff_s {

monstermonster_s::monstermonster_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int monstermonster_s::CreateInit() {
	monsterID = (int64_t)0;
	functionType = (int32_t)0;
	functionValue = (int64_t)0;
	profession = (int32_t)0;
	damageAddType = (int32_t)0;
	monsterLV = (int32_t)0;
	droplimit = (int32_t)0;
	displayID = (int64_t)0;
	valuetype = (int64_t)0;
	aiId = (int64_t)0;
	hpSectionNum = (int32_t)0;
	showGuild = (int32_t)0;
	breedProb = (int32_t)0;
	breedMonID = (int64_t)0;
	breedMonLive = (int32_t)0;
	isBornActionOn = (int32_t)0;
	exp = (int64_t)0;
	dropType = (int32_t)0;
	isBelongToPlayer = (int32_t)0;
	dropDefault = (int64_t)0;
	dropBoxID = (int64_t)0;
	ifMultiple = (int32_t)0;
	dropRool = (int64_t)0;
	lastBox = (int64_t)0;
	btnRange = (int32_t)0;
	btnId = (int64_t)0;
	return 0;
}

int monstermonster_s::ResumeInit() {
	return 0;
}

void monstermonster_s::write_to_pbmsg(::proto_ff::monstermonster & msg) const {
	msg.set_monsterid((int64_t)monsterID);
	msg.set_monstername((const char*)monsterName.Get());
	msg.set_functiontype((int32_t)functionType);
	msg.set_functionvalue((int64_t)functionValue);
	msg.set_profession((int32_t)profession);
	msg.set_damageaddtype((int32_t)damageAddType);
	msg.set_monsterlv((int32_t)monsterLV);
	msg.set_droplimit((int32_t)droplimit);
	msg.set_displayid((int64_t)displayID);
	msg.set_valuetype((int64_t)valuetype);
	msg.set_aiid((int64_t)aiId);
	msg.set_hpsectionnum((int32_t)hpSectionNum);
	msg.set_showguild((int32_t)showGuild);
	msg.set_breedprob((int32_t)breedProb);
	msg.set_breedmonid((int64_t)breedMonID);
	msg.set_breedmonlive((int32_t)breedMonLive);
	msg.set_itemcost((const char*)itemCost.Get());
	msg.set_isbornactionon((int32_t)isBornActionOn);
	msg.set_exp((int64_t)exp);
	msg.set_droptype((int32_t)dropType);
	msg.set_isbelongtoplayer((int32_t)isBelongToPlayer);
	msg.set_dropdefault((int64_t)dropDefault);
	msg.set_dropboxid((int64_t)dropBoxID);
	msg.set_ifmultiple((int32_t)ifMultiple);
	msg.set_droprool((int64_t)dropRool);
	msg.set_lastbox((int64_t)lastBox);
	msg.set_btnrange((int32_t)btnRange);
	msg.set_btnid((int64_t)btnId);
}

void monstermonster_s::read_from_pbmsg(const ::proto_ff::monstermonster & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct monstermonster_s));
	monsterID = msg.monsterid();
	monsterName.Copy(msg.monstername());
	functionType = msg.functiontype();
	functionValue = msg.functionvalue();
	profession = msg.profession();
	damageAddType = msg.damageaddtype();
	monsterLV = msg.monsterlv();
	droplimit = msg.droplimit();
	displayID = msg.displayid();
	valuetype = msg.valuetype();
	aiId = msg.aiid();
	hpSectionNum = msg.hpsectionnum();
	showGuild = msg.showguild();
	breedProb = msg.breedprob();
	breedMonID = msg.breedmonid();
	breedMonLive = msg.breedmonlive();
	itemCost.Copy(msg.itemcost());
	isBornActionOn = msg.isbornactionon();
	exp = msg.exp();
	dropType = msg.droptype();
	isBelongToPlayer = msg.isbelongtoplayer();
	dropDefault = msg.dropdefault();
	dropBoxID = msg.dropboxid();
	ifMultiple = msg.ifmultiple();
	dropRool = msg.droprool();
	lastBox = msg.lastbox();
	btnRange = msg.btnrange();
	btnId = msg.btnid();
}

Sheet_monstermonster_s::Sheet_monstermonster_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_monstermonster_s::CreateInit() {
	return 0;
}

int Sheet_monstermonster_s::ResumeInit() {
	return 0;
}

void Sheet_monstermonster_s::write_to_pbmsg(::proto_ff::Sheet_monstermonster & msg) const {
	for(int32_t i = 0; i < (int32_t)monstermonster_List.GetSize() && i < monstermonster_List.GetMaxSize(); ++i) {
		::proto_ff::monstermonster* temp_monstermonster_list = msg.add_monstermonster_list();
		monstermonster_List[i].write_to_pbmsg(*temp_monstermonster_list);
	}
}

void Sheet_monstermonster_s::read_from_pbmsg(const ::proto_ff::Sheet_monstermonster & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_monstermonster_s));
	monstermonster_List.SetSize(msg.monstermonster_list_size() > monstermonster_List.GetMaxSize() ? monstermonster_List.GetMaxSize() : msg.monstermonster_list_size());
	for(int32_t i = 0; i < (int32_t)monstermonster_List.GetSize(); ++i) {
		const ::proto_ff::monstermonster & temp_monstermonster_list = msg.monstermonster_list(i);
		monstermonster_List[i].read_from_pbmsg(temp_monstermonster_list);
	}
}

monsterdisplayskillDesc_s::monsterdisplayskillDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int monsterdisplayskillDesc_s::CreateInit() {
	id = (int64_t)0;
	return 0;
}

int monsterdisplayskillDesc_s::ResumeInit() {
	return 0;
}

void monsterdisplayskillDesc_s::write_to_pbmsg(::proto_ff::monsterdisplayskillDesc & msg) const {
	msg.set_id((int64_t)id);
}

void monsterdisplayskillDesc_s::read_from_pbmsg(const ::proto_ff::monsterdisplayskillDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct monsterdisplayskillDesc_s));
	id = msg.id();
}

monsterdisplay_s::monsterdisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int monsterdisplay_s::CreateInit() {
	displayID = (int64_t)0;
	modelOffsetsX = (int32_t)0;
	modelOffsetsY = (int32_t)0;
	modelScale = (int32_t)0;
	modelRadius = (int32_t)0;
	pathRadius = (int32_t)0;
	collisionRadius = (int32_t)0;
	rSpeed = (int32_t)0;
	return 0;
}

int monsterdisplay_s::ResumeInit() {
	return 0;
}

void monsterdisplay_s::write_to_pbmsg(::proto_ff::monsterdisplay & msg) const {
	msg.set_displayid((int64_t)displayID);
	msg.set_modeloffsetsx((int32_t)modelOffsetsX);
	msg.set_modeloffsetsy((int32_t)modelOffsetsY);
	msg.set_modelscale((int32_t)modelScale);
	msg.set_modelradius((int32_t)modelRadius);
	msg.set_pathradius((int32_t)pathRadius);
	msg.set_collisionradius((int32_t)collisionRadius);
	msg.set_rspeed((int32_t)rSpeed);
	for(int32_t i = 0; i < (int32_t)skill.GetSize() && i < skill.GetMaxSize(); ++i) {
		::proto_ff::monsterdisplayskillDesc* temp_skill = msg.add_skill();
		skill[i].write_to_pbmsg(*temp_skill);
	}
}

void monsterdisplay_s::read_from_pbmsg(const ::proto_ff::monsterdisplay & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct monsterdisplay_s));
	displayID = msg.displayid();
	modelOffsetsX = msg.modeloffsetsx();
	modelOffsetsY = msg.modeloffsetsy();
	modelScale = msg.modelscale();
	modelRadius = msg.modelradius();
	pathRadius = msg.pathradius();
	collisionRadius = msg.collisionradius();
	rSpeed = msg.rspeed();
	skill.SetSize(msg.skill_size() > skill.GetMaxSize() ? skill.GetMaxSize() : msg.skill_size());
	for(int32_t i = 0; i < (int32_t)skill.GetSize(); ++i) {
		const ::proto_ff::monsterdisplayskillDesc & temp_skill = msg.skill(i);
		skill[i].read_from_pbmsg(temp_skill);
	}
}

Sheet_monsterdisplay_s::Sheet_monsterdisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_monsterdisplay_s::CreateInit() {
	return 0;
}

int Sheet_monsterdisplay_s::ResumeInit() {
	return 0;
}

void Sheet_monsterdisplay_s::write_to_pbmsg(::proto_ff::Sheet_monsterdisplay & msg) const {
	for(int32_t i = 0; i < (int32_t)monsterdisplay_List.GetSize() && i < monsterdisplay_List.GetMaxSize(); ++i) {
		::proto_ff::monsterdisplay* temp_monsterdisplay_list = msg.add_monsterdisplay_list();
		monsterdisplay_List[i].write_to_pbmsg(*temp_monsterdisplay_list);
	}
}

void Sheet_monsterdisplay_s::read_from_pbmsg(const ::proto_ff::Sheet_monsterdisplay & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_monsterdisplay_s));
	monsterdisplay_List.SetSize(msg.monsterdisplay_list_size() > monsterdisplay_List.GetMaxSize() ? monsterdisplay_List.GetMaxSize() : msg.monsterdisplay_list_size());
	for(int32_t i = 0; i < (int32_t)monsterdisplay_List.GetSize(); ++i) {
		const ::proto_ff::monsterdisplay & temp_monsterdisplay_list = msg.monsterdisplay_list(i);
		monsterdisplay_List[i].read_from_pbmsg(temp_monsterdisplay_list);
	}
}

monstervalue_s::monstervalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int monstervalue_s::CreateInit() {
	ID = (int64_t)0;
	type = (int32_t)0;
	monsterLV = (int32_t)0;
	maxHp = (int64_t)0;
	attack = (int64_t)0;
	defense = (int64_t)0;
	pierce = (int64_t)0;
	divineAtt = (int64_t)0;
	divineDef = (int64_t)0;
	hitRate = (int64_t)0;
	dodgeRate = (int64_t)0;
	critRate = (int64_t)0;
	toughRate = (int64_t)0;
	killRate = (int64_t)0;
	parryRate = (int64_t)0;
	critDam = (int64_t)0;
	critRedu = (int64_t)0;
	killDam = (int64_t)0;
	killRedu = (int64_t)0;
	attDam = (int64_t)0;
	attRedu = (int64_t)0;
	fightingCapacity = (int64_t)0;
	isFightPress = (int32_t)0;
	exp = (int64_t)0;
	return 0;
}

int monstervalue_s::ResumeInit() {
	return 0;
}

void monstervalue_s::write_to_pbmsg(::proto_ff::monstervalue & msg) const {
	msg.set_id((int64_t)ID);
	msg.set_type((int32_t)type);
	msg.set_monsterlv((int32_t)monsterLV);
	msg.set_maxhp((int64_t)maxHp);
	msg.set_attack((int64_t)attack);
	msg.set_defense((int64_t)defense);
	msg.set_pierce((int64_t)pierce);
	msg.set_divineatt((int64_t)divineAtt);
	msg.set_divinedef((int64_t)divineDef);
	msg.set_hitrate((int64_t)hitRate);
	msg.set_dodgerate((int64_t)dodgeRate);
	msg.set_critrate((int64_t)critRate);
	msg.set_toughrate((int64_t)toughRate);
	msg.set_killrate((int64_t)killRate);
	msg.set_parryrate((int64_t)parryRate);
	msg.set_critdam((int64_t)critDam);
	msg.set_critredu((int64_t)critRedu);
	msg.set_killdam((int64_t)killDam);
	msg.set_killredu((int64_t)killRedu);
	msg.set_attdam((int64_t)attDam);
	msg.set_attredu((int64_t)attRedu);
	msg.set_fightingcapacity((int64_t)fightingCapacity);
	msg.set_isfightpress((int32_t)isFightPress);
	msg.set_exp((int64_t)exp);
}

void monstervalue_s::read_from_pbmsg(const ::proto_ff::monstervalue & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct monstervalue_s));
	ID = msg.id();
	type = msg.type();
	monsterLV = msg.monsterlv();
	maxHp = msg.maxhp();
	attack = msg.attack();
	defense = msg.defense();
	pierce = msg.pierce();
	divineAtt = msg.divineatt();
	divineDef = msg.divinedef();
	hitRate = msg.hitrate();
	dodgeRate = msg.dodgerate();
	critRate = msg.critrate();
	toughRate = msg.toughrate();
	killRate = msg.killrate();
	parryRate = msg.parryrate();
	critDam = msg.critdam();
	critRedu = msg.critredu();
	killDam = msg.killdam();
	killRedu = msg.killredu();
	attDam = msg.attdam();
	attRedu = msg.attredu();
	fightingCapacity = msg.fightingcapacity();
	isFightPress = msg.isfightpress();
	exp = msg.exp();
}

Sheet_monstervalue_s::Sheet_monstervalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_monstervalue_s::CreateInit() {
	return 0;
}

int Sheet_monstervalue_s::ResumeInit() {
	return 0;
}

void Sheet_monstervalue_s::write_to_pbmsg(::proto_ff::Sheet_monstervalue & msg) const {
	for(int32_t i = 0; i < (int32_t)monstervalue_List.GetSize() && i < monstervalue_List.GetMaxSize(); ++i) {
		::proto_ff::monstervalue* temp_monstervalue_list = msg.add_monstervalue_list();
		monstervalue_List[i].write_to_pbmsg(*temp_monstervalue_list);
	}
}

void Sheet_monstervalue_s::read_from_pbmsg(const ::proto_ff::Sheet_monstervalue & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_monstervalue_s));
	monstervalue_List.SetSize(msg.monstervalue_list_size() > monstervalue_List.GetMaxSize() ? monstervalue_List.GetMaxSize() : msg.monstervalue_list_size());
	for(int32_t i = 0; i < (int32_t)monstervalue_List.GetSize(); ++i) {
		const ::proto_ff::monstervalue & temp_monstervalue_list = msg.monstervalue_list(i);
		monstervalue_List[i].read_from_pbmsg(temp_monstervalue_list);
	}
}

}