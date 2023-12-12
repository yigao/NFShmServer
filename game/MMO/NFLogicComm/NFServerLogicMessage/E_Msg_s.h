#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Msg.pb.h"
#include "E_Msg_s.h"

#define DEFINE_SHEET_MSGPHPMSG_E_MSGPHPMSG_LIST_MAX_NUM 128


namespace proto_ff_s {

	struct E_MsgPhpmsg_s : public NFDescStoreSeqOP {
		E_MsgPhpmsg_s();
		virtual ~E_MsgPhpmsg_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//下标
		NFShmString<128> m_content;//显示信息
		NFShmString<64> m_note;//备注

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
		NFShmVector<struct E_MsgPhpmsg_s, DEFINE_SHEET_MSGPHPMSG_E_MSGPHPMSG_LIST_MAX_NUM> E_MsgPhpmsg_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MsgPhpmsg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MsgPhpmsg & msg);
		static ::proto_ff::Sheet_MsgPhpmsg* new_pbmsg(){ return new ::proto_ff::Sheet_MsgPhpmsg(); }
		static ::proto_ff::Sheet_MsgPhpmsg make_pbmsg(){ return ::proto_ff::Sheet_MsgPhpmsg(); }
	};
	typedef struct Sheet_MsgPhpmsg_s Sheet_MsgPhpmsg_t;

}

