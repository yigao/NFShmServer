#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Fashion.pb.h"
#include "E_Fashion_s.h"

#define DEFINE_E_FASHIONFASHION_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_E_FASHIONFASHION_M_ACTIVEATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_FASHIONFASHION_E_FASHIONFASHION_LIST_MAX_NUM 64


namespace proto_ff_s {

	struct E_FashionFashionAttributeDesc_s : public NFDescStoreSeqOP {
		E_FashionFashionAttributeDesc_s();
		virtual ~E_FashionFashionAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_FashionFashionAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FashionFashionAttributeDesc & msg);
		static ::proto_ff::E_FashionFashionAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_FashionFashionAttributeDesc(); }
		static ::proto_ff::E_FashionFashionAttributeDesc make_pbmsg(){ return ::proto_ff::E_FashionFashionAttributeDesc(); }
	};
	typedef struct E_FashionFashionAttributeDesc_s E_FashionFashionAttributeDesc_t;

	struct E_FashionFashionActiveattributeDesc_s : public NFDescStoreSeqOP {
		E_FashionFashionActiveattributeDesc_s();
		virtual ~E_FashionFashionActiveattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_FashionFashionActiveattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FashionFashionActiveattributeDesc & msg);
		static ::proto_ff::E_FashionFashionActiveattributeDesc* new_pbmsg(){ return new ::proto_ff::E_FashionFashionActiveattributeDesc(); }
		static ::proto_ff::E_FashionFashionActiveattributeDesc make_pbmsg(){ return ::proto_ff::E_FashionFashionActiveattributeDesc(); }
	};
	typedef struct E_FashionFashionActiveattributeDesc_s E_FashionFashionActiveattributeDesc_t;

	struct E_FashionFashion_s : public NFDescStoreSeqOP {
		E_FashionFashion_s();
		virtual ~E_FashionFashion_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_ID;//时装ID
		NFShmString<64> m_name;//时装名称
		int32_t m_type;//外观类型
		int32_t m_quality;//时装品质
		NFShmString<64> m_professionLimit;//职业限制
		int32_t m_timeLimit;//是否时效
		int64_t m_activationItem;//激活道具ID
		int32_t m_activationNum;//激活道具数量
		int64_t m_starId;//升星道具id
		NFShmString<256> m_starNum;//升星道具数量
		int32_t m_starUp;//升星等级上限
		int32_t m_starBer;//每次升星属性增加的百分比值
		NFShmVector<struct E_FashionFashionAttributeDesc_s, DEFINE_E_FASHIONFASHION_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性
		NFShmVector<struct E_FashionFashionActiveattributeDesc_s, DEFINE_E_FASHIONFASHION_M_ACTIVEATTRIBUTE_MAX_NUM> m_ActiveAttribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_FashionFashion & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FashionFashion & msg);
		static ::proto_ff::E_FashionFashion* new_pbmsg(){ return new ::proto_ff::E_FashionFashion(); }
		static ::proto_ff::E_FashionFashion make_pbmsg(){ return ::proto_ff::E_FashionFashion(); }
	};
	typedef struct E_FashionFashion_s E_FashionFashion_t;

	struct Sheet_FashionFashion_s : public NFDescStoreSeqOP {
		Sheet_FashionFashion_s();
		virtual ~Sheet_FashionFashion_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FashionFashion_s, DEFINE_SHEET_FASHIONFASHION_E_FASHIONFASHION_LIST_MAX_NUM> E_FashionFashion_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FashionFashion & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FashionFashion & msg);
		static ::proto_ff::Sheet_FashionFashion* new_pbmsg(){ return new ::proto_ff::Sheet_FashionFashion(); }
		static ::proto_ff::Sheet_FashionFashion make_pbmsg(){ return ::proto_ff::Sheet_FashionFashion(); }
	};
	typedef struct Sheet_FashionFashion_s Sheet_FashionFashion_t;

}

