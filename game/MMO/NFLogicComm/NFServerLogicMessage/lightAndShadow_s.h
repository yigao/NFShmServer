#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "lightAndShadow.pb.h"
#include "lightAndShadow_s.h"

namespace proto_ff_s {

	struct lightAndShadowcons_s : public NFDescStoreSeqOP {
		lightAndShadowcons_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int64_t valuedata;
		NFSizeString<47> stringdata;

		virtual void write_to_pbmsg(::proto_ff::lightAndShadowcons & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::lightAndShadowcons & msg);
		static ::proto_ff::lightAndShadowcons* new_pbmsg(){ return new ::proto_ff::lightAndShadowcons(); }
		static ::proto_ff::lightAndShadowcons make_pbmsg(){ return ::proto_ff::lightAndShadowcons(); }
	};
	typedef struct lightAndShadowcons_s lightAndShadowcons_t;

	struct Sheet_lightAndShadowcons_s : public NFDescStoreSeqOP {
		Sheet_lightAndShadowcons_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct lightAndShadowcons_s, 121> lightAndShadowcons_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_lightAndShadowcons & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_lightAndShadowcons & msg);
		static ::proto_ff::Sheet_lightAndShadowcons* new_pbmsg(){ return new ::proto_ff::Sheet_lightAndShadowcons(); }
		static ::proto_ff::Sheet_lightAndShadowcons make_pbmsg(){ return ::proto_ff::Sheet_lightAndShadowcons(); }
	};
	typedef struct Sheet_lightAndShadowcons_s Sheet_lightAndShadowcons_t;

	struct lightAndShadowreward_s : public NFDescStoreSeqOP {
		lightAndShadowreward_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t goldMin;
		int32_t goldMax;
		int64_t winReward;
		int32_t winRewardNum;
		int64_t loseReward;
		int32_t loseRewardNum;

		virtual void write_to_pbmsg(::proto_ff::lightAndShadowreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::lightAndShadowreward & msg);
		static ::proto_ff::lightAndShadowreward* new_pbmsg(){ return new ::proto_ff::lightAndShadowreward(); }
		static ::proto_ff::lightAndShadowreward make_pbmsg(){ return ::proto_ff::lightAndShadowreward(); }
	};
	typedef struct lightAndShadowreward_s lightAndShadowreward_t;

	struct Sheet_lightAndShadowreward_s : public NFDescStoreSeqOP {
		Sheet_lightAndShadowreward_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct lightAndShadowreward_s, 110> lightAndShadowreward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_lightAndShadowreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_lightAndShadowreward & msg);
		static ::proto_ff::Sheet_lightAndShadowreward* new_pbmsg(){ return new ::proto_ff::Sheet_lightAndShadowreward(); }
		static ::proto_ff::Sheet_lightAndShadowreward make_pbmsg(){ return ::proto_ff::Sheet_lightAndShadowreward(); }
	};
	typedef struct Sheet_lightAndShadowreward_s Sheet_lightAndShadowreward_t;

}

