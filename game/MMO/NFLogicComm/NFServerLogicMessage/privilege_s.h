#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "privilege.pb.h"
#include "privilege_s.h"

namespace proto_ff_s {

	struct privilegeprivilege_s : public NFDescStoreSeqOP {
		privilegeprivilege_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t showType;
		int32_t type;
		int32_t param;
		NFSizeString<32> severParam;
		int64_t openReward;
		int64_t dailyReward;
		int32_t resourceLimit;
		int64_t skillid;
		NFSizeString<47> privilege_id;

		virtual void write_to_pbmsg(::proto_ff::privilegeprivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::privilegeprivilege & msg);
		static ::proto_ff::privilegeprivilege* new_pbmsg(){ return new ::proto_ff::privilegeprivilege(); }
		static ::proto_ff::privilegeprivilege make_pbmsg(){ return ::proto_ff::privilegeprivilege(); }
	};
	typedef struct privilegeprivilege_s privilegeprivilege_t;

	struct Sheet_privilegeprivilege_s : public NFDescStoreSeqOP {
		Sheet_privilegeprivilege_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct privilegeprivilege_s, 111> privilegeprivilege_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_privilegeprivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_privilegeprivilege & msg);
		static ::proto_ff::Sheet_privilegeprivilege* new_pbmsg(){ return new ::proto_ff::Sheet_privilegeprivilege(); }
		static ::proto_ff::Sheet_privilegeprivilege make_pbmsg(){ return ::proto_ff::Sheet_privilegeprivilege(); }
	};
	typedef struct Sheet_privilegeprivilege_s Sheet_privilegeprivilege_t;

}

