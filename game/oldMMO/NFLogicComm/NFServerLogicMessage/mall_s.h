#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "mall.pb.h"
#include "mall_s.h"

#define DEFINE_SHEET_MALLMALL_E_MALLMALL_LIST_MAX_NUM 60
#define DEFINE_SHEET_MALLMALLTYPE_E_MALLMALLTYPE_LIST_MAX_NUM 20
#define DEFINE_SHEET_MALLMALLTYPE_TAB_E_MALLMALLTYPE_TAB_LIST_MAX_NUM 20
namespace proto_ff_s {

	struct E_MallMall_s : public NFDescStoreSeqOP {
		E_MallMall_s();
		virtual ~E_MallMall_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_itemid;
		int32_t m_malltype;
		int32_t m_priority;
		int32_t m_moneytype;
		int32_t m_price;
		int32_t m_secondarymoneytype;
		int32_t m_discount;
		int32_t m_buylimittype;
		int32_t m_buyamount;
		int32_t m_viplimit;
		int32_t m_lvlimit;
		int32_t m_vipunlock;
		int32_t m_isclose;
		int32_t m_cantbuy;
		int32_t m_ismarkbind;

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
		NFShmVector<struct E_MallMall_s, DEFINE_SHEET_MALLMALL_E_MALLMALL_LIST_MAX_NUM> E_MallMall_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MallMall & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MallMall & msg);
		static ::proto_ff::Sheet_MallMall* new_pbmsg(){ return new ::proto_ff::Sheet_MallMall(); }
		static ::proto_ff::Sheet_MallMall make_pbmsg(){ return ::proto_ff::Sheet_MallMall(); }
	};
	typedef struct Sheet_MallMall_s Sheet_MallMall_t;

	struct E_MallMalltype_s : public NFDescStoreSeqOP {
		E_MallMalltype_s();
		virtual ~E_MallMalltype_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		NFShmString<60> m_title;
		int32_t m_grouptype;
		int32_t m_priority;
		int32_t m_functionunlock;

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
		NFShmVector<struct E_MallMalltype_s, DEFINE_SHEET_MALLMALLTYPE_E_MALLMALLTYPE_LIST_MAX_NUM> E_MallMalltype_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MallMalltype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MallMalltype & msg);
		static ::proto_ff::Sheet_MallMalltype* new_pbmsg(){ return new ::proto_ff::Sheet_MallMalltype(); }
		static ::proto_ff::Sheet_MallMalltype make_pbmsg(){ return ::proto_ff::Sheet_MallMalltype(); }
	};
	typedef struct Sheet_MallMalltype_s Sheet_MallMalltype_t;

	struct E_MallMalltype_tab_s : public NFDescStoreSeqOP {
		E_MallMalltype_tab_s();
		virtual ~E_MallMalltype_tab_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_priority;
		int32_t m_functionunlock;

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
		NFShmVector<struct E_MallMalltype_tab_s, DEFINE_SHEET_MALLMALLTYPE_TAB_E_MALLMALLTYPE_TAB_LIST_MAX_NUM> E_MallMalltype_tab_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MallMalltype_tab & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MallMalltype_tab & msg);
		static ::proto_ff::Sheet_MallMalltype_tab* new_pbmsg(){ return new ::proto_ff::Sheet_MallMalltype_tab(); }
		static ::proto_ff::Sheet_MallMalltype_tab make_pbmsg(){ return ::proto_ff::Sheet_MallMalltype_tab(); }
	};
	typedef struct Sheet_MallMalltype_tab_s Sheet_MallMalltype_tab_t;

}

