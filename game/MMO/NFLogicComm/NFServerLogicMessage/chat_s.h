#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "chat.pb.h"
#include "chat_s.h"

namespace proto_ff_s {

	struct chatchat_s : public NFDescStoreSeqOP {
		chatchat_s();
		int CreateInit();
		int ResumeInit();
		int64_t chatId;
		int32_t chatType;
		int32_t showTime;
		NFSizeString<200> chatContent;
		int32_t channel;
		int32_t CrossService;

		virtual void write_to_pbmsg(::proto_ff::chatchat & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::chatchat & msg);
		static ::proto_ff::chatchat* new_pbmsg(){ return new ::proto_ff::chatchat(); }
		static ::proto_ff::chatchat make_pbmsg(){ return ::proto_ff::chatchat(); }
	};
	typedef struct chatchat_s chatchat_t;

	struct Sheet_chatchat_s : public NFDescStoreSeqOP {
		Sheet_chatchat_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct chatchat_s, 200> chatchat_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_chatchat & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_chatchat & msg);
		static ::proto_ff::Sheet_chatchat* new_pbmsg(){ return new ::proto_ff::Sheet_chatchat(); }
		static ::proto_ff::Sheet_chatchat make_pbmsg(){ return ::proto_ff::Sheet_chatchat(); }
	};
	typedef struct Sheet_chatchat_s Sheet_chatchat_t;

	struct chatspecialchat_s : public NFDescStoreSeqOP {
		chatspecialchat_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		NFSizeString<60> parama;
		NFSizeString<140> paramb;
		int64_t chat_Id;

		virtual void write_to_pbmsg(::proto_ff::chatspecialchat & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::chatspecialchat & msg);
		static ::proto_ff::chatspecialchat* new_pbmsg(){ return new ::proto_ff::chatspecialchat(); }
		static ::proto_ff::chatspecialchat make_pbmsg(){ return ::proto_ff::chatspecialchat(); }
	};
	typedef struct chatspecialchat_s chatspecialchat_t;

	struct Sheet_chatspecialchat_s : public NFDescStoreSeqOP {
		Sheet_chatspecialchat_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct chatspecialchat_s, 20> chatspecialchat_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_chatspecialchat & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_chatspecialchat & msg);
		static ::proto_ff::Sheet_chatspecialchat* new_pbmsg(){ return new ::proto_ff::Sheet_chatspecialchat(); }
		static ::proto_ff::Sheet_chatspecialchat make_pbmsg(){ return ::proto_ff::Sheet_chatspecialchat(); }
	};
	typedef struct Sheet_chatspecialchat_s Sheet_chatspecialchat_t;

}

