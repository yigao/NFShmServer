#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "perActivity.pb.h"
#include "perActivity_s.h"

namespace proto_ff_s {

	struct perActivityperActivity_s : public NFDescStoreSeqOP {
		perActivityperActivity_s();
		virtual ~perActivityperActivity_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t activeId;
		NFShmString<60> activeName;
		int32_t typeId;
		int32_t functionID;
		NFShmString<60> opeDay;
		NFShmString<60> closeDay;
		int32_t serverdelayTime;
		int32_t serverTime;
		int32_t openingTime;
		int32_t advanceTime;
		int32_t intervalTime;
		int32_t isCross;

		virtual void write_to_pbmsg(::proto_ff::perActivityperActivity & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::perActivityperActivity & msg);
		static ::proto_ff::perActivityperActivity* new_pbmsg(){ return new ::proto_ff::perActivityperActivity(); }
		static ::proto_ff::perActivityperActivity make_pbmsg(){ return ::proto_ff::perActivityperActivity(); }
	};
	typedef struct perActivityperActivity_s perActivityperActivity_t;

	struct Sheet_perActivityperActivity_s : public NFDescStoreSeqOP {
		Sheet_perActivityperActivity_s();
		virtual ~Sheet_perActivityperActivity_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct perActivityperActivity_s, 20> perActivityperActivity_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_perActivityperActivity & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_perActivityperActivity & msg);
		static ::proto_ff::Sheet_perActivityperActivity* new_pbmsg(){ return new ::proto_ff::Sheet_perActivityperActivity(); }
		static ::proto_ff::Sheet_perActivityperActivity make_pbmsg(){ return ::proto_ff::Sheet_perActivityperActivity(); }
	};
	typedef struct Sheet_perActivityperActivity_s Sheet_perActivityperActivity_t;

	struct perActivityweek_s : public NFDescStoreSeqOP {
		perActivityweek_s();
		virtual ~perActivityweek_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFShmString<60> time;
		NFArray<NFShmString<60>, 7> week;

		virtual void write_to_pbmsg(::proto_ff::perActivityweek & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::perActivityweek & msg);
		static ::proto_ff::perActivityweek* new_pbmsg(){ return new ::proto_ff::perActivityweek(); }
		static ::proto_ff::perActivityweek make_pbmsg(){ return ::proto_ff::perActivityweek(); }
	};
	typedef struct perActivityweek_s perActivityweek_t;

	struct Sheet_perActivityweek_s : public NFDescStoreSeqOP {
		Sheet_perActivityweek_s();
		virtual ~Sheet_perActivityweek_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct perActivityweek_s, 20> perActivityweek_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_perActivityweek & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_perActivityweek & msg);
		static ::proto_ff::Sheet_perActivityweek* new_pbmsg(){ return new ::proto_ff::Sheet_perActivityweek(); }
		static ::proto_ff::Sheet_perActivityweek make_pbmsg(){ return ::proto_ff::Sheet_perActivityweek(); }
	};
	typedef struct Sheet_perActivityweek_s Sheet_perActivityweek_t;

}

