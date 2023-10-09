#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Area.pb.h"
#include "E_Area_s.h"

#define DEFINE_SHEET_AREAAREA_E_AREAAREA_LIST_MAX_NUM 32


namespace proto_ff_s {

	struct E_AreaArea_s : public NFDescStoreSeqOP {
		E_AreaArea_s();
		virtual ~E_AreaArea_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//区域ID
		int32_t m_subtype;//细分类型
		int64_t m_belongtosceneid;//所属场景
		int32_t m_shapetype;//形状类型
		int32_t m_isnotice;//是否进出提示

		virtual void write_to_pbmsg(::proto_ff::E_AreaArea & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AreaArea & msg);
		static ::proto_ff::E_AreaArea* new_pbmsg(){ return new ::proto_ff::E_AreaArea(); }
		static ::proto_ff::E_AreaArea make_pbmsg(){ return ::proto_ff::E_AreaArea(); }
	};
	typedef struct E_AreaArea_s E_AreaArea_t;

	struct Sheet_AreaArea_s : public NFDescStoreSeqOP {
		Sheet_AreaArea_s();
		virtual ~Sheet_AreaArea_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AreaArea_s, DEFINE_SHEET_AREAAREA_E_AREAAREA_LIST_MAX_NUM> E_AreaArea_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AreaArea & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AreaArea & msg);
		static ::proto_ff::Sheet_AreaArea* new_pbmsg(){ return new ::proto_ff::Sheet_AreaArea(); }
		static ::proto_ff::Sheet_AreaArea make_pbmsg(){ return ::proto_ff::Sheet_AreaArea(); }
	};
	typedef struct Sheet_AreaArea_s Sheet_AreaArea_t;

}

