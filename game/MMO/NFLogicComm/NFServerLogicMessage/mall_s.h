#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "mall.pb.h"
#include "mall_s.h"

namespace proto_ff_s {

	struct mallmall_s : public NFDescStoreSeqOP {
		mallmall_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int64_t itemID;
		int32_t num;
		int64_t mallType;
		int32_t subType;
		int32_t priority;
		int32_t moneyType;
		int32_t price;
		int32_t discount;
		int32_t daily;
		NFSizeString<32> buyAmount;
		NFSizeString<32> vipLimit;
		int32_t isClose;
		int32_t cantBuy;
		int32_t isMarkBind;
		int32_t roleLimit;
		int32_t functionUnlock;

		virtual void write_to_pbmsg(::proto_ff::mallmall & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::mallmall & msg);
		static ::proto_ff::mallmall* new_pbmsg(){ return new ::proto_ff::mallmall(); }
		static ::proto_ff::mallmall make_pbmsg(){ return ::proto_ff::mallmall(); }
	};
	typedef struct mallmall_s mallmall_t;

	struct Sheet_mallmall_s : public NFDescStoreSeqOP {
		Sheet_mallmall_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct mallmall_s, 290> mallmall_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_mallmall & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_mallmall & msg);
		static ::proto_ff::Sheet_mallmall* new_pbmsg(){ return new ::proto_ff::Sheet_mallmall(); }
		static ::proto_ff::Sheet_mallmall make_pbmsg(){ return ::proto_ff::Sheet_mallmall(); }
	};
	typedef struct Sheet_mallmall_s Sheet_mallmall_t;

	struct mallmalltype_s : public NFDescStoreSeqOP {
		mallmalltype_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<32> title;
		NFSizeString<32> tab;
		int32_t groupType;
		int32_t priority;
		int32_t logicType;
		int32_t functionunlock;

		virtual void write_to_pbmsg(::proto_ff::mallmalltype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::mallmalltype & msg);
		static ::proto_ff::mallmalltype* new_pbmsg(){ return new ::proto_ff::mallmalltype(); }
		static ::proto_ff::mallmalltype make_pbmsg(){ return ::proto_ff::mallmalltype(); }
	};
	typedef struct mallmalltype_s mallmalltype_t;

	struct Sheet_mallmalltype_s : public NFDescStoreSeqOP {
		Sheet_mallmalltype_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct mallmalltype_s, 114> mallmalltype_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_mallmalltype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_mallmalltype & msg);
		static ::proto_ff::Sheet_mallmalltype* new_pbmsg(){ return new ::proto_ff::Sheet_mallmalltype(); }
		static ::proto_ff::Sheet_mallmalltype make_pbmsg(){ return ::proto_ff::Sheet_mallmalltype(); }
	};
	typedef struct Sheet_mallmalltype_s Sheet_mallmalltype_t;

}

