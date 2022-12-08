#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "item.pb.h"
#include "item_s.h"

namespace proto_ff_s {

	struct itemitem_s : public NFDescStoreSeqOP {
		itemitem_s();
		virtual ~itemitem_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFShmString<60> name;
		int32_t itemType;
		int32_t subType;
		int32_t functionType;
		NFShmString<60> functionValue;
		NFShmString<60> usecondition;
		int32_t level;
		int32_t quality;
		int32_t levelRequest;
		NFShmString<60> profession;
		int32_t bindType;
		int32_t isTradeBind;
		int32_t dropNum;
		int32_t stackLimit;
		int32_t sellPrice;
		int64_t sellBox;
		int32_t broadcast;
		int32_t isCanBatchUse;
		int32_t dayUse;
		int32_t time;
		NFShmString<60> useLimit;
		int32_t blessing;
		int32_t invest;
		int32_t exchange;

		virtual void write_to_pbmsg(::proto_ff::itemitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::itemitem & msg);
		static ::proto_ff::itemitem* new_pbmsg(){ return new ::proto_ff::itemitem(); }
		static ::proto_ff::itemitem make_pbmsg(){ return ::proto_ff::itemitem(); }
	};
	typedef struct itemitem_s itemitem_t;

	struct Sheet_itemitem_s : public NFDescStoreSeqOP {
		Sheet_itemitem_s();
		virtual ~Sheet_itemitem_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct itemitem_s, 1000> itemitem_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_itemitem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_itemitem & msg);
		static ::proto_ff::Sheet_itemitem* new_pbmsg(){ return new ::proto_ff::Sheet_itemitem(); }
		static ::proto_ff::Sheet_itemitem make_pbmsg(){ return ::proto_ff::Sheet_itemitem(); }
	};
	typedef struct Sheet_itemitem_s Sheet_itemitem_t;

}

