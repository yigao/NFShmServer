#include "treasureBowl_s.h"

namespace proto_ff_s {

treasureBowltreasureBowl_s::treasureBowltreasureBowl_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int treasureBowltreasureBowl_s::CreateInit() {
	Id = (int32_t)0;
	level = (int32_t)0;
	Type = (int32_t)0;
	price = (int32_t)0;
	returnD = (int32_t)0;
	returnVip = (int32_t)0;
	returnItemID = (int64_t)0;
	returnItem = (int32_t)0;
	boxid = (int64_t)0;
	skillid = (int64_t)0;
	return 0;
}

int treasureBowltreasureBowl_s::ResumeInit() {
	return 0;
}

void treasureBowltreasureBowl_s::write_to_pbmsg(::proto_ff::treasureBowltreasureBowl & msg) const {
	msg.set_id((int32_t)Id);
	msg.set_level((int32_t)level);
	msg.set_type((int32_t)Type);
	msg.set_price((int32_t)price);
	msg.set_returnd((int32_t)returnD);
	msg.set_returnvip((int32_t)returnVip);
	msg.set_returnitemid((int64_t)returnItemID);
	msg.set_returnitem((int32_t)returnItem);
	msg.set_boxid((int64_t)boxid);
	msg.set_skillid((int64_t)skillid);
	msg.set_skilldes((const char*)skilldes.Get());
}

void treasureBowltreasureBowl_s::read_from_pbmsg(const ::proto_ff::treasureBowltreasureBowl & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct treasureBowltreasureBowl_s));
	Id = msg.id();
	level = msg.level();
	Type = msg.type();
	price = msg.price();
	returnD = msg.returnd();
	returnVip = msg.returnvip();
	returnItemID = msg.returnitemid();
	returnItem = msg.returnitem();
	boxid = msg.boxid();
	skillid = msg.skillid();
	skilldes.Copy(msg.skilldes());
}

Sheet_treasureBowltreasureBowl_s::Sheet_treasureBowltreasureBowl_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_treasureBowltreasureBowl_s::CreateInit() {
	return 0;
}

int Sheet_treasureBowltreasureBowl_s::ResumeInit() {
	return 0;
}

void Sheet_treasureBowltreasureBowl_s::write_to_pbmsg(::proto_ff::Sheet_treasureBowltreasureBowl & msg) const {
	for(int32_t i = 0; i < (int32_t)treasureBowltreasureBowl_List.GetSize() && i < treasureBowltreasureBowl_List.GetMaxSize(); ++i) {
		::proto_ff::treasureBowltreasureBowl* temp_treasurebowltreasurebowl_list = msg.add_treasurebowltreasurebowl_list();
		treasureBowltreasureBowl_List[i].write_to_pbmsg(*temp_treasurebowltreasurebowl_list);
	}
}

void Sheet_treasureBowltreasureBowl_s::read_from_pbmsg(const ::proto_ff::Sheet_treasureBowltreasureBowl & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_treasureBowltreasureBowl_s));
	treasureBowltreasureBowl_List.SetSize(msg.treasurebowltreasurebowl_list_size() > treasureBowltreasureBowl_List.GetMaxSize() ? treasureBowltreasureBowl_List.GetMaxSize() : msg.treasurebowltreasurebowl_list_size());
	for(int32_t i = 0; i < (int32_t)treasureBowltreasureBowl_List.GetSize(); ++i) {
		const ::proto_ff::treasureBowltreasureBowl & temp_treasurebowltreasurebowl_list = msg.treasurebowltreasurebowl_list(i);
		treasureBowltreasureBowl_List[i].read_from_pbmsg(temp_treasurebowltreasurebowl_list);
	}
}

}