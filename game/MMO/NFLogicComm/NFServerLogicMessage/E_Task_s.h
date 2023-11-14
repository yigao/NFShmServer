#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Task.pb.h"
#include "E_Task_s.h"

#define DEFINE_SHEET_TASKTASK_E_TASKTASK_LIST_MAX_NUM 512


namespace proto_ff_s {

	struct E_TaskTask_s : public NFDescStoreSeqOP {
		E_TaskTask_s();
		virtual ~E_TaskTask_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_minlv;//发放等级
		int32_t m_truelv;//可完成等级
		int32_t m_type;//任务类型
		NFShmString<64> m_showtype;//显示类型
		int32_t m_weights;//排序权重
		NFShmString<64> m_name;//任务名
		NFShmString<64> m_rececond;//接取条件
		NFShmString<64> m_receadd;//过程
		NFShmString<64> m_comcond;//完成条件
		int32_t m_nexttask;//后续任务
		NFShmString<64> m_tracker;//任务追踪
		NFShmString<64> m_subtype;//提交方式
		int32_t m_subnpc;//npc的ID
		int32_t m_subaward;//提交奖励

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
		NFShmVector<struct E_TaskTask_s, DEFINE_SHEET_TASKTASK_E_TASKTASK_LIST_MAX_NUM> E_TaskTask_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TaskTask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TaskTask & msg);
		static ::proto_ff::Sheet_TaskTask* new_pbmsg(){ return new ::proto_ff::Sheet_TaskTask(); }
		static ::proto_ff::Sheet_TaskTask make_pbmsg(){ return ::proto_ff::Sheet_TaskTask(); }
	};
	typedef struct Sheet_TaskTask_s Sheet_TaskTask_t;

}

