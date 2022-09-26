#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "godGM.pb.h"
#include "godGM_s.h"

namespace proto_ff_s {

	struct godGMgodGM_s : public NFDescStoreSeqOP {
		godGMgodGM_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t Time;
		int32_t freeRechargeId;
		int32_t rechargeId;
		int64_t freeBox;
		int64_t rechargeBox;
		NFSizeString<60> freePrivilege;
		NFSizeString<60> payPrivilege;
		int64_t costId;
		int32_t costNum;
		int64_t getId;
		int32_t getNum;
		int32_t exchargeTimes;

		virtual void write_to_pbmsg(::proto_ff::godGMgodGM & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::godGMgodGM & msg);
		static ::proto_ff::godGMgodGM* new_pbmsg(){ return new ::proto_ff::godGMgodGM(); }
		static ::proto_ff::godGMgodGM make_pbmsg(){ return ::proto_ff::godGMgodGM(); }
	};
	typedef struct godGMgodGM_s godGMgodGM_t;

	struct Sheet_godGMgodGM_s : public NFDescStoreSeqOP {
		Sheet_godGMgodGM_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct godGMgodGM_s, 20> godGMgodGM_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_godGMgodGM & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_godGMgodGM & msg);
		static ::proto_ff::Sheet_godGMgodGM* new_pbmsg(){ return new ::proto_ff::Sheet_godGMgodGM(); }
		static ::proto_ff::Sheet_godGMgodGM make_pbmsg(){ return ::proto_ff::Sheet_godGMgodGM(); }
	};
	typedef struct Sheet_godGMgodGM_s Sheet_godGMgodGM_t;

}

