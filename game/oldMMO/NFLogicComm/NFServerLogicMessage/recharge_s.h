#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "recharge.pb.h"
#include "recharge_s.h"

#define DEFINE_E_RECHARGERECHARGE_M_ITEM_MAX_NUM 2
#define DEFINE_E_RECHARGERECHARGE_M_CHANNEL_MAX_NUM 4
#define DEFINE_SHEET_RECHARGERECHARGE_E_RECHARGERECHARGE_LIST_MAX_NUM 2000
namespace proto_ff_s {

	struct E_RechargeRechargeItemDesc_s : public NFDescStoreSeqOP {
		E_RechargeRechargeItemDesc_s();
		virtual ~E_RechargeRechargeItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;
		int64_t m_id;

		virtual void write_to_pbmsg(::proto_ff::E_RechargeRechargeItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RechargeRechargeItemDesc & msg);
		static ::proto_ff::E_RechargeRechargeItemDesc* new_pbmsg(){ return new ::proto_ff::E_RechargeRechargeItemDesc(); }
		static ::proto_ff::E_RechargeRechargeItemDesc make_pbmsg(){ return ::proto_ff::E_RechargeRechargeItemDesc(); }
	};
	typedef struct E_RechargeRechargeItemDesc_s E_RechargeRechargeItemDesc_t;

	struct E_RechargeRechargeChannelDesc_s : public NFDescStoreSeqOP {
		E_RechargeRechargeChannelDesc_s();
		virtual ~E_RechargeRechargeChannelDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmString<60> m_point;

		virtual void write_to_pbmsg(::proto_ff::E_RechargeRechargeChannelDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RechargeRechargeChannelDesc & msg);
		static ::proto_ff::E_RechargeRechargeChannelDesc* new_pbmsg(){ return new ::proto_ff::E_RechargeRechargeChannelDesc(); }
		static ::proto_ff::E_RechargeRechargeChannelDesc make_pbmsg(){ return ::proto_ff::E_RechargeRechargeChannelDesc(); }
	};
	typedef struct E_RechargeRechargeChannelDesc_s E_RechargeRechargeChannelDesc_t;

	struct E_RechargeRecharge_s : public NFDescStoreSeqOP {
		E_RechargeRecharge_s();
		virtual ~E_RechargeRecharge_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmString<60> m_name;
		NFShmString<60> m_defaultpoint;
		int32_t m_type;
		NFShmString<60> m_unit;
		NFShmString<200> m_beizhu;
		int64_t m_quantity;
		int32_t m_itemnum;
		int64_t m_multipletimes;
		int64_t m_multiplereward;
		int32_t m_zuanshitype;
		int32_t m_vipexp;
		int32_t m_vipexplimit;
		int32_t m_activitycount;
		int32_t m_price;
		int32_t m_presentid;
		int32_t m_fristpresent;
		NFShmString<60> m_icon;
		NFShmVector<struct E_RechargeRechargeItemDesc_s, DEFINE_E_RECHARGERECHARGE_M_ITEM_MAX_NUM> m_item;
		NFShmVector<struct E_RechargeRechargeChannelDesc_s, DEFINE_E_RECHARGERECHARGE_M_CHANNEL_MAX_NUM> m_channel;

		virtual void write_to_pbmsg(::proto_ff::E_RechargeRecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RechargeRecharge & msg);
		static ::proto_ff::E_RechargeRecharge* new_pbmsg(){ return new ::proto_ff::E_RechargeRecharge(); }
		static ::proto_ff::E_RechargeRecharge make_pbmsg(){ return ::proto_ff::E_RechargeRecharge(); }
	};
	typedef struct E_RechargeRecharge_s E_RechargeRecharge_t;

	struct Sheet_RechargeRecharge_s : public NFDescStoreSeqOP {
		Sheet_RechargeRecharge_s();
		virtual ~Sheet_RechargeRecharge_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RechargeRecharge_s, DEFINE_SHEET_RECHARGERECHARGE_E_RECHARGERECHARGE_LIST_MAX_NUM> E_RechargeRecharge_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RechargeRecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RechargeRecharge & msg);
		static ::proto_ff::Sheet_RechargeRecharge* new_pbmsg(){ return new ::proto_ff::Sheet_RechargeRecharge(); }
		static ::proto_ff::Sheet_RechargeRecharge make_pbmsg(){ return ::proto_ff::Sheet_RechargeRecharge(); }
	};
	typedef struct Sheet_RechargeRecharge_s Sheet_RechargeRecharge_t;

}
