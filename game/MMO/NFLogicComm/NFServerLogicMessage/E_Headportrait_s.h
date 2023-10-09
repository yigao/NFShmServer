#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Headportrait.pb.h"
#include "E_Headportrait_s.h"

#define DEFINE_E_HEADPORTRAITHEAD_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_E_HEADPORTRAITHEAD_M_ACTIVEATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_HEADPORTRAITHEAD_E_HEADPORTRAITHEAD_LIST_MAX_NUM 64


namespace proto_ff_s {

	struct E_HeadportraitHeadAttributeDesc_s : public NFDescStoreSeqOP {
		E_HeadportraitHeadAttributeDesc_s();
		virtual ~E_HeadportraitHeadAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_HeadportraitHeadAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_HeadportraitHeadAttributeDesc & msg);
		static ::proto_ff::E_HeadportraitHeadAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_HeadportraitHeadAttributeDesc(); }
		static ::proto_ff::E_HeadportraitHeadAttributeDesc make_pbmsg(){ return ::proto_ff::E_HeadportraitHeadAttributeDesc(); }
	};
	typedef struct E_HeadportraitHeadAttributeDesc_s E_HeadportraitHeadAttributeDesc_t;

	struct E_HeadportraitHeadActiveattributeDesc_s : public NFDescStoreSeqOP {
		E_HeadportraitHeadActiveattributeDesc_s();
		virtual ~E_HeadportraitHeadActiveattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_HeadportraitHeadActiveattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_HeadportraitHeadActiveattributeDesc & msg);
		static ::proto_ff::E_HeadportraitHeadActiveattributeDesc* new_pbmsg(){ return new ::proto_ff::E_HeadportraitHeadActiveattributeDesc(); }
		static ::proto_ff::E_HeadportraitHeadActiveattributeDesc make_pbmsg(){ return ::proto_ff::E_HeadportraitHeadActiveattributeDesc(); }
	};
	typedef struct E_HeadportraitHeadActiveattributeDesc_s E_HeadportraitHeadActiveattributeDesc_t;

	struct E_HeadportraitHead_s : public NFDescStoreSeqOP {
		E_HeadportraitHead_s();
		virtual ~E_HeadportraitHead_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//头像ID
		NFShmString<64> m_name;//头像名称
		int32_t m_type;//外观类型
		int32_t m_quality;//头像品质
		NFShmString<64> m_professionlimit;//职业限制
		int64_t m_activationitem;//激活道具ID
		int32_t m_activationnum;//激活道具数量
		int64_t m_starid;//升星道具id
		NFShmString<256> m_starnum;//升星道具数量
		int32_t m_starup;//升星等级上限
		int32_t m_starber;//每次升星属性增加的百分比值
		NFShmVector<struct E_HeadportraitHeadAttributeDesc_s, DEFINE_E_HEADPORTRAITHEAD_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性
		NFShmVector<struct E_HeadportraitHeadActiveattributeDesc_s, DEFINE_E_HEADPORTRAITHEAD_M_ACTIVEATTRIBUTE_MAX_NUM> m_activeattribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_HeadportraitHead & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_HeadportraitHead & msg);
		static ::proto_ff::E_HeadportraitHead* new_pbmsg(){ return new ::proto_ff::E_HeadportraitHead(); }
		static ::proto_ff::E_HeadportraitHead make_pbmsg(){ return ::proto_ff::E_HeadportraitHead(); }
	};
	typedef struct E_HeadportraitHead_s E_HeadportraitHead_t;

	struct Sheet_HeadportraitHead_s : public NFDescStoreSeqOP {
		Sheet_HeadportraitHead_s();
		virtual ~Sheet_HeadportraitHead_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_HeadportraitHead_s, DEFINE_SHEET_HEADPORTRAITHEAD_E_HEADPORTRAITHEAD_LIST_MAX_NUM> E_HeadportraitHead_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_HeadportraitHead & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_HeadportraitHead & msg);
		static ::proto_ff::Sheet_HeadportraitHead* new_pbmsg(){ return new ::proto_ff::Sheet_HeadportraitHead(); }
		static ::proto_ff::Sheet_HeadportraitHead make_pbmsg(){ return ::proto_ff::Sheet_HeadportraitHead(); }
	};
	typedef struct Sheet_HeadportraitHead_s Sheet_HeadportraitHead_t;

}

