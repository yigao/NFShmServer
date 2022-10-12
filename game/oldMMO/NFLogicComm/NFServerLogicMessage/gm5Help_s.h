#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "gm5Help.pb.h"
#include "gm5Help_s.h"

namespace proto_ff_s {

	struct gm5Helpcons_s : public NFDescStoreSeqOP {
		gm5Helpcons_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t constantdata;
		NFSizeString<60> stringdata;

		virtual void write_to_pbmsg(::proto_ff::gm5Helpcons & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::gm5Helpcons & msg);
		static ::proto_ff::gm5Helpcons* new_pbmsg(){ return new ::proto_ff::gm5Helpcons(); }
		static ::proto_ff::gm5Helpcons make_pbmsg(){ return ::proto_ff::gm5Helpcons(); }
	};
	typedef struct gm5Helpcons_s gm5Helpcons_t;

	struct Sheet_gm5Helpcons_s : public NFDescStoreSeqOP {
		Sheet_gm5Helpcons_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct gm5Helpcons_s, 20> gm5Helpcons_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_gm5Helpcons & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_gm5Helpcons & msg);
		static ::proto_ff::Sheet_gm5Helpcons* new_pbmsg(){ return new ::proto_ff::Sheet_gm5Helpcons(); }
		static ::proto_ff::Sheet_gm5Helpcons make_pbmsg(){ return ::proto_ff::Sheet_gm5Helpcons(); }
	};
	typedef struct Sheet_gm5Helpcons_s Sheet_gm5Helpcons_t;

	struct gm5HelprewardrewardDesc_s : public NFDescStoreSeqOP {
		gm5HelprewardrewardDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t ItemId;
		int32_t num;

		virtual void write_to_pbmsg(::proto_ff::gm5HelprewardrewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::gm5HelprewardrewardDesc & msg);
		static ::proto_ff::gm5HelprewardrewardDesc* new_pbmsg(){ return new ::proto_ff::gm5HelprewardrewardDesc(); }
		static ::proto_ff::gm5HelprewardrewardDesc make_pbmsg(){ return ::proto_ff::gm5HelprewardrewardDesc(); }
	};
	typedef struct gm5HelprewardrewardDesc_s gm5HelprewardrewardDesc_t;

	struct gm5Helpreward_s : public NFDescStoreSeqOP {
		gm5Helpreward_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t rewardType;
		int32_t getNeed;
		NFArray<struct gm5HelprewardrewardDesc_s, 4> reward;

		virtual void write_to_pbmsg(::proto_ff::gm5Helpreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::gm5Helpreward & msg);
		static ::proto_ff::gm5Helpreward* new_pbmsg(){ return new ::proto_ff::gm5Helpreward(); }
		static ::proto_ff::gm5Helpreward make_pbmsg(){ return ::proto_ff::gm5Helpreward(); }
	};
	typedef struct gm5Helpreward_s gm5Helpreward_t;

	struct Sheet_gm5Helpreward_s : public NFDescStoreSeqOP {
		Sheet_gm5Helpreward_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct gm5Helpreward_s, 20> gm5Helpreward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_gm5Helpreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_gm5Helpreward & msg);
		static ::proto_ff::Sheet_gm5Helpreward* new_pbmsg(){ return new ::proto_ff::Sheet_gm5Helpreward(); }
		static ::proto_ff::Sheet_gm5Helpreward make_pbmsg(){ return ::proto_ff::Sheet_gm5Helpreward(); }
	};
	typedef struct Sheet_gm5Helpreward_s Sheet_gm5Helpreward_t;

}

