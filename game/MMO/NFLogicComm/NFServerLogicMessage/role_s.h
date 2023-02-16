#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "role.pb.h"
#include "role_s.h"

namespace proto_ff_s {

	struct E_RoleBornItemDesc_s : public NFDescStoreSeqOP {
		E_RoleBornItemDesc_s();
		virtual ~E_RoleBornItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;
		int64_t m_name;

		virtual void write_to_pbmsg(::proto_ff::E_RoleBornItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleBornItemDesc & msg);
		static ::proto_ff::E_RoleBornItemDesc* new_pbmsg(){ return new ::proto_ff::E_RoleBornItemDesc(); }
		static ::proto_ff::E_RoleBornItemDesc make_pbmsg(){ return ::proto_ff::E_RoleBornItemDesc(); }
	};
	typedef struct E_RoleBornItemDesc_s E_RoleBornItemDesc_t;

	struct E_RoleBornMailDesc_s : public NFDescStoreSeqOP {
		E_RoleBornMailDesc_s();
		virtual ~E_RoleBornMailDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;
		int64_t m_name;

		virtual void write_to_pbmsg(::proto_ff::E_RoleBornMailDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleBornMailDesc & msg);
		static ::proto_ff::E_RoleBornMailDesc* new_pbmsg(){ return new ::proto_ff::E_RoleBornMailDesc(); }
		static ::proto_ff::E_RoleBornMailDesc make_pbmsg(){ return ::proto_ff::E_RoleBornMailDesc(); }
	};
	typedef struct E_RoleBornMailDesc_s E_RoleBornMailDesc_t;

	struct E_RoleBorn_s : public NFDescStoreSeqOP {
		E_RoleBorn_s();
		virtual ~E_RoleBorn_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_bornid;
		int32_t m_professionid;
		NFShmString<60> m_professionname;
		NFShmString<60> m_placement;
		int32_t m_gender;
		int32_t m_bornlevel;
		int32_t m_borntitle;
		int64_t m_diamond;
		int64_t m_binddiamond;
		int64_t m_gold;
		int64_t m_mapid;
		int32_t m_birthface;
		NFShmString<60> m_icons;
		NFShmString<60> m_loginavata;
		NFShmString<60> m_newweapon;
		NFShmString<60> m_newclothing;
		NFShmString<60> m_weaponavata;
		NFShmString<60> m_roleavata;
		int32_t m_haircolor;
		int32_t m_clothescolor;
		int32_t m_skincolor;
		int64_t m_carryweapons;
		int64_t m_carryarmor;
		int64_t m_carrycloak;
		int64_t m_carryshoes;
		int64_t m_carrynecklace;
		int64_t m_carryamulet;
		int64_t m_carrybracer;
		int64_t m_carryring;
		int64_t m_carryfashionweapons;
		int64_t m_carryfashionarmor;
		int64_t m_carrywings;
		int32_t m_mspeed;
		int32_t m_view;
		int32_t m_radius;
		int32_t m_group;
		int64_t m_sheny;
		int64_t m_shenw;
		NFShmVector<int32_t, 4> m_actbuff;
		NFShmVector<struct E_RoleBornItemDesc_s, 35> m_item;
		NFShmVector<int64_t, 12> m_actskill;
		NFShmVector<struct E_RoleBornMailDesc_s, 1> m_mail;

		virtual void write_to_pbmsg(::proto_ff::E_RoleBorn & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleBorn & msg);
		static ::proto_ff::E_RoleBorn* new_pbmsg(){ return new ::proto_ff::E_RoleBorn(); }
		static ::proto_ff::E_RoleBorn make_pbmsg(){ return ::proto_ff::E_RoleBorn(); }
	};
	typedef struct E_RoleBorn_s E_RoleBorn_t;

	struct Sheet_RoleBorn_s : public NFDescStoreSeqOP {
		Sheet_RoleBorn_s();
		virtual ~Sheet_RoleBorn_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RoleBorn_s, 20> E_RoleBorn_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RoleBorn & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RoleBorn & msg);
		static ::proto_ff::Sheet_RoleBorn* new_pbmsg(){ return new ::proto_ff::Sheet_RoleBorn(); }
		static ::proto_ff::Sheet_RoleBorn make_pbmsg(){ return ::proto_ff::Sheet_RoleBorn(); }
	};
	typedef struct Sheet_RoleBorn_s Sheet_RoleBorn_t;

	struct E_RoleMastermaleAttributeDesc_s : public NFDescStoreSeqOP {
		E_RoleMastermaleAttributeDesc_s();
		virtual ~E_RoleMastermaleAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_RoleMastermaleAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleMastermaleAttributeDesc & msg);
		static ::proto_ff::E_RoleMastermaleAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_RoleMastermaleAttributeDesc(); }
		static ::proto_ff::E_RoleMastermaleAttributeDesc make_pbmsg(){ return ::proto_ff::E_RoleMastermaleAttributeDesc(); }
	};
	typedef struct E_RoleMastermaleAttributeDesc_s E_RoleMastermaleAttributeDesc_t;

	struct E_RoleMastermale_s : public NFDescStoreSeqOP {
		E_RoleMastermale_s();
		virtual ~E_RoleMastermale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;
		int32_t m_upgradepoint;
		NFShmVector<struct E_RoleMastermaleAttributeDesc_s, 70> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_RoleMastermale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleMastermale & msg);
		static ::proto_ff::E_RoleMastermale* new_pbmsg(){ return new ::proto_ff::E_RoleMastermale(); }
		static ::proto_ff::E_RoleMastermale make_pbmsg(){ return ::proto_ff::E_RoleMastermale(); }
	};
	typedef struct E_RoleMastermale_s E_RoleMastermale_t;

	struct Sheet_RoleMastermale_s : public NFDescStoreSeqOP {
		Sheet_RoleMastermale_s();
		virtual ~Sheet_RoleMastermale_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RoleMastermale_s, 2000> E_RoleMastermale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RoleMastermale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RoleMastermale & msg);
		static ::proto_ff::Sheet_RoleMastermale* new_pbmsg(){ return new ::proto_ff::Sheet_RoleMastermale(); }
		static ::proto_ff::Sheet_RoleMastermale make_pbmsg(){ return ::proto_ff::Sheet_RoleMastermale(); }
	};
	typedef struct Sheet_RoleMastermale_s Sheet_RoleMastermale_t;

	struct E_RoleMasterfemaleAttributeDesc_s : public NFDescStoreSeqOP {
		E_RoleMasterfemaleAttributeDesc_s();
		virtual ~E_RoleMasterfemaleAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_RoleMasterfemaleAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleMasterfemaleAttributeDesc & msg);
		static ::proto_ff::E_RoleMasterfemaleAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_RoleMasterfemaleAttributeDesc(); }
		static ::proto_ff::E_RoleMasterfemaleAttributeDesc make_pbmsg(){ return ::proto_ff::E_RoleMasterfemaleAttributeDesc(); }
	};
	typedef struct E_RoleMasterfemaleAttributeDesc_s E_RoleMasterfemaleAttributeDesc_t;

	struct E_RoleMasterfemale_s : public NFDescStoreSeqOP {
		E_RoleMasterfemale_s();
		virtual ~E_RoleMasterfemale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;
		int32_t m_upgradepoint;
		NFShmVector<struct E_RoleMasterfemaleAttributeDesc_s, 70> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_RoleMasterfemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleMasterfemale & msg);
		static ::proto_ff::E_RoleMasterfemale* new_pbmsg(){ return new ::proto_ff::E_RoleMasterfemale(); }
		static ::proto_ff::E_RoleMasterfemale make_pbmsg(){ return ::proto_ff::E_RoleMasterfemale(); }
	};
	typedef struct E_RoleMasterfemale_s E_RoleMasterfemale_t;

	struct Sheet_RoleMasterfemale_s : public NFDescStoreSeqOP {
		Sheet_RoleMasterfemale_s();
		virtual ~Sheet_RoleMasterfemale_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RoleMasterfemale_s, 2000> E_RoleMasterfemale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RoleMasterfemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RoleMasterfemale & msg);
		static ::proto_ff::Sheet_RoleMasterfemale* new_pbmsg(){ return new ::proto_ff::Sheet_RoleMasterfemale(); }
		static ::proto_ff::Sheet_RoleMasterfemale make_pbmsg(){ return ::proto_ff::Sheet_RoleMasterfemale(); }
	};
	typedef struct Sheet_RoleMasterfemale_s Sheet_RoleMasterfemale_t;

	struct E_RoleSicklemaleAttributeDesc_s : public NFDescStoreSeqOP {
		E_RoleSicklemaleAttributeDesc_s();
		virtual ~E_RoleSicklemaleAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_RoleSicklemaleAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleSicklemaleAttributeDesc & msg);
		static ::proto_ff::E_RoleSicklemaleAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_RoleSicklemaleAttributeDesc(); }
		static ::proto_ff::E_RoleSicklemaleAttributeDesc make_pbmsg(){ return ::proto_ff::E_RoleSicklemaleAttributeDesc(); }
	};
	typedef struct E_RoleSicklemaleAttributeDesc_s E_RoleSicklemaleAttributeDesc_t;

	struct E_RoleSicklemale_s : public NFDescStoreSeqOP {
		E_RoleSicklemale_s();
		virtual ~E_RoleSicklemale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;
		int32_t m_upgradepoint;
		NFShmVector<struct E_RoleSicklemaleAttributeDesc_s, 70> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_RoleSicklemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleSicklemale & msg);
		static ::proto_ff::E_RoleSicklemale* new_pbmsg(){ return new ::proto_ff::E_RoleSicklemale(); }
		static ::proto_ff::E_RoleSicklemale make_pbmsg(){ return ::proto_ff::E_RoleSicklemale(); }
	};
	typedef struct E_RoleSicklemale_s E_RoleSicklemale_t;

	struct Sheet_RoleSicklemale_s : public NFDescStoreSeqOP {
		Sheet_RoleSicklemale_s();
		virtual ~Sheet_RoleSicklemale_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RoleSicklemale_s, 2000> E_RoleSicklemale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RoleSicklemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RoleSicklemale & msg);
		static ::proto_ff::Sheet_RoleSicklemale* new_pbmsg(){ return new ::proto_ff::Sheet_RoleSicklemale(); }
		static ::proto_ff::Sheet_RoleSicklemale make_pbmsg(){ return ::proto_ff::Sheet_RoleSicklemale(); }
	};
	typedef struct Sheet_RoleSicklemale_s Sheet_RoleSicklemale_t;

	struct E_RoleSicklefemaleAttributeDesc_s : public NFDescStoreSeqOP {
		E_RoleSicklefemaleAttributeDesc_s();
		virtual ~E_RoleSicklefemaleAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_RoleSicklefemaleAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleSicklefemaleAttributeDesc & msg);
		static ::proto_ff::E_RoleSicklefemaleAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_RoleSicklefemaleAttributeDesc(); }
		static ::proto_ff::E_RoleSicklefemaleAttributeDesc make_pbmsg(){ return ::proto_ff::E_RoleSicklefemaleAttributeDesc(); }
	};
	typedef struct E_RoleSicklefemaleAttributeDesc_s E_RoleSicklefemaleAttributeDesc_t;

	struct E_RoleSicklefemale_s : public NFDescStoreSeqOP {
		E_RoleSicklefemale_s();
		virtual ~E_RoleSicklefemale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;
		int32_t m_upgradepoint;
		NFShmVector<struct E_RoleSicklefemaleAttributeDesc_s, 70> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_RoleSicklefemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleSicklefemale & msg);
		static ::proto_ff::E_RoleSicklefemale* new_pbmsg(){ return new ::proto_ff::E_RoleSicklefemale(); }
		static ::proto_ff::E_RoleSicklefemale make_pbmsg(){ return ::proto_ff::E_RoleSicklefemale(); }
	};
	typedef struct E_RoleSicklefemale_s E_RoleSicklefemale_t;

	struct Sheet_RoleSicklefemale_s : public NFDescStoreSeqOP {
		Sheet_RoleSicklefemale_s();
		virtual ~Sheet_RoleSicklefemale_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RoleSicklefemale_s, 2000> E_RoleSicklefemale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RoleSicklefemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RoleSicklefemale & msg);
		static ::proto_ff::Sheet_RoleSicklefemale* new_pbmsg(){ return new ::proto_ff::Sheet_RoleSicklefemale(); }
		static ::proto_ff::Sheet_RoleSicklefemale make_pbmsg(){ return ::proto_ff::Sheet_RoleSicklefemale(); }
	};
	typedef struct Sheet_RoleSicklefemale_s Sheet_RoleSicklefemale_t;

	struct E_RoleSwordmaleAttributeDesc_s : public NFDescStoreSeqOP {
		E_RoleSwordmaleAttributeDesc_s();
		virtual ~E_RoleSwordmaleAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_RoleSwordmaleAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleSwordmaleAttributeDesc & msg);
		static ::proto_ff::E_RoleSwordmaleAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_RoleSwordmaleAttributeDesc(); }
		static ::proto_ff::E_RoleSwordmaleAttributeDesc make_pbmsg(){ return ::proto_ff::E_RoleSwordmaleAttributeDesc(); }
	};
	typedef struct E_RoleSwordmaleAttributeDesc_s E_RoleSwordmaleAttributeDesc_t;

	struct E_RoleSwordmale_s : public NFDescStoreSeqOP {
		E_RoleSwordmale_s();
		virtual ~E_RoleSwordmale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;
		int32_t m_upgradepoint;
		NFShmVector<struct E_RoleSwordmaleAttributeDesc_s, 70> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_RoleSwordmale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleSwordmale & msg);
		static ::proto_ff::E_RoleSwordmale* new_pbmsg(){ return new ::proto_ff::E_RoleSwordmale(); }
		static ::proto_ff::E_RoleSwordmale make_pbmsg(){ return ::proto_ff::E_RoleSwordmale(); }
	};
	typedef struct E_RoleSwordmale_s E_RoleSwordmale_t;

	struct Sheet_RoleSwordmale_s : public NFDescStoreSeqOP {
		Sheet_RoleSwordmale_s();
		virtual ~Sheet_RoleSwordmale_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RoleSwordmale_s, 2000> E_RoleSwordmale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RoleSwordmale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RoleSwordmale & msg);
		static ::proto_ff::Sheet_RoleSwordmale* new_pbmsg(){ return new ::proto_ff::Sheet_RoleSwordmale(); }
		static ::proto_ff::Sheet_RoleSwordmale make_pbmsg(){ return ::proto_ff::Sheet_RoleSwordmale(); }
	};
	typedef struct Sheet_RoleSwordmale_s Sheet_RoleSwordmale_t;

	struct E_RoleSwordfemaleAttributeDesc_s : public NFDescStoreSeqOP {
		E_RoleSwordfemaleAttributeDesc_s();
		virtual ~E_RoleSwordfemaleAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_RoleSwordfemaleAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleSwordfemaleAttributeDesc & msg);
		static ::proto_ff::E_RoleSwordfemaleAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_RoleSwordfemaleAttributeDesc(); }
		static ::proto_ff::E_RoleSwordfemaleAttributeDesc make_pbmsg(){ return ::proto_ff::E_RoleSwordfemaleAttributeDesc(); }
	};
	typedef struct E_RoleSwordfemaleAttributeDesc_s E_RoleSwordfemaleAttributeDesc_t;

	struct E_RoleSwordfemale_s : public NFDescStoreSeqOP {
		E_RoleSwordfemale_s();
		virtual ~E_RoleSwordfemale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;
		int32_t m_upgradepoint;
		NFShmVector<struct E_RoleSwordfemaleAttributeDesc_s, 70> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_RoleSwordfemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleSwordfemale & msg);
		static ::proto_ff::E_RoleSwordfemale* new_pbmsg(){ return new ::proto_ff::E_RoleSwordfemale(); }
		static ::proto_ff::E_RoleSwordfemale make_pbmsg(){ return ::proto_ff::E_RoleSwordfemale(); }
	};
	typedef struct E_RoleSwordfemale_s E_RoleSwordfemale_t;

	struct Sheet_RoleSwordfemale_s : public NFDescStoreSeqOP {
		Sheet_RoleSwordfemale_s();
		virtual ~Sheet_RoleSwordfemale_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RoleSwordfemale_s, 2000> E_RoleSwordfemale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RoleSwordfemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RoleSwordfemale & msg);
		static ::proto_ff::Sheet_RoleSwordfemale* new_pbmsg(){ return new ::proto_ff::Sheet_RoleSwordfemale(); }
		static ::proto_ff::Sheet_RoleSwordfemale make_pbmsg(){ return ::proto_ff::Sheet_RoleSwordfemale(); }
	};
	typedef struct Sheet_RoleSwordfemale_s Sheet_RoleSwordfemale_t;

	struct E_RoleTaidaomaleAttributeDesc_s : public NFDescStoreSeqOP {
		E_RoleTaidaomaleAttributeDesc_s();
		virtual ~E_RoleTaidaomaleAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_RoleTaidaomaleAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleTaidaomaleAttributeDesc & msg);
		static ::proto_ff::E_RoleTaidaomaleAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_RoleTaidaomaleAttributeDesc(); }
		static ::proto_ff::E_RoleTaidaomaleAttributeDesc make_pbmsg(){ return ::proto_ff::E_RoleTaidaomaleAttributeDesc(); }
	};
	typedef struct E_RoleTaidaomaleAttributeDesc_s E_RoleTaidaomaleAttributeDesc_t;

	struct E_RoleTaidaomale_s : public NFDescStoreSeqOP {
		E_RoleTaidaomale_s();
		virtual ~E_RoleTaidaomale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;
		int32_t m_upgradepoint;
		NFShmVector<struct E_RoleTaidaomaleAttributeDesc_s, 70> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_RoleTaidaomale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleTaidaomale & msg);
		static ::proto_ff::E_RoleTaidaomale* new_pbmsg(){ return new ::proto_ff::E_RoleTaidaomale(); }
		static ::proto_ff::E_RoleTaidaomale make_pbmsg(){ return ::proto_ff::E_RoleTaidaomale(); }
	};
	typedef struct E_RoleTaidaomale_s E_RoleTaidaomale_t;

	struct Sheet_RoleTaidaomale_s : public NFDescStoreSeqOP {
		Sheet_RoleTaidaomale_s();
		virtual ~Sheet_RoleTaidaomale_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RoleTaidaomale_s, 2000> E_RoleTaidaomale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RoleTaidaomale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RoleTaidaomale & msg);
		static ::proto_ff::Sheet_RoleTaidaomale* new_pbmsg(){ return new ::proto_ff::Sheet_RoleTaidaomale(); }
		static ::proto_ff::Sheet_RoleTaidaomale make_pbmsg(){ return ::proto_ff::Sheet_RoleTaidaomale(); }
	};
	typedef struct Sheet_RoleTaidaomale_s Sheet_RoleTaidaomale_t;

	struct E_RoleTaidaofemaleAttributeDesc_s : public NFDescStoreSeqOP {
		E_RoleTaidaofemaleAttributeDesc_s();
		virtual ~E_RoleTaidaofemaleAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_RoleTaidaofemaleAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleTaidaofemaleAttributeDesc & msg);
		static ::proto_ff::E_RoleTaidaofemaleAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_RoleTaidaofemaleAttributeDesc(); }
		static ::proto_ff::E_RoleTaidaofemaleAttributeDesc make_pbmsg(){ return ::proto_ff::E_RoleTaidaofemaleAttributeDesc(); }
	};
	typedef struct E_RoleTaidaofemaleAttributeDesc_s E_RoleTaidaofemaleAttributeDesc_t;

	struct E_RoleTaidaofemale_s : public NFDescStoreSeqOP {
		E_RoleTaidaofemale_s();
		virtual ~E_RoleTaidaofemale_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;
		int32_t m_upgradepoint;
		NFShmVector<struct E_RoleTaidaofemaleAttributeDesc_s, 70> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_RoleTaidaofemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleTaidaofemale & msg);
		static ::proto_ff::E_RoleTaidaofemale* new_pbmsg(){ return new ::proto_ff::E_RoleTaidaofemale(); }
		static ::proto_ff::E_RoleTaidaofemale make_pbmsg(){ return ::proto_ff::E_RoleTaidaofemale(); }
	};
	typedef struct E_RoleTaidaofemale_s E_RoleTaidaofemale_t;

	struct Sheet_RoleTaidaofemale_s : public NFDescStoreSeqOP {
		Sheet_RoleTaidaofemale_s();
		virtual ~Sheet_RoleTaidaofemale_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RoleTaidaofemale_s, 2000> E_RoleTaidaofemale_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RoleTaidaofemale & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RoleTaidaofemale & msg);
		static ::proto_ff::Sheet_RoleTaidaofemale* new_pbmsg(){ return new ::proto_ff::Sheet_RoleTaidaofemale(); }
		static ::proto_ff::Sheet_RoleTaidaofemale make_pbmsg(){ return ::proto_ff::Sheet_RoleTaidaofemale(); }
	};
	typedef struct Sheet_RoleTaidaofemale_s Sheet_RoleTaidaofemale_t;

	struct E_RoleExp_s : public NFDescStoreSeqOP {
		E_RoleExp_s();
		virtual ~E_RoleExp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;
		int64_t m_exp;
		int32_t m_skillpoint;

		virtual void write_to_pbmsg(::proto_ff::E_RoleExp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleExp & msg);
		static ::proto_ff::E_RoleExp* new_pbmsg(){ return new ::proto_ff::E_RoleExp(); }
		static ::proto_ff::E_RoleExp make_pbmsg(){ return ::proto_ff::E_RoleExp(); }
	};
	typedef struct E_RoleExp_s E_RoleExp_t;

	struct Sheet_RoleExp_s : public NFDescStoreSeqOP {
		Sheet_RoleExp_s();
		virtual ~Sheet_RoleExp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RoleExp_s, 2000> E_RoleExp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RoleExp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RoleExp & msg);
		static ::proto_ff::Sheet_RoleExp* new_pbmsg(){ return new ::proto_ff::Sheet_RoleExp(); }
		static ::proto_ff::Sheet_RoleExp make_pbmsg(){ return ::proto_ff::Sheet_RoleExp(); }
	};
	typedef struct Sheet_RoleExp_s Sheet_RoleExp_t;

	struct E_RoleSkilltype_s : public NFDescStoreSeqOP {
		E_RoleSkilltype_s();
		virtual ~E_RoleSkilltype_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_skillid;
		int32_t m_skilltype;

		virtual void write_to_pbmsg(::proto_ff::E_RoleSkilltype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleSkilltype & msg);
		static ::proto_ff::E_RoleSkilltype* new_pbmsg(){ return new ::proto_ff::E_RoleSkilltype(); }
		static ::proto_ff::E_RoleSkilltype make_pbmsg(){ return ::proto_ff::E_RoleSkilltype(); }
	};
	typedef struct E_RoleSkilltype_s E_RoleSkilltype_t;

	struct Sheet_RoleSkilltype_s : public NFDescStoreSeqOP {
		Sheet_RoleSkilltype_s();
		virtual ~Sheet_RoleSkilltype_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RoleSkilltype_s, 200> E_RoleSkilltype_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RoleSkilltype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RoleSkilltype & msg);
		static ::proto_ff::Sheet_RoleSkilltype* new_pbmsg(){ return new ::proto_ff::Sheet_RoleSkilltype(); }
		static ::proto_ff::Sheet_RoleSkilltype make_pbmsg(){ return ::proto_ff::Sheet_RoleSkilltype(); }
	};
	typedef struct Sheet_RoleSkilltype_s Sheet_RoleSkilltype_t;

	struct E_RoleAddskill_s : public NFDescStoreSeqOP {
		E_RoleAddskill_s();
		virtual ~E_RoleAddskill_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int64_t m_skillid;

		virtual void write_to_pbmsg(::proto_ff::E_RoleAddskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleAddskill & msg);
		static ::proto_ff::E_RoleAddskill* new_pbmsg(){ return new ::proto_ff::E_RoleAddskill(); }
		static ::proto_ff::E_RoleAddskill make_pbmsg(){ return ::proto_ff::E_RoleAddskill(); }
	};
	typedef struct E_RoleAddskill_s E_RoleAddskill_t;

	struct Sheet_RoleAddskill_s : public NFDescStoreSeqOP {
		Sheet_RoleAddskill_s();
		virtual ~Sheet_RoleAddskill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RoleAddskill_s, 20> E_RoleAddskill_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RoleAddskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RoleAddskill & msg);
		static ::proto_ff::Sheet_RoleAddskill* new_pbmsg(){ return new ::proto_ff::Sheet_RoleAddskill(); }
		static ::proto_ff::Sheet_RoleAddskill make_pbmsg(){ return ::proto_ff::Sheet_RoleAddskill(); }
	};
	typedef struct Sheet_RoleAddskill_s Sheet_RoleAddskill_t;

	struct E_RoleWorldexp_s : public NFDescStoreSeqOP {
		E_RoleWorldexp_s();
		virtual ~E_RoleWorldexp_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_lv;
		int32_t m_worldexp;

		virtual void write_to_pbmsg(::proto_ff::E_RoleWorldexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoleWorldexp & msg);
		static ::proto_ff::E_RoleWorldexp* new_pbmsg(){ return new ::proto_ff::E_RoleWorldexp(); }
		static ::proto_ff::E_RoleWorldexp make_pbmsg(){ return ::proto_ff::E_RoleWorldexp(); }
	};
	typedef struct E_RoleWorldexp_s E_RoleWorldexp_t;

	struct Sheet_RoleWorldexp_s : public NFDescStoreSeqOP {
		Sheet_RoleWorldexp_s();
		virtual ~Sheet_RoleWorldexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RoleWorldexp_s, 600> E_RoleWorldexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RoleWorldexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RoleWorldexp & msg);
		static ::proto_ff::Sheet_RoleWorldexp* new_pbmsg(){ return new ::proto_ff::Sheet_RoleWorldexp(); }
		static ::proto_ff::Sheet_RoleWorldexp make_pbmsg(){ return ::proto_ff::Sheet_RoleWorldexp(); }
	};
	typedef struct Sheet_RoleWorldexp_s Sheet_RoleWorldexp_t;

}

