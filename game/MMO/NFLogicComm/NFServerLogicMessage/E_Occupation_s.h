#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Occupation.pb.h"
#include "E_Occupation_s.h"

#define DEFINE_SHEET_OCCUPATIONOCCUPATION_E_OCCUPATIONOCCUPATION_LIST_MAX_NUM 16
#define DEFINE_SHEET_OCCUPATIONSTAGE_E_OCCUPATIONSTAGE_LIST_MAX_NUM 32
#define DEFINE_E_OCCUPATIONATTRIBUTE_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_OCCUPATIONATTRIBUTE_E_OCCUPATIONATTRIBUTE_LIST_MAX_NUM 64
#define DEFINE_E_OCCUPATIONSOUL_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_OCCUPATIONSOUL_E_OCCUPATIONSOUL_LIST_MAX_NUM 64


namespace proto_ff_s {

	struct E_OccupationOccupation_s : public NFDescStoreSeqOP {
		E_OccupationOccupation_s();
		virtual ~E_OccupationOccupation_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//转职职业ID
		int32_t m_professionID;//主职业ID
		int32_t m_grade;//职业等级
		NFShmString<64> m_equip;//展示武器模型
		NFShmString<64> m_modelID;//展示衣服模型
		NFShmString<128> m_activeDesc;//激活描述
		int32_t m_level;//等级要求
		int64_t m_skill_id;//增加技能ID
		NFShmString<64> m_itemIDs;//转职道具奖励奖励

		virtual void write_to_pbmsg(::proto_ff::E_OccupationOccupation & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_OccupationOccupation & msg);
		static ::proto_ff::E_OccupationOccupation* new_pbmsg(){ return new ::proto_ff::E_OccupationOccupation(); }
		static ::proto_ff::E_OccupationOccupation make_pbmsg(){ return ::proto_ff::E_OccupationOccupation(); }
	};
	typedef struct E_OccupationOccupation_s E_OccupationOccupation_t;

	struct Sheet_OccupationOccupation_s : public NFDescStoreSeqOP {
		Sheet_OccupationOccupation_s();
		virtual ~Sheet_OccupationOccupation_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_OccupationOccupation_s, DEFINE_SHEET_OCCUPATIONOCCUPATION_E_OCCUPATIONOCCUPATION_LIST_MAX_NUM> E_OccupationOccupation_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_OccupationOccupation & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_OccupationOccupation & msg);
		static ::proto_ff::Sheet_OccupationOccupation* new_pbmsg(){ return new ::proto_ff::Sheet_OccupationOccupation(); }
		static ::proto_ff::Sheet_OccupationOccupation make_pbmsg(){ return ::proto_ff::Sheet_OccupationOccupation(); }
	};
	typedef struct Sheet_OccupationOccupation_s Sheet_OccupationOccupation_t;

	struct E_OccupationStage_s : public NFDescStoreSeqOP {
		E_OccupationStage_s();
		virtual ~E_OccupationStage_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_grade;//职业等级
		NFShmString<64> m_stgae;//阶段
		int32_t m_lv;//要求等级
		int32_t m_stgaeAttShow;//属性是否展示用
		int32_t m_stgaeAtt;//阶段属性
		int32_t m_taskId;//阶段任务ID
		int32_t m_battle;//推荐战力
		int32_t m_skillID;//激活技能
		NFShmString<64> m_lightSoul;//点亮龙魂
		int32_t m_soulTpye;//龙魂类型
		int32_t m_itemID;//点亮的道具

		virtual void write_to_pbmsg(::proto_ff::E_OccupationStage & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_OccupationStage & msg);
		static ::proto_ff::E_OccupationStage* new_pbmsg(){ return new ::proto_ff::E_OccupationStage(); }
		static ::proto_ff::E_OccupationStage make_pbmsg(){ return ::proto_ff::E_OccupationStage(); }
	};
	typedef struct E_OccupationStage_s E_OccupationStage_t;

	struct Sheet_OccupationStage_s : public NFDescStoreSeqOP {
		Sheet_OccupationStage_s();
		virtual ~Sheet_OccupationStage_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_OccupationStage_s, DEFINE_SHEET_OCCUPATIONSTAGE_E_OCCUPATIONSTAGE_LIST_MAX_NUM> E_OccupationStage_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_OccupationStage & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_OccupationStage & msg);
		static ::proto_ff::Sheet_OccupationStage* new_pbmsg(){ return new ::proto_ff::Sheet_OccupationStage(); }
		static ::proto_ff::Sheet_OccupationStage make_pbmsg(){ return ::proto_ff::Sheet_OccupationStage(); }
	};
	typedef struct Sheet_OccupationStage_s Sheet_OccupationStage_t;

	struct E_OccupationAttributeAttributeDesc_s : public NFDescStoreSeqOP {
		E_OccupationAttributeAttributeDesc_s();
		virtual ~E_OccupationAttributeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数量
		int32_t m_item;//ID

		virtual void write_to_pbmsg(::proto_ff::E_OccupationAttributeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_OccupationAttributeAttributeDesc & msg);
		static ::proto_ff::E_OccupationAttributeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_OccupationAttributeAttributeDesc(); }
		static ::proto_ff::E_OccupationAttributeAttributeDesc make_pbmsg(){ return ::proto_ff::E_OccupationAttributeAttributeDesc(); }
	};
	typedef struct E_OccupationAttributeAttributeDesc_s E_OccupationAttributeAttributeDesc_t;

	struct E_OccupationAttribute_s : public NFDescStoreSeqOP {
		E_OccupationAttribute_s();
		virtual ~E_OccupationAttribute_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//属性id
		NFShmVector<struct E_OccupationAttributeAttributeDesc_s, DEFINE_E_OCCUPATIONATTRIBUTE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性道具

		virtual void write_to_pbmsg(::proto_ff::E_OccupationAttribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_OccupationAttribute & msg);
		static ::proto_ff::E_OccupationAttribute* new_pbmsg(){ return new ::proto_ff::E_OccupationAttribute(); }
		static ::proto_ff::E_OccupationAttribute make_pbmsg(){ return ::proto_ff::E_OccupationAttribute(); }
	};
	typedef struct E_OccupationAttribute_s E_OccupationAttribute_t;

	struct Sheet_OccupationAttribute_s : public NFDescStoreSeqOP {
		Sheet_OccupationAttribute_s();
		virtual ~Sheet_OccupationAttribute_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_OccupationAttribute_s, DEFINE_SHEET_OCCUPATIONATTRIBUTE_E_OCCUPATIONATTRIBUTE_LIST_MAX_NUM> E_OccupationAttribute_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_OccupationAttribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_OccupationAttribute & msg);
		static ::proto_ff::Sheet_OccupationAttribute* new_pbmsg(){ return new ::proto_ff::Sheet_OccupationAttribute(); }
		static ::proto_ff::Sheet_OccupationAttribute make_pbmsg(){ return ::proto_ff::Sheet_OccupationAttribute(); }
	};
	typedef struct Sheet_OccupationAttribute_s Sheet_OccupationAttribute_t;

	struct E_OccupationSoulAttributeDesc_s : public NFDescStoreSeqOP {
		E_OccupationSoulAttributeDesc_s();
		virtual ~E_OccupationSoulAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_OccupationSoulAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_OccupationSoulAttributeDesc & msg);
		static ::proto_ff::E_OccupationSoulAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_OccupationSoulAttributeDesc(); }
		static ::proto_ff::E_OccupationSoulAttributeDesc make_pbmsg(){ return ::proto_ff::E_OccupationSoulAttributeDesc(); }
	};
	typedef struct E_OccupationSoulAttributeDesc_s E_OccupationSoulAttributeDesc_t;

	struct E_OccupationSoul_s : public NFDescStoreSeqOP {
		E_OccupationSoul_s();
		virtual ~E_OccupationSoul_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//属性id
		int32_t m_soulTpye;//属性类型
		int32_t m_position;//位置
		NFShmVector<struct E_OccupationSoulAttributeDesc_s, DEFINE_E_OCCUPATIONSOUL_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_OccupationSoul & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_OccupationSoul & msg);
		static ::proto_ff::E_OccupationSoul* new_pbmsg(){ return new ::proto_ff::E_OccupationSoul(); }
		static ::proto_ff::E_OccupationSoul make_pbmsg(){ return ::proto_ff::E_OccupationSoul(); }
	};
	typedef struct E_OccupationSoul_s E_OccupationSoul_t;

	struct Sheet_OccupationSoul_s : public NFDescStoreSeqOP {
		Sheet_OccupationSoul_s();
		virtual ~Sheet_OccupationSoul_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_OccupationSoul_s, DEFINE_SHEET_OCCUPATIONSOUL_E_OCCUPATIONSOUL_LIST_MAX_NUM> E_OccupationSoul_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_OccupationSoul & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_OccupationSoul & msg);
		static ::proto_ff::Sheet_OccupationSoul* new_pbmsg(){ return new ::proto_ff::Sheet_OccupationSoul(); }
		static ::proto_ff::Sheet_OccupationSoul make_pbmsg(){ return ::proto_ff::Sheet_OccupationSoul(); }
	};
	typedef struct Sheet_OccupationSoul_s Sheet_OccupationSoul_t;

}

