#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "task.pb.h"
#include "task_s.h"

namespace proto_ff_s {

	struct E_TaskTask_s : public NFDescStoreSeqOP {
		E_TaskTask_s();
		virtual ~E_TaskTask_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_minlv;
		int32_t m_truelv;
		int32_t m_type;
		NFShmString<60> m_showtype;
		int32_t m_weights;
		NFShmString<60> m_name;
		NFShmString<60> m_rececond;
		NFShmString<60> m_receadd;
		NFShmString<80> m_comcond;
		int32_t m_nexttask;
		NFShmString<60> m_tracker;
		NFShmString<60> m_subtype;
		int32_t m_subnpc;
		NFShmString<200> m_subdesc;
		int32_t m_subaward;
		NFShmVector<NFShmString<300>, 4> m_submsg;

		virtual void write_to_pbmsg(::proto_ff::E_TaskTask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TaskTask & msg);
		static ::proto_ff::E_TaskTask* new_pbmsg(){ return new ::proto_ff::E_TaskTask(); }
		static ::proto_ff::E_TaskTask make_pbmsg(){ return ::proto_ff::E_TaskTask(); }
	};
	typedef struct E_TaskTask_s E_TaskTask_t;

	struct Sheet_TaskTask_s : public NFDescStoreSeqOP {
		Sheet_TaskTask_s();
		virtual ~Sheet_TaskTask_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TaskTask_s, 200> E_TaskTask_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_TaskTask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TaskTask & msg);
		static ::proto_ff::Sheet_TaskTask* new_pbmsg(){ return new ::proto_ff::Sheet_TaskTask(); }
		static ::proto_ff::Sheet_TaskTask make_pbmsg(){ return ::proto_ff::Sheet_TaskTask(); }
	};
	typedef struct Sheet_TaskTask_s Sheet_TaskTask_t;

}

