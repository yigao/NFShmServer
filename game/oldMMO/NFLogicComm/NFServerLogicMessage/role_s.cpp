#include "role_s.h"

namespace proto_ff_s {

rolebornitemDesc_s::rolebornitemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rolebornitemDesc_s::CreateInit() {
	num = (int32_t)0;
	name = (int64_t)0;
	return 0;
}

int rolebornitemDesc_s::ResumeInit() {
	return 0;
}

void rolebornitemDesc_s::write_to_pbmsg(::proto_ff::rolebornitemDesc & msg) const {
	msg.set_num((int32_t)num);
	msg.set_name((int64_t)name);
}

void rolebornitemDesc_s::read_from_pbmsg(const ::proto_ff::rolebornitemDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rolebornitemDesc_s));
	num = msg.num();
	name = msg.name();
}

rolebornmailDesc_s::rolebornmailDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rolebornmailDesc_s::CreateInit() {
	num = (int32_t)0;
	name = (int64_t)0;
	return 0;
}

int rolebornmailDesc_s::ResumeInit() {
	return 0;
}

void rolebornmailDesc_s::write_to_pbmsg(::proto_ff::rolebornmailDesc & msg) const {
	msg.set_num((int32_t)num);
	msg.set_name((int64_t)name);
}

void rolebornmailDesc_s::read_from_pbmsg(const ::proto_ff::rolebornmailDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rolebornmailDesc_s));
	num = msg.num();
	name = msg.name();
}

roleborn_s::roleborn_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roleborn_s::CreateInit() {
	bornID = (int64_t)0;
	professionID = (int32_t)0;
	gender = (int32_t)0;
	bornLevel = (int32_t)0;
	bornTitle = (int32_t)0;
	diamond = (int64_t)0;
	bindDiamond = (int64_t)0;
	gold = (int64_t)0;
	mapID = (int64_t)0;
	birthFace = (int32_t)0;
	carryWeapons = (int64_t)0;
	carryArmor = (int64_t)0;
	carryCloak = (int64_t)0;
	carryShoes = (int64_t)0;
	carryNecklace = (int64_t)0;
	carryAmulet = (int64_t)0;
	carryBracer = (int64_t)0;
	carryRing = (int64_t)0;
	carryFashionWeapons = (int64_t)0;
	carryFashionArmor = (int64_t)0;
	carryWings = (int64_t)0;
	mSpeed = (int32_t)0;
	view = (int32_t)0;
	radius = (int32_t)0;
	sheny = (int64_t)0;
	shenw = (int64_t)0;
	return 0;
}

int roleborn_s::ResumeInit() {
	return 0;
}

void roleborn_s::write_to_pbmsg(::proto_ff::roleborn & msg) const {
	msg.set_bornid((int64_t)bornID);
	msg.set_professionid((int32_t)professionID);
	msg.set_professionname((const char*)professionName.Get());
	msg.set_placement((const char*)placement.Get());
	msg.set_gender((int32_t)gender);
	msg.set_bornlevel((int32_t)bornLevel);
	msg.set_borntitle((int32_t)bornTitle);
	msg.set_diamond((int64_t)diamond);
	msg.set_binddiamond((int64_t)bindDiamond);
	msg.set_gold((int64_t)gold);
	msg.set_mapid((int64_t)mapID);
	msg.set_birthface((int32_t)birthFace);
	msg.set_icons((const char*)icons.Get());
	msg.set_loginavata((const char*)loginAvata.Get());
	msg.set_newweapon((const char*)newweapon.Get());
	msg.set_newclothing((const char*)newclothing.Get());
	msg.set_weaponavata((const char*)weaponAvata.Get());
	msg.set_roleavata((const char*)roleAvata.Get());
	msg.set_carryweapons((int64_t)carryWeapons);
	msg.set_carryarmor((int64_t)carryArmor);
	msg.set_carrycloak((int64_t)carryCloak);
	msg.set_carryshoes((int64_t)carryShoes);
	msg.set_carrynecklace((int64_t)carryNecklace);
	msg.set_carryamulet((int64_t)carryAmulet);
	msg.set_carrybracer((int64_t)carryBracer);
	msg.set_carryring((int64_t)carryRing);
	msg.set_carryfashionweapons((int64_t)carryFashionWeapons);
	msg.set_carryfashionarmor((int64_t)carryFashionArmor);
	msg.set_carrywings((int64_t)carryWings);
	msg.set_mspeed((int32_t)mSpeed);
	msg.set_view((int32_t)view);
	msg.set_radius((int32_t)radius);
	msg.set_sheny((int64_t)sheny);
	msg.set_shenw((int64_t)shenw);
	for(int32_t i = 0; i < (int32_t)actBuff.GetSize() && i < actBuff.GetMaxSize(); ++i) {
		msg.add_actbuff((int32_t)actBuff[i]);
	}
	for(int32_t i = 0; i < (int32_t)item.GetSize() && i < item.GetMaxSize(); ++i) {
		::proto_ff::rolebornitemDesc* temp_item = msg.add_item();
		item[i].write_to_pbmsg(*temp_item);
	}
	for(int32_t i = 0; i < (int32_t)actSkill.GetSize() && i < actSkill.GetMaxSize(); ++i) {
		msg.add_actskill((int64_t)actSkill[i]);
	}
	for(int32_t i = 0; i < (int32_t)mail.GetSize() && i < mail.GetMaxSize(); ++i) {
		::proto_ff::rolebornmailDesc* temp_mail = msg.add_mail();
		mail[i].write_to_pbmsg(*temp_mail);
	}
}

void roleborn_s::read_from_pbmsg(const ::proto_ff::roleborn & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roleborn_s));
	bornID = msg.bornid();
	professionID = msg.professionid();
	professionName.Copy(msg.professionname());
	placement.Copy(msg.placement());
	gender = msg.gender();
	bornLevel = msg.bornlevel();
	bornTitle = msg.borntitle();
	diamond = msg.diamond();
	bindDiamond = msg.binddiamond();
	gold = msg.gold();
	mapID = msg.mapid();
	birthFace = msg.birthface();
	icons.Copy(msg.icons());
	loginAvata.Copy(msg.loginavata());
	newweapon.Copy(msg.newweapon());
	newclothing.Copy(msg.newclothing());
	weaponAvata.Copy(msg.weaponavata());
	roleAvata.Copy(msg.roleavata());
	carryWeapons = msg.carryweapons();
	carryArmor = msg.carryarmor();
	carryCloak = msg.carrycloak();
	carryShoes = msg.carryshoes();
	carryNecklace = msg.carrynecklace();
	carryAmulet = msg.carryamulet();
	carryBracer = msg.carrybracer();
	carryRing = msg.carryring();
	carryFashionWeapons = msg.carryfashionweapons();
	carryFashionArmor = msg.carryfashionarmor();
	carryWings = msg.carrywings();
	mSpeed = msg.mspeed();
	view = msg.view();
	radius = msg.radius();
	sheny = msg.sheny();
	shenw = msg.shenw();
	actBuff.SetSize(msg.actbuff_size() > actBuff.GetMaxSize() ? actBuff.GetMaxSize() : msg.actbuff_size());
	for(int32_t i = 0; i < (int32_t)actBuff.GetSize(); ++i) {
		actBuff[i] = msg.actbuff(i);
	}
	item.SetSize(msg.item_size() > item.GetMaxSize() ? item.GetMaxSize() : msg.item_size());
	for(int32_t i = 0; i < (int32_t)item.GetSize(); ++i) {
		const ::proto_ff::rolebornitemDesc & temp_item = msg.item(i);
		item[i].read_from_pbmsg(temp_item);
	}
	actSkill.SetSize(msg.actskill_size() > actSkill.GetMaxSize() ? actSkill.GetMaxSize() : msg.actskill_size());
	for(int32_t i = 0; i < (int32_t)actSkill.GetSize(); ++i) {
		actSkill[i] = msg.actskill(i);
	}
	mail.SetSize(msg.mail_size() > mail.GetMaxSize() ? mail.GetMaxSize() : msg.mail_size());
	for(int32_t i = 0; i < (int32_t)mail.GetSize(); ++i) {
		const ::proto_ff::rolebornmailDesc & temp_mail = msg.mail(i);
		mail[i].read_from_pbmsg(temp_mail);
	}
}

Sheet_roleborn_s::Sheet_roleborn_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_roleborn_s::CreateInit() {
	return 0;
}

int Sheet_roleborn_s::ResumeInit() {
	return 0;
}

void Sheet_roleborn_s::write_to_pbmsg(::proto_ff::Sheet_roleborn & msg) const {
	for(int32_t i = 0; i < (int32_t)roleborn_List.GetSize() && i < roleborn_List.GetMaxSize(); ++i) {
		::proto_ff::roleborn* temp_roleborn_list = msg.add_roleborn_list();
		roleborn_List[i].write_to_pbmsg(*temp_roleborn_list);
	}
}

void Sheet_roleborn_s::read_from_pbmsg(const ::proto_ff::Sheet_roleborn & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_roleborn_s));
	roleborn_List.SetSize(msg.roleborn_list_size() > roleborn_List.GetMaxSize() ? roleborn_List.GetMaxSize() : msg.roleborn_list_size());
	for(int32_t i = 0; i < (int32_t)roleborn_List.GetSize(); ++i) {
		const ::proto_ff::roleborn & temp_roleborn_list = msg.roleborn_list(i);
		roleborn_List[i].read_from_pbmsg(temp_roleborn_list);
	}
}

rolewarriorattributeDesc_s::rolewarriorattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rolewarriorattributeDesc_s::CreateInit() {
	Type = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int rolewarriorattributeDesc_s::ResumeInit() {
	return 0;
}

void rolewarriorattributeDesc_s::write_to_pbmsg(::proto_ff::rolewarriorattributeDesc & msg) const {
	msg.set_type((int32_t)Type);
	msg.set_value((int32_t)Value);
}

void rolewarriorattributeDesc_s::read_from_pbmsg(const ::proto_ff::rolewarriorattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rolewarriorattributeDesc_s));
	Type = msg.type();
	Value = msg.value();
}

rolewarrior_s::rolewarrior_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rolewarrior_s::CreateInit() {
	lv = (int32_t)0;
	upgradePoint = (int32_t)0;
	return 0;
}

int rolewarrior_s::ResumeInit() {
	return 0;
}

void rolewarrior_s::write_to_pbmsg(::proto_ff::rolewarrior & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_upgradepoint((int32_t)upgradePoint);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::rolewarriorattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void rolewarrior_s::read_from_pbmsg(const ::proto_ff::rolewarrior & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rolewarrior_s));
	lv = msg.lv();
	upgradePoint = msg.upgradepoint();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::rolewarriorattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_rolewarrior_s::Sheet_rolewarrior_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_rolewarrior_s::CreateInit() {
	return 0;
}

int Sheet_rolewarrior_s::ResumeInit() {
	return 0;
}

void Sheet_rolewarrior_s::write_to_pbmsg(::proto_ff::Sheet_rolewarrior & msg) const {
	for(int32_t i = 0; i < (int32_t)rolewarrior_List.GetSize() && i < rolewarrior_List.GetMaxSize(); ++i) {
		::proto_ff::rolewarrior* temp_rolewarrior_list = msg.add_rolewarrior_list();
		rolewarrior_List[i].write_to_pbmsg(*temp_rolewarrior_list);
	}
}

void Sheet_rolewarrior_s::read_from_pbmsg(const ::proto_ff::Sheet_rolewarrior & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_rolewarrior_s));
	rolewarrior_List.SetSize(msg.rolewarrior_list_size() > rolewarrior_List.GetMaxSize() ? rolewarrior_List.GetMaxSize() : msg.rolewarrior_list_size());
	for(int32_t i = 0; i < (int32_t)rolewarrior_List.GetSize(); ++i) {
		const ::proto_ff::rolewarrior & temp_rolewarrior_list = msg.rolewarrior_list(i);
		rolewarrior_List[i].read_from_pbmsg(temp_rolewarrior_list);
	}
}

rolemasterattributeDesc_s::rolemasterattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rolemasterattributeDesc_s::CreateInit() {
	Type = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int rolemasterattributeDesc_s::ResumeInit() {
	return 0;
}

void rolemasterattributeDesc_s::write_to_pbmsg(::proto_ff::rolemasterattributeDesc & msg) const {
	msg.set_type((int32_t)Type);
	msg.set_value((int32_t)Value);
}

void rolemasterattributeDesc_s::read_from_pbmsg(const ::proto_ff::rolemasterattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rolemasterattributeDesc_s));
	Type = msg.type();
	Value = msg.value();
}

rolemaster_s::rolemaster_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rolemaster_s::CreateInit() {
	lv = (int32_t)0;
	upgradePoint = (int32_t)0;
	return 0;
}

int rolemaster_s::ResumeInit() {
	return 0;
}

void rolemaster_s::write_to_pbmsg(::proto_ff::rolemaster & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_upgradepoint((int32_t)upgradePoint);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::rolemasterattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void rolemaster_s::read_from_pbmsg(const ::proto_ff::rolemaster & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rolemaster_s));
	lv = msg.lv();
	upgradePoint = msg.upgradepoint();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::rolemasterattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_rolemaster_s::Sheet_rolemaster_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_rolemaster_s::CreateInit() {
	return 0;
}

int Sheet_rolemaster_s::ResumeInit() {
	return 0;
}

void Sheet_rolemaster_s::write_to_pbmsg(::proto_ff::Sheet_rolemaster & msg) const {
	for(int32_t i = 0; i < (int32_t)rolemaster_List.GetSize() && i < rolemaster_List.GetMaxSize(); ++i) {
		::proto_ff::rolemaster* temp_rolemaster_list = msg.add_rolemaster_list();
		rolemaster_List[i].write_to_pbmsg(*temp_rolemaster_list);
	}
}

void Sheet_rolemaster_s::read_from_pbmsg(const ::proto_ff::Sheet_rolemaster & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_rolemaster_s));
	rolemaster_List.SetSize(msg.rolemaster_list_size() > rolemaster_List.GetMaxSize() ? rolemaster_List.GetMaxSize() : msg.rolemaster_list_size());
	for(int32_t i = 0; i < (int32_t)rolemaster_List.GetSize(); ++i) {
		const ::proto_ff::rolemaster & temp_rolemaster_list = msg.rolemaster_list(i);
		rolemaster_List[i].read_from_pbmsg(temp_rolemaster_list);
	}
}

roleassassinattributeDesc_s::roleassassinattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roleassassinattributeDesc_s::CreateInit() {
	Type = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int roleassassinattributeDesc_s::ResumeInit() {
	return 0;
}

void roleassassinattributeDesc_s::write_to_pbmsg(::proto_ff::roleassassinattributeDesc & msg) const {
	msg.set_type((int32_t)Type);
	msg.set_value((int32_t)Value);
}

void roleassassinattributeDesc_s::read_from_pbmsg(const ::proto_ff::roleassassinattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roleassassinattributeDesc_s));
	Type = msg.type();
	Value = msg.value();
}

roleassassin_s::roleassassin_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roleassassin_s::CreateInit() {
	lv = (int32_t)0;
	upgradePoint = (int32_t)0;
	return 0;
}

int roleassassin_s::ResumeInit() {
	return 0;
}

void roleassassin_s::write_to_pbmsg(::proto_ff::roleassassin & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_upgradepoint((int32_t)upgradePoint);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::roleassassinattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void roleassassin_s::read_from_pbmsg(const ::proto_ff::roleassassin & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roleassassin_s));
	lv = msg.lv();
	upgradePoint = msg.upgradepoint();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::roleassassinattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_roleassassin_s::Sheet_roleassassin_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_roleassassin_s::CreateInit() {
	return 0;
}

int Sheet_roleassassin_s::ResumeInit() {
	return 0;
}

void Sheet_roleassassin_s::write_to_pbmsg(::proto_ff::Sheet_roleassassin & msg) const {
	for(int32_t i = 0; i < (int32_t)roleassassin_List.GetSize() && i < roleassassin_List.GetMaxSize(); ++i) {
		::proto_ff::roleassassin* temp_roleassassin_list = msg.add_roleassassin_list();
		roleassassin_List[i].write_to_pbmsg(*temp_roleassassin_list);
	}
}

void Sheet_roleassassin_s::read_from_pbmsg(const ::proto_ff::Sheet_roleassassin & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_roleassassin_s));
	roleassassin_List.SetSize(msg.roleassassin_list_size() > roleassassin_List.GetMaxSize() ? roleassassin_List.GetMaxSize() : msg.roleassassin_list_size());
	for(int32_t i = 0; i < (int32_t)roleassassin_List.GetSize(); ++i) {
		const ::proto_ff::roleassassin & temp_roleassassin_list = msg.roleassassin_list(i);
		roleassassin_List[i].read_from_pbmsg(temp_roleassassin_list);
	}
}

roleshooterattributeDesc_s::roleshooterattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roleshooterattributeDesc_s::CreateInit() {
	Type = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int roleshooterattributeDesc_s::ResumeInit() {
	return 0;
}

void roleshooterattributeDesc_s::write_to_pbmsg(::proto_ff::roleshooterattributeDesc & msg) const {
	msg.set_type((int32_t)Type);
	msg.set_value((int32_t)Value);
}

void roleshooterattributeDesc_s::read_from_pbmsg(const ::proto_ff::roleshooterattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roleshooterattributeDesc_s));
	Type = msg.type();
	Value = msg.value();
}

roleshooter_s::roleshooter_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roleshooter_s::CreateInit() {
	lv = (int32_t)0;
	upgradePoint = (int32_t)0;
	return 0;
}

int roleshooter_s::ResumeInit() {
	return 0;
}

void roleshooter_s::write_to_pbmsg(::proto_ff::roleshooter & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_upgradepoint((int32_t)upgradePoint);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::roleshooterattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void roleshooter_s::read_from_pbmsg(const ::proto_ff::roleshooter & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roleshooter_s));
	lv = msg.lv();
	upgradePoint = msg.upgradepoint();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::roleshooterattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_roleshooter_s::Sheet_roleshooter_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_roleshooter_s::CreateInit() {
	return 0;
}

int Sheet_roleshooter_s::ResumeInit() {
	return 0;
}

void Sheet_roleshooter_s::write_to_pbmsg(::proto_ff::Sheet_roleshooter & msg) const {
	for(int32_t i = 0; i < (int32_t)roleshooter_List.GetSize() && i < roleshooter_List.GetMaxSize(); ++i) {
		::proto_ff::roleshooter* temp_roleshooter_list = msg.add_roleshooter_list();
		roleshooter_List[i].write_to_pbmsg(*temp_roleshooter_list);
	}
}

void Sheet_roleshooter_s::read_from_pbmsg(const ::proto_ff::Sheet_roleshooter & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_roleshooter_s));
	roleshooter_List.SetSize(msg.roleshooter_list_size() > roleshooter_List.GetMaxSize() ? roleshooter_List.GetMaxSize() : msg.roleshooter_list_size());
	for(int32_t i = 0; i < (int32_t)roleshooter_List.GetSize(); ++i) {
		const ::proto_ff::roleshooter & temp_roleshooter_list = msg.roleshooter_list(i);
		roleshooter_List[i].read_from_pbmsg(temp_roleshooter_list);
	}
}

roleexp_s::roleexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roleexp_s::CreateInit() {
	lv = (int32_t)0;
	exp = (int64_t)0;
	skillPoint = (int32_t)0;
	return 0;
}

int roleexp_s::ResumeInit() {
	return 0;
}

void roleexp_s::write_to_pbmsg(::proto_ff::roleexp & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_exp((int64_t)exp);
	msg.set_skillpoint((int32_t)skillPoint);
}

void roleexp_s::read_from_pbmsg(const ::proto_ff::roleexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roleexp_s));
	lv = msg.lv();
	exp = msg.exp();
	skillPoint = msg.skillpoint();
}

Sheet_roleexp_s::Sheet_roleexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_roleexp_s::CreateInit() {
	return 0;
}

int Sheet_roleexp_s::ResumeInit() {
	return 0;
}

void Sheet_roleexp_s::write_to_pbmsg(::proto_ff::Sheet_roleexp & msg) const {
	for(int32_t i = 0; i < (int32_t)roleexp_List.GetSize() && i < roleexp_List.GetMaxSize(); ++i) {
		::proto_ff::roleexp* temp_roleexp_list = msg.add_roleexp_list();
		roleexp_List[i].write_to_pbmsg(*temp_roleexp_list);
	}
}

void Sheet_roleexp_s::read_from_pbmsg(const ::proto_ff::Sheet_roleexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_roleexp_s));
	roleexp_List.SetSize(msg.roleexp_list_size() > roleexp_List.GetMaxSize() ? roleexp_List.GetMaxSize() : msg.roleexp_list_size());
	for(int32_t i = 0; i < (int32_t)roleexp_List.GetSize(); ++i) {
		const ::proto_ff::roleexp & temp_roleexp_list = msg.roleexp_list(i);
		roleexp_List[i].read_from_pbmsg(temp_roleexp_list);
	}
}

roleskillType_s::roleskillType_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roleskillType_s::CreateInit() {
	skillId = (int64_t)0;
	skillType = (int32_t)0;
	return 0;
}

int roleskillType_s::ResumeInit() {
	return 0;
}

void roleskillType_s::write_to_pbmsg(::proto_ff::roleskillType & msg) const {
	msg.set_skillid((int64_t)skillId);
	msg.set_skilltype((int32_t)skillType);
}

void roleskillType_s::read_from_pbmsg(const ::proto_ff::roleskillType & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roleskillType_s));
	skillId = msg.skillid();
	skillType = msg.skilltype();
}

Sheet_roleskillType_s::Sheet_roleskillType_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_roleskillType_s::CreateInit() {
	return 0;
}

int Sheet_roleskillType_s::ResumeInit() {
	return 0;
}

void Sheet_roleskillType_s::write_to_pbmsg(::proto_ff::Sheet_roleskillType & msg) const {
	for(int32_t i = 0; i < (int32_t)roleskillType_List.GetSize() && i < roleskillType_List.GetMaxSize(); ++i) {
		::proto_ff::roleskillType* temp_roleskilltype_list = msg.add_roleskilltype_list();
		roleskillType_List[i].write_to_pbmsg(*temp_roleskilltype_list);
	}
}

void Sheet_roleskillType_s::read_from_pbmsg(const ::proto_ff::Sheet_roleskillType & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_roleskillType_s));
	roleskillType_List.SetSize(msg.roleskilltype_list_size() > roleskillType_List.GetMaxSize() ? roleskillType_List.GetMaxSize() : msg.roleskilltype_list_size());
	for(int32_t i = 0; i < (int32_t)roleskillType_List.GetSize(); ++i) {
		const ::proto_ff::roleskillType & temp_roleskilltype_list = msg.roleskilltype_list(i);
		roleskillType_List[i].read_from_pbmsg(temp_roleskilltype_list);
	}
}

roleaddSkill_s::roleaddSkill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roleaddSkill_s::CreateInit() {
	Id = (int32_t)0;
	skillId = (int64_t)0;
	return 0;
}

int roleaddSkill_s::ResumeInit() {
	return 0;
}

void roleaddSkill_s::write_to_pbmsg(::proto_ff::roleaddSkill & msg) const {
	msg.set_id((int32_t)Id);
	msg.set_skillid((int64_t)skillId);
}

void roleaddSkill_s::read_from_pbmsg(const ::proto_ff::roleaddSkill & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roleaddSkill_s));
	Id = msg.id();
	skillId = msg.skillid();
}

Sheet_roleaddSkill_s::Sheet_roleaddSkill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_roleaddSkill_s::CreateInit() {
	return 0;
}

int Sheet_roleaddSkill_s::ResumeInit() {
	return 0;
}

void Sheet_roleaddSkill_s::write_to_pbmsg(::proto_ff::Sheet_roleaddSkill & msg) const {
	for(int32_t i = 0; i < (int32_t)roleaddSkill_List.GetSize() && i < roleaddSkill_List.GetMaxSize(); ++i) {
		::proto_ff::roleaddSkill* temp_roleaddskill_list = msg.add_roleaddskill_list();
		roleaddSkill_List[i].write_to_pbmsg(*temp_roleaddskill_list);
	}
}

void Sheet_roleaddSkill_s::read_from_pbmsg(const ::proto_ff::Sheet_roleaddSkill & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_roleaddSkill_s));
	roleaddSkill_List.SetSize(msg.roleaddskill_list_size() > roleaddSkill_List.GetMaxSize() ? roleaddSkill_List.GetMaxSize() : msg.roleaddskill_list_size());
	for(int32_t i = 0; i < (int32_t)roleaddSkill_List.GetSize(); ++i) {
		const ::proto_ff::roleaddSkill & temp_roleaddskill_list = msg.roleaddskill_list(i);
		roleaddSkill_List[i].read_from_pbmsg(temp_roleaddskill_list);
	}
}

roleworldexp_s::roleworldexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roleworldexp_s::CreateInit() {
	lv = (int64_t)0;
	worldExp = (int32_t)0;
	return 0;
}

int roleworldexp_s::ResumeInit() {
	return 0;
}

void roleworldexp_s::write_to_pbmsg(::proto_ff::roleworldexp & msg) const {
	msg.set_lv((int64_t)lv);
	msg.set_worldexp((int32_t)worldExp);
}

void roleworldexp_s::read_from_pbmsg(const ::proto_ff::roleworldexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roleworldexp_s));
	lv = msg.lv();
	worldExp = msg.worldexp();
}

Sheet_roleworldexp_s::Sheet_roleworldexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_roleworldexp_s::CreateInit() {
	return 0;
}

int Sheet_roleworldexp_s::ResumeInit() {
	return 0;
}

void Sheet_roleworldexp_s::write_to_pbmsg(::proto_ff::Sheet_roleworldexp & msg) const {
	for(int32_t i = 0; i < (int32_t)roleworldexp_List.GetSize() && i < roleworldexp_List.GetMaxSize(); ++i) {
		::proto_ff::roleworldexp* temp_roleworldexp_list = msg.add_roleworldexp_list();
		roleworldexp_List[i].write_to_pbmsg(*temp_roleworldexp_list);
	}
}

void Sheet_roleworldexp_s::read_from_pbmsg(const ::proto_ff::Sheet_roleworldexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_roleworldexp_s));
	roleworldexp_List.SetSize(msg.roleworldexp_list_size() > roleworldexp_List.GetMaxSize() ? roleworldexp_List.GetMaxSize() : msg.roleworldexp_list_size());
	for(int32_t i = 0; i < (int32_t)roleworldexp_List.GetSize(); ++i) {
		const ::proto_ff::roleworldexp & temp_roleworldexp_list = msg.roleworldexp_list(i);
		roleworldexp_List[i].read_from_pbmsg(temp_roleworldexp_list);
	}
}

}