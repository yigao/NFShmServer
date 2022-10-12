#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "tasktracker.pb.h"
#include "tasktracker_s.h"

namespace proto_ff_s {

	struct tasktrackertasktracker_s : public NFDescStoreSeqOP {
		tasktrackertasktracker_s();
		int CreateInit();
		int ResumeInit();
		int32_t comID;
		int32_t trueID;

		virtual void write_to_pbmsg(::proto_ff::tasktrackertasktracker & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::tasktrackertasktracker & msg);
		static ::proto_ff::tasktrackertasktracker* new_pbmsg(){ return new ::proto_ff::tasktrackertasktracker(); }
		static ::proto_ff::tasktrackertasktracker make_pbmsg(){ return ::proto_ff::tasktrackertasktracker(); }
	};
	typedef struct tasktrackertasktracker_s tasktrackertasktracker_t;

	struct Sheet_tasktrackertasktracker_s : public NFDescStoreSeqOP {
		Sheet_tasktrackertasktracker_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct tasktrackertasktracker_s, 60> tasktrackertasktracker_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_tasktrackertasktracker & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_tasktrackertasktracker & msg);
		static ::proto_ff::Sheet_tasktrackertasktracker* new_pbmsg(){ return new ::proto_ff::Sheet_tasktrackertasktracker(); }
		static ::proto_ff::Sheet_tasktrackertasktracker make_pbmsg(){ return ::proto_ff::Sheet_tasktrackertasktracker(); }
	};
	typedef struct Sheet_tasktrackertasktracker_s Sheet_tasktrackertasktracker_t;

}

