#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "taskdynamic.pb.h"
#include "taskdynamic_s.h"

#define DEFINE_SHEET_TASKDYNAMICTASKDYNAMIC_E_TASKDYNAMICTASKDYNAMIC_LIST_MAX_NUM 20
#define DEFINE_SHEET_TASKDYNAMICTASKCOMCOND_E_TASKDYNAMICTASKCOMCOND_LIST_MAX_NUM 20
#define DEFINE_SHEET_TASKDYNAMICTASKTEXT_E_TASKDYNAMICTASKTEXT_LIST_MAX_NUM 60
namespace proto_ff_s {

	struct E_TaskdynamicTaskdynamic_s : public NFDescStoreSeqOP {
		E_TaskdynamicTaskdynamic_s();
		virtual ~E_TaskdynamicTaskdynamic_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_taskid;
		NFShmString<60> m_remark;
		int32_t m_tasktype;
		int32_t m_minlv;
		int32_t m_maxlv;
		int32_t m_rececount;
		NFShmString<60> m_idlist;

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
		NFShmVector<struct E_TaskdynamicTaskdynamic_s, DEFINE_SHEET_TASKDYNAMICTASKDYNAMIC_E_TASKDYNAMICTASKDYNAMIC_LIST_MAX_NUM> E_TaskdynamicTaskdynamic_List;

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
		int64_t m_comcondid;
		int32_t m_comcondtype;
		int64_t m_param1;
		int64_t m_param2;
		int64_t m_param3;
		int64_t m_param4;
		int64_t m_param5;
		int32_t m_comcondrandomvalue;

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
		NFShmVector<struct E_TaskdynamicTaskcomcond_s, DEFINE_SHEET_TASKDYNAMICTASKCOMCOND_E_TASKDYNAMICTASKCOMCOND_LIST_MAX_NUM> E_TaskdynamicTaskcomcond_List;

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
		int64_t m_textid;
		NFShmString<60> m_tasktype;
		int32_t m_comcondtype;

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
		NFShmVector<struct E_TaskdynamicTasktext_s, DEFINE_SHEET_TASKDYNAMICTASKTEXT_E_TASKDYNAMICTASKTEXT_LIST_MAX_NUM> E_TaskdynamicTasktext_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_TaskdynamicTasktext & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TaskdynamicTasktext & msg);
		static ::proto_ff::Sheet_TaskdynamicTasktext* new_pbmsg(){ return new ::proto_ff::Sheet_TaskdynamicTasktext(); }
		static ::proto_ff::Sheet_TaskdynamicTasktext make_pbmsg(){ return ::proto_ff::Sheet_TaskdynamicTasktext(); }
	};
	typedef struct Sheet_TaskdynamicTasktext_s Sheet_TaskdynamicTasktext_t;

}

