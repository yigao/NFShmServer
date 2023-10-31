#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Qypeak.pb.h"
#include "E_Qypeak_s.h"

#define DEFINE_SHEET_QYPEAKBACK_E_QYPEAKBACK_LIST_MAX_NUM 16
#define DEFINE_E_QYPEAKCONSTANT_M_RANKREWARD_MAX_NUM 3
#define DEFINE_E_QYPEAKCONSTANT_M_TITLESHOW_MAX_NUM 3
#define DEFINE_SHEET_QYPEAKCONSTANT_E_QYPEAKCONSTANT_LIST_MAX_NUM 2


namespace proto_ff_s {

	struct E_QypeakBack_s : public NFDescStoreSeqOP {
		E_QypeakBack_s();
		virtual ~E_QypeakBack_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_layers;//层数
		int32_t m_skillNum;//击杀数量
		int32_t m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_QypeakBack & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_QypeakBack & msg);
		static ::proto_ff::E_QypeakBack* new_pbmsg(){ return new ::proto_ff::E_QypeakBack(); }
		static ::proto_ff::E_QypeakBack make_pbmsg(){ return ::proto_ff::E_QypeakBack(); }
	};
	typedef struct E_QypeakBack_s E_QypeakBack_t;

	struct Sheet_QypeakBack_s : public NFDescStoreSeqOP {
		Sheet_QypeakBack_s();
		virtual ~Sheet_QypeakBack_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_QypeakBack_s, DEFINE_SHEET_QYPEAKBACK_E_QYPEAKBACK_LIST_MAX_NUM> E_QypeakBack_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_QypeakBack & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_QypeakBack & msg);
		static ::proto_ff::Sheet_QypeakBack* new_pbmsg(){ return new ::proto_ff::Sheet_QypeakBack(); }
		static ::proto_ff::Sheet_QypeakBack make_pbmsg(){ return ::proto_ff::Sheet_QypeakBack(); }
	};
	typedef struct Sheet_QypeakBack_s Sheet_QypeakBack_t;

	struct E_QypeakConstant_s : public NFDescStoreSeqOP {
		E_QypeakConstant_s();
		virtual ~E_QypeakConstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_mapid;//地图id
		int32_t m_revivalBuff;//复活buff
		NFShmVector<int32_t, DEFINE_E_QYPEAKCONSTANT_M_RANKREWARD_MAX_NUM> m_rankreward;//排名奖励
		NFShmVector<int32_t, DEFINE_E_QYPEAKCONSTANT_M_TITLESHOW_MAX_NUM> m_titleshow;//称号展示

		virtual void write_to_pbmsg(::proto_ff::E_QypeakConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_QypeakConstant & msg);
		static ::proto_ff::E_QypeakConstant* new_pbmsg(){ return new ::proto_ff::E_QypeakConstant(); }
		static ::proto_ff::E_QypeakConstant make_pbmsg(){ return ::proto_ff::E_QypeakConstant(); }
	};
	typedef struct E_QypeakConstant_s E_QypeakConstant_t;

	struct Sheet_QypeakConstant_s : public NFDescStoreSeqOP {
		Sheet_QypeakConstant_s();
		virtual ~Sheet_QypeakConstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_QypeakConstant_s, DEFINE_SHEET_QYPEAKCONSTANT_E_QYPEAKCONSTANT_LIST_MAX_NUM> E_QypeakConstant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_QypeakConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_QypeakConstant & msg);
		static ::proto_ff::Sheet_QypeakConstant* new_pbmsg(){ return new ::proto_ff::Sheet_QypeakConstant(); }
		static ::proto_ff::Sheet_QypeakConstant make_pbmsg(){ return ::proto_ff::Sheet_QypeakConstant(); }
	};
	typedef struct Sheet_QypeakConstant_s Sheet_QypeakConstant_t;

}

