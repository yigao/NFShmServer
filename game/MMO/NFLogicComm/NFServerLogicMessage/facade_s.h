#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "facade.pb.h"
#include "facade_s.h"

#define DEFINE_E_FACADEDISPLAY_M_MATERIAL_MAX_NUM 3
#define DEFINE_E_FACADEDISPLAY_M_FRAGMENTID_MAX_NUM 3
#define DEFINE_SHEET_FACADEDISPLAY_E_FACADEDISPLAY_LIST_MAX_NUM 20
#define DEFINE_E_FACADEVALUE_M_TREASUREATTRIBUTE_MAX_NUM 5
#define DEFINE_E_FACADEVALUE_M_ARTIFACTATTRIBUTE_MAX_NUM 6
#define DEFINE_E_FACADEVALUE_M_BLADEATTRIBUTE_MAX_NUM 6
#define DEFINE_E_FACADEVALUE_M_WINGATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_FACADEVALUE_E_FACADEVALUE_LIST_MAX_NUM 500
#define DEFINE_SHEET_FACADETYPE_E_FACADETYPE_LIST_MAX_NUM 20
#define DEFINE_E_FACADEFRAGMENT_M_ATTRIBUTE_MAX_NUM 3
#define DEFINE_SHEET_FACADEFRAGMENT_E_FACADEFRAGMENT_LIST_MAX_NUM 20
#define DEFINE_E_FACADECHANGE_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_E_FACADECHANGE_M_ACTIVEATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_FACADECHANGE_E_FACADECHANGE_LIST_MAX_NUM 60
#define DEFINE_E_FACADESTARUP_M_UPATTRIBUTE_MAX_NUM 3
#define DEFINE_SHEET_FACADESTARUP_E_FACADESTARUP_LIST_MAX_NUM 40
#define DEFINE_E_FACADESOUL_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_E_FACADESOUL_M_MINORSKILL_MAX_NUM 8
#define DEFINE_SHEET_FACADESOUL_E_FACADESOUL_LIST_MAX_NUM 20
#define DEFINE_E_FACADESOULACTIVE_M_UNLOCK_MAX_NUM 2
#define DEFINE_SHEET_FACADESOULACTIVE_E_FACADESOULACTIVE_LIST_MAX_NUM 40
#define DEFINE_E_FACADESOULLV_M_ATTRIBUTE_MAX_NUM 7
#define DEFINE_SHEET_FACADESOULLV_E_FACADESOULLV_LIST_MAX_NUM 140
#define DEFINE_SHEET_FACADESOULACHIEVEMENT_E_FACADESOULACHIEVEMENT_LIST_MAX_NUM 160
namespace proto_ff_s {

	struct E_FacadeDisplayMaterialDesc_s : public NFDescStoreSeqOP {
		E_FacadeDisplayMaterialDesc_s();
		virtual ~E_FacadeDisplayMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_exp;

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
		int64_t m_id;
		int32_t m_type;
		NFShmString<60> m_resource;
		NFShmString<60> m_name;
		NFShmString<100> m_activedesc;
		NFShmString<60> m_professionid;
		NFShmString<80> m_skillid;
		int32_t m_souliid;
		NFShmVector<struct E_FacadeDisplayMaterialDesc_s, DEFINE_E_FACADEDISPLAY_M_MATERIAL_MAX_NUM> m_material;
		NFShmVector<int64_t, DEFINE_E_FACADEDISPLAY_M_FRAGMENTID_MAX_NUM> m_fragmentid;

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
		NFShmVector<struct E_FacadeDisplay_s, DEFINE_SHEET_FACADEDISPLAY_E_FACADEDISPLAY_LIST_MAX_NUM> E_FacadeDisplay_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_FacadeDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FacadeDisplay & msg);
		static ::proto_ff::Sheet_FacadeDisplay* new_pbmsg(){ return new ::proto_ff::Sheet_FacadeDisplay(); }
		static ::proto_ff::Sheet_FacadeDisplay make_pbmsg(){ return ::proto_ff::Sheet_FacadeDisplay(); }
	};
	typedef struct Sheet_FacadeDisplay_s Sheet_FacadeDisplay_t;

	struct E_FacadeValueTreasureattributeDesc_s : public NFDescStoreSeqOP {
		E_FacadeValueTreasureattributeDesc_s();
		virtual ~E_FacadeValueTreasureattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

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
		int32_t m_type;
		int32_t m_value;

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
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_FacadeValueBladeattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeValueBladeattributeDesc & msg);
		static ::proto_ff::E_FacadeValueBladeattributeDesc* new_pbmsg(){ return new ::proto_ff::E_FacadeValueBladeattributeDesc(); }
		static ::proto_ff::E_FacadeValueBladeattributeDesc make_pbmsg(){ return ::proto_ff::E_FacadeValueBladeattributeDesc(); }
	};
	typedef struct E_FacadeValueBladeattributeDesc_s E_FacadeValueBladeattributeDesc_t;

	struct E_FacadeValueWingattributeDesc_s : public NFDescStoreSeqOP {
		E_FacadeValueWingattributeDesc_s();
		virtual ~E_FacadeValueWingattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_FacadeValueWingattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FacadeValueWingattributeDesc & msg);
		static ::proto_ff::E_FacadeValueWingattributeDesc* new_pbmsg(){ return new ::proto_ff::E_FacadeValueWingattributeDesc(); }
		static ::proto_ff::E_FacadeValueWingattributeDesc make_pbmsg(){ return ::proto_ff::E_FacadeValueWingattributeDesc(); }
	};
	typedef struct E_FacadeValueWingattributeDesc_s E_FacadeValueWingattributeDesc_t;

	struct E_FacadeValue_s : public NFDescStoreSeqOP {
		E_FacadeValue_s();
		virtual ~E_FacadeValue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;
		int64_t m_wingexp;
		int64_t m_treasureexp;
		int64_t m_artifactexp;
		int64_t m_bladeexp;
		NFShmVector<struct E_FacadeValueTreasureattributeDesc_s, DEFINE_E_FACADEVALUE_M_TREASUREATTRIBUTE_MAX_NUM> m_treasureattribute;
		NFShmVector<struct E_FacadeValueArtifactattributeDesc_s, DEFINE_E_FACADEVALUE_M_ARTIFACTATTRIBUTE_MAX_NUM> m_artifactattribute;
		NFShmVector<struct E_FacadeValueBladeattributeDesc_s, DEFINE_E_FACADEVALUE_M_BLADEATTRIBUTE_MAX_NUM> m_bladeattribute;
		NFShmVector<struct E_FacadeValueWingattributeDesc_s, DEFINE_E_FACADEVALUE_M_WINGATTRIBUTE_MAX_NUM> m_wingattribute;

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
		NFShmVector<struct E_FacadeValue_s, DEFINE_SHEET_FACADEVALUE_E_FACADEVALUE_LIST_MAX_NUM> E_FacadeValue_List;

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
		int32_t m_id;
		NFShmString<60> m_soucename;

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
		NFShmVector<struct E_FacadeType_s, DEFINE_SHEET_FACADETYPE_E_FACADETYPE_LIST_MAX_NUM> E_FacadeType_List;

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
		int32_t m_type;
		int32_t m_value;

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
		int64_t m_fragmentid;
		int64_t m_item;
		int32_t m_itemnum;
		NFShmVector<struct E_FacadeFragmentAttributeDesc_s, DEFINE_E_FACADEFRAGMENT_M_ATTRIBUTE_MAX_NUM> m_attribute;

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
		NFShmVector<struct E_FacadeFragment_s, DEFINE_SHEET_FACADEFRAGMENT_E_FACADEFRAGMENT_LIST_MAX_NUM> E_FacadeFragment_List;

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
		int32_t m_type;
		int32_t m_value;

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
		int32_t m_type;
		int32_t m_value;

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
		int64_t m_id;
		int32_t m_type;
		NFShmString<60> m_resource;
		NFShmString<60> m_professionid;
		NFShmString<60> m_name;
		NFShmString<160> m_activedesc;
		int32_t m_quality;
		int64_t m_activationitem;
		int32_t m_activationnum;
		int64_t m_starid;
		NFShmString<300> m_starnum;
		int32_t m_starup;
		int32_t m_starber;
		int64_t m_upattributeid;
		int32_t m_activeskill;
		NFShmVector<struct E_FacadeChangeAttributeDesc_s, DEFINE_E_FACADECHANGE_M_ATTRIBUTE_MAX_NUM> m_attribute;
		NFShmVector<struct E_FacadeChangeActiveattributeDesc_s, DEFINE_E_FACADECHANGE_M_ACTIVEATTRIBUTE_MAX_NUM> m_activeattribute;

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
		NFShmVector<struct E_FacadeChange_s, DEFINE_SHEET_FACADECHANGE_E_FACADECHANGE_LIST_MAX_NUM> E_FacadeChange_List;

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
		int32_t m_type;
		int32_t m_value;

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
		int32_t m_id;
		int64_t m_upattributeid;
		int32_t m_starid;
		int32_t m_skillid;
		NFShmVector<struct E_FacadeStarupUpattributeDesc_s, DEFINE_E_FACADESTARUP_M_UPATTRIBUTE_MAX_NUM> m_upattribute;

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
		NFShmVector<struct E_FacadeStarup_s, DEFINE_SHEET_FACADESTARUP_E_FACADESTARUP_LIST_MAX_NUM> E_FacadeStarup_List;

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
		int32_t m_type;
		int32_t m_value;

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
		int64_t m_id;
		int32_t m_rechargeid;
		int32_t m_mainskill;
		NFShmString<60> m_attributetype;
		NFShmVector<struct E_FacadeSoulAttributeDesc_s, DEFINE_E_FACADESOUL_M_ATTRIBUTE_MAX_NUM> m_attribute;
		NFShmVector<int32_t, DEFINE_E_FACADESOUL_M_MINORSKILL_MAX_NUM> m_minorskill;

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
		NFShmVector<struct E_FacadeSoul_s, DEFINE_SHEET_FACADESOUL_E_FACADESOUL_LIST_MAX_NUM> E_FacadeSoul_List;

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
		NFShmString<60> m_parama;
		int32_t m_condition;

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
		int64_t m_id;
		NFShmVector<struct E_FacadeSoulactiveUnlockDesc_s, DEFINE_E_FACADESOULACTIVE_M_UNLOCK_MAX_NUM> m_unlock;

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
		NFShmVector<struct E_FacadeSoulactive_s, DEFINE_SHEET_FACADESOULACTIVE_E_FACADESOULACTIVE_LIST_MAX_NUM> E_FacadeSoulactive_List;

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
		int32_t m_type;
		int32_t m_value;

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
		int64_t m_id;
		int32_t m_soulllv;
		int32_t m_soulid;
		int32_t m_itemid;
		int32_t m_num;
		int32_t m_successrate;
		int32_t m_downlv;
		NFShmVector<struct E_FacadeSoullvAttributeDesc_s, DEFINE_E_FACADESOULLV_M_ATTRIBUTE_MAX_NUM> m_attribute;

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
		NFShmVector<struct E_FacadeSoullv_s, DEFINE_SHEET_FACADESOULLV_E_FACADESOULLV_LIST_MAX_NUM> E_FacadeSoullv_List;

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
		int64_t m_id;
		int32_t m_soulid;
		int32_t m_type;
		int32_t m_parama;
		int32_t m_itemid;
		int32_t m_num;

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
		NFShmVector<struct E_FacadeSoulachievement_s, DEFINE_SHEET_FACADESOULACHIEVEMENT_E_FACADESOULACHIEVEMENT_LIST_MAX_NUM> E_FacadeSoulachievement_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_FacadeSoulachievement & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FacadeSoulachievement & msg);
		static ::proto_ff::Sheet_FacadeSoulachievement* new_pbmsg(){ return new ::proto_ff::Sheet_FacadeSoulachievement(); }
		static ::proto_ff::Sheet_FacadeSoulachievement make_pbmsg(){ return ::proto_ff::Sheet_FacadeSoulachievement(); }
	};
	typedef struct Sheet_FacadeSoulachievement_s Sheet_FacadeSoulachievement_t;

}

