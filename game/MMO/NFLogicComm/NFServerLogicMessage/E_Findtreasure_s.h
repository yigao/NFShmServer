#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Findtreasure.pb.h"
#include "E_Findtreasure_s.h"

#define DEFINE_SHEET_FINDTREASUREFINDTREASURE_E_FINDTREASUREFINDTREASURE_LIST_MAX_NUM 16
#define DEFINE_SHEET_FINDTREASUREFINDPOOL_E_FINDTREASUREFINDPOOL_LIST_MAX_NUM 256
#define DEFINE_SHEET_FINDTREASURECONSTANT_E_FINDTREASURECONSTANT_LIST_MAX_NUM 2
#define DEFINE_E_FINDTREASURETOTAL_M_ARG_MAX_NUM 2
#define DEFINE_SHEET_FINDTREASURETOTAL_E_FINDTREASURETOTAL_LIST_MAX_NUM 64
#define DEFINE_SHEET_FINDTREASUREACTIVE_E_FINDTREASUREACTIVE_LIST_MAX_NUM 8
#define DEFINE_SHEET_FINDTREASUREACTIVEUP_E_FINDTREASUREACTIVEUP_LIST_MAX_NUM 32
#define DEFINE_SHEET_FINDTREASUREACTIVEGOODS_E_FINDTREASUREACTIVEGOODS_LIST_MAX_NUM 4
#define DEFINE_E_FINDTREASUREACTIVESHOP_M_GOOD_MAX_NUM 4
#define DEFINE_SHEET_FINDTREASUREACTIVESHOP_E_FINDTREASUREACTIVESHOP_LIST_MAX_NUM 4
#define DEFINE_SHEET_FINDTREASURESHOP_E_FINDTREASURESHOP_LIST_MAX_NUM 16


namespace proto_ff_s {

	struct E_FindtreasureFindtreasure_s : public NFDescStoreSeqOP {
		E_FindtreasureFindtreasure_s();
		virtual ~E_FindtreasureFindtreasure_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//类型
		int32_t m_functionunlock;//功能开放
		int64_t m_costid;//道具id
		NFShmString<64> m_costnum;//抽奖消耗
		int32_t m_contitem;//特殊连抽道具
		NFShmString<64> m_poolgroupid;//奖池id
		int32_t m_loop;//第几个奖池后为循环奖池
		int32_t m_pooltime;//奖池轮换时间
		int32_t m_totalgroupid;//累计次数奖励id
		int32_t m_activegroupid;//活动id
		int32_t m_protecttime;//保底奖池次数
		int32_t m_additem;//抽奖额外奖励ID
		int32_t m_addnum;//抽奖额外奖励数量
		int32_t m_shopid;//商城Id
		int32_t m_storehousetype;//仓库类型

		virtual void write_to_pbmsg(::proto_ff::E_FindtreasureFindtreasure & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FindtreasureFindtreasure & msg);
		static ::proto_ff::E_FindtreasureFindtreasure* new_pbmsg(){ return new ::proto_ff::E_FindtreasureFindtreasure(); }
		static ::proto_ff::E_FindtreasureFindtreasure make_pbmsg(){ return ::proto_ff::E_FindtreasureFindtreasure(); }
	};
	typedef struct E_FindtreasureFindtreasure_s E_FindtreasureFindtreasure_t;

	struct Sheet_FindtreasureFindtreasure_s : public NFDescStoreSeqOP {
		Sheet_FindtreasureFindtreasure_s();
		virtual ~Sheet_FindtreasureFindtreasure_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FindtreasureFindtreasure_s, DEFINE_SHEET_FINDTREASUREFINDTREASURE_E_FINDTREASUREFINDTREASURE_LIST_MAX_NUM> E_FindtreasureFindtreasure_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FindtreasureFindtreasure & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureFindtreasure & msg);
		static ::proto_ff::Sheet_FindtreasureFindtreasure* new_pbmsg(){ return new ::proto_ff::Sheet_FindtreasureFindtreasure(); }
		static ::proto_ff::Sheet_FindtreasureFindtreasure make_pbmsg(){ return ::proto_ff::Sheet_FindtreasureFindtreasure(); }
	};
	typedef struct Sheet_FindtreasureFindtreasure_s Sheet_FindtreasureFindtreasure_t;

	struct E_FindtreasureFindpool_s : public NFDescStoreSeqOP {
		E_FindtreasureFindpool_s();
		virtual ~E_FindtreasureFindpool_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupid;//奖池组ID
		int32_t m_showorder;//客户端展示
		int64_t m_itemid;//物品
		int32_t m_num;//数量
		int32_t m_prof;//职业
		int32_t m_weights;//掉落权重
		int32_t m_proweights;//保底掉落权重
		int32_t m_record;//奖励记录稀有度

		virtual void write_to_pbmsg(::proto_ff::E_FindtreasureFindpool & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FindtreasureFindpool & msg);
		static ::proto_ff::E_FindtreasureFindpool* new_pbmsg(){ return new ::proto_ff::E_FindtreasureFindpool(); }
		static ::proto_ff::E_FindtreasureFindpool make_pbmsg(){ return ::proto_ff::E_FindtreasureFindpool(); }
	};
	typedef struct E_FindtreasureFindpool_s E_FindtreasureFindpool_t;

	struct Sheet_FindtreasureFindpool_s : public NFDescStoreSeqOP {
		Sheet_FindtreasureFindpool_s();
		virtual ~Sheet_FindtreasureFindpool_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FindtreasureFindpool_s, DEFINE_SHEET_FINDTREASUREFINDPOOL_E_FINDTREASUREFINDPOOL_LIST_MAX_NUM> E_FindtreasureFindpool_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FindtreasureFindpool & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureFindpool & msg);
		static ::proto_ff::Sheet_FindtreasureFindpool* new_pbmsg(){ return new ::proto_ff::Sheet_FindtreasureFindpool(); }
		static ::proto_ff::Sheet_FindtreasureFindpool make_pbmsg(){ return ::proto_ff::Sheet_FindtreasureFindpool(); }
	};
	typedef struct Sheet_FindtreasureFindpool_s Sheet_FindtreasureFindpool_t;

	struct E_FindtreasureConstant_s : public NFDescStoreSeqOP {
		E_FindtreasureConstant_s();
		virtual ~E_FindtreasureConstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_dragonsevertime;//真龙秘宝开服开启常规刷新时间
		int32_t m_godsevertime;//神机更换奖池时间

		virtual void write_to_pbmsg(::proto_ff::E_FindtreasureConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FindtreasureConstant & msg);
		static ::proto_ff::E_FindtreasureConstant* new_pbmsg(){ return new ::proto_ff::E_FindtreasureConstant(); }
		static ::proto_ff::E_FindtreasureConstant make_pbmsg(){ return ::proto_ff::E_FindtreasureConstant(); }
	};
	typedef struct E_FindtreasureConstant_s E_FindtreasureConstant_t;

	struct Sheet_FindtreasureConstant_s : public NFDescStoreSeqOP {
		Sheet_FindtreasureConstant_s();
		virtual ~Sheet_FindtreasureConstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FindtreasureConstant_s, DEFINE_SHEET_FINDTREASURECONSTANT_E_FINDTREASURECONSTANT_LIST_MAX_NUM> E_FindtreasureConstant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FindtreasureConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureConstant & msg);
		static ::proto_ff::Sheet_FindtreasureConstant* new_pbmsg(){ return new ::proto_ff::Sheet_FindtreasureConstant(); }
		static ::proto_ff::Sheet_FindtreasureConstant make_pbmsg(){ return ::proto_ff::Sheet_FindtreasureConstant(); }
	};
	typedef struct Sheet_FindtreasureConstant_s Sheet_FindtreasureConstant_t;

	struct E_FindtreasureTotal_s : public NFDescStoreSeqOP {
		E_FindtreasureTotal_s();
		virtual ~E_FindtreasureTotal_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupid;//组id
		int32_t m_type;//类型
		int32_t m_itemid;//奖励道具id
		int32_t m_num;//奖励道具数量
		NFShmVector<int32_t, DEFINE_E_FINDTREASURETOTAL_M_ARG_MAX_NUM> m_arg;//参数

		virtual void write_to_pbmsg(::proto_ff::E_FindtreasureTotal & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FindtreasureTotal & msg);
		static ::proto_ff::E_FindtreasureTotal* new_pbmsg(){ return new ::proto_ff::E_FindtreasureTotal(); }
		static ::proto_ff::E_FindtreasureTotal make_pbmsg(){ return ::proto_ff::E_FindtreasureTotal(); }
	};
	typedef struct E_FindtreasureTotal_s E_FindtreasureTotal_t;

	struct Sheet_FindtreasureTotal_s : public NFDescStoreSeqOP {
		Sheet_FindtreasureTotal_s();
		virtual ~Sheet_FindtreasureTotal_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FindtreasureTotal_s, DEFINE_SHEET_FINDTREASURETOTAL_E_FINDTREASURETOTAL_LIST_MAX_NUM> E_FindtreasureTotal_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FindtreasureTotal & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureTotal & msg);
		static ::proto_ff::Sheet_FindtreasureTotal* new_pbmsg(){ return new ::proto_ff::Sheet_FindtreasureTotal(); }
		static ::proto_ff::Sheet_FindtreasureTotal make_pbmsg(){ return ::proto_ff::Sheet_FindtreasureTotal(); }
	};
	typedef struct Sheet_FindtreasureTotal_s Sheet_FindtreasureTotal_t;

	struct E_FindtreasureActive_s : public NFDescStoreSeqOP {
		E_FindtreasureActive_s();
		virtual ~E_FindtreasureActive_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupid;//组id
		int32_t m_opentime;//活动开启时间
		int32_t m_durtime;//持续时间
		int32_t m_closetime;//关闭时间
		int32_t m_type;//活动类型
		int32_t m_typegroupid;//活动组id

		virtual void write_to_pbmsg(::proto_ff::E_FindtreasureActive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FindtreasureActive & msg);
		static ::proto_ff::E_FindtreasureActive* new_pbmsg(){ return new ::proto_ff::E_FindtreasureActive(); }
		static ::proto_ff::E_FindtreasureActive make_pbmsg(){ return ::proto_ff::E_FindtreasureActive(); }
	};
	typedef struct E_FindtreasureActive_s E_FindtreasureActive_t;

	struct Sheet_FindtreasureActive_s : public NFDescStoreSeqOP {
		Sheet_FindtreasureActive_s();
		virtual ~Sheet_FindtreasureActive_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FindtreasureActive_s, DEFINE_SHEET_FINDTREASUREACTIVE_E_FINDTREASUREACTIVE_LIST_MAX_NUM> E_FindtreasureActive_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FindtreasureActive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureActive & msg);
		static ::proto_ff::Sheet_FindtreasureActive* new_pbmsg(){ return new ::proto_ff::Sheet_FindtreasureActive(); }
		static ::proto_ff::Sheet_FindtreasureActive make_pbmsg(){ return ::proto_ff::Sheet_FindtreasureActive(); }
	};
	typedef struct Sheet_FindtreasureActive_s Sheet_FindtreasureActive_t;

	struct E_FindtreasureActiveup_s : public NFDescStoreSeqOP {
		E_FindtreasureActiveup_s();
		virtual ~E_FindtreasureActiveup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupid;//组id
		int32_t m_type;//分类
		int32_t m_itemid;//物品id
		int32_t m_proarg;//调整系数

		virtual void write_to_pbmsg(::proto_ff::E_FindtreasureActiveup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FindtreasureActiveup & msg);
		static ::proto_ff::E_FindtreasureActiveup* new_pbmsg(){ return new ::proto_ff::E_FindtreasureActiveup(); }
		static ::proto_ff::E_FindtreasureActiveup make_pbmsg(){ return ::proto_ff::E_FindtreasureActiveup(); }
	};
	typedef struct E_FindtreasureActiveup_s E_FindtreasureActiveup_t;

	struct Sheet_FindtreasureActiveup_s : public NFDescStoreSeqOP {
		Sheet_FindtreasureActiveup_s();
		virtual ~Sheet_FindtreasureActiveup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FindtreasureActiveup_s, DEFINE_SHEET_FINDTREASUREACTIVEUP_E_FINDTREASUREACTIVEUP_LIST_MAX_NUM> E_FindtreasureActiveup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FindtreasureActiveup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureActiveup & msg);
		static ::proto_ff::Sheet_FindtreasureActiveup* new_pbmsg(){ return new ::proto_ff::Sheet_FindtreasureActiveup(); }
		static ::proto_ff::Sheet_FindtreasureActiveup make_pbmsg(){ return ::proto_ff::Sheet_FindtreasureActiveup(); }
	};
	typedef struct Sheet_FindtreasureActiveup_s Sheet_FindtreasureActiveup_t;

	struct E_FindtreasureActivegoods_s : public NFDescStoreSeqOP {
		E_FindtreasureActivegoods_s();
		virtual ~E_FindtreasureActivegoods_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_groupid;//组id
		int32_t m_itemid;//道具id
		int32_t m_type;//价格类型
		int32_t m_price;//价格
		int32_t m_itemnum;//道具数量

		virtual void write_to_pbmsg(::proto_ff::E_FindtreasureActivegoods & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FindtreasureActivegoods & msg);
		static ::proto_ff::E_FindtreasureActivegoods* new_pbmsg(){ return new ::proto_ff::E_FindtreasureActivegoods(); }
		static ::proto_ff::E_FindtreasureActivegoods make_pbmsg(){ return ::proto_ff::E_FindtreasureActivegoods(); }
	};
	typedef struct E_FindtreasureActivegoods_s E_FindtreasureActivegoods_t;

	struct Sheet_FindtreasureActivegoods_s : public NFDescStoreSeqOP {
		Sheet_FindtreasureActivegoods_s();
		virtual ~Sheet_FindtreasureActivegoods_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FindtreasureActivegoods_s, DEFINE_SHEET_FINDTREASUREACTIVEGOODS_E_FINDTREASUREACTIVEGOODS_LIST_MAX_NUM> E_FindtreasureActivegoods_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FindtreasureActivegoods & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureActivegoods & msg);
		static ::proto_ff::Sheet_FindtreasureActivegoods* new_pbmsg(){ return new ::proto_ff::Sheet_FindtreasureActivegoods(); }
		static ::proto_ff::Sheet_FindtreasureActivegoods make_pbmsg(){ return ::proto_ff::Sheet_FindtreasureActivegoods(); }
	};
	typedef struct Sheet_FindtreasureActivegoods_s Sheet_FindtreasureActivegoods_t;

	struct E_FindtreasureActiveshopGoodDesc_s : public NFDescStoreSeqOP {
		E_FindtreasureActiveshopGoodDesc_s();
		virtual ~E_FindtreasureActiveshopGoodDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_FindtreasureActiveshopGoodDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FindtreasureActiveshopGoodDesc & msg);
		static ::proto_ff::E_FindtreasureActiveshopGoodDesc* new_pbmsg(){ return new ::proto_ff::E_FindtreasureActiveshopGoodDesc(); }
		static ::proto_ff::E_FindtreasureActiveshopGoodDesc make_pbmsg(){ return ::proto_ff::E_FindtreasureActiveshopGoodDesc(); }
	};
	typedef struct E_FindtreasureActiveshopGoodDesc_s E_FindtreasureActiveshopGoodDesc_t;

	struct E_FindtreasureActiveshop_s : public NFDescStoreSeqOP {
		E_FindtreasureActiveshop_s();
		virtual ~E_FindtreasureActiveshop_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupid;//组id
		int32_t m_type;//价格类型
		int32_t m_price;//价格
		int32_t m_times;//限购次数
		NFShmVector<struct E_FindtreasureActiveshopGoodDesc_s, DEFINE_E_FINDTREASUREACTIVESHOP_M_GOOD_MAX_NUM> m_good;//商品

		virtual void write_to_pbmsg(::proto_ff::E_FindtreasureActiveshop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FindtreasureActiveshop & msg);
		static ::proto_ff::E_FindtreasureActiveshop* new_pbmsg(){ return new ::proto_ff::E_FindtreasureActiveshop(); }
		static ::proto_ff::E_FindtreasureActiveshop make_pbmsg(){ return ::proto_ff::E_FindtreasureActiveshop(); }
	};
	typedef struct E_FindtreasureActiveshop_s E_FindtreasureActiveshop_t;

	struct Sheet_FindtreasureActiveshop_s : public NFDescStoreSeqOP {
		Sheet_FindtreasureActiveshop_s();
		virtual ~Sheet_FindtreasureActiveshop_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FindtreasureActiveshop_s, DEFINE_SHEET_FINDTREASUREACTIVESHOP_E_FINDTREASUREACTIVESHOP_LIST_MAX_NUM> E_FindtreasureActiveshop_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FindtreasureActiveshop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureActiveshop & msg);
		static ::proto_ff::Sheet_FindtreasureActiveshop* new_pbmsg(){ return new ::proto_ff::Sheet_FindtreasureActiveshop(); }
		static ::proto_ff::Sheet_FindtreasureActiveshop make_pbmsg(){ return ::proto_ff::Sheet_FindtreasureActiveshop(); }
	};
	typedef struct Sheet_FindtreasureActiveshop_s Sheet_FindtreasureActiveshop_t;

	struct E_FindtreasureShop_s : public NFDescStoreSeqOP {
		E_FindtreasureShop_s();
		virtual ~E_FindtreasureShop_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupid;//组id
		int32_t m_goodsid;//商品id
		int32_t m_goodsnum;//商品数量
		int32_t m_costid;//货币id
		int32_t m_num;//货币数量

		virtual void write_to_pbmsg(::proto_ff::E_FindtreasureShop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FindtreasureShop & msg);
		static ::proto_ff::E_FindtreasureShop* new_pbmsg(){ return new ::proto_ff::E_FindtreasureShop(); }
		static ::proto_ff::E_FindtreasureShop make_pbmsg(){ return ::proto_ff::E_FindtreasureShop(); }
	};
	typedef struct E_FindtreasureShop_s E_FindtreasureShop_t;

	struct Sheet_FindtreasureShop_s : public NFDescStoreSeqOP {
		Sheet_FindtreasureShop_s();
		virtual ~Sheet_FindtreasureShop_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FindtreasureShop_s, DEFINE_SHEET_FINDTREASURESHOP_E_FINDTREASURESHOP_LIST_MAX_NUM> E_FindtreasureShop_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FindtreasureShop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureShop & msg);
		static ::proto_ff::Sheet_FindtreasureShop* new_pbmsg(){ return new ::proto_ff::Sheet_FindtreasureShop(); }
		static ::proto_ff::Sheet_FindtreasureShop make_pbmsg(){ return ::proto_ff::Sheet_FindtreasureShop(); }
	};
	typedef struct Sheet_FindtreasureShop_s Sheet_FindtreasureShop_t;

}

