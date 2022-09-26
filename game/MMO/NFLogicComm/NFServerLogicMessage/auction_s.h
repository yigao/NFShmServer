#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "auction.pb.h"
#include "auction_s.h"

namespace proto_ff_s {

	struct auctionacquisition_s : public NFDescStoreSeqOP {
		auctionacquisition_s();
		int CreateInit();
		int ResumeInit();
		int64_t Id;
		int32_t profession;
		int32_t position;
		NFSizeString<32> name;
		NFSizeString<32> icon;
		int32_t num;

		virtual void write_to_pbmsg(::proto_ff::auctionacquisition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::auctionacquisition & msg);
		static ::proto_ff::auctionacquisition* new_pbmsg(){ return new ::proto_ff::auctionacquisition(); }
		static ::proto_ff::auctionacquisition make_pbmsg(){ return ::proto_ff::auctionacquisition(); }
	};
	typedef struct auctionacquisition_s auctionacquisition_t;

	struct Sheet_auctionacquisition_s : public NFDescStoreSeqOP {
		Sheet_auctionacquisition_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct auctionacquisition_s, 162> auctionacquisition_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_auctionacquisition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_auctionacquisition & msg);
		static ::proto_ff::Sheet_auctionacquisition* new_pbmsg(){ return new ::proto_ff::Sheet_auctionacquisition(); }
		static ::proto_ff::Sheet_auctionacquisition make_pbmsg(){ return ::proto_ff::Sheet_auctionacquisition(); }
	};
	typedef struct Sheet_auctionacquisition_s Sheet_auctionacquisition_t;

	struct auctionpurchase_s : public NFDescStoreSeqOP {
		auctionpurchase_s();
		int CreateInit();
		int ResumeInit();
		int64_t Id;
		int32_t type;
		int32_t subType;
		NFSizeString<32> name;
		NFSizeString<32> itemName;
		NFSizeString<35> itemId;

		virtual void write_to_pbmsg(::proto_ff::auctionpurchase & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::auctionpurchase & msg);
		static ::proto_ff::auctionpurchase* new_pbmsg(){ return new ::proto_ff::auctionpurchase(); }
		static ::proto_ff::auctionpurchase make_pbmsg(){ return ::proto_ff::auctionpurchase(); }
	};
	typedef struct auctionpurchase_s auctionpurchase_t;

	struct Sheet_auctionpurchase_s : public NFDescStoreSeqOP {
		Sheet_auctionpurchase_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct auctionpurchase_s, 1404> auctionpurchase_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_auctionpurchase & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_auctionpurchase & msg);
		static ::proto_ff::Sheet_auctionpurchase* new_pbmsg(){ return new ::proto_ff::Sheet_auctionpurchase(); }
		static ::proto_ff::Sheet_auctionpurchase make_pbmsg(){ return ::proto_ff::Sheet_auctionpurchase(); }
	};
	typedef struct Sheet_auctionpurchase_s Sheet_auctionpurchase_t;

}

