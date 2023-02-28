#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "pet.pb.h"
#include "pet_s.h"

namespace proto_ff_s {

	struct E_PetDisplayMaterialDesc_s : public NFDescStoreSeqOP {
		E_PetDisplayMaterialDesc_s();
		virtual ~E_PetDisplayMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_exp;

		virtual void write_to_pbmsg(::proto_ff::E_PetDisplayMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetDisplayMaterialDesc & msg);
		static ::proto_ff::E_PetDisplayMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_PetDisplayMaterialDesc(); }
		static ::proto_ff::E_PetDisplayMaterialDesc make_pbmsg(){ return ::proto_ff::E_PetDisplayMaterialDesc(); }
	};
	typedef struct E_PetDisplayMaterialDesc_s E_PetDisplayMaterialDesc_t;

	struct E_PetDisplay_s : public NFDescStoreSeqOP {
		E_PetDisplay_s();
		virtual ~E_PetDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_quality;
		int32_t m_isstar;
		NFShmString<60> m_grade;
		int64_t m_monsterid;
		NFShmString<60> m_name;
		int32_t m_activeskillid;
		NFShmString<60> m_exclusiveskillid;
		NFShmString<60> m_passiveskillid;
		int32_t m_activeattribute;
		int32_t m_growatt;
		float m_activeparama;
		float m_growattparama;
		float m_growstandarda;
		float m_growstandardb;
		float m_growstandard;
		float m_growmin;
		float m_growmax;
		float m_growstar;
		int32_t m_advanceattribute;
		int32_t m_advancetype;
		NFShmString<60> m_pettagskill;
		int32_t m_starattribute;
		int32_t m_starpercent;
		int32_t m_starllimit;
		int64_t m_staritem;
		NFShmString<300> m_starnum;
		int64_t m_starpetid;
		NFShmString<300> m_starpetnum;
		int32_t m_weapon;
		int64_t m_upattributeid;
		int32_t m_fettersid;
		NFShmVector<struct E_PetDisplayMaterialDesc_s, 3> m_material;

		virtual void write_to_pbmsg(::proto_ff::E_PetDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetDisplay & msg);
		static ::proto_ff::E_PetDisplay* new_pbmsg(){ return new ::proto_ff::E_PetDisplay(); }
		static ::proto_ff::E_PetDisplay make_pbmsg(){ return ::proto_ff::E_PetDisplay(); }
	};
	typedef struct E_PetDisplay_s E_PetDisplay_t;

	struct Sheet_PetDisplay_s : public NFDescStoreSeqOP {
		Sheet_PetDisplay_s();
		virtual ~Sheet_PetDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetDisplay_s, 20> E_PetDisplay_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetDisplay & msg);
		static ::proto_ff::Sheet_PetDisplay* new_pbmsg(){ return new ::proto_ff::Sheet_PetDisplay(); }
		static ::proto_ff::Sheet_PetDisplay make_pbmsg(){ return ::proto_ff::Sheet_PetDisplay(); }
	};
	typedef struct Sheet_PetDisplay_s Sheet_PetDisplay_t;

	struct E_PetAttributetpyeAttributeDesc_s : public NFDescStoreSeqOP {
		E_PetAttributetpyeAttributeDesc_s();
		virtual ~E_PetAttributetpyeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_PetAttributetpyeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetAttributetpyeAttributeDesc & msg);
		static ::proto_ff::E_PetAttributetpyeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_PetAttributetpyeAttributeDesc(); }
		static ::proto_ff::E_PetAttributetpyeAttributeDesc make_pbmsg(){ return ::proto_ff::E_PetAttributetpyeAttributeDesc(); }
	};
	typedef struct E_PetAttributetpyeAttributeDesc_s E_PetAttributetpyeAttributeDesc_t;

	struct E_PetAttributetpye_s : public NFDescStoreSeqOP {
		E_PetAttributetpye_s();
		virtual ~E_PetAttributetpye_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_tpye;
		NFShmVector<struct E_PetAttributetpyeAttributeDesc_s, 6> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_PetAttributetpye & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetAttributetpye & msg);
		static ::proto_ff::E_PetAttributetpye* new_pbmsg(){ return new ::proto_ff::E_PetAttributetpye(); }
		static ::proto_ff::E_PetAttributetpye make_pbmsg(){ return ::proto_ff::E_PetAttributetpye(); }
	};
	typedef struct E_PetAttributetpye_s E_PetAttributetpye_t;

	struct Sheet_PetAttributetpye_s : public NFDescStoreSeqOP {
		Sheet_PetAttributetpye_s();
		virtual ~Sheet_PetAttributetpye_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetAttributetpye_s, 40> E_PetAttributetpye_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetAttributetpye & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetAttributetpye & msg);
		static ::proto_ff::Sheet_PetAttributetpye* new_pbmsg(){ return new ::proto_ff::Sheet_PetAttributetpye(); }
		static ::proto_ff::Sheet_PetAttributetpye make_pbmsg(){ return ::proto_ff::Sheet_PetAttributetpye(); }
	};
	typedef struct Sheet_PetAttributetpye_s Sheet_PetAttributetpye_t;

	struct E_PetLvexp_s : public NFDescStoreSeqOP {
		E_PetLvexp_s();
		virtual ~E_PetLvexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int64_t m_exp;

		virtual void write_to_pbmsg(::proto_ff::E_PetLvexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetLvexp & msg);
		static ::proto_ff::E_PetLvexp* new_pbmsg(){ return new ::proto_ff::E_PetLvexp(); }
		static ::proto_ff::E_PetLvexp make_pbmsg(){ return ::proto_ff::E_PetLvexp(); }
	};
	typedef struct E_PetLvexp_s E_PetLvexp_t;

	struct Sheet_PetLvexp_s : public NFDescStoreSeqOP {
		Sheet_PetLvexp_s();
		virtual ~Sheet_PetLvexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetLvexp_s, 500> E_PetLvexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetLvexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetLvexp & msg);
		static ::proto_ff::Sheet_PetLvexp* new_pbmsg(){ return new ::proto_ff::Sheet_PetLvexp(); }
		static ::proto_ff::Sheet_PetLvexp make_pbmsg(){ return ::proto_ff::Sheet_PetLvexp(); }
	};
	typedef struct Sheet_PetLvexp_s Sheet_PetLvexp_t;

	struct E_PetAdvancelvAdvanceDesc_s : public NFDescStoreSeqOP {
		E_PetAdvancelvAdvanceDesc_s();
		virtual ~E_PetAdvancelvAdvanceDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		float m_param;

		virtual void write_to_pbmsg(::proto_ff::E_PetAdvancelvAdvanceDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetAdvancelvAdvanceDesc & msg);
		static ::proto_ff::E_PetAdvancelvAdvanceDesc* new_pbmsg(){ return new ::proto_ff::E_PetAdvancelvAdvanceDesc(); }
		static ::proto_ff::E_PetAdvancelvAdvanceDesc make_pbmsg(){ return ::proto_ff::E_PetAdvancelvAdvanceDesc(); }
	};
	typedef struct E_PetAdvancelvAdvanceDesc_s E_PetAdvancelvAdvanceDesc_t;

	struct E_PetAdvancelv_s : public NFDescStoreSeqOP {
		E_PetAdvancelv_s();
		virtual ~E_PetAdvancelv_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_advanceitem;
		int32_t m_advancenum;
		NFShmVector<struct E_PetAdvancelvAdvanceDesc_s, 2> m_advance;

		virtual void write_to_pbmsg(::proto_ff::E_PetAdvancelv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetAdvancelv & msg);
		static ::proto_ff::E_PetAdvancelv* new_pbmsg(){ return new ::proto_ff::E_PetAdvancelv(); }
		static ::proto_ff::E_PetAdvancelv make_pbmsg(){ return ::proto_ff::E_PetAdvancelv(); }
	};
	typedef struct E_PetAdvancelv_s E_PetAdvancelv_t;

	struct Sheet_PetAdvancelv_s : public NFDescStoreSeqOP {
		Sheet_PetAdvancelv_s();
		virtual ~Sheet_PetAdvancelv_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetAdvancelv_s, 200> E_PetAdvancelv_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetAdvancelv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetAdvancelv & msg);
		static ::proto_ff::Sheet_PetAdvancelv* new_pbmsg(){ return new ::proto_ff::Sheet_PetAdvancelv(); }
		static ::proto_ff::Sheet_PetAdvancelv make_pbmsg(){ return ::proto_ff::Sheet_PetAdvancelv(); }
	};
	typedef struct Sheet_PetAdvancelv_s Sheet_PetAdvancelv_t;

	struct E_PetStarupUpattributeDesc_s : public NFDescStoreSeqOP {
		E_PetStarupUpattributeDesc_s();
		virtual ~E_PetStarupUpattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_PetStarupUpattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetStarupUpattributeDesc & msg);
		static ::proto_ff::E_PetStarupUpattributeDesc* new_pbmsg(){ return new ::proto_ff::E_PetStarupUpattributeDesc(); }
		static ::proto_ff::E_PetStarupUpattributeDesc make_pbmsg(){ return ::proto_ff::E_PetStarupUpattributeDesc(); }
	};
	typedef struct E_PetStarupUpattributeDesc_s E_PetStarupUpattributeDesc_t;

	struct E_PetStarup_s : public NFDescStoreSeqOP {
		E_PetStarup_s();
		virtual ~E_PetStarup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int64_t m_upattributeid;
		int32_t m_starid;
		int32_t m_skillid;
		int32_t m_activeskillidlv;
		NFShmVector<struct E_PetStarupUpattributeDesc_s, 6> m_upattribute;

		virtual void write_to_pbmsg(::proto_ff::E_PetStarup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetStarup & msg);
		static ::proto_ff::E_PetStarup* new_pbmsg(){ return new ::proto_ff::E_PetStarup(); }
		static ::proto_ff::E_PetStarup make_pbmsg(){ return ::proto_ff::E_PetStarup(); }
	};
	typedef struct E_PetStarup_s E_PetStarup_t;

	struct Sheet_PetStarup_s : public NFDescStoreSeqOP {
		Sheet_PetStarup_s();
		virtual ~Sheet_PetStarup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetStarup_s, 40> E_PetStarup_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetStarup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetStarup & msg);
		static ::proto_ff::Sheet_PetStarup* new_pbmsg(){ return new ::proto_ff::Sheet_PetStarup(); }
		static ::proto_ff::Sheet_PetStarup make_pbmsg(){ return ::proto_ff::Sheet_PetStarup(); }
	};
	typedef struct Sheet_PetStarup_s Sheet_PetStarup_t;

	struct E_PetEggPetDesc_s : public NFDescStoreSeqOP {
		E_PetEggPetDesc_s();
		virtual ~E_PetEggPetDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_rand;
		int32_t m_id;

		virtual void write_to_pbmsg(::proto_ff::E_PetEggPetDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetEggPetDesc & msg);
		static ::proto_ff::E_PetEggPetDesc* new_pbmsg(){ return new ::proto_ff::E_PetEggPetDesc(); }
		static ::proto_ff::E_PetEggPetDesc make_pbmsg(){ return ::proto_ff::E_PetEggPetDesc(); }
	};
	typedef struct E_PetEggPetDesc_s E_PetEggPetDesc_t;

	struct E_PetEgg_s : public NFDescStoreSeqOP {
		E_PetEgg_s();
		virtual ~E_PetEgg_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_time;
		NFShmVector<struct E_PetEggPetDesc_s, 10> m_pet;

		virtual void write_to_pbmsg(::proto_ff::E_PetEgg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetEgg & msg);
		static ::proto_ff::E_PetEgg* new_pbmsg(){ return new ::proto_ff::E_PetEgg(); }
		static ::proto_ff::E_PetEgg make_pbmsg(){ return ::proto_ff::E_PetEgg(); }
	};
	typedef struct E_PetEgg_s E_PetEgg_t;

	struct Sheet_PetEgg_s : public NFDescStoreSeqOP {
		Sheet_PetEgg_s();
		virtual ~Sheet_PetEgg_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetEgg_s, 20> E_PetEgg_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetEgg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetEgg & msg);
		static ::proto_ff::Sheet_PetEgg* new_pbmsg(){ return new ::proto_ff::Sheet_PetEgg(); }
		static ::proto_ff::Sheet_PetEgg make_pbmsg(){ return ::proto_ff::Sheet_PetEgg(); }
	};
	typedef struct Sheet_PetEgg_s Sheet_PetEgg_t;

	struct E_PetDecomposeDecomposeDesc_s : public NFDescStoreSeqOP {
		E_PetDecomposeDecomposeDesc_s();
		virtual ~E_PetDecomposeDecomposeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_boxid;
		int32_t m_type;

		virtual void write_to_pbmsg(::proto_ff::E_PetDecomposeDecomposeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetDecomposeDecomposeDesc & msg);
		static ::proto_ff::E_PetDecomposeDecomposeDesc* new_pbmsg(){ return new ::proto_ff::E_PetDecomposeDecomposeDesc(); }
		static ::proto_ff::E_PetDecomposeDecomposeDesc make_pbmsg(){ return ::proto_ff::E_PetDecomposeDecomposeDesc(); }
	};
	typedef struct E_PetDecomposeDecomposeDesc_s E_PetDecomposeDecomposeDesc_t;

	struct E_PetDecompose_s : public NFDescStoreSeqOP {
		E_PetDecompose_s();
		virtual ~E_PetDecompose_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_quality;
		NFShmVector<struct E_PetDecomposeDecomposeDesc_s, 4> m_decompose;

		virtual void write_to_pbmsg(::proto_ff::E_PetDecompose & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetDecompose & msg);
		static ::proto_ff::E_PetDecompose* new_pbmsg(){ return new ::proto_ff::E_PetDecompose(); }
		static ::proto_ff::E_PetDecompose make_pbmsg(){ return ::proto_ff::E_PetDecompose(); }
	};
	typedef struct E_PetDecompose_s E_PetDecompose_t;

	struct Sheet_PetDecompose_s : public NFDescStoreSeqOP {
		Sheet_PetDecompose_s();
		virtual ~Sheet_PetDecompose_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetDecompose_s, 20> E_PetDecompose_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetDecompose & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetDecompose & msg);
		static ::proto_ff::Sheet_PetDecompose* new_pbmsg(){ return new ::proto_ff::Sheet_PetDecompose(); }
		static ::proto_ff::Sheet_PetDecompose make_pbmsg(){ return ::proto_ff::Sheet_PetDecompose(); }
	};
	typedef struct Sheet_PetDecompose_s Sheet_PetDecompose_t;

	struct E_PetFettersAttributeDesc_s : public NFDescStoreSeqOP {
		E_PetFettersAttributeDesc_s();
		virtual ~E_PetFettersAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_PetFettersAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetFettersAttributeDesc & msg);
		static ::proto_ff::E_PetFettersAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_PetFettersAttributeDesc(); }
		static ::proto_ff::E_PetFettersAttributeDesc make_pbmsg(){ return ::proto_ff::E_PetFettersAttributeDesc(); }
	};
	typedef struct E_PetFettersAttributeDesc_s E_PetFettersAttributeDesc_t;

	struct E_PetFetters_s : public NFDescStoreSeqOP {
		E_PetFetters_s();
		virtual ~E_PetFetters_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_quality;
		NFShmVector<int32_t, 3> m_petid;
		NFShmVector<int32_t, 4> m_atctive_skillid;
		NFShmVector<struct E_PetFettersAttributeDesc_s, 6> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_PetFetters & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PetFetters & msg);
		static ::proto_ff::E_PetFetters* new_pbmsg(){ return new ::proto_ff::E_PetFetters(); }
		static ::proto_ff::E_PetFetters make_pbmsg(){ return ::proto_ff::E_PetFetters(); }
	};
	typedef struct E_PetFetters_s E_PetFetters_t;

	struct Sheet_PetFetters_s : public NFDescStoreSeqOP {
		Sheet_PetFetters_s();
		virtual ~Sheet_PetFetters_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PetFetters_s, 20> E_PetFetters_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_PetFetters & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PetFetters & msg);
		static ::proto_ff::Sheet_PetFetters* new_pbmsg(){ return new ::proto_ff::Sheet_PetFetters(); }
		static ::proto_ff::Sheet_PetFetters make_pbmsg(){ return ::proto_ff::Sheet_PetFetters(); }
	};
	typedef struct Sheet_PetFetters_s Sheet_PetFetters_t;

}

