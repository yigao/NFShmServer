#include "manor_s.h"

namespace proto_ff_s {

manorconstants_s::manorconstants_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manorconstants_s::CreateInit() {
	ID = (int32_t)0;
	valuedata = (int64_t)0;
	return 0;
}

int manorconstants_s::ResumeInit() {
	return 0;
}

void manorconstants_s::write_to_pbmsg(::proto_ff::manorconstants & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_valuedata((int64_t)valuedata);
	msg.set_stringdata((const char*)stringdata.Get());
}

void manorconstants_s::read_from_pbmsg(const ::proto_ff::manorconstants & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manorconstants_s));
	ID = msg.id();
	valuedata = msg.valuedata();
	stringdata.Copy(msg.stringdata());
}

Sheet_manorconstants_s::Sheet_manorconstants_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_manorconstants_s::CreateInit() {
	return 0;
}

int Sheet_manorconstants_s::ResumeInit() {
	return 0;
}

void Sheet_manorconstants_s::write_to_pbmsg(::proto_ff::Sheet_manorconstants & msg) const {
	for(int32_t i = 0; i < (int32_t)manorconstants_List.GetSize() && i < manorconstants_List.GetMaxSize(); ++i) {
		::proto_ff::manorconstants* temp_manorconstants_list = msg.add_manorconstants_list();
		manorconstants_List[i].write_to_pbmsg(*temp_manorconstants_list);
	}
}

void Sheet_manorconstants_s::read_from_pbmsg(const ::proto_ff::Sheet_manorconstants & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_manorconstants_s));
	manorconstants_List.SetSize(msg.manorconstants_list_size() > manorconstants_List.GetMaxSize() ? manorconstants_List.GetMaxSize() : msg.manorconstants_list_size());
	for(int32_t i = 0; i < (int32_t)manorconstants_List.GetSize(); ++i) {
		const ::proto_ff::manorconstants & temp_manorconstants_list = msg.manorconstants_list(i);
		manorconstants_List[i].read_from_pbmsg(temp_manorconstants_list);
	}
}

manoritemCost_s::manoritemCost_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manoritemCost_s::CreateInit() {
	itemId = (int64_t)0;
	useFor = (int32_t)0;
	itemValue = (int32_t)0;
	backType = (int32_t)0;
	backValue = (int32_t)0;
	return 0;
}

int manoritemCost_s::ResumeInit() {
	return 0;
}

void manoritemCost_s::write_to_pbmsg(::proto_ff::manoritemCost & msg) const {
	msg.set_itemid((int64_t)itemId);
	msg.set_usefor((int32_t)useFor);
	msg.set_itemvalue((int32_t)itemValue);
	msg.set_backtype((int32_t)backType);
	msg.set_backvalue((int32_t)backValue);
}

void manoritemCost_s::read_from_pbmsg(const ::proto_ff::manoritemCost & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manoritemCost_s));
	itemId = msg.itemid();
	useFor = msg.usefor();
	itemValue = msg.itemvalue();
	backType = msg.backtype();
	backValue = msg.backvalue();
}

Sheet_manoritemCost_s::Sheet_manoritemCost_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_manoritemCost_s::CreateInit() {
	return 0;
}

int Sheet_manoritemCost_s::ResumeInit() {
	return 0;
}

void Sheet_manoritemCost_s::write_to_pbmsg(::proto_ff::Sheet_manoritemCost & msg) const {
	for(int32_t i = 0; i < (int32_t)manoritemCost_List.GetSize() && i < manoritemCost_List.GetMaxSize(); ++i) {
		::proto_ff::manoritemCost* temp_manoritemcost_list = msg.add_manoritemcost_list();
		manoritemCost_List[i].write_to_pbmsg(*temp_manoritemcost_list);
	}
}

void Sheet_manoritemCost_s::read_from_pbmsg(const ::proto_ff::Sheet_manoritemCost & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_manoritemCost_s));
	manoritemCost_List.SetSize(msg.manoritemcost_list_size() > manoritemCost_List.GetMaxSize() ? manoritemCost_List.GetMaxSize() : msg.manoritemcost_list_size());
	for(int32_t i = 0; i < (int32_t)manoritemCost_List.GetSize(); ++i) {
		const ::proto_ff::manoritemCost & temp_manoritemcost_list = msg.manoritemcost_list(i);
		manoritemCost_List[i].read_from_pbmsg(temp_manoritemcost_list);
	}
}

manormanorlistinitialMonsterDesc_s::manormanorlistinitialMonsterDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manormanorlistinitialMonsterDesc_s::CreateInit() {
	Num = (int32_t)0;
	return 0;
}

int manormanorlistinitialMonsterDesc_s::ResumeInit() {
	return 0;
}

void manormanorlistinitialMonsterDesc_s::write_to_pbmsg(::proto_ff::manormanorlistinitialMonsterDesc & msg) const {
	msg.set_num((int32_t)Num);
}

void manormanorlistinitialMonsterDesc_s::read_from_pbmsg(const ::proto_ff::manormanorlistinitialMonsterDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manormanorlistinitialMonsterDesc_s));
	Num = msg.num();
}

manormanorlist_s::manormanorlist_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manormanorlist_s::CreateInit() {
	ID = (int64_t)0;
	manorType = (int32_t)0;
	attackBuildLevel = (int32_t)0;
	coreBaseLevel = (int32_t)0;
	mapId = (int64_t)0;
	productId = (int32_t)0;
	coreBasePath = (int64_t)0;
	coreBaseMaxLevel = (int32_t)0;
	coreBaseId = (int64_t)0;
	hatcheryBasePath = (int64_t)0;
	hatcheryBaseMaxLevel = (int32_t)0;
	hatcheryBaseId = (int64_t)0;
	buffBasePath = (int64_t)0;
	buffBaseMaxLevel = (int32_t)0;
	buffBaseId = (int64_t)0;
	shopPath = (int64_t)0;
	shopMaxLevel = (int32_t)0;
	shopId = (int64_t)0;
	crossGateBasePath = (int64_t)0;
	crossGateMaxLevel = (int32_t)0;
	crossGateBaseId = (int64_t)0;
	return 0;
}

int manormanorlist_s::ResumeInit() {
	return 0;
}

void manormanorlist_s::write_to_pbmsg(::proto_ff::manormanorlist & msg) const {
	msg.set_id((int64_t)ID);
	msg.set_name((const char*)name.Get());
	msg.set_manortype((int32_t)manorType);
	msg.set_attackbuildlevel((int32_t)attackBuildLevel);
	msg.set_corebaselevel((int32_t)coreBaseLevel);
	msg.set_mapid((int64_t)mapId);
	msg.set_productid((int32_t)productId);
	msg.set_corebasepath((int64_t)coreBasePath);
	msg.set_corebasemaxlevel((int32_t)coreBaseMaxLevel);
	msg.set_corebaseid((int64_t)coreBaseId);
	msg.set_hatcherybasepath((int64_t)hatcheryBasePath);
	msg.set_hatcherybasemaxlevel((int32_t)hatcheryBaseMaxLevel);
	msg.set_hatcherybaseid((int64_t)hatcheryBaseId);
	msg.set_buffbasepath((int64_t)buffBasePath);
	msg.set_buffbasemaxlevel((int32_t)buffBaseMaxLevel);
	msg.set_buffbaseid((int64_t)buffBaseId);
	msg.set_shoppath((int64_t)shopPath);
	msg.set_shopmaxlevel((int32_t)shopMaxLevel);
	msg.set_shopid((int64_t)shopId);
	msg.set_crossgatebasepath((int64_t)crossGateBasePath);
	msg.set_crossgatemaxlevel((int32_t)crossGateMaxLevel);
	msg.set_crossgatebaseid((int64_t)crossGateBaseId);
	for(int32_t i = 0; i < (int32_t)initialMonster.GetSize() && i < initialMonster.GetMaxSize(); ++i) {
		::proto_ff::manormanorlistinitialMonsterDesc* temp_initialmonster = msg.add_initialmonster();
		initialMonster[i].write_to_pbmsg(*temp_initialmonster);
	}
	for(int32_t i = 0; i < (int32_t)patBeastAttack_Path.GetSize() && i < patBeastAttack_Path.GetMaxSize(); ++i) {
		msg.add_patbeastattack_path((int64_t)patBeastAttack_Path[i]);
	}
	for(int32_t i = 0; i < (int32_t)initialMonster_Id.GetSize() && i < initialMonster_Id.GetMaxSize(); ++i) {
		msg.add_initialmonster_id((int64_t)initialMonster_Id[i]);
	}
}

void manormanorlist_s::read_from_pbmsg(const ::proto_ff::manormanorlist & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manormanorlist_s));
	ID = msg.id();
	name.Copy(msg.name());
	manorType = msg.manortype();
	attackBuildLevel = msg.attackbuildlevel();
	coreBaseLevel = msg.corebaselevel();
	mapId = msg.mapid();
	productId = msg.productid();
	coreBasePath = msg.corebasepath();
	coreBaseMaxLevel = msg.corebasemaxlevel();
	coreBaseId = msg.corebaseid();
	hatcheryBasePath = msg.hatcherybasepath();
	hatcheryBaseMaxLevel = msg.hatcherybasemaxlevel();
	hatcheryBaseId = msg.hatcherybaseid();
	buffBasePath = msg.buffbasepath();
	buffBaseMaxLevel = msg.buffbasemaxlevel();
	buffBaseId = msg.buffbaseid();
	shopPath = msg.shoppath();
	shopMaxLevel = msg.shopmaxlevel();
	shopId = msg.shopid();
	crossGateBasePath = msg.crossgatebasepath();
	crossGateMaxLevel = msg.crossgatemaxlevel();
	crossGateBaseId = msg.crossgatebaseid();
	initialMonster.SetSize(msg.initialmonster_size() > initialMonster.GetMaxSize() ? initialMonster.GetMaxSize() : msg.initialmonster_size());
	for(int32_t i = 0; i < (int32_t)initialMonster.GetSize(); ++i) {
		const ::proto_ff::manormanorlistinitialMonsterDesc & temp_initialmonster = msg.initialmonster(i);
		initialMonster[i].read_from_pbmsg(temp_initialmonster);
	}
	patBeastAttack_Path.SetSize(msg.patbeastattack_path_size() > patBeastAttack_Path.GetMaxSize() ? patBeastAttack_Path.GetMaxSize() : msg.patbeastattack_path_size());
	for(int32_t i = 0; i < (int32_t)patBeastAttack_Path.GetSize(); ++i) {
		patBeastAttack_Path[i] = msg.patbeastattack_path(i);
	}
	initialMonster_Id.SetSize(msg.initialmonster_id_size() > initialMonster_Id.GetMaxSize() ? initialMonster_Id.GetMaxSize() : msg.initialmonster_id_size());
	for(int32_t i = 0; i < (int32_t)initialMonster_Id.GetSize(); ++i) {
		initialMonster_Id[i] = msg.initialmonster_id(i);
	}
}

Sheet_manormanorlist_s::Sheet_manormanorlist_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_manormanorlist_s::CreateInit() {
	return 0;
}

int Sheet_manormanorlist_s::ResumeInit() {
	return 0;
}

void Sheet_manormanorlist_s::write_to_pbmsg(::proto_ff::Sheet_manormanorlist & msg) const {
	for(int32_t i = 0; i < (int32_t)manormanorlist_List.GetSize() && i < manormanorlist_List.GetMaxSize(); ++i) {
		::proto_ff::manormanorlist* temp_manormanorlist_list = msg.add_manormanorlist_list();
		manormanorlist_List[i].write_to_pbmsg(*temp_manormanorlist_list);
	}
}

void Sheet_manormanorlist_s::read_from_pbmsg(const ::proto_ff::Sheet_manormanorlist & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_manormanorlist_s));
	manormanorlist_List.SetSize(msg.manormanorlist_list_size() > manormanorlist_List.GetMaxSize() ? manormanorlist_List.GetMaxSize() : msg.manormanorlist_list_size());
	for(int32_t i = 0; i < (int32_t)manormanorlist_List.GetSize(); ++i) {
		const ::proto_ff::manormanorlist & temp_manormanorlist_list = msg.manormanorlist_list(i);
		manormanorlist_List[i].read_from_pbmsg(temp_manormanorlist_list);
	}
}

manorproductproductDesc_s::manorproductproductDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manorproductproductDesc_s::CreateInit() {
	Num = (int32_t)0;
	buildLevle = (int32_t)0;
	return 0;
}

int manorproductproductDesc_s::ResumeInit() {
	return 0;
}

void manorproductproductDesc_s::write_to_pbmsg(::proto_ff::manorproductproductDesc & msg) const {
	msg.set_num((int32_t)Num);
	msg.set_buildlevle((int32_t)buildLevle);
}

void manorproductproductDesc_s::read_from_pbmsg(const ::proto_ff::manorproductproductDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manorproductproductDesc_s));
	Num = msg.num();
	buildLevle = msg.buildlevle();
}

manorproduct_s::manorproduct_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manorproduct_s::CreateInit() {
	ID = (int32_t)0;
	return 0;
}

int manorproduct_s::ResumeInit() {
	return 0;
}

void manorproduct_s::write_to_pbmsg(::proto_ff::manorproduct & msg) const {
	msg.set_id((int32_t)ID);
	for(int32_t i = 0; i < (int32_t)product_Item.GetSize() && i < product_Item.GetMaxSize(); ++i) {
		msg.add_product_item((int64_t)product_Item[i]);
	}
	for(int32_t i = 0; i < (int32_t)product.GetSize() && i < product.GetMaxSize(); ++i) {
		::proto_ff::manorproductproductDesc* temp_product = msg.add_product();
		product[i].write_to_pbmsg(*temp_product);
	}
}

void manorproduct_s::read_from_pbmsg(const ::proto_ff::manorproduct & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manorproduct_s));
	ID = msg.id();
	product_Item.SetSize(msg.product_item_size() > product_Item.GetMaxSize() ? product_Item.GetMaxSize() : msg.product_item_size());
	for(int32_t i = 0; i < (int32_t)product_Item.GetSize(); ++i) {
		product_Item[i] = msg.product_item(i);
	}
	product.SetSize(msg.product_size() > product.GetMaxSize() ? product.GetMaxSize() : msg.product_size());
	for(int32_t i = 0; i < (int32_t)product.GetSize(); ++i) {
		const ::proto_ff::manorproductproductDesc & temp_product = msg.product(i);
		product[i].read_from_pbmsg(temp_product);
	}
}

Sheet_manorproduct_s::Sheet_manorproduct_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_manorproduct_s::CreateInit() {
	return 0;
}

int Sheet_manorproduct_s::ResumeInit() {
	return 0;
}

void Sheet_manorproduct_s::write_to_pbmsg(::proto_ff::Sheet_manorproduct & msg) const {
	for(int32_t i = 0; i < (int32_t)manorproduct_List.GetSize() && i < manorproduct_List.GetMaxSize(); ++i) {
		::proto_ff::manorproduct* temp_manorproduct_list = msg.add_manorproduct_list();
		manorproduct_List[i].write_to_pbmsg(*temp_manorproduct_list);
	}
}

void Sheet_manorproduct_s::read_from_pbmsg(const ::proto_ff::Sheet_manorproduct & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_manorproduct_s));
	manorproduct_List.SetSize(msg.manorproduct_list_size() > manorproduct_List.GetMaxSize() ? manorproduct_List.GetMaxSize() : msg.manorproduct_list_size());
	for(int32_t i = 0; i < (int32_t)manorproduct_List.GetSize(); ++i) {
		const ::proto_ff::manorproduct & temp_manorproduct_list = msg.manorproduct_list(i);
		manorproduct_List[i].read_from_pbmsg(temp_manorproduct_list);
	}
}

manorbuild_s::manorbuild_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manorbuild_s::CreateInit() {
	ID = (int64_t)0;
	buildingType = (int32_t)0;
	monsterId = (int64_t)0;
	return 0;
}

int manorbuild_s::ResumeInit() {
	return 0;
}

void manorbuild_s::write_to_pbmsg(::proto_ff::manorbuild & msg) const {
	msg.set_id((int64_t)ID);
	msg.set_name((const char*)name.Get());
	msg.set_buildingtype((int32_t)buildingType);
	msg.set_monsterid((int64_t)monsterId);
	msg.set_buildingvalue((const char*)buildingvalue.Get());
	msg.set_buildingaddbuff((const char*)buildingAddBuff.Get());
	msg.set_buildingconsume((const char*)buildingConsume.Get());
}

void manorbuild_s::read_from_pbmsg(const ::proto_ff::manorbuild & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manorbuild_s));
	ID = msg.id();
	name.Copy(msg.name());
	buildingType = msg.buildingtype();
	monsterId = msg.monsterid();
	buildingvalue.Copy(msg.buildingvalue());
	buildingAddBuff.Copy(msg.buildingaddbuff());
	buildingConsume.Copy(msg.buildingconsume());
}

Sheet_manorbuild_s::Sheet_manorbuild_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_manorbuild_s::CreateInit() {
	return 0;
}

int Sheet_manorbuild_s::ResumeInit() {
	return 0;
}

void Sheet_manorbuild_s::write_to_pbmsg(::proto_ff::Sheet_manorbuild & msg) const {
	for(int32_t i = 0; i < (int32_t)manorbuild_List.GetSize() && i < manorbuild_List.GetMaxSize(); ++i) {
		::proto_ff::manorbuild* temp_manorbuild_list = msg.add_manorbuild_list();
		manorbuild_List[i].write_to_pbmsg(*temp_manorbuild_list);
	}
}

void Sheet_manorbuild_s::read_from_pbmsg(const ::proto_ff::Sheet_manorbuild & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_manorbuild_s));
	manorbuild_List.SetSize(msg.manorbuild_list_size() > manorbuild_List.GetMaxSize() ? manorbuild_List.GetMaxSize() : msg.manorbuild_list_size());
	for(int32_t i = 0; i < (int32_t)manorbuild_List.GetSize(); ++i) {
		const ::proto_ff::manorbuild & temp_manorbuild_list = msg.manorbuild_list(i);
		manorbuild_List[i].read_from_pbmsg(temp_manorbuild_list);
	}
}

manorbuildUpbuildDesc_s::manorbuildUpbuildDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manorbuildUpbuildDesc_s::CreateInit() {
	exp = (int32_t)0;
	return 0;
}

int manorbuildUpbuildDesc_s::ResumeInit() {
	return 0;
}

void manorbuildUpbuildDesc_s::write_to_pbmsg(::proto_ff::manorbuildUpbuildDesc & msg) const {
	msg.set_exp((int32_t)exp);
}

void manorbuildUpbuildDesc_s::read_from_pbmsg(const ::proto_ff::manorbuildUpbuildDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manorbuildUpbuildDesc_s));
	exp = msg.exp();
}

manorbuildUp_s::manorbuildUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manorbuildUp_s::CreateInit() {
	level = (int32_t)0;
	return 0;
}

int manorbuildUp_s::ResumeInit() {
	return 0;
}

void manorbuildUp_s::write_to_pbmsg(::proto_ff::manorbuildUp & msg) const {
	msg.set_level((int32_t)level);
	for(int32_t i = 0; i < (int32_t)build_type.GetSize() && i < build_type.GetMaxSize(); ++i) {
		msg.add_build_type((int32_t)build_type[i]);
	}
	for(int32_t i = 0; i < (int32_t)build.GetSize() && i < build.GetMaxSize(); ++i) {
		::proto_ff::manorbuildUpbuildDesc* temp_build = msg.add_build();
		build[i].write_to_pbmsg(*temp_build);
	}
}

void manorbuildUp_s::read_from_pbmsg(const ::proto_ff::manorbuildUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manorbuildUp_s));
	level = msg.level();
	build_type.SetSize(msg.build_type_size() > build_type.GetMaxSize() ? build_type.GetMaxSize() : msg.build_type_size());
	for(int32_t i = 0; i < (int32_t)build_type.GetSize(); ++i) {
		build_type[i] = msg.build_type(i);
	}
	build.SetSize(msg.build_size() > build.GetMaxSize() ? build.GetMaxSize() : msg.build_size());
	for(int32_t i = 0; i < (int32_t)build.GetSize(); ++i) {
		const ::proto_ff::manorbuildUpbuildDesc & temp_build = msg.build(i);
		build[i].read_from_pbmsg(temp_build);
	}
}

Sheet_manorbuildUp_s::Sheet_manorbuildUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_manorbuildUp_s::CreateInit() {
	return 0;
}

int Sheet_manorbuildUp_s::ResumeInit() {
	return 0;
}

void Sheet_manorbuildUp_s::write_to_pbmsg(::proto_ff::Sheet_manorbuildUp & msg) const {
	for(int32_t i = 0; i < (int32_t)manorbuildUp_List.GetSize() && i < manorbuildUp_List.GetMaxSize(); ++i) {
		::proto_ff::manorbuildUp* temp_manorbuildup_list = msg.add_manorbuildup_list();
		manorbuildUp_List[i].write_to_pbmsg(*temp_manorbuildup_list);
	}
}

void Sheet_manorbuildUp_s::read_from_pbmsg(const ::proto_ff::Sheet_manorbuildUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_manorbuildUp_s));
	manorbuildUp_List.SetSize(msg.manorbuildup_list_size() > manorbuildUp_List.GetMaxSize() ? manorbuildUp_List.GetMaxSize() : msg.manorbuildup_list_size());
	for(int32_t i = 0; i < (int32_t)manorbuildUp_List.GetSize(); ++i) {
		const ::proto_ff::manorbuildUp & temp_manorbuildup_list = msg.manorbuildup_list(i);
		manorbuildUp_List[i].read_from_pbmsg(temp_manorbuildup_list);
	}
}

manoregg_s::manoregg_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manoregg_s::CreateInit() {
	eggItemID = (int64_t)0;
	incubationTime = (int32_t)0;
	return 0;
}

int manoregg_s::ResumeInit() {
	return 0;
}

void manoregg_s::write_to_pbmsg(::proto_ff::manoregg & msg) const {
	msg.set_eggitemid((int64_t)eggItemID);
	msg.set_incubationtime((int32_t)incubationTime);
	msg.set_patbeastsprobab((const char*)patBeastsProbab.Get());
}

void manoregg_s::read_from_pbmsg(const ::proto_ff::manoregg & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manoregg_s));
	eggItemID = msg.eggitemid();
	incubationTime = msg.incubationtime();
	patBeastsProbab.Copy(msg.patbeastsprobab());
}

Sheet_manoregg_s::Sheet_manoregg_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_manoregg_s::CreateInit() {
	return 0;
}

int Sheet_manoregg_s::ResumeInit() {
	return 0;
}

void Sheet_manoregg_s::write_to_pbmsg(::proto_ff::Sheet_manoregg & msg) const {
	for(int32_t i = 0; i < (int32_t)manoregg_List.GetSize() && i < manoregg_List.GetMaxSize(); ++i) {
		::proto_ff::manoregg* temp_manoregg_list = msg.add_manoregg_list();
		manoregg_List[i].write_to_pbmsg(*temp_manoregg_list);
	}
}

void Sheet_manoregg_s::read_from_pbmsg(const ::proto_ff::Sheet_manoregg & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_manoregg_s));
	manoregg_List.SetSize(msg.manoregg_list_size() > manoregg_List.GetMaxSize() ? manoregg_List.GetMaxSize() : msg.manoregg_list_size());
	for(int32_t i = 0; i < (int32_t)manoregg_List.GetSize(); ++i) {
		const ::proto_ff::manoregg & temp_manoregg_list = msg.manoregg_list(i);
		manoregg_List[i].read_from_pbmsg(temp_manoregg_list);
	}
}

manorpatBeast_s::manorpatBeast_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manorpatBeast_s::CreateInit() {
	Id = (int64_t)0;
	return 0;
}

int manorpatBeast_s::ResumeInit() {
	return 0;
}

void manorpatBeast_s::write_to_pbmsg(::proto_ff::manorpatBeast & msg) const {
	msg.set_id((int64_t)Id);
}

void manorpatBeast_s::read_from_pbmsg(const ::proto_ff::manorpatBeast & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manorpatBeast_s));
	Id = msg.id();
}

Sheet_manorpatBeast_s::Sheet_manorpatBeast_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_manorpatBeast_s::CreateInit() {
	return 0;
}

int Sheet_manorpatBeast_s::ResumeInit() {
	return 0;
}

void Sheet_manorpatBeast_s::write_to_pbmsg(::proto_ff::Sheet_manorpatBeast & msg) const {
	for(int32_t i = 0; i < (int32_t)manorpatBeast_List.GetSize() && i < manorpatBeast_List.GetMaxSize(); ++i) {
		::proto_ff::manorpatBeast* temp_manorpatbeast_list = msg.add_manorpatbeast_list();
		manorpatBeast_List[i].write_to_pbmsg(*temp_manorpatbeast_list);
	}
}

void Sheet_manorpatBeast_s::read_from_pbmsg(const ::proto_ff::Sheet_manorpatBeast & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_manorpatBeast_s));
	manorpatBeast_List.SetSize(msg.manorpatbeast_list_size() > manorpatBeast_List.GetMaxSize() ? manorpatBeast_List.GetMaxSize() : msg.manorpatbeast_list_size());
	for(int32_t i = 0; i < (int32_t)manorpatBeast_List.GetSize(); ++i) {
		const ::proto_ff::manorpatBeast & temp_manorpatbeast_list = msg.manorpatbeast_list(i);
		manorpatBeast_List[i].read_from_pbmsg(temp_manorpatbeast_list);
	}
}

manorpatBeastUP_s::manorpatBeastUP_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manorpatBeastUP_s::CreateInit() {
	level = (int32_t)0;
	exp = (int32_t)0;
	return 0;
}

int manorpatBeastUP_s::ResumeInit() {
	return 0;
}

void manorpatBeastUP_s::write_to_pbmsg(::proto_ff::manorpatBeastUP & msg) const {
	msg.set_level((int32_t)level);
	msg.set_exp((int32_t)exp);
}

void manorpatBeastUP_s::read_from_pbmsg(const ::proto_ff::manorpatBeastUP & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manorpatBeastUP_s));
	level = msg.level();
	exp = msg.exp();
}

Sheet_manorpatBeastUP_s::Sheet_manorpatBeastUP_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_manorpatBeastUP_s::CreateInit() {
	return 0;
}

int Sheet_manorpatBeastUP_s::ResumeInit() {
	return 0;
}

void Sheet_manorpatBeastUP_s::write_to_pbmsg(::proto_ff::Sheet_manorpatBeastUP & msg) const {
	for(int32_t i = 0; i < (int32_t)manorpatBeastUP_List.GetSize() && i < manorpatBeastUP_List.GetMaxSize(); ++i) {
		::proto_ff::manorpatBeastUP* temp_manorpatbeastup_list = msg.add_manorpatbeastup_list();
		manorpatBeastUP_List[i].write_to_pbmsg(*temp_manorpatbeastup_list);
	}
}

void Sheet_manorpatBeastUP_s::read_from_pbmsg(const ::proto_ff::Sheet_manorpatBeastUP & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_manorpatBeastUP_s));
	manorpatBeastUP_List.SetSize(msg.manorpatbeastup_list_size() > manorpatBeastUP_List.GetMaxSize() ? manorpatBeastUP_List.GetMaxSize() : msg.manorpatbeastup_list_size());
	for(int32_t i = 0; i < (int32_t)manorpatBeastUP_List.GetSize(); ++i) {
		const ::proto_ff::manorpatBeastUP & temp_manorpatbeastup_list = msg.manorpatbeastup_list(i);
		manorpatBeastUP_List[i].read_from_pbmsg(temp_manorpatbeastup_list);
	}
}

manorbuildBuff_s::manorbuildBuff_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manorbuildBuff_s::CreateInit() {
	levelSum = (int32_t)0;
	skillId = (int64_t)0;
	return 0;
}

int manorbuildBuff_s::ResumeInit() {
	return 0;
}

void manorbuildBuff_s::write_to_pbmsg(::proto_ff::manorbuildBuff & msg) const {
	msg.set_levelsum((int32_t)levelSum);
	msg.set_skillid((int64_t)skillId);
}

void manorbuildBuff_s::read_from_pbmsg(const ::proto_ff::manorbuildBuff & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manorbuildBuff_s));
	levelSum = msg.levelsum();
	skillId = msg.skillid();
}

Sheet_manorbuildBuff_s::Sheet_manorbuildBuff_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_manorbuildBuff_s::CreateInit() {
	return 0;
}

int Sheet_manorbuildBuff_s::ResumeInit() {
	return 0;
}

void Sheet_manorbuildBuff_s::write_to_pbmsg(::proto_ff::Sheet_manorbuildBuff & msg) const {
	for(int32_t i = 0; i < (int32_t)manorbuildBuff_List.GetSize() && i < manorbuildBuff_List.GetMaxSize(); ++i) {
		::proto_ff::manorbuildBuff* temp_manorbuildbuff_list = msg.add_manorbuildbuff_list();
		manorbuildBuff_List[i].write_to_pbmsg(*temp_manorbuildbuff_list);
	}
}

void Sheet_manorbuildBuff_s::read_from_pbmsg(const ::proto_ff::Sheet_manorbuildBuff & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_manorbuildBuff_s));
	manorbuildBuff_List.SetSize(msg.manorbuildbuff_list_size() > manorbuildBuff_List.GetMaxSize() ? manorbuildBuff_List.GetMaxSize() : msg.manorbuildbuff_list_size());
	for(int32_t i = 0; i < (int32_t)manorbuildBuff_List.GetSize(); ++i) {
		const ::proto_ff::manorbuildBuff & temp_manorbuildbuff_list = msg.manorbuildbuff_list(i);
		manorbuildBuff_List[i].read_from_pbmsg(temp_manorbuildbuff_list);
	}
}

manorshop_s::manorshop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manorshop_s::CreateInit() {
	ID = (int32_t)0;
	itemId = (int64_t)0;
	needShopLV = (int32_t)0;
	buyLimit = (int32_t)0;
	moneyCode = (int32_t)0;
	moneyType = (int64_t)0;
	Price = (int32_t)0;
	return 0;
}

int manorshop_s::ResumeInit() {
	return 0;
}

void manorshop_s::write_to_pbmsg(::proto_ff::manorshop & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_itemid((int64_t)itemId);
	msg.set_needshoplv((int32_t)needShopLV);
	msg.set_buylimit((int32_t)buyLimit);
	msg.set_moneycode((int32_t)moneyCode);
	msg.set_moneytype((int64_t)moneyType);
	msg.set_price((int32_t)Price);
}

void manorshop_s::read_from_pbmsg(const ::proto_ff::manorshop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manorshop_s));
	ID = msg.id();
	itemId = msg.itemid();
	needShopLV = msg.needshoplv();
	buyLimit = msg.buylimit();
	moneyCode = msg.moneycode();
	moneyType = msg.moneytype();
	Price = msg.price();
}

Sheet_manorshop_s::Sheet_manorshop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_manorshop_s::CreateInit() {
	return 0;
}

int Sheet_manorshop_s::ResumeInit() {
	return 0;
}

void Sheet_manorshop_s::write_to_pbmsg(::proto_ff::Sheet_manorshop & msg) const {
	for(int32_t i = 0; i < (int32_t)manorshop_List.GetSize() && i < manorshop_List.GetMaxSize(); ++i) {
		::proto_ff::manorshop* temp_manorshop_list = msg.add_manorshop_list();
		manorshop_List[i].write_to_pbmsg(*temp_manorshop_list);
	}
}

void Sheet_manorshop_s::read_from_pbmsg(const ::proto_ff::Sheet_manorshop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_manorshop_s));
	manorshop_List.SetSize(msg.manorshop_list_size() > manorshop_List.GetMaxSize() ? manorshop_List.GetMaxSize() : msg.manorshop_list_size());
	for(int32_t i = 0; i < (int32_t)manorshop_List.GetSize(); ++i) {
		const ::proto_ff::manorshop & temp_manorshop_list = msg.manorshop_list(i);
		manorshop_List[i].read_from_pbmsg(temp_manorshop_list);
	}
}

manorbuildAdd_s::manorbuildAdd_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manorbuildAdd_s::CreateInit() {
	levelSum = (int32_t)0;
	addRatio = (int32_t)0;
	return 0;
}

int manorbuildAdd_s::ResumeInit() {
	return 0;
}

void manorbuildAdd_s::write_to_pbmsg(::proto_ff::manorbuildAdd & msg) const {
	msg.set_levelsum((int32_t)levelSum);
	msg.set_addratio((int32_t)addRatio);
}

void manorbuildAdd_s::read_from_pbmsg(const ::proto_ff::manorbuildAdd & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manorbuildAdd_s));
	levelSum = msg.levelsum();
	addRatio = msg.addratio();
}

Sheet_manorbuildAdd_s::Sheet_manorbuildAdd_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_manorbuildAdd_s::CreateInit() {
	return 0;
}

int Sheet_manorbuildAdd_s::ResumeInit() {
	return 0;
}

void Sheet_manorbuildAdd_s::write_to_pbmsg(::proto_ff::Sheet_manorbuildAdd & msg) const {
	for(int32_t i = 0; i < (int32_t)manorbuildAdd_List.GetSize() && i < manorbuildAdd_List.GetMaxSize(); ++i) {
		::proto_ff::manorbuildAdd* temp_manorbuildadd_list = msg.add_manorbuildadd_list();
		manorbuildAdd_List[i].write_to_pbmsg(*temp_manorbuildadd_list);
	}
}

void Sheet_manorbuildAdd_s::read_from_pbmsg(const ::proto_ff::Sheet_manorbuildAdd & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_manorbuildAdd_s));
	manorbuildAdd_List.SetSize(msg.manorbuildadd_list_size() > manorbuildAdd_List.GetMaxSize() ? manorbuildAdd_List.GetMaxSize() : msg.manorbuildadd_list_size());
	for(int32_t i = 0; i < (int32_t)manorbuildAdd_List.GetSize(); ++i) {
		const ::proto_ff::manorbuildAdd & temp_manorbuildadd_list = msg.manorbuildadd_list(i);
		manorbuildAdd_List[i].read_from_pbmsg(temp_manorbuildadd_list);
	}
}

manorlog_s::manorlog_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int manorlog_s::CreateInit() {
	ID = (int32_t)0;
	return 0;
}

int manorlog_s::ResumeInit() {
	return 0;
}

void manorlog_s::write_to_pbmsg(::proto_ff::manorlog & msg) const {
	msg.set_id((int32_t)ID);
}

void manorlog_s::read_from_pbmsg(const ::proto_ff::manorlog & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct manorlog_s));
	ID = msg.id();
}

Sheet_manorlog_s::Sheet_manorlog_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_manorlog_s::CreateInit() {
	return 0;
}

int Sheet_manorlog_s::ResumeInit() {
	return 0;
}

void Sheet_manorlog_s::write_to_pbmsg(::proto_ff::Sheet_manorlog & msg) const {
	for(int32_t i = 0; i < (int32_t)manorlog_List.GetSize() && i < manorlog_List.GetMaxSize(); ++i) {
		::proto_ff::manorlog* temp_manorlog_list = msg.add_manorlog_list();
		manorlog_List[i].write_to_pbmsg(*temp_manorlog_list);
	}
}

void Sheet_manorlog_s::read_from_pbmsg(const ::proto_ff::Sheet_manorlog & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_manorlog_s));
	manorlog_List.SetSize(msg.manorlog_list_size() > manorlog_List.GetMaxSize() ? manorlog_List.GetMaxSize() : msg.manorlog_list_size());
	for(int32_t i = 0; i < (int32_t)manorlog_List.GetSize(); ++i) {
		const ::proto_ff::manorlog & temp_manorlog_list = msg.manorlog_list(i);
		manorlog_List[i].read_from_pbmsg(temp_manorlog_list);
	}
}

}