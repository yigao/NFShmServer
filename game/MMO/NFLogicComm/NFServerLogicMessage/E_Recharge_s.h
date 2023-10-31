#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Recharge.pb.h"
#include "E_Recharge_s.h"

#define DEFINE_E_RECHARGERECHARGE_M_CHANNEL_MAX_NUM 4
#define DEFINE_E_RECHARGERECHARGE_M_ITEM_MAX_NUM 2
#define DEFINE_SHEET_RECHARGERECHARGE_E_RECHARGERECHARGE_LIST_MAX_NUM 128
#define DEFINE_E_RECHARGEONECLICKBUY_M_ALLBUY_MAX_NUM 3
#define DEFINE_SHEET_RECHARGEONECLICKBUY_E_RECHARGEONECLICKBUY_LIST_MAX_NUM 4


namespace proto_ff_s {

	struct E_RechargeRechargeChannelDesc_s : public NFDescStoreSeqOP {
		E_RechargeRechargeChannelDesc_s();
		virtual ~E_RechargeRechargeChannelDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_point;//计费点
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_RechargeRechargeChannelDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RechargeRechargeChannelDesc & msg);
		static ::proto_ff::E_RechargeRechargeChannelDesc* new_pbmsg(){ return new ::proto_ff::E_RechargeRechargeChannelDesc(); }
		static ::proto_ff::E_RechargeRechargeChannelDesc make_pbmsg(){ return ::proto_ff::E_RechargeRechargeChannelDesc(); }
	};
	typedef struct E_RechargeRechargeChannelDesc_s E_RechargeRechargeChannelDesc_t;

	struct E_RechargeRechargeItemDesc_s : public NFDescStoreSeqOP {
		E_RechargeRechargeItemDesc_s();
		virtual ~E_RechargeRechargeItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//数量
		int64_t m_Id;//id

		virtual void write_to_pbmsg(::proto_ff::E_RechargeRechargeItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RechargeRechargeItemDesc & msg);
		static ::proto_ff::E_RechargeRechargeItemDesc* new_pbmsg(){ return new ::proto_ff::E_RechargeRechargeItemDesc(); }
		static ::proto_ff::E_RechargeRechargeItemDesc make_pbmsg(){ return ::proto_ff::E_RechargeRechargeItemDesc(); }
	};
	typedef struct E_RechargeRechargeItemDesc_s E_RechargeRechargeItemDesc_t;

	struct E_RechargeRecharge_s : public NFDescStoreSeqOP {
		E_RechargeRecharge_s();
		virtual ~E_RechargeRecharge_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<64> m_name;//名称
		NFShmString<64> m_defaultPoint;//默认计费点
		int32_t m_type;//充值类型
		NFShmString<64> m_unit;//单位
		NFShmString<64> m_beizhu;//备注
		int64_t m_quantity;//获取档位
		int32_t m_itemNum;//获得物品的数量
		int64_t m_multipleTimes;//重复次数
		int64_t m_multipleReward;//重复奖励
		int32_t m_zuanshitype;//获取类型
		int32_t m_vipExp;//vip经验
		int32_t m_vipExpLimit;//vip经验限制
		int32_t m_activityCount;//运营活动计数
		int32_t m_price;//售价
		int32_t m_presentID;//首充赠送物品id
		int32_t m_fristpresent;//首充赠送数量
		NFShmString<64> m_icon;//图标
		NFShmVector<struct E_RechargeRechargeChannelDesc_s, DEFINE_E_RECHARGERECHARGE_M_CHANNEL_MAX_NUM> m_channel;//渠道
		NFShmVector<struct E_RechargeRechargeItemDesc_s, DEFINE_E_RECHARGERECHARGE_M_ITEM_MAX_NUM> m_item;//充值赠送物品

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
		NFShmVector<struct E_RechargeRecharge_s, DEFINE_SHEET_RECHARGERECHARGE_E_RECHARGERECHARGE_LIST_MAX_NUM> E_RechargeRecharge_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RechargeRecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RechargeRecharge & msg);
		static ::proto_ff::Sheet_RechargeRecharge* new_pbmsg(){ return new ::proto_ff::Sheet_RechargeRecharge(); }
		static ::proto_ff::Sheet_RechargeRecharge make_pbmsg(){ return ::proto_ff::Sheet_RechargeRecharge(); }
	};
	typedef struct Sheet_RechargeRecharge_s Sheet_RechargeRecharge_t;

	struct E_RechargeOneclickbuyAllbuyDesc_s : public NFDescStoreSeqOP {
		E_RechargeOneclickbuyAllbuyDesc_s();
		virtual ~E_RechargeOneclickbuyAllbuyDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_RechargeOneclickbuyAllbuyDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RechargeOneclickbuyAllbuyDesc & msg);
		static ::proto_ff::E_RechargeOneclickbuyAllbuyDesc* new_pbmsg(){ return new ::proto_ff::E_RechargeOneclickbuyAllbuyDesc(); }
		static ::proto_ff::E_RechargeOneclickbuyAllbuyDesc make_pbmsg(){ return ::proto_ff::E_RechargeOneclickbuyAllbuyDesc(); }
	};
	typedef struct E_RechargeOneclickbuyAllbuyDesc_s E_RechargeOneclickbuyAllbuyDesc_t;

	struct E_RechargeOneclickbuy_s : public NFDescStoreSeqOP {
		E_RechargeOneclickbuy_s();
		virtual ~E_RechargeOneclickbuy_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<64> m_name;//名称
		NFShmString<64> m_allowid;//允许充值的rechargeid列表
		NFShmString<64> m_num_limit;//允许充值rechargeid的次数限制
		int32_t m_discount;//一键购买的折扣
		int32_t m_rechargeid;//全部购买rechargeid
		NFShmVector<struct E_RechargeOneclickbuyAllbuyDesc_s, DEFINE_E_RECHARGEONECLICKBUY_M_ALLBUY_MAX_NUM> m_allbuy;//全部购买的渠道

		virtual void write_to_pbmsg(::proto_ff::E_RechargeOneclickbuy & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RechargeOneclickbuy & msg);
		static ::proto_ff::E_RechargeOneclickbuy* new_pbmsg(){ return new ::proto_ff::E_RechargeOneclickbuy(); }
		static ::proto_ff::E_RechargeOneclickbuy make_pbmsg(){ return ::proto_ff::E_RechargeOneclickbuy(); }
	};
	typedef struct E_RechargeOneclickbuy_s E_RechargeOneclickbuy_t;

	struct Sheet_RechargeOneclickbuy_s : public NFDescStoreSeqOP {
		Sheet_RechargeOneclickbuy_s();
		virtual ~Sheet_RechargeOneclickbuy_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RechargeOneclickbuy_s, DEFINE_SHEET_RECHARGEONECLICKBUY_E_RECHARGEONECLICKBUY_LIST_MAX_NUM> E_RechargeOneclickbuy_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RechargeOneclickbuy & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RechargeOneclickbuy & msg);
		static ::proto_ff::Sheet_RechargeOneclickbuy* new_pbmsg(){ return new ::proto_ff::Sheet_RechargeOneclickbuy(); }
		static ::proto_ff::Sheet_RechargeOneclickbuy make_pbmsg(){ return ::proto_ff::Sheet_RechargeOneclickbuy(); }
	};
	typedef struct Sheet_RechargeOneclickbuy_s Sheet_RechargeOneclickbuy_t;

}

