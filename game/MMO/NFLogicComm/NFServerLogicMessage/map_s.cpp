#include "map_s.h"

namespace proto_ff_s {

mapmap_s::mapmap_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int mapmap_s::CreateInit() {
	mapId = (int64_t)0;
	levelLimit = (int32_t)0;
	mapType = (int32_t)0;
	mapSubType = (int32_t)0;
	clearanceTime = (int32_t)0;
	mapPkmode = (int32_t)0;
	pklock = (int32_t)0;
	pk = (int32_t)0;
	killValue = (int32_t)0;
	BanGroup = (int32_t)0;
	reviveTime = (int32_t)0;
	mapWide = (int32_t)0;
	mapHeight = (int32_t)0;
	reviveSkill = (int64_t)0;
	reviveInPlaceType = (int32_t)0;
	isHangUp = (int32_t)0;
	itemDropType = (int32_t)0;
	linkOffLine = (int64_t)0;
	banOnHook = (int32_t)0;
	Rewait = (int32_t)0;
	REtime = (int32_t)0;
	HREBan = (int32_t)0;
	Retiered = (int32_t)0;
	REskillid = (int32_t)0;
	Reteimes = (int32_t)0;
	drivePoint = (int32_t)0;
	dieDP = (int32_t)0;
	timeDP = (int32_t)0;
	meditation = (int32_t)0;
	return 0;
}

int mapmap_s::ResumeInit() {
	return 0;
}

void mapmap_s::write_to_pbmsg(::proto_ff::mapmap & msg) const {
	msg.set_mapid((int64_t)mapId);
	msg.set_levellimit((int32_t)levelLimit);
	msg.set_advicelv((const char*)adviceLv.Get());
	msg.set_maptype((int32_t)mapType);
	msg.set_mapsubtype((int32_t)mapSubType);
	msg.set_clearancetime((int32_t)clearanceTime);
	msg.set_mappkmode((int32_t)mapPkmode);
	msg.set_pklock((int32_t)pklock);
	msg.set_pk((int32_t)pk);
	msg.set_killvalue((int32_t)killValue);
	msg.set_bangroup((int32_t)BanGroup);
	msg.set_revivetime((int32_t)reviveTime);
	msg.set_mapwide((int32_t)mapWide);
	msg.set_mapheight((int32_t)mapHeight);
	msg.set_mapresources((const char*)mapResources.Get());
	msg.set_reviveskill((int64_t)reviveSkill);
	msg.set_reviveinplacetype((int32_t)reviveInPlaceType);
	msg.set_ishangup((int32_t)isHangUp);
	msg.set_itemdroptype((int32_t)itemDropType);
	msg.set_itemdropid((const char*)itemDropID.Get());
	msg.set_linkoffline((int64_t)linkOffLine);
	msg.set_banonhook((int32_t)banOnHook);
	msg.set_rewait((int32_t)Rewait);
	msg.set_retime((int32_t)REtime);
	msg.set_hreban((int32_t)HREBan);
	msg.set_retiered((int32_t)Retiered);
	msg.set_reskillid((int32_t)REskillid);
	msg.set_reteimes((int32_t)Reteimes);
	msg.set_drivepoint((int32_t)drivePoint);
	msg.set_diedp((int32_t)dieDP);
	msg.set_timedp((int32_t)timeDP);
	msg.set_meditation((int32_t)meditation);
}

void mapmap_s::read_from_pbmsg(const ::proto_ff::mapmap & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct mapmap_s));
	mapId = msg.mapid();
	levelLimit = msg.levellimit();
	adviceLv.Copy(msg.advicelv());
	mapType = msg.maptype();
	mapSubType = msg.mapsubtype();
	clearanceTime = msg.clearancetime();
	mapPkmode = msg.mappkmode();
	pklock = msg.pklock();
	pk = msg.pk();
	killValue = msg.killvalue();
	BanGroup = msg.bangroup();
	reviveTime = msg.revivetime();
	mapWide = msg.mapwide();
	mapHeight = msg.mapheight();
	mapResources.Copy(msg.mapresources());
	reviveSkill = msg.reviveskill();
	reviveInPlaceType = msg.reviveinplacetype();
	isHangUp = msg.ishangup();
	itemDropType = msg.itemdroptype();
	itemDropID.Copy(msg.itemdropid());
	linkOffLine = msg.linkoffline();
	banOnHook = msg.banonhook();
	Rewait = msg.rewait();
	REtime = msg.retime();
	HREBan = msg.hreban();
	Retiered = msg.retiered();
	REskillid = msg.reskillid();
	Reteimes = msg.reteimes();
	drivePoint = msg.drivepoint();
	dieDP = msg.diedp();
	timeDP = msg.timedp();
	meditation = msg.meditation();
}

Sheet_mapmap_s::Sheet_mapmap_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_mapmap_s::CreateInit() {
	return 0;
}

int Sheet_mapmap_s::ResumeInit() {
	return 0;
}

void Sheet_mapmap_s::write_to_pbmsg(::proto_ff::Sheet_mapmap & msg) const {
	for(int32_t i = 0; i < (int32_t)mapmap_List.GetSize() && i < mapmap_List.GetMaxSize(); ++i) {
		::proto_ff::mapmap* temp_mapmap_list = msg.add_mapmap_list();
		mapmap_List[i].write_to_pbmsg(*temp_mapmap_list);
	}
}

void Sheet_mapmap_s::read_from_pbmsg(const ::proto_ff::Sheet_mapmap & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_mapmap_s));
	mapmap_List.SetSize(msg.mapmap_list_size() > mapmap_List.GetMaxSize() ? mapmap_List.GetMaxSize() : msg.mapmap_list_size());
	for(int32_t i = 0; i < (int32_t)mapmap_List.GetSize(); ++i) {
		const ::proto_ff::mapmap & temp_mapmap_list = msg.mapmap_list(i);
		mapmap_List[i].read_from_pbmsg(temp_mapmap_list);
	}
}

mapitemdrop_s::mapitemdrop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int mapitemdrop_s::CreateInit() {
	itemDropID = (int32_t)0;
	dropType = (int32_t)0;
	odds = (int32_t)0;
	dropvaluea = (int32_t)0;
	dropvalueb = (int32_t)0;
	dropvaluec = (int32_t)0;
	dropvalued = (int32_t)0;
	dropvaluee = (int32_t)0;
	dropvaluef = (int32_t)0;
	return 0;
}

int mapitemdrop_s::ResumeInit() {
	return 0;
}

void mapitemdrop_s::write_to_pbmsg(::proto_ff::mapitemdrop & msg) const {
	msg.set_itemdropid((int32_t)itemDropID);
	msg.set_droptype((int32_t)dropType);
	msg.set_odds((int32_t)odds);
	msg.set_dropvaluea((int32_t)dropvaluea);
	msg.set_dropvalueb((int32_t)dropvalueb);
	msg.set_dropvaluec((int32_t)dropvaluec);
	msg.set_dropvalued((int32_t)dropvalued);
	msg.set_dropvaluee((int32_t)dropvaluee);
	msg.set_dropvaluef((int32_t)dropvaluef);
}

void mapitemdrop_s::read_from_pbmsg(const ::proto_ff::mapitemdrop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct mapitemdrop_s));
	itemDropID = msg.itemdropid();
	dropType = msg.droptype();
	odds = msg.odds();
	dropvaluea = msg.dropvaluea();
	dropvalueb = msg.dropvalueb();
	dropvaluec = msg.dropvaluec();
	dropvalued = msg.dropvalued();
	dropvaluee = msg.dropvaluee();
	dropvaluef = msg.dropvaluef();
}

Sheet_mapitemdrop_s::Sheet_mapitemdrop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_mapitemdrop_s::CreateInit() {
	return 0;
}

int Sheet_mapitemdrop_s::ResumeInit() {
	return 0;
}

void Sheet_mapitemdrop_s::write_to_pbmsg(::proto_ff::Sheet_mapitemdrop & msg) const {
	for(int32_t i = 0; i < (int32_t)mapitemdrop_List.GetSize() && i < mapitemdrop_List.GetMaxSize(); ++i) {
		::proto_ff::mapitemdrop* temp_mapitemdrop_list = msg.add_mapitemdrop_list();
		mapitemdrop_List[i].write_to_pbmsg(*temp_mapitemdrop_list);
	}
}

void Sheet_mapitemdrop_s::read_from_pbmsg(const ::proto_ff::Sheet_mapitemdrop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_mapitemdrop_s));
	mapitemdrop_List.SetSize(msg.mapitemdrop_list_size() > mapitemdrop_List.GetMaxSize() ? mapitemdrop_List.GetMaxSize() : msg.mapitemdrop_list_size());
	for(int32_t i = 0; i < (int32_t)mapitemdrop_List.GetSize(); ++i) {
		const ::proto_ff::mapitemdrop & temp_mapitemdrop_list = msg.mapitemdrop_list(i);
		mapitemdrop_List[i].read_from_pbmsg(temp_mapitemdrop_list);
	}
}

mapdestroyitem_s::mapdestroyitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int mapdestroyitem_s::CreateInit() {
	destroyitemID = (int64_t)0;
	return 0;
}

int mapdestroyitem_s::ResumeInit() {
	return 0;
}

void mapdestroyitem_s::write_to_pbmsg(::proto_ff::mapdestroyitem & msg) const {
	msg.set_destroyitemid((int64_t)destroyitemID);
}

void mapdestroyitem_s::read_from_pbmsg(const ::proto_ff::mapdestroyitem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct mapdestroyitem_s));
	destroyitemID = msg.destroyitemid();
}

Sheet_mapdestroyitem_s::Sheet_mapdestroyitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_mapdestroyitem_s::CreateInit() {
	return 0;
}

int Sheet_mapdestroyitem_s::ResumeInit() {
	return 0;
}

void Sheet_mapdestroyitem_s::write_to_pbmsg(::proto_ff::Sheet_mapdestroyitem & msg) const {
	for(int32_t i = 0; i < (int32_t)mapdestroyitem_List.GetSize() && i < mapdestroyitem_List.GetMaxSize(); ++i) {
		::proto_ff::mapdestroyitem* temp_mapdestroyitem_list = msg.add_mapdestroyitem_list();
		mapdestroyitem_List[i].write_to_pbmsg(*temp_mapdestroyitem_list);
	}
}

void Sheet_mapdestroyitem_s::read_from_pbmsg(const ::proto_ff::Sheet_mapdestroyitem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_mapdestroyitem_s));
	mapdestroyitem_List.SetSize(msg.mapdestroyitem_list_size() > mapdestroyitem_List.GetMaxSize() ? mapdestroyitem_List.GetMaxSize() : msg.mapdestroyitem_list_size());
	for(int32_t i = 0; i < (int32_t)mapdestroyitem_List.GetSize(); ++i) {
		const ::proto_ff::mapdestroyitem & temp_mapdestroyitem_list = msg.mapdestroyitem_list(i);
		mapdestroyitem_List[i].read_from_pbmsg(temp_mapdestroyitem_list);
	}
}

}