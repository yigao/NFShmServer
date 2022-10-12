#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "chooseGift.pb.h"
#include "chooseGift_s.h"

namespace proto_ff_s {

	struct chooseGiftchooseGiftrechargeDesc_s : public NFDescStoreSeqOP {
		chooseGiftchooseGiftrechargeDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t Box;
		int32_t Id;

		virtual void write_to_pbmsg(::proto_ff::chooseGiftchooseGiftrechargeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::chooseGiftchooseGiftrechargeDesc & msg);
		static ::proto_ff::chooseGiftchooseGiftrechargeDesc* new_pbmsg(){ return new ::proto_ff::chooseGiftchooseGiftrechargeDesc(); }
		static ::proto_ff::chooseGiftchooseGiftrechargeDesc make_pbmsg(){ return ::proto_ff::chooseGiftchooseGiftrechargeDesc(); }
	};
	typedef struct chooseGiftchooseGiftrechargeDesc_s chooseGiftchooseGiftrechargeDesc_t;

	struct chooseGiftchooseGift_s : public NFDescStoreSeqOP {
		chooseGiftchooseGift_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t box;
		int32_t switchTime;
		NFArray<struct chooseGiftchooseGiftrechargeDesc_s, 2> recharge;

		virtual void write_to_pbmsg(::proto_ff::chooseGiftchooseGift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::chooseGiftchooseGift & msg);
		static ::proto_ff::chooseGiftchooseGift* new_pbmsg(){ return new ::proto_ff::chooseGiftchooseGift(); }
		static ::proto_ff::chooseGiftchooseGift make_pbmsg(){ return ::proto_ff::chooseGiftchooseGift(); }
	};
	typedef struct chooseGiftchooseGift_s chooseGiftchooseGift_t;

	struct Sheet_chooseGiftchooseGift_s : public NFDescStoreSeqOP {
		Sheet_chooseGiftchooseGift_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct chooseGiftchooseGift_s, 20> chooseGiftchooseGift_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_chooseGiftchooseGift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_chooseGiftchooseGift & msg);
		static ::proto_ff::Sheet_chooseGiftchooseGift* new_pbmsg(){ return new ::proto_ff::Sheet_chooseGiftchooseGift(); }
		static ::proto_ff::Sheet_chooseGiftchooseGift make_pbmsg(){ return ::proto_ff::Sheet_chooseGiftchooseGift(); }
	};
	typedef struct Sheet_chooseGiftchooseGift_s Sheet_chooseGiftchooseGift_t;

}

