#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "functionunlock.pb.h"
#include "functionunlock_s.h"

namespace proto_ff_s {

	struct functionunlockfunctionUnlock_s : public NFDescStoreSeqOP {
		functionunlockfunctionUnlock_s();
		virtual ~functionunlockfunctionUnlock_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t functionId;
		int32_t openDaily;
		int32_t openType;
		int64_t openVal;
		int32_t iconOpenVal;
		int32_t belong;

		virtual void write_to_pbmsg(::proto_ff::functionunlockfunctionUnlock & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::functionunlockfunctionUnlock & msg);
		static ::proto_ff::functionunlockfunctionUnlock* new_pbmsg(){ return new ::proto_ff::functionunlockfunctionUnlock(); }
		static ::proto_ff::functionunlockfunctionUnlock make_pbmsg(){ return ::proto_ff::functionunlockfunctionUnlock(); }
	};
	typedef struct functionunlockfunctionUnlock_s functionunlockfunctionUnlock_t;

	struct Sheet_functionunlockfunctionUnlock_s : public NFDescStoreSeqOP {
		Sheet_functionunlockfunctionUnlock_s();
		virtual ~Sheet_functionunlockfunctionUnlock_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct functionunlockfunctionUnlock_s, 200> functionunlockfunctionUnlock_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_functionunlockfunctionUnlock & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_functionunlockfunctionUnlock & msg);
		static ::proto_ff::Sheet_functionunlockfunctionUnlock* new_pbmsg(){ return new ::proto_ff::Sheet_functionunlockfunctionUnlock(); }
		static ::proto_ff::Sheet_functionunlockfunctionUnlock make_pbmsg(){ return ::proto_ff::Sheet_functionunlockfunctionUnlock(); }
	};
	typedef struct Sheet_functionunlockfunctionUnlock_s Sheet_functionunlockfunctionUnlock_t;

	struct functionunlockpreview_s : public NFDescStoreSeqOP {
		functionunlockpreview_s();
		virtual ~functionunlockpreview_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t functionId;
		int32_t rewardItem;
		int32_t rewardNum;

		virtual void write_to_pbmsg(::proto_ff::functionunlockpreview & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::functionunlockpreview & msg);
		static ::proto_ff::functionunlockpreview* new_pbmsg(){ return new ::proto_ff::functionunlockpreview(); }
		static ::proto_ff::functionunlockpreview make_pbmsg(){ return ::proto_ff::functionunlockpreview(); }
	};
	typedef struct functionunlockpreview_s functionunlockpreview_t;

	struct Sheet_functionunlockpreview_s : public NFDescStoreSeqOP {
		Sheet_functionunlockpreview_s();
		virtual ~Sheet_functionunlockpreview_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct functionunlockpreview_s, 20> functionunlockpreview_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_functionunlockpreview & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_functionunlockpreview & msg);
		static ::proto_ff::Sheet_functionunlockpreview* new_pbmsg(){ return new ::proto_ff::Sheet_functionunlockpreview(); }
		static ::proto_ff::Sheet_functionunlockpreview make_pbmsg(){ return ::proto_ff::Sheet_functionunlockpreview(); }
	};
	typedef struct Sheet_functionunlockpreview_s Sheet_functionunlockpreview_t;

}

