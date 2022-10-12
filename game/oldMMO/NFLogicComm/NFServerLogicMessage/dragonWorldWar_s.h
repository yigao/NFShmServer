#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "dragonWorldWar.pb.h"
#include "dragonWorldWar_s.h"

namespace proto_ff_s {

	struct dragonWorldWarconstants_s : public NFDescStoreSeqOP {
		dragonWorldWarconstants_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t valuedata;
		NFSizeString<200> stringdata;

		virtual void write_to_pbmsg(::proto_ff::dragonWorldWarconstants & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dragonWorldWarconstants & msg);
		static ::proto_ff::dragonWorldWarconstants* new_pbmsg(){ return new ::proto_ff::dragonWorldWarconstants(); }
		static ::proto_ff::dragonWorldWarconstants make_pbmsg(){ return ::proto_ff::dragonWorldWarconstants(); }
	};
	typedef struct dragonWorldWarconstants_s dragonWorldWarconstants_t;

	struct Sheet_dragonWorldWarconstants_s : public NFDescStoreSeqOP {
		Sheet_dragonWorldWarconstants_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct dragonWorldWarconstants_s, 20> dragonWorldWarconstants_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_dragonWorldWarconstants & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_dragonWorldWarconstants & msg);
		static ::proto_ff::Sheet_dragonWorldWarconstants* new_pbmsg(){ return new ::proto_ff::Sheet_dragonWorldWarconstants(); }
		static ::proto_ff::Sheet_dragonWorldWarconstants make_pbmsg(){ return ::proto_ff::Sheet_dragonWorldWarconstants(); }
	};
	typedef struct Sheet_dragonWorldWarconstants_s Sheet_dragonWorldWarconstants_t;

	struct dragonWorldWargoldskill_s : public NFDescStoreSeqOP {
		dragonWorldWargoldskill_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t type;
		int32_t goldmin;
		int64_t skillId;

		virtual void write_to_pbmsg(::proto_ff::dragonWorldWargoldskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dragonWorldWargoldskill & msg);
		static ::proto_ff::dragonWorldWargoldskill* new_pbmsg(){ return new ::proto_ff::dragonWorldWargoldskill(); }
		static ::proto_ff::dragonWorldWargoldskill make_pbmsg(){ return ::proto_ff::dragonWorldWargoldskill(); }
	};
	typedef struct dragonWorldWargoldskill_s dragonWorldWargoldskill_t;

	struct Sheet_dragonWorldWargoldskill_s : public NFDescStoreSeqOP {
		Sheet_dragonWorldWargoldskill_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct dragonWorldWargoldskill_s, 20> dragonWorldWargoldskill_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_dragonWorldWargoldskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_dragonWorldWargoldskill & msg);
		static ::proto_ff::Sheet_dragonWorldWargoldskill* new_pbmsg(){ return new ::proto_ff::Sheet_dragonWorldWargoldskill(); }
		static ::proto_ff::Sheet_dragonWorldWargoldskill make_pbmsg(){ return ::proto_ff::Sheet_dragonWorldWargoldskill(); }
	};
	typedef struct Sheet_dragonWorldWargoldskill_s Sheet_dragonWorldWargoldskill_t;

	struct dragonWorldWargoldShop_s : public NFDescStoreSeqOP {
		dragonWorldWargoldShop_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int64_t itemId;
		int32_t itemNum;
		int32_t itemPrice;
		int32_t weight;

		virtual void write_to_pbmsg(::proto_ff::dragonWorldWargoldShop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dragonWorldWargoldShop & msg);
		static ::proto_ff::dragonWorldWargoldShop* new_pbmsg(){ return new ::proto_ff::dragonWorldWargoldShop(); }
		static ::proto_ff::dragonWorldWargoldShop make_pbmsg(){ return ::proto_ff::dragonWorldWargoldShop(); }
	};
	typedef struct dragonWorldWargoldShop_s dragonWorldWargoldShop_t;

	struct Sheet_dragonWorldWargoldShop_s : public NFDescStoreSeqOP {
		Sheet_dragonWorldWargoldShop_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct dragonWorldWargoldShop_s, 60> dragonWorldWargoldShop_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_dragonWorldWargoldShop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_dragonWorldWargoldShop & msg);
		static ::proto_ff::Sheet_dragonWorldWargoldShop* new_pbmsg(){ return new ::proto_ff::Sheet_dragonWorldWargoldShop(); }
		static ::proto_ff::Sheet_dragonWorldWargoldShop make_pbmsg(){ return ::proto_ff::Sheet_dragonWorldWargoldShop(); }
	};
	typedef struct Sheet_dragonWorldWargoldShop_s Sheet_dragonWorldWargoldShop_t;

}

