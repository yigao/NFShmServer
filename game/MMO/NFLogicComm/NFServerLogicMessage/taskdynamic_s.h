#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "taskdynamic.pb.h"
#include "taskdynamic_s.h"

namespace proto_ff_s {

	struct taskdynamictaskdynamic_s : public NFDescStoreSeqOP {
		taskdynamictaskdynamic_s();
		virtual ~taskdynamictaskdynamic_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t taskID;
		NFShmString<60> remark;
		int32_t taskType;
		int32_t minlv;
		int32_t maxlv;
		int32_t receCount;
		NFShmString<60> idList;

		virtual void write_to_pbmsg(::proto_ff::taskdynamictaskdynamic & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::taskdynamictaskdynamic & msg);
		static ::proto_ff::taskdynamictaskdynamic* new_pbmsg(){ return new ::proto_ff::taskdynamictaskdynamic(); }
		static ::proto_ff::taskdynamictaskdynamic make_pbmsg(){ return ::proto_ff::taskdynamictaskdynamic(); }
	};
	typedef struct taskdynamictaskdynamic_s taskdynamictaskdynamic_t;

	struct Sheet_taskdynamictaskdynamic_s : public NFDescStoreSeqOP {
		Sheet_taskdynamictaskdynamic_s();
		virtual ~Sheet_taskdynamictaskdynamic_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct taskdynamictaskdynamic_s, 20> taskdynamictaskdynamic_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_taskdynamictaskdynamic & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_taskdynamictaskdynamic & msg);
		static ::proto_ff::Sheet_taskdynamictaskdynamic* new_pbmsg(){ return new ::proto_ff::Sheet_taskdynamictaskdynamic(); }
		static ::proto_ff::Sheet_taskdynamictaskdynamic make_pbmsg(){ return ::proto_ff::Sheet_taskdynamictaskdynamic(); }
	};
	typedef struct Sheet_taskdynamictaskdynamic_s Sheet_taskdynamictaskdynamic_t;

	struct taskdynamictaskcomcond_s : public NFDescStoreSeqOP {
		taskdynamictaskcomcond_s();
		virtual ~taskdynamictaskcomcond_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t comcondID;
		int32_t comcondType;
		int64_t param1;
		int64_t param2;
		int64_t param3;
		int64_t param4;
		int64_t param5;
		int32_t comcondRandomValue;

		virtual void write_to_pbmsg(::proto_ff::taskdynamictaskcomcond & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::taskdynamictaskcomcond & msg);
		static ::proto_ff::taskdynamictaskcomcond* new_pbmsg(){ return new ::proto_ff::taskdynamictaskcomcond(); }
		static ::proto_ff::taskdynamictaskcomcond make_pbmsg(){ return ::proto_ff::taskdynamictaskcomcond(); }
	};
	typedef struct taskdynamictaskcomcond_s taskdynamictaskcomcond_t;

	struct Sheet_taskdynamictaskcomcond_s : public NFDescStoreSeqOP {
		Sheet_taskdynamictaskcomcond_s();
		virtual ~Sheet_taskdynamictaskcomcond_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct taskdynamictaskcomcond_s, 20> taskdynamictaskcomcond_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_taskdynamictaskcomcond & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_taskdynamictaskcomcond & msg);
		static ::proto_ff::Sheet_taskdynamictaskcomcond* new_pbmsg(){ return new ::proto_ff::Sheet_taskdynamictaskcomcond(); }
		static ::proto_ff::Sheet_taskdynamictaskcomcond make_pbmsg(){ return ::proto_ff::Sheet_taskdynamictaskcomcond(); }
	};
	typedef struct Sheet_taskdynamictaskcomcond_s Sheet_taskdynamictaskcomcond_t;

	struct taskdynamictasktext_s : public NFDescStoreSeqOP {
		taskdynamictasktext_s();
		virtual ~taskdynamictasktext_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t textID;
		NFShmString<60> taskType;
		int32_t comcondType;

		virtual void write_to_pbmsg(::proto_ff::taskdynamictasktext & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::taskdynamictasktext & msg);
		static ::proto_ff::taskdynamictasktext* new_pbmsg(){ return new ::proto_ff::taskdynamictasktext(); }
		static ::proto_ff::taskdynamictasktext make_pbmsg(){ return ::proto_ff::taskdynamictasktext(); }
	};
	typedef struct taskdynamictasktext_s taskdynamictasktext_t;

	struct Sheet_taskdynamictasktext_s : public NFDescStoreSeqOP {
		Sheet_taskdynamictasktext_s();
		virtual ~Sheet_taskdynamictasktext_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct taskdynamictasktext_s, 20> taskdynamictasktext_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_taskdynamictasktext & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_taskdynamictasktext & msg);
		static ::proto_ff::Sheet_taskdynamictasktext* new_pbmsg(){ return new ::proto_ff::Sheet_taskdynamictasktext(); }
		static ::proto_ff::Sheet_taskdynamictasktext make_pbmsg(){ return ::proto_ff::Sheet_taskdynamictasktext(); }
	};
	typedef struct Sheet_taskdynamictasktext_s Sheet_taskdynamictasktext_t;

}

