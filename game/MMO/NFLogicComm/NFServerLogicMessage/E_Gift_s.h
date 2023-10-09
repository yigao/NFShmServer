#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Gift.pb.h"
#include "E_Gift_s.h"

#define DEFINE_SHEET_GIFTFREE_E_GIFTFREE_LIST_MAX_NUM 16
#define DEFINE_SHEET_GIFTCONDITION_E_GIFTCONDITION_LIST_MAX_NUM 2
#define DEFINE_SHEET_GIFTMUST_E_GIFTMUST_LIST_MAX_NUM 32


namespace proto_ff_s {

	struct E_GiftFree_s : public NFDescStoreSeqOP {
		E_GiftFree_s();
		virtual ~E_GiftFree_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//类型
		int32_t m_costid;//货币id
		int32_t m_price;//价格
		int32_t m_freeday;//返还服务器天数
		int32_t m_boxid;//礼包内容box

		virtual void write_to_pbmsg(::proto_ff::E_GiftFree & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GiftFree & msg);
		static ::proto_ff::E_GiftFree* new_pbmsg(){ return new ::proto_ff::E_GiftFree(); }
		static ::proto_ff::E_GiftFree make_pbmsg(){ return ::proto_ff::E_GiftFree(); }
	};
	typedef struct E_GiftFree_s E_GiftFree_t;

	struct Sheet_GiftFree_s : public NFDescStoreSeqOP {
		Sheet_GiftFree_s();
		virtual ~Sheet_GiftFree_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GiftFree_s, DEFINE_SHEET_GIFTFREE_E_GIFTFREE_LIST_MAX_NUM> E_GiftFree_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GiftFree & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GiftFree & msg);
		static ::proto_ff::Sheet_GiftFree* new_pbmsg(){ return new ::proto_ff::Sheet_GiftFree(); }
		static ::proto_ff::Sheet_GiftFree make_pbmsg(){ return ::proto_ff::Sheet_GiftFree(); }
	};
	typedef struct Sheet_GiftFree_s Sheet_GiftFree_t;

	struct E_GiftCondition_s : public NFDescStoreSeqOP {
		E_GiftCondition_s();
		virtual ~E_GiftCondition_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_conditiontype;//类型
		int32_t m_arg;//参数
		int32_t m_time;//礼包持续时间
		int32_t m_pricetype;//价格类型
		int32_t m_price;//价格
		int32_t m_boxid;//礼包内容box

		virtual void write_to_pbmsg(::proto_ff::E_GiftCondition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GiftCondition & msg);
		static ::proto_ff::E_GiftCondition* new_pbmsg(){ return new ::proto_ff::E_GiftCondition(); }
		static ::proto_ff::E_GiftCondition make_pbmsg(){ return ::proto_ff::E_GiftCondition(); }
	};
	typedef struct E_GiftCondition_s E_GiftCondition_t;

	struct Sheet_GiftCondition_s : public NFDescStoreSeqOP {
		Sheet_GiftCondition_s();
		virtual ~Sheet_GiftCondition_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GiftCondition_s, DEFINE_SHEET_GIFTCONDITION_E_GIFTCONDITION_LIST_MAX_NUM> E_GiftCondition_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GiftCondition & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GiftCondition & msg);
		static ::proto_ff::Sheet_GiftCondition* new_pbmsg(){ return new ::proto_ff::Sheet_GiftCondition(); }
		static ::proto_ff::Sheet_GiftCondition make_pbmsg(){ return ::proto_ff::Sheet_GiftCondition(); }
	};
	typedef struct Sheet_GiftCondition_s Sheet_GiftCondition_t;

	struct E_GiftMust_s : public NFDescStoreSeqOP {
		E_GiftMust_s();
		virtual ~E_GiftMust_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_boxid;//boxid
		int32_t m_original;//原价
		int32_t m_pricetype;//价格类型
		int32_t m_price;//现价

		virtual void write_to_pbmsg(::proto_ff::E_GiftMust & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GiftMust & msg);
		static ::proto_ff::E_GiftMust* new_pbmsg(){ return new ::proto_ff::E_GiftMust(); }
		static ::proto_ff::E_GiftMust make_pbmsg(){ return ::proto_ff::E_GiftMust(); }
	};
	typedef struct E_GiftMust_s E_GiftMust_t;

	struct Sheet_GiftMust_s : public NFDescStoreSeqOP {
		Sheet_GiftMust_s();
		virtual ~Sheet_GiftMust_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GiftMust_s, DEFINE_SHEET_GIFTMUST_E_GIFTMUST_LIST_MAX_NUM> E_GiftMust_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_GiftMust & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GiftMust & msg);
		static ::proto_ff::Sheet_GiftMust* new_pbmsg(){ return new ::proto_ff::Sheet_GiftMust(); }
		static ::proto_ff::Sheet_GiftMust make_pbmsg(){ return ::proto_ff::Sheet_GiftMust(); }
	};
	typedef struct Sheet_GiftMust_s Sheet_GiftMust_t;

}

