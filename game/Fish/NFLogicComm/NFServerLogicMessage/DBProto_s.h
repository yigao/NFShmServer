#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "DBProto.pb.h"
#include "DBProto_s.h"
#include "Com.pb.h"
#include "Com_s.h"

#define DEFINE_GIVEBANKRECORDDBDATA_RECORD_MAX_NUM 1


namespace proto_ff_s {

	struct tbFishAccountTable_s : public NFDescStoreSeqOP {
		tbFishAccountTable_s();
		virtual ~tbFishAccountTable_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t player_id;
		NFShmString<128> account;
		NFShmString<128> password;
		uint32_t account_type;
		NFShmString<128> device_id;
		uint64_t phonenum;

		virtual void write_to_pbmsg(::proto_ff::tbFishAccountTable & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::tbFishAccountTable & msg);
		static ::proto_ff::tbFishAccountTable* new_pbmsg(){ return new ::proto_ff::tbFishAccountTable(); }
		static ::proto_ff::tbFishAccountTable make_pbmsg(){ return ::proto_ff::tbFishAccountTable(); }
	};
	typedef struct tbFishAccountTable_s tbFishAccountTable_t;

	struct tbFishPlayerData_s : public NFDescStoreSeqOP {
		tbFishPlayerData_s();
		virtual ~tbFishPlayerData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t player_id;
		NFShmString<128> nickname;
		uint32_t faceid;
		uint64_t regdate;
		uint32_t gender;
		uint32_t age;
		uint64_t phonenum;
		uint64_t jetton;
		NFShmString<64> ip;
		uint64_t last_login_time;
		uint64_t last_logout_time;

		virtual void write_to_pbmsg(::proto_ff::tbFishPlayerData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::tbFishPlayerData & msg);
		static ::proto_ff::tbFishPlayerData* new_pbmsg(){ return new ::proto_ff::tbFishPlayerData(); }
		static ::proto_ff::tbFishPlayerData make_pbmsg(){ return ::proto_ff::tbFishPlayerData(); }
	};
	typedef struct tbFishPlayerData_s tbFishPlayerData_t;

	struct tbFishSnsPlayerSimpleData_s : public NFDescStoreSeqOP {
		tbFishSnsPlayerSimpleData_s();
		virtual ~tbFishSnsPlayerSimpleData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t player_id;
		NFShmString<128> nickname;
		uint32_t faceid;
		uint64_t last_login_time;
		uint64_t last_logout_time;
		uint64_t agent;

		virtual void write_to_pbmsg(::proto_ff::tbFishSnsPlayerSimpleData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::tbFishSnsPlayerSimpleData & msg);
		static ::proto_ff::tbFishSnsPlayerSimpleData* new_pbmsg(){ return new ::proto_ff::tbFishSnsPlayerSimpleData(); }
		static ::proto_ff::tbFishSnsPlayerSimpleData make_pbmsg(){ return ::proto_ff::tbFishSnsPlayerSimpleData(); }
	};
	typedef struct tbFishSnsPlayerSimpleData_s tbFishSnsPlayerSimpleData_t;

	struct GiveBankRecordDBData_s : public NFDescStoreSeqOP {
		GiveBankRecordDBData_s();
		virtual ~GiveBankRecordDBData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct tbGiveBankJetton_s, DEFINE_GIVEBANKRECORDDBDATA_RECORD_MAX_NUM> record;

		virtual void write_to_pbmsg(::proto_ff::GiveBankRecordDBData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GiveBankRecordDBData & msg);
		static ::proto_ff::GiveBankRecordDBData* new_pbmsg(){ return new ::proto_ff::GiveBankRecordDBData(); }
		static ::proto_ff::GiveBankRecordDBData make_pbmsg(){ return ::proto_ff::GiveBankRecordDBData(); }
	};
	typedef struct GiveBankRecordDBData_s GiveBankRecordDBData_t;

	struct tbFishSnsPlayerDetailData_s : public NFDescStoreSeqOP {
		tbFishSnsPlayerDetailData_s();
		virtual ~tbFishSnsPlayerDetailData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t player_id;
		uint64_t bank_jetton;
		NFShmString<128> bank_password;
		struct GiveBankRecordDBData_s record;

		virtual void write_to_pbmsg(::proto_ff::tbFishSnsPlayerDetailData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::tbFishSnsPlayerDetailData & msg);
		static ::proto_ff::tbFishSnsPlayerDetailData* new_pbmsg(){ return new ::proto_ff::tbFishSnsPlayerDetailData(); }
		static ::proto_ff::tbFishSnsPlayerDetailData make_pbmsg(){ return ::proto_ff::tbFishSnsPlayerDetailData(); }
	};
	typedef struct tbFishSnsPlayerDetailData_s tbFishSnsPlayerDetailData_t;

}

