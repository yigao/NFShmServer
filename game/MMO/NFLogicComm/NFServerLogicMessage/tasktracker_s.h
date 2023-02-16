#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "tasktracker.pb.h"
#include "tasktracker_s.h"

namespace proto_ff_s {

	struct E_TasktrackerTasktracker_s : public NFDescStoreSeqOP {
		E_TasktrackerTasktracker_s();
		virtual ~E_TasktrackerTasktracker_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_comid;
		int32_t m_trueid;

		virtual void write_to_pbmsg(::proto_ff::E_TasktrackerTasktracker & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TasktrackerTasktracker & msg);
		static ::proto_ff::E_TasktrackerTasktracker* new_pbmsg(){ return new ::proto_ff::E_TasktrackerTasktracker(); }
		static ::proto_ff::E_TasktrackerTasktracker make_pbmsg(){ return ::proto_ff::E_TasktrackerTasktracker(); }
	};
	typedef struct E_TasktrackerTasktracker_s E_TasktrackerTasktracker_t;

	struct Sheet_TasktrackerTasktracker_s : public NFDescStoreSeqOP {
		Sheet_TasktrackerTasktracker_s();
		virtual ~Sheet_TasktrackerTasktracker_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TasktrackerTasktracker_s, 60> E_TasktrackerTasktracker_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_TasktrackerTasktracker & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TasktrackerTasktracker & msg);
		static ::proto_ff::Sheet_TasktrackerTasktracker* new_pbmsg(){ return new ::proto_ff::Sheet_TasktrackerTasktracker(); }
		static ::proto_ff::Sheet_TasktrackerTasktracker make_pbmsg(){ return ::proto_ff::Sheet_TasktrackerTasktracker(); }
	};
	typedef struct Sheet_TasktrackerTasktracker_s Sheet_TasktrackerTasktracker_t;

}

