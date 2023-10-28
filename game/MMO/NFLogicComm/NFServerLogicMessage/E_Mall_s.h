#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Mall.pb.h"
#include "E_Mall_s.h"

#define DEFINE_SHEET_MALLMALL_E_MALLMALL_LIST_MAX_NUM 512
#define DEFINE_SHEET_MALLMALLTYPE_TAB_E_MALLMALLTYPE_TAB_LIST_MAX_NUM 16
#define DEFINE_SHEET_MALLMALLTYPE_E_MALLMALLTYPE_LIST_MAX_NUM 64
#define DEFINE_SHEET_MALLHOLYBEAST_E_MALLHOLYBEAST_LIST_MAX_NUM 32


namespace proto_ff_s {

	struct E_MallMall_s : public NFDescStoreSeqOP {
		E_MallMall_s();
		virtual ~E_MallMall_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//商品ID
		int32_t m_itemid;//物品ID
		int32_t m_malltype;//商城分类
		int32_t m_priority;//优先级
		int32_t m_moneytype;//货币类型
		int32_t m_moneyitem;//货币道具id
		int32_t m_price;//价格
		int32_t m_secondarymoneytype;//次级货币
		int32_t m_discount;//折扣
		int32_t m_buylimittype;//限制购买类型
		int32_t m_buyamount;//购买数量
		int32_t m_viplimit;//VIP等级解锁
		int32_t m_lvlimit;//等级限制
		int32_t m_vipunlock;//vip或等级解锁
		int32_t m_isclose;//是否下架
		int32_t m_cantbuy;//下架情况下是否能购买
		int32_t m_ismarkbind;//是否标记为已绑定

		virtual void write_to_pbmsg(::proto_ff::E_MallMall & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MallMall & msg);
		static ::proto_ff::E_MallMall* new_pbmsg(){ return new ::proto_ff::E_MallMall(); }
		static ::proto_ff::E_MallMall make_pbmsg(){ return ::proto_ff::E_MallMall(); }
	};
	typedef struct E_MallMall_s E_MallMall_t;

	struct Sheet_MallMall_s : public NFDescStoreSeqOP {
		Sheet_MallMall_s();
		virtual ~Sheet_MallMall_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MallMall_s, DEFINE_SHEET_MALLMALL_E_MALLMALL_LIST_MAX_NUM> E_MallMall_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MallMall & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MallMall & msg);
		static ::proto_ff::Sheet_MallMall* new_pbmsg(){ return new ::proto_ff::Sheet_MallMall(); }
		static ::proto_ff::Sheet_MallMall make_pbmsg(){ return ::proto_ff::Sheet_MallMall(); }
	};
	typedef struct Sheet_MallMall_s Sheet_MallMall_t;

	struct E_MallMalltype_tab_s : public NFDescStoreSeqOP {
		E_MallMalltype_tab_s();
		virtual ~E_MallMalltype_tab_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_priority;//优先级
		int32_t m_functionunlock;//开启条件
		int32_t m_entrance;//入口位置

		virtual void write_to_pbmsg(::proto_ff::E_MallMalltype_tab & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MallMalltype_tab & msg);
		static ::proto_ff::E_MallMalltype_tab* new_pbmsg(){ return new ::proto_ff::E_MallMalltype_tab(); }
		static ::proto_ff::E_MallMalltype_tab make_pbmsg(){ return ::proto_ff::E_MallMalltype_tab(); }
	};
	typedef struct E_MallMalltype_tab_s E_MallMalltype_tab_t;

	struct Sheet_MallMalltype_tab_s : public NFDescStoreSeqOP {
		Sheet_MallMalltype_tab_s();
		virtual ~Sheet_MallMalltype_tab_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MallMalltype_tab_s, DEFINE_SHEET_MALLMALLTYPE_TAB_E_MALLMALLTYPE_TAB_LIST_MAX_NUM> E_MallMalltype_tab_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MallMalltype_tab & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MallMalltype_tab & msg);
		static ::proto_ff::Sheet_MallMalltype_tab* new_pbmsg(){ return new ::proto_ff::Sheet_MallMalltype_tab(); }
		static ::proto_ff::Sheet_MallMalltype_tab make_pbmsg(){ return ::proto_ff::Sheet_MallMalltype_tab(); }
	};
	typedef struct Sheet_MallMalltype_tab_s Sheet_MallMalltype_tab_t;

	struct E_MallMalltype_s : public NFDescStoreSeqOP {
		E_MallMalltype_s();
		virtual ~E_MallMalltype_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//组ID
		NFShmString<64> m_title;//商店名
		int32_t m_grouptype;//组类型
		int32_t m_priority;//优先级
		int32_t m_functionunlock;//开启条件
		NFShmString<64> m_profession;//职业类型

		virtual void write_to_pbmsg(::proto_ff::E_MallMalltype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MallMalltype & msg);
		static ::proto_ff::E_MallMalltype* new_pbmsg(){ return new ::proto_ff::E_MallMalltype(); }
		static ::proto_ff::E_MallMalltype make_pbmsg(){ return ::proto_ff::E_MallMalltype(); }
	};
	typedef struct E_MallMalltype_s E_MallMalltype_t;

	struct Sheet_MallMalltype_s : public NFDescStoreSeqOP {
		Sheet_MallMalltype_s();
		virtual ~Sheet_MallMalltype_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MallMalltype_s, DEFINE_SHEET_MALLMALLTYPE_E_MALLMALLTYPE_LIST_MAX_NUM> E_MallMalltype_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MallMalltype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MallMalltype & msg);
		static ::proto_ff::Sheet_MallMalltype* new_pbmsg(){ return new ::proto_ff::Sheet_MallMalltype(); }
		static ::proto_ff::Sheet_MallMalltype make_pbmsg(){ return ::proto_ff::Sheet_MallMalltype(); }
	};
	typedef struct Sheet_MallMalltype_s Sheet_MallMalltype_t;

	struct E_MallHolybeast_s : public NFDescStoreSeqOP {
		E_MallHolybeast_s();
		virtual ~E_MallHolybeast_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_mountid;//坐骑id
		int32_t m_itemid;//商品id
		int32_t m_costid;//兑换道具
		int32_t m_costnum;//道具数量

		virtual void write_to_pbmsg(::proto_ff::E_MallHolybeast & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MallHolybeast & msg);
		static ::proto_ff::E_MallHolybeast* new_pbmsg(){ return new ::proto_ff::E_MallHolybeast(); }
		static ::proto_ff::E_MallHolybeast make_pbmsg(){ return ::proto_ff::E_MallHolybeast(); }
	};
	typedef struct E_MallHolybeast_s E_MallHolybeast_t;

	struct Sheet_MallHolybeast_s : public NFDescStoreSeqOP {
		Sheet_MallHolybeast_s();
		virtual ~Sheet_MallHolybeast_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MallHolybeast_s, DEFINE_SHEET_MALLHOLYBEAST_E_MALLHOLYBEAST_LIST_MAX_NUM> E_MallHolybeast_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MallHolybeast & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MallHolybeast & msg);
		static ::proto_ff::Sheet_MallHolybeast* new_pbmsg(){ return new ::proto_ff::Sheet_MallHolybeast(); }
		static ::proto_ff::Sheet_MallHolybeast make_pbmsg(){ return ::proto_ff::Sheet_MallHolybeast(); }
	};
	typedef struct Sheet_MallHolybeast_s Sheet_MallHolybeast_t;

}

