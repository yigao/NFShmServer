#include "DBProto2_s.h"

namespace proto_ff_s {

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

}