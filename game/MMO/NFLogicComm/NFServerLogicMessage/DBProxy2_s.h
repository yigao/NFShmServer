#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "DBProxy2.pb.h"
#include "DBProxy2_s.h"
#include "Com.pb.h"
#include "Com_s.h"
#include "ComDefine.pb.h"
#include "ComDefine_s.h"
#include "DBProxy.pb.h"
#include "DBProxy_s.h"

#define DEFINE_DBSERVERMGR_LOGOUT_TIME_MAX_NUM 1
#define DEFINE_DBSERVERMGR_DESC_MAX_NUM 1
#define DEFINE_DBSERVERMGR_PAIR_MAX_NUM 1
#define DEFINE_DBSERVERMGR_FACADE_MAX_NUM 1


namespace proto_ff_s {

	struct dbServerMgr_s : public NFDescStoreSeqOP {
		dbServerMgr_s();
		virtual ~dbServerMgr_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		NFShmString<32> contract;//
		NFShmString<32> machine_addr;//
		NFShmString<32> ip;//
		NFShmString<32> bus_name;//
		NFShmString<32> server_desc;//
		uint32_t cur_count;//
		uint64_t last_login_time;//
		uint64_t last_logout_time;//
		NFShmVector<uint64_t, DEFINE_DBSERVERMGR_LOGOUT_TIME_MAX_NUM> logout_time;//
		NFShmVector<NFShmString<32>, DEFINE_DBSERVERMGR_DESC_MAX_NUM> desc;//
		NFShmVector<struct ComPair_s, DEFINE_DBSERVERMGR_PAIR_MAX_NUM> pair;//
		NFShmVector<struct BestEQSlotInfo_s, DEFINE_DBSERVERMGR_FACADE_MAX_NUM> facade;//

		virtual void write_to_pbmsg(::proto_ff::dbServerMgr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dbServerMgr & msg);
		static ::proto_ff::dbServerMgr* new_pbmsg(){ return new ::proto_ff::dbServerMgr(); }
		static ::proto_ff::dbServerMgr make_pbmsg(){ return ::proto_ff::dbServerMgr(); }
	};
	typedef struct dbServerMgr_s dbServerMgr_t;

	struct GetRegisterNum_RoleDBData_s : public NFDescStoreSeqOP {
		GetRegisterNum_RoleDBData_s();
		virtual ~GetRegisterNum_RoleDBData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t num;//

		virtual void write_to_pbmsg(::proto_ff::GetRegisterNum_RoleDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GetRegisterNum_RoleDBData & msg);
		static ::proto_ff::GetRegisterNum_RoleDBData* new_pbmsg(){ return new ::proto_ff::GetRegisterNum_RoleDBData(); }
		static ::proto_ff::GetRegisterNum_RoleDBData make_pbmsg(){ return ::proto_ff::GetRegisterNum_RoleDBData(); }
	};
	typedef struct GetRegisterNum_RoleDBData_s GetRegisterNum_RoleDBData_t;

	struct RoleDBSnsSimple_s : public NFDescStoreSeqOP {
		RoleDBSnsSimple_s();
		virtual ~RoleDBSnsSimple_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cid;//
		uint32_t zid;//
		uint32_t uid;//
		struct RoleDBBaseData_s base;//

		virtual void write_to_pbmsg(::proto_ff::RoleDBSnsSimple & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleDBSnsSimple & msg);
		static ::proto_ff::RoleDBSnsSimple* new_pbmsg(){ return new ::proto_ff::RoleDBSnsSimple(); }
		static ::proto_ff::RoleDBSnsSimple make_pbmsg(){ return ::proto_ff::RoleDBSnsSimple(); }
	};
	typedef struct RoleDBSnsSimple_s RoleDBSnsSimple_t;

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
		uint64_t cid;//
		uint32_t zid;//
		uint32_t uid;//
		struct MyFriendInfo_s friend_info;//

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
		uint64_t cid;//
		uint32_t zid;//
		uint32_t uid;//
		struct RoleDBBaseData_s base;//
		struct AttrDBData_s attr;//

		virtual void write_to_pbmsg(::proto_ff::RoleEnterSceneData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleEnterSceneData & msg);
		static ::proto_ff::RoleEnterSceneData* new_pbmsg(){ return new ::proto_ff::RoleEnterSceneData(); }
		static ::proto_ff::RoleEnterSceneData make_pbmsg(){ return ::proto_ff::RoleEnterSceneData(); }
	};
	typedef struct RoleEnterSceneData_s RoleEnterSceneData_t;

	struct RoleDBName_s : public NFDescStoreSeqOP {
		RoleDBName_s();
		virtual ~RoleDBName_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> name;//

		virtual void write_to_pbmsg(::proto_ff::RoleDBName & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::RoleDBName & msg);
		static ::proto_ff::RoleDBName* new_pbmsg(){ return new ::proto_ff::RoleDBName(); }
		static ::proto_ff::RoleDBName make_pbmsg(){ return ::proto_ff::RoleDBName(); }
	};
	typedef struct RoleDBName_s RoleDBName_t;

	struct tbSnsGlobal_s : public NFDescStoreSeqOP {
		tbSnsGlobal_s();
		virtual ~tbSnsGlobal_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		NFShmString<32> data;//

		virtual void write_to_pbmsg(::proto_ff::tbSnsGlobal & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::tbSnsGlobal & msg);
		static ::proto_ff::tbSnsGlobal* new_pbmsg(){ return new ::proto_ff::tbSnsGlobal(); }
		static ::proto_ff::tbSnsGlobal make_pbmsg(){ return ::proto_ff::tbSnsGlobal(); }
	};
	typedef struct tbSnsGlobal_s tbSnsGlobal_t;

	struct tbSnsTeam_s : public NFDescStoreSeqOP {
		tbSnsTeam_s();
		virtual ~tbSnsTeam_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t team_id;//

		virtual void write_to_pbmsg(::proto_ff::tbSnsTeam & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::tbSnsTeam & msg);
		static ::proto_ff::tbSnsTeam* new_pbmsg(){ return new ::proto_ff::tbSnsTeam(); }
		static ::proto_ff::tbSnsTeam make_pbmsg(){ return ::proto_ff::tbSnsTeam(); }
	};
	typedef struct tbSnsTeam_s tbSnsTeam_t;

	struct tbSnsRank_s : public NFDescStoreSeqOP {
		tbSnsRank_s();
		virtual ~tbSnsRank_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		NFShmString<32> data;//

		virtual void write_to_pbmsg(::proto_ff::tbSnsRank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::tbSnsRank & msg);
		static ::proto_ff::tbSnsRank* new_pbmsg(){ return new ::proto_ff::tbSnsRank(); }
		static ::proto_ff::tbSnsRank make_pbmsg(){ return ::proto_ff::tbSnsRank(); }
	};
	typedef struct tbSnsRank_s tbSnsRank_t;

}

