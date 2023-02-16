#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "chat.pb.h"
#include "chat_s.h"

namespace proto_ff_s {

	struct E_ChatChat_s : public NFDescStoreSeqOP {
		E_ChatChat_s();
		virtual ~E_ChatChat_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_chatid;
		int32_t m_chattype;
		int32_t m_showtime;
		NFShmString<200> m_chatcontent;
		int32_t m_channel;
		int32_t m_crossservice;

		virtual void write_to_pbmsg(::proto_ff::E_ChatChat & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ChatChat & msg);
		static ::proto_ff::E_ChatChat* new_pbmsg(){ return new ::proto_ff::E_ChatChat(); }
		static ::proto_ff::E_ChatChat make_pbmsg(){ return ::proto_ff::E_ChatChat(); }
	};
	typedef struct E_ChatChat_s E_ChatChat_t;

	struct Sheet_ChatChat_s : public NFDescStoreSeqOP {
		Sheet_ChatChat_s();
		virtual ~Sheet_ChatChat_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ChatChat_s, 40> E_ChatChat_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_ChatChat & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ChatChat & msg);
		static ::proto_ff::Sheet_ChatChat* new_pbmsg(){ return new ::proto_ff::Sheet_ChatChat(); }
		static ::proto_ff::Sheet_ChatChat make_pbmsg(){ return ::proto_ff::Sheet_ChatChat(); }
	};
	typedef struct Sheet_ChatChat_s Sheet_ChatChat_t;

	struct E_ChatSpecialchat_s : public NFDescStoreSeqOP {
		E_ChatSpecialchat_s();
		virtual ~E_ChatSpecialchat_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		NFShmString<60> m_parama;
		NFShmString<140> m_paramb;
		int64_t m_chat_id;

		virtual void write_to_pbmsg(::proto_ff::E_ChatSpecialchat & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ChatSpecialchat & msg);
		static ::proto_ff::E_ChatSpecialchat* new_pbmsg(){ return new ::proto_ff::E_ChatSpecialchat(); }
		static ::proto_ff::E_ChatSpecialchat make_pbmsg(){ return ::proto_ff::E_ChatSpecialchat(); }
	};
	typedef struct E_ChatSpecialchat_s E_ChatSpecialchat_t;

	struct Sheet_ChatSpecialchat_s : public NFDescStoreSeqOP {
		Sheet_ChatSpecialchat_s();
		virtual ~Sheet_ChatSpecialchat_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ChatSpecialchat_s, 20> E_ChatSpecialchat_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_ChatSpecialchat & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ChatSpecialchat & msg);
		static ::proto_ff::Sheet_ChatSpecialchat* new_pbmsg(){ return new ::proto_ff::Sheet_ChatSpecialchat(); }
		static ::proto_ff::Sheet_ChatSpecialchat make_pbmsg(){ return ::proto_ff::Sheet_ChatSpecialchat(); }
	};
	typedef struct Sheet_ChatSpecialchat_s Sheet_ChatSpecialchat_t;

}

