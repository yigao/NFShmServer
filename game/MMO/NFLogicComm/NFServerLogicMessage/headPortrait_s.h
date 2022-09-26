#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "headPortrait.pb.h"
#include "headPortrait_s.h"

namespace proto_ff_s {

	struct headPortraitheadattributeDesc_s : public NFDescStoreSeqOP {
		headPortraitheadattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::headPortraitheadattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::headPortraitheadattributeDesc & msg);
		static ::proto_ff::headPortraitheadattributeDesc* new_pbmsg(){ return new ::proto_ff::headPortraitheadattributeDesc(); }
		static ::proto_ff::headPortraitheadattributeDesc make_pbmsg(){ return ::proto_ff::headPortraitheadattributeDesc(); }
	};
	typedef struct headPortraitheadattributeDesc_s headPortraitheadattributeDesc_t;

	struct headPortraithead_s : public NFDescStoreSeqOP {
		headPortraithead_s();
		int CreateInit();
		int ResumeInit();
		int64_t ID;
		NFSizeString<60> name;
		int32_t quality;
		NFSizeString<60> professionLimit;
		int64_t activationItem;
		int32_t activationNum;
		int64_t starId;
		NFSizeString<200> starNum;
		int32_t starUp;
		int32_t starBer;
		NFArray<struct headPortraitheadattributeDesc_s, 6> attribute;

		virtual void write_to_pbmsg(::proto_ff::headPortraithead & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::headPortraithead & msg);
		static ::proto_ff::headPortraithead* new_pbmsg(){ return new ::proto_ff::headPortraithead(); }
		static ::proto_ff::headPortraithead make_pbmsg(){ return ::proto_ff::headPortraithead(); }
	};
	typedef struct headPortraithead_s headPortraithead_t;

	struct Sheet_headPortraithead_s : public NFDescStoreSeqOP {
		Sheet_headPortraithead_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct headPortraithead_s, 20> headPortraithead_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_headPortraithead & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_headPortraithead & msg);
		static ::proto_ff::Sheet_headPortraithead* new_pbmsg(){ return new ::proto_ff::Sheet_headPortraithead(); }
		static ::proto_ff::Sheet_headPortraithead make_pbmsg(){ return ::proto_ff::Sheet_headPortraithead(); }
	};
	typedef struct Sheet_headPortraithead_s Sheet_headPortraithead_t;

	struct headPortraitframeattributeDesc_s : public NFDescStoreSeqOP {
		headPortraitframeattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::headPortraitframeattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::headPortraitframeattributeDesc & msg);
		static ::proto_ff::headPortraitframeattributeDesc* new_pbmsg(){ return new ::proto_ff::headPortraitframeattributeDesc(); }
		static ::proto_ff::headPortraitframeattributeDesc make_pbmsg(){ return ::proto_ff::headPortraitframeattributeDesc(); }
	};
	typedef struct headPortraitframeattributeDesc_s headPortraitframeattributeDesc_t;

	struct headPortraitframe_s : public NFDescStoreSeqOP {
		headPortraitframe_s();
		int CreateInit();
		int ResumeInit();
		int64_t ID;
		NFSizeString<60> name;
		int32_t quality;
		NFSizeString<60> professionLimit;
		int64_t activationItem;
		int32_t activationNum;
		int64_t starId;
		NFSizeString<200> starNum;
		int32_t starUp;
		int32_t starBer;
		NFArray<struct headPortraitframeattributeDesc_s, 6> attribute;

		virtual void write_to_pbmsg(::proto_ff::headPortraitframe & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::headPortraitframe & msg);
		static ::proto_ff::headPortraitframe* new_pbmsg(){ return new ::proto_ff::headPortraitframe(); }
		static ::proto_ff::headPortraitframe make_pbmsg(){ return ::proto_ff::headPortraitframe(); }
	};
	typedef struct headPortraitframe_s headPortraitframe_t;

	struct Sheet_headPortraitframe_s : public NFDescStoreSeqOP {
		Sheet_headPortraitframe_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct headPortraitframe_s, 20> headPortraitframe_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_headPortraitframe & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_headPortraitframe & msg);
		static ::proto_ff::Sheet_headPortraitframe* new_pbmsg(){ return new ::proto_ff::Sheet_headPortraitframe(); }
		static ::proto_ff::Sheet_headPortraitframe make_pbmsg(){ return ::proto_ff::Sheet_headPortraitframe(); }
	};
	typedef struct Sheet_headPortraitframe_s Sheet_headPortraitframe_t;

	struct headPortraitbubbleattributeDesc_s : public NFDescStoreSeqOP {
		headPortraitbubbleattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::headPortraitbubbleattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::headPortraitbubbleattributeDesc & msg);
		static ::proto_ff::headPortraitbubbleattributeDesc* new_pbmsg(){ return new ::proto_ff::headPortraitbubbleattributeDesc(); }
		static ::proto_ff::headPortraitbubbleattributeDesc make_pbmsg(){ return ::proto_ff::headPortraitbubbleattributeDesc(); }
	};
	typedef struct headPortraitbubbleattributeDesc_s headPortraitbubbleattributeDesc_t;

	struct headPortraitbubble_s : public NFDescStoreSeqOP {
		headPortraitbubble_s();
		int CreateInit();
		int ResumeInit();
		int64_t ID;
		NFSizeString<60> name;
		int32_t quality;
		NFSizeString<60> professionLimit;
		int64_t activationItem;
		int32_t activationNum;
		int64_t starId;
		NFSizeString<200> starNum;
		int32_t starUp;
		int32_t starBer;
		NFArray<struct headPortraitbubbleattributeDesc_s, 6> attribute;

		virtual void write_to_pbmsg(::proto_ff::headPortraitbubble & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::headPortraitbubble & msg);
		static ::proto_ff::headPortraitbubble* new_pbmsg(){ return new ::proto_ff::headPortraitbubble(); }
		static ::proto_ff::headPortraitbubble make_pbmsg(){ return ::proto_ff::headPortraitbubble(); }
	};
	typedef struct headPortraitbubble_s headPortraitbubble_t;

	struct Sheet_headPortraitbubble_s : public NFDescStoreSeqOP {
		Sheet_headPortraitbubble_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct headPortraitbubble_s, 20> headPortraitbubble_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_headPortraitbubble & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_headPortraitbubble & msg);
		static ::proto_ff::Sheet_headPortraitbubble* new_pbmsg(){ return new ::proto_ff::Sheet_headPortraitbubble(); }
		static ::proto_ff::Sheet_headPortraitbubble make_pbmsg(){ return ::proto_ff::Sheet_headPortraitbubble(); }
	};
	typedef struct Sheet_headPortraitbubble_s Sheet_headPortraitbubble_t;

}

