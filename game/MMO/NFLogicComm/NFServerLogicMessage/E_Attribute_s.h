#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Attribute.pb.h"
#include "E_Attribute_s.h"

#define DEFINE_SHEET_ATTRIBUTEATTRIBUTE_E_ATTRIBUTEATTRIBUTE_LIST_MAX_NUM 256
#define DEFINE_SHEET_ATTRIBUTESUPPRESS_E_ATTRIBUTESUPPRESS_LIST_MAX_NUM 512
#define DEFINE_SHEET_ATTRIBUTEPOWERSUP_E_ATTRIBUTEPOWERSUP_LIST_MAX_NUM 128


namespace proto_ff_s {

	struct E_AttributeAttribute_s : public NFDescStoreSeqOP {
		E_AttributeAttribute_s();
		virtual ~E_AttributeAttribute_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//属性ID
		int32_t m_percent;//百分比
		float m_power;//战斗力
		int32_t m_systemType;//模块类型

		virtual void write_to_pbmsg(::proto_ff::E_AttributeAttribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AttributeAttribute & msg);
		static ::proto_ff::E_AttributeAttribute* new_pbmsg(){ return new ::proto_ff::E_AttributeAttribute(); }
		static ::proto_ff::E_AttributeAttribute make_pbmsg(){ return ::proto_ff::E_AttributeAttribute(); }
	};
	typedef struct E_AttributeAttribute_s E_AttributeAttribute_t;

	struct Sheet_AttributeAttribute_s : public NFDescStoreSeqOP {
		Sheet_AttributeAttribute_s();
		virtual ~Sheet_AttributeAttribute_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AttributeAttribute_s, DEFINE_SHEET_ATTRIBUTEATTRIBUTE_E_ATTRIBUTEATTRIBUTE_LIST_MAX_NUM> E_AttributeAttribute_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AttributeAttribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AttributeAttribute & msg);
		static ::proto_ff::Sheet_AttributeAttribute* new_pbmsg(){ return new ::proto_ff::Sheet_AttributeAttribute(); }
		static ::proto_ff::Sheet_AttributeAttribute make_pbmsg(){ return ::proto_ff::Sheet_AttributeAttribute(); }
	};
	typedef struct Sheet_AttributeAttribute_s Sheet_AttributeAttribute_t;

	struct E_AttributeSuppress_s : public NFDescStoreSeqOP {
		E_AttributeSuppress_s();
		virtual ~E_AttributeSuppress_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lvlDiff;//等级差
		int32_t m_hitSupPve;//命中压制
		int32_t m_critSupPve;//暴击压制
		int32_t m_killSupPve;//必杀压制
		int32_t m_stateSupPve;//状态压制
		int32_t m_lvSupPve;//等级压制
		int32_t m_hitSupPvp;//命中压制
		int32_t m_critSupPvp;//暴击压制
		int32_t m_killSupPvp;//必杀压制
		int32_t m_stateSupPvp;//状态压制
		int32_t m_lvSupPvp;//等级压制

		virtual void write_to_pbmsg(::proto_ff::E_AttributeSuppress & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AttributeSuppress & msg);
		static ::proto_ff::E_AttributeSuppress* new_pbmsg(){ return new ::proto_ff::E_AttributeSuppress(); }
		static ::proto_ff::E_AttributeSuppress make_pbmsg(){ return ::proto_ff::E_AttributeSuppress(); }
	};
	typedef struct E_AttributeSuppress_s E_AttributeSuppress_t;

	struct Sheet_AttributeSuppress_s : public NFDescStoreSeqOP {
		Sheet_AttributeSuppress_s();
		virtual ~Sheet_AttributeSuppress_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AttributeSuppress_s, DEFINE_SHEET_ATTRIBUTESUPPRESS_E_ATTRIBUTESUPPRESS_LIST_MAX_NUM> E_AttributeSuppress_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AttributeSuppress & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AttributeSuppress & msg);
		static ::proto_ff::Sheet_AttributeSuppress* new_pbmsg(){ return new ::proto_ff::Sheet_AttributeSuppress(); }
		static ::proto_ff::Sheet_AttributeSuppress make_pbmsg(){ return ::proto_ff::Sheet_AttributeSuppress(); }
	};
	typedef struct Sheet_AttributeSuppress_s Sheet_AttributeSuppress_t;

	struct E_AttributePowersup_s : public NFDescStoreSeqOP {
		E_AttributePowersup_s();
		virtual ~E_AttributePowersup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_powerDiff;//战力差
		int32_t m_powerSupPve;//战力压制
		int32_t m_powerSupPvp;//战力压制

		virtual void write_to_pbmsg(::proto_ff::E_AttributePowersup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AttributePowersup & msg);
		static ::proto_ff::E_AttributePowersup* new_pbmsg(){ return new ::proto_ff::E_AttributePowersup(); }
		static ::proto_ff::E_AttributePowersup make_pbmsg(){ return ::proto_ff::E_AttributePowersup(); }
	};
	typedef struct E_AttributePowersup_s E_AttributePowersup_t;

	struct Sheet_AttributePowersup_s : public NFDescStoreSeqOP {
		Sheet_AttributePowersup_s();
		virtual ~Sheet_AttributePowersup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AttributePowersup_s, DEFINE_SHEET_ATTRIBUTEPOWERSUP_E_ATTRIBUTEPOWERSUP_LIST_MAX_NUM> E_AttributePowersup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AttributePowersup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AttributePowersup & msg);
		static ::proto_ff::Sheet_AttributePowersup* new_pbmsg(){ return new ::proto_ff::Sheet_AttributePowersup(); }
		static ::proto_ff::Sheet_AttributePowersup make_pbmsg(){ return ::proto_ff::Sheet_AttributePowersup(); }
	};
	typedef struct Sheet_AttributePowersup_s Sheet_AttributePowersup_t;

}

