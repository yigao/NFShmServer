#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "vip.pb.h"
#include "vip_s.h"

namespace proto_ff_s {

	struct vipvip_s : public NFDescStoreSeqOP {
		vipvip_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t level;
		int32_t vipType;
		int32_t exp;
		NFSizeString<191> privilege_id;
		int64_t chat;

		virtual void write_to_pbmsg(::proto_ff::vipvip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::vipvip & msg);
		static ::proto_ff::vipvip* new_pbmsg(){ return new ::proto_ff::vipvip(); }
		static ::proto_ff::vipvip make_pbmsg(){ return ::proto_ff::vipvip(); }
	};
	typedef struct vipvip_s vipvip_t;

	struct Sheet_vipvip_s : public NFDescStoreSeqOP {
		Sheet_vipvip_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct vipvip_s, 125> vipvip_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_vipvip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_vipvip & msg);
		static ::proto_ff::Sheet_vipvip* new_pbmsg(){ return new ::proto_ff::Sheet_vipvip(); }
		static ::proto_ff::Sheet_vipvip make_pbmsg(){ return ::proto_ff::Sheet_vipvip(); }
	};
	typedef struct Sheet_vipvip_s Sheet_vipvip_t;

	struct vipprivilege_s : public NFDescStoreSeqOP {
		vipprivilege_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t type;
		NFSizeString<32> canshuString;

		virtual void write_to_pbmsg(::proto_ff::vipprivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::vipprivilege & msg);
		static ::proto_ff::vipprivilege* new_pbmsg(){ return new ::proto_ff::vipprivilege(); }
		static ::proto_ff::vipprivilege make_pbmsg(){ return ::proto_ff::vipprivilege(); }
	};
	typedef struct vipprivilege_s vipprivilege_t;

	struct Sheet_vipprivilege_s : public NFDescStoreSeqOP {
		Sheet_vipprivilege_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct vipprivilege_s, 469> vipprivilege_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_vipprivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_vipprivilege & msg);
		static ::proto_ff::Sheet_vipprivilege* new_pbmsg(){ return new ::proto_ff::Sheet_vipprivilege(); }
		static ::proto_ff::Sheet_vipprivilege make_pbmsg(){ return ::proto_ff::Sheet_vipprivilege(); }
	};
	typedef struct Sheet_vipprivilege_s Sheet_vipprivilege_t;

	struct vipgift_s : public NFDescStoreSeqOP {
		vipgift_s();
		int CreateInit();
		int ResumeInit();
		int64_t ID;
		int32_t Type;
		int32_t VipLv;
		int32_t moneyType;
		int32_t OriginalPrice;
		int32_t Price;
		int64_t boxid;

		virtual void write_to_pbmsg(::proto_ff::vipgift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::vipgift & msg);
		static ::proto_ff::vipgift* new_pbmsg(){ return new ::proto_ff::vipgift(); }
		static ::proto_ff::vipgift make_pbmsg(){ return ::proto_ff::vipgift(); }
	};
	typedef struct vipgift_s vipgift_t;

	struct Sheet_vipgift_s : public NFDescStoreSeqOP {
		Sheet_vipgift_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct vipgift_s, 144> vipgift_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_vipgift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_vipgift & msg);
		static ::proto_ff::Sheet_vipgift* new_pbmsg(){ return new ::proto_ff::Sheet_vipgift(); }
		static ::proto_ff::Sheet_vipgift make_pbmsg(){ return ::proto_ff::Sheet_vipgift(); }
	};
	typedef struct Sheet_vipgift_s Sheet_vipgift_t;

}

