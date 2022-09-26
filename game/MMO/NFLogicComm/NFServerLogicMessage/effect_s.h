#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "effect.pb.h"
#include "effect_s.h"

namespace proto_ff_s {

	struct effecteffect_s : public NFDescStoreSeqOP {
		effecteffect_s();
		int CreateInit();
		int ResumeInit();
		int32_t effectId;
		int32_t effectType;
		NFSizeString<60> eContent;
		int32_t effectAudio;
		NFArray<int32_t, 5> eparam;

		virtual void write_to_pbmsg(::proto_ff::effecteffect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::effecteffect & msg);
		static ::proto_ff::effecteffect* new_pbmsg(){ return new ::proto_ff::effecteffect(); }
		static ::proto_ff::effecteffect make_pbmsg(){ return ::proto_ff::effecteffect(); }
	};
	typedef struct effecteffect_s effecteffect_t;

	struct Sheet_effecteffect_s : public NFDescStoreSeqOP {
		Sheet_effecteffect_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct effecteffect_s, 2000> effecteffect_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_effecteffect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_effecteffect & msg);
		static ::proto_ff::Sheet_effecteffect* new_pbmsg(){ return new ::proto_ff::Sheet_effecteffect(); }
		static ::proto_ff::Sheet_effecteffect make_pbmsg(){ return ::proto_ff::Sheet_effecteffect(); }
	};
	typedef struct Sheet_effecteffect_s Sheet_effecteffect_t;

}

