#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "flash.pb.h"
#include "flash_s.h"

namespace proto_ff_s {

	struct E_FlashFlashMonsterDesc_s : public NFDescStoreSeqOP {
		E_FlashFlashMonsterDesc_s();
		virtual ~E_FlashFlashMonsterDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;
		int64_t m_id;

		virtual void write_to_pbmsg(::proto_ff::E_FlashFlashMonsterDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FlashFlashMonsterDesc & msg);
		static ::proto_ff::E_FlashFlashMonsterDesc* new_pbmsg(){ return new ::proto_ff::E_FlashFlashMonsterDesc(); }
		static ::proto_ff::E_FlashFlashMonsterDesc make_pbmsg(){ return ::proto_ff::E_FlashFlashMonsterDesc(); }
	};
	typedef struct E_FlashFlashMonsterDesc_s E_FlashFlashMonsterDesc_t;

	struct E_FlashFlash_s : public NFDescStoreSeqOP {
		E_FlashFlash_s();
		virtual ~E_FlashFlash_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_isleveldynamic;
		int32_t m_minilevel;
		int32_t m_levelcheck;
		int64_t m_pointid;
		int32_t m_monster_type;
		int32_t m_monsterrefreshtime;
		NFShmVector<struct E_FlashFlashMonsterDesc_s, 5> m_monster;

		virtual void write_to_pbmsg(::proto_ff::E_FlashFlash & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FlashFlash & msg);
		static ::proto_ff::E_FlashFlash* new_pbmsg(){ return new ::proto_ff::E_FlashFlash(); }
		static ::proto_ff::E_FlashFlash make_pbmsg(){ return ::proto_ff::E_FlashFlash(); }
	};
	typedef struct E_FlashFlash_s E_FlashFlash_t;

	struct Sheet_FlashFlash_s : public NFDescStoreSeqOP {
		Sheet_FlashFlash_s();
		virtual ~Sheet_FlashFlash_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FlashFlash_s, 20> E_FlashFlash_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_FlashFlash & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FlashFlash & msg);
		static ::proto_ff::Sheet_FlashFlash* new_pbmsg(){ return new ::proto_ff::Sheet_FlashFlash(); }
		static ::proto_ff::Sheet_FlashFlash make_pbmsg(){ return ::proto_ff::Sheet_FlashFlash(); }
	};
	typedef struct Sheet_FlashFlash_s Sheet_FlashFlash_t;

	struct E_FlashItemflashMonsterDesc_s : public NFDescStoreSeqOP {
		E_FlashItemflashMonsterDesc_s();
		virtual ~E_FlashItemflashMonsterDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_weight;

		virtual void write_to_pbmsg(::proto_ff::E_FlashItemflashMonsterDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FlashItemflashMonsterDesc & msg);
		static ::proto_ff::E_FlashItemflashMonsterDesc* new_pbmsg(){ return new ::proto_ff::E_FlashItemflashMonsterDesc(); }
		static ::proto_ff::E_FlashItemflashMonsterDesc make_pbmsg(){ return ::proto_ff::E_FlashItemflashMonsterDesc(); }
	};
	typedef struct E_FlashItemflashMonsterDesc_s E_FlashItemflashMonsterDesc_t;

	struct E_FlashItemflash_s : public NFDescStoreSeqOP {
		E_FlashItemflash_s();
		virtual ~E_FlashItemflash_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		NFShmString<60> m_usemap;
		int32_t m_live;
		int32_t m_levelwave;
		int32_t m_flashnum;
		NFShmVector<struct E_FlashItemflashMonsterDesc_s, 10> m_monster;

		virtual void write_to_pbmsg(::proto_ff::E_FlashItemflash & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FlashItemflash & msg);
		static ::proto_ff::E_FlashItemflash* new_pbmsg(){ return new ::proto_ff::E_FlashItemflash(); }
		static ::proto_ff::E_FlashItemflash make_pbmsg(){ return ::proto_ff::E_FlashItemflash(); }
	};
	typedef struct E_FlashItemflash_s E_FlashItemflash_t;

	struct Sheet_FlashItemflash_s : public NFDescStoreSeqOP {
		Sheet_FlashItemflash_s();
		virtual ~Sheet_FlashItemflash_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FlashItemflash_s, 20> E_FlashItemflash_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_FlashItemflash & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FlashItemflash & msg);
		static ::proto_ff::Sheet_FlashItemflash* new_pbmsg(){ return new ::proto_ff::Sheet_FlashItemflash(); }
		static ::proto_ff::Sheet_FlashItemflash make_pbmsg(){ return ::proto_ff::Sheet_FlashItemflash(); }
	};
	typedef struct Sheet_FlashItemflash_s Sheet_FlashItemflash_t;

}

