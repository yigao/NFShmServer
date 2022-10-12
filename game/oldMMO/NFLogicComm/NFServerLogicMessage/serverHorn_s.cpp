#include "serverHorn_s.h"

namespace proto_ff_s {

serverHornserverHorn_s::serverHornserverHorn_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int serverHornserverHorn_s::CreateInit() {
	id = (int64_t)0;
	time = (int32_t)0;
	minTime = (int32_t)0;
	itemid = (int64_t)0;
	currencyType = (int32_t)0;
	currencyCost = (int32_t)0;
	return 0;
}

int serverHornserverHorn_s::ResumeInit() {
	return 0;
}

void serverHornserverHorn_s::write_to_pbmsg(::proto_ff::serverHornserverHorn & msg) const {
	msg.set_id((int64_t)id);
	msg.set_time((int32_t)time);
	msg.set_mintime((int32_t)minTime);
	msg.set_itemid((int64_t)itemid);
	msg.set_currencytype((int32_t)currencyType);
	msg.set_currencycost((int32_t)currencyCost);
}

void serverHornserverHorn_s::read_from_pbmsg(const ::proto_ff::serverHornserverHorn & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct serverHornserverHorn_s));
	id = msg.id();
	time = msg.time();
	minTime = msg.mintime();
	itemid = msg.itemid();
	currencyType = msg.currencytype();
	currencyCost = msg.currencycost();
}

Sheet_serverHornserverHorn_s::Sheet_serverHornserverHorn_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_serverHornserverHorn_s::CreateInit() {
	return 0;
}

int Sheet_serverHornserverHorn_s::ResumeInit() {
	return 0;
}

void Sheet_serverHornserverHorn_s::write_to_pbmsg(::proto_ff::Sheet_serverHornserverHorn & msg) const {
	for(int32_t i = 0; i < (int32_t)serverHornserverHorn_List.GetSize() && i < serverHornserverHorn_List.GetMaxSize(); ++i) {
		::proto_ff::serverHornserverHorn* temp_serverhornserverhorn_list = msg.add_serverhornserverhorn_list();
		serverHornserverHorn_List[i].write_to_pbmsg(*temp_serverhornserverhorn_list);
	}
}

void Sheet_serverHornserverHorn_s::read_from_pbmsg(const ::proto_ff::Sheet_serverHornserverHorn & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_serverHornserverHorn_s));
	serverHornserverHorn_List.SetSize(msg.serverhornserverhorn_list_size() > serverHornserverHorn_List.GetMaxSize() ? serverHornserverHorn_List.GetMaxSize() : msg.serverhornserverhorn_list_size());
	for(int32_t i = 0; i < (int32_t)serverHornserverHorn_List.GetSize(); ++i) {
		const ::proto_ff::serverHornserverHorn & temp_serverhornserverhorn_list = msg.serverhornserverhorn_list(i);
		serverHornserverHorn_List[i].read_from_pbmsg(temp_serverhornserverhorn_list);
	}
}

}