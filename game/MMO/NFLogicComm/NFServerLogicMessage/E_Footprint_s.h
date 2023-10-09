#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Footprint.pb.h"
#include "E_Footprint_s.h"

#define DEFINE_E_FOOTPRINTFOOTPRINT_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_E_FOOTPRINTFOOTPRINT_M_ACTIVEATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_FOOTPRINTFOOTPRINT_E_FOOTPRINTFOOTPRINT_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_FootprintFootprintAttributeDesc_s : public NFDescStoreSeqOP {
		E_FootprintFootprintAttributeDesc_s();
		virtual ~E_FootprintFootprintAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_FootprintFootprintAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FootprintFootprintAttributeDesc & msg);
		static ::proto_ff::E_FootprintFootprintAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_FootprintFootprintAttributeDesc(); }
		static ::proto_ff::E_FootprintFootprintAttributeDesc make_pbmsg(){ return ::proto_ff::E_FootprintFootprintAttributeDesc(); }
	};
	typedef struct E_FootprintFootprintAttributeDesc_s E_FootprintFootprintAttributeDesc_t;

	struct E_FootprintFootprintActiveattributeDesc_s : public NFDescStoreSeqOP {
		E_FootprintFootprintActiveattributeDesc_s();
		virtual ~E_FootprintFootprintActiveattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_FootprintFootprintActiveattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FootprintFootprintActiveattributeDesc & msg);
		static ::proto_ff::E_FootprintFootprintActiveattributeDesc* new_pbmsg(){ return new ::proto_ff::E_FootprintFootprintActiveattributeDesc(); }
		static ::proto_ff::E_FootprintFootprintActiveattributeDesc make_pbmsg(){ return ::proto_ff::E_FootprintFootprintActiveattributeDesc(); }
	};
	typedef struct E_FootprintFootprintActiveattributeDesc_s E_FootprintFootprintActiveattributeDesc_t;

	struct E_FootprintFootprint_s : public NFDescStoreSeqOP {
		E_FootprintFootprint_s();
		virtual ~E_FootprintFootprint_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//足迹ID
		NFShmString<64> m_name;//足迹名称
		int32_t m_type;//外观类型
		int32_t m_quality;//足迹品质
		NFShmString<64> m_professionlimit;//职业限制
		int64_t m_activationitem;//激活道具ID
		int32_t m_activationnum;//激活道具数量
		int64_t m_starid;//升星道具id
		NFShmString<256> m_starnum;//升星道具数量
		int32_t m_starup;//升星等级上限
		int32_t m_starber;//每次升星属性增加的百分比值
		NFShmVector<struct E_FootprintFootprintAttributeDesc_s, DEFINE_E_FOOTPRINTFOOTPRINT_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性
		NFShmVector<struct E_FootprintFootprintActiveattributeDesc_s, DEFINE_E_FOOTPRINTFOOTPRINT_M_ACTIVEATTRIBUTE_MAX_NUM> m_activeattribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_FootprintFootprint & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FootprintFootprint & msg);
		static ::proto_ff::E_FootprintFootprint* new_pbmsg(){ return new ::proto_ff::E_FootprintFootprint(); }
		static ::proto_ff::E_FootprintFootprint make_pbmsg(){ return ::proto_ff::E_FootprintFootprint(); }
	};
	typedef struct E_FootprintFootprint_s E_FootprintFootprint_t;

	struct Sheet_FootprintFootprint_s : public NFDescStoreSeqOP {
		Sheet_FootprintFootprint_s();
		virtual ~Sheet_FootprintFootprint_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FootprintFootprint_s, DEFINE_SHEET_FOOTPRINTFOOTPRINT_E_FOOTPRINTFOOTPRINT_LIST_MAX_NUM> E_FootprintFootprint_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FootprintFootprint & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FootprintFootprint & msg);
		static ::proto_ff::Sheet_FootprintFootprint* new_pbmsg(){ return new ::proto_ff::Sheet_FootprintFootprint(); }
		static ::proto_ff::Sheet_FootprintFootprint make_pbmsg(){ return ::proto_ff::Sheet_FootprintFootprint(); }
	};
	typedef struct Sheet_FootprintFootprint_s Sheet_FootprintFootprint_t;

}

