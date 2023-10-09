#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Market.pb.h"
#include "E_Market_s.h"

#define DEFINE_SHEET_MARKETMARKET_E_MARKETMARKET_LIST_MAX_NUM 16384
#define DEFINE_SHEET_MARKETBIG_E_MARKETBIG_LIST_MAX_NUM 16
#define DEFINE_SHEET_MARKETSMALL_E_MARKETSMALL_LIST_MAX_NUM 128
#define DEFINE_SHEET_MARKETCONSTANT_E_MARKETCONSTANT_LIST_MAX_NUM 2


namespace proto_ff_s {

	struct E_MarketMarket_s : public NFDescStoreSeqOP {
		E_MarketMarket_s();
		virtual ~E_MarketMarket_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_itemid;//道具id
		int32_t m_type;//所属类型组
		int32_t m_order;//排序
		int32_t m_readytime;//准备时间
		int32_t m_sjtime;//上架时间
		int32_t m_endtime;//竞拍时间
		int32_t m_pricetype;//交易货币
		int32_t m_vietype;//是否支持竞价
		int32_t m_startprice;//竞拍底价
		int32_t m_onceprice;//每次增加的价格
		int32_t m_directprice;//一口价
		int32_t m_gztype;//是否关注
		NFShmString<64> m_gztutype;//关注获取途径
		int32_t m_recoverytype;//是否系统回收

		virtual void write_to_pbmsg(::proto_ff::E_MarketMarket & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarketMarket & msg);
		static ::proto_ff::E_MarketMarket* new_pbmsg(){ return new ::proto_ff::E_MarketMarket(); }
		static ::proto_ff::E_MarketMarket make_pbmsg(){ return ::proto_ff::E_MarketMarket(); }
	};
	typedef struct E_MarketMarket_s E_MarketMarket_t;

	struct Sheet_MarketMarket_s : public NFDescStoreSeqOP {
		Sheet_MarketMarket_s();
		virtual ~Sheet_MarketMarket_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarketMarket_s, DEFINE_SHEET_MARKETMARKET_E_MARKETMARKET_LIST_MAX_NUM> E_MarketMarket_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarketMarket & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarketMarket & msg);
		static ::proto_ff::Sheet_MarketMarket* new_pbmsg(){ return new ::proto_ff::Sheet_MarketMarket(); }
		static ::proto_ff::Sheet_MarketMarket make_pbmsg(){ return ::proto_ff::Sheet_MarketMarket(); }
	};
	typedef struct Sheet_MarketMarket_s Sheet_MarketMarket_t;

	struct E_MarketBig_s : public NFDescStoreSeqOP {
		E_MarketBig_s();
		virtual ~E_MarketBig_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//大类id
		NFShmString<64> m_bigname;//大类名称
		int32_t m_xb;//性别

		virtual void write_to_pbmsg(::proto_ff::E_MarketBig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarketBig & msg);
		static ::proto_ff::E_MarketBig* new_pbmsg(){ return new ::proto_ff::E_MarketBig(); }
		static ::proto_ff::E_MarketBig make_pbmsg(){ return ::proto_ff::E_MarketBig(); }
	};
	typedef struct E_MarketBig_s E_MarketBig_t;

	struct Sheet_MarketBig_s : public NFDescStoreSeqOP {
		Sheet_MarketBig_s();
		virtual ~Sheet_MarketBig_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarketBig_s, DEFINE_SHEET_MARKETBIG_E_MARKETBIG_LIST_MAX_NUM> E_MarketBig_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarketBig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarketBig & msg);
		static ::proto_ff::Sheet_MarketBig* new_pbmsg(){ return new ::proto_ff::Sheet_MarketBig(); }
		static ::proto_ff::Sheet_MarketBig make_pbmsg(){ return ::proto_ff::Sheet_MarketBig(); }
	};
	typedef struct Sheet_MarketBig_s Sheet_MarketBig_t;

	struct E_MarketSmall_s : public NFDescStoreSeqOP {
		E_MarketSmall_s();
		virtual ~E_MarketSmall_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//子页签id
		NFShmString<64> m_smallname;//子页签名称
		int32_t m_openlevel;//显示等级
		int32_t m_bigid;//大类id

		virtual void write_to_pbmsg(::proto_ff::E_MarketSmall & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarketSmall & msg);
		static ::proto_ff::E_MarketSmall* new_pbmsg(){ return new ::proto_ff::E_MarketSmall(); }
		static ::proto_ff::E_MarketSmall make_pbmsg(){ return ::proto_ff::E_MarketSmall(); }
	};
	typedef struct E_MarketSmall_s E_MarketSmall_t;

	struct Sheet_MarketSmall_s : public NFDescStoreSeqOP {
		Sheet_MarketSmall_s();
		virtual ~Sheet_MarketSmall_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarketSmall_s, DEFINE_SHEET_MARKETSMALL_E_MARKETSMALL_LIST_MAX_NUM> E_MarketSmall_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarketSmall & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarketSmall & msg);
		static ::proto_ff::Sheet_MarketSmall* new_pbmsg(){ return new ::proto_ff::Sheet_MarketSmall(); }
		static ::proto_ff::Sheet_MarketSmall make_pbmsg(){ return ::proto_ff::Sheet_MarketSmall(); }
	};
	typedef struct Sheet_MarketSmall_s Sheet_MarketSmall_t;

	struct E_MarketConstant_s : public NFDescStoreSeqOP {
		E_MarketConstant_s();
		virtual ~E_MarketConstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_taxrate;//出售税率
		int32_t m_bpselltime;//帮派拍品上架时间
		int32_t m_sellnum;//上架数量
		int32_t m_recyclenum;//回收数量
		int32_t m_gz;//关注上限
		NFShmString<64> m_epackagetype;//包裹类型
		int32_t m_dh;//钻石兑换元宝

		virtual void write_to_pbmsg(::proto_ff::E_MarketConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MarketConstant & msg);
		static ::proto_ff::E_MarketConstant* new_pbmsg(){ return new ::proto_ff::E_MarketConstant(); }
		static ::proto_ff::E_MarketConstant make_pbmsg(){ return ::proto_ff::E_MarketConstant(); }
	};
	typedef struct E_MarketConstant_s E_MarketConstant_t;

	struct Sheet_MarketConstant_s : public NFDescStoreSeqOP {
		Sheet_MarketConstant_s();
		virtual ~Sheet_MarketConstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MarketConstant_s, DEFINE_SHEET_MARKETCONSTANT_E_MARKETCONSTANT_LIST_MAX_NUM> E_MarketConstant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MarketConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MarketConstant & msg);
		static ::proto_ff::Sheet_MarketConstant* new_pbmsg(){ return new ::proto_ff::Sheet_MarketConstant(); }
		static ::proto_ff::Sheet_MarketConstant make_pbmsg(){ return ::proto_ff::Sheet_MarketConstant(); }
	};
	typedef struct Sheet_MarketConstant_s Sheet_MarketConstant_t;

}

