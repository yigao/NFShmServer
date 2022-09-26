#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "button.pb.h"
#include "button_s.h"

namespace proto_ff_s {

	struct buttonbutton_s : public NFDescStoreSeqOP {
		buttonbutton_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t time;

		virtual void write_to_pbmsg(::proto_ff::buttonbutton & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::buttonbutton & msg);
		static ::proto_ff::buttonbutton* new_pbmsg(){ return new ::proto_ff::buttonbutton(); }
		static ::proto_ff::buttonbutton make_pbmsg(){ return ::proto_ff::buttonbutton(); }
	};
	typedef struct buttonbutton_s buttonbutton_t;

	struct Sheet_buttonbutton_s : public NFDescStoreSeqOP {
		Sheet_buttonbutton_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct buttonbutton_s, 80> buttonbutton_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_buttonbutton & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_buttonbutton & msg);
		static ::proto_ff::Sheet_buttonbutton* new_pbmsg(){ return new ::proto_ff::Sheet_buttonbutton(); }
		static ::proto_ff::Sheet_buttonbutton make_pbmsg(){ return ::proto_ff::Sheet_buttonbutton(); }
	};
	typedef struct Sheet_buttonbutton_s Sheet_buttonbutton_t;

}

