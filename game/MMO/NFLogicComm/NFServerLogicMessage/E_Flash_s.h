#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Flash.pb.h"
#include "E_Flash_s.h"

#define DEFINE_E_FLASHFLASH_M_MONSTER_MAX_NUM 5
#define DEFINE_SHEET_FLASHFLASH_E_FLASHFLASH_LIST_MAX_NUM 512
#define DEFINE_E_FLASHITEMFLASH_M_MONSTER_MAX_NUM 10
#define DEFINE_SHEET_FLASHITEMFLASH_E_FLASHITEMFLASH_LIST_MAX_NUM 2


namespace proto_ff_s {

	struct E_FlashFlashMonsterDesc_s : public NFDescStoreSeqOP {
		E_FlashFlashMonsterDesc_s();
		virtual ~E_FlashFlashMonsterDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int64_t m_id;//ID

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
		int64_t m_id;//刷新ID
		int32_t m_isleveldynamic;//是否动态等级
		int32_t m_minilevel;//动态初始等级
		int32_t m_levelcheck;//动态等级校正
		int64_t m_pointid;//路径ID
		int32_t m_monster_type;//怪物类型
		int32_t m_monsterrefreshtime;//怪物刷新时间
		NFShmVector<struct E_FlashFlashMonsterDesc_s, DEFINE_E_FLASHFLASH_M_MONSTER_MAX_NUM> m_monster;//怪物

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
		NFShmVector<struct E_FlashFlash_s, DEFINE_SHEET_FLASHFLASH_E_FLASHFLASH_LIST_MAX_NUM> E_FlashFlash_List;//

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
		int32_t m_weight;//权重
		int64_t m_id;//ID

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
		int64_t m_id;//刷新ID
		NFShmString<64> m_usemap;//可使用地图
		int32_t m_live;//怪物存在时间
		int32_t m_levelwave;//是否动态等级
		int32_t m_flashnum;//刷新怪物数量
		NFShmVector<struct E_FlashItemflashMonsterDesc_s, DEFINE_E_FLASHITEMFLASH_M_MONSTER_MAX_NUM> m_monster;//怪物

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
		NFShmVector<struct E_FlashItemflash_s, DEFINE_SHEET_FLASHITEMFLASH_E_FLASHITEMFLASH_LIST_MAX_NUM> E_FlashItemflash_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FlashItemflash & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FlashItemflash & msg);
		static ::proto_ff::Sheet_FlashItemflash* new_pbmsg(){ return new ::proto_ff::Sheet_FlashItemflash(); }
		static ::proto_ff::Sheet_FlashItemflash make_pbmsg(){ return ::proto_ff::Sheet_FlashItemflash(); }
	};
	typedef struct Sheet_FlashItemflash_s Sheet_FlashItemflash_t;

}

