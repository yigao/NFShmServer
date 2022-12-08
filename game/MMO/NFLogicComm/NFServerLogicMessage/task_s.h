#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "task.pb.h"
#include "task_s.h"

namespace proto_ff_s {

	struct tasktask_s : public NFDescStoreSeqOP {
		tasktask_s();
		virtual ~tasktask_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t minlv;
		int32_t truelv;
		int32_t type;
		NFShmString<60> showtype;
		int32_t weights;
		NFShmString<60> name;
		NFShmString<60> rececond;
		NFShmString<60> receadd;
		NFShmString<60> comcond;
		int32_t nexttask;
		NFShmString<60> tracker;
		NFShmString<60> subtype;
		int32_t subnpc;
		NFShmString<200> subdesc;
		int32_t subaward;
		NFArray<NFShmString<300>, 4> submsg;

		virtual void write_to_pbmsg(::proto_ff::tasktask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::tasktask & msg);
		static ::proto_ff::tasktask* new_pbmsg(){ return new ::proto_ff::tasktask(); }
		static ::proto_ff::tasktask make_pbmsg(){ return ::proto_ff::tasktask(); }
	};
	typedef struct tasktask_s tasktask_t;

	struct Sheet_tasktask_s : public NFDescStoreSeqOP {
		Sheet_tasktask_s();
		virtual ~Sheet_tasktask_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct tasktask_s, 200> tasktask_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_tasktask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_tasktask & msg);
		static ::proto_ff::Sheet_tasktask* new_pbmsg(){ return new ::proto_ff::Sheet_tasktask(); }
		static ::proto_ff::Sheet_tasktask make_pbmsg(){ return ::proto_ff::Sheet_tasktask(); }
	};
	typedef struct Sheet_tasktask_s Sheet_tasktask_t;

}

