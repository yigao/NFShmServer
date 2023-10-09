#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Personalshop.pb.h"
#include "E_Personalshop_s.h"

#define DEFINE_SHEET_PERSONALSHOPSHOPITEMS_E_PERSONALSHOPSHOPITEMS_LIST_MAX_NUM 1024
#define DEFINE_SHEET_PERSONALSHOPSHOPS_E_PERSONALSHOPSHOPS_LIST_MAX_NUM 2


namespace proto_ff_s {

	struct E_PersonalshopShopitems_s : public NFDescStoreSeqOP {
		E_PersonalshopShopitems_s();
		virtual ~E_PersonalshopShopitems_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		int32_t m_shopid;//商店类型
		int32_t m_itemid;//物品ID
		int32_t m_amount;//物品数量
		int32_t m_currency;//货币类型
		int32_t m_price;//价格
		int32_t m_discount;//折扣
		int32_t m_lvlimit;//等级限制
		int32_t m_weight;//权重

		virtual void write_to_pbmsg(::proto_ff::E_PersonalshopShopitems & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PersonalshopShopitems & msg);
		static ::proto_ff::E_PersonalshopShopitems* new_pbmsg(){ return new ::proto_ff::E_PersonalshopShopitems(); }
		static ::proto_ff::E_PersonalshopShopitems make_pbmsg(){ return ::proto_ff::E_PersonalshopShopitems(); }
	};
	typedef struct E_PersonalshopShopitems_s E_PersonalshopShopitems_t;

	struct Sheet_PersonalshopShopitems_s : public NFDescStoreSeqOP {
		Sheet_PersonalshopShopitems_s();
		virtual ~Sheet_PersonalshopShopitems_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PersonalshopShopitems_s, DEFINE_SHEET_PERSONALSHOPSHOPITEMS_E_PERSONALSHOPSHOPITEMS_LIST_MAX_NUM> E_PersonalshopShopitems_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PersonalshopShopitems & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PersonalshopShopitems & msg);
		static ::proto_ff::Sheet_PersonalshopShopitems* new_pbmsg(){ return new ::proto_ff::Sheet_PersonalshopShopitems(); }
		static ::proto_ff::Sheet_PersonalshopShopitems make_pbmsg(){ return ::proto_ff::Sheet_PersonalshopShopitems(); }
	};
	typedef struct Sheet_PersonalshopShopitems_s Sheet_PersonalshopShopitems_t;

	struct E_PersonalshopShops_s : public NFDescStoreSeqOP {
		E_PersonalshopShops_s();
		virtual ~E_PersonalshopShops_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//商店id
		int32_t m_keeptime;//商店持续时间
		int32_t m_freetimes;//免费刷新次数
		int32_t m_refreshmoney;//刷新货币id
		int32_t m_refreshprice;//刷新价格
		int32_t m_salelistcount;//出售数量
		int32_t m_addtype;//添加类型
		int32_t m_addtypevalue;//变量

		virtual void write_to_pbmsg(::proto_ff::E_PersonalshopShops & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PersonalshopShops & msg);
		static ::proto_ff::E_PersonalshopShops* new_pbmsg(){ return new ::proto_ff::E_PersonalshopShops(); }
		static ::proto_ff::E_PersonalshopShops make_pbmsg(){ return ::proto_ff::E_PersonalshopShops(); }
	};
	typedef struct E_PersonalshopShops_s E_PersonalshopShops_t;

	struct Sheet_PersonalshopShops_s : public NFDescStoreSeqOP {
		Sheet_PersonalshopShops_s();
		virtual ~Sheet_PersonalshopShops_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PersonalshopShops_s, DEFINE_SHEET_PERSONALSHOPSHOPS_E_PERSONALSHOPSHOPS_LIST_MAX_NUM> E_PersonalshopShops_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PersonalshopShops & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PersonalshopShops & msg);
		static ::proto_ff::Sheet_PersonalshopShops* new_pbmsg(){ return new ::proto_ff::Sheet_PersonalshopShops(); }
		static ::proto_ff::Sheet_PersonalshopShops make_pbmsg(){ return ::proto_ff::Sheet_PersonalshopShops(); }
	};
	typedef struct Sheet_PersonalshopShops_s Sheet_PersonalshopShops_t;

}

