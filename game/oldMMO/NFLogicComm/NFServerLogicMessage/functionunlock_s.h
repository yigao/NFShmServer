#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "functionunlock.pb.h"
#include "functionunlock_s.h"

namespace proto_ff_s {

	struct functionunlockfunctionUnlock_s : public NFDescStoreSeqOP {
		functionunlockfunctionUnlock_s();
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
		int CreateInit();
		int ResumeInit();
		NFArray<struct functionunlockfunctionUnlock_s, 300> functionunlockfunctionUnlock_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_functionunlockfunctionUnlock & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_functionunlockfunctionUnlock & msg);
		static ::proto_ff::Sheet_functionunlockfunctionUnlock* new_pbmsg(){ return new ::proto_ff::Sheet_functionunlockfunctionUnlock(); }
		static ::proto_ff::Sheet_functionunlockfunctionUnlock make_pbmsg(){ return ::proto_ff::Sheet_functionunlockfunctionUnlock(); }
	};
	typedef struct Sheet_functionunlockfunctionUnlock_s Sheet_functionunlockfunctionUnlock_t;

}

