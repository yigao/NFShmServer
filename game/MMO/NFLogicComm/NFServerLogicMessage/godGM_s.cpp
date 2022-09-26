#include "godGM_s.h"

namespace proto_ff_s {

godGMgodGM_s::godGMgodGM_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int godGMgodGM_s::CreateInit() {
	id = (int32_t)0;
	Time = (int32_t)0;
	freeRechargeId = (int32_t)0;
	rechargeId = (int32_t)0;
	freeBox = (int64_t)0;
	rechargeBox = (int64_t)0;
	costId = (int64_t)0;
	costNum = (int32_t)0;
	getId = (int64_t)0;
	getNum = (int32_t)0;
	exchargeTimes = (int32_t)0;
	return 0;
}

int godGMgodGM_s::ResumeInit() {
	return 0;
}

void godGMgodGM_s::write_to_pbmsg(::proto_ff::godGMgodGM & msg) const {
	msg.set_id((int32_t)id);
	msg.set_time((int32_t)Time);
	msg.set_freerechargeid((int32_t)freeRechargeId);
	msg.set_rechargeid((int32_t)rechargeId);
	msg.set_freebox((int64_t)freeBox);
	msg.set_rechargebox((int64_t)rechargeBox);
	msg.set_freeprivilege((const char*)freePrivilege.Get());
	msg.set_payprivilege((const char*)payPrivilege.Get());
	msg.set_costid((int64_t)costId);
	msg.set_costnum((int32_t)costNum);
	msg.set_getid((int64_t)getId);
	msg.set_getnum((int32_t)getNum);
	msg.set_exchargetimes((int32_t)exchargeTimes);
}

void godGMgodGM_s::read_from_pbmsg(const ::proto_ff::godGMgodGM & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct godGMgodGM_s));
	id = msg.id();
	Time = msg.time();
	freeRechargeId = msg.freerechargeid();
	rechargeId = msg.rechargeid();
	freeBox = msg.freebox();
	rechargeBox = msg.rechargebox();
	freePrivilege.Copy(msg.freeprivilege());
	payPrivilege.Copy(msg.payprivilege());
	costId = msg.costid();
	costNum = msg.costnum();
	getId = msg.getid();
	getNum = msg.getnum();
	exchargeTimes = msg.exchargetimes();
}

Sheet_godGMgodGM_s::Sheet_godGMgodGM_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_godGMgodGM_s::CreateInit() {
	return 0;
}

int Sheet_godGMgodGM_s::ResumeInit() {
	return 0;
}

void Sheet_godGMgodGM_s::write_to_pbmsg(::proto_ff::Sheet_godGMgodGM & msg) const {
	for(int32_t i = 0; i < (int32_t)godGMgodGM_List.GetSize() && i < godGMgodGM_List.GetMaxSize(); ++i) {
		::proto_ff::godGMgodGM* temp_godgmgodgm_list = msg.add_godgmgodgm_list();
		godGMgodGM_List[i].write_to_pbmsg(*temp_godgmgodgm_list);
	}
}

void Sheet_godGMgodGM_s::read_from_pbmsg(const ::proto_ff::Sheet_godGMgodGM & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_godGMgodGM_s));
	godGMgodGM_List.SetSize(msg.godgmgodgm_list_size() > godGMgodGM_List.GetMaxSize() ? godGMgodGM_List.GetMaxSize() : msg.godgmgodgm_list_size());
	for(int32_t i = 0; i < (int32_t)godGMgodGM_List.GetSize(); ++i) {
		const ::proto_ff::godGMgodGM & temp_godgmgodgm_list = msg.godgmgodgm_list(i);
		godGMgodGM_List[i].read_from_pbmsg(temp_godgmgodgm_list);
	}
}

}