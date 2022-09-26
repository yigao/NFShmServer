#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "serverHorn.pb.h"
#include "serverHorn_s.h"

namespace proto_ff_s {

	struct serverHornserverHorn_s : public NFDescStoreSeqOP {
		serverHornserverHorn_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t time;
		int32_t minTime;
		int64_t itemid;
		int32_t currencyType;
		int32_t currencyCost;

		virtual void write_to_pbmsg(::proto_ff::serverHornserverHorn & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::serverHornserverHorn & msg);
		static ::proto_ff::serverHornserverHorn* new_pbmsg(){ return new ::proto_ff::serverHornserverHorn(); }
		static ::proto_ff::serverHornserverHorn make_pbmsg(){ return ::proto_ff::serverHornserverHorn(); }
	};
	typedef struct serverHornserverHorn_s serverHornserverHorn_t;

	struct Sheet_serverHornserverHorn_s : public NFDescStoreSeqOP {
		Sheet_serverHornserverHorn_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct serverHornserverHorn_s, 107> serverHornserverHorn_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_serverHornserverHorn & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_serverHornserverHorn & msg);
		static ::proto_ff::Sheet_serverHornserverHorn* new_pbmsg(){ return new ::proto_ff::Sheet_serverHornserverHorn(); }
		static ::proto_ff::Sheet_serverHornserverHorn make_pbmsg(){ return ::proto_ff::Sheet_serverHornserverHorn(); }
	};
	typedef struct Sheet_serverHornserverHorn_s Sheet_serverHornserverHorn_t;

}

