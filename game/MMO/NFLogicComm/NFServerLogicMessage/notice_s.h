#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "notice.pb.h"
#include "notice_s.h"

namespace proto_ff_s {

	struct noticenotice_s : public NFDescStoreSeqOP {
		noticenotice_s();
		int CreateInit();
		int ResumeInit();
		int32_t noticeId;
		int32_t noitceOnoff;
		int32_t noticeType;
		NFSizeString<60> openCycle;
		NFSizeString<60> time;
		int32_t levelRequire;
		NFSizeString<60> endDay;
		NFSizeString<60> startDay;
		NFSizeString<60> noticeTitle;
		NFSizeString<120> noticeContent;

		virtual void write_to_pbmsg(::proto_ff::noticenotice & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::noticenotice & msg);
		static ::proto_ff::noticenotice* new_pbmsg(){ return new ::proto_ff::noticenotice(); }
		static ::proto_ff::noticenotice make_pbmsg(){ return ::proto_ff::noticenotice(); }
	};
	typedef struct noticenotice_s noticenotice_t;

	struct Sheet_noticenotice_s : public NFDescStoreSeqOP {
		Sheet_noticenotice_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct noticenotice_s, 20> noticenotice_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_noticenotice & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_noticenotice & msg);
		static ::proto_ff::Sheet_noticenotice* new_pbmsg(){ return new ::proto_ff::Sheet_noticenotice(); }
		static ::proto_ff::Sheet_noticenotice make_pbmsg(){ return ::proto_ff::Sheet_noticenotice(); }
	};
	typedef struct Sheet_noticenotice_s Sheet_noticenotice_t;

}

