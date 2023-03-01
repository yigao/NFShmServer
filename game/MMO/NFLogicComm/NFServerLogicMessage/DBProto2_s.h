#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "DBProto2.pb.h"
#include "DBProto2_s.h"
#include "Com.pb.h"
#include "Com_s.h"
#include "ComDefine.pb.h"
#include "ComDefine_s.h"
#include "DBProto.pb.h"
#include "DBProto_s.h"

namespace proto_ff_s {

	struct GetRegisterNum_RoleDBData_s : public NFDescStoreSeqOP {
		GetRegisterNum_RoleDBData_s();
		virtual ~GetRegisterNum_RoleDBData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t num;

		virtual void write_to_pbmsg(::proto_ff::GetRegisterNum_RoleDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GetRegisterNum_RoleDBData & msg);
		static ::proto_ff::GetRegisterNum_RoleDBData* new_pbmsg(){ return new ::proto_ff::GetRegisterNum_RoleDBData(); }
		static ::proto_ff::GetRegisterNum_RoleDBData make_pbmsg(){ return ::proto_ff::GetRegisterNum_RoleDBData(); }
	};
	typedef struct GetRegisterNum_RoleDBData_s GetRegisterNum_RoleDBData_t;

	struct RoleDBSimpleData_s : public NFDescStoreSeqOP {
		RoleDBSimpleData_s();
		virtual ~RoleDBSimpleData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		uint32_t zid;
		uint32_t uid;
		struct RoleDBBaseData_s base;

		virtual void write_to_pbmsg(::proto_ff::RoleDBSimpleData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleDBSimpleData & msg);
		static ::proto_ff::RoleDBSimpleData* new_pbmsg(){ return new ::proto_ff::RoleDBSimpleData(); }
		static ::proto_ff::RoleDBSimpleData make_pbmsg(){ return ::proto_ff::RoleDBSimpleData(); }
	};
	typedef struct RoleDBSimpleData_s RoleDBSimpleData_t;

	struct MyFriendInfo_s : public NFDescStoreSeqOP {
		MyFriendInfo_s();
		virtual ~MyFriendInfo_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::MyFriendInfo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::MyFriendInfo & msg);
		static ::proto_ff::MyFriendInfo* new_pbmsg(){ return new ::proto_ff::MyFriendInfo(); }
		static ::proto_ff::MyFriendInfo make_pbmsg(){ return ::proto_ff::MyFriendInfo(); }
	};
	typedef struct MyFriendInfo_s MyFriendInfo_t;

	struct RoleDBSnsDetail_s : public NFDescStoreSeqOP {
		RoleDBSnsDetail_s();
		virtual ~RoleDBSnsDetail_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		struct MyFriendInfo_s friend_info;

		virtual void write_to_pbmsg(::proto_ff::RoleDBSnsDetail & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleDBSnsDetail & msg);
		static ::proto_ff::RoleDBSnsDetail* new_pbmsg(){ return new ::proto_ff::RoleDBSnsDetail(); }
		static ::proto_ff::RoleDBSnsDetail make_pbmsg(){ return ::proto_ff::RoleDBSnsDetail(); }
	};
	typedef struct RoleDBSnsDetail_s RoleDBSnsDetail_t;

	struct RoleEnterSceneData_s : public NFDescStoreSeqOP {
		RoleEnterSceneData_s();
		virtual ~RoleEnterSceneData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;
		uint32_t zid;
		uint32_t uid;
		struct RoleDBBaseData_s base;
		struct AttrDBData_s attr;

		virtual void write_to_pbmsg(::proto_ff::RoleEnterSceneData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleEnterSceneData & msg);
		static ::proto_ff::RoleEnterSceneData* new_pbmsg(){ return new ::proto_ff::RoleEnterSceneData(); }
		static ::proto_ff::RoleEnterSceneData make_pbmsg(){ return ::proto_ff::RoleEnterSceneData(); }
	};
	typedef struct RoleEnterSceneData_s RoleEnterSceneData_t;

}

