#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Intimacy.pb.h"
#include "E_Intimacy_s.h"

#define DEFINE_E_INTIMACYINTIMACY_M_ATTRIBUTE_MAX_NUM 3
#define DEFINE_SHEET_INTIMACYINTIMACY_E_INTIMACYINTIMACY_LIST_MAX_NUM 16
#define DEFINE_SHEET_INTIMACYGIFT_E_INTIMACYGIFT_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_IntimacyIntimacyAttributeDesc_s : public NFDescStoreSeqOP {
		E_IntimacyIntimacyAttributeDesc_s();
		virtual ~E_IntimacyIntimacyAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_IntimacyIntimacyAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_IntimacyIntimacyAttributeDesc & msg);
		static ::proto_ff::E_IntimacyIntimacyAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_IntimacyIntimacyAttributeDesc(); }
		static ::proto_ff::E_IntimacyIntimacyAttributeDesc make_pbmsg(){ return ::proto_ff::E_IntimacyIntimacyAttributeDesc(); }
	};
	typedef struct E_IntimacyIntimacyAttributeDesc_s E_IntimacyIntimacyAttributeDesc_t;

	struct E_IntimacyIntimacy_s : public NFDescStoreSeqOP {
		E_IntimacyIntimacy_s();
		virtual ~E_IntimacyIntimacy_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_intimacyMin;//亲密度要求
		int32_t m_intimacyMax;//亲密度要求
		NFShmVector<struct E_IntimacyIntimacyAttributeDesc_s, DEFINE_E_INTIMACYINTIMACY_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_IntimacyIntimacy & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_IntimacyIntimacy & msg);
		static ::proto_ff::E_IntimacyIntimacy* new_pbmsg(){ return new ::proto_ff::E_IntimacyIntimacy(); }
		static ::proto_ff::E_IntimacyIntimacy make_pbmsg(){ return ::proto_ff::E_IntimacyIntimacy(); }
	};
	typedef struct E_IntimacyIntimacy_s E_IntimacyIntimacy_t;

	struct Sheet_IntimacyIntimacy_s : public NFDescStoreSeqOP {
		Sheet_IntimacyIntimacy_s();
		virtual ~Sheet_IntimacyIntimacy_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_IntimacyIntimacy_s, DEFINE_SHEET_INTIMACYINTIMACY_E_INTIMACYINTIMACY_LIST_MAX_NUM> E_IntimacyIntimacy_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_IntimacyIntimacy & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_IntimacyIntimacy & msg);
		static ::proto_ff::Sheet_IntimacyIntimacy* new_pbmsg(){ return new ::proto_ff::Sheet_IntimacyIntimacy(); }
		static ::proto_ff::Sheet_IntimacyIntimacy make_pbmsg(){ return ::proto_ff::Sheet_IntimacyIntimacy(); }
	};
	typedef struct Sheet_IntimacyIntimacy_s Sheet_IntimacyIntimacy_t;

	struct E_IntimacyGift_s : public NFDescStoreSeqOP {
		E_IntimacyGift_s();
		virtual ~E_IntimacyGift_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_mallid;//商城id
		int32_t m_itemId;//道具id
		int32_t m_nameType;//名称类型
		NFShmString<64> m_uiPic;//底框图片
		int32_t m_intimacy;//亲密度
		int32_t m_charm;//魅力值

		virtual void write_to_pbmsg(::proto_ff::E_IntimacyGift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_IntimacyGift & msg);
		static ::proto_ff::E_IntimacyGift* new_pbmsg(){ return new ::proto_ff::E_IntimacyGift(); }
		static ::proto_ff::E_IntimacyGift make_pbmsg(){ return ::proto_ff::E_IntimacyGift(); }
	};
	typedef struct E_IntimacyGift_s E_IntimacyGift_t;

	struct Sheet_IntimacyGift_s : public NFDescStoreSeqOP {
		Sheet_IntimacyGift_s();
		virtual ~Sheet_IntimacyGift_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_IntimacyGift_s, DEFINE_SHEET_INTIMACYGIFT_E_INTIMACYGIFT_LIST_MAX_NUM> E_IntimacyGift_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_IntimacyGift & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_IntimacyGift & msg);
		static ::proto_ff::Sheet_IntimacyGift* new_pbmsg(){ return new ::proto_ff::Sheet_IntimacyGift(); }
		static ::proto_ff::Sheet_IntimacyGift make_pbmsg(){ return ::proto_ff::Sheet_IntimacyGift(); }
	};
	typedef struct Sheet_IntimacyGift_s Sheet_IntimacyGift_t;

}

