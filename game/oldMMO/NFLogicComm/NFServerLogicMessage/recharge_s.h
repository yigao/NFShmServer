#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "recharge.pb.h"
#include "recharge_s.h"

namespace proto_ff_s {

	struct rechargerechargepresentDesc_s : public NFDescStoreSeqOP {
		rechargerechargepresentDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Num;
		int64_t Id;

		virtual void write_to_pbmsg(::proto_ff::rechargerechargepresentDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rechargerechargepresentDesc & msg);
		static ::proto_ff::rechargerechargepresentDesc* new_pbmsg(){ return new ::proto_ff::rechargerechargepresentDesc(); }
		static ::proto_ff::rechargerechargepresentDesc make_pbmsg(){ return ::proto_ff::rechargerechargepresentDesc(); }
	};
	typedef struct rechargerechargepresentDesc_s rechargerechargepresentDesc_t;

	struct rechargerechargechannelDesc_s : public NFDescStoreSeqOP {
		rechargerechargechannelDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<60> point;

		virtual void write_to_pbmsg(::proto_ff::rechargerechargechannelDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rechargerechargechannelDesc & msg);
		static ::proto_ff::rechargerechargechannelDesc* new_pbmsg(){ return new ::proto_ff::rechargerechargechannelDesc(); }
		static ::proto_ff::rechargerechargechannelDesc make_pbmsg(){ return ::proto_ff::rechargerechargechannelDesc(); }
	};
	typedef struct rechargerechargechannelDesc_s rechargerechargechannelDesc_t;

	struct rechargerecharge_s : public NFDescStoreSeqOP {
		rechargerecharge_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<80> name;
		NFSizeString<60> defaultPoint;
		int32_t type;
		NFSizeString<60> unit;
		NFSizeString<200> beizhu;
		int64_t quantity;
		int32_t itemNum;
		int64_t multipleTimes;
		int64_t multipleReward;
		int32_t zuanshitype;
		int32_t vipExp;
		int32_t vipExpLimit;
		int32_t activityCount;
		int32_t HactivityCount;
		int32_t price;
		int32_t fristpresent;
		int32_t presenttype;
		NFSizeString<60> icon;
		int32_t preRecharge;
		NFArray<struct rechargerechargepresentDesc_s, 2> present;
		NFArray<struct rechargerechargechannelDesc_s, 4> channel;

		virtual void write_to_pbmsg(::proto_ff::rechargerecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::rechargerecharge & msg);
		static ::proto_ff::rechargerecharge* new_pbmsg(){ return new ::proto_ff::rechargerecharge(); }
		static ::proto_ff::rechargerecharge make_pbmsg(){ return ::proto_ff::rechargerecharge(); }
	};
	typedef struct rechargerecharge_s rechargerecharge_t;

	struct Sheet_rechargerecharge_s : public NFDescStoreSeqOP {
		Sheet_rechargerecharge_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct rechargerecharge_s, 2000> rechargerecharge_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_rechargerecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_rechargerecharge & msg);
		static ::proto_ff::Sheet_rechargerecharge* new_pbmsg(){ return new ::proto_ff::Sheet_rechargerecharge(); }
		static ::proto_ff::Sheet_rechargerecharge make_pbmsg(){ return ::proto_ff::Sheet_rechargerecharge(); }
	};
	typedef struct Sheet_rechargerecharge_s Sheet_rechargerecharge_t;

}

