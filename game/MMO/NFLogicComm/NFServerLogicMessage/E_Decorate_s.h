#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Decorate.pb.h"
#include "E_Decorate_s.h"

#define DEFINE_E_DECORATEDECORATE_M_ATTRIBUTE_MAX_NUM 8
#define DEFINE_E_DECORATEDECORATE_M_ACTIVEATTRIBUTE_MAX_NUM 8
#define DEFINE_SHEET_DECORATEDECORATE_E_DECORATEDECORATE_LIST_MAX_NUM 64


namespace proto_ff_s {

	struct E_DecorateDecorateAttributeDesc_s : public NFDescStoreSeqOP {
		E_DecorateDecorateAttributeDesc_s();
		virtual ~E_DecorateDecorateAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_DecorateDecorateAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DecorateDecorateAttributeDesc & msg);
		static ::proto_ff::E_DecorateDecorateAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_DecorateDecorateAttributeDesc(); }
		static ::proto_ff::E_DecorateDecorateAttributeDesc make_pbmsg(){ return ::proto_ff::E_DecorateDecorateAttributeDesc(); }
	};
	typedef struct E_DecorateDecorateAttributeDesc_s E_DecorateDecorateAttributeDesc_t;

	struct E_DecorateDecorateActiveattributeDesc_s : public NFDescStoreSeqOP {
		E_DecorateDecorateActiveattributeDesc_s();
		virtual ~E_DecorateDecorateActiveattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_DecorateDecorateActiveattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DecorateDecorateActiveattributeDesc & msg);
		static ::proto_ff::E_DecorateDecorateActiveattributeDesc* new_pbmsg(){ return new ::proto_ff::E_DecorateDecorateActiveattributeDesc(); }
		static ::proto_ff::E_DecorateDecorateActiveattributeDesc make_pbmsg(){ return ::proto_ff::E_DecorateDecorateActiveattributeDesc(); }
	};
	typedef struct E_DecorateDecorateActiveattributeDesc_s E_DecorateDecorateActiveattributeDesc_t;

	struct E_DecorateDecorate_s : public NFDescStoreSeqOP {
		E_DecorateDecorate_s();
		virtual ~E_DecorateDecorate_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_ID;//装饰ID
		NFShmString<64> m_name;//装饰名称
		int32_t m_type;//外观类型
		int32_t m_quality;//眼芒品质
		NFShmString<64> m_professionLimit;//职业限制
		int64_t m_activationItem;//激活道具ID
		int32_t m_activationNum;//激活道具数量
		int64_t m_starId;//升星道具id
		NFShmString<256> m_starNum;//升星道具数量
		int32_t m_starUp;//升星等级上限
		int32_t m_starBer;//每次升星属性增加的百分比值
		NFShmVector<struct E_DecorateDecorateAttributeDesc_s, DEFINE_E_DECORATEDECORATE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性
		NFShmVector<struct E_DecorateDecorateActiveattributeDesc_s, DEFINE_E_DECORATEDECORATE_M_ACTIVEATTRIBUTE_MAX_NUM> m_ActiveAttribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_DecorateDecorate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DecorateDecorate & msg);
		static ::proto_ff::E_DecorateDecorate* new_pbmsg(){ return new ::proto_ff::E_DecorateDecorate(); }
		static ::proto_ff::E_DecorateDecorate make_pbmsg(){ return ::proto_ff::E_DecorateDecorate(); }
	};
	typedef struct E_DecorateDecorate_s E_DecorateDecorate_t;

	struct Sheet_DecorateDecorate_s : public NFDescStoreSeqOP {
		Sheet_DecorateDecorate_s();
		virtual ~Sheet_DecorateDecorate_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DecorateDecorate_s, DEFINE_SHEET_DECORATEDECORATE_E_DECORATEDECORATE_LIST_MAX_NUM> E_DecorateDecorate_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_DecorateDecorate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DecorateDecorate & msg);
		static ::proto_ff::Sheet_DecorateDecorate* new_pbmsg(){ return new ::proto_ff::Sheet_DecorateDecorate(); }
		static ::proto_ff::Sheet_DecorateDecorate make_pbmsg(){ return ::proto_ff::Sheet_DecorateDecorate(); }
	};
	typedef struct Sheet_DecorateDecorate_s Sheet_DecorateDecorate_t;

}

