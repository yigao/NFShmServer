#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "vip.pb.h"
#include "vip_s.h"

namespace proto_ff_s {

	struct vipvip_s : public NFDescStoreSeqOP {
		vipvip_s();
		virtual ~vipvip_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t level;
		int32_t exp;
		int32_t privilege_group;

		virtual void write_to_pbmsg(::proto_ff::vipvip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::vipvip & msg);
		static ::proto_ff::vipvip* new_pbmsg(){ return new ::proto_ff::vipvip(); }
		static ::proto_ff::vipvip make_pbmsg(){ return ::proto_ff::vipvip(); }
	};
	typedef struct vipvip_s vipvip_t;

	struct Sheet_vipvip_s : public NFDescStoreSeqOP {
		Sheet_vipvip_s();
		virtual ~Sheet_vipvip_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct vipvip_s, 20> vipvip_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_vipvip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_vipvip & msg);
		static ::proto_ff::Sheet_vipvip* new_pbmsg(){ return new ::proto_ff::Sheet_vipvip(); }
		static ::proto_ff::Sheet_vipvip make_pbmsg(){ return ::proto_ff::Sheet_vipvip(); }
	};
	typedef struct Sheet_vipvip_s Sheet_vipvip_t;

	struct vipprivilege_s : public NFDescStoreSeqOP {
		vipprivilege_s();
		virtual ~vipprivilege_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t group;
		int32_t type;
		int32_t arg;
		NFShmString<60> args;

		virtual void write_to_pbmsg(::proto_ff::vipprivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::vipprivilege & msg);
		static ::proto_ff::vipprivilege* new_pbmsg(){ return new ::proto_ff::vipprivilege(); }
		static ::proto_ff::vipprivilege make_pbmsg(){ return ::proto_ff::vipprivilege(); }
	};
	typedef struct vipprivilege_s vipprivilege_t;

	struct Sheet_vipprivilege_s : public NFDescStoreSeqOP {
		Sheet_vipprivilege_s();
		virtual ~Sheet_vipprivilege_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct vipprivilege_s, 60> vipprivilege_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_vipprivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_vipprivilege & msg);
		static ::proto_ff::Sheet_vipprivilege* new_pbmsg(){ return new ::proto_ff::Sheet_vipprivilege(); }
		static ::proto_ff::Sheet_vipprivilege make_pbmsg(){ return ::proto_ff::Sheet_vipprivilege(); }
	};
	typedef struct Sheet_vipprivilege_s Sheet_vipprivilege_t;

}

