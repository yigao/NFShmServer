#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "sensitiveword.pb.h"
#include "sensitiveword_s.h"

namespace proto_ff_s {

	struct sensitivewordsensitive_word_s : public NFDescStoreSeqOP {
		sensitivewordsensitive_word_s();
		virtual ~sensitivewordsensitive_word_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFShmString<60> sensitiveWord;

		virtual void write_to_pbmsg(::proto_ff::sensitivewordsensitive_word & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::sensitivewordsensitive_word & msg);
		static ::proto_ff::sensitivewordsensitive_word* new_pbmsg(){ return new ::proto_ff::sensitivewordsensitive_word(); }
		static ::proto_ff::sensitivewordsensitive_word make_pbmsg(){ return ::proto_ff::sensitivewordsensitive_word(); }
	};
	typedef struct sensitivewordsensitive_word_s sensitivewordsensitive_word_t;

	struct Sheet_sensitivewordsensitive_word_s : public NFDescStoreSeqOP {
		Sheet_sensitivewordsensitive_word_s();
		virtual ~Sheet_sensitivewordsensitive_word_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct sensitivewordsensitive_word_s, 6000> sensitivewordsensitive_word_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_sensitivewordsensitive_word & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_sensitivewordsensitive_word & msg);
		static ::proto_ff::Sheet_sensitivewordsensitive_word* new_pbmsg(){ return new ::proto_ff::Sheet_sensitivewordsensitive_word(); }
		static ::proto_ff::Sheet_sensitivewordsensitive_word make_pbmsg(){ return ::proto_ff::Sheet_sensitivewordsensitive_word(); }
	};
	typedef struct Sheet_sensitivewordsensitive_word_s Sheet_sensitivewordsensitive_word_t;

	struct sensitivewordrolesensitive_s : public NFDescStoreSeqOP {
		sensitivewordrolesensitive_s();
		virtual ~sensitivewordrolesensitive_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFShmString<60> sensitiveWord;

		virtual void write_to_pbmsg(::proto_ff::sensitivewordrolesensitive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::sensitivewordrolesensitive & msg);
		static ::proto_ff::sensitivewordrolesensitive* new_pbmsg(){ return new ::proto_ff::sensitivewordrolesensitive(); }
		static ::proto_ff::sensitivewordrolesensitive make_pbmsg(){ return ::proto_ff::sensitivewordrolesensitive(); }
	};
	typedef struct sensitivewordrolesensitive_s sensitivewordrolesensitive_t;

	struct Sheet_sensitivewordrolesensitive_s : public NFDescStoreSeqOP {
		Sheet_sensitivewordrolesensitive_s();
		virtual ~Sheet_sensitivewordrolesensitive_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct sensitivewordrolesensitive_s, 300> sensitivewordrolesensitive_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_sensitivewordrolesensitive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_sensitivewordrolesensitive & msg);
		static ::proto_ff::Sheet_sensitivewordrolesensitive* new_pbmsg(){ return new ::proto_ff::Sheet_sensitivewordrolesensitive(); }
		static ::proto_ff::Sheet_sensitivewordrolesensitive make_pbmsg(){ return ::proto_ff::Sheet_sensitivewordrolesensitive(); }
	};
	typedef struct Sheet_sensitivewordrolesensitive_s Sheet_sensitivewordrolesensitive_t;

}

