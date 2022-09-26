#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "indultTask.pb.h"
#include "indultTask_s.h"

namespace proto_ff_s {

	struct indultTaskindultTask_s : public NFDescStoreSeqOP {
		indultTaskindultTask_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t order;
		int32_t functionUnlock;
		int64_t boxid;
		NFSizeString<32> taskID;
		int32_t taskNum;

		virtual void write_to_pbmsg(::proto_ff::indultTaskindultTask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::indultTaskindultTask & msg);
		static ::proto_ff::indultTaskindultTask* new_pbmsg(){ return new ::proto_ff::indultTaskindultTask(); }
		static ::proto_ff::indultTaskindultTask make_pbmsg(){ return ::proto_ff::indultTaskindultTask(); }
	};
	typedef struct indultTaskindultTask_s indultTaskindultTask_t;

	struct Sheet_indultTaskindultTask_s : public NFDescStoreSeqOP {
		Sheet_indultTaskindultTask_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct indultTaskindultTask_s, 115> indultTaskindultTask_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_indultTaskindultTask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_indultTaskindultTask & msg);
		static ::proto_ff::Sheet_indultTaskindultTask* new_pbmsg(){ return new ::proto_ff::Sheet_indultTaskindultTask(); }
		static ::proto_ff::Sheet_indultTaskindultTask make_pbmsg(){ return ::proto_ff::Sheet_indultTaskindultTask(); }
	};
	typedef struct Sheet_indultTaskindultTask_s Sheet_indultTaskindultTask_t;

	struct indultTasktask_s : public NFDescStoreSeqOP {
		indultTasktask_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t task;
		NFSizeString<47> taskParam;

		virtual void write_to_pbmsg(::proto_ff::indultTasktask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::indultTasktask & msg);
		static ::proto_ff::indultTasktask* new_pbmsg(){ return new ::proto_ff::indultTasktask(); }
		static ::proto_ff::indultTasktask make_pbmsg(){ return ::proto_ff::indultTasktask(); }
	};
	typedef struct indultTasktask_s indultTasktask_t;

	struct Sheet_indultTasktask_s : public NFDescStoreSeqOP {
		Sheet_indultTasktask_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct indultTasktask_s, 112> indultTasktask_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_indultTasktask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_indultTasktask & msg);
		static ::proto_ff::Sheet_indultTasktask* new_pbmsg(){ return new ::proto_ff::Sheet_indultTasktask(); }
		static ::proto_ff::Sheet_indultTasktask make_pbmsg(){ return ::proto_ff::Sheet_indultTasktask(); }
	};
	typedef struct Sheet_indultTasktask_s Sheet_indultTasktask_t;

}

