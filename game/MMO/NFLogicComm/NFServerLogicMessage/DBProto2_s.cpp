#include "DBProto2_s.h"

namespace proto_ff_s {

dbServerMgr_s::dbServerMgr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dbServerMgr_s::CreateInit() {
	id = (uint64_t)0;
	cur_count = (uint32_t)0;
	last_login_time = (uint64_t)0;
	last_logout_time = (uint64_t)0;
	return 0;
}

int dbServerMgr_s::ResumeInit() {
	return 0;
}

void dbServerMgr_s::write_to_pbmsg(::proto_ff::dbServerMgr & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_contract((const char*)contract.data());
	msg.set_machine_addr((const char*)machine_addr.data());
	msg.set_ip((const char*)ip.data());
	msg.set_bus_name((const char*)bus_name.data());
	msg.set_server_desc((const char*)server_desc.data());
	msg.set_cur_count((uint32_t)cur_count);
	msg.set_last_login_time((uint64_t)last_login_time);
	msg.set_last_logout_time((uint64_t)last_logout_time);
	for(int32_t i = 0; i < (int32_t)logout_time.size(); ++i) {
		msg.add_logout_time((uint64_t)logout_time[i]);
	}
	for(int32_t i = 0; i < (int32_t)desc.size(); ++i) {
		msg.add_desc((const char*)desc[i].data());
	}
	for(int32_t i = 0; i < (int32_t)pair.size(); ++i) {
		::proto_ff::ComPair* temp_pair = msg.add_pair();
		pair[i].write_to_pbmsg(*temp_pair);
	}
	for(int32_t i = 0; i < (int32_t)facade.size(); ++i) {
		::proto_ff::BestEQSlotInfo* temp_facade = msg.add_facade();
		facade[i].write_to_pbmsg(*temp_facade);
	}
}

void dbServerMgr_s::read_from_pbmsg(const ::proto_ff::dbServerMgr & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dbServerMgr_s));
	id = msg.id();
	contract = msg.contract();
	machine_addr = msg.machine_addr();
	ip = msg.ip();
	bus_name = msg.bus_name();
	server_desc = msg.server_desc();
	cur_count = msg.cur_count();
	last_login_time = msg.last_login_time();
	last_logout_time = msg.last_logout_time();
	logout_time.resize(msg.logout_time_size());
	for(int32_t i = 0; i < (int32_t)logout_time.size(); ++i) {
		logout_time[i] = msg.logout_time(i);
	}
	desc.resize(msg.desc_size());
	for(int32_t i = 0; i < (int32_t)desc.size(); ++i) {
	}
	pair.resize(msg.pair_size());
	for(int32_t i = 0; i < (int32_t)pair.size(); ++i) {
		const ::proto_ff::ComPair & temp_pair = msg.pair(i);
		pair[i].read_from_pbmsg(temp_pair);
	}
	facade.resize(msg.facade_size());
	for(int32_t i = 0; i < (int32_t)facade.size(); ++i) {
		const ::proto_ff::BestEQSlotInfo & temp_facade = msg.facade(i);
		facade[i].read_from_pbmsg(temp_facade);
	}
}

GetRegisterNum_RoleDBData_s::GetRegisterNum_RoleDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GetRegisterNum_RoleDBData_s::CreateInit() {
	num = (uint32_t)0;
	return 0;
}

int GetRegisterNum_RoleDBData_s::ResumeInit() {
	return 0;
}

void GetRegisterNum_RoleDBData_s::write_to_pbmsg(::proto_ff::GetRegisterNum_RoleDBData & msg) const {
	msg.set_num((uint32_t)num);
}

void GetRegisterNum_RoleDBData_s::read_from_pbmsg(const ::proto_ff::GetRegisterNum_RoleDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GetRegisterNum_RoleDBData_s));
	num = msg.num();
}

RoleDBSimpleData_s::RoleDBSimpleData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleDBSimpleData_s::CreateInit() {
	cid = (uint64_t)0;
	zid = (uint32_t)0;
	uid = (uint32_t)0;
	return 0;
}

int RoleDBSimpleData_s::ResumeInit() {
	return 0;
}

void RoleDBSimpleData_s::write_to_pbmsg(::proto_ff::RoleDBSimpleData & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_zid((uint32_t)zid);
	msg.set_uid((uint32_t)uid);
	::proto_ff::RoleDBBaseData* temp_base = msg.mutable_base();
	base.write_to_pbmsg(*temp_base);
}

void RoleDBSimpleData_s::read_from_pbmsg(const ::proto_ff::RoleDBSimpleData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleDBSimpleData_s));
	cid = msg.cid();
	zid = msg.zid();
	uid = msg.uid();
	const ::proto_ff::RoleDBBaseData & temp_base = msg.base();
	base.read_from_pbmsg(temp_base);
}

MyFriendInfo_s::MyFriendInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MyFriendInfo_s::CreateInit() {
	return 0;
}

int MyFriendInfo_s::ResumeInit() {
	return 0;
}

void MyFriendInfo_s::write_to_pbmsg(::proto_ff::MyFriendInfo & msg) const {
}

void MyFriendInfo_s::read_from_pbmsg(const ::proto_ff::MyFriendInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct MyFriendInfo_s));
}

RoleDBSnsDetail_s::RoleDBSnsDetail_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleDBSnsDetail_s::CreateInit() {
	cid = (uint64_t)0;
	return 0;
}

int RoleDBSnsDetail_s::ResumeInit() {
	return 0;
}

void RoleDBSnsDetail_s::write_to_pbmsg(::proto_ff::RoleDBSnsDetail & msg) const {
	msg.set_cid((uint64_t)cid);
	::proto_ff::MyFriendInfo* temp_friend_info = msg.mutable_friend_info();
	friend_info.write_to_pbmsg(*temp_friend_info);
}

void RoleDBSnsDetail_s::read_from_pbmsg(const ::proto_ff::RoleDBSnsDetail & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleDBSnsDetail_s));
	cid = msg.cid();
	const ::proto_ff::MyFriendInfo & temp_friend_info = msg.friend_info();
	friend_info.read_from_pbmsg(temp_friend_info);
}

RoleEnterSceneData_s::RoleEnterSceneData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleEnterSceneData_s::CreateInit() {
	cid = (uint64_t)0;
	zid = (uint32_t)0;
	uid = (uint32_t)0;
	return 0;
}

int RoleEnterSceneData_s::ResumeInit() {
	return 0;
}

void RoleEnterSceneData_s::write_to_pbmsg(::proto_ff::RoleEnterSceneData & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_zid((uint32_t)zid);
	msg.set_uid((uint32_t)uid);
	::proto_ff::RoleDBBaseData* temp_base = msg.mutable_base();
	base.write_to_pbmsg(*temp_base);
	::proto_ff::AttrDBData* temp_attr = msg.mutable_attr();
	attr.write_to_pbmsg(*temp_attr);
}

void RoleEnterSceneData_s::read_from_pbmsg(const ::proto_ff::RoleEnterSceneData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleEnterSceneData_s));
	cid = msg.cid();
	zid = msg.zid();
	uid = msg.uid();
	const ::proto_ff::RoleDBBaseData & temp_base = msg.base();
	base.read_from_pbmsg(temp_base);
	const ::proto_ff::AttrDBData & temp_attr = msg.attr();
	attr.read_from_pbmsg(temp_attr);
}

}