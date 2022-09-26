#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "attribute.pb.h"
#include "attribute_s.h"

namespace proto_ff_s {

	struct attributeattribute_s : public NFDescStoreSeqOP {
		attributeattribute_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t percent;
		float power;

		virtual void write_to_pbmsg(::proto_ff::attributeattribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::attributeattribute & msg);
		static ::proto_ff::attributeattribute* new_pbmsg(){ return new ::proto_ff::attributeattribute(); }
		static ::proto_ff::attributeattribute make_pbmsg(){ return ::proto_ff::attributeattribute(); }
	};
	typedef struct attributeattribute_s attributeattribute_t;

	struct Sheet_attributeattribute_s : public NFDescStoreSeqOP {
		Sheet_attributeattribute_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct attributeattribute_s, 200> attributeattribute_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_attributeattribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_attributeattribute & msg);
		static ::proto_ff::Sheet_attributeattribute* new_pbmsg(){ return new ::proto_ff::Sheet_attributeattribute(); }
		static ::proto_ff::Sheet_attributeattribute make_pbmsg(){ return ::proto_ff::Sheet_attributeattribute(); }
	};
	typedef struct Sheet_attributeattribute_s Sheet_attributeattribute_t;

	struct attributesuppress_s : public NFDescStoreSeqOP {
		attributesuppress_s();
		int CreateInit();
		int ResumeInit();
		int32_t lvlDiff;
		int32_t hitSupPve;
		int32_t critSupPve;
		int32_t killSupPve;
		int32_t stateSupPve;
		int32_t lvSupPve;
		int32_t hitSupPvp;
		int32_t critSupPvp;
		int32_t killSupPvp;
		int32_t stateSupPvp;
		int32_t lvSupPvp;

		virtual void write_to_pbmsg(::proto_ff::attributesuppress & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::attributesuppress & msg);
		static ::proto_ff::attributesuppress* new_pbmsg(){ return new ::proto_ff::attributesuppress(); }
		static ::proto_ff::attributesuppress make_pbmsg(){ return ::proto_ff::attributesuppress(); }
	};
	typedef struct attributesuppress_s attributesuppress_t;

	struct Sheet_attributesuppress_s : public NFDescStoreSeqOP {
		Sheet_attributesuppress_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct attributesuppress_s, 600> attributesuppress_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_attributesuppress & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_attributesuppress & msg);
		static ::proto_ff::Sheet_attributesuppress* new_pbmsg(){ return new ::proto_ff::Sheet_attributesuppress(); }
		static ::proto_ff::Sheet_attributesuppress make_pbmsg(){ return ::proto_ff::Sheet_attributesuppress(); }
	};
	typedef struct Sheet_attributesuppress_s Sheet_attributesuppress_t;

	struct attributepowersup_s : public NFDescStoreSeqOP {
		attributepowersup_s();
		int CreateInit();
		int ResumeInit();
		int32_t powerDiff;
		int32_t powerSupPve;
		int32_t powerSupPvp;

		virtual void write_to_pbmsg(::proto_ff::attributepowersup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::attributepowersup & msg);
		static ::proto_ff::attributepowersup* new_pbmsg(){ return new ::proto_ff::attributepowersup(); }
		static ::proto_ff::attributepowersup make_pbmsg(){ return ::proto_ff::attributepowersup(); }
	};
	typedef struct attributepowersup_s attributepowersup_t;

	struct Sheet_attributepowersup_s : public NFDescStoreSeqOP {
		Sheet_attributepowersup_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct attributepowersup_s, 200> attributepowersup_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_attributepowersup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_attributepowersup & msg);
		static ::proto_ff::Sheet_attributepowersup* new_pbmsg(){ return new ::proto_ff::Sheet_attributepowersup(); }
		static ::proto_ff::Sheet_attributepowersup make_pbmsg(){ return ::proto_ff::Sheet_attributepowersup(); }
	};
	typedef struct Sheet_attributepowersup_s Sheet_attributepowersup_t;

}

