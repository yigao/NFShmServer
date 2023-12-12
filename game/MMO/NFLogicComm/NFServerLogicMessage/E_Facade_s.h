#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Facade.pb.h"
#include "E_Facade_s.h"

#define DEFINE_E_FACADEDISPLAY_M_MATERIAL_MAX_NUM 3
#define DEFINE_E_FACADEDISPLAY_M_FRAGMENTID_MAX_NUM 3
#define DEFINE_SHEET_FACADEDISPLAY_E_FACADEDISPLAY_LIST_MAX_NUM 8
#define DEFINE_E_FACADEVALUE_M_WINGATTRIBUTE_MAX_NUM 4
#define DEFINE_E_FACADEVALUE_M_TREASUREATTRIBUTE_MAX_NUM 5
#define DEFINE_E_FACADEVALUE_M_ARTIFACTATTRIBUTE_MAX_NUM 6
#define DEFINE_E_FACADEVALUE_M_BLADEATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_FACADEVALUE_E_FACADEVALUE_LIST_MAX_NUM 1024
#define DEFINE_SHEET_FACADETYPE_E_FACADETYPE_LIST_MAX_NUM 8
#define DEFINE_E_FACADEFRAGMENT_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_FACADEFRAGMENT_E_FACADEFRAGMENT_LIST_MAX_NUM 16
#define DEFINE_E_FACADECHANGE_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_E_FACADECHANGE_M_ACTIVEATTRIBUTE_MAX_NUM 7
#define DEFINE_SHEET_FACADECHANGE_E_FACADECHANGE_LIST_MAX_NUM 64
#define DEFINE_E_FACADESTARUP_M_UPATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_FACADESTARUP_E_FACADESTARUP_LIST_MAX_NUM 512
#define DEFINE_E_FACADESOUL_M_MINORSKILL_MAX_NUM 8
#define DEFINE_E_FACADESOUL_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_FACADESOUL_E_FACADESOUL_LIST_MAX_NUM 8
#define DEFINE_E_FACADESOULACTIVE_M_UNLOCK_MAX_NUM 2
#define DEFINE_SHEET_FACADESOULACTIVE_E_FACADESOULACTIVE_LIST_MAX_NUM 32
#define DEFINE_E_FACADESOULLV_M_ATTRIBUTE_MAX_NUM 7
#define DEFINE_SHEET_FACADESOULLV_E_FACADESOULLV_LIST_MAX_NUM 512
#define DEFINE_SHEET_FACADESOULACHIEVEMENT_E_FACADESOULACHIEVEMENT_LIST_MAX_NUM 128


namespace proto_ff_s {

	struct E_FacadeDisplayMaterialDesc_s : public NFDescStoreSeqOP {
		E_FacadeDisplayMaterialDesc_s();
		virtual ~E_FacadeDisplayMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_exp;//经验值
		int64_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_FacadeDisplayMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeDisplayMaterialDesc & msg);
		static ::proto_ff::E_FacadeDisplayMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_FacadeDisplayMaterialDesc(); }
		static ::proto_ff::E_FacadeDisplayMaterialDesc make_pbmsg(){ return ::proto_ff::E_FacadeDisplayMaterialDesc(); }
	};
	typedef struct E_FacadeDisplayMaterialDesc_s E_FacadeDisplayMaterialDesc_t;

	struct E_FacadeDisplay_s : public NFDescStoreSeqOP {
		E_FacadeDisplay_s();
		virtual ~E_FacadeDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//外观ID
		int32_t m_type;//大类
		NFShmString<64> m_resource;//资源形象
		NFShmString<64> m_name;//名字
		NFShmString<64> m_activeDesc;//激活描述
		NFShmString<64> m_professionID;//职业ID
		NFShmString<64> m_skillID;//解锁技能ID
		int32_t m_soulIID;//器魂ID
		NFShmVector<struct E_FacadeDisplayMaterialDesc_s, DEFINE_E_FACADEDISPLAY_M_MATERIAL_MAX_NUM> m_material;//进阶材料
		NFShmVector<int64_t, DEFINE_E_FACADEDISPLAY_M_FRAGMENTID_MAX_NUM> m_fragmentID;//关联碎片ID

		virtual void write_to_pbmsg(::proto_ff::E_FacadeDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeDisplay & msg);
		static ::proto_ff::E_FacadeDisplay* new_pbmsg(){ return new ::proto_ff::E_FacadeDisplay(); }
		static ::proto_ff::E_FacadeDisplay make_pbmsg(){ return ::proto_ff::E_FacadeDisplay(); }
	};
	typedef struct E_FacadeDisplay_s E_FacadeDisplay_t;

	struct Sheet_FacadeDisplay_s : public NFDescStoreSeqOP {
		Sheet_FacadeDisplay_s();
		virtual ~Sheet_FacadeDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FacadeDisplay_s, DEFINE_SHEET_FACADEDISPLAY_E_FACADEDISPLAY_LIST_MAX_NUM> E_FacadeDisplay_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FacadeDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FacadeDisplay & msg);
		static ::proto_ff::Sheet_FacadeDisplay* new_pbmsg(){ return new ::proto_ff::Sheet_FacadeDisplay(); }
		static ::proto_ff::Sheet_FacadeDisplay make_pbmsg(){ return ::proto_ff::Sheet_FacadeDisplay(); }
	};
	typedef struct Sheet_FacadeDisplay_s Sheet_FacadeDisplay_t;

	struct E_FacadeValueWingattributeDesc_s : public NFDescStoreSeqOP {
		E_FacadeValueWingattributeDesc_s();
		virtual ~E_FacadeValueWingattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_FacadeValueWingattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeValueWingattributeDesc & msg);
		static ::proto_ff::E_FacadeValueWingattributeDesc* new_pbmsg(){ return new ::proto_ff::E_FacadeValueWingattributeDesc(); }
		static ::proto_ff::E_FacadeValueWingattributeDesc make_pbmsg(){ return ::proto_ff::E_FacadeValueWingattributeDesc(); }
	};
	typedef struct E_FacadeValueWingattributeDesc_s E_FacadeValueWingattributeDesc_t;

	struct E_FacadeValueTreasureattributeDesc_s : public NFDescStoreSeqOP {
		E_FacadeValueTreasureattributeDesc_s();
		virtual ~E_FacadeValueTreasureattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_FacadeValueTreasureattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeValueTreasureattributeDesc & msg);
		static ::proto_ff::E_FacadeValueTreasureattributeDesc* new_pbmsg(){ return new ::proto_ff::E_FacadeValueTreasureattributeDesc(); }
		static ::proto_ff::E_FacadeValueTreasureattributeDesc make_pbmsg(){ return ::proto_ff::E_FacadeValueTreasureattributeDesc(); }
	};
	typedef struct E_FacadeValueTreasureattributeDesc_s E_FacadeValueTreasureattributeDesc_t;

	struct E_FacadeValueArtifactattributeDesc_s : public NFDescStoreSeqOP {
		E_FacadeValueArtifactattributeDesc_s();
		virtual ~E_FacadeValueArtifactattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_FacadeValueArtifactattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeValueArtifactattributeDesc & msg);
		static ::proto_ff::E_FacadeValueArtifactattributeDesc* new_pbmsg(){ return new ::proto_ff::E_FacadeValueArtifactattributeDesc(); }
		static ::proto_ff::E_FacadeValueArtifactattributeDesc make_pbmsg(){ return ::proto_ff::E_FacadeValueArtifactattributeDesc(); }
	};
	typedef struct E_FacadeValueArtifactattributeDesc_s E_FacadeValueArtifactattributeDesc_t;

	struct E_FacadeValueBladeattributeDesc_s : public NFDescStoreSeqOP {
		E_FacadeValueBladeattributeDesc_s();
		virtual ~E_FacadeValueBladeattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_FacadeValueBladeattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeValueBladeattributeDesc & msg);
		static ::proto_ff::E_FacadeValueBladeattributeDesc* new_pbmsg(){ return new ::proto_ff::E_FacadeValueBladeattributeDesc(); }
		static ::proto_ff::E_FacadeValueBladeattributeDesc make_pbmsg(){ return ::proto_ff::E_FacadeValueBladeattributeDesc(); }
	};
	typedef struct E_FacadeValueBladeattributeDesc_s E_FacadeValueBladeattributeDesc_t;

	struct E_FacadeValue_s : public NFDescStoreSeqOP {
		E_FacadeValue_s();
		virtual ~E_FacadeValue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int64_t m_wingExp;//翅膀升级经验
		int64_t m_treasureExp;//宝物升级经验
		int64_t m_ArtifactExp;//神器升级经验
		int64_t m_BladeExp;//剑灵升级经验
		NFShmVector<struct E_FacadeValueWingattributeDesc_s, DEFINE_E_FACADEVALUE_M_WINGATTRIBUTE_MAX_NUM> m_wingAttribute;//翅膀基础属性
		NFShmVector<struct E_FacadeValueTreasureattributeDesc_s, DEFINE_E_FACADEVALUE_M_TREASUREATTRIBUTE_MAX_NUM> m_treasureAttribute;//宝具基础属性
		NFShmVector<struct E_FacadeValueArtifactattributeDesc_s, DEFINE_E_FACADEVALUE_M_ARTIFACTATTRIBUTE_MAX_NUM> m_ArtifactAttribute;//神器基础属性
		NFShmVector<struct E_FacadeValueBladeattributeDesc_s, DEFINE_E_FACADEVALUE_M_BLADEATTRIBUTE_MAX_NUM> m_BladeAttribute;//神器基础属性

		virtual void write_to_pbmsg(::proto_ff::E_FacadeValue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeValue & msg);
		static ::proto_ff::E_FacadeValue* new_pbmsg(){ return new ::proto_ff::E_FacadeValue(); }
		static ::proto_ff::E_FacadeValue make_pbmsg(){ return ::proto_ff::E_FacadeValue(); }
	};
	typedef struct E_FacadeValue_s E_FacadeValue_t;

	struct Sheet_FacadeValue_s : public NFDescStoreSeqOP {
		Sheet_FacadeValue_s();
		virtual ~Sheet_FacadeValue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FacadeValue_s, DEFINE_SHEET_FACADEVALUE_E_FACADEVALUE_LIST_MAX_NUM> E_FacadeValue_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FacadeValue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FacadeValue & msg);
		static ::proto_ff::Sheet_FacadeValue* new_pbmsg(){ return new ::proto_ff::Sheet_FacadeValue(); }
		static ::proto_ff::Sheet_FacadeValue make_pbmsg(){ return ::proto_ff::Sheet_FacadeValue(); }
	};
	typedef struct Sheet_FacadeValue_s Sheet_FacadeValue_t;

	struct E_FacadeType_s : public NFDescStoreSeqOP {
		E_FacadeType_s();
		virtual ~E_FacadeType_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//类型id
		NFShmString<64> m_souceName;//资源名称

		virtual void write_to_pbmsg(::proto_ff::E_FacadeType & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeType & msg);
		static ::proto_ff::E_FacadeType* new_pbmsg(){ return new ::proto_ff::E_FacadeType(); }
		static ::proto_ff::E_FacadeType make_pbmsg(){ return ::proto_ff::E_FacadeType(); }
	};
	typedef struct E_FacadeType_s E_FacadeType_t;

	struct Sheet_FacadeType_s : public NFDescStoreSeqOP {
		Sheet_FacadeType_s();
		virtual ~Sheet_FacadeType_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FacadeType_s, DEFINE_SHEET_FACADETYPE_E_FACADETYPE_LIST_MAX_NUM> E_FacadeType_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FacadeType & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FacadeType & msg);
		static ::proto_ff::Sheet_FacadeType* new_pbmsg(){ return new ::proto_ff::Sheet_FacadeType(); }
		static ::proto_ff::Sheet_FacadeType make_pbmsg(){ return ::proto_ff::Sheet_FacadeType(); }
	};
	typedef struct Sheet_FacadeType_s Sheet_FacadeType_t;

	struct E_FacadeFragmentAttributeDesc_s : public NFDescStoreSeqOP {
		E_FacadeFragmentAttributeDesc_s();
		virtual ~E_FacadeFragmentAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_FacadeFragmentAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeFragmentAttributeDesc & msg);
		static ::proto_ff::E_FacadeFragmentAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_FacadeFragmentAttributeDesc(); }
		static ::proto_ff::E_FacadeFragmentAttributeDesc make_pbmsg(){ return ::proto_ff::E_FacadeFragmentAttributeDesc(); }
	};
	typedef struct E_FacadeFragmentAttributeDesc_s E_FacadeFragmentAttributeDesc_t;

	struct E_FacadeFragment_s : public NFDescStoreSeqOP {
		E_FacadeFragment_s();
		virtual ~E_FacadeFragment_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_fragmentID;//碎片ID
		int64_t m_item;//物品ID
		int32_t m_itemNum;//碎片使用上限
		NFShmVector<struct E_FacadeFragmentAttributeDesc_s, DEFINE_E_FACADEFRAGMENT_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_FacadeFragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeFragment & msg);
		static ::proto_ff::E_FacadeFragment* new_pbmsg(){ return new ::proto_ff::E_FacadeFragment(); }
		static ::proto_ff::E_FacadeFragment make_pbmsg(){ return ::proto_ff::E_FacadeFragment(); }
	};
	typedef struct E_FacadeFragment_s E_FacadeFragment_t;

	struct Sheet_FacadeFragment_s : public NFDescStoreSeqOP {
		Sheet_FacadeFragment_s();
		virtual ~Sheet_FacadeFragment_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FacadeFragment_s, DEFINE_SHEET_FACADEFRAGMENT_E_FACADEFRAGMENT_LIST_MAX_NUM> E_FacadeFragment_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FacadeFragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FacadeFragment & msg);
		static ::proto_ff::Sheet_FacadeFragment* new_pbmsg(){ return new ::proto_ff::Sheet_FacadeFragment(); }
		static ::proto_ff::Sheet_FacadeFragment make_pbmsg(){ return ::proto_ff::Sheet_FacadeFragment(); }
	};
	typedef struct Sheet_FacadeFragment_s Sheet_FacadeFragment_t;

	struct E_FacadeChangeAttributeDesc_s : public NFDescStoreSeqOP {
		E_FacadeChangeAttributeDesc_s();
		virtual ~E_FacadeChangeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_FacadeChangeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeChangeAttributeDesc & msg);
		static ::proto_ff::E_FacadeChangeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_FacadeChangeAttributeDesc(); }
		static ::proto_ff::E_FacadeChangeAttributeDesc make_pbmsg(){ return ::proto_ff::E_FacadeChangeAttributeDesc(); }
	};
	typedef struct E_FacadeChangeAttributeDesc_s E_FacadeChangeAttributeDesc_t;

	struct E_FacadeChangeActiveattributeDesc_s : public NFDescStoreSeqOP {
		E_FacadeChangeActiveattributeDesc_s();
		virtual ~E_FacadeChangeActiveattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_FacadeChangeActiveattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeChangeActiveattributeDesc & msg);
		static ::proto_ff::E_FacadeChangeActiveattributeDesc* new_pbmsg(){ return new ::proto_ff::E_FacadeChangeActiveattributeDesc(); }
		static ::proto_ff::E_FacadeChangeActiveattributeDesc make_pbmsg(){ return ::proto_ff::E_FacadeChangeActiveattributeDesc(); }
	};
	typedef struct E_FacadeChangeActiveattributeDesc_s E_FacadeChangeActiveattributeDesc_t;

	struct E_FacadeChange_s : public NFDescStoreSeqOP {
		E_FacadeChange_s();
		virtual ~E_FacadeChange_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//外观ID
		int32_t m_type;//大类
		NFShmString<64> m_resource;//资源形象
		NFShmString<64> m_professionID;//职业ID
		NFShmString<64> m_name;//名字
		NFShmString<128> m_activeDesc;//激活描述
		int32_t m_quality;//品质
		int64_t m_activationItem;//激活道具ID
		int32_t m_activationNum;//激活道具数量
		int64_t m_starId;//升星道具id
		NFShmString<256> m_starNum;//升星道具数量
		int32_t m_starUp;//升星等级上限
		int32_t m_starBer;//每次升星属性增加的万分比值
		int64_t m_upAttributeId;//升星属性组ID
		int32_t m_activeSkill;//激活获得技能
		NFShmVector<struct E_FacadeChangeAttributeDesc_s, DEFINE_E_FACADECHANGE_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性
		NFShmVector<struct E_FacadeChangeActiveattributeDesc_s, DEFINE_E_FACADECHANGE_M_ACTIVEATTRIBUTE_MAX_NUM> m_ActiveAttribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_FacadeChange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeChange & msg);
		static ::proto_ff::E_FacadeChange* new_pbmsg(){ return new ::proto_ff::E_FacadeChange(); }
		static ::proto_ff::E_FacadeChange make_pbmsg(){ return ::proto_ff::E_FacadeChange(); }
	};
	typedef struct E_FacadeChange_s E_FacadeChange_t;

	struct Sheet_FacadeChange_s : public NFDescStoreSeqOP {
		Sheet_FacadeChange_s();
		virtual ~Sheet_FacadeChange_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FacadeChange_s, DEFINE_SHEET_FACADECHANGE_E_FACADECHANGE_LIST_MAX_NUM> E_FacadeChange_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FacadeChange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FacadeChange & msg);
		static ::proto_ff::Sheet_FacadeChange* new_pbmsg(){ return new ::proto_ff::Sheet_FacadeChange(); }
		static ::proto_ff::Sheet_FacadeChange make_pbmsg(){ return ::proto_ff::Sheet_FacadeChange(); }
	};
	typedef struct Sheet_FacadeChange_s Sheet_FacadeChange_t;

	struct E_FacadeStarupUpattributeDesc_s : public NFDescStoreSeqOP {
		E_FacadeStarupUpattributeDesc_s();
		virtual ~E_FacadeStarupUpattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_FacadeStarupUpattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeStarupUpattributeDesc & msg);
		static ::proto_ff::E_FacadeStarupUpattributeDesc* new_pbmsg(){ return new ::proto_ff::E_FacadeStarupUpattributeDesc(); }
		static ::proto_ff::E_FacadeStarupUpattributeDesc make_pbmsg(){ return ::proto_ff::E_FacadeStarupUpattributeDesc(); }
	};
	typedef struct E_FacadeStarupUpattributeDesc_s E_FacadeStarupUpattributeDesc_t;

	struct E_FacadeStarup_s : public NFDescStoreSeqOP {
		E_FacadeStarup_s();
		virtual ~E_FacadeStarup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_ID;//唯一ID
		int64_t m_upAttributeId;//升星属性组ID
		int32_t m_starID;//星级
		int32_t m_skillID;//技能id
		NFShmVector<struct E_FacadeStarupUpattributeDesc_s, DEFINE_E_FACADESTARUP_M_UPATTRIBUTE_MAX_NUM> m_upAttribute;//激活属性

		virtual void write_to_pbmsg(::proto_ff::E_FacadeStarup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeStarup & msg);
		static ::proto_ff::E_FacadeStarup* new_pbmsg(){ return new ::proto_ff::E_FacadeStarup(); }
		static ::proto_ff::E_FacadeStarup make_pbmsg(){ return ::proto_ff::E_FacadeStarup(); }
	};
	typedef struct E_FacadeStarup_s E_FacadeStarup_t;

	struct Sheet_FacadeStarup_s : public NFDescStoreSeqOP {
		Sheet_FacadeStarup_s();
		virtual ~Sheet_FacadeStarup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FacadeStarup_s, DEFINE_SHEET_FACADESTARUP_E_FACADESTARUP_LIST_MAX_NUM> E_FacadeStarup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FacadeStarup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FacadeStarup & msg);
		static ::proto_ff::Sheet_FacadeStarup* new_pbmsg(){ return new ::proto_ff::Sheet_FacadeStarup(); }
		static ::proto_ff::Sheet_FacadeStarup make_pbmsg(){ return ::proto_ff::Sheet_FacadeStarup(); }
	};
	typedef struct Sheet_FacadeStarup_s Sheet_FacadeStarup_t;

	struct E_FacadeSoulAttributeDesc_s : public NFDescStoreSeqOP {
		E_FacadeSoulAttributeDesc_s();
		virtual ~E_FacadeSoulAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_FacadeSoulAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeSoulAttributeDesc & msg);
		static ::proto_ff::E_FacadeSoulAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_FacadeSoulAttributeDesc(); }
		static ::proto_ff::E_FacadeSoulAttributeDesc make_pbmsg(){ return ::proto_ff::E_FacadeSoulAttributeDesc(); }
	};
	typedef struct E_FacadeSoulAttributeDesc_s E_FacadeSoulAttributeDesc_t;

	struct E_FacadeSoul_s : public NFDescStoreSeqOP {
		E_FacadeSoul_s();
		virtual ~E_FacadeSoul_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//器魂ID
		int32_t m_rechargeID;//价格计费点
		int32_t m_mainSkill;//主技能ID
		NFShmString<64> m_attributeType;//升级属性类型
		NFShmVector<int32_t, DEFINE_E_FACADESOUL_M_MINORSKILL_MAX_NUM> m_minorSkill;//副技能ID
		NFShmVector<struct E_FacadeSoulAttributeDesc_s, DEFINE_E_FACADESOUL_M_ATTRIBUTE_MAX_NUM> m_attribute;//激活基础属性

		virtual void write_to_pbmsg(::proto_ff::E_FacadeSoul & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeSoul & msg);
		static ::proto_ff::E_FacadeSoul* new_pbmsg(){ return new ::proto_ff::E_FacadeSoul(); }
		static ::proto_ff::E_FacadeSoul make_pbmsg(){ return ::proto_ff::E_FacadeSoul(); }
	};
	typedef struct E_FacadeSoul_s E_FacadeSoul_t;

	struct Sheet_FacadeSoul_s : public NFDescStoreSeqOP {
		Sheet_FacadeSoul_s();
		virtual ~Sheet_FacadeSoul_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FacadeSoul_s, DEFINE_SHEET_FACADESOUL_E_FACADESOUL_LIST_MAX_NUM> E_FacadeSoul_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FacadeSoul & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FacadeSoul & msg);
		static ::proto_ff::Sheet_FacadeSoul* new_pbmsg(){ return new ::proto_ff::Sheet_FacadeSoul(); }
		static ::proto_ff::Sheet_FacadeSoul make_pbmsg(){ return ::proto_ff::Sheet_FacadeSoul(); }
	};
	typedef struct Sheet_FacadeSoul_s Sheet_FacadeSoul_t;

	struct E_FacadeSoulactiveUnlockDesc_s : public NFDescStoreSeqOP {
		E_FacadeSoulactiveUnlockDesc_s();
		virtual ~E_FacadeSoulactiveUnlockDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_parama;//参数
		int32_t m_condition;//条件

		virtual void write_to_pbmsg(::proto_ff::E_FacadeSoulactiveUnlockDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeSoulactiveUnlockDesc & msg);
		static ::proto_ff::E_FacadeSoulactiveUnlockDesc* new_pbmsg(){ return new ::proto_ff::E_FacadeSoulactiveUnlockDesc(); }
		static ::proto_ff::E_FacadeSoulactiveUnlockDesc make_pbmsg(){ return ::proto_ff::E_FacadeSoulactiveUnlockDesc(); }
	};
	typedef struct E_FacadeSoulactiveUnlockDesc_s E_FacadeSoulactiveUnlockDesc_t;

	struct E_FacadeSoulactive_s : public NFDescStoreSeqOP {
		E_FacadeSoulactive_s();
		virtual ~E_FacadeSoulactive_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//技能ID
		NFShmVector<struct E_FacadeSoulactiveUnlockDesc_s, DEFINE_E_FACADESOULACTIVE_M_UNLOCK_MAX_NUM> m_unlock;//解锁

		virtual void write_to_pbmsg(::proto_ff::E_FacadeSoulactive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeSoulactive & msg);
		static ::proto_ff::E_FacadeSoulactive* new_pbmsg(){ return new ::proto_ff::E_FacadeSoulactive(); }
		static ::proto_ff::E_FacadeSoulactive make_pbmsg(){ return ::proto_ff::E_FacadeSoulactive(); }
	};
	typedef struct E_FacadeSoulactive_s E_FacadeSoulactive_t;

	struct Sheet_FacadeSoulactive_s : public NFDescStoreSeqOP {
		Sheet_FacadeSoulactive_s();
		virtual ~Sheet_FacadeSoulactive_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FacadeSoulactive_s, DEFINE_SHEET_FACADESOULACTIVE_E_FACADESOULACTIVE_LIST_MAX_NUM> E_FacadeSoulactive_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FacadeSoulactive & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FacadeSoulactive & msg);
		static ::proto_ff::Sheet_FacadeSoulactive* new_pbmsg(){ return new ::proto_ff::Sheet_FacadeSoulactive(); }
		static ::proto_ff::Sheet_FacadeSoulactive make_pbmsg(){ return ::proto_ff::Sheet_FacadeSoulactive(); }
	};
	typedef struct Sheet_FacadeSoulactive_s Sheet_FacadeSoulactive_t;

	struct E_FacadeSoullvAttributeDesc_s : public NFDescStoreSeqOP {
		E_FacadeSoullvAttributeDesc_s();
		virtual ~E_FacadeSoullvAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_FacadeSoullvAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeSoullvAttributeDesc & msg);
		static ::proto_ff::E_FacadeSoullvAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_FacadeSoullvAttributeDesc(); }
		static ::proto_ff::E_FacadeSoullvAttributeDesc make_pbmsg(){ return ::proto_ff::E_FacadeSoullvAttributeDesc(); }
	};
	typedef struct E_FacadeSoullvAttributeDesc_s E_FacadeSoullvAttributeDesc_t;

	struct E_FacadeSoullv_s : public NFDescStoreSeqOP {
		E_FacadeSoullv_s();
		virtual ~E_FacadeSoullv_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//id
		int32_t m_soullLv;//等级
		int32_t m_soulID;//器魂ID
		int32_t m_itemID;//消耗道具
		int32_t m_num;//消耗数量
		int32_t m_successRate;//升级成功率
		int32_t m_downLv;//是否掉级
		NFShmVector<struct E_FacadeSoullvAttributeDesc_s, DEFINE_E_FACADESOULLV_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_FacadeSoullv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeSoullv & msg);
		static ::proto_ff::E_FacadeSoullv* new_pbmsg(){ return new ::proto_ff::E_FacadeSoullv(); }
		static ::proto_ff::E_FacadeSoullv make_pbmsg(){ return ::proto_ff::E_FacadeSoullv(); }
	};
	typedef struct E_FacadeSoullv_s E_FacadeSoullv_t;

	struct Sheet_FacadeSoullv_s : public NFDescStoreSeqOP {
		Sheet_FacadeSoullv_s();
		virtual ~Sheet_FacadeSoullv_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FacadeSoullv_s, DEFINE_SHEET_FACADESOULLV_E_FACADESOULLV_LIST_MAX_NUM> E_FacadeSoullv_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FacadeSoullv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FacadeSoullv & msg);
		static ::proto_ff::Sheet_FacadeSoullv* new_pbmsg(){ return new ::proto_ff::Sheet_FacadeSoullv(); }
		static ::proto_ff::Sheet_FacadeSoullv make_pbmsg(){ return ::proto_ff::Sheet_FacadeSoullv(); }
	};
	typedef struct Sheet_FacadeSoullv_s Sheet_FacadeSoullv_t;

	struct E_FacadeSoulachievement_s : public NFDescStoreSeqOP {
		E_FacadeSoulachievement_s();
		virtual ~E_FacadeSoulachievement_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//成就id
		int32_t m_soulID;//器魂ID
		int32_t m_type;//类型
		int32_t m_parama;//影响值
		int32_t m_itemID;//奖励道具
		int32_t m_num;//奖励数量

		virtual void write_to_pbmsg(::proto_ff::E_FacadeSoulachievement & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeSoulachievement & msg);
		static ::proto_ff::E_FacadeSoulachievement* new_pbmsg(){ return new ::proto_ff::E_FacadeSoulachievement(); }
		static ::proto_ff::E_FacadeSoulachievement make_pbmsg(){ return ::proto_ff::E_FacadeSoulachievement(); }
	};
	typedef struct E_FacadeSoulachievement_s E_FacadeSoulachievement_t;

	struct Sheet_FacadeSoulachievement_s : public NFDescStoreSeqOP {
		Sheet_FacadeSoulachievement_s();
		virtual ~Sheet_FacadeSoulachievement_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FacadeSoulachievement_s, DEFINE_SHEET_FACADESOULACHIEVEMENT_E_FACADESOULACHIEVEMENT_LIST_MAX_NUM> E_FacadeSoulachievement_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FacadeSoulachievement & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FacadeSoulachievement & msg);
		static ::proto_ff::Sheet_FacadeSoulachievement* new_pbmsg(){ return new ::proto_ff::Sheet_FacadeSoulachievement(); }
		static ::proto_ff::Sheet_FacadeSoulachievement make_pbmsg(){ return ::proto_ff::Sheet_FacadeSoulachievement(); }
	};
	typedef struct Sheet_FacadeSoulachievement_s Sheet_FacadeSoulachievement_t;

}

