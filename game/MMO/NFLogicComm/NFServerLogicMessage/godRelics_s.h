#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "godRelics.pb.h"
#include "godRelics_s.h"

namespace proto_ff_s {

	struct godRelicsgodRelics_s : public NFDescStoreSeqOP {
		godRelicsgodRelics_s();
		virtual ~godRelicsgodRelics_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t functionId;
		int32_t group;
		int32_t skillID;

		virtual void write_to_pbmsg(::proto_ff::godRelicsgodRelics & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::godRelicsgodRelics & msg);
		static ::proto_ff::godRelicsgodRelics* new_pbmsg(){ return new ::proto_ff::godRelicsgodRelics(); }
		static ::proto_ff::godRelicsgodRelics make_pbmsg(){ return ::proto_ff::godRelicsgodRelics(); }
	};
	typedef struct godRelicsgodRelics_s godRelicsgodRelics_t;

	struct Sheet_godRelicsgodRelics_s : public NFDescStoreSeqOP {
		Sheet_godRelicsgodRelics_s();
		virtual ~Sheet_godRelicsgodRelics_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct godRelicsgodRelics_s, 20> godRelicsgodRelics_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_godRelicsgodRelics & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_godRelicsgodRelics & msg);
		static ::proto_ff::Sheet_godRelicsgodRelics* new_pbmsg(){ return new ::proto_ff::Sheet_godRelicsgodRelics(); }
		static ::proto_ff::Sheet_godRelicsgodRelics make_pbmsg(){ return ::proto_ff::Sheet_godRelicsgodRelics(); }
	};
	typedef struct Sheet_godRelicsgodRelics_s Sheet_godRelicsgodRelics_t;

	struct godRelicscondition_s : public NFDescStoreSeqOP {
		godRelicscondition_s();
		virtual ~godRelicscondition_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t group;
		int32_t conditon;
		NFShmString<60> parama;
		int32_t count;
		int32_t rewardItem;
		int32_t rewardNumber;

		virtual void write_to_pbmsg(::proto_ff::godRelicscondition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::godRelicscondition & msg);
		static ::proto_ff::godRelicscondition* new_pbmsg(){ return new ::proto_ff::godRelicscondition(); }
		static ::proto_ff::godRelicscondition make_pbmsg(){ return ::proto_ff::godRelicscondition(); }
	};
	typedef struct godRelicscondition_s godRelicscondition_t;

	struct Sheet_godRelicscondition_s : public NFDescStoreSeqOP {
		Sheet_godRelicscondition_s();
		virtual ~Sheet_godRelicscondition_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct godRelicscondition_s, 20> godRelicscondition_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_godRelicscondition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_godRelicscondition & msg);
		static ::proto_ff::Sheet_godRelicscondition* new_pbmsg(){ return new ::proto_ff::Sheet_godRelicscondition(); }
		static ::proto_ff::Sheet_godRelicscondition make_pbmsg(){ return ::proto_ff::Sheet_godRelicscondition(); }
	};
	typedef struct Sheet_godRelicscondition_s Sheet_godRelicscondition_t;

}

