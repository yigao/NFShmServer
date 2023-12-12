#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "CommonClass.pb.h"
#include "CommonClass_s.h"
#include "Com.pb.h"
#include "Com_s.h"



namespace proto_ff_s {

	struct ItemBase_s : public NFDescStoreSeqOP {
		ItemBase_s();
		virtual ~ItemBase_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t index;//索引
		uint32_t item_id;//物品ID
		uint64_t item_num;//物品数量
		bool bind;//绑定状态
		uint32_t level;//等级 预留(装备里，这个等级是玩家等级)
		uint64_t expireTime;//过期时间,0,永不过期
		uint32_t type;//

		virtual void write_to_pbmsg(::proto_ff::ItemBase & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ItemBase & msg);
		static ::proto_ff::ItemBase* new_pbmsg(){ return new ::proto_ff::ItemBase(); }
		static ::proto_ff::ItemBase make_pbmsg(){ return ::proto_ff::ItemBase(); }
	};
	typedef struct ItemBase_s ItemBase_t;

	struct EquipBase_s : public NFDescStoreSeqOP {
		EquipBase_s();
		virtual ~EquipBase_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t base_attr_percent;//基础属性
		uint32_t star_attr_percent;//星级属性 仙品属性 = 星级属性(带★) + 蓝星属性(不带★)
		uint32_t god_attr_percent;//仙尊属性

		virtual void write_to_pbmsg(::proto_ff::EquipBase & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::EquipBase & msg);
		static ::proto_ff::EquipBase* new_pbmsg(){ return new ::proto_ff::EquipBase(); }
		static ::proto_ff::EquipBase make_pbmsg(){ return ::proto_ff::EquipBase(); }
	};
	typedef struct EquipBase_s EquipBase_t;

}

