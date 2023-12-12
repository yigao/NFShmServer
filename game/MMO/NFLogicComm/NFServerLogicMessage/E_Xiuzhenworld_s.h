#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Xiuzhenworld.pb.h"
#include "E_Xiuzhenworld_s.h"

#define DEFINE_SHEET_XIUZHENWORLDWORLD_E_XIUZHENWORLDWORLD_LIST_MAX_NUM 16
#define DEFINE_E_XIUZHENWORLDCONSTANT_M_TIMEITEM_MAX_NUM 3
#define DEFINE_E_XIUZHENWORLDCONSTANT_M_TYPE_MAX_NUM 5
#define DEFINE_SHEET_XIUZHENWORLDCONSTANT_E_XIUZHENWORLDCONSTANT_LIST_MAX_NUM 16
#define DEFINE_SHEET_XIUZHENWORLDEXPMAP_E_XIUZHENWORLDEXPMAP_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_XiuzhenworldWorld_s : public NFDescStoreSeqOP {
		E_XiuzhenworldWorld_s();
		virtual ~E_XiuzhenworldWorld_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//类型
		int32_t m_order;//服务器分配序号
		int32_t m_landDup;//领地副本

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenworldWorld & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenworldWorld & msg);
		static ::proto_ff::E_XiuzhenworldWorld* new_pbmsg(){ return new ::proto_ff::E_XiuzhenworldWorld(); }
		static ::proto_ff::E_XiuzhenworldWorld make_pbmsg(){ return ::proto_ff::E_XiuzhenworldWorld(); }
	};
	typedef struct E_XiuzhenworldWorld_s E_XiuzhenworldWorld_t;

	struct Sheet_XiuzhenworldWorld_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenworldWorld_s();
		virtual ~Sheet_XiuzhenworldWorld_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenworldWorld_s, DEFINE_SHEET_XIUZHENWORLDWORLD_E_XIUZHENWORLDWORLD_LIST_MAX_NUM> E_XiuzhenworldWorld_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenworldWorld & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenworldWorld & msg);
		static ::proto_ff::Sheet_XiuzhenworldWorld* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenworldWorld(); }
		static ::proto_ff::Sheet_XiuzhenworldWorld make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenworldWorld(); }
	};
	typedef struct Sheet_XiuzhenworldWorld_s Sheet_XiuzhenworldWorld_t;

	struct E_XiuzhenworldConstantTimeitemDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenworldConstantTimeitemDesc_s();
		virtual ~E_XiuzhenworldConstantTimeitemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_time;//时间
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenworldConstantTimeitemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenworldConstantTimeitemDesc & msg);
		static ::proto_ff::E_XiuzhenworldConstantTimeitemDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenworldConstantTimeitemDesc(); }
		static ::proto_ff::E_XiuzhenworldConstantTimeitemDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenworldConstantTimeitemDesc(); }
	};
	typedef struct E_XiuzhenworldConstantTimeitemDesc_s E_XiuzhenworldConstantTimeitemDesc_t;

	struct E_XiuzhenworldConstantTypeDesc_s : public NFDescStoreSeqOP {
		E_XiuzhenworldConstantTypeDesc_s();
		virtual ~E_XiuzhenworldConstantTypeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_num;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenworldConstantTypeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenworldConstantTypeDesc & msg);
		static ::proto_ff::E_XiuzhenworldConstantTypeDesc* new_pbmsg(){ return new ::proto_ff::E_XiuzhenworldConstantTypeDesc(); }
		static ::proto_ff::E_XiuzhenworldConstantTypeDesc make_pbmsg(){ return ::proto_ff::E_XiuzhenworldConstantTypeDesc(); }
	};
	typedef struct E_XiuzhenworldConstantTypeDesc_s E_XiuzhenworldConstantTypeDesc_t;

	struct E_XiuzhenworldConstant_s : public NFDescStoreSeqOP {
		E_XiuzhenworldConstant_s();
		virtual ~E_XiuzhenworldConstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_ID;//id
		int32_t m_starFreeTime;//初始免费时间
		NFShmString<64> m_freeTimeMoment;//获得免费时间的时间点
		int32_t m_freeTime;//每次获得的时间
		int32_t m_freeTimeMax;//免费时间上限
		int32_t m_helpid;//帮助信息
		int32_t m_addGExpMax;//神元经验上限
		int32_t m_priPriceType;//特权价格类型
		int32_t m_priceValue;//特权价格
		int32_t m_GExpPriBonus;//特权神元经验加成
		int32_t m_GExpGroupBonus;//组队加成
		int32_t m_mapStart;//地图开始
		int32_t m_mapEnd;//地图结束
		int32_t m_expItemId;//经验的物品ID
		NFShmVector<struct E_XiuzhenworldConstantTimeitemDesc_s, DEFINE_E_XIUZHENWORLDCONSTANT_M_TIMEITEM_MAX_NUM> m_timeItem;//时间道具
		NFShmVector<struct E_XiuzhenworldConstantTypeDesc_s, DEFINE_E_XIUZHENWORLDCONSTANT_M_TYPE_MAX_NUM> m_type;//属性

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenworldConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenworldConstant & msg);
		static ::proto_ff::E_XiuzhenworldConstant* new_pbmsg(){ return new ::proto_ff::E_XiuzhenworldConstant(); }
		static ::proto_ff::E_XiuzhenworldConstant make_pbmsg(){ return ::proto_ff::E_XiuzhenworldConstant(); }
	};
	typedef struct E_XiuzhenworldConstant_s E_XiuzhenworldConstant_t;

	struct Sheet_XiuzhenworldConstant_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenworldConstant_s();
		virtual ~Sheet_XiuzhenworldConstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenworldConstant_s, DEFINE_SHEET_XIUZHENWORLDCONSTANT_E_XIUZHENWORLDCONSTANT_LIST_MAX_NUM> E_XiuzhenworldConstant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenworldConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenworldConstant & msg);
		static ::proto_ff::Sheet_XiuzhenworldConstant* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenworldConstant(); }
		static ::proto_ff::Sheet_XiuzhenworldConstant make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenworldConstant(); }
	};
	typedef struct Sheet_XiuzhenworldConstant_s Sheet_XiuzhenworldConstant_t;

	struct E_XiuzhenworldExpmap_s : public NFDescStoreSeqOP {
		E_XiuzhenworldExpmap_s();
		virtual ~E_XiuzhenworldExpmap_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_conditionGlv;//进入转生要求
		int32_t m_mapid;//地图id

		virtual void write_to_pbmsg(::proto_ff::E_XiuzhenworldExpmap & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_XiuzhenworldExpmap & msg);
		static ::proto_ff::E_XiuzhenworldExpmap* new_pbmsg(){ return new ::proto_ff::E_XiuzhenworldExpmap(); }
		static ::proto_ff::E_XiuzhenworldExpmap make_pbmsg(){ return ::proto_ff::E_XiuzhenworldExpmap(); }
	};
	typedef struct E_XiuzhenworldExpmap_s E_XiuzhenworldExpmap_t;

	struct Sheet_XiuzhenworldExpmap_s : public NFDescStoreSeqOP {
		Sheet_XiuzhenworldExpmap_s();
		virtual ~Sheet_XiuzhenworldExpmap_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_XiuzhenworldExpmap_s, DEFINE_SHEET_XIUZHENWORLDEXPMAP_E_XIUZHENWORLDEXPMAP_LIST_MAX_NUM> E_XiuzhenworldExpmap_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_XiuzhenworldExpmap & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenworldExpmap & msg);
		static ::proto_ff::Sheet_XiuzhenworldExpmap* new_pbmsg(){ return new ::proto_ff::Sheet_XiuzhenworldExpmap(); }
		static ::proto_ff::Sheet_XiuzhenworldExpmap make_pbmsg(){ return ::proto_ff::Sheet_XiuzhenworldExpmap(); }
	};
	typedef struct Sheet_XiuzhenworldExpmap_s Sheet_XiuzhenworldExpmap_t;

}

