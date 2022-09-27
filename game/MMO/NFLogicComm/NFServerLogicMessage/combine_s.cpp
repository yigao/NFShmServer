#include "combine_s.h"

namespace proto_ff_s {

combinecitemneedMaterialDesc_s::combinecitemneedMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int combinecitemneedMaterialDesc_s::CreateInit() {
	id = (int64_t)0;
	return 0;
}

int combinecitemneedMaterialDesc_s::ResumeInit() {
	return 0;
}

void combinecitemneedMaterialDesc_s::write_to_pbmsg(::proto_ff::combinecitemneedMaterialDesc & msg) const {
	msg.set_id((int64_t)id);
}

void combinecitemneedMaterialDesc_s::read_from_pbmsg(const ::proto_ff::combinecitemneedMaterialDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct combinecitemneedMaterialDesc_s));
	id = msg.id();
}

combinecitem_s::combinecitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int combinecitem_s::CreateInit() {
	newItem = (int64_t)0;
	moneyType = (int32_t)0;
	price = (int32_t)0;
	huobiType = (int32_t)0;
	huobiPrice = (int32_t)0;
	probability = (int32_t)0;
	level = (int32_t)0;
	floor = (int32_t)0;
	return 0;
}

int combinecitem_s::ResumeInit() {
	return 0;
}

void combinecitem_s::write_to_pbmsg(::proto_ff::combinecitem & msg) const {
	msg.set_newitem((int64_t)newItem);
	msg.set_moneytype((int32_t)moneyType);
	msg.set_price((int32_t)price);
	msg.set_huobitype((int32_t)huobiType);
	msg.set_huobiprice((int32_t)huobiPrice);
	msg.set_probability((int32_t)probability);
	msg.set_level((int32_t)level);
	msg.set_floor((int32_t)floor);
	for(int32_t i = 0; i < (int32_t)needMaterial.GetSize() && i < needMaterial.GetMaxSize(); ++i) {
		::proto_ff::combinecitemneedMaterialDesc* temp_needmaterial = msg.add_needmaterial();
		needMaterial[i].write_to_pbmsg(*temp_needmaterial);
	}
}

void combinecitem_s::read_from_pbmsg(const ::proto_ff::combinecitem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct combinecitem_s));
	newItem = msg.newitem();
	moneyType = msg.moneytype();
	price = msg.price();
	huobiType = msg.huobitype();
	huobiPrice = msg.huobiprice();
	probability = msg.probability();
	level = msg.level();
	floor = msg.floor();
	needMaterial.SetSize(msg.needmaterial_size() > needMaterial.GetMaxSize() ? needMaterial.GetMaxSize() : msg.needmaterial_size());
	for(int32_t i = 0; i < (int32_t)needMaterial.GetSize(); ++i) {
		const ::proto_ff::combinecitemneedMaterialDesc & temp_needmaterial = msg.needmaterial(i);
		needMaterial[i].read_from_pbmsg(temp_needmaterial);
	}
}

Sheet_combinecitem_s::Sheet_combinecitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_combinecitem_s::CreateInit() {
	return 0;
}

int Sheet_combinecitem_s::ResumeInit() {
	return 0;
}

void Sheet_combinecitem_s::write_to_pbmsg(::proto_ff::Sheet_combinecitem & msg) const {
	for(int32_t i = 0; i < (int32_t)combinecitem_List.GetSize() && i < combinecitem_List.GetMaxSize(); ++i) {
		::proto_ff::combinecitem* temp_combinecitem_list = msg.add_combinecitem_list();
		combinecitem_List[i].write_to_pbmsg(*temp_combinecitem_list);
	}
}

void Sheet_combinecitem_s::read_from_pbmsg(const ::proto_ff::Sheet_combinecitem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_combinecitem_s));
	combinecitem_List.SetSize(msg.combinecitem_list_size() > combinecitem_List.GetMaxSize() ? combinecitem_List.GetMaxSize() : msg.combinecitem_list_size());
	for(int32_t i = 0; i < (int32_t)combinecitem_List.GetSize(); ++i) {
		const ::proto_ff::combinecitem & temp_combinecitem_list = msg.combinecitem_list(i);
		combinecitem_List[i].read_from_pbmsg(temp_combinecitem_list);
	}
}

combinestarUp_s::combinestarUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int combinestarUp_s::CreateInit() {
	newItem = (int64_t)0;
	equipMin = (int32_t)0;
	num = (int32_t)0;
	needMaterial_id = (int64_t)0;
	needMaterial_num = (int32_t)0;
	star = (int32_t)0;
	wearQuality = (int32_t)0;
	quality = (int32_t)0;
	sameProfession = (int32_t)0;
	probability = (int32_t)0;
	increase = (int32_t)0;
	return 0;
}

int combinestarUp_s::ResumeInit() {
	return 0;
}

void combinestarUp_s::write_to_pbmsg(::proto_ff::combinestarUp & msg) const {
	msg.set_newitem((int64_t)newItem);
	msg.set_equipmin((int32_t)equipMin);
	msg.set_num((int32_t)num);
	msg.set_needmaterial_id((int64_t)needMaterial_id);
	msg.set_needmaterial_num((int32_t)needMaterial_num);
	msg.set_star((int32_t)star);
	msg.set_wearquality((int32_t)wearQuality);
	msg.set_quality((int32_t)quality);
	msg.set_sameprofession((int32_t)sameProfession);
	msg.set_sameposition((const char*)samePosition.Get());
	msg.set_probability((int32_t)probability);
	msg.set_increase((int32_t)increase);
}

void combinestarUp_s::read_from_pbmsg(const ::proto_ff::combinestarUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct combinestarUp_s));
	newItem = msg.newitem();
	equipMin = msg.equipmin();
	num = msg.num();
	needMaterial_id = msg.needmaterial_id();
	needMaterial_num = msg.needmaterial_num();
	star = msg.star();
	wearQuality = msg.wearquality();
	quality = msg.quality();
	sameProfession = msg.sameprofession();
	samePosition.Copy(msg.sameposition());
	probability = msg.probability();
	increase = msg.increase();
}

Sheet_combinestarUp_s::Sheet_combinestarUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_combinestarUp_s::CreateInit() {
	return 0;
}

int Sheet_combinestarUp_s::ResumeInit() {
	return 0;
}

void Sheet_combinestarUp_s::write_to_pbmsg(::proto_ff::Sheet_combinestarUp & msg) const {
	for(int32_t i = 0; i < (int32_t)combinestarUp_List.GetSize() && i < combinestarUp_List.GetMaxSize(); ++i) {
		::proto_ff::combinestarUp* temp_combinestarup_list = msg.add_combinestarup_list();
		combinestarUp_List[i].write_to_pbmsg(*temp_combinestarup_list);
	}
}

void Sheet_combinestarUp_s::read_from_pbmsg(const ::proto_ff::Sheet_combinestarUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_combinestarUp_s));
	combinestarUp_List.SetSize(msg.combinestarup_list_size() > combinestarUp_List.GetMaxSize() ? combinestarUp_List.GetMaxSize() : msg.combinestarup_list_size());
	for(int32_t i = 0; i < (int32_t)combinestarUp_List.GetSize(); ++i) {
		const ::proto_ff::combinestarUp & temp_combinestarup_list = msg.combinestarup_list(i);
		combinestarUp_List[i].read_from_pbmsg(temp_combinestarup_list);
	}
}

combineitemUp_s::combineitemUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int combineitemUp_s::CreateInit() {
	newItem = (int64_t)0;
	moneyType = (int32_t)0;
	price = (int32_t)0;
	needMaterialID = (int64_t)0;
	needMaterialMin = (int32_t)0;
	needMaterialMan = (int32_t)0;
	probability = (int32_t)0;
	increase = (int32_t)0;
	return 0;
}

int combineitemUp_s::ResumeInit() {
	return 0;
}

void combineitemUp_s::write_to_pbmsg(::proto_ff::combineitemUp & msg) const {
	msg.set_newitem((int64_t)newItem);
	msg.set_moneytype((int32_t)moneyType);
	msg.set_price((int32_t)price);
	msg.set_needmaterialid((int64_t)needMaterialID);
	msg.set_needmaterialmin((int32_t)needMaterialMin);
	msg.set_needmaterialman((int32_t)needMaterialMan);
	msg.set_probability((int32_t)probability);
	msg.set_increase((int32_t)increase);
}

void combineitemUp_s::read_from_pbmsg(const ::proto_ff::combineitemUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct combineitemUp_s));
	newItem = msg.newitem();
	moneyType = msg.moneytype();
	price = msg.price();
	needMaterialID = msg.needmaterialid();
	needMaterialMin = msg.needmaterialmin();
	needMaterialMan = msg.needmaterialman();
	probability = msg.probability();
	increase = msg.increase();
}

Sheet_combineitemUp_s::Sheet_combineitemUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_combineitemUp_s::CreateInit() {
	return 0;
}

int Sheet_combineitemUp_s::ResumeInit() {
	return 0;
}

void Sheet_combineitemUp_s::write_to_pbmsg(::proto_ff::Sheet_combineitemUp & msg) const {
	for(int32_t i = 0; i < (int32_t)combineitemUp_List.GetSize() && i < combineitemUp_List.GetMaxSize(); ++i) {
		::proto_ff::combineitemUp* temp_combineitemup_list = msg.add_combineitemup_list();
		combineitemUp_List[i].write_to_pbmsg(*temp_combineitemup_list);
	}
}

void Sheet_combineitemUp_s::read_from_pbmsg(const ::proto_ff::Sheet_combineitemUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_combineitemUp_s));
	combineitemUp_List.SetSize(msg.combineitemup_list_size() > combineitemUp_List.GetMaxSize() ? combineitemUp_List.GetMaxSize() : msg.combineitemup_list_size());
	for(int32_t i = 0; i < (int32_t)combineitemUp_List.GetSize(); ++i) {
		const ::proto_ff::combineitemUp & temp_combineitemup_list = msg.combineitemup_list(i);
		combineitemUp_List[i].read_from_pbmsg(temp_combineitemup_list);
	}
}

combinerankUp_s::combinerankUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int combinerankUp_s::CreateInit() {
	newItem = (int64_t)0;
	num = (int32_t)0;
	needMaterial_id = (int64_t)0;
	needMaterial_num = (int32_t)0;
	star = (int32_t)0;
	wearQuality = (int32_t)0;
	quality = (int32_t)0;
	sameProfession = (int32_t)0;
	probability = (int32_t)0;
	return 0;
}

int combinerankUp_s::ResumeInit() {
	return 0;
}

void combinerankUp_s::write_to_pbmsg(::proto_ff::combinerankUp & msg) const {
	msg.set_newitem((int64_t)newItem);
	msg.set_num((int32_t)num);
	msg.set_needmaterial_id((int64_t)needMaterial_id);
	msg.set_needmaterial_num((int32_t)needMaterial_num);
	msg.set_star((int32_t)star);
	msg.set_wearquality((int32_t)wearQuality);
	msg.set_quality((int32_t)quality);
	msg.set_sameprofession((int32_t)sameProfession);
	msg.set_sameposition((const char*)samePosition.Get());
	msg.set_probability((int32_t)probability);
}

void combinerankUp_s::read_from_pbmsg(const ::proto_ff::combinerankUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct combinerankUp_s));
	newItem = msg.newitem();
	num = msg.num();
	needMaterial_id = msg.needmaterial_id();
	needMaterial_num = msg.needmaterial_num();
	star = msg.star();
	wearQuality = msg.wearquality();
	quality = msg.quality();
	sameProfession = msg.sameprofession();
	samePosition.Copy(msg.sameposition());
	probability = msg.probability();
}

Sheet_combinerankUp_s::Sheet_combinerankUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_combinerankUp_s::CreateInit() {
	return 0;
}

int Sheet_combinerankUp_s::ResumeInit() {
	return 0;
}

void Sheet_combinerankUp_s::write_to_pbmsg(::proto_ff::Sheet_combinerankUp & msg) const {
	for(int32_t i = 0; i < (int32_t)combinerankUp_List.GetSize() && i < combinerankUp_List.GetMaxSize(); ++i) {
		::proto_ff::combinerankUp* temp_combinerankup_list = msg.add_combinerankup_list();
		combinerankUp_List[i].write_to_pbmsg(*temp_combinerankup_list);
	}
}

void Sheet_combinerankUp_s::read_from_pbmsg(const ::proto_ff::Sheet_combinerankUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_combinerankUp_s));
	combinerankUp_List.SetSize(msg.combinerankup_list_size() > combinerankUp_List.GetMaxSize() ? combinerankUp_List.GetMaxSize() : msg.combinerankup_list_size());
	for(int32_t i = 0; i < (int32_t)combinerankUp_List.GetSize(); ++i) {
		const ::proto_ff::combinerankUp & temp_combinerankup_list = msg.combinerankup_list(i);
		combinerankUp_List[i].read_from_pbmsg(temp_combinerankup_list);
	}
}

combinequalityUp_s::combinequalityUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int combinequalityUp_s::CreateInit() {
	newItem = (int64_t)0;
	num = (int32_t)0;
	needEqup_num = (int32_t)0;
	star = (int32_t)0;
	wearQuality = (int32_t)0;
	quality = (int32_t)0;
	sameProfession = (int32_t)0;
	probability = (int32_t)0;
	costType = (int32_t)0;
	bindJewelCost = (int32_t)0;
	return 0;
}

int combinequalityUp_s::ResumeInit() {
	return 0;
}

void combinequalityUp_s::write_to_pbmsg(::proto_ff::combinequalityUp & msg) const {
	msg.set_newitem((int64_t)newItem);
	msg.set_num((int32_t)num);
	msg.set_needequp_num((int32_t)needEqup_num);
	msg.set_star((int32_t)star);
	msg.set_wearquality((int32_t)wearQuality);
	msg.set_quality((int32_t)quality);
	msg.set_sameprofession((int32_t)sameProfession);
	msg.set_sameposition((const char*)samePosition.Get());
	msg.set_probability((int32_t)probability);
	msg.set_costtype((int32_t)costType);
	msg.set_bindjewelcost((int32_t)bindJewelCost);
	for(int32_t i = 0; i < (int32_t)needEqup_id.GetSize() && i < needEqup_id.GetMaxSize(); ++i) {
		msg.add_needequp_id((const char*)needEqup_id[i].Get());
	}
	for(int32_t i = 0; i < (int32_t)needMaterial_num.GetSize() && i < needMaterial_num.GetMaxSize(); ++i) {
		msg.add_needmaterial_num((int32_t)needMaterial_num[i]);
	}
	for(int32_t i = 0; i < (int32_t)needMaterial_id.GetSize() && i < needMaterial_id.GetMaxSize(); ++i) {
		msg.add_needmaterial_id((int64_t)needMaterial_id[i]);
	}
}

void combinequalityUp_s::read_from_pbmsg(const ::proto_ff::combinequalityUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct combinequalityUp_s));
	newItem = msg.newitem();
	num = msg.num();
	needEqup_num = msg.needequp_num();
	star = msg.star();
	wearQuality = msg.wearquality();
	quality = msg.quality();
	sameProfession = msg.sameprofession();
	samePosition.Copy(msg.sameposition());
	probability = msg.probability();
	costType = msg.costtype();
	bindJewelCost = msg.bindjewelcost();
	needEqup_id.SetSize(msg.needequp_id_size() > needEqup_id.GetMaxSize() ? needEqup_id.GetMaxSize() : msg.needequp_id_size());
	for(int32_t i = 0; i < (int32_t)needEqup_id.GetSize(); ++i) {
		needEqup_id[i].Copy(msg.needequp_id(i));
	}
	needMaterial_num.SetSize(msg.needmaterial_num_size() > needMaterial_num.GetMaxSize() ? needMaterial_num.GetMaxSize() : msg.needmaterial_num_size());
	for(int32_t i = 0; i < (int32_t)needMaterial_num.GetSize(); ++i) {
		needMaterial_num[i] = msg.needmaterial_num(i);
	}
	needMaterial_id.SetSize(msg.needmaterial_id_size() > needMaterial_id.GetMaxSize() ? needMaterial_id.GetMaxSize() : msg.needmaterial_id_size());
	for(int32_t i = 0; i < (int32_t)needMaterial_id.GetSize(); ++i) {
		needMaterial_id[i] = msg.needmaterial_id(i);
	}
}

Sheet_combinequalityUp_s::Sheet_combinequalityUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_combinequalityUp_s::CreateInit() {
	return 0;
}

int Sheet_combinequalityUp_s::ResumeInit() {
	return 0;
}

void Sheet_combinequalityUp_s::write_to_pbmsg(::proto_ff::Sheet_combinequalityUp & msg) const {
	for(int32_t i = 0; i < (int32_t)combinequalityUp_List.GetSize() && i < combinequalityUp_List.GetMaxSize(); ++i) {
		::proto_ff::combinequalityUp* temp_combinequalityup_list = msg.add_combinequalityup_list();
		combinequalityUp_List[i].write_to_pbmsg(*temp_combinequalityup_list);
	}
}

void Sheet_combinequalityUp_s::read_from_pbmsg(const ::proto_ff::Sheet_combinequalityUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_combinequalityUp_s));
	combinequalityUp_List.SetSize(msg.combinequalityup_list_size() > combinequalityUp_List.GetMaxSize() ? combinequalityUp_List.GetMaxSize() : msg.combinequalityup_list_size());
	for(int32_t i = 0; i < (int32_t)combinequalityUp_List.GetSize(); ++i) {
		const ::proto_ff::combinequalityUp & temp_combinequalityup_list = msg.combinequalityup_list(i);
		combinequalityUp_List[i].read_from_pbmsg(temp_combinequalityup_list);
	}
}

}