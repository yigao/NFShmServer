#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "CommonClass.pb.h"
#include "CommonClass_s.h"

namespace proto_ff_s {

	struct GridItemBase_s : public NFDescStoreSeqOP {
		GridItemBase_s();
		virtual ~GridItemBase_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t index;
		uint64_t item_id;
		uint64_t item_num;
		bool bind;
		uint32_t level;
		uint64_t expireTime;
		uint32_t type;

		virtual void write_to_pbmsg(::proto_ff::GridItemBase & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GridItemBase & msg);
		static ::proto_ff::GridItemBase* new_pbmsg(){ return new ::proto_ff::GridItemBase(); }
		static ::proto_ff::GridItemBase make_pbmsg(){ return ::proto_ff::GridItemBase(); }
	};
	typedef struct GridItemBase_s GridItemBase_t;

	struct EquipExt_s : public NFDescStoreSeqOP {
		EquipExt_s();
		virtual ~EquipExt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<int32_t, 10> base_attr;
		NFShmVector<int32_t, 10> star_attr;
		NFShmVector<int32_t, 10> blue_attr;
		NFShmVector<int32_t, 10> god_attr;
		NFShmVector<int32_t, 10> special_attr;

		virtual void write_to_pbmsg(::proto_ff::EquipExt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::EquipExt & msg);
		static ::proto_ff::EquipExt* new_pbmsg(){ return new ::proto_ff::EquipExt(); }
		static ::proto_ff::EquipExt make_pbmsg(){ return ::proto_ff::EquipExt(); }
	};
	typedef struct EquipExt_s EquipExt_t;

	struct ItemGridCSData_s : public NFDescStoreSeqOP {
		ItemGridCSData_s();
		virtual ~ItemGridCSData_s(){}
		int CreateInit();
		int ResumeInit();
		struct GridItemBase_s base;
		struct EquipExt_s equip_data;

		virtual void write_to_pbmsg(::proto_ff::ItemGridCSData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ItemGridCSData & msg);
		static ::proto_ff::ItemGridCSData* new_pbmsg(){ return new ::proto_ff::ItemGridCSData(); }
		static ::proto_ff::ItemGridCSData make_pbmsg(){ return ::proto_ff::ItemGridCSData(); }
	};
	typedef struct ItemGridCSData_s ItemGridCSData_t;

}

