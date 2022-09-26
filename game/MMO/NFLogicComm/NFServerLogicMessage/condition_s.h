#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "condition.pb.h"
#include "condition_s.h"

namespace proto_ff_s {

	struct conditionconditionconditionDesc_s : public NFDescStoreSeqOP {
		conditionconditionconditionDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Type;
		int32_t Param;

		virtual void write_to_pbmsg(::proto_ff::conditionconditionconditionDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::conditionconditionconditionDesc & msg);
		static ::proto_ff::conditionconditionconditionDesc* new_pbmsg(){ return new ::proto_ff::conditionconditionconditionDesc(); }
		static ::proto_ff::conditionconditionconditionDesc make_pbmsg(){ return ::proto_ff::conditionconditionconditionDesc(); }
	};
	typedef struct conditionconditionconditionDesc_s conditionconditionconditionDesc_t;

	struct conditioncondition_s : public NFDescStoreSeqOP {
		conditioncondition_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFArray<struct conditionconditionconditionDesc_s, 3> condition;

		virtual void write_to_pbmsg(::proto_ff::conditioncondition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::conditioncondition & msg);
		static ::proto_ff::conditioncondition* new_pbmsg(){ return new ::proto_ff::conditioncondition(); }
		static ::proto_ff::conditioncondition make_pbmsg(){ return ::proto_ff::conditioncondition(); }
	};
	typedef struct conditioncondition_s conditioncondition_t;

	struct Sheet_conditioncondition_s : public NFDescStoreSeqOP {
		Sheet_conditioncondition_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct conditioncondition_s, 125> conditioncondition_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_conditioncondition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_conditioncondition & msg);
		static ::proto_ff::Sheet_conditioncondition* new_pbmsg(){ return new ::proto_ff::Sheet_conditioncondition(); }
		static ::proto_ff::Sheet_conditioncondition make_pbmsg(){ return ::proto_ff::Sheet_conditioncondition(); }
	};
	typedef struct Sheet_conditioncondition_s Sheet_conditioncondition_t;

}

