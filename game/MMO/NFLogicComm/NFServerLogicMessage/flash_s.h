#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "flash.pb.h"
#include "flash_s.h"

namespace proto_ff_s {

	struct flashflashmonsterDesc_s : public NFDescStoreSeqOP {
		flashflashmonsterDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Num;
		int64_t ID;

		virtual void write_to_pbmsg(::proto_ff::flashflashmonsterDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::flashflashmonsterDesc & msg);
		static ::proto_ff::flashflashmonsterDesc* new_pbmsg(){ return new ::proto_ff::flashflashmonsterDesc(); }
		static ::proto_ff::flashflashmonsterDesc make_pbmsg(){ return ::proto_ff::flashflashmonsterDesc(); }
	};
	typedef struct flashflashmonsterDesc_s flashflashmonsterDesc_t;

	struct flashflash_s : public NFDescStoreSeqOP {
		flashflash_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int64_t typeID;
		int32_t monster_Type;
		int32_t isLevelDynamic;
		int32_t miniLevel;
		int32_t levelCheck;
		int32_t monsterRefreshTime;
		int64_t facePath;
		NFArray<struct flashflashmonsterDesc_s, 5> monster;

		virtual void write_to_pbmsg(::proto_ff::flashflash & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::flashflash & msg);
		static ::proto_ff::flashflash* new_pbmsg(){ return new ::proto_ff::flashflash(); }
		static ::proto_ff::flashflash make_pbmsg(){ return ::proto_ff::flashflash(); }
	};
	typedef struct flashflash_s flashflash_t;

	struct Sheet_flashflash_s : public NFDescStoreSeqOP {
		Sheet_flashflash_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct flashflash_s, 645> flashflash_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_flashflash & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_flashflash & msg);
		static ::proto_ff::Sheet_flashflash* new_pbmsg(){ return new ::proto_ff::Sheet_flashflash(); }
		static ::proto_ff::Sheet_flashflash make_pbmsg(){ return ::proto_ff::Sheet_flashflash(); }
	};
	typedef struct Sheet_flashflash_s Sheet_flashflash_t;

	struct flashitemFlashmonsterDesc_s : public NFDescStoreSeqOP {
		flashitemFlashmonsterDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t Id;
		int32_t weight;

		virtual void write_to_pbmsg(::proto_ff::flashitemFlashmonsterDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::flashitemFlashmonsterDesc & msg);
		static ::proto_ff::flashitemFlashmonsterDesc* new_pbmsg(){ return new ::proto_ff::flashitemFlashmonsterDesc(); }
		static ::proto_ff::flashitemFlashmonsterDesc make_pbmsg(){ return ::proto_ff::flashitemFlashmonsterDesc(); }
	};
	typedef struct flashitemFlashmonsterDesc_s flashitemFlashmonsterDesc_t;

	struct flashitemFlash_s : public NFDescStoreSeqOP {
		flashitemFlash_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<155> useMap;
		int32_t live;
		int32_t levelwave;
		int32_t flashNum;
		NFArray<struct flashitemFlashmonsterDesc_s, 10> monster;

		virtual void write_to_pbmsg(::proto_ff::flashitemFlash & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::flashitemFlash & msg);
		static ::proto_ff::flashitemFlash* new_pbmsg(){ return new ::proto_ff::flashitemFlash(); }
		static ::proto_ff::flashitemFlash make_pbmsg(){ return ::proto_ff::flashitemFlash(); }
	};
	typedef struct flashitemFlash_s flashitemFlash_t;

	struct Sheet_flashitemFlash_s : public NFDescStoreSeqOP {
		Sheet_flashitemFlash_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct flashitemFlash_s, 157> flashitemFlash_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_flashitemFlash & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_flashitemFlash & msg);
		static ::proto_ff::Sheet_flashitemFlash* new_pbmsg(){ return new ::proto_ff::Sheet_flashitemFlash(); }
		static ::proto_ff::Sheet_flashitemFlash make_pbmsg(){ return ::proto_ff::Sheet_flashitemFlash(); }
	};
	typedef struct Sheet_flashitemFlash_s Sheet_flashitemFlash_t;

}

