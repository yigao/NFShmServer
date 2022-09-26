#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "ai.pb.h"
#include "ai_s.h"

namespace proto_ff_s {

	struct aiaihpDesc_s : public NFDescStoreSeqOP {
		aiaihpDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t skill;
		int32_t percent;
		int64_t chat;

		virtual void write_to_pbmsg(::proto_ff::aiaihpDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::aiaihpDesc & msg);
		static ::proto_ff::aiaihpDesc* new_pbmsg(){ return new ::proto_ff::aiaihpDesc(); }
		static ::proto_ff::aiaihpDesc make_pbmsg(){ return ::proto_ff::aiaihpDesc(); }
	};
	typedef struct aiaihpDesc_s aiaihpDesc_t;

	struct aiai_s : public NFDescStoreSeqOP {
		aiai_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t type;
		NFSizeString<32> deadHateRemain;
		NFSizeString<32> invisibleRemain;
		int32_t isActive;
		int32_t returnType;
		int32_t view;
		int32_t isAttackedShowOff;
		int32_t pursueRange;
		int32_t actionRange;
		int32_t wakeupRadius;
		int32_t isAIWorkWhenNobody;
		int32_t bornEffectAIDelay;
		NFSizeString<74> initSkills;
		NFArray<struct aiaihpDesc_s, 2> hp;

		virtual void write_to_pbmsg(::proto_ff::aiai & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::aiai & msg);
		static ::proto_ff::aiai* new_pbmsg(){ return new ::proto_ff::aiai(); }
		static ::proto_ff::aiai make_pbmsg(){ return ::proto_ff::aiai(); }
	};
	typedef struct aiai_s aiai_t;

	struct Sheet_aiai_s : public NFDescStoreSeqOP {
		Sheet_aiai_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct aiai_s, 166> aiai_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_aiai & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_aiai & msg);
		static ::proto_ff::Sheet_aiai* new_pbmsg(){ return new ::proto_ff::Sheet_aiai(); }
		static ::proto_ff::Sheet_aiai make_pbmsg(){ return ::proto_ff::Sheet_aiai(); }
	};
	typedef struct Sheet_aiai_s Sheet_aiai_t;

}

