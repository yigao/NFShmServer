#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "offline.pb.h"
#include "offline_s.h"

namespace proto_ff_s {

	struct offlineoffline_s : public NFDescStoreSeqOP {
		offlineoffline_s();
		virtual ~offlineoffline_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int64_t offlineExp;

		virtual void write_to_pbmsg(::proto_ff::offlineoffline & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::offlineoffline & msg);
		static ::proto_ff::offlineoffline* new_pbmsg(){ return new ::proto_ff::offlineoffline(); }
		static ::proto_ff::offlineoffline make_pbmsg(){ return ::proto_ff::offlineoffline(); }
	};
	typedef struct offlineoffline_s offlineoffline_t;

	struct Sheet_offlineoffline_s : public NFDescStoreSeqOP {
		Sheet_offlineoffline_s();
		virtual ~Sheet_offlineoffline_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct offlineoffline_s, 2000> offlineoffline_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_offlineoffline & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_offlineoffline & msg);
		static ::proto_ff::Sheet_offlineoffline* new_pbmsg(){ return new ::proto_ff::Sheet_offlineoffline(); }
		static ::proto_ff::Sheet_offlineoffline make_pbmsg(){ return ::proto_ff::Sheet_offlineoffline(); }
	};
	typedef struct Sheet_offlineoffline_s Sheet_offlineoffline_t;

	struct offlineitemlistitemDesc_s : public NFDescStoreSeqOP {
		offlineitemlistitemDesc_s();
		virtual ~offlineitemlistitemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t Num;
		int32_t Vle;
		int64_t ID;

		virtual void write_to_pbmsg(::proto_ff::offlineitemlistitemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::offlineitemlistitemDesc & msg);
		static ::proto_ff::offlineitemlistitemDesc* new_pbmsg(){ return new ::proto_ff::offlineitemlistitemDesc(); }
		static ::proto_ff::offlineitemlistitemDesc make_pbmsg(){ return ::proto_ff::offlineitemlistitemDesc(); }
	};
	typedef struct offlineitemlistitemDesc_s offlineitemlistitemDesc_t;

	struct offlineitemlist_s : public NFDescStoreSeqOP {
		offlineitemlist_s();
		virtual ~offlineitemlist_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t Lvdown;
		int32_t Lvup;
		int32_t daoju;
		NFArray<struct offlineitemlistitemDesc_s, 22> item;

		virtual void write_to_pbmsg(::proto_ff::offlineitemlist & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::offlineitemlist & msg);
		static ::proto_ff::offlineitemlist* new_pbmsg(){ return new ::proto_ff::offlineitemlist(); }
		static ::proto_ff::offlineitemlist make_pbmsg(){ return ::proto_ff::offlineitemlist(); }
	};
	typedef struct offlineitemlist_s offlineitemlist_t;

	struct Sheet_offlineitemlist_s : public NFDescStoreSeqOP {
		Sheet_offlineitemlist_s();
		virtual ~Sheet_offlineitemlist_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct offlineitemlist_s, 60> offlineitemlist_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_offlineitemlist & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_offlineitemlist & msg);
		static ::proto_ff::Sheet_offlineitemlist* new_pbmsg(){ return new ::proto_ff::Sheet_offlineitemlist(); }
		static ::proto_ff::Sheet_offlineitemlist make_pbmsg(){ return ::proto_ff::Sheet_offlineitemlist(); }
	};
	typedef struct Sheet_offlineitemlist_s Sheet_offlineitemlist_t;

}

