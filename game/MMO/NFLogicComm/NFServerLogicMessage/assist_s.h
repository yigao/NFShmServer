#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "assist.pb.h"
#include "assist_s.h"

namespace proto_ff_s {

	struct E_AssistAssistbox_s : public NFDescStoreSeqOP {
		E_AssistAssistbox_s();
		virtual ~E_AssistAssistbox_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_times;
		int32_t m_itemid;

		virtual void write_to_pbmsg(::proto_ff::E_AssistAssistbox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AssistAssistbox & msg);
		static ::proto_ff::E_AssistAssistbox* new_pbmsg(){ return new ::proto_ff::E_AssistAssistbox(); }
		static ::proto_ff::E_AssistAssistbox make_pbmsg(){ return ::proto_ff::E_AssistAssistbox(); }
	};
	typedef struct E_AssistAssistbox_s E_AssistAssistbox_t;

	struct Sheet_AssistAssistbox_s : public NFDescStoreSeqOP {
		Sheet_AssistAssistbox_s();
		virtual ~Sheet_AssistAssistbox_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AssistAssistbox_s, 20> E_AssistAssistbox_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_AssistAssistbox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AssistAssistbox & msg);
		static ::proto_ff::Sheet_AssistAssistbox* new_pbmsg(){ return new ::proto_ff::Sheet_AssistAssistbox(); }
		static ::proto_ff::Sheet_AssistAssistbox make_pbmsg(){ return ::proto_ff::Sheet_AssistAssistbox(); }
	};
	typedef struct Sheet_AssistAssistbox_s Sheet_AssistAssistbox_t;

	struct E_AssistAssistthank_s : public NFDescStoreSeqOP {
		E_AssistAssistthank_s();
		virtual ~E_AssistAssistthank_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmString<60> m_msg;

		virtual void write_to_pbmsg(::proto_ff::E_AssistAssistthank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AssistAssistthank & msg);
		static ::proto_ff::E_AssistAssistthank* new_pbmsg(){ return new ::proto_ff::E_AssistAssistthank(); }
		static ::proto_ff::E_AssistAssistthank make_pbmsg(){ return ::proto_ff::E_AssistAssistthank(); }
	};
	typedef struct E_AssistAssistthank_s E_AssistAssistthank_t;

	struct Sheet_AssistAssistthank_s : public NFDescStoreSeqOP {
		Sheet_AssistAssistthank_s();
		virtual ~Sheet_AssistAssistthank_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AssistAssistthank_s, 20> E_AssistAssistthank_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_AssistAssistthank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AssistAssistthank & msg);
		static ::proto_ff::Sheet_AssistAssistthank* new_pbmsg(){ return new ::proto_ff::Sheet_AssistAssistthank(); }
		static ::proto_ff::Sheet_AssistAssistthank make_pbmsg(){ return ::proto_ff::Sheet_AssistAssistthank(); }
	};
	typedef struct Sheet_AssistAssistthank_s Sheet_AssistAssistthank_t;

}

