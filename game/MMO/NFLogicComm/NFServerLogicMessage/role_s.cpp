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
	hairColor = (int32_t)0;
	clothesColor = (int32_t)0;
	skinColor = (int32_t)0;
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
	group = (int32_t)0;
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
	msg.set_haircolor((int32_t)hairColor);
	msg.set_clothescolor((int32_t)clothesColor);
	msg.set_skincolor((int32_t)skinColor);
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
	msg.set_group((int32_t)group);
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
	hairColor = msg.haircolor();
	clothesColor = msg.clothescolor();
	skinColor = msg.skincolor();
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
	group = msg.group();
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

rolemasterMaleattributeDesc_s::rolemasterMaleattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rolemasterMaleattributeDesc_s::CreateInit() {
	Type = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int rolemasterMaleattributeDesc_s::ResumeInit() {
	return 0;
}

void rolemasterMaleattributeDesc_s::write_to_pbmsg(::proto_ff::rolemasterMaleattributeDesc & msg) const {
	msg.set_type((int32_t)Type);
	msg.set_value((int32_t)Value);
}

void rolemasterMaleattributeDesc_s::read_from_pbmsg(const ::proto_ff::rolemasterMaleattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rolemasterMaleattributeDesc_s));
	Type = msg.type();
	Value = msg.value();
}

rolemasterMale_s::rolemasterMale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rolemasterMale_s::CreateInit() {
	lv = (int32_t)0;
	upgradePoint = (int32_t)0;
	return 0;
}

int rolemasterMale_s::ResumeInit() {
	return 0;
}

void rolemasterMale_s::write_to_pbmsg(::proto_ff::rolemasterMale & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_upgradepoint((int32_t)upgradePoint);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::rolemasterMaleattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void rolemasterMale_s::read_from_pbmsg(const ::proto_ff::rolemasterMale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rolemasterMale_s));
	lv = msg.lv();
	upgradePoint = msg.upgradepoint();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::rolemasterMaleattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_rolemasterMale_s::Sheet_rolemasterMale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_rolemasterMale_s::CreateInit() {
	return 0;
}

int Sheet_rolemasterMale_s::ResumeInit() {
	return 0;
}

void Sheet_rolemasterMale_s::write_to_pbmsg(::proto_ff::Sheet_rolemasterMale & msg) const {
	for(int32_t i = 0; i < (int32_t)rolemasterMale_List.GetSize() && i < rolemasterMale_List.GetMaxSize(); ++i) {
		::proto_ff::rolemasterMale* temp_rolemastermale_list = msg.add_rolemastermale_list();
		rolemasterMale_List[i].write_to_pbmsg(*temp_rolemastermale_list);
	}
}

void Sheet_rolemasterMale_s::read_from_pbmsg(const ::proto_ff::Sheet_rolemasterMale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_rolemasterMale_s));
	rolemasterMale_List.SetSize(msg.rolemastermale_list_size() > rolemasterMale_List.GetMaxSize() ? rolemasterMale_List.GetMaxSize() : msg.rolemastermale_list_size());
	for(int32_t i = 0; i < (int32_t)rolemasterMale_List.GetSize(); ++i) {
		const ::proto_ff::rolemasterMale & temp_rolemastermale_list = msg.rolemastermale_list(i);
		rolemasterMale_List[i].read_from_pbmsg(temp_rolemastermale_list);
	}
}

rolemasterFemaleattributeDesc_s::rolemasterFemaleattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rolemasterFemaleattributeDesc_s::CreateInit() {
	Type = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int rolemasterFemaleattributeDesc_s::ResumeInit() {
	return 0;
}

void rolemasterFemaleattributeDesc_s::write_to_pbmsg(::proto_ff::rolemasterFemaleattributeDesc & msg) const {
	msg.set_type((int32_t)Type);
	msg.set_value((int32_t)Value);
}

void rolemasterFemaleattributeDesc_s::read_from_pbmsg(const ::proto_ff::rolemasterFemaleattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rolemasterFemaleattributeDesc_s));
	Type = msg.type();
	Value = msg.value();
}

rolemasterFemale_s::rolemasterFemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rolemasterFemale_s::CreateInit() {
	lv = (int32_t)0;
	upgradePoint = (int32_t)0;
	return 0;
}

int rolemasterFemale_s::ResumeInit() {
	return 0;
}

void rolemasterFemale_s::write_to_pbmsg(::proto_ff::rolemasterFemale & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_upgradepoint((int32_t)upgradePoint);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::rolemasterFemaleattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void rolemasterFemale_s::read_from_pbmsg(const ::proto_ff::rolemasterFemale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rolemasterFemale_s));
	lv = msg.lv();
	upgradePoint = msg.upgradepoint();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::rolemasterFemaleattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_rolemasterFemale_s::Sheet_rolemasterFemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_rolemasterFemale_s::CreateInit() {
	return 0;
}

int Sheet_rolemasterFemale_s::ResumeInit() {
	return 0;
}

void Sheet_rolemasterFemale_s::write_to_pbmsg(::proto_ff::Sheet_rolemasterFemale & msg) const {
	for(int32_t i = 0; i < (int32_t)rolemasterFemale_List.GetSize() && i < rolemasterFemale_List.GetMaxSize(); ++i) {
		::proto_ff::rolemasterFemale* temp_rolemasterfemale_list = msg.add_rolemasterfemale_list();
		rolemasterFemale_List[i].write_to_pbmsg(*temp_rolemasterfemale_list);
	}
}

void Sheet_rolemasterFemale_s::read_from_pbmsg(const ::proto_ff::Sheet_rolemasterFemale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_rolemasterFemale_s));
	rolemasterFemale_List.SetSize(msg.rolemasterfemale_list_size() > rolemasterFemale_List.GetMaxSize() ? rolemasterFemale_List.GetMaxSize() : msg.rolemasterfemale_list_size());
	for(int32_t i = 0; i < (int32_t)rolemasterFemale_List.GetSize(); ++i) {
		const ::proto_ff::rolemasterFemale & temp_rolemasterfemale_list = msg.rolemasterfemale_list(i);
		rolemasterFemale_List[i].read_from_pbmsg(temp_rolemasterfemale_list);
	}
}

rolesickleMaleattributeDesc_s::rolesickleMaleattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rolesickleMaleattributeDesc_s::CreateInit() {
	Type = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int rolesickleMaleattributeDesc_s::ResumeInit() {
	return 0;
}

void rolesickleMaleattributeDesc_s::write_to_pbmsg(::proto_ff::rolesickleMaleattributeDesc & msg) const {
	msg.set_type((int32_t)Type);
	msg.set_value((int32_t)Value);
}

void rolesickleMaleattributeDesc_s::read_from_pbmsg(const ::proto_ff::rolesickleMaleattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rolesickleMaleattributeDesc_s));
	Type = msg.type();
	Value = msg.value();
}

rolesickleMale_s::rolesickleMale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rolesickleMale_s::CreateInit() {
	lv = (int32_t)0;
	upgradePoint = (int32_t)0;
	return 0;
}

int rolesickleMale_s::ResumeInit() {
	return 0;
}

void rolesickleMale_s::write_to_pbmsg(::proto_ff::rolesickleMale & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_upgradepoint((int32_t)upgradePoint);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::rolesickleMaleattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void rolesickleMale_s::read_from_pbmsg(const ::proto_ff::rolesickleMale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rolesickleMale_s));
	lv = msg.lv();
	upgradePoint = msg.upgradepoint();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::rolesickleMaleattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_rolesickleMale_s::Sheet_rolesickleMale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_rolesickleMale_s::CreateInit() {
	return 0;
}

int Sheet_rolesickleMale_s::ResumeInit() {
	return 0;
}

void Sheet_rolesickleMale_s::write_to_pbmsg(::proto_ff::Sheet_rolesickleMale & msg) const {
	for(int32_t i = 0; i < (int32_t)rolesickleMale_List.GetSize() && i < rolesickleMale_List.GetMaxSize(); ++i) {
		::proto_ff::rolesickleMale* temp_rolesicklemale_list = msg.add_rolesicklemale_list();
		rolesickleMale_List[i].write_to_pbmsg(*temp_rolesicklemale_list);
	}
}

void Sheet_rolesickleMale_s::read_from_pbmsg(const ::proto_ff::Sheet_rolesickleMale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_rolesickleMale_s));
	rolesickleMale_List.SetSize(msg.rolesicklemale_list_size() > rolesickleMale_List.GetMaxSize() ? rolesickleMale_List.GetMaxSize() : msg.rolesicklemale_list_size());
	for(int32_t i = 0; i < (int32_t)rolesickleMale_List.GetSize(); ++i) {
		const ::proto_ff::rolesickleMale & temp_rolesicklemale_list = msg.rolesicklemale_list(i);
		rolesickleMale_List[i].read_from_pbmsg(temp_rolesicklemale_list);
	}
}

rolesickleFemaleattributeDesc_s::rolesickleFemaleattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rolesickleFemaleattributeDesc_s::CreateInit() {
	Type = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int rolesickleFemaleattributeDesc_s::ResumeInit() {
	return 0;
}

void rolesickleFemaleattributeDesc_s::write_to_pbmsg(::proto_ff::rolesickleFemaleattributeDesc & msg) const {
	msg.set_type((int32_t)Type);
	msg.set_value((int32_t)Value);
}

void rolesickleFemaleattributeDesc_s::read_from_pbmsg(const ::proto_ff::rolesickleFemaleattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rolesickleFemaleattributeDesc_s));
	Type = msg.type();
	Value = msg.value();
}

rolesickleFemale_s::rolesickleFemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rolesickleFemale_s::CreateInit() {
	lv = (int32_t)0;
	upgradePoint = (int32_t)0;
	return 0;
}

int rolesickleFemale_s::ResumeInit() {
	return 0;
}

void rolesickleFemale_s::write_to_pbmsg(::proto_ff::rolesickleFemale & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_upgradepoint((int32_t)upgradePoint);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::rolesickleFemaleattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void rolesickleFemale_s::read_from_pbmsg(const ::proto_ff::rolesickleFemale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rolesickleFemale_s));
	lv = msg.lv();
	upgradePoint = msg.upgradepoint();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::rolesickleFemaleattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_rolesickleFemale_s::Sheet_rolesickleFemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_rolesickleFemale_s::CreateInit() {
	return 0;
}

int Sheet_rolesickleFemale_s::ResumeInit() {
	return 0;
}

void Sheet_rolesickleFemale_s::write_to_pbmsg(::proto_ff::Sheet_rolesickleFemale & msg) const {
	for(int32_t i = 0; i < (int32_t)rolesickleFemale_List.GetSize() && i < rolesickleFemale_List.GetMaxSize(); ++i) {
		::proto_ff::rolesickleFemale* temp_rolesicklefemale_list = msg.add_rolesicklefemale_list();
		rolesickleFemale_List[i].write_to_pbmsg(*temp_rolesicklefemale_list);
	}
}

void Sheet_rolesickleFemale_s::read_from_pbmsg(const ::proto_ff::Sheet_rolesickleFemale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_rolesickleFemale_s));
	rolesickleFemale_List.SetSize(msg.rolesicklefemale_list_size() > rolesickleFemale_List.GetMaxSize() ? rolesickleFemale_List.GetMaxSize() : msg.rolesicklefemale_list_size());
	for(int32_t i = 0; i < (int32_t)rolesickleFemale_List.GetSize(); ++i) {
		const ::proto_ff::rolesickleFemale & temp_rolesicklefemale_list = msg.rolesicklefemale_list(i);
		rolesickleFemale_List[i].read_from_pbmsg(temp_rolesicklefemale_list);
	}
}

roleswordMaleattributeDesc_s::roleswordMaleattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roleswordMaleattributeDesc_s::CreateInit() {
	Type = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int roleswordMaleattributeDesc_s::ResumeInit() {
	return 0;
}

void roleswordMaleattributeDesc_s::write_to_pbmsg(::proto_ff::roleswordMaleattributeDesc & msg) const {
	msg.set_type((int32_t)Type);
	msg.set_value((int32_t)Value);
}

void roleswordMaleattributeDesc_s::read_from_pbmsg(const ::proto_ff::roleswordMaleattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roleswordMaleattributeDesc_s));
	Type = msg.type();
	Value = msg.value();
}

roleswordMale_s::roleswordMale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roleswordMale_s::CreateInit() {
	lv = (int32_t)0;
	upgradePoint = (int32_t)0;
	return 0;
}

int roleswordMale_s::ResumeInit() {
	return 0;
}

void roleswordMale_s::write_to_pbmsg(::proto_ff::roleswordMale & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_upgradepoint((int32_t)upgradePoint);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::roleswordMaleattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void roleswordMale_s::read_from_pbmsg(const ::proto_ff::roleswordMale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roleswordMale_s));
	lv = msg.lv();
	upgradePoint = msg.upgradepoint();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::roleswordMaleattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_roleswordMale_s::Sheet_roleswordMale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_roleswordMale_s::CreateInit() {
	return 0;
}

int Sheet_roleswordMale_s::ResumeInit() {
	return 0;
}

void Sheet_roleswordMale_s::write_to_pbmsg(::proto_ff::Sheet_roleswordMale & msg) const {
	for(int32_t i = 0; i < (int32_t)roleswordMale_List.GetSize() && i < roleswordMale_List.GetMaxSize(); ++i) {
		::proto_ff::roleswordMale* temp_roleswordmale_list = msg.add_roleswordmale_list();
		roleswordMale_List[i].write_to_pbmsg(*temp_roleswordmale_list);
	}
}

void Sheet_roleswordMale_s::read_from_pbmsg(const ::proto_ff::Sheet_roleswordMale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_roleswordMale_s));
	roleswordMale_List.SetSize(msg.roleswordmale_list_size() > roleswordMale_List.GetMaxSize() ? roleswordMale_List.GetMaxSize() : msg.roleswordmale_list_size());
	for(int32_t i = 0; i < (int32_t)roleswordMale_List.GetSize(); ++i) {
		const ::proto_ff::roleswordMale & temp_roleswordmale_list = msg.roleswordmale_list(i);
		roleswordMale_List[i].read_from_pbmsg(temp_roleswordmale_list);
	}
}

roleswordFemaleattributeDesc_s::roleswordFemaleattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roleswordFemaleattributeDesc_s::CreateInit() {
	Type = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int roleswordFemaleattributeDesc_s::ResumeInit() {
	return 0;
}

void roleswordFemaleattributeDesc_s::write_to_pbmsg(::proto_ff::roleswordFemaleattributeDesc & msg) const {
	msg.set_type((int32_t)Type);
	msg.set_value((int32_t)Value);
}

void roleswordFemaleattributeDesc_s::read_from_pbmsg(const ::proto_ff::roleswordFemaleattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roleswordFemaleattributeDesc_s));
	Type = msg.type();
	Value = msg.value();
}

roleswordFemale_s::roleswordFemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roleswordFemale_s::CreateInit() {
	lv = (int32_t)0;
	upgradePoint = (int32_t)0;
	return 0;
}

int roleswordFemale_s::ResumeInit() {
	return 0;
}

void roleswordFemale_s::write_to_pbmsg(::proto_ff::roleswordFemale & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_upgradepoint((int32_t)upgradePoint);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::roleswordFemaleattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void roleswordFemale_s::read_from_pbmsg(const ::proto_ff::roleswordFemale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roleswordFemale_s));
	lv = msg.lv();
	upgradePoint = msg.upgradepoint();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::roleswordFemaleattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_roleswordFemale_s::Sheet_roleswordFemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_roleswordFemale_s::CreateInit() {
	return 0;
}

int Sheet_roleswordFemale_s::ResumeInit() {
	return 0;
}

void Sheet_roleswordFemale_s::write_to_pbmsg(::proto_ff::Sheet_roleswordFemale & msg) const {
	for(int32_t i = 0; i < (int32_t)roleswordFemale_List.GetSize() && i < roleswordFemale_List.GetMaxSize(); ++i) {
		::proto_ff::roleswordFemale* temp_roleswordfemale_list = msg.add_roleswordfemale_list();
		roleswordFemale_List[i].write_to_pbmsg(*temp_roleswordfemale_list);
	}
}

void Sheet_roleswordFemale_s::read_from_pbmsg(const ::proto_ff::Sheet_roleswordFemale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_roleswordFemale_s));
	roleswordFemale_List.SetSize(msg.roleswordfemale_list_size() > roleswordFemale_List.GetMaxSize() ? roleswordFemale_List.GetMaxSize() : msg.roleswordfemale_list_size());
	for(int32_t i = 0; i < (int32_t)roleswordFemale_List.GetSize(); ++i) {
		const ::proto_ff::roleswordFemale & temp_roleswordfemale_list = msg.roleswordfemale_list(i);
		roleswordFemale_List[i].read_from_pbmsg(temp_roleswordfemale_list);
	}
}

roletaidaoMaleattributeDesc_s::roletaidaoMaleattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roletaidaoMaleattributeDesc_s::CreateInit() {
	Type = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int roletaidaoMaleattributeDesc_s::ResumeInit() {
	return 0;
}

void roletaidaoMaleattributeDesc_s::write_to_pbmsg(::proto_ff::roletaidaoMaleattributeDesc & msg) const {
	msg.set_type((int32_t)Type);
	msg.set_value((int32_t)Value);
}

void roletaidaoMaleattributeDesc_s::read_from_pbmsg(const ::proto_ff::roletaidaoMaleattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roletaidaoMaleattributeDesc_s));
	Type = msg.type();
	Value = msg.value();
}

roletaidaoMale_s::roletaidaoMale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roletaidaoMale_s::CreateInit() {
	lv = (int32_t)0;
	upgradePoint = (int32_t)0;
	return 0;
}

int roletaidaoMale_s::ResumeInit() {
	return 0;
}

void roletaidaoMale_s::write_to_pbmsg(::proto_ff::roletaidaoMale & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_upgradepoint((int32_t)upgradePoint);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::roletaidaoMaleattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void roletaidaoMale_s::read_from_pbmsg(const ::proto_ff::roletaidaoMale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roletaidaoMale_s));
	lv = msg.lv();
	upgradePoint = msg.upgradepoint();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::roletaidaoMaleattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_roletaidaoMale_s::Sheet_roletaidaoMale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_roletaidaoMale_s::CreateInit() {
	return 0;
}

int Sheet_roletaidaoMale_s::ResumeInit() {
	return 0;
}

void Sheet_roletaidaoMale_s::write_to_pbmsg(::proto_ff::Sheet_roletaidaoMale & msg) const {
	for(int32_t i = 0; i < (int32_t)roletaidaoMale_List.GetSize() && i < roletaidaoMale_List.GetMaxSize(); ++i) {
		::proto_ff::roletaidaoMale* temp_roletaidaomale_list = msg.add_roletaidaomale_list();
		roletaidaoMale_List[i].write_to_pbmsg(*temp_roletaidaomale_list);
	}
}

void Sheet_roletaidaoMale_s::read_from_pbmsg(const ::proto_ff::Sheet_roletaidaoMale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_roletaidaoMale_s));
	roletaidaoMale_List.SetSize(msg.roletaidaomale_list_size() > roletaidaoMale_List.GetMaxSize() ? roletaidaoMale_List.GetMaxSize() : msg.roletaidaomale_list_size());
	for(int32_t i = 0; i < (int32_t)roletaidaoMale_List.GetSize(); ++i) {
		const ::proto_ff::roletaidaoMale & temp_roletaidaomale_list = msg.roletaidaomale_list(i);
		roletaidaoMale_List[i].read_from_pbmsg(temp_roletaidaomale_list);
	}
}

roletaidaoFemaleattributeDesc_s::roletaidaoFemaleattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roletaidaoFemaleattributeDesc_s::CreateInit() {
	Type = (int32_t)0;
	Value = (int32_t)0;
	return 0;
}

int roletaidaoFemaleattributeDesc_s::ResumeInit() {
	return 0;
}

void roletaidaoFemaleattributeDesc_s::write_to_pbmsg(::proto_ff::roletaidaoFemaleattributeDesc & msg) const {
	msg.set_type((int32_t)Type);
	msg.set_value((int32_t)Value);
}

void roletaidaoFemaleattributeDesc_s::read_from_pbmsg(const ::proto_ff::roletaidaoFemaleattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roletaidaoFemaleattributeDesc_s));
	Type = msg.type();
	Value = msg.value();
}

roletaidaoFemale_s::roletaidaoFemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int roletaidaoFemale_s::CreateInit() {
	lv = (int32_t)0;
	upgradePoint = (int32_t)0;
	return 0;
}

int roletaidaoFemale_s::ResumeInit() {
	return 0;
}

void roletaidaoFemale_s::write_to_pbmsg(::proto_ff::roletaidaoFemale & msg) const {
	msg.set_lv((int32_t)lv);
	msg.set_upgradepoint((int32_t)upgradePoint);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::roletaidaoFemaleattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void roletaidaoFemale_s::read_from_pbmsg(const ::proto_ff::roletaidaoFemale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct roletaidaoFemale_s));
	lv = msg.lv();
	upgradePoint = msg.upgradepoint();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::roletaidaoFemaleattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_roletaidaoFemale_s::Sheet_roletaidaoFemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_roletaidaoFemale_s::CreateInit() {
	return 0;
}

int Sheet_roletaidaoFemale_s::ResumeInit() {
	return 0;
}

void Sheet_roletaidaoFemale_s::write_to_pbmsg(::proto_ff::Sheet_roletaidaoFemale & msg) const {
	for(int32_t i = 0; i < (int32_t)roletaidaoFemale_List.GetSize() && i < roletaidaoFemale_List.GetMaxSize(); ++i) {
		::proto_ff::roletaidaoFemale* temp_roletaidaofemale_list = msg.add_roletaidaofemale_list();
		roletaidaoFemale_List[i].write_to_pbmsg(*temp_roletaidaofemale_list);
	}
}

void Sheet_roletaidaoFemale_s::read_from_pbmsg(const ::proto_ff::Sheet_roletaidaoFemale & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_roletaidaoFemale_s));
	roletaidaoFemale_List.SetSize(msg.roletaidaofemale_list_size() > roletaidaoFemale_List.GetMaxSize() ? roletaidaoFemale_List.GetMaxSize() : msg.roletaidaofemale_list_size());
	for(int32_t i = 0; i < (int32_t)roletaidaoFemale_List.GetSize(); ++i) {
		const ::proto_ff::roletaidaoFemale & temp_roletaidaofemale_list = msg.roletaidaofemale_list(i);
		roletaidaoFemale_List[i].read_from_pbmsg(temp_roletaidaofemale_list);
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