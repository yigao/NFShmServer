#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Tasktracker.pb.h"
#include "E_Tasktracker_s.h"

#define DEFINE_SHEET_TASKTRACKERTASKTRACKER_E_TASKTRACKERTASKTRACKER_LIST_MAX_NUM 64


namespace proto_ff_s {

	struct E_TasktrackerTasktracker_s : public NFDescStoreSeqOP {
		E_TasktrackerTasktracker_s();
		virtual ~E_TasktrackerTasktracker_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_comid;//完成条件类型ID
		int32_t m_trueid;//实际完成条件类型ID

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
		NFShmVector<struct E_TasktrackerTasktracker_s, DEFINE_SHEET_TASKTRACKERTASKTRACKER_E_TASKTRACKERTASKTRACKER_LIST_MAX_NUM> E_TasktrackerTasktracker_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TasktrackerTasktracker & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TasktrackerTasktracker & msg);
		static ::proto_ff::Sheet_TasktrackerTasktracker* new_pbmsg(){ return new ::proto_ff::Sheet_TasktrackerTasktracker(); }
		static ::proto_ff::Sheet_TasktrackerTasktracker make_pbmsg(){ return ::proto_ff::Sheet_TasktrackerTasktracker(); }
	};
	typedef struct Sheet_TasktrackerTasktracker_s Sheet_TasktrackerTasktracker_t;

}

