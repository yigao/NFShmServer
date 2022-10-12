#include "recharge_s.h"

namespace proto_ff_s {

rechargerechargepresentDesc_s::rechargerechargepresentDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rechargerechargepresentDesc_s::CreateInit() {
	Num = (int32_t)0;
	Id = (int64_t)0;
	return 0;
}

int rechargerechargepresentDesc_s::ResumeInit() {
	return 0;
}

void rechargerechargepresentDesc_s::write_to_pbmsg(::proto_ff::rechargerechargepresentDesc & msg) const {
	msg.set_num((int32_t)Num);
	msg.set_id((int64_t)Id);
}

void rechargerechargepresentDesc_s::read_from_pbmsg(const ::proto_ff::rechargerechargepresentDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rechargerechargepresentDesc_s));
	Num = msg.num();
	Id = msg.id();
}

rechargerechargechannelDesc_s::rechargerechargechannelDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rechargerechargechannelDesc_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int rechargerechargechannelDesc_s::ResumeInit() {
	return 0;
}

void rechargerechargechannelDesc_s::write_to_pbmsg(::proto_ff::rechargerechargechannelDesc & msg) const {
	msg.set_id((int32_t)id);
	msg.set_point((const char*)point.Get());
}

void rechargerechargechannelDesc_s::read_from_pbmsg(const ::proto_ff::rechargerechargechannelDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rechargerechargechannelDesc_s));
	id = msg.id();
	point.Copy(msg.point());
}

rechargerecharge_s::rechargerecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int rechargerecharge_s::CreateInit() {
	id = (int32_t)0;
	type = (int32_t)0;
	quantity = (int64_t)0;
	itemNum = (int32_t)0;
	multipleTimes = (int64_t)0;
	multipleReward = (int64_t)0;
	zuanshitype = (int32_t)0;
	vipExp = (int32_t)0;
	vipExpLimit = (int32_t)0;
	activityCount = (int32_t)0;
	HactivityCount = (int32_t)0;
	price = (int32_t)0;
	fristpresent = (int32_t)0;
	presenttype = (int32_t)0;
	preRecharge = (int32_t)0;
	return 0;
}

int rechargerecharge_s::ResumeInit() {
	return 0;
}

void rechargerecharge_s::write_to_pbmsg(::proto_ff::rechargerecharge & msg) const {
	msg.set_id((int32_t)id);
	msg.set_name((const char*)name.Get());
	msg.set_defaultpoint((const char*)defaultPoint.Get());
	msg.set_type((int32_t)type);
	msg.set_unit((const char*)unit.Get());
	msg.set_beizhu((const char*)beizhu.Get());
	msg.set_quantity((int64_t)quantity);
	msg.set_itemnum((int32_t)itemNum);
	msg.set_multipletimes((int64_t)multipleTimes);
	msg.set_multiplereward((int64_t)multipleReward);
	msg.set_zuanshitype((int32_t)zuanshitype);
	msg.set_vipexp((int32_t)vipExp);
	msg.set_vipexplimit((int32_t)vipExpLimit);
	msg.set_activitycount((int32_t)activityCount);
	msg.set_hactivitycount((int32_t)HactivityCount);
	msg.set_price((int32_t)price);
	msg.set_fristpresent((int32_t)fristpresent);
	msg.set_presenttype((int32_t)presenttype);
	msg.set_icon((const char*)icon.Get());
	msg.set_prerecharge((int32_t)preRecharge);
	for(int32_t i = 0; i < (int32_t)present.GetSize() && i < present.GetMaxSize(); ++i) {
		::proto_ff::rechargerechargepresentDesc* temp_present = msg.add_present();
		present[i].write_to_pbmsg(*temp_present);
	}
	for(int32_t i = 0; i < (int32_t)channel.GetSize() && i < channel.GetMaxSize(); ++i) {
		::proto_ff::rechargerechargechannelDesc* temp_channel = msg.add_channel();
		channel[i].write_to_pbmsg(*temp_channel);
	}
}

void rechargerecharge_s::read_from_pbmsg(const ::proto_ff::rechargerecharge & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct rechargerecharge_s));
	id = msg.id();
	name.Copy(msg.name());
	defaultPoint.Copy(msg.defaultpoint());
	type = msg.type();
	unit.Copy(msg.unit());
	beizhu.Copy(msg.beizhu());
	quantity = msg.quantity();
	itemNum = msg.itemnum();
	multipleTimes = msg.multipletimes();
	multipleReward = msg.multiplereward();
	zuanshitype = msg.zuanshitype();
	vipExp = msg.vipexp();
	vipExpLimit = msg.vipexplimit();
	activityCount = msg.activitycount();
	HactivityCount = msg.hactivitycount();
	price = msg.price();
	fristpresent = msg.fristpresent();
	presenttype = msg.presenttype();
	icon.Copy(msg.icon());
	preRecharge = msg.prerecharge();
	present.SetSize(msg.present_size() > present.GetMaxSize() ? present.GetMaxSize() : msg.present_size());
	for(int32_t i = 0; i < (int32_t)present.GetSize(); ++i) {
		const ::proto_ff::rechargerechargepresentDesc & temp_present = msg.present(i);
		present[i].read_from_pbmsg(temp_present);
	}
	channel.SetSize(msg.channel_size() > channel.GetMaxSize() ? channel.GetMaxSize() : msg.channel_size());
	for(int32_t i = 0; i < (int32_t)channel.GetSize(); ++i) {
		const ::proto_ff::rechargerechargechannelDesc & temp_channel = msg.channel(i);
		channel[i].read_from_pbmsg(temp_channel);
	}
}

Sheet_rechargerecharge_s::Sheet_rechargerecharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_rechargerecharge_s::CreateInit() {
	return 0;
}

int Sheet_rechargerecharge_s::ResumeInit() {
	return 0;
}

void Sheet_rechargerecharge_s::write_to_pbmsg(::proto_ff::Sheet_rechargerecharge & msg) const {
	for(int32_t i = 0; i < (int32_t)rechargerecharge_List.GetSize() && i < rechargerecharge_List.GetMaxSize(); ++i) {
		::proto_ff::rechargerecharge* temp_rechargerecharge_list = msg.add_rechargerecharge_list();
		rechargerecharge_List[i].write_to_pbmsg(*temp_rechargerecharge_list);
	}
}

void Sheet_rechargerecharge_s::read_from_pbmsg(const ::proto_ff::Sheet_rechargerecharge & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_rechargerecharge_s));
	rechargerecharge_List.SetSize(msg.rechargerecharge_list_size() > rechargerecharge_List.GetMaxSize() ? rechargerecharge_List.GetMaxSize() : msg.rechargerecharge_list_size());
	for(int32_t i = 0; i < (int32_t)rechargerecharge_List.GetSize(); ++i) {
		const ::proto_ff::rechargerecharge & temp_rechargerecharge_list = msg.rechargerecharge_list(i);
		rechargerecharge_List[i].read_from_pbmsg(temp_rechargerecharge_list);
	}
}

}