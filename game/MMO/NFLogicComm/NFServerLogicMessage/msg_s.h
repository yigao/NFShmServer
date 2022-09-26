#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "msg.pb.h"
#include "msg_s.h"

namespace proto_ff_s {

	struct msgphpmsg_s : public NFDescStoreSeqOP {
		msgphpmsg_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<160> content;
		NFSizeString<60> note;

		virtual void write_to_pbmsg(::proto_ff::msgphpmsg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::msgphpmsg & msg);
		static ::proto_ff::msgphpmsg* new_pbmsg(){ return new ::proto_ff::msgphpmsg(); }
		static ::proto_ff::msgphpmsg make_pbmsg(){ return ::proto_ff::msgphpmsg(); }
	};
	typedef struct msgphpmsg_s msgphpmsg_t;

	struct Sheet_msgphpmsg_s : public NFDescStoreSeqOP {
		Sheet_msgphpmsg_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct msgphpmsg_s, 200> msgphpmsg_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_msgphpmsg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_msgphpmsg & msg);
		static ::proto_ff::Sheet_msgphpmsg* new_pbmsg(){ return new ::proto_ff::Sheet_msgphpmsg(); }
		static ::proto_ff::Sheet_msgphpmsg make_pbmsg(){ return ::proto_ff::Sheet_msgphpmsg(); }
	};
	typedef struct Sheet_msgphpmsg_s Sheet_msgphpmsg_t;

}

