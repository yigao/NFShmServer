#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Collect.pb.h"
#include "E_Collect_s.h"

#define DEFINE_E_COLLECTCOLLECT_M_ATTRIBUT_MAX_NUM 4
#define DEFINE_SHEET_COLLECTCOLLECT_E_COLLECTCOLLECT_LIST_MAX_NUM 64
#define DEFINE_E_COLLECTATTRIBUTETPYE_M_ATTRIBUTE_MAX_NUM 3
#define DEFINE_SHEET_COLLECTATTRIBUTETPYE_E_COLLECTATTRIBUTETPYE_LIST_MAX_NUM 256


namespace proto_ff_s {

	struct E_CollectCollectAttributDesc_s : public NFDescStoreSeqOP {
		E_CollectCollectAttributDesc_s();
		virtual ~E_CollectCollectAttributDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		int32_t m_num;//数量

		virtual void write_to_pbmsg(::proto_ff::E_CollectCollectAttributDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CollectCollectAttributDesc & msg);
		static ::proto_ff::E_CollectCollectAttributDesc* new_pbmsg(){ return new ::proto_ff::E_CollectCollectAttributDesc(); }
		static ::proto_ff::E_CollectCollectAttributDesc make_pbmsg(){ return ::proto_ff::E_CollectCollectAttributDesc(); }
	};
	typedef struct E_CollectCollectAttributDesc_s E_CollectCollectAttributDesc_t;

	struct E_CollectCollect_s : public NFDescStoreSeqOP {
		E_CollectCollect_s();
		virtual ~E_CollectCollect_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		NFShmString<64> m_name;//真甲名称
		int32_t m_lv;//开启等级
		int32_t m_group;//分组
		NFShmString<64> m_stagetitle;//阶段标题
		NFShmString<64> m_position;//装备部位
		int32_t m_grade;//要求阶数
		int32_t m_quality;//要求品质
		int32_t m_star;//要求星级
		int32_t m_skillid;//激活技能
		NFShmVector<struct E_CollectCollectAttributDesc_s, DEFINE_E_COLLECTCOLLECT_M_ATTRIBUT_MAX_NUM> m_attribut;//套装属性

		virtual void write_to_pbmsg(::proto_ff::E_CollectCollect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CollectCollect & msg);
		static ::proto_ff::E_CollectCollect* new_pbmsg(){ return new ::proto_ff::E_CollectCollect(); }
		static ::proto_ff::E_CollectCollect make_pbmsg(){ return ::proto_ff::E_CollectCollect(); }
	};
	typedef struct E_CollectCollect_s E_CollectCollect_t;

	struct Sheet_CollectCollect_s : public NFDescStoreSeqOP {
		Sheet_CollectCollect_s();
		virtual ~Sheet_CollectCollect_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CollectCollect_s, DEFINE_SHEET_COLLECTCOLLECT_E_COLLECTCOLLECT_LIST_MAX_NUM> E_CollectCollect_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CollectCollect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CollectCollect & msg);
		static ::proto_ff::Sheet_CollectCollect* new_pbmsg(){ return new ::proto_ff::Sheet_CollectCollect(); }
		static ::proto_ff::Sheet_CollectCollect make_pbmsg(){ return ::proto_ff::Sheet_CollectCollect(); }
	};
	typedef struct Sheet_CollectCollect_s Sheet_CollectCollect_t;

	struct E_CollectAttributetpyeAttributeDesc_s : public NFDescStoreSeqOP {
		E_CollectAttributetpyeAttributeDesc_s();
		virtual ~E_CollectAttributetpyeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_CollectAttributetpyeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CollectAttributetpyeAttributeDesc & msg);
		static ::proto_ff::E_CollectAttributetpyeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_CollectAttributetpyeAttributeDesc(); }
		static ::proto_ff::E_CollectAttributetpyeAttributeDesc make_pbmsg(){ return ::proto_ff::E_CollectAttributetpyeAttributeDesc(); }
	};
	typedef struct E_CollectAttributetpyeAttributeDesc_s E_CollectAttributetpyeAttributeDesc_t;

	struct E_CollectAttributetpye_s : public NFDescStoreSeqOP {
		E_CollectAttributetpye_s();
		virtual ~E_CollectAttributetpye_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//id
		NFShmVector<struct E_CollectAttributetpyeAttributeDesc_s, DEFINE_E_COLLECTATTRIBUTETPYE_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_CollectAttributetpye & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_CollectAttributetpye & msg);
		static ::proto_ff::E_CollectAttributetpye* new_pbmsg(){ return new ::proto_ff::E_CollectAttributetpye(); }
		static ::proto_ff::E_CollectAttributetpye make_pbmsg(){ return ::proto_ff::E_CollectAttributetpye(); }
	};
	typedef struct E_CollectAttributetpye_s E_CollectAttributetpye_t;

	struct Sheet_CollectAttributetpye_s : public NFDescStoreSeqOP {
		Sheet_CollectAttributetpye_s();
		virtual ~Sheet_CollectAttributetpye_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_CollectAttributetpye_s, DEFINE_SHEET_COLLECTATTRIBUTETPYE_E_COLLECTATTRIBUTETPYE_LIST_MAX_NUM> E_CollectAttributetpye_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_CollectAttributetpye & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_CollectAttributetpye & msg);
		static ::proto_ff::Sheet_CollectAttributetpye* new_pbmsg(){ return new ::proto_ff::Sheet_CollectAttributetpye(); }
		static ::proto_ff::Sheet_CollectAttributetpye make_pbmsg(){ return ::proto_ff::Sheet_CollectAttributetpye(); }
	};
	typedef struct Sheet_CollectAttributetpye_s Sheet_CollectAttributetpye_t;

}

