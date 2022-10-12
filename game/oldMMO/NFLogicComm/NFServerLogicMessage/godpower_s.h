#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "godpower.pb.h"
#include "godpower_s.h"

namespace proto_ff_s {

	struct godpowergodpower_s : public NFDescStoreSeqOP {
		godpowergodpower_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t boxid;
		int32_t price;
		int32_t times;
		int32_t unlock;

		virtual void write_to_pbmsg(::proto_ff::godpowergodpower & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::godpowergodpower & msg);
		static ::proto_ff::godpowergodpower* new_pbmsg(){ return new ::proto_ff::godpowergodpower(); }
		static ::proto_ff::godpowergodpower make_pbmsg(){ return ::proto_ff::godpowergodpower(); }
	};
	typedef struct godpowergodpower_s godpowergodpower_t;

	struct Sheet_godpowergodpower_s : public NFDescStoreSeqOP {
		Sheet_godpowergodpower_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct godpowergodpower_s, 20> godpowergodpower_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_godpowergodpower & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_godpowergodpower & msg);
		static ::proto_ff::Sheet_godpowergodpower* new_pbmsg(){ return new ::proto_ff::Sheet_godpowergodpower(); }
		static ::proto_ff::Sheet_godpowergodpower make_pbmsg(){ return ::proto_ff::Sheet_godpowergodpower(); }
	};
	typedef struct Sheet_godpowergodpower_s Sheet_godpowergodpower_t;

	struct godpowerskillupdateattributeDesc_s : public NFDescStoreSeqOP {
		godpowerskillupdateattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int64_t value;

		virtual void write_to_pbmsg(::proto_ff::godpowerskillupdateattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::godpowerskillupdateattributeDesc & msg);
		static ::proto_ff::godpowerskillupdateattributeDesc* new_pbmsg(){ return new ::proto_ff::godpowerskillupdateattributeDesc(); }
		static ::proto_ff::godpowerskillupdateattributeDesc make_pbmsg(){ return ::proto_ff::godpowerskillupdateattributeDesc(); }
	};
	typedef struct godpowerskillupdateattributeDesc_s godpowerskillupdateattributeDesc_t;

	struct godpowerskillupdate_s : public NFDescStoreSeqOP {
		godpowerskillupdate_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t tableID;
		int32_t lv;
		int64_t itemID;
		int32_t itemNum;
		int64_t skillID;
		int32_t isBreak;
		int32_t unlock;
		NFArray<struct godpowerskillupdateattributeDesc_s, 2> attribute;

		virtual void write_to_pbmsg(::proto_ff::godpowerskillupdate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::godpowerskillupdate & msg);
		static ::proto_ff::godpowerskillupdate* new_pbmsg(){ return new ::proto_ff::godpowerskillupdate(); }
		static ::proto_ff::godpowerskillupdate make_pbmsg(){ return ::proto_ff::godpowerskillupdate(); }
	};
	typedef struct godpowerskillupdate_s godpowerskillupdate_t;

	struct Sheet_godpowerskillupdate_s : public NFDescStoreSeqOP {
		Sheet_godpowerskillupdate_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct godpowerskillupdate_s, 300> godpowerskillupdate_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_godpowerskillupdate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_godpowerskillupdate & msg);
		static ::proto_ff::Sheet_godpowerskillupdate* new_pbmsg(){ return new ::proto_ff::Sheet_godpowerskillupdate(); }
		static ::proto_ff::Sheet_godpowerskillupdate make_pbmsg(){ return ::proto_ff::Sheet_godpowerskillupdate(); }
	};
	typedef struct Sheet_godpowerskillupdate_s Sheet_godpowerskillupdate_t;

}

