#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "msg.pb.h"
#include "msg_s.h"

namespace proto_ff_s {

	struct E_MsgPhpmsg_s : public NFDescStoreSeqOP {
		E_MsgPhpmsg_s();
		virtual ~E_MsgPhpmsg_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmString<160> m_content;
		NFShmString<60> m_note;

		virtual void write_to_pbmsg(::proto_ff::E_MsgPhpmsg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MsgPhpmsg & msg);
		static ::proto_ff::E_MsgPhpmsg* new_pbmsg(){ return new ::proto_ff::E_MsgPhpmsg(); }
		static ::proto_ff::E_MsgPhpmsg make_pbmsg(){ return ::proto_ff::E_MsgPhpmsg(); }
	};
	typedef struct E_MsgPhpmsg_s E_MsgPhpmsg_t;

	struct Sheet_MsgPhpmsg_s : public NFDescStoreSeqOP {
		Sheet_MsgPhpmsg_s();
		virtual ~Sheet_MsgPhpmsg_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MsgPhpmsg_s, 200> E_MsgPhpmsg_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MsgPhpmsg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MsgPhpmsg & msg);
		static ::proto_ff::Sheet_MsgPhpmsg* new_pbmsg(){ return new ::proto_ff::Sheet_MsgPhpmsg(); }
		static ::proto_ff::Sheet_MsgPhpmsg make_pbmsg(){ return ::proto_ff::Sheet_MsgPhpmsg(); }
	};
	typedef struct Sheet_MsgPhpmsg_s Sheet_MsgPhpmsg_t;

}

