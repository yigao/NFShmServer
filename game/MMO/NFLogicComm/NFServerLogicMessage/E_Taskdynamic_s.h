#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Taskdynamic.pb.h"
#include "E_Taskdynamic_s.h"

#define DEFINE_SHEET_TASKDYNAMICTASKDYNAMIC_E_TASKDYNAMICTASKDYNAMIC_LIST_MAX_NUM 32
#define DEFINE_SHEET_TASKDYNAMICTASKCOMCOND_E_TASKDYNAMICTASKCOMCOND_LIST_MAX_NUM 128
#define DEFINE_SHEET_TASKDYNAMICTASKTEXT_E_TASKDYNAMICTASKTEXT_LIST_MAX_NUM 32


namespace proto_ff_s {

	struct E_TaskdynamicTaskdynamic_s : public NFDescStoreSeqOP {
		E_TaskdynamicTaskdynamic_s();
		virtual ~E_TaskdynamicTaskdynamic_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_taskID;//id
		NFShmString<64> m_remark;//策划备注
		int32_t m_taskType;//任务类型
		int32_t m_weights;//权重值
		int32_t m_minlv;//最低等级
		int32_t m_maxlv;//最高等级
		int32_t m_receCount;//可接取数量
		NFShmString<64> m_idList;//抽取id列表

		virtual void write_to_pbmsg(::proto_ff::E_TaskdynamicTaskdynamic & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TaskdynamicTaskdynamic & msg);
		static ::proto_ff::E_TaskdynamicTaskdynamic* new_pbmsg(){ return new ::proto_ff::E_TaskdynamicTaskdynamic(); }
		static ::proto_ff::E_TaskdynamicTaskdynamic make_pbmsg(){ return ::proto_ff::E_TaskdynamicTaskdynamic(); }
	};
	typedef struct E_TaskdynamicTaskdynamic_s E_TaskdynamicTaskdynamic_t;

	struct Sheet_TaskdynamicTaskdynamic_s : public NFDescStoreSeqOP {
		Sheet_TaskdynamicTaskdynamic_s();
		virtual ~Sheet_TaskdynamicTaskdynamic_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TaskdynamicTaskdynamic_s, DEFINE_SHEET_TASKDYNAMICTASKDYNAMIC_E_TASKDYNAMICTASKDYNAMIC_LIST_MAX_NUM> E_TaskdynamicTaskdynamic_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TaskdynamicTaskdynamic & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TaskdynamicTaskdynamic & msg);
		static ::proto_ff::Sheet_TaskdynamicTaskdynamic* new_pbmsg(){ return new ::proto_ff::Sheet_TaskdynamicTaskdynamic(); }
		static ::proto_ff::Sheet_TaskdynamicTaskdynamic make_pbmsg(){ return ::proto_ff::Sheet_TaskdynamicTaskdynamic(); }
	};
	typedef struct Sheet_TaskdynamicTaskdynamic_s Sheet_TaskdynamicTaskdynamic_t;

	struct E_TaskdynamicTaskcomcond_s : public NFDescStoreSeqOP {
		E_TaskdynamicTaskcomcond_s();
		virtual ~E_TaskdynamicTaskcomcond_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_comcondID;//完成id
		int32_t m_comcondType;//条件类型
		int64_t m_param1;//条件参数a
		int64_t m_param2;//条件参数b
		int64_t m_param3;//条件参数c
		int64_t m_param4;//条件参数d
		int64_t m_param5;//条件参数e
		int32_t m_comcondRandomValue;//完成条件随机值

		virtual void write_to_pbmsg(::proto_ff::E_TaskdynamicTaskcomcond & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TaskdynamicTaskcomcond & msg);
		static ::proto_ff::E_TaskdynamicTaskcomcond* new_pbmsg(){ return new ::proto_ff::E_TaskdynamicTaskcomcond(); }
		static ::proto_ff::E_TaskdynamicTaskcomcond make_pbmsg(){ return ::proto_ff::E_TaskdynamicTaskcomcond(); }
	};
	typedef struct E_TaskdynamicTaskcomcond_s E_TaskdynamicTaskcomcond_t;

	struct Sheet_TaskdynamicTaskcomcond_s : public NFDescStoreSeqOP {
		Sheet_TaskdynamicTaskcomcond_s();
		virtual ~Sheet_TaskdynamicTaskcomcond_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TaskdynamicTaskcomcond_s, DEFINE_SHEET_TASKDYNAMICTASKCOMCOND_E_TASKDYNAMICTASKCOMCOND_LIST_MAX_NUM> E_TaskdynamicTaskcomcond_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TaskdynamicTaskcomcond & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TaskdynamicTaskcomcond & msg);
		static ::proto_ff::Sheet_TaskdynamicTaskcomcond* new_pbmsg(){ return new ::proto_ff::Sheet_TaskdynamicTaskcomcond(); }
		static ::proto_ff::Sheet_TaskdynamicTaskcomcond make_pbmsg(){ return ::proto_ff::Sheet_TaskdynamicTaskcomcond(); }
	};
	typedef struct Sheet_TaskdynamicTaskcomcond_s Sheet_TaskdynamicTaskcomcond_t;

	struct E_TaskdynamicTasktext_s : public NFDescStoreSeqOP {
		E_TaskdynamicTasktext_s();
		virtual ~E_TaskdynamicTasktext_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_textID;//文本id
		NFShmString<64> m_taskType;//任务类型
		int32_t m_comcondType;//完成条件类型

		virtual void write_to_pbmsg(::proto_ff::E_TaskdynamicTasktext & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TaskdynamicTasktext & msg);
		static ::proto_ff::E_TaskdynamicTasktext* new_pbmsg(){ return new ::proto_ff::E_TaskdynamicTasktext(); }
		static ::proto_ff::E_TaskdynamicTasktext make_pbmsg(){ return ::proto_ff::E_TaskdynamicTasktext(); }
	};
	typedef struct E_TaskdynamicTasktext_s E_TaskdynamicTasktext_t;

	struct Sheet_TaskdynamicTasktext_s : public NFDescStoreSeqOP {
		Sheet_TaskdynamicTasktext_s();
		virtual ~Sheet_TaskdynamicTasktext_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TaskdynamicTasktext_s, DEFINE_SHEET_TASKDYNAMICTASKTEXT_E_TASKDYNAMICTASKTEXT_LIST_MAX_NUM> E_TaskdynamicTasktext_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TaskdynamicTasktext & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TaskdynamicTasktext & msg);
		static ::proto_ff::Sheet_TaskdynamicTasktext* new_pbmsg(){ return new ::proto_ff::Sheet_TaskdynamicTasktext(); }
		static ::proto_ff::Sheet_TaskdynamicTasktext make_pbmsg(){ return ::proto_ff::Sheet_TaskdynamicTasktext(); }
	};
	typedef struct Sheet_TaskdynamicTasktext_s Sheet_TaskdynamicTasktext_t;

}

