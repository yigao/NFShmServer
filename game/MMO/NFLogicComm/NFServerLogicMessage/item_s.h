#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "item.pb.h"
#include "item_s.h"

namespace proto_ff_s {

	struct E_ItemItem_s : public NFDescStoreSeqOP {
		E_ItemItem_s();
		virtual ~E_ItemItem_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		NFShmString<60> m_name;
		int32_t m_itemtype;
		int32_t m_subtype;
		int32_t m_functiontype;
		NFShmString<60> m_functionvalue;
		NFShmString<60> m_usecondition;
		int64_t m_waiguanlink;
		int32_t m_level;
		int32_t m_quality;
		int32_t m_levelrequest;
		NFShmString<60> m_profession;
		int32_t m_bindtype;
		int32_t m_istradebind;
		int32_t m_dropnum;
		int32_t m_stacklimit;
		int32_t m_sellprice;
		int64_t m_sellbox;
		int32_t m_broadcast;
		int32_t m_iscanbatchuse;
		int32_t m_dayuse;
		int32_t m_time;
		NFShmString<60> m_uselimit;
		int32_t m_blessing;
		int32_t m_invest;
		int32_t m_exchange;

		virtual void write_to_pbmsg(::proto_ff::E_ItemItem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ItemItem & msg);
		static ::proto_ff::E_ItemItem* new_pbmsg(){ return new ::proto_ff::E_ItemItem(); }
		static ::proto_ff::E_ItemItem make_pbmsg(){ return ::proto_ff::E_ItemItem(); }
	};
	typedef struct E_ItemItem_s E_ItemItem_t;

	struct Sheet_ItemItem_s : public NFDescStoreSeqOP {
		Sheet_ItemItem_s();
		virtual ~Sheet_ItemItem_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ItemItem_s, 2000> E_ItemItem_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_ItemItem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ItemItem & msg);
		static ::proto_ff::Sheet_ItemItem* new_pbmsg(){ return new ::proto_ff::Sheet_ItemItem(); }
		static ::proto_ff::Sheet_ItemItem make_pbmsg(){ return ::proto_ff::Sheet_ItemItem(); }
	};
	typedef struct Sheet_ItemItem_s Sheet_ItemItem_t;

}

