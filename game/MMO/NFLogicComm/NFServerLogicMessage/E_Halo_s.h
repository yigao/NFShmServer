#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Halo.pb.h"
#include "E_Halo_s.h"

#define DEFINE_E_HALOHALO_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_E_HALOHALO_M_ACTIVEATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_HALOHALO_E_HALOHALO_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_HaloHaloAttributeDesc_s : public NFDescStoreSeqOP {
		E_HaloHaloAttributeDesc_s();
		virtual ~E_HaloHaloAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_HaloHaloAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_HaloHaloAttributeDesc & msg);
		static ::proto_ff::E_HaloHaloAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_HaloHaloAttributeDesc(); }
		static ::proto_ff::E_HaloHaloAttributeDesc make_pbmsg(){ return ::proto_ff::E_HaloHaloAttributeDesc(); }
	};
	typedef struct E_HaloHaloAttributeDesc_s E_HaloHaloAttributeDesc_t;

	struct E_HaloHaloActiveattributeDesc_s : public NFDescStoreSeqOP {
		E_HaloHaloActiveattributeDesc_s();
		virtual ~E_HaloHaloActiveattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_HaloHaloActiveattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_HaloHaloActiveattributeDesc & msg);
		static ::proto_ff::E_HaloHaloActiveattributeDesc* new_pbmsg(){ return new ::proto_ff::E_HaloHaloActiveattributeDesc(); }
		static ::proto_ff::E_HaloHaloActiveattributeDesc make_pbmsg(){ return ::proto_ff::E_HaloHaloActiveattributeDesc(); }
	};
	typedef struct E_HaloHaloActiveattributeDesc_s E_HaloHaloActiveattributeDesc_t;

	struct E_HaloHalo_s : public NFDescStoreSeqOP {
		E_HaloHalo_s();
		virtual ~E_HaloHalo_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//光环ID
		NFShmString<64> m_name;//光环名称
		int32_t m_type;//外观类型
		int32_t m_quality;//光环品质
		NFShmString<64> m_professionlimit;//职业限制
		int64_t m_activationitem;//激活道具ID
		int32_t m_activationnum;//激活道具数量
		int64_t m_starid;//升星道具id
		NFShmString<256> m_starnum;//升星道具数量
		int32_t m_starup;//升星等级上限
		int32_t m_starber;//每次升星属性增加的百分比值
		NFShmVector<struct E_HaloHaloAttributeDesc_s, DEFINE_E_HALOHALO_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性
		NFShmVector<struct E_HaloHaloActiveattributeDesc_s, DEFINE_E_HALOHALO_M_ACTIVEATTRIBUTE_MAX_NUM> m_activeattribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_HaloHalo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_HaloHalo & msg);
		static ::proto_ff::E_HaloHalo* new_pbmsg(){ return new ::proto_ff::E_HaloHalo(); }
		static ::proto_ff::E_HaloHalo make_pbmsg(){ return ::proto_ff::E_HaloHalo(); }
	};
	typedef struct E_HaloHalo_s E_HaloHalo_t;

	struct Sheet_HaloHalo_s : public NFDescStoreSeqOP {
		Sheet_HaloHalo_s();
		virtual ~Sheet_HaloHalo_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_HaloHalo_s, DEFINE_SHEET_HALOHALO_E_HALOHALO_LIST_MAX_NUM> E_HaloHalo_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_HaloHalo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_HaloHalo & msg);
		static ::proto_ff::Sheet_HaloHalo* new_pbmsg(){ return new ::proto_ff::Sheet_HaloHalo(); }
		static ::proto_ff::Sheet_HaloHalo make_pbmsg(){ return ::proto_ff::Sheet_HaloHalo(); }
	};
	typedef struct Sheet_HaloHalo_s Sheet_HaloHalo_t;

}

