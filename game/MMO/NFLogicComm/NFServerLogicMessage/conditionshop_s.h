#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "conditionshop.pb.h"
#include "conditionshop_s.h"

namespace proto_ff_s {

	struct conditionshopconditionshop_s : public NFDescStoreSeqOP {
		conditionshopconditionshop_s();
		int CreateInit();
		int ResumeInit();
		int32_t Id;
		int32_t Type;
		int32_t Time;
		int64_t boxId;
		NFSizeString<60> itemId;
		int32_t type;
		int32_t DiscountPrice;
		NFArray<NFSizeString<60>, 3> ConditionParam;
		NFArray<int32_t, 3> ConditionType;

		virtual void write_to_pbmsg(::proto_ff::conditionshopconditionshop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::conditionshopconditionshop & msg);
		static ::proto_ff::conditionshopconditionshop* new_pbmsg(){ return new ::proto_ff::conditionshopconditionshop(); }
		static ::proto_ff::conditionshopconditionshop make_pbmsg(){ return ::proto_ff::conditionshopconditionshop(); }
	};
	typedef struct conditionshopconditionshop_s conditionshopconditionshop_t;

	struct Sheet_conditionshopconditionshop_s : public NFDescStoreSeqOP {
		Sheet_conditionshopconditionshop_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct conditionshopconditionshop_s, 20> conditionshopconditionshop_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_conditionshopconditionshop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_conditionshopconditionshop & msg);
		static ::proto_ff::Sheet_conditionshopconditionshop* new_pbmsg(){ return new ::proto_ff::Sheet_conditionshopconditionshop(); }
		static ::proto_ff::Sheet_conditionshopconditionshop make_pbmsg(){ return ::proto_ff::Sheet_conditionshopconditionshop(); }
	};
	typedef struct Sheet_conditionshopconditionshop_s Sheet_conditionshopconditionshop_t;

}

