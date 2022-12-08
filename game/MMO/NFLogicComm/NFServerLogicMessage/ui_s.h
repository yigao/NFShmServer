#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "ui.pb.h"
#include "ui_s.h"

namespace proto_ff_s {

	struct uieffect_s : public NFDescStoreSeqOP {
		uieffect_s();
		virtual ~uieffect_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t time;

		virtual void write_to_pbmsg(::proto_ff::uieffect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::uieffect & msg);
		static ::proto_ff::uieffect* new_pbmsg(){ return new ::proto_ff::uieffect(); }
		static ::proto_ff::uieffect make_pbmsg(){ return ::proto_ff::uieffect(); }
	};
	typedef struct uieffect_s uieffect_t;

	struct Sheet_uieffect_s : public NFDescStoreSeqOP {
		Sheet_uieffect_s();
		virtual ~Sheet_uieffect_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct uieffect_s, 20> uieffect_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_uieffect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_uieffect & msg);
		static ::proto_ff::Sheet_uieffect* new_pbmsg(){ return new ::proto_ff::Sheet_uieffect(); }
		static ::proto_ff::Sheet_uieffect make_pbmsg(){ return ::proto_ff::Sheet_uieffect(); }
	};
	typedef struct Sheet_uieffect_s Sheet_uieffect_t;

}

